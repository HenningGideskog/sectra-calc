#include "Calculator.h"
#include <string>
#include <stdexcept>
#include <algorithm>

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
    double numInput{};

    // TODO - Is this really a good way to check eof?
    //        Probably not, since stuff below ruins it.
    while (not is.eof())
    {
        // TODO - Is this really the best way to check if the register name is
        // allowed or not?
        // No. Should be able to use dynamic casting with conversion function
        // from string (or inputstream) to Nptr.
        if (is >> numInput)
        {
            throw runtime_error("Registers are not allowed to start with"
                                "numeric characters.");
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
            parseTree(strInput, is);
        }
    }
};

void Calculator::print(istream& is) const
{
    // TODO - What happens here if is is EOF?
    // TODO - Think about tests for errors here.
    string toPrint{};
    is >> toPrint;

    // TODO - Message does not always match error reason.
    if (not regs.contains(capitalize(toPrint)))
        throw runtime_error("Tried to print register which does not exist.");
    else
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

void Calculator::parseTree(string const& affected_reg, istream& is)
{
    string operatorStr{};

    // TODO - This should work for strings too!
    double operandStr{};
    is >> operatorStr >> operandStr;

    // TODO - Is this a good check?
    if (not is.good())
        throw runtime_error("Parsing input failed due to bad input.");
    
    if (not regs.contains(affected_reg))
    {
        // Initialize new registers to 0.
        regs[affected_reg] = make_shared<Number>(0);
    }
    
    if (capitalize(operatorStr) == "ADD")
    {
        Nptr tmp{make_shared<Number>(operandStr)};
        regs[affected_reg] = make_shared<Addition>(regs[affected_reg], tmp);
    }
    else if (operatorStr == "SUBTRACT")
    {
        Nptr tmp{make_shared<Number>(operandStr)};
        regs[affected_reg] = make_shared<Subtraction>(regs[affected_reg], tmp);
    }
    else if (operatorStr == "MULTIPLY")
    {
        Nptr tmp{make_shared<Number>(operandStr)};
        regs[affected_reg] = make_shared<Multiplication>(regs[affected_reg], 
                                                         tmp);
    }
    else
    {
        // TODO - Check that this works.
        throw runtime_error("Unknown operator: " + operatorStr);
    }
};
