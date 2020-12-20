#ifndef BASEACTION_H
#define BASEACTION_H

#include  <string>

class BaseAction {
protected:
    long OctToDec(long dec) const;
    long BinaryToDecimal(std::string binary) const;
    long HexadecimalToDecimal(std::string hexVal) const;
    std::string ConvertToBinary(std::string str) const;
    long DecimalToOct(long decimal) const;
    std::string DecimalToHex(long decimal) const;

private:
    bool is_number(const std::string& s) const;
};


#endif
