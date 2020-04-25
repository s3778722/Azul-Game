#include <iostream>

void printCredits();

int main(int argc, char const *argv[]){//use this to get the random seed

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
            //create a new game
        }
        else if(userInput == 2){
            // load game
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
}