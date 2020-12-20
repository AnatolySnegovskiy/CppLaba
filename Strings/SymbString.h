#include <string>
#include "AString.h"

class SymbString: public AString {
public:
    SymbString(std::string _name) : name(_name) {}
    SymbString(std::string _name, std::string _val) : name(_name), val(_val) {}

    const std::string& GetName() const {return name;}
    const std::string& GetVal() const {return val;}
    int GetSize() const {return val.size();}
    SymbString operator+(SymbString a);
    SymbString operator-(SymbString a);
private:
    std::string name;
    std::string val;
    std::string sub(const std::string &s1, const std::string &s2) const;
};