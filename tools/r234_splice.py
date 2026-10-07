#!/usr/bin/env python3
# R234 splice: the dual-class engine.
#
# The human class change goes live (the PHB THE
# CHARACTER WITH TWO CLASSES section): a human with
# 15+ in the prime requisite of the old class and
# 17+ in the new may cease the old profession and
# take up the new. The hit dice and hit points are
# RETAINED; all other functions begin at 1st level
# of the new class. Resorting to former-class
# functions negates the experience, until the new
# level EXCEEDS the old - then the new-class hit
# die per level and the functions may mix freely.
#
# The engine seam in rules/multiclass.h (pure
# expressions - the evaluable-subset convention):
# the exceeded boundary (dualClassNewDieDue) and
# the XP negation (dualClassXpNegated); the R185
# DUAL_CLASS_* constants become a named enum (the
# R233 McBits convention) so audit_eval reads them.
#
# The runtime: the Character fields (dualOldClass,
# dualOldLevel, oldClassUse) and the member
# factory (canSwitchProfession / switchProfession -
# the gates, the retained hp, the 1st-level
# restart, the new-profession kit, the caster slot
# and book restart), the gainXp negation, the
# trainNext promotion die (no die at or below the
# old level, the engine canonical new-class die
# once exceeded), the town guild command (the [K]
# key - the deterministic first-qualifying pick)
# and the resort stance toggle (the [U] key), the
# F6>M1 roster line, the v1-compatible dual save
# lines, the R234 battery audit.
#
# commit: R234: the dual-class engine - the human class change, the retained hit dice, the negated XP and the exceeded-level die (census 152)

import sys

MC   = 'rules/multiclass.h'
PAR  = 'game/party.h'
APP  = 'game/appstate.h'
TOWN = 'game/state_town.cpp'
AD   = 'adnd1.cpp'
CORE = 'game/state_core.cpp'
REG  = 'regtest.cpp'
GAP  = 'tools/phb_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks on the tree - the pristine base OR the
# fully-patched rerun both pass; anything else (a
# wrong base or a half-landed tree) fails
g = open(GAP).read()
if g.count('Census 150.') != 1 and g.count('Census 152.') != 1:
    print('R234 FAIL: gap report census line missing')
    sys.exit(1)
if ('- [ ] dual-class engine (the human class-change' not in g and
        'R234 the dual-class engine - WIRED' not in g):
    print('R234 FAIL: the dual-class box is not open')
    sys.exit(1)
t = open(REG).read()
if t.count('audit: bad ') != 150 and t.count('audit: bad ') != 152:
    print('R234 FAIL: regtest census is neither 150 nor 152')
    sys.exit(1)

# ---- 1: the DUAL_CLASS constants become a named enum
# (the R233 McBits convention - audit_eval reads enum
# constants, not static const ints) ----
mins_old = [
    'static const int DUAL_CLASS_OLD_PRIME_MIN = 15;',
    'static const int DUAL_CLASS_NEW_PRIME_MIN = 17;',
]
mins_new = [
    '// R234: named enum constants (was static const',
    '// ints) so the audit_eval seam reads the same',
    '// values (the R233 McBits convention).',
    'enum DualClassMins {',
    '    DUAL_CLASS_OLD_PRIME_MIN = 15,',
    '    DUAL_CLASS_NEW_PRIME_MIN = 17,',
    '};',
]

# ---- 2: the multiclass.h R234 seam ----
seam_old = [
    'inline int multiClassSubOfBit(int bit) {',
    '    return bit == MC_ILLUSIONIST ? 3',
    '         : bit == MC_RANGER ? 1',
    '         : bit == MC_ASSASSIN ? 4',
    '         : -1;',
    '}',
    '',
    '} // namespace rules',
]
seam_new = [
    'inline int multiClassSubOfBit(int bit) {',
    '    return bit == MC_ILLUSIONIST ? 3',
    '         : bit == MC_RANGER ? 1',
    '         : bit == MC_ASSASSIN ? 4',
    '         : -1;',
    '}',
    '',
    '// ---- the R234 dual-class seam (pure expressions',
    '// - the evaluable-subset convention) ----',
    '',
    '// The new-class hit die begins once the new level',
    '// EXCEEDS the former class level (the print: at',
    '// such time as the character has attained a level',
    '// which exceeds the former class level).',
    'inline int dualClassNewDieDue(int newLevel, int oldLevel) {',
    '    return newLevel > oldLevel ? 1 : 0;',
    '}',
    '',
    '// The XP negation: a dual-class member resorting to',
    '// former-class functions earns no experience, until',
    '// the new level exceeds the old (then the member',
    '// may mix functions freely). isDual is the 1/0 form',
    '// of dualOldClass >= 0; oldUse the stance.',
    'inline int dualClassXpNegated(int isDual, int newLevel,',
    '                              int oldLevel, int oldUse) {',
    '    return (isDual == 1 && oldUse == 1 &&',
    '            newLevel <= oldLevel) ? 1 : 0;',
    '}',
    '',
    '} // namespace rules',
]

# ---- 3: the Character fields ----
field_old = [
    '    int  multiMask = 0;',
    '    int  xp   = 0;',
]
field_new = [
    '    int  multiMask = 0;',
    '    // R234: the dual-class career (-1 = never',
    '    // switched; else the former class index and',
    '    // its frozen level - the human class change)',
    '    int  dualOldClass = -1;',
    '    int  dualOldLevel = 0;',
    '    // R234: the former-class resort stance (true =',
    '    // resorting to old-class functions; the XP is',
    '    // negated until the new level exceeds the old)',
    '    bool oldClassUse = false;',
    '    int  xp   = 0;',
]

# ---- 4: the member factory (canSwitchProfession /
# switchProfession), after strDisplay ----
meth_old = [
    '        else',
    '            snprintf(buf, sizeof buf, "%d", (int)abilities.str);',
    '        return buf;',
    '    }',
    '};',
]
meth_new = [
    '        else',
    '            snprintf(buf, sizeof buf, "%d", (int)abilities.str);',
    '        return buf;',
    '    }',
    '',
    '    // R234: can this member change professions? The',
    '    // print: a human (the character with two classes',
    '    // must be human), 15+ in the prime requisite of',
    '    // the original class and 17+ in the new (the',
    '    // ADJUSTED scores - the stored abilities are the',
    '    // adjusted ones), a plain single-classed member',
    '    // (no combo, no registry subclass), a different',
    '    // base class, and ONE switch only (the second',
    '    // class - a further change is not the print).',
    '    bool canSwitchProfession(int newClass) const {',
    '        if (!rules::dualClassRaceAllowed(race))',
    '            return false;',
    '        if (multiMask != 0) return false;',
    '        if (subclass >= 0) return false;',
    '        if (dualOldClass >= 0) return false;',
    '        if (newClass < 0 || newClass > 3) return false;',
    '        if (newClass == classIndex) return false;',
    '        return rules::dualClassPrimeGate(',
    '            abilities.get((rules::Ability)',
    '                rules::primeRequisite(classIndex)),',
    '            abilities.get((rules::Ability)',
    '                rules::primeRequisite(newClass)));',
    '    }',
    '',
    '    // R234: cease the old profession and take up the',
    '    // new (the print: the hit dice and hit points are',
    '    // RETAINED; all other functions begin at 1st',
    '    // level of the new class; the kit rides the new',
    '    // profession; the caster slots and the MU book',
    '    // restart at 1st level - the makeMember',
    '    // conventions, re-ridden here)',
    '    bool switchProfession(int newClass, rules::Dice& dice) {',
    '        if (!canSwitchProfession(newClass)) return false;',
    '        dualOldClass = classIndex;',
    '        dualOldLevel = level;',
    '        oldClassUse = false;',
    '        classIndex = newClass;',
    '        level = 1;',
    '        xp = 0;',
    '        knownSpells.clear();',
    '        for (int lv = 0; lv < 9; ++lv)',
    '            slotsByLevel[lv] = 0;',
    '        if (newClass == 1 || newClass == 2) {',
    '            spells::SpellClass sc = newClass == 1',
    '                ? spells::SPELL_MU : spells::SPELL_CLERIC;',
    '            for (int lv = 1; lv <= 9; ++lv)',
    '                slotsByLevel[lv - 1] =',
    '                    spells::spellSlots(sc, 1, lv);',
    '        }',
    '        if (newClass == 1) {',
    '            std::vector<int> l1;',
    '            for (int id = 0; id < spells::SPELL_COUNT;',
    '                 ++id) {',
    '                const spells::SpellDef& s =',
    '                    spells::spell((spells::SpellId)id);',
    '                if (s.sclass == spells::SPELL_MU &&',
    '                    s.level == 1)',
    '                    l1.push_back(id);',
    '            }',
    '            if (!l1.empty()) {',
    '                int pick = (int)dice.roll(',
    '                    1, (uint32_t)l1.size(), 0) - 1;',
    '                knownSpells.push_back(l1[pick]);',
    '            }',
    '        }',
    '        if (newClass == rules::CLASS_FIGHTER &&',
    '            abilities.str == 18 && !exStr.has) {',
    '            exStr.has = true;',
    '            exStr.pct = rules::rollExceptionalStrength(dice);',
    '        }',
    '        switch (newClass) {',
    '            case rules::CLASS_FIGHTER:',
    '                weapon.id = items::WPN_LONG_SWORD;',
    '                armor.id  = items::ARMOR_PLATE;',
    '                shield    = true;',
    '                break;',
    '            case rules::CLASS_MAGIC_USER:',
    '                weapon.id = items::WPN_DAGGER;',
    '                armor.id  = items::ARMOR_NONE_EQUIPPED;',
    '                shield    = false;',
    '                break;',
    '            case rules::CLASS_CLERIC:',
    '                weapon.id = items::WPN_MACE;',
    '                armor.id  = items::ARMOR_CHAIN_MAIL;',
    '                shield    = true;',
    '                break;',
    '            case rules::CLASS_THIEF:',
    '                weapon.id = items::WPN_SHORT_SWORD;',
    '                armor.id  = items::ARMOR_LEATHER;',
    '                shield    = false;',
    '                rangedWeapon.id = items::WPN_SLING;',
    '                break;',
    '        }',
    '        return true;',
    '    }',
    '};',
]

# ---- 5: the gainXp negation ----
gx_old = [
    '        for (auto& c : members) {',
    '            if (c.hp <= 0) continue;   // the dead earn nothing',
]
gx_new = [
    '        for (auto& c : members) {',
    '            if (c.hp <= 0) continue;   // the dead earn nothing',
    '            // R234: the dual-class XP negation - a',
    '            // member resorting to former-class',
    '            // functions earns nothing (the print:',
    '            // reversion negates the experience),',
    '            // until the new level exceeds the old',
    '            // (then the functions mix freely)',
    '            if (rules::dualClassXpNegated(',
    '                    c.dualOldClass >= 0 ? 1 : 0,',
    '                    c.level, c.dualOldLevel,',
    '                    c.oldClassUse ? 1 : 0)) {',
    '                char nbuf[96];',
    '                snprintf(nbuf, sizeof nbuf,',
    '                         "%s earns no experience "',
    '                         "(former-class resort).",',
    '                         c.name.c_str());',
    '                log.add(nbuf);',
    '                continue;',
    '            }',
]

# ---- 6: the trainNext dual promotion die ----
die_old = [
    '            int conAdj;',
    '            int die;',
    '            if (c.multiMask != 0) {',
]
die_new = [
    '            int conAdj;',
    '            int die;',
    '            if (c.dualOldClass >= 0) {',
    '                // R234: the dual-class promotion die -',
    '                // no die while the new level has not',
    '                // exceeded the former level (the old',
    '                // hit dice are retained, the new class',
    '                // rolls nothing below it); once',
    '                // exceeded, the engine canonical',
    '                // new-class die (the per-die floor 1)',
    '                if (rules::dualClassNewDieDue(',
    '                        c.level, c.dualOldLevel)) {',
    '                    conAdj = rules::conHPAdjustment(',
    '                        c.classIndex, c.abilities.con);',
    '                    die = rules::rollHitPoints(',
    '                        c.classIndex, c.level, conAdj, dice);',
    '                    if (die < 1) die = 1;',
    '                } else {',
    '                    die = 0;',
    '                }',
    '            } else if (c.multiMask != 0) {',
]

# ---- 7: the appstate.h declarations ----
decl_old = [
    '    void townTrain();',
]
decl_new = [
    '    void townTrain();',
    '',
    '    // R234: the guild class-change and the resort stance',
    '    void townChangeClass();',
    '    void townOldClassResort();',
]

# ---- 8: the town guild command and the resort toggle ----
town_old = [
    '            restoreSlots();',
    '        }',
    '    }',
    '',
    '// ---- townBuyChain ----',
]
town_new = [
    '            restoreSlots();',
    '        }',
    '    }',
    '',
    '// ---- townChangeClass ----',
    '// R234: the guild - the human class change (the',
    '// print: 15+ in the old prime, 17+ in the new).',
    '// The first member who meets the gates switches',
    '// to the first qualifying base class (the',
    '// deterministic pick; the town has no dialogs).',
    'void AppState::townChangeClass(){',
    '        if (mode != MODE_TOWN) return;',
    '        for (auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            for (int nc = 0; nc < 4; ++nc) {',
    '                if (!c.canSwitchProfession(nc)) continue;',
    '                c.switchProfession(nc, dice);',
    '                static const char* NC[4] =',
    '                    { "fighter", "magic-user",',
    '                      "cleric", "thief" };',
    '                char buf[128];',
    '                snprintf(buf, sizeof buf,',
    '                         "%s ceases the old profession "',
    '                         "and takes up %s at 1st "',
    '                         "level (hit dice kept).",',
    '                         c.name.c_str(), NC[nc]);',
    '                log.add(buf);',
    '                log.add("No hit die until the new level "',
    '                        "exceeds the old; [U] resorts to "',
    '                        "former-class functions.");',
    '                return;',
    '            }',
    '        }',
    '        log.add("No one can change class (human, 15+ "',
    '                "old prime, 17+ new).");',
    '}',
    '',
    '// ---- townOldClassResort ----',
    '// R234: the former-class resort stance - while',
    '// held the member earns no experience (the print:',
    '// reversion negates it), until the new level',
    '// exceeds the old.',
    'void AppState::townOldClassResort(){',
    '        if (mode != MODE_TOWN) return;',
    '        for (auto& c : party.members) {',
    '            if (c.hp <= 0) continue;',
    '            if (c.dualOldClass < 0) continue;',
    '            c.oldClassUse = !c.oldClassUse;',
    '            log.add(c.oldClassUse',
    '                ? "Resorting to former-class functions "',
    '                  "- no experience while this holds."',
    '                : "Performing strictly within the new "',
    '                  "profession.");',
    '            return;',
    '        }',
    '        log.add("No member has two classes.");',
    '}',
    '',
    '// ---- townBuyChain ----',
]

# ---- 9: the town keydown cases ----
key_old = [
    '                    case ' + Q + 'R' + Q + ':',
    '                    case ' + Q + 'r' + Q + ':',
    '                        g_app.townRaiseDead();',
    '                        break;',
]
key_new = [
    '                    case ' + Q + 'R' + Q + ':',
    '                    case ' + Q + 'r' + Q + ':',
    '                        g_app.townRaiseDead();',
    '                        break;',
    '',
    '                    // R234: the guild class-change and the resort',
    '                    case ' + Q + 'K' + Q + ':',
    '                    case ' + Q + 'k' + Q + ':',
    '                        g_app.townChangeClass();',
    '                        break;',
    '',
    '                    case ' + Q + 'U' + Q + ':',
    '                    case ' + Q + 'u' + Q + ':',
    '                        g_app.townOldClassResort();',
    '                        break;',
]

# ---- 10: the drawTown guild help line ----
help_old = [
    '    snprintf(line, sizeof line,',
    '             "Identify scrolls: %d  (unidentified: %d)",',
    '             s.party.identifyScrolls,',
    '             (int)s.party.unidentified.size());',
    '    TextOutA(dc, 430, sy, line, (int)strlen(line));',
    '}',
]
help_new = [
    '    snprintf(line, sizeof line,',
    '             "Identify scrolls: %d  (unidentified: %d)",',
    '             s.party.identifyScrolls,',
    '             (int)s.party.unidentified.size());',
    '    TextOutA(dc, 430, sy, line, (int)strlen(line));',
    '',
    '    // R234: the guild class-change and the resort',
    '    // stance (the left column is full to y=600; the',
    '    // lines ride under the company column)',
    '    sy += 22;',
    '    snprintf(line, sizeof line,',
    '             "GUILD: [K] change class  [U] resort stance");',
    '    TextOutA(dc, 430, sy, line, (int)strlen(line));',
    '}',
]

# ---- 11: the town roster dual line ----
roster_old = [
    '        if (c.hp <= 0) {',
    '            snprintf(line, sizeof line, "%s  fallen", nm);',
    '        } else {',
    '            snprintf(line, sizeof line, "%s  %c%d  %d/%d",',
    '                     nm, CLASS_LETTER[c.classIndex & 3],',
    '                     c.level, c.hp, c.maxHp);',
    '        }',
    '        TextOutA(dc, 430, sy, line, (int)strlen(line));',
    '        sy += 22;',
    '    }',
    '    if (sy < 200) sy = 200;   // clear of a short roster',
]
roster_new = [
    '        if (c.hp <= 0) {',
    '            snprintf(line, sizeof line, "%s  fallen", nm);',
    '        } else if (c.dualOldClass >= 0) {',
    '            // R234: the two-class roster line - the',
    '            // former class and level, then the new',
    '            snprintf(line, sizeof line,',
    '                     "%s  %c%d>%c%d  %d/%d",',
    '                     nm, CLASS_LETTER[c.dualOldClass & 3],',
    '                     c.dualOldLevel,',
    '                     CLASS_LETTER[c.classIndex & 3],',
    '                     c.level, c.hp, c.maxHp);',
    '        } else {',
    '            snprintf(line, sizeof line, "%s  %c%d  %d/%d",',
    '                     nm, CLASS_LETTER[c.classIndex & 3],',
    '                     c.level, c.hp, c.maxHp);',
    '        }',
    '        TextOutA(dc, 430, sy, line, (int)strlen(line));',
    '        sy += 22;',
    '    }',
    '    if (sy < 200) sy = 200;   // clear of a short roster',
]

# ---- 12: the save lines ----
save_old = [
    '            // R233: the multi-class combo (only when set -',
    '            // v1 saves carry no line and load as single)',
    '            if (c.multiMask != 0)',
    '                fprintf(f, "multi %d' + BS + 'n", c.multiMask);',
]
save_new = [
    '            // R233: the multi-class combo (only when set -',
    '            // v1 saves carry no line and load as single)',
    '            if (c.multiMask != 0)',
    '                fprintf(f, "multi %d' + BS + 'n", c.multiMask);',
    '            // R234: the dual-class career (only when',
    '            // switched - v1 saves carry no line and',
    '            // load as single)',
    '            if (c.dualOldClass >= 0) {',
    '                fprintf(f, "dual %d %d' + BS + 'n",',
    '                        c.dualOldClass, c.dualOldLevel);',
    '                fprintf(f, "olduse %d' + BS + 'n",',
    '                        c.oldClassUse ? 1 : 0);',
    '            }',
]

# ---- 13: the load branches ----
load_old = [
    '                    c.multiMask = mm;',
    '                } else if (strcmp(tag, "age") == 0) {',
]
load_new = [
    '                    c.multiMask = mm;',
    '                } else if (strcmp(tag, "dual") == 0) {',
    '                    int oc = 0, ol = 0;',
    '                    if (fscanf(f, "%d %d", &oc, &ol) != 2 ||',
    '                        oc < 0 || oc > 3 ||',
    '                        ol < 1 || ol > 40) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is corrupt (dual).");',
    '                        return false;',
    '                    }',
    '                    c.dualOldClass = oc;',
    '                    c.dualOldLevel = ol;',
    '                } else if (strcmp(tag, "olduse") == 0) {',
    '                    int ou = 0;',
    '                    if (fscanf(f, "%d", &ou) != 1 ||',
    '                        ou < 0 || ou > 1) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is corrupt (olduse).");',
    '                        return false;',
    '                    }',
    '                    c.oldClassUse = ou != 0;',
    '                } else if (strcmp(tag, "age") == 0) {',
]

# ---- 14: the regtest audits ----
audit_old = [
    '        printf("R233 multi-class engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]
audit_new = [
    '        printf("R233 multi-class engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R234a: the dual-class seam audit ----',
    '    // The R185 gates and the R234 pure-expression',
    '    // seam (an evaluable block - verified by',
    '    // audit_eval).',
    '    {',
    '        int bad = 0;',
    '        // the race gate: humans only',
    '        if (!rules::dualClassRaceAllowed(0)) ++bad;',
    '        if (rules::dualClassRaceAllowed(1)) ++bad;',
    '        if (rules::dualClassRaceAllowed(6)) ++bad;',
    '        // the prime gates: 15+ old, 17+ new',
    '        if (rules::dualClassPrimeGate(14, 17)) ++bad;',
    '        if (rules::dualClassPrimeGate(15, 16)) ++bad;',
    '        if (!rules::dualClassPrimeGate(15, 17)) ++bad;',
    '        if (!rules::dualClassPrimeGate(16, 18)) ++bad;',
    '        // the exceeded boundary: the new die begins',
    '        // when the new level EXCEEDS the old',
    '        if (rules::dualClassNewDieDue(6, 6) != 0) ++bad;',
    '        if (rules::dualClassNewDieDue(7, 6) != 1) ++bad;',
    '        if (rules::dualClassNewDieDue(1, 1) != 0) ++bad;',
    '        // the XP negation: the resort stance negates',
    '        // until exceeded, then mixing is free',
    '        if (rules::dualClassXpNegated(1, 1, 6, 1) != 1) ++bad;',
    '        if (rules::dualClassXpNegated(1, 6, 6, 1) != 1) ++bad;',
    '        if (rules::dualClassXpNegated(1, 7, 6, 1) != 0) ++bad;',
    '        if (rules::dualClassXpNegated(1, 1, 6, 0) != 0) ++bad;',
    '        if (rules::dualClassXpNegated(0, 1, 6, 1) != 0) ++bad;',
    '        printf("R234a dual-class seam audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R234: the dual-class engine audit ----',
    '    // The switch gates, the retained hit dice, the',
    '    // 1st-level restart, the XP negation and the',
    '    // exceeded-level die (an engine audit - the C++',
    '    // battery is the gate).',
    '    {',
    '        int bad = 0;',
    '        {',
    '            Character c;',
    '            c.race = 0;   // human',
    '            c.abilities.str = 15;',
    '            c.abilities.int_ = 17;',
    '            c.classIndex = 0;   // the printed example: fighter',
    '            c.level = 6;',
    '            c.hp = c.maxHp = 40;',
    '            if (!c.canSwitchProfession(1)) ++bad;',
    '            // the refusals: same class, wrong race,',
    '            // low old prime, low new prime',
    '            if (c.canSwitchProfession(0)) ++bad;',
    '            c.race = 1;',
    '            if (c.canSwitchProfession(1)) ++bad;',
    '            c.race = 0;',
    '            c.abilities.str = 14;',
    '            if (c.canSwitchProfession(1)) ++bad;',
    '            c.abilities.str = 15;',
    '            c.abilities.int_ = 16;',
    '            if (c.canSwitchProfession(1)) ++bad;',
    '            c.abilities.int_ = 17;',
    '            // the switch: hit dice kept, 1st-level',
    '            // restart, the MU kit',
    '            rules::Rng r{1};',
    '            rules::Dice d(r);',
    '            if (!c.switchProfession(1, d)) ++bad;',
    '            if (c.dualOldClass != 0) ++bad;',
    '            if (c.dualOldLevel != 6) ++bad;',
    '            if (c.classIndex != 1) ++bad;',
    '            if (c.level != 1) ++bad;',
    '            if (c.xp != 0) ++bad;',
    '            if (c.hp != 40 || c.maxHp != 40) ++bad;',
    '            if (c.armor.id != items::ARMOR_NONE_EQUIPPED)',
    '                ++bad;',
    '            if (c.shield) ++bad;',
    '            // one switch only',
    '            if (c.canSwitchProfession(2)) ++bad;',
    '        }',
    '        // the XP negation and the exceeded die, on a',
    '        // live party train loop',
    '        {',
    '            Party p;',
    '            Character c;',
    '            c.name = "Swit";',
    '            c.race = 0;',
    '            c.abilities.str = 15;',
    '            c.abilities.int_ = 17;',
    '            c.classIndex = 0;',
    '            c.level = 2;',
    '            c.hp = c.maxHp = 12;',
    '            rules::Rng r{7};',
    '            rules::Dice d(r);',
    '            if (!c.switchProfession(1, d)) ++bad;',
    '            p.members.push_back(c);',
    '            MessageLog log;',
    '            // the resort stance negates the award',
    '            p.members[0].oldClassUse = true;',
    '            p.gainXp(1000, d, log);',
    '            if (p.members[0].xp != 0) ++bad;',
    '            // strict: the award flows and queues',
    '            p.members[0].oldClassUse = false;',
    '            p.gainXp(1000, d, log);',
    '            if (p.members[0].xp <= 0) ++bad;',
    '            p.members[0].xp = 100000;',
    '            // no die at or below the old level',
    '            int hpAtOld = p.members[0].maxHp;',
    '            p.gainXp(0, d, log);',
    '            if (p.trainNext(d, log) < 0) ++bad;',
    '            if (p.members[0].level != 2) ++bad;',
    '            if (p.members[0].maxHp != hpAtOld) ++bad;',
    '            // the new-class die once exceeded',
    '            p.gainXp(0, d, log);',
    '            if (p.trainNext(d, log) < 0) ++bad;',
    '            if (p.members[0].level != 3) ++bad;',
    '            if (p.members[0].maxHp <= hpAtOld) ++bad;',
    '        }',
    '        printf("R234 dual-class engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

# ---- 15: the gap-report box ----
gap_old = [
    '- [ ] dual-class engine (the human class-change',
    '      runtime; R185 comments, no engine yet).',
]
gap_new = [
    '- [x] R234 the dual-class engine - WIRED: the',
    '      human class change is playable - the guild',
    '      command (the [K] town key; the first member',
    '      who meets the gates switches to the first',
    '      qualifying base class - the deterministic',
    '      pick), the gates (human only, 15+ in the',
    '      ADJUSTED prime of the old class, 17+ in the',
    '      new, one switch only, a plain single-classed',
    '      member), the switch itself (the hit dice and',
    '      hit points RETAINED, all functions at 1st',
    '      level of the new class, the kit rides the new',
    '      profession, the caster slots and the MU book',
    '      restart at 1st level), the resort stance',
    '      (the [U] town key - while held the member',
    '      earns no experience, the print: reversion',
    '      negates it; free once the new level EXCEEDS',
    '      the old), and the promotion die (no die at or',
    '      below the old level; the engine canonical',
    '      new-class die once exceeded). Simplifications',
    '      recorded: the resort stance is a standing',
    '      town toggle (the engine has no per-adventure',
    '      XP boundary), the switch targets the base',
    '      classes only (the printed paladin and ranger',
    '      combinations stay future work), the roster',
    '      prints the F6>M1 line. Census 152.',
]

PATCHES = [
    (MC,   'enum DualClassMins', mins_old, mins_new),
    (MC,   'dualClassNewDieDue(int newLevel, int oldLevel)', seam_old, seam_new),
    (PAR,  'int  dualOldClass = -1;', field_old, field_new),
    (PAR,  'bool canSwitchProfession(int newClass) const', meth_old, meth_new),
    (PAR,  'earns no experience (former-class resort)', gx_old, gx_new),
    (PAR,  'the dual-class promotion die', die_old, die_new),
    (APP,  'void townChangeClass();', decl_old, decl_new),
    (TOWN, 'void AppState::townChangeClass()', town_old, town_new),
    (AD,   'g_app.townChangeClass();', key_old, key_new),
    (AD,   'GUILD: [K] change class', help_old, help_new),
    (AD,   'CLASS_LETTER[c.dualOldClass & 3]', roster_old, roster_new),
    (CORE, 'dual %d %d', save_old, save_new),
    (CORE, 'strcmp(tag, "dual") == 0', load_old, load_new),
    (REG,  'R234a dual-class seam audit', audit_old, audit_new),
    (GAP,  'R234 the dual-class engine - WIRED', gap_old, gap_new),
]

applied = 0
already = 0
for path, marker, old, new in PATCHES:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    count_new = text.count(new_s)
    count_old = text.count(old_s)
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if count_new >= 1:
        already += 1
        continue
    if count_old == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif count_old == 0:
        print('R234 FAIL: marker missing post-patch: ' + marker)
        sys.exit(1)
    else:
        print('R234 FAIL: marker appears ' + str(count_old) +
              ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied == len(PATCHES):
    t = open(REG).read()
    if t.count('audit: bad ') != 152:
        print('R234 FAIL: census is not 152')
        sys.exit(1)
    if t.count('R234a dual-class seam audit') != 1:
        print('R234 FAIL: the R234a audit line must appear once')
        sys.exit(1)
    if t.count('R234 dual-class engine audit') != 1:
        print('R234 FAIL: the R234 audit line must appear once')
        sys.exit(1)
    t = open(GAP).read()
    if t.count('Census 152.') != 1:
        print('R234 FAIL: gap census line missing')
        sys.exit(1)
    if '- [ ] dual-class engine' in t:
        print('R234 FAIL: the old box still open')
        sys.exit(1)

print('R234 splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R234 note: 15 patches - the human class change playable; the hit')
print('dice are kept, all functions restart at 1st level; the resort')
print('stance negates XP until the new level exceeds the old.')
print('commit: R234: the dual-class engine - the human class change, the retained hit dice, the negated XP and the exceeded-level die (census 152)')

