#include "Node.h"

using namespace std;

Value::Value(double const d)
    : Node{}, val{d}
{};

void Value::print(ostream& os) const
{
    os << val << endl;
};

double Value::evaluate() const
{
    return val;
};

Operator::Operator(Nptr const& l, Nptr const& r)
    : lhs{l}, rhs{r}
{};

void Operator::print(ostream& os) const
{
    os << evaluate() << endl;
};

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

