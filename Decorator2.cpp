//
// Created by osher on 13/02/2022.
//

#include <iostream>

using namespace std;

class Shake {
public:
    virtual int getPrice()=0;
    virtual string getDescription()=0;
    virtual ~Shake() {}
};

class BigShake : public Shake {
    int getPrice() {
        return 13;
    }
    string getDescription() {
        return "Big Shake";
    }
    virtual ~BigShake() {
        cout << "delete BigShake" << endl;
    }
};

class SmallShake : public Shake {
    int getPrice() {
        return 6;
    }
    string getDescription() {
        return "Small Shake";
    }
    virtual ~SmallShake() {
        cout << "delete SmallShake" << endl;
    }
};

class ShakeDecorator : public Shake {
protected:
    Shake* _shake;
public:
    virtual int getPrice()=0;
    virtual string getDescription()=0;
    virtual ~ShakeDecorator() {
        cout << "delete ShakeDecorator" << endl;
        delete _shake;
    }
};

class Oreo : public ShakeDecorator {
public:
    Oreo(Shake* shake) {
        _shake = shake;
    }
    int getPrice() {
        return _shake->getPrice() + 3;
    }
    string getDescription() {
        return _shake->getDescription() + ", Oreo";
    }
    virtual ~Oreo() {
        cout << "delete Oreo" << endl;
    }
};

class Caramel : public ShakeDecorator {
public:
    Caramel(Shake* shake) {
        _shake = shake;
    }
    int getPrice() {
        return _shake->getPrice() + 5;
    }
    string getDescription() {
        return _shake->getDescription() + ", Caramel";
    }
    virtual ~Caramel() {
        cout << "delete Caramel" << endl;
    }
};

class Strawberry : public ShakeDecorator {
public:
    Strawberry(Shake* shake) {
        _shake = shake;
    }
    int getPrice() {
        return _shake->getPrice() + 1;
    }
    string getDescription() {
        return _shake->getDescription() + ", Strawberry";
    }
    virtual ~Strawberry() {
        cout << "delete Strawberry" << endl;
    }
};

int main() {
    Shake* shake1 = new Strawberry(new Oreo(new BigShake()));
    cout << "shake1=" << shake1->getDescription() << endl;
    cout << "cost: " << shake1->getPrice() << endl;
    delete shake1;
    Shake* shake2 = new Caramel(new SmallShake());
    cout << "shake2=" << shake2->getDescription() << endl;
    cout << "cost: " << shake2->getPrice() << endl;
    delete shake2;
}