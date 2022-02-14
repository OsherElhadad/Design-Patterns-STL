//
// Created by osher on 13/02/2022.
//

#include <iostream>
using namespace std;

class DogVoicePrinter {
protected:
    void print() {
        cout << "bark bark.." << endl;
    }
};

class Target {
public:
    virtual void request()=0;
};

class Adapter :public Target, public DogVoicePrinter {
public:
    void request() override {
        print();
    }
};

int main() {
    Target* target = new Adapter();
    target->request();
    delete target;
}

