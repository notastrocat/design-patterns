#pragma once
#include <iostream>
#include <format>
#include <string>
#include <memory>
#include "colors.hpp"

namespace FactoryMethod
{

// Product Interface
class IWeapon {
public:
    virtual ~IWeapon() = default;
    virtual std::string attack() const = 0;
};

// Concrete Product Implementations
class Spear : public IWeapon {
    std::string name_;
    int power_;
public:
    explicit Spear(std::string name, int power) : name_(std::move(name)), power_(power) {}
    std::string attack() const override;
};

class Club : public IWeapon {
    std::string name_;
    int power_;
public:
    explicit Club(std::string name, int power) : name_(std::move(name)), power_(power) {}
    std::string attack() const override;
};

// ---

// Creator Interface
class ToolMaker {
public:
    virtual ~ToolMaker() = default;
    virtual std::unique_ptr<IWeapon> FactoryMethod(std::string name, int power) const = 0;

    std::string dealDamage(std::string name, int power) const {
        auto weapon = FactoryMethod(std::move(name), power);

        return colors::foreground::red +
               std::format("Dealing damage...\n") + weapon->attack() +
               colors::reset_all;
    }
};

// Concrete Creators
class SpearMaker : public ToolMaker {
public:
    std::unique_ptr<IWeapon> FactoryMethod(std::string name, int power) const override;
};

class ClubMaker : public ToolMaker {
public:
    std::unique_ptr<IWeapon> FactoryMethod(std::string name, int power) const override;
};

// ---

// Client Code
void clientCode(const ToolMaker& toolMaker, std::string name, int power);

}  // end namespace *FactoryMethod*
