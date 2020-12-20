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