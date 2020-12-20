#include "BaseAction.h"
#include <bitset>
#include <cmath>
#include <iostream>
using namespace std;

long BaseAction::OctToDec(long dec) const {
    string str = to_string(dec);
    bool p = false;
    int l = str.length();
    int N = 0;

    if (str[0] == '-') {
        str.erase(0, 1);
        p = true;
    } else {

        for (int i = 0; i < l; i++) {
            N += (str[i] - '0') * pow(8, l - i - 1);
        }
    }

    if (p) {
        N *= -1;
    }

    return N;
}

long BaseAction::BinaryToDecimal(string binary) const {
    unsigned long long value = std::bitset<64>(binary).to_ullong();
    return value;
}

long BaseAction::HexadecimalToDecimal(string hexVal) const {
    int len = hexVal.size();
    int base = 1;
    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (hexVal[i] - 48) * base;
            base = base * 16;
        } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (hexVal[i] - 55) * base;
            base = base * 16;
        }
    }

    return dec_val;
}

string BaseAction::ConvertToBinary(string str) const {
    string binaryString = "";

    if (is_number(str)) {
        long number = atol(str.c_str());
        binaryString = bitset<sizeof(number) * 8>(number).to_string();
    } else {
        for (char &_char : str) {
            binaryString += bitset<8>(_char).to_string();
        }
    }

    return binaryString;
}

long BaseAction::DecimalToOct(long decimal) const {
    unsigned long b, k, c, dec;
    k = 1;
    c = 0;
    dec = decimal;

    while (dec > 0) {
        b = dec % 8;
        dec /= 8;
        c += b * pow(10, k - 1);
        b = 0;
        k++;
    }

    return c;
}

string BaseAction::DecimalToHex(long decimal) const {
    unsigned long dec = decimal;
    char hex[to_string(dec).size()];

    sprintf(hex, "%x", dec);
    return hex;
}

bool BaseAction::is_number(const string& s) const
{
    return !s.empty() && (s.find_first_not_of("0123456789") == s.npos);
}