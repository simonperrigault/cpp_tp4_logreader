#include <iostream>
#include <string>
#include <vector>

#include "../int/Analyse.h"
#include "../int/Reader.h"

using namespace std;

const string URL_BASE = "http://intranet-if.insa-lyon.fr";

int main (int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "Usage: " << argv[0] << " [options] file.log" << endl;
    return 1;
  }
  bool wantGraph = false;
  string graphFile;
  bool wantTime = false;
  int time = 0;
  bool wantImage = true;
  for (int i = 1; i < argc; ++i)
  {
    string arg = argv[i];
    if (arg == "-e")
    {
      wantImage = false;
    }
    else if (arg == "-t")
    {
      wantTime = true;
      time = stoi(argv[i + 1]);
    }
    else if (arg == "-g")
    {
      wantGraph = true;
      graphFile = argv[i + 1];
    }
  }

  string filename = argv[argc - 1];
  Reader reader(filename, URL_BASE);
  if (reader.is_open() == false)
  {
    cerr << "Erreur lors de l'ouverture du fichier" << endl;
    return 1;
  }
  vector<Requete> tableauRequetes;
  Requete req;
  size_t pos;

  while (reader.GetNextRequest(req))
  {
    
    if (wantTime && req.hour != time)
    {
      continue;
    }
    if (!wantImage && req.cible.find(".html") == string::npos && req.cible.find(".php") == string::npos)
    {
      continue;
    }
    if (req.status >= 400) // enlève les erreurs
    {
      continue;
    }

    tableauRequetes.push_back(req);
    pos = req.cible.find(';');
    pos = min(req.cible.find('#'), pos);
    pos = min(req.cible.find('?'), pos);
    if (pos != string::npos)
    {
      req.cible = req.cible.substr(0, pos);
    }
    
        tableauRequetes.push_back(req);
  }

  Analyse analyse(tableauRequetes);
  analyse.GetTop(10);

  if (wantGraph)
  {
    analyse.Generation_dot(graphFile);
  }
  

  return 0;
}
