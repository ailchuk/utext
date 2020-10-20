#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QWidget>
#include <QString>

#include <QCompleter>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QAbstractItemModel>
#include <QScrollBar>
#include <QAbstractItemView>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QList>


class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = nullptr);
    explicit MyTextEdit(const QString &text, QWidget *parent = nullptr);
    ~MyTextEdit() {};

    QTextCharFormat fmt;
    QList<ExtraSelection> selections;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private slots:
    void insertCompletion(const QString &completion);

private:
    QString textUnderCursor() const;
    QAbstractItemModel* modelFromFile(const QString& fileName);
    void setCompleter();
    void setupCursorHighlightings();

private:
    QCompleter *m_c = nullptr;

};

#endif // MYTEXTEDIT_H
