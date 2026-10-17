// =========================================================================================
// Adnd1 - rules/dsgmine.h
// The DSG MINING OPENER, WHERE TO MINE AND TYPES OF MINES, R519: printed pp.
// 48-49 (pdf 49-50) - the mining opener (the mined stones and metals as
// perhaps the most valuable of underground resources - copper and iron for
// blacksmithing, emeralds, rubies and gold prized - and the miner proficiency
// framework the DM may allow), the where-to-mine prospecting rules (the
// find-something chance equal to the Wisdom score plus the miner proficiency
// modifier, the no-yield regions of deep sand or dirt and hardened lava with
// the stream-traces exception, the Proficiency Check after a thorough search
// of at least a week covering about four miles square, the good conditions
// that forbid fending off bandits or hunting for food, the deep-snow
// impossibility, the thin-snow doubling or tripling, the rainstorm and
// rough-terrain and short-winter-daylight interferences with the DM extending
// the time, the repeat-search ladder of -1 and twice the time on the second
// search and -2 and tripled time on the third with corresponding increases
// and the automatic failure past a certain point, and the success reading
// Table 30: Mining Products), and the types-of-mines taxonomy (the placer and
// underground tunnel mines of a fantasy world, the strip mining excluded for
// its heavy equipment, the placer sifting of gravel, dirt, sand and water
// from a flowing stream needing only a shallow pan and patience, the
// eroded-vein streambed collection, the not-the-way-to-a-significant-lode
// limit, the tunnel mine trading more work for much greater wealth, and the
// book primarily ruling tunnel mining though placer mining remains possible
// along underground streams)
// census 442 -> 443.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~6340-6465) with the pdf Acrobat-Capture layer as the second read (idx 66 =
// printed p. 49 holding the snow rules and the repeat-search ladder clean;
// the mining opener on the idx 65 tail) - every load-bearing number
// dual-confirmed: the Wisdom-score find chance, the one-week minimum search
// over four miles square, the deep-snow impossibility, the thin-snow double
// or triple, the -1/x2 and -2/x3 repeat ladder with the automatic failure,
// and the shallow-pan placer minimum. The DMG page 106 mining-rates seam
// (Table 27) and Table 30 are the NEXT round per the content-density rule:
// the mining chapter continues with excavating, vein direction Tables 28-29,
// shoring, and the products grids.
//
// A prose round opening the mining chapter - no tables. The repeat-search
// modifiers pin as positive magnitudes with the minus in the name and comment
// per the R514 convention. The Wisdom-score chance and the
// miner-proficiency-modifier addition are pinned as prose booleans; the
// engine multiplies nothing - the search-time doubling and tripling pin as
// multipliers, not computed values. The Table 30 seam is noted for R520;
// nothing auto-credits.
//
namespace rules {

// ---- the mining opener ----

// the stones and metals found by miners are perhaps the most valuable of all
// natural underground resources: strong metals like copper and iron for
// blacksmithing, valuable stones and metals like emeralds, rubies, and gold
// all highly prized.
inline bool dnmMinedResourcesValuable()
    { return true; }

// with the miner proficiency (see the DSG Proficiency section) PCs may take
// an interest in mining; if the DM allows mining ventures, this section
// provides the framework governing the outcome of the enterprise.
inline bool dnmMinerProficiencyFramework()
    { return true; }

// ---- the where-to-mine rules ----

// as a general rule, a character with miner proficiency stands a chance equal
// to his Wisdom score (plus his miner proficiency modifier) of finding
// something of worth where he elects to dig.
inline bool dnmFindChanceIsWisScore()
    { return true; }

// certain areas do not yield anything of value regardless of the success of
// the proficiency roll: regions of deep sand or dirt, or areas of hardened
// lava.
inline bool dnmNoYieldRegionsExist()
    { return true; }

// streams flowing through no-yield regions might have brought traces of a
// valuable ore or a gemstone, but mining the ground itself is virtually
// guaranteed to yield nothing there.
inline bool dnmStreamTracesException()
    { return true; }

// if a miner seeks to mine an area the DM believes might yield valuable
// material, the character can make a Proficiency Check after thoroughly
// searching the area.
inline bool dnmCheckAfterThoroughSearch()
    { return true; }

// a thorough search of a possibly-yielding area requires at least a week of
// time under good searching conditions.
inline int dnmSearchMinWeeks()
    { return 1; }

// the search generally covers an area about four miles square.
inline int dnmSearchAreaMilesSquare()
    { return 4; }

// good searching conditions mean the character cannot be fending off bandits
// or hunting for food while searching.
inline bool dnmGoodConditionsRequired()
    { return true; }

// ---- the adverse search conditions ----

// a deep snow cover makes such a search impossible.
inline bool dnmDeepSnowBlocksSearch()
    { return true; }

// even a thin coating of snow doubles or triples the time needed to search an
// area.
inline bool dnmThinSnowDoublesOrTriples()
    { return true; }

// steady rainstorms, rough terrain, and the short hours of daylight typical
// in wintertime can all interfere; the DM must decide how much additional
// time is required before the area is suitably searched.
inline bool dnmAdverseConditionsDMExtends()
    { return true; }

// ---- the repeat-search ladder ----

// if the Proficiency Check roll is unsuccessful, so is the search - but the
// character can repeat his search of the same area if he wants to, though the
// task grows more difficult.
inline bool dnmFailedSearchRepeatable()
    { return true; }

// the second time an area is searched by any character with miner
// proficiency, the chances are rolled with a -1 modifier to the Proficiency
// Check (pinned as a positive magnitude with the minus in the name and
// comment).
inline int dnmSecondSearchModifier()
    { return 1; }

// twice as much time is required to search the area the second time.
inline int dnmSecondSearchTimeMult()
    { return 2; }

// if the attempt is made a third time, a -2 modifier applies to the
// Proficiency Check (pinned as a positive magnitude).
inline int dnmThirdSearchModifier()
    { return 2; }

// the third search takes tripled time; an area can be searched as many times
// as desired with corresponding increases in penalties.
inline int dnmThirdSearchTimeMult()
    { return 3; }

// after a certain point the modified Proficiency Check automatically fails,
// and further searches are fruitless.
inline bool dnmAutoFailPastAPoint()
    { return true; }

// if the Proficiency Check succeeds, the miner has discovered something of
// value within the area searched - exactly what is determined by Table 30:
// Mining Products (the R520 seam).
inline bool dnmSuccessReadsTable30()
    { return true; }

// ---- the types of mines ----

// the types of mines commonly encountered in a fantasy world include placer
// mines and underground (or tunnel) mines.
inline bool dnmPlacerAndTunnelTypes()
    { return true; }

// the strip mining common in the modern age requires heavy equipment not
// found in the typical AD&D game campaign.
inline bool dnmStripMiningExcluded()
    { return true; }

// placer mining involves sifting gravel, dirt, sand, and water from a flowing
// stream or river - most commonly employed above ground; at its most basic
// level the only requirements are a character with a shallow pan and a great
// deal of patience.
inline bool dnmPlacerSiftingOperation()
    { return true; }

// a placer mine gathers the mineral content of an underground vein of metal
// eroded by water and flowed downstream, collecting where the miner separates
// it from the water in the streambed.
inline bool dnmPlacerStreambedCollection()
    { return true; }

// because only the mineral wealth eroded from the ground collects along the
// streambed, placer mining is not the way to discover a lode of significant
// value.
inline bool dnmPlacerNotSignificantLode()
    { return true; }

// an underground or tunnel mine requires a great deal more work than a placer
// mine, but the potential for wealth is much greater: a tunnel excavated into
// the earth, the dug rock examined for riches.
inline bool dnmTunnelMoreWorkMoreWealth()
    { return true; }

// because the book deals solely with the underground, the mining rules deal
// primarily with tunnel mining - though placer mining is still possible along
// underground streams, underground characters and creatures are much more
// likely to labor in the lucrative tunnel mines.
inline bool dnmRulesPrimarilyTunnelMining()
    { return true; }

}   // namespace rules
