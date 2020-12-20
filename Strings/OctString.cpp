#include "OctString.h"

using namespace std;

OctString::OctString(string _name, string _val) :
        name(_name) {
    val = to_string(
            DecimalToOct(
                    BinaryToDecimal(
                            ConvertToBinary(_val)
                    )
            )
    );
}