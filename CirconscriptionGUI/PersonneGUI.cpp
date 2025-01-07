/*
 * File:   PersonneGUI.cpp
 * Author: Rayyane Houmine & Hassan Alaoui
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
  widget.tableWidget->setColumnWidth(0,225);
  widget.tableWidget->setColumnWidth(1,225);

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
      
      widget.tableWidget->setItem(nbreLignes, 0 , new QTableWidgetItem(p_prenom));
      widget.tableWidget->setItem(nbreLignes, 1 , new QTableWidgetItem(p_nom));

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
      widget.affichage->setText(m_circonscription.reqCirconscriptionFormate ().c_str());
    }catch (PersonneAbsenteException& e)
      {
        QMessageBox::information (this, "Erreur",e.what());
      }
}
}

void
PersonneGUI::selectionLigneTable ()
{
  int ligne = widget.tableWidget->currentRow ();
  QTableWidgetItem *tNom = widget.tableWidget->item (ligne, 0);
  QTableWidgetItem *tPrenom = widget.tableWidget->item (ligne, 1);
  
  widget.affichage->setText ((m_circonscription.reqPersonneSelection ( (*tNom).text().toStdString(),(*tPrenom).text().toStdString() ).c_str() ));
}