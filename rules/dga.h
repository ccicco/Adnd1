// =========================================================================================
// Adnd1 - rules/dga.h
// the DDG front matter - the arc opener. DEITIES & DEMIGODS, the 1980 second
// printing (Ward with Kuntz), print pp. 1-11: the front matter walk.
// census 771 -> 772.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1); the physical-copy eyeball settled the
// strength 23 damage +11, the psionic roman numerals I-VI and the class V
// lettered mode lists (A,B,C,E attack, F,G,H defense); the archive.org L&L
// parity voice is lending-gated and was not obtainable.
//
// the odPd 0 sentinel encodes the single-number open-doors parentheses (five
// rows); the wisdom loLvl/loCnt 0 pair encodes the two-spell rows (23, 24);
// the constitution regen 0 is the Nil row; the psionic class VI row is all 0
// with the asterisked invulnerability noted in the bools.
//
namespace rules {

// ---- the R849 census ----

// the DDG front matter round: the D&DG arc opener, print pp. 1-11 (Curtiss go
// on the landed R848)
inline int dgaRound()
    { return 849; }

// DEITIES & DEMIGODS, the 1980 second printing (TSR 2017, Ward with Kuntz,
// Schick editor)
inline int dgaPrintYear()
    { return 1980; }

// the 17 mythoi of the contents walk (American Indian through Sumerian,
// Cthulhu and Melnibonean included)
inline int dgaMythoiCount()
    { return 17; }

// the front matter opens at print p. 1
inline int dgaFrontMatterStart()
    { return 1; }

// the front matter ends at print p. 11 (the divine ascension section)
inline int dgaFrontMatterEnd()
    { return 11; }

// the nine over-18 and doctrine grids pinned this round
inline int dgaTableCount()
    { return 9; }

// the one chain pinned this round (the monster intelligence ladder)
inline int dgaChainCount()
    { return 1; }

// ZERO registry defs touched this round (a doctrine round, the floor holds at
// 995)
inline int dgaRegistryFloor()
    { return 995; }

// the strength table rows (scores 19-25)
inline int dgaStrRows()
    { return 7; }

// the wisdom table rows (scores 19-25)
inline int dgaWisRows()
    { return 7; }

// the intelligence table rows (scores 19-25)
inline int dgaIntRows()
    { return 7; }

// the dexterity table rows (scores 19-25)
inline int dgaDexRows()
    { return 7; }

// the constitution table rows (scores 19-25)
inline int dgaConRows()
    { return 7; }

// the charisma table rows (scores 19-25)
inline int dgaChaRows()
    { return 7; }

// the negative-charisma horror table rows (scores -1 to -7)
inline int dgaHorrorRows()
    { return 7; }

// the psionic class table rows (classes I-VI*)
inline int dgaPsiRows()
    { return 6; }

// the divine intervention modifier rows
inline int dgaIntModsRows()
    { return 6; }

// ---- the preface and foreword doctrine ----

// all the leaders of the pantheons were given 400 hit points, the rest scaled
// down from there (the preface)
inline int dgaPantheonLeadersHp()
    { return 400; }

// the foreword thesis: do not fall into the error of regarding it as a
// supplement - it is integral to Dungeon Mastering a true AD&D campaign
inline bool dgaNotSupplement()
    { return true; }

// deities are presented in pantheons; the DM selects which ones,
// combinations, or parts of pantheons suit the campaign
inline bool dgaForewordPantheonSelection()
    { return true; }

// the book includes major, minor, and almost-gods (demigods), plus a few
// divine monsters and magic items
inline bool dgaDemigodsIncluded()
    { return true; }

// characters who become a match for the deities are to be ranked amongst
// their number and removed from daily campaign interaction (the ascension
// seed in the foreword)
inline bool dgaMatchForDeitiesAscended()
    { return true; }

// three-fourths of the information was drawn from knowledgeable sources
// rather than the imagination of the authors (the preface)
inline bool dgaThreeFourthsSourced()
    { return true; }

// when a being was made too all-powerful in AD&D terms we scaled them down to
// be compatible in game terms (the preface)
inline bool dgaScaledDown()
    { return true; }

// the book should be used as a beginning framework for the DM - sample it and
// take what is wanted (the preface)
inline bool dgaBeginningFramework()
    { return true; }

// special thanks are given to Chaosium, Inc. for permission to use the
// Cthulhu Mythos and the Melnibonean Mythos material (print p. 4, the
// credits)
inline bool dgaChaosiumCredit()
    { return true; }

// the Chaosium credit is present, the only 1st-vs-2nd printing delta - the
// upload is the 1980 second printing
inline bool dgaSecondPrinting()
    { return true; }

// ---- the explanatory notes doctrine ----

// very rare indicates a 4% chance of occurrence (the explanatory notes)
inline int dgaFreqVeryRare()
    { return 4; }

// rare indicates an 11% chance of occurrence
inline int dgaFreqRare()
    { return 11; }

// uncommon indicates a 20% chance of occurrence
inline int dgaFreqUncommon()
    { return 20; }

// common indicates a 65% chance of occurrence
inline int dgaFreqCommon()
    { return 65; }

// magic resistance is based on the spell being cast by an 11th level
// spell-caster
inline int dgaMrCasterBase()
    { return 11; }

// magic resistance adjusts 5% per level above or below the 11th level base
inline int dgaMrPerLevel()
    { return 5; }

// the magic ability and psionic discipline level floor for demigods (15th)
inline int dgaLevelFloorDemi()
    { return 15; }

// the level floor for lesser gods (20th)
inline int dgaLevelFloorLesser()
    { return 20; }

// the level floor for greater gods (25th)
inline int dgaLevelFloorGreater()
    { return 25; }

// the gods psionic abilities fall into six standardized classes (I-VI)
inline int dgaPsiClasses()
    { return 6; }

// unique indicates that there is only one of the creature in existence
inline bool dgaFreqUnique()
    { return true; }

// number appearing is furnished as a guideline only, not generally
// recommended for establishing dungeon level populations
inline bool dgaNumAppearingGuideline()
    { return true; }

// a god or hero armor class may not jibe with stated armor and dexterity due
// to the magical nature of the being
inline bool dgaAcMagicalNature()
    { return true; }

// a doubled move number indicates the creature can travel in two mediums or
// modes (flying, swimming, burrowing, web)
inline bool dgaMoveTwoMediums()
    { return true; }

// infinite movement is a sort of continuous no-error teleport ability to any
// point desired
inline bool dgaInfiniteMoveTeleport()
    { return true; }

// hit points killed for a deity means temporarily banished back to its plane
// of origin, not measure of attack ability
inline bool dgaDeityHpBanish()
    { return true; }

// magic resistance is the percentage chance of a spell absolutely failing, at
// the 11th level base, adjusted 5% per level either way
inline bool dgaMrStandardDoctrine()
    { return true; }

// a creature magic resistance extends only to its immediate possessions -
// anything carried or worn
inline bool dgaMrPossessionsOnly()
    { return true; }

// area-effect spells will still function if targeted, even against a
// magic-resistant creature
inline bool dgaMrAreaEffectNote()
    { return true; }

// even if a spell does affect a magic-resistant creature, it is entitled to
// normal saving throws if applicable
inline bool dgaMrSavesStillApply()
    { return true; }

// the five-slot class grid: CLERIC/DRUID, FIGHTER, MAGIC-USER/ILLUSIONIST,
// THIEF/ASSASSIN, MONK/BARD - Nth level X or Nil (the stat block format)
inline bool dgaClassGridDoctrine()
    { return true; }

// deity stat blocks list hit POINTS, not hit dice (the stat block format
// finding)
inline bool dgaHitPointsNotDice()
    { return true; }

// wisdom spell bonuses apply to the number of spells a divine CLERIC/DRUID
// can have
inline bool dgaWisdomSpellBonusesApply()
    { return true; }

// a divine being need not be of neutral alignment to have levels of druidical
// ability
inline bool dgaDruidNeedNotNeutral()
    { return true; }

// nothing prevents deities from functioning in several different
// apparently-inconsistent classes at once
inline bool dgaMultiClassInconsistent()
    { return true; }

// the deity magic-ability level is its highest class level, unless that is
// less than the 15/20/25 floor by divine rank
inline bool dgaMagicLevelFloor()
    { return true; }

// the strength score is always followed in parentheses by the being bonus to
// hit and damage, corresponding to the over-18 table
inline bool dgaStrengthParen()
    { return true; }

// deities are not always constrained to follow their alignment to the letter
// - their motives and purposes are far above the mortal
inline bool dgaDeityAlignmentLoose()
    { return true; }

// the alignment of the deity clerics must be identical with their patron (the
// explanatory notes)
inline bool dgaClericAlignIdentical()
    { return true; }

// size is abbreviated S (smaller than human), M (man-sized), L (larger than
// man-sized with greater mass)
inline bool dgaSizeThreeFold()
    { return true; }

// the intelligence illusion/phantasm immunities are cumulative with higher
// intelligence
inline bool dgaIntIllusionCumulative()
    { return true; }

// beings of very high intelligence will not be fooled by illusion/phantasm
// spells - a 19 intelligence never believes a 1st level illusion
inline bool dgaIntNeverFooled()
    { return true; }

// the wisdom spell immunities are cumulative with higher wisdom
inline bool dgaWisdomImmunitiesCumulative()
    { return true; }

// beings with high wisdom are simply able to automatically throw off the
// effects of the immune spells
inline bool dgaWisdomAutoThrowOff()
    { return true; }

// the dexterity thief-skill columns (picking pockets, open locks, traps, move
// silently, hide) apply only to beings with thief, assassin or monk abilities
inline bool dgaDexThiefColsNote()
    { return true; }

// the constitution no-1s doctrine: 1s rolled on hit dice count as 2s; at
// 21-22 the 1s and 2s count as 3s, and so on
inline bool dgaConRerollDoctrine()
    { return true; }

// beings without fighter, paladin or ranger class receive no more than 2
// bonus hit points per die
inline bool dgaConNonFighterCap2()
    { return true; }

// the awe power applies only to divine beings (gods and demigods) - mortals
// with godlike charisma do not radiate it
inline bool dgaAweDivineOnly()
    { return true; }

// the awe stun works through any control up to and including a magic jar
// spell, with no saving throw
inline bool dgaAweStunNoSave()
    { return true; }

// creatures stunned by awe can initiate nothing but physical defense if
// attacked
inline bool dgaAweStunnedDefendOnly()
    { return true; }

// the horror aura applies only to the truly ghastly divine beings - a cursed
// non-divine negative charisma does not confer it
inline bool dgaHorrorDivineOnly()
    { return true; }

// a horror-stunned creature can do nothing but defend itself physically until
// the being leaves sight
inline bool dgaHorrorDefendOnly()
    { return true; }

// beings with negative charisma will never have henchmen of a normal nature
inline bool dgaNegativeChaNoHenchmen()
    { return true; }

// psionic disciplines function at a minimum level of 15th for demigods, 20th
// for lesser gods and 25th for greater gods
inline bool dgaPsionicLevelFloor()
    { return true; }

// the monster intelligence rating ladder (the explanatory notes): band 0
// non-intelligent or not ratable, 1 animal, 2 semi-intelligent (2-4), 3 low
// (5-7), 4 average human (8-10), 5 very intelligent (11-12), 6 highly
// intelligent (13-14), 7 exceptionally intelligent (15-16), 8 genius (17-18),
// 9 supra-genius (19-20), and the tail band 10 godlike (21 and above)
inline int dgaIntRating(int x)
    {
        if (x <= 0) return 0;
        if (x <= 1) return 1;
        if (x <= 4) return 2;
        if (x <= 7) return 3;
        if (x <= 10) return 4;
        if (x <= 12) return 5;
        if (x <= 14) return 6;
        if (x <= 16) return 7;
        if (x <= 18) return 8;
        if (x <= 20) return 9;
        return 10;
    }

// ---- the nine over-18 and doctrine grids ----

// The strength score cells (19-25, the over-18 doctrine)
inline int dgaStrScore(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 21;
        case 3:
            return 22;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// The to-hit bonus cells (the parenthesized first figure)
inline int dgaStrToHit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return 0;
        }
    }

// The damage bonus cells (the parenthesized second figure; the 23 row reads
// +11 - the physical-copy eyeball against a +1 misread)
inline int dgaStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
        case 2:
            return 9;
        case 3:
            return 10;
        case 4:
            return 11;
        case 5:
            return 12;
        case 6:
            return 14;
        default:
            return 0;
        }
    }

// The weight allowance cells (gold piece weight)
inline int dgaStrWt(int b)
    {
        switch (b) {
        case 0:
            return 4500;
        case 1:
            return 5000;
        case 2:
            return 6000;
        case 3:
            return 7500;
        case 4:
            return 9000;
        case 5:
            return 12000;
        case 6:
            return 15000;
        default:
            return 0;
        }
    }

// The open-doors numerator cells (the 1-in-N figure)
inline int dgaStrOdN(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 11;
        case 4:
            return 11;
        case 5:
            return 19;
        case 6:
            return 23;
        default:
            return 0;
        }
    }

// The open-doors denominator cells
inline int dgaStrOdD(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 10;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 20;
        case 6:
            return 24;
        default:
            return 0;
        }
    }

// The parenthesized open-doors numerator cells (odPd 0 = a single
// parenthesized number, the no-paren rows)
inline int dgaStrOdPn(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 7;
        case 6:
            return 9;
        default:
            return 0;
        }
    }

// The parenthesized open-doors denominator cells (0 = none printed)
inline int dgaStrOdPd(int b)
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
            return 8;
        case 6:
            return 10;
        default:
            return 0;
        }
    }

// The bend bars/lift gates percent cells (with the giant-comparison column
// noted in the header comment)
inline int dgaStrBendPct(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 60;
        case 2:
            return 70;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 100;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The intelligence score cells (19-25)
inline int dgaIntScore(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 21;
        case 3:
            return 22;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// The chance-to-know-a-spell percent cells
inline int dgaIntKnowPct(int b)
    {
        switch (b) {
        case 0:
            return 95;
        case 1:
            return 96;
        case 2:
            return 97;
        case 3:
            return 98;
        case 4:
            return 99;
        case 5:
            return 100;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The minimum spells per level cells (11-17)
inline int dgaIntMinSpells(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 14;
        case 4:
            return 15;
        case 5:
            return 16;
        case 6:
            return 17;
        default:
            return 0;
        }
    }

// The illusion/phantasm immunity level cells (1st-7th level illusions
// disbelieved)
inline int dgaIntIllusLvl(int b)
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
        default:
            return 0;
        }
    }

// The wisdom score cells (19-25)
inline int dgaWisScore(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 21;
        case 3:
            return 22;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// The high-level spell cells (4th, 5th, 6th, 7th by row)
inline int dgaWisHiLvl(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return 0;
        }
    }

// The high-level spell count cells (one or two)
inline int dgaWisHiCnt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The low-level spell cells (1st-4th, 0 = none at the two-spell rows)
inline int dgaWisLoLvl(int b)
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
            return 0;
        case 5:
            return 0;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// The low-level spell count cells (0 = none at the two-spell rows)
inline int dgaWisLoCnt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The dexterity score cells (19-25)
inline int dgaDexScore(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 21;
        case 3:
            return 22;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// The reaction/attacking adjustment cells (+3 to +5)
inline int dgaDexReact(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 5;
        default:
            return 0;
        }
    }

// The defensive adjustment cells (-4 to -6)
inline int dgaDexDef(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -4;
        case 2:
            return -5;
        case 3:
            return -5;
        case 4:
            return -5;
        case 5:
            return -6;
        case 6:
            return -6;
        default:
            return 0;
        }
    }

// The picking pockets bonus percent cells (thief cols)
inline int dgaDexPockets(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 30;
        case 4:
            return 35;
        case 5:
            return 40;
        case 6:
            return 45;
        default:
            return 0;
        }
    }

// The open locks bonus percent cells
inline int dgaDexLocks(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 45;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// The locate/remove traps bonus percent cells
inline int dgaDexTraps(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 30;
        case 5:
            return 35;
        case 6:
            return 40;
        default:
            return 0;
        }
    }

// The move silently bonus percent cells
inline int dgaDexSilent(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 18;
        case 3:
            return 20;
        case 4:
            return 23;
        case 5:
            return 25;
        case 6:
            return 30;
        default:
            return 0;
        }
    }

// The hiding in shadows bonus percent cells
inline int dgaDexHide(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 15;
        case 2:
            return 18;
        case 3:
            return 20;
        case 4:
            return 23;
        case 5:
            return 25;
        case 6:
            return 30;
        default:
            return 0;
        }
    }

// The constitution score cells (19-25)
inline int dgaConScore(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 21;
        case 3:
            return 22;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// The hit point adjustment cells (+5 to +7, the no-1s doctrine per the bool)
inline int dgaConHpAdj(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 7;
        default:
            return 0;
        }
    }

// The poison save adjustment cells (+1 to +4)
inline int dgaConPoisonSave(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 4;
        default:
            return 0;
        }
    }

// The regeneration turn cells (1 point per N turns; 0 = the Nil row)
inline int dgaConRegenTurns(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
        default:
            return 0;
        }
    }

// The charisma score cells (19-25)
inline int dgaChaScore(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 21;
        case 3:
            return 22;
        case 4:
            return 23;
        case 5:
            return 24;
        case 6:
            return 25;
        default:
            return 0;
        }
    }

// The maximum henchmen cells (20-50)
inline int dgaChaHench(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 45;
        case 6:
            return 50;
        default:
            return 0;
        }
    }

// The loyalty base cells (50-100 percent)
inline int dgaChaLoyalty(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 60;
        case 2:
            return 70;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 100;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// The reaction adjustment cells (40-70 percent)
inline int dgaChaReact(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 45;
        case 2:
            return 50;
        case 3:
            return 55;
        case 4:
            return 60;
        case 5:
            return 65;
        case 6:
            return 70;
        default:
            return 0;
        }
    }

// The awe power cells (up to N HD/levels stunned)
inline int dgaChaAweHd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 8;
        case 5:
            return 10;
        case 6:
            return 12;
        default:
            return 0;
        }
    }

// The negative charisma score cells (-1 to -7)
inline int dgaHorScore(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -2;
        case 2:
            return -3;
        case 3:
            return -4;
        case 4:
            return -5;
        case 5:
            return -6;
        case 6:
            return -7;
        default:
            return 0;
        }
    }

// The reaction adjustment cells (-40 to -70 percent)
inline int dgaHorReact(int b)
    {
        switch (b) {
        case 0:
            return -40;
        case 1:
            return -45;
        case 2:
            return -50;
        case 3:
            return -55;
        case 4:
            return -60;
        case 5:
            return -65;
        case 6:
            return -70;
        default:
            return 0;
        }
    }

// The horror cells (up to N HD/levels stunned with fear and detestation)
inline int dgaHorHd(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 8;
        case 5:
            return 10;
        case 6:
            return 12;
        default:
            return 0;
        }
    }

// The psionic class cells (I-VI, the physical-copy roman-numeral
// adjudication)
inline int dgaPsiCls(int b)
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
        default:
            return 0;
        }
    }

// The psionic strength range lower bound cells
inline int dgaPsiStrLo(int b)
    {
        switch (b) {
        case 0:
            return 326;
        case 1:
            return 276;
        case 2:
            return 236;
        case 3:
            return 181;
        case 4:
            return 91;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The psionic strength range upper bound cells
inline int dgaPsiStrHi(int b)
    {
        switch (b) {
        case 0:
            return 365;
        case 1:
            return 315;
        case 2:
            return 265;
        case 3:
            return 210;
        case 4:
            return 110;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The minor discipline count cells (5 down to 2; 0 = the Nil class VI row)
inline int dgaPsiMinDis(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The major discipline count cells (2 down to 1; 0 = the Nil row)
inline int dgaPsiMajDis(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The attack mode count cells (5 = All, 4 = the class V lettered list
// A,B,C,E; 0 = Nil)
inline int dgaPsiAtkCnt(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The defense mode count cells (5 = All, 3 = the class V lettered list F,G,H;
// 0 = Nil)
inline int dgaPsiDefCnt(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The modifier ordinal cells (the printed list order)
inline int dgaIntModsOrd(int b)
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
        default:
            return 0;
        }
    }

// The percent modifier cells (previous intervention 5, average alignment
// behavior 5, borderline 10, direct confrontation required 10, opposing
// diametric forces 1, serving the deity proximately 25)
inline int dgaIntModsPct(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 1;
        case 5:
            return 25;
        default:
            return 0;
        }
    }

// ---- the standard divine abilities and saves ----

// the eight standard divine abilities (command, comprehend languages, detect
// alignment, gate, geas, quest, teleport, true seeing)
inline int dgaStdAbilities()
    { return 8; }

// the command ability lasts 2 rounds for lesser gods
inline int dgaCommandLesser()
    { return 2; }

// the command ability lasts 3 rounds for greater gods
inline int dgaCommandGreater()
    { return 3; }

// the geas ability: as the spell, but with a range of 9
inline int dgaGeasRange()
    { return 9; }

// the quest ability: as the spell with a range of 9 inches, and no saving
// throw
inline int dgaQuestRange()
    { return 9; }

// all gods and demigods have a saving throw of 2 in all categories (only a 1
// on d20 misses)
inline int dgaGodSave()
    { return 2; }

// all heroes delineated in the book have saves of 3 in all categories
inline int dgaHeroSave()
    { return 3; }

// the command ability has no saving throw vs. this divine ability
inline bool dgaCommandNoSave()
    { return true; }

// the comprehend languages divine ability also grants the ability to speak or
// write the language in question
inline bool dgaComprehendSpeakWrite()
    { return true; }

// the detect alignment ability enables the deity to detect the alignment of
// objects or creatures with no error
inline bool dgaDetectAlignNoError()
    { return true; }

// the deity can only attempt to gate in other beings of the same mythos
inline bool dgaGateSameMythos()
    { return true; }

// the quest divine ability carries no saving throw
inline bool dgaQuestNoSave()
    { return true; }

// the teleport ability allows the deity to move from place to place or plane
// to plane with no error
inline bool dgaTeleportNoError()
    { return true; }

// the standard abilities all function instantaneously and at will, but not
// continuously
inline bool dgaAbilitiesAtWillNotContinuous()
    { return true; }

// the gods sometimes manifest surprising abilities - changing ability scores,
// granting wishes, teleporting others - at DM judgment
inline bool dgaBonusPowersDmJudgment()
    { return true; }

// gods and heroes saving throw numbers are irreducible regardless of magical
// aids and adjustments
inline bool dgaSavesIrreducible()
    { return true; }

// ---- the dungeon mastering and intervention doctrine ----

// the straight 10% chance some creature is sent if the beseeching character
// is exemplary and this is the first request
inline int dgaInterventionBase()
    { return 10; }

// the source of a deity godhead is connected to earthly worshipers; power
// often increases or decreases as worshiper numbers vary
inline bool dgaPowerFromWorshipers()
    { return true; }

// a human raised into the 20s by ultra-potent magic does not gain the powers
// reserved for the gods
inline bool dgaRaisedAbilitiesNoDivine()
    { return true; }

// the statistics do not tell how a deity should be played - treating gods as
// lists of armor classes reduces them to mere monsters
inline bool dgaGodsNotMonsterLists()
    { return true; }

// any god with a wisdom score above 15 knows flattery for what it is and
// generally guesses the flatterer motives
inline bool dgaFlatterySeenThrough()
    { return true; }

// gods with intelligence above 20 can often tell what action a mortal is
// about to attempt from preparatory motions
inline bool dgaInt20PredictsAction()
    { return true; }

// a god in combat always attempts to avoid physical defeat - the innate
// teleport leaves or blinks away, taking no time or concentration
inline bool dgaAvoidDefeatTeleport()
    { return true; }

// deities in combat almost always summon a retinue, and many gods then depart
// the field leaving the retinue to fight
inline bool dgaSummonAidDepart()
    { return true; }

// unless they have a history of mutual antipathy, deities are always
// unwilling to fight other deities, backing off from confrontation
inline bool dgaDeitiesAvoidEachOther()
    { return true; }

// gate spells are more likely to bring one of the god followers than the
// deity; a gate spell cannot compel a deity appearance
inline bool dgaGateBringsServants()
    { return true; }

// specific aid to individuals is extremely rare; the gods prefer subtle
// general aid to their worshipers as a whole
inline bool dgaSpecificAidRare()
    { return true; }

// the evil gods, demons and devils are prone to appear when their name is
// spoken - provided they stand to gain converts
inline bool dgaEvilGodsAppearForConverts()
    { return true; }

// intervention by a deity is no trifling matter and is not to be allowed on a
// whim, even if characters are in extremis
inline bool dgaInterventionNoWhim()
    { return true; }

// an exemplary character gets the straight 10% creature-sent chance only the
// first time help is asked
inline bool dgaFirstRequestRule()
    { return true; }

// if 00 is rolled there is a percentage chance equal to the character level
// that the deity itself comes, modified by the intervention table
inline bool dgaDeityComesOn00()
    { return true; }

// characters asked to take part in the maneuverings of the gods may actually
// become part of the intervention itself
inline bool dgaCharactersBecomeIntervention()
    { return true; }

// the intervention modifiers apply only to activities on the Prime Material
// Plane
inline bool dgaInterventionPrimeOnly()
    { return true; }

// deities will not intervene on the planes which are the habitations of other
// deities, i.e. the Outer Planes
inline bool dgaInterventionNoOuterPlanes()
    { return true; }

// deities will neither venture to involve themselves in the Positive or
// Negative Material Planes
inline bool dgaInterventionNotPosNeg()
    { return true; }

// intervention in the Elemental Planes is subject to DM option; if there are
// elemental gods, the Outer Planes deities will NOT go there
inline bool dgaInterventionElementalDmOption()
    { return true; }

// intervention occurs only on the Prime Material Plane in most cases, with
// occasional intervention in the Astral and Ethereal Planes
inline bool dgaInterventionOccasionalAstral()
    { return true; }

// ---- the clerics and spell-granting doctrine ----

// the three divine ranks: demigod, lesser god, greater god
inline int dgaDivineRanks()
    { return 3; }

// a demigod cannot grant spells above 5th level
inline int dgaDemigodMaxSpell()
    { return 5; }

// 1st and 2nd level cleric spells are gained through the cleric knowledge and
// faith, not prayer
inline bool dgaSpells12KnowledgeFaith()
    { return true; }

// 3rd, 4th and 5th level spells are granted by the supernatural servants or
// minions of the deity, ranging up to demigod level
inline bool dgaSpells345ServantsMinions()
    { return true; }

// clerics whose patrons are demigods receive their 3rd through 5th level
// spells directly from their deity
inline bool dgaDemigodDirect345()
    { return true; }

// a cleric of a demigod could never receive 6th or 7th level spells
inline bool dgaDemigodNo67()
    { return true; }

// sixth and seventh level spells are granted to clerics directly from their
// deities
inline bool dgaSixthSeventhFromDeity()
    { return true; }

// only the greater gods may grant 7th level spells
inline bool dgaSeventhGreaterOnly()
    { return true; }

// the DM may carefully consider altering the demigod/lesser/greater
// designations if they do not suit the campaign
inline bool dgaRankAlterable()
    { return true; }

// clerics are expected to behave in a manner exemplary of the teachings of
// their faith, role models exhibiting greater wisdom
inline bool dgaClericExemplary()
    { return true; }

// cleric adventurers must maintain appearances and perform the proper rituals
// essential to their faith and alignment
inline bool dgaClericRitualsRequired()
    { return true; }

// clerics build places of worship from roadside shrines to whole temples, in
// places of relative security - desecration is a terrible blow to a religion
// honor
inline bool dgaClericTempleBuilding()
    { return true; }

// a minor offense by a higher level cleric typically brings an unmistakable
// omen sent by one of the deity servants
inline bool dgaMinorTransgressionWarningOmen()
    { return true; }

// until the atonement period is complete, use of certain spells or spell
// levels may be denied the errant cleric
inline bool dgaSpellsDeniedDuringAtonement()
    { return true; }

// a grave transgression may require sacrificing all possessions and going on
// a major quest to restore good standing
inline bool dgaGraveSinAllPossessions()
    { return true; }

// irredeemable sins bring immediate and total excommunication - never again
// clerical spells in that deity name, nor aid from its followers
inline bool dgaExcommunicationTotal()
    { return true; }

// ---- the omens ----

// the coming of a will-o-wisp means some building will burn to the ground
// within seven days
inline int dgaOmenWispDays()
    { return 7; }

// omens are devices for judges (the DM) to use in correcting players that
// constantly do improper things
inline bool dgaOmensCorrectionDevices()
    { return true; }

// the most common bad omen is a partial loss of power: forgotten higher-level
// spells, constant illness (one-fourth to one-half hit points), failed
// renewals
inline bool dgaOmenPartialPowerLoss()
    { return true; }

// if a temporary loss of power does not deter the player, more severe omens
// can be given or the effects made permanent
inline bool dgaOmenEscalation()
    { return true; }

// any and all omen powers or results are entirely optional; a player cannot
// badger a DM into bonuses for carrying lucky charms
inline bool dgaOmenResultsOptional()
    { return true; }

// good-luck portents: finding a four-leaf clover, seeing the crescent moon,
// and finding a toadstool
inline bool dgaOmenGoodPortents()
    { return true; }

// good-luck symbols: dice, crossed fingers, a shoe, a fish, a dog, a wheel,
// and the three apes that see, hear and speak no evil
inline bool dgaOmenGoodSymbols()
    { return true; }

// finding mistletoe in the wild is good luck; boiled with pure spring water
// it is a universal cure for poisons
inline bool dgaOmenMistletoe()
    { return true; }

// the wearing of leather from top to bottom is said to repel demons and
// devils
inline bool dgaOmenLeatherRepels()
    { return true; }

// dung has both properties: the dung-covered cannot be touched by the undead,
// but dung cast on a good altar defiles it
inline bool dgaOmenDung()
    { return true; }

// breaking a mirror and spilling salt are universally recognized bad omens
inline bool dgaOmenMirrorSalt()
    { return true; }

// the appearance of meteors, comets and eclipses portends great changes or
// happenings, usually not good
inline bool dgaOmenCelestials()
    { return true; }

// meeting an old woman as one sets out on a journey is ill fortune
inline bool dgaOmenOldWoman()
    { return true; }

// a bat flying in the window is ill fortune
inline bool dgaOmenBatWindow()
    { return true; }

// tripping as one enters a doorway is ill fortune
inline bool dgaOmenTripping()
    { return true; }

// a bird perched on a holy symbol means horrible things will happen to that
// sect in the near future
inline bool dgaOmenBirdOnSymbol()
    { return true; }

// finding crossed knives in a room is a sure sign that person will be cut the
// very next time they are attacked
inline bool dgaOmenCrossedKnives()
    { return true; }

// thirteen of anything in one group is the height of bad luck; taking objects
// from a group of thirteen invites a horrible death
inline bool dgaOmenThirteen()
    { return true; }

// the coming of a will-o-wisp means some building is going to burn to the
// ground within seven days
inline bool dgaOmenWispFire()
    { return true; }

// the wail of a banshee certainly means someone is going to die that very
// night
inline bool dgaOmenBanshee()
    { return true; }

// a rainbow is a definite statement from a deity: either it wants to converse
// with a mortal or to give the mortal a quest
inline bool dgaOmenRainbow()
    { return true; }

// in Norse legend men and women of power could travel to Asgard by touching a
// rainbow (part of the bridge Bifrost) and wishing to be there
inline bool dgaOmenBifrost()
    { return true; }

// ---- the mortality and immortality doctrine ----

// the five soul races (humans, dwarves, halflings, gnomes, half-elves - the
// raise dead and resurrection targets)
inline int dgaSoulRaces()
    { return 5; }

// the death-to-plane journey takes as little as 3 days relative to the Prime
// Material Plane
inline int dgaDeathLagMin()
    { return 3; }

// the death-to-plane journey takes up to 30 days relative to the Prime
// Material Plane
inline int dgaDeathLagMax()
    { return 30; }

// a spirit may spend as little as ten years on its plane before returning to
// the Prime Material Plane
inline int dgaSpiritRestMin()
    { return 10; }

// a spirit may spend a millennium or more on its plane before returning (time
// is not important to a deity)
inline int dgaSpiritRestMax()
    { return 1000; }

// type V and VI demons must rest a century before returning unaided to the
// plane where they were slain
inline int dgaRestDemonsCentury()
    { return 100; }

// demon princes and lords, greater devils and arch-devils require 2-8 weeks
// of rest
inline int dgaRestPrincesMin()
    { return 2; }

// the top of the 2-8 week demon prince rest range
inline int dgaRestPrincesMax()
    { return 8; }

// even greater deities require 1-4 weeks of rest before dealing with
// activities outside their home plane
inline int dgaRestGreaterMin()
    { return 1; }

// the top of the 1-4 week greater deity rest range
inline int dgaRestGreaterMax()
    { return 4; }

// the anima is one of two sorts: souls (the five raiseable races) or spirits
// (all other beings that worship deities, the DM deciding case by case)
inline bool dgaSoulSpiritDoctrine()
    { return true; }

// monsters with spirits must have at least an intelligence rating of Low
inline bool dgaSpiritMinIntLow()
    { return true; }

// the plane a soul or spirit goes to is the DM call, judged on the alignment
// behavior of the mortal life; the faithful pass to their deity plane
inline bool dgaSoulPlaneDmChoice()
    { return true; }

// for souls the destination plane is the beginning of eternity - the soul
// remains there forever, enjoying the benefits or suffering the torments
inline bool dgaSoulEternalResident()
    { return true; }

// spirits are but temporary residents: their rewards and punishments are less
// than that received by souls
inline bool dgaSpiritRewardsLess()
    { return true; }

// a spirit can be returned to the Prime Material Plane - reincarnated with no
// overt memories, the new form not necessarily the same as the old
inline bool dgaSpiritReincarnation()
    { return true; }

// the 3-30 day death lag is the rationale for the progressive time limit on
// the raise dead spell - the farther the soul has travelled, the more
// powerful the cleric needed
inline bool dgaRaisedLimitRationale()
    { return true; }

// the road through the Astral Plane is clearly marked for the dead but not
// free of peril - hence burial chambers with weapons, treasure and bodyguards
inline bool dgaAstralPerilDoctrine()
    { return true; }

// resurrection recalls the soul from its deity plane with that deity
// cooperation; resurrecting a radically different alignment may greatly
// offend
inline bool dgaResurrectionCooperation()
    { return true; }

// the minions of some deities (demons, devils, couatl, ki-rin, titans) are
// actually spirits put into those forms; the MONSTER MANUAL forms are not the
// only ones
inline bool dgaServantsAreSpirits()
    { return true; }

// immortality does not confer everlasting existence - what the gods enjoy is
// eternal youth
inline bool dgaImmortalityEternalYouth()
    { return true; }

// a character with apparent immortality through potions of longevity need not
// fear natural causes until the final potion reverses all previous ones
inline bool dgaLongevityPotionReversal()
    { return true; }

// the silver cord anchoring traveling deities and minions to their home plane
// cannot be broken by the Psychic Wind or any other means
inline bool dgaSilverCordUnbreakable()
    { return true; }

// the cord pulls a spirit back to its plane of origin near-instantaneously
// when its material form is destroyed, at enormous energy cost
inline bool dgaCordPullNearInstant()
    { return true; }

// when a deity dies on the Prime Material Plane the person and possessions
// fade away and disappear, though certain items might remain at DM discretion
inline bool dgaDeityDeathFades()
    { return true; }

// during a resting deity dormancy its clerics can acquire or recover no
// spells of third level or higher
inline bool dgaDormancyBlocksSpells()
    { return true; }

// the dormancy spell loss may be interpreted with dismay as a bad omen, but
// no information will be forthcoming until the dormancy is over
inline bool dgaDormancyReadAsOmen()
    { return true; }

// it is unlikely that a deity would admit to its followers that it had been
// defeated
inline bool dagaDeityNeverAdmitsDefeat()
    { return true; }

// a being slain on its home plane is absolutely and irrevocably dead - no
// power in the multiverse can restore it, including other deities
inline bool dgaHomePlaneDeathAbsolute()
    { return true; }

// it should be next to impossible for anything except another deity to slay a
// deity on its own plane; brazen characters are dealt with severely
inline bool dgaHomePlaneDeityNearImpossible()
    { return true; }

// ---- the divine ascension doctrine ----

// the four divine ascension requirements (level, abilities, worshipers,
// faithful follower)
inline int dgaAscensionReqts()
    { return 4; }

// at an average campaign level of 5, an ascension candidate should be around
// 9th-10th level
inline int dgaAscAvg5Min()
    { return 9; }

// the top of the average-5 example (9th-10th level)
inline int dgaAscAvg5Max()
    { return 10; }

// at an average campaign level of 15, a candidate would be in the realm of
// 25th-30th level
inline int dgaAscAvg15Min()
    { return 25; }

// the top of the average-15 example (25th-30th level)
inline int dgaAscAvg15Max()
    { return 30; }

// each wish spell weakens the caster and ages him or her 3 years (the
// ascension cost note)
inline int dgaWishAgingYears()
    { return 3; }

// the first requirement: an experience level significantly above the average
// of adventure-type characters in the campaign
inline bool dgaAscLevelAboveAverage()
    { return true; }

// the second requirement: ability scores raised through mighty world-shaking
// magic to be on par with the lesser demigods - dozens of wishes, each aging
// the caster 3 years
inline bool dgaAscAbilitiesRaised()
    { return true; }

// the third requirement: a body of sincere worshipers, genuine and honest in
// their adoration, convinced by witnessed mighty deeds and miracles
inline bool dgaAscSincereWorshipers()
    { return true; }

// the fourth requirement: the person must be and have been a faithful and
// true follower of his or her alignment and patron deity
inline bool dgaAscFaithfulFollower()
    { return true; }

// with all four conditions met and a sufficient number of divine quests
// fulfilled, the deity may invest the person with divine power
inline bool dgaAscDivineQuests()
    { return true; }

// the ascended serve as minor functionaries; after several centuries of
// superior service, exceptional servants may be awarded demigod status with
// an earthly priesthood
inline bool dgaServantCenturiesToDemigod()
    { return true; }

// ascension to divinity effectively removes the character from the general
// campaign as a non-player member of the DM pantheon
inline bool dgaAscensionRemovesFromCampaign()
    { return true; }

}   // namespace rules
