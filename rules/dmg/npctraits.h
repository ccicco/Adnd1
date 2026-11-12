// ====================================================================
// Adnd1 - rules/dmg/npctraits.h
// R210: the NPC personae traits tables (DMG
// pp.115-116, TRAITS TABLES) - the general
// tendencies, personality, interests and the
// eleven word tables, with the morals asterisk
// rule and the print encounter/offer reaction
// adjustment percents.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the dice
// and the selection; the tables read here).
// Every word is pinned as its own enum value in
// face order - the R209 convention, no strings
// (the audit_eval evaluable subset). The d10
// tables read through the R209 npcD10Face
// clamp; the d6/d8/d12 faces clamp the same
// way (under 1 and over the face count read
// the extreme face).
//
// Conventions and judgments, named in place:
//   - The d6 halves: General Tendencies and
//     Interests are (d12, d6) tables - the d6
//     1-3 reads the first twelve rows, 4-6 the
//     second twelve; the row index is
//     half * 12 + d12.
//   - JUDGMENT (morals asterisk): the print -
//     roll again; if perverted, sadistic or
//     depraved is again indicated, the
//     character is that; otherwise the second
//     roll tells the true morals - has the
//     same shape as the R209 sanity rule: a
//     marked first roll takes the second
//     roll, an unmarked first roll stands.
//   - The reaction adjustment table is the
//     PRINT one (nine groups, the mins and
//     maxes); the compilation annotation
//     columns (per-word percents) are not in
//     the print and are excluded.
// ====================================================================

#pragma once

#include "npcpersonae.h"  // R209: the d10 face clamp
#include "rules/dmg/npcpersonae.h"  // R-refactor: cross-file symbol




// -----------------------------------------------------------------------
// The General Tendencies (d12, d6) - 24
// tendencies in print order: the d6 1-3
// half reads 1-12, 4-6 reads 13-24.
// -----------------------------------------------------------------------
enum NpcTendency {
    NPT_OPTIMIST = 0,
    NPT_PESSIMIST,
    NPT_HEDONIST,
    NPT_ALTRUIST,
    NPT_HELPFUL_KINDLY,
    NPT_CARELESS,
    NPT_CAPRICIOUS_MISCHIEVOUS,
    NPT_SOBER,
    NPT_CURIOUS_INQUISITIVE,
    NPT_MOODY,
    NPT_TRUSTING,
    NPT_SUSPICIOUS_CAUTIOUS,
    NPT_PRECISE_EXACTING,
    NPT_PERCEPTIVE,
    NPT_OPINIONATED_CONTRARY,
    NPT_VIOLENT_WARLIKE,
    NPT_STUDIOUS,
    NPT_FOUL_BARBARIC,
    NPT_CRUEL_CALLOUS,
    NPT_PRACTICAL_JOKER,
    NPT_SERVILE_OBSEQUIOUS,
    NPT_FANATICAL_OBSSESSIVE,
    NPT_MALEVOLENT,
    NPT_LOQUACIOUS,
    NPT_TENDENCY_COUNT
};



// -----------------------------------------------------------------------
// The Personality (d8, d8) - three columns
// of eight: the first d8 picks the column
// (1-5 average, 6-7 extroverted, 8
// introverted), the second d8 the row.
// -----------------------------------------------------------------------
enum NpcPersType {
    NPPTY_AVERAGE = 0,
    NPPTY_EXTROVERTED,
    NPPTY_INTROVERTED,
    NPPTY_TYPE_COUNT
};


enum NpcPersWord {
    // average column 1-8
    NPPW_MODEST = 0,
    NPPW_EGOIST_ARROGANT,
    NPPW_FRIENDLY,
    NPPW_ALOOF,
    NPPW_HOSTILE,
    NPPW_WELL_SPOKEN,
    NPPW_DIPLOMATIC,
    NPPW_ABRASIVE,
    // extroverted column 1-8
    NPPW_FORCEFUL,
    NPPW_OVERBEARING,
    NPPW_EXTRO_FRIENDLY,
    NPPW_BLUSTERING,
    NPPW_ANTAGONISTIC,
    NPPW_RUDE,
    NPPW_RASH,
    NPPW_EXTRO_DIPLOMATIC,
    // introverted column 1-8
    NPPW_RETIRING,
    NPPW_TACITURN,
    NPPW_INTRO_FRIENDLY,
    NPPW_INTRO_ALOOF,
    NPPW_INTRO_HOSTILE,
    NPPW_INTRO_RUDE,
    NPPW_COURTEOUS,
    NPPW_SOLITARY_SECRETIVE,
    NPPW_WORD_COUNT
};



// -----------------------------------------------------------------------
// The Interests (d12, d6) - 24 interests:
// 1-12 the pursuits, 13-16 the vices, 17-20
// the four collector rows, 21-22 the
// services, 23-24 none.
// -----------------------------------------------------------------------
enum NpcInterest {
    NPI_RELIGION = 0,
    NPI_LEGENDS,
    NPI_HISTORY,
    NPI_NATURE,
    NPI_HORTICULTURE,
    NPI_HUSBANDRY,
    NPI_EXOTIC_ANIMALS,
    NPI_HUNTING,
    NPI_FISHING,
    NPI_HANDICRAFTS,
    NPI_ATHLETICS,
    NPI_POLITICS,
    NPI_WINES_SPIRITS,
    NPI_FOODS_PREPARATION,
    NPI_GAMBLING,
    NPI_DRUGS,
    NPI_COLLECTOR_1,
    NPI_COLLECTOR_2,
    NPI_COLLECTOR_3,
    NPI_COLLECTOR_4,
    NPI_COMMUNITY_SERVICE,
    NPI_ALTRUISM,
    NPI_NONE_1,
    NPI_NONE_2,
    NPI_INTEREST_COUNT
};



// -----------------------------------------------------------------------
// Disposition (d10): cheerful, morose,
// compassionate/sensitive, unfeeling/
// insensitive, humble, proud/haughty, even
// tempered, hot tempered, easy going, harsh.
// -----------------------------------------------------------------------
enum NpcDisposition {
    NPD_CHEERFUL = 0,
    NPD_MOROSE,
    NPD_COMPASSIONATE_SENSITIVE,
    NPD_UNFEELING_INSENSITIVE,
    NPD_HUMBLE,
    NPD_PROUD_HAUGHTY,
    NPD_EVEN_TEMPERED,
    NPD_HOT_TEMPERED,
    NPD_EASY_GOING,
    NPD_HARSH,
    NPD_COUNT
};



// -----------------------------------------------------------------------
// Intellect (d10): dull, average, average,
// active, active, dreaming, ponderous,
// anti-intellectual, scheming, brilliant -
// the last four faces (dreaming through
// brilliant) modify the intelligence rating.
// -----------------------------------------------------------------------
enum NpcIntellect {
    NPIQ_DULL = 0,
    NPIQ_AVERAGE_1,
    NPIQ_AVERAGE_2,
    NPIQ_ACTIVE_1,
    NPIQ_ACTIVE_2,
    NPIQ_DREAMING,
    NPIQ_PONDEROUS,
    NPIQ_ANTI_INTELLECTUAL,
    NPIQ_SCHEMING,
    NPIQ_BRILLIANT,
    NPIQ_COUNT
};



// -----------------------------------------------------------------------
// Collections (d12): knives & daggers,
// swords, weapons, shields & weapons, armor,
// books & scrolls, minerals & gems,
// ornaments & jewelry, coins & tokens,
// trophies & skins, porcelain/china &
// crystal, artwork.
// -----------------------------------------------------------------------
enum NpcCollection {
    NPCOL_KNIVES_DAGGERS = 0,
    NPCOL_SWORDS,
    NPCOL_WEAPONS,
    NPCOL_SHIELDS_WEAPONS,
    NPCOL_ARMOR,
    NPCOL_BOOKS_SCROLLS,
    NPCOL_MINERALS_GEMS,
    NPCOL_ORNAMENTS_JEWELRY,
    NPCOL_COINS_TOKENS,
    NPCOL_TROPHIES_SKINS,
    NPCOL_PORCELAIN_CRYSTAL,
    NPCOL_ARTWORK,
    NPCOL_COUNT
};



// -----------------------------------------------------------------------
// Nature (d6): soft-hearted, forgiving,
// hard-hearted, unforgiving, jealous,
// vengeful.
// -----------------------------------------------------------------------
enum NpcNature {
    NPNT_SOFT_HEARTED = 0,
    NPNT_FORGIVING,
    NPNT_HARD_HEARTED,
    NPNT_UNFORGIVING,
    NPNT_JEALOUS,
    NPNT_VENGEFUL,
    NPNT_COUNT
};



// -----------------------------------------------------------------------
// Materialism (d6): aesthetic,
// intellectualist, average, covetous,
// greedy, avaricious.
// -----------------------------------------------------------------------
enum NpcMaterialism {
    NPM_AESTHETIC = 0,
    NPM_INTELLECTUALIST,
    NPM_AVERAGE,
    NPM_COVETOUS,
    NPM_GREEDY,
    NPM_AVARICIOUS,
    NPM_COUNT
};



// -----------------------------------------------------------------------
// Honesty (d8): scrupulous, very honorable,
// truthful, average, average, average,
// liar, deceitful.
// -----------------------------------------------------------------------
enum NpcHonesty {
    NPH_SCRUPULOUS = 0,
    NPH_VERY_HONORABLE,
    NPH_TRUTHFUL,
    NPH_AVERAGE_1,
    NPH_AVERAGE_2,
    NPH_AVERAGE_3,
    NPH_LIAR,
    NPH_DECEITFUL,
    NPH_COUNT
};



// -----------------------------------------------------------------------
// Bravery (d8): normal, normal, normal,
// foolhardy, brave, fearless, cowardly,
// craven.
// -----------------------------------------------------------------------
enum NpcBravery {
    NPB_NORMAL_1 = 0,
    NPB_NORMAL_2,
    NPB_NORMAL_3,
    NPB_FOOLHARDY,
    NPB_BRAVE,
    NPB_FEARLESS,
    NPB_COWARDLY,
    NPB_CRAVEN,
    NPB_COUNT
};



// -----------------------------------------------------------------------
// Energy (d8): slothful, lazy, normal,
// normal, normal, energetic, energetic,
// driven - the driven individual is
// certainly neurotic.
// -----------------------------------------------------------------------
enum NpcEnergy {
    NPE_SLOTHFUL = 0,
    NPE_LAZY,
    NPE_NORMAL_1,
    NPE_NORMAL_2,
    NPE_NORMAL_3,
    NPE_ENERGETIC_1,
    NPE_ENERGETIC_2,
    NPE_DRIVEN,
    NPE_COUNT
};



// -----------------------------------------------------------------------
// Thrift (d8): miserly, mean, thrifty,
// average, average, spendthrift,
// spendthrift, wastrel.
// -----------------------------------------------------------------------
enum NpcThrift {
    NPTHR_MISERLY = 0,
    NPTHR_MEAN,
    NPTHR_THRIFTY,
    NPTHR_AVERAGE_1,
    NPTHR_AVERAGE_2,
    NPTHR_SPENDTHRIFT_1,
    NPTHR_SPENDTHRIFT_2,
    NPTHR_WASTREL,
    NPTHR_COUNT
};



// -----------------------------------------------------------------------
// Morals (d12): ascetic, virtuous, normal,
// normal, lusty, lusty, lustful, immoral,
// amoral, perverted, sadistic, depraved -
// the last three carry the asterisk reroll.
// -----------------------------------------------------------------------
enum NpcMorals {
    NPMOR_ASCETIC = 0,
    NPMOR_VIRTUOUS,
    NPMOR_NORMAL_1,
    NPMOR_NORMAL_2,
    NPMOR_LUSTY_1,
    NPMOR_LUSTY_2,
    NPMOR_LUSTFUL,
    NPMOR_IMMORAL,
    NPMOR_AMORAL,
    NPMOR_PERVERTED,
    NPMOR_SADISTIC,
    NPMOR_DEPRAVED,
    NPMOR_COUNT
};



// -----------------------------------------------------------------------
// Piety (d12): saintly, martyr/zealot,
// pious, reverent, average, average,
// average, average, impious, irreverent,
// iconoclastic, irreligious.
// -----------------------------------------------------------------------
enum NpcPiety {
    NPP_SAINTLY = 0,
    NPP_MARTYR_ZEALOT,
    NPP_PIOUS,
    NPP_REVERENT,
    NPP_AVERAGE_1,
    NPP_AVERAGE_2,
    NPP_AVERAGE_3,
    NPP_AVERAGE_4,
    NPP_IMPIOUS,
    NPP_IRREVERENT,
    NPP_ICONOCLASTIC,
    NPP_IRRELIGIOUS,
    NPP_COUNT
};



// -----------------------------------------------------------------------
// The encounter/offer reaction adjustments
// (p.115, the print table): the percent
// min/max per group - the sanity rows
// (neurotic -1 to 6, insane 1 to 10,
// maniacal 1 to 20), disposition any 1 to 6,
// nature any 1 to 4, general tendencies any
// 1 to 8, bravery any 1 to 20, personality
// any 1 to 8, materialism any 1 to 20.
// -----------------------------------------------------------------------
enum NpcReactGroup {
    NPRG_SANITY_NEUROTIC = 0,
    NPRG_SANITY_INSANE,
    NPRG_SANITY_MANIACAL,
    NPRG_DISPOSITION,
    NPRG_NATURE,
    NPRG_GENERAL_TENDENCIES,
    NPRG_BRAVERY,
    NPRG_PERSONALITY,
    NPRG_MATERIALISM,
    NPRG_GROUP_COUNT
};

// R-refactor: namespace rules -> class Npctraits (instance methods)
class Npctraits {
public:
    int npcTendencyCount();
    int npcTraitTendency(int d6, int d12);
    int npcTraitPersonalityType(int d8);
    int npcTraitPersonality(int d8first, int d8second);
    int npcInterestCount();
    int npcTraitInterest(int d6, int d12);
    bool npcInterestIsCollector(int i);
    int npcTraitDisposition(int d10);
    int npcTraitIntellect(int d10);
    bool npcIntellectModifiesRating(int iq);
    int npcTraitCollection(int d12);
    int npcTraitNature(int d6);
    int npcTraitMaterialism(int d6);
    int npcTraitHonesty(int d8);
    int npcTraitBravery(int d8);
    int npcTraitEnergy(int d8);
    int npcTraitThrift(int d8);
    int npcTraitMorals(int d12);
    bool npcMoralsIsMarked(int m);
    int npcMoralsResolved(int firstRoll, int secondRoll);
    int npcTraitPiety(int d12);
    int npcReactGroupCount();
    int npcReactionAdjMin(int group);
    int npcReactionAdjMax(int group);
};
