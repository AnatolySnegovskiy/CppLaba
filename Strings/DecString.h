#include <string>
#include "AString.h"

class DecString : public AString {
public:
    DecString(std::string _name) : name(_name) {}
    DecString(std::string _name, std::string _val);

    const std::string& GetName() const {return name;}
    const std::string& GetVal() const {return val;}
    int GetSize() const {return val.size();}

private:
    std::string name;
    std::string val;
};
