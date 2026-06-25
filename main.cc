#include <iostream>
#include <memory>
#include <format>
#include <fstream>

#include "Decorator/Decorator.hpp"
#include "Strategy/Strategy.hpp"
#include "Observer/Observer.hpp"
#include "Factory/Factory.hpp"
#include "AbstractFactory/AbstractFactory.hpp"
#include "Adapter/Adapter.hpp"

#include "nlohmann/json.hpp"
#include "colors.hpp"

using json = nlohmann::json;

int main(int argc, char* argv[]) {
    // std::cout << std::format("\033[35mDesign Patterns in C++20\033[0m\n");

    bool b_JsonConfig = false;
    if (argc < 2) {
        std::cout << colors::foreground::green << std::format("Running tests for everything: -\n") << colors::reset_all;
    } else {
        b_JsonConfig = true;
    }

    // std::cout << argv[1] << std::format("\n");
    bool b_DEBUG = false;
 
    if (!b_JsonConfig)
    {
        std::cout << colors::foreground::magenta << std::format("Running tests for Decorator Pattern: -\n") << colors::reset_all;
        Decorator::generateMenu();
        Strategy::clientCode();
        Observer::clientCode();

        std::cout << std::endl;
        FactoryMethod::SpearMaker spearFactory;
        FactoryMethod::ClubMaker clubFactory;

        FactoryMethod::clientCode(spearFactory, "LongTooth", 25);
        FactoryMethod::clientCode(clubFactory, "HeavyLog", 10);

        std::cout << std::endl;
        AbstractFactory::clientCode(AbstractFactory::StoneAgeArmory{}, "Spear", 25, "Club", 10, "Hide Armor", 15);
        AbstractFactory::clientCode(AbstractFactory::MedievalArmory{}, "CrossBow", 105, "Sword", 85, "Chain Mail Armor", 150);
        AbstractFactory::clientCode(AbstractFactory::ModernArmory{}, "Rifle", 125, "Knife", 120, "Bullet Proof Armor", 95);

        std::cout<<std::endl;
        Adapter::clientCode();
    }
    else
    {
        try
        {
            std::ifstream f(argv[1]);
            json j = json::parse(f);
            j.value("debug", false) ? b_DEBUG = true : b_DEBUG = false;

            if (b_DEBUG) {
                std::cout << std::format("JSON file loaded successfully: -\n{}\n", j.dump(4));
            }

            if (j.value("decorator", false)) {
                std::cout << colors::foreground::magenta << std::format("Running tests for Decorator Pattern: -\n") << colors::reset_all;
                Decorator::generateMenu();
            }

            if (j.value("strategy", false)) {
                std::cout << colors::foreground::magenta << std::format("Running tests for Strategy Pattern: -\n") << colors::reset_all;
                Strategy::clientCode();
                std::cout << std::endl;
            }

            if (j.value("observer", false)) {
                std::cout << colors::foreground::magenta << std::format("Running tests for Observer Pattern: -\n") << colors::reset_all;
                Observer::clientCode();
                // std::cout << std::endl;
            }

            if (j.value("factory", false)) {
                std::cout << std::endl;
                std::cout << colors::foreground::magenta << std::format("Running tests for FactoryMethod Pattern: -\n") << colors::reset_all;
                FactoryMethod::SpearMaker spearFactory;
                FactoryMethod::ClubMaker clubFactory;

                FactoryMethod::clientCode(spearFactory, "LongTooth", 25);
                FactoryMethod::clientCode(clubFactory, "HeavyLog", 10);
            }

            if (j.value("abstractFactory", false)) {
                std::cout << std::endl;
                std::cout << colors::foreground::magenta << std::format("Running tests for AbstractFactoryMethod Pattern: -\n") << colors::reset_all;
                AbstractFactory::clientCode(AbstractFactory::StoneAgeArmory{}, "Spear", 25, "Club", 10, "Hide Armor", 15);
                AbstractFactory::clientCode(AbstractFactory::MedievalArmory{}, "CrossBow", 105, "Sword", 85, "Chain Mail Armor", 150);
                AbstractFactory::clientCode(AbstractFactory::ModernArmory{}, "Rifle", 125, "Knife", 120, "Bullet Proof Armor", 95);
            }

            if (j.value("adapter", false)) {
                std::cout<<std::endl;
                std::cout << colors::foreground::magenta << std::format("Running tests for Adapter Pattern: -\n") << colors::reset_all;
                Adapter::clientCode();
            }
        }
        catch (const nlohmann::json::parse_error& e)
        {
            std::cerr << std::format("JSON parsing error: {}\n", e.what());
            return 1;
        }
    }

    return 0;
}