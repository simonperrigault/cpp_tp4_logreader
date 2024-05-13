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
#include <utility>

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
= default;
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

Requete::Requete(string  p_ip, string  p_userLogName, string  p_authenticatedUser, string  p_date, int p_hour, int p_minute, int p_second, int p_gmt, string  p_requestType, string  p_target, string  p_protocole, int p_status, int p_size, string  p_referer, string  p_navigator)
  : ip(std::move(p_ip)), userLogName(std::move(p_userLogName)), authenticatedUser(std::move(p_authenticatedUser)), date(std::move(p_date)), hour(p_hour), minute(p_minute), second(p_second), gmt(p_gmt), requestType(std::move(p_requestType)), cible(std::move(p_target)), protocole(std::move(p_protocole)), status(p_status), size(p_size), referer(std::move(p_referer)), navigator(std::move(p_navigator))
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