#include <catch2/catch.hpp>
#include <vector>
#include "../include/Menu.hpp"
#include "../include/UserInput.hpp"

using namespace std;

unsigned int factorial2( unsigned int number ) {
    return number <= 1 ? number : factorial2(number-1)*number;
}

TEST_CASE( "Factorials are computed2", "[factorial]" ) {
    REQUIRE( factorial2(1) == 1 );
    REQUIRE( factorial2(2) == 2 );
    REQUIRE( factorial2(3) == 6 );
    REQUIRE( factorial2(10) == 3628800 );
}

//TEST_CASE("Only valid menu choices will be interpreted", "[set]")
//{
    //UserInput userInput;
    //Menu menu;
    //set<char> validInputSet = menu.getValidInputs();
    
    //SECTION("enter invalid chars")
    //{
        //vector<char> inputtedChars;
        
        //inputtedChars.push_back('a');
        //inputtedChars.push_back('r');
        //inputtedChars.push_back('1');
        //inputtedChars.push_back(' ');
        //inputtedChars.push_back('-');
        //inputtedChars.push_back('\\');
    
        //for (auto const input : inputtedChars)
        //{
            //REQUIRE(userInput.isValid(input, validInputSet) == false);
        //} 
    //}

    //SECTION("enter all valid chars")
    //{
        //vector<char> inputtedChars;
        
        //for (auto const validInput : validInputSet)
        //{
            //inputtedChars.push_back(validInput);
        //}
    
        //for (auto const input : inputtedChars)
        //{
            //REQUIRE(userInput.isValid(input, validInputSet) == true);
        //} 
    //}
//}
