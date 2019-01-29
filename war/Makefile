HEADERS = card.hpp

default: war

war.o : war.cpp $(HEADERS)
	g++ war.cpp card.hpp --std=c++11 -o war.o

war: war.o
	g++ war.o -o war

clean:
	-rm -f war.o
	-rm -f war


