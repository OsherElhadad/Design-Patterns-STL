//
// Created by osher on 14/02/2022.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Observer {
public:
    virtual void update(const char *course) = 0;
};

class Subject {
protected:
    vector<Observer *> observers;
public:
    void Attach(Observer *observer) {
        observers.push_back(observer);
    }

    void Detach(Observer *observer) {
        for (auto o : observers)
            if (o == observer)
                observer = nullptr;
    }

    virtual void Notify(const char* course) {
        for (auto o : observers)
            if (o != nullptr)
                o->update(course);
    }
};

class Moodle : public Subject {
    int mathScore, algoScore;
public:
    Moodle() {
        mathScore = 0;
        algoScore = 0;
    }
    void setScore(const char *course, int score) {
        if (strcmp(course, "algo") == 0) {
            algoScore = score;
            Notify("algo");
            return;
        }
        if (strcmp(course, "math") == 0) {
            algoScore = score;
            Notify("math");
        }
    }
    int getScore(const char* course) const {
        if (strcmp(course, "algo") == 0)
            return algoScore;
        if (strcmp(course, "math") == 0)
            return mathScore;
        return 0;
    }
};

class Student : public Observer {
    Moodle* _moodle;
public:
    Student(Moodle* moodle) {
        _moodle = moodle;
    }
    void update(const char *course) override {
        if (strcmp(course, "algo") == 0) {
            if(_moodle->getScore("algo") > 80)
                cout << "WOW." << endl;
        }
    }
};

int main() {
    Moodle* moodle = new Moodle();
    Student* s = new Student(moodle);
    moodle->Attach(s);
    moodle->setScore("math", 100);
    moodle->setScore("algo", 70);
    moodle->setScore("algo", 81);
}