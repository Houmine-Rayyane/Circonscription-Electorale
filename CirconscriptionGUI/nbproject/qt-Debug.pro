# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = CirconscriptionGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutCandidat.cpp AjoutElecteur.cpp PersonneGUI.cpp SupprimerPersonne.cpp main.cpp
HEADERS += AjoutCandidat.h AjoutElecteur.h PersonneGUI.h SupprimerPersonne.h
FORMS += AjoutCandidat.ui AjoutElecteur.ui PersonneGUI.ui SupprimerPersonne.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../source 
LIBS += ../source/dist/Debug/GNU-Linux/libsource.a  
