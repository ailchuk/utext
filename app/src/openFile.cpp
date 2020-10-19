#include "mainwindow.h"

bool openFileWithHighlight(MyTextEdit **textEdit, Highlighter **highlighter, const QString &file_path) {
    *highlighter = new Highlighter((*textEdit)->document());

    QFile file(file_path);

    if (!file.open(QFile::ReadOnly | QFile::Text) || !file.isReadable()) {
        return false;
    }

    (*textEdit)->setPlainText(file.readAll());
    return true;
}

bool openFileWithoutHighlight(MyTextEdit **textEdit, QString &file_path) {
    QFile file(file_path);

    if (!file.open(QFile::ReadOnly | QFile::Text) || !file.isReadable()) {
        return false;
    }

    (*textEdit)->setPlainText(file.readAll());
    return true;
}
