#include <iostream>
#include "Action.h"

#include "DecString.h"
#include "OctString.h"
#include "BinString.h"
#include "HexString.h"
#include "SymbString.h"

using namespace std;

long Action::GetDecimal(AString *pObj) const {
    if (dynamic_cast<DecString *>(pObj)) {
        return atol(pObj->GetVal().c_str());
    } else if (dynamic_cast<OctString *>(pObj)) {
        return OctToDec(atol(pObj->GetVal().c_str()));
    } else if (dynamic_cast<BinString *>(pObj)) {
        return BinaryToDecimal(pObj->GetVal());
    } else if (dynamic_cast<HexString *>(pObj)) {
        return HexadecimalToDecimal(pObj->GetVal());
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return BinaryToDecimal(ConvertToBinary(pObj->GetVal()));
    }
}

string Action::GetString(AString *pObj) const {
    string val;

    if (dynamic_cast<DecString *>(pObj)) {
        val = ConvertToBinary(pObj->GetVal());
    } else if (dynamic_cast<OctString *>(pObj)) {
        val = ConvertToBinary(pObj->GetVal());
    } else if (dynamic_cast<BinString *>(pObj)) {
        val = pObj->GetVal();
    } else if (dynamic_cast<HexString *>(pObj)) {
        val = ConvertToBinary(pObj->GetVal());
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
        return ConvertToBinary(pObj->GetVal());
    }
}

long Action::GetOct(AString *pObj) const {
    if (dynamic_cast<DecString *>(pObj)) {
        return DecimalToOct(atol(pObj->GetVal().c_str()));
    } else if (dynamic_cast<OctString *>(pObj)) {
        return atol(pObj->GetVal().c_str());
    } else if (dynamic_cast<BinString *>(pObj)) {
        return BinaryToDecimal(pObj->GetVal());
    } else if (dynamic_cast<HexString *>(pObj)) {
        return HexadecimalToDecimal(pObj->GetVal());
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return BinaryToDecimal(ConvertToBinary(pObj->GetVal()));
    }
}

string Action::GetHex(AString *pObj) const {
    if (dynamic_cast<DecString *>(pObj)) {
        return DecimalToHex(atol(pObj->GetVal().c_str()));
    } else if (dynamic_cast<OctString *>(pObj)) {
        return DecimalToHex(OctToDec(atol(pObj->GetVal().c_str())));
    } else if (dynamic_cast<BinString *>(pObj)) {
        return DecimalToHex(BinaryToDecimal(pObj->GetVal()));
    } else if (dynamic_cast<HexString *>(pObj)) {
        return pObj->GetVal();
    } else if (dynamic_cast<SymbString *>(pObj)) {
        return DecimalToHex(BinaryToDecimal(ConvertToBinary(pObj->GetVal())));
    }
}