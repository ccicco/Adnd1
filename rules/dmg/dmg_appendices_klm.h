// ====================================================================
// Adnd1 - rules/dmg/dmg_appendices_klm.h
// R171: Appendices K, L and M (DMG pp.221-224) -
// the magical substance word lists, the conjured
// animals table and the summoned monsters tables.
//
// Pure data, header-only (the grenade.h pattern:
// the caller rolls and selects; support tables for
// the conjure and summon spell effects).
//
// JUDGMENTs: the K lists were cell-verified against
// the 1eonline.info compilation (the repo-trusted
// source, the R146 precedent); the Appendix L
// 5-and-up section is pinned R175 (the full table
// from the trusted compilation; the book upload
// drops the band columns); the whale cap and the
// water note are pinned; the Appendix M water tables for
// summonings II-VI come from the trusted compilation,
// which agrees with the upload on the I and VII water
// tables the upload shows.
// ====================================================================

#pragma once



// ----------------------------------------------------------------------------
// Appendix L: conjured animals (pp.222-223)
// ----------------------------------------------------------------------------
struct ConjuredAnimalRow {
    int lo;
    int hi;
    const char* name;
    int costQ;  // the hit dice cost in quarters
};



// R175: the full 5-and-up section - hit dice
// categories 5-14, every band, name and quarter
// cost. Source: the 1eonline.info compilation
// (the repo-trusted source), whose
// conjure-animals page carries the complete
// table the book upload drops. JUDGMENTs: the
// R171 20-name roster was incomplete (buffalo,
// skunk giant, lion, bear cave and boar giant
// were absent) - replaced by the full table;
// the compilation spelling woolly corrects the
// pinned wooly; the bandless rows the print
// dashes (9, 11, 13, 14) pin as lo/hi 0.
struct ConjHigherRow {
    int cat;           // hit dice category (5-14)
    int lo, hi;        // 0,0 = the printed dash
    const char* name;
    int cost;          // quarter hit dice (5 = 20)
};



// ----------------------------------------------------------------------------
// Appendix M: summoned monsters (pp.223-224)
// ----------------------------------------------------------------------------
struct SummonedMonsterRow {
    int lo;
    int hi;
    const char* name;
    const char* evilAlt;  // null: no parenthesis
};

// R-refactor: namespace rules -> class Dmg_appendices_klm (instance methods)
class Dmg_appendices_klm {
public:


// ----------------------------------------------------------------------------
// Appendix K: describing magical substances (p.221)
// ----------------------------------------------------------------------------
    int klmAppearanceCount();
    const char* klmAppearance(int i);
    int klmTransparencyCount();


// The printed text with its parenthetical.
    const char* klmTransparency(int i);


// True where the printed parenthetical asks the
// reader to determine transparency or colors.
    bool klmTransparencyNeedsDetermination(int i);


// The color list: 74 words in 11 printed groups.
    int klmColorGroupCount();
    const char* klmColorGroupName(int g);
    int klmColorGroupSize(int g);


// The word at index j within group g.
    const char* klmColorWord(int g, int j);
    int klmTasteCount();
    const char* klmTaste(int i);


// In combination with Appendix I dungeon dressing
// or by itself.
    bool klmUsedWithDungeonDressing();


// The prose: fractional hit point costs must be
// charged off against the total conjurable; where
// several possibilities exist a number for random
// selection has been assigned, for the caster cannot
// specify what sort of animal will come.
    bool klmConjFractionalCostCharged();
    bool klmConjRandomSelectionWhereSeveral();
    bool klmConjCasterCannotSpecify();
    int klmConjCategoryCount();
    int klmConjRowCount(int c);
    const ConjuredAnimalRow& klmConjRow(int c, int r);
    int klmConjHigherCount();
    const ConjHigherRow& klmConjHigherRow(int i);


// Whales only, to a maximum of 36 hit dice cost.
    int klmConjWhaleMaxHitDiceCost();


// If in or on water, only the appropriate sorts
// of animals can be called, i.e. swimmers and
// flying ones, where applicable.
    bool klmConjWaterSwimmersAndFlyersOnly();


// If the summoner is evil, the monster in
// parentheses may be used; and it is always
// within the DM purview to select the monster
// and appoint the numbers.
    bool klmSummonEvilUsesParenthesis();
    bool klmSummonDMMaySelectAndAppoint();
    int klmSummonLandTableCount();
    int klmSummonLandRowCount(int t);
    const SummonedMonsterRow& klmSummonLandRow( int t, int r);


// The water tables: fresh and salt for each
// summoning (VI is fresh or salt, one table).
    int klmSummonWaterTableCount();
    const char* klmSummonWaterTableName(int t);
    int klmSummonWaterRowCount(int t);
    const SummonedMonsterRow& klmSummonWaterRow( int t, int r);
};
