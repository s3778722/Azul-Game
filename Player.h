#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cctype>
#include "FloorLine.h"
#include <iostream>
#include "Mosaic.h"
#include "PatternLine.h"
#include "vector"

class Player{
public:
    Player();
    ~Player();
    Player(std::string name);
    Player(std::string name, int score, bool isTurn, Mosaic* mosaicLoad, FloorLine* FloorLineLoad, PatternLine* patternLineLoad);
    int getScore();
    std::string getName();
    bool getTurn();
    void setIsTurn(bool isTurn);
    void addPoints(int points);
    void displayGameboard();
    FloorLine* getFloorLine();
    PatternLine* getPatternLine();
    Mosaic* getMosaic();
    std::vector<Tile*> makeTileMosaicUppercase();
    void scoring();
    void checkBrokenTiles();
    void countColours();
    void scoreColours();
    char** getScoreBoard();

private:
    std::string name;
    int score;
    bool isTurn;
    Mosaic* mosaic;
    FloorLine* playerFloorLine;
    PatternLine* playerPatternLine;
    std::vector<int> checkRow;
    std::vector<int> checkColumn;
    bool checkingRow;
    bool checkingColumn;
    char** scoringBoard;
    Tile* brokenTilesSlot[7];
    int blackCounter = 0;
    int lightblueCounter = 0;
    int blueCounter = 0;
    int yellowCounter = 0;
    int redCounter = 0;
    bool* colourTiles;

};
#endif //PLAYER_H