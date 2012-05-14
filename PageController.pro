TEMPLATE = app
CONFIG += console
CONFIG -= qt

QMAKE_CXXFLAGS += -pthread -std=c++0x -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -Wctor-dtor-privacy -Wnon-virtual-dtor -Wold-style-cast -Wconversion -Wsign-conversion -Winit-self -Wunreachable-code

LIBS += -lpthread

SOURCES += main.cpp \
    MainHandler.cpp \
File.cpp\
FileUtils.cpp\
Logger.cpp\
OSUtils.cpp\
Socket.cpp\
Stream.cpp\
Thread.cpp\
Util.cpp \
Client.cpp\
Http.cpp\
HttpHelpers.cpp\
Server.cpp \
    OtherHandler.cpp

HEADERS += \
    MainHandler.h \
File.h\
FileUtils.h\
Logger.h\
OSUtils.h\
Socket.h\
Stream.h\
Thread.h\
Util.h\
Client.h\
Http.h\
HttpHelpers.h\
Server.h\
WebToolkit.h \
    OtherHandler.h
