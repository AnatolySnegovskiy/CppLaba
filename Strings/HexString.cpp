#include "HexString.h"
#include <iostream>

using namespace std;

HexString::HexString(string _name, string _val) :
        name(_name) {
    val = DecimalToHex(
            BinaryToDecimalString(
                    ConvertToBinary(_val)
            )
    );
}