#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "ville.h"
#include "noeud.h"
#include "tools.h"
#include "constantes.h"
#include "error.h"

using namespace std;

typedef vector<Noeud> Web;

<<<<<<< HEAD
=======
bool check_link (Noeud noeud1, Noeud noeud2);
bool check_identical_uid (unsigned int uid);
bool check_link_vacuum (Links lien);
bool check_max_link (Noeud noeud);
bool check_multiple_same_link (Links lien);


>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1

class Ville{
public:
	Ville(unsigned int nbrL=0, unsigned nbrT=0, unsigned int nbrP=0);
<<<<<<< HEAD
	void AddNode (Noeud noeud);
	void AddLink (Liste link);
	Web GetN () const;
	vector<Liste> GetLiens () const;
	
private:
	vector<Liste> liens;
=======
	void addNode (Noeud noeud);
	void addLink (Links link);
	Web getN () const;
	vector<Links> getLink() const;
	
private:
	vector<Links> liens;
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
	Web N;
	unsigned int nombreL;
	unsigned int nombreT;
	unsigned int nombreP;
	double ENJ = 0;
	double CI = 0;
	double MTA = 0;
};

Ville::Ville(unsigned int nbrL, unsigned nbrT, unsigned int nbrP)
: nombreL(nbrL), nombreT(nbrT), nombreP(nbrP)
{}

Ville v;

<<<<<<< HEAD
Web Ville::GetN () const {return N;}
vector<Liste> Ville::GetLiens () const {return liens;}	

void Ville::AddNode(Noeud noeud) {
	
	N.push_back(noeud);
}

void Ville::AddLink(Liste link) {
=======
Web Ville::getN () const {return N;}

vector<Links> Ville::getLink() const { return liens; }	

void Ville::addNode(Noeud noeud) {
	if (check_identical_uid(noeud.getUid())) exit(1);
	N.push_back(noeud);
}

void Ville::addLink(Links link) {
	if (check_link_vacuum(link)) exit(1);
	if (check_multiple_same_link(link)) exit(1);
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
	liens.push_back(link);
}


<<<<<<< HEAD
//-----------Vérifications---------------

bool check_node_node_superposition(Noeud noeud) const {
	bool resultat(true);
	double x1,y1,x2,y2,r1,r2,dx,dy;
	double distance;
	x1 = noeud.GetCentre().GetX();
	y1 = noeud.GetCentre().GetY();
	r1 = sqrt(noeud.GetCapacity());
	
	for(auto& element : v.GetN()) {
		x2 = element.GetCentre().GetX();
		y2 = element.GetCentre().GetY();
		r2 = sqrt(element.GetCapacity());
		dx = x1-x2;
		dy = y1-y2;
		distance = sqrt(dx*dx + dy*dy);
		if(distance < r1+r2+dist_min) {
			resultat = false;
			cout << error::node_node_superposition(noeud.GetUid(), element.GetUid());
		}
	}
	return resultat;
}	

bool check_node_link_superposition(Noeud noeud) {
	bool resultat(true);
	double x1,y1,r1;
	x1 = noeud.GetCentre().GetX();
	y1 = noeud.GetCentre().GetY();
	r1 = sqrt(noeud.GetCapacity());
	
	for(auto& liste_liens : v.GetLiens()) {
		for(auto& elements : liste_liens) {
			
			
				
=======
bool check_identical_uid (unsigned int uid) {
	for (auto i : v.getN()){
		if (i.getUid() == uid){
			cout << error::identical_uid(uid);
			return true;
		}
	}
	return false;
}
	
bool check_link_vacuum (Links lien) {
	for (auto i : v.getN()){
		if (lien[1] == i.getUid()){
			return false;
		}
	}
	cout << error::link_vacuum(lien[1]);
	return true;
}
	
bool check_max_link (Noeud noeud) {
	if (noeud.getType() == Logement and noeud.getV().size() >= max_link)
	{ 
		return false; 
	}
	return true;
}

bool check_multiple_same_link (Links lien) {
	for (auto i : v.getLink()){
		if (lien[0] == i[1] and lien[1] == i[0]){
			cout << error::multiple_same_link(i[0], i[1]);
			return true;
		}
	}
	return false;
}
	

					 
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
	


//------------Automate de lecture --------------
void lecture( char * nom_fichier)
{
    string line;
    ifstream fichier(nom_fichier); 
    if(!fichier.fail()) 
    {
        while(getline(fichier >> ws,line)) 
        {
			if(line[0]=='#' or line[0]=='\n' or line[0]=='\r')  continue;
			
			decodage_ligne(line);	
				
        }
        cout << "Fin de la lecture" << endl;
	}
	else erreur(LECTURE_OUVERTURE);
}

void decodage_ligne(string line){
	istringstream data(line);
  
	enum Etat_lecture {NB0,HOUSING,NB1,TRANSPORT,NB2,PRODUCTION,
					   NB3, LINK, FIN};
  
	static int etat(NB0);
	static int i(0), total(0);
	NodeType type;
	switch(etat) 
	{
	case NB0: 
		if(!(data >> total)) erreur(LECTURE_NB); 
		else i=0 ;
		if(total==0) etat=NB1; else etat=HOUSING ; 
	    break;

	case HOUSING: 
		type = Logement;
<<<<<<< HEAD
		v.AddNode(analyse_ligne_noeud(line, type));
=======
		v.addNode(analyse_ligne_noeud(line, type));
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
		++i;
		if(i == total) etat=NB1 ;
	    break;

	case NB1: 
		if(!(data >> total)) erreur(LECTURE_NB); 
		else i=0 ;
		if(total==0) etat=NB2; else etat=TRANSPORT ; 
	    break;

	case TRANSPORT:
		type = Transport;
<<<<<<< HEAD
		v.AddNode(analyse_ligne_noeud(line, type));
=======
		v.addNode(analyse_ligne_noeud(line, type));
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
		++i;
		if(i == total) etat=NB2 ;
	    break;

	case NB2: 
		if(!(data >> total)) erreur(LECTURE_NB); 
		else i=0;
		if(total==0) etat=NB3; else etat=PRODUCTION ; 
		break;

	case PRODUCTION: 
		type = Production;
<<<<<<< HEAD
		v.AddNode(analyse_ligne_noeud(line, type));
=======
		v.addNode(analyse_ligne_noeud(line, type));
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
		++i;
		if(i == total) etat=NB3 ;
	    break;
	    
	case NB3: 
		if(!(data >> total)) erreur(LECTURE_NB); 
		else i=0;
		if(total==0) etat=FIN; else etat=LINK ; 
		break;

	case LINK:
<<<<<<< HEAD
		v.AddLink(analyse_ligne_link(line));
=======
		v.addLink(analyse_ligne_link(line));
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
		++i;
		if(i == total) etat=FIN ;
	    break;

	case FIN: erreur(LECTURE_FIN);
		break;

	default: erreur(LECTURE_ETAT);
	}	
}

void erreur(Erreur_lecture code)
{
	switch(code)
	{
	case LECTURE_ARG : cout << "-- Nom de fichier manquant --\n"; break;
	case LECTURE_OUVERTURE: cout << "-- Ouverture impossible --\n";break;
	case LECTURE_NB : cout << "-- Erreur de lecture dans nombre --\n"; break;
	case LECTURE_FIN : cout << error::success(); break;
	case LECTURE_ETAT : cout << "-- Etat inexistant --\n"; break;
	default: cout << "-- Erreur inconnue --\n";
	}
	exit(EXIT_FAILURE);
}
