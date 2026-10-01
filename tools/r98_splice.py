#!/usr/bin/env python3
# R98 the years tell: age ability brackets. Middle age (45)
# bends STR/CON/DEX down and INT/WIS up; old age (60) and
# venerable (90) deepen the bend. The bracket advance is
# applied ONCE, at the inn birthday that crosses into the
# new bracket, baked into the persisted abilities (DMG
# p.11-12 convention; book-verify pending - magnitudes are
# 1/2/3 for the three brackets).
#
# Patches (6):
#   game/party.h      - ageBracket()/ageAbilityDelta()/
#                       applyAgeBracket() helpers
#   game/state_town.cpp - bracket advance at the birthday
#   regtest.cpp       - R98 years tell audit
#   tools/playverify_r77_r83.md - R98 section
import sys, os

os.chdir(os.path.dirname(os.path.abspath(__file__)) + '/..')

def rd(p):
    with open(p, 'r', encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(p, 'w', encoding='ascii') as f:
        f.write(s)

OK = True

def patch(path, anchor, repl, label):
    global OK
    s = rd(path)
    if repl in s:
        print(label + ': already patched')
        return True
    i = s.find(anchor)
    if i < 0:
        print(label + ': ANCHOR MISS')
        OK = False
        return False
    s = s.replace(anchor, repl, 1)
    wr(path, s)
    print(label + ': patched')
    return True

# ---------------------------------------------------------------------------
# 1) party.h - the bracket helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// age today: the starting age plus whole years on the
// career clock (365 days to the year)
inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}
""",
"""// age today: the starting age plus whole years on the
// career clock (365 days to the year)
inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}

// R98: the years tell. Brackets (DMG p.11-12 convention,
// book-verify pending): young < 45, middle 45..59,
// old 60..89, venerable 90+.
inline int ageBracket(int age) {
    if (age < 45) return 0;
    if (age < 60) return 1;
    if (age < 90) return 2;
    return 3;
}

// the bend by bracket: STR/CON/DEX fall 1/2/3, INT/WIS
// rise 1/2/3, CHA is untouched (a face is a face)
inline int ageAbilityDelta(int bracket, rules::Ability a) {
    if (bracket <= 0) return 0;
    int mag = bracket;   // 1/2/3
    switch (a) {
        case rules::ABILITY_STR:
        case rules::ABILITY_CON:
        case rules::ABILITY_DEX:
            return -mag;
        case rules::ABILITY_INT:
        case rules::ABILITY_WIS:
            return mag;
        default:
            return 0;
    }
}

// apply the bracket advance to a member (once, at the
// birthday that crosses into it); clamps 3..18
inline void applyAgeBracket(Character& c, int newBracket) {
    const rules::Ability as[5] = {
        rules::ABILITY_STR, rules::ABILITY_INT,
        rules::ABILITY_WIS, rules::ABILITY_DEX,
        rules::ABILITY_CON };
    for (int i = 0; i < 5; ++i) {
        int d = ageAbilityDelta(newBracket, as[i]);
        if (d == 0) continue;
        int v = (int)c.abilities.get(as[i]) + d;
        if (v < 3)  v = 3;
        if (v > 18) v = 18;
        c.abilities.set(as[i], (uint8_t)v);
    }
}
""",
'party.h bracket helpers')

# ---------------------------------------------------------------------------
# 2) state_town.cpp - the bracket advance at the birthday
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""            for (auto& c : party.members) {
                if (c.hp <= 0 || c.startAge <= 0) continue;
                char ab[96];
                snprintf(ab, sizeof ab,
                         "%s turns %d years old.",
                         c.name.c_str(),
                         ageYears(c, party.careerDays));
                log.add(ab);
            }""",
"""            for (auto& c : party.members) {
                if (c.hp <= 0 || c.startAge <= 0) continue;
                char ab[96];
                snprintf(ab, sizeof ab,
                         "%s turns %d years old.",
                         c.name.c_str(),
                         ageYears(c, party.careerDays));
                log.add(ab);
                // R98: the years tell - the birthday that
                // crosses a bracket applies its bend once
                int newB = ageBracket(
                    ageYears(c, party.careerDays));
                int oldB = ageBracket(
                    ageYears(c, party.careerDays - 1));
                if (newB > oldB) {
                    applyAgeBracket(c, newB);
                    log.add("The years tell on him - "
                            "the bend of the age.");
                }
            }""",
'town.cpp bracket advance')

# ---------------------------------------------------------------------------
# 3) regtest.cpp - the years tell audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R97 gray beard audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R97 gray beard audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R98: years tell audit ----
    {
        int bad = 0;
        // bracket thresholds: 44 young, 45 middle, 60 old,
        // 90 venerable
        if (ageBracket(44) != 0) ++bad;
        if (ageBracket(45) != 1) ++bad;
        if (ageBracket(59) != 1) ++bad;
        if (ageBracket(60) != 2) ++bad;
        if (ageBracket(89) != 2) ++bad;
        if (ageBracket(90) != 3) ++bad;
        // the bend by bracket
        if (ageAbilityDelta(0, rules::ABILITY_STR) != 0)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_CON) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_DEX) != -3)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_WIS) != 2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_INT) != 3)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_CHA) != 0)
            ++bad;
        // the bend applies once and clamps 3..18
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  3);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            applyAgeBracket(c, 1);   // middle age
            if (c.abilities.get(rules::ABILITY_STR) != 17)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;                // clamped, no floor break
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;                // clamped at the ceiling
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 8)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;                // untouched
        }
        // a full life: 18/3/17/10/9/9 through three bends
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  9);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            applyAgeBracket(c, 1);
            applyAgeBracket(c, 2);
            applyAgeBracket(c, 3);
            // STR 18-6=12, CON 9-6=3, INT 17+6=18 (clamped),
            // WIS 10+6=16, DEX 9-6=3, CHA 10
            if (c.abilities.get(rules::ABILITY_STR) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 16)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 3)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;
        }
        printf("R98 years tell audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp years tell audit')

# ---------------------------------------------------------------------------
# 4) playverify - the R98 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R97: the gray beard
""",
"""## R98: the years tell
- [ ] A member crossing 45/60/90 at an inn birthday logs
      "The years tell on him - the bend of the age."
- [ ] The bend: STR/CON/DEX -1/-2/-3, INT/WIS +1/+2/+3,
      CHA untouched, scores clamp 3..18
- [ ] The bend applies once per bracket (a save made
      after the birthday round-trips the bent scores)
- [ ] Members under 45 see no change at their birthdays

## R97: the gray beard
""",
'playverify years tell section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R98 splice: ALL OK')
    sys.exit(0)
else:
    print('R98 splice: FAILED')
    sys.exit(1)
