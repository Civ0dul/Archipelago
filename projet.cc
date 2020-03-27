#include <iostream>
#include <cstdlib>
#include "ville.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc != 2){
		cout << "Erreur d'arguments" << endl;
		return EXIT_FAILURE;
	}
	lecture(argv[1]);
	return EXIT_SUCCESS;
}
