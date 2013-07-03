#-------------------------------------------------
#
# Project created by QtCreator 2013-07-03T17:37:27
#
#-------------------------------------------------

QT       += core gui

TARGET = DamnXML
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xml/xmlelement.cpp

HEADERS  += mainwindow.h \
    xml/xmlelement.h

FORMS    += mainwindow.ui

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
} else {
    DESTDIR = build/release
}

OBJECTS_DIR = build/tmp/obj
MOC_DIR = build/tmp/moc
RCC_DIR = build/tmp/rcc
UI_DIR = build/tmp/ui
