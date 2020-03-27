# Definitions de macros

CXX     = g++
CXXFLAGS = -g -Wall -std=c++11
CXXFILES = error.cc noeud.cc ville.cc projet.cc
OFILES = $(CXXFILES:.cc=.o)


# Definition de la premiere regle

prog: $(OFILES)
	$(CXX) $(OFILES) -o projet

# Definitions de cibles particulieres

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CXX) -MM $(CXXFLAGS) $(CXXFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x *.cc~ *.h~ projet

#
# -- Regles de dependances generees automatiquement
#
# DO NOT DELETE THIS LINE
error.o: error.cc error.h constantes.h
noeud.o: noeud.cc noeud.h tools.h error.h constantes.h
ville.o: ville.cc ville.h noeud.h tools.h constantes.h error.h
projet.o: projet.cc ville.h
