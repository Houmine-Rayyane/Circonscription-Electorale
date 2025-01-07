/* 
 * File:   PersonneGUI.h
 * Author: Rayyane Houmine 
 *
 * Created on 3 décembre 2024, 00 h 53
 */

#ifndef _PERSONNEGUI_H
#define _PERSONNEGUI_H

#include "ui_PersonneGUI.h"
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"



class PersonneGUI : public QMainWindow
{
  Q_OBJECT
public:
  PersonneGUI ();
  virtual ~PersonneGUI ();
  private slots:
    void dialogCandidat();
    void dialogElecteur();
    void dialogSupp();
    void selectionLigneTable ();
    
private:
  Ui::PersonneGUI widget;
  elections::Circonscription m_circonscription;
};

#endif /* _PERSONNEGUI_H */
