#include <iostream>

#include "filemanager.h"
#include "class.h"

int main()
{
    std::string fileName;
    std::cout << "Podaj nazwe pliku z klasami:" << std::endl;
    std::cin >> fileName;

    fileManager fileMgr(fileName);

}

