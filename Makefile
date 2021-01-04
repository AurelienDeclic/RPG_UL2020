game := fantasy

all: fantasy run

run: fantasy
	./fantasy

fantasy: player.o inventory.o race.o enemy.o armour.o weapon.o shield.o ring.o item.o Console.o main.cpp
	g++ -Wall -ggdb -o $(game) main.cpp player.o inventory.o race.o enemy.o armour.o weapon.o shield.o ring.o item.o Console.o

race.o: Race/race.h Race/race.cpp
	g++ -Wall -ggdb -c Race/race.cpp

item.o: Item/item.h Item/item.cpp
	g++ -Wall -ggdb -c Item/item.cpp

enemy.o: Enemy/enemy.h Enemy/enemy.cpp
	g++ -Wall -ggdb -c Enemy/enemy.cpp

armour.o: Item/armour.h Item/armour.cpp
	g++ -Wall -ggdb -c Item/armour.cpp

weapon.o: Item/weapon.h Item/weapon.cpp
	g++ -Wall -ggdb -c Item/weapon.cpp

shield.o: Item/shield.h Item/shield.cpp
	g++ -Wall -ggdb -c Item/shield.cpp

ring.o: Item/ring.h Item/ring.cpp
	g++ -Wall -ggdb -c Item/ring.cpp

inventory.o: Player/inventory.h Player/inventory.cpp
	g++ -Wall -ggdb -c Player/inventory.cpp

player.o: Player/player.h Player/player.cpp
	g++ -Wall -ggdb -c Player/player.cpp

Console.o: Console.h Console.cpp
	g++ -Wall -ggdb -c Console.cpp

clean:
	rm $(game) *.o #*~ *#
