// =========================================================================================
// Adnd1 - rules/mm2dp.h
// THE MM2 LETTER D PART 1 - the twenty-nine planar evil entries of the letter
// D opening (the daemons, the demodands and the demons, pp. 28-42 through the
// derro), promoted to the live registry
// census 721 -> 722.
//
// Round three of the MM2 arc, the first PART-LETTER walk (the user Go call on
// the landed letters BC: the letter D is too large for one round, so part 1
// takes the planar evil families pp. 28-42 and the rest of D awaits the user
// call). The capture is the Curtiss PDF upload cross-checked against an
// independent transcription and the archive.org djvu OCR, the contested cells
// settled: the kelubar LEVEL/X.P. keeps the print 3959 (the ladder would say
// 3950) and its % IN LAIR cell prints BLANK (all three sources); the cambion
// xp prints 4400 in the block and 4409 in the parentage table (a genuine
// print-internal inconsistency pinning as it prints; the grid rides the block
// Minor 1275 + 10/hp); the shator weapon strength bonus reads +9 (the capture
// +8 is an OCR misread; the giant ladder 21 reads +9); the graz'zt
// DAMAGE/ATTACK prints By weapon type 6 verbatim (no plus); the alu-demon
// range VIII or IX/3000 or 4050 + 14/hp pins its low end; the yagnodaemon
// SIZE is L; the dao SIZE keeps its capture-primary double-primes; the
// hydrodaemon treasure prints I,Y; the chasme LEVEL prints VIII; the nabassu
// first claw reads 2-8/2-8/3-12; the babau attack/defense modes read
// A,C,E/F,G,H; the arcanadaemon INTELLIGENCE reads Supra-genius; the demilich
// ARMOR CLASS prints -6 and special so the def carries the bare -6 (the
// sign-drop class); the derro LEVEL/X.P. prints Variables preclude a fixed
// number so the def carries the xp 0 sentinel (the Amaimon precedent); the
// farastu Nil (25%) and shator Nil (40%) lair parentheticals and the
// hydrodaemon 90%-near-Styx parenthetical ride the pins. The pin-time walk
// finds nine daemon entries (the arcanadaemon through the yagnodaemon), three
// demodands (the farastu through the shator), thirteen demons (the alu-demon
// through the rutterkin) and four singletons (the dao, the crimson death, the
// demilich, the derro); twenty-nine .lua defs ride the R791 data_files
// extension, registry 491+43 -> 534 -> 563 (the landed letters A and BC
// floors stay floors). The stat blocks pin in the 29-row DpStats grid; the
// cambion Male Parentage Class table pins as the 12-row parentage grid; the
// daemon, demodand and demon common doctrine (the attack-form charts, the
// magic-resistance decrement rule, the demodand summon-cap ladder, the
// name-speaking base, the 45-name Abyss ruler enumeration and the 28-line
// inhabitants roster) pins as round-level doctrine. NO GAP FLIPS: the Letter
// D box flips only when all the D parts land (the R791 no-flip precedent). NO
// XP-AUDIT PATCH: mm2_print already rides the allowed-source list (the R797
// patch). The live def walk (the one file-patch site block, no census marker)
// cross-checks all 29 defs against the DpStats grid, the planes, the xpValue
// formula, the cambion parentage cells, the derro sentinel and the registry
// census 534 -> 563 as a floor.
//
namespace rules {

// ---- the MM2 letter D part 1 round pins (the R799 census) ----

// The MM2 letter D part 1 round: the planar evil families walk (the user Go
// call on the landed letters BC)
inline int mm2dpRound()
    { return 799; }

// The pin-time walk from the print (pp. 28-42): the arcanadaemon through the
// derro - the D-part-1 entries before the deva turn
inline int mm2dpEntryCount()
    { return 29; }

// The def census: twenty-nine .lua defs ride the R791 data_files extension
// (no form splits in D part 1)
inline int mm2dpDefCount()
    { return 29; }

// The daemon entries (pp. 28-31): arcanadaemon, charon, charonadaemon,
// derghodaemon, hydrodaemon, oinodaemon, piscodaemon, ultrodaemon,
// yagnodaemon
inline int mm2dpDaemonEntryCount()
    { return 9; }

// The demodand entries (pp. 33-34): farastu, kelubar, shator
inline int mm2dpDemodandEntryCount()
    { return 3; }

// The demon entries (pp. 35-42): alu-demon, babau, baphomet, bar-lgura,
// cambion, chasme, dretch, fraz-urb'luu, grazzt, kostchtchie, nabassu,
// pazuzu, rutterkin
inline int mm2dpDemonEntryCount()
    { return 13; }

// The D-part-1 singletons outside the three families: dao, crimson death,
// demilich, derro
inline int mm2dpSingletonEntryCount()
    { return 4; }

// The letter D part 1 opens at p. 28 (the daemon section head)
inline int mm2dpFirstPage()
    { return 28; }

// The letter D part 1 closes at p. 42 (the derro entry; the deva turn comes
// with the next D part)
inline int mm2dpLastPage()
    { return 42; }

// The live registry census at the landed letters BC (the R798 landing count)
inline int mm2dpRegistryBefore()
    { return 534; }

// The live registry census after the twenty-nine D-part-1 defs (534 + 29)
inline int mm2dpRegistryAfter()
    { return 563; }

// The 29-row D-part-1 stat grid: one row per promoted def in print order
inline int mm2dpDpStatRows()
    { return 29; }

// The cambion parentage printed grid: the 12-row Male Parentage Class table
// (the Major and Baron/Marquis columns)
inline int mm2dpCambionParentageRows()
    { return 12; }

// The kelubar LEVEL/X.P. prints IX/3959 + 18/hp verbatim (the ladder would
// say 3950; the print wins)
inline int mm2dpKelubarXpPrintVerbatim()
    { return 3959; }

// The cambion block line Baron VIII/4400 + 15/hp is the def-block pin
inline int mm2dpCambionBaronBlockXp()
    { return 4400; }

// The cambion block Baron xp per hit point
inline int mm2dpCambionBaronBlockXpPerHp()
    { return 15; }

// The cambion parentage table prints 4409 (a genuine print-internal
// inconsistency - the block 4400 and the table 4409 both pin; the grid uses
// the Minor 1275 + 10/hp line)
inline int mm2dpCambionBaronTableXp()
    { return 4409; }

// The parentage table Baron xp per hit point (the table and the block agree
// here)
inline int mm2dpCambionBaronTableXpPerHp()
    { return 15; }

// The cambion block line Marquis IX/6500 + 20/hp (the marquis* footnote: evil
// cleric abilities and 16-18 hit dice)
inline int mm2dpCambionMarquisXp()
    { return 6500; }

// The cambion block Marquis xp per hit point
inline int mm2dpCambionMarquisXpPerHp()
    { return 20; }

// The cambion block line Minor VII/1275 + 10/hp - the grid xp cell
inline int mm2dpCambionMinorXp()
    { return 1275; }

// The cambion block Minor xp per hit point - the grid xp/hp cell
inline int mm2dpCambionMinorXpPerHp()
    { return 10; }

// The shator weapon strength bonus prints +9 (the settled read: the capture
// +8 is an OCR misread; the giant ladder 21 strength reads +9, consistent
// with the derghodaemon stone-giant +8 and the yagnodaemon storm-giant +12)
inline int mm2dpShatorWeaponStrengthBonus()
    { return 9; }

// The alu-demon LEVEL/X.P. prints VIII or IX/3000 or 4050 + 14/hp - the range
// precedent pins the low end 3000 + 14
inline int mm2dpAluXpLowEnd()
    { return 3000; }

// The alu-demon range high end (pinned; the grid cell carries the low end)
inline int mm2dpAluXpHighEnd()
    { return 4050; }

// The alu-demon xp per hit point
inline int mm2dpAluXpPerHp()
    { return 14; }

// The chasme LEVEL/X.P. prints VIII/1275 + 10/hp (the roman VIII confirmed by
// both sources)
inline int mm2dpChasmeXpLevelViii()
    { return 8; }

// The derro LEVEL/X.P. prints Variables preclude a fixed number - the def xp
// 0 sentinel (the Amaimon precedent)
inline int mm2dpDerroXp()
    { return 0; }

// NO gap flips this round: the Letter D box flips only when all the D parts
// land (the R791 no-flip precedent - a part walk never flips the box)
inline bool mm2dpDBoxFlipsOnlyWhenAllPartsLand()
    { return true; }

// The letter D walks in parts (part 1 = the planar evil families pp. 28-42;
// the rest of D awaits the user call)
inline bool mm2dpMultiPartLetterWalk()
    { return true; }

// mm2_print already rides the allowed-source list (the R797 patch) - no
// xp-audit patch this round
inline bool mm2dpMm2PrintRidesXpAudit()
    { return true; }

// The twenty-nine defs ride the R791 data_files extension, idempotent by
// existence
inline bool mm2dpDefsRideDataFiles()
    { return true; }

// The pin headers stay the print-fidelity record (the .lua headers stay
// hand-edit-locked)
inline bool mm2dpPinHeaderStaysPrintRecord()
    { return true; }

// The kelubar % IN LAIR cell prints BLANK (all three sources agree) - the def
// lair reads 0 and the pin documents the blank cell
inline bool mm2dpKelubarLairCellBlank()
    { return true; }

// The kelubar 3959 kept print verbatim over the ladder 3950 (the
// print-fidelity rule)
inline bool mm2dpKelubarXpKeptPrintVerbatim()
    { return true; }

// The cambion Baron xp prints 4400 in the block and 4409 in the parentage
// table (a genuine print-internal inconsistency - both pin as they print)
inline bool mm2dpCambionXpPrintInconsistent()
    { return true; }

// The cambion See below cells (AC, HD, lair, treasure, MR, psionic) read the
// parentage table - the def AC 6 and HD 5 ride the Major column
inline bool mm2dpCambionCellsFromParentage()
    { return true; }

// The graz'zt DAMAGE/ATTACK prints By weapon type 6 (no plus; the family
// convention would suspect +6 but both captures agree - the print verbatim
// wins)
inline bool mm2dpGrazztDamagePrintsVerbatim()
    { return true; }

// The yagnodaemon SIZE prints L (12' tall) (the settled read; the
// transcription M is the misread)
inline bool mm2dpYagnodaemonSizeIsL()
    { return true; }

// The dao SIZE prints L (8"-11" tall) - the capture-primary double-primes
// kept verbatim (the settled read, mirroring the R797 domestic cat move)
inline bool mm2dpDaoSizeKeepsDoublePrimes()
    { return true; }

// The hydrodaemon TREASURE TYPE prints I,Y (the capture LY and the djvu t,Y
// are both misreads of the comma)
inline bool mm2dpHydroTreasureIsIY()
    { return true; }

// The demilich ARMOR CLASS prints -6 and special - the def carries the bare
// -6 (a string would load +6: the sign-drop class)
inline bool mm2dpDemilichAcCarriesBareNegative()
    { return true; }

// The arcanadaemon INTELLIGENCE prints Supra-genius (the settled read; the
// transcription Average was the misread)
inline bool mm2dpArcanadaemonIntSupraGenius()
    { return true; }

// The derro xp 0 sentinel (the Amaimon precedent; the loader floors xpValue
// at the 0 base)
inline bool mm2dpDerroXpZeroSentinel()
    { return true; }

// The farastu Nil (25%) and shator Nil (40%) lair parentheticals ride the
// pins (the def lair cells read 0)
inline bool mm2dpDemodandLairParensPin()
    { return true; }

// ---- the daemon doctrine pins (the R799 MM2 letter D part 1) ----

// The daemon magic resistance falls 5% for each spell level above 1st (the
// daemon-common rule)
inline int mm2dpDaemonMrDecrementPct()
    { return 5; }

// The daemon magic resistance baseline reads versus an 11th-level
// spell-caster
inline int mm2dpDaemonMrBaselineLevel()
    { return 11; }

// word of recall rides the daemon-common spell-like list once per day (back
// to the plane of origin)
inline int mm2dpDaemonWordOfRecallPerDay()
    { return 1; }

// The daemon attack-form chart: acid half damage
inline bool mm2dpDaemonAcidHalfDamage()
    { return true; }

// cold half damage
inline bool mm2dpDaemonColdHalfDamage()
    { return true; }

// electricity or lightning full damage
inline bool mm2dpDaemonElectricityFullDamage()
    { return true; }

// dragon or magical fire half damage
inline bool mm2dpDaemonFireHalfDamage()
    { return true; }

// gas full damage
inline bool mm2dpDaemonGasFullDamage()
    { return true; }

// magic missile full damage
inline bool mm2dpDaemonMagicMissileFullDamage()
    { return true; }

// enchanted iron and silver weapons full damage
inline bool mm2dpDaemonIronAndSilverFullDamage()
    { return true; }

// poison, paralysis and normal weapons do no damage
inline bool mm2dpDaemonPoisonParalysisNone()
    { return true; }

// charm and suggestion spells have no effect on daemonic life
inline bool mm2dpDaemonCharmSuggestionImmune()
    { return true; }

// the daemon-common list: detect invisible, read magic, comprehend languages,
// invisibility, telepathy (low intelligence or higher) and word of recall
// once per day
inline bool mm2dpDaemonCommonSpellLikeList()
    { return true; }

// all daemons have infra- and ultravision
inline bool mm2dpDaemonInfraAndUltravision()
    { return true; }

// ---- the demodand doctrine pins (the R799 MM2 letter D part 1) ----

// The demodand summon caps: the total summoned by others of that type can
// never exceed the number encounterable on the Planes of Tarterus - 12, 10 or
// 8
inline int mm2dpDemodandSummonCapHi()
    { return 12; }

// The demodand summon-cap ladder floor (the shator 8)
inline int mm2dpDemodandSummonCapLo()
    { return 8; }

// The farastu summon cap 12 (the commoners of Tarterus)
inline int mm2dpFarastuSummonCap()
    { return 12; }

// The kelubar summon cap 10 (the middle class of Tarterus)
inline int mm2dpKelubarSummonCap()
    { return 10; }

// The shator summon cap 8 (the ruling nobility of Tarterus)
inline int mm2dpShatorSummonCap()
    { return 8; }

// The demodands form a feudal society of barons and commoners on the planes
// of Tarterus
inline bool mm2dpDemodandFeudalSociety()
    { return true; }

// On the Prime Material Plane but a single demodand will be encountered
inline bool mm2dpDemodandSingleOnPrime()
    { return true; }

// ---- the demon doctrine pins (the R799 MM2 letter D part 1) ----

// A base 5% chance that a spoken demon name is heard (the demon-common rule)
inline int mm2dpNameSpeakingBasePct()
    { return 5; }

// The Enumeration of the Rulers of the Abyss prints 15 rows
inline int mm2dpAbyssRulerRows()
    { return 15; }

// of 3 names each
inline int mm2dpAbyssRulerCols()
    { return 3; }

// 45 enumerated rulers (the (L) lord and (F) female markers ride the print)
inline int mm2dpAbyssRulerCount()
    { return 45; }

// The Typical Inhabitants of an Abyssal Layer roster prints 28 lines
inline int mm2dpAbyssRosterLines()
    { return 28; }

// The demon attack-form chart: acid full damage
inline bool mm2dpDemonAcidFullDamage()
    { return true; }

// cold half damage
inline bool mm2dpDemonColdHalfDamage()
    { return true; }

// electricity (lightning) half damage
inline bool mm2dpDemonElectricityHalfDamage()
    { return true; }

// fire (dragon, magical) half damage
inline bool mm2dpDemonFireHalfDamage()
    { return true; }

// gas (poisonous, etc.) half damage
inline bool mm2dpDemonGasHalfDamage()
    { return true; }

// iron weapon full damage
inline bool mm2dpDemonIronFullDamage()
    { return true; }

// magic missile full damage
inline bool mm2dpDemonMagicMissileFullDamage()
    { return true; }

// poison full damage
inline bool mm2dpDemonPoisonFullDamage()
    { return true; }

// silver weapon none (unless affected by normal weapons, in which case by
// weapon type)
inline bool mm2dpDemonSilverNone()
    { return true; }

// No demon can ever be subdued
inline bool mm2dpDemonNeverSubdued()
    { return true; }

// The demon telepathy understands every intelligent communication; average or
// better intelligence likewise converses
inline bool mm2dpDemonTelepathicUnderstanding()
    { return true; }

// Demons cannot enter the Prime Material Plane without aid (conjuration,
// gate, name speaking or similar means)
inline bool mm2dpDemonCannotEnterPrimeUnaided()
    { return true; }

// ---- the MM2 letter D part 1 stat grid (the R799 wiring) ----

// The ARMOR CLASS cell (the charon, oinodaemon, demilich, farastu, kelubar,
// shator, babau, baphomet, bar-lgura, chasme, fraz-urb'luu, graz'zt,
// kostchtchie and pazuzu negatives ride bare Lua numbers - a string drops the
// sign; the demilich -6 and the cambion 6 are settled reads, the print
// strings ride the defs)
inline int mm2dpDpStatAC(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -5;
        case 2:
            return -1;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return -6;
        case 6:
            return -1;
        case 7:
            return -5;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return -6;
        case 12:
            return -1;
        case 13:
            return -2;
        case 14:
            return -3;
        case 15:
            return 5;
        case 16:
            return -3;
        case 17:
            return -4;
        case 18:
            return -3;
        case 19:
            return 6;
        case 20:
            return -1;
        case 21:
            return 2;
        case 22:
            return -2;
        case 23:
            return -9;
        case 24:
            return -3;
        case 25:
            return 4;
        case 26:
            return -9;
        case 27:
            return 1;
        case 28:
            return 9;
        default:
            return 0;
        }
    }

// The HIT DICE number (the flat-hp forms read 0 - the loader flat-hp path;
// the alu 6+2 pins the range low end)
inline int mm2dpDpStatHd(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 0;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 9;
        case 5:
            return 0;
        case 6:
            return 6;
        case 7:
            return 14;
        case 8:
            return 13;
        case 9:
            return 8;
        case 10:
            return 13;
        case 11:
            return 0;
        case 12:
            return 11;
        case 13:
            return 13;
        case 14:
            return 15;
        case 15:
            return 6;
        case 16:
            return 7;
        case 17:
            return 0;
        case 18:
            return 6;
        case 19:
            return 5;
        case 20:
            return 7;
        case 21:
            return 4;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 5;
        case 26:
            return 0;
        case 27:
            return 5;
        case 28:
            return 3;
        default:
            return 0;
        }
    }

// The HIT DICE bonus points (the alu 6+2 to 6+6 pins the +2)
inline int mm2dpDpStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 39;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 22;
        case 4:
            return 36;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 28;
        case 8:
            return 13;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 14;
        case 17:
            return 0;
        case 18:
            return 6;
        case 19:
            return 0;
        case 20:
            return 2;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 2;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The average hit points (floor of dice x 3.5 plus bonus; the flat-hp forms
// carry the print value)
inline int mm2dpDpStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 84;
        case 1:
            return 140;
        case 2:
            return 55;
        case 3:
            return 60;
        case 4:
            return 67;
        case 5:
            return 233;
        case 6:
            return 21;
        case 7:
            return 77;
        case 8:
            return 58;
        case 9:
            return 31;
        case 10:
            return 45;
        case 11:
            return 50;
        case 12:
            return 38;
        case 13:
            return 45;
        case 14:
            return 52;
        case 15:
            return 23;
        case 16:
            return 38;
        case 17:
            return 106;
        case 18:
            return 27;
        case 19:
            return 17;
        case 20:
            return 26;
        case 21:
            return 14;
        case 22:
            return 233;
        case 23:
            return 186;
        case 24:
            return 96;
        case 25:
            return 19;
        case 26:
            return 155;
        case 27:
            return 18;
        case 28:
            return 10;
        default:
            return 0;
        }
    }

// The NO. OF ATTACKS (the loader or-rule reads the max: the babau 1 or 3
// reads 3, graz'zt 2 or 4 reads 4; the fraz-urb'luu 3 and 1 sums to 4; the
// demilich Special reads 1)
inline int mm2dpDpStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 2;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 1;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 2;
        case 28:
            return 2;
        default:
            return 0;
        }
    }

// The LEVEL/X.P. base value (the kelubar 3959 print verbatim; the cambion
// 1275 is the block Minor line; the derro 0 is the Variables sentinel)
inline int mm2dpDpStatXp(int b)
    {
        switch (b) {
        case 0:
            return 6950;
        case 1:
            return 22200;
        case 2:
            return 5300;
        case 3:
            return 5800;
        case 4:
            return 3450;
        case 5:
            return 29555;
        case 6:
            return 455;
        case 7:
            return 8100;
        case 8:
            return 7050;
        case 9:
            return 1600;
        case 10:
            return 7050;
        case 11:
            return 5950;
        case 12:
            return 2850;
        case 13:
            return 3959;
        case 14:
            return 5250;
        case 15:
            return 3000;
        case 16:
            return 2000;
        case 17:
            return 45000;
        case 18:
            return 1725;
        case 19:
            return 1275;
        case 20:
            return 1275;
        case 21:
            return 175;
        case 22:
            return 50000;
        case 23:
            return 60000;
        case 24:
            return 42500;
        case 25:
            return 1800;
        case 26:
            return 65000;
        case 27:
            return 425;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The xp per hit point (the charon 35, the
// oinodaemon/baphomet/fraz-urb'luu/graz'zt/kostchtchie/pazuzu 0 flat-form
// cells)
inline int mm2dpDpStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 35;
        case 2:
            return 16;
        case 3:
            return 16;
        case 4:
            return 14;
        case 5:
            return 0;
        case 6:
            return 6;
        case 7:
            return 20;
        case 8:
            return 18;
        case 9:
            return 12;
        case 10:
            return 18;
        case 11:
            return 16;
        case 12:
            return 16;
        case 13:
            return 18;
        case 14:
            return 20;
        case 15:
            return 14;
        case 16:
            return 12;
        case 17:
            return 0;
        case 18:
            return 10;
        case 19:
            return 10;
        case 20:
            return 10;
        case 21:
            return 4;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 12;
        case 26:
            return 0;
        case 27:
            return 6;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The % IN LAIR cell (Nil reads 0; the kelubar cell prints BLANK; the farastu
// Nil (25%) and shator Nil (40%) parentheticals ride the pins)
inline int mm2dpDpStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 0;
        case 2:
            return 100;
        case 3:
            return 20;
        case 4:
            return 5;
        case 5:
            return 50;
        case 6:
            return 50;
        case 7:
            return 25;
        case 8:
            return 30;
        case 9:
            return 0;
        case 10:
            return 60;
        case 11:
            return 100;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 15;
        case 16:
            return 20;
        case 17:
            return 40;
        case 18:
            return 10;
        case 19:
            return 0;
        case 20:
            return 5;
        case 21:
            return 15;
        case 22:
            return 20;
        case 23:
            return 60;
        case 24:
            return 25;
        case 25:
            return 5;
        case 26:
            return 15;
        case 27:
            return 20;
        case 28:
            return 20;
        default:
            return 0;
        }
    }

// The primary MOVE rate in inches (the first range reads its low end; the
// demilich Special reads 0)
inline int mm2dpDpStatMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 12;
        case 4:
            return 6;
        case 5:
            return 18;
        case 6:
            return 6;
        case 7:
            return 15;
        case 8:
            return 18;
        case 9:
            return 9;
        case 10:
            return 12;
        case 11:
            return 0;
        case 12:
            return 15;
        case 13:
            return 12;
        case 14:
            return 9;
        case 15:
            return 12;
        case 16:
            return 15;
        case 17:
            return 24;
        case 18:
            return 9;
        case 19:
            return 15;
        case 20:
            return 6;
        case 21:
            return 9;
        case 22:
            return 12;
        case 23:
            return 12;
        case 24:
            return 6;
        case 25:
            return 15;
        case 26:
            return 12;
        case 27:
            return 12;
        case 28:
            return 9;
        default:
            return 0;
        }
    }

// ---- the cambion parentage grid (the R799 wiring) ----

// The Male Parentage Class table, the Major column: the cell low end (the AC
// base 6 is the def armor class; the hit-dice 5-8 low end is the def hit
// dice)
inline int mm2dpCambionMajorLo(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 17;
        case 3:
            return 9;
        case 4:
            return 5;
        case 5:
            return 13;
        case 6:
            return 13;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 1275;
        default:
            return 0;
        }
    }

// The Major column cell high end
inline int mm2dpCambionMajorHi(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 18;
        case 3:
            return 16;
        case 4:
            return 8;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 6;
        case 8:
            return 0;
        case 9:
            return 20;
        case 10:
            return 0;
        case 11:
            return 10;
        default:
            return 0;
        }
    }

// The Baron/Marquis column low end (the LEVEL/X.P. row carries base then
// per-hp: the table prints 4409, the print-internal inconsistency with the
// block 4400)
inline int mm2dpCambionBaronLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 9;
        case 2:
            return 18;
        case 3:
            return 13;
        case 4:
            return 3;
        case 5:
            return 15;
        case 6:
            return 15;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 25;
        case 10:
            return 1;
        case 11:
            return 4409;
        default:
            return 0;
        }
    }

// The Baron/Marquis column high end
inline int mm2dpCambionBaronHi(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 16;
        case 2:
            return 20;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 20;
        case 6:
            return 18;
        case 7:
            return 24;
        case 8:
            return 1;
        case 9:
            return 40;
        case 10:
            return 1;
        case 11:
            return 15;
        default:
            return 0;
        }
    }

// ---- the arcanadaemon pins (the R799 MM2 letter D part 1) ----

// The horns strike 2-16; the bite 1-6 and the double claws 1-4 each
inline int mm2dpArcanadaemonHornDamageHi()
    { return 16; }

// The burning hands at-will power does 13 points within 3 feet of the claw
// attack
inline int mm2dpArcanadaemonBurningHandsDamage()
    { return 13; }

// The burning hands reach in feet
inline int mm2dpArcanadaemonBurningHandsRangeFeet()
    { return 3; }

// The telekinese power moves 3250 gp weight
inline int mm2dpArcanadaemonTelekineseWeight()
    { return 3250; }

// The arcanadaemon casts spells as a magic-user of levels 11-18 (the low end
// pins)
inline int mm2dpArcanadaemonMuLevelLo()
    { return 11; }

// The magic-user level high end
inline int mm2dpArcanadaemonMuLevelHi()
    { return 18; }

// The psionic abilities sit at the 10th level of mastery
inline int mm2dpArcanadaemonPsionicMasteryLevel()
    { return 10; }

// The red-iron forts hold 1-4 lesser daemons as servants
inline int mm2dpArcanadaemonFortLesserLo()
    { return 1; }

// The lesser-daemon servant count high end
inline int mm2dpArcanadaemonFortLesserHi()
    { return 4; }

// plus 1-10 hordlings or diakks
inline int mm2dpArcanadaemonFortHordlingLo()
    { return 1; }

// The hordling/diakk count high end
inline int mm2dpArcanadaemonFortHordlingHi()
    { return 10; }

// The fly as spell power holds for an unlimited duration
inline bool mm2dpArcanadaemonFliesUnlimited()
    { return true; }

// The daemon casts its spells without checking its own magic resistance
inline bool mm2dpArcanadaemonCastsWithoutMrCheck()
    { return true; }

// Scrolls and wands also bypass the magic resistance check
inline bool mm2dpArcanadaemonScrollsWandsFree()
    { return true; }

// The at-will list creates darkness within a 20' radius
inline bool mm2dpArcanadaemonDarknessRadiusTwenty()
    { return true; }

// dimension door and teleport ride the list once per day
inline bool mm2dpArcanadaemonTeleportOncePerDay()
    { return true; }

// ---- the charon pins (the R799 MM2 letter D part 1) ----

// Charon carries 140 hit points (the flat-hp path - the hit-dice cell reads
// 0)
inline int mm2dpCharonFlatHp()
    { return 140; }

// The large black skiff holds 10
inline int mm2dpCharonSkiffHolds()
    { return 10; }

// His charge: a magic item, a silk bag of 100 pp, or two gems of 500+ gp
// value
inline int mm2dpCharonSilkBagPp()
    { return 100; }

// The gem-charge floor in gp
inline int mm2dpCharonGemValueGp()
    { return 500; }

// The long pole strikes 2-8 plus paralysis
inline int mm2dpCharonPoleDamageLo()
    { return 2; }

// The pole damage high end
inline int mm2dpCharonPoleDamageHi()
    { return 8; }

// The paralysis lasts 2-8 turns
inline int mm2dpCharonParalysisTurnsLo()
    { return 2; }

// The paralysis turn high end
inline int mm2dpCharonParalysisTurnsHi()
    { return 8; }

// Charon taps the Styx into a 16 hit dice water elemental
inline int mm2dpCharonStyxDice()
    { return 16; }

// The river-incarnation hits for 5-30 and the target saves or loses its
// memory
inline int mm2dpCharonStyxDamageLo()
    { return 5; }

// The river-incarnation damage high end
inline int mm2dpCharonStyxDamageHi()
    { return 30; }

// Charon summons 3-18 charonadaemons or 2-12 hydrodaemons
inline int mm2dpCharonSummonCharonadaemonLo()
    { return 3; }

// The charonadaemon count high end
inline int mm2dpCharonSummonCharonadaemonHi()
    { return 18; }

// The hydrodaemon summon low end
inline int mm2dpCharonSummonHydroLo()
    { return 2; }

// The hydrodaemon summon high end
inline int mm2dpCharonSummonHydroHi()
    { return 12; }

// They appear in 1-3 rounds
inline int mm2dpCharonAppearRoundsLo()
    { return 1; }

// The appearance round high end
inline int mm2dpCharonAppearRoundsHi()
    { return 3; }

// A Styx save reads as a forget spell cast by a 15th-level magic-user
inline int mm2dpCharonForgetCasterLevel()
    { return 15; }

// Charon's form may be destroyed but he is never truly slain (native to all 5
// lower planes)
inline bool mm2dpCharonNeverTrulySlain()
    { return true; }

// The form ceases to exist on that plane for a single day before returning
inline bool mm2dpCharonFormReturnsNextDay()
    { return true; }

// Charon may be summoned only on the banks of the Styx
inline bool mm2dpCharonBanksOnly()
    { return true; }

// ---- the charonadaemon pins (the R799 MM2 letter D part 1) ----

// The per-passenger charge: a magic item, a bag of 10 platinum coins, or 2
// gems of 50+ gp
inline int mm2dpCharonadaemonBoatFeePlatinum()
    { return 10; }

// The gem-charge floor in gp
inline int mm2dpCharonadaemonGemValueGp()
    { return 50; }

// A paid charonadaemon still betrays its summoners 15% of the time
inline int mm2dpCharonadaemonBetrayPct()
    { return 15; }

// The betrayal delivers to the incorrect place or plane 85% of the time
inline int mm2dpCharonadaemonWrongDestinationPct()
    { return 85; }

// The betrayal leads into an ambush of charonadaemons and hydrodaemons 15% of
// the time
inline int mm2dpCharonadaemonAmbushPct()
    { return 15; }

// The charonadaemon summons 1-6 hydrodaemons from the Styx
inline int mm2dpCharonadaemonSummonHydroLo()
    { return 1; }

// The hydrodaemon summon high end
inline int mm2dpCharonadaemonSummonHydroHi()
    { return 6; }

// If not paid it teleports itself and its craft away
inline bool mm2dpCharonadaemonTeleportsCraftAway()
    { return true; }

// The angered fiery-red eyes force a save vs. fear or flee in terror (as
// spell)
inline bool mm2dpCharonadaemonGlowingEyesFear()
    { return true; }

// They are telepathic and keep in contact with others of their race at all
// times
inline bool mm2dpCharonadaemonTelepathicRaceContact()
    { return true; }

// ---- the derghodaemon pins (the R799 MM2 letter D part 1) ----

// The round body has 5 arms and 3 legs
inline int mm2dpDerghoArmCount()
    { return 5; }

// The leg count
inline int mm2dpDerghoLegCount()
    { return 3; }

// The insect-like head rotates 360 degrees (move and change direction at
// will)
inline int mm2dpDerghoHeadRotation()
    { return 360; }

// The 4-clawed hands do 1-4 plus the strength bonus
inline int mm2dpDerghoClawDamage()
    { return 4; }

// The stone-giant strength adds 8 points
inline int mm2dpDerghoStrengthDamageBonus()
    { return 8; }

// Unarmed 60% of the time
inline int mm2dpDerghoUnarmedPct()
    { return 60; }

// A carried weapon is magical 20% of the time
inline int mm2dpDerghoWeaponMagicalPct()
    { return 20; }

// The weapon parry drops the armor class to -8 for that round against 1
// attacker
inline int mm2dpDerghoParryAc()
    { return -8; }

// The at-will darkness within 10 feet
inline int mm2dpDerghoDarknessRadiusFeet()
    { return 10; }

// The wand-strength fear within 20 feet
inline int mm2dpDerghoFearRadiusFeet()
    { return 20; }

// The sleep spell casts twice a day
inline int mm2dpDerghoSleepPerDay()
    { return 2; }

// The gizzard holds 0-3 gems of base 100 gp value
inline int mm2dpDerghoGizzardGemsLo()
    { return 0; }

// The gizzard gem count high end
inline int mm2dpDerghoGizzardGemsHi()
    { return 3; }

// The gizzard gem base value
inline int mm2dpDerghoGemBaseValueGp()
    { return 100; }

// After the first 2 claws hit the target is grabbed and the remaining attacks
// read +2
inline bool mm2dpDerghoGrabbedPlusTwo()
    { return true; }

// Extremely strong (as a stone giant) but extremely stupid
inline bool mm2dpDerghoStoneGiantStrength()
    { return true; }

// ---- the hydrodaemon pins (the R799 MM2 letter D part 1) ----

// Found in numbers 10-30 wherever the Styx appears in the Lower Planes
inline int mm2dpHydroSwimGroupLo()
    { return 10; }

// The swim-group high end
inline int mm2dpHydroSwimGroupHi()
    { return 30; }

// The flying-fish glide holds up to 1 turn
inline int mm2dpHydroGlideTurns()
    { return 1; }

// Airborne: 5 attacks (feet 1-4, hands 1-8, bite 1-10)
inline int mm2dpHydroAirborneAttacks()
    { return 5; }

// On the ground: 3 attacks
inline int mm2dpHydroGroundAttacks()
    { return 3; }

// Gates in another hydrodaemon with a 50% chance of success
inline int mm2dpHydroGateChancePct()
    { return 50; }

// On the Prime Material Plane it summons a water elemental of 12 hit dice
inline int mm2dpHydroWaterElementalDice()
    { return 12; }

// The % IN LAIR parenthetical: 90% if near the Styx (the block cell reads 5)
inline int mm2dpHydroLairNearStyxFloorPct()
    { return 90; }

// The only creatures known to swim in the Styx without losing their memories
inline bool mm2dpHydroOnlyStyxSwimmers()
    { return true; }

// The bite drains 1 life energy level from its victim
inline bool mm2dpHydroDrainsOneLevel()
    { return true; }

// Half damage from water-based attack forms, and none if the save is made
inline bool mm2dpHydroHalfWaterDamage()
    { return true; }

// ---- the oinodaemon pins (the R799 MM2 letter D part 1) ----

// Anthraxus carries 233 hit points (the flat-hp path - the hit-dice cell
// reads 0)
inline int mm2dpOinoFlatHp()
    { return 233; }

// The touch disease prevents healing and is fatal in 1 week
inline int mm2dpOinoDiseaseFatalWeeks()
    { return 1; }

// Gates in 1-3 daemons of his choice with an 85% chance of success
inline int mm2dpOinoGateChancePct()
    { return 85; }

// The gate daemon count low end
inline int mm2dpOinoGateDaemonsLo()
    { return 1; }

// The gate daemon count high end
inline int mm2dpOinoGateDaemonsHi()
    { return 3; }

// He performs the abilities as a 25th-level magic-user
inline int mm2dpOinoSpellLevel()
    { return 25; }

// All psionic disciplines at the 20th level of mastery
inline int mm2dpOinoPsionicMasteryLevel()
    { return 20; }

// His chief rivals: Bubonis, Cholerix, Typhus and Diptherius
inline int mm2dpOinoRivalCount()
    { return 4; }

// The oinodaemon bears the Staff of the Lower Planes (mass charm, beguilement
// as rod, geas, and grant another's wish)
inline bool mm2dpOinoStaffOfTheLowerPlanes()
    { return true; }

// The staff charm and beguilement operate even on other daemons,
// automatically overcoming their magic resistances
inline bool mm2dpOinoCharmBypassesDaemonMr()
    { return true; }

// The molecular arrangement turns lead to platinum
inline bool mm2dpOinoLeadToPlatinum()
    { return true; }

// The gaze transfixes 1 target per round until the daemonlord permits
inline bool mm2dpOinoTransfixesOnePerRound()
    { return true; }

// ---- the piscodaemon pins (the R799 MM2 letter D part 1) ----

// The tentacle venom is fatal in 6 rounds (save vs. poison; if saved, slowed
// for 6 rounds)
inline int mm2dpPiscoVenomFatalRounds()
    { return 6; }

// The slow duration on a successful save
inline int mm2dpPiscoSlowedRounds()
    { return 6; }

// Seized characters attack at -1 to hit
inline int mm2dpPiscoSeizedHitPenalty()
    { return 1; }

// Water-based attacks against it read -1 per damage die
inline int mm2dpPiscoWaterDiePenalty()
    { return 1; }

// The faceted eyes see around and behind so it cannot be surprised
inline bool mm2dpPiscoCannotBeSurprised()
    { return true; }

// If both claws hit the target is seized and drawn towards its maw
inline bool mm2dpPiscoSeizedDrawnToMaw()
    { return true; }

// Summoned to the Prime Material Plane as labor or guards, they conspire to
// overthrow and enslave their masters
inline bool mm2dpPiscoResentfulLabor()
    { return true; }

// ---- the ultrodaemon pins (the R799 MM2 letter D part 1) ----

// All spell-like abilities perform as if the ultrodaemon were a 15th-level
// spell-caster
inline int mm2dpUltroSpellLevel()
    { return 15; }

// The telekinese power moves 6000 gp weight
inline int mm2dpUltroTelekineseWeight()
    { return 6000; }

// The fire-opal gaze forces a save vs. spells or a fascinated stop (as from a
// hold person spell)
inline bool mm2dpUltroGazeFascinates()
    { return true; }

// Those saving will not see the ultrodaemon but someone loved or respected
inline bool mm2dpUltroSeersSeeLovedOne()
    { return true; }

// Once per day: wall of fire, inscribe symbols of persuasion, insanity or
// hopelessness, or create a blade barrier
inline bool mm2dpUltroOncePerDayPowers()
    { return true; }

// Some ultrodaemons have mastered the arts of summoning, even from the Prime
// Material Plane
inline bool mm2dpUltroSummonMastersExist()
    { return true; }

// ---- the yagnodaemon pins (the R799 MM2 letter D part 1) ----

// The tol-kendar polearm is 15 feet of steel topped by an inverted cone
inline int mm2dpYagnoTolKendarLengthFeet()
    { return 15; }

// The harpoon tip does 1-10 (+strength bonus) and 1-6 the next round as it is
// pulled out
inline int mm2dpYagnoTipDamageHi()
    { return 10; }

// The tip pull-out damage high end
inline int mm2dpYagnoTipPullDamageHi()
    { return 6; }

// The bladed sides do 1-8 (+strength bonus) and 2-16 pulled out
inline int mm2dpYagnoSideDamageHi()
    { return 8; }

// The side pull-out damage high end
inline int mm2dpYagnoSidePullDamageHi()
    { return 16; }

// A natural 20 knocks the opponent out for 2-12 rounds (save vs. paralysis)
inline int mm2dpYagnoKoRoundsLo()
    { return 2; }

// The knockout round high end
inline int mm2dpYagnoKoRoundsHi()
    { return 12; }

// The life-force feeding takes 5 melee rounds
inline int mm2dpYagnoFeedRounds()
    { return 5; }

// It devours 10-100% of the victim abilities before being sated
inline int mm2dpYagnoDevourPctLo()
    { return 10; }

// The devour percentage high end
inline int mm2dpYagnoDevourPctHi()
    { return 100; }

// Shocking grasp thrice daily for 1-8 + 13
inline int mm2dpYagnoShockingGraspPerDay()
    { return 3; }

// The shocking grasp strength addition
inline int mm2dpYagnoShockingGraspBonus()
    { return 13; }

// The giant arm inflicts damage as a storm giant (+12)
inline bool mm2dpYagnoStormGiantStrength()
    { return true; }

// The sturdy nature takes half-damage from all earth-based attacks
inline bool mm2dpYagnoHalfEarthDamage()
    { return true; }

// Only 1 of the 2 tol-kendar attacks per round
inline bool mm2dpYagnoOneAttackPerRound()
    { return true; }

// ---- the dao pins (the R799 MM2 letter D part 1) ----

// The dao perform at the 18th level of spell use
inline int mm2dpDaoSpellLevel()
    { return 18; }

// A dao carries 5000 gp weight without tiring
inline int mm2dpDaoCarryGp()
    { return 5000; }

// After tiring a dao must rest for 6 turns
inline int mm2dpDaoRestTurns()
    { return 6; }

// Turn rock to mud 3 times per day
inline int mm2dpDaoTurnRockToMudPerDay()
    { return 3; }

// Dig as often as 6 times per day
inline int mm2dpDaoDigPerDay()
    { return 6; }

// The earth moves as if at a burrowing speed of 6 inches
inline int mm2dpDaoBurrowInches()
    { return 6; }

// The dao is a creature from the Elemental Plane of Earth (the def plane
// field; related to the efreeti, djinni, jann and marid)
inline bool mm2dpDaoPlaneOfEarth()
    { return true; }

// They move through earth (not worked stone) and cannot take living beings
// with them
inline bool mm2dpDaoMovesThroughEarth()
    { return true; }

// Not harmed by earth-based or affecting spells
inline bool mm2dpDaoEarthSpellsNoHarm()
    { return true; }

// Holy water has double normal effects upon them
inline bool mm2dpDaoHolyWaterDouble()
    { return true; }

// For every 1000 gp under 10,000 add 1 turn to the carrying duration (a 6000
// gp weight allows 8 turns)
inline bool mm2dpDaoSixThousandEightTurns()
    { return true; }

// Only the efreet are friendly towards dao; they hate djinn, jannee and
// marids
inline bool mm2dpDaoHatesDjinn()
    { return true; }

// ---- the crimson death pins (the R799 MM2 letter D part 1) ----

// After feeding the substance lasts 6 turns (armor class 4, +1 or better
// weapons)
inline int mm2dpCrimsonFeedTurns()
    { return 6; }

// Until fed it surprises prey 5 in 6 (1d6: 1-5 equals surprise)
inline int mm2dpCrimsonSurpriseDie()
    { return 6; }

// The surprise die low end
inline int mm2dpCrimsonSurpriseHitLo()
    { return 1; }

// The surprise die high end
inline int mm2dpCrimsonSurpriseHitHi()
    { return 5; }

// Dwells only in bogs and marshy places where chill and damp prevail
inline bool mm2dpCrimsonBogDweller()
    { return true; }

// The insubstantial form: armor class 0, hit only by +2 or better magic
// weapons until fed
inline bool mm2dpCrimsonHitOnlyByPlusTwo()
    { return true; }

// It surrounds the victim with vaporous tentacles and drains all body fluids
// - then flushes crimson
inline bool mm2dpCrimsonDrainsBodyFluids()
    { return true; }

// The den collects valuable items from victims as later bribe or lure
inline bool mm2dpCrimsonDenHoardsLures()
    { return true; }

// ---- the demilich pins (the R799 MM2 letter D part 1) ----

// A demilich's skull takes 50 hit points before it is destroyed
inline int mm2dpDemilichSkullHp()
    { return 50; }

// And it is armor class -6 (the def carries the bare -6; the block prints -6
// and special)
inline int mm2dpDemilichSkullAc()
    { return -6; }

// Each skull has 5-8 gems set in the eye sockets and in place of teeth
inline int mm2dpDemilichGemsLo()
    { return 5; }

// The gem count high end
inline int mm2dpDemilichGemsHi()
    { return 8; }

// The howl equals a death ray for a 20-foot radius
inline int mm2dpDemilichHowlRadiusFeet()
    { return 20; }

// A shatter spell inflicts 3-18 points of damage on the skull
inline int mm2dpDemilichShatterDamageLo()
    { return 3; }

// The shatter damage high end
inline int mm2dpDemilichShatterDamageHi()
    { return 18; }

// A dispel evil spell inflicts 5-8 points of damage
inline int mm2dpDemilichDispelEvilDamageLo()
    { return 5; }

// The dispel evil damage high end
inline int mm2dpDemilichDispelEvilDamageHi()
    { return 8; }

// A holy word inflicts 5-30 points of damage
inline int mm2dpDemilichHolyWordDamageLo()
    { return 5; }

// The holy word damage high end
inline int mm2dpDemilichHolyWordDamageHi()
    { return 30; }

// A +4 or better weapon or a mace of disruption inflicts 1 point per strike
inline int mm2dpDemilichPlusFourWeaponDamage()
    { return 1; }

// The dust must be destroyed by holy water or the creature re-forms over 1-10
// days
inline int mm2dpDemilichReformDaysLo()
    { return 1; }

// The re-form day high end
inline int mm2dpDemilichReformDaysHi()
    { return 10; }

// A trapped soul frees only if some material body waits within a 10-foot
// distance
inline int mm2dpDemilichSoulFreeDistanceFeet()
    { return 10; }

// The howl forces a save vs. spell or be permanently slain and forever dead
inline bool mm2dpDemilichHowlPermanentlySlays()
    { return true; }

// The soul-draining gem attack is irresistible - no saving throw is possible
inline bool mm2dpDemilichGemDrainIrresistible()
    { return true; }

// An amulet of life protection prevails over the lifestealing powers of a gem
inline bool mm2dpDemilichAmuletPrevails()
    { return true; }

// A power word kill pronounced from an astral or ethereal magic-user destroys
// the skull
inline bool mm2dpDemilichPowerWordKillDestroys()
    { return true; }

// The touch of the skull may first raise a wraith or ghost manifestation
inline bool mm2dpDemilichWraithOrGhostManifests()
    { return true; }

// ---- the farastu pins (the R799 MM2 letter D part 1) ----

// The tar-like skin excretions: anything it hits or that hits it sticks 5% of
// the time for 1-6 segments
inline int mm2dpFarastuStickChancePct()
    { return 5; }

// The stick segment low end
inline int mm2dpFarastuStickSegmentsLo()
    { return 1; }

// The stick segment high end
inline int mm2dpFarastuStickSegmentsHi()
    { return 6; }

// A stuck weapon is pulled from the grasp 25% of the time
inline int mm2dpFarastuStuckWeaponPullPct()
    { return 25; }

// The farastu employs spell-like powers at the 11th level
inline int mm2dpFarastuSpellLevel()
    { return 11; }

// It summons 1-2 fellow tarry demodands (40% success, on the Planes of
// Tarterus only)
inline int mm2dpFarastuSummonLo()
    { return 1; }

// The summon count high end
inline int mm2dpFarastuSummonHi()
    { return 2; }

// The summon success chance
inline int mm2dpFarastuSummonSuccessPct()
    { return 40; }

// Effective strength 19
inline int mm2dpFarastuStrength()
    { return 19; }

// Weight about 420 pounds - the commoners of Tarterus
inline int mm2dpFarastuWeightPounds()
    { return 420; }

// Harmed only by +1 or better magic weapons
inline bool mm2dpFarastuPlusOneToHit()
    { return true; }

// Acid or poison has no effect; cold or fire cause only half normal damage
inline bool mm2dpFarastuAcidPoisonNoEffect()
    { return true; }

// Fear magic is virtually unknown to it and illusion magic is useless
inline bool mm2dpFarastuFearIllusionUseless()
    { return true; }

// Both infra- and ultravisual sight
inline bool mm2dpFarastuInfraAndUltra()
    { return true; }

// ---- the kelubar pins (the R799 MM2 letter D part 1) ----

// Any hit causes 1-6 additional acid points unless the victim saves vs.
// poison
inline int mm2dpKelubarAcidDamageLo()
    { return 1; }

// The acid damage high end
inline int mm2dpKelubarAcidDamageHi()
    { return 6; }

// A full grapple (all 3 attacks hit) enslimes for 4-24 more:
// 2-8/2-8/4-16/4-24
inline int mm2dpKelubarGrappleDamageLo()
    { return 4; }

// The grapple acid damage high end
inline int mm2dpKelubarGrappleDamageHi()
    { return 24; }

// The kelubar employs spell-like powers at the 13th level
inline int mm2dpKelubarSpellLevel()
    { return 13; }

// It summons 1-2 of its fellows (50% success, cap 10)
inline int mm2dpKelubarSummonLo()
    { return 1; }

// The summon count high end
inline int mm2dpKelubarSummonHi()
    { return 2; }

// The summon success chance
inline int mm2dpKelubarSummonSuccessPct()
    { return 50; }

// Effective strength 20
inline int mm2dpKelubarStrength()
    { return 20; }

// Weight about 490 pounds - the middle class of Tarterus
inline int mm2dpKelubarWeightPounds()
    { return 490; }

// Infravision to 120 feet and standard ultravision
inline int mm2dpKelubarInfravisionFeet()
    { return 120; }

// If all 3 attacks per round are successful the kelubar has grappled the
// victim and enslimed it
inline bool mm2dpKelubarThreeHitsGrapple()
    { return true; }

// A saving throw reduces the acid damage by 50%
inline bool mm2dpKelubarSaveHalvesAcid()
    { return true; }

// Only +2 or better magic weapons will harm it
inline bool mm2dpKelubarPlusTwoToHit()
    { return true; }

// ---- the shator pins (the R799 MM2 letter D part 1) ----

// A wielded large weapon strikes at +4 on the to-hit roll
inline int mm2dpShatorWeaponToHitBonus()
    { return 4; }

// The print reads +9 on strength bonus (the settled read; the capture +8 was
// an OCR misread) - consistent with the giant strength ladder 21 -> +9
inline int mm2dpShatorWeaponStrengthBonusPrint()
    { return 9; }

// Only 1 attack per round is then possible
inline int mm2dpShatorWeaponAttackRate()
    { return 1; }

// The shator employs spell-like powers at the 15th level
inline int mm2dpShatorSpellLevel()
    { return 15; }

// It summons 1-8 of its fellows (60% success)
inline int mm2dpShatorSummonLo()
    { return 1; }

// The summon count high end
inline int mm2dpShatorSummonHi()
    { return 8; }

// The summon success chance
inline int mm2dpShatorSummonSuccessPct()
    { return 60; }

// The overlapping hide puts edged weapons at -1 to hit and damage
inline int mm2dpShatorEdgedWeaponPenalty()
    { return 1; }

// Using all senses they can be surprised only 10% of the time
inline int mm2dpShatorSurprisePct()
    { return 10; }

// Effective strength 21
inline int mm2dpShatorStrength()
    { return 21; }

// Weight around 560 pounds - the ruling nobility of Tarterus
inline int mm2dpShatorWeightPounds()
    { return 560; }

// Six-feet tall, squat and broad
inline int mm2dpShatorHeightFeet()
    { return 6; }

// Only +3 or better magic weapons will harm it
inline bool mm2dpShatorPlusThreeToHit()
    { return true; }

// The edged-weapon penalty covers long, broad, bastard and 2-handed swords;
// short swords are excluded
inline bool mm2dpShatorShortSwordsExcluded()
    { return true; }

// Acid or poison has no effect; cold or fire cause only half damage
inline bool mm2dpShatorAcidPoisonNoEffect()
    { return true; }

// ---- the alu-demon pins (the R799 MM2 letter D part 1) ----

// Base armor class 5 (the demonic heritage; the def block prints Base 5)
inline int mm2dpAluBaseAc()
    { return 5; }

// A +1 plate mail would increase armor class to 2 (full benefit over the
// intrinsic protection)
inline int mm2dpAluPlateMailAc()
    { return 2; }

// Twenty-five percent of alu-demons are of genius level (actual magic-users)
inline int mm2dpAluGeniusPct()
    { return 25; }

// Magic use level ranges 1st through 12th with equal probabilities
inline int mm2dpAluMagicLevelMax()
    { return 12; }

// The intrinsic powers (charm person, ESP, shape change, suggestion) 3 times
// per day
inline int mm2dpAluIntrinsicPerDay()
    { return 3; }

// Each intrinsic power performs at the 12th level of ability
inline int mm2dpAluPowerLevel()
    { return 12; }

// Superior infravision for 240 feet
inline int mm2dpAluInfravisionFeet()
    { return 240; }

// The firm-touch drain takes 1-8 hit points of energy
inline int mm2dpAluDrainHpLo()
    { return 1; }

// The drain high end
inline int mm2dpAluDrainHpHi()
    { return 8; }

// Energy gained is 1-4 hit points (half of the drain, fractions rounded up)
inline int mm2dpAluGainHpHi()
    { return 4; }

// Some 20% are not totally devoted to Evil
inline int mm2dpAluNotDevotedPct()
    { return 20; }

// The offspring of succubi and humans, always female
inline bool mm2dpAluAlwaysFemale()
    { return true; }

// At will they drain life energy and use half of it to restore their own lost
// hit points
inline bool mm2dpAluDoublesWeaponDrain()
    { return true; }

// Harmed only by cold-wrought iron or magic weapons
inline bool mm2dpAluColdIronOrMagic()
    { return true; }

// ---- the babau pins (the R799 MM2 letter D part 1) ----

// Strength 19, used to the fullest
inline int mm2dpBabauStrength()
    { return 19; }

// Cold-wrought iron inflicts +2 points per hit in addition to normal damage
inline int mm2dpBabauColdIronBonus()
    { return 2; }

// The darkness covers a 5-foot radius
inline int mm2dpBabauDarknessRadiusFeet()
    { return 5; }

// Abilities equal to a 9th-level thief
inline int mm2dpBabauThiefLevel()
    { return 9; }

// Gates in another babau demon (25% chance of success)
inline int mm2dpBabauGateChancePct()
    { return 25; }

// The enfeeblement-gaze range is 20 feet
inline int mm2dpBabauGazeRangeFeet()
    { return 20; }

// Levitate as a 10th-level magic-user
inline int mm2dpBabauLevitateLevel()
    { return 10; }

// Fly as an 11th-level magic-user
inline int mm2dpBabauFlyLevel()
    { return 11; }

// Dispel magic as a 12th-level magic-user
inline int mm2dpBabauDispelLevel()
    { return 12; }

// Heat metal as a 14th-level druid
inline int mm2dpBabauHeatMetalLevel()
    { return 14; }

// The reddish body slime makes cutting, stabbing and similar attacks do only
// half normal damage
inline bool mm2dpBabauSlimeHalvesDamage()
    { return true; }

// The glowing red eyes force a save vs. spell or a ray of enfeeblement effect
inline bool mm2dpBabauGazeEnfeebles()
    { return true; }

// The preferred attack is to leap upon victims from above
inline bool mm2dpBabauLeapsFromAbove()
    { return true; }

// ---- the baphomet pins (the R799 MM2 letter D part 1) ----

// The huge bardiche does 11-20 (3d4+8) points of damage
inline int mm2dpBaphometBardicheDamageLo()
    { return 11; }

// The bardiche damage high end
inline int mm2dpBaphometBardicheDamageHi()
    { return 20; }

// The 3d4+8 dice bonus
inline int mm2dpBaphometBardicheDiceBonus()
    { return 8; }

// 75% likely to have 2-5 minotaurs with him
inline int mm2dpBaphometRetinuePct()
    { return 75; }

// The retinue count low end
inline int mm2dpBaphometRetinueLo()
    { return 2; }

// The retinue count high end
inline int mm2dpBaphometRetinueHi()
    { return 5; }

// He summons 5-8 additional minotaurs, possibly in a single round, once per
// day
inline int mm2dpBaphometSummonLo()
    { return 5; }

// The summon count high end
inline int mm2dpBaphometSummonHi()
    { return 8; }

// The bellow carries within 30 inches: save vs. spell or flee in panic for 6
// rounds
inline int mm2dpBaphometBellowRadiusInches()
    { return 30; }

// The panic duration
inline int mm2dpBaphometBellowFleeRounds()
    { return 6; }

// Gates in a Type III demon (85% chance) once per day
inline int mm2dpBaphometGateChancePct()
    { return 85; }

// Telekinese 75,000 gp weight
inline int mm2dpBaphometTelekineseWeight()
    { return 75000; }

// The unholy-water gout 6 times per day (1 quart per gout, range 1 inch)
inline int mm2dpBaphometUnholyWaterPerDay()
    { return 6; }

// Damage to creatures of the Upper or Positive Planes: 16-64 points
inline int mm2dpBaphometUpperPlaneDamageLo()
    { return 16; }

// The unholy water damage high end
inline int mm2dpBaphometUpperPlaneDamageHi()
    { return 64; }

// Baphomet is lord of minotaurs, warring against Yeenoghu
inline bool mm2dpBaphometLordOfMinotaurs()
    { return true; }

// Infravision to 120 feet and hearing double human norm
inline bool mm2dpBaphometHearingDouble()
    { return true; }

// ---- the bar-lgura pins (the R799 MM2 letter D part 1) ----

// A bar-lgura can spring from all fours and cover 40 feet
inline int mm2dpBarLguraSpringFeet()
    { return 40; }

// Hands and feet have 6 digits with exceptionally long claws
inline int mm2dpBarLguraDigitCount()
    { return 6; }

// Telekinese 2500 gp weight
inline int mm2dpBarLguraTelekineseWeight()
    { return 2500; }

// Create water as a 6th-level cleric
inline int mm2dpBarLguraCreateWaterLevel()
    { return 6; }

// If severely threatened, 25% chance to gate in another of its kind
inline int mm2dpBarLguraGateChancePct()
    { return 25; }

// A coloration change requires 1 round
inline int mm2dpBarLguraTransformationRounds()
    { return 1; }

// Seven hues: black, brown, gray, green, orange, purple or red
inline int mm2dpBarLguraColorHues()
    { return 7; }

// Normal weapons have full effect upon this type of demon
inline bool mm2dpBarLguraNormalWeaponsFull()
    { return true; }

// Twice per day: change self, invisibility and spectral force
inline bool mm2dpBarLguraTwicePerDayPowers()
    { return true; }

// They prefer to hunt and terrorize with their own fellows only
inline bool mm2dpBarLguraShunsOtherDemons()
    { return true; }

// Where arms and legs both serve it moves far more rapidly
inline bool mm2dpBarLguraMovesFastClimbing()
    { return true; }

// ---- the cambion pins (the R799 MM2 letter D part 1) ----

// Hit dice cannot exceed the predetermined maximum of 5-8 (1d4+4)
inline int mm2dpCambionHdCapLo()
    { return 5; }

// The hit-dice cap high end
inline int mm2dpCambionHdCapHi()
    { return 8; }

// The 1d4+4 dice bonus
inline int mm2dpCambionHdCapBonus()
    { return 4; }

// Major cambions of intelligence above 14 follow magic use to a maximum of
// 5th-level ability
inline int mm2dpCambionMagicLevelMax()
    { return 5; }

// Baron or marquis cambions have 1-4 of the listed abilities (cause fear by
// touch, detect magic, levitate, polymorph self)
inline int mm2dpCambionBaronAbilitiesLo()
    { return 1; }

// The baron ability count high end
inline int mm2dpCambionBaronAbilitiesHi()
    { return 4; }

// Baron or marquis fighter ability runs 9th-16th level (equal to their hit
// dice)
inline int mm2dpCambionFighterLo()
    { return 9; }

// The fighter level high end
inline int mm2dpCambionFighterHi()
    { return 16; }

// The offspring of a human female and a demon is always a cambion male
inline bool mm2dpCambionAlwaysMale()
    { return true; }

// Base armor class is either 6 or 2, rather than the normal 10, depending on
// heritage
inline bool mm2dpCambionBaseAcSixOrTwo()
    { return true; }

// All cambions have infravision and can speak with demons
inline bool mm2dpCambionInfravisionDemonSpeech()
    { return true; }

// Subject to iron as normal demons and unharmed by silver
inline bool mm2dpCambionIronYesSilverNo()
    { return true; }

// Baron or marquis with wisdom greater than 9 can become evil clerics of as
// high a level as their total hit dice
inline bool mm2dpCambionClericIfWisdomNine()
    { return true; }

// Each profession must be followed in turn - simultaneous practice is not
// possible
inline bool mm2dpCambionOneProfessionAtATime()
    { return true; }

// ---- the chasme pins (the R799 MM2 letter D part 1) ----

// The drone chance is 100% minus 10% per level or hit die of each opponent
inline int mm2dpChasmeDroneBasePct()
    { return 100; }

// The per-level decrement
inline int mm2dpChasmeDronePerLevelPct()
    { return 10; }

// The comatose sleep persists for 2-8 hours
inline int mm2dpChasmeSleepHoursLo()
    { return 2; }

// The sleep hour high end
inline int mm2dpChasmeSleepHoursHi()
    { return 8; }

// The sleeping victim is drained for 1-4 points of blood damage
inline int mm2dpChasmeBloodDrainLo()
    { return 1; }

// The blood drain high end
inline int mm2dpChasmeBloodDrainHi()
    { return 4; }

// Gates in another of its kind (15% chance of success)
inline int mm2dpChasmeGateChancePct()
    { return 15; }

// Telekinese 1500 gp weight
inline int mm2dpChasmeTelekineseWeight()
    { return 1500; }

// Like flies they walk on walls and ceilings
inline bool mm2dpChasmeWalksWallsCeilings()
    { return true; }

// Struck by normal weapons, but poison does not affect them
inline bool mm2dpChasmePoisonImmune()
    { return true; }

// The touch causes fear as a wand
inline bool mm2dpChasmeTouchFearAsWand()
    { return true; }

// Rutterkin are allied with chasme, although chasme are not fond of them and
// use them
inline bool mm2dpChasmeUsesRutterkin()
    { return true; }

// ---- the dretch pins (the R799 MM2 letter D part 1) ----

// A dretch gates in a Type I demon (5% chance of success)
inline int mm2dpDretchGateChancePct()
    { return 5; }

// The at-will darkness covers a 5-foot radius
inline int mm2dpDretchDarknessRadiusFeet()
    { return 5; }

// Telekinese 500 gp weight
inline int mm2dpDretchTelekineseWeight()
    { return 500; }

// Stinking cloud once per day
inline int mm2dpDretchStinkingCloudPerDay()
    { return 1; }

// Teleport once per day
inline int mm2dpDretchTeleportPerDay()
    { return 1; }

// The most common and least powerful of all demons - scarcely a match for a
// quasit on equal terms
inline bool mm2dpDretchCommonestDemons()
    { return true; }

// Normal attack mode is a bite and 2 clawing attacks
inline bool mm2dpDretchBiteAndTwoClaws()
    { return true; }

// ---- the fraz-urb'luu pins (the R799 MM2 letter D part 1) ----

// Fraz-Urb'luu carries 233 hit points (the flat-hp path - the hit-dice cell
// reads 0)
inline int mm2dpFrazFlatHp()
    { return 233; }

// Each fist delivers 13-18 points of damage
inline int mm2dpFrazFistDamageLo()
    { return 13; }

// The fist damage high end
inline int mm2dpFrazFistDamageHi()
    { return 18; }

// The bite does 3-18 to an opponent he is holding
inline int mm2dpFrazBiteDamageHi()
    { return 18; }

// The 15-foot razor-barbed tail
inline int mm2dpFrazTailLengthFeet()
    { return 15; }

// The tail slashes for 1-12
inline int mm2dpFrazTailDamageHi()
    { return 12; }

// The spell-like powers at the 20th level
inline int mm2dpFrazSpellLevel()
    { return 20; }

// Telekinese 10,000 gp weight
inline int mm2dpFrazTelekineseWeight()
    { return 10000; }

// Gates in 1-4 Type I demons (60% success)
inline int mm2dpFrazGateTypeILo()
    { return 1; }

// The gate count high end
inline int mm2dpFrazGateTypeIHi()
    { return 4; }

// 75% likely to deceive another demon prince rather than gating the lesser
// demons
inline int mm2dpFrazDeceivePct()
    { return 75; }

// The Type I gate success chance
inline int mm2dpFrazGateSuccessPct()
    { return 60; }

// 75% likely to cause another of the greatest demons to appear
inline int mm2dpFrazTrickPrincePct()
    { return 75; }

// 85% probable that the nearby creatures suffer in the fury
inline int mm2dpFrazFuryPct()
    { return 85; }

// In addition to being 70% resistant to magic
inline int mm2dpFrazMagicResistPct()
    { return 70; }

// It seems 90% certain that magic items other than artifacts or relics are
// spoiled on his plane
inline int mm2dpFrazSpoilPct()
    { return 90; }

// Completely resistant to spells which detect or influence (charm, command,
// dominate, hypnotize, suggest, etc.)
inline bool mm2dpFrazDeceptionImmune()
    { return true; }

// His abyssal plane is alive to his wishes and shapes itself accordingly
inline bool mm2dpFrazPlaneAliveToWishes()
    { return true; }

// He searches for his staff (a staff of command, a rod of beguiling and a rod
// of rulership combined) - stolen during his imprisonment under Castle
// Greyhawk
inline bool mm2dpFrazSearchingForHisStaff()
    { return true; }

// ---- the graz'zt pins (the R799 MM2 letter D part 1) ----

// Graz'zt carries 186 hit points (the flat-hp path - the hit-dice cell reads
// 0)
inline int mm2dpGrazztFlatHp()
    { return 186; }

// With 2 weapons instead of the shield he goes from armor class -9 to -6
inline int mm2dpGrazztTwoWeaponAc()
    { return -6; }

// The normal kit: a huge +3 shield and a huge wavy-bladed sword
inline int mm2dpGrazztShieldPlus()
    { return 3; }

// The sword drips acid on command for an additional 5-8 points of damage
inline int mm2dpGrazztAcidDamageLo()
    { return 5; }

// The acid damage high end
inline int mm2dpGrazztAcidDamageHi()
    { return 8; }

// The magic missile throws 5 missiles
inline int mm2dpGrazztMissileCount()
    { return 5; }

// By sneer and word he engenders fear within a 60-foot range
inline int mm2dpGrazztFearRangeFeet()
    { return 60; }

// Gates in 1-2 Type VI demons (60%) without fail
inline int mm2dpGrazztTypeVIGatePct()
    { return 60; }

// Or 2-5 babau demons (40%) without fail
inline int mm2dpGrazztBabauGatePct()
    { return 40; }

// Served by Iamias: always 1-3 with him
inline int mm2dpGrazztIamiasLo()
    { return 1; }

// The Iamias count high end
inline int mm2dpGrazztIamiasHi()
    { return 3; }

// Telekinese 15,000 gp weight
inline int mm2dpGrazztTelekineseWeight()
    { return 15000; }

// The spell-like powers at the 20th level
inline int mm2dpGrazztSpellLevel()
    { return 20; }

// He battled free at the cost of being confined to his own plane for a
// century
inline int mm2dpGrazztExileYears()
    { return 100; }

// Graz'zt rules an entire layer of the Abyss, dedicated foe of Demogorgon and
// Orcus
inline bool mm2dpGrazztLordOfALayer()
    { return true; }

// The normal attacks double if he employs 2 weapons in lieu of the shield
inline bool mm2dpGrazztDoublesAttacks()
    { return true; }

// Trap the soul once per week; disintegrate and polymorph any object once per
// day
inline bool mm2dpGrazztTrapSoulOncePerWeek()
    { return true; }

// Graz'zt is 6-fingered and 6-toed
inline bool mm2dpGrazztSixFingered()
    { return true; }

// ---- the kostchtchie pins (the R799 MM2 letter D part 1) ----

// Kostchtchie carries 96 hit points (the flat-hp path - the hit-dice cell
// reads 0)
inline int mm2dpKostFlatHp()
    { return 96; }

// The cold-iron hammer does 2-12 points of damage, with nickel and silver
// inlays
inline int mm2dpKostHammerDamageHi()
    { return 12; }

// A pair of largest-size leucrotta serve as constant guards (AC 3, 2 x 49 hp,
// rear kicks 2-7 each)
inline int mm2dpKostLeucrottaGuards()
    { return 2; }

// The leucrotta guard armor class
inline int mm2dpKostLeucrottaAc()
    { return 3; }

// Each leucrotta hit points (2x49)
inline int mm2dpKostLeucrottaHp()
    { return 49; }

// The leucrotta rear kicks do 2-7 each
inline int mm2dpKostRearKickDamageLo()
    { return 2; }

// The rear kick damage high end
inline int mm2dpKostRearKickDamageHi()
    { return 7; }

// The spell-like powers at the 20th level
inline int mm2dpKostSpellLevel()
    { return 20; }

// Telekinese 5000 gp weight
inline int mm2dpKostTelekineseWeight()
    { return 5000; }

// Always gates in 1-4 babau demons (35%) or 2-5 bar-lgura (65%)
inline int mm2dpKostBabauGatePct()
    { return 35; }

// The bar-lgura gate chance
inline int mm2dpKostBarLguraGatePct()
    { return 65; }

// Poison twice per day; harm, unholy word once; wind walk twice
inline int mm2dpKostPoisonPerDay()
    { return 2; }

// A hammer hit forces a save vs. paralysis or the victim is stunned for the
// balance of that round and all of the next
inline bool mm2dpKostHammerStuns()
    { return true; }

// So hateful that he is disliked even by the rest of his kind, save the minor
// sorts
inline bool mm2dpKostDislikedByAll()
    { return true; }

// At times he is served by frost giants; a white dragon of ancient age is
// rumored as his steed
inline bool mm2dpKostFrostGiantServants()
    { return true; }

// ---- the nabassu pins (the R799 MM2 letter D part 1) ----

// After slaying and eating 18 humans a nabassu reaches full growth
inline int mm2dpNabassuHumansToMature()
    { return 18; }

// The demonlings arrive with only armor class 4 and 5 hit dice
inline int mm2dpNabassuDemonlingAc()
    { return 4; }

// The demonling hit dice
inline int mm2dpNabassuDemonlingHd()
    { return 5; }

// The probability-travel passage gives 2 additional hit points of growth
inline int mm2dpNabassuTravelBonusHp()
    { return 2; }

// After 2 devoured humans: +4 hit points and armor class 3
inline int mm2dpNabassuTwoHumansAc()
    { return 3; }

// The immature cause shadows within a 20-foot radius; the darkness covers 5
// feet
inline int mm2dpNabassuCauseShadowsRadiusFeet()
    { return 20; }

// The death-stealing gaze range is 2 inches; the bestowing range 1 inch
inline int mm2dpNabassuStealRangeInches()
    { return 2; }

// The bestowal range
inline int mm2dpNabassuBestowRangeInches()
    { return 1; }

// At maturity: summon 2-5 ghasts once per day on the Abyssal Planes
inline int mm2dpNabassuMatureGhastSummonLo()
    { return 2; }

// The ghast summon count high end
inline int mm2dpNabassuMatureGhastSummonHi()
    { return 5; }

// Regenerate up to 20 hit points per day
inline int mm2dpNabassuRegenPerDay()
    { return 20; }

// Paralyzation within a 10-foot radius once per day
inline int mm2dpNabassuParalysisRadiusFeet()
    { return 10; }

// An effective strength of 18/00 (the 1800 encoding pins the 18/00)
inline int mm2dpNabassuStrength()
    { return 1800; }

// The death-stealing gaze forces a save vs. death magic or the victim becomes
// a ghast (or a ghoul if demihuman) - and the bestowal kills instantly,
// leaving a shadow
inline bool mm2dpNabassuGhastOrGhoulVictim()
    { return true; }

// Thief-like abilities at half the hit-point bonus, measured as thief level
inline bool mm2dpNabassuThiefAbilities()
    { return true; }

// Harmed only by iron or +1 or better magic weapons
inline bool mm2dpNabassuIronOrPlusOne()
    { return true; }

// The inborn psionic probability travel carries others along, though nabassu
// have no other psionic ability
inline bool mm2dpNabassuProbabilityTravelInborn()
    { return true; }

// ---- the pazuzu pins (the R799 MM2 letter D part 1) ----

// Pazuzu carries 155 hit points (the flat-hp path - the hit-dice cell reads
// 0)
inline int mm2dpPazuzuFlatHp()
    { return 155; }

// The turn starts by speaking his name aloud 3 times in succession
inline int mm2dpPazuzuNameTimes()
    { return 3; }

// Evil flying creatures of under 5 hit dice obey his every command within
// sight
inline int mm2dpPazuzuObedienceHdLimit()
    { return 5; }

// The breath weapon 3 times per day: creeping doom, insect plague or poison
// gas (green-dragon size)
inline int mm2dpPazuzuBreathPerDay()
    { return 3; }

// The typical bodyguard: 6 Type VI demons (not those of MONSTER MANUAL I)
inline int mm2dpPazuzuBodyguardCount()
    { return 6; }

// Summons 4-16 harpies (50%), 3-12 perytons (25%) or 3-12 gargoyles (25%)
// with 90% probability
inline int mm2dpPazuzuHarpySummonLo()
    { return 4; }

// The harpy count high end
inline int mm2dpPazuzuHarpySummonHi()
    { return 16; }

// The summon probability
inline int mm2dpPazuzuSummonPct()
    { return 90; }

// Gates in 1-4 succubi with 75% probability once per day
inline int mm2dpPazuzuSuccubusGateLo()
    { return 1; }

// The succubus gate count high end
inline int mm2dpPazuzuSuccubusGateHi()
    { return 4; }

// The succubus gate probability
inline int mm2dpPazuzuSuccubusGatePct()
    { return 75; }

// Regenerates 1 hit point per round
inline int mm2dpPazuzuRegenPerRound()
    { return 1; }

// Lord of all evil flying creatures, ruling the skies above all the layers
inline bool mm2dpPazuzuRulesTheSkies()
    { return true; }

// Able to enter the Prime Material Plane at will (own power or secret
// artifact - under question)
inline bool mm2dpPazuzuEntersPrimeAtWill()
    { return true; }

// His especial joy is turning lawful good clerics and paladins to his service
inline bool mm2dpPazuzuTurnsClerics()
    { return true; }

// The at-will list includes wish once per day, unholy word and symbols of
// pain, hopelessness and death
inline bool mm2dpPazuzuWishOncePerDay()
    { return true; }

// The true form is a tall humanoid with 4 wings, taloned avian feet and
// glowing red eyes
inline bool mm2dpPazuzuFourWings()
    { return true; }

// ---- the rutterkin pins (the R799 MM2 letter D part 1) ----

// The snap-tongs inflict 2-8 and continue each round until the opponent
// breaks free
inline int mm2dpRutterkinSnapTongsDamageHi()
    { return 8; }

// The double-crescent polearm: S-M 1-10, L 1-12
inline int mm2dpRutterkinCrescentDamageLo()
    { return 10; }

// The L-size crescent damage high end
inline int mm2dpRutterkinCrescentDamageHi()
    { return 12; }

// The 3-armed blades thrown from an atlati-like device: S-M 3-8, L 3-6
inline int mm2dpRutterkinBladeDamageLo()
    { return 3; }

// The thrown-blade range
inline int mm2dpRutterkinBladeRangeInches()
    { return 15; }

// Telekinese 1000 gp weight
inline int mm2dpRutterkinTelekineseWeight()
    { return 1000; }

// Gates in chasmes (15% chance) - their only demon allies
inline int mm2dpRutterkinGateChasmePct()
    { return 15; }

// The saw-toothed flatchet is a broad sword +1 damage against unarmored
// opponents
inline bool mm2dpRutterkinFlatchetPlusOneVsUnarmored()
    { return true; }

// Hated and abused by most demons; they return the favor on a dretch, a lone
// vrock or a single hezrou
inline bool mm2dpRutterkinHatedAndAbused()
    { return true; }

// The at-will list carries teleport once per day
inline bool mm2dpRutterkinTeleportOncePerDay()
    { return true; }

// ---- the derro pins (the R799 MM2 letter D part 1) ----

// High dexterity 15-18, so armor class must be adjusted accordingly (the
// block See below cell)
inline int mm2dpDerroDexLo()
    { return 15; }

// The dexterity high end
inline int mm2dpDerroDexHi()
    { return 18; }

// The repeating light crossbow: 12-inch maximum range, 2 shots per round,
// 6-bolt capacity, 1-3 points
inline int mm2dpDerroCrossbowRangeInches()
    { return 12; }

// The crossbow rate
inline int mm2dpDerroCrossbowShotsPerRound()
    { return 2; }

// The bolt capacity
inline int mm2dpDerroCrossbowCapacity()
    { return 6; }

// The arrow poison adds 2-12 unless the save is made
inline int mm2dpDerroPoisonDamageLo()
    { return 2; }

// The poison damage high end
inline int mm2dpDerroPoisonDamageHi()
    { return 12; }

// The hook fauchard is 25% likely to pull a man-sized or smaller victim off
// balance
inline int mm2dpDerroFauchardPullPct()
    { return 25; }

// For every 3 derroes: 1 having 4 hit dice; every 6: 1 having 5 hit dice
inline int mm2dpDerroEvery3LeaderHd()
    { return 4; }

// The every-6 hit dice
inline int mm2dpDerroEvery6LeaderHd()
    { return 5; }

// 10 or more: a 7-hit dice leader and a 6-hit dice lieutenant (in addition to
// the initial number)
inline int mm2dpDerroTenLeaderHd()
    { return 7; }

// The lieutenant hit dice
inline int mm2dpDerroLieutenantHd()
    { return 6; }

// Savants have 5-8 hit dice; students 4-7
inline int mm2dpDerroSavantHdLo()
    { return 5; }

// The savant hit-dice high end
inline int mm2dpDerroSavantHdHi()
    { return 8; }

// The student hit-dice low end
inline int mm2dpDerroStudentHdLo()
    { return 4; }

// The student hit-dice high end
inline int mm2dpDerroStudentHdHi()
    { return 7; }

// Savants know 6-9 spells; students 1-3
inline int mm2dpDerroSavantSpellsLo()
    { return 6; }

// The savant spell count high end
inline int mm2dpDerroSavantSpellsHi()
    { return 9; }

// The student spell count low end
inline int mm2dpDerroStudentSpellsLo()
    { return 1; }

// The student spell count high end
inline int mm2dpDerroStudentSpellsHi()
    { return 3; }

// Performance is at the 12th level of ability
inline int mm2dpDerroSpellLevel()
    { return 12; }

// Students are only 25% likely to use a nonfighter magic item
inline int mm2dpDerroStudentItemPct()
    { return 25; }

// A lair holds 30 plus 3-12 normal derroes
inline int mm2dpDerroLairNormalLo()
    { return 30; }

// The normal-derro high end (30 plus the 3-12)
inline int mm2dpDerroLairNormalHi()
    { return 42; }

// 1-3 savants, 2-6 students
inline int mm2dpDerroLairSavantLo()
    { return 1; }

// The savant count high end
inline int mm2dpDerroLairSavantHi()
    { return 3; }

// 15-40 slaves (80% female), 1-3 gargoyles (70%) or a lamia (30%) as allies
inline int mm2dpDerroLairSlaveLo()
    { return 15; }

// The slave count high end
inline int mm2dpDerroLairSlaveHi()
    { return 40; }

// The slave female percentage
inline int mm2dpDerroSlaveFemalePct()
    { return 80; }

// Poor infravision (30 feet) but good ultravision (120 feet)
inline int mm2dpDerroInfravisionFeet()
    { return 30; }

// The savant list: affect normal fires, anti-magic shell, blink, light,
// lightning bolt, minor creation, charm person, cloudkill, ESP, hypnotic
// pattern, ice storm, invisibility, levitate, paralyzation, repulsion, shadow
// magic, spider climb, ventriloquism, wall of fog, wall of force
inline bool mm2dpDerroSavantSavantSpellList()
    { return true; }

// The derro hate light and suffer from nausea in sunlight; they raid the
// surface at night through secret shaft openings
inline bool mm2dpDerroSunlightNausea()
    { return true; }

// The 10-20% kits wear scaled leather equal to mail in protection
inline bool mm2dpDerroScaledLeather()
    { return true; }

// The aklys is half as effective as a hook fauchard in pulling opponents down
inline bool mm2dpDerroAklysHalfFauchard()
    { return true; }

}   // namespace rules
