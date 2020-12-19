#include <iostream>
#include "ShowBin.h"
#include "ShowDec.h"
#include "AString.h"
#include "BinString.h"

using namespace std;

void ShowBin::Operate(AString *pObj) {
    cout << pObj->GetName() << ": ";
    cout << GetBinary(pObj) << endl;
}

ShowBin show_bin;