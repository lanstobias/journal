#include <string>
#include <fstream>
#include <sstream>

#include "../include/FileHandler.hpp"

using namespace std;

// Contructors
FileHandler::FileHandler()
{
    destinationPath = "";
}

FileHandler::FileHandler(string destinationPath)
{
    this->destinationPath = destinationPath;
}

// Accessors
string FileHandler::getDestinationPath()
{
    return destinationPath;
}

// Mutators
void FileHandler::setDestinationPath(string newDestinationPath)
{
    // TODO: Validate path before changing
    destinationPath = newDestinationPath;
}

// Public methods
void FileHandler::openNano()
{
    // TODO: Modularize function

    // Open temporary file
    string tempFilename = temporaryFilename();
    ofstream outfile(tempFilename);

    // Build command
    ostringstream oss;
    oss << "/usr/bin/nano " << tempFilename;
    string fileToOpen = oss.str();

    // Open file with nano
    system(fileToOpen.c_str());

    outfile.close();
}

// Private methods
string FileHandler::temporaryFilename()
{
    char tempFilename[L_tmpnam];
    tmpnam(tempFilename);

    return tempFilename;
}

string FileHandler::readTempFile()
{
    return "";
}

void FileHandler::deleteTempFile()
{
}
