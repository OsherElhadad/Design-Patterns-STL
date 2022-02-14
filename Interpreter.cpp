//
// Created by osher on 14/02/2022.
//

#include <iostream>

using namespace std;

class AbstractExpression {
public:
    virtual string print()=0;
    virtual int evaluate()=0;
};

class NonTerminalExpression : public AbstractExpression {
protected:
    AbstractExpression* _first;
    AbstractExpression* _sec;
    NonTerminalExpression(AbstractExpression* first, AbstractExpression* sec) {
        _first = first;
        _sec = sec;
    }
};

class Plus : public NonTerminalExpression {
public:
    Plus(AbstractExpression* first, AbstractExpression* sec):NonTerminalExpression(first, sec) {}
    string print() override {
        return "(" + _first->print() + " + " + _sec->print() + ")";
    }
    int evaluate() override {
        return _first->evaluate() + _sec->evaluate();
    }
};

class Minus : public NonTerminalExpression {
public:
    Minus(AbstractExpression* first, AbstractExpression* sec):NonTerminalExpression(first, sec) {}
    string print() override {
        return "(" + _first->print() + " - " + _sec->print() + ")";
    }
    int evaluate() override {
        return _first->evaluate() - _sec->evaluate();
    }
};

class Num : public AbstractExpression {
    int _num;
public:
    Num(int num) {
        _num = num;
    }
    string print() override {
        return to_string(_num);
    }
    int evaluate() override {
        return _num;
    }
};


int main() {
    AbstractExpression* expression = new Plus((new Minus(new Num(2), new Num(5))), new Num(4));
    cout << expression->print() << " = " << expression->evaluate() << endl;
}