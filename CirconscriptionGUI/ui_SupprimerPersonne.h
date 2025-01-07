/********************************************************************************
** Form generated from reading UI file 'SupprimerPersonne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERPERSONNE_H
#define UI_SUPPRIMERPERSONNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerPersonne
{
public:
    QLabel *label;
    QLineEdit *nas;
    QPushButton *ok;

    void setupUi(QDialog *SupprimerPersonne)
    {
        if (SupprimerPersonne->objectName().isEmpty())
            SupprimerPersonne->setObjectName(QString::fromUtf8("SupprimerPersonne"));
        SupprimerPersonne->resize(406, 298);
        label = new QLabel(SupprimerPersonne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 321, 20));
        nas = new QLineEdit(SupprimerPersonne);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(100, 130, 171, 28));
        ok = new QPushButton(SupprimerPersonne);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(140, 240, 90, 28));

        retranslateUi(SupprimerPersonne);
        QObject::connect(ok, SIGNAL(clicked()), SupprimerPersonne, SLOT(validation()));

        QMetaObject::connectSlotsByName(SupprimerPersonne);
    } // setupUi

    void retranslateUi(QDialog *SupprimerPersonne)
    {
        SupprimerPersonne->setWindowTitle(QCoreApplication::translate("SupprimerPersonne", "SupprimerPersonne", nullptr));
        label->setText(QCoreApplication::translate("SupprimerPersonne", "Veuillez entrer le Nas de la personne a supprimer", nullptr));
        ok->setText(QCoreApplication::translate("SupprimerPersonne", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerPersonne: public Ui_SupprimerPersonne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERPERSONNE_H
