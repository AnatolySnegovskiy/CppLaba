#ifndef ASTRING_H
#define ASTRING_H

#include  <string>
#include "BaseAction.h"

class AString : public BaseAction {
public:
    virtual ~AString() {}

    virtual const std::string &GetName() const = 0;

    virtual const std::string &GetVal() const = 0;

    virtual int GetSize() const = 0;
};

#endif