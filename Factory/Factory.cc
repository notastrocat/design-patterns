#include "Factory.hpp"

namespace FactoryMethod
{

std::string Spear::attack() const {
    return std::format("Ranged attack from {} (Spear). Power level: {}", name_, power_);
}

std::string Club::attack() const {
    return std::format("Melee attack from {} (Club). Power level: {}", name_, power_);
}

std::unique_ptr<IWeapon> SpearMaker::FactoryMethod(std::string name, int power) const {
    return std::make_unique<Spear>(std::move(name), power);
}

std::unique_ptr<IWeapon> ClubMaker::FactoryMethod(std::string name, int power) const {
    return std::make_unique<Club>(std::move(name), power);
}

void clientCode(const ToolMaker& toolMaker, std::string name, int power) {
    std::cout << toolMaker.dealDamage(std::move(name), power) << '\n';
}

}  // end namespace *FactoryMethod*
