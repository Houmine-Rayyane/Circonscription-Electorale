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

    void setupUi(QDialog *AjoutCandidat)
    {
        if (AjoutCandidat->objectName().isEmpty())
            AjoutCandidat->setObjectName(QString::fromUtf8("AjoutCandidat"));
        AjoutCandidat->resize(841, 695);
        label = new QLabel(AjoutCandidat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 50, 91, 31));
        nom = new QLineEdit(AjoutCandidat);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(200, 50, 431, 28));
        label_2 = new QLabel(AjoutCandidat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 130, 81, 21));
        prenom = new QLineEdit(AjoutCandidat);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(200, 120, 431, 28));
        label_3 = new QLabel(AjoutCandidat);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 340, 121, 20));
        dateN = new QCalendarWidget(AjoutCandidat);
        dateN->setObjectName(QString::fromUtf8("dateN"));
        dateN->setGeometry(QRect(200, 320, 431, 211));
        label_4 = new QLabel(AjoutCandidat);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 270, 71, 21));
        nas = new QLineEdit(AjoutCandidat);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(200, 190, 431, 28));
        label_5 = new QLabel(AjoutCandidat);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 200, 181, 16));
        adresse = new QLineEdit(AjoutCandidat);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(200, 260, 431, 28));
        label_6 = new QLabel(AjoutCandidat);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 570, 101, 31));
        parti = new QSpinBox(AjoutCandidat);
        parti->setObjectName(QString::fromUtf8("parti"));
        parti->setGeometry(QRect(200, 570, 42, 26));
        ok = new QPushButton(AjoutCandidat);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(330, 650, 90, 28));

        retranslateUi(AjoutCandidat);
        QObject::connect(ok, SIGNAL(clicked()), AjoutCandidat, SLOT(validationCandidat()));

        QMetaObject::connectSlotsByName(AjoutCandidat);
    } // setupUi

    void retranslateUi(QDialog *AjoutCandidat)
    {
        AjoutCandidat->setWindowTitle(QCoreApplication::translate("AjoutCandidat", "AjoutCandidat", nullptr));
        label->setText(QCoreApplication::translate("AjoutCandidat", "Nom :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutCandidat", "Prenom : ", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutCandidat", "Date de naissance :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutCandidat", "Adresse : ", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutCandidat", "Numero d'assurance sociale : ", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutCandidat", "Parti Politique :", nullptr));
        ok->setText(QCoreApplication::translate("AjoutCandidat", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutCandidat: public Ui_AjoutCandidat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCANDIDAT_H
