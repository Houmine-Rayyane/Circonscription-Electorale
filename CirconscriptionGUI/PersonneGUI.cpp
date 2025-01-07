/*
 * File:   PersonneGUI.cpp
 * Author: Rayyane Houmine 
 *
 * Created on 3 décembre 2024, 00 h 53
 */

#include "PersonneGUI.h"
#include "AjoutCandidat.h"
#include "AjoutElecteur.h"
#include "PersonneException.h"
#include <QMessageBox>
#include "SupprimerPersonne.h"
#include "Circonscription.h"


using namespace elections;

Candidat inconnu("046 454 286", "Rayyane", "Houmine", "2255, Rue de l'universite", util::Date(20,06,2004), INDEPENDANT);
PersonneGUI::PersonneGUI () : m_circonscription (" Circonscription n0 1",inconnu)
{
  widget.setupUi (this);
  widget.tableWidget->setColumnWidth(0,190);
  widget.tableWidget->setColumnWidth(1,190);
  widget.tableWidget->setColumnHidden(2, true);

}

PersonneGUI::~PersonneGUI () { }


void PersonneGUI :: dialogCandidat()
{
  AjoutCandidat CAND;
  if (CAND.exec())
    {
      try
        {
      m_circonscription.inscrire(Candidat(CAND.reqNas(),
                                 CAND.reqPrenom(),
                                 CAND.reqNom(),
                                 CAND.reqAdresse(),
                                 CAND.reqDateNaissance(),
                                 CAND.reqPartiPolitique())
                                 );
      //widget.affichage->setText(m_circonscription.reqCirconscriptionFormate ().c_str());
      int nbreLignes = widget.tableWidget->rowCount ();
      widget.tableWidget->setRowCount (nbreLignes+1);
      
      QString p_nom = QString::fromStdString (CAND.reqNom());
      QString p_prenom = QString::fromStdString (CAND.reqPrenom());
      QString p_nas = QString::fromStdString (CAND.reqNas());

      
      widget.tableWidget->setItem(nbreLignes, 0 , new QTableWidgetItem(p_prenom));
      widget.tableWidget->setItem(nbreLignes, 1 , new QTableWidgetItem(p_nom));
      widget.tableWidget->setItem(nbreLignes, 2 , new QTableWidgetItem(p_nas));
      
      QMessageBox::information(this, "Confirmation", "Le candidat a été ajouté avec succès.");


    }
      catch (PersonneDejaPresenteException& e)
        {
          QMessageBox::information (this,"Ereur",e.what());
        }
}
}

void PersonneGUI :: dialogElecteur()
{
  AjoutElecteur ELEC;
  if (ELEC.exec())
    {
      try
        {
      m_circonscription.inscrire(Electeur(ELEC.reqNas(),
                                 ELEC.reqPrenom(),
                                 ELEC.reqNom(),
                                 ELEC.reqAdresse(),
                                 ELEC.reqDateNaissance())
                                 );
      //widget.affichage->setText(m_circonscription.reqCirconscriptionFormate ().c_str());
      int nbreLignes = widget.tableWidget->rowCount();
            widget.tableWidget->setRowCount(nbreLignes + 1);

            QString p_nom = QString::fromStdString(ELEC.reqNom());
            QString p_prenom = QString::fromStdString(ELEC.reqPrenom());
            QString p_nas = QString::fromStdString (ELEC.reqNas());


            widget.tableWidget->setItem(nbreLignes, 0, new QTableWidgetItem(p_prenom));
            widget.tableWidget->setItem(nbreLignes, 1, new QTableWidgetItem(p_nom));
            widget.tableWidget->setItem(nbreLignes, 2, new QTableWidgetItem(p_nas));

            QMessageBox::information(this, "Confirmation", "L'electeur a été ajouté avec succès.");

        }
      catch (PersonneDejaPresenteException& e) {
                    QMessageBox::information (this,"Ereur",e.what());
        }
    }
}

void PersonneGUI :: dialogSupp()
{
  SupprimerPersonne supp;
  if (supp.exec())
    {
      try {
      m_circonscription.desinscrire(supp.reqNas ());
        for (int i = 0; i < widget.tableWidget->rowCount(); ++i)
            {
                QTableWidgetItem *itemNas = widget.tableWidget->item(i, 2); 

                if (itemNas && itemNas->text().toStdString() == supp.reqNas())
                {
                    
                    widget.tableWidget->removeRow(i);
                    widget.affichage->clear();
                    
                    QMessageBox::information(this, "Succès", "La personne a été supprimée avec succès.");
                    return;
                }
            }
      
    }catch (PersonneAbsenteException& e)
      {
        QMessageBox::information (this, "Erreur",e.what());
      }
}
}

void
PersonneGUI::selectionLigneTable ()
{
  int ligne = widget.tableWidget->currentRow();
    if (ligne < 0) return;

    QTableWidgetItem* prenomItem = widget.tableWidget->item(ligne, 0);
    QTableWidgetItem* nomItem = widget.tableWidget->item(ligne, 1);

    // Afficher les détails de la personne sélectionnée
    QString details = QString::fromStdString(m_circonscription.reqPersonneSelection(
        nomItem->text().toStdString(), prenomItem->text().toStdString()));

    widget.affichage->setText(details);
}