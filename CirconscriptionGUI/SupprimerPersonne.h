/* 
 * File:   SupprimerPersonne.h
 * Author: Rayyane Houmine 
 *
 * Created on 3 décembre 2024, 05 h 00
 */

#ifndef _SUPPRIMERPERSONNE_H
#define _SUPPRIMERPERSONNE_H

#include "ui_SupprimerPersonne.h"
#include <string>

class SupprimerPersonne : public QDialog
{
  Q_OBJECT
public:
  SupprimerPersonne ();
  virtual ~SupprimerPersonne ();
  std::string reqNas() const;
  
private slots:
    void validation();
private:
  Ui::SupprimerPersonne widget;
};

#endif /* _SUPPRIMERPERSONNE_H */
