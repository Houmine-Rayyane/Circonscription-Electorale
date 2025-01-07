/**
 * \file Electeur.cpp
 * \brief Implementations de la classe Electeur.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */

#include "Electeur.h"
#include<iostream>
#include<sstream>

using namespace std;

namespace elections {
  
  /**
 * \brief Constructeur avec parametre.
 * On construit un objet Electeur à  partir des valeurs passées en paramètres 
 * \param[in] p_nas , Le numero d'assurance sociale de l'electeur  
 * \param[in] p_prenom, le prenom de l'electeur
 * \param[in] p_nom , le nom de l'electeur
 * \param[in] p_adresse , l'adresse de l'electeur
 * \param[in] p_dateNaissance , la date de naissance de l'electeur
 * \return Un objet Personne
 * \note : Ce constructeur utilise le constructeur de la classe Personne pour faire sa liste d'initialisation
 */
Electeur::Electeur (const std::string& p_nas, const std::string& p_prenom,
            const std::string& p_nom, const std::string& p_adresse,
            const util::Date& p_dateNaissance)
:Personne(p_nas, p_prenom, p_nom,p_adresse,p_dateNaissance) { }

/**
 * \brief Crée une copie (clone) de l'objet `Electeur` actuel.
 * \return std::unique_ptr<Personne> Un pointeur unique vers un nouvel objet `Electeur` qui est une copie
 *         de l'objet actuel. Ce pointeur est géré automatiquement par `std::unique_ptr`.
 */
std::unique_ptr <Personne> Electeur :: clone () const
{
  return make_unique < Electeur > (*this);
}

/**
 * \brief methode qui formate et retourne une représentation textuelle complète d'un electeur.
 * \return std::string Une chaîne de caractères contenant les informations formatées du electeur
 * \note : Cette methode est une augmentation de la methode reqPersonneFormate() de la classe Personne
 */
std::string Electeur :: reqPersonneFormate ()const
{
  ostringstream os;
  os<<"Electeur"<<endl;
  os<<"----------------------------------------------"<<endl;
  os<<Personne::reqPersonneFormate();
  return os.str();
}
}

