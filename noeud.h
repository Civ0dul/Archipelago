#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <vector>
#include <cmath>
#include "tools.h"
using namespace std;

enum NodeType {Logement, Transport, Production};
typedef vector<unsigned int> Links;




class Noeud {
	
public:
	
	Noeud(NodeType type_, unsigned int uid_, double x_,
		  double y_, unsigned int capacity_);
	
	void addLink (unsigned int uid);
	Point getCentre () const;
	unsigned int getCapacity () const;
	unsigned int getUid () const;
	NodeType getType () const;
	Liste getV () const;
	
private:
	
	NodeType type;
	unsigned int uid;
	Links V;
	Point c;
	unsigned int capacity;
	
};

Noeud analyse_ligne_noeud(string ligne, NodeType type);
Links analyse_ligne_link(string ligne);
	
#endif
