/*
 * File:   AjoutCandidat.cpp
 * Author: Rayyane Houmine 
 *
 * Created on 3 décembre 2024, 01 h 36
 */

#include "AjoutCandidat.h"
#include <QMessageBox>

AjoutCandidat::AjoutCandidat ()
{
  widget.setupUi (this);
}

AjoutCandidat::~AjoutCandidat () { }

std::string AjoutCandidat::reqNom() const
{
  return widget.nom->text().toStdString();
}
std::string AjoutCandidat::reqPrenom() const{
    return widget.prenom->text().toStdString();

}
std::string AjoutCandidat::reqNas() const
{
    return widget.nas->text().toStdString();
}
std::string AjoutCandidat::reqAdresse() const
{
    return widget.adresse->text().toStdString();
}
util::Date AjoutCandidat::reqDateNaissance() const
{
  return m_dateNaissance;
}
int AjoutCandidat::reqPartiPolitique() const
{
  return widget.parti->value();
}

void AjoutCandidat::validationCandidat()
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
  if (reqPartiPolitique()<0 || reqPartiPolitique()>4)
    {
      QString message("Le parti politique doit etre compris entre 0 et 4 ");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  accept();
}
