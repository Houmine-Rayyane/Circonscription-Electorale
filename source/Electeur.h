/**
 * \file Electeur.h
 * \brief déclarations de la classe Electeur.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */

#ifndef ELECTEUR_H
#define ELECTEUR_H
#include "Personne.h"

/**
 * \namespace elections
 * \brief Ce namespace contient toutes les classes demandees pour ce Tp2
 * Candidat , Personne , Electeur , Circonscription
 */
namespace elections{

 /**
 * \class Electeur
 * \brief Prototype de la classe Electeur qui represente les informations liees
  * a l'electeur dans un systeme de gestion de circonscriptions electorales.
  * Elle herite de la classe Personne 
 */ 
class Electeur: public Personne
{
public:
  //Constructeur
  Electeur (const std::string& p_nas, const std::string& p_prenom,
            const std::string& p_nom, const std::string& p_adresse,
            const util::Date& p_dateNaissance);
  
 
  virtual std::unique_ptr < Personne > clone() const;
  virtual std::string reqPersonneFormate ()const;
};
}
#endif /* ELECTEUR_H */

