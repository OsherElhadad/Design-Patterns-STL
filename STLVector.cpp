//
// Created by osher on 14/02/2022.
//

#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
class MyVector {
    T *_arr;
    size_t _size;
    size_t _realSize;
public:
    explicit MyVector(size_t size) {
        _size = size;
        _arr = new T[_size];
        _realSize = 0;
    }

    explicit MyVector() {
        _size = 1;
        _arr = new T[_size];
        _realSize = 0;
    }

    MyVector(const MyVector<T> &vec) {
        _size = vec._size;
        _arr = new T[_size];
        for (int i = 0; i < _size; ++i) {
            _arr[i] = vec._arr[i];
        }
        _realSize = _size;
    }

    MyVector(MyVector<T> &&vec) {
        _size = vec._size;
        _arr = new T[_size];
        _arr = vec;
        _realSize = _size;

        vec._realSize = 0;
        vec._size = 0;
        vec._arr = nullptr;
    }

    const T &at(size_t index) const {
        if (index >= _realSize)
            throw std::out_of_range("");
        return _arr[index];
    }

    void push_back(const T &t) {
        if (_realSize >= _size) {
            _size *= 2;
            T *temp = new T[_size];
            for (int i = 0; i < _realSize; i++) {
                temp[i] = this->at(i);
            }
            delete[] _arr;
            _arr = move(temp);
        }
        _arr[_realSize] = t;
        _realSize++;
    }

    size_t size() {
        return _realSize;
    }

    bool empty() {
        return _realSize == 0;
    }

    const T &operator[](int index) {
        return _arr[index];
    }

    virtual ~MyVector() {
        delete []_arr;
    }

    class iterator {
        T* _it;
    public:
        explicit iterator(T* ptr) {
            _it = ptr;
        }
        MyVector::iterator& operator++() {
            _it++;// += sizeof(T);
            return *this;
        }
        MyVector::iterator operator++(int) {
            MyVector::iterator it(_it);// = *this;
            _it++;
            return it;
        }

        bool operator==(MyVector::iterator it) {
            //cout << "address: " << _it << " - " << it._it << endl;
            return _it == it._it;
        }
        bool operator<(MyVector::iterator it) {
            return _it < it._it;
        }

        MyVector::iterator& operator=(MyVector::iterator it) {
            if (this != &it)
                _it = it._it;
            return *this;
        }
        T& operator*() {
            return *_it;
        }
    };

    iterator begin() {
        return iterator(&_arr[0]);
    }

    iterator end() {
        return iterator(&_arr[_realSize]);
    }

};

template<class iterator, class func>
func forEach(iterator begin, iterator end, func f) {
    while (begin < end) {
        f(*begin);
        begin++;
    }
    return f;
}

template<class iterator, class predicate>
int countIf(iterator begin, iterator end, predicate p) {
    int counter = 0;
    while (begin < end) {
        if (p(*begin))
            counter++;
        begin++;
    }
    return counter;
}

template<class T, class iterator>
void swap(iterator it1, iterator it2) {
    T object = *it1;
    *it1 = *it2;
    *it2 = object;
}

template<class T, class iterator>
iterator find(iterator begin, iterator end, T object) {
    while (begin < end) {
        if (object == *begin)
            return begin;
        begin++;
    }
    return begin;
}


int main() {
    MyVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    forEach(v.begin(), v.end(), [](int x){
        cout << x << endl;
    });
    int count = countIf(v.begin(), v.end(), [](int x){
        return x > 3;
    });
    cout << "number of numbers above 3: " << count << endl;

    swap<int, MyVector<int>::iterator>(++(v.begin()), ++(++(v.begin())));

    forEach(v.begin(), v.end(), [](int x){
        cout << x << endl;
    });

    if(find(v.begin(), v.end(), 5) == v.end())
        cout << "didn't find 5" << endl;
    else
        cout << "find 5!" << endl;
    if(find(v.begin(), v.end(), 6) == v.end())
        cout << "didn't find 6" << endl;
    else
        cout << "find 6!" << endl;

}