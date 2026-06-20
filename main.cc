#include <iostream>
#include <memory>
#include <format>
#include <fstream>
#include "Decorator/Decorator.hpp"
#include "Strategy/Strategy.hpp"
#include "nlohmann/json.hpp"
#include "common.hpp"

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
    }
    else
    {
        try
        {
            std::ifstream f(argv[1]);
            json j = json::parse(f);
            j.value("debug", false) ? b_DEBUG = true : b_DEBUG = false;

            if (b_DEBUG) {
                std::cout << std::format("JSON file loaded successfully: {}\n", j.dump(4));
            }

            if (j.value("decorator", false)) {
                std::cout << colors::foreground::magenta << std::format("Running tests for Decorator Pattern: -\n") << colors::reset_all;
                Decorator::generateMenu();
            }

            if (j.value("decorator", false)) {
                std::cout << colors::foreground::magenta << std::format("Running tests for Decorator Pattern: -\n") << colors::reset_all;
                Strategy::clientCode();
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