TEMPLATE = app
TARGET = qt_tutorial

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += Include

SOURCES +=  main.cpp \
    Sources/HelloWorld.cpp \
    Sources/ParentingSystem.cpp \
    Sources/RespondingEvents.cpp \
    Sources/TransmittingInformation.cpp \
    Sources/CustomSlotSignal.cpp \
    Sources/Window.cpp \
    Sources/QO_Window.cpp

HEADERS += \
    Include/HelloWorld.h \
    Include/ParentingSystem.h \
    Include/RespondindEvents.h \
    Include/TransmittingInformation.h \
    Include/CustomSlotSignal.h \
    Include/Window.h \
    Include/QO_Window.h
