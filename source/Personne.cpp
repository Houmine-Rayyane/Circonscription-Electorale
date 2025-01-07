/**
 * \file Personne.cpp
 * \brief Implementatoion de la classe Personne.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */
#include "Personne.h"
#include<iostream>
#include<sstream>
#include"validationFormat.h"

using namespace std;
namespace elections{

/**
 * \brief Constructeur avec parametre.
 * On construit un objet Personne à  partir des valeurs passées en paramètres 
 * \param[in] p_nas, Le numnero d'assurance sociale de la personne  
 * \param[in] p_prenom, le prenom de la personne
 * \param[in] p_nom, le nom de la personne
 * \param[in] p_adresse, l'adresse de la personne 
 * \param[in] p_dateNaissance, la date de naissance de la personne
 * \pre p_nas doit etre valide par la fonction validerNas
 * \pre p_prenom, p_nom , p_adresse ne doivent pas etre vides 
 * \pre p_dateNaissance doit etre valide par la fonction validerDate
 * \post Vérification de l'attribut m_nas s'il contient le nas de la personne courante.
 * \post Vérification de l'attribut m_prenom s'il contient le prenom de la personne courante.
 * \post Vérification de l'attribut m_nom  s'il contient le nom de la personne  courante.
 * \post Vérification de l'attribut m_adresse s'il contient l'adresse de la personne courante.
 * \post Vérification de l'attribut m_dateNaissance s'il contient la date de naissance de la personne courante.
 * \return Un objet personne
 */ 
Personne::Personne (const std::string& p_nas, const std::string& p_prenom,
                    const std::string& p_nom, const std::
                    string& p_adresse, const util::Date& p_dateNaissance) :
m_nas (p_nas),
m_prenom (p_prenom), m_nom (p_nom), m_adresse (p_adresse),
m_dateNaissance (p_dateNaissance.reqJour (), p_dateNaissance.reqMois (),
                 p_dateNaissance.reqAnnee ())
{
  PRECONDITION (validerNas (p_nas));
  PRECONDITION (!p_prenom.empty ());
  PRECONDITION (!p_nom.empty ());
  PRECONDITION (!p_adresse.empty ());
  PRECONDITION ((util::Date::validerDate (p_dateNaissance.reqJour (),
                                          p_dateNaissance.reqMois (),
                                          p_dateNaissance.reqAnnee ())));
  POSTCONDITION (m_nas == p_nas);
  POSTCONDITION (m_prenom == p_prenom);
  POSTCONDITION (m_nom == p_nom);
  POSTCONDITION (m_adresse == p_adresse);
  POSTCONDITION (m_dateNaissance == p_dateNaissance);
  INVARIANTS ();
}

/**
 * @brief Destructeur de la classe Personne.
 */
Personne::~Personne() { }

/**
 * \brief Méthode accesseur récupérant le nas .
 * \return le nas .
 */
 string
Personne::reqNas ()const
{
  return m_nas;
}

 /**
 * \brief Méthode accesseur récupérant le prenom .
 * \return le prenom .
 */
string
Personne::reqPrenom ()const
{
  return m_prenom;
}

/**
 * \brief Méthode accesseur récupérant le nom .
 * \return le nom .
 */
string
Personne::reqNom ()const
{
  return m_nom;
}

/**
 * \brief Méthode accesseur récupérant l'adresse .
 * \return l'adresse .
 */
string
Personne::reqAdresse ()const
{
  return m_adresse;
}
 /**
 * \brief Méthode accesseur récupérant la date de naissance .
 * \return la date de naissance .
 */
const util::Date&
Personne::reqdateNaissance ()const
{
  return m_dateNaissance;
}

/**
 * \brief Assignation de l'attrribut de l'adresse de la personne avec la valeur passe en parametre.
 * \param[in] p_adresse, l'adresse de la personne 
 * \pre p_adresse , est un objet string qui ne doit pas etre vide
 * \post Vérification de l'attribut m_)adresse s'il contient l'adresse passe en parametre
 */
void
Personne::asgAdresse (std::string p_adresse)
{
  PRECONDITION (!p_adresse.empty ());
  m_adresse = p_adresse;
  POSTCONDITION (m_adresse == p_adresse);
  INVARIANTS ();
}

/**
 * \brief Surcharge de l'operateur == pour permettre la comparaison de tous les attributs.
 * \param[in] p_personne à  comparer à  l'objet courant.
 * \return un booleen indiquant si les attributs des deux objets sont égaux ou non.
 */
bool Personne::operator== (const Personne& p_personne) const
{
  return ((m_nas == p_personne.m_nas) &&
          (m_prenom == p_personne.m_prenom) &&
          (m_nom == p_personne.m_nom) &&
          (m_adresse == p_personne.m_adresse)&&
          (m_dateNaissance == p_personne.m_dateNaissance));
}

/**
 * \brief methode qui formate et retourne une représentation textuelle complète d'une personne.
 * \return std::string Une chaîne de caractères contenant les informations formatées de la personne
 */
string
Personne::reqPersonneFormate ()const
{
  ostringstream os;
  os << "NAS           :" << reqNas () << endl;
  os << "Prenom        :" << reqPrenom () << endl;
  os << "Nom           :" << reqNom () << endl;
  os << "Date de naissance :" << reqdateNaissance ().reqDateFormatee () << endl;
  os << "Adresse       :" << reqAdresse () << endl;
  return os.str ();
}

/**
 * \brief verifier les invariants de la classe
 */
void
Personne::verifieInvariant ()const
{
  INVARIANT (validerNas (m_nas));
  INVARIANT (!m_prenom.empty ());
  INVARIANT (!m_nom.empty ());
  INVARIANT (!m_adresse.empty ());
  INVARIANT ((util::Date::validerDate (
                                       m_dateNaissance.reqJour (),
                                       m_dateNaissance.reqMois (), 
                                       m_dateNaissance.reqAnnee ()
                                       )
             )
            );
}
}