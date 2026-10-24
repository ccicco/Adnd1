// =========================================================================================
// Adnd1 - rules/mm2df.h
// THE MM2 LETTER D PART 3 - the devil section (the DEVIL family pp. 44-49:
// the abishai five-form table and the Amon through spined devil stat blocks),
// promoted to the live registry
// census 723 -> 724.
//
// Round five of the MM2 arc, the third PART-LETTER walk (the user Go call on
// the landed deva turn: the letter D continues with the devil section pp.
// 44-49; the DIAKK turn and the rest of D await the user call). The capture
// is the Curtiss PDF upload cross-checked against an independent
// transcription and the archive.org djvu OCR, the contested cells settled:
// the Titivilus symbol prints 19 levels or hit dice or 99 hit points (the
// capture 98 is an OCR misread; the transcription and the djvu print 99); the
// Titivilus MOVE prints 15/30 MC:D (the djvu agrees; the transcription 12
// token is its own annotation); the Mephistopheles spell list prints
// rulership once per day - the print typo pins verbatim (the capture and the
// djvu agree); the abishai spell list prints command (the capture c-command
// is an OCR artifact); the nupperibo MAGIC RESISTANCE prints the word
// Standard (the grid reads 0, the charon Nil precedent applied to the word);
// the Stench Kow frequency column is a single column (the capture table-split
// introduced a phantom blank column; the djvu corroborates). The pin-time
// walk finds thirteen devil stat-block entries - the abishai table splits
// five ways (the aspis precedent) - so seventeen .lua defs ride the R791
// data_files extension, registry 566 -> 583. The stat blocks pin in the
// 17-row DevStats grid; the two Frequency of Devils and Others on Plane
// tables pin as 9x12 letter-code grids (the legend 0 absent, 1 VVR, 2 VR, 3
// R, 4 U, 5 C); the 61-line Hierarchy of the Planes of Hell roster and the
// devil-common doctrine (the lemure-status decades, the duke decade, the
// attack-form chart) pin as round-level doctrine. NO GAP FLIPS: the Letter D
// box flips only when all the D parts land (the R791 no-flip precedent). NO
// XP-AUDIT PATCH: mm2_print already rides the allowed-source list (the R797
// patch). The live def walk (the one file-patch site block, no census marker)
// cross-checks all 17 defs against the DevStats grid, the loader attack
// semantics, the nupperibo Standard word and the registry census 566 -> 583
// as a floor.
//
namespace rules {

// ---- the MM2 letter D part 3 round pins (the R801 census) ----

// The MM2 letter D part 3 round: the devil section walk (the user Go call on
// the landed deva turn)
inline int mm2dfRound()
    { return 801; }

// The pin-time walk from the print (pp. 44-49): thirteen devil stat-block
// entries - the abishai table counts once, the Amon through spined devil
// blocks follow
inline int mm2dfEntryCount()
    { return 13; }

// The abishai five-form table: black, blue, green, red and white (the aspis
// split precedent)
inline int mm2dfAbishaiFormCount()
    { return 5; }

// The def census: seventeen .lua defs ride the R791 data_files extension (the
// abishai splits five ways)
inline int mm2dfDefCount()
    { return 17; }

// The devil section opens on p. 44 (the DEVIL family head after the movanic
// deva prose tail)
inline int mm2dfFirstPage()
    { return 44; }

// The devil section closes on p. 49 (the spined devil entry; the DIAKK turn
// comes with the next D part)
inline int mm2dfLastPage()
    { return 49; }

// The live registry census at the landed deva turn (the R800 landing count)
inline int mm2dfRegistryBefore()
    { return 566; }

// The live registry census after the seventeen devil defs (566 + 17)
inline int mm2dfRegistryAfter()
    { return 583; }

// The 17-row devil stat grid: one row per promoted def in print order
inline int mm2dfDevStatRows()
    { return 17; }

// The Frequency of Devils on Plane table: nine rows, one per plane of Hell
inline int mm2dfDevilFreqRows()
    { return 9; }

// The Frequency of Others on Plane table: nine rows, one per plane of Hell
inline int mm2dfOthersFreqRows()
    { return 9; }

// The Hierarchy of the Planes of Hell roster: the 61-line dukes-and-henchmen
// table (no stat blocks ride the roster lines)
inline int mm2dfDukeRosterRows()
    { return 61; }

// The frequency-table legend cell: the dash - the type never appears on that
// plane
inline int mm2dfFreqCodeAbsent()
    { return 0; }

// The legend cell: very very rare
inline int mm2dfFreqCodeVvr()
    { return 1; }

// The legend cell: very rare
inline int mm2dfFreqCodeVr()
    { return 2; }

// The legend cell: rare
inline int mm2dfFreqCodeR()
    { return 3; }

// The legend cell: uncommon
inline int mm2dfFreqCodeU()
    { return 4; }

// The legend cell: common
inline int mm2dfFreqCodeC()
    { return 5; }

// ---- the devil doctrine pins (the R801 MM2 letter D part 3) ----

// A greater devil whose material form is destroyed is forced to lemure status
// for 9 decades of torment before resuming its former station
inline int mm2dfGreaterDevilLemureDecades()
    { return 9; }

// A duke whose material form is destroyed is bound to its own particular
// plane of Hell for a decade (unless again properly called prior to the end
// of the 10 years) and suffers a great loss of face
inline int mm2dfDukePlaneBoundYears()
    { return 10; }

// The inhabitants and rulers of the planes of Hell are principally devils,
// the most powerful of lawful evil creatures
inline bool mm2dfDevilsMostPowerfulLawfulEvil()
    { return true; }

// Devils follow a definite order or chain of command which they dare not
// break for fear of the arch-devils
inline bool mm2dfDevilsChainOfCommand()
    { return true; }

// While the lesser devils squabble and the dukes vie to usurp the throne, the
// archfiend has always succeeded in playing one against the other and still
// rules from his lowest plane
inline bool mm2dfAsmodeusPlaysOneAgainstOther()
    { return true; }

// All devils move about the planes of Hell (sans authorization only the
// dukes) and to Gehenna, Hades and Acheron at will; through the Astral seldom
inline bool mm2dfDevilsMoveAboutTheHells()
    { return true; }

// No devil enters other planes unless the proper ritual is performed, a gate
// is opened, or the proper name is spoken and heard
inline bool mm2dfDevilCannotEnterOtherPlanesUnaided()
    { return true; }

// The material form of a greater devil or duke can be destroyed, but they
// cannot actually be slain unless fought in Hell or the adjacent lower planes
inline bool mm2dfGreaterDevilNotSlainOutsideHell()
    { return true; }

// Devils can never be subdued; the lesser fight until destroyed, the greater
// negotiate if seriously threatened
inline bool mm2dfDevilsNeverSubdued()
    { return true; }

// Devils serve if properly commanded, but an improper command breaks the law
// which binds them, and it typically requires a contract for the soul
inline bool mm2dfDevilsServeIfCommanded()
    { return true; }

// Persons other than lawful evil can invoke or otherwise treat with devils
inline bool mm2dfNonLawfulEvilMayTreat()
    { return true; }

// Magic circles keep devils off for a time if properly scribed (and
// ensymboled for greater and arch-devils)
inline bool mm2dfMagicCirclesRepelDevils()
    { return true; }

// Devils are repelled by holy (Good) artifacts or relics
inline bool mm2dfHolyArtifactsRepelDevils()
    { return true; }

// All devils can direct their attacks against 2 or more opponents if means
// are at hand
inline bool mm2dfDevilsSplitAttacks()
    { return true; }

// A special form of telepathy lets devils understand and converse with any
// intelligent creature
inline bool mm2dfDevilTelepathy()
    { return true; }

// The devil attack-form chart: acid, full
inline bool mm2dfDevilAcidFullDamage()
    { return true; }

// The devil attack-form chart: cold, half
inline bool mm2dfDevilColdHalfDamage()
    { return true; }

// The devil attack-form chart: electricity (lightning), full
inline bool mm2dfDevilElectricityFullDamage()
    { return true; }

// The devil attack-form chart: fire (dragon, magical), none
inline bool mm2dfDevilFireNoneDamage()
    { return true; }

// The devil attack-form chart: gas (poisonous, etc.), half
inline bool mm2dfDevilGasHalfDamage()
    { return true; }

// The devil attack-form chart: iron weapon, none unless affected by normal
// weapons in which case damage is according to the weapon type
inline bool mm2dfDevilIronWeaponNone()
    { return true; }

// The devil attack-form chart: magic missile, full
inline bool mm2dfDevilMagicMissileFullDamage()
    { return true; }

// The devil attack-form chart: poison, full
inline bool mm2dfDevilPoisonFullDamage()
    { return true; }

// Devils somewhat resemble the demons of chaos in their characteristics,
// abilities and general attributes (further information in MM1 under Devil)
inline bool mm2dfDevilsResembleDemons()
    { return true; }

// ---- the MM2 letter D part 3 stat grid (the R801 wiring) ----

// The devil armor class cells
inline int mm2dfDevStatAC(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return -2;
        case 6:
            return -3;
        case 7:
            return 1;
        case 8:
            return -4;
        case 9:
            return -2;
        case 10:
            return -4;
        case 11:
            return -3;
        case 12:
            return -6;
        case 13:
            return -3;
        case 14:
            return 9;
        case 15:
            return -2;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The devil hit dice (num only; the flat-hp uniques read 0 - the charon path)
inline int mm2dfDevStatHd(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 7;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 6;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The devil hit dice bonus points
inline int mm2dfDevStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 6;
        case 8:
            return 0;
        case 9:
            return 0;
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
            return 0;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The devil book-average hit points (the flat-hp uniques carry their printed
// totals)
inline int mm2dfDevStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 18;
        case 2:
            return 21;
        case 3:
            return 16;
        case 4:
            return 24;
        case 5:
            return 126;
        case 6:
            return 106;
        case 7:
            return 27;
        case 8:
            return 154;
        case 9:
            return 69;
        case 10:
            return 111;
        case 11:
            return 139;
        case 12:
            return 188;
        case 13:
            return 126;
        case 14:
            return 3;
        case 15:
            return 86;
        case 16:
            return 13;
        default:
            return 0;
        }
    }

// The devil attacks per round (the loader semantics: the Amon 1-and-1 sums to
// 2, the bearded 1-or-3 and nupperibo 2-or-1 max, the spined 1-and/or-2 sums
// to 3)
inline int mm2dfDevStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 3;
        default:
            return 0;
        }
    }

// The devil xp base cells (the material-form-only uniques carry no per-hp
// addend)
inline int mm2dfDevStatXp(int b)
    {
        switch (b) {
        case 0:
            return 855;
        case 1:
            return 550;
        case 2:
            return 550;
        case 3:
            return 320;
        case 4:
            return 650;
        case 5:
            return 30000;
        case 6:
            return 35000;
        case 7:
            return 1125;
        case 8:
            return 30000;
        case 9:
            return 20000;
        case 10:
            return 30000;
        case 11:
            return 32000;
        case 12:
            return 49000;
        case 13:
            return 42000;
        case 14:
            return 18;
        case 15:
            return 29000;
        case 16:
            return 240;
        default:
            return 0;
        }
    }

// The devil xp per hit point
inline int mm2dfDevStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 5;
        case 4:
            return 8;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 10;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 4;
        default:
            return 0;
        }
    }

// The devil % in lair cells (Nil -> 0, the charon precedent)
inline int mm2dfDevStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 35;
        case 2:
            return 30;
        case 3:
            return 40;
        case 4:
            return 25;
        case 5:
            return 60;
        case 6:
            return 55;
        case 7:
            return 15;
        case 8:
            return 75;
        case 9:
            return 80;
        case 10:
            return 30;
        case 11:
            return 65;
        case 12:
            return 70;
        case 13:
            return 95;
        case 14:
            return 0;
        case 15:
            return 35;
        case 16:
            return 10;
        default:
            return 0;
        }
    }

// The devil primary ground move rate (inches x 10)
inline int mm2dfDevStatMove(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 15;
        case 2:
            return 12;
        case 3:
            return 18;
        case 4:
            return 9;
        case 5:
            return 18;
        case 6:
            return 12;
        case 7:
            return 15;
        case 8:
            return 9;
        case 9:
            return 15;
        case 10:
            return 9;
        case 11:
            return 6;
        case 12:
            return 15;
        case 13:
            return 12;
        case 14:
            return 6;
        case 15:
            return 15;
        case 16:
            return 6;
        default:
            return 0;
        }
    }

// The devil magic resistance percentages (the nupperibo Standard reads 0 -
// the charon Nil precedent applied to the word)
inline int mm2dfDevStatMr(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 40;
        case 4:
            return 30;
        case 5:
            return 70;
        case 6:
            return 70;
        case 7:
            return 45;
        case 8:
            return 80;
        case 9:
            return 60;
        case 10:
            return 65;
        case 11:
            return 75;
        case 12:
            return 85;
        case 13:
            return 70;
        case 14:
            return 0;
        case 15:
            return 75;
        case 16:
            return 25;
        default:
            return 0;
        }
    }

// ---- the frequency of devils on plane grid (the R801 wiring) ----

// The abishai column (common on the 1st and 2nd, uncommon on the 3rd, rare on
// the 4th, very rare on the 5th, absent below)
inline int mm2dfFreqDAbishai(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The arch-devil column (very very rare on every plane)
inline int mm2dfFreqDArch(int b)
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
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return 0;
        }
    }

// The barbed devil column
inline int mm2dfFreqDBarbed(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The bearded devil column
inline int mm2dfFreqDBearded(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The bone devil column
inline int mm2dfFreqDBone(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The erinyes column
inline int mm2dfFreqDErinyes(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The horned devil column
inline int mm2dfFreqDHorned(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 2;
        case 8:
            return 2;
        default:
            return 0;
        }
    }

// The ice devil column
inline int mm2dfFreqDIce(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 3;
        default:
            return 0;
        }
    }

// The nupperibo column (common on every plane but the 1st)
inline int mm2dfFreqDNupperibo(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        default:
            return 0;
        }
    }

// The pit fiend column
inline int mm2dfFreqDPitFiend(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 5;
        default:
            return 0;
        }
    }

// The spined devil column (common on the 1st through 5th)
inline int mm2dfFreqDSpined(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        default:
            return 0;
        }
    }

// The styx devil column
inline int mm2dfFreqDStyx(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// ---- the frequency of others on plane grid (the R801 wiring) ----

// The achaierai column
inline int mm2dfFreqOAchaierai(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 2;
        default:
            return 0;
        }
    }

// The barghest column (very rare on every plane but the last two)
inline int mm2dfFreqOBarghest(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        default:
            return 0;
        }
    }

// The daemon column
inline int mm2dfFreqODaemon(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        default:
            return 0;
        }
    }

// The hell cat column
inline int mm2dfFreqOHellCat(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The hell hound column
inline int mm2dfFreqOHellHound(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 4;
        default:
            return 0;
        }
    }

// The hoardling column
inline int mm2dfFreqOHoardling(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The imp column
inline int mm2dfFreqOImp(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 3;
        default:
            return 0;
        }
    }

// The lemure column
inline int mm2dfFreqOLemure(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        default:
            return 0;
        }
    }

// The mephit column (common on the upper planes, uncommon on the lower)
inline int mm2dfFreqOMephit(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        default:
            return 0;
        }
    }

// The nightmare column
inline int mm2dfFreqONightmare(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 2;
        default:
            return 0;
        }
    }

// The rakshasa column
inline int mm2dfFreqORakshasa(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 2;
        default:
            return 0;
        }
    }

// The stench kow column (the phantom blank capture column resolved: the
// capture table-split introduced a spurious empty column; the djvu
// corroborates the single stench kow column)
inline int mm2dfFreqOStenchKow(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        default:
            return 0;
        }
    }

// ---- the abishai pins (the R801 MM2 letter D part 3) ----

// The black abishai full kill xp: 855 + 10 x 28 hit points
inline int mm2dfBlackAbishaiXpValue()
    { return 1135; }

// The blue abishai full kill xp: 550 + 6 x 18 hit points
inline int mm2dfBlueAbishaiXpValue()
    { return 658; }

// The green abishai full kill xp: 550 + 6 x 21 hit points
inline int mm2dfGreenAbishaiXpValue()
    { return 676; }

// The red abishai full kill xp: 320 + 5 x 16 hit points
inline int mm2dfRedAbishaiXpValue()
    { return 400; }

// The white abishai full kill xp: 650 + 8 x 24 hit points
inline int mm2dfWhiteAbishaiXpValue()
    { return 842; }

// The abishai LEVEL/X.P. prints VI for the black, blue, green and white forms
inline int mm2dfAbishaiXpLevel()
    { return 6; }

// The red abishai LEVEL/X.P. prints V - the weakest form
inline int mm2dfRedAbishaiXpLevel()
    { return 5; }

// The abishai grapple strength bonus: black +4
inline int mm2dfBlackAbishaiStrengthBonus()
    { return 4; }

// The abishai grapple strength bonus: blue +3
inline int mm2dfBlueAbishaiStrengthBonus()
    { return 3; }

// The abishai grapple strength bonus: green +2
inline int mm2dfGreenAbishaiStrengthBonus()
    { return 2; }

// The abishai grapple strength bonus: white +2
inline int mm2dfWhiteAbishaiStrengthBonus()
    { return 2; }

// The abishai grapple strength bonus: red +1
inline int mm2dfRedAbishaiStrengthBonus()
    { return 1; }

// The abishai grapple damage: 1-4 from sharp scales, talons, etc., plus the
// strength bonus
inline int mm2dfAbishaiGrappleDamageLo()
    { return 1; }

// The abishai grapple damage high end
inline int mm2dfAbishaiGrappleDamageHi()
    { return 4; }

// The abishai tail strike: 1-2 points of damage
inline int mm2dfAbishaiTailDamageHi()
    { return 2; }

// Abishai regenerate at 1 point per round unless struck by silver, holy
// water, or holy magic weapons
inline int mm2dfAbishaiRegenPerRound()
    { return 1; }

// The abishai summon another abishai at 20% chance of success, once per day
inline int mm2dfAbishaiSummonPct()
    { return 20; }

// In their lair about 10% of the time there will be 1-4 other types with them
inline int mm2dfAbishaiOtherTypesPct()
    { return 10; }

// Abishai occasionally (15%) have charge of Q-type treasure being taken to
// some greater devil
inline int mm2dfAbishaiQTreasurePct()
    { return 15; }

// The race of abishai, the scaly devils, are common to the First Hell and
// most serve Tiamat; common on the 1st and 2nd, uncommon on the 3rd, rare on
// the 4th, very rare on the 5th and 6th
inline bool mm2dfAbishaiCommonToFirstHell()
    { return true; }

// The abishai are reptilian, appearing as humanoids with small horns, snaky
// hair, fangs, pointed ears, slanting eyes, leathery wings and barbed tail
inline bool mm2dfAbishaiReptilian()
    { return true; }

// Attack damage is for the weapon of each sort: black halberds, white flails,
// red long daggers, green guisarme-voulges, blue tridents
inline bool mm2dfAbishaiWeaponsByForm()
    { return true; }

// ---- the Amon pins (the R801 MM2 letter D part 3) ----

// The Amon full kill xp: X/30,000 (material form only, no per-hp addend)
inline int mm2dfAmonXpValue()
    { return 30000; }

// The Amon LEVEL/X.P. prints the roman X
inline int mm2dfAmonXpLevel()
    { return 10; }

// The Amon psionic ability 229, attack/defense modes all/all
inline int mm2dfAmonPsionicAbility()
    { return 229; }

// Amon is a vassal of Geryon commanding up to 40 companies of bone devils
// recruited from his fief
inline int mm2dfAmonBoneDevilCompanies()
    { return 40; }

// Amon typically attacks with a huge +3 mace and delivers a vicious bite as
// well
inline int mm2dfAmonMaceBonus()
    { return 3; }

// The winter wolf companion of Amon is 25% magic resistant
inline int mm2dfAmonWinterWolfMagicResist()
    { return 25; }

// The winter wolf companion has +3 to hit and +3 to damage
inline int mm2dfAmonWinterWolfBonus()
    { return 3; }

// Amon summons 1-4 bone devils with 60% chance of success
inline int mm2dfAmonSummonBoneDevilsPct()
    { return 60; }

// Amon regenerates from 1-12 points of damage per turn - the low end
inline int mm2dfAmonRegenPerTurnLo()
    { return 1; }

// The Amon regeneration high end
inline int mm2dfAmonRegenPerTurnHi()
    { return 12; }

// On the Prime Material Plane Amon can summon and control all wolves within 1
// mile of him
inline int mm2dfAmonWolfControlMiles()
    { return 1; }

// Amon causes fear in any individuals he gazes upon unless they save vs.
// spells
inline bool mm2dfAmonFearGaze()
    { return true; }

// Once per day Amon can use a symbol of hopelessness
inline bool mm2dfAmonSymbolOfHopelessnessOncePerDay()
    { return true; }

// Amon is wolf-headed but otherwise appears human; his torso is well-formed
// and muscled
inline bool mm2dfAmonWolfHeaded()
    { return true; }

// ---- the Bael pins (the R801 MM2 letter D part 3) ----

// The Bael full kill xp: X/35,000 (material form only)
inline int mm2dfBaelXpValue()
    { return 35000; }

// The Bael LEVEL/X.P. prints the roman X
inline int mm2dfBaelXpLevel()
    { return 10; }

// The Bael psionic ability 206, modes all/all
inline int mm2dfBaelPsionicAbility()
    { return 206; }

// Bael is vassal to Mammon, commanding 66 companies of barbed devils
inline int mm2dfBaelBarbedCompanies()
    { return 66; }

// Bael uses a morning star +2 with a long bronze handle
inline int mm2dfBaelMorningStarBonus()
    { return 2; }

// The handle telescopes magically from 4-8 feet as Bael desires - the low end
inline int mm2dfBaelMorningStarLoFeet()
    { return 4; }

// The Bael morning star handle high end
inline int mm2dfBaelMorningStarHiFeet()
    { return 8; }

// Bael uses his spell-like powers as a 20th-level magic-user
inline int mm2dfBaelSpellLevel()
    { return 20; }

// Bael summons 1-4 barbed devils with 65% chance of success
inline int mm2dfBaelSummonBarbedPct()
    { return 65; }

// Once per day Bael can employ a symbol of stunning
inline bool mm2dfBaelSymbolOfStunningOncePerDay()
    { return true; }

// Bael radiates fear within a 20-foot radius when he so desires
inline bool mm2dfBaelFearRadius()
    { return true; }

// Bael regenerates 1 point per round
inline bool mm2dfBaelRegenerates()
    { return true; }

// Bael is a well-formed humanoid with golden skin, small forward curling bull
// horns and rather bovine features
inline bool mm2dfBaelBovineFeatures()
    { return true; }

// ---- the bearded devil pins (the R801 MM2 letter D part 3) ----

// The bearded devil full kill xp: 1125 + 10 x 27 hit points
inline int mm2dfBeardedXpValue()
    { return 1395; }

// The bearded devil LEVEL/X.P. prints VII
inline int mm2dfBeardedXpLevel()
    { return 7; }

// The saw-toothed glaive treble-hook entangles for 1-3 points plus held fast
// unless a die roll equal to opening a door is made
inline int mm2dfBeardedGlaiveHookDamageHi()
    { return 3; }

// If both hand attacks succeed the beard damage is maximum, i.e., 8 points
inline int mm2dfBeardedBeardMaxDamage()
    { return 8; }

// A creature struck for maximum beard damage must save vs. poison or develop
// a burning rash reducing dexterity by 1 per round for 4 rounds
inline int mm2dfBeardedRashRounds()
    { return 4; }

// The rash dexterity loss per round
inline int mm2dfBeardedRashDexLossPerRound()
    { return 1; }

// Bearded devils summon another bearded devil at 35% chance of success
inline int mm2dfBeardedSummonPct()
    { return 35; }

// Bearded devils populate the Third Hell, the domain of Mammon, as well as
// planes below that
inline bool mm2dfBeardedThirdHell()
    { return true; }

// Bearded devils are particularly cruel and violent, using any excuse to
// attack, which makes them desirable as shock troops
inline bool mm2dfBeardedShockTroops()
    { return true; }

// ---- the Belial pins (the R801 MM2 letter D part 3) ----

// The Belial full kill xp: X/30,000 (material form only)
inline int mm2dfBelialXpValue()
    { return 30000; }

// The Belial LEVEL/X.P. prints the roman X
inline int mm2dfBelialXpLevel()
    { return 10; }

// The Belial psionic ability 279, modes all/all
inline int mm2dfBelialPsionicAbility()
    { return 279; }

// Belial utilizes a huge military fork +4 which causes a save vs. spells or a
// symbol of pain effect
inline int mm2dfBelialForkBonus()
    { return 4; }

// Three times per day Belial can use a symbol of pain
inline int mm2dfBelialSymbolOfPainPerDay()
    { return 3; }

// Belial summons (black) abishai (25%), 1-3 barbed devils (25%) or 1-4
// bearded devils (50%) with 85% chance of success
inline int mm2dfBelialSummonPct()
    { return 85; }

// Belial uses his spell-like powers as a 20th-level magic-user
inline int mm2dfBelialSpellLevel()
    { return 20; }

// Great Belial rules the Fourth Hell from his basalt palace, firmly in the
// camp of Baalzebul
inline bool mm2dfBelialRulesFourthHell()
    { return true; }

// Belial can pronounce an unholy word once per day
inline bool mm2dfBelialUnholyWordOncePerDay()
    { return true; }

// Belial causes fear in any individual he stares at, saving throw vs. spells
// applicable
inline bool mm2dfBelialFearByStare()
    { return true; }

// Belial is the most handsome and diabolic in appearance of all devils, the
// lord of pain and sufferings
inline bool mm2dfBelialMostHandsome()
    { return true; }

// ---- the Glasya pins (the R801 MM2 letter D part 3) ----

// The Glasya full kill xp: X/20,000 (material form only)
inline int mm2dfGlasyaXpValue()
    { return 20000; }

// The Glasya LEVEL/X.P. prints the roman X
inline int mm2dfGlasyaXpLevel()
    { return 10; }

// The Glasya psionic ability 206, modes all/all
inline int mm2dfGlasyaPsionicAbility()
    { return 206; }

// Glasya regenerates 2 hit points every turn
inline int mm2dfGlasyaRegenPerTurn()
    { return 2; }

// Glasya summons 1-2 malebranche - the low end
inline int mm2dfGlasyaSummonLo()
    { return 1; }

// The Glasya summon high end
inline int mm2dfGlasyaSummonHi()
    { return 2; }

// The Glasya summon chance of success
inline int mm2dfGlasyaSummonPct()
    { return 70; }

// Glasya employs her spell-like powers as a 20th-level magic-user
inline int mm2dfGlasyaSpellLevel()
    { return 20; }

// As consort to Mammon, Glasya is one of the more powerful and influential of
// female devils
inline bool mm2dfGlasyaConsortToMammon()
    { return true; }

// Glasya is the daughter of Asmodeus and incredibly beautiful; her wings,
// forked tail, horns and copper-colored skin betray her origins
inline bool mm2dfGlasyaDaughterOfAsmodeus()
    { return true; }

// Once per day Glasya can employ a finger of death
inline bool mm2dfGlasyaFingerOfDeathOncePerDay()
    { return true; }

// Glasya carries a short sword with a poisoned blade equal to a dagger of
// venom
inline bool mm2dfGlasyaDaggerOfVenom()
    { return true; }

// ---- the Hutijin pins (the R801 MM2 letter D part 3) ----

// The Hutijin full kill xp: X/30,000 (material form only)
inline int mm2dfHutijinXpValue()
    { return 30000; }

// The Hutijin LEVEL/X.P. prints the roman X
inline int mm2dfHutijinXpLevel()
    { return 10; }

// The Hutijin psionic ability 275, modes all/all
inline int mm2dfHutijinPsionicAbility()
    { return 275; }

// Hutijin commands 2 companies of pit fiends in service to Mephistopheles
inline int mm2dfHutijinPitFiendCompanies()
    { return 2; }

// Hutijin uses a net of snaring and a +3 trident in battle
inline int mm2dfHutijinTridentBonus()
    { return 3; }

// Hutijin causes fear by voice tone within a 30-foot radius, save vs. rods et
// al. applicable
inline int mm2dfHutijinFearRadiusFeet()
    { return 30; }

// Hutijin can summon a pit fiend with 75% chance of success
inline int mm2dfHutijinSummonPct()
    { return 75; }

// Hutijin uses his spell-like powers as a 20th-level magic-user
inline int mm2dfHutijinSpellLevel()
    { return 20; }

// Hutijin commands the aristocracy of the Eighth Plane and is one of the
// greatest of Hell dukes
inline bool mm2dfHutijinAristocracyOfEighthPlane()
    { return true; }

// Hutijin can use a symbol of persuasion once per day
inline bool mm2dfHutijinSymbolOfPersuasionOncePerDay()
    { return true; }

// The Hutijin spell-like list carries heal twice per day
inline bool mm2dfHutijinHealTwicePerDay()
    { return true; }

// Hutijin resembles a pit fiend, with proportionately smaller wings, a larger
// head, and a dark rust-red hide
inline bool mm2dfHutijinResemblesPitFiend()
    { return true; }

// ---- the Mammon pins (the R801 MM2 letter D part 3) ----

// The Mammon full kill xp: X/32,000 (material form only)
inline int mm2dfMammonXpValue()
    { return 32000; }

// The Mammon LEVEL/X.P. prints the roman X
inline int mm2dfMammonXpLevel()
    { return 10; }

// The Mammon psionic ability 259, modes all/all
inline int mm2dfMammonPsionicAbility()
    { return 259; }

// Mammon uses his spell-like powers as a 20th-level magic-user
inline int mm2dfMammonSpellLevel()
    { return 20; }

// Mammon summons (green) abishai (50%), 1-3 barbed devils (25%) or 1-3
// bearded devils (25%) with 80% chance of success
inline int mm2dfMammonSummonPct()
    { return 80; }

// Mammon is the king of Hell Third Plane, a boundless series of rifts with
// slime streams under hot ash from spurting volcanos
inline bool mm2dfMammonRulesThirdHell()
    { return true; }

// Mammon rides a nightmare of largest size with a pack of hell hounds at his
// heels, seeking trophies of the hunt
inline bool mm2dfMammonRidesNightmare()
    { return true; }

// His fauchard-fork inflicts normal damage (1-8 or 1-10) but otherwise acts
// as a sword of wounding
inline bool mm2dfMammonSwordOfWounding()
    { return true; }

// Once per day Mammon can use a symbol of hopelessness and pronounce an
// unholy word
inline bool mm2dfMammonSymbolOfHopelessnessOncePerDay()
    { return true; }

// Mammon causes fear by means of his gaze, save vs. spells applicable
inline bool mm2dfMammonFearByGaze()
    { return true; }

// Mammon is a red-gold color, his scaled wings gleam like rubies, and his
// bloated form is very strong
inline bool mm2dfMammonRedGold()
    { return true; }

// ---- the Mephistopheles pins (the R801 MM2 letter D part 3) ----

// The Mephistopheles full kill xp: X/49,000 (material form only)
inline int mm2dfMephistoXpValue()
    { return 49000; }

// The Mephistopheles LEVEL/X.P. prints the roman X
inline int mm2dfMephistoXpLevel()
    { return 10; }

// The Mephistopheles psionic ability 309, modes all/all
inline int mm2dfMephistoPsionicAbility()
    { return 309; }

// The great 3-tined fork +3 delivers 3-12 points of cold, electrical or fire
// damage on command, save vs. spells applicable
inline int mm2dfMephistoForkBonus()
    { return 3; }

// The fork function damage high end (3-12)
inline int mm2dfMephistoForkDamageHi()
    { return 12; }

// Each fork function is usable 3 times per day
inline int mm2dfMephistoForkUsesPerDay()
    { return 3; }

// Mephistopheles summons 1-3 ice devils with 90% chance of success
inline int mm2dfMephistoSummonIceDevilsPct()
    { return 90; }

// Mephisto causes fear by gaze (save vs. spells) or within a 10-foot radius
// (save vs. rods et al.)
inline int mm2dfMephistoFearRadiusFeet()
    { return 10; }

// Mephistopheles uses his spell-like powers as a 20th-level magic-user
inline int mm2dfMephistoSpellLevel()
    { return 20; }

// The Eighth Hell is ruled by Mephistopheles from a great iron citadel in the
// ice mountains
inline bool mm2dfMephistoRulesEighthHell()
    { return true; }

// His main aim is to wrest the 7th plane from Baalzebul and then challenge
// Asmodeus for the overlordship of all the hells
inline bool mm2dfMephistoWrestSeventhPlane()
    { return true; }

// The Mephistopheles spell list prints rulership once per day - the print
// pins verbatim (a genuine print typo that stands; the capture and the djvu
// OCR agree)
inline bool mm2dfMephistoRulershipPrintsVerbatim()
    { return true; }

// The tall blue-black Mephistopheles has huge muscles, sooty black scales,
// deep blue wings, horns and talons, pale blue eyes with red irises, and his
// normal speech is whispering wind
inline bool mm2dfMephistoWhisperingWind()
    { return true; }

// ---- the Moloch pins (the R801 MM2 letter D part 3) ----

// The Moloch full kill xp: X/42,000 (material form only)
inline int mm2dfMolochXpValue()
    { return 42000; }

// The Moloch LEVEL/X.P. prints the roman X
inline int mm2dfMolochXpLevel()
    { return 10; }

// The Moloch psionic ability 226, modes all/all
inline int mm2dfMolochPsionicAbility()
    { return 226; }

// Moloch carries a 6-tailed whip of pliable metal delivering 1, 2, or 4
// points per tail striking
inline int mm2dfMolochWhipTails()
    { return 6; }

// Moloch may expend up to 20 charges per turn; the whip itself has no charges
inline int mm2dfMolochWhipChargesPerTurn()
    { return 20; }

// The Moloch burning hands does 16 points of damage
inline int mm2dfMolochBurningHandsDamage()
    { return 16; }

// Moloch breathes fear upon 1-8 persons within 30 feet - the low end
inline int mm2dfMolochFearBreathLo()
    { return 1; }

// The fear breath target high end
inline int mm2dfMolochFearBreathHi()
    { return 8; }

// The fear breath range in feet
inline int mm2dfMolochFearBreathRangeFeet()
    { return 30; }

// Moloch summons 1-3 horned devils with 80% chance of success
inline int mm2dfMolochSummonHornedPct()
    { return 80; }

// Moloch uses his spell-like powers as a 20th-level magic-user
inline int mm2dfMolochSpellLevel()
    { return 20; }

// Moloch is a grand duke, viceroy of Baalzebul and lord of Hell Sixth Plane
inline bool mm2dfMolochRulesSixthHell()
    { return true; }

// The whip damage is electrical in nature and so greatly feared by less
// powerful devils
inline bool mm2dfMolochWhipElectrical()
    { return true; }

// Once per day Moloch can create a flame strike, use a symbol of stunning and
// pronounce an unholy word
inline bool mm2dfMolochFlameStrikeOncePerDay()
    { return true; }

// Great enmity exists between Moloch and Geryon; if not for Baalzebul there
// would be open warfare
inline bool mm2dfMolochEnmityWithGeryon()
    { return true; }

// Moloch is a great square-bodied creature with red-orange skin, short thick
// arms and legs, huge square hands and feet, and a huge horned head
inline bool mm2dfMolochSquareBodied()
    { return true; }

// ---- the nupperibo pins (the R801 MM2 letter D part 3) ----

// The nupperibo full kill xp: 18 + 1 x 3 hit points
inline int mm2dfNupperiboXpValue()
    { return 21; }

// The nupperibo LEVEL/X.P. prints I/18 + 1/hp
inline int mm2dfNupperiboXpLevel()
    { return 1; }

// In the Infernal Region or areas of total Evil nupperibos regenerate at 1
// hit point per round, but elsewhere this power is lost
inline int mm2dfNupperiboRegenPerRound()
    { return 1; }

// Nupperibos slain in the cause of evil are 99% likely to be re-formed as
// nupperibos
inline int mm2dfNupperiboReformedPct()
    { return 99; }

// There is a 1% chance they will be re-formed as lemures of a special sort,
// from which the lesser devils are formed
inline int mm2dfNupperiboLemurePct()
    { return 1; }

// One spending a mere millennium of time as one of these special lemures
// might attain devilhood
inline int mm2dfNupperiboMillenniumYears()
    { return 1000; }

// The nupperibo MAGIC RESISTANCE prints Standard (the def carries it
// verbatim; the grid reads 0 - the charon Nil precedent applied to the word)
inline bool mm2dfNupperiboMrStandard()
    { return true; }

// Nupperibos are blind, deaf and unable to speak; sensitive to mental
// commands from stronger devils, they sense the presence of their own kind
inline bool mm2dfNupperiboBlindDeafMute()
    { return true; }

// If uncommanded the hordes of nupperibos continue to march and attack all
// things not of the Nine Hells
inline bool mm2dfNupperiboHordesMarch()
    { return true; }

// If a holy object (water, weapon) is used against them, regeneration is not
// possible
inline bool mm2dfNupperiboHolyObjectBlocksRegen()
    { return true; }

// Nupperibos are the remains of all lawful evil creatures not sufficiently
// malignant to be changed into lemures
inline bool mm2dfNupperiboRemainsOfLawfulEvil()
    { return true; }

// ---- the Titivilus pins (the R801 MM2 letter D part 3) ----

// The Titivilus full kill xp: X/29,000 (material form only)
inline int mm2dfTitivilusXpValue()
    { return 29000; }

// The Titivilus LEVEL/X.P. prints the roman X
inline int mm2dfTitivilusXpLevel()
    { return 10; }

// The Titivilus psionic ability 239, modes all/all
inline int mm2dfTitivilusPsionicAbility()
    { return 239; }

// The Titivilus symbol of discord or sleep affects 19 levels or hit dice (or
// the hit point total) - the print pins verbatim
inline int mm2dfTitivilusSymbolLevelsOrDice()
    { return 19; }

// The symbol affects 99 hit points (the settled read: the capture 98 is an
// OCR misread; the independent transcription and the djvu OCR print 99 - the
// shator +9 class)
inline int mm2dfTitivilusSymbolHitPoints()
    { return 99; }

// A saving throw indicates only nodding and dozing with a 1 in 20 chance per
// round of awakening fully
inline int mm2dfTitivilusAwakenChance()
    { return 20; }

// Titivilus summons 1-4 erinyes with 50% chance of success
inline int mm2dfTitivilusSummonErinyesPct()
    { return 50; }

// Titivilus regenerates from 1 point of damage per round
inline int mm2dfTitivilusRegenPerRound()
    { return 1; }

// Titivilus uses his spell-like powers as a 20th-level magic-user
inline int mm2dfTitivilusSpellLevel()
    { return 20; }

// Titivilus is the messenger for Dispater, notorious for his ability to twist
// words
inline bool mm2dfTitivilusMessengerForDispater()
    { return true; }

// It is said that Titivilus possesses a silver sword of wounding; he normally
// uses his other powers
inline bool mm2dfTitivilusSilverSwordOfWounding()
    { return true; }

// Titivilus causes fear by touch only
inline bool mm2dfTitivilusFearByTouch()
    { return true; }

// The Titivilus MOVE prints 15/30 MC:D (the djvu agrees; the transcription 12
// token is its own annotation)
inline bool mm2dfTitivilusMovePrintsMCd()
    { return true; }

// ---- the spined devil pins (the R801 MM2 letter D part 3) ----

// The spined devil full kill xp: 240 + 4 x 13 hit points
inline int mm2dfSpinedXpValue()
    { return 292; }

// The spined devil LEVEL/X.P. prints IV/240 + 4/hp
inline int mm2dfSpinedXpLevel()
    { return 4; }

// Most spined devils carry a short military fork 4 1/2 feet long
inline int mm2dfSpinedForkLengthInches()
    { return 54; }

// Up to 12 spikes can be loosed when flying over an opponent, each inflicting
// damage as a dart when hits are successful and causing flammable materials
// to burst into flame
inline int mm2dfSpinedSpineCap()
    { return 12; }

// In melee from 1-4 spines can wound an opponent if the devil hurls itself
// upon an antagonist - the low end
inline int mm2dfSpinedMeleeSpinesLo()
    { return 1; }

// The melee spine high end
inline int mm2dfSpinedMeleeSpinesHi()
    { return 4; }

// Spined devils summon once per day a barbed devil with 5% chance of success
inline int mm2dfSpinedSummonBarbedPct()
    { return 5; }

// Spined devils are used as servants and couriers, for they are too small and
// weak for most other duties
inline bool mm2dfSpinedServantsCouriers()
    { return true; }

// Spined devils often herd lemures
inline bool mm2dfSpinedHerdLemures()
    { return true; }

// Spined devils are found on all the planes of Hell, most common on the 2nd,
// 3rd, 4th and 5th planes
inline bool mm2dfSpinedAllPlanesOfHell()
    { return true; }

// The melee spine hits are automatic, but no other attack is possible in that
// round
inline bool mm2dfSpinedAttacksAutoHit()
    { return true; }

}   // namespace rules
