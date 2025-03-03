#include "mainwindow.h"

bool openFileWithHighlight(MyTextEdit **textEdit, Highlighter **m_highlighter, const QString &file_path) {
    (*m_highlighter)->setDocument((*textEdit)->document());

    QFile file(file_path);

    if (!file.open(QFile::ReadOnly | QFile::Text) || !file.isReadable()) {
        return false;
    }

    (*textEdit)->setPlainText(file.readAll());
    return true;
}

bool openFileWithoutHighlight(MyTextEdit **textEdit, const QString &file_path) {
    QFile file(file_path);

    if (!file.open(QFile::ReadOnly | QFile::Text) || !file.isReadable()) {
        return false;
    }

    (*textEdit)->setPlainText(file.readAll());
    return true;
}
