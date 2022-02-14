//
// Created by osher on 13/02/2022.
//

#include <iostream>

using namespace std;

class Bank {
protected:
    double balance;
public:
    virtual double getBalance()=0;
    virtual void addMoney(size_t money)=0;
};

class LeumiBank : public Bank {
    double BankId;
public:
    LeumiBank(double id) {
        BankId = id;
    }
    double getBalance() override {
        return balance;
    }
    void addMoney(size_t money) override {
        balance += money;
    }
};

class Proxy : public Bank {
    LeumiBank* _bank;
public:
    Proxy(LeumiBank* bank) {
        _bank = bank;
    }
    double getBalance() override {
        return _bank->getBalance();
    }
    void addMoney(size_t money) override {
        cout << "Proxy: you don't have permission to add money!" << endl;
    }
    ~Proxy() {
        delete _bank;
    }
};


int main() {
    LeumiBank* myBank = new LeumiBank(123);
    myBank->addMoney(1000);

    Bank* bank = new Proxy(myBank);
    cout << "Your balance is: " << bank->getBalance() << endl;
    bank->addMoney(1500);
    delete bank;
}