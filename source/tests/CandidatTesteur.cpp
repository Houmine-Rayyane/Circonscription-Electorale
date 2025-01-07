/**
 * \file CandidatTesteur.cpp
 * \brief Test unitaire de la classe Candidat
 * \author Rayyane Houmine 
 * \date 20 Novembre 2024
 */

#include <gtest/gtest.h>
#include <iostream>
#include"Candidat.h"
#include"Personne.h"
#include<sstream>

using namespace std;
using namespace elections;

/**
 * \test Test du constructeur
 *
 * 		  Cas valides: Création d'un objet Candidat et vérification de l'assignation du parti politique
 *		  Cas invalides:Creation d'un objet Candidat avec un parti politique invalide (>4)
 */
TEST (Candidat, ConstructeurValide)
{
  Candidat unCandidat("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS);
  ASSERT_EQ(BLOC_QUEBECOIS,unCandidat.reqPartiPolitique());
}

//cas invaldie
TEST (Candidat, ConstructeurAvecPartiInvalide)
{
  ASSERT_THROW(Candidat unCandidat("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      5),PreconditionException)<<"Le parti politique est invalide";
  
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class CandidatValide: public ::testing ::Test
{
public:
  
  CandidatValide():
  f_candidatVal("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS){ };
  Candidat f_candidatVal;
};

/**
 * \test Test de la méthode reqPartiPolitique()
 *
 *     Cas valide: vérifier le retour du parti politique du candidat
 *     Cas invalide: aucun
 */
TEST_F(CandidatValide,reqPartiPolitique)
{
  ASSERT_EQ(BLOC_QUEBECOIS,f_candidatVal.reqPartiPolitique());
}

/**
 * \test Test de la méthode reqStringPartiPolitique()
 *
 *     Cas valide: vérifier le retour du parti politique du candidat sous forme de chaine de caractere 
 *     Cas invalide: aucun
 */
TEST_F(CandidatValide,reqStringParti)
{
  ASSERT_EQ("Bloc Quebecois",f_candidatVal.reqStringParti());
}

/**
 
 * \test Test de la methode std::unique_ptr<Personne> clone() const 
 *               Cas valide : 
 *                   cloneValide : retourne une copie exacte de l'objet courrant.
 *               Cas Invalide : 
 *                   cloneInvalideNull : retourne un pointeur vide 
 *                   cloneInvalideAdresse : l'adresse de l'objet et son clone sont identiques
 *                  
 * 
 */
TEST_F(CandidatValide, CloneValide)
{
auto candidatPtr = f_candidatVal.clone();  
ASSERT_EQ(f_candidatVal.reqPersonneFormate (), candidatPtr->reqPersonneFormate());
}

TEST_F(CandidatValide, CloneInvalideNull) {
    ASSERT_NE(f_candidatVal.clone (), nullptr)<<"le clone ne devrait pas etre null";
}
TEST_F(CandidatValide, cloneInvalideAdresse) {
     std::unique_ptr<Personne> cloner = f_candidatVal.clone();
    ASSERT_NE(&f_candidatVal, cloner.get()) << "L'original et le clone doivent avoir des adresses différentes.";
  
}

/**
 * \test Test de la méthode reqPersonneFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Candidat formatees 
 *        Cas invalides: aucun
 */
TEST_F (CandidatValide, reqPersonneFormate)
{
  ostringstream os;
  os<<"Candidat"<<endl;
  os<<"----------------------------------------------"<<endl;
  os << "NAS           :" << f_candidatVal.reqNas () << endl;
  os << "Prenom        :" << f_candidatVal.reqPrenom () << endl;
  os << "Nom           :" << f_candidatVal.reqNom () << endl;
  os << "Date de naissance :" << (f_candidatVal.reqdateNaissance ()).reqDateFormatee () << endl;
  os << "Adresse       :" << f_candidatVal.reqAdresse () << endl;
  os<<"Parti politique   : "<<f_candidatVal.reqStringParti()<<endl;
  ASSERT_EQ (os.str (), f_candidatVal.reqPersonneFormate ());
}
