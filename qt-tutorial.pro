TEMPLATE = app
TARGET = qt_tutorial

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += Include

SOURCES +=  main.cpp \
    Sources/HelloWorld.cpp \
    Sources/ParentingSystem.cpp \

HEADERS += \
    Include/HelloWorld.h \
    Include/ParentingSystem.h
