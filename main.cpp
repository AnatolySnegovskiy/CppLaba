#include <iostream>
#include "Strings/AString.h"
#include "Strings/SymbString.h"
#include "Strings/HexString.h"
#include "Strings/BinString.h"
#include "Strings/Action.h"
#include "Strings/ShowStr.h"
#include "Strings/ShowDec.h"
#include "Strings/ShowBin.h"
#include "Strings/Factory.h"
#include "Strings/Menu.h"

using namespace std;

Action *pActs[] = {&show_str, &show_dec, &show_bin};

vector<Action *> actionList(pActs, pActs + sizeof(pActs) / sizeof(Action *));

int main() {
    Factory factory;
    Menu menu(actionList);
    JobMode jobMode;

    while ((jobMode = menu.SelectJob()) != Exit) {
        switch (jobMode) {
            case AddObj:
                factory.AddObject();
                break;
            case DelObj:
                factory.DeleteObject();
                break;
            case WorkWithObj:
                AString *pObj = menu.SelectObject(factory);
                Action *pAct = menu.SelectAction(pObj);
                if (pAct) pAct->Operate(pObj);
                break;
        }
        cin.get();
    }

    cout << "Bye!\n";
    return 0;
}