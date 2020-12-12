# ================================= VARIABLES =================================

#--------------------------- Parametres compilateurs ---------------------------
CPPFLAGS = -ansi -pedantic -Wall -std=c++11
CC = g++

#------------------------------- Fichiers source -------------------------------
CPP = $(wildcard *.cpp)
O = $(CPP:%.cpp=%.o)
TEST = ListeChaineeGenerique.o Noeud.o trajet_compose.o  \
       chainon.o trajet_simple.o liste_chainee.o ListeChaineeGenerique.o \
       ChainonGenerique.o Catalogue.o

# ================================ REGLES MAKE ================================

# -------------------------------- EXECUTABLES --------------------------------
test_liste_chainee.out:test_liste_chainee.o $(TEST) 
	g++ -o $@ $^

main.out:main.o chainon.o liste_chainee.o trajet_simple.o Catalogue.o trajet_compose.o
	g++ -o $@ $^

test.out:tests.o $(TEST)
	g++ -o $@ $^

#--------------------------------- COMPILATION ---------------------------------
main.o:main.cpp CouleurTTY.h
tests.o:tests.cpp
test_liste_chainee.o:test_liste_chainee.cpp
trajet_compose.o:trajet_compose.cpp trajet_compose.h CouleurTTY.h
Catalogue.o:Catalogue.cpp Catalogue.h
chainon.o:chainon.cpp chainon.h
liste_chainee.o:liste_chainee.cpp liste_chainee.h CouleurTTY.h
trajet_simple.o:trajet_simple.cpp trajet_simple.h trajet.h
Noeud.o:Noeud.cpp Noeud.h CouleurTTY.h
ListeChaineeGenerique.o:ListeChaineeGenerique.cpp ListeChaineeGenerique.h
ChainonGenerique.o:ChainonGenerique.cpp ChainonGenerique.h
ArbreTrajet.o:ArbreTrajet.cpp ArbreTrajet.h

# ---------------------------------REGLES PHONY---------------------------------
debug: CPPFLAGS += -DMAP -g
debug: all
rebuild:clean debug
clean:
	@rm -vf *.o *.out *.gch

all:test.out
.PHONY: all clean rebuild debug
