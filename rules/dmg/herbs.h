// ====================================================================
// Adnd1 - rules/dmg/herbs.h
// R172: Appendix J (DMG p.220) - herbs, spices and
// medicinal vegetables: the alphabetical plant and
// uses table, 171 rows.
//
// Pure data, header-only (the grenade.h pattern:
// the caller rolls and selects; a support table for
// the potion, scroll ink and magic item flavor).
//
// JUDGMENTs: the table structure follows the
// 1eonline.info compilation (the repo-trusted source,
// the R146 precedent), cell-verified against the book
// upload wherever the upload is legible, with per-run
// cell-count arithmetic used to detect compilation
// omissions; print spellings win where they differ;
// the compilation drops the turnip row and truncates
// the celery uses - both restored from the print; the
// benzoin anti-septic line break is read as
// antiseptic; the compilation artifacts (the belladonna
// stray parenthesis, the leek and rose doodles, the
// poppy wikipedia aside, the sage trailing comma and
// star) are normalized; Appendix J was OUT of scope by
// design until R172 reversed it (user-authorized).
// ====================================================================

#pragma once



// ----------------------------------------------------------------------------
// Appendix J: the plant and uses table (p.220)
// ----------------------------------------------------------------------------
struct HerbRow {
    const char* plant;
    const char* uses;  // "?" where the book leaves it unknown
};

// R-refactor: namespace rules -> class Herbs (instance methods)
class Herbs {
public:
    int herbsRowCount();


// The rows: the uses and/or powers column exactly as
// printed. The blueberry row is a printed cross-reference
// to bilberry with an empty uses cell.
    const HerbRow& herbsRow(int i);


// The rows the book leaves with unknown uses ("?").
    int herbsUnknownUsesCount();


// True only for the one printed cross-reference row
// (blueberry - see bilberry, index 49).
    bool herbsIsCrossReference(int i);


// The intro prose: hundreds of different vegetable
// flavorings and seasonings were or are reputed to have
// medicinal and/or magic properties.
    bool herbsIntroHundredsReputedMedicinalAndMagic();


// It is not within the scope of this work to detail all
// of these herbs and spices, particularly as regards
// their description, habitat, and the many uses claimed
// for most.
    bool herbsIntroNotWithinScopeToDetailAll();


// An alphabetical listing with one or two comments on
// each is presented.
    bool herbsIntroAlphabeticalOneOrTwoComments();


// The dedicated herbologist will have to pursue his or
// her research in scholarly texts.
    bool herbsIntroHerbologistPursuesScholarlyTexts();


// The closing prose: use the list as a guide to which
// herbs, spices or vegetables are required for various
// magical effects desired from potions, scroll inks and
// other magic items.
    bool herbsClosingGuideForPotionsInksItems();


// You may add to or delete from the list as you desire.
    bool herbsClosingAddOrDeleteAsDesired();


// Reputed folk uses are not detailed with respect to
// magic in most cases, as this decision is the purview
// of the DM.
    bool herbsClosingFolkUsesMagicDMPurview();
};
