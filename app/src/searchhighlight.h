#pragma once

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextEdit>

class SearchHighLight : public QSyntaxHighlighter
{
    Q_OBJECT
    using BaseClass = QSyntaxHighlighter;
public:
    explicit SearchHighLight(QTextDocument *parent = nullptr);

    void searchText(const QString &text);

    void offHighlight();

    void replaceText(QTextEdit *textEdit, const QString &old_text, const QString &new_text);

protected:
    virtual void highlightBlock(const QString &text) override;

private:
    QRegularExpression m_pattern; // Regular expression to search for, in our case, this word or text
    QTextCharFormat m_format; // Text formatting, highlighting
};
