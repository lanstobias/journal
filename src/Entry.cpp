#include "../include/Entry.hpp"

using namespace std;

// Contructors
Entry::Entry()
{
    Date date;
    dateCreated = date;
}

Entry::Entry(string title)
{
    this->title = title;

    Date date;
    dateCreated = date;
}

// Accessors
string Entry::getTitle()
{
    return title;
}

// Mutators
void Entry::setTitle(string newTitle)
{
    title = newTitle;
}

// Public methods
string Entry::dateTime()
{
    return dateCreated.getDateTime();
}

// Private methods
