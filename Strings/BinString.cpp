#include "BinString.h"
#include <bitset>

using namespace std;

string toBinaryStrVal(string _str) {
    string binaryString = "";
    for (char& _char : _str) {
        binaryString +=bitset<8>(_char).to_string();
    }

    return binaryString;
}

BinString::BinString(string _name, string _val) :
        name(_name) {
        val = toBinaryStrVal(_val);
}