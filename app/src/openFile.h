#ifndef OPENFILE_H
#define OPENFILE_H

#include <QTextEdit>
#include <QString>
#include "highlighter.h"

bool openFileWithHighlight(QTextEdit **textEdit, Highlighter **highlighter, const QString &file_path);
bool openFileWithoutHighlight(QTextEdit **textEdit, QString &file_path);

#endif // OPENFILE_H
