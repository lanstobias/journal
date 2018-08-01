#include "Entry.h"

using namespace journal;
using namespace std;

// Contructors
Entry::Entry()
{
}

Entry::Entry(string title)
{
    this->title = title;
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

// Private methods
