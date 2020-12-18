#include "OctString.h"

using namespace std;

string IsOctStrVal(string _str) {
    string newString = "";

    for (int i = 0; i < _str.size(); ++i) {
        if (_str[i] > '0' || _str[i] < '7') {
            newString += _str[i];
        }
    }

    return newString;
}

OctString::OctString(string _name, string _val) :
        name(_name) {
    val = IsOctStrVal(_val);
}