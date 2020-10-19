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

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = nullptr);
    explicit MyTextEdit(const QString &text, QWidget *parent = nullptr);
    ~MyTextEdit() {};

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private slots:
    void insertCompletion(const QString &completion);

private:
    QString textUnderCursor() const;
    QAbstractItemModel* modelFromFile(const QString& fileName);

private:
    QCompleter *c = nullptr;
    void setCompleter();

};

#endif // MYTEXTEDIT_H
