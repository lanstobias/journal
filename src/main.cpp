#include <iostream>
#include "Entry.h"
#include "Date.h"

using namespace std;
using namespace journal;

int main()
{
    Entry entry("Hej dagboken");

    cout << entry.dateTime() << ": " << entry.getTitle() << endl;

    return 0;
}
