/********************************************************************************
** Form generated from reading UI file 'AjoutCandidat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCANDIDAT_H
#define UI_AJOUTCANDIDAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AjoutCandidat
{
public:
    QLabel *label;
    QLineEdit *nom;
    QLabel *label_2;
    QLineEdit *prenom;
    QLabel *label_3;
    QCalendarWidget *dateN;
    QLabel *label_4;
    QLineEdit *nas;
    QLabel *label_5;
    QLineEdit *adresse;
    QLabel *label_6;
    QSpinBox *parti;
    QPushButton *ok;
    QTextEdit *textEdit;

    void setupUi(QDialog *AjoutCandidat)
    {
        if (AjoutCandidat->objectName().isEmpty())
            AjoutCandidat->setObjectName(QString::fromUtf8("AjoutCandidat"));
        AjoutCandidat->resize(488, 731);
        label = new QLabel(AjoutCandidat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 91, 31));
        nom = new QLineEdit(AjoutCandidat);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(40, 110, 431, 28));
        label_2 = new QLabel(AjoutCandidat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 150, 81, 21));
        prenom = new QLineEdit(AjoutCandidat);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(40, 180, 431, 28));
        label_3 = new QLabel(AjoutCandidat);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 360, 121, 20));
        dateN = new QCalendarWidget(AjoutCandidat);
        dateN->setObjectName(QString::fromUtf8("dateN"));
        dateN->setGeometry(QRect(40, 390, 431, 201));
        label_4 = new QLabel(AjoutCandidat);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 290, 71, 21));
        nas = new QLineEdit(AjoutCandidat);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(40, 250, 431, 28));
        label_5 = new QLabel(AjoutCandidat);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 220, 371, 16));
        adresse = new QLineEdit(AjoutCandidat);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(40, 320, 431, 28));
        label_6 = new QLabel(AjoutCandidat);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 600, 101, 31));
        parti = new QSpinBox(AjoutCandidat);
        parti->setObjectName(QString::fromUtf8("parti"));
        parti->setGeometry(QRect(80, 640, 101, 26));
        ok = new QPushButton(AjoutCandidat);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(190, 690, 90, 28));
        textEdit = new QTextEdit(AjoutCandidat);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 20, 231, 31));

        retranslateUi(AjoutCandidat);
        QObject::connect(ok, SIGNAL(clicked()), AjoutCandidat, SLOT(validationCandidat()));

        QMetaObject::connectSlotsByName(AjoutCandidat);
    } // setupUi

    void retranslateUi(QDialog *AjoutCandidat)
    {
        AjoutCandidat->setWindowTitle(QCoreApplication::translate("AjoutCandidat", "AjoutCandidat", nullptr));
        label->setText(QCoreApplication::translate("AjoutCandidat", "Nom ", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutCandidat", "Prenom ", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutCandidat", "Date de naissance ", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutCandidat", "Adresse ", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutCandidat", "Numero d'assurance sociale [ex : XXX XXX XXX]", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutCandidat", "Parti Politique", nullptr));
        ok->setText(QCoreApplication::translate("AjoutCandidat", "Ajouter ", nullptr));
        textEdit->setHtml(QCoreApplication::translate("AjoutCandidat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline;\">Inscrire un Candidat </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutCandidat: public Ui_AjoutCandidat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCANDIDAT_H
