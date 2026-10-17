// =========================================================================================
// Adnd1 - rules/dsgmine5.h
// The DSG MINING TAIL, R523: printed p. 53 (pdf 54) plus the claim
// continuation on printed p. 54 (pdf 55) - the placer value: only gold,
// silver or platinum can be placer-mined (copper, iron, mithril and gemstones
// impossible), the value following the normal page-51 quality determination
// then the 1d4-times-10 percentage of full value (10-40%); the smelting: one
// smelter-proficiency character runs the operation with unskilled workers
// under supervision, over a bellows-and-unmeltable-container setup with a
// coal (sometimes wood) fire, the smoke and smell making it almost impossible
// to conceal, and the underground rule that careless ventilation lets the
// fire consume all the oxygen; the finishing: gemstones rarely need smelting
// (occasional heat for crusted minerals), the gem cutter proficiency cutting
// and polishing at 2d20 stones per character per day (excavation usually
// greatly exceeding finishing), and the weekly 1d100 exceptional-stone check
// (a 00 unearths a stone worth 1d100 times the week's average value); the
// duration: the secret d100 man-weeks roll with the doubles ladder (doubles
// add a d100 of man-months, doubles again a d100 of man-years, repeating
// until a non-doubles roll; a month is four weeks, a year 48 weeks; 12 miners
// use 12 man-weeks per week) and the placer exception (doubles disregarded,
// always 1-100 man-weeks); the hazards: inherent, with success attracting
// problems almost automatically; and the claim: the right to remove mineral
// wealth, clear titles rare with rulers usually holding title, the mining
// charter (as little as 25 or 30%, more often 50%, a strong ruler always 50%)
// enforced by spies, surprise inspections, discreet observation or a
// ruler-employed smelter reporting the exact amounts, cheating punished
// usually by death (leniency never restoring the mine), and the wilderness
// continuation - the overnight land war among rulers with tribute and the
// winner-dependent claim recognition, the savage denizens raiding trespassers
// with cancellable charter-like monster agreements, no legal protection (the
// claim held by whoever can hold it), claim-jumpers in direct proportion to
// profitability, the rarely-working concealment (hiding the entrance with
// secret doors and brush, the tailings spread or dumped in water at the 25%
// mining rate, the chipping noise carrying to Underdark creatures, the
// bulette bust-in, the smelter smoke killing concealment), and the
// wealth-disposal risk of brazen moneychanger visits
// census 446 -> 447.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~6790-7060) with the pdf Acrobat-Capture layer as the second read (idx 125
// = the printed pp. 52-53 window, idx 127 = the printed p. 54 window); the
// compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND:
// both machine reads agree on every load-bearing number, and the only garbles
// are the standing OCR die-notation class (djvu "14100"/"4100" and Capture
// "ld4"/"dlOO"/"1-1 00" all reading as 1d100/1d4). The charter percentages
// multi-confirm: the djvu "5096" and the Capture "50%" both read as 50%, and
// both reads give the as-little-as 25-or-30% phrasing (pinned as 25 with the
// phrasing noted). The tailings 25% mining rate, the 2d20 finishing capacity,
// the 4-week month, the 48-week year, the 1-100 man-week placer cap and the
// exceptional-stone 1d100 weekly check with the 1d100-times-average value all
// appear identically in both reads. CATCH-UP: the exceptional-stone paragraph
// sits on printed p. 52 with no gap child of its own (it fell between the
// R521 products child and the R522 quality child) - it rides this round via
// the Finishing child flip, keeping the report lossless. The hireling loyalty
// section proper (child 133) starts the NEXT round at its printed p. 54
// heading. The R519 placer/tunnel seam and the R521 Table 30 seam are noted;
// nothing auto-credits.
//
// A prose round: no tables pin. The dice pin as consts per the R508
// convention - the placer 1d4 x 10 percentage, the 2d20 finishing capacity,
// the secret d100 duration roll, and the weekly 1d100 exceptional-stone check
// with its 1d100-times-average value roll. The conveniences and thresholds
// pin as consts: the 4-week month, the 48-week year, the 1-100 man-week
// placer cap, the 25-or-30/50 charter shares, and the 25% tailings-scattering
// mining rate. The rest pins as prose bools: the placer metal restrictions,
// the one-smelter rule with its equipment and ventilation, the gem-cutter
// finishing, the doubles duration ladder with the placer exception and the
// man-week definition, the charter enforcement and cheating penalty, the
// wilderness war/denizen/no-legal-protection/claim-jumper hazards, the
// concealment problem set, and the wealth-disposal risk. The
// exceptional-stone catch-up is load-bearing: printed p. 52 prose with no
// child line, pinned under the Finishing child. The R519/R520/R521 seams are
// noted; nothing auto-credits.
//
namespace rules {

// ---- the placer mine value ----

// placer mining of copper, iron, mithril, or any kind of gemstone is
// impossible for these rules; only gold, silver, or platinum deposits can be
// worked with a placer mine.
inline bool dnrvPlacerGoldSilverPlatinumOnly()
    { return true; }

// calculate the placer value by the normal quality determination (page 51),
// then apply the 1d4-times-10 percentage of full value.
inline bool dnrvPlacerUsesQualityThenPercent()
    { return true; }

// the placer full-value roll is one die.
inline int dnrvPlacerDice()
    { return 1; }

// the placer full-value roll is 1d4, multiplied by 10 to give the percentage
// of full value.
inline int dnrvPlacerSides()
    { return 4; }

// the d4 result times 10 is the percentage of full value gained from a placer
// mine (10-40%).
inline int dnrvPlacerPctMult()
    { return 10; }

// ---- the smelting of ore ----

// as with mining, only one character with smelter proficiency is required to
// run a smelting operation; other, unskilled characters work under that
// character's supervision.
inline bool dnrvOneSmelterSuffices()
    { return true; }

// the smelting of ore requires a fairly extensive equipment collection:
// because a very hot fire is crucial, smelters must have a bellows system and
// several unmeltable containers to hold heated ore.
inline bool dnrvSmelterNeedsHotFire()
    { return true; }

// most minerals require a coal fire for smelting, but some can be smelted by
// wood fires.
inline bool dnrvMostMineralsNeedCoal()
    { return true; }

// a smelting operation produces much smoke and smell, so it is almost
// impossible to conceal.
inline bool dnrvSmeltingImpossibleToConceal()
    { return true; }

// if done underground, the ventilation of the smelting area must be carefully
// attended, or the smelting fire is likely to consume all the oxygen in the
// area.
inline bool dnrvUndergroundSmeltingVentilation()
    { return true; }

// ---- the finishing of stones ----

// gemstones rarely require the complicated procedures needed to smelt ore
// from rock, though occasionally heat removes excess minerals crusted around
// the gemstones.
inline bool dnrvStonesRarelyNeedSmelting()
    { return true; }

// the usual finishing procedure requires a character with gem cutter
// proficiency to cut and polish the stones.
inline bool dnrvGemCutterFinishes()
    { return true; }

// a character finishing stones rolls 2 dice of capacity per day.
inline int dnrvFinishDice()
    { return 2; }

// a given character can only finish 2d20 stones in a day.
inline int dnrvFinishSides()
    { return 20; }

// the rate at which stones can be excavated usually greatly exceeds the
// 2d20-per-day rate at which they can be finished.
inline bool dnrvExcavationExceedsFinishing()
    { return true; }

// in addition to the week's base stone value, roll 1d100 each week the mine
// operates: a 00 means an exceptional stone is unearthed (the printed p. 52
// catch-up, no gap child of its own).
inline bool dnrvExcepStoneWeeklyCheck()
    { return true; }

// the exceptional stone's finder rolls 1d100 and multiplies the result by the
// average stone value for that week - e.g., a 20 gp turquoise average and a
// 68 yields a 1,360 gp stone.
inline bool dnrvExcepStoneValueRoll()
    { return true; }

// the exceptional-stone check is one die (the printed p. 52 catch-up).
inline int dnrvExcepStoneDice()
    { return 1; }

// roll 1d100 each week the mine is operating: a result of 00 means an
// exceptional stone is unearthed.
inline int dnrvExcepStoneSides()
    { return 100; }

// ---- the duration of a mining site ----

// a given mine always contains a finite amount of mineral wealth -
// occasionally a lifetime or more, much more frequently the mine plays out
// after a certain time.
inline bool dnrvMineWealthFinite()
    { return true; }

// the duration roll is one die.
inline int dnrvDurationDice()
    { return 1; }

// the DM secretly rolls d100 at the start of the mining operation: the result
// is the man-weeks before depletion.
inline int dnrvDurationSides()
    { return 100; }

// if the secret d100 duration roll yields doubles (e.g., 11, 22, 33), the
// mine has a much longer duration: roll d100 again and read the result as
// man-months, added to the weeks.
inline bool dnrvDoublesAddMonths()
    { return true; }

// if the second d100 roll also yields doubles, roll d100 a third time reading
// man-years; further doubles add more years until a roll comes up without
// doubles.
inline bool dnrvDoublesAgainAddYears()
    { return true; }

// each month is treated as four weeks when totalling a mine's longevity.
inline int dnrvMonthWeeks()
    { return 4; }

// each year is treated as 48 weeks, or 12 months, when totalling a mine's
// longevity.
inline int dnrvYearWeeks()
    { return 48; }

// a man-week is the amount of work one human miner performs in a week - 12
// miners engaged on a mine use up 12 man-weeks of its lifetime every week.
inline bool dnrvManWeekPerMiner()
    { return true; }

// if the mine is a placer mine, disregard any doubles rolls for the duration
// of the find: always depleted after 1-100 man-weeks of work.
inline bool dnrvPlacerDisregardsDoubles()
    { return true; }

// a placer mine is always depleted after 1 man-week of work at the minimum
// (doubles disregarded).
inline int dnrvPlacerMinWeeks()
    { return 1; }

// a placer mine is always depleted after at most 100 man-weeks of work.
inline int dnrvPlacerMaxWeeks()
    { return 100; }

// ---- the inherent hazards and the claim ----

// any mining operation includes an inherent set of hazards, and a very
// successful operation attracts additional problems almost automatically - no
// free lunch for avaricious player characters.
inline bool dnrvHazardsInherent()
    { return true; }

// a claim is the miner's claimed right to remove mineral or gemstone wealth
// from the ground; with clear and undisputable legal title it is usually no
// problem initially.
inline bool dnrvClaimIsRightToWealth()
    { return true; }

// except in the most civilized and well-developed areas, a clear and
// undisputable title is uncommon; if anyone holds title to the land it is
// usually a king or other ruler with a selfish interest in its wealth.
inline bool dnrvTitleUsuallyARuler()
    { return true; }

// a character might gain a mining charter from a ruler allowing mining of a
// given tract, with a hefty percentage of the mine's profit turned over to
// the ruler.
inline bool dnrvCharterPossible()
    { return true; }

// a mining charter might claim as little as 25 or 30% of the mine's profit
// for the ruler (the low claim only from a weak-grasping ruler avoiding
// conflict).
inline int dnrvCharterLowPct()
    { return 25; }

// a charter more often requires a 50% share, and a strong ruler always asks
// for 50% of the mine's products.
inline int dnrvCharterCommonPct()
    { return 50; }

// the ruler takes steps to insure the fair share: a spy among the miners,
// surprise inspections, discreet observation from a safe distance, or a
// smelter/finisher in the ruler's employ loyally reporting the exact amount
// processed.
inline bool dnrvRulerEnforcesShare()
    { return true; }

// a miner caught cheating his liege is usually punished by death; exceptional
// leniency might let the character live - perhaps retaining all body parts -
// but never to continue operating the mine.
inline bool dnrvCheatingUsuallyDeath()
    { return true; }

// a claim on wilderness land is initially free of charter negotiation, but
// the land is wilderness because it is too savage for settlement or no useful
// purpose was discovered.
inline bool dnrvWildernessClaimFreeButHazardous()
    { return true; }

// land thought worthless for centuries can become highly sought after when
// minerals are found: rulers war over it, and the winning ruler exacts
// tribute - PCs who aided the winner may continue operating with taxes; PCs
// who opposed the winner have little likelihood of recognized claims, at best
// fleeing with their lives and some small profit.
inline bool dnrvLandWarOvernight()
    { return true; }

// raiding monsters show no favor to PCs perceived as trespassing; intelligent
// monsters not inclined to take over operations may be negotiated with,
// charter-like, but chaotic monsters have little respect for agreements and
// might cancel one with no more notice than a battle-cry or surprise attack.
inline bool dnrvSavageDenizensRaid()
    { return true; }

// a wilderness claim has no legal protection: it is generally owned by
// whichever creature or party is most capable of holding it against
// interlopers.
inline bool dnrvNoLegalProtection()
    { return true; }

// the number of claim-jumpers climbs in direct proportion to the mine's
// profitability - considerable wealth attracts distant creatures or
// high-level characters whose only purpose is taking the mine by force.
inline bool dnrvClaimJumpersProportional()
    { return true; }

// attempting to conceal the mine is commonly attempted but rarely successful:
// it virtually never works in a settled area and has only a limited chance in
// the wilderness.
inline bool dnrvConcealmentRarelyWorks()
    { return true; }

// concealment requires hiding the entrance (secret doors, piles of brush and
// twigs), defeating the tailings giveaway (spreading them over a large area,
// or dumping into a river, lake, or deep pit - at the 25% mining rate), and
// the noise of chipping that carries clues especially to Underdark creatures.
inline bool dnrvConcealmentProblems()
    { return true; }

// if miners scatter the tailings to hide the mine, the rate of mining is no
// more than 25% of what it could be.
inline int dnrvTailingsMiningPct()
    { return 25; }

// a mine located next to a smelter had better abandon all hope of
// concealment: the clouds of smoke and pervasive odor make it all but
// impossible except in the most remote and uninhabited areas.
inline bool dnrvSmelterKillsConcealment()
    { return true; }

// even in complete secrecy, wealth disposal is a problem: brazenly converting
// 100 pounds of solid gold at the moneychanger raises eyebrows, and NPCs
// getting wind of a valuable claim may follow the characters back to their
// mine.
inline bool dnrvWealthDisposalRisky()
    { return true; }

}   // namespace rules
