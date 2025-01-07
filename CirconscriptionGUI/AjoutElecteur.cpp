/*
 * File:   AjoutElecteur.cpp
 * Author: Rayyane Houmine 
 *
 * Created on December 3, 2024, 3:28 AM
 */

#include "AjoutElecteur.h"
#include "QMessageBox"

AjoutElecteur::AjoutElecteur ()
{
  widget.setupUi (this);
}

AjoutElecteur::~AjoutElecteur () { }

std::string AjoutElecteur::reqNom() const
{
  return widget.nom->text().toStdString();
}
std::string AjoutElecteur::reqPrenom() const{
    return widget.prenom->text().toStdString();

}
std::string AjoutElecteur::reqNas() const
{
    return widget.nas->text().toStdString();
}
std::string AjoutElecteur::reqAdresse() const
{
    return widget.adresse->text().toStdString();
}
util::Date AjoutElecteur::reqDateNaissance() const
{
  return m_dateNaissance;
}

void AjoutElecteur::validationElecteur()
{
  if (reqNom().empty())
    {
      QString message("Le nom ne doit pas etre vide");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  if (reqPrenom().empty())
    {
      QString message("Le prenom ne doit pas etre vide");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  if (!validerNas(reqNas()))
    {
      QString message("Le nas doit etre valide");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  if (reqAdresse().empty())
    {
      QString message("L'adresse ne doit pas etre vide");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  QDate dateCourant = QDate::currentDate();
  if (widget.dateN->selectedDate () >= dateCourant)
    {
      QString message("La date ne doit pas etre dans le futur");
      QMessageBox::information (this,"Erreur",message);
      return;
    }
  else{
      m_dateNaissance.asgDate(widget.dateN->selectedDate ().day(),
                              widget.dateN->selectedDate ().month (),
                              widget.dateN->selectedDate ().year ());
    }
  accept();
}
