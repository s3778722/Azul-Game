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
void loadGame(std::string fileName);
void createGame();
void newGame();

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
            std::cout << "Starting a New Game" << std::endl;
            std::string player1Name;
            std::string player2Name;
            std::cout << "Enter the name for player 1:" << std::endl;
            std::cin >> player1Name;
            std::cout << "\nEnter the name for player 2:" << std::endl;
            std::cin >> player2Name;
            GameModel* Game = new GameModel(player1Name, player2Name);
            Game->play();
            //create a new game
        }
        else if(userInput == 2){
            // load game
            std::string fileName;
            std::cin >> fileName;
            std::ifstream gameFile;
            gameFile.open(fileName);
            loadGame(fileName);
            //GameModel* Game = new GameModel(player,player,factories,boxlid,tilebag,floorline)
            //Game->play();
        }
        else if(userInput == 3){
            printCredits();
        }
        else if(userInput == 4){
            return EXIT_SUCCESS;
        }
    }
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

void loadGame(std::string fileName) {
    /*
    • The player’s name and scores ( 2 player game only)
    • The state of the factories and player mosaic’s
    • The order of the tiles in both bags
    • The current player - the next player to take a turn
    */

    std::string playerName1;
    std::string playerName2;
    int playerScore1;
    int playerScore2;
    bool p1 = true;
    bool p2 = false;

    //Will need to filter through the gameformat text to find these variables
    std::ifstream input( fileName );
    int lineNum = 0;
    for( std::string line; getline( input, line ); )
    {
        //if ( lineNum > )
        lineNum++;
    }
        

    //Create new players from variables in loaded game
    player1 = new Player(playerName1, playerScore1, p1);
    player2 = new Player(playerName2, playerScore2, p2);

   new gameModel(player1, player2);
    
}

void newGame() {
    std::string pName1;
    std::string pName2;

    player1 = new Player(pName1, 0, true);
    player2 = new Player(pName2, 0, false);

   new gameModel(player1, player2);

}

