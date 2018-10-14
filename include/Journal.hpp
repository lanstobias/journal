#pragma once
#include <list>
#include <string>

#include "Entry.hpp"
#include "FileHandler.hpp"

class Journal
{
private:
    std::string path;
    std::list<Entry> entries;
    FileHandler fileHandler;

public:
    Journal();
    Journal(std::string journalPath);

    std::string getPath();

    void newEntry();

private:
    void setSavePath();
    void initializeFileHandler();
};
