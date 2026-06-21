#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "colors.hpp"

/**
 * NOTE: we're not using smart pointer because we don't want exclusive ownership in either of the two things.
 * Smart pointer demand exclusive ownership. LookOut not own Hunter. Hunter independent.
 * If LookOut hold smart pointer, LookOut die, Hunter die. Unacceptable.
 * You appreciate manual memory management. Raw pointer just point. No own. Disentangled. Hunter join or leave freely. Architecture orthogonal.
*/

namespace Observer
{

class TribalMember;

class ILookOut {
public:
    virtual ~ILookOut() = default;
    virtual bool registerForWarning(TribalMember* o) = 0;
    virtual bool deRegisterForWarning(TribalMember* o) = 0;
    virtual void setSignal(const std::string& signal) = 0;
    virtual void notifyAll() = 0;
};

class LookOut : public ILookOut {
    std::vector<TribalMember*> observers_;
    std::string signal_;
public:
    bool registerForWarning(TribalMember* o) override;
    bool deRegisterForWarning(TribalMember* o) override;
    void setSignal(const std::string& signal) override;
    void notifyAll() override;
};

class TribalMember {
public:
    virtual ~TribalMember() = default;
    virtual void update(const std::string& signal) = 0;
    virtual void joinTribe() = 0;
    virtual void leaveTribe() = 0;
};

class Hunter : public TribalMember {
    std::string name_;
    ILookOut* lookOut_;
public:
    explicit Hunter(ILookOut* lookOut, std::string name);
    ~Hunter() override;
    void update(const std::string& signal) override;
    void joinTribe() override;
    void leaveTribe() override;
};

class Gatherer : public TribalMember {
    std::string name_;
    ILookOut* lookOut_;
public:
    explicit Gatherer(ILookOut* lookOut, std::string name);
    ~Gatherer() override;
    void update(const std::string& signal) override;
    void joinTribe() override;
    void leaveTribe() override;
};

void clientCode();

}  // end namespace *Observer*
