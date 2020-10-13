#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::on_actionDark_theme_triggered()
{
    m_ui->actionDark_theme->setChecked(true);
    m_ui->actionLight_theme->setChecked(false);

    this->setStyleSheet("color: white; background-color: #2e2f32;");
    m_ui->textEdit->setStyleSheet("color: white; background-color: #2e2f32;");
    m_ui->menubar->setStyleSheet("background-color: #323336;");
    m_ui->toolBar->setStyleSheet("QToolBar {background: #323336;border: 1px solid #323336;}");
    m_ui->statusbar->setStyleSheet("background-color: #2e2f32;");
    m_ui->treeView->setStyleSheet("color: white; background-color: #2e2f32;");
}

void MainWindow::on_actionLight_theme_triggered()
{
    m_ui->actionLight_theme->setChecked(true);
    m_ui->actionDark_theme->setChecked(false);

    this->setStyleSheet("color: black; background-color: #dde1e5;");
    m_ui->textEdit->setStyleSheet("color: black; background-color: white;");
    m_ui->menubar->setStyleSheet("background-color: #fafafa;");
    m_ui->toolBar->setStyleSheet("QToolBar {background: #dde1e5;border: 1px solid #dde1e5;}");
    m_ui->statusbar->setStyleSheet("background-color: #dde1e5;");
    m_ui->treeView->setStyleSheet("color: black; background-color: white;");
}