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
//------------------------------------------------------ Include personnel
#include "../int/Reader.h"
#include "../int/Requete.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type Reader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Requete Reader::GetNextRequest()
{
    string ligne;
    std::getline(*this,ligne); //on récupère la ligne suivante du fichier log

    stringstream flux_string(ligne); //on convertit la ligne en flux

    string ip;
    string userLogName;
    string authenticatedUser;
    string date;
    int hour;
    int minute;
    char gmt_signe;
    int gmt;
    string requestType;
    string target;
    string protocole;
    int status;
    string size_string;
    int size_int;
    string referer;
    string navigator;

    flux_string >> ip >> userLogName >> authenticatedUser;
    
    flux_string.ignore(1); //on ignore le caractère [
    flux_string >> date;
    
    flux_string.ignore(1); //on ignore le caractère :
    flux_string >> hour;
    flux_string.ignore(1); //on ignore le caractère :
    flux_string >> minute;

    flux_string.ignore(4); //on ignore les caractères ':02 ', les secondes quoi

    flux_string >> gmt_signe >> gmt; //on récupère le signe et la valeur du gmt
    gmt = gmt/100; //formatage du fichier log est avec un gmt de type 0200, on le convertit en 2
    if (gmt_signe == '-') gmt = -gmt;

    flux_string.ignore(3); //on ignore les caractères ] "

    flux_string >> requestType >> target >> protocole;
    flux_string.ignore(1); //on ignore le caractère "
    
    flux_string >> status >> size_string;
    if (size_string == "-") size_int = 0;
    else size_int = stoi(size_string);
    
    flux_string.ignore(1); //on ignore le caractère "
    flux_string >> referer;
    flux_string.ignore(3); //on ignore les caractères " "

    std::getline(flux_string, navigator, '"');

    Requete requete(ip, userLogName, authenticatedUser, date, hour, minute, gmt, requestType, target, protocole, status, size_int, referer, navigator);

    return requete;
}

//------------------------------------------------- Surcharge d'opérateurs
Reader & Reader::operator = ( const Reader & unReader )
// Algorithme :
//
{
} //----- Fin de operator =
//-------------------------------------------- Constructeurs - destructeur
Reader::Reader ( const Reader & unReader )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <Reader>" << endl;
#endif
} //----- Fin de Reader (constructeur de copie)


Reader::Reader(const string& chemin, const string& p_URL_BASE) : ifstream(chemin), url_base(p_URL_BASE) //notre objet reader est un ifstream
{
    #ifdef MAP 
        cout << "Appel au constructeur de <Reader>" << endl;
    #endif
}


Reader::~Reader ( )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Reader>" << endl;
#endif
} //----- Fin de ~Reader
//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées