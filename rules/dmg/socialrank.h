// ====================================================================
// Adnd1 - rules/dmg/socialrank.h
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

// R-refactor: namespace rules -> class Socialrank (instance methods)
class Socialrank {
public:
    int govFormCount();
    int govFormTrait(int form);


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
    bool aristocratEligible( bool servedMilitary, int acresOwned, int annualIncomeTaxGold);
    bool aristocratMerchantEligible( bool servedMilitary, int annualTaxGold);


// The offices: aristocrats only, for any
// government office and command of the
// military; senators elected from their
// number; former senators eligible for the
// tribunals and judgeships; former military
// officers appointed by senatorial vote to
// keep the peace and police the land.
    bool officeEligible(bool isAristocrat);
    bool senateEligible(bool isAristocrat);
    bool tribunalEligible(bool formerSenator);
    bool policeAppointedFrom( bool formerMilitaryOfficer);
    int townClassCount();


// Upper: nobles, gentlemen, the wealthiest
// merchants and the most important guildmasters
// - the important law makers and executives.
    bool townDrawsImportantLawmakers(int tc);


// Middle: merchants and guildmasters with the
// master artisans - the lesser officials.
    bool townProvidesLesserOfficials(int tc);


// Lower: tradesmen, journeymen, laborers and
// all others - the common council.
    bool townDrawsCommonCouncil(int tc);


// -----------------------------------------------------------------------
// The municipal offices (pp.89-90).
// -----------------------------------------------------------------------
// Mayor, magistrate or burgomaster: probably
// a lifetime office drawn only from the upper
// class.
    int mayorTitleCount();
    bool mayorOfficeLifetime();
    int mayorOfficeSourceClass();


// Aldermen, burghers or burgesses: chosen by
// the upper class to serve as the major
// officers under the mayor; elected by the
// middle class.
    int aldermanTitleCount();
    bool aldermenChosenBy(int tc);
    bool aldermenElectedBy(int tc);


// The judiciary and the military commanders of
// the municipality fall within the upper
// stratum; law enforcement, customs and tax
// officials all come from the middle class.
    int townJudiciaryStratum();
    int townMilitaryCommandStratum();
    int lawEnforcementSourceClass();
    int customsOfficialSourceClass();
    int taxOfficialSourceClass();


// Councilors of the common council: selected
// by the upper and middle classes as well as
// the free lower class; petty officials drawn
// from the lower class, advisory or
// administrative only.
    bool councilorSelectedBy(int tc);
    bool councilorSelectedByLower( bool lowerIsFree);
    int pettyOfficialsSourceClass();
    bool pettyOfficialRoleAdministrative();


// The constabulary: drawn in part from citizen
// soldiers, the city watch or police force, and
// militia called up in times of great need; by
// far the bulk of other soldiery hired
// mercenaries.
    bool constabularyIncludesCitizenSoldiers();
    bool constabularyIncludesWatchOrPolice();
    bool militiaCalledInGreatNeed();
    bool soldieryBulkMercenaries();


// -----------------------------------------------------------------------
// Knights (p.89): non-hereditary peers, their
// precedence varying with the order of
// knighthood held.
// -----------------------------------------------------------------------
    bool knightsHereditary();
    bool knightPrecedenceVariesByOrder();
    int nobleTitleRNCount();
    int nobleTitleRNPrecedence(int t);


// The ecclesiastical ranks (archbishop, bishop,
// abbot, prior) sit among the nobility per the
// table rows.
    int ecclesiasticalRanksAmongNobility();
    int germanEquivalentCount();
    int germanEquivalentOf(int t);


// The Asian title forms (p.89): twenty listed
// in the table - Padishah, Maharaja, Kha-Khan,
// Tarkhan, Sultan, Shah, Rajah, Ilkhan, Dey,
// Caliph, Bey, Orkhon, Bashaw, Pasha, Emir,
// Amir, Khan, Sheikh, Nawab, Malik.
    int asianTitleCount();
};
