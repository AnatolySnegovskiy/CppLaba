#ifndef ACTION_H
#define ACTION_H

#include "AString.h"

class Action {
public:
    virtual ~Action(){}
    virtual void Operate(AString*) = 0;
    virtual const std::string &GetName() const = 0;

protected:
    long GetDecimal(AString* pObj) const;
    std::string GetString(AString* pObj) const;
    std::string GetBinary(AString* pObj) const;
    long GetOct(AString* pObj) const;
    std::string GetHex(AString* pObj) const;

private:
    long octToDec(long dec) const;
    long binaryToDecimal(std::string binary) const;
    long hexadecimalToDecimal(std::string hexVal) const;
    std::string convertToBinary(std::string str) const;
    long decimalToOct(long decimal) const;
    std::string decimalToHex(long decimal) const;
};

#endif