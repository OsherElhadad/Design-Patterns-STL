//
// Created by osher on 13/02/2022.
//

#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Employee {
protected:
    string _name;
public:
    void work() {
        cout << _name << ":work" << endl;
    };
};

class TA : public Employee{
public:
    TA() {
        _name = "TA";
    }
};

class Developer : public Employee{
public:
    Developer() {
        _name = "Developer";
    }
};

class Manager : public Employee{
public:
    Manager() {
        _name = "Manager";
    }
};


class EmployeeFactory {
    map<string, std::function<Employee*()>> _map;
public:
    EmployeeFactory() {
        _map.insert({"ta", []() { return (Employee *) new TA(); }});
        _map.insert({"manager", []() { return (Employee *) new Manager(); }});
        _map.insert({"developer", []() { return (Employee *) new Developer(); }});
    }

    Employee *create(const string& key) {
        if (_map.find(key) != _map.end())
            return _map.at(key)();
        return nullptr;
    }
};

int main() {
    EmployeeFactory* employeeFactory = new EmployeeFactory();
    Employee *e = employeeFactory->create("developer");
    if(e) {
        e->work();
        delete e;
    }
    e = employeeFactory->create("ta");
    if(e) {
        e->work();
        delete e;
    }
    e = employeeFactory->create("garbage collector");
    if(e) {
        e->work();
        delete e;
    }
    delete employeeFactory;
    return 0;
}