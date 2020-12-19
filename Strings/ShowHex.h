#include "Action.h"

class ShowHex: public Action {
public:
    ShowHex() : name("Show hex value"){}
    void Operate(AString*);
    const std::string& GetName() const {return name;}

private:
    std::string name;
};

extern ShowHex show_hex;