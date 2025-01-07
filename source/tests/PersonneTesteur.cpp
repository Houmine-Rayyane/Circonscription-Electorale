/*
 * \file PersonneTesteur.cpp
 * \brief test unitaire de la classe Personne.
 * \author Rayyane Houmine aka THE BO$$
 * \Date 20 Novembre 2024
 */
#include<gtest/gtest.h>
#include"Personne.h"
#include <iostream>
#include"ContratException.h"
#include"Date.h"
#include<sstream>

using namespace std;
using namespace elections;

/**
 * \brief Création d'une classe derivee de la classe base Personne qui est abstraite , pour 
 * pouvoir creer des instances pour tester les methodes de cette classe
 */
class PersonneDeTest : public Personne
{
public:

  PersonneDeTest (const std::string& p_nas, const std::string& p_prenom,
                  const std::string& p_nom, const std::
                  string& p_adresse, const util::Date& p_dateNaissance) :
  Personne (p_nas, p_prenom, p_nom, p_adresse, p_dateNaissance) { };

 virtual std::unique_ptr<Personne> clone() const{
   return unique_ptr <Personne> (new PersonneDeTest (*this));
 }
 virtual std::string reqPersonneFormate() const{
      
    return Personne::reqPersonneFormate ();
    
  }
};

/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Personne et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       NAS invalide = 123 456 789
 *		       Prenom vide
 *                     Nom vide
 *                     Adresse vide 
 *                     Date invalide : 20 10 2400
 */
TEST (Personne, ConstructeurAvecParametresValides)
{
  PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                            "2255 Rue de l'universite", util::Date (20, 10, 2003));
  ASSERT_EQ ("046 454 286", personne1.reqNas ());
  ASSERT_EQ ("Rayyane", personne1.reqPrenom ());
  ASSERT_EQ ("Houmine", personne1.reqNom ());
  ASSERT_EQ ("2255 Rue de l'universite", personne1.reqAdresse ());
  ASSERT_EQ (util::Date (20, 10, 2003), personne1.reqdateNaissance ());
}

//Cas invalides
TEST (Personne, ConstructeurNasInvalide)
{
  ASSERT_THROW (PersonneDeTest personne1 ("123 456 789", "Rayyane", "Houmine",
                                          "2255 Rue de l'universite", util::Date (20, 10, 2003)), 
                PreconditionException) << "Le nas est invalide";
}
TEST (Personne, ConstructeurPrenomInvalide)
{
  ASSERT_THROW (PersonneDeTest personne1 ("046 454 286", "", "Houmine",
                                          "2255 Rue de l'universite", util::Date (20, 10, 2003)),
                PreconditionException) << "Le prenom ne doit pas etre vide";
}
TEST (Personne, ConstructeurNomInvalide)
{
  ASSERT_THROW (PersonneDeTest personne1 ("046 454 286", "Rayyane", "",
                                          "2255 Rue de l'universite", util::Date (20, 10, 2003)),
                PreconditionException) << "Le nom ne doit pas etre vide";
}
TEST (Personne, ConstructeurAdresseInvalide)
{
  ASSERT_THROW (PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                                          "", util::Date (20, 10, 2003)),
                PreconditionException) << "L'adresse ne doit pas etre vide";
}
TEST (Personne, ConstructeurJourInvalides)
{
  ASSERT_THROW (PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                                          "2255 Rue de l'universite", util::Date (32, 10, 2003)),
                                          PreconditionException) << "Le jour doit etre compris entre 1 et 31";
}
TEST (Personne, ConstructeurMoisInvalides)
{
  ASSERT_THROW (PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                                          "2255 Rue de l'universite", util::Date (20, 13, 2003)),
                PreconditionException) << "Le mois doit etre entre 1 et 12";
}
TEST (Personne, ConstructeurAnneeInvalides)
{
  ASSERT_THROW (PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                                          "2255 Rue de l'universite", util::Date (20, 10, 2400)),
                PreconditionException) << "L'annee doit etre entre 1970 et 2037";
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class PersonneValide : public ::testing::Test
{
public:

  PersonneValide () :
  f_personneVal ("046 454 286", "Rayyane", "Houmine",
                 "2255 Rue de l'universite", util::Date (20, 10, 2003)) { };
  PersonneDeTest f_personneVal;
};


/**
 * \test Test de la méthode reqNas()
 *
 *     Cas valide: vérifier le retour du nas de la personne
 *     Cas invalide: aucun
 */
TEST_F (PersonneValide, reqNas)
{
  ASSERT_EQ ("046 454 286", f_personneVal.reqNas ());
}

/**
 * \test Test de la méthode reqPrenom()
 *
 *     Cas valide: vérifier le retour du prenom de la personne
 *     Cas invalide: aucun
 */
TEST_F (PersonneValide, reqPrenom)
{
  ASSERT_EQ ("Rayyane", f_personneVal.reqPrenom ());
}


/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour du nom de la personne
 *     Cas invalide: aucun
 */
TEST_F (PersonneValide, reqNom)
{
  ASSERT_EQ ("Houmine", f_personneVal.reqNom ());
}


/**
 * \test Test de la méthode reqAdresse()
 *
 *     Cas valide: vérifier le retour de l'adresse de la personne
 *     Cas invalide: aucun
 */
TEST_F (PersonneValide, reqAdresse)
{
  ASSERT_EQ ("2255 Rue de l'universite", f_personneVal.reqAdresse ());
}


/**
 * \test Test de la méthode reqdateNaissance()
 *
 *     Cas valide: vérifier le retour de la date de naissance de la personne
 *     Cas invalide: aucun
 */
TEST_F (PersonneValide, reqdateNaissance)
{
  ASSERT_EQ (util::Date (20, 10, 2003), f_personneVal.reqdateNaissance ());
}

/**
 * @brief Teste la méthode asgAdresse() pour les cas valides et invalides.
 * 
 * Ce test vérifie le comportement de la méthode asgAdresse() de la classe Personne
 * dans deux scénarios différents :
 *                           Cas valide : 
 *                               Adresse valide : "2255 Rue de l'universite"
 *                               Adresse invalide vide : ""
 */
TEST_F (PersonneValide, asgAdresseValide)
{
  f_personneVal.asgAdresse ("2255 Rue de l'universite");
  ASSERT_EQ ("2255 Rue de l'universite", f_personneVal.reqAdresse ());
}
//Cas invalide
TEST_F (PersonneValide, asgAdresseInvalide)
{
  ASSERT_THROW (f_personneVal.asgAdresse (""), PreconditionException) << "L'adresse ne doit pas etre vide";
}

/**
 * \test Test de la méthode reqPersonneFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Personne formatees 
 *        Cas invalides: aucun
 */
TEST_F (PersonneValide, reqPersonneFormate)
{
  ostringstream os;
  os << "NAS           :" << f_personneVal.reqNas () << endl;
  os << "Prenom        :" << f_personneVal.reqPrenom () << endl;
  os << "Nom           :" << f_personneVal.reqNom () << endl;
  os << "Date de naissance :" << (f_personneVal.reqdateNaissance ()).reqDateFormatee () << endl;
  os << "Adresse       :" << f_personneVal.reqAdresse () << endl;
  ASSERT_EQ (os.str (), f_personneVal.reqPersonneFormate ());
}

/**
 * @brief Teste l'opérateur d'égalité (==) pour la classe Personne dans des cas d'égalité et d'inégalité.
 * 
 * Ce test vérifie le comportement de l'opérateur d'égalité (==) de la classe Personne dans deux scénarios différents :
 *                          Egalite des deux objets et Inegalite des deux objets
 */
TEST (Personne, OperateurEgalTrue)
{
  PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                            "2255 Rue de l'universite", util::Date (20, 10, 2003));
  PersonneDeTest personne2 ("046 454 286", "Rayyane", "Houmine",
                            "2255 Rue de l'universite", util::Date (20, 10, 2003));
  ASSERT_TRUE (personne1 == personne2);
}
//Inegalite
TEST (Personne, OperateurEgalFalse)
{
  PersonneDeTest personne1 ("046 454 286", "Rayyane", "Houmine",
                            "2255 Rue de l'universite", util::Date (20, 10, 2003));
  PersonneDeTest personne2 ("046 454 286", "Omar", "Houmine",
                            "2255 Rue de l'universite", util::Date (20, 10, 2003));
  ASSERT_FALSE (personne1 == personne2);
}
