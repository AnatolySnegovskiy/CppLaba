#include "HexString.h"
#include <iostream>

using namespace std;

HexString::HexString(string _name, string _val) :
        name(_name + " (HexString)") {
    val = DecimalToHex(
            BinaryToDecimal(
                    ConvertToBinary(_val)
            )
    );
}

HexString HexString::operator+(HexString a) {
    this->val =
            DecimalToHex(
                    HexadecimalToDecimal(this->val)
                    +
                    HexadecimalToDecimal(a.GetVal())
            );


    return HexString(this->name, this->val);
}


HexString HexString::operator-(HexString a) {
    this->val =
            DecimalToHex(
                    HexadecimalToDecimal(this->val)
                    -
                    HexadecimalToDecimal(a.GetVal())
            );

    return HexString(this->name, this->val);
}