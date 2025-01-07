/* 
 * File:   AjoutCandidat.h
 * Author: Rayyane Houmine & Hassan Alaoui
 *
 * Created on 3 décembre 2024, 01 h 36
 */

#ifndef _AJOUTCANDIDAT_H
#define _AJOUTCANDIDAT_H

#include "ui_AjoutCandidat.h"
#include <string>
#include "Date.h"
#include "validationFormat.h"

class AjoutCandidat : public QDialog
{
  Q_OBJECT
public:
  AjoutCandidat ();
  virtual ~AjoutCandidat ();
  std::string reqNom() const;
  std::string reqPrenom() const;
  std::string reqNas() const;
  std::string reqAdresse() const;
  util::Date reqDateNaissance() const;
  int reqPartiPolitique() const;
  private slots : 
    void validationCandidat();
private:
  Ui::AjoutCandidat widget;
  util::Date m_dateNaissance;
};

#endif /* _AJOUTCANDIDAT_H */
