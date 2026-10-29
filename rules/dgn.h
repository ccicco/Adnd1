// =========================================================================================
// Adnd1 - rules/dgn.h
// The Dragon issue-9 opener - the Gygax alignment article (folios 5-6) and
// the Ward Tombs & Crypts article (folio 25): two adjudicated chains in one
// round
// census 834 -> 835.
//
// Pinned from The Dragon Vol. II No. 3 (September 1977), the archive.org scan
// voice (single-voice: no chat-side upload cross-check exists for issue 9;
// the source lives in the archive.org item accessory-dragon-magazine-012).
// The folios: 5-6, the Gygax Designers Forum alignment article - player
// characters not knowing encountered alignments in the normal course, the new
// character dissembled as neutral or agreeable until strong enough to survive
// the block, the abrupt concealed change, the Greyhawk precept that good is
// the end sought by the majority of humanity and its allied races, the
// lawful-good-vs-chaotic-good war not precluded with either or both allied
// with evil beings, most places a mixture of alignments, the Free City's
// neutral-in-outlook oligarchs with free commerce and carefully thwarted
// preeminence, the cleric's shrine cutting expenses to zero then the temple
// escalation arousing rival-cleric enmity, government suspicion, levied taxes
// and survival bribes that skyrocket in open conflict, influence
// proportionate to power in the own area and relative to its importance,
// influence allowable but dictation not, the uncoerced alignment choice, and
// all campaign events subject to DM intervention; 25, the Ward Tombs & Crypts
// article - the d12 occupant roll across soldier, hero, priest, pair, mated
// pair, lord, king, patriarch, EHP, magic user, wizard and being, the nine
// item rolls per tomb, the over-100 assume-100-and-reroll-without-bonus and
// under-0 assume-01 rules, the maps band (1-80 none, 81-100 the judge's
// option), the special-item band (1-85 none, 86-100 the judge's own
// manufacture), the guardian chain (none, the magic spell, the 1-4 invisible
// stalkers, the 6th-level-chart creature, the stronger monster), the
// tomb-structure chain from the 1-room mound through the 2-6 room complex,
// the 1-10 rooms with 1-10 traps, the 1-10 rooms with 1-20 corridors and 2-20
// traps, the connecting rooms with magical guards, to the 1-20 room
// special-word tomb whose word is not found inside, and the gold-piece, gems,
// jewelry and misc-magic tables. The transcripts ride extract/dragon/009/
// (all 32 issue pages); the issue-9 gap report ships pre-flip. PRINT FOLIO =
// PDF PAGE, verified at the printed 4, 7, 8, 9, 10, 11, 12, 14, 20, 21, 22
// and 23 footers.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// the Gygax alignment article - though it prefigures the later print - pins
// as a variant layer with provenance, never core canon. The Ward print quirks
// ride AS SCANNED, noted, never silent: the gold-piece table's 51-60 x2 row
// and its garbled 100 row (the '100,00 Thousand' OCR) never guessed - only
// the five clean bands pin; the guardian 100-band's tail text garbled - the
// band index pins, the prose rides; the per-occupant modifier grid garbled
// whole in the OCR and riding the transcript; the Barker EPT column and the
// Blume Boot Hill ratings scoped out per the standing other-system precedent
// (R904, R906, R907). The editor's standing caution rides: none of this is
// official.
//
namespace rules {

// ---- the Gygax alignment article (folios 5-6) ----

// player characters will not know the alignment of persons they encounter in
// the normal course of affairs (folio 5)
inline bool dgnAlignmentUnknownByDefault()
    { return true; }

// the new character may be listed as neutral or agreeable and carefully
// played concealed (folio 5)
inline bool dgnDissemblingAlignmentAllowed()
    { return true; }

// the abrupt alignment change comes when the character can survive in
// opposition to the block (folio 5)
inline bool dgnConcealedChangeAtStrength()
    { return true; }

// the Greyhawk precept - good is the end sought by the majority of humanity
// and its allied races (folio 5)
inline bool dgnGreyhawkGoodMajorityPrecept()
    { return true; }

// a war of lawful good against chaotic good is not precluded, either or both
// allied with evil beings (folio 5)
inline bool dgnGoodVsGoodWarPossible()
    { return true; }

// most places contain a mixture of alignments (folio 5)
inline bool dgnMixedAlignmentsUsual()
    { return true; }

// the Free City oligarchs are neutral in outlook if not in alignment (folio
// 5)
inline bool dgnGreyhawkOligarchsNeutralOutlook()
    { return true; }

// commerce is free and all alignments co-exist on equitable terms in the Free
// City (folio 5)
inline bool dgnGreyhawkCommerceFree()
    { return true; }

// any preeminence of alignment is carefully thwarted by the rulers of the
// Free City (folio 5)
inline bool dgnGreyhawkPreeminenceThwarted()
    { return true; }

// the shrine-level establishment cuts expenses to zero if not a small profit
// (folio 5)
inline bool dgnClericShrineSelfSupporting()
    { return true; }

// the temple or patriarchate proclamation arouses the enmity of rival clerics
// and the government (folio 6)
inline bool dgnTempleEscalationArousesEnmity()
    { return true; }

// taxes are levied and bribes paid to survive, skyrocketing in open conflict
// (folio 6)
inline bool dgnTaxesLeviedBribesPaid()
    { return true; }

// influence is proportionate to power in the own area, relative to the area
// importance (folio 6)
inline bool dgnInfluenceProportionateToPower()
    { return true; }

// influence upon alignment is quite allowable, dictation is not (folio 6)
inline bool dgnInfluenceAllowedDictationNot()
    { return true; }

// participants have the right of uncoerced alignment choice (folio 6)
inline bool dgnUncoercedAlignmentChoice()
    { return true; }

// all that takes place in the campaign is subject to DM intervention (folio
// 6)
inline bool dgnDmInterventionDoctrine()
    { return true; }

// ---- the Ward Tombs & Crypts article (folio 25) ----

// the d12 occupant roll - soldier, hero, priest, pair, mated pair, lord,
// king, patriarch, EHP, magic user, wizard, being (folio 25)
inline int dgnTombOccupantTypes()
    { return 12; }

// roll for each of the 9 items per tomb (folio 25)
inline int dgnTombItemRolls()
    { return 9; }

// an over-100 total assumes a 100 roll and rolls again without the occupant
// bonus (folio 25)
inline int dgnTombOverflowCeiling()
    { return 100; }

// a total under 0 assumes an 01 roll (folio 25)
inline int dgnTombFloorRoll()
    { return 1; }

// the five clean gold-piece bands pinned - the 51-60 x2 row and the garbled
// 100 row ride the transcript as scanned (folio 25)
inline int dgnTombGoldBands()
    { return 5; }

// the gems table bands - 1-50 through the 100 row (folio 25)
inline int dgnTombGemsBands()
    { return 7; }

// the jewelry table bands - 1-50 through the 100 row (folio 25)
inline int dgnTombJewelryBands()
    { return 7; }

// the misc-magic bands - none plus the five Greyhawk tables (folio 25)
inline int dgnTombMiscMagicBands()
    { return 6; }

// the tomb-structure bands - the 1-room mound through the special-word tomb
// (folio 25)
inline int dgnTombItselfBands()
    { return 7; }

// the guardian band 51-80 - invisible stalker(s), 1-4 (folio 25)
inline int dgnGuardianStalkerMin()
    { return 1; }

// the guardian band 51-80 stalker maximum (folio 25)
inline int dgnGuardianStalkerMax()
    { return 4; }

// the 81-90 tomb-structure band - 1-20 corridors (folio 25)
inline int dgnTombCorridorsMin()
    { return 1; }

// the 81-90 tomb-structure band corridor maximum (folio 25)
inline int dgnTombCorridorsMax()
    { return 20; }

// the pair factor is more than one being buried in the tomb (folio 25)
inline bool dgnTombPairIsTwoBuried()
    { return true; }

// the mated pair is a husband-and-wife type tomb, not necessarily human
// (folio 25)
inline bool dgnTombMatedPairShared()
    { return true; }

// the 12th factor is an intelligent creature honored by followers with a
// special crypt (folio 25)
inline bool dgnTombBeingCryptOfHonor()
    { return true; }

// the over-100 re-roll rolls again without the occupant bonus (folio 25)
inline bool dgnTombOverflowDropsBonus()
    { return true; }

// the special word opening the final door should not be found in the tomb
// (folio 25)
inline bool dgnTombFinalWordNotInside()
    { return true; }

// the maps band - 1-80 none, 81-100 the judge option (folio 25)
inline int dgnTombMapBand(int x)
    {
        if (x <= 80) return 0;
        return 1;
    }

// the special-item band - 1-85 none, 86-100 the judge own manufacture (folio
// 25)
inline int dgnTombSpecialBand(int x)
    {
        if (x <= 85) return 0;
        return 1;
    }

// the guardian chain - none, the magic spell, the 1-4 invisible stalkers, the
// 6th-level-chart creature, the stronger monster (folio 25)
inline int dgnTombGuardianBand(int x)
    {
        if (x <= 30) return 0;
        if (x <= 50) return 1;
        if (x <= 80) return 2;
        if (x <= 99) return 3;
        return 4;
    }

// the tomb-structure chain - the seven bands from the 1-room mound to the
// special-word tomb (folio 25)
inline int dgnTombItselfBand(int x)
    {
        if (x <= 40) return 0;
        if (x <= 50) return 1;
        if (x <= 60) return 2;
        if (x <= 80) return 3;
        if (x <= 90) return 4;
        if (x <= 99) return 5;
        return 6;
    }

// the gold-piece band minimum in pieces - the 1-100 piece row through the
// 2-40 thousand row, the 51-60 x2 and garbled 100 rows riding the transcript
// (folio 25)
inline int dgnTombGoldPiecesMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1000;
        case 2:
            return 1000;
        case 3:
            return 1000;
        case 4:
            return 2000;
        default:
            return -1;
        }
    }

// the gold-piece band maximum in pieces - as scanned (folio 25)
inline int dgnTombGoldPiecesMax(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 6000;
        case 2:
            return 12000;
        case 3:
            return 20000;
        case 4:
            return 40000;
        default:
            return -1;
        }
    }

// the gems band count minimum, 1-6 through the 1-20 base row (folio 25)
inline int dgnTombGemCountMin(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return -1;
        }
    }

// the gems band count maximum (folio 25)
inline int dgnTombGemCountMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 6;
        case 6:
            return 20;
        default:
            return -1;
        }
    }

// the gems band base value - 100 through 10,000 (folio 25)
inline int dgnTombGemBaseValue(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 500;
        case 2:
            return 500;
        case 3:
            return 500;
        case 4:
            return 1000;
        case 5:
            return 5000;
        case 6:
            return 10000;
        default:
            return -1;
        }
    }

// the jewelry band count minimum (folio 25)
inline int dgnTombJewelryCountMin(int b)
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
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return -1;
        }
    }

// the jewelry band count maximum, 1-20 at the 100 row (folio 25)
inline int dgnTombJewelryCountMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 20;
        default:
            return -1;
        }
    }

// the jewelry band base value - 500 through 50,000 (folio 25)
inline int dgnTombJewelryBaseValue(int b)
    {
        switch (b) {
        case 0:
            return 500;
        case 1:
            return 1000;
        case 2:
            return 5000;
        case 3:
            return 10000;
        case 4:
            return 20000;
        case 5:
            return 30000;
        case 6:
            return 50000;
        default:
            return -1;
        }
    }

// the misc-magic band Greyhawk table - 0 none, 1 through 5 the Greyhawk
// tables I to V (folio 25)
inline int dgnTombMiscMagicTable(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        default:
            return 0;
        }
    }

// the tomb-structure band rooms minimum - the hall band and the
// unstated-count bands sentinel -1 (folio 25)
inline int dgnTombItselfRoomsMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        default:
            return -1;
        }
    }

// the tomb-structure band rooms maximum (folio 25)
inline int dgnTombItselfRoomsMax(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 20;
        default:
            return -1;
        }
    }

// the tomb-structure band traps minimum - the unstated-count bands sentinel
// -1 (folio 25)
inline int dgnTombItselfTrapsMin(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 1;
        case 2:
            return -1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return -1;
        case 6:
            return -1;
        default:
            return -1;
        }
    }

// the tomb-structure band traps maximum (folio 25)
inline int dgnTombItselfTrapsMax(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 1;
        case 2:
            return -1;
        case 3:
            return 10;
        case 4:
            return 20;
        case 5:
            return -1;
        case 6:
            return -1;
        default:
            return -1;
        }
    }

}   // namespace rules
