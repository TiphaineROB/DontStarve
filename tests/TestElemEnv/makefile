FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: testElemEnv

testElemEnv : testElemEnv.o ElemEnv.hpp
	g++ $(FLAG) -o testElemEnv testElemEnv.o $(LINKER_FLAGS)

testElemEnv.o : TestElemEnv.cpp ElemEnv.hpp Arbre.hpp Roche.hpp Baie.hpp Feu.hpp
	g++ $(FLAG) -c testElemEnv.o TestElemEnv.cpp

clean:
	rm -f *.o

