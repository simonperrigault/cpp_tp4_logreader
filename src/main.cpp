#include <regex>
#include <iostream>

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
      try
      {
        time = stoi(argv[i + 1]);
      }
      catch(const invalid_argument& e)
      {
        cerr << "Veuillez entrer un nombre après -t" << endl;
        return 1;
      }
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

    string extension;
    regex pattern_extension("\\.([^\\.]{1,5})$");
    smatch match;
    if (!wantImage && regex_search(req.cible, match, pattern_extension))
    {
      extension = match[1].str();
      // liste des extensions trouvées dans anonyme.log
      // 7z, asm, bmp, clf, css, doc, docx, gif, htlm, htm, html, ic
      // ico, ics, jpg, js, masm, pdf, php, png, pps, txt, xml, zip

      if (extension == "png" || extension == "jpg" || extension == "gif" || extension == "bmp" || extension == "ico")
      // images
      {
        continue;
      }
    }
    if (req.status >= 400) // enlève les requêtes en erreurs
    {
      continue;
    }

    // on nettoie les cibles et referers si elles sont trop longues
    pos = min(req.cible.find('#'), min(req.cible.find(';'), req.cible.find('?')));
    if (pos != string::npos)
    {
      req.cible.resize(pos);
    }
    pos = min(req.referer.find('#'), min(req.referer.find(';'), req.referer.find('?')));
    if (pos != string::npos)
    {
      req.referer.resize(pos);
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
