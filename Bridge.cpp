//
// Created by osher on 13/02/2022.
//

#include <iostream>

using namespace std;

class HouseImplementor {
public:
    virtual void printImplementation()=0;
};
class WoodHouse : public HouseImplementor {
    void printImplementation() override {
        cout << "wood house" << endl;
    }
};
class BrickHouse : public HouseImplementor {
    void printImplementation() override {
        cout << "brick house" << endl;
    }
};
class House {
protected:
    HouseImplementor* _houseImplementor;
public:
    House(HouseImplementor* houseImplementor) {
        _houseImplementor = houseImplementor;
    }
    virtual void print()=0;
    virtual ~House() {
        cout << "delete" << "House" << endl;
        delete _houseImplementor;
    }
};

class BigHouse : public House {
public:
    BigHouse(HouseImplementor* houseImplementor) : House(houseImplementor) {
    }
    void print() override {
        cout << "big ";
        _houseImplementor->printImplementation();
    }
    ~BigHouse() {
        cout << "delete" << "BigHouse" << endl;
    }
};
class SmallHouse : public House {
public:
    SmallHouse(HouseImplementor* houseImplementor) : House(houseImplementor) {
    }
    void print() override {
        cout << "small ";
        _houseImplementor->printImplementation();
    }
    ~SmallHouse() {
        cout << "delete" << "SmallHouse" << endl;
    }
};


int main() {
    House* h1 = new BigHouse(new WoodHouse());
    h1->print();
    House* h2 = new SmallHouse(new BrickHouse());
    h2->print();
    delete h1;
    delete h2;
}