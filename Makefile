main: main.cpp Console.h Console.cpp Player/player.h Player/player.cpp Race/race.h Race/race.cpp Enemy/enemy.h Enemy/enemy.cpp Player/inventory.h Player/inventory.cpp Item/armour.h Item/armour.cpp Item/item.h Item/item.cpp Item/ring.h Item/ring.cpp Item/shield.h Item/shield.cpp Item/weapon.h Item/weapon.cpp
	g++ -Wall -Wconversion -ggdb -std=c++14 -o main main.cpp Player/player.cpp Race/race.cpp Enemy/enemy.cpp Player/inventory.cpp Item/armour.cpp Item/item.cpp Item/ring.cpp Item/shield.cpp Item/weapon.cpp Console.cpp




#game := fantasy
#
#all: fantasy run
#
#run: fantasy
#	./fantasy
#
#fantasy: player.o race.o console.o main.cpp
#	g++ -Wall -ggdb -o $(game) main.cpp player.o race.o console.o
#
#player.o: Player/player.h Player/player.cpp Player/inventory.h Player/inventory.cpp
#	g++ -Wall -ggdb -c Player/player.cpp Player/inventory.cpp
#
#race.o: Race/race.h Race/race.cpp
#	g++ -Wall -ggdb -c Race/race.cpp
#
##board.o: board.h board.cpp
##	g++ -Wall -ggdb -c board.cpp
#
#console.o: Console.h Console.cpp
#	g++ -Wall -ggdb -c Console.cpp
#
#clean:
#	rm $(game) *.o #*~ *#