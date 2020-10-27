#include <mytextedit.h>
#include <QStringListModel>
#include <QGuiApplication>
#include <QTextDocumentFragment>

#include <iostream>

QAbstractItemModel *MyTextEdit::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        // "Can't open wordlist.txt file: "
        return new QStringListModel(m_c);
    }

#ifndef QT_NO_CURSOR
    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << QString::fromUtf8(line.trimmed());
    }

#ifndef QT_NO_CURSOR
    QGuiApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, m_c);
}

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {
    setCompleter();
    setupCursorHighlightings();
}

MyTextEdit::MyTextEdit(const QString &text, QWidget *parent) : QTextEdit(text, parent) {
    setCompleter();
    setupCursorHighlightings();
}

void MyTextEdit::setupCursorHighlightings()
{
    m_fmt.setUnderlineStyle(QTextCharFormat::SingleUnderline);
    m_fmt.setUnderlineColor(QColor(200,200,200));
    m_fmt.setBackground(QBrush(QColor(230,230,230)));
}

void MyTextEdit::setCompleter()
{
   if (m_c)
        m_c->disconnect(this);
    m_c = new QCompleter(this);

    m_c->setModel(modelFromFile(":/wordlist.txt"));
    m_c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    m_c->setCaseSensitivity(Qt::CaseInsensitive);
    m_c->setWrapAround(false);

    if (!m_c)
        return;

    m_c->setWidget(this);
    m_c->setCompletionMode(QCompleter::PopupCompletion);
    m_c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(m_c, QOverload<const QString &>::of(&QCompleter::activated),
                     this, &MyTextEdit::insertCompletion);
}

void MyTextEdit::insertCompletion(const QString &completion)
{
    if (m_c->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = completion.length() - m_c->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}


QString MyTextEdit::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::SelectionType::WordUnderCursor);

    return tc.selectedText();
}

void MyTextEdit::focusInEvent(QFocusEvent *e)
{
    if (m_c)
        m_c->setWidget(this);
    QTextEdit::focusInEvent(e);
}

void MyTextEdit::keyPressEvent(QKeyEvent *e)
{
    if (m_c && m_c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
       switch (e->key()) {
       case Qt::Key_Enter:
       case Qt::Key_Return:
       case Qt::Key_Escape:
       case Qt::Key_Tab:
       case Qt::Key_Backtab:
            e->ignore();
            return; // let the completer do default behavior
       default:
           break;
       }
    }

    const bool isShortcut = (e->modifiers().testFlag(Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!m_c || !isShortcut) // do not process the shortcut when we have a completer
        QTextEdit::keyPressEvent(e);
    const bool ctrlOrShift = e->modifiers().testFlag(Qt::ControlModifier) ||
                                 e->modifiers().testFlag(Qt::ShiftModifier);
    if (!m_c || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
    const bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();



    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
                      || eow.contains(e->text().right(1)))) {
        m_c->popup()->hide();
        return;
    }

    if (completionPrefix != m_c->completionPrefix()) {
        m_c->setCompletionPrefix(completionPrefix);
        m_c->popup()->setCurrentIndex(m_c->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();
    cr.setWidth(m_c->popup()->sizeHintForColumn(0)
                + m_c->popup()->verticalScrollBar()->sizeHint().width());
    m_c->complete(cr); // popup it up!
}
