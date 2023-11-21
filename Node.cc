#include "Node.h"

using namespace std;

Register::Register(Nptr const& nptr)
    : next{nptr}
{};

double Register::evaluate() const
{
    return next->evaluate();
};

Number::Number(double const d)
    : Node{}, val{d}
{};

double Number::evaluate() const
{
    return val;
};

Operator::Operator(Nptr const& l, Nptr const& r)
    : lhs{l}, rhs{r}
{};

Addition::Addition(Nptr const& l, Nptr const& r)
    : Operator{l, r}
{};

double Addition::evaluate() const
{
    return lhs->evaluate() + rhs->evaluate();
};

Subtraction::Subtraction(Nptr const& l, Nptr const& r)
    : Operator{l, r}
{};

double Subtraction::evaluate() const
{
    return lhs->evaluate() - rhs->evaluate();
};

Multiplication::Multiplication(Nptr const& l, Nptr const& r)
    : Operator{l, r}
{};

double Multiplication::evaluate() const
{
    return lhs->evaluate() * rhs->evaluate();
};

ostream& operator<<(ostream& os, Nptr nptr)
{
    return (os << nptr->evaluate());
};
