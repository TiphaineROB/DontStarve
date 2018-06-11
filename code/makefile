FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: simulation

testElem : testElem.o TestElemEnv.hpp
	g++ $(FLAG) -o testElem testElem.o $(LINKER_FLAGS)

testElem.o : TestElemEnv.cpp TestElemEnv.hpp
	g++ $(FLAG) -c TestElemEnv.cpp


simulation : ToDraw.o Simulation.o Personnage.o Jeu.hpp
	g++ $(FLAG) -o simulation Simulation.o Personnage.o $(LINKER_FLAGS)

Simulation.o: Simulation.cpp Jeu.hpp
	g++ $(FLAG) -c Simulation.cpp

ToDraw.o: ToDraw.cpp ToDraw.hpp
	g++ $(FLAG) -c ToDraw.cpp

Personnage.o: Personnage.cpp Personnage.hpp Outil.hpp ToDraw.hpp Pioche.hpp Hache.hpp ElemEnv.hpp
	g++ $(FLAG) -c Personnage.cpp

clean:
	rm -f *.o
