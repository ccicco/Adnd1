// R-refactor: split from socialrank.h - definitions
#include "rules/dmg/socialrank.h"

int Socialrank::govFormCount() { return 19; }

int Socialrank::govFormTrait(int form) {
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

bool Socialrank::aristocratEligible( bool servedMilitary, int acresOwned, int annualIncomeTaxGold) {
    if (!servedMilitary) return false;
    if (acresOwned < 100) return false;
    if (annualIncomeTaxGold < 10) return false;
    return true;
}

bool Socialrank::aristocratMerchantEligible( bool servedMilitary, int annualTaxGold) {
    // the land criterion waived at 20 gold
    if (!servedMilitary) return false;
    if (annualTaxGold < 20) return false;
    return true;
}

bool Socialrank::officeEligible(bool isAristocrat) {
    return isAristocrat;
}

bool Socialrank::senateEligible(bool isAristocrat) {
    return isAristocrat;
}

bool Socialrank::tribunalEligible(bool formerSenator) {
    return formerSenator;
}

bool Socialrank::policeAppointedFrom( bool formerMilitaryOfficer) {
    return formerMilitaryOfficer;
}

int Socialrank::townClassCount() { return 3; }

bool Socialrank::townDrawsImportantLawmakers(int tc) {
    return tc == TOWN_UPPER;
}

bool Socialrank::townProvidesLesserOfficials(int tc) {
    return tc == TOWN_MIDDLE;
}

bool Socialrank::townDrawsCommonCouncil(int tc) {
    return tc == TOWN_LOWER;
}

int Socialrank::mayorTitleCount() { return 3; }

bool Socialrank::mayorOfficeLifetime() { return true; }

int Socialrank::mayorOfficeSourceClass() {
    return TOWN_UPPER;
}

int Socialrank::aldermanTitleCount() { return 3; }

bool Socialrank::aldermenChosenBy(int tc) {
    return tc == TOWN_UPPER;
}

bool Socialrank::aldermenElectedBy(int tc) {
    return tc == TOWN_MIDDLE;
}

int Socialrank::townJudiciaryStratum() {
    return TOWN_UPPER;
}

int Socialrank::townMilitaryCommandStratum() {
    return TOWN_UPPER;
}

int Socialrank::lawEnforcementSourceClass() {
    return TOWN_MIDDLE;
}

int Socialrank::customsOfficialSourceClass() {
    return TOWN_MIDDLE;
}

int Socialrank::taxOfficialSourceClass() {
    return TOWN_MIDDLE;
}

bool Socialrank::councilorSelectedBy(int tc) {
    return tc == TOWN_UPPER || tc == TOWN_MIDDLE;
}

bool Socialrank::councilorSelectedByLower( bool lowerIsFree) {
    return lowerIsFree;
}

int Socialrank::pettyOfficialsSourceClass() {
    return TOWN_LOWER;
}

bool Socialrank::pettyOfficialRoleAdministrative() {
    return true;
}

bool Socialrank::constabularyIncludesCitizenSoldiers() {
    return true;
}

bool Socialrank::constabularyIncludesWatchOrPolice() {
    return true;
}

bool Socialrank::militiaCalledInGreatNeed() {
    return true;
}

bool Socialrank::soldieryBulkMercenaries() {
    return true;
}

bool Socialrank::knightsHereditary() { return false; }

bool Socialrank::knightPrecedenceVariesByOrder() {
    return true;
}

int Socialrank::nobleTitleRNCount() { return 10; }

int Socialrank::nobleTitleRNPrecedence(int t) {
    // emperor highest, knight lowest
    if (t < 0) t = 0;
    if (t > 9) t = 9;
    return t;
}

int Socialrank::ecclesiasticalRanksAmongNobility() {
    return 4;
}

int Socialrank::germanEquivalentCount() { return 7; }

int Socialrank::germanEquivalentOf(int t) {
    static const int g[10] = {
        -1, -1, 0, 1, 2, 3, 4, -1, 5, 6,
    };
    if (t < 0) t = 0;
    if (t > 9) t = 9;
    return g[t];
}

int Socialrank::asianTitleCount() { return 20; }
