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
        PersonneGUI->resize(870, 645);
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
        affichage->setGeometry(QRect(510, 0, 351, 581));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 451, 581));
        PersonneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PersonneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 870, 22));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PersonneGUI", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PersonneGUI", "Nom", nullptr));
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
