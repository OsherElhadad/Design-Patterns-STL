//
// Created by osher on 14/02/2022.
//

#include <iostream>
#include <functional>

using namespace std;

class Shape {
protected:
    const char* _shapeName;
public:
    Shape(const char* name):_shapeName(name){}
    virtual Shape* clone() const=0;
    virtual void print()=0;
};

class Circle : public Shape{
    int _x, _y;
    double _radius;
public:
    Circle(int x, int y, double r): Shape("circle") {
        _x = x; _y = y; _radius = r;
    }
    Circle(): Shape("circle") {
        _x = 0; _y = 0; _radius = 0;
    }
    Shape* clone() const override {
        return (Shape*)new Circle(_x, _y, _radius);
    };
    void print() {
        cout << "x=" << _x << ", y=" << _y << ", r=" << _radius << endl;
        cout << "^" << _shapeName << endl;
    }
};
class Rectangle : public Shape{
    int _x1, _y1;
    int _x2, _y2;
public:
    Rectangle(int x1, int y1, int x2, int y2): Shape("rectangle") {
        _x1 = x1; _y1 = y1;
        _x2 = x2; _y2 = y2;
    }
    Rectangle(): Shape("rectangle") {
        _x1 = 0; _y1 = 0;
        _x2 = 1; _y2 = 1;
    }
    Shape* clone() const override {
        return (Shape*)new Rectangle(_x1, _y1, _x2, _y2);
    };
    void print() {
        cout << "x1=" << _x1 << ", y1=" << _y1 << ", x2=" << _x2 << ", y2=" << _y2 << endl;
        cout << "^" << _shapeName << endl;
    }
};


int main() {
    char choose;
    Shape* shape;
    bool x;
    do {
        cout << "Enter shape ('c' or 'r'): ";
        cin >> choose;
        switch (choose) {
            case 'c':
                shape = new Circle();
                x = false;
                break;
            case 'r':
                shape = new Rectangle();
                x = false;
                break;
            default:
                x = true;
        }
    } while (x);
    Shape* shapeCopy = shape->clone();
    cout << "original shape: address=" << &shape << ", ";
    shape->print();
    cout << "shape copy: address=" << &shapeCopy << ", ";
    shapeCopy->print();
    return 0;
}