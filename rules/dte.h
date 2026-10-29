// =========================================================================================
// Adnd1 - rules/dte.h
// The Dragon issue-10 opener, part two - the Gilbert dungeon method article
// (folios 11-14), the Weights & Measures article (folios 19-20) and the
// Holsinger level ritual article (folios 20-21): three adjudicated chains and
// the part-one flip
// census 837 -> 838.
//
// Pinned from The Dragon Vol. 2 No. 4 (October 1977), the archive.org scan
// voice (single-voice; the source lives in the archive.org item
// accessory-dragon-magazine-012). The folios: 11-14, the Gilbert Design Forum
// dungeon-method article - think like the builders and allow every necessary
// function, the organized society that dug the dungeon out of solid rock and
// then abandoned it, the rooms no longer used for their intention and read
// like antedated storefronts, the builder occupation, standing, alignment and
// personality decreeing the levels, the storage-room rule, the two views -
// vertical cutaway and horizontal overlay at 200 feet to the inch - keep it
// simple and stick to a plan, the rich-builder doctrine, and the Nappo dig:
// 120 years of life, 275 years dead, three facets and fifteen levels, the
// report 010 box label reading 11-13 against the article tail riding folio 14
// beside the Archive ad; 19-20, the Crabaugh Weights & Measures article -
// Size on 3d6 and Build on d6, +1 hit per die at Size 16 and up, -1 at 5 and
// down, one pound at 10 GP, armor at 15, 30 and 60 percent of body mass,
// females +2 Constitution and +1 Dexterity with the lighter carrying
// capacity, the musculature-versus-force doctrine, the carrying grid - human
// 1.0 to 3.0, dwarf 1.5 to 3.5, hobbit 2.0 to 4.0 in tenths of body weight,
// the elf column mirroring the human, the speed ladder at 3, 6, 9 and 12, the
// male height-and-weight grid from 5-1 and 120 pounds to 6-4 and 215, the
// female grid from 4-10 and 100 to 6-1 and 185, and the appearance bands -
// eyes, hair, skin, voice, handedness, expression, hair length, males at 30
// percent bearded; 20-21, the Holsinger Gaining a New Experience Level
// article - the four-part ritual of qualification, attention, intercession
// and exhaustion, the good fasting and prayer or the sacrifice at double the
// new level with each creature at least half and conscious, the 50/50 neutral
// notice and the 50/50 evil nothing, the 60/40 sacrilege chances and the 50%
// temple-rite kill, the druid tree at 1 hit die and mistletoe at 10, the
// neutral mistletoe tree rite with its free cure, the Great Pink Elephants in
// the drunken stupor, the demihuman liquor toughness behind the level limits,
// the 7th-level militia ejection and the guild halls, and the spell learning
// by the Greyhawk columns with one forgettable spell per level. The part-one
// box in report 010 flips closed this round, 1 closed / 1 open. PRINT FOLIO =
// PDF PAGE, verified at the printed 10, 19 and 21 footers.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// the Holsinger level ritual and the Crabaugh Size system - though both echo
// later print - pin as a variant layer with provenance, never core canon. The
// print quirks ride AS SCANNED, noted, never silent: the male medium-weight
// Size-4 cell reading 185 as scanned against the 135 column pattern; the
// female Size-15 height cell garbled and riding sentinel -1; the carrying
// grid elf column mirroring the human with its two garbled cells riding the
// transcript, the dwarf Strength-16 cell garbled and riding sentinel; the
// speed-12 fraction garbled in the OCR, the speed pinning and the fraction
// riding; the facial-features d6-minus-2 rule and the limb tables riding
// prose; the Snits game and the Stellar Conquest article scoped out as other
// systems. The editor's standing caution rides: none of this is official.
//
namespace rules {

// ---- the Gilbert dungeon method article (folios 11-14) ----

// the Nappo dig example - three personality facets generated fifteen levels,
// the builder assumed celibate and a recluse (folios 12-14)
inline int dtnGilNappoLevels()
    { return 15; }

// the Nappo example facets - an MU, fond of animal experimentation, needing
// space for his orcs (folios 12-14)
inline int dtnGilNappoFacets()
    { return 3; }

// the two-views drawing scale - 200 feet to the inch, or whatever fits one
// sheet (folio 13)
inline int dtnGilScaleFtPerInch()
    { return 200; }

// Nappo, assisted by magic, lived on the site for 120 years (folio 12)
inline int dtnGilNappoLifespanYears()
    { return 120; }

// the 275 years since Nappo died, his orcs continuing to inhabit the place
// (folio 12)
inline int dtnGilNappoDeadYears()
    { return 275; }

// the designer must think like the builders and allow for all the necessary
// functions of the dungeon (folio 11)
inline bool dtnGilBuildersMindset()
    { return true; }

// dungeons are abandoned by the organized society it required to build them -
// digging one out of solid rock is a tremendous task (folio 11)
inline bool dtnGilOrganizedOrigins()
    { return true; }

// the rooms are no longer used for what they were intended - players read
// them like antedated storefronts by torchlight and never guess (folios
// 12-13)
inline bool dtnGilRoomsMisread()
    { return true; }

// the builder occupation, social standing, alignment and personality decree a
// great number of levels for his own personal use (folios 11-12)
inline bool dtnGilBuilderTraitsDecree()
    { return true; }

// always allow for storage rooms in the levels - it was a long hike to the
// surface (folio 12)
inline bool dtnGilStorageRoomsRule()
    { return true; }

// draw two views of the dungeon as a whole - a vertical cutaway and a
// horizontal overlay, both to scale, the levels as rectangles with their
// purpose written in (folio 13)
inline bool dtnGilTwoViewsRule()
    { return true; }

// keep it simple and stick to a plan - what looks obvious on paper is the
// deepest of forbidden mysteries to the players (folio 12)
inline bool dtnGilKeepItSimple()
    { return true; }

// the more a builder is developed, the more rich and varied his dungeons -
// each trait of character finds expression in additional levels (folios
// 13-14)
inline bool dtnGilRichBuilderRichDungeon()
    { return true; }

// ---- the Weights & Measures article (folios 19-20) ----

// one pound is presumed to equal 10 GP (folio 19)
inline int dtnWmPoundGp()
    { return 10; }

// armor weight as a fraction of body mass - leather armor 15% (folio 19)
inline int dtnWmLeatherPct()
    { return 15; }

// chain mail weighs 30% of body mass (folio 19)
inline int dtnWmChainPct()
    { return 30; }

// plate mail weighs 60% of body mass (folio 19)
inline int dtnWmPlatePct()
    { return 60; }

// females add 2 to their Constitution score (folio 19)
inline int dtnWmFemaleConBonus()
    { return 2; }

// females add 1 to their Dexterity score (folio 19)
inline int dtnWmFemaleDexBonus()
    { return 1; }

// a Size of 16 or greater adds 1 hit per die (folio 19)
inline int dtnWmSizeBonusMin()
    { return 16; }

// a Size of 5 or less subtracts 1 hit per die (folio 19)
inline int dtnWmSizePenaltyMax()
    { return 5; }

// the Size hit-per-die modification (folio 19)
inline int dtnWmSizeHpMod()
    { return 1; }

// at maximum carrying capacity the character staggers along at speed 3 (folio
// 20)
inline int dtnWmSpeedFull()
    { return 3; }

// at two-thirds maximum the character moves at speed 6 (folio 20)
inline int dtnWmSpeedTwoThirds()
    { return 6; }

// at one-third maximum the character moves at speed 9 (folio 20)
inline int dtnWmSpeedOneThird()
    { return 9; }

// at the lightest fraction the character moves at speed 12 - the printed
// fraction garbled in the OCR and riding the transcript (folio 20)
inline int dtnWmSpeedLightest()
    { return 12; }

// males have a 30% chance of having a beard (folio 20)
inline int dtnWmMaleBeardPct()
    { return 30; }

// the Size range - 3 through 18 on 3d6, sixteen rows per height and weight
// table (folio 19)
inline int dtnWmSizeBands()
    { return 16; }

// the carrying-capacity Strength range - 3 through 18, sixteen rows (folio
// 20)
inline int dtnWmCarryBands()
    { return 16; }

// Size is an additional characteristic rolled on 3 six-sided dice (folio 19)
inline bool dtnWmSizeThreeDice()
    { return true; }

// Build rolls on one six-sided die - 1 light, 2-5 normal, 6 heavy -
// functional only for humans but rolled for non-humans anyway (folio 19)
inline bool dtnWmBuildFunctionalHumans()
    { return true; }

// the carrying-capacity elf column mirrors the human column by the print own
// arithmetic - the strength-5 and strength-16 cells garbled in the OCR and
// riding the transcript (folio 20)
inline bool dtnWmElfMirrorsHuman()
    { return true; }

// females sit at a carrying-capacity disadvantage through body mass, with no
// Strength penalty (folio 20)
inline bool dtnWmFemaleLighterCapacity()
    { return true; }

// two kinds of strength - how well muscled, reflected in the Strength
// characteristic, and physical force, reflected in carrying capacity as a
// multiple of body weight (folio 20)
inline bool dtnWmMusculatureVsForce()
    { return true; }

// the appearance tables are intended for humans and work poorly to not at all
// for non-humans (folio 20)
inline bool dtnWmAppearanceHumanOnly()
    { return true; }

// the Build band - 1 light, 2-5 normal, 6 heavy (folio 19)
inline int dtnWmBuildBand(int x)
    {
        if (x <= 1) return 0;
        if (x <= 5) return 1;
        return 2;
    }

// the eye color band - brown 1-7, blue 8-13, green 14-17, steel-gray 18-19,
// golden 20 (folio 20)
inline int dtnWmEyesBand(int x)
    {
        if (x <= 7) return 0;
        if (x <= 13) return 1;
        if (x <= 17) return 2;
        if (x <= 19) return 3;
        return 4;
    }

// the hair color band - brown 1-8, black 9-10, blonde 11-16, white 17, gray
// 18-19, red 20 (folio 20)
inline int dtnWmHairBand(int x)
    {
        if (x <= 8) return 0;
        if (x <= 10) return 1;
        if (x <= 16) return 2;
        if (x <= 17) return 3;
        if (x <= 19) return 4;
        return 5;
    }

// the complexion band - pale 1-3, fair 4-6, normal 7-11, tanned 12-14, dark
// 15-16, black 17-18, oriental 19-20 (folio 20)
inline int dtnWmSkinBand(int x)
    {
        if (x <= 3) return 0;
        if (x <= 6) return 1;
        if (x <= 11) return 2;
        if (x <= 14) return 3;
        if (x <= 16) return 4;
        if (x <= 18) return 5;
        return 6;
    }

// the voice pitch band - high 1, medium 2-3, low 4 on the four-sided (folio
// 21)
inline int dtnWmVoiceBand(int x)
    {
        if (x <= 1) return 0;
        if (x <= 3) return 1;
        return 2;
    }

// the handedness band on two six-sided - ambidextrous 2, left 3-4, right 5-12
// (folio 21)
inline int dtnWmHandednessBand(int x)
    {
        if (x <= 2) return 0;
        if (x <= 4) return 1;
        return 2;
    }

// the habitual expression band - carefree 1-2 through amused 20 (folio 21)
inline int dtnWmExpressionBand(int x)
    {
        if (x <= 2) return 0;
        if (x <= 3) return 1;
        if (x <= 6) return 2;
        if (x <= 8) return 3;
        if (x <= 9) return 4;
        if (x <= 10) return 5;
        if (x <= 11) return 6;
        if (x <= 12) return 7;
        if (x <= 13) return 8;
        if (x <= 14) return 9;
        if (x <= 16) return 10;
        if (x <= 18) return 11;
        if (x <= 19) return 12;
        return 13;
    }

// the male hair length band - short 4 inches 1-5, medium 8 inches 6-9, long
// 10 (folio 20)
inline int dtnWmHairLengthMaleBand(int x)
    {
        if (x <= 5) return 0;
        if (x <= 9) return 1;
        return 2;
    }

// the female hair length band - short 1-2, medium 3-7, long 8-10 (folio 20)
inline int dtnWmHairLengthFemaleBand(int x)
    {
        if (x <= 2) return 0;
        if (x <= 7) return 1;
        return 2;
    }

// the male human height in inches per Size, 5-1 at 3 through 6-4 at 18 (folio
// 19)
inline int dtnWmMaleHeightIn(int b)
    {
        switch (b) {
        case 0:
            return 61;
        case 1:
            return 62;
        case 2:
            return 63;
        case 3:
            return 64;
        case 4:
            return 65;
        case 5:
            return 66;
        case 6:
            return 67;
        case 7:
            return 68;
        case 8:
            return 69;
        case 9:
            return 70;
        case 10:
            return 71;
        case 11:
            return 72;
        case 12:
            return 73;
        case 13:
            return 74;
        case 14:
            return 75;
        case 15:
            return 76;
        default:
            return -1;
        }
    }

// the male light-build weight in pounds per Size (folio 19)
inline int dtnWmMaleLightLb(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 120;
        case 2:
            return 125;
        case 3:
            return 130;
        case 4:
            return 130;
        case 5:
            return 135;
        case 6:
            return 140;
        case 7:
            return 140;
        case 8:
            return 145;
        case 9:
            return 150;
        case 10:
            return 155;
        case 11:
            return 160;
        case 12:
            return 160;
        case 13:
            return 165;
        case 14:
            return 170;
        case 15:
            return 175;
        default:
            return -1;
        }
    }

// the male medium-build weight in pounds - the Size-4 row reading 185 as
// scanned against a 135 column pattern, noted never silent (folio 19)
inline int dtnWmMaleMedLb(int b)
    {
        switch (b) {
        case 0:
            return 135;
        case 1:
            return 185;
        case 2:
            return 140;
        case 3:
            return 145;
        case 4:
            return 145;
        case 5:
            return 150;
        case 6:
            return 155;
        case 7:
            return 160;
        case 8:
            return 160;
        case 9:
            return 165;
        case 10:
            return 170;
        case 11:
            return 175;
        case 12:
            return 180;
        case 13:
            return 185;
        case 14:
            return 190;
        case 15:
            return 195;
        default:
            return -1;
        }
    }

// the male heavy-build weight in pounds per Size (folio 19)
inline int dtnWmMaleHvyLb(int b)
    {
        switch (b) {
        case 0:
            return 145;
        case 1:
            return 150;
        case 2:
            return 155;
        case 3:
            return 155;
        case 4:
            return 160;
        case 5:
            return 165;
        case 6:
            return 170;
        case 7:
            return 175;
        case 8:
            return 180;
        case 9:
            return 185;
        case 10:
            return 190;
        case 11:
            return 195;
        case 12:
            return 200;
        case 13:
            return 205;
        case 14:
            return 210;
        case 15:
            return 215;
        default:
            return -1;
        }
    }

// the female human height in inches per Size - the Size-15 cell garbled in
// the OCR, sentinel -1, riding the transcript (folio 19)
inline int dtnWmFemaleHeightIn(int b)
    {
        switch (b) {
        case 0:
            return 58;
        case 1:
            return 59;
        case 2:
            return 60;
        case 3:
            return 61;
        case 4:
            return 62;
        case 5:
            return 63;
        case 6:
            return 64;
        case 7:
            return 65;
        case 8:
            return 66;
        case 9:
            return 67;
        case 10:
            return 68;
        case 11:
            return 69;
        case 12:
            return -1;
        case 13:
            return 71;
        case 14:
            return 72;
        case 15:
            return 73;
        default:
            return -1;
        }
    }

// the female light-build weight in pounds per Size (folio 19)
inline int dtnWmFemaleLightLb(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 105;
        case 2:
            return 105;
        case 3:
            return 110;
        case 4:
            return 110;
        case 5:
            return 115;
        case 6:
            return 115;
        case 7:
            return 120;
        case 8:
            return 120;
        case 9:
            return 125;
        case 10:
            return 130;
        case 11:
            return 130;
        case 12:
            return 135;
        case 13:
            return 140;
        case 14:
            return 145;
        case 15:
            return 150;
        default:
            return -1;
        }
    }

// the female medium-build weight in pounds per Size (folio 19)
inline int dtnWmFemaleMedLb(int b)
    {
        switch (b) {
        case 0:
            return 110;
        case 1:
            return 115;
        case 2:
            return 115;
        case 3:
            return 120;
        case 4:
            return 125;
        case 5:
            return 125;
        case 6:
            return 130;
        case 7:
            return 130;
        case 8:
            return 135;
        case 9:
            return 140;
        case 10:
            return 145;
        case 11:
            return 145;
        case 12:
            return 150;
        case 13:
            return 155;
        case 14:
            return 160;
        case 15:
            return 165;
        default:
            return -1;
        }
    }

// the female heavy-build weight in pounds per Size (folio 19)
inline int dtnWmFemaleHvyLb(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 125;
        case 2:
            return 130;
        case 3:
            return 130;
        case 4:
            return 135;
        case 5:
            return 140;
        case 6:
            return 140;
        case 7:
            return 145;
        case 8:
            return 150;
        case 9:
            return 155;
        case 10:
            return 155;
        case 11:
            return 160;
        case 12:
            return 165;
        case 13:
            return 170;
        case 14:
            return 175;
        case 15:
            return 185;
        default:
            return -1;
        }
    }

// the human carrying multiple in tenths of body weight per Strength, 1.0 at 3
// to 3.0 at 18 - the elf column mirrors this by the print arithmetic (folio
// 20)
inline int dtnWmCarryHuman(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 14;
        case 4:
            return 16;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 24;
        case 12:
            return 26;
        case 13:
            return 27;
        case 14:
            return 28;
        case 15:
            return 30;
        default:
            return -1;
        }
    }

// the dwarf carrying multiple in tenths - 1.5 at 3 to 3.5 at 18, the
// Strength-16 cell garbled in the OCR, sentinel -1 (folio 20)
inline int dtnWmCarryDwarf(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 17;
        case 2:
            return 18;
        case 3:
            return 19;
        case 4:
            return 20;
        case 5:
            return 22;
        case 6:
            return 23;
        case 7:
            return 25;
        case 8:
            return 25;
        case 9:
            return 27;
        case 10:
            return 28;
        case 11:
            return 29;
        case 12:
            return 31;
        case 13:
            return -1;
        case 14:
            return 33;
        case 15:
            return 35;
        default:
            return -1;
        }
    }

// the hobbit carrying multiple in tenths - 2.0 at 3 to 4.0 at 18 (folio 20)
inline int dtnWmCarryHobbit(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 22;
        case 2:
            return 23;
        case 3:
            return 24;
        case 4:
            return 26;
        case 5:
            return 27;
        case 6:
            return 28;
        case 7:
            return 30;
        case 8:
            return 30;
        case 9:
            return 32;
        case 10:
            return 33;
        case 11:
            return 34;
        case 12:
            return 36;
        case 13:
            return 37;
        case 14:
            return 38;
        case 15:
            return 40;
        default:
            return -1;
        }
    }

// ---- the Holsinger level ritual article (folios 20-21) ----

// the sacrifice total - hit dice double the number of the new experience
// level (folio 20)
inline int dtnHolsSacrificeTotalFactor()
    { return 2; }

// each individual creature must have at least half as many hit dice as the
// new level (folio 20)
inline int dtnHolsSacrificeEachMinHalf()
    { return 2; }

// a neutral sacrifice without a cleric - 50/50 the good gods or the evil gods
// notice (folio 20)
inline int dtnHolsNeutralSacrificePct()
    { return 50; }

// an evil sacrifice without a good cleric - 50/50 that nothing happens (folio
// 20)
inline int dtnHolsEvilSacrificeNothingPct()
    { return 50; }

// sacrilege against the good gods without clerics - a 60% chance the right
// gods notice (folio 21)
inline int dtnHolsGoodSacrilegeRightPct()
    { return 60; }

// a 40% chance the wrong gods notice at sacrilege against the good gods
// (folio 21)
inline int dtnHolsWrongGodsPct()
    { return 40; }

// a rite of a different alignment in an outraged temple - a 50% chance the
// gods show up immediately and kill, no chance for revival (folio 21)
inline int dtnHolsTempleRiteKillPct()
    { return 50; }

// characters usually build their own castle in the wilderness at the 7th
// experience level (folio 21)
inline int dtnHolsCastleLevel()
    { return 7; }

// the druid-appeased sacrifice of a tree counts as a one-hit-die neutral
// creature (folio 21)
inline int dtnHolsTreeHD()
    { return 1; }

// mistletoe counts as ten hit dice (folio 21)
inline int dtnHolsMistletoeHD()
    { return 10; }

// the sacrificed tree must be at least ten feet tall and alive - potted -
// when sacrificed in a temple (folio 21)
inline int dtnHolsTreeMinFt()
    { return 10; }

// the four parts of gaining a level - qualifying experience, attracting the
// gods, a cleric intercession, complete exhaustion (folio 20)
inline bool dtnHolsFourPartRitual()
    { return true; }

// the good attract the gods by fasting and prayer in a temple - no danger
// from other gods, but a substantial free-will offering required (folio 20)
inline bool dtnHolsGoodFastingPrayer()
    { return true; }

// sacrifices must be conscious and not under the influence of magic (folio
// 20)
inline bool dtnHolsSacrificeConsciousRule()
    { return true; }

// good may not sacrifice neutral humans though they may sacrifice evil humans
// - evil may sacrifice both (folio 21)
inline bool dtnHolsGoodNoNeutralHumans()
    { return true; }

// the neutral rite - getting laid while perched in a mistletoe tree, the
// druids paid, a free cure light wounds for the stickers (folio 21)
inline bool dtnHolsNeutralMistletoeRite()
    { return true; }

// a cleric of the character own alignment must intercede so only the gods of
// that alignment show up (folio 20)
inline bool dtnHolsClericIntercession()
    { return true; }

// clerics expect to be paid for their services throughout the ritual (folio
// 20)
inline bool dtnHolsClericsExpectPay()
    { return true; }

// the only reliable attitude is complete exhaustion - thoroughly inebriated
// following great physical activity, whereupon the Emissaries of the Gods,
// the Great Pink Elephants, lay on the new abilities (folio 21)
inline bool dtnHolsExhaustionStuporRule()
    { return true; }

// dwarves, elves and hobbits are tougher to get bombed - this is why there
// are limits on the experience levels they may reach (folio 21)
inline bool dtnHolsDemiHumanLiquorToughness()
    { return true; }

// the local militia heaves passed-out characters over the town walls at the
// 7th level, whence the wilderness castle (folio 21)
inline bool dtnHolsMilitiaEjects7th()
    { return true; }

// cities contain guild halls for each profession where members carouse in
// safety, even mass affairs promoting dozens at once (folio 21)
inline bool dtnHolsGuildHalls()
    { return true; }

// new spell levels are learned from the Great Pink Elephants by the Greyhawk
// minimum-per-level column with percentile rolls against the chance to know
// any given spell (folio 21)
inline bool dtnHolsSpellLearningRitual()
    { return true; }

// each new level a character may choose to forget one spell of each level
// previously known, to make room for others (folio 21)
inline bool dtnHolsForgettingSpells()
    { return true; }

}   // namespace rules
