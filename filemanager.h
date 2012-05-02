#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class fileManager
{  
public:
    typedef std::vector<std::string> fileList;

    fileManager(std::string fileName);
    fileList& getFilesList();

private:
    void checkAndStore(std::string fileName);

    fileList list;
};

#endif // FILEMANAGER_H
