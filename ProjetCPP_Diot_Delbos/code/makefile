FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: simulation

simulation : Jeu.o Personnage.o Jeu.hpp
	g++ $(FLAG) -o simulation Jeu.o Personnage.o $(LINKER_FLAGS)

Jeu.o: Jeu.cpp Jeu.hpp
	g++ $(FLAG) -c Jeu.cpp

Personnage.o: Personnage.cpp Personnage.hpp Outil.hpp ToDraw.hpp Pioche.hpp Hache.hpp ElemEnv.hpp
	g++ $(FLAG) -c Personnage.cpp

clean:
	rm -f *.o
