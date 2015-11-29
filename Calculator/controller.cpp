#include "controller.h"


Controller::Controller(QString const& data)
{
    LexicalAnalyzer lexicalAnalyzer(data);


    PostFixNotation postfix(lexicalAnalyzer.getTokenLexemePairList());
     this->answer=postfix.getAnswer();

}


double Controller::getAnswer() const
{
    return this->answer;
}


Controller::~Controller()
{

}

