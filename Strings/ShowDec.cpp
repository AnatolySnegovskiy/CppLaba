#include <iostream>
#include "ShowDec.h"
#include "HexString.h"

using namespace std;

void ShowDec::Operate(AString *pObj) {
    cout << pObj->GetName() << ": ";
    cout << GetDecimal(pObj) << endl;
}

ShowDec show_dec;