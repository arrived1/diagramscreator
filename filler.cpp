#include "filler.h"

void filler::fill(std::string)
{
    std::cout << "You shuld not use this metod !!!";
}

bool filler::checkParentisis(std::string line)
{
    if(line.find('(') != std::string::npos and
       line.find(')') != std::string::npos)
        return true;
    return false;
}

bool filler::checkBraces(std::string line)
{
    if(line.find('{') != std::string::npos or
       line.find('}') != std::string::npos)
        return true;
    return false;
}
