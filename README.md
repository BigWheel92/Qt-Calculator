# Qt-Calculator
The Calculator can perform addition, subtraction, multiplication, and division. It can also handle parentheses and precedence. It can also handle negative and decimal numbers.

Steps) 
1) The arithmetic expression given by the user is passed to "Lexical Analyzer". Lexical Analyzer parses and validates the
  arithmetic expression and forms tokens of the expression.

2) If the expression is well formed (i.e. if the expression is correct) then the Lexical Analyzer gives the tokens to "PostFix Notation". PostFix Notation
   converts the tokenized arithmetic expression to postfix notation and then evaluates the expression.
