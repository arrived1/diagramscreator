CXX           = g++
CXXFLAGS      = -O2 -frtti -fexceptions -mthreads -Wall -Wextra -I C:/boost_1_48_0/
CPPFLAGS      = -I$(GTEST_DIR)/include -I$(GMOCK_DIR)/include
LINK          = g++
LFLAGS        = -Wl,-s -Wl,-subsystem,console -mthreads
DEL_FILE      = rm

GTEST_DIR = C:/gtest-1.6.0
GMOCK_DIR = C:/gmock-1.6.0



####### Files

SOURCES = main.cpp \
		filemanager.cpp \
		fillmethods.cpp \
		fillinherits.cpp \
		filler.cpp 
OBJECTS = filemanager.o \
		fillmethods.o \
		fillinherits.o \
		filler.o

TEST_SOURCES = filler_test.cpp \
		filemanager_test.cpp
TEST_OBJECTS = filler_test.o \
		filemanager_test.o



DESTDIR_TARGET = diagrams.exe
TESTS = tests



####### Implicit rules

.SUFFIXES: .cpp 

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<



####### Build rules

all: $(DESTDIR_TARGET) $(TESTS)

$(DESTDIR_TARGET): $(OBJECTS) main.o
	$(LINK) $(LFLAGS) -o $(DESTDIR_TARGET) $(OBJECTS) main.o

$(TESTS): $(TEST_OBJECTS) $(OBJECTS) gmock_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

clean: 
	rm *.o




####### Compile

main.o: main.cpp filemanager.h \
		class.h \
		method.h \
		typeandname.h
	$(CXX) -c $(CXXFLAGS) -o main.o main.cpp

filemanager.o: filemanager.cpp filemanager.h
	$(CXX) -c $(CXXFLAGS) -o filemanager.o filemanager.cpp

fillmethods.o: fillmethods.cpp fillmethods.h \
		filler.h
	$(CXX) -c $(CXXFLAGS) -o fillmethods.o fillmethods.cpp

fillinherits.o: fillinherits.cpp fillinherits.h \
		filler.h
	$(CXX) -c $(CXXFLAGS) -o fillinherits.o fillinherits.cpp

filler.o: filler.cpp filler.h
	$(CXX) -c $(CXXFLAGS) -o filler.o filler.cpp



filler_test.o : filler_test.cpp $(GMOCK_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c filler_test.cpp

filemanager_test.o : filemanager_test.cpp $(GMOCK_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c filemanager_test.cpp

####### GTest GMock


GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h

GMOCK_HEADERS = $(GMOCK_DIR)/include/gmock/*.h \
		$(GMOCK_DIR)/include/gmock/internal/*.h \
		$(GTEST_HEADERS)

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
GMOCK_SRCS_ = $(GMOCK_DIR)/src/*.cc $(GMOCK_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) -I$(GMOCK_DIR) $(CXXFLAGS) \
            -c $(GTEST_DIR)/src/gtest-all.cc

gmock-all.o : $(GMOCK_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) -I$(GMOCK_DIR) $(CXXFLAGS) \
            -c $(GMOCK_DIR)/src/gmock-all.cc

gmock_main.o : $(GMOCK_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) -I$(GMOCK_DIR) $(CXXFLAGS) \
            -c $(GMOCK_DIR)/src/gmock_main.cc

gmock.a : gmock-all.o gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gmock_main.a : gmock-all.o gtest-all.o gmock_main.o
	$(AR) $(ARFLAGS) $@ $^




