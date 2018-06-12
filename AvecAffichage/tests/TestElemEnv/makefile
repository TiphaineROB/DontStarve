FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: TestElemEnv

TestElemEnv : TestElemEnv.o ElemEnv.hpp
	g++ $(FLAG) -o TestElemEnv TestElemEnv.o $(LINKER_FLAGS)

TestElemEnv.o : TestElemEnv.cpp ElemEnv.hpp Arbre.hpp Roche.hpp Baie.hpp Feu.hpp
	g++ $(FLAG) -c TestElemEnv.cpp

clean:
	rm -f *.o

