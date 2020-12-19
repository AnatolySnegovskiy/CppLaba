#include "AString.h"
#include <bitset>
#include <cmath>

using namespace std;

string AString::ConvertToBinary(string str) const {
    string binaryString = "";

    if (is_number(str)) {
        binaryString += bitset<8>(atol(str.c_str())).to_string();
    } else {
        for (char &_char : str) {
            binaryString += bitset<8>(_char).to_string();
        }
    }

    return binaryString;
}


string AString::BinaryToDecimalString(string binary) const {
    unsigned long long value = std::bitset<64>(binary).to_ullong();
    return to_string(value);
}


string AString::DecimalToOct(string decimal) const {
    unsigned long b, k, c, dec;
    k = 1;
    c = 0;
    dec = atol(decimal.c_str());

    while (dec > 0) {
        b = dec % 8;
        dec /= 8;
        c += b * pow(10, k - 1);
        b = 0;
        k++;
    }

    return to_string(c);
}


string AString::DecimalToHex(string decimal) const {
    unsigned long dec = atol(decimal.c_str());
    char hex[to_string(dec).size()];

    sprintf(hex, "%x", dec);
    return hex;
}

bool AString::is_number(const std::string& s) const
{
    return !s.empty() && (s.find_first_not_of("0123456789") == s.npos);
}
