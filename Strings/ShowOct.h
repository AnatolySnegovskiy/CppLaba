#include "Action.h"

class ShowOct: public Action {
public:
    ShowOct() : name("Show Oct value"){}
    void Operate(AString*);
    const std::string& GetName() const {return name;}

private:
    std::string name;
};

extern ShowOct show_oct;