/* 
 * \File:  Candidat.cpp
 * \brief Implémentation de la classe Candidat
 * \Author: Rayyane Houmine
 * \version finale
 */

#include "Candidat.h"
#include<iostream>
#include<sstream>


using namespace std;
namespace elections{
  
  
  
//Declaration de la fonction estPartiValide qui verifie la date 
bool estPartiValide(int p_parti);

/**
 * \brief Constructeur avec parametre.
 * On construit un objet Candidat à  partir des valeurs passées en paramètres 
 * \param[in] p_nas , Le numero d'assurance sociale du candidat  
 * \param[in] p_prenom, le prenom du candidat
 * \param[in] p_nom , le nom du candidat 
 * \param[in] p_adresse , l'adresse du candidat
 * \param[in] p_dateNaissance , la date de naissance du candidat
 * \param[in] p_partiPolitique , la parti politique a laquelle appartient le candidat
 * \pre p_partiPolitique , doit etre valide par la fonction estPartiValide
 * \post Vérification de l'attribut m_partiPolitique s'il contient la parti politique courante
 * \return Un objet Candidat
 */
Candidat :: Candidat (const std::string& p_nas, const std::string& p_prenom,
            const std::string& p_nom, const std::string& p_adresse,
            const util::Date& p_dateNaissance, int p_partiPolitique):
Personne(p_nas, p_prenom, p_nom, p_adresse,p_dateNaissance),
  m_partiPolitique(p_partiPolitique)
{
  PRECONDITION(estPartiValide(p_partiPolitique));
  
  POSTCONDITION(m_partiPolitique == p_partiPolitique);
  
  INVARIANTS();
}

/**
 * \brief Méthode accesseur récupérant la parti politique du candidat
 * \return la parti politique
 */
int Candidat :: reqPartiPolitique() const 
{
  return m_partiPolitique;
}

/**
 * \brief Methode qui retourne le nom du parti politique du candidat sous forme de chaîne de caractères.
 * Cette fonction utilise l'attribut `m_partiPolitique` pour déterminer le nom du parti
 * auquel le candidat appartient et retourne la chaîne correspondante.
 * \return std::string La chaîne représentant le nom du parti politique du candidat. 
 *         Si aucun parti valide n'est trouvé, retourne "Parti inconnu".
 */
std::string Candidat::reqStringParti() const{
    switch (m_partiPolitique) {
       case BLOC_QUEBECOIS:
           return "Bloc Quebecois";
       case CONSERVATEUR:
           return "Conservateur";
       case INDEPENDANT:
           return "Independant";
       case LIBERAL:
           return "Liberal";
       case NOUVEAU_PARTI_DEMOCRATIQUE:
           return "Nouveau Parti Democratique";
       default:
           return "Parti inconnu";
   }
 }

/**
 * \brief Crée une copie (clone) de l'objet `Candidat` actuel.
 * \return std::unique_ptr<Personne> Un pointeur unique vers un nouvel objet `Candidat` qui est une copie
 *         de l'objet actuel. Ce pointeur est géré automatiquement par `std::unique_ptr`.
 */
std::unique_ptr <Personne> Candidat :: clone () const
{
  return unique_ptr <Personne> (new Candidat (*this));
}

/**
 * \brief methode qui formate et retourne une représentation textuelle complète d'un candidat.
 * \return std::string Une chaîne de caractères contenant les informations formatées du candidat
 * \note : Cette methode est une augmentation de la methode reqPersonneFormat() de la classe Personne
 */
std::string Candidat :: reqPersonneFormate ()const
{
  ostringstream os;
  os<<"Candidat"<<endl;
  os<<"----------------------------------------------"<<endl;
  os<<Personne::reqPersonneFormate();
  os<<"Parti politique   : "<<reqStringParti()<<endl;
  return os.str();
}

/**
 * \brief verifier les invariants de la classe Candidat
 */
void Candidat :: verifieInvariant() const 
{
 INVARIANT (estPartiValide(m_partiPolitique)) ;
}

/**
 * \brief Vérifie si un identifiant de parti politique est valide.
 * \param[in] p_parti L'identifiant sous forme d'un entier du parti politique à valider.
 * \return retourne un booleen `true` si l'identifiant du parti est valide ,
 *              sinon retourne `false`.
 */
bool estPartiValide(int p_parti){
  return p_parti >= PartisPolitiques::BLOC_QUEBECOIS && p_parti <= PartisPolitiques::NOUVEAU_PARTI_DEMOCRATIQUE;
}
}
