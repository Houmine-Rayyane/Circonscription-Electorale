/* 
 * File:   validationFormat.h
 * Author: Rayyane Houmine AKA THE BO$$
 *
 * Created on 25 septembre 2024, 18 h 30
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include<array>
#include <string>

/**
 *\brief : Declaration des fonctions du fichier validationFormat.cpp
 */

const std::array<std::string,5> PARTIS={
  "BLOC_QUEBECOIS",
    "CONSERVATEUR",
    "INDEPENDANT",
    "LIBERAL",
    "NOUVEAU_PARTI_DEMOCRATIQUE"
};

bool validerNas(const std::string& p_nas);
bool validerDate(const std::string& date);
bool partiPolitique(const std::string& ligne);
bool validerFormatFichier(std::istream& p_is);


#endif /* VALIDATIONFORMAT_H */

