/**
 * \file Circonscription.cpp
 * \brief Implementations de la classe Circonscription.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 * \version finale
 */
#include "Circonscription.h"
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include"Circonscription.h"
#include"Candidat.h"
#include"Personne.h"
#include"ContratException.h"
#include"validationFormat.h"
#include "PersonneException.h"
using namespace std;

namespace elections
{

  /**
   * \brief Constructeur avec parametre.
   * On construit un objet Circonscriptrion à  partir des valeurs passées en paramètres 
   * \param[in] p_nomCirconscription, Le nom de la circonscription courante 
   * \param[in] p_deputeElu, le depute elu sous forme d'un objet Candidat
   * \pre p_nomCirconscription ne doit pas etre une chaine de caracteres vide
   * \post Vérification de l'attribut m_nomCirconscription s'il contient le nom de la circonscription courante
   * \post Vérification de l'attribut m_deputeElu s'il contient le depute Elu de la circonscription courante
   * \return Un objet Circonscription
   */
  Circonscription::Circonscription (const std::string& p_nomCirconscription,
                                    Candidat& p_deputeElu) :
  m_nomCirconscription (p_nomCirconscription), m_deputeElu (p_deputeElu)
  {
    PRECONDITION (!(p_nomCirconscription.empty ()));

    POSTCONDITION (m_nomCirconscription == p_nomCirconscription);
    POSTCONDITION (m_deputeElu == p_deputeElu);

    INVARIANTS ();
  }

  /**
   * \brief Constructeur de copie
   * On construit un objet Circonscriptrion en copiant les valeurs d'une autre instance de Circonscription
   * \param[in] p_circonscription, instance de la classe Circonscription 
   * \pre p_nomCirconscription ne doit pas etre une chaine de caracteres vide
   * \post Vérification de l'attribut m_nomCirconscription s'il contient le nom de la circonscription courante
   * \post Vérification de l'attribut m_deputeElu s'il contient le depute Elu de la circonscription courante
   * \return Un objet Circonscription
   */
  Circonscription::Circonscription (const Circonscription& p_circonscription) :
  m_nomCirconscription (p_circonscription.m_nomCirconscription),
  m_deputeElu (p_circonscription.m_deputeElu)
  {
    PRECONDITION (!(m_nomCirconscription.empty ()));
    for (const auto& element : p_circonscription.m_inscrits)
      {
        inscrire(*element);
      }
    POSTCONDITION (m_nomCirconscription == p_circonscription.m_nomCirconscription);
    POSTCONDITION (m_deputeElu == p_circonscription.m_deputeElu);
    INVARIANTS ();
  }

  /**
   * \brief Méthode accesseur récupérant le nom de la circonscription
   * \return le nom de la circonscription
   */
  string
  Circonscription::reqNomCirconscription () const
  {
    return m_nomCirconscription;
  }

  /**
   * \brief Méthode accesseur récupérant l'objet DeputeElu 
   * \return l'objet DeputeElu 
   */
  Candidat
  Circonscription::reqDeputeElu () const
  {
    return m_deputeElu;
  }

  /**
   * \brief Retourne le nombre d'inscrits dans la circonscription.
   * Cette méthode renvoie la taille de la liste des inscrits dans la circonscription,
   * c'est-à-dire le nombre d'éléments dans le conteneur `m_inscrits`.
   * \return Le nombre d'inscrits dans la circonscription.
   */
  size_t
  Circonscription::reqCompteurDePersonnes () const
  {
    return m_inscrits.size ();
  }

  /**
   * \brief Opérateur d'assignation pour la classe Circonscription.
   * Cet opérateur permet de copier les données d'une autre instance de `Circonscription`
   * dans l'objet actuel. Si l'objet à affecter est différent de l'objet actuel, les attributs
   * de la circonscription sont copiés.
   * \param [in] p_circonscription L'objet `Circonscription` à copier.
   * \return Circonscription& L'objet actuel après l'assignation.
   */
  Circonscription& Circonscription::operator= (const Circonscription& p_circonscription)
  {
    if (!(this == &p_circonscription))
      {
        m_nomCirconscription = p_circonscription.m_nomCirconscription;
        m_deputeElu = p_circonscription.m_deputeElu;

        m_inscrits.clear ();

        for (const auto & element : p_circonscription.m_inscrits)
          {
            inscrire(*element);
          }
      }
    return *this;
  }

  /**
   * \brief Inscrit une nouvelle personne dans la circonscription.
   * 
   * Cette méthode permet d'inscrire une nouvelle personne dans la circonscription,
   * elle verifie d'abord si cette personne est deja inscrite , si c'est le cas 
   * elle affiche un message .
   *
   * \param[in] p_nouvelInscrit L'objet `Personne` représentant la personne à inscrire dans la circonscription.
   */
  void
  Circonscription::inscrire (const Personne& p_nouvelInscrit)
  {
    if (personneEstDejaPresente(p_nouvelInscrit.reqNas ())==false){
        m_inscrits.push_back (p_nouvelInscrit.clone ());
      }
    else {
        throw PersonneDejaPresenteException("Impossible d'ajouter cet personne , car elle est deja inscrite ");
      }
  }

  /**
   * \brief desinscrit une personne deja presente dans la circonscription.
   * 
   * Cette méthode permet de desinscrire une  personne dans la circonscription, à condition
   * qu'elle ne soit pas absente. Si la personne est absente, un message d'erreur
   * est affiché dans le flux d'erreur standard.
   *
   * \param[in] p_nas Le numero d'assurance sociale de la personne.
   */
  void
  Circonscription::desinscrire (const std::string& p_nas)
  {
    PRECONDITION (validerNas (p_nas));
    if (personneEstDejaPresente (p_nas) == true)
      {
        vector <std::unique_ptr < Personne>>::const_iterator iter;
        for (iter = m_inscrits.begin (); iter != m_inscrits.end (); iter++)
          {
            if (p_nas == (*iter)->reqNas ())
              {
                m_inscrits.erase (iter);
                iter--;
              }
          }
      }
    else {
        throw PersonneAbsenteException("Impossible de supprimer cette personne, car elle n'est pas presente");
      }
  }


  /**
   * \brief methode qui formate et retourne une représentation textuelle complète d'une circonscription.
   * \return std::string Une chaîne de caractères contenant les informations formatées de la circonscription
   * \note : Cette methode utilise la methode reqPersonneFormatee() de la classe Candidat et la classe Electeur
   */
  std::string
  Circonscription::reqCirconscriptionFormate () const
  {

    ostringstream os, os2;
    for (const auto & element : m_inscrits)
      {
        os2 << element->reqPersonneFormate () << endl;
        os2 << endl;
      }

    os << "circonscription : " << m_nomCirconscription << endl;
    os << "Depute sortant :" << endl;
    os << m_deputeElu.reqPersonneFormate () << endl << endl;
    os << "Liste des inscrits : " << endl;
    os << os2.str ()<<endl;
    return os.str ();
  }

  /**
   * \brief verifier les invariants de la classe
   */
  void 
  Circonscription::verifieInvariant () const
  {
    INVARIANT (!(m_nomCirconscription.empty ()));
  }

  
/**
 * \brief Retourne les détails formatés d'une personne spécifique inscrite dans la circonscription.
 * \param[in] p_nom Le nom de la personne recherchée.
 * \param[in] p_prenom Le prénom de la personne recherchée.
 * \return Une chaîne de caractères contenant les informations formatées de la personne,
 *         ou une chaîne vide si aucune personne ne correspond.
 *
 * Cette méthode parcourt la liste des personnes inscrites dans la circonscription et
 * retourne les informations de la première personne trouvée correspondant au nom et
 * au prénom donnés. Les informations sont retournées dans un format déterminé par
 * la méthode `reqPersonneFormate()` de la classe `Personne`.
 */

std::string 
Circonscription::reqPersonneSelection(const std::string& p_nom,const std::string& p_prenom)const
  {
    ostringstream os; 
    std::vector<std::unique_ptr<Personne>>::const_iterator it;
    for (it = m_inscrits.begin (); it != m_inscrits.end (); it++)
      {
        if ((*it)->reqNom () == p_nom && (*it)->reqPrenom () == p_prenom)
          os<< (*it)->reqPersonneFormate ();
      }
    return os.str();
  }
  /**
   * \brief Vérifie si une personne est déjà inscrite dans la circonscription.
   * Elle permet de vérifier si une personne donnée est déjà inscrite dans la
   * liste des inscrits de la circonscription. La comparaison est effectuée en utilisant
   * l'opérateur d'égalité (`==`) entre la personne donnée et chaque élément inscrit.
   * \param[in] p_nas Le numero d'assurance sociale de la personne.
   * \return true Si la personne est déjà inscrite dans la circonscription, sinon false.
   */
  bool
  Circonscription::personneEstDejaPresente (const string& p_nas) const
  {
    bool dejainscrit = false;
    vector<std::unique_ptr<Personne>>::const_iterator iter;
    for (iter =m_inscrits.begin();iter != m_inscrits.end();iter ++)
      {
        if (p_nas == (*iter)->reqNas ())
          {
            dejainscrit = true;
          }
      }
    return dejainscrit;
  }

 
}//namespace elections



