#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::on_actionNew_triggered()
{
    m_file_path = "";
    m_ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open file");

    if (file_name.isEmpty()) {
        return;
    }

    if (m_highlighterStatus) {
        if (!openFileWithHighlight(&m_ui->textEdit, &m_highlighter, file_name)) {
            QMessageBox::warning(this, "utext: Error", "Can't read/open selected file!");
            return;
        }
    }
    else {
        if (!openFileWithoutHighlight(&m_ui->textEdit, file_name)) {
            QMessageBox::warning(this, "utext: Error", "Can't read/open selected file!");
            return;
        }
    }

    m_file_path = file_name;
    createTreeView();
}

void MainWindow::on_actionSave_triggered()
{
    if (m_file_path.isEmpty()) {
        on_actionSave_as_triggered();
        return;
    }

    QFile file(m_file_path);
    if (!file.open(QFile::WriteOnly | QFile::Text) || !file.isWritable()) {
        QMessageBox::warning(this, "utext: Error", "Can't open/write file!\n ");
        return;
    }

    QTextStream out(&file);

    out << m_ui->textEdit->toPlainText();
    file.flush();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Open file");

    if (file_name.isEmpty()) {
        return;
    }

    QFile file(file_name);

    if (!file.open(QFile::WriteOnly | QFile::Text) || !file.isWritable()) {
        QMessageBox::warning(this, "utext: Error", "Can't open/write file!");
        return;
    }

    m_file_path = file_name;

    QTextStream out(&file);

    out << m_ui->textEdit->toPlainText();
    file.flush();
}

void MainWindow::on_actionCut_triggered()
{
    m_ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    m_ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    m_ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    m_ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    m_ui->textEdit->undo();
}

void MainWindow::on_actionFont_triggered()
{
    bool is_font;
    QFont font = QFontDialog::getFont(&is_font, this);
    QTextCursor cursor(m_ui->textEdit->textCursor());
    QString sel = cursor.selectedText();

    if (!sel.isEmpty()) {
        QTextCharFormat format;

        format.setFont(font);
        cursor.mergeCharFormat(format);
        return;
    }

    if (is_font) {
        m_ui->textEdit->setFont(font);
    } else {
        return;
    }
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");

    if (color.isValid()) {
        m_ui->textEdit->setTextColor(color);
    }
}

void MainWindow::on_actionBackground_Color_triggered()
{
    QColor background_color = QColorDialog::getColor(Qt::white, this, "Choose Background Color");

    if (background_color.isValid()) {
        m_ui->textEdit->setTextBackgroundColor(background_color);
    }
}

void MainWindow::on_actionFind_triggered()
{
    QTextCursor cursor(m_ui->textEdit->textCursor());
    QString sel = cursor.selectedText();

    m_find_dialog = new MyFind(this, m_ui->textEdit, &sel);
    m_find_dialog->show();
}

void MainWindow::on_actionSyntax_highlighting_triggered()
{
    if (this->m_highlighterStatus) {
        this->m_highlighterStatus = false;
        m_highlighter->setDocument(0);

    }
    else {
        m_highlighter->setDocument(m_ui->textEdit->document());
        this->m_highlighterStatus = true;
    }
}

void MainWindow::on_actionBackground_color_of_editing_text_triggered()
{
    QColor background_color = QColorDialog::getColor(Qt::white, this, "Choose Background Color");

    if (background_color.isValid()) {
        m_ui->textEdit->m_color = background_color;
    }
}
