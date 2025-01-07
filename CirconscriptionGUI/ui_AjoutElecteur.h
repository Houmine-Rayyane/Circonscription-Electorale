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
#include <QtWidgets/QTextEdit>

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
    QTextEdit *textEdit;

    void setupUi(QDialog *AjoutElecteur)
    {
        if (AjoutElecteur->objectName().isEmpty())
            AjoutElecteur->setObjectName(QString::fromUtf8("AjoutElecteur"));
        AjoutElecteur->resize(569, 737);
        qlabel1 = new QLabel(AjoutElecteur);
        qlabel1->setObjectName(QString::fromUtf8("qlabel1"));
        qlabel1->setGeometry(QRect(20, 70, 81, 31));
        qlabel2 = new QLabel(AjoutElecteur);
        qlabel2->setObjectName(QString::fromUtf8("qlabel2"));
        qlabel2->setGeometry(QRect(20, 150, 81, 21));
        label4 = new QLabel(AjoutElecteur);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(20, 300, 341, 21));
        calendar1 = new QLabel(AjoutElecteur);
        calendar1->setObjectName(QString::fromUtf8("calendar1"));
        calendar1->setGeometry(QRect(20, 370, 141, 21));
        Qlabel3 = new QLabel(AjoutElecteur);
        Qlabel3->setObjectName(QString::fromUtf8("Qlabel3"));
        Qlabel3->setGeometry(QRect(20, 220, 121, 31));
        prenom = new QLineEdit(AjoutElecteur);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(20, 180, 501, 31));
        adresse = new QLineEdit(AjoutElecteur);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(20, 260, 501, 31));
        nas = new QLineEdit(AjoutElecteur);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(20, 330, 501, 31));
        nom = new QLineEdit(AjoutElecteur);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(20, 110, 501, 31));
        dateN = new QCalendarWidget(AjoutElecteur);
        dateN->setObjectName(QString::fromUtf8("dateN"));
        dateN->setGeometry(QRect(20, 400, 501, 271));
        ok = new QPushButton(AjoutElecteur);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(310, 690, 90, 28));
        textEdit = new QTextEdit(AjoutElecteur);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(110, 20, 251, 41));

        retranslateUi(AjoutElecteur);
        QObject::connect(ok, SIGNAL(clicked()), AjoutElecteur, SLOT(validationElecteur()));

        QMetaObject::connectSlotsByName(AjoutElecteur);
    } // setupUi

    void retranslateUi(QDialog *AjoutElecteur)
    {
        AjoutElecteur->setWindowTitle(QCoreApplication::translate("AjoutElecteur", "AjoutElecteur", nullptr));
        qlabel1->setText(QCoreApplication::translate("AjoutElecteur", "Nom :", nullptr));
        qlabel2->setText(QCoreApplication::translate("AjoutElecteur", "Prenom :", nullptr));
        label4->setText(QCoreApplication::translate("AjoutElecteur", "Numero d' assurance sociale [ex : XXX XXX XXX]", nullptr));
        calendar1->setText(QCoreApplication::translate("AjoutElecteur", "Date de Naissance :", nullptr));
        Qlabel3->setText(QCoreApplication::translate("AjoutElecteur", "Adresse :", nullptr));
        ok->setText(QCoreApplication::translate("AjoutElecteur", "Ajouter", nullptr));
        textEdit->setHtml(QCoreApplication::translate("AjoutElecteur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline;\">Inscrire un Electeur : </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutElecteur: public Ui_AjoutElecteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTELECTEUR_H
