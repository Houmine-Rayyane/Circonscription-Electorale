/* 
 * File:   validationFormat.cpp
 * Author: Rayyane Houmine AKA THE BO$$
 *
 * Created on 25 septembre 2024, 18 h 30
 */

#include <iostream>
#include <string>
#include <sstream>
#include<cctype>
#include "validationFormat.h"


using namespace std;

/**
 * \brief : valide le format du numero d'assurance sociale
 * \param[in] numero d'assurance sociale a valider
 */
bool validerNas(const std::string& p_nas){ 
  
  //Verifier que la longueur du Nas entree est bel et bien 11
  if (p_nas.size() != 11) return false;
  
 //Verifier que le Nas respecte la norme du format "XXX XXX XXX"
 // et enlever les espaces du Nas
  string nasSansEspaces;
  for (int i =0;i<p_nas.size();i++){
      if (i==3 || i == 7)
        {
          if (p_nas[i] !=' ')return false;
        }else if (isdigit(p_nas[i]))
            {
              nasSansEspaces +=p_nas[i];
            }else{
              return false;
            }
    }

  
  //Initialiser le produit et la somme
  int produit = 1;
  int somme =0;
  
  //Multiplier le Nas par 121 212 121
  for (int i=0;i< nasSansEspaces.size();i++){
      //Convertir chaque caractere en chiffre entier equivalent
      int valeurNumerique = nasSansEspaces[i] - '0';
      
      //Multiplier par 1 si l'index de la position est pair,par 2 si il est impair
      (i%2==0)?produit = valeurNumerique:produit = valeurNumerique * 2;
 
      //Si le produit est compose de deux chifres, additioner les chiffres
    (produit>9) ?somme+= (produit / 10) + (produit % 10):somme+=produit;
      
    }
  
  //Verifier si la somme est divisible par 10
  return (somme%10 == 0);
}

/**
 * \brief : valide le format du fichier des donnees
 * \param[in] p_is flux de carateres de type istream
 */
bool validerFormatFichier(std::istream &p_is){
  string ligne;
  
  if (!getline(p_is, ligne)){
      return false;
    }
  
  while (getline(p_is,ligne)){
      string nas, prenom,nom,date,adresse,parti;
      
      //Candidat?
      if (partiPolitique(ligne)){//Oui
          parti = ligne;
          
          if (!getline(p_is, nas)||!getline(p_is, prenom)||!getline(p_is, nom)||
              !getline(p_is, date)||!getline(p_is, adresse)){
              return false;
            }
        }else{//Electeur:
          nas = ligne;
          
          if (!getline(p_is, prenom)||!getline(p_is, nom)||
              !getline(p_is, date)||!getline(p_is, adresse)){
              return false;
            }
          }
      //Verifier si les donnees sont vides et utiliser les fonctions
      //validerNas() et validerDate() pour analyser le nas et la date
      if (nas.empty() || prenom.empty() || nom.empty() || date.empty() ||
          adresse.empty() ||!validerDate(date) || !validerNas(nas)) {
            return false;
        }
    }
  return true;
}

/**
 * \brief : valide le format de la date
 * \param[in] date chaine de caractere qui represente la date
 * \return un booleen true si la date est valide, sinon false
 */
bool validerDate(const std::string& date) {
    bool valide = false; 

    if (!date.empty()) {
        bool formatValide = true;
        for (char c : date) {
            if (!isdigit(c) && c != ' ') {
                formatValide = false;
                break;
            }
        }

        if (formatValide) {
            if (date.size() == 10 && date[2] == ' ' && date[5] == ' ') {
                int jour = stoi(date.substr(0, 2));
                int mois = stoi(date.substr(3, 2));
                int annee = stoi(date.substr(6, 4));

                
                if (jour >= 1 && jour <= 31) {
                    if (mois >= 1 && mois <= 12) {
                        if (annee >= 1970 && annee <= 2037) {
                            valide = true; 
                        }
                    }
                }
            }
        }
    }

    return valide;
}

//Fonction supplementaire qui verifie si la ligne est une parti
bool partiPolitique(const string& ligne){
  for (const auto& parti :PARTIS){
      if (ligne == parti){
          return true;
        }
    }
  return false;
}
