#include <iostream>
#include <format>
#include <memory>
#include <string>
#include "colors.hpp"

namespace AbstractFactory
{

// Product Interface
class IWeapon {
protected:
    std::string name_;
    int power_;
public:
    const std::string& name()  const { return name_; }
    int                power() const { return power_; }

    IWeapon(std::string name, int power) : name_(std::move(name)), power_(power) {}
    virtual ~IWeapon() = default;
    virtual std::string attack() const = 0;
};

class IArmor {
protected:
    std::string name_;
    int life_;
public:
    const std::string& name()  const { return name_; }
    int                life() const { return life_; }

    IArmor(std::string name, int maxLife) : name_(std::move(name)), life_(maxLife) {}
    virtual ~IArmor() = default;
    virtual std::string defend(std::string weaponName, int weaponPowerLevel) = 0;
};

// Concrete Products
class Spear : public IWeapon {
public:
    explicit Spear(std::string name, int powerLevel) : IWeapon(std::move(name), powerLevel) {}
    std::string attack() const override;
};

class Club : public IWeapon {
public:
    explicit Club(std::string name, int powerLevel) : IWeapon(std::move(name), powerLevel) {}
    std::string attack() const override;
};

class HideArmor : public IArmor {
public:
    explicit HideArmor(std::string name, int maxLife) : IArmor(std::move(name), maxLife) {}
    std::string defend(std::string weaponName, int weaponPowerLevel) override;
};

class CrossBow : public IWeapon {
public:
    explicit CrossBow(std::string name, int powerLevel) : IWeapon(std::move(name), powerLevel) {}
    std::string attack() const override;
};

class Sword : public IWeapon {
public:
    explicit Sword(std::string name, int powerLevel) : IWeapon(std::move(name), powerLevel) {}
    std::string attack() const override;
};

class ChainMailArmor : public IArmor {
public:
    explicit ChainMailArmor(std::string name, int maxLife) : IArmor(std::move(name), maxLife) {}
    std::string defend(std::string weaponName, int weaponPowerLevel) override;
};

class Rifle : public IWeapon {
public:
    explicit Rifle(std::string name, int powerLevel) : IWeapon(std::move(name), powerLevel) {}
    std::string attack() const override;
};

class Knife : public IWeapon {
public:
    explicit Knife(std::string name, int powerLevel) : IWeapon(std::move(name), powerLevel) {}
    std::string attack() const override;
};

class BulletProofArmor : public IArmor {
public:
    explicit BulletProofArmor(std::string name, int maxLife) : IArmor(std::move(name), maxLife) {}
    std::string defend(std::string weaponName, int weaponPowerLevel) override;
};

// ---

// Factory Interface / Creator Interface
class IArmory {
public:
    virtual ~IArmory() = default;
    virtual std::unique_ptr<IWeapon> createRangedWeapon(std::string name, int powerLevel) const = 0;
    virtual std::unique_ptr<IWeapon> createMeleeWeapon(std::string name, int powerLevel) const = 0;
    virtual std::unique_ptr<IArmor> createArmor(std::string name, int maxLife) const = 0;
};

// Concrete Factories / Concrete Creators
class StoneAgeArmory : public IArmory {
public:
    std::unique_ptr<IWeapon> createRangedWeapon(std::string name, int powerLevel) const override;
    std::unique_ptr<IWeapon> createMeleeWeapon(std::string name, int powerLevel) const override;
    std::unique_ptr<IArmor> createArmor(std::string name, int maxLife) const override;
};

class MedievalArmory : public IArmory {
public:
    std::unique_ptr<IWeapon> createRangedWeapon(std::string name, int powerLevel) const override;
    std::unique_ptr<IWeapon> createMeleeWeapon(std::string name, int powerLevel) const override;
    std::unique_ptr<IArmor> createArmor(std::string name, int maxLife) const override;
};

class ModernArmory : public IArmory {
public:
    std::unique_ptr<IWeapon> createRangedWeapon(std::string name, int powerLevel) const override;
    std::unique_ptr<IWeapon> createMeleeWeapon(std::string name, int powerLevel) const override;
    std::unique_ptr<IArmor> createArmor(std::string name, int maxLife) const override;
};

// ---

// Client Code
void clientCode(const IArmory &armory, std::string rangedName, int rangedPower, std::string meleeName, int meleePower, std::string armorName, int maxLifeArmor);

} // end namespace *AbstractFactory*
