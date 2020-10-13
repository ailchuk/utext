#include "myfind.h"
#include "ui_myfind.h"
#include <QDebug>

#include <QSyntaxHighlighter>

MyFind::MyFind(QWidget *parent, QTextEdit *textEdit, QString *selected_text) :
    QDialog(parent),
    m_findui(new Ui::MyFind),
    m_textEdit(textEdit)
{
    m_findui->setupUi(this);
    this->setFixedSize(QSize(420, 85));
    m_search_highLight = new SearchHighLight(m_textEdit->document());
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    m_findui->findLine->setText(*selected_text);
}

MyFind::~MyFind()
{
    delete m_findui;
}

void MyFind::on_findButton_clicked()
{
    m_search_highLight->searchText(m_findui->findLine->text());
}

void MyFind::on_replaceButton_clicked()
{
    m_search_highLight->replaceText(m_textEdit, m_findui->findLine->text(), m_findui->replaceLine->text());
    m_search_highLight->searchText(m_findui->replaceLine->text());
}

void MyFind::closeEvent(QCloseEvent *event)
{
    m_search_highLight->offHighlight();
    QDialog::closeEvent(event);
}
