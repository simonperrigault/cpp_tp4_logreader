/*************************************************************************
                          Analyse  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Interface de la classe <Analyse> (fichier Analyse.h) ----------------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H

#include "Requete.h"
#include <unordered_map>
#include <string>
#include <vector>
//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Analyse>
//
//
//------------------------------------------------------------------------
class Analyse
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
  bool Generation_dot(string nom_fichier) const;
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  void AddRequete(const Requete & Requete);
  // type Méthode ( liste des paramètres );
  // Mode d'emploi :
  //
  // Contrat :
  //

  
//------------------------------------------------- Surcharge d'opérateurs
  Analyse & operator = ( const Analyse & unAnalyse );
  // Mode d'emploi :
  //
  // Contrat :
  //
//-------------------------------------------- Constructeurs - destructeur
  Analyse ( const Analyse & unAnalyse );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //
  Analyse (const vector<Requete> & vecReq);
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~Analyse ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
  void GetTop(unsigned int taille) const;
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés

  unordered_map <string, pair<unordered_map <string, int>, int>> data;
};
//-------------------------------- Autres définitions dépendantes de <Analyse>
#endif // ANALYSE_H
