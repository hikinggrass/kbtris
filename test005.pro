TEMPLATE = app
TARGET = test005
QT += core \
    gui
QT += sql
HEADERS += connection.h \
    Highscore.h \
    Daten.h \
    Steuerung.h \
    test005.h
SOURCES += Highscore.cpp \
    Daten.cpp \
    Steuerung.cpp \
    main.cpp \
    test005.cpp
FORMS += test005.ui
RESOURCES += res.qrc
LIBS += -L/isr/lib/
INCLUDEPATH += /usr/include/qt4
