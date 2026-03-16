//
//  main.cpp
//  templating lab
//
//  Created by Marina Balamoon on 3/10/26.
//

#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

using namespace std;

template <typename T>
vector<T> vec_fill(T elem){
    vector<T> v;
    for(int i = 0; i < 10; i++){
        v.push_back(elem + i);
    }
    return v;
}

template <typename T>
T until(T elem, function<T(T)> func, function<bool(T)> predicate){
    while(!predicate(elem)){
        elem = func(elem);
    }
    return elem;
}

template <typename T>
void order(T& a, T& b, T& c){
    T temp;

    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    if(a < c){
        temp = a;
        a = c;
        c = temp;
    }
    if(b < c){
        temp = b;
        b = c;
        c = temp;
    }
}

int add10(int x){
    return x + 10;
}

bool greater_than_100(int x){
    return x > 100;
}

double double_num(double x){
    return x * 2;
}

bool more_than_50(double x){
    return x > 50;
}

char next_char(char c){
    return c + 1;
}

bool less_than_z(char c){
    return c >= 'z';
}

int main() {
    //fill
    vector<int> v1 = vec_fill(3);
    assert(v1[0] == 3);
    assert(v1[3] == 6);
    assert(v1[6] == 9);

    vector<double> v2 = vec_fill(0.5);
    assert(v2[0] == 0.5);
    assert(v2[3] == 3.5);
    assert(v2[6] == 6.5);

    vector<char> v3 = vec_fill('a');
    assert(v3[0] == 'a');
    assert(v3[3] == 'd');
    assert(v3[6] == 'g');

    //until
    assert(until<int>(5, add10, greater_than_100) == 105);
    assert(until<double>(4.0, double_num, more_than_50) == 64.0);
    assert(until<char>('w', next_char, less_than_z) == 'z');

    //order
    int a = 5, b = 2, c = 7;
    order(a, b, c);
    assert(a == 7 && b == 5 && c == 2);

    double x = 5.3, y = 9.8, z = 1.6;
    order(x, y, z);
    assert(x == 9.8 && y == 5.3 && z == 1.6);

    char p = 'h', q = 'e', r = 'r';
    order(p, q, r);
    assert(p == 'r' && q == 'h' && r == 'e');

    cout << "All tests passed!" << endl;
}
