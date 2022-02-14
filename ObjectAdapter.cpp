//
// Created by osher on 13/02/2022.
//

#include <iostream>

using namespace std;

class Printer {
public:
    virtual void print()=0;
};

class DogVoicePrinter : public Printer {
public:
    void print() override {
        cout << "bark bark.." << endl;
    }
};

class CatVoicePrinter : public Printer {
public:
    void print() override {
        cout << "meow meow.." << endl;
    }
};

class Target {
public:
    virtual void request()=0;
};

class Adapter :public Target {
    Printer* _printer;
public:
    Adapter(Printer* printer) {
        _printer = printer;
    }
    void request() override {
        _printer->print();
    }
    ~Adapter() {
        delete _printer;
    }
};


int main() {
    char choose;
    bool x;
    Target* target;
    do {
        cout << "cat or dog? 'c' / 'd'";
        cin >> choose;
        switch (choose) {
            case 'c':
                target = new Adapter(new CatVoicePrinter());
                x = false;
                break;
            case 'd':
                target = new Adapter(new DogVoicePrinter());
                x = false;
                break;
            default:
                x = true;
        }
    } while (x);
    target->request();
    delete target;
}