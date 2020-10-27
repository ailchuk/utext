#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    createTreeView();

    on_actionLight_theme_triggered();
    connect(m_ui->textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(showCursorPos()));
    m_highlighter = new Highlighter();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}
