#include <string>
#include "AString.h"

std::string IsBinaryStrVal(std::string);

class OctString : public AString {
public:
    OctString(std::string _name) : name(_name) {}
    OctString(std::string _name, std::string _val);

    const std::string& GetName() const {return name;}
    const std::string& GetVal() const {return val;}
    int GetSize() const {return val.size();}

private:
    std::string name;
    std::string val;
};
