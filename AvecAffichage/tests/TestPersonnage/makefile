FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: TestPersonnage

TestPersonnage : TestPersonnage.o Personnage.o Outil.hpp ElemEnv.hpp Pioche.hpp Hache.hpp ToDraw.hpp
	g++ $(FLAG) -o TestPersonnage TestPersonnage.o Personnage.o $(LINKER_FLAGS)

TestPersonnage.o : TestPersonnage.cpp ElemEnv.hpp Outil.hpp Pioche.hpp Hache.hpp ToDraw.hpp
	g++ $(FLAG) -c TestPersonnage.cpp

Personnage.o: Personnage.cpp Personnage.hpp Outil.hpp ToDraw.hpp Pioche.hpp Hache.hpp ElemEnv.hpp
	g++ $(FLAG) -c Personnage.cpp

clean:
	rm -f *.o

