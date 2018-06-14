FLAG = -Wall -g

LINKER_FLAGS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: TestOutils

TestOutils : TestOutils.o Outil.hpp Pioche.hpp Hache.hpp
	g++ $(FLAG) -o TestOutils TestOutils.o $(LINKER_FLAGS)

TestOutils.o : TestOutils.cpp Outil.hpp Pioche.hpp Hache.hpp
	g++ $(FLAG) -c TestOutils.cpp

clean:
	rm -f *.o

