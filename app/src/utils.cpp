#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>

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

void MainWindow::showCursorPos()
{
    int pos = m_ui->textEdit->textCursor().columnNumber() + 1;
    int line = m_ui->textEdit->textCursor().blockNumber() + 1;

    m_ui->statusbar->showMessage(QString("Line: %1, Column: %2").arg(line).arg(pos));

    QTextCursor tc = m_ui->textEdit->textCursor();
    tc.select(QTextCursor::SelectionType::WordUnderCursor);
    std::cerr << tc.selectedText().toStdString().size() << std::endl;
    if (tc.anchor() != tc.position()) { // true only if there is some symbols under cursor
        cursor.clearSelection();
        std::cerr << tc.anchor() << " " << tc.position() << std::endl;
        tc.movePosition(QTextCursor::StartOfWord);
        tc.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
        std::cerr << tc.selectedText().toStdString() << std::endl;

        MyTextEdit::ExtraSelection sel;

        QTextEdit::ExtraSelection selection;
        selection.format.setBackground(Qt::green);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = tc;
//        selection.cursor.clearSelection();
        m_ui->textEdit->selections.append(selection);
        m_ui->textEdit->setExtraSelections(m_ui->textEdit->selections);

//        while( !(tc = m_ui->textEdit->document()->find(QRegExp("\\([^)]*\\)"), tc)).isNull()) {
//           MyTextEdit::ExtraSelection sel = { tc, m_ui->textEdit->fmt };
//           m_ui->textEdit->selections.append(sel);
//        }
        //m_ui->textEdit->setExtraSelections(m_ui->textEdit->selections);
    }
}
