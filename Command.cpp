//
// Created by osher on 14/02/2022.
//

#include <iostream>
#include <cstring>

using namespace std;

class Student {
    char *_name;
public:
    Student(const char *name) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }

    void sleep() {
        cout << "I'm sleeping!! (" << _name << ")" << endl;
    }

    void eat() {
        cout << "Yummy (" << _name << ")" << endl;
    }
};

class Command {
public:
    virtual void execute() = 0;
};

class SleepCommand : public Command {
    Student *_student;
public:
    void execute() {
        _student->sleep();
    }

    SleepCommand(Student *student) {
        _student = student;
    }
};

class EatCommand : public Command {
    Student *_student;
public:
    EatCommand(Student *student) {
        _student = student;
    }

    void execute() {
        _student->eat();
    }
};

class Parent {
    Command **_commands;
public:
    Parent(Student *student) {
        _commands = new Command *[2];
        _commands[0] = new SleepCommand(student);
        _commands[1] = new EatCommand(student);
    }

    void makeStudentSleep() {
        _commands[0]->execute();
    }

    void makeStudentEat() {
        _commands[1]->execute();
    }
};


int main() {
    Student student("Israel");
    Parent p(&student);
    p.makeStudentEat();
    p.makeStudentSleep();
}