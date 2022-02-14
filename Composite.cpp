//
// Created by osher on 13/02/2022.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Employee{
public:
    virtual void print(){
        cout<<"Employee"<<endl;
    }
    virtual ~Employee(){}
};
class Engineer:public Employee{
public:
    virtual void print(){
        cout<<"Engineer"<<endl;
    }
};

list<Employee*> hasAManager;
class Manager: public Employee{
    list<Employee*> emps;
public:
    virtual void print(){
        cout<<"Manager"<<endl;
        for_each(emps.begin(),emps.end(),[](Employee* e){e->print();});
    }
    void addEmployee(Employee* emp){
        if(find(emp) || findMe(emp))
            throw -1;
        emps.push_back(emp);
        hasAManager.push_back(emp);
    }
    virtual ~Manager(){
        for_each(emps.begin(),emps.end(),[](Employee* e){delete e;});
    }
private:
    bool find(Employee* e){
        list<Employee*>::iterator it=hasAManager.begin();
        while(it!=hasAManager.end()){
            if(e==*it)
                return true;
            it++;
        }
        return false;
    }
    bool findMe(Employee* e){
        if(this==e)
            return true;
        Manager* m=dynamic_cast<Manager*>(e);
        if(m){
            list<Employee*>::iterator it=m->emps.begin();
            while(it!=m->emps.end()){
                if(findMe(*it))
                    return true;
                it++;
            }
        }
        return false;
    }
};


int main(){
    Manager* m0=new Manager();
    Manager* m1=new Manager();
    Manager* m2=new Manager();
    Employee* e0=new Engineer();
    Employee* e1=new Engineer();
    Employee* e2=new Engineer();
    Employee* e3=new Engineer();
    m0->addEmployee(e0);
    m0->addEmployee(m1);
    m1->addEmployee(e1);
    m1->addEmployee(e2);
    m1->addEmployee(m2);
    m2->addEmployee(e3);
    m0->print();
    try{
        m1->addEmployee(e0);
    }catch(int e){
        cout<<"catch 1"<<endl;
    }
    try{
        m2->addEmployee(m0);
    }catch(int e){cout<<"catch 2"<<endl;}
    try{
        m1->addEmployee(m1);
    }catch(int e){ cout<<"catch 3"<<endl;}
    delete m0;
    return 0;
}