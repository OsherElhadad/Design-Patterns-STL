//
// Created by osher on 14/02/2022.
//

#include <iostream>

using namespace std;

class Sword {
public:
    string material;
};
class WoodSword:public Sword {
public:
    WoodSword() {
        material = "wood";
    }
};
class MetalSword:public Sword {
public:
    MetalSword() {
        material = "metal";
    }
};
class Shield {
public:
    string material;
};
class WoodShield:public Shield {
public:
    WoodShield() {
        material = "wood";
    }
};
class MetalShield:public Shield {
public:
    MetalShield() {
        material = "metal";
    }
};


class AbstractFactory {
public:
    virtual Sword* createSword() = 0;
    virtual Shield* createShield() = 0;
};

class WoodFactory : public AbstractFactory {
    Sword* createSword() override {
        return new WoodSword;
    };
    Shield* createShield() override {
        return new WoodShield;
    };
};

class MetalFactory : public AbstractFactory {
    Sword* createSword() override {
        return new MetalSword;
    };
    Shield* createShield() override {
        return new MetalShield;
    };
};

int main() {
    char material;
    AbstractFactory* factory;
    bool x;
    do {
        cout << "Enter material ('m' or 'w'): ";
        cin >> material;
        switch (material) {
            case 'm':
                factory = new MetalFactory();
                x = false;
                break;
            case 'w':
                factory = new WoodFactory();
                x = false;
                break;
            default:
                x = true;
        }
    } while (x);
    Sword *sword = factory->createSword();
    Shield *shield = factory->createShield();
    cout << "Sword material: " << sword->material << endl;
    cout << "Shield material: " << shield->material << endl;
    return 0;
}