//
// Created by osher on 14/02/2022.
//

#include <iostream>
#include <cstring>

using namespace std;

class Robot {
    friend class Singleton;

    char *_name;

    Robot() {
        _name = new char[strlen("Robot666") + 1];
        strcpy(_name, "Robot666");
    }
};

class Singleton {
    Robot *robot;
public:
    Robot *getRobot() {
        if (!robot)
            robot = new Robot();
        return robot;

    }
};


int main() {
    Singleton singleton;
    Robot* r1 = singleton.getRobot();
    cout << "r1 address=" << r1 << endl;
    Robot* r2 = singleton.getRobot();
    cout << "r2 address=" << r2 << endl;
}