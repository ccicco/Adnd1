// ============================================================================
// Adnd1 — treasuresim.cpp (repo root, sibling of regtest.cpp)
// R73: statistical audit of dm::treasure::rollTreasureType() against the
// MM p.105 table (Curtiss-verified). Rolls every letter A-Z N times and
// prints observed percentages/averages for eyeball comparison with the
// printed table, plus hard consistency checks that fail loudly.
//
// Build (Termux, from the repo root):
//   clang++ -std=c++17 -I. treasuresim.cpp dm/treasure.cpp rules/dice.cpp \
//       -o /tmp/treasuresim && /tmp/treasuresim
//
// The r71verify.sh regtest gate is unaffected (this is a separate binary).
// ============================================================================

#include "dm/treasure.h"
#include "rules/dice.h"

#include <cstdio>
#include <cstdlib>

static const int N = 50000;   // rolls per letter

struct Stat {
    long long anyPct[5] = {0,0,0,0,0};   // % of hoards with cp/sp/ep/gp/pp
    long long total[5]   = {0,0,0,0,0};  // total coins of each type
    int  gemHoards = 0,  gemPieces = 0;
    int  jewelHoards = 0, jewelPieces = 0;
    int  magicHoards = 0, magicItems = 0;
    long long value = 0;
    long long maxValue = 0;
    long long minValue = -1;
};

static void fail(const char* why) {
    printf("FAIL: %s\n", why);
    exit(1);
}

int main() {
    printf("R73 treasure drop-rate audit — %d rolls per letter\n\n", N);
    printf("%-6s %6s %7s %7s %7s %7s %7s %8s\n",
           "letter", "%gems", "%jewel", "%magic",
           "avg gp", "avg val", "max val", "hoards");

    for (char L = 'A'; L <= 'Z'; ++L) {
        rules::Rng rng(1);
        rules::Dice dice(rng);
        Stat s;
        long long hoards = 0;

        for (int i = 0; i < N; ++i) {
            dm::treasure::Hoard h =
                dm::treasure::rollTreasureType(dice, L);

            // hard consistency checks
            if (h.cp < 0 || h.sp < 0 || h.ep < 0 || h.gp < 0 || h.pp < 0)
                fail("negative coin field");
            if (h.gemValue < 0 || h.jewelryValue < 0)
                fail("negative gem/jewelry value");
            long long each = 0;
            if (h.gemCount > 0)
                each = h.gemValue / h.gemCount;
            if (each > 1000000) fail("gem value above book cap");
            each = 0;
            if (h.jewelryCount > 0)
                each = h.jewelryValue / h.jewelryCount;
            if (each > 640000) fail("jewelry value above book cap");

            ++hoards;
            long long cp[] = { h.cp, h.sp, h.ep, h.gp, h.pp };
            for (int c = 0; c < 5; ++c) {
                if (cp[c] > 0) ++s.anyPct[c];
                s.total[c] += cp[c];
            }
            if (h.gemCount > 0) { ++s.gemHoards; s.gemPieces += h.gemCount; }
            if (h.jewelryCount > 0) {
                ++s.jewelHoards; s.jewelPieces += h.jewelryCount;
            }
            if (!h.magic.empty()) {
                ++s.magicHoards;
                s.magicItems += (int)h.magic.size();
            }
            long long v = h.goldValue();
            s.value += v;
            if (v > s.maxValue) s.maxValue = v;
            if (s.minValue < 0 || v < s.minValue) s.minValue = v;
        }

        printf("%-6c %5.1f%% %6.1f%% %6.1f%% %8.0f %9.0f %9lld %8lld\n",
            L,
            100.0 * s.gemHoards / N,
            100.0 * s.jewelHoards / N,
            100.0 * s.magicHoards / N,
            (double)s.total[3] / N,             // avg gp per roll
            (double)s.value / N,                // avg total value per roll
            s.maxValue,
            hoards);
        fflush(stdout);
    }

    // ---- determinism: same seed must reproduce the same totals ----------
    for (char L : { 'H', 'M', 'V' }) {
        long long totals[2] = {0,0};
        for (int pass = 0; pass < 2; ++pass) {
            rules::Rng rng(42);
            rules::Dice dice(rng);
            for (int i = 0; i < 5000; ++i)
                totals[pass] +=
                    dm::treasure::rollTreasureType(dice, L).goldValue();
        }
        if (totals[0] != totals[1]) fail("non-deterministic rolls");
    }
    printf("\ndeterminism: OK (identical totals on repeated seeds)\n");

    // ---- J-N individual multiplier: 'M' with 10 creatures ----------------
    // MM: M is gold per individual; 10 individuals should scale the
    // coin roughly 10x (other columns do not scale).
    for (int nc : { 1, 10 }) {
        rules::Rng rng(7);
        rules::Dice dice(rng);
        long long gp = 0;
        for (int i = 0; i < 20000; ++i)
            gp += dm::treasure::rollTreasureType(dice, 'M', nc).gp;
        printf("letter M with %2d creatures: avg gp per roll = %.1f\n",
               nc, (double)gp / 20000);
    }
    printf("\naudit done — compare the %% columns and avg gp against MM p.105\n");
    return 0;
                }
