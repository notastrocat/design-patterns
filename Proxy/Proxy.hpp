#include <memory>
#include <iostream>
#include <chrono>
#include <thread>
#include <format>
#include "colors.hpp"

namespace Proxy
{

class TribalMember;

// Interface which the *Real* Service as well as the *Proxy* Service needs to implement.
// So that the *Proxy* Service can act as the *Real* Service.
class ICave {
public:
    virtual      ~ICave() = default;

    virtual std::string getEnchanted(std::unique_ptr<TribalMember> member) = 0;
};

// *Real* Service
class SacredCave : public ICave {
public:
    SacredCave() = default;
    ~SacredCave() override = default;

    std::string getEnchanted(std::unique_ptr<TribalMember> member) override;
};

// *Proxy* Service
class Guard : public ICave {
private:
    std::unique_ptr<SacredCave>           realCave_;
    std::chrono::steady_clock::time_point lastBoulderMoveTime_;

    // let's suppose that this the lazy init that we wish to do before anyone can access the cave.
    void        moveBoulder();
    // let's suppose this is the access check we wish to do before anyone can access the cave.
    bool        checkEligibility(const int &rank);
public:
    explicit Guard() { realCave_ = std::make_unique<SacredCave>(); }
             ~Guard() override = default;

    // *Real* API from *Real* Service
    std::string getEnchanted(std::unique_ptr<TribalMember> member) override;
};

// just to have some meaning to this example.
class TribalMember {
private:
    int         rank_;
    std::string name_;
public:
    explicit TribalMember(std::string &name, int &rank) : name_(std::move(name)), rank_(rank) {}
    virtual  ~TribalMember() = default;

    std::string getName() const;
    int         getRank() const;
};

void clientCode();

} // namespace Proxy
