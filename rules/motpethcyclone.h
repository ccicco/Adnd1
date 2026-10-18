// =========================================================================================
// Adnd1 - rules/motpethcyclone.h
// THE ETHER CYCLONE - printed p. 17, the Ethereal chapter's storm: the
// warning doctrine, the d20 effects table, and the curtain-blow aftermath
// rules - the one named table the R566 full-book scan missed, found by the
// R596-post full-coverage audit.
// census 520 -> 521.
//
// verified against printed p. 17 of the uploaded motp.pdf OCR (OCR page 18);
// the 50% warning with its 1d6-round herald, the four d20 bands (1-10 the
// disrupted flow, 11-15 the random curtain, 16-18 the farther curtain, 19-20
// the saving throw), the added-day dice (5d12 and 10d12), and the Border
// Ethereal fallback rules pinned from the OCR text as printed; the gap census
// grows 90 -> 91 boxes (91/0).
//
// the gap census after this round: 91 closed, 0 open - the missed table gets
// its box; the R566 amended-manifest promise (every named table its own line
// item) now kept whole.
//
namespace rules {

// ---- the Ether Cyclone pins ----

// the warning chance: fifty percent of the time travelers receive warning of
// the approaching cyclone - 1d6 rounds of it - the other fifty percent, none
// at all. The warning sign is a deep hum in the ethereal matter underneath,
// portions ripped away by the approaching storm.
inline int dedCycloneWarningChance()
    { return 50; }

// the warning, when it comes, gives 1d6 rounds before the cyclone strikes -
// time to reach a safe haven: another plane, a demi-plane, the Border
// Ethereal, or a curtain.
inline int dedCycloneWarningRoundsHigh()
    { return 6; }

// the first d20 band, 1-10: the flow of the ether is disrupted - add four
// hours (one additional encounter check) to the travel time.
inline int dedCycloneDisruptedHigh()
    { return 10; }

// the disrupted-flow band adds four hours to the travel time - one additional
// encounter check.
inline int dedCycloneDisruptedHours()
    { return 4; }

// the second d20 band, 11-15: the party is blown through a curtain into the
// Border Ethereal of a random plane or demi-plane - the usual encounter check
// for crossing a curtain, and the journey must begin again.
inline int dedCycloneCurtainHigh()
    { return 15; }

// the third d20 band, 16-18: blown through a curtain into the Border Ethereal
// of a random plane farther from the original destination - the journey
// restarts with 5d12 days added.
inline int dedCycloneFartherHigh()
    { return 18; }

// the farther-plane blow adds 5d12 days to the total travel time.
inline int dedCycloneFartherDaysDice()
    { return 5; }

// the farther-plane blow's added days roll 5d12.
inline int dedCycloneFartherDaysSides()
    { return 12; }

// the fourth d20 band, 19-20: the saving-throw band.
inline int dedCycloneSaveHigh()
    { return 20; }

// the 19-20 save made: the party is blown far from their tracks to an
// unexplored section of the Ethereal - 10d12 days added to reach any other
// plane or destination.
inline int dedCycloneLostDaysDice()
    { return 10; }

// the unexplored-section blow's added days roll 10d12.
inline int dedCycloneLostDaysSides()
    { return 12; }

// one roll per group: all caught in the cyclone suffer the same d20 effects -
// though the aftermath saves are per member.
inline bool dedCycloneGroupRoll()
    { return true; }

// the 19-20 band: the lowest-level member of the party makes the saving throw
// vs. spell - success blows the party to an unexplored section, failure blows
// the entire party into the Astral plane.
inline bool dedCycloneLowestLevelSaves()
    { return true; }

// the failed-save tumble into the Astral is as for plane shift and does not
// require a silver cord.
inline bool dedCycloneAstralNoCord()
    { return true; }

// blown through a curtain into the Border Ethereal of the Prime or a
// hospitable demi-plane: each member saves vs. spell - success remains in the
// Border, failure flings the individual back into the Prime plane or
// demi-plane, no longer ethereal or invisible.
inline bool dedCyclonePrimeFallback()
    { return true; }

// travelers blown through a curtain into an inner plane or an inhospitable
// demi-plane stop in the Border Ethereal and are not transported into the
// plane.
inline bool dedCycloneInnerBorderStop()
    { return true; }

// the Border Ethereal is dangerous in its own right in some cases - the
// demi-plane of Time is the book's named example.
inline bool dedCycloneTimeBorderDanger()
    { return true; }

}   // namespace rules
