#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

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
}
