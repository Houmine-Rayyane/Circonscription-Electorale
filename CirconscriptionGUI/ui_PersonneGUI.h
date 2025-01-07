/********************************************************************************
** Form generated from reading UI file 'PersonneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONNEGUI_H
#define UI_PERSONNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonneGUI
{
public:
    QAction *actionCandidat;
    QAction *actionElecteur;
    QAction *actionQUITTER;
    QAction *actionDesinscrire;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QTableWidget *tableWidget;
    QFrame *line;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_Personne;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *PersonneGUI)
    {
        if (PersonneGUI->objectName().isEmpty())
            PersonneGUI->setObjectName(QString::fromUtf8("PersonneGUI"));
        PersonneGUI->resize(841, 645);
        actionCandidat = new QAction(PersonneGUI);
        actionCandidat->setObjectName(QString::fromUtf8("actionCandidat"));
        actionElecteur = new QAction(PersonneGUI);
        actionElecteur->setObjectName(QString::fromUtf8("actionElecteur"));
        actionQUITTER = new QAction(PersonneGUI);
        actionQUITTER->setObjectName(QString::fromUtf8("actionQUITTER"));
        actionDesinscrire = new QAction(PersonneGUI);
        actionDesinscrire->setObjectName(QString::fromUtf8("actionDesinscrire"));
        centralwidget = new QWidget(PersonneGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(410, 60, 421, 201));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 40, 381, 541));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(380, 0, 31, 581));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 381, 41));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(410, 20, 141, 41));
        PersonneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PersonneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 841, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_Personne = new QMenu(menuMenu);
        menuAjouter_Personne->setObjectName(QString::fromUtf8("menuAjouter_Personne"));
        PersonneGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(PersonneGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PersonneGUI->setStatusBar(statusbar);
        toolBar = new QToolBar(PersonneGUI);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        PersonneGUI->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(PersonneGUI);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        PersonneGUI->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_Personne->menuAction());
        menuMenu->addAction(actionDesinscrire);
        menuMenu->addAction(actionQUITTER);
        menuAjouter_Personne->addAction(actionCandidat);
        menuAjouter_Personne->addAction(actionElecteur);

        retranslateUi(PersonneGUI);
        QObject::connect(actionQUITTER, SIGNAL(triggered()), PersonneGUI, SLOT(close()));
        QObject::connect(actionCandidat, SIGNAL(triggered()), PersonneGUI, SLOT(dialogCandidat()));
        QObject::connect(actionElecteur, SIGNAL(triggered()), PersonneGUI, SLOT(dialogElecteur()));
        QObject::connect(actionDesinscrire, SIGNAL(triggered()), PersonneGUI, SLOT(dialogSupp()));
        QObject::connect(tableWidget, SIGNAL(cellDoubleClicked(int,int)), PersonneGUI, SLOT(selectionLigneTable()));

        QMetaObject::connectSlotsByName(PersonneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *PersonneGUI)
    {
        PersonneGUI->setWindowTitle(QCoreApplication::translate("PersonneGUI", "PersonneGUI", nullptr));
        actionCandidat->setText(QCoreApplication::translate("PersonneGUI", "Candidat", nullptr));
        actionElecteur->setText(QCoreApplication::translate("PersonneGUI", "Electeur", nullptr));
        actionQUITTER->setText(QCoreApplication::translate("PersonneGUI", "Quitter", nullptr));
        actionDesinscrire->setText(QCoreApplication::translate("PersonneGUI", "Supprimer Personne", nullptr));
        affichage->setHtml(QCoreApplication::translate("PersonneGUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PersonneGUI", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PersonneGUI", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PersonneGUI", "Nas", nullptr));
        textEdit->setHtml(QCoreApplication::translate("PersonneGUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; text-decoration: underline; color:#ff0000;\">Liste des personnes inscrites : </span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("PersonneGUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; text-decoration: underline; color:#ff0000;\">Informations : </span></p></body></html>", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("PersonneGUI", "Menu", nullptr));
        menuAjouter_Personne->setTitle(QCoreApplication::translate("PersonneGUI", "Ajouter Personne", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("PersonneGUI", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("PersonneGUI", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonneGUI: public Ui_PersonneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONNEGUI_H
