# output:BoxLid.o FactoryTable.o Node.o PatternLine.o Player.o Tile.o TileBag.o GameModel.o MainPage.o
# 	g++ -Wall -Werror -std=c++14 -O -o -g BoxLid.o FactoryTable.o Node.o PatternLine.o Player.o Tile.o TileBag.o GameModel.o MainPage.o Azul 
# 	# g++ -Wall -Werror -std=c++14 -O -o -g BoxLid.o FactoryTable.o Node.o PatternLine.o Player.o Tile.o TileBag.o GameModel.o MainPage.o Azul

# BoxLid.o: BoxLid.cpp
# 	g++ -g -c BoxLid.cpp

# FactoryTable.o: FactoryTable.cpp
# 	g++ -g -c FactoryTable.cpp

# Mosaics.o: Mosaic.cpp
# 	g++ -g -c Mosaic.cpp

# Node.o: Node.cpp
# 	g++ -g -c Node.cpp

# PatternLine.o: PatternLine.cpp
# 	g++ -g -c PatternLine.cpp

# Player.o: Player.cpp
# 	g++ -g -c Player.cpp

# Tile.o: Tile.cpp
# 	g++ -g -c Tile.cpp

# TileBag.o: TileBag.cpp
# 	g++ -g -c TileBag.cpp

# GameModel.o: GameModel.cpp
# 	g++ -g -c GameModel.cpp

# MainPage.o: MainPage.cpp
# 	g++ -g -c MainPage.cpp

# clean:
# 	rm *.o


.default: all

all: Azul

clean:
	rm -f Azul *.o

Azul: BoxLid.o FactoryTable.o Node.o PatternLine.o Player.o Tile.o TileBag.o GameModel.o MainPage.o FloorLine.o LinkedList.o Mosaic.o TileCode.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^