#ifndef FILLINHERITS_H
#define FILLINHERITS_H

#include <string>
#include "filler.h"

class fillinherits : public filler
{
public:
    fillinherits();
    void fill(std::string line);
};

#endif // FILLINHERITS_H
