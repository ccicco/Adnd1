// ====================================================================
// Adnd1 - rules/specartprose2.h
// R281: the III.E Special artifacts explanation
// prose part 2 (DMG p.159-160) - the Axe of the
// Dwarvish Lords, the Baba Yaga Hut and the Codex
// of the Infinite Planes, part2 lines 1184-1235
// (global = 11065 + part2 line), the first three
// of the 29 artifact descriptions. The Axe pins:
// the blade equals a sword of sharpness; the head
// equals a +3 hammer; the handle extends or
// contracts on command to equal a battle or hand
// axe for throwing; the Axe returns 30 feet to its
// thrower; the possessor has dwarven abilities,
// doubled for a dwarf; the life span is 50 percent
// longer; the Axe supposedly bears a curse and was
// lost in the Invoked Devastation; powers 2 of
// table I and 1 each of tables II through VI. The
// Hut pins: 15 feet diameter, 10 feet high; two
// fowl legs 12 feet long; infravision 120 feet;
// 30 rooms on 3 floors; movement 48 inches over
// swamp, 36 over rough or normal terrain and 12
// over hills; obeys commands from 1 key-phrase
// commander; comes to a call from 1 league; the
// legs strike as a hill giant, 2 attacks per
// round, armor class 2, 48 hit points each,
// regenerating 1 per round; 5 foot granite walls;
// powers 4 of table I, 2 of table II, 1 each of
// III through VI. The Codex pins: 99 damned
// pages; 99 percent certain doom at 1 percent
// cumulative per page; keys to instant
// transference to any plane; destroys any
// character under 11th level on touch; 11th or
// higher save versus magic to command; powers 4
// each of tables I and II, 2 each of III through
// VI; the powers activate per the progress of the
// perusal. This round has one seam restored: the
// p.159-160 page break splits the Codex paragraph
// between the 1216 tail (the work will destroy
// instantly any) and the 1221 head (character
// under 11th level) across the blank pair at
// 1217-1218, the TREASURE (ARTIFACTS & RELICS)
// running head at 1219 and the 1220 post-head
// blank. The upload quirks this round: the power
// lines print the counts as N x table with the
// true multiplication sign, 18 of them; the feet
// primes print as the curly right single quote
// and the inch primes as the curly right double
// quote; the Tzunk fragment prints curly quotes;
// the hit point/ melee round slash split carries
// a space - all pinned as plain digits and words,
// apostrophe-free here. 37 accessors: 33 scalars
// + 4 walkers (the three power-count walkers -
// 2,1,1,1,1,1 for the Axe, 4,2,1,1,1,1 for the
// Hut, 4,4,2,2,2,2 for the Codex - and the hut
// move walker 48, 36, 12), no name collisions
// with the miscprose and specart headers. The
// audit cross-pins the R240 sale table rows: the
// Axe band 01 at 55000, the Hut band 02 at
// 90000, the Codex band 03-04 at 62500. Pure
// data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

namespace rules {

inline int sapAxeBladeSharpness() {
    // the blade equals a sword of sharpness
    return 1;
}

inline int sapAxeHammerBonus() {
    // the head equals a +3 hammer
    return 3;
}

inline int sapAxeHandleForms() {
    // the handle equals a battle or hand axe
    return 2;
}

inline int sapAxeReturnFeet() {
    // returns 30 feet to its thrower
    return 30;
}

inline int sapAxeDwarfAbilityMultiplier() {
    // dwarven abilities doubled for a dwarf
    return 2;
}

inline int sapAxeLifespanBonusPct() {
    // the life span is 50 percent longer
    return 50;
}

inline int sapAxeBearsCurse() {
    // the Axe supposedly bears a curse
    return 1;
}

inline int sapAxeInvokedDevastationLost() {
    // lost in the Invoked Devastation centuries gone
    return 1;
}

inline int sapAxePowerTotal() {
    // 2 of table I plus 1 each of tables II-VI
    return 7;
}

inline int sapAxePowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        2, 1, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapHutDiameterFeet() {
    // a circular thatched structure of 15 feet
    return 15;
}

inline int sapHutHeightFeet() {
    // 10 feet high
    return 10;
}

inline int sapHutLegCount() {
    // two powerful fowl legs
    return 2;
}

inline int sapHutLegLengthFeet() {
    // the legs are 12 feet long stilts
    return 12;
}

inline int sapHutInfravisionFeet() {
    // infravisual ability to 120 feet
    return 120;
}

inline int sapHutRoomCount() {
    // 30 rooms on 3 floors, all furnished
    return 30;
}

inline int sapHutFloorCount() {
    // the 30 rooms sit on 3 floors
    return 3;
}

inline int sapHutMoveTerrainCount() {
    // swamp, rough or normal, hills and forests
    return 3;
}

inline int sapHutMoveInches(int i) {
    // move per terrain; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        48, 36, 12,
    };
    return t[i];
}

inline int sapHutCommanderCount() {
    // obeys the one first using a key phrase
    return 1;
}

inline int sapHutCallRangeLeagues() {
    // comes to a call from 1 league away
    return 1;
}

inline int sapHutLegAttacksPerRound() {
    // the legs deliver blows, 2 attacks per round
    return 2;
}

inline int sapHutLegArmorClass() {
    // the legs are armor class 2
    return 2;
}

inline int sapHutLegHpEach() {
    // the legs take 48 hit points damage each
    return 48;
}

inline int sapHutLegRegenPerRound() {
    // regenerating at 1 hit point per round
    return 1;
}

inline int sapHutWallGraniteFeet() {
    // the walls equal 5 feet thick granite
    return 5;
}

inline int sapHutLegsHillGiantBlows() {
    // the leg blows equal those of a hill giant
    return 1;
}

inline int sapHutPowerTotal() {
    // 4 of I, 2 of II, 1 each of III-VI
    return 10;
}

inline int sapHutPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 2, 1, 1, 1, 1,
    };
    return t[i];
}

inline int sapCodexDamnedPages() {
    // any person reading its 99 damned pages
    return 99;
}

inline int sapCodexDoomChancePct() {
    // 99 percent certain to meet a terrible fate
    return 99;
}

inline int sapCodexPerilPerPagePct() {
    // 1 percent cumulative chance per page
    return 1;
}

inline int sapCodexTouchKillBelowLevel() {
    // destroys any character under 11th level
    return 11;
}

inline int sapCodexCommandMinLevel() {
    // 11th or higher save versus magic to command
    return 11;
}

inline int sapCodexPerusalActivation() {
    // powers activate per the progress of perusal
    return 1;
}

inline int sapCodexPowerTotal() {
    // 4 each of I-II, 2 each of III-VI
    return 16;
}

inline int sapCodexPowerCount(int i) {
    // the powers per table I-VI; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 4, 2, 2, 2, 2,
    };
    return t[i];
}

}  // namespace rules