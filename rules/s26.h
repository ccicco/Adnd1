// =========================================================================================
// Adnd1 - rules/s26.h
// The Dragon issue-26 opener part two - the table round
// census 885 -> 886.
//
// The part-two round of the issue-26 four-round shape - four of the thirteen
// Curtiss-called chains pinned as the table round: the Chinese Undead roster
// (print 20-21) with the six undead brackets, the nine-point alignment chart
// (print 23) with the conduct encodings, the Deck of Fate tarot artifact
// (print 24-25) with the wheel bands and the arcana, and the strength
// comparison ladder (print 38) with the giant rungs and the ogre power
// revision, the five-chain opener set down at part one and the four-chain
// commentary set plus the flip to follow. All pinned from The Dragon Vol. III
// No. 12 (June 1979) print 20-25 and 38 at extract/dragon/026 (landed at
// R962), the single-voice transcript of the Curtiss-provided scan; the four
// grids carry the printed numbers as scanned, the strength ladder printing
// its overlapping 18/90 row pinned as scanned. The watches - the Sullin
// levels 7-9 and the brawling sequel - ride to TD 27 absent a fifth issue.
//
namespace rules {

// ---- the Chinese Undead roster (print 20-21) ----

// the roster size - six Chinese undead from the lower soul to the goat demon
// the Chinese Undead roster (print 20-21)
inline int s26UndeadRosterCount()
    { return 6; }

// the psionic class - all six printing class six the Chinese Undead roster
// (print 20-21)
inline int s26UndeadPsionicClass()
    { return 6; }

// the neutral count - the lower soul and the celestial stag, the other four
// Chaotic Evil the Chinese Undead roster (print 20-21)
inline int s26UndeadNeutralCount()
    { return 2; }

// the lost soul attack - 1-10 damage the Chinese Undead roster (print 20-21)
inline int s26LostSoulDamageHi()
    { return 10; }

// the lost soul drain - two levels a hit, the victim never becoming one the
// Chinese Undead roster (print 20-21)
inline int s26LostSoulDrain()
    { return 2; }

// the vampire spectre claws - two at 1-4 the Chinese Undead roster (print
// 20-21)
inline int s26VampireClawHi()
    { return 4; }

// the vampire spectre bite - 2-12 the Chinese Undead roster (print 20-21)
inline int s26VampireBiteHi()
    { return 12; }

// the cause disease touches - up to five a day the Chinese Undead roster
// (print 20-21)
inline int s26VampireDiseaseUses()
    { return 5; }

// the turning penalty - the cleric subtracting two the Chinese Undead roster
// (print 20-21)
inline int s26VampireTurnPenalty()
    { return 2; }

// the charm penalty - the victim subtracting three the Chinese Undead roster
// (print 20-21)
inline int s26VampireCharmPenalty()
    { return 3; }

// the charm breath uses - three a day the Chinese Undead roster (print 20-21)
inline int s26SeaBonzeBreathUses()
    { return 3; }

// the sea bonze bite - 1-8 the Chinese Undead roster (print 20-21)
inline int s26SeaBonzeBiteHi()
    { return 8; }

// the celestial stag horns - two at 1-6 the Chinese Undead roster (print
// 20-21)
inline int s26StagHornHi()
    { return 6; }

// the goat demon butt - 1-8 with the paralysis save the Chinese Undead roster
// (print 20-21)
inline int s26GoatDemonButtHi()
    { return 8; }

// the baseline - all affected by the same items as Western undead the Chinese
// Undead roster (print 20-21)
inline bool s26UndeadWesternItems()
    { return true; }

// the immunity - charm person and sleep never working on any the Chinese
// Undead roster (print 20-21)
inline bool s26UndeadCharmSleepImmune()
    { return true; }

// the lower soul - the ordinary Chinese vampire, no fly and no bat or mist
// forms the Chinese Undead roster (print 20-21)
inline bool s26LowerSoulNoFly()
    { return true; }

// the lost soul law - killing a replacement to go to rest, the victim never
// transformed the Chinese Undead roster (print 20-21)
inline bool s26LostSoulReplacementKill()
    { return true; }

// the lost soul turn - never dissolved, a dissolve result merely turning it
// away the Chinese Undead roster (print 20-21)
inline bool s26LostSoulNoDissolve()
    { return true; }

// the magic tiger skin - the weretiger slavery, removed only by another
// completing a harrowing quest the Chinese Undead roster (print 20-21)
inline bool s26TigerSkinQuest()
    { return true; }

// the sea bonze lure - the charmed swimming to the lair, the dead body
// completing the course the Chinese Undead roster (print 20-21)
inline bool s26SeaBonzeLairSwim()
    { return true; }

// the celestial stag form - amoeba-like, oozing through any nook and
// reforming the Chinese Undead roster (print 20-21)
inline bool s26StagOozeForm()
    { return true; }

// the celestial stag bane - full daylight dissolving it the Chinese Undead
// roster (print 20-21)
inline bool s26StagDaylightRule()
    { return true; }

// the goat demon law - ghouls in goat shape, treated as ordinary ghouls the
// Chinese Undead roster (print 20-21)
inline bool s26GoatDemonGhoulRule()
    { return true; }

// the appearing band - the lower number of the six undead brackets
inline int s26UndeadNumLo(int b)
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
            return 2;
        case 5:
            return 2;
        default:
            return -99;
        }
    }

// the appearing band - the higher number
inline int s26UndeadNumHi(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 12;
        case 5:
            return 24;
        default:
            return -99;
        }
    }

// the armor class - the sea bonze and the lower soul both printing 2
inline int s26UndeadAc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return -99;
        }
    }

// the movement rate - the vampire spectre fastest at eighteen
inline int s26UndeadMove(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 12;
        case 2:
            return 18;
        case 3:
            return 9;
        case 4:
            return 12;
        case 5:
            return 9;
        default:
            return -99;
        }
    }

// the hit dice band - the lower number
inline int s26UndeadHdLo(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 4;
        case 2:
            return 10;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 2;
        default:
            return -99;
        }
    }

// the hit dice band - the higher number
inline int s26UndeadHdHi(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 4;
        case 2:
            return 10;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 2;
        default:
            return -99;
        }
    }

// the lair percentage - the lost soul and the celestial stag at zero
inline int s26UndeadLairPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 20;
        case 4:
            return 0;
        case 5:
            return 20;
        default:
            return -99;
        }
    }

// ---- the nine-point alignment chart (print 23) ----

// the chart size - nine boxes from lawful good to chaotic evil the nine-point
// alignment chart (print 23)
inline int s26AlignSchemeCount()
    { return 9; }

// the conduct rows - the word, the unarmed foe, poison, aid, teamwork,
// authority and trust the nine-point alignment chart (print 23)
inline int s26AlignConductRows()
    { return 7; }

// the chart cells - nine boxes against seven conduct rows the nine-point
// alignment chart (print 23)
inline int s26AlignCellCount()
    { return 63; }

// the angry lord - the fifteenth level one the neutrals would not let draw
// his sword the nine-point alignment chart (print 23)
inline int s26AlignLordLevel()
    { return 15; }

// the word keepers - the three Lawful boxes keeping their word outright, the
// lawful evil printing pinned as scanned the nine-point alignment chart
// (print 23)
inline int s26AlignWordUnconditional()
    { return 3; }

// the poison refusers - the three Good boxes refusing it against intelligent
// creatures the nine-point alignment chart (print 23)
inline int s26AlignPoisonRefusers()
    { return 3; }

// the indifferent boxes - the neutral goods through the neutral evils toward
// higher authority the nine-point alignment chart (print 23)
inline int s26AlignIndifferentAuthority()
    { return 3; }

// the distrustful boxes - the three Chaotic ones toward organizations the
// nine-point alignment chart (print 23)
inline int s26AlignDistrustCount()
    { return 3; }

// the Lawful column - good, neutral and evil the nine-point alignment chart
// (print 23)
inline int s26AlignLawfulCount()
    { return 3; }

// the Chaotic column - good, neutral and evil the nine-point alignment chart
// (print 23)
inline int s26AlignChaoticCount()
    { return 3; }

// the chart purpose - ending the arguments over chaotics in parties and open
// season on neutrals the nine-point alignment chart (print 23)
inline bool s26AlignChartPurpose()
    { return true; }

// the DM license - the chart followed no more strictly than the referee
// wishes the nine-point alignment chart (print 23)
inline bool s26AlignDmLicense()
    { return true; }

// the axis - the Lawfuls liking order and organization, the Chaotics
// shuddering at cooperation the nine-point alignment chart (print 23)
inline bool s26AlignLawfulOrder()
    { return true; }

// the authority row - following the directives or wanting the order to
// crumble the nine-point alignment chart (print 23)
inline bool s26AlignAuthorityAxis()
    { return true; }

// the trust effect - Lawful money in banks and hotel safes, Chaotic money
// buried or in hollow trees the nine-point alignment chart (print 23)
inline bool s26AlignBankingRule()
    { return true; }

// the poison exception - wyverns fair game for anyone with a little
// belladonna the nine-point alignment chart (print 23)
inline bool s26AlignBelladonnaNote()
    { return true; }

// the unarmed foe row - the Evils thriving on it, the Goods letting the poor
// fellow draw the nine-point alignment chart (print 23)
inline bool s26AlignEvilUnarmed()
    { return true; }

// the aid row - the Goods helping, the Neutrals on a whim or reward, the
// Evils for a sizeable reward the nine-point alignment chart (print 23)
inline bool s26AlignAidRow()
    { return true; }

// the neutral warning - the True Neutrals taking a lot of watching before
// anyone pins them down the nine-point alignment chart (print 23)
inline bool s26AlignNeutralWatching()
    { return true; }

// the closing caveat - not firm restrictions, always open to DM
// interpretation the nine-point alignment chart (print 23)
inline bool s26AlignNotFirmRules()
    { return true; }

// the word row - two keeping it, one conditional, zero refusing
inline int s26AlignWord(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the unarmed foe row - two letting him draw, one conditional, zero thriving
// on it
inline int s26AlignUnarmed(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 2;
        default:
            return -99;
        }
    }

// the poison row - two refusing it against intelligent creatures, one
// conditional, zero using it
inline int s26AlignPoison(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 2;
        default:
            return -99;
        }
    }

// the aid row - two helping others, one on a whim or reward, zero for a
// sizeable reward
inline int s26AlignAid(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the teamwork row - two preferring company, one tolerating, zero preferring
// to work alone
inline int s26AlignTeamwork(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the authority row - two following directives, one indifferent or
// conditional, zero wanting the order to crumble
inline int s26AlignAuthority(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the trust row - two trustful, one neutral, zero distrustful
inline int s26AlignTrust(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// ---- the Deck of Fate tarot artifact (print 24-25) ----

// the wheel of fortune bands - the seven percentile ranges the Deck of Fate
// tarot artifact (print 24-25)
inline int s26FateWheelBands()
    { return 7; }

// the greater arcana - the twenty one numbered cards and the fool the Deck of
// Fate tarot artifact (print 24-25)
inline int s26FateGreaterArcana()
    { return 22; }

// the numbered cards of the greater arcana the Deck of Fate tarot artifact
// (print 24-25)
inline int s26FateNumberedCards()
    { return 21; }

// the fool zonks - ten silly worthless items from the giant rabbit costume
// down the Deck of Fate tarot artifact (print 24-25)
inline int s26FateZonkCount()
    { return 10; }

// the magician - one spell of the next highest level the Deck of Fate tarot
// artifact (print 24-25)
inline int s26FateMagicianGain()
    { return 1; }

// the goddess - the cleric wisdom boost to eighteen the Deck of Fate tarot
// artifact (print 24-25)
inline int s26FateGoddessWisdom()
    { return 18; }

// the empress money floor the Deck of Fate tarot artifact (print 24-25)
inline int s26FateEmpressGoldLo()
    { return 400; }

// the empress money ceiling the Deck of Fate tarot artifact (print 24-25)
inline int s26FateEmpressGoldHi()
    { return 1000; }

// the jupiter grant - two permanent spells of the next highest level the Deck
// of Fate tarot artifact (print 24-25)
inline int s26FateJupiterSpells()
    { return 2; }

// the devil summons - the bone devil of the fifth plane of Hell the Deck of
// Fate tarot artifact (print 24-25)
inline int s26FateBoneDevilPlane()
    { return 5; }

// the house of god wreckage - thirteen gold pieces left with a tunic and one
// weapon the Deck of Fate tarot artifact (print 24-25)
inline int s26FateTowerSpareGold()
    { return 13; }

// the star boon - plus three on all saving throws the Deck of Fate tarot
// artifact (print 24-25)
inline int s26FateStarSaves()
    { return 3; }

// the sun gold ceiling the Deck of Fate tarot artifact (print 24-25)
inline int s26FateSunGoldHi()
    { return 600; }

// the world gold ceiling the Deck of Fate tarot artifact (print 24-25)
inline int s26FateWorldGoldHi()
    { return 800; }

// the moon citation - The Dragon number eighteen, September 1978, the
// Thompson insanity rules the Deck of Fate tarot artifact (print 24-25)
inline int s26FateMoonRef()
    { return 18; }

// the rarity - only one in the known Universe, belonging to no individual the
// Deck of Fate tarot artifact (print 24-25)
inline bool s26FateSingleCopy()
    { return true; }

// the effect law - immediate, no saving throw allowed the Deck of Fate tarot
// artifact (print 24-25)
inline bool s26FateNoSavingThrow()
    { return true; }

// the second card - the invoked deity angry, imprisonment in the deck or the
// good card reversed the Deck of Fate tarot artifact (print 24-25)
inline bool s26FateSecondCardWrath()
    { return true; }

// the magician gate - directed at magic users, others gaining only a misc
// item the Deck of Fate tarot artifact (print 24-25)
inline bool s26FateMagicianGate()
    { return true; }

// the empress and emperor - money only for women, the emperor the masculine
// equivalent the Deck of Fate tarot artifact (print 24-25)
inline bool s26FateEmpressSexGate()
    { return true; }

// the lovers - love with the first character of the opposite sex encountered
// the Deck of Fate tarot artifact (print 24-25)
inline bool s26FateLoversRule()
    { return true; }

// the justice duel - same level, armament and hit points, opposite alignment,
// the spectators frozen the Deck of Fate tarot artifact (print 24-25)
inline bool s26FateJusticeTrial()
    { return true; }

// the hermit mercy - the transported kept on the same dungeon level the Deck
// of Fate tarot artifact (print 24-25)
inline bool s26FateHermitMercy()
    { return true; }

// the moon - alignment to Chaotic Evil, the already chaotic going insane the
// Deck of Fate tarot artifact (print 24-25)
inline bool s26FateMoonMadness()
    { return true; }

// the extension - the fifty six card Lesser Arcana with its four suits, the
// forerunner of the card deck the Deck of Fate tarot artifact (print 24-25)
inline bool s26FateLesserArcana()
    { return true; }

// the percentile band ceiling - twenty through one hundred
inline int s26FateWheelRollHi(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 40;
        case 2:
            return 60;
        case 3:
            return 70;
        case 4:
            return 80;
        case 5:
            return 90;
        case 6:
            return 100;
        default:
            return -99;
        }
    }

// the item band - the magic sword through the misc magic item
inline int s26FateWheelBand(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return -99;
        }
    }

// ---- the strength comparison ladder (print 38) ----

// the ladder rows - the printed bands from collapse to the storm giants the
// strength comparison ladder (print 38)
inline int s26StrengthLadderRows()
    { return 21; }

// the ladder floor - zero, collapse on the ground the strength comparison
// ladder (print 38)
inline int s26StrengthDieFloor()
    { return 0; }

// the ladder ceiling - storm giants and titans the strength comparison ladder
// (print 38)
inline int s26StrengthCeiling()
    { return 27; }

// the gauntlets of ogre power revision - plus three to hit the strength
// comparison ladder (print 38)
inline int s26StrengthOgreHit()
    { return 3; }

// the gauntlets damage revision - plus one to six against the Players
// Handbook plus one to eight the strength comparison ladder (print 38)
inline int s26StrengthOgreDamageDie()
    { return 6; }

// the old gauntlets rating - plus two to hit per the Players Handbook,
// revised here the strength comparison ladder (print 38)
inline int s26StrengthGauntletsOldHit()
    { return 2; }

// the demon and devil floor - twenty the strength comparison ladder (print
// 38)
inline int s26StrengthDemonLo()
    { return 20; }

// the demon and devil ceiling - twenty five, referee discretion the strength
// comparison ladder (print 38)
inline int s26StrengthDemonHi()
    { return 25; }

// the hobbit battle axe - one d4 the strength comparison ladder (print 38)
inline int s26StrengthHobbitAxeDie()
    { return 4; }

// the strong hobbit damage - 2-5 at strength sixteen the strength comparison
// ladder (print 38)
inline int s26StrengthHobbitDamageHi()
    { return 5; }

// the girdle cursed human potential - 1-7 with the man sized axe the strength
// comparison ladder (print 38)
inline int s26StrengthCursedAxeHi()
    { return 7; }

// the sex change note - the hobbit female capped at fourteen the strength
// comparison ladder (print 38)
inline int s26StrengthSexChangeCap()
    { return 14; }

// the damage floor - never below one point the strength comparison ladder
// (print 38)
inline int s26StrengthDamageFloor()
    { return 1; }

// the inspiration - the Dave Hargrave Arduin Grimoire II strength table the
// strength comparison ladder (print 38)
inline bool s26StrengthArduinSource()
    { return true; }

// the natural limit - racial maximums never exceeded, magic raising past them
// temporarily and sometimes permanently via wishes the strength comparison
// ladder (print 38)
inline bool s26StrengthRacialMaxima()
    { return true; }

// the man sized rule - monster weapons damage plus the racial strength
// bonuses the strength comparison ladder (print 38)
inline bool s26StrengthMonsterWeaponsRule()
    { return true; }

// the smaller than man sized rule - the accompanying table without the
// bonuses the strength comparison ladder (print 38)
inline bool s26StrengthSmallerTableRule()
    { return true; }

// the individual method - 3d6 plus the personal added to the racial average,
// the polymorph carrying it over the strength comparison ladder (print 38)
inline bool s26StrengthExceptionalRolls()
    { return true; }

// the monster PC rule - the Men Attacking Table with the racial and personal
// bonuses, never the Monsters Attacking Table the strength comparison ladder
// (print 38)
inline bool s26StrengthMenAttackingTable()
    { return true; }

// the flesh and bone caveat - magic not strengthening the tendons, the joints
// failing messily the strength comparison ladder (print 38)
inline bool s26StrengthFleshAndBone()
    { return true; }

// the cumulative law - all hit probability and damage bonuses cumulative the
// strength comparison ladder (print 38)
inline bool s26StrengthCumulativeRule()
    { return true; }

// the house fit - the Dungeon Masters Guide magic items modified to fit this
// table the strength comparison ladder (print 38)
inline bool s26StrengthDmgModificationGate()
    { return true; }

// the referee kit - girdles of kobold strength and gauntlets of pixie power
// for the monsters the strength comparison ladder (print 38)
inline bool s26StrengthGirdleQuips()
    { return true; }

// the equivalent strength band - the lower number, collapse at zero
inline int s26StrengthEqLo(int b)
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
            return 8;
        case 8:
            return 9;
        case 9:
            return 13;
        case 10:
            return 15;
        case 11:
            return 17;
        case 12:
            return 19;
        case 13:
            return 20;
        case 14:
            return 21;
        case 15:
            return 22;
        case 16:
            return 23;
        case 17:
            return 24;
        case 18:
            return 25;
        case 19:
            return 26;
        case 20:
            return 27;
        default:
            return -99;
        }
    }

// the equivalent strength band - the higher number, storm giants and titans
// at twenty seven
inline int s26StrengthEqHi(int b)
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
            return 7;
        case 7:
            return 8;
        case 8:
            return 12;
        case 9:
            return 14;
        case 10:
            return 16;
        case 11:
            return 18;
        case 12:
            return 19;
        case 13:
            return 20;
        case 14:
            return 21;
        case 15:
            return 22;
        case 16:
            return 23;
        case 17:
            return 24;
        case 18:
            return 25;
        case 19:
            return 26;
        case 20:
            return 27;
        default:
            return -99;
        }
    }

// the hit adjustment - minus four at one through plus six at twenty seven,
// zero the normal rung, the sentinel on the collapse row
inline int s26StrengthHitAdj(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -4;
        case 2:
            return -1;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 6;
        case 20:
            return 6;
        default:
            return -99;
        }
    }

}   // namespace rules
