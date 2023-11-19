#include "Calculator.h"
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

void Calculator::run(istream& is)
{
    string input{};
    while (is >> input and capitalize(input) != "QUIT")
    {
        if (input == "QUIT")
            return;
        else if (input == "PRINT")
            print(is);
        else
            // Handle anything else.
        {
            buildTree(input, is);
            cout << "Not yet implemented: " << input << endl;
        };

    }
};

void Calculator::print(istream& is) const
{
    // TODO - What happens here if is is EOF?
    // TODO - Think about tests for errors here.
    string toPrint{};

    // TODO - Message does not always match error reason.
    if (not (is >> toPrint) or not regs.contains(toPrint))
        throw runtime_error("Tried to print register which does not exist.");
    else
        // TODO - Will just print the nptr for now.
        cout << regs.at(toPrint) << endl;
};

string& Calculator::capitalize(string& s) const
{
    transform(s.begin(), s.end(), s.begin(), 
              [](unsigned char c) // We use unsigned char here because
                                  // std::toupper has undefined behaviour for
                                  // signed chars.
              {
              return toupper(c);
              });
    return s;
};

void Calculator::buildTree(string const& affected_reg, istream& is)
{
    string operatorStr, operandStr;
    is >> operatorStr >> operandStr;
    // TODO - Start here next time.
    // Figure out if operandStr is a number or register.
    // If it is a number, simply create a nptr to a value node of that number.
    // If it is a register:
    //     Check if it already exists in regs, in that case, 

    if (capitalize(operatorStr) == "ADD")
    {
        return;
    }
};
