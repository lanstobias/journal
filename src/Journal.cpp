#include <string> // string
#include <iostream> // cout
#include <stdexcept> // invalid_argument()
#include <fstream>

#include "../include/Helpers.hpp"
#include "../include/Journal.hpp"
#include "../include/FileHandler.hpp"

using namespace std;

// Contructors
Journal::Journal() {
    setSavePath();
    initializeFileHandler();
}

Journal::Journal(const string& journalPath) {
    this->path = journalPath;
    initializeFileHandler();
}

// Accessors
string Journal::getPath() {
    return path;
}

// Mutators

// Public methods
void Journal::newEntry() {
    Entry entry;
    string pathToTempFile = fileHandler.createTempFile();

    cout << "pathToTempFile: " << pathToTempFile << endl;
    
    writeTemplateToTempFile(pathToTempFile);
    fileHandler.openFileWithEditor(pathToTempFile);

    system("read");
}

void Journal::showMenu() {
    char userInput;
    bool userInputIsValid = false;
    
    while (!userInputIsValid) {
        Helpers::clearScreen();
        menu.print();
        
        userInput = menu.getUserInput();
        userInputIsValid = menu.isValidInput(userInput, menu.getValidInputs());
    }
    
    try {
        executeMenuChoice(userInput);
    } catch(const std::exception& e) {
        std::cerr << e.what() << endl;
    }
}

// Private methods
void Journal::setSavePath() {
    string finalDestination = "journal";
    this->path = Helpers::getUserHomePath() + "/" + finalDestination;
}

void Journal::initializeFileHandler() {
    fileHandler.setDestinationPath(path);
}

void Journal::executeMenuChoice(char userChoice) {
    switch (userChoice) {
        case 'n':
            Helpers::clearScreen();
            newEntry();
            break;
            
        case 'q':
            exit();
            break;
    
        default:
            throw invalid_argument("Received invalid menu choice input");
    }
}

void Journal::exit() {
    cout << "Bye bye" << endl;
}

void Journal::writeTemplateToTempFile(const string& filename) {
    try {
        cout << "Opening file " << filename << endl;
        fileHandler.temporaryFile().open(filename);
    } catch(ofstream::failure e) {
        cerr << "Could not open file: " << filename << endl;
    }

    fileHandler.temporaryFile() << "Dagens datum..\n";
    fileHandler.temporaryFile().close();
}
