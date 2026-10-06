// ====================================================================
// Adnd1 - rules/socialrank.h
// R208: the social class and rank system (DMG
// pp.88-89, SOCIAL CLASS AND RANK IN
// ADVANCED DUNGEONS AND DRAGONS) - the
// government forms, the worked example
// aristocracy, the town and city social
// structure, the noble titles.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// society; the definitions read here). No
// random birth table exists in the print by
// design - the DM devises the social
// structure; what is pinned here is exactly
// what the print does state.
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The government forms (p.89), the print list in order.
// -----------------------------------------------------------------------
enum GovForm {
    GOV_AUTOCRACY = 0,
    GOV_BUREAUCRACY,
    GOV_CONFEDERACY,
    GOV_DEMOCRACY,
    GOV_DICTATORSHIP,
    GOV_FEUDALITY,
    GOV_GERIATOCRACY,
    GOV_GYNARCHY,
    GOV_HIERARCHY,
    GOV_MAGOCRACY,
    GOV_MATRIARCHY,
    GOV_MILITOCRACY,
    GOV_MONARCHY,
    GOV_OLIGARCHY,
    GOV_PEDOCRACY,
    GOV_PLUTOCRACY,
    GOV_REPUBLIC,
    GOV_THEOCRACY,
    GOV_SYNDICRACY,
    GOV_FORM_COUNT
};

// The defining trait of each form - the print
// definition, one code per form, in form order.
enum GovTrait {
    GOVT_SELF_DERIVED_ABSOLUTE = 0,
    GOVT_DEPARTMENT_HEADS,
    GOVT_LEAGUE_COMMON_GOOD,
    GOVT_CITIZENS_BODY,
    GOVT_ONE_SUPREME_HEAD,
    GOVT_LAYERED_FEALTY,
    GOVT_ELDERLY_ONLY,
    GOVT_FEMALES_ONLY,
    GOVT_RELIGIOUS_LIKE_FEUDAL,
    GOVT_MAGIC_USERS_ONLY,
    GOVT_ELDEST_FEMALES,
    GOVT_MILITARY_HEADS,
    GOVT_SINGLE_HEREDITARY_SOVEREIGN,
    GOVT_FEW_COEQUAL,
    GOVT_THE_LEARNED,
    GOVT_THE_WEALTHY,
    GOVT_REPRESENTATIVE_ELECTORATE,
    GOVT_GOD_RULE,
    GOVT_SYNDICS_BUSINESS,
    GOVT_TRAIT_COUNT
};

inline int govFormCount() { return 19; }

inline int govFormTrait(int form) {
    // the trait code of each form, in print
    // list order: autocracy is self-derived
    // absolute power, bureaucracy rule by
    // department heads, confederacy a league
    // for the common good, democracy the
    // body of citizens, dictatorship final
    // authority in one supreme head,
    // feudality layered fealty, geriatocracy
    // the elderly, gynarchy females only,
    // hierarchy religious like a feudality,
    // magocracy magic-users only, matriarchy
    // the eldest females, militocracy the
    // military heads, monarchy a single
    // hereditary sovereign, oligarchy a few
    // coequal rulers, pedocracy the learned,
    // plutocracy the wealthy, republic
    // representatives of an electorate,
    // theocracy rule by the god, syndicracy
    // a body of business syndics
    static const int t[19] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18,
    };
    if (form < 0) form = 0;
    if (form > 18) form = 18;
    return t[form];
}

// -----------------------------------------------------------------------
// The worked example aristocracy (p.88): a
// non-hereditary ruling class. Members are
// those who have served in the military, own
// property of 100 or more acres extent, and
// pay an annual tax of not less than 10 gold
// pieces on their income - the serial list
// reads conjunctively (all three), and the
// merchant waiver settles it: land ownership
// is waived for merchants and tradesmen
// whose business pays not less than 20 gold
// pieces in taxes each year - a waiver that
// would be vacuous under an or-reading.
// -----------------------------------------------------------------------
inline bool aristocratEligible(
        bool servedMilitary, int acresOwned,
        int annualIncomeTaxGold) {
    if (!servedMilitary) return false;
    if (acresOwned < 100) return false;
    if (annualIncomeTaxGold < 10) return false;
    return true;
}

inline bool aristocratMerchantEligible(
        bool servedMilitary, int annualTaxGold) {
    // the land criterion waived at 20 gold
    if (!servedMilitary) return false;
    if (annualTaxGold < 20) return false;
    return true;
}

// The offices: aristocrats only, for any
// government office and command of the
// military; senators elected from their
// number; former senators eligible for the
// tribunals and judgeships; former military
// officers appointed by senatorial vote to
// keep the peace and police the land.
inline bool officeEligible(bool isAristocrat) {
    return isAristocrat;
}

inline bool senateEligible(bool isAristocrat) {
    return isAristocrat;
}

inline bool tribunalEligible(bool formerSenator) {
    return formerSenator;
}

inline bool policeAppointedFrom(
        bool formerMilitaryOfficer) {
    return formerMilitaryOfficer;
}

// -----------------------------------------------------------------------
// The town and city social structure (p.89):
// three classes, each drawing its officers.
// -----------------------------------------------------------------------
enum TownClass {
    TOWN_UPPER = 0,
    TOWN_MIDDLE,
    TOWN_LOWER,
    TOWN_CLASS_COUNT
};

inline int townClassCount() { return 3; }

// Upper: nobles, gentlemen, the wealthiest
// merchants and the most important guildmasters
// - the important law makers and executives.
inline bool townDrawsImportantLawmakers(int tc) {
    return tc == TOWN_UPPER;
}

// Middle: merchants and guildmasters with the
// master artisans - the lesser officials.
inline bool townProvidesLesserOfficials(int tc) {
    return tc == TOWN_MIDDLE;
}

// Lower: tradesmen, journeymen, laborers and
// all others - the common council.
inline bool townDrawsCommonCouncil(int tc) {
    return tc == TOWN_LOWER;
}

// -----------------------------------------------------------------------
// The municipal offices (pp.89-90).
// -----------------------------------------------------------------------
// Mayor, magistrate or burgomaster: probably
// a lifetime office drawn only from the upper
// class.
inline int mayorTitleCount() { return 3; }
inline bool mayorOfficeLifetime() { return true; }
inline int mayorOfficeSourceClass() {
    return TOWN_UPPER;
}

// Aldermen, burghers or burgesses: chosen by
// the upper class to serve as the major
// officers under the mayor; elected by the
// middle class.
inline int aldermanTitleCount() { return 3; }
inline bool aldermenChosenBy(int tc) {
    return tc == TOWN_UPPER;
}
inline bool aldermenElectedBy(int tc) {
    return tc == TOWN_MIDDLE;
}

// The judiciary and the military commanders of
// the municipality fall within the upper
// stratum; law enforcement, customs and tax
// officials all come from the middle class.
inline int townJudiciaryStratum() {
    return TOWN_UPPER;
}
inline int townMilitaryCommandStratum() {
    return TOWN_UPPER;
}
inline int lawEnforcementSourceClass() {
    return TOWN_MIDDLE;
}
inline int customsOfficialSourceClass() {
    return TOWN_MIDDLE;
}
inline int taxOfficialSourceClass() {
    return TOWN_MIDDLE;
}

// Councilors of the common council: selected
// by the upper and middle classes as well as
// the free lower class; petty officials drawn
// from the lower class, advisory or
// administrative only.
inline bool councilorSelectedBy(int tc) {
    return tc == TOWN_UPPER || tc == TOWN_MIDDLE;
}
inline bool councilorSelectedByLower(
        bool lowerIsFree) {
    return lowerIsFree;
}
inline int pettyOfficialsSourceClass() {
    return TOWN_LOWER;
}
inline bool pettyOfficialRoleAdministrative() {
    return true;
}

// The constabulary: drawn in part from citizen
// soldiers, the city watch or police force, and
// militia called up in times of great need; by
// far the bulk of other soldiery hired
// mercenaries.
inline bool constabularyIncludesCitizenSoldiers() {
    return true;
}
inline bool constabularyIncludesWatchOrPolice() {
    return true;
}
inline bool militiaCalledInGreatNeed() {
    return true;
}
inline bool soldieryBulkMercenaries() {
    return true;
}

// -----------------------------------------------------------------------
// Knights (p.89): non-hereditary peers, their
// precedence varying with the order of
// knighthood held.
// -----------------------------------------------------------------------
inline bool knightsHereditary() { return false; }
inline bool knightPrecedenceVariesByOrder() {
    return true;
}

// -----------------------------------------------------------------------
// Royal and noble titles, northern European
// (p.89): the secular ladder of the table -
// the print lists duke before prince.
// -----------------------------------------------------------------------
enum NobleTitleRN {
    NT_EMPEROR = 0,
    NT_KING,
    NT_DUKE,
    NT_PRINCE,
    NT_MARQUIS,
    NT_COUNT_EARL,
    NT_VISCOUNT,
    NT_BARON_THANE,
    NT_BARONET,
    NT_KNIGHT,
    NT_RN_COUNT
};

inline int nobleTitleRNCount() { return 10; }

inline int nobleTitleRNPrecedence(int t) {
    // emperor highest, knight lowest
    if (t < 0) t = 0;
    if (t > 9) t = 9;
    return t;
}

// The ecclesiastical ranks (archbishop, bishop,
// abbot, prior) sit among the nobility per the
// table rows.
inline int ecclesiasticalRanksAmongNobility() {
    return 4;
}

// The German equivalents of the table: 0
// Pfalzgraf (with duke), 1 Herzog (with
// prince), 2 Margrave (with marquis), 3 Graf
// (with count/earl), 4 Waldgraf (with
// viscount), 5 Freiherr (with baronet), 6
// Ritter (with knight); -1 = no equivalent in
// the row.
enum GermanTitle {
    GT_PFALZGRAF = 0,
    GT_HERZOG,
    GT_MARGRAVE,
    GT_GRAF,
    GT_WALDGRAF,
    GT_FREIHERR,
    GT_RITTER,
    GT_COUNT
};

inline int germanEquivalentCount() { return 7; }

inline int germanEquivalentOf(int t) {
    static const int g[10] = {
        -1, -1, 0, 1, 2, 3, 4, -1, 5, 6,
    };
    if (t < 0) t = 0;
    if (t > 9) t = 9;
    return g[t];
}

// The Asian title forms (p.89): twenty listed
// in the table - Padishah, Maharaja, Kha-Khan,
// Tarkhan, Sultan, Shah, Rajah, Ilkhan, Dey,
// Caliph, Bey, Orkhon, Bashaw, Pasha, Emir,
// Amir, Khan, Sheikh, Nawab, Malik.
inline int asianTitleCount() { return 20; }

} // namespace rules
