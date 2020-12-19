#ifndef ASTRING_H
#define ASTRING_H

#include  <string>

class AString {
public:
    virtual ~AString() {}

    virtual const std::string &GetName() const = 0;

    virtual const std::string &GetVal() const = 0;

    virtual int GetSize() const = 0;

protected:
    std::string ConvertToBinary(std::string str) const;
    std::string BinaryToDecimalString(std::string str) const;
    std::string DecimalToOct(std::string str) const;
    std::string DecimalToHex(std::string str) const;

private:
    bool is_number(const std::string& s) const;
};

#endif