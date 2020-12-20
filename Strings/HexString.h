#include <string>
#include "AString.h"

class HexString: public AString {
public:
    HexString(std::string _name) : name(_name) {}
    HexString(std::string _name, std::string _val);
    const std::string& GetName() const {return name;}
    const std::string& GetVal() const {return val;}
    int GetSize() const {return val.size();}
    HexString operator+(HexString a);
    HexString operator-(HexString a);
private:
    std::string name;
    std::string val;
};