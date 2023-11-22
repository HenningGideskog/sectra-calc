#include "Calculator.h"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using namespace std;

void Calculator::run(istream& is)
{
    string strInput{};

    while (is >> strInput)
    {
        capitalize(strInput);

        if (is.eof())
            // TODO - Does this actually ever happen or does the while condition
            // fail above?
            return;

        if (strInput == "PRINT")
            print(is);
        else if (strInput == "QUIT")
            return;
        else
            parseTree(strInput, is);
    }
};

void Calculator::print(istream& is)
{
    // TODO - Think about tests for errors here.
    string toPrint{};
    if (is >> toPrint)
    {
        capitalize(toPrint);
        cout << getNptr(toPrint) << endl;
    }
    else if (is.eof())
    {
        cerr << "Unexpected EOF. Exiting..." << endl;
        return;
    }
    else
        throw runtime_error("Print failed due to bad input.");
};


void Calculator::parseTree(string const& affectedReg, istream& is)
{
    Nptr affectedNode{getNptr(affectedReg)};

    string operatorStr{};
    string operandStr{};

    if (is >> operatorStr >> operandStr)
    {
        capitalize(operatorStr);
        capitalize(operandStr);
    }
    else if (is.eof())
    {
        cerr << "Unexpected EOF. Exiting..." << endl;
        return;
    }
    else
        throw runtime_error("Parsing failed due to bad input.");

    Nptr operandNode{getNptr(operandStr)};
    
    if (operatorStr == "ADD")
        regs[affectedReg]->add(operandNode);
    else if (operatorStr == "SUBTRACT")
        regs[affectedReg]->subtract(operandNode);
    else if (operatorStr == "MULTIPLY")
        regs[affectedReg]->multiply(operandNode);
    else
        throw runtime_error("Unknown operator: " + operatorStr);
};

Nptr Calculator::getNptr(string const& nodeStr)
{
    if (isNumber(nodeStr))
    {
        // TODO - How will this handle 100. or .100?
        return make_shared<Number>(stod(nodeStr));
    }
    else if (not regs.contains(nodeStr))
        regs[nodeStr] = make_shared<Register>();

    return regs[nodeStr];
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

bool Calculator::isNumber(string const& str) const
{
    // Check if the ENTIRE str can be enterpreted as a double. 
    unsigned counter{};

    for (char const& c : str)
    {
        if ((c == ',' or c == '.') and ++counter < 2) 
            continue;
        else if (c < '0' or c > '9') 
            return false;
    }

    return true;
};
