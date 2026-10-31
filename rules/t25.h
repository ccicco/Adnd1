// =========================================================================================
// Adnd1 - rules/t25.h
// The Dragon issue-25 opener part one - the opener set
// census 880 -> 881.
//
// The opener of the issue-25 four-round shape - three of the eight
// Curtiss-called chains pinned as the opener set, the Xochiyaoyotl war game
// and the vampire roster riding the part-two table round, the three-chain
// commentary set at part three and the flip to follow. All pinned from The
// Dragon Vol. III No. 11 (May 1979) print 12-19 at extract/dragon/025, PRINT
// FOLIO = PDF PAGE this issue, the single-voice transcript of the
// Curtiss-provided scan - the issue runs 48 pages, the cover printing Vol.
// III No. II (the roman II for 11), pinned as scanned. The Traveller Navy and
// the Gamma World ink - the cryptic alliances roster, the judging advice and
// the artifact chart with 20th Century Primitive - sit on the drop list per
// the Curtiss 2026-10-31 non-D&D calls, and the Armada Disasters history per
// the same-day usable call - pure narrative, no game ink. The intake seats
// the gap report and all forty-eight transcripts; the two inherited watches -
// the Sullin levels 7-9 and the brawling long-term- effects sequel - print
// nowhere in issue 25 and ride to TD 26.
//
namespace rules {

// ---- the Gygax social class essay (print 12-13) ----

// the common background band - a roll of one through seventy five the Gygax
// social class essay (print 12-13)
inline int t25CommonBand()
    { return 75; }

// the aristocratic background band ceiling - seventy six through ninety five
// the Gygax social class essay (print 12-13)
inline int t25AristocratBandHi()
    { return 95; }

// the upper class background band ceiling - ninety six through zero zero the
// Gygax social class essay (print 12-13)
inline int t25UpperClassBandHi()
    { return 100; }

// the government forms list - anarchy through theocracy the Gygax social
// class essay (print 12-13)
inline int t25GovernmentForms()
    { return 19; }

// the lowest class adventurer chance - five percent the Gygax social class
// essay (print 12-13)
inline int t25LowestClassPct()
    { return 5; }

// the laboring class adventurer chance - ten percent the Gygax social class
// essay (print 12-13)
inline int t25LaboringClassPct()
    { return 10; }

// the freemen and artisans adventurer chance - thirty percent the Gygax
// social class essay (print 12-13)
inline int t25FreemenClassPct()
    { return 30; }

// the gentle class adventurer chance - fifty percent the Gygax social class
// essay (print 12-13)
inline int t25GentleClassPct()
    { return 50; }

// the lesser noble adventurer chance - five percent, anything higher causing
// severe campaign anomalies the Gygax social class essay (print 12-13)
inline int t25LesserNoblePct()
    { return 5; }

// the birth table verdict - out the window, the information useful only under
// primogeniture, entail and Salic Law the Gygax social class essay (print
// 12-13)
inline bool t25BirthTablesRejected()
    { return true; }

// the thief and assassin gate - only from the two lowest social classes the
// Gygax social class essay (print 12-13)
inline bool t25ThievesLowestTwo()
    { return true; }

// the cleric gate - only from the levels above the two lowest the Gygax
// social class essay (print 12-13)
inline bool t25ClericsAboveLowestTwo()
    { return true; }

// the magic user gate - only from the three highest levels the Gygax social
// class essay (print 12-13)
inline bool t25MagicUsersThreeHighest()
    { return true; }

// the paladin gate - only from the highest class the Gygax social class essay
// (print 12-13)
inline bool t25PaladinsHighest()
    { return true; }

// the fighter exception - the apprenticeship coming later through levy,
// militia and mercenary service the Gygax social class essay (print 12-13)
inline bool t25FighterLateApprenticeship()
    { return true; }

// the DM prerogative - the governments and social systems devised directly by
// each DM, any detailed system imposing its own order the Gygax social class
// essay (print 12-13)
inline bool t25DmWorldPrerogative()
    { return true; }

// the closing adage - class will tell, social class never added lightly the
// Gygax social class essay (print 12-13)
inline bool t25ClassWillTell()
    { return true; }

// ---- the Armies of the Renaissance Part III commentary (print 17) ----

// the White Company longbowmen - two thousand, many veterans of the French
// Wars the Armies of the Renaissance Part III commentary (print 17)
inline int t25WhiteCompanyLongbowmen()
    { return 2000; }

// the White Company mounted men at arms - two thousand the Armies of the
// Renaissance Part III commentary (print 17)
inline int t25WhiteCompanyMenAtArms()
    { return 2000; }

// the French invasion - the artillery lesson year for the Italians the Armies
// of the Renaissance Part III commentary (print 17)
inline int t25FrenchInvasionYear()
    { return 1490; }

// the Condotierre economy - reduce casualties and increase the wealthy
// ransomable prisoners the Armies of the Renaissance Part III commentary
// (print 17)
inline bool t25RansomOverBlood()
    { return true; }

// the Stradiot - the light cavalryman serving as a dragoon on horse or foot
// the Armies of the Renaissance Part III commentary (print 17)
inline bool t25StradiotDragoon()
    { return true; }

// the crossbow answer - heavy bolts penetrating the heaviest armor at the
// untenable position the Armies of the Renaissance Part III commentary (print
// 17)
inline bool t25CrossbowAnswer()
    { return true; }

// the Machiavelli Art of War - the classic not read widely enough by his
// contemporaries the Armies of the Renaissance Part III commentary (print 17)
inline bool t25MachiavelliArtOfWar()
    { return true; }

// the Papal core - the personal guard of Swiss mercenaries with legendary
// loyalty the Armies of the Renaissance Part III commentary (print 17)
inline bool t25SwissPapalGuard()
    { return true; }

// the White Company dress - white surcoats emblazoned with the red cross of
// St. George the Armies of the Renaissance Part III commentary (print 17)
inline bool t25WhiteCompanyLivery()
    { return true; }

// ---- the Harrop orc taxonomy guide (print 18-19) ----

// the evil family - kobolds, goblins, hobgoblins, orcs and ogres the Harrop
// orc taxonomy guide (print 18-19)
inline int t25EvilFamilyRaces()
    { return 5; }

// the orkus species - Superus the great orcs and Uruk hai, communis the
// lesser and snaga orcs, homus the man orcs the Harrop orc taxonomy guide
// (print 18-19)
inline int t25OrkusSpecies()
    { return 3; }

// the koboldus height ceiling - up to four feet tall the Harrop orc taxonomy
// guide (print 18-19)
inline int t25KoboldusMaxFt()
    { return 4; }

// the ogrus height floor - six feet plus and as tall as giants the Harrop orc
// taxonomy guide (print 18-19)
inline int t25OgrusMinFt()
    { return 6; }

// the goblin height floor - three to five feet tall the Harrop orc taxonomy
// guide (print 18-19)
inline int t25GoblinFtLo()
    { return 3; }

// the goblin height ceiling the Harrop orc taxonomy guide (print 18-19)
inline int t25GoblinFtHi()
    { return 5; }

// the hobgoblin height floor - five to seven feet tall the Harrop orc
// taxonomy guide (print 18-19)
inline int t25HobgoblinFtLo()
    { return 5; }

// the hobgoblin height ceiling the Harrop orc taxonomy guide (print 18-19)
inline int t25HobgoblinFtHi()
    { return 7; }

// the lesser orc height ceiling - up to four feet tall the Harrop orc
// taxonomy guide (print 18-19)
inline int t25LesserOrcMaxFt()
    { return 4; }

// the great orc height floor - four to six feet the Harrop orc taxonomy guide
// (print 18-19)
inline int t25GreatOrcFtLo()
    { return 4; }

// the great orc height ceiling the Harrop orc taxonomy guide (print 18-19)
inline int t25GreatOrcFtHi()
    { return 6; }

// the man orc height floor - five or six feet tall the Harrop orc taxonomy
// guide (print 18-19)
inline int t25ManOrcFtLo()
    { return 5; }

// the man orc height ceiling the Harrop orc taxonomy guide (print 18-19)
inline int t25ManOrcFtHi()
    { return 6; }

// the painting guides - tribal flesh colours through the raised symbols to
// avoid the Harrop orc taxonomy guide (print 18-19)
inline int t25PaintingGuides()
    { return 10; }

// the gaming guides - the sunlight morale, the racial feud checks and the
// formation rule the Harrop orc taxonomy guide (print 18-19)
inline int t25GamingGuides()
    { return 4; }

// the man orc origin - every tribe specially bred by a powerful evil
// magician, the tribes unable to inter breed the Harrop orc taxonomy guide
// (print 18-19)
inline bool t25HomusBredTribes()
    { return true; }

// the kobold gnome feud - almost instant attacks, obedience checks at
// charging distance the Harrop orc taxonomy guide (print 18-19)
inline bool t25KoboldGnomeFeud()
    { return true; }

// the goblin dwarf feud - the same checks, and the lesser orc and elf feud
// the Harrop orc taxonomy guide (print 18-19)
inline bool t25GoblinDwarfFeud()
    { return true; }

// the sunlight rule - all goblin races dislike the daylight, lower their
// morale in the daytime the Harrop orc taxonomy guide (print 18-19)
inline bool t25SunlightMorale()
    { return true; }

// the tribal feud rule - orcs of different tribes attack each other, leaders
// adjusting the die roll the Harrop orc taxonomy guide (print 18-19)
inline bool t25TribalFeuds()
    { return true; }

// the formation rule - only great orcs and man orcs fight in formations, the
// rest fight en masse the Harrop orc taxonomy guide (print 18-19)
inline bool t25FormationOrcs()
    { return true; }

// the warg cavalry - the smaller goblin races ride the large corrupted wolves
// the Harrop orc taxonomy guide (print 18-19)
inline bool t25WargCavalry()
    { return true; }

}   // namespace rules
