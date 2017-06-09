#-------------------------------------------------
#
# Project created by QtCreator 2017-05-04T00:17:50
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projektarbeit_D
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    gameframe.cpp \
    border.cpp \
    background.cpp \
    borderpart.cpp \
    separator.cpp \
    slot.cpp \
    square.cpp \
    credit.cpp \
    music.cpp \
    creditoutput.cpp \
    animation.cpp

HEADERS  += \
    gameframe.h \
    border.h \
    background.h \
    borderpart.h \
    separator.h \
    slot.h \
    square.h \
    credit.h \
    music.h \
    creditoutput.h \
    animation.h

FORMS    +=

DISTFILES += \
    Slotmachine.qml

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../Coding/Qt/5.8/msvc2015_64/lib/ -lQt5Multimedia
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../Coding/Qt/5.8/msvc2015_64/lib/ -lQt5Multimediad
else:unix: LIBS += -L$$PWD/../../../../../../Coding/Qt/5.8/msvc2015_64/lib/ -lQt5Multimedia

#INCLUDEPATH += $$PWD/../../../../../../Coding/Qt/5.8/msvc2015_64/include
#DEPENDPATH += $$PWD/../../../../../../Coding/Qt/5.8/msvc2015_64/include

INCLUDEPATH += $$PWD/../../../../../../Coding/Qt/5.9/msvc2015_64/include
DEPENDPATH += $$PWD/../../../../../../Coding/Qt/5.9/msvc2015_64/include

unix|win32: LIBS += -lQt5Multimedia
