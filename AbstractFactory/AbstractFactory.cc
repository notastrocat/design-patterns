#include "AbstractFactory.hpp"

namespace AbstractFactory
{

std::string Spear::attack() const {
    return colors::foreground::red +  std::format("Ranged attack from {}! Power level: {}", this->name_,
            this->power_) + colors::reset_all;
}

std::string Club::attack() const {
    return colors::foreground::red + std::format("Melee attack from {}! Power level: {}", this->name_,
            this->power_) + colors::reset_all;
}

std::string HideArmor::defend(std::string weaponName, int weaponPowerLevel) {
    return colors::foreground::red + std::format("Defending attack from {}! Life left: {}", weaponName,
            (this->life_ -= weaponPowerLevel)) + colors::reset_all;
}

std::string CrossBow::attack() const {
    return colors::foreground::red +  std::format("Ranged attack from {}! Power level: {}", this->name_,
            this->power_) + colors::reset_all;
}

std::string Sword::attack() const {
    return colors::foreground::red + std::format("Melee attack from {}! Power level: {}", this->name_,
            this->power_) + colors::reset_all;
}

std::string ChainMailArmor::defend(std::string weaponName, int weaponPowerLevel) {
    return colors::foreground::red + std::format("Defending attack from {}! Life left: {}", weaponName,
            (this->life_ -= weaponPowerLevel)) + colors::reset_all;
}

std::string Rifle::attack() const {
    return colors::foreground::red +  std::format("Ranged attack from {}! Power level: {}", this->name_,
            this->power_) + colors::reset_all;
}

std::string Knife::attack() const {
    return colors::foreground::red + std::format("Melee attack from {}! Power level: {}", this->name_,
            this->power_) + colors::reset_all;
}

std::string BulletProofArmor::defend(std::string weaponName, int weaponPowerLevel) {
    return colors::foreground::red + std::format("Defending attack from {}! Life left: {}", weaponName,
            (this->life_ -= weaponPowerLevel)) + colors::reset_all;
}

std::unique_ptr<IWeapon> StoneAgeArmory::createRangedWeapon(std::string name, int powerLevel) const {
    return std::make_unique<Spear>(std::move(name), powerLevel);
}

std::unique_ptr<IWeapon> StoneAgeArmory::createMeleeWeapon(std::string name, int powerLevel) const {
    return std::make_unique<Club>(std::move(name), powerLevel);
}

std::unique_ptr<IArmor> StoneAgeArmory::createArmor(std::string name, int maxLife) const {
    return std::make_unique<HideArmor>(std::move(name), maxLife);
}

std::unique_ptr<IWeapon> MedievalArmory::createRangedWeapon(std::string name, int powerLevel) const {
    return std::make_unique<CrossBow>(std::move(name), powerLevel);
}

std::unique_ptr<IWeapon> MedievalArmory::createMeleeWeapon(std::string name, int powerLevel) const {
    return std::make_unique<Sword>(std::move(name), powerLevel);
}

std::unique_ptr<IArmor> MedievalArmory::createArmor(std::string name, int maxLife) const {
    return std::make_unique<ChainMailArmor>(std::move(name), maxLife);
}

std::unique_ptr<IWeapon> ModernArmory::createRangedWeapon(std::string name, int powerLevel) const {
    return std::make_unique<Rifle>(std::move(name), powerLevel);
}
std::unique_ptr<IWeapon> ModernArmory::createMeleeWeapon(std::string name, int powerLevel) const {
    return std::make_unique<Knife>(std::move(name), powerLevel);
}

std::unique_ptr<IArmor> ModernArmory::createArmor(std::string name, int maxLife) const {
    return std::make_unique<BulletProofArmor>(std::move(name), maxLife);
}

void clientCode(const IArmory &armory, std::string rangedName, int rangedPower, std::string meleeName, int meleePower, std::string armorName, int maxLifeArmor) {
    auto rangedWeapon = armory.createRangedWeapon(rangedName, rangedPower);
    auto meleeWeapon = armory.createMeleeWeapon(meleeName, meleePower);

    auto armor = armory.createArmor(armorName, maxLifeArmor);

    std::cout << rangedWeapon->attack() << std::endl;
    std::cout << armor->defend(rangedWeapon->name(), rangedWeapon->power()) << std::endl;

    std::cout << meleeWeapon->attack() << std::endl;
    std::cout << armor->defend(meleeWeapon->name(), meleeWeapon->power()) << std::endl;
}

} // end namespace *AbstractFactory*
