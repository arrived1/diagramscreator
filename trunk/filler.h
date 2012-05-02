#ifndef FILLER_H
#define FILLER_H

#include <iostream>
#include <string>

class ifiller
{
public:
    virtual void fill(std::string) = 0;
};

class filler : public ifiller
{
public:
    virtual void fill(std::string);
    bool checkParentisis(std::string);
    bool checkBraces(std::string);
};

#endif // FILLER_H
