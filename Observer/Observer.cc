#include "Observer.hpp"

namespace Observer
{

bool LookOut::registerForWarning(TribalMember* o) {
    if (o) {
        observers_.push_back(o);
        return true;
    }

    return false;
}

bool LookOut::deRegisterForWarning(TribalMember* o) {
    auto it = std::find(observers_.begin(), observers_.end(), o);
    if (it != observers_.end()) {
        observers_.erase(it);
        return true;
    }

    return false;
}

void LookOut::setSignal(const std::string& signal) {
    signal_ = signal;
    notifyAll();
}

void LookOut::notifyAll() {
    for (auto* observer : observers_) {
        if (observer) {
            observer->update(signal_);
        }
    }
}

Hunter::Hunter(ILookOut* lookOut, std::string name)
    : name_(std::move(name)), lookOut_(lookOut) {}

Hunter::~Hunter() {
    leaveTribe();
}

void Hunter::update(const std::string& signal) {
    std::cout << colors::foreground::blue << "Hunter " << name_ << " grab spear! Signal: " << signal << '\n';
}

void Hunter::joinTribe() {
    if (lookOut_) {
        if ( true == lookOut_->registerForWarning(this) )
        {
            std::cout << colors::foreground::blue << "Hunter " << name_ << " joined tribe!\n";
        }
    }
}

void Hunter::leaveTribe() {
    if (lookOut_) {
        if ( lookOut_->deRegisterForWarning(this) )
        {
            std::cout << colors::foreground::blue << "Hunter " << name_ << " left tribe!\n";
        }
    }
}

Gatherer::Gatherer(ILookOut* lookOut, std::string name)
    : name_(std::move(name)), lookOut_(lookOut) {}

Gatherer::~Gatherer() {
    leaveTribe();
}

void Gatherer::update(const std::string& signal) {
    std::cout << colors::foreground::light_magenta << "Gatherer " << name_ << " hide in bush! Signal: " << signal << '\n';
}

void Gatherer::joinTribe() {
    if (lookOut_) {
        if (true == lookOut_->registerForWarning(this) )
        {
            std::cout << colors::foreground::light_magenta << "Gatherer " << name_ << " joined tribe!\n";
        }
    }
}

void Gatherer::leaveTribe() {
    if (lookOut_) {
        if ( true == lookOut_->deRegisterForWarning(this) )
        {
            std::cout << colors::foreground::light_magenta << "Gatherer " << name_ << " left tribe!\n";
        }
    }
}

void clientCode() {
    LookOut lookOut;

    Hunter grog(&lookOut, "Grog");
    Hunter bogo(&lookOut, "Bogo");
    Gatherer oola(&lookOut, "Oola");

    grog.joinTribe();
    bogo.joinTribe();
    oola.joinTribe();

    std::cout << std::endl;

    lookOut.setSignal("Mammoth!");

    std::cout << std::endl;

    bogo.leaveTribe();

    std::cout << std::endl;

    lookOut.setSignal("Sabre-tooth Tiger!");

    std::cout << std::endl;
}

}  // end namespace *Observer*