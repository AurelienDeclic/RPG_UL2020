RPG: Main.cpp item.o shield.o
	g++ -Wall -ggdb -o RPG Main.cpp item.o shield.o
item.o: item.cpp item.h
	g++ -Wall -ggdb -c item.cpp
shield.o: shield.cpp shield.h
	g++ -Wall -ggdb -c shield.cpp
clean:
	rm *.o *~ RPG
