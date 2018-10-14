#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sstream>
#include <iostream> // cout, cin

using namespace std;

namespace Helpers
{
    string getUserHomePath()
    {
        const char* homeDir;

        if ((homeDir = getenv("HOME")) == NULL)
        {
            homeDir = getpwuid(getuid())->pw_dir;
        }

        return homeDir;
    }
    
    void clearScreen()
    {
        cout << "\033[2J\033[1;1H";
    }
    
    void newline()
    {
        putchar('\n');
    }
    
    string bold(string text)
    {
        const char ESC_CHAR = 27;
        ostringstream os;
        
        os << ESC_CHAR << "[1m" << text << ESC_CHAR << "[0m";
        
        return os.str();
    }
}
