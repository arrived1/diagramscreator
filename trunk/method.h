#ifndef METHOD_H
#define METHOD_H

#include <string>
#include <vector>

struct methodCpp
{
    typedef std::vector<std::pair<std::string, std::string> > argumenstList;
    std::string returnType;
    std::string name;
    argumenstList args;
};

#endif // METHOD_H
