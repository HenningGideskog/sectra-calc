#pragma once
#include <memory>
#include <ostream>


struct Node;
using nptr = std::shared_ptr<Node>;

struct Node
{
    virtual ~Node() = default;
    virtual void print(std::ostream&) const = 0;
};

struct Register : public Node
{
    Register(); 
    ~Register() override;
    void print(std::ostream&) const override;

private:
    nptr next;
};

struct Operator : public Node
{
    virtual ~Operator() = default;

protected:
    nptr lhs; // lhs - Left hand side.
    nptr rhs; // rhs - Right hand side.
};

struct Addition : public Operator
{
    Addition();
};

struct Subtraction : public Operator
{
    Subtraction();
};

struct Multiplication : public Operator
{
    Multiplication();
};

