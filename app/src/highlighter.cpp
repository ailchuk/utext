#include <highlighter.h>

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    m_keywordFormat.setForeground(Qt::darkBlue);
    m_keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatterns[] = {
        QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
        QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
        QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"), QStringLiteral("\\bint\\b"),
        QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
        QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
        QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
        QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),
        QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"),
        QStringLiteral("\\bunion\\b"), QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"),
        QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bbool\\b")
    };

    for (const QString &m_pattern : keywordPatterns) {
        rule.m_pattern = QRegularExpression(m_pattern);
        rule.m_format = m_keywordFormat;
        m_highlightingRules.append(rule);
    }

    m_classFormat.setFontWeight(QFont::Bold);
    m_classFormat.setForeground(Qt::darkMagenta);
    rule.m_pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.m_format = m_classFormat;
    m_highlightingRules.append(rule);

    m_quotationFormat.setForeground(Qt::darkGreen);
    rule.m_pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.m_format = m_quotationFormat;
    m_highlightingRules.append(rule);

    m_functionFormat.setFontItalic(true);
    m_functionFormat.setForeground(Qt::blue);
    rule.m_pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.m_format = m_functionFormat;
    m_highlightingRules.append(rule);
    m_singleLineCommentFormat.setForeground(Qt::red);
    rule.m_pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.m_format = m_singleLineCommentFormat;
    m_highlightingRules.append(rule);

    m_multiLineCommentFormat.setForeground(Qt::red);

    m_commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    m_commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}

void Highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : qAsConst(m_highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.m_pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.m_format);
        }
    }
    setCurrentBlockState(0);
    int startIndex = 0;
        if (previousBlockState() != 1)
            startIndex = text.indexOf(m_commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = m_commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, m_multiLineCommentFormat);
        startIndex = text.indexOf(m_commentStartExpression, startIndex + commentLength);
    }
}
