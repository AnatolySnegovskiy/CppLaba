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
        string source = pObj->GetVal();
        return atoi(source.c_str());
    } else {
        cout << "Action not supported" << endl;
        return -1;
    }
}