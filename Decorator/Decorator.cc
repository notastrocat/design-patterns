#include <iostream>
#include "Decorator.hpp"

namespace Decorator
{

std::string Tea::getDescription() const {
    return "tea";
}

float Tea::getCost() const {
    return 2.0;
}

std::string DeCaf::getDescription() const {
    return "decaf";
}

float DeCaf::getCost() const {
    return 1.5;
}

std::string Espresso::getDescription() const {
    return "espresso";
}

float Espresso::getCost() const {
    return 1.0;
}

std::string WhippedCream::getDescription() const {
    return this->bev->getDescription() + " + whipped cream";
}

float WhippedCream::getCost() const {
    return this->bev->getCost() + 2.5;
}

std::string Caramel::getDescription() const {
    return this->bev->getDescription() + " + caramel";
}

float Caramel::getCost() const {
    return this->bev->getCost() + 3.0;
}

std::string AlmondMilk::getDescription() const {
    return this->bev->getDescription() + " + almond milk";
}

float AlmondMilk::getCost() const {
    return this->bev->getCost() + 2.5;
}

std::string OatMilk::getDescription() const {
    return this->bev->getDescription() + " + oat milk";
}

float OatMilk::getCost() const {
    return this->bev->getCost() + 2.0;
}

std::string FullCream::getDescription() const {
    return this->bev->getDescription() + " + full cream";
}

float FullCream::getCost() const {
    return this->bev->getCost() + 1.0;
}

std::string HalfNHalf::getDescription() const {
    return this->bev->getDescription() + " + half n half";
}

float HalfNHalf::getCost() const {
    return this->bev->getCost() + 1.5;
}

std::string Matcha::getDescription() const {
    return this->bev->getDescription() + " + matcha";
}

float Matcha::getCost() const {
    return this->bev->getCost() + 3.0;
}

std::string Cardamom::getDescription() const {
    return this->bev->getDescription() + " + cardamom";
}

float Cardamom::getCost() const {
    return this->bev->getCost() + 3.5;
}

std::string EarlGrey::getDescription() const {
    return this->bev->getDescription() + " + earl grey";
}

float EarlGrey::getCost() const {
    return this->bev->getCost() + 3.0;
}

void generateMenu() {
    // Espresso-based coffees
    auto espresso_whipped = std::make_unique<WhippedCream>(
        std::make_unique<Espresso>()
    );
    
    auto espresso_caramel_oat = std::make_unique<OatMilk>(
        std::make_unique<Caramel>(
            std::make_unique<Espresso>()
        )
    );

    // Decaf-based coffees
    auto decaf_almond = std::make_unique<AlmondMilk>(
        std::make_unique<DeCaf>()
    );

    auto decaf_caramel_cream = std::make_unique<FullCream>(
        std::make_unique<Caramel>(
            std::make_unique<DeCaf>()
        )
    );

    // Tea-based beverages
    auto tea_earl_grey = std::make_unique<EarlGrey>(
        std::make_unique<Tea>()
    );

    auto tea_matcha_almond = std::make_unique<AlmondMilk>(
        std::make_unique<Matcha>(
            std::make_unique<Tea>()
        )
    );

    // Herbal teas
    auto herbal_cardamom = std::make_unique<Cardamom>(
        std::make_unique<Tea>()
    );

    auto herbal_cardamom_halfnhalf = std::make_unique<HalfNHalf>(
        std::make_unique<Cardamom>(
            std::make_unique<Tea>()
        )
    );

    // Print all
    
    std::cout << "espresso-whipped: ";
    std::cout << espresso_whipped->getDescription() << " = $" << espresso_whipped->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "espresso-caramel-oat: ";
    std::cout << espresso_caramel_oat->getDescription() << " = $" << espresso_caramel_oat->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "decaf-almond: ";
    std::cout << decaf_almond->getDescription() << " = $" << decaf_almond->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "decaf-caramel-cream: ";
    std::cout << decaf_caramel_cream->getDescription() << " = $" << decaf_caramel_cream->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "tea-earl-grey: ";
    std::cout << tea_earl_grey->getDescription() << " = $" << tea_earl_grey->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "tea-matcha-almond: ";
    std::cout << tea_matcha_almond->getDescription() << " = $" << tea_matcha_almond->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "herbal-cardamom: ";
    std::cout << herbal_cardamom->getDescription() << " = $" << herbal_cardamom->getCost() << std::endl;
    std::cout << std::endl;
    
    std::cout << "herbal-cardamom-halfnhalf: ";
    std::cout << herbal_cardamom_halfnhalf->getDescription() << " = $" << herbal_cardamom_halfnhalf->getCost() << std::endl;
    std::cout << std::endl;
}

} // end namespace Decorator
