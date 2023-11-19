#include <unordered_map>
#include "Node.h"
#include <string>
#include <iostream>


struct Calculator
{

    void run(std::istream&);

private:
    // HINT - nptr = std::shared_ptr<Node>
    std::unordered_map<std::string, nptr> regs;
    void print(std::istream&) const; 
    std::string& capitalize(std::string&) const;
    void parseTree(std::string const&, std::istream&);
};

