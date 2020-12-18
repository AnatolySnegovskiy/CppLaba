#include <iostream>
#include "Action.h"
#include "HexString.h"
#include "BinString.h"

using namespace std;

long Action::GetDecimal(AString *pObj) const {
    if (dynamic_cast<HexString *>(pObj)) {
        long dest;
        string source = pObj->GetVal();
        sscanf(source.c_str(), "%1X", &dest);
        return dest;
    } else if (dynamic_cast<BinString *>(pObj)) {
        long dest;
        string source = GetString(pObj);
        sscanf(source.c_str(), "%1X", &dest);
        return dest;
    } else {
        long dest;
        string source = pObj->GetVal();
        sscanf(source.c_str(), "%1X", &dest);
        return dest;
    }
}

string Action::GetString(AString *pObj) const {
    if (dynamic_cast<BinString *>(pObj)) {
        string val = pObj->GetVal();
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
    } else {
        return pObj->GetVal();
    }
}