#pragma once
#include <list>
#include <string>

#include "Entry.hpp"
#include "FileHandler.hpp"
#include "Menu.hpp"

class Journal
{
private:
    std::string path;
    std::list<Entry> entries;
    FileHandler fileHandler;
    Menu menu;

public:
    Journal();
    Journal(std::string journalPath);

    std::string getPath();

    void newEntry();
    void showMenu();

private:
    void setSavePath();
    void initializeFileHandler();
    void executeMenuChoice(char userChoice);
    void exit();
};
