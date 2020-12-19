#include "BinString.h"
#include <bitset>

using namespace std;

BinString::BinString(string _name, string _val) :
        name(_name) {
        val = ConvertToBinary(_val);
}