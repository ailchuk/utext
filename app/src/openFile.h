#ifndef OPENFILE_H
#define OPENFILE_H

#include <QString>
#include "highlighter.h"
#include "mytextedit.h"

bool openFileWithHighlight(MyTextEdit **textEdit, Highlighter **highlighter, const QString &file_path);
bool openFileWithoutHighlight(MyTextEdit **textEdit, QString &file_path);

#endif // OPENFILE_H
