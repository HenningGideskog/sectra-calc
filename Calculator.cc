#include "Calculator.h"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmath>

// TODO - Start here
//        Re-work parsing to be more robust. Also write function to convert
//        string to an appropriate Nptr.
//
//        Should also re-work capitalize somehow. It is a little hard to see and
//        un-intuitive what it does. Maybe...

using namespace std;

void Calculator::run(istream& is)
{
    string strInput{};

    while (is >> strInput)
    {
        if (is.eof())
            return;
        else
            capitalize(strInput);

        if (strInput == "PRINT")
            print(is);

        else if (strInput == "QUIT")
            return;

        else
            parseTree(strInput, is);
    }
};

void Calculator::print(istream& is) const
{
    // TODO - Think about tests for errors here.
    string toPrint{};
    is >> toPrint;

    if (is.fail())
        throw runtime_error("Print failed due to bad input.");
    else if (is.eof())
    {
        // Graceful exit, will exit entire program due to condition in run.
        cout << "Reached EOF. Exiting..." << endl;
        return;
    }

    capitalize(toPrint);
    cout << getNptr(toPrint) << endl;
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

void Calculator::parseTree(string const& affected_reg, istream& is)
{
    string operatorStr{};
    string operandStr{};

    is >> operatorStr >> operandStr;

    // TODO - Code duplication in print.
    if (is.fail())
        throw runtime_error("Parsing failed due to bad input.");
    else if (is.eof())
    {
        // Graceful exit, will exit entire program due to condition in run.
        cout << "Reached EOF. Exiting..." << endl;
        return;
    }

    capitalize(operatorStr);
    
    Nptr operandNode{getNptr(operandStr)};
    
    if (capitalize(operatorStr) == "ADD")
    {
        regs[affected_reg] = make_shared<Addition>(regs[affected_reg],
                                                   operandNode);
    }
    else if (operatorStr == "SUBTRACT")
    {
        regs[affected_reg] = make_shared<Subtraction>(regs[affected_reg],
                                                   operandNode);
    }
    else if (operatorStr == "MULTIPLY")
    {
        regs[affected_reg] = make_shared<Multiplication>(regs[affected_reg],
                                                   operandNode);
    }
    else
    {
        throw runtime_error("Unknown operator: " + operatorStr);
    }
};

Nptr Calculator::getNptr(string const& nodeStr) const
{
    double value{strToDouble(nodeStr)};

    if (value == NAN)
    {
        cout << "Value is NAN" << endl;
        return nullptr;
    }
    else
    {
        cout << "Value is not NAN" << endl;
        return nullptr;
    }
};

double Calculator::strToDouble(string const& s) const
{
    double d{};
    size_t nConvChar{};

    try
    {
        d = stod(s, &nConvChar);
    }
    catch (invalid_argument)
    {
        d = NAN;
    }
    
    if (nConvChar != s.length())
        return NAN;
    else
        return d;

};
