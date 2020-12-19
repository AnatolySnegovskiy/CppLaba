#include "OctString.h"

using namespace std;

OctString::OctString(string _name, string _val) :
        name(_name) {
    val = DecimalToOct(
            BinaryToDecimalString(
                    ConvertToBinary(_val)
            )
    );
}