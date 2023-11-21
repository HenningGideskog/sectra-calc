#pragma once
#include <memory>
#include <iostream>



struct Node;
using Nptr = std::shared_ptr<Node>;

struct Node
{
    virtual ~Node() = default;
    virtual double evaluate() const = 0;
};

struct Register : public Node
{
    Register(Nptr const&);
    virtual double evaluate() const override;
private:
    Nptr next;
};

struct Number : Node
{
    Number(double const d);
    virtual double evaluate() const override;
private:
    double val;
};

struct Operator : public Node
{
    virtual ~Operator() = default;
    Operator(Nptr const&, Nptr const&);

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

std::ostream& operator<<(std::ostream&, Nptr);
