// =========================================================================================
// Adnd1 - rules/wwt.h
// The witchcraft wilderness encounter table round - the folio-4 grid,
// resolved legible by the chat-side upload cross-check: armor class 8, the
// 9/24 move, hit dice 4-7, the 30/45 lair lines and the number-appearing
// terrain bands
// census 826 -> 827.
//
// Pinned from The Dragon Vol. 1 No. 5 (March 1977), folio 4, the Witchcraft
// Supplement's wilderness encounter table - the grid the archive.org DjVu OCR
// garbled and R902 scoped out per the standing OCR-table caution. The
// chat-side upload cross-check (Curtiss's Dragon_Magazine_005.pdf, October
// 29) made the grid fully legible: number appearing by terrain (Mts/Desert
// none, Riv/Swamps 2-4, Clear 1-3, Towns/Woods 2-13), armor class 8, movement
// 9 on foot and 24 on broom, hit dice 4-7, and the lair lines - Lawful Witch
// 30 percent, Chaotic Witch 45 percent, the Secret Order witches excepted at
// their own 75 percent any-terrain one-only line already pinned at R902. The
// same cross-check confirmed every pages-1-5 pin of R902 against the upload's
// voice - the encounter doctrine, the Order ladder, the quotas, the
// immunities and the spell matrix through Curse - with one voice quirk noted
// below. The upload's extraction capped at page 5, so pages 6-32 remain
// single-voice archive.org; the provenance recorded at R902 stands for those
// pages.
//
// The cross-check doctrine rides: the pin IS the conversion, and the second
// voice settles the garbled cell - the wilderness table pins exactly as the
// upload reads it, the terrain none band as the 0 sentinel, and the
// scoped-out sentence in tools/dragon_gap_report_005.md updates by file patch
// to record the resolution, never silently. The Comfort spell's duration
// quirk is noted and settled by arithmetic: the upload reads 'D = 3b (6
// hours)' where the archive.org scan reads 'D = 36', and 6 hours at 10
// minutes per turn is 36 turns - the R902 pin of 36 stands. No new registry
// ink: this is a pure variant-layer const round against the R902 Witchcraft
// Supplement chain, no lua defs, no transcripts, no gap flips.
//
namespace rules {

// ---- the wilderness encounter grid (folio 4) ----

// the witch armor class - 8 on the wilderness encounter table (folio 4)
inline int wwtWitchAc()
    { return 8; }

// the witch movement - 9 inches on foot (folio 4)
inline int wwtWitchMoveFoot()
    { return 9; }

// the witch movement - 24 inches on broom (folio 4)
inline int wwtWitchMoveBroom()
    { return 24; }

// the witch hit dice, minimum - 4 (folio 4)
inline int wwtWitchHdMin()
    { return 4; }

// the witch hit dice, maximum - 7 (folio 4)
inline int wwtWitchHdMax()
    { return 7; }

// the Lawful witch percent in lair - 30 (folio 4)
inline int wwtLawfulWitchLairPct()
    { return 30; }

// the Chaotic witch percent in lair - 45 (folio 4)
inline int wwtChaoticWitchLairPct()
    { return 45; }

// all other evil witches and the Lawful witches comply with this table - the
// Secret Order witches excepted at their own 75 percent any-terrain one-only
// line, already pinned at R902 (folio 4)
inline bool wwtTableAppliesToAll()
    { return true; }

// the number of witches encountered is a factor of terrain - best suited to
// certain environments, the woodlands and orchards favored most of all (folio
// 4)
inline bool wwtTerrainFactor()
    { return true; }

// a witch in her lair has the use of every portable magic device in her hoard
// - the GM must determine the items, as they may affect the battle when the
// lair is invaded (folio 4)
inline bool wwtLairDeviceAccess()
    { return true; }

// the terrain band count - 4 rows as scanned: Mts/Desert, Riv/Swamps, Clear,
// Towns/Woods (folio 4)
inline int wwtTerrainNaCount()
    { return 4; }

// the number appearing minimum by terrain - 0 the sentinel for the Mts/Desert
// none (folio 4)
inline int wwtTerrainNaMin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return 0;
        }
    }

// the number appearing maximum by terrain - 0 the sentinel for the Mts/Desert
// none (folio 4)
inline int wwtTerrainNaMax(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 13;
        default:
            return 0;
        }
    }

}   // namespace rules
