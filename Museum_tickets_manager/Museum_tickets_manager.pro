#-------------------------------------------------
#
# Project created by QtCreator 2015-12-07T17:51:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Museum_tickets_manager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    biglietto.cpp \
    bigliettoordinario.cpp \
    bigliettoridotto.cpp \
    ridottobambini.cpp \
    ridottodisabili.cpp \
    listabiglietti.cpp \
    aggiungiwindow.cpp \
    rimuoviwindow.cpp \
    modificawindow.cpp \
    confermawindow.cpp \
    visualizzawindow.cpp \
    sogliawindow.cpp

HEADERS  += mainwindow.h \
    biglietto.h \
    bigliettoordinario.h \
    bigliettoridotto.h \
    ridottobambini.h \
    ridottodisabili.h \
    listabiglietti.h \
    aggiungiwindow.h \
    rimuoviwindow.h \
    modificawindow.h \
    confermawindow.h \
    visualizzawindow.h \
    sogliawindow.h

FORMS    +=

RESOURCES += \
    immagini.qrc
