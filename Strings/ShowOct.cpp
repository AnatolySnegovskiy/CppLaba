#include <iostream>
#include "ShowOct.h"
#include "HexString.h"

using namespace std;

void ShowOct::Operate(AString * pObj) {
    cout << pObj->GetName() << ": ";
    cout << GetOct(pObj) << endl;
}

ShowOct show_oct;