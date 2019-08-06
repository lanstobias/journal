#include <iostream>
#include <set>

#include "../include/UserInput.hpp"

using namespace std;

// Constructors
UserInput::UserInput() {}

// Public methods
char UserInput::readSingleCharacter() {
    char characterInput;
    cin >> characterInput;
    return characterInput;
}

bool UserInput::isValid(char input, set<char> validInputs) {
    const bool isMenuChoice = validInputs.find(input) != validInputs.end();
    return isMenuChoice;
}
