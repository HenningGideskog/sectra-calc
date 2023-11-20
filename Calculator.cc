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
    string strInput{};
    double numInput{};

    // TODO - Is this really a good way to check eof?
    while (not is.eof())
    {
        // TODO - Is this really the best way to check if the register name is
        // allowed or not?
        if (is >> numInput)
        {
            throw runtime_error("Registers are not allowed to start with \
                                 numeric characters.");
        }
        else
        {
            is.clear();
        }

        if (is >> strInput and capitalize(strInput) == "PRINT")
        {
            print(is);
        }
        else if (strInput == "QUIT")
        {
            return;
        }
        else
        {
            parseRegisterOperation(is, strInput);
        }
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
    string operatorStr{};
    string operandStr{};
    is >> operatorStr >> operandStr;

    if (not is.good())
        throw runtime_error("Parsing input failed due to bad input.");
    
    if (not regs.contains(affected_reg))
    {
        // TODO - Start here next time.
        // Do I abandon smart pointers for regular ones here?
        regs[affected_reg] = new Value(0);
    }

    else if (capitalize(operatorStr) == "ADD")
    {
        
    }
    else if (operatorStr == "SUBTRACT")
    {

    }
    else if (operatorStr == "MULTIPLY")
    {

    }
    else
    {
        // TODO - Check that this works.
        throw runtime_error("Unknown operator: " + operatorStr)
    }
    // Figure out if operandStr is a number or register.
    // If it is a number, simply create a nptr to a value node of that number.
    // If it is a register:
    //     Check if it already exists in regs, in that case, 

};
