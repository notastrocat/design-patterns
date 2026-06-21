#include <iostream>
#include <memory>
#include "colors.hpp"

namespace Strategy
{

// IBehavior
class WeaponBehavior {
public:
    virtual ~WeaponBehavior() = default;
    virtual void useWeapon() const = 0;
};

// ---

// ConcreteBehaviors
class Sword : public WeaponBehavior {
public:
    void useWeapon() const override {
        std::cout << colors::foreground::light_blue << "Slash! Sharp blade cut!\n" << colors::reset_all;
    }
};

class Club : public WeaponBehavior {
public:
    void useWeapon() const override {
        std::cout << colors::foreground::cyan << "Smash! Heavy wood crush!\n" << colors::reset_all;
    }
};

// ---

// Context
class CaveMan {
private:
    std::unique_ptr<WeaponBehavior> weapon_;

public:
    explicit CaveMan(std::unique_ptr<WeaponBehavior> weapon = {}) : weapon_(std::move(weapon)) {}

    void setWeapon(std::unique_ptr<WeaponBehavior> weapon) {
        weapon_ = std::move(weapon);
    }

    void attack() {
        if (!weapon_) {
            std::cout << colors::foreground::blue << "Punch with fist!\n" << colors::reset_all;
            return;
        }

        this->weapon_->useWeapon();
    }
};

void clientCode();

} // end namespace *Strategy*