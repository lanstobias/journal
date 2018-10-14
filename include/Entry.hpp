#pragma once
#include <string>

#include "Date.hpp"

class Entry
{
private:
    Date dateCreated, lastUpdated;
    std::string title;
    std::string content;

public:
    Entry();
    Entry(std::string title);

    std::string getTitle();

    void setTitle(std::string newTitle);

    std::string dateTime();

private:

};
