RPG: Main.cpp item.o weapon.o armour.o shield.o ring.o
	g++ -Wall -ggdb -o RPG Main.cpp item.o weapon.o armour.o shield.o ring.o
item.o: item.cpp item.h
	g++ -Wall -ggdb -c item.cpp
weapon.o: weapon.cpp weapon.h
	g++ -Wall -ggdb -c weapon.cpp
armour.o: armour.cpp armour.h
	g++ -Wall -ggdb -c armour.cpp
shield.o: shield.cpp shield.h
	g++ -Wall -ggdb -c shield.cpp
ring.o: ring.cpp ring.h
	g++ -Wall -ggdb -c ring.cpp
clean:
	rm *.o *~ RPG
