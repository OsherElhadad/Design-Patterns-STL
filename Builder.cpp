//
// Created by osher on 14/02/2022.
//

#include <iostream>

using namespace std;

class Pizza {
    friend class PizzaBuilder;
    const bool _extra_cheese;
    const bool _tomatoes;
    const bool _olives;
    const bool _pineapple;
    Pizza(bool extra_cheese, bool tomatoes, bool olives, bool pineapple):_extra_cheese(extra_cheese), _olives(olives), _pineapple(pineapple), _tomatoes(tomatoes) {}

public:
    void print() const {
        cout << "Pizza states:" << endl;
        cout << "\tExtra Cheese: " << (_extra_cheese ? "+" : "-") << endl;
        cout << "\tTomatoes: " << (_tomatoes ? "+" : "-") << endl;
        cout << "\tOlives: " << (_olives ? "+" : "-") << endl;
        cout << "\tPineapple: " << (_pineapple ? "+" : "-") << endl;
    }
};

class PizzaBuilder {
    bool _extra_cheese;
    bool _tomatoes;
    bool _olives;
    bool _pineapple;
public:
    PizzaBuilder(){
        _extra_cheese = false;
        _tomatoes = false;
        _olives = false;
        _pineapple = false;
    }
    PizzaBuilder AddCheese() {
        _extra_cheese = true;
        return *this;
    }
    PizzaBuilder AddTomatoes() {
        _tomatoes = true;
        return *this;
    }
    PizzaBuilder AddOlives() {
        _olives = true;
        return *this;
    }
    PizzaBuilder AddPineapple() {
        _pineapple = true;
        return *this;
    }

    Pizza* build() const {
        return new Pizza(_extra_cheese, _tomatoes, _olives, _pineapple);
    }
};


int main() {
    PizzaBuilder pizzaBuilder;
    Pizza p = *(pizzaBuilder.AddCheese().AddOlives().AddPineapple().build());
    p.print();
    Pizza* p2 = pizzaBuilder.AddCheese().AddOlives().AddPineapple().build();
    p2->print();
    return 0;
}