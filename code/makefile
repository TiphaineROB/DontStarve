FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: simulation

simulation : Simulation.o Personnage.o Simulation.hpp
	g++ $(FLAG) -o simulation Simulation.o Personnage.o $(LINKER_FLAGS)

Simulation.o: Simulation.cpp Simulation.hpp
	g++ $(FLAG) -c Simulation.cpp

Personnage.o: Personnage.cpp Personnage.hpp
	g++ $(FLAG) -c Personnage.cpp

clean:
	rm -f *.o
