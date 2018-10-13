#include <string>

#include "../include/Helpers.hpp"
#include "../include/Journal.hpp"
#include "../include/FileHandler.hpp"

using namespace std;

// Contructors
Journal::Journal()
{
    setSavePath();
    initializeFileHandler();
}

Journal::Journal(string journalPath)
{
    this->path = journalPath;
    initializeFileHandler();
}

// Accessors
string Journal::getPath()
{
    return path;
}

// Mutators

// Public methods
void Journal::newEntry()
{

}

// Private methods
void Journal::setSavePath()
{
    string finalDestination = "journal";
    this->path = Helpers::getUserHomePath() + "/" + finalDestination;
}

void Journal::initializeFileHandler()
{
    fileHandler.setDestinationPath(path);
}
