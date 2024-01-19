/*************************************************************************
                          Analyse  -  description
                          -------------------
    début                : DATE$
    copyright            : (C) YEAR$ par AUTHOR$
    e-mail               : EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <Analyse> (fichier Analyse.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "../int/Analyse.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>


//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Analyse::GetTop() const
{
  vector<pair<int, string>> top;
  for (auto it = data.begin(); it != data.end(); ++it)
  {
    push_heap(top.begin(), top.end(), [](pair<int, string> a, pair<int, string> b) { return a.first < b.first; });
    // on change la manière de comparer les pairs pour que le premier élément le plus grand soit en haut
    if (top.size() > 10)
    {
      top.pop_back();
    }
  }
  cout << "Top 10:" << endl;
  for (auto it = top.begin(); it != top.end(); ++it)
  {
    cout << "\t" << it->second << " (" << it->first << " hits)" << endl;
  }
}

//------------------------------------------------- Surcharge d'opérateurs
Analyse & Analyse::operator = ( const Analyse & unAnalyse )
// Algorithme :
//
{
} //----- Fin de operator =
//-------------------------------------------- Constructeurs - destructeur
Analyse::Analyse ( const Analyse & unAnalyse )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)
Analyse::Analyse ( )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de <Analyse>" << endl;
#endif
} //----- Fin de Analyse
Analyse::~Analyse ( )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées