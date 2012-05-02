#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include <string>

#include "filler.h"

using namespace ::testing;

TEST(filler_test, checkParentisis_test)
{
    filler basicFiller;

    std::string txt = "dupa bla i konieC $%^ ale nie Jednak";
    ASSERT_EQ(false, basicFiller.checkParentisis(txt));

    txt.clear();
    txt = "sdfks;ldfks(sdkfsd sldfkjsdf ( lkdsfjsd (";
    ASSERT_EQ(false, basicFiller.checkParentisis(txt));

    txt.clear();
    txt = "sdfks;ldfks)sdkfsd sldfkjsdf ) lkdsfjsd [ ] ' ";
    ASSERT_EQ(false, basicFiller.checkParentisis(txt));

    txt.clear();
    txt = "sdfk(s;ldfks)sdkfsd sldfkjsdf ) lkdsfjsd";
    ASSERT_EQ(true, basicFiller.checkParentisis(txt));

    txt.clear();
    txt = "";
    ASSERT_EQ(false, basicFiller.checkParentisis(txt));
}

TEST(filler_test, checkBraces_test)
{
    filler basicFiller;

    std::string txt = "dupa bla i konieC $%^ ale nie Jednak";
    ASSERT_EQ(false, basicFiller.checkBraces(txt));

    txt.clear();
    txt = "sdfks;ldfks{(sdkfsd sldfkjsdf ( {lkdsfjsd {(";
    ASSERT_EQ(true, basicFiller.checkBraces(txt));

    txt.clear();
    txt = "sdfks;ldfks}sdkfsd sldfkjsdf )} lkdsfjsd [ ] ' }";
    ASSERT_EQ(true, basicFiller.checkBraces(txt));

    txt.clear();
    txt = "sdfk({s;ldfks)}sdkfsd sldfkjsdf )} lkdsfjsd";
    ASSERT_EQ(true, basicFiller.checkBraces(txt));

    txt.clear();
    txt = "";
    ASSERT_EQ(false, basicFiller.checkBraces(txt));
}