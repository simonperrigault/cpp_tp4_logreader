/*************************************************************************
                          Requete  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H
//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------
class Requete
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //
//------------------------------------------------- Surcharge d'opérateurs
  Requete & operator = ( const Requete & unRequete );
  // Mode d'emploi :
  //
  // Contrat :
  //
//-------------------------------------------- Constructeurs - destructeur
  Requete ( const Requete & unRequete );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //
  Requete(const string & p_ip="", const string & p_userLogName="", const string & p_authenticatedUser="", const string & p_date="", int p_hour=0, int p_minute=0, int p_second=0, int p_gmt=0, const string & p_requestType="", const string & p_target="",const string & p_protocole="", int p_status=0, int p_size=0, const string & p_referer="", const string & p_navigator="");
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~Requete ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

  // on met les attributs en public pour pouvoir les utiliser dans le main
  // la classe agit comme une structure
  // elle sert à mieux organiser les données recueillies par le reader
  string ip;
  string userLogName;
  string authenticatedUser;
  string date;
  int hour;
  int minute;
  int second;
  int gmt;
  string requestType;
  string cible;
  string protocole;
  int status;
  int size;
  string referer;
  string navigator;
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Requete>
#endif // REQUETE_H