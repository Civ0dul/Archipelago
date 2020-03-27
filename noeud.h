#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <vector>
#include <cmath>
#include "tools.h"
using namespace std;

enum NodeType {Logement, Transport, Production};
typedef vector<unsigned int> Liste;




class Noeud {
	
public:
	
	Noeud(NodeType type_, unsigned int uid_, double x_,
		  double y_, unsigned int capacity_);
	
	void AddLink (unsigned int uid);
	Point GetCentre () const;
	unsigned int GetCapacity () const;
	unsigned int GetUid () const;
	NodeType GetType () const;
	Liste GetV () const;
	
private:
	
	NodeType type;
	unsigned int uid;
	Liste V;
	Point c;
	unsigned int capacity;
	
};

Noeud analyse_ligne_noeud(string ligne, NodeType type);
Liste analyse_ligne_link(string ligne);
	
#endif
