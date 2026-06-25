#include <format>
#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <stdexcept>
#include "colors.hpp"

namespace Adapter
{

// The two incompatible classes
class RoundPeg {
private:
    int radius_;
public:
    explicit RoundPeg(int radius) : radius_(radius) {}
    int      getRadius() const;
};

class SquarePeg {
private:
    int width_;
public:
    explicit SquarePeg(int width) : width_(width) {}
    int      getWidth() const;
};


class RoundHole {
private:
    int                       radius_;
public:
    explicit RoundHole(int radius) : radius_(radius) {}
    int      getRadius()         const;
    bool     fits(const RoundPeg &peg) const;
};

class SquarePegAdapter {
private:
    std::unique_ptr<SquarePeg> peg_;  // this is our adaptee
public:
    explicit SquarePegAdapter(std::unique_ptr<SquarePeg> peg = {}) : peg_(std::move(peg)) {}

    /**
     * Since we've chosen not to go the "inheritance" path and instead go "composition/association" path
     * we could've named this func absolutely anything. Right? Because there's no restriction.
     * In fact, one benefit of using "inheritance" path would've been that this function remains same across the adaptor and adaptee.
     * But, keeping the name same makes sense, at least to me, so that the call sites remains consistent.
     */
    RoundPeg getRadius() const;
};

void clientCode();

} // namespace Adapter
