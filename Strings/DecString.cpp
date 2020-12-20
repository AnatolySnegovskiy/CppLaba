#include "DecString.h"
#include <bitset>

using namespace std;

DecString::DecString(string _name, string _val) :
        name(_name) {
    val = to_string(
            BinaryToDecimal(
                    ConvertToBinary(_val)
            )
    );
}

DecString DecString::operator+(DecString a) {
    this->val = to_string(atol(this->val.c_str()) + atol(a.GetVal().c_str()));

    return DecString(this->name, this->val);
}


DecString DecString::operator-(DecString a) {
    this->val = to_string(atol(this->val.c_str()) - atol(a.GetVal().c_str()));

    return DecString(this->name, this->val);
}