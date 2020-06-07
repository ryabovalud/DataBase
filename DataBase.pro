#-------------------------------------------------
#
# Project created by QtCreator 2018-10-02T08:50:43
#
#-------------------------------------------------

QT += printsupport
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataBase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/ -llimereport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/ -llimereportd

INCLUDEPATH += $$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/include
DEPENDPATH += $$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/ -lQtZint
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/ -lQtZintd

INCLUDEPATH += $$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/include
DEPENDPATH += $$PWD/../LimeReport-master/build/5.5.1/win32/debug/lib/include
