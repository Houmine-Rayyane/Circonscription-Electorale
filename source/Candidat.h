/**
 * \file Candidat.h
 * \brief déclarations de la classe Candidat.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */

#ifndef CANDIDAT_H
#define CANDIDAT_H

#include"Personne.h"

/**
 * enum PartisPolitique
 * brief Represente les principaux partis politiques dans le contexte de ce Tp2
 * Les valeurs des partis commencent de 0 a 4 
 */
enum PartisPolitiques
{
  BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
  NOUVEAU_PARTI_DEMOCRATIQUE
};

/**
 * \namespace elections
 * \brief Ce namespace contient toutes les classes demandees pour ce Tp2
 * Candidat , Personne , Electeur , Circonscription
 */
namespace elections{
  
 /**
 * \class Candidat
 * \brief Prototype de la classe Candidat qui represente les inforrmations liees
  * au candidat dans un systeme de gestion de circonscriptions electorales.
  * Elle herite de la classe Personne mais ajoute la fonctionnalite de
  * l'affiliation politique.
 */  
class Candidat: public Personne
{
public:
  
  //Constructeur 
  Candidat (const std::string& p_nas, const std::string& p_prenom,
            const std::string& p_nom, const std::string& p_adresse,
            const util::Date& p_dateNaissance, int p_partiPolitique);
  //Accesseur
  int reqPartiPolitique () const;
  
  std::string reqStringParti() const;
  virtual std::unique_ptr <Personne> clone () const;
  
  virtual std::string reqPersonneFormate ()const;
  
private:
  
  
  int m_partiPolitique;
  void verifieInvariant() const;
};
}
#endif /* CANDIDAT_H */

