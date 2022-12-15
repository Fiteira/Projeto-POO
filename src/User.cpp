#include "User.h"

User::User(int _id,string _nome)
{
  ID=_id;
  NOME=_nome;
}

User::~User()
{
//      cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
