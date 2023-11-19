#include "Calculator.h"
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Note - "Any name consisting of alphanumeric characters should be allowed as
// register names" in instructions given by Sectra causes undefined behaviour.
// What happens below?
//
//      123 add 5
//      123 add 123
//      print 123
//
// Does it print 10? 128? Should it just crash because of circular dependency 
// for register 123? 

void Calculator::run(istream& is)
{
    string strInput;
    double numInput;

    while (not is.EOF())
    {
        if (is >> numInput)
        {
            throw runtime_error("No numbers allowed in 
        };
    };


    while (is >> input and capitalize(input) != "QUIT")
    {
        if (input == "QUIT")
            return;
        else if (input == "PRINT")
            print(is);
        else
            parseTree(input, is);

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
    //TODO - What happens if s contains numbers?
    transform(s.begin(), s.end(), s.begin(), 
              [](unsigned char c) // We use unsigned char here because
                                  // std::toupper has undefined behaviour for
                                  // signed chars.
              {
              return toupper(c);
              });
    return s;
};

void Calculator::parseTree(string const& affected_reg, istream& is)
{
    string operatorStr, operandStr;
    is >> operatorStr >> operandStr;
    // Figure out if operandStr is a number or register.
    // If it is a number, simply create a nptr to a value node of that number.
    // If it is a register:
    //     Check if it already exists in regs, in that case, 

};
