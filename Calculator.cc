#include "Calculator.h"
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

void Calculator::run(istream& is)
{
    string strInput{};

    while (is >> strInput)
    {
        capitalize(strInput);

        if (strInput == "PRINT")
            print(is);
        else if (strInput == "QUIT")
            return;
        else
            parseTree(strInput, is);
    }
    
    // I am not sure is.bad() can ever happen since we are only reading strings
    // from is, but just in case:
    if (is.bad())
        throw runtime_error("ERROR: Reading from input failed.");

};

void Calculator::print(istream& is)
{
    string toPrint{};
    if (is >> toPrint)
    {
        capitalize(toPrint);
        cout << getNptr(toPrint) << endl;
    }
    else if (is.eof())
        cerr << "Unexpected EOF. Exiting..." << endl;
};


void Calculator::parseTree(string const& affectedReg, istream& is)
{
    Nptr affectedNode{getRegPtr(affectedReg)};

    string operatorStr{};
    string operandStr{};

    if (is >> operatorStr >> operandStr)
    {
        capitalize(operatorStr);
        capitalize(operandStr);

        Nptr operandNode{getNptr(operandStr)};

        if (operatorStr == "ADD")
            regs[affectedReg]->add(operandNode);
        else if (operatorStr == "SUBTRACT")
            regs[affectedReg]->subtract(operandNode);
        else if (operatorStr == "MULTIPLY")
            regs[affectedReg]->multiply(operandNode);
        else
            throw runtime_error("Unknown operator: " + operatorStr);
    }
    else if (is.eof())
        cerr << "Unexpected EOF. Exiting..." << endl;
};

Nptr Calculator::getNptr(string const& nodeStr)
{
    if (isNumber(nodeStr))
        return make_shared<Number>(stod(nodeStr));

    return getRegPtr(nodeStr);
};

shared_ptr<Register> Calculator::getRegPtr(string const& regStr)
{
    if (isNumber(regStr))
        throw runtime_error("ERROR: Pure numeric register name not allowed.");
    else if (not regs.contains(regStr))
        regs[regStr] = make_shared<Register>();
    return regs[regStr];
};

string& Calculator::capitalize(string& s) const
{
    // We use UNSIGNED char below because toupper has undefined behaviour for
    // signed chars.
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
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
