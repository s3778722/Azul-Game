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
    //constructor
    Player(std::string name);
    // overloaded constructor to be used in the loading of player data
    Player(std::string name, int score, bool isTurn, Mosaic* mosaicLoad, FloorLine* FloorLineLoad, PatternLine* patternLineLoad);
    // destructor
    ~Player();
    // get player score
    int getScore();
    // get player name
    std::string getName();
    // check if it is player turn
    bool getTurn();
    // set the player turn
    void setIsTurn(bool isTurn);
    // add player points
    void addPoints(int points);
    // displayer player game board
    void displayGameboard();
    // get player floor line
    FloorLine* getFloorLine();
    //get player patternline
    PatternLine* getPatternLine();
    //get player mosaic/wall
    Mosaic* getMosaic();
    //move tiles from the pattern line to mosaic
    std::vector<Tile*> makeTileMosaicUppercase();
    // update player score
    LinkedList* scoring();
    // update the score according to the player floorline
    LinkedList* checkBrokenTiles();
    // support function for the score
    void countColours();
    // support function for the score
    void scoreColours();
    // get the score board, support function for the score
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
    int blackCounter = 0;
    int lightblueCounter = 0;
    int blueCounter = 0;
    int yellowCounter = 0;
    int redCounter = 0;
    bool* colourTiles;

};
#endif //PLAYER_H