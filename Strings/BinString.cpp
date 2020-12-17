#include <iostream>
#include "BinString.h"

using namespace std;

bool IsBinaryStrVal(string _str) {
    for (int i = 0; i < _str.size(); ++i) {
        if (_str[i] != '0' && _str[i] != '1') {
            cout << "this char is not binary: " << _str[i] << endl;
            return false;
        }
    }

    return true;
}

BinString::BinString(string _name, string _val) :
        name(_name) {
    if (IsBinaryStrVal(_val)) {
        val = _val;
    }
}