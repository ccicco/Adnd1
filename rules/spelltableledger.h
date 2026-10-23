// =========================================================================================
// Adnd1 - rules/spelltableledger.h
// THE UA SPELL TABLE LEDGER - the R342 PDF-ledger repair: the 6th-level
// column reads, the drifted cells re-seat, the fragment holes resolve, and
// the illusionist UA-new censuses pin
// census 707 -> 708.
//
// The R784 handoff pointed here: the uaspelltables2.h print holes stayed
// pending the PDF. The archive.org full-text OCR of the continued table (pp.
// 30-31) reads the 6th-9th columns; the readable cells cross-check against
// the UA-new description rosters (R361-R368) and the R80 registry. The
// repaired rosters: 6th = 17, 7th = 16, 8th = 10, 9th = 8. The row-number
// column contradicts the alphabetical order and stays unpinned; Glassteel and
// Power Word Kill stay open; the "Whip" doubt strikes (uam2WhipName); the
// illusionist 3rd-6th columns resolve on the UA-new side only. The
// R342/R361/R362 regtest seams re-point at the repaired rosters.
//
namespace rules {

// ---- the ledger (the R785 wiring) ----

// The ledger round: the R342 PDF-ledger holes close here
inline int sldLedgerRound()
    { return 785; }

// The feeder round: the R342 continued-table pins this ledger repairs
inline int sldFeederRound()
    { return 342; }

// The ledger grid row census: one row per repaired MU level (6th-9th)
inline int sldColumnCount()
    { return 4; }

// The repaired 6th roster: 12 readable cells, 3 UA-new description names, 2
// registry rows
inline int sldMu6thRosterCount()
    { return 17; }

// The repaired 7th roster: 9 readable cells, 6 UA-new description names, 1
// registry row
inline int sldMu7thRosterCount()
    { return 16; }

// The repaired 8th roster: 9 readable cells, 1 UA-new description name, 0
// registry rows
inline int sldMu8thRosterCount()
    { return 10; }

// The repaired 9th roster: 5 readable cells, 3 UA-new description names, 0
// registry rows
inline int sldMu9thRosterCount()
    { return 8; }

// The UA-new illusionist 3rd-level census (rules/uailspells3.h): Delude,
// Phantom Steed, Phantom Wind, Wraithform
inline int sldIl3rdNewCount()
    { return 4; }

// The UA-new illusionist 4th-level census (rules/uailspells4.h): Dispel
// Magic, Rainbow Pattern, Solid Fog, Vacancy
inline int sldIl4thNewCount()
    { return 4; }

// The UA-new illusionist 5th-level census (rules/uailspells5.h): Advanced
// Illusion, Dream, Magic Mirror, Tempus Fugit
inline int sldIl5thNewCount()
    { return 4; }

// The UA-new illusionist 6th-level census (rules/uailspells6.h): Death Fog,
// Mislead, Phantasmagoria, Mirage Arcane
inline int sldIl6thNewCount()
    { return 4; }

// The UA-new illusionist 7th-level census (rules/uailspells7.h): Shadow Walk,
// Weird
inline int sldIl7thNewCount()
    { return 2; }

// The illusionist UA-new census total: 4 + 4 + 4 + 4 + 2
inline int sldIlNewTotalCount()
    { return 18; }

// The 6th-level column reads in the archive.org full-text OCR (the
// wholly-lost verdict flips; uas2MuSixthLevelColumnLost() now false)
inline bool sldSixthColumnRead()
    { return true; }

// The R342 contamination repairs: the 6th-column cells that drifted into the
// 7th and 8th blocks re-seat (Tenser's Transformation and Transmute Water To
// Dust among them)
inline bool sldContaminationRepaired()
    { return true; }

// The "Whip" doubt strikes: the uam2WhipName pin proves the cell reads a real
// UA 2nd-level spell
inline bool sldWhipDoubtStruck()
    { return true; }

// The 2nd-column "Flaming" fragment resolves as Flaming Sphere
inline bool sldFlamingIsFlamingSphere()
    { return true; }

// The "Protection From" fragment resolves as the cantrips tail
inline bool sldProtectionFromIsCantrips()
    { return true; }

// The 3rd-column "Detect" fragment resolves as Detect Illusion
inline bool sldDetectIsDetectIllusion()
    { return true; }

// The "Item" fragment resolves against the UA-new rosters
inline bool sldItemResolves()
    { return true; }

// The "Material" fragment resolves against the UA-new rosters
inline bool sldMaterialResolves()
    { return true; }

// The 4th-column "Dispel" fragment resolves as Dispel Illusion
inline bool sldDispelIsDispelIllusion()
    { return true; }

// The 5th-column "Dolor" fragment resolves against the UA-new rosters
inline bool sldDolorResolves()
    { return true; }

// The "Truename" fragment resolves (the repaired 7th roster carries Truename)
inline bool sldTruenameResolves()
    { return true; }

// The "Gravity" fragment resolves as the Reverse Gravity tail
inline bool sldGravityIsReverseGravity()
    { return true; }

// The "Project Im" fragment resolves as Project Image
inline bool sldProjectImIsProjectImage()
    { return true; }

// The illusionist "Mirror" tail seam-decodes as Mirror Image (the R342 read
// stands)
inline bool sldMirrorImagIsMirrorImage()
    { return true; }

// The illusionist "Phantom Wind" fragment resolves (the UA-new 3rd roster
// carries it)
inline bool sldPhantomWindResolves()
    { return true; }

// The "To Flesh" fragment is the Stone To Flesh cell bleeding into the 8th
// block (it re-seats to the 6th column)
inline bool sldToFleshIsSixthColumnBleed()
    { return true; }

// The 6th-column PHB rows the OCR cannot read stay open holes (noted, not
// pinned)
inline bool sldSixthPhbRowsStayOpen()
    { return true; }

// Glassteel and Power Word Kill stay OPEN holes (absent from the print, the
// descriptions, and the registry)
inline bool sldEighthHolesStayOpen()
    { return true; }

// The illusionist 3rd-6th columns resolve only on the UA-new side; the
// PHB-side rows stay lost
inline bool sldIlColumnsPhbSideLost()
    { return true; }

// The printed row-number column stays unreliable (the alphabetical order
// contradicts it); not pinned
inline bool sldRowNumbersUnreliable()
    { return true; }

// ---- the MU column ledger grid (the R785 wiring) ----

// The readable continued-table cells per level (the archive.org OCR:
// 12/9/9/5)
inline int sldReadableCells(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 5;
        default:
            return -1;
        }
    }

// The UA-new description-roster names per level (3/6/1/3: Chain Lightning,
// Ensnarement, Mordenkainen's Lucubration; Banishment, Forcecage, Teleport
// Without Error, Torment, Truename, Volley; Binding; Crystalbrittle,
// Mordenkainen's Disjunction, Succor)
inline int sldDescNewUnreadable(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 1;
        case 3:
            return 3;
        default:
            return -1;
        }
    }

// The registry-proven rows per level (2/1/0/0: Death Spell and Disintegrate;
// Limited Wish)
inline int sldRegistryRows(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        default:
            return -1;
        }
    }

}   // namespace rules
