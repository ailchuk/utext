#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::on_actionDark_theme_triggered()
{
    m_ui->actionDark_theme->setChecked(true);
    m_ui->actionLight_theme->setChecked(false);

    m_ui->textEdit->setStyleSheet("background-color: #E0E0E0;");
    m_ui->menubar->setStyleSheet("background-color: #C0C0C0;");
    m_ui->toolBar->setStyleSheet("background-color: #C0C0C0;");
    m_ui->statusbar->setStyleSheet("background-color: #C0C0C0;");
}

void MainWindow::on_actionLight_theme_triggered()
{
    m_ui->actionLight_theme->setChecked(true);
    m_ui->actionDark_theme->setChecked(false);

    m_ui->textEdit->setStyleSheet("background-color: white;");
    m_ui->menubar->setStyleSheet("background-color: #E0E0E0;");
    m_ui->toolBar->setStyleSheet("background-color: #E0E0E0;");
    m_ui->statusbar->setStyleSheet("background-color: #E0E0E0;");

}
