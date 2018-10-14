#include <iostream> // cout, ios
#include <sstream> // ostringstream
#include <iomanip> // setw, setfill
#include <fstream> // fstream

#include "../include/Menu.hpp"
#include "../include/Helpers.hpp"

using namespace std;
using namespace Helpers;

// Constructors
Menu::Menu() {}

// Accessors
std::set<char> Menu::getValidInputs()
{
    return validInputs;
}

// Public menthods
void Menu::show()
{
    char userInput;
    bool userInputIsValid = false;
    
    while (!userInputIsValid)
    {
        Helpers::clearScreen();
        print();
        
        userInput = getUserInput();
        userInputIsValid = input.isValid(userInput, validInputs);
    }
}

// Private methods
void Menu::printItems()
{
    ostringstream os;
    
    os << "(n) Create " << bold("n") << "ew entry" << endl;
    os << "(q) " << bold("Q") << "uit" << endl;
    
    cout << os.str();
}

void Menu::printHeader()
{
    cout << "----- Journal -----" << endl;
}

void Menu::print()
{
    printHeader();
    newline();
    printItems();
    newline();
}

char Menu::getUserInput()
{
    cout << "Enter choice: ";
    return input.readSingleCharacter();
}
