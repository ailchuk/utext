#include "searchhighlight.h"

#include <QTextCharFormat>
#include <QDebug>

SearchHighLight::SearchHighLight(QTextDocument* parent) : BaseClass(parent)
{
    // Set the backlight color
    m_format.setBackground(Qt::yellow);
}

void SearchHighLight::highlightBlock(const QString& text)
{
    // Using a regular expression, we find all matches.
    QRegularExpressionMatchIterator matchIterator = m_pattern.globalMatch(text);
    while (matchIterator.hasNext())
    {
        // Highlight all matches
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), m_format);
    }
}

void SearchHighLight::searchText(const QString &text)
{
    // Set the text as a regular expression.
    m_pattern = QRegularExpression(text);
    rehighlight(); // reload highlight
}

void SearchHighLight::offHighlight() // disable highlight
{
    m_pattern = QRegularExpression("");
    rehighlight();
}

void SearchHighLight::replaceText(QTextEdit *textEdit, const QString &old_text, const QString &new_text)
{
    QRegularExpression repl(old_text);

    textEdit->setPlainText(textEdit->toPlainText().replace(repl, new_text));
}
