#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    this->on_actionDark_theme_triggered();
    createTreeView();

    connect(m_ui->textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(showCursorPos()));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

