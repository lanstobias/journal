#pragma once
#include <string>

#include "Date.hpp"

class Entry
{
private:
    // Member variables
    Date dateCreated, lastUpdated;
    std::string title;
    std::string content;

public:
    // Constructors
    Entry();
    Entry(std::string title);

    // Accessors
    std::string getTitle();

    // Mutators
    void setTitle(std::string newTitle);

    // Public methods
    std::string dateTime();

private:
    // Private methods

};
