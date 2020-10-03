#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::on_treeView_doubleClicked(const QModelIndex &idx)
{
    if (m_model->fileInfo(idx).isDir()) {
        QMessageBox::warning(this, "utext: Error", "You have selected a folder!\nPlease, select a file");
        return;
    } else if (!idx.isValid() || !m_model->fileInfo(idx).isFile()) {
        QMessageBox::warning(this, "utext: Error", "Selected item error!");
        return;
    } else if (m_model->fileInfo(idx).fileName().isEmpty()) {
        return;
    }

    QFile file(m_model->fileInfo(idx).absoluteFilePath());

    m_file_path = file.fileName();

    if (!file.open(QFile::ReadOnly | QFile::Text) || !file.isReadable()) {
        QMessageBox::warning(this, "utext: Error", "Can't read/open selected file!");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();

    m_ui->textEdit->setText(text);
    file.close();
}
