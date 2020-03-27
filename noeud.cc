#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "noeud.h"
#include "tools.h"
#include "error.h"
#include "constantes.h"

using namespace std;

Noeud::Noeud(NodeType type_, unsigned int uid_, double x_, 
			 double y_, unsigned int capacity_)
: type(type_), uid(uid_), c(x_,y_), capacity(capacity_)
{}

bool verificationNoeud(unsigned int uid, unsigned int capa){
	if (uid == no_link){
		cout << error::reserved_uid();
		return false;
	}
	if (capa<min_capacity){
		cout << error::too_little_capacity(capa);
		return false;
	}
	if (capa>max_capacity){
		cout << error::too_much_capacity(capa);
		return false;
	}
	return true;
}

Noeud analyse_ligne_noeud(string ligne, NodeType type){
	istringstream data(ligne);
	unsigned int uid;
	double coordx, coordy;
	unsigned int capa;
	data >> uid >> coordx >> coordy >> capa;

	if (verificationNoeud(uid, capa)){
		return (Noeud (type, uid, coordx, coordy, capa));
	}
	else exit(1);
}

bool verificationLien(unsigned int id1, unsigned int id2){
	if (id1==id2) {
		cout << error::self_link_node(id1);
		return false;
	}
	return true;
	
}

Links analyse_ligne_link(string ligne){
	istringstream data(ligne);
	unsigned int uid1, uid2;
	data >> uid1 >> uid2;
	if (verificationLien(uid1, uid2)){
		return (Links {uid1, uid2});
	}
	else exit(1);
}




	
void Noeud::addLink (unsigned int uid) {
	V.push_back(uid);
}

Point Noeud::getCentre () const {return c;}
unsigned int Noeud::getCapacity () const {return capacity;}
unsigned int Noeud::getUid () const {return uid;}
NodeType Noeud::getType () const {return type;}
Links Noeud::getV () const {return V;}
