#include <string>
#include "AString.h"

class BinString : public AString {
public:
    BinString(std::string _name) : name(_name) {}
    BinString(std::string _name, std::string _val);

    const std::string& GetName() const {return name;}
    const std::string& GetVal() const {return val;}
    int GetSize() const {return val.size();}
    BinString operator+(BinString a);
    BinString operator-(BinString a);
private:
    std::string name;
    std::string val;
};
