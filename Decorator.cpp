//
// Created by osher on 13/02/2022.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class I {
public:
    virtual void m()=0;
};

class Decorator : public I{
    static I* ins;
    static list<Decorator*> PQ;
    int priority;
    void push(Decorator* d){
        list<Decorator*>::iterator it=PQ.begin();
        while(it!=PQ.end() && (*it)->priority > priority) it++;
        PQ.insert(it,d);
    }
public:
    Decorator(I* i, int priority){
        ins=i;
        this->priority=priority;
        push(this);
    }
    Decorator(Decorator* d,int priority){
        this->priority=priority;
        push(this);
    }
    virtual void m(){
        if(!PQ.empty()){
            Decorator* d = PQ.front();
            PQ.pop_front();
            d->m();
            d->addedBehavior();
        }
        else
            ins->m();
    }
    virtual void addedBehavior()=0;
};

class A : public Decorator{
public:
    A(I* i):Decorator(i,3){}
    A(Decorator* d):Decorator(d,3){}
    virtual void addedBehavior(){
        cout<<" A ";
    }
};
class B : public Decorator{
public:
    B(I* i):Decorator(i,2){}
    B(Decorator* d):Decorator(d,2){}
    virtual void addedBehavior(){
        cout<<" B ";
    }
};
class C : public Decorator{
public:
    C(I* i):Decorator(i,1){}
    C(Decorator* d):Decorator(d,1){}
    virtual void addedBehavior(){
        cout<<" C ";
    }
};
class SomeI : public I{
public:
    virtual void m(){
        cout << " someI ";
    }
};
I* Decorator::ins = nullptr;
list<Decorator*> Decorator:: PQ;
int main(){
    I* i = new C(new A(new B(new SomeI())));
    i->m();
    return 0;
}