// =========================================================================================
// Adnd1 - rules/worshipsites.h
// THE WORSHIP SITES - the last unpinned Appendix S chart read: the
// place-of-worship kinds, the cleric-gender grid, and the print verdict on
// the contaminated chart rows
// census 706 -> 707.
//
// The R783 handoff deferred the five clerical chart rows (spheres, raiment,
// holy days, sacrifice) as blocked on chart-extraction contamination. This
// round unblocked them: all 23 deity pages re-fetched from the 1eonline.info
// compilation (the repo-trusted R189 source), the chart tables parsed cell
// for cell, and the print itself read via the archive.org full-text OCR of
// pp. 121-122. THE VERDICT: every R407 pin stands - the contamination is
// compilation-side (the Hanali chart row carries Solonor's cells wholesale,
// Labelas's sphere cell prints Erevan's sphere, the Arvoreen and Segojan and
// Aerdrie rows carry spelling variants), so no chart repair was owed. THE
// PINS: the two per-row reads the chart carries that R407 left unpinned - the
// place-of-worship (16 distinct kinds, the prose under each chart: the
// battlefield pair Clangeddin and Bahgtru, the four dwarven underground
// temples, Aerdrie's open hilltops, Hanali's fountain or spring, Labelas's
// small grove, Solonor's deep forest, Erevan's never-the-same-place-twice,
// Sheela's open field, Cyrrollalee's the home, the two anywhere pairs,
// Baervan's forest clearing, Urdlen's underground cavern, Segojan's
// subterranean temple, Flandal's underground forge, Yurtrus's underground
// crypt, Luthic's temple within a cave) and the cleric-gender grid (12
// males-only rows - the male dwarves, the gnomish all-male, the non-Luthic
// orcs; the lone Berronar females-only row; 10 either-gender rows - the
// elves, the halflings, Luthic). The printed site strings ride
// rules/uascharts.h (the uscWorshipSite accessor) with a live regtest strings
// block walking all 23 rows row for row (the R782 site-block precedent).
// Honest boundaries: the M, F, and N-H columns on the compilation pages are
// the compilation's own additions, not print chart columns - they stay
// contract-side; the print's own typos (the Erevan "can by worshiped", the
// one-r Cyrollalee prose) ride the prose; the pantheon prose stays open (R423
// stands)
//
// Zero new book pages: the worship-site reads ride the Appendix S pp. 121-122
// chart and prose the R405/R406/R407 pins already seat, the compilation rides
// the R189 duty already trusted, and the print OCR rode the archive.org
// full-text read (the source-verification class)
//
namespace rules {

// ---- the worship sites (the R784 wiring) ----

// The worship-site grid row census: 23 rows in the R405/R406/R783 registry
// order (dwarves, elves, halflings, gnomes, orcs)
inline int plcDeityRowCount()
    { return 23; }

// The worship-site round: the last unpinned Appendix S chart read
inline int plcWorshipSiteRound()
    { return 784; }

// The feeder round: the R407 five-chart pins this round re-verifies against
// the print and extends
inline int plcChartFeederRound()
    { return 407; }

// The distinct place-of-worship kinds the print prose names (codes 0-15)
inline int plcSiteKindCount()
    { return 16; }

// The males-only gender census: the four male dwarves, the four gnomes, the
// four non-Luthic orcs (Berronar alone reads female-only)
inline int plcMaleOnlyClericRows()
    { return 12; }

// The females-only gender census: the Berronar row alone (the lone female
// deity of the five pantheons)
inline int plcFemaleOnlyClericRows()
    { return 1; }

// The either-gender census: the five elves, the four halflings, Luthic
inline int plcEitherGenderClericRows()
    { return 10; }

// The anywhere census: Arvoreen, Brandobaris, Shargaas, Ilneval (the halfling
// and orc anywhere pairs)
inline int plcAnywhereSiteRows()
    { return 4; }

// The underground census: the four dwarven temples, the cavern, the
// subterranean temple, the forge, the crypt, the cave temple
inline int plcUndergroundSiteRows()
    { return 9; }

// The Hanali kind: by a fountain or spring (the compilation row carries
// Solonor's cells wholesale; the print stands)
inline int plcFountainSiteKind()
    { return 3; }

// The Erevan kind: never the same place twice (the print's own "can by
// worshiped" typo rides the prose, not the pin)
inline int plcNeverSamePlaceKind()
    { return 6; }

// The Berronar row index: the lone female-deity read (the females-only gender
// cell)
inline int plcFemaleOnlyDeityRow()
    { return 4; }

// The place-of-worship reads print in the prose under the five clerical
// charts, not a chart column (the strings ride rules/uascharts.h, the kinds
// and genders pin here)
inline bool plcSitesRideTheChartProse()
    { return true; }

// The five R407 chart rows re-verify against the print (the archive.org
// full-text OCR of pp. 121-122): every pinned cell stands, and every
// divergence rides the compilation side
inline bool plcChartRowsVerifiedAgainstPrint()
    { return true; }

// The compilation's Hanali chart row carries Solonor's cells wholesale
// (sphere, animal, raiment, colors, form, site); the print's romance, bare,
// gold robes, fountain-or-spring row stands
inline bool plcHanaliRowContaminationStandsPrint()
    { return true; }

// The only restriction on where Erevan can be worshiped: never in the same
// place twice
inline bool plcErevanNeverSamePlaceTwice()
    { return true; }

// Clangeddin is worshiped on the battlefield; the other four dwarves are
// worshiped in underground temples carved from natural rock
inline bool plcDwarvenRestWorshipInTemples()
    { return true; }

// The halfling anywhere pair: services for Arvoreen and Brandobaris may be
// conducted anywhere (Sheela requires an open field, Cyrrollalee the home)
inline bool plcHalflingAnywherePair()
    { return true; }

// The orc anywhere pair: services for Shargaas and Ilneval anywhere (Bahgtru
// requires a battlefield, Yurtrus an underground crypt, Luthic a temple
// within a cave)
inline bool plcOrcAnywherePair()
    { return true; }

// Luthic's worship is one of the few that allows both male and female orcs to
// become clerics; nearly all of the other deities permit male clerics only
inline bool plcLuthicAllowsBothGenders()
    { return true; }

// The M, F, and N-H columns on the compilation pages are the compilation's
// own additions, not print chart columns; the print states the gender reads
// in the prose, pinned here per row (the columns stay contract-side)
inline bool plcGenderColumnsRideTheCompilation()
    { return true; }

// ---- the site grid (the R784 wiring) ----

// The place-of-worship kind: 0 battlefield, 1 underground temple, 2 open
// hilltops, 3 by a fountain or spring, 4 small grove, 5 deep forest, 6 never
// the same place twice, 7 open field, 8 the home, 9 anywhere, 10 forest
// clearing, 11 underground cavern, 12 subterranean temple, 13 underground
// forge, 14 underground crypt, 15 a temple within a cave (the prose under the
// five clerical charts, pp. 121-122)
inline int plcSiteKind(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 7;
        case 11:
            return 9;
        case 12:
            return 8;
        case 13:
            return 9;
        case 14:
            return 10;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 13;
        case 18:
            return 0;
        case 19:
            return 9;
        case 20:
            return 9;
        case 21:
            return 14;
        case 22:
            return 15;
        default:
            return -1;
        }
    }

// The cleric gender read: 0 males only, 1 females only, 2 either gender (the
// pantheon prose: the dwarven male/female split, the elven and halfling
// either-gender, the all-male gnomish, the Luthic exception)
inline int plcClericGender(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 2;
        default:
            return -1;
        }
    }

}   // namespace rules
