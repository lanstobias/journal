#pragma once
#include <list>
#include <string>

#include "Entry.hpp"
#include "FileHandler.hpp"

class Journal
{
private:
    // Member variables
    std::string path;
    std::list<Entry> entries;
    FileHandler fileHandler;

public:
    // Constructors
    Journal();
    Journal(std::string journalPath);

    // Accessors
    std::string getPath();

    // Mutators

    // Public methods
    void newEntry();

private:
    // Private methods
    void setSavePath();
    void initializeFileHandler();

};
