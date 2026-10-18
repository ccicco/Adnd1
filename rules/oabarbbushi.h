// =========================================================================================
// Adnd1 - rules/oabarbbushi.h
// THE BARBARIAN AND BUSHI, printed capture pp. 23-28 - the OA class run opens
// census 541 -> 542.
//
// verified against capture pp. 23-28 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages), with the 2018-print settling
// capture consulted for the contested horde cell: the first capture prints
// 1112 times the leader level - the 2018 print reads 1 1/2 times CLEAN;
// pinned as the 3-over-2 pair. Other settled garbles: hone/tells read as
// horse/tents, hulling as hunting, five as live - prose only, the numbers
// read clean. The Table 15 bonus rows pin as a coded grid (each lifted
// restriction its own code const) with the save bonuses as their own column.
// This round also carries the R618 v3 adjudication amendment folded in
// (comment-only, no data changes).
//
// the gap census after this round: 33 closed, 202 open - the barbarian and
// bushi boxes with Tables 14-17 flip (census 541 -> 542); NEXT - R620: the
// Kensai - the favored-weapon doctrine, the honor code, the ki powers, Tables
// 18 and 19, prefix dgg (verify free), audit "R620 OA kensai audit", include
// after rules/oabarbbushi.h
//
namespace rules {

// ---- the barbarian doctrine pins ----

// Barbarian prose (capture p. 23): no prime requisite - barbarians never gain
// an experience bonus
inline bool dgfBarbNoPrime()
    { return true; }

// Barbarian prose (capture p. 23): barbarians cannot be lawful; humans and
// korobokuru only
inline bool dgfBarbNotLawful()
    { return true; }

// Barbarian prose (capture p. 23): the 12-sided hit die, one per level
inline int dgfBarbHitDie()
    { return 12; }

// Barbarian prose (capture p. 23): the fighter combat and saving throw
// tables; any weapons and armor
inline bool dgfBarbFighterTables()
    { return true; }

// Barbarian prose (capture p. 23): +2 hit points per level for every point of
// Constitution over 14 - instead of the Table 4 bonuses
inline int dgfBarbConHpBonus()
    { return 2; }

// Barbarian prose (capture p. 23): the Constitution threshold for the
// +2-per-point bonus
inline int dgfBarbConThreshold()
    { return 14; }

// Barbarian prose (capture p. 24): at low levels no magical items, only a few
// at higher levels - the Table 15 ladder lifts the restrictions
inline bool dgfBarbMagicHatred()
    { return true; }

// Barbarian prose (capture p. 24): no experience for discovering or
// possessing magical items
inline bool dgfBarbNoXpForItems()
    { return true; }

// Barbarian prose (capture p. 24): destroying a magical item earns its full
// experience value
inline bool dgfBarbXpForDestroying()
    { return true; }

// Barbarian prose (capture p. 24): at low levels wu jen and spirit folk are
// deadly foes; even at high levels viewed with suspicion
inline bool dgfBarbWuJenFoes()
    { return true; }

// ---- the barbarian capability pins ----

// Barbarian capabilities (capture p. 24): climb trees and natural cliffs per
// Table 16; smooth surfaces at one-half the listed chance
inline bool dgfBarbClimbSmoothHalf()
    { return true; }

// Barbarian capabilities (capture p. 24): hide in familiar natural
// surroundings per Table 16; unfamiliar terrain at one-half
inline bool dgfBarbHideUnfamiliarHalf()
    { return true; }

// Barbarian capabilities (capture p. 24): 3 in 6 to surprise, surprised only
// on a 1
inline int dgfBarbSurpriseDie()
    { return 6; }

// Barbarian capabilities (capture p. 24): the 3-in-6 surprise chance
inline int dgfBarbSurpriseChance()
    { return 3; }

// Barbarian capabilities (capture p. 24): back protection - 5 percent per
// level to detect the attacker
inline int dgfBarbBackProtPerLevel()
    { return 5; }

// Barbarian capabilities (capture p. 24): a detected rear attack loses its
// bonuses and the barbarian gets a free attack at the end of the round, not
// counting against his normal attacks
inline bool dgfBarbBackProtFreeAttack()
    { return true; }

// Barbarian capabilities (capture p. 24): the standing leap - 10 feet forward
inline int dgfBarbLeapFwd()
    { return 10; }

// Barbarian capabilities (capture p. 24): the standing leap - 3 feet backward
inline int dgfBarbLeapBack()
    { return 3; }

// Barbarian capabilities (capture p. 24): the standing leap - 3 feet upward
inline int dgfBarbLeapUp()
    { return 3; }

// Barbarian capabilities (capture p. 24): the running leap - 15 + 1d6 feet
// forward
inline int dgfBarbRunLeapBase()
    { return 15; }

// Barbarian capabilities (capture p. 24): the running forward-leap die
inline int dgfBarbRunLeapDie()
    { return 6; }

// Barbarian capabilities (capture p. 24): the running leap upward - 4 + 1d4
// feet, each pip six inches
inline int dgfBarbRunLeapUpBase()
    { return 4; }

// Barbarian capabilities (capture p. 24): the running upward-leap die
inline int dgfBarbRunLeapUpDie()
    { return 4; }

// Barbarian capabilities (capture p. 24): detect illusion - 5 percent per
// level, one round of concentration
inline int dgfBarbDetIllusionPerLevel()
    { return 5; }

// Barbarian capabilities (capture p. 24): the detect-illusion cap - never
// greater than 75 percent
inline int dgfBarbDetIllusionCap()
    { return 75; }

// Barbarian capabilities (capture p. 24): detect magic - a base 25 percent
// plus 5 percent per level, one round of concentration, spells and items but
// not spellcasters
inline int dgfBarbDetMagicBase()
    { return 25; }

// ---- the Table 14 and Table 16 grids ----

// Table 14 (capture p. 24): eleven rows, levels 1-11
inline int dgfT14RowCount()
    { return 11; }

// the experience column: the upper xp bound of each level, 4,000 at 1st
// doubling to 1,900,000 at 11th (capture p. 24).
inline int dgfT14XpMax(int b)
    {
        switch (b) {
        case 0:
            return 4000;
        case 1:
            return 8000;
        case 2:
            return 16000;
        case 3:
            return 32000;
        case 4:
            return 75000;
        case 5:
            return 130000;
        case 6:
            return 240000;
        case 7:
            return 460000;
        case 8:
            return 900000;
        case 9:
            return 1400000;
        case 10:
            return 1900000;
        default:
            return -99;
        }
    }

// the accumulated d12 dice column: one die per level through 8th, then held
// at 8 (capture p. 24).
inline int dgfT14Dice(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 8;
        default:
            return -99;
        }
    }

// the hit-point bonus column: the printed 8-plus-N cells - 4 per level beyond
// 8th: 0 through 8th, then 4, 8, 12 (capture p. 24).
inline int dgfT14HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 8;
        case 10:
            return 12;
        default:
            return -99;
        }
    }

// Table 14 note (capture p. 24): 500,000 experience points per level beyond
// 11th
inline int dgfT14XpBeyond()
    { return 500000; }

// Table 14 note (capture p. 24): 4 hit points per level beyond 8th
inline int dgfT14HpBeyond()
    { return 4; }

// Table 16 (capture p. 25): eleven rows, levels 1-11
inline int dgfT16RowCount()
    { return 11; }

// the climb column: 85 percent at 1st rising one per level to 95 at 11th
// (capture p. 25).
inline int dgfT16Climb(int b)
    {
        switch (b) {
        case 0:
            return 85;
        case 1:
            return 86;
        case 2:
            return 87;
        case 3:
            return 88;
        case 4:
            return 89;
        case 5:
            return 90;
        case 6:
            return 91;
        case 7:
            return 92;
        case 8:
            return 93;
        case 9:
            return 94;
        case 10:
            return 95;
        default:
            return -99;
        }
    }

// the hide column: 25 at 1st rising in 6-7 percent steps to 93 at 11th
// (capture p. 25).
inline int dgfT16Hide(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 31;
        case 2:
            return 37;
        case 3:
            return 43;
        case 4:
            return 49;
        case 5:
            return 56;
        case 6:
            return 63;
        case 7:
            return 70;
        case 8:
            return 77;
        case 9:
            return 85;
        case 10:
            return 93;
        default:
            return -99;
        }
    }

// the back protection column: 5 per level, 5 to 55 (capture p. 25).
inline int dgfT16BackProt(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 35;
        case 7:
            return 40;
        case 8:
            return 45;
        case 9:
            return 50;
        case 10:
            return 55;
        default:
            return -99;
        }
    }

// the detect illusion column: 5 per level, 5 to 55 - capped at 75 by the
// prose (capture p. 25).
inline int dgfT16DetIllusion(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 35;
        case 7:
            return 40;
        case 8:
            return 45;
        case 9:
            return 50;
        case 10:
            return 55;
        default:
            return -99;
        }
    }

// the detect magic column: 30 at 1st rising 5 per level to 80 at 11th
// (capture p. 25).
inline int dgfT16DetMagic(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 35;
        case 2:
            return 40;
        case 3:
            return 45;
        case 4:
            return 50;
        case 5:
            return 55;
        case 6:
            return 60;
        case 7:
            return 65;
        case 8:
            return 70;
        case 9:
            return 75;
        case 10:
            return 80;
        default:
            return -99;
        }
    }

// ---- the Table 15 bonuses grid ----

// Table 15 (capture p. 25): ten bonus rows, levels 3-12
inline int dgfT15RowCount()
    { return 10; }

// Table 15 code (capture p. 25): level 3 - can use magical potions
inline int dgfB15Potions()
    { return 1; }

// Table 15 code (capture p. 25): level 4 - can use magical weapons, +1 on
// saves vs. spell
inline int dgfB15WeaponsSave()
    { return 2; }

// Table 15 code (capture p. 25): level 5 - can use magical armor
inline int dgfB15Armor()
    { return 3; }

// Table 15 code (capture p. 25): level 6 - half experience with wu jen and
// spirit folk companions
inline int dgfB15HalfXp()
    { return 4; }

// Table 15 code (capture p. 25): level 7 - can use weapon-like miscellaneous
// magical items
inline int dgfB15MiscItems()
    { return 5; }

// Table 15 code (capture p. 25): level 8 - full experience with wu jen and
// spirit folk companions
inline int dgfB15FullXp()
    { return 6; }

// Table 15 code (capture p. 25): level 9 - can use protection scrolls (if he
// can read)
inline int dgfB15Scrolls()
    { return 7; }

// Table 15 code (capture p. 25): level 10 - +2 on saves vs. spell
inline int dgfB15SaveTwo()
    { return 8; }

// Table 15 code (capture p. 25): level 11 - can summon a barbarian horde
inline int dgfB15Horde()
    { return 9; }

// Table 15 code (capture p. 25): level 12 - +3 on saves vs. spell
inline int dgfB15SaveThree()
    { return 10; }

// the level column: 3 through 12 (capture p. 25).
inline int dgfT15Level(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 11;
        case 9:
            return 12;
        default:
            return -99;
        }
    }

// the bonus code column: potions 1, weapons 2, armor 3, half xp 4, misc items
// 5, full xp 6, scrolls 7, save two 8, horde 9, save three 10 (capture p.
// 25).
inline int dgfT15Bonus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the save bonus column: +1 at level 4, +2 at 10, +3 at 12, zero elsewhere
// (capture p. 25).
inline int dgfT15SaveBonus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 3;
        default:
            return -99;
        }
    }

// ---- the territory and horde pins ----

// Steppeland prose (capture p. 26): sixteen proficiencies - horsemanship,
// long-distance signaling, outdoor craft, tracking, animal handling, weapon
// smith, armorer, bowyer, running, dancing, singing, weaving, tanning, sound
// imitation, survival, chanting
inline int dgfSteppeProfCount()
    { return 16; }

// Steppeland prose (capture p. 26): four preferred weapons - light lance,
// horsebow, sword, hand axe
inline int dgfSteppeWeaponCount()
    { return 4; }

// Steppeland prose (capture p. 26): roving nomads, masters of the horse -
// leather tents, migratory herds, no agriculture (the capture prints hone and
// tells; the 2018 print reads horse and tents clean)
inline bool dgfSteppeNomads()
    { return true; }

// Forest prose (capture p. 26): eighteen proficiencies - small water craft,
// fishing, tracking, survival, animal handling, weapon smithing, pottery,
// bowyer, sound imitation, snare building, weaving, tanning, carpentry,
// agriculture, singing, chanting, dancing, rhetoric
inline int dgfForestProfCount()
    { return 18; }

// Forest prose (capture p. 26): five preferred weapons - spear, shortbow,
// hand axe, harpoon, sword
inline int dgfForestWeaponCount()
    { return 5; }

// Forest prose (capture p. 26): small permanent villages - the women raise
// crops, the men hunt and fish
inline bool dgfForestVillages()
    { return true; }

// Jungle prose (capture p. 26): sixteen proficiencies - small water craft,
// fishing, swimming, survival, animal handling, carpentry, weapon smith,
// armorer, sound imitation, snare building, pottery, tracking, chanting,
// dancing, music, sailing craft
inline int dgfJungleProfCount()
    { return 16; }

// Jungle prose (capture p. 26): five preferred weapons - blowgun, spear,
// sword, hand axe, dagger
inline int dgfJungleWeaponCount()
    { return 5; }

// Jungle prose (capture p. 26): permanent villages - gathering jungle plants,
// hunting wild animals and fishing (the capture prints hulling; read as
// hunting)
inline bool dgfJungleVillages()
    { return true; }

// Barbarian prose (capture p. 26): automatic outsiders - the lowest caste,
// never roll on Table 38; clan membership required
inline bool dgfBarbOutsiders()
    { return true; }

// The Barbarian Horde (capture p. 26): summonable from 11th level - only in
// the native territory, from those of the background
inline int dgfHordeLevel()
    { return 11; }

// The Barbarian Horde (capture p. 26): the horde size - the leader experience
// points divided by 2,000, capped by the eligible population
inline int dgfHordeXpDiv()
    { return 2000; }

// The Barbarian Horde (capture p. 26): one aide per 500 men (or fraction) at
// one-half the leader levels; each aide with two assistants at one-half the
// aide level
inline int dgfHordeAidePerMen()
    { return 500; }

// The Barbarian Horde (capture p. 26): witch doctors or shamans as
// appropriate - helpful spells but prone to meddling and fomenting unrest
inline bool dgfHordeShamans()
    { return true; }

// The Barbarian Horde (capture p. 26): assembles at 500 men per week at a
// predesignated home point
inline int dgfHordeAssemblePerWeek()
    { return 500; }

// The Barbarian Horde (capture p. 26): one clearly stated purpose,
// unchangeable - changing it or weeks of inactivity disbands the horde
inline bool dgfHordePurposeFixed()
    { return true; }

// The Barbarian Horde (capture p. 26): holds together for weeks equal to the
// leader level; each week beyond needs a successful appeal reaction check
inline bool dgfHordeWeeksEqualLevel()
    { return true; }

// The Barbarian Horde (capture p. 26): no horde remains together beyond 1 1/2
// times the leader level - the numerator 3 over the divisor 2 (the capture
// prints 1112; the 2018-print settling capture reads 1 1/2 clean)
inline int dgfHordeMaxWeeksNum()
    { return 3; }

// The Barbarian Horde (capture p. 26): the 1 1/2 times divisor
inline int dgfHordeMaxWeeksDen()
    { return 2; }

// The Barbarian Horde (capture pp. 26-27): a successful campaign disbands to
// a hero welcome - a new horde raises easily; disaster means no second horde
// and a poor welcome home
inline bool dgfHordeSuccessLegacy()
    { return true; }

// ---- the bushi doctrine and Table 17 grid ----

// Bushi prose (capture p. 27): masterless warriors - mercenaries, bandits,
// highwaymen, wanderers; mostly low birth choosing the way of the warrior
inline bool dgfBushiMasterless()
    { return true; }

// Bushi prose (capture p. 27): Strength is the prime requisite - Str 14 or
// greater earns the 10 percent bonus (the printed 550-to-605 example); any
// alignment or race
inline bool dgfBushiStrPrime()
    { return true; }

// Bushi prose (capture p. 27): the 10-sided hit die, one per level
inline int dgfBushiHitDie()
    { return 10; }

// Bushi prose (capture p. 27): the fighter combat and saving throw tables;
// any armor and weapon
inline bool dgfBushiFighterTables()
    { return true; }

// Bushi prose (capture p. 27): ninja preferred weapons lose honor - but not
// as much as a samurai
inline bool dgfBushiNinjaHonor()
    { return true; }

// Bushi prose (capture p. 27): high Strength and Constitution earn the normal
// fighter bonuses
inline bool dgfBushiFighterBonuses()
    { return true; }

// Bushi prose (capture p. 27): four initial proficiency slots; single-weapon
// specialization chosen at creation
inline int dgfBushiSlots()
    { return 4; }

// Bushi prose (capture p. 27): the poverty proficiencies - weaponsmith,
// armorer and bowyer free at start
inline int dgfBushiPoorProfCount()
    { return 3; }

// Bushi prose (capture p. 27): armor class improves one step per five
// experience levels, stacked on the Dexterity adjustment, worn armor or not
inline int dgfBushiAcStepLevels()
    { return 5; }

// Table 17 (capture p. 27): twelve rows, levels 1-12
inline int dgfT17RowCount()
    { return 12; }

// the experience column: the upper xp bound of each level, 1,500 at 1st to
// 1,250,000 at 12th (capture p. 27).
inline int dgfT17XpMax(int b)
    {
        switch (b) {
        case 0:
            return 1500;
        case 1:
            return 3000;
        case 2:
            return 6000;
        case 3:
            return 14000;
        case 4:
            return 30000;
        case 5:
            return 60000;
        case 6:
            return 120000;
        case 7:
            return 240000;
        case 8:
            return 480000;
        case 9:
            return 710000;
        case 10:
            return 1000000;
        case 11:
            return 1250000;
        default:
            return -99;
        }
    }

// the accumulated d10 dice column: one per level through 9th, then held at 9
// (capture p. 27).
inline int dgfT17Dice(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 9;
        case 11:
            return 9;
        default:
            return -99;
        }
    }

// the hit-point bonus column: the printed 9-plus-N cells - 2 per level beyond
// 9th: 0 through 9th, then 2, 4, 6 (capture p. 27).
inline int dgfT17HpBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 6;
        default:
            return -99;
        }
    }

// Table 17 note (capture p. 27): 250,000 experience points per level beyond
// 12th
inline int dgfT17XpBeyond()
    { return 250000; }

// Table 17 note (capture p. 27): 2 hit points per level beyond 9th
inline int dgfT17HpBeyond()
    { return 2; }

}   // namespace rules
