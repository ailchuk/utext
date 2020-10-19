#include <mytextedit.h>

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent) {

}

MyTextEdit::MyTextEdit(const QString &text, QWidget *parent) : QTextEdit(text, parent) {

}


