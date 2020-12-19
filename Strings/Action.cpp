#include <iostream>
#include "Action.h"

#include "DecString.h"
#include "OctString.h"
#include "BinString.h"
#include "HexString.h"
#include "SymbString.h"

#include <bitset>
#include <cmath>
#include <stdlib.h>

using namespace std;

long Action::GetDecimal(AString *pObj) const {
    if (dynamic_cast<DecString *>(pObj)) {
        return atol(pObj->GetVal().c_str());
    } else if (dynamic_cast<OctString *>(pObj)) {
        return octToDec(atol(pObj->GetVal().c_str()));
    } else if (dynamic_cast<BinString *>(pObj)) {
        return binaryToDecimal(pObj->GetVal());
    } else if (dynamic_cast<HexString *>(pObj)) {
        return hexadecimalToDecimal(pObj->GetVal());
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return binaryToDecimal(convertToBinary(pObj->GetVal()));
    }
}

string Action::GetString(AString *pObj) const {
    string val;

    if (dynamic_cast<DecString *>(pObj)) {
        val = convertToBinary(pObj->GetVal());
    } else if (dynamic_cast<OctString *>(pObj)) {
        val = convertToBinary(pObj->GetVal());
    } else if (dynamic_cast<BinString *>(pObj)) {
        val = pObj->GetVal();
    } else if (dynamic_cast<HexString *>(pObj)) {
        val = convertToBinary(pObj->GetVal());
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return pObj->GetVal();
    }

    string newstring = "";

    for (int i = 0; i < val.size(); i = i + 8) {
        char parsed = 0;
        for (int j = 0; j < 8; j++) {
            if (val[i + j] == '1') {
                parsed |= 1 << (7 - j);
            }
        }

        newstring += parsed;
    }

    return newstring;
}

string Action::GetBinary(AString *pObj) const {
    if (dynamic_cast<BinString *>(pObj)) {
        return pObj->GetVal();
    } else {
        return convertToBinary(pObj->GetVal());
    }
}

long Action::GetOct(AString *pObj) const {
    if (dynamic_cast<DecString *>(pObj)) {
        return decimalToOct(atol(pObj->GetVal().c_str()));
    } else if (dynamic_cast<OctString *>(pObj)) {
        return atol(pObj->GetVal().c_str());
    } else if (dynamic_cast<BinString *>(pObj)) {
        return binaryToDecimal(pObj->GetVal());
    } else if (dynamic_cast<HexString *>(pObj)) {
        return hexadecimalToDecimal(pObj->GetVal());
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return binaryToDecimal(convertToBinary(pObj->GetVal()));
    }
}

string Action::GetHex(AString *pObj) const {
    if (dynamic_cast<DecString *>(pObj)) {
        return decimalToHex(atol(pObj->GetVal().c_str()));
    } else if (dynamic_cast<OctString *>(pObj)) {
        return decimalToHex(octToDec(atol(pObj->GetVal().c_str())));
    } else if (dynamic_cast<BinString *>(pObj)) {
        return decimalToHex(binaryToDecimal(pObj->GetVal()));
    } else if (dynamic_cast<HexString *>(pObj)) {
        return pObj->GetVal();
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return decimalToHex(binaryToDecimal(convertToBinary(pObj->GetVal())));
    }
}

long Action::octToDec(long dec) const {
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

long Action::binaryToDecimal(string binary) const {
    unsigned long long value = std::bitset<64>(binary).to_ullong();
    return value;
}

long Action::hexadecimalToDecimal(string hexVal) const {
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

string Action::convertToBinary(string str) const {
    string binaryString = "";

    for (char &_char : str) {
        binaryString += bitset<8>(_char).to_string();
    }

    return binaryString;
}

long Action::decimalToOct(long decimal) const {
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

string Action::decimalToHex(long decimal) const {
    unsigned long dec = decimal;
    char hex[to_string(dec).size()];

    sprintf(hex, "%x", dec);
    return hex;
}