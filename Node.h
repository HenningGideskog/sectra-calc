#pragma once
#include <memory>
#include <ostream>


struct Node;
using Nptr = std::shared_ptr<Node>;

struct Node
{
    virtual ~Node() = default;
    virtual void print(std::ostream&) const = 0;
    virtual double evaluate() const = 0;
};

struct Value : Node
{
    Value(double const d);
    void print(std::ostream&) const override;
    virtual double evaluate() const override;
private:
    double val;
};

struct Operator : public Node
{
    virtual ~Operator() = default;
    Operator(Nptr const&, Nptr const&);
    void print(std::ostream&) const override;

protected:
    Nptr lhs; // lhs - Left hand side.
    Nptr rhs; // rhs - Right hand side.
};

struct Addition : public Operator
{
    Addition(Nptr const&, Nptr const&);
    double evaluate() const override;
};

struct Subtraction : public Operator
{
    Subtraction(Nptr const&, Nptr const&);
    double evaluate() const override;
};

struct Multiplication : public Operator
{
    Multiplication(Nptr const&, Nptr const&);
    double evaluate() const override;
};

