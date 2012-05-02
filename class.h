#ifndef CLASS_H
#define CLASS_H

#include "method.h"
#include "typeandname.h"

struct classCpp
{
    std::string name;

    std::vector<typeAndName> inherits;
    std::vector<methodCpp> methods;
    std::vector<typeAndName> members;
};

#endif // CLASS_H
