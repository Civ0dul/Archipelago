#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <vector>
#include <cmath>
#include "tools.h"
using namespace std;

enum NodeType {Logement, Transport, Production};
<<<<<<< HEAD
typedef vector<unsigned int> Liste;



=======
typedef vector<unsigned int> Links;
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1

class Noeud {
	
public:
	
	Noeud(NodeType type_, unsigned int uid_, double x_,
		  double y_, unsigned int capacity_);
	
<<<<<<< HEAD
	void AddLink (unsigned int uid);
	Point GetCentre () const;
	unsigned int GetCapacity () const;
	unsigned int GetUid () const;
	NodeType GetType () const;
	Liste GetV () const;
=======
	void addLink (unsigned int uid);
	Point getCentre () const;
	unsigned int getCapacity () const;
	unsigned int getUid () const;
	NodeType getType () const;
	Links getV () const;
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
	
private:
	
	NodeType type;
	unsigned int uid;
<<<<<<< HEAD
	Liste V;
=======
	Links V;
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
	Point c;
	unsigned int capacity;
	
};

Noeud analyse_ligne_noeud(string ligne, NodeType type);
<<<<<<< HEAD
Liste analyse_ligne_link(string ligne);
=======
Links analyse_ligne_link(string ligne);
>>>>>>> 42649b540cb0476014f4d2e95bda5cab248f8dd1
	
#endif
