#include "Node.h"
#include "Calculator.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    Calculator c{};

    if (argc == 1)
        c.run(cin);
    else if (argc == 2)
    {
        fstream fs{argv[1]};
        c.run(fs);
    }

    return 0;
};
