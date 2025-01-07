/**
 * \file CirconscriptionTesteur.cpp
 * \brief Test unitaire de la classe Circonscription
 * \author Rayyane Houmine 
 * \date 20 Novembre 2024
 */
#include <gtest/gtest.h>
#include <iostream>
#include"Circonscription.h"
#include"Candidat.h"
#include"Personne.h"
#include"Electeur.h"
#include<sstream>

using namespace std;
using namespace elections;

//Creation de deux objets de la classe Candidat pour tester les methodes de la classe Circonscription
Candidat uncandidat("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS);
Candidat uncandidat2("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS);
 

/**
 * \test Test du constructeur avec parametre
 *
 * 		  Cas valides: Création d'un objet Circonscription et vérification de l'assignation des attributs
 *		  Cas invalides:Creation d'un objet Circonscription avec un nom de circonscription vide
 */
TEST (Circonscription, ConstructeurAvecParametreValide)
{
  
  Circonscription c1("circonscription n1",uncandidat);
  ASSERT_EQ("circonscription n1",c1.reqNomCirconscription ());
  ASSERT_EQ("046 454 286",c1.reqDeputeElu().reqNas ());
  ASSERT_EQ( "Rayyane",c1.reqDeputeElu().reqPrenom ());
  ASSERT_EQ("Houmine",c1.reqDeputeElu().reqNom ());
  ASSERT_EQ("2255 Rue de l'universite",c1.reqDeputeElu().reqAdresse ()); 
  ASSERT_EQ(util::Date (20, 10, 2003),c1.reqDeputeElu().reqdateNaissance ());
  ASSERT_EQ(BLOC_QUEBECOIS,c1.reqDeputeElu().reqPartiPolitique());

}
//Cas invalide
TEST (Circonscription, ConstructeurNomCirconscriptionInvalide)
{
  Candidat uncandidat("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS);
   std::string nomCirconscriptionVide = "";
  ASSERT_THROW (Circonscription c1(nomCirconscriptionVide,uncandidat),
  PreconditionException) <<"Le nom de la circonscription ne doit pas etre vide";

}


/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class CirconscriptionValide : public ::testing ::Test
{
public:
  CirconscriptionValide() : deputeElu("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),PartisPolitiques::INDEPENDANT)
  ,f_circonscriptionVal("circonscription n1",deputeElu){
    Electeur electeur("123 456 782", "Omar", "Chaoui",
                   "4160 Rue De La fontaine", util::Date (20, 10, 2003));
    f_circonscriptionVal.inscrire(electeur);
  }
  Candidat deputeElu;
  Circonscription f_circonscriptionVal;

};

/**
 * \test Test du constructeur de copie;
 *               Cas valide : objetCopie
 *               Cas Invalide : aucun
 
*/
TEST_F(CirconscriptionValide, ConstructeurDeCopie)
{
  Candidat uncandidat1("046 454 286", "Rayyane", "Houmine",
                            "2255 Rue de l'universite", util::Date (20, 10, 2003),BLOC_QUEBECOIS);
  f_circonscriptionVal.inscrire (uncandidat1);
  Circonscription objettest(f_circonscriptionVal);

  ASSERT_EQ(objettest.reqCirconscriptionFormate (), f_circonscriptionVal.reqCirconscriptionFormate ());  
}

/**
 * \test Test de la méthode reqNomCirconscription()
 *
 *     Cas valide: vérifier le retour du nom de la circonscription
 *     Cas invalide: aucun
 */
TEST_F (CirconscriptionValide, reqNomCirconscription)
{
  ASSERT_EQ ("circonscription n1", f_circonscriptionVal.reqNomCirconscription ());
}
/**
 * \test Test de la méthode reqDeputeElu()
 *
 *     Cas valide: vérifier le retour du depute elu
 *     Cas invalide: aucun
 */
TEST_F (CirconscriptionValide, reqDeputeElu)
{
  ASSERT_EQ ("046 454 286", f_circonscriptionVal.reqDeputeElu().reqNas ());
  ASSERT_EQ ("Rayyane", f_circonscriptionVal.reqDeputeElu().reqPrenom ());
  ASSERT_EQ ("Houmine", f_circonscriptionVal.reqDeputeElu().reqNom ());
  ASSERT_EQ ("2255 Rue de l'universite", f_circonscriptionVal.reqDeputeElu().reqAdresse ());
  ASSERT_EQ (util::Date (20, 10, 2003), f_circonscriptionVal.reqDeputeElu().reqdateNaissance ());
  ASSERT_EQ (2, f_circonscriptionVal.reqDeputeElu().reqPartiPolitique ());
}

/**
 * \test Test de la méthode reqCompteurDePersonnes()
 *
 *     Cas valide: vérifier si le compte est bien , et que la methode fonctionne justement
 *     Cas invalide: aucun
 */
TEST_F(CirconscriptionValide,reqCompteurDePersonnes)
{
  ASSERT_EQ(f_circonscriptionVal.reqCompteurDePersonnes (),1);
}

/**
 * \test TEST_F(CirconscriptionValide, OperateurAssignation)
 * \brief Teste l'opérateur d'assignation pour la classe Circonscription.
 * Étapes du test :
 * - Création de deux objets `Candidat` avec les mêmes informations personnelles.
 * - Inscription de ces candidats dans deux objets `Circonscription` distincts.
 * - Utilisation de l'opérateur d'assignation pour copier les données d'une circonscription à l'autre.
 * - Comparaison des données des deux circonscriptions à l'aide de la méthode `reqCirconscriptionFormate`.
 */
TEST_F(CirconscriptionValide, OperateurAssignation)
{
  ostringstream os;
  Candidat uncandidat("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS);
  Candidat uncandidat2("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),
                      BLOC_QUEBECOIS);
  Circonscription circonsTest(f_circonscriptionVal);
  
  circonsTest.inscrire(uncandidat);
  f_circonscriptionVal.inscrire(uncandidat2);
  
  circonsTest = f_circonscriptionVal;
  
  ASSERT_EQ(circonsTest.reqCirconscriptionFormate (), f_circonscriptionVal.reqCirconscriptionFormate ());
  
}

/**
 * \test Test de la méthode inscrire()
 *
 *     Cas valide: vérifier si la personne est ajoute a la liste des personnes inscrites
 *     Cas invalide: ne pas inscrire une personne si elle est deja presente
 */
TEST_F(CirconscriptionValide,inscrire)
{
  Candidat uncandidat3("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),PartisPolitiques::INDEPENDANT);
  f_circonscriptionVal.inscrire(uncandidat3);
  ASSERT_EQ(f_circonscriptionVal.reqCompteurDePersonnes (),2);
}


/**
 * 
 * \test Test de la méthode inscrire()
 *
 *     Cas valide: vérifier si la personne est ajoute a la liste des personnes inscrites
 *     Cas invalide: ne pas inscrire une personne si elle est deja presente
 * */
TEST_F(CirconscriptionValide,desinscrire)
{
  Candidat uncandidat3("046 454 286", "Rayyane", "Houmine",
                   "2255 Rue de l'universite", util::Date (20, 10, 2003),PartisPolitiques::INDEPENDANT);
  f_circonscriptionVal.inscrire(uncandidat3);
  f_circonscriptionVal.desinscrire(uncandidat3.reqNas());
  ASSERT_EQ(f_circonscriptionVal.reqCompteurDePersonnes (),1);
}



/**
 * \test Test de la méthode reqCirconscriptionFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet Circonscription formatees 
 *        Cas invalides: aucun
 */
TEST_F(CirconscriptionValide, reqCirconscriptionFormate)
{
    ostringstream os;
    os << "circonscription : " << "circonscription n1" << endl
       << "Depute sortant :"<< endl
       << "Candidat" << endl
       << "----------------------------------------------" << endl
       << "NAS           :" << "046 454 286" << endl
       << "Prenom        :" << "Rayyane" << endl
       << "Nom           :" << "Houmine" << endl
       << "Date de naissance :" << util::Date (20, 10, 2003).reqDateFormatee() << endl
       << "Adresse       :" << "2255 Rue de l'universite" << endl
       << "Parti politique   : " << "Independant" << endl<<endl
       << endl
       << "Liste des inscrits : " << endl
       << "Electeur" << endl
       << "----------------------------------------------" << endl
       << "NAS           :" << "123 456 782" << endl
       << "Prenom        :" << "Omar" << endl
       << "Nom           :" << "Chaoui" << endl
       << "Date de naissance :" << util::Date (20, 10, 2003).reqDateFormatee() << endl
       << "Adresse       :" << "4160 Rue De La fontaine" << endl<< endl<<endl<<endl;

    ASSERT_EQ(os.str(),f_circonscriptionVal.reqCirconscriptionFormate());
}


