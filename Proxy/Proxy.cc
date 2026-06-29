#include "Proxy.hpp"

namespace Proxy
{

std::string TribalMember::getName() const {
    return this->name_;
}

int TribalMember::getRank() const {
    return this->rank_;
}

std::string SacredCave::getEnchanted(std::unique_ptr<TribalMember> member) {
    return colors::italics + colors::background::green + colors::foreground::white +
        std::format("you've been enchanted, {}", member->getName()) + colors::reset_all;
}

bool Guard::checkEligibility(const int &rank) {
    return (rank > 3) ? true : false;
}

void Guard::moveBoulder() {
    using namespace std::chrono_literals;

    std::cout << colors::foreground::light_blue << "moving the boulder... this may take a while." << colors::reset_all << std::endl;
    std::this_thread::sleep_for(5s);
}

std::string Guard::getEnchanted(std::unique_ptr<TribalMember> member) {
    if (checkEligibility(member->getRank())) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = now - this->lastBoulderMoveTime_;
        if ( elapsed > std::chrono::milliseconds(10000) ) {
            this->lastBoulderMoveTime_ = std::chrono::steady_clock::now();
            moveBoulder();
        }
    } else {
        return colors::bold + colors::background::light_red + colors::foreground::white +
            std::format("you're not eligible to get enchanted yet, {}", member->getName()) +
            colors::reset_all; 
    }

    std::string res = this->realCave_->getEnchanted(std::move(member));

    return res;
}

void clientCode() {
    std::string name = "Shrek";
    int rank = 6;
    std::unique_ptr<TribalMember> shrek = std::make_unique<TribalMember>(name, rank);

    name = "Fiona";
    rank = 6;
    std::unique_ptr<TribalMember> fiona = std::make_unique<TribalMember>(name, rank);

    name = "Donkey";
    rank = 2;
    std::unique_ptr<TribalMember> donkey = std::make_unique<TribalMember>(name, rank);

    name = "Fred Flintstone";
    rank = 4;
    std::unique_ptr<TribalMember> fred = std::make_unique<TribalMember>(name, rank);

    // std::unique_ptr<SacredCave> sacredCave;
    Guard caveGuard;

    std::string res;
    res = caveGuard.getEnchanted(std::move(shrek));
    std::cout << res << std::endl;
    res = caveGuard.getEnchanted(std::move(fiona));
    std::cout << res << std::endl;
    res = caveGuard.getEnchanted(std::move(donkey));
    std::cout << res << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    name = "Donkey";
    rank = 2;
    donkey = std::make_unique<TribalMember>(name, rank);
    res = caveGuard.getEnchanted(std::move(donkey));
    std::cout << res << std::endl;
    res = caveGuard.getEnchanted(std::move(fred));
    std::cout << res << std::endl;
}

} // namespace Proxy
