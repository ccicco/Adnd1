// ============================================================================
// Adnd1 — rules/dice.h
// Dice for AD&D 1st Edition: d4, d6, d8, d10, d12, d20, d100.
//
// All randomness flows through a seeded, deterministic Rng. The same seed
// produces the same sequence everywhere (sim harness, gym, game) so batch
// runs are reproducible. No global rand() — every roll is explicit.
// ============================================================================

#pragma once

#include <cstdint>
#include <string>

namespace rules {

// ----------------------------------------------------------------------------
// Deterministic RNG — xorshift64*. Simple, fast, fully reproducible across
// platforms, good enough for dice. Seed 0 is remapped internally.
// ----------------------------------------------------------------------------
class Rng {
public:
    explicit Rng(uint64_t seed = 1);

    void     seed(uint64_t s);      // restart the sequence
    uint64_t state() const;         // for save/load of run determinism

    uint64_t nextU64();             // raw engine step
    uint32_t below(uint32_t n);     // uniform in [0, n)
    uint32_t range(uint32_t lo, uint32_t hi); // uniform in [lo, hi]

private:
    uint64_t m_state;
};

// ----------------------------------------------------------------------------
// Dice
// ----------------------------------------------------------------------------
class Dice {
public:
    explicit Dice(Rng& rng) : m_rng(rng) {}

    // single die: 4, 6, 8, 10, 12, 20, 100
    uint32_t d(uint32_t sides);

    // classic rolls
    uint32_t d4()  { return d(4); }
    uint32_t d6()  { return d(6); }
    uint32_t d8()  { return d(8); }
    uint32_t d10() { return d(10); }
    uint32_t d12() { return d(12); }
    uint32_t d20() { return d(20); }
    uint32_t d100(){ return d(100); }   // percentile pair modeled as one die

    // multiple dice with flat bonus, e.g. roll(3, 6, 0) = 3d6, roll(2, 8, 1)
    // = 2d8+1. Count may be 0 (bonus only). Sides may be 1 for fixed adds.
    int32_t roll(uint32_t count, uint32_t sides, int32_t bonus = 0);

    // best-of-N ability rolls, e.g. 4d6 drop lowest: bestOf(4, 6, 3)
    int32_t bestOf(uint32_t count, uint32_t sides, uint32_t keep);

private:
    Rng& m_rng;
};

} // namespace rule

