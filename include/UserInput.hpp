#pragma once
#include <set>

class UserInput
{
private:

public:
    UserInput();
    
    char readSingleCharacter();
    bool isValid(char input, std::set<char> validInputs);
};
