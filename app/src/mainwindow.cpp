#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    this->on_actionDark_theme_triggered();
    createTreeView();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::createTreeView() {
    m_model = new QFileSystemModel;
    QDir dir1 = QFileInfo(m_file_path).absoluteDir();
    QString dir = dir1.path();
    m_model->setRootPath(dir1.absolutePath());

    m_ui->treeView->setModel(m_model);
    m_ui->treeView->setRootIndex(m_model->index(dir));
    m_ui->treeView->header()->hideSection(1);
    m_ui->treeView->header()->hideSection(2);
    m_ui->treeView->header()->hideSection(3);

}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &idx)
{
    if (!idx.isValid() || !m_model->fileInfo(idx).isFile()) {
        QMessageBox::warning(this, "utext: Error", "Selected item error!");
        return;
    } else if (m_model->fileInfo(idx).fileName().isEmpty()) {
        return;
    }

    QFile file(m_model->fileInfo(idx).absoluteFilePath());

    m_file_path = file.fileName();

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "utext: Error", "Selected file not opened!");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();

    m_ui->textEdit->setText(text);
    file.close();
}


