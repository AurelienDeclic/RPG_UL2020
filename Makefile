rpgmain: rpgmain.cpp player.h player.cpp race.h race.cpp enemy.h enemy.cpp inventory.h inventory.cpp armour.h armour.cpp item.h item.cpp ring.h ring.cpp shield.h shield.cpp weapon.h weapon.cpp
	g++ -Wall -Wconversion -ggdb -std=c++14 -o rpgmain rpgmain.cpp player.cpp race.cpp enemy.cpp inventory.cpp armour.cpp item.cpp ring.cpp shield.cpp weapon.cpp