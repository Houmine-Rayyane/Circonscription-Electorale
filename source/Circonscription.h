/**
 * \file Circonscription.h
 * \brief déclarations de la classe Circonscription.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */
#ifndef CIRCONSCRIPTION_H
#define CIRCONSCRIPTION_H
#include"Candidat.h"
#include<string>
#include<vector>
#include"Personne.h"

/**
 * \namespace elections
 * \brief Ce namespace contient toutes les classes demandees pour ce Tp2
 * Candidat , Personne , Electeur , Circonscription
 */
namespace elections
{

/**
 * \class Circonscription
 * \brief Prototype de la classe Circonscripition qui permet de faire la gestion des listes electorales
 */
class Circonscription
  {
  public:
    //Constructeur par parametres
    Circonscription (const std::string& p_nomCirconscription, Candidat& p_deputeElu);
    //Constructeur de copie
    Circonscription (const Circonscription& p_circonscription);
    
    //Accesseurs
    std::string reqNomCirconscription () const;
    Candidat reqDeputeElu () const;
    
    size_t reqCompteurDePersonnes () const;
    
    //Operateur d'assignation
    Circonscription& operator= (const Circonscription& p_circonscription);
    
    
    void inscrire (const Personne& p_nouvelInscrit);
    void desinscrire (const std::string& p_nas);
    
    std::string reqPersonneSelection(const std::string& p_nom,const std::string& p_prenom)const;
    std::string reqCirconscriptionFormate () const;

  private:

    std::string m_nomCirconscription;
    Candidat m_deputeElu;
    std::vector<std::unique_ptr<Personne>> m_inscrits;
    bool personneEstDejaPresente (const std::string& p_nas) const;
    void verifieInvariant () const;
  };
}
#endif /* CIRCONSCRIPTION_H */

