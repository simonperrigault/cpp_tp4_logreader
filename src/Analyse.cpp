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
#include <vector>
//------------------------------------------------------ Include personnel
#include "../int/Analyse.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Analyse::Generation_dot(string nom_fichier) const
{
  string fichier;
  ofstream file(nom_fichier, ofstream::out | ofstream::trunc);
  fichier += "digraph {";
  vector<string> noeud_cree;
  if (!file)
  {
    cerr << "Problème ouverture du fichier" << endl;
    file.close();
    return false;
  }

  if (data.size() == 0)
  {
    cerr << "Aucun graphe créé" << endl;
    file.close();
    return false;
  }

  for (auto it1 = data.begin(); it1 != data.end(); it1++)
  {
    if (find(noeud_cree.begin(), noeud_cree.end(), it1->first) != noeud_cree.end())
    {
      fichier += "\""+it1->first + "\";";
      noeud_cree.push_back(it1->first);
    }

    for (auto it2 = it1->second.first.begin(); it2 != it1->second.first.end(); it2++)
    {
      if (find(noeud_cree.begin(), noeud_cree.end(), it2->first) != noeud_cree.end())
      {
        fichier += it2->first + ";";
        noeud_cree.push_back(it2->first);
      }
      fichier += "\""+it2->first + "\"->\"" + it1->first + "\" [label=\"" + to_string(it2->second) + "\"" +"];\n";
    }
  }

  fichier += "}";

  file << fichier;

  if (file.good())
  {
    cout << "Graphe généré avec succès !" << endl;
    file.close();
  }

  return true;
}


void Analyse::GetTop() const
{
  vector<pair<int, string>> top;
  int mini = 0;
  for (unordered_map<string, pair<unordered_map<string, int>, int>>::const_iterator it = data.cbegin(); it != data.cend(); ++it)
  {
    if (top.size() < 10)
    {
      top.push_back(make_pair(it->second.second, it->first));
      mini = min(mini, it->second.second);
    }
    else
    {
      if (it->second.second > mini)
      {
        top.push_back(make_pair(it->second.second, it->first));
        sort(top.begin(), top.end());
        top.erase(top.begin());
        mini = top[0].first;
      }
    }
  }
  sort(top.begin(), top.end());
  cout << "Top 10:" << endl;
  for (vector<pair<int, string>>::const_reverse_iterator it = top.crbegin(); it != top.crend(); ++it)
  {
    cout << "\t" << it->second << " (" << it->first << " hits)" << endl;
  }
}

void Analyse::AddRequete(const Requete &Requete)
{
  ++(data[Requete.cible].second); // Incrémente le deuxième élément de la paire associé à la cible
  // Si aucune paire associée, élément intialisé à zéro puis incrémenté
  ++data[Requete.cible].first[Requete.referer]; // Incrémente l'élément associé au referer
}

//------------------------------------------------- Surcharge d'opérateurs
// Analyse &Analyse::operator=(const Analyse &unAnalyse)
// // Algorithme :
// //
// {
// } //----- Fin de operator =
//-------------------------------------------- Constructeurs - destructeur
Analyse::Analyse(const Analyse &unAnalyse)
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)
Analyse::Analyse(const vector<Requete> & vecReq) : data()
// Algorithme :
//
{
  for (vector<Requete>::const_iterator iterator = vecReq.cbegin(); iterator != vecReq.cend(); iterator++)
  {
    AddRequete(*iterator);
  }
#ifdef MAP
  cout << "Appel au constructeur de <Analyse>" << endl;
#endif
} //----- Fin de Analyse
Analyse::~Analyse()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées