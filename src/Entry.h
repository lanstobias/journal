#ifndef ENTRY_H
#define ENTRY_H

#include "Date.h"
#include <string>

namespace journal
{
    class Entry
    {
    private:
        // Member variables
        Date dateCreated, lastUpdated;
        std::string title;

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
}

#endif
