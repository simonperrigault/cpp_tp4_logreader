/*************************************************************************
                          Reader  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <Reader> (fichier Reader.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <utility>
//------------------------------------------------------ Include personnel
#include "../int/Reader.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type Reader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Reader &Reader::GetNextRequest(Requete &req)
{

  // peut faire regex
  // regex pattern("(\\d+\\.\\d+\\.\\d+\\.\\d+) (-) (-) \\[(\\d{2}/\\w{3}/\\d{4}):(\\d{2}):(\\d{2}):(\\d{2}) (\\+|-)0(\\d)00] \\\"(\\w+) ([\\w\\d\\./]+) ([^\\\"]+)\\\" (\\d+|-) (\\d+|-) \\\"([^\\\"]+)\\\" \\\"([^\\\"]+)\\\"");

  string ligne;
  std::getline(*this, ligne); // on récupère la ligne suivante du fichier log
  if (!(*this)) // failbit ou badbit
  {
    return *this;
  }
  stringstream flux_string(ligne); // on convertit la ligne en flux

  string hour_string;
  string minute_string;
  char gmt_signe;
  string size_string;

  flux_string >> req.ip >> req.userLogName >> req.authenticatedUser;

  flux_string.ignore(2); // on ignore les caractères _[
  std::getline(flux_string, req.date, ':');

  std::getline(flux_string, hour_string, ':');
  std::getline(flux_string, minute_string, ':');
  try
  {
    req.hour = stoi(hour_string);
    req.minute = stoi(minute_string);
  }
  catch (const invalid_argument &e)
  {
    cerr << "Erreur lors de la conversion de l'heure" << endl;
    this->setstate(ios::failbit);
    exit(1);
  }

  flux_string >> req.second;

  flux_string.ignore(1); // on ignore _

  flux_string >> gmt_signe >> req.gmt; // on récupère le signe et la valeur du gmt
  req.gmt = req.gmt / 100; // formatage du fichier log est avec un gmt de type 0200, on le convertit en 2
  if (gmt_signe == '-')
    req.gmt = -req.gmt;

  flux_string.ignore(3); // on ignore les caractères ] "

  flux_string >> req.requestType >> req.cible;
  std::getline(flux_string, req.protocole, '"');

  flux_string >> req.status >> size_string;
  if (size_string == "-")
  {
    req.size = 0;
  }
  else
  {
    try
    {
      req.size = stoi(size_string);
    }
    catch(const invalid_argument& e)
    {
      cerr << "Erreur lors de la conversion de la taille" << endl;
      this->setstate(ios::failbit);
      exit(1);
    }
    
  }

  flux_string.ignore(2); // on ignore les caractères _"
  std::getline(flux_string, req.referer, '"');
  if (req.referer.compare(0, url_base.size(), url_base, 0, url_base.size()) == 0)
  {
    req.referer = req.referer.substr(url_base.size()); // on enlève l'URL de base pour ne garder que le chemin relatif
  }

  flux_string.ignore(2); // on ignore les caractères _"
  std::getline(flux_string, req.navigator, '"');

  return *this;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Reader::Reader(const string &chemin, string p_URL_BASE) : ifstream(chemin), url_base(std::move(p_URL_BASE)) // notre objet reader est un ifstream
{
#ifdef MAP
  cout << "Appel au constructeur de <Reader>" << endl;
#endif
}

Reader::~Reader()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Reader>" << endl;
#endif
} //----- Fin de ~Reader
  //------------------------------------------------------------------ PRIVE
  //----------------------------------------------------- Méthodes protégées
