#-------------------------------------------------
#
# Project created by QtCreator 2021-01-02T16:04:36
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

TARGET = Learning_Computer_Vision
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        Learn_Computer_Vision_Dialog.cpp \
    HomepageWidget.cpp \
    SelectModuleWidget.cpp \
    TrainWidget.cpp \
    VisualizationWidget.cpp \
    AnnotationWidget.cpp \
    ParameterControlBlock.cpp \
	pythoncomm.cpp

HEADERS += \
        Learn_Computer_Vision_Dialog.h \
    HomepageWidget.h \
    SelectModuleWidget.h \
    TrainWidget.h \
    VisualizationWidget.h \
    AnnotationWidget.h \
    ParameterControlBlock.h \
	pythoncomm.h

FORMS += \
        Learn_Computer_Vision_Dialog.ui \
    HomepageWidget.ui \
    SelectModuleWidget.ui \
    TrainWidget.ui \
    VisualizationWidget.ui \
    AnnotationWidget.ui

RESOURCES += \
	resourse.qrc
