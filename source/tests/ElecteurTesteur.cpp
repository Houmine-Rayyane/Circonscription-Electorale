/**
 * \file ElecteurTesteur.cpp
 * \brief Test unitaire de la classe Electeur
 * \author Rayyane Houmine 
 * \date 20 Novembre 2024
 */
#include <gtest/gtest.h>
#include <iostream>
#include"Electeur.h"
#include"Personne.h"
#include<sstream>

using namespace std;
using namespace elections;


/**
 * Clarification : Je ne teste pas le constructeur vu qu'il utilise le constructeur de la classe Personne
 * qui on a deja teste dans le fichier PersonneTesteur.cpp
 */

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class ElecteurValide: public ::testing ::Test
{
public:
  
  ElecteurValide():
  f_electeurVal("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003)){ };
  Electeur f_electeurVal;
};

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
TEST_F(ElecteurValide, CloneValide)
{
auto electeurPtr = f_electeurVal.clone();  
ASSERT_EQ(f_electeurVal.reqPersonneFormate (), electeurPtr->reqPersonneFormate());
}

TEST_F(ElecteurValide, CloneInvalideNull) {
    ASSERT_NE(f_electeurVal.clone (), nullptr)<<"le clone ne devrait pas etre null";
}
TEST_F(ElecteurValide, cloneInvalideAdresse) {
     std::unique_ptr<Personne> cloner = f_electeurVal.clone();
    ASSERT_NE(&f_electeurVal, cloner.get()) << "L'original et le clone doivent avoir des adresses différentes.";
  
}

/**
 * \test Test de la méthode reqPersonneFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Electeur formatees 
 *        Cas invalides: aucun
 */
TEST_F (ElecteurValide, reqPersonneFormate)
{
  ostringstream os;
  os<<"Electeur"<<endl;
  os<<"----------------------------------------------"<<endl;
  os << "NAS           :" << f_electeurVal.reqNas () << endl;
  os << "Prenom        :" << f_electeurVal.reqPrenom () << endl;
  os << "Nom           :" << f_electeurVal.reqNom () << endl;
  os << "Date de naissance :" << (f_electeurVal.reqdateNaissance ()).reqDateFormatee () << endl;
  os << "Adresse       :" << f_electeurVal.reqAdresse () << endl;
  ASSERT_EQ (os.str (), f_electeurVal.reqPersonneFormate ());
}