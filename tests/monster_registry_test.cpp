#include "../monsters/MonsterRegistry.h"
#include "../rules/dice.h"

#include <cstdio>
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

struct ScopedDir {
    fs::path dir;
    bool ok = false;

    ScopedDir() {
        std::error_code ec;
        fs::path base = fs::temp_directory_path(ec);
        if (ec) return;
        long long stamp = (long long)std::time(nullptr);
        for (int i = 0; i < 1000; ++i) {
            dir = base / ("adnd1_monster_registry_test_" +
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

    ~ScopedDir() {
        std::error_code ec;
        fs::remove_all(dir, ec);
    }
};

bool writeFile(const fs::path& path, const std::string& text) {
    std::ofstream out(path);
    out << text;
    return (bool)out;
}

std::string joinedErrors(const monsters::MonsterRegistry& reg) {
    std::string out;
    for (const std::string& err : reg.errors()) {
        if (!out.empty()) out += "\n";
        out += err;
    }
    return out;
}

void checkImportedAndLegacyLoads() {
    ScopedDir dir;
    CHECK(dir.ok);
    if (!dir.ok) return;

    const fs::path repoRoot = fs::path(__FILE__).parent_path().parent_path();
    std::error_code ec;
    fs::copy_file(repoRoot / "monsters/monsters/orc.lua",
                  dir.dir / "orc.lua",
                  fs::copy_options::overwrite_existing, ec);
    CHECK(!ec);
    ec.clear();
    fs::copy_file(repoRoot / "monsters/monsters/mind_flayer.lua",
                  dir.dir / "mind_flayer.lua",
                  fs::copy_options::overwrite_existing, ec);
    CHECK(!ec);

    CHECK(writeFile(
        dir.dir / "legacy.lua",
        "return {\n"
        "  name = \"Legacy Wolf\",\n"
        "  hd = 3,\n"
        "  hpBonus = 2,\n"
        "  ac = 5,\n"
        "  attacks = 2,\n"
        "  damageCount = 2,\n"
        "  damageSides = 4,\n"
        "  xpValue = 33,\n"
        "}\n"));

    CHECK(writeFile(
        dir.dir / "mixed.lua",
        "return {\n"
        "  name = \"Mixed Schema\",\n"
        "  hd = 1,\n"
        "  hpBonus = 0,\n"
        "  ac = 9,\n"
        "  attacks = 1,\n"
        "  damageCount = 1,\n"
        "  damageSides = 2,\n"
        "  xp = 5,\n"
        "  hitDiceNum = 4,\n"
        "  hitDiceBonus = 1,\n"
        "  armorClass = 3,\n"
        "  numAttacks = 2,\n"
        "  damage = { { min = 2, max = 12 } },\n"
        "  xpValue = 123,\n"
        "}\n"));

    monsters::MonsterRegistry reg;
    int count = reg.loadDirectory(dir.dir.string());
    CHECK(count == 4);
    CHECK(reg.errors().empty());

    const monsters::MonsterDef* orc = reg.find("orc");
    CHECK(orc != nullptr);
    if (orc) {
        CHECK(orc->hitDice == 1.0f);
        CHECK(orc->hitPointBonus == 0);
        CHECK(orc->armorClass == 6);
        CHECK(orc->attacks == 1);
        CHECK(orc->damageMin == 1);
        CHECK(orc->damageMax == 8);
        CHECK(orc->damageRaw.empty());
        CHECK(orc->xpValue == 14);

        rules::Rng rng(1);
        rules::Dice dice(rng);
        ai::Actor actor = reg.toActor("orc", dice, 4);
        CHECK(actor.hitDice == 1.0f);
        CHECK(actor.monsterArmorClass == 6);
        CHECK(actor.monsterAttacks == 1);
        CHECK(actor.monsterDamageMin == 1);
        CHECK(actor.monsterDamageMax == 8);
        CHECK(actor.hp == 4);
        CHECK(actor.maxHp == 4);
    }

    const monsters::MonsterDef* mindFlayer = reg.find("mind_flayer");
    CHECK(mindFlayer != nullptr);
    if (mindFlayer) {
        CHECK(mindFlayer->hitDice == 8.0f);
        CHECK(mindFlayer->hitPointBonus == 4);
        CHECK(mindFlayer->armorClass == 5);
        CHECK(mindFlayer->attacks == 4);
        CHECK(mindFlayer->damageMin == 2);
        CHECK(mindFlayer->damageMax == 2);
        CHECK(mindFlayer->damageRaw == "2 each");
        CHECK(mindFlayer->magicResist == 90);
        CHECK(mindFlayer->xpValue == 1400);

        rules::Rng rng(2);
        rules::Dice dice(rng);
        ai::Actor actor = reg.toActor("mind_flayer", dice, 40);
        CHECK(actor.hitDice == 8.0f);
        CHECK(actor.monsterArmorClass == 5);
        CHECK(actor.monsterAttacks == 4);
        CHECK(actor.monsterDamageMin == 2);
        CHECK(actor.monsterDamageMax == 2);
        CHECK(actor.monsterDamageRaw == "2 each");
        CHECK(actor.magicResistPct == 90);
        CHECK(actor.hp == 40);
        CHECK(actor.maxHp == 40);
    }

    const monsters::MonsterDef* legacy = reg.find("legacy");
    CHECK(legacy != nullptr);
    if (legacy) {
        CHECK(legacy->hitDice == 3.0f);
        CHECK(legacy->hitPointBonus == 2);
        CHECK(legacy->armorClass == 5);
        CHECK(legacy->attacks == 2);
        CHECK(legacy->damageCount == 2);
        CHECK(legacy->damageSides == 4);
        CHECK(legacy->damageMin == 2);
        CHECK(legacy->damageMax == 8);
        CHECK(legacy->xpValue == 33);
    }

    const monsters::MonsterDef* mixed = reg.find("mixed");
    CHECK(mixed != nullptr);
    if (mixed) {
        CHECK(mixed->hitDice == 4.0f);
        CHECK(mixed->hitPointBonus == 1);
        CHECK(mixed->armorClass == 3);
        CHECK(mixed->attacks == 2);
        CHECK(mixed->damageMin == 2);
        CHECK(mixed->damageMax == 12);
        CHECK(mixed->xpValue == 123);
    }
}

void checkImportedFieldErrors() {
    ScopedDir dir;
    CHECK(dir.ok);
    if (!dir.ok) return;

    CHECK(writeFile(
        dir.dir / "broken.lua",
        "return {\n"
        "  name = \"Broken Imported\",\n"
        "  hitDiceNum = 2,\n"
        "  hitDiceBonus = 1,\n"
        "  numAttacks = 1,\n"
        "  damage = { { min = 1, max = 6 } },\n"
        "  xpValue = 42,\n"
        "}\n"));

    monsters::MonsterRegistry reg;
    int count = reg.loadDirectory(dir.dir.string());
    CHECK(count == 0);
    CHECK(reg.find("broken") == nullptr);
    CHECK(reg.errors().size() == 1);
    std::string errors = joinedErrors(reg);
    CHECK(errors.find("broken") != std::string::npos);
    CHECK(errors.find("armorClass") != std::string::npos);
    CHECK(errors.find("imported runtime field") != std::string::npos);
}

} // namespace

int main() {
    checkImportedAndLegacyLoads();
    checkImportedFieldErrors();

    std::printf("%d checks, %d failures\n", g_checks, g_failures);
    return g_failures == 0 ? 0 : 1;
}
