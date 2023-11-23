#include "Node.h"
#include "Calculator.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    Calculator c{};

    try
    {
        if (argc == 1)
            c.run(cin);
        else if (argc == 2)
        {
            fstream fs{argv[1]};

            if (fs.fail())
            {
                cerr << "ERROR: Reading from file \"" << argv[1] 
                     << "\" failed." << endl;
            }
            else
                c.run(fs);
        }
        else
            cerr << "ERROR: Unexpected number of arguments." << endl;
    }
    catch (runtime_error& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
};
