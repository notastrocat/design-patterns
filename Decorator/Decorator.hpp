#include <string>
#include <memory>

namespace Decorator {

void generateMenu();

// Base class
class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual float getCost() const = 0;
};

// ---

// Derived classes
class Tea : public Beverage {
public:
    std::string getDescription() const override;
    float getCost() const override;
};

class DeCaf : public Beverage {
public:
    std::string getDescription() const override;
    float getCost() const override;
};

class Espresso : public Beverage {
public:
    std::string getDescription() const override;
    float getCost() const override;
};

// ---

// Wrapper Interface - *Decorator*
class IAddOnDecorator : public Beverage {
protected:
    std::unique_ptr<Beverage> bev;

public:
    explicit IAddOnDecorator(std::unique_ptr<Beverage> beverage) 
        : bev(std::move(beverage)) {}
    virtual ~IAddOnDecorator() = default;
};

// Concrete Implementations of the Wrapper Interface - *AddOn Decorators*
class WhippedCream : public IAddOnDecorator {
public:
    explicit WhippedCream(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class Caramel : public IAddOnDecorator {
public:
    explicit Caramel(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class AlmondMilk : public IAddOnDecorator {
public:
    explicit AlmondMilk(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class OatMilk : public IAddOnDecorator {
public:
    explicit OatMilk(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class FullCream : public IAddOnDecorator {
public:
    explicit FullCream(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class HalfNHalf : public IAddOnDecorator {
public:
    explicit HalfNHalf(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class Matcha : public IAddOnDecorator {
public:
    explicit Matcha(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class Cardamom : public IAddOnDecorator {
public:
    explicit Cardamom(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

class EarlGrey : public IAddOnDecorator {
public:
    explicit EarlGrey(std::unique_ptr<Beverage> beverage) : IAddOnDecorator(std::move(beverage)) {}
    std::string getDescription() const override;
    float getCost() const override;
};

} // end namespace Decorator
