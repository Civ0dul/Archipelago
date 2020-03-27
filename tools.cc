#include "tools.h"

//définition des fonctions
S2d point(double varX, double varY){
	return {varX, varY};
}

int main(){
	point(1., 1.);
	cout << point.x;
	return 0;
}
