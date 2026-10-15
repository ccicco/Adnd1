// =========================================================================================
// Adnd1 - rules/wsgpurify.h
// R470: the WSG PURIFYING WATER slice with the TAINTED-WATER EFFECTS - the
// purification trigger (characters suspecting scavenged water is tainted, a
// possibility that almost always exists, can greatly reduce the chance of
// harm by purifying before drinking), the boil rule (assuming no magical
// purification, boiling the best way to remove impurities: a sufficiently
// long boil leaves only a 10% chance of remaining tainted, the required time
// 2-5 rounds - 1d4+1 - at an elevation close to sea level plus an extra 1d2
// minutes for every 1,000 feet of elevation above sea level, taking the water
// off the fire before the required time expires doing no good), the
// evaporation cost (boiling reduces the volume to be drunk: at relatively low
// elevation - 5,000 feet or less - 5% of the water's volume lost per minute
// boiled, at higher elevation only 3% per minute, characters facing a
// shortage often going for quantity over quality), the tainted-water effects
// (the same as eating tainted or spoiled food: mildly tainted water hits as
// tainted food but with a 6-hour minimum duration instead of 12, severely
// tainted water as spoiled food with an 18-hour minimum instead of 24), the
// severity ruling (the DM decides mild or severe; severely tainted water
// relatively more likely in areas of low elevation such as swamps and in
// perennially warm or hot climates where bacteria prosper - extreme heat
// kills bacteria, extreme cold does not necessarily, subarctic melt ice
// almost as likely to carry organic impurities as temperate lake water) and
// the bad-water warnings (taste and appearance not reliable purity indicators
// - the murky brown water may be less harmful than the fresh clear liquid;
// some wilderness water carries illness-producing bacteria above and beyond
// the taint effects and some is naturally poisonous, both DM matters; a
// waterhole devoid of vegetation and especially one ringed with skeletal
// remains a dead giveaway to find a different source; even without magical
// aids such as detect poison, caution and common sense go a long way),
// printed p. 60.
// census 394 -> 395.
//
// Ground truth two-way, pure prose: the user-run tesseract text of printed p.
// 60 (the --psm 4 run from the R469 extraction) vs the pdf embedded text
// layer (pdftotext -layout, pdf page 61; the archive.org djvu item still
// dark, the pdf layer the standing second reader). The two readers agree on
// every mechanic and every number: the 10% remainder, the 2-5 round boil, the
// 1d4+1 dice, the 1d2-minute adder per 1,000 feet, the 5,000-foot break, the
// 5%/3% evaporation ladder, the 6/18-hour minimum durations against the 12/24
// food bases, and the skeletal-remains waterhole warning. The pdfy garbles
// resolve cleanly against the tesseract reads: ld4+ 1 = 1d4+1, detectpoison =
// detect poison, Punfymg Water = Purifying Water. No contested cells - no
// physical-page reads needed.
//
// No printed grid in this slice - the boil rule, the elevation ladders, the
// taint durations and the bad-water warnings pin as consts and bools, every
// one audit-verified against the model.
//
namespace rules {

// ---- Purifying water ----

// characters having reason to suspect scavenged water is tainted - a
// possibility that almost always exists - can greatly reduce the chance of
// harm by purifying before drinking
inline bool wpuSuspectTaintAlmostAlways()
    { return true; }

// assuming no magical means of purification is available, the best way to
// remove impurities from water is by boiling it
inline bool wpuBoilBestNonmagical()
    { return true; }

// if the water is boiled sufficiently long there is only a 10% chance that it
// will remain tainted
inline int wpuBoilTaintRemainPct()
    { return 10; }

// the required boil time at an elevation close to sea level: 2-5 rounds
// (1d4+1), the dice floor
inline int wpuBoilRoundsMin()
    { return 2; }

// the required boil time at sea level: the dice ceiling (4+1)
inline int wpuBoilRoundsMax()
    { return 5; }

// an extra 1d2 minutes of boiling for every 1,000 feet of elevation above sea
// level: the step in feet
inline int wpuElevStepFt()
    { return 1000; }

// if the water is taken off the fire before the required time has expired,
// the boiling will have done no good
inline bool wpuEarlyRemovalNoGood()
    { return true; }

// the evaporation-ladder break: relatively low elevation means 5,000 feet or
// less
inline int wpuEvapBreakFt()
    { return 5000; }

// at relatively low elevation (5,000 feet or less) 5% of the water volume is
// lost to evaporation for every minute boiled
inline int wpuEvapLowPctPerMin()
    { return 5; }

// at higher elevation the evaporation loss is only 3% per minute
inline int wpuEvapHighPctPerMin()
    { return 3; }

// faced with a choice between not having enough water and risking the ill
// effects of unpurified water, characters may often decide to go for quantity
// over quality - the evaporation cost is why one would stop boiling early
inline bool wpuQuantityOverQuality()
    { return true; }

// ---- The tainted-water effects ----

// in essence the effects of drinking tainted water are the same as the
// effects of eating tainted or spoiled food (see the Food Gathering text);
// only the minimum durations differ
inline bool wpuEffectsMatchTaintedFood()
    { return true; }

// mildly tainted water hits like tainted food but with a minimum duration of
// 6 hours instead of 12
inline int wpuMildMinHours()
    { return 6; }

// the tainted-food minimum duration baseline that the mild water taint
// replaces: 12 hours
inline int wpuMildFoodBaseHours()
    { return 12; }

// severely tainted water hits like spoiled food but with a minimum duration
// of 18 hours instead of 24
inline int wpuSevereMinHours()
    { return 18; }

// the spoiled-food minimum duration baseline that the severe water taint
// replaces: 24 hours
inline int wpuSevereFoodBaseHours()
    { return 24; }

// the Dungeon Master must decide whether a certain supply of bad water is
// mildly or severely tainted
inline bool wpuSeverityDMRuling()
    { return true; }

// severely tainted water is relatively more likely in areas of low elevation
// (such as swamps) and in perennially warm or hot climates where bacteria
// prosper because of the temperature
inline bool wpuSevereLikelyLowWarm()
    { return true; }

// extreme heat (boiling) kills bacteria, but extreme cold does not
// necessarily have the same effect: water melted from subarctic ice is almost
// as likely to contain organic impurities as water dipped from a temperate
// lake
inline bool wpuColdDoesNotKill()
    { return true; }

// ---- The bad-water warnings ----

// the taste and appearance of water are not always indicators of its purity:
// characters should not necessarily refrain from murky or strangely colored
// water - the brown water may actually be less harmful than the fresh, clear
// liquid saved for a special occasion
inline bool wpuTasteNotIndicator()
    { return true; }

// some wilderness water may carry bacteria producing illness above and beyond
// the taint effects, and some naturally occurring water may actually be
// poisonous - whether these occur and their effects are DM matters
inline bool wpuBacteriaAndPoisonLayer()
    { return true; }

// if the area surrounding a waterhole is devoid of vegetation, and especially
// if it contains skeletal remains, characters should consider those signs
// strong evidence for finding a different water source - a dead giveaway
inline bool wpuWaterholeDeadGiveaway()
    { return true; }

// even in the absence of magical aids (such as detect poison), caution and
// common sense can go a long way toward steering clear of very bad water
inline bool wpuCautionCommonSense()
    { return true; }

}   // namespace rules
