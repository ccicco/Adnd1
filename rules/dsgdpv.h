// =========================================================================================
// Adnd1 - rules/dsgdpv.h
// The DSG DPV AND HYPOTHERMIA, R513: the printed pp. 40-42 (pdf 41-43) - the
// defensive point values section (the DMG page-110 fortification seam, the
// natural and constructed formations assigned DPVs, the
// destroy-on-attack-or-spell use, the cubic-open-space reading where the
// value is the damage needed to collapse the ceiling, the chain-reaction
// follow-up check after a collapse, and the Table 19 thirteen-formation grid
// - room 10-ft tube 50, room 20-ft cube 90, column 3-ft 10, column 10-ft 100,
// wall 10-ft square 20, bridge small wooden 12, bridge small stone 40, bridge
// large stone 80, rock ledge per 1-ft 10, ceiling small cavern 100, ceiling
// large cavern 250, stalactite small 8, stalactite large 20) and the
// hypothermia optional rule (the damp-chill preamble, the one-turn swimming
// onset with the no-heat-source assumption, the shallow-water risk reduction
// - knee-to-waist deep one hour, shallower than knee no threat - the
// Constitution Check after onset with 1d6 lost on a failure repeated every
// turn, the losses accumulating until an external heat source and even after
// leaving the water, the 1d6-per-turn recovery by a fire or warm-blooded
// creatures until fully recovered, the cold-adapted and ring-of-warmth
// immunity, and the grease or oil coating doubling both the time before the
// first check and the interval between checks)
// census 437 -> 438.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read (idx 54 = printed p. 41, idx 55-57
// = printed p. 42) - the Table 19 grid confirmed THREE WAYS: the chapter djvu
// read and the compiled-tables appendix reprint (djvu.txt line 15570ff) agree
// on all thirteen rows, with the Capture layer partially corroborating (Room
// 10- 50, Column 3 10, Column 10^4 diameter 100, Wall 10-fl square 20, Bridge
// small wooden 12, Ceiling large cavern 250; the Capture garble 104 = 10-ft
// and the appendix drop of the word Stalactite on the small 8 row are both
// settled by the chapter read). The hypothermia numbers dual-confirmed by
// Capture idx 56-57: the Constitution Check, the 1d6 loss per failed check,
// the per-turn repetition, the 1d6-per-turn recovery, the
// fire/warm-blooded-creature source, the ring-of-warmth immunity and the
// grease doubling. The Magnetic Effects of Lodestone section starts the NEXT
// round per the content-density rule.
//
// Table 19 pins as a 13x2 grid: the row key and the Defensive Point Value,
// each the damage needed to destroy the formation (or, for a cubic open
// space, to collapse its ceiling). The hypothermia dice pin as dice + sides
// consts (loss 1d6, recovery 1d6) per the R508 convention. The DMG page-110
// seam and the wsgheat.h cross-book seam are noted but nothing auto-credits;
// the R512 chain reaction procedure is the collapse follow-up.
//
namespace rules {

// ---- the defensive point values section ----

// constructed fortifications have Defensive Point Values, as explained in the
// DMG (page 110), and many natural and constructed underground formations are
// assigned DPVs too - the cross-book seam.
inline bool dnyFortificationsHaveDpv()
    { return true; }

// use these Defensive Point Values to determine if an area is destroyed by
// the effects of an attack or spell.
inline bool dnyDpvDestroysOnAttackOrSpell()
    { return true; }

// when a Defensive Point Value is provided for a cubic open space, the value
// equals the amount of damage needed to cause the area's ceiling to collapse.
inline bool dnyCubicOpenSpaceCeiling()
    { return true; }

// after a DPV collapse, check for additional ceiling or wall collapses with
// the normal chain reaction procedure - the R512 rules/dsgcavein2.h seam.
inline bool dnyCollapseChecksChainReaction()
    { return true; }

// ---- the hypothermia onset ----

// the damp chill of the underworld air is decidedly unhealthy for most
// creatures; the streams, rivers and lakes of the Underdark can numb a
// character who suffers prolonged exposure to their bone-chilling cold
// waters.
inline bool dnyDampChillUnhealthy()
    { return true; }

// a character becomes subject to hypothermia - a disastrous lowering of body
// temperature - after one turn of swimming in a typical underground body of
// water.
inline int dnySwimTurnsToOnset()
    { return 1; }

// the one-turn swimming onset assumes no subterranean heat source is warming
// the water.
inline bool dnyNoHeatSourceAssumed()
    { return true; }

// the risks of hypothermia are reduced in shallow water.
inline bool dnyShallowWaterReducesRisk()
    { return true; }

// if a character is moving through water between knee and waist deep,
// hypothermia effects do not begin for one hour.
inline bool dnyKneeToWaistOneHour()
    { return true; }

// the knee-to-waist-deep wading onset delay: one hour.
inline int dnyWadingOnsetHours()
    { return 1; }

// if the water is shallower than knee deep, hypothermia is not a threat.
inline bool dnyShallowerThanKneeNoThreat()
    { return true; }

// ---- the hypothermia check cycle ----

// after hypothermia sets in, the player must make a Constitution Check.
inline bool dnyConCheckOnOnset()
    { return true; }

// if the Constitution Check fails, the character loses hit points on 1d6 -
// the dice count.
inline int dnyLossPerFailDice()
    { return 1; }

// the hypothermia loss die: d6.
inline int dnyLossPerFailSides()
    { return 6; }

// the Constitution Check must be repeated every turn, with all hit point
// losses accumulating.
inline int dnyCheckEveryTurns()
    { return 1; }

// all hit point losses accumulate until the character reaches some external
// heat source that can warm his chilled body.
inline bool dnyLossesAccumulateUntilHeat()
    { return true; }

// hit point loss continues even after the character has gotten out of the
// water, if no heat source is found.
inline bool dnyLossContinuesOutOfWater()
    { return true; }

// ---- the hypothermia recovery and immunity ----

// if a means of warming up - such as a fire or the close presence of other
// warm-blooded creatures - is located, the character recovers.
inline bool dnyFireOrWarmCreaturesRecover()
    { return true; }

// near a heat source the character regains hit points at 1d6 per turn - the
// dice count.
inline int dnyRecoveryPerTurnDice()
    { return 1; }

// the hypothermia recovery die: d6.
inline int dnyRecoveryPerTurnSides()
    { return 6; }

// the 1d6-per-turn recovery continues until the hypothermia losses have been
// fully recovered.
inline bool dnyRecoveryUntilFullyRecovered()
    { return true; }

// creatures especially adapted for cold environments, or carrying magical
// protections such as a ring of warmth, are not susceptible to the effects of
// this rule.
inline bool dnyColdAdaptedOrRingImmune()
    { return true; }

// a character who thoroughly coats himself with a layer of grease or oil
// before entering the water can double the amount of time before making a
// Constitution Check, and double the interval between checks as well.
inline bool dnyGreaseDoublesInterval()
    { return true; }

// the grease or oil coating multiplier on the time before the first
// Constitution Check and on the interval between checks.
inline int dnyGreaseTimeMult()
    { return 2; }

// ---- the Table 19 DPV grid ----

// the Table 19 carries thirteen formations: two rooms, two columns, a wall,
// three bridges, a rock ledge, two cavern ceilings and two stalactites.
inline int dnyT19RowCount()
    { return 13; }

// the row key: 0 room 10-ft tube, 1 room 20-ft cube, 2 column 3-ft diameter,
// 3 column 10-ft diameter, 4 wall 10-ft square, 5 bridge small wooden, 6
// bridge small stone, 7 bridge large stone, 8 rock ledge per 1-ft wide, 9
// ceiling small cavern, 10 ceiling large cavern, 11 stalactite small, 12
// stalactite large.
inline int dnyT19Key(int b)
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
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        default:
            return -99;
        }
    }

// the Defensive Point Value of the formation: the damage needed to destroy it
// (or, for a cubic open space, to collapse its ceiling).
inline int dnyT19Dpv(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 90;
        case 2:
            return 10;
        case 3:
            return 100;
        case 4:
            return 20;
        case 5:
            return 12;
        case 6:
            return 40;
        case 7:
            return 80;
        case 8:
            return 10;
        case 9:
            return 100;
        case 10:
            return 250;
        case 11:
            return 8;
        case 12:
            return 20;
        default:
            return -99;
        }
    }

}   // namespace rules
