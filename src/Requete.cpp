/*************************************************************************
                          Requete  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../int/Requete.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type Requete::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//------------------------------------------------- Surcharge d'opérateurs
Requete& Requete::operator = (const Requete & uneRequete)
{   
  ip = uneRequete.ip;
  userLogName = uneRequete.userLogName;
  authenticatedUser = uneRequete.authenticatedUser;
  date = uneRequete.date;
  hour = uneRequete.hour;
  minute = uneRequete.minute;
  second = uneRequete.second;
  gmt = uneRequete.gmt;
  requestType = uneRequete.requestType;
  cible = uneRequete.cible;
  protocole = uneRequete.protocole;
  status = uneRequete.status;
  size = uneRequete.size;
  referer = uneRequete.referer;
  navigator = uneRequete.navigator;
  return *this;
}
//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & unRequete )
// Algorithme :
//
  : ip(unRequete.ip), userLogName(unRequete.userLogName), authenticatedUser(unRequete.authenticatedUser), date(unRequete.date), hour(unRequete.hour), minute(unRequete.minute), second(unRequete.second), gmt(unRequete.gmt), requestType(unRequete.requestType), cible(unRequete.cible), protocole(unRequete.protocole), status(unRequete.status), size(unRequete.size), referer(unRequete.referer), navigator(unRequete.navigator)
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)

Requete::Requete(const string & p_ip, const string & p_userLogName, const string & p_authenticatedUser, const string & p_date, int p_hour, int p_minute, int p_second, int p_gmt, const string & p_requestType, const string & p_target, const string & p_protocole, int p_status, int p_size, const string & p_referer, const string & p_navigator)
  : ip(p_ip), userLogName(p_userLogName), authenticatedUser(p_authenticatedUser), date(p_date), hour(p_hour), minute(p_minute), second(p_second), gmt(p_gmt), requestType(p_requestType), cible(p_target), protocole(p_protocole), status(p_status), size(p_size), referer(p_referer), navigator(p_navigator)
{
#ifdef MAP 
  cout << "Appel au constructeur de <Requete>" << endl;
#endif
}


Requete::~Requete ( )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées