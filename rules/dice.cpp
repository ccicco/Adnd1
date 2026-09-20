// ============================================================================
// Adnd1 — rules/dice.cpp
// ============================================================================

#include "dice.h"

#include <algorithm>
#include <vector>

namespace rules {

// ----------------------------------------------------------------------------
// Rng
// ----------------------------------------------------------------------------

Rng::Rng(uint64_t seed) { Rng::seed(seed); }

void Rng::seed(uint64_t s) {
    // avoid the all-zero fixed point; any nonzero constant works
    m_state = (s == 0) ? 0x9E3779B97F4A7C15ull : s;
}

uint64_t Rng::state() const { return m_state; }

uint64_t Rng::nextU64() {
    // xorshift64*
    m_state ^= m_state >> 12;
    m_state ^= m_state << 25;
    m_state ^= m_state >> 27;
    return m_state * 0x2545F4914F6CDD1Dull;
}

uint32_t Rng::below(uint32_t n) {
    if (n <= 1) return 0;
    // rejection sampling keeps the distribution uniform
    uint64_t limit = UINT64_MAX - (UINT64_MAX % n);
    uint64_t v;
    do { v = nextU64(); } while (v >= limit);
    return (uint32_t)(v % n);
}

uint32_t Rng::range(uint32_t lo, uint32_t hi) {
    if (hi <= lo) return lo;
    return lo + below(hi - lo + 1);
}

// ----------------------------------------------------------------------------
// Dice
// ----------------------------------------------------------------------------

uint32_t Dice::d(uint32_t sides) {
    if (sides < 2) return sides;   // d1 stays 1, d0 stays 0 (defensive)
    return m_rng.below(sides) + 1;
}

int32_t Dice::roll(uint32_t count, uint32_t sides, int32_t bonus) {
    int32_t total = bonus;
    for (uint32_t i = 0; i < count; ++i) total += (int32_t)d(sides);
    return total;
}

int32_t Dice::bestOf(uint32_t count, uint32_t sides, uint32_t keep) {
    if (keep == 0 || count == 0) return 0;
    if (keep >= count) return roll(count, sides, 0);
    std::vector<int32_t> rolls;
    rolls.reserve(count);
    for (uint32_t i = 0; i < count; ++i) rolls.push_back((int32_t)d(sides));
    std::sort(rolls.begin(), rolls.end(), std::greater<int32_t>());
    int32_t total = 0;
    for (uint32_t i = 0; i < keep; ++i) total += rolls[i];
    return total;
}

} // namespace rules