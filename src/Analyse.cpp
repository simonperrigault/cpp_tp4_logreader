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

bool Analyse::Generation_dot(const string& nom_fichier) const
{
  string fichier;
  ofstream file(nom_fichier, ofstream::out | ofstream::trunc);
  fichier += "digraph {";
  vector <string> noeud_cree;
  if (!file)
  {
    cerr << "Problème ouverture du fichier dot" << endl;
    file.close();
    exit(1);
  }

  if (data.empty())
  {
    cerr << "Aucun graphe créé" << endl;
    file.close();
    return false;
  }

  for (const auto & it1 : data)
  {
    for (auto it2 = it1.second.first.cbegin(); it2 != it1.second.first.cend(); ++it2)
    {
      fichier += "\""+it2->first + "\"->\"" + it1.first + "\" [label=\"" + to_string(it2->second) + "\"" +"];\n";
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


void Analyse::GetTop(unsigned int taille) const
{
  vector<pair<int, string>> top; // vector qu'on va garder trié par ordre croissant du int (= nombre de visites)
  int mini = 0;
  for (const auto & it : data)
  {
    if (top.size() < taille) // si on n'a pas atteint la taille max, on ajoute dans tous les cas
    {
      top.emplace_back(it.second.second, it.first);
      mini = min(mini, it.second.second);
    }
    else // sinon on ajoute que si le nombre de visites est supérieur au minimum de notre vector
    {
      if (it.second.second > mini)
      {
        top.emplace_back(it.second.second, it.first);
        sort(top.begin(), top.end());
        top.erase(top.begin());
        mini = top[0].first;
      }
    }
  }
  if (top.empty())
  {
    cout << "Aucun top à afficher" << endl;
    return;
  }
  sort(top.begin(), top.end());
  cout << "Top " << taille << ":" << endl;
  // on parcourt à l'envers pour avoir le top dans l'ordre décroissant
  for (auto it = top.crbegin(); it != top.crend(); ++it)
  {
    if (it->first == 1) // petite subtilité pour l'affichage avec un s ou pas
    {
      cout << "\t" << it->second << " (" << it->first << " hit)" << endl;
    }
    else
    {
      cout << "\t" << it->second << " (" << it->first << " hits)" << endl;
    }
  }
}

void Analyse::AddRequete(const Requete &Requete)
{
  ++(data[Requete.cible].second);
  // Incrémente le deuxième élément de la paire associé à la cible (= somme des visites)
  // Si aucune paire associée, élément intialisé à zéro par la unordered_map puis incrémenté

  ++data[Requete.cible].first[Requete.referer];
  // Incrémente l'élément associé au referer (= nombre de fois que le referer va vers la cible)
}

//------------------------------------------------- Surcharge d'opérateurs

Analyse &Analyse::operator=(const Analyse &unAnalyse)
// Algorithme :
//
{
  if (this != &unAnalyse) // regarde si l'adresse de l'objet est différente de l'adresse de l'objet passé en paramètre
  {
    data = unAnalyse.data;
  }
  return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Analyse::Analyse(const Analyse &unAnalyse) : data(unAnalyse.data)
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
  for (const auto & iterator : vecReq)
  {
    AddRequete(iterator);
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
