#ifndef PERSONNEEXCEPTION_H
#define PERSONNEEXCEPTION_H

#include<stdexcept>

namespace elections {
class PersonneException : public std::runtime_error
{
public:
  PersonneException (const std::string& p_raison):std::runtime_error(p_raison){}
};

class PersonneDejaPresenteException : public PersonneException
{
public:
  PersonneDejaPresenteException (const std::string& p_raison):PersonneException(p_raison){}
};

class PersonneAbsenteException : public PersonneException
{
public:
  PersonneAbsenteException (const std::string& p_raison):PersonneException(p_raison){}
};
}

#endif /* PERSONNEEXCEPTION_H */

