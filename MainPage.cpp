#include <iostream>

int main(void){

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
            std::cout << "----------------------------------" << std::endl;
            std::cout << "Name: Muditha Kanishka Dulshan Kodithuwakku" << std::endl;
            std::cout << "Student ID: s3813354" << std::endl;
            std::cout << "Email: s3813354@student.rmit.edu.au" << std::endl;
            std::cout << "Name: " << std::endl;
            std::cout << "Student ID: " << std::endl;
            std::cout << "Email: " << std::endl;
            std::cout << "----------------------------------" << std::endl;
            std::cout << std::endl;
        }
        else if(userInput == 4){
            return EXIT_SUCCESS;
        }
    }
}