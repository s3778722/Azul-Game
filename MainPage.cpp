#include <iostream>
#include <string>
#include "GameModel.h"

class CMDArgs {
public:

   bool haveSeed = false;
   int randomSeed = 0; // set up the random seed it needs to be when the game isn't given a seed
};

void printCredits();
void processArgs(int argc, char** argv, CMDArgs* cmdArgs);

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
            Game->Play();
            //create a new game
        }
        else if(userInput == 2){
            // load game
        }
        else if(userInput == 3){
            printCredits();
            FactoryTable* Factories = new FactoryTable();//remove later
            Factories->DisplayFactories();//remove later
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
}

void processArgs(int argc, char** argv, CMDArgs* cmdArgs){

    if(argc >=2){
        cmdArgs->randomSeed = std::stoi(argv[1]);
        cmdArgs->haveSeed = true;
    }
}