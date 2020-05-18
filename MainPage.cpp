#include <iostream>
#include <string>
#include <fstream>
#include "GameModel.h"

Player* player1;
Player* player2;


class CMDArgs {
public:

   bool haveSeed = false;
   int randomSeed = 0; // set up the random seed it needs to be when the game isn't given a seed

private:
    
};

void printCredits();
void processArgs(int argc, char** argv, CMDArgs* cmdArgs);
GameModel* loadGame(std::string fileName);
void createGame();
void newGame(int seed);

int main(int argc, char** argv){

    CMDArgs cmdArgs;
    processArgs(argc, argv, &cmdArgs);

    // cmdArgs.randomSeed //this is the random seed given to through the command line interface

    std::cout << "Welcome to Azul! -------------------" << std::endl;

    while (std::cin.good())
    {   
        int userInput = 0;
        std::cout << "Menu" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits (Show student information)" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << std::endl;
        std::cout << "> ";
        std::cin >> userInput;
        std::cout << std::endl;

        if(userInput == 1){
            if(cmdArgs.haveSeed){
                newGame(cmdArgs.randomSeed);
            }
            else{
                newGame(0);
            }
        }
        else if(userInput == 2){
            // load game
            std::string fileName = "";
            std::cout << "Enter the filename from which load a game: ";
            std::cin >> fileName;

            GameModel* gameModel = loadGame(fileName);

            //Play game
            gameModel->play();
        }
        else if(userInput == 3){
            printCredits();
        }
        else if(userInput == 4){
            return EXIT_SUCCESS;
        }
    }
}

void newGame(int seed){
    std::cout << "Starting a New Game" << std::endl;
    std::string player1Name;
    std::string player2Name;
    std::cout << "Enter the name for player 1:" << std::endl;
    std::cout << "> ";
    std::cin >> player1Name;
    std::cout << "\nEnter the name for player 2:" << std::endl;
    std::cout << "> ";
    std::cin >> player2Name;
    GameModel* Game;
    if(seed != 0){
        Game = new GameModel(player1Name, player2Name,seed);
    }
    else{
        Game = new GameModel(player1Name, player2Name);
    }
    
    Game->play();
    //create a new game
}

void printCredits(){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Name: Muditha Kanishka Dulshan Kodithuwakku" << std::endl;
    std::cout << "Student ID: s3813354" << std::endl;
    std::cout << "Email: s3813354@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;
    std::cout << "Name: Han Chien Leow " << std::endl;
    std::cout << "Student ID: s3778722" << std::endl;
    std::cout << "Email: s3778722@student.rmit.edu.au" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Name: Evan Mason" << std::endl;
    std::cout << "Student ID: s3688949" << std::endl;
    std::cout << "Email:  s3688949@student.rmit.edu.au" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Name: Angelique Marcelin" << std::endl;
    std::cout << "Student ID: s3602636" << std::endl;
    std::cout << "Email:  s3602636@student.rmit.edu.au" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void printError(){

    std::cout << "Please enter a valid option." << std::endl;

}

void processArgs(int argc, char** argv, CMDArgs* cmdArgs){

    if(argc >=2){
        cmdArgs->randomSeed = std::stoi(argv[1]);
        cmdArgs->haveSeed = true;
    }
}

GameModel* loadGame(std::string fileName) {
    /*
    • The player’s name and scores ( 2 player game only)
    • The state of the factories and player mosaic’s
    • The order of the tiles in both bags
    • The current player - the next player to take a turn
    */

    std::string playerName1 = "";
    int playerScore1 = 0;
    bool p1Turn = false;
    PatternLine* player1PatternLine = new PatternLine();
    FloorLine* player1FloorLine = new FloorLine();
    Mosaic* player1Mosaic = new Mosaic();

    std::string playerName2 = "";
    int playerScore2 = 0;
    bool p2Turn = false;
    PatternLine* player2PatternLine = new PatternLine();
    FloorLine* player2FloorLine = new FloorLine();
    Mosaic* player2Mosaic = new Mosaic();

    LinkedList* tileBagLoad = new LinkedList();
    BoxLid* boxLidLoad = new BoxLid();
    std::vector< std::vector<Tile*> > tableState;

    std::ifstream inputFile(fileName);
    int lineNum = 0;
    std::string line;

    if (inputFile.is_open()){
        while (getline(inputFile,line)){
            if(lineNum ==0){
                std::vector<Tile*> factory;
                int times = 0;
                if(line.length() == 0){
                    times = 4;
                }
                else{
                    times = line.length();
                }
                for(int i=0;i<times;i++){
                    if(line[i] != ' ' && line[i]){
                        factory.push_back(new Tile(line[i]));
                    }
                    else{
                        factory.push_back(new Tile());
                    }
                }
                tableState.push_back(factory);
            }
            else if(lineNum == 1||lineNum == 2||lineNum == 3||lineNum == 4||lineNum == 5){
                std::vector<Tile*> factory;
                for(unsigned int i=0;i<line.length();i++){
                    if(line[i] != ' '){
                        // std::cout << line[i] << std::endl;
                        factory.push_back(new Tile(line[i]));
                    }
                }
                tableState.push_back(factory);
            }
            else if(lineNum == 7){
                for(unsigned int i=0;i<line.length();i++){
                    if(line[i] != ' '){
                        tileBagLoad->addFront(new Tile(line[i]));
                    }
                }
            }
            else if(lineNum == 8){
               for(unsigned int i=0;i<line.length();i++){
                    if(line[i] != ' '){
                        boxLidLoad->addTile(new Tile(line[i]));
                    }
                } 
            }
            else if (lineNum == 10){
                playerName1 = line;
            }
            else if (lineNum == 11){
                p1Turn = (int)line[0];
            }
            else if (lineNum == 12){
                playerScore1 = std::stoi(line.c_str());
            }
            else if(lineNum == 14||lineNum == 15||lineNum == 16||lineNum == 17||lineNum == 18){//patternline player 1
                int j = 0;
                for(unsigned int k=0;k<line.length();k++){
                    if(line[k] != ' '){
                        player1PatternLine->setTile(lineNum-14, j, line[k]);
                        j++;
                    }
                }
            }
            else if(lineNum == 20||lineNum == 21||lineNum == 22||lineNum == 23||lineNum == 24){
                int j = 0;
                for(unsigned int k=0;k<line.length();k++){
                    if(line[k] != ' '){
                        player1Mosaic->setMosaicTile(lineNum-20, j, line[k]);
                        j++;
                    }
                }
            }
            else if(lineNum == 26){
                for(unsigned  int i=0;i<line.length();i++){
                    if(line[i] != ' '){
                        player1FloorLine->addTile(new Tile(line[i]));
                    }
                }
            }
            else if (lineNum == 28){
                playerName2 = line;
            }
            else if (lineNum == 29){
                p2Turn = (int)line[0];
            }
            else if (lineNum == 30){
                playerScore2 = std::stoi(line.c_str());
            }
            else if(lineNum == 32||lineNum == 33||lineNum == 34||lineNum == 35||lineNum == 36){//patternline player 1
                int j = 0;
                for(unsigned int k=0;k<line.length();k++){
                    if(line[k] != ' '){
                        player2PatternLine->setTile(lineNum-32, j, line[k]);
                        j++;
                    }
                }
            }
            else if(lineNum == 38||lineNum == 39||lineNum == 40||lineNum == 41||lineNum == 42){
                int j = 0;
                for(unsigned  int k=0;k<line.length();k++){
                    if(line[k] != ' '){
                        player2Mosaic->setMosaicTile(lineNum-38, j, line[k]);
                        j++;
                    }
                }
            }
            else if(lineNum == 44){
                for(unsigned  int i=0;i<line.length();i++){
                    if(line[i] != ' '){
                        player2FloorLine->addTile(new Tile(line[i]));
                    }
                }
            }
            
            lineNum++;
        }
        inputFile.close();
    }
    else{
        std::cout << "Unable to open file"; 
    }
   
    Player* player1 = new Player(playerName1,playerScore1,p1Turn,player1Mosaic,player1FloorLine,player1PatternLine);
    Player* player2 = new Player(playerName2,playerScore2,p2Turn,player2Mosaic,player2FloorLine,player2PatternLine);
    FactoryTable* factories = new FactoryTable(tableState);
    TileBag* tileBag = new TileBag(tileBagLoad);

    factories->setFactoriesLoaded(true);


    GameModel* gameModel = new GameModel(player1, player2, factories, tileBag, boxLidLoad);
    return gameModel;
}



