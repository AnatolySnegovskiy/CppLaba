#include <iostream>
#include "ShowHex.h"
#include "HexString.h"

using namespace std;

void ShowHex::Operate(AString * pObj) {
    cout << pObj->GetName() << ": ";
    cout << GetHex(pObj) << endl;
}

ShowHex show_hex;