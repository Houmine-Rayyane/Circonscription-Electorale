/*
 * File:   SupprimerPersonne.cpp
 * Author: Rayyane Houmine 
 *
 * Created on 3 décembre 2024, 05 h 00
 */

#include "SupprimerPersonne.h"
#include "validationFormat.h"
#include <QMessageBox>

SupprimerPersonne::SupprimerPersonne ()
{
  widget.setupUi (this);
}

SupprimerPersonne::~SupprimerPersonne () { }

std::string SupprimerPersonne::reqNas() const
{
    return widget.nas->text().toStdString();
}
void SupprimerPersonne::validation()
{
  if (!validerNas(reqNas()))
    {
      QString message("Le nas doit etre valide");
      QMessageBox::information (this, "Erreur", message);
      return;
    }
  accept();
}