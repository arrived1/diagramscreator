#include "filemanager.h"

fileManager::fileManager(std::string fileName)
{
    std::ifstream file;
    file.open(fileName.c_str());

    while(not file.eof())
    {
        std::string txt;
        getline(file, txt);
        checkAndStore(txt);
    }

    file.close();
}

fileManager::fileList& fileManager::getFilesList()
{
    return list;
}

void fileManager::checkAndStore(std::string fileName)
{
    std::string fileExtension = "hpp";
    if(fileName.find(fileExtension) != std::string::npos)
    {
        list.push_back(fileName);
    }
}
