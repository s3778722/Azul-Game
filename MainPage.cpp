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
GameModel* loadGame(std::string fileName, GameModel* Game);
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

            GameModel* Game = nullptr;
            Game = loadGame(fileName, Game);

            //Play game
            Game->play();
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

GameModel* loadGame(std::string fileName, GameModel* Game) {
    /*
    • The player’s name and scores ( 2 player game only)
    • The state of the factories and player mosaic’s
    • The order of the tiles in both bags
    • The current player - the next player to take a turn
    */

    std::string playerName1 = "";
    std::string playerName2 = "";
    int playerScore1 = 0;
    int playerScore2 = 0;
    bool p1 = false;
    bool p2 = false;

    //Will need to filter through the gameformat text to find these variables
    std::ifstream input( "SaveGameFormat.txt" );
    int lineNum = 0;
    for( std::string line; getline( input, line ); )
    {
        if (lineNum == 10){
            playerName1 = line;
            std::cout << "playername:" << playerName1 << ". is set" << std::endl;
        }

        if (lineNum == 11){
            bool p1 = std::stoi(line.c_str());
            std::cout << "turn for above: " << p1 << ". is set" << std::endl;
        }

        if (lineNum == 12){
            int playerScore1 = std::stoi(line.c_str());
            std::cout << "score for above: " << playerScore1 << ". is set" << std::endl;
        }

        if (lineNum == 28){
            playerName2 = line;
            std::cout << "playername:" << playerName2 << ". is set" << std::endl;
        }

        if (lineNum == 29){
            bool p2 = std::stoi(line.c_str());
            std::cout << "turn for above: " << p2 << ". is set" << std::endl;
        }

        if (lineNum == 30){
            int playerScore2 = std::stoi(line.c_str());
            std::cout << "score for above: " << playerScore2 << ". is set" << std::endl;
        }

        lineNum++;
        
    }
   
    Player* player1 = new Player(playerName1,playerScore1,p1 );
    Player* player2 = new Player(playerName2,playerScore2,p2 );


    Game = new GameModel(player1, player2);
    return Game; 
}


