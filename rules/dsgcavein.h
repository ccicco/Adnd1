// =========================================================================================
// Adnd1 - rules/dsgcavein.h
// The DSG CAVE-INS PART I, R511: the printed pp. 38-39 (pdf 39-40) - the
// opener (cave-ins unique to the underground environment, the roof-collapse
// chance considered when excavating, using explosive magic or otherwise
// stressing the overhanging rock, the bridge and floor collapses, the
// trigger-as-attack ploy with its chain-reaction risk), the causes (the
// natural-disaster causes - floods, earthquakes, volcanic eruptions - with
// the spell-duplicates-disaster rule and the raise water example, the ripe
// areas noted on the maps, the accidental causes on the frailest locations -
// weight or sound, the DM-assigned percentage with the 5% ledge example, the
// laden/mule modification, the run and melee doublings, the sound-trigger
// with the 1% sword-clash example, the excavation causes - double the
// accidental chance, the 10% per turn, the mining and shoring seam, the
// sabotage causes - the sixths splits with and without miner proficiency),
// the random occurrences (the base 1% per day, the 10% per 10 days
// long-expedition option, the near-the-PCs-not-on-top rule) and the Table 17
// eight-band location grid with the movement-relative directions, the
// higher-roll-farther-away rule, the may-go-undiscovered note and the
// decayed-stone double-or-triple
// census 435 -> 436.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR with the pdf
// Acrobat-Capture layer as the second read - every numeric cell
// dual-confirmed: the djvu garbles 596 = 5%, 196 = 1% and 1096 = 10% (the
// percent sign OCR) are settled by the Capture layer (the explicit 5% chance
// per character crossing the ledge, the 1% per round of clashing swords, the
// 10% chance per turn of excavation); the Table 17 bands confirmed THREE WAYS
// - the chapter djvu read, the compiled-tables appendix reprint (djvu.txt
// line 15539) and the Capture layer agree on all eight rows; the djvu/Acrobat
// garbles lias/tias occurred = has occurred. The CAVE-IN CHAIN REACTIONS
// heading and prose (Table 18) and the Effects of Cave-ins section start the
// NEXT round per the content-density rule (the R507-to-R508 tail precedent).
//
// Table 17 pins as an 8x3 grid: the row key plus the lo and hi ends of each
// d100 band, with 00 read as 100 (the 96-00 band pins as 96-100). The
// sabotage splits pin in SIXTHS - the exact-integer encoding of the printed
// fractions: without miner proficiency 1/3, 1/3, 1/3 = 2+2+2 of 6; with miner
// proficiency 2/3, 1/6, 1/6 = 4+1+1 of 6. The R508 Battlesystem cave-in pins
// are the mass-combat seam and the R512 chain-reaction section follows -
// nothing auto-credited.
//
namespace rules {

// ---- the cave-in opener ----

// cave-ins are unique to the underground environment.
inline bool dnwCaveInUniqueToUnderground()
    { return true; }

// the chance that the roof of an underground location may cave in must be
// considered especially if characters are excavating, using explosive magic,
// or otherwise placing stress on the overhanging rock.
inline bool dnwConsideredWhenStressingRock()
    { return true; }

// cave-ins can also endanger characters in other ways: a bridge being crossed
// may collapse, or a floor may give way, dropping those standing on it amid
// tons of jagged, crushing rock.
inline bool dnwBridgeFloorAlsoEndanger()
    { return true; }

// characters may try to trigger a cave-in as a means of attacking an enemy;
// such attempts must be made cautiously, since a cave-in may create a chain
// reaction that collapses a far larger area than intended.
inline bool dnwTriggerAsAttackChainRisk()
    { return true; }

// ---- the natural causes ----

// a strong cavern, dungeon, or realm is only susceptible to cave-ins as a
// result of natural disasters such as floods, earthquakes, or volcanic
// eruptions.
inline bool dnwStrongStructureOnlyDisasters()
    { return true; }

// certain magical spells that duplicate natural disasters can duplicate their
// destructive effects; a raise water spell that creates a flood in a tunnel
// should be treated as a natural flood.
inline bool dnwSpellDuplicatesDisaster()
    { return true; }

// in the case of a major natural disaster the DM's judgment determines the
// exact area of effect; the far-reaching effects of a major earthquake might
// actually annihilate an entire subterranean realm.
inline bool dnwMajorDisasterDmJudgment()
    { return true; }

// underground areas ripe for cave-ins - aging or recent-disaster-weakened,
// needing only a slight additional pressure - should be noted when the maps
// for an underground area are prepared.
inline bool dnwRipeAreasNotedOnMaps()
    { return true; }

// ---- the accidental causes ----

// only the frailest of underground locations are susceptible to accidental
// cave-ins.
inline bool dnwAccidentalOnlyFrailest()
    { return true; }

// accidental collapses are triggered by the weight of a creature walking
// across a weak spot, or even by the sounds created by characters or
// creatures.
inline bool dnwAccidentalWeightOrSound()
    { return true; }

// based on the weakness of the area under consideration, the DM should assign
// a percentage chance of a collapse occurring.
inline bool dnwDmAssignsCollapsePct()
    { return true; }

// a ledge might have eroded to the point where it has a 5% chance of
// collapsing per character crossing it (the djvu garble 596, settled by the
// Acrobat layer).
inline int dnwAccidentalLedgeExamplePct()
    { return 5; }

// the collapse chance should be modified if the characters are very heavily
// laden, or accompanied by mules or other creatures.
inline bool dnwLadenOrBeastsModifyPct()
    { return true; }

// the chance of collapse may be doubled if the characters run across a
// weakened ledge, since the pounding is much harder than when walking slowly.
inline int dnwRunChanceMult()
    { return 2; }

// the chance of collapse may be doubled if the characters run across a
// weakened surface.
inline bool dnwRunDoublesChance()
    { return true; }

// the chance of collapse should be doubled for melee combat on a fragile
// surface, because of the additional pounding the surface takes.
inline int dnwMeleeChanceMult()
    { return 2; }

// if characters participate in melee combat on a fragile surface, the weight
// of all participating creatures must be figured in - carefully, for nonhuman
// creatures such as ogres - and the chance of collapse should be doubled.
inline bool dnwMeleeDoublesChance()
    { return true; }

// where the weakened area is not directly beneath the characters, the chance
// of a cave-in is reduced; unless the characters apply weight to the area,
// sound is the only other likely avenue for causing an accidental collapse.
inline bool dnwOffPositionReducedChance()
    { return true; }

// the intensity of the sound must be considered, with a percentage chance of
// collapse assigned according to the loudness and sharpness of the noise; an
// area might stand no chance under normal conversation but the clashing of
// swords might give a 1% chance per round.
inline bool dnwSoundChanceByLoudness()
    { return true; }

// the clashing of swords in combat might give a 1% chance per round of a
// cave-in on a sound-fragile area (the djvu garble 196).
inline int dnwSwordClashCollapsePctPerRound()
    { return 1; }

// ---- the excavation causes ----

// whenever characters or creatures are digging into the earth, they run the
// risk of excavating away a significant support for the ceiling, causing a
// cave-in.
inline bool dnwExcavationRisksSupport()
    { return true; }

// mining is the most common cause of excavation cave-ins, and precautions
// such as shoring up an excavated passage are usually taken by the miners -
// the mining-rules seam.
inline bool dnwMiningMostCommonCause()
    { return true; }

// characters digging an escape tunnel or clearing rubble from a previous
// cave-in are often unable to properly shore up their excavated passage;
// weakened surfaces then stand a fair chance of collapsing.
inline bool dnwUnshoredEscapeTunnelRisk()
    { return true; }

// the possibility of a cave-in while digging an escape tunnel or clearing
// rubble is about double that of an accidental cave-in.
inline int dnwExcavationChanceMult()
    { return 2; }

// the possibility of a cave-in while digging without proper shoring is about
// double that of an accidental cave-in, with about a 10% chance per turn of a
// weakened ceiling or tunnel wall collapsing.
inline bool dnwExcavationChanceAboutDouble()
    { return true; }

// there is about a 10% chance per turn that a weakened ceiling or tunnel wall
// collapses during excavation (the djvu garble 1096).
inline int dnwExcavationCollapsePctPerTurn()
    { return 10; }

// ---- the sabotage causes ----

// to chip stone away to the point where a collapse is likely requires some
// skill at stonework and a little luck; a character must have miner
// proficiency to have a decent chance of successfully sabotaging an
// underground area.
inline bool dnwSabotageNeedsMinerProficiency()
    { return true; }

// a character without miner proficiency who makes a sabotage attempt has a
// 1/3 chance of successfully completing his task - 2 of 6.
inline int dnwSabotageNoMinerSuccessSixths()
    { return 2; }

// without miner proficiency, a 1/3 chance of leaving the structure too strong
// to collapse - 2 of 6.
inline int dnwSabotageNoMinerTooStrongSixths()
    { return 2; }

// without miner proficiency, a 1/3 chance of bringing the structure down upon
// himself - 2 of 6.
inline int dnwSabotageNoMinerSelfCollapseSixths()
    { return 2; }

// a character with miner proficiency has a 2/3 chance of successfully
// sabotaging the area - 4 of 6.
inline int dnwSabotageMinerSuccessSixths()
    { return 4; }

// with miner proficiency, a 1/6 chance of not damaging the structure enough -
// 1 of 6.
inline int dnwSabotageMinerUnderdamageSixths()
    { return 1; }

// with miner proficiency, a 1/6 chance of damaging it so extensively that it
// collapses during the sabotage attempt - 1 of 6.
inline int dnwSabotageMinerSelfCollapseSixths()
    { return 1; }

// many areas subject to sabotage collapse on the heads of the saboteurs
// themselves.
inline bool dnwSabotageMayCrushSaboteur()
    { return true; }

// columns that support a ceiling, bridge supports, or narrow layers of rock
// walked over are obvious sabotage targets; the soaring ceiling of a vast
// chamber is very difficult to damage, while its supporting columns are much
// more accessible.
inline bool dnwSabotageTargetsAccessible()
    { return true; }

// sabotage attempts take considerable time and create quite a bit of noise;
// see the excavation rules for how long it might take to chisel through a
// column - the page-50 seam.
inline bool dnwSabotageTimeAndNoise()
    { return true; }

// ---- the random occurrences ----

// if a campaign focuses on the underground for extended periods, the chance
// of a naturally occurring cave-in affecting the characters increases.
inline bool dnwRandomChanceGrowsWithTime()
    { return true; }

// the base chance for a cave-in during underground exploration is 1% per day.
inline int dnwRandomCaveInPctPerDay()
    { return 1; }

// on long expeditions the DM may wish to alter the daily roll to a 10%
// chance.
inline int dnwRandomCaveInLongExpeditionPct()
    { return 10; }

// the long-expedition cave-in roll is made every 10 days.
inline int dnwRandomCaveInLongExpeditionDays()
    { return 10; }

// a successful random-occurrence roll means a cave-in has occurred somewhere
// in the underground region near the PCs - not on top of the characters, and
// not necessarily within their earshot.
inline bool dnwRandomMeansNearNotOnTop()
    { return true; }

// all Table 17 directions relate to the party's direction of movement at the
// time of the cave-in.
inline bool dnwT17RelativeToMovement()
    { return true; }

// in the categories indicating a cave-in some distance away, the higher the
// roll, the farther away the cave-in.
inline bool dnwHigherRollFartherAway()
    { return true; }

// it is quite possible for a group of characters to fail to discover a
// cave-in that occurs during their adventures.
inline bool dnwCaveInMayGoUndiscovered()
    { return true; }

// in areas of exceptionally decayed stone, or of rotten supporting timbers,
// the DM may increase the chance of a randomly occurring cave-in - possibly
// doubling or tripling it.
inline bool dnwDecayedStoneChanceIncrease()
    { return true; }

// in areas of exceptionally decayed stone or rotten supporting timbers, such
// considerations could double, or perhaps triple, the chance of a randomly
// occurring cave-in.
inline int dnwDecayedChanceMultMax()
    { return 3; }

// ---- the Table 17 location grid ----

// the Table 17 carries eight location bands: on top, immediately in front,
// immediately behind, in front within hearing, behind within hearing, well
// behind out of hearing, well in front out of hearing, and the entrance.
inline int dnwT17RowCount()
    { return 8; }

// the row key: 0 on top of the PCs, 1 immediately in front, 2 immediately
// behind, 3 in front within hearing range, 4 behind within hearing range, 5
// well behind out of hearing range, 6 well in front out of hearing range, 7
// at the entrance the PCs used to get underground.
inline int dnwT17Loc(int b)
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
        default:
            return -99;
        }
    }

// the low end of the d100 roll band.
inline int dnwT17Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 11;
        case 5:
            return 16;
        case 6:
            return 56;
        case 7:
            return 96;
        default:
            return -99;
        }
    }

// the high end of the d100 roll band; a rolled 00 reads as 100, so the last
// band pins as 96-100.
inline int dnwT17Hi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 55;
        case 6:
            return 95;
        case 7:
            return 100;
        default:
            return -99;
        }
    }

}   // namespace rules
