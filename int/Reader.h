/*************************************************************************
                          Reader  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Interface de la classe <Reader> (fichier Reader.h) ----------------
#if !defined(READER_H)
#define READER_H
//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <fstream>
#include "Requete.h"

using namespace std;

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

  Reader & GetNextRequest(Requete & req); // méthode qui lit le fichier log et rentre les informations dans une requête
  //------------------------------------------------- Surcharge d'opérateurs

  //-------------------------------------------- Constructeurs - destructeur

  Reader(const string &cheminFichierLog, string URL_BASE);
  // Mode d'emploi :
  //
  // Contrat :
  //
  ~Reader() override;
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
