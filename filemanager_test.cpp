#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include <string>

#include "filemanager.h"

using namespace ::testing;

TEST(fileManager_test, getFilesList_test)
{
    std::string path = "C:/Users/arrived/Desktop/diagrams/listaPlikow.txt";

    fileManager fileMgr(path);
    fileManager::fileList list = fileMgr.getFilesList();

    ASSERT_EQ("dupa1.hpp", list[0]);
    ASSERT_EQ("nikurde.hpp", list[1]);
    ASSERT_EQ("niepowimCi.hpp", list[2]);
    ASSERT_EQ("gdzie.hpp", list[3]);
    ASSERT_EQ("WDUPEJEZA.hpp", list[4]);
}
