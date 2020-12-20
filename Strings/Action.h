#ifndef ACTION_H
#define ACTION_H

#include "AString.h"
#include "BaseAction.h"

class Action : public BaseAction {
public:
    virtual ~Action(){}
    virtual void Operate(AString*) = 0;
    virtual const std::string &GetName() const = 0;

protected:
    long GetDecimal(AString* pObj) const;
    std::string GetString(AString* pObj) const;
    std::string GetBinary(AString* pObj) const;
    long GetOct(AString* pObj) const;
    std::string GetHex(AString* pObj) const;
};

#endif