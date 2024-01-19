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
  Requete ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~Requete ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};
//-------------------------------- Autres définitions dépendantes de <Requete>
#endif // REQUETE_H