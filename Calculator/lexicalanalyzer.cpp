#include "lexicalanalyzer.h"
#include <qdebug.h>
#include <QtDebug>
#include <QDebug>
#include <iostream>
using namespace std;

LexicalAnalyzer::LexicalAnalyzer(QString const& input)
{
    this->input= input;
    this->currentIndex=0;
    this->expectedSignFlag=true;

    qDebug()<<input<<endl;
    this->startAnalyze();

     qDebug()<<"----------START PRINTING TOKENS----------"<<endl;
    //printing tokens on console
    QVectorIterator<TokenLexemePair> i(this->tokensList);
    while (i.hasNext())
        qDebug() << i.next().lexeme<<endl;

}

QVector<TokenLexemePair> & LexicalAnalyzer::getTokenLexemePairList()
{
    return this->tokensList;
}

bool LexicalAnalyzer::isOp(QChar const& input)
{
    if (input=='X' || input=='+' || input=='-' || input=='÷')
        return true;

    return false;
}

bool LexicalAnalyzer::isSign(QChar const& input)
{
    if ( input=='+' || input=='-')
        return true;

    return false;

}


void LexicalAnalyzer::recurAnalyze()
{

    int state=0;
    while (this->currentIndex< this->input.size())
    {
        switch(state)
        {

        case 0:
            if (this->findNum())
            {
                state=1;
                break;
            }

            else if (this->findOpeningParenthesis())
            {
                 this->recurAnalyze();
                 state=1;
                 break;
            }

            else {
                         qDebug()<<"The input is not well formed!"<<endl;
                         exit(EXIT_FAILURE);
            }

          case 1:
              if (this->findOp())
              {
                  state=2;
              }

              else if (this->findClosingParenthesis())
              {
                  return;
              }

              else {
                  qDebug()<<"The input is not well formed!"<<endl;
                  exit(EXIT_FAILURE);
              }

          case 2:

            if (this->findNum())
            {
                state=1;
            }

            else if (this->findOpeningParenthesis())
            {
                //recur analysis
                this->recurAnalyze();
                state=1;
                break;
            }

            else
            {
                qDebug()<<"The input is not well formed!"<<endl;
                exit(EXIT_FAILURE);
            }
        }//end of switch

     }//end of while loop

    qDebug()<<"The input is not well formed (the closing parenthesis not found!)";
    exit(EXIT_FAILURE);
}

void LexicalAnalyzer::startAnalyze()
{

    int state=0;
    while (this->currentIndex< this->input.size())
    {
        switch(state)
        {

        case 0:
            if (this->findNum())
            {
                state=1;
                break;
            }

            else if (this->findOpeningParenthesis())
            {
                 //recur Analyze
                this->recurAnalyze();
                state=1;
                break;
            }

            else {
                         qDebug()<<"The input is not well formed!"<<endl;
                         exit(EXIT_FAILURE);
            }

          case 1:
              if (this->findOp())
              {
                  state=2;
                  break;
              }

              else {
                  qDebug()<<"The input is not well formed!"<<endl;
                  exit(EXIT_FAILURE);
              }

          case 2:

            if (this->findNum())
            {
                state=1;
                break;
            }

            else if (this->findOpeningParenthesis())
            {
                //recur analysis
                this->recurAnalyze();
                state=1;
                break;
            }

            else
            {
                qDebug()<<"The input is not well formed!"<<endl;
                exit(EXIT_FAILURE);
            }
        }//end of switch

     }//end of while loop

}

bool LexicalAnalyzer::findOpeningParenthesis()
{
    if (this->input[this->currentIndex]=='(')
    {
        TokenLexemePair a;
        a.tokenType= OPENING_PARENTHESIS;
        a.lexeme="(";
        this->tokensList.push_back(a);
        this->currentIndex++;
        return true;
    }
    return false;
}

bool LexicalAnalyzer::findClosingParenthesis()
{
    if (this->input[this->currentIndex]==')')
    {
        TokenLexemePair a;
        a.tokenType= CLOSING_PARENTHESIS;
        a.lexeme=")";
        this->tokensList.push_back(a);
        this->currentIndex++;
        return true;
    }
    return false;
}

bool LexicalAnalyzer::findOp()
{
    if ( input[this->currentIndex]=='+' || input[this->currentIndex]=='-' || input[this->currentIndex]=='X' || input[this->currentIndex]=='/')
    {

        TokenLexemePair a;
        a.tokenType= OPERATOR;
        a.lexeme=this->input[this->currentIndex];
        this->tokensList.push_back(a);
        this->currentIndex++;
        return true;

    }
    return false;
}

bool LexicalAnalyzer::isDigit(QChar const& data)
{
    if (data>='0' && data<='9')
    {
       return true;
    }

    return false;
}

bool LexicalAnalyzer::findNum()
{

    QString current_token="";
    short state=0;


    while (this->currentIndex< this->input.size())
    {
        switch(state)
        {
             case 0:
                       if (this->isSign(this->input[this->currentIndex]))
                       {
                           current_token=this->input[this->currentIndex];
                           this->currentIndex++;
                           if (this->currentIndex== this->input.size())
                           {
                               qDebug()<<"Error has been detected by number automata (end of input)";
                               exit(EXIT_FAILURE);
                           }
                           state=1;
                           break;

                       }

                       else if (this->isDigit(this->input[this->currentIndex]))
                       {
                           current_token=this->input[this->currentIndex];
                             this->currentIndex++;
                           if (this->currentIndex== this->input.size())
                           {
                               TokenLexemePair a;
                               a.tokenType= NUMBER;
                               a.lexeme=current_token;
                               this->tokensList.push_back(a);
                               qDebug()<<"The number= "<< a.lexeme<<"has been deteced by number automata";
                               return true;
                           }
                             state=2;
                             break;

                       }

                       else if (this->input[this->currentIndex]=='.')
                       {
                           state=3;
                           current_token='.';
                           this->currentIndex++;
                           if (this->currentIndex== this->input.size())
                           {
                               qDebug()<<"Error has been detected by number automata (end of input)";
                               exit(EXIT_FAILURE);
                           }
                           break;
                       }

                       else
                       {
                         qDebug()<<("Nothing Found by number automata! Try Next Automata");
                         return false;
                       }


          case 1:
            if (this->input[this->currentIndex]=='.')
            {
                current_token+='.';
                this->currentIndex++;
                if (this->currentIndex== this->input.size())
                {
                    qDebug()<<"Error has been detected by number automata (end of input)";
                    exit(EXIT_FAILURE);
                }
                state=3;
                break;
            }
            else if (this->isDigit(this->input[this->currentIndex]))
            {
               current_token+= this->input[this->currentIndex];
               this->currentIndex++;
               if (this->currentIndex== this->input.size())
               {
                   TokenLexemePair a;
                   a.tokenType= NUMBER;
                   a.lexeme=current_token;
                   this->tokensList.push_back(a);
                   qDebug()<<"The number= "<< a.lexeme<<"has been deteced by number automata";
                   return true;
               }
               state=2;
               break;
            }

            else  {
                qDebug()<<"Error Has been detected by number automata! "<<endl;

                exit(EXIT_FAILURE);
            }
           case 2:
                   if (this->isDigit(this->input[this->currentIndex]))
                   {
                          state=2;
                          current_token+= this->input[this->currentIndex];
                          this->currentIndex++;
                          if (this->currentIndex== this->input.size())
                          {
                              TokenLexemePair a;
                              a.tokenType= NUMBER;
                              a.lexeme=current_token;
                              this->tokensList.push_back(a);
                              qDebug()<<"The number= "<< a.lexeme<<"has been deteced by number automata";
                              return true;
                          }
                          break;

                   }
                   else if (this->input[this->currentIndex]=='.')
                   {
                       state=3;
                       current_token+='.';
                       this->currentIndex++;
                       if (this->currentIndex== this->input.size())
                       {

                           qDebug()<<"Error has been detected by number automata (end of input)";
                           exit(EXIT_FAILURE);
                       }
                       break;
                   }

                   else {
                       TokenLexemePair a;
                       a.tokenType= NUMBER;
                       a.lexeme=current_token;
                       this->tokensList.push_back(a);
                                   qDebug()<<"The Number= "<< a.lexeme<<" has been found!"<<endl;
                                    return true;
                   }


          case 3:

                  if (this->isDigit(this->input[this->currentIndex]))
                  {
                      current_token+= this->input[this->currentIndex];
                       this->currentIndex++;
                      state=4;
                      if (this->currentIndex== this->input.size())
                      {
                          TokenLexemePair a;
                          a.tokenType= NUMBER;
                          a.lexeme=current_token;
                          this->tokensList.push_back(a);
                          qDebug()<<"The number= "<< a.lexeme<<"has been deteced by number automata";
                          return true;
                      }
                      break;
                  }


                  else {
                               qDebug()<<"ERROR has been detected by number automata (No Number after decimal)"<<endl;
                               exit(EXIT_FAILURE);
                  }


          case 4:
                 if (this->isDigit(this->input[this->currentIndex]))
                 {
                     current_token+= this->input[this->currentIndex];
                     this->currentIndex++;
                     state=4;
                     if (this->currentIndex== this->input.size())
                     {
                         TokenLexemePair a;
                         a.tokenType= NUMBER;
                         a.lexeme=current_token;
                         this->tokensList.push_back(a);
                         qDebug()<<"The number= "<< a.lexeme<<"has been deteced by number automata";
                         return true;
                     }
                     break;
                 }

                 else if (this->input[this->currentIndex]=='.')
                 {
                      qDebug()<<"ERROR has been detected by number automata (Decimal After Decimal)"<<endl;
                      exit(EXIT_FAILURE);
                 }
                 else {
                     TokenLexemePair a;
                     a.tokenType= NUMBER;
                     a.lexeme=current_token;
                     this->tokensList.push_back(a);
                     qDebug()<<"The Number= "<< a.lexeme<<" has been detected by number automata";
                     return true;
                 }

    }//end of switch
  }

    qDebug()<<"findNum did not even go into while loop due to end of input";
    return false;
}
LexicalAnalyzer::~LexicalAnalyzer()
{

}

