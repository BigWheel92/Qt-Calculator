#ifndef POSTFIXNOTATION_H
#define POSTFIXNOTATION_H
#include "QStack"
#include "QDebug"
#include "QChar"

#include "qstack.h"
#include"lexicalanalyzer.h"
class PostFixNotation
{
  QStack<double> numbers;
  QStack<QChar> operators;

public:
    PostFixNotation()
    {

    }

    PostFixNotation(QVector<TokenLexemePair>&);
    ~PostFixNotation();

   void convertToPostFix(QVector<TokenLexemePair>);
   bool hasPrec(const QChar&, const QChar&);
   double getAnswer();

  double evaluate( double const& operand1, double const& operand2, QChar const&);
};

#endif // POSTFIXNOTATION_H
