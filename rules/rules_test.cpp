// ============================================================================
// Adnd1 — rules/rules_test.cpp
// Minimal self-contained test harness. Every rules/ domain adds CHECKs here.
//
// Build & run (MinGW or Linux):
//   g++ -std=c++17 -I. rules/dice.cpp rules/rules_test.cpp -o rules_test
//   ./rules_test
//
// Exit code 0 = all checks passed. No external test framework: the harness is
// a single CHECK macro plus a pass/fail summary, so it builds anywhere the
// game builds.
// ============================================================================

#include "../rules/dice.h"

#include <cstdio>
#include <cstring>

static int g_checks = 0;
static int g_failures = 0;

#define CHECK(cond) do {                                              \
    ++g_checks;                                                       \
    if (!(cond)) {                                                    \
        ++g_failures;                                                 \
        std::printf("FAIL %s:%d  %s\n", __FILE__, __LINE__, #cond);   \
    }                                                                 \
} while (0)

int main() {
    using namespace rules;

    // ---- determinism: same seed, same sequence -----------------------------
    {
        Rng a(42), b(42);
        Dice da(a), db(b);
        bool same = true;
        for (int i = 0; i < 1000; ++i)
            if (da.d20() != db.d20()) { same = false; break; }
        CHECK(same);
    }
    // different seeds diverge (practically certain within 1000 rolls)
    {
        Rng a(42), b(43);
        Dice da(a), db(b);
        bool diverged = false;
        for (int i = 0; i < 1000; ++i)
            if (da.d20() != db.d20()) { diverged = true; break; }
        CHECK(diverged);
    }

    // ---- ranges -------------------------------------------------------------
    {
        Rng r(7); Dice d(r);
        bool ok = true;
        for (int i = 0; i < 10000; ++i) {
            uint32_t v = d.d20();
            if (v < 1 || v > 20) { ok = false; break; }
        }
        CHECK(ok);
    }
    {
        Rng r(7); Dice d(r);
        bool ok = true;
        for (int i = 0; i < 10000; ++i) {
            uint32_t v = d.d100();
            if (v < 1 || v > 100) { ok = false; break; }
        }
        CHECK(ok);
    }

    // ---- roll(count, sides, bonus) -----------------------------------------
    {
        Rng r(9); Dice d(r);
        int32_t v = d.roll(3, 6, 0);           // 3d6
        CHECK(v >= 3 && v <= 18);
        v = d.roll(2, 8, 1);                   // 2d8+1
        CHECK(v >= 3 && v <= 17);
        v = d.roll(0, 6, 5);                   // flat bonus only
        CHECK(v == 5);
        v = d.roll(1, 1, 0);                   // fixed die
        CHECK(v == 1);
    }

    // ---- bestOf: 4d6 drop lowest -------------------------------------------
    {
        Rng r(11); Dice d(r);
        bool ok = true;
        for (int i = 0; i < 10000; ++i) {
            int32_t v = d.bestOf(4, 6, 3);
            if (v < 3 || v > 18) { ok = false; break; }
        }
        CHECK(ok);
    }
    // bestOf with keep >= count equals a plain roll's bounds
    {
        Rng r(13); Dice d(r);
        int32_t v = d.bestOf(3, 6, 5);         // degenerates to 3d6
        CHECK(v >= 3 && v <= 18);
        CHECK(d.bestOf(4, 6, 0) == 0);
        CHECK(d.bestOf(0, 6, 3) == 0);
    }

    // ---- range()/below() edge cases ----------------------------------------
    {
        Rng r(1);
        CHECK(r.below(1) == 0);
        CHECK(r.range(5, 5) == 5);
        CHECK(r.range(2, 3) == 2 || r.range(2, 3) == 3);
        uint32_t v = r.range(1, 100);
        CHECK(v >= 1 && v <= 100);
    }

    // ---- uniformity smoke test: d20 faces all appear -----------------------
    {
        Rng r(2024); Dice d(r);
        bool seen[21] = {};
        for (int i = 0; i < 20000; ++i) seen[d.d20()] = true;
        bool all = true;
        for (int f = 1; f <= 20; ++f) if (!seen[f]) { all = false; break; }
        CHECK(all);
    }

    std::printf("%d checks, %d failures\n", g_checks, g_failures);
    return g_failures == 0 ? 0 : 1;
}