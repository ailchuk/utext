#ifndef MYFIND_H
#define MYFIND_H

#include <QDialog>
#include <QTextEdit>

#include "searchhighlight.h"

namespace Ui {
class MyFind;
}

class MyFind : public QDialog
{
    Q_OBJECT

public:
    explicit MyFind(QWidget *parent = nullptr, QTextEdit *textEdit = nullptr, QString *selected_text = nullptr);
    ~MyFind();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_findButton_clicked();

    void on_replaceButton_clicked();


private:
    Ui::MyFind *m_findui;
    QTextEdit *m_textEdit;
    SearchHighLight *m_search_highLight;
};

#endif // MYFIND_H
