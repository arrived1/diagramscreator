TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    filemanager.cpp \
    fillmethods.cpp \
    fillinherits.cpp \
    filler.cpp \
    filler_test.cpp \
    filemanager_test.cpp

HEADERS += \
    filemanager.h \
    class.h \
    method.h \
    typeandname.h \
    filler.h \
    fillmethods.h \
    fillinherits.h

OTHER_FILES += \
    listaPlikow.txt

