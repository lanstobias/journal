#pragma once
#include <string>
#include <set>

#include "UserInput.hpp"

class Menu
{
private:
    std::set<char> validInputs{'n', 'q'};
    UserInput input;

public:
    Menu();
    
    std::set<char> getValidInputs();
    
    void show();
    
private:
    void printItems();
    void printHeader();
    void print();
    char getUserInput();
};
