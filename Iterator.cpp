//
// Created by osher on 14/02/2022.
//

#include <iostream>

using namespace std;
class Integer {
    int _i;
public:
    Integer() {
        _i = 0;
    }
    Integer(int i) {
        _i = i;
    }
    Integer operator+(Integer i) const {
        return Integer(_i + i._i);
    }
    Integer operator-(Integer i) const {
        return Integer(_i - i._i);
    }
    Integer& operator=(Integer i) {
        _i = i._i;
        return *this;
    }
    bool operator==(Integer i) const {
        return _i == i._i;
    }
    bool operator>(Integer i) const {
        return _i > i._i;
    }
    bool operator<(Integer i) const {
        return _i < i._i;
    }
    bool operator>=(Integer i) const {
        return _i >= i._i;
    }
    bool operator<=(Integer i) const {
        return _i <= i._i;
    }
    Integer& operator++() {
        _i++;
        return *this;
    }
    Integer& operator--() {
        _i--;
        return *this;
    }
    Integer operator++(int) {
        Integer i;// = *this;
        i._i = _i;
        _i++;
        return i;
    }
    Integer operator--(int) {
        Integer i;// = *this;
        i._i = _i;
        _i--;
        return i;
    }
    Integer& operator+=(Integer i) {
        _i += i._i;
        return *this;
    }
    Integer operator-=(Integer i) {
        _i -= i._i;
        return *this;
    }
    Integer operator*(Integer i) const {
        return Integer(_i * i._i);
    }
    Integer operator/(Integer i) const {
        return Integer(_i / i._i);
    }
    friend ostream& operator<<(ostream& out, Integer i);
    friend Integer operator+(int i1, Integer i2);
    friend Integer operator-(int i1, Integer i2);
    friend Integer operator*(int i1, Integer i2);
    friend Integer operator/(int i1, Integer i2);
    friend bool operator==(int i1, Integer i2);
    friend bool operator>(int i1, Integer i2);
    friend bool operator<(int i1, Integer i2);
    friend bool operator>=(int i1, Integer i2);
    friend bool operator<=(int i1, Integer i2);
};

ostream &operator<<(ostream &out, Integer i) {
    out << i._i;
    return out;
}
Integer operator+(int i1, Integer i2) {
    return Integer(i1 + i2._i);
}
Integer operator-(int i1, Integer i2) {
    return Integer(i1 - i2._i);
}
Integer operator*(int i1, Integer i2) {
    return Integer(i1 * i2._i);
}
Integer operator/(int i1, Integer i2) {
    return Integer(i1 / i2._i);
}
bool operator==(int i1, Integer i2) {
    return i1 == i2._i;
}
bool operator>(int i1, Integer i2) {
    return i1 > i2._i;
}
bool operator<(int i1, Integer i2) {
    return i1 < i2._i;
}
bool operator>=(int i1, Integer i2) {
    return i1 >= i2._i;
}
bool operator<=(int i1, Integer i2) {
    return i1 <= i2._i;
}


int main() {
    Integer i1 = 10;
    Integer i2 = 20;
    i1 += i2;
    Integer i4 = 3 * i2;
    i1++;
    cout << i1++ << endl;
    cout << i2 + i1 << endl;
    cout << i4 << endl;
    cout << (21 >= i2 ? "true" : "false") << endl;
}