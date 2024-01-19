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
  Analyse ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
  virtual ~Analyse ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};
//-------------------------------- Autres définitions dépendantes de <Analyse>
#endif // ANALYSE_H