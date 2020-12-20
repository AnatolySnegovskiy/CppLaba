#include "SymbString.h"

using namespace std;

SymbString SymbString::operator+(SymbString a) {
    this->val += a.GetVal();

    return SymbString(this->name, this->val);
}


SymbString SymbString::operator-(SymbString a) {
    this->val = sub(this->val, a.GetVal());

    return SymbString(this->name, this->val);
}

string SymbString::sub(const string &s1, const string &s2) const {
    int pos1 = s1.find(s2);

    string res = s1.substr(0, pos1 - 1) + s1.substr(pos1 + s2.size(), string::npos);

    return res;
}