#include <string>
#include "AString.h"

bool IsBinaryStrVal(std::string);

class BinString : public AString {
public:
    BinString(std::string _name) : name(_name) {}
    BinString(std::string _name, std::string _val);

    const std::string& GetName() const {return name;}
    const std::string& GetVal() const {return val;}
    int GetSize() const {return val.size();}

private:
    std::string name;
    std::string val;
};
