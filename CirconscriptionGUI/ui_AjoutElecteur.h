/********************************************************************************
** Form generated from reading UI file 'AjoutElecteur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTELECTEUR_H
#define UI_AJOUTELECTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutElecteur
{
public:
    QLabel *qlabel1;
    QLabel *qlabel2;
    QLabel *label4;
    QLabel *calendar1;
    QLabel *Qlabel3;
    QLineEdit *prenom;
    QLineEdit *adresse;
    QLineEdit *nas;
    QLineEdit *nom;
    QCalendarWidget *dateN;
    QPushButton *ok;

    void setupUi(QDialog *AjoutElecteur)
    {
        if (AjoutElecteur->objectName().isEmpty())
            AjoutElecteur->setObjectName(QString::fromUtf8("AjoutElecteur"));
        AjoutElecteur->resize(850, 737);
        qlabel1 = new QLabel(AjoutElecteur);
        qlabel1->setObjectName(QString::fromUtf8("qlabel1"));
        qlabel1->setGeometry(QRect(50, 30, 81, 51));
        qlabel2 = new QLabel(AjoutElecteur);
        qlabel2->setObjectName(QString::fromUtf8("qlabel2"));
        qlabel2->setGeometry(QRect(40, 120, 81, 41));
        label4 = new QLabel(AjoutElecteur);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(0, 300, 191, 51));
        calendar1 = new QLabel(AjoutElecteur);
        calendar1->setObjectName(QString::fromUtf8("calendar1"));
        calendar1->setGeometry(QRect(20, 390, 141, 51));
        Qlabel3 = new QLabel(AjoutElecteur);
        Qlabel3->setObjectName(QString::fromUtf8("Qlabel3"));
        Qlabel3->setGeometry(QRect(40, 210, 121, 31));
        prenom = new QLineEdit(AjoutElecteur);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(200, 120, 501, 51));
        adresse = new QLineEdit(AjoutElecteur);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(200, 210, 501, 51));
        nas = new QLineEdit(AjoutElecteur);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(200, 300, 501, 51));
        nom = new QLineEdit(AjoutElecteur);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(200, 30, 501, 51));
        dateN = new QCalendarWidget(AjoutElecteur);
        dateN->setObjectName(QString::fromUtf8("dateN"));
        dateN->setGeometry(QRect(200, 380, 501, 271));
        ok = new QPushButton(AjoutElecteur);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(310, 690, 90, 28));

        retranslateUi(AjoutElecteur);
        QObject::connect(ok, SIGNAL(clicked()), AjoutElecteur, SLOT(validationElecteur()));

        QMetaObject::connectSlotsByName(AjoutElecteur);
    } // setupUi

    void retranslateUi(QDialog *AjoutElecteur)
    {
        AjoutElecteur->setWindowTitle(QCoreApplication::translate("AjoutElecteur", "AjoutElecteur", nullptr));
        qlabel1->setText(QCoreApplication::translate("AjoutElecteur", "Nom :", nullptr));
        qlabel2->setText(QCoreApplication::translate("AjoutElecteur", "Prenom :", nullptr));
        label4->setText(QCoreApplication::translate("AjoutElecteur", "Numero d' assurance sociale :", nullptr));
        calendar1->setText(QCoreApplication::translate("AjoutElecteur", "Date de Naissance :", nullptr));
        Qlabel3->setText(QCoreApplication::translate("AjoutElecteur", "Adresse :", nullptr));
        ok->setText(QCoreApplication::translate("AjoutElecteur", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutElecteur: public Ui_AjoutElecteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTELECTEUR_H
