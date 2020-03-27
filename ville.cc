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


class Ville{
public:
	Ville(unsigned int nbrL=0, unsigned nbrT=0, unsigned int nbrP=0);
	void AddNode (Noeud noeud);
	void AddLink (Liste link);
	Web GetN () const;
	vector<Liste> GetLiens () const;
	
private:
	vector<Liste> liens;
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

Web Ville::GetN () const {return N;}
vector<Liste> Ville::GetLiens () const {return liens;}	

void Ville::AddNode(Noeud noeud) {
	
	N.push_back(noeud);
}

void Ville::AddLink(Liste link) {
	liens.push_back(link);
}


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
		if(distance <= r1+r2) {
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
	
	for(auto& element : v.GetN()) {
		double x2,x3,y2,y3,dx,dy,p;
		x2 = element.GetCentre().GetX();
		y2 = element.GetCentre().GetY();

		for(auto uid : element.GetV()) {
			x3 = uid.GetCentre().GetX();
			y3 = uid.GetCentre().GetY();
		}
		
		dx = x2-x3;
		dy = y2-y3;
		p = dy/dx;
	
	
			
			
				
	


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
		v.AddNode(analyse_ligne_noeud(line, type));
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
		v.AddNode(analyse_ligne_noeud(line, type));
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
		v.AddNode(analyse_ligne_noeud(line, type));
		++i;
		if(i == total) etat=NB3 ;
	    break;
	    
	case NB3: 
		if(!(data >> total)) erreur(LECTURE_NB); 
		else i=0;
		if(total==0) etat=FIN; else etat=LINK ; 
		break;

	case LINK:
		v.AddLink(analyse_ligne_link(line));
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
