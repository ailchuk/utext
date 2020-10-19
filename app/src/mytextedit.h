#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QWidget>
#include <QString>

#include <QCompleter>
#include <QFocusEvent>
#include <QKeyEvent>

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = nullptr);
    explicit MyTextEdit(const QString &text, QWidget *parent = nullptr);
    ~MyTextEdit() {};

    //void setCompleter(QCompleter *c);
    //QCompleter *completer() const;

protected:
    //void keyPressEvent(QKeyEvent *e) override;
    //void focusInEvent(QFocusEvent *e) override;

private slots:
    //void insertCompletion(const QString &completion);

private:
    //QString textUnderCursor() const;

private:
    //QCompleter *c = nullptr;

};

#endif // MYTEXTEDIT_H
