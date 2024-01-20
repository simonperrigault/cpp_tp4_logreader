/*************************************************************************
                          Reader  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Interface de la classe <Reader> (fichier Reader.h) ----------------
#if ! defined ( READER_H )
#define READER_H
//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Requete.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Reader>
//
//
//------------------------------------------------------------------------

class Reader : public ifstream
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

  Requete GetNextRequest(); //méthode qui lit le fichier log et renvoie la requête suivante
//------------------------------------------------- Surcharge d'opérateurs
  Reader & operator = ( const Reader & unReader );
  // Mode d'emploi :
  //
  // Contrat :
  //
//-------------------------------------------- Constructeurs - destructeur
  Reader ( const Reader & unReader );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //
  Reader(const string & cheminFichierLog, const string & URL_BASE);
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~Reader ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  string url_base;
};
//-------------------------------- Autres définitions dépendantes de <Reader>
#endif // READER_H