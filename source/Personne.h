/**
 * \file Personne.h
 * \brief déclarations de la classe Personne.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */

#ifndef PERSONNE_H
#define PERSONNE_H

#include<string>
#include<memory>
#include"Date.h"
#include"ContratException.h"

/**
 * \namespace elections
 * \brief Ce namespace contient toutes les classes demandees pour ce Tp2
 * Candidat , Personne , Electeur , Circonscription
 */
namespace elections{
  
/**
 * \class Personne
 * \brief Prototype de la classe Personne abstraite qui represente la classe base des classes derivees
 * Candidat , Electeur.
 */  
class Personne
{
public:
  //Constructeur 
  Personne (const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
            const std::string& p_adresse, const util::Date& p_dateNaissance);
  //Accesseur
  std::string reqNas ()const;
  std::string reqPrenom ()const;
  std::string reqNom ()const;
  std::string reqAdresse ()const;
  const util::Date& reqdateNaissance ()const;
  
  //Mutateur
  void asgAdresse (std::string p_adresse);
  
  //Operateur d'egalite
  bool operator== (const Personne& p_personne) const;
  //Destructeur
  virtual
  ~Personne ();

  virtual std::unique_ptr<Personne> clone() const=0;
  
  virtual std::string reqPersonneFormate ()const;

private:
  std::string m_nas;
  std::string m_prenom;
  std::string m_nom;
  std::string m_adresse;
  util::Date m_dateNaissance;
  void verifieInvariant () const;
};
}//namespace elections
#endif /* PERSONNE_H */

