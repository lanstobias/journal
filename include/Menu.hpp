#pragma once
#include <string>
#include <set>

#include "UserInput.hpp"

class Menu
{
private:
    std::set<char> validInputs_ {'n', 'q'};
    UserInput input;

public:
    Menu();
    
    std::set<char> getValidInputs();
    
    void print();
    char getUserInput();
    char isValidInput(char input, std::set<char> validInput);
    
private: 
    void printItems();
    void printHeader();
};
