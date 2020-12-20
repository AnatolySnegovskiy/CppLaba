#include "BinString.h"
#include <bitset>

using namespace std;

BinString::BinString(string _name, string _val) :
        name(_name) {
    val = ConvertToBinary(_val);
}

BinString BinString::operator+(BinString a) {
    this->val =
            ConvertToBinary(
                    to_string(BinaryToDecimal(this->val) + BinaryToDecimal(a.GetVal()))
            );


    return BinString(this->name, this->val);
}


BinString BinString::operator-(BinString a) {
    this->val =
            ConvertToBinary(
                    to_string(BinaryToDecimal(this->val) - BinaryToDecimal(a.GetVal()))
            );

    return BinString(this->name, this->val);
}