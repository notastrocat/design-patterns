#include "Adapter.hpp"

namespace Adapter
{

int SquarePeg::getWidth() const {
    return this->width_;
}

int RoundPeg::getRadius() const {
    return this->radius_;
}

int RoundHole::getRadius() const {
    return this->radius_;
}

bool RoundHole::fits(const RoundPeg &peg) const {
    return getRadius() >= peg.getRadius();
}

RoundPeg SquarePegAdapter::getRadius() const {
    if (!peg_) {
        throw std::runtime_error("Adaptee pointer is null!");
    }

    // Apply the formula: width * sqrt(2) / 2
    int convertedRadius = static_cast<int>(peg_->getWidth() * std::sqrt(2) / 2);
    return RoundPeg(convertedRadius);
}

void clientCode() {
    RoundHole hole(5);
    std::cout << colors::foreground::blue << "Created RoundHole with radius 5.\n\n" << colors::reset_all;

    RoundPeg normalPeg(5);
    std::cout << colors::foreground::light_blue << "Does a standard RoundPeg (radius 5) fit? "
              << (hole.fits(normalPeg) ? colors::foreground::green + "Yes!" : colors::foreground::light_red + "No.")
              << "\n" + colors::reset_all;

    std::unique_ptr<SquarePeg> smallSqPeg = std::make_unique<SquarePeg>(5);
    std::unique_ptr<SquarePeg> largeSqPeg = std::make_unique<SquarePeg>(10);

    SquarePegAdapter smallAdapter(std::move(smallSqPeg));
    SquarePegAdapter largeAdapter(std::move(largeSqPeg));

    std::cout << colors::foreground::light_blue << "Does a SquarePeg (width 5) fit? "
              << (hole.fits(smallAdapter.getRadius()) ?
                    colors::foreground::green + "Yes!" : colors::foreground::light_red + "No.")
              << "\n" + colors::reset_all;
              
    std::cout << colors::foreground::light_blue << "Does a SquarePeg (width 10) fit? "
              << (hole.fits(largeAdapter.getRadius()) ?
                    colors::foreground::green + "Yes!" : colors::foreground::light_red + "No.")
              << "\n" + colors::reset_all;
}

} // namespace Adapter
