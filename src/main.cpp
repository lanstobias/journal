#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>

#include "../include/Entry.hpp"
#include "../include/Date.hpp"
#include "../include/FileHandler.hpp"
#include "../include/Journal.hpp"
#include "../include/Menu.hpp"

using namespace std;

int main()
{
    Menu menu;
    // Create temporary filename
    // char tempFilename[L_tmpnam];
    // tmpnam(tempFilename);

    // Open file
    // ofstream outfile(tempFilename);

    // ostringstream oss;
    // oss << "/usr/bin/nano " << tempFilename;

    // string fileToOpen = oss.str();
    // system(fileToOpen.c_str());

    // outfile.close();

    // Journal journal;
    // journal.newEntry();
    
    menu.show();
    system("read");

    return 0;
}
