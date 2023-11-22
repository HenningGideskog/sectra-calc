#include "Node.h"

using namespace std;

Register::Register()
    : next{make_shared<Number>(0)}
{};

Register::Register(Nptr const& nptr)
    : next{nptr}
{};

double Register::evaluate() const
{
    return next->evaluate();
};

void Register::add(Nptr const& nodeToAdd)
{
    next = make_shared<Addition>(next, nodeToAdd);
};

void Register::subtract(Nptr const& nodeToSubtract)
{
    next = make_shared<Subtraction>(next, nodeToSubtract);
};

void Register::multiply(Nptr const& nodeToMultiplyBy)
{
    next = make_shared<Multiplication>(next, nodeToMultiplyBy);
};

Number::Number(double const d)
    : val{d}
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
