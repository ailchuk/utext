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

    if (m_highlighterStatus) {
        if (!openFileWithHighlight(&m_ui->textEdit, &m_highlighter, m_model->fileInfo(idx).absoluteFilePath())) {
            QMessageBox::warning(this, "utext: Error", "Can't read/open selected file!");
            return;
        }
    }
    else {
        if (!openFileWithoutHighlight(&m_ui->textEdit, m_model->fileInfo(idx).absoluteFilePath())) {
            QMessageBox::warning(this, "utext: Error", "Can't read/open selected file!");
            return;
        }
    }

    m_file_path = m_model->fileInfo(idx).absoluteFilePath();
}
