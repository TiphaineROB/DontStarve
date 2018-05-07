FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: simulation

simulation : Simulation.o Simulation.hpp
	g++ $(FLAG) -o simulation Simulation.o $(LINKER_FLAGS)

Simulation.o: Simulation.cpp Simulation.hpp
	g++ $(FLAG) -c Simulation.cpp

clean:
	rm -f *.o
