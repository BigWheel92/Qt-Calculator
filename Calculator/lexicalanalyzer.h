#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H
#include <QSTring>
#include <QVector>


enum TokenType
{
 OPERATOR,
 NUMBER,
 OPENING_PARENTHESIS,
 CLOSING_PARENTHESIS
};

struct TokenLexemePair
{
     TokenType tokenType;
     QString lexeme;

};

class LexicalAnalyzer
{
    QString input;
    int currentIndex;
    QVector<TokenLexemePair> tokensList;
    bool expectedSignFlag;

    bool findNum();
    bool findOpeningParenthesis();
    bool findClosingParenthesis();
    bool findOp();

    bool isOp(QChar const&);
    bool isSign(QChar const&);
    bool isDigit(QChar const&);
    void startAnalyze();
    void recurAnalyze();

public:
    LexicalAnalyzer(QString const&);
    ~LexicalAnalyzer();

    QVector<TokenLexemePair> & getTokenLexemePairList();




};




#endif // LEXICALANALYZER_H
