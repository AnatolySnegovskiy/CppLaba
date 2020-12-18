#include <iostream>
#include "ShowStr.h"
#include "BinString.h"

using namespace std;

void ShowStr::Operate(AString * pObj) {
    cout << pObj->GetName() << "; ";
    cout << GetString(pObj) << endl;

    cin.get();
}

ShowStr show_str;