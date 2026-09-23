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
#include "../game/henchman_save.h"

#include <cstdio>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <string>

static int g_checks = 0;
static int g_failures = 0;

#define CHECK(cond) do {                                              \
    ++g_checks;                                                       \
    if (!(cond)) {                                                    \
        ++g_failures;                                                 \
        std::printf("FAIL %s:%d  %s\n", __FILE__, __LINE__, #cond);   \
    }                                                                 \
} while (0)

namespace fs = std::filesystem;

namespace {

struct ScopedSaveDir {
    fs::path dir;
    bool ok = false;

    ScopedSaveDir() {
        std::error_code ec;
        fs::path base = fs::temp_directory_path(ec);
        if (ec) return;
        long long stamp = (long long)std::time(nullptr);
        for (int i = 0; i < 1000; ++i) {
            dir = base / ("adnd1_rules_test_" +
                          std::to_string(stamp) + "_" +
                          std::to_string(i));
            if (fs::exists(dir, ec)) {
                if (ec) return;
                continue;
            }
            if (!fs::create_directory(dir, ec) || ec) return;
            ok = true;
            return;
        }
    }

    ~ScopedSaveDir() {
        std::error_code ec;
        fs::remove_all(dir, ec);
    }
};

std::string readFile(const fs::path& path) {
    std::ifstream in(path);
    return std::string((std::istreambuf_iterator<char>(in)),
                       std::istreambuf_iterator<char>());
}

bool writeFile(const fs::path& path, const std::string& text) {
    std::ofstream out(path);
    out << text;
    return (bool)out;
}

bool rewriteLegacyHenchmanLine(const fs::path& path) {
    const std::string current =
        "henchman 7 11 3 88 444 555 666 Sellsword\n";
    const std::string legacy =
        "henchman 1 7 11 3 88 Sellsword 444 555 666\n";
    std::string text = readFile(path);
    size_t pos = text.find(current);
    if (pos == std::string::npos) return false;
    text.replace(pos, current.size(), legacy);
    return writeFile(path, text);
}

void checkHenchman(const Party& p) {
    CHECK(p.henchmanPresent);
    CHECK(p.henchmanName == "Sellsword");
    CHECK(p.henchmanHp == 7);
    CHECK(p.henchmanMaxHp == 11);
    CHECK(p.henchmanLevel == 3);
    CHECK(p.henchmanLoyalty == 88);
    CHECK(p.henchmanXp == 444);
    CHECK(p.henchmanPurse == 555);
    CHECK(p.delveGold == 666);
}

Party makeHenchmanParty() {
    Party p;
    p.henchmanPresent = true;
    p.henchmanName = "Sellsword";
    p.henchmanHp = 7;
    p.henchmanMaxHp = 11;
    p.henchmanLevel = 3;
    p.henchmanLoyalty = 88;
    p.henchmanXp = 444;
    p.henchmanPurse = 555;
    p.delveGold = 666;
    return p;
}

} // namespace

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

    // ---- henchman save/load round-trip --------------------------------------
    fs::path saveDir;
    {
        ScopedSaveDir dir;
        saveDir = dir.dir;
        CHECK(dir.ok);
        if (dir.ok) {
            fs::path path = dir.dir / "adnd1.sav";
            FILE* f = fopen(path.string().c_str(), "w");
            CHECK(f != nullptr);
            if (f) {
                Party saved = makeHenchmanParty();
                writeHenchmanSaveRecord(f, saved);
                fclose(f);
            }
            Party loaded;
            f = fopen(path.string().c_str(), "r");
            CHECK(f != nullptr);
            if (f) {
                char tag[16] = "";
                CHECK(fscanf(f, "%15s", tag) == 1);
                CHECK(std::strcmp(tag, "henchman") == 0);
                bool ok = readHenchmanSaveRecord(f, loaded);
                CHECK(ok);
                fclose(f);
                if (ok) checkHenchman(loaded);
            }
        }
    }
    CHECK(!saveDir.empty());
    CHECK(!fs::exists(saveDir));

    // ---- absent henchman survives round-trip --------------------------------
    saveDir.clear();
    {
        ScopedSaveDir dir;
        saveDir = dir.dir;
        CHECK(dir.ok);
        if (dir.ok) {
            fs::path path = dir.dir / "adnd1.sav";
            FILE* f = fopen(path.string().c_str(), "w");
            CHECK(f != nullptr);
            if (f) {
                Party saved;
                writeHenchmanSaveRecord(f, saved);
                fclose(f);
            }
            Party loaded;
            f = fopen(path.string().c_str(), "r");
            CHECK(f != nullptr);
            if (f) {
                char tag[16] = "";
                CHECK(fscanf(f, "%15s", tag) == 1);
                CHECK(std::strcmp(tag, "henchman") == 0);
                CHECK(readHenchmanSaveRecord(f, loaded));
                fclose(f);
            }
            CHECK(!loaded.henchmanPresent);
            CHECK(loaded.henchmanName.empty());
            CHECK(loaded.henchmanHp == 0);
            CHECK(loaded.henchmanMaxHp == 0);
            CHECK(loaded.henchmanXp == 0);
            CHECK(loaded.henchmanPurse == 0);
            CHECK(loaded.delveGold == 0);
        }
    }
    CHECK(!saveDir.empty());
    CHECK(!fs::exists(saveDir));

    // ---- legacy flagged henchman line still loads ---------------------------
    saveDir.clear();
    {
        ScopedSaveDir dir;
        saveDir = dir.dir;
        CHECK(dir.ok);
        if (dir.ok) {
            fs::path path = dir.dir / "adnd1.sav";
            FILE* f = fopen(path.string().c_str(), "w");
            CHECK(f != nullptr);
            if (f) {
                Party saved = makeHenchmanParty();
                writeHenchmanSaveRecord(f, saved);
                fclose(f);
            }
            CHECK(rewriteLegacyHenchmanLine(path));
            Party loaded;
            f = fopen(path.string().c_str(), "r");
            CHECK(f != nullptr);
            if (f) {
                char tag[16] = "";
                CHECK(fscanf(f, "%15s", tag) == 1);
                CHECK(std::strcmp(tag, "henchman") == 0);
                bool ok = readHenchmanSaveRecord(f, loaded);
                CHECK(ok);
                fclose(f);
                if (ok) checkHenchman(loaded);
            }
        }
    }
    CHECK(!saveDir.empty());
    CHECK(!fs::exists(saveDir));

    // ---- malformed/ambiguous henchman records fail cleanly ------------------
    {
        Party loaded;
        CHECK(!parseHenchmanSaveRecord(
            "1 7 11 3 88 444 555 666 Sellsword\n", loaded));
        CHECK(!parseHenchmanSaveRecord(
            "7 11 3 88 444 555 666\n", loaded));
        CHECK(!loaded.henchmanPresent);
        ScopedSaveDir dir;
        CHECK(dir.ok);
        if (dir.ok) {
            fs::path path = dir.dir / "adnd1.sav";
            CHECK(writeFile(path, "henchman 7 11 3 88 444 555 666 Sellsword"));
            FILE* f = fopen(path.string().c_str(), "r");
            CHECK(f != nullptr);
            if (f) {
                char tag[16] = "";
                CHECK(fscanf(f, "%15s", tag) == 1);
                CHECK(std::strcmp(tag, "henchman") == 0);
                bool ok = readHenchmanSaveRecord(f, loaded);
                CHECK(ok);
                fclose(f);
                if (ok) checkHenchman(loaded);
            }
        }
    }

    std::printf("%d checks, %d failures\n", g_checks, g_failures);
    return g_failures == 0 ? 0 : 1;
}