//
// Created by osher on 13/02/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Character {
protected:
    int _health;
public:
    Character() { _health = 0; }

    void setHealth(int health) {
        _health = health;
    }

    int getHealth() const {
        return _health;
    }

    virtual void print(int i, int j) = 0;
};

class Soldier : public Character {
public:
    Soldier(int health) {
        _health = health;
    }

    void print(int i, int j) override {
        cout << "soldier=" << this << " is at [" << i << ", " << j << "] with health=" << _health << endl;
    }
};

class Tank : public Character {
public:
    Tank(int health) {
        _health = health;
    }

    void print(int i, int j) override {
        cout << "tank=" << this << " is at [" << i << ", " << j << "] with health=" << _health << endl;
    }
};

class Flyweight {
protected:
    vector<Character *> characters;

    virtual Character *newCharacter(int health) = 0;

public:
    Character *getCharacter(int health) {
        int i;
        for (i = 0; i < characters.size(); i++) {
            if (characters.at(i)->getHealth() == health)
                return characters.at(i);
        }
        characters.push_back(newCharacter(health));
        return characters.at(i);
    }
    ~Flyweight() {
        for_each(characters.begin(), characters.end(), [](Character* c) {delete c;});
    }
};

class SoldierFlyweight : public Flyweight {
    Character *newCharacter(int health) override {
        return new Soldier(health);
    }
};

class TankFlyweight : public Flyweight {
    Character *newCharacter(int health) override {
        return new Tank(health);
    }
};

int main() {
    Character *table[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            table[i][j] = nullptr;
        }
    }
    Flyweight *soldierFlyweight = new SoldierFlyweight();
    Flyweight *tankFlyweight = new TankFlyweight();
    table[0][0] = soldierFlyweight->getCharacter(100);
    table[1][0] = soldierFlyweight->getCharacter(100);
    table[0][2] = tankFlyweight->getCharacter(50);
    table[1][2] = tankFlyweight->getCharacter(50);
    table[1][3] = tankFlyweight->getCharacter(50);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table[i][j])
                table[i][j]->print(i, j);
        }
    }
    cout << "A tank was hit: Tank [1,2] health=10" << endl;
    table[1][2] = tankFlyweight->getCharacter(10);
    cout << "After change:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table[i][j])
                table[i][j]->print(i, j);
        }
    }
    delete soldierFlyweight;
    delete tankFlyweight;
}