rpgmain: rpgmain.cpp player.h player.cpp race.h race.cpp enemy.h enemy.cpp
	g++ -Wall -Wconversion -ggdb -std=c++14 -o rpgmain rpgmain.cpp player.cpp race.cpp enemy.cpp