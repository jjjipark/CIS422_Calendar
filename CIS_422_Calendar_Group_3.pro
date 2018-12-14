# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = CIS_422_Calendar_Group_3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS =

HEADERS = \
    include/Add_Window.h \
    include/Controller.hpp \
    include/EventStructs.hpp \
    include/Model.hpp \
    include/sqlite3.h \
    include/Weekly.h \
    include/Event_Button.h \
    include/Interval.hpp

SOURCES = \
    ext/sqlite3.c \
    src/Add_Window.cpp \
    src/Controller.cpp \
    src/main.cpp \
    src/Model.cpp \
    src/Event_Button.cpp \
    src/Weekly.cpp \
    src/Interval.cpp

INCLUDEPATH = \
    $$PWD/include

CONFIG += static

FORMS += \
    ui/Weekly.ui \
    ui/Add_Window.ui

