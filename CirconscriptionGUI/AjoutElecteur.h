/* 
 * File:   AjoutElecteur.h
 * Author: Rayyane Houmine 
 *
 * Created on December 3, 2024, 3:28 AM
 */

#ifndef _AJOUTELECTEUR_H
#define _AJOUTELECTEUR_H

#include "ui_AjoutElecteur.h"
#include <string>
#include "Date.h"
#include "validationFormat.h"

class AjoutElecteur : public QDialog
{
  Q_OBJECT
public:
  AjoutElecteur ();
  virtual ~AjoutElecteur ();
  std::string reqNom() const;
  std::string reqPrenom() const;
  std::string reqNas() const;
  std::string reqAdresse() const;
  util::Date reqDateNaissance() const;
  
private slots :
    void validationElecteur();

private:
  Ui::AjoutElecteur widget;
  util::Date m_dateNaissance;

};

#endif /* _AJOUTELECTEUR_H */
