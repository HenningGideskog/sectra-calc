#include <unordered_map>
#include "Node.h"
#include <string>
#include <iostream>


struct Calculator
{

    void run(std::istream&);

private:
    // HINT - Nptr = std::shared_ptr<Node>
    std::unordered_map<std::string, std::shared_ptr<Register>> regs;
    void print(std::istream&);
    std::string& capitalize(std::string&) const;
    void parseTree(std::string const&, std::istream&);
    Nptr getNptr(std::string const&);
    bool isNumber(std::string const&) const;
};
