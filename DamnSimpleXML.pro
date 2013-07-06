#-------------------------------------------------
#
# Project created by QtCreator 2013-07-03T17:37:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DamnSimpleXML
TEMPLATE = app

INCLUDEPATH += xml
INCLUDEPATH += gui

SOURCES += main.cpp\
        mainwindow.cpp \
    xml/xmlelement.cpp \
    xml/xmltree.cpp \
    xml/xmlattribute.cpp \
    xml/xmlparser.cpp \
    gui/xmltreewidget.cpp

HEADERS  += mainwindow.h \
    xml/xmlelement.h \
    xml/xmltree.h \
    xml/xmlattribute.h \
    xml/xmlparser.h \
    gui/xmltreewidget.h

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

RESOURCES += \
    resources/icons.qrc
