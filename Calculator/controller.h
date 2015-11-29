#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "postfixnotation.h"

class Controller
{
    double answer;

public:
    Controller(QString const& data);
    double getAnswer() const;
    ~Controller();
};

#endif // CONTROLLER_H
