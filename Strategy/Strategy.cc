#include "Strategy.hpp"

namespace Strategy
{

void clientCode() {
    CaveMan caveMan(nullptr);
    std::cout << "Client: Weapon is set to \"fist\" (default).\n";
    caveMan.attack();

    std::cout << "\n";

    caveMan.setWeapon(std::make_unique<Sword>());
    std::cout << "Client: Weapon is set to \"sword\".\n";
    caveMan.attack();

    std::cout << "\n";

    std::cout << "Client: Weapon is set to \"club\".\n";
    caveMan.setWeapon(std::make_unique<Club>());
    caveMan.attack();
}

} // end namespace *Strategy*
