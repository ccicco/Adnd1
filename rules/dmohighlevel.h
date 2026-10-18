// =========================================================================================
// Adnd1 - rules/dmohighlevel.h
// HIGH-LEVEL CHARACTERS OPENS - DMO Chapter 7, round one of five: the
// saving-throw improvement limits by group (priest 19, rogue 21, warrior 17,
// wizard 21, read from the PHB Table 60 reference), the automatic
// saving-throw failure doctrine (the universal fail on 3 or less on 1d20, the
// lesser-deity 2, the intermediate 1, the greater never, the bonus-proof and
// always-a-chance rules, the adjusted-roll reading of 3-or-less numbers, the
// Wulf worked example reading 5 - 3 = 2 with the actual 1, 2 or 3 still
// failing), the Table 36 saving-throw grid (28 rows in four group bands by
// the defender-minus-caster difference: priest 7 rows, rogue 6, warrior 10,
// wizard 5, in the paralyzation-or-death, petrification-or-polymorph and
// spell columns) with its four row-band chains, the Table 37 device casting
// levels (rod 12, staff 8, wand 6, other item 12, artifact 20), the Table 38
// caster-level penalty ladder (0 at 1-12 down to -6 at 28-30, the either-or
// rule that excludes Table 36 in favor of the PHB Table 60), and the Table 39
// THACO limits (priest 8, rogue 11, warrior 1, wizard 14, the attack roll of
// 1 always a miss, monsters unlimited).
// census 530 -> 531.
//
// verified against printed pp. 142-144 of the archive.org DMO captures (items
// dungeon-master-option-high-level-campaigns and
// tsr02156dmsoptionhighlevelcampaigns, the djvu.txt full texts, leaf N =
// printed page N; the tsr02156 ABBYY read is primary and the tesseract read
// is cross-checked - its two misreads noted here: the fails-on-5-or-less for
// the printed 3-or-less, and the -1-to-5 row for the printed -1 to -3); the
// save limits and the auto-failure doctrine from p. 142, the Table 36 grid,
// the footnote worked examples and the usage doctrine from p. 143, the Tables
// 37 through 39 from p. 144. The Wulf example is pinned verbatim: the -3
// poison penalty succeeds on 5 or higher while an actual 1, 2 or 3 still
// fails.
//
// the gap census after this round: 84 closed, 12 open - five Chapter 7
// children flip in round one of five (the parent stays open until R612); the
// DMO arc continues with R609 (Tables 40-41 plus the Warriors with Table 42).
//
namespace rules {

// ---- the DMO save-limit pins ----

// the improvement cap: priests reach a level beyond which saving throws
// cannot be further improved, at level 19 (printed p. 142).
inline int dewPriestSaveLimitLevel()
    { return 19; }

// the improvement cap: rogues reach the saving-throw limit at level 21
// (printed p. 142).
inline int dewRogueSaveLimitLevel()
    { return 21; }

// the improvement cap: warriors reach the saving-throw limit at level 17
// (printed p. 142).
inline int dewWarriorSaveLimitLevel()
    { return 17; }

// the improvement cap: wizards reach the saving-throw limit at level 21
// (printed p. 142).
inline int dewWizardSaveLimitLevel()
    { return 21; }

// the reference table: the group save limits are read from Table 60 in the
// Player's Handbook (printed p. 142; referenced, not reprinted).
inline int dewPhbSaveTable()
    { return 60; }

// ---- the DMO auto-failure pins ----

// the universal failure floor: all characters and most other creatures fail
// their saving throws on rolls of 3 or less on 1d20 (printed p. 142).
inline int dewAutoFailMortal()
    { return 3; }

// the lesser-deity failure floor: lesser deities fail their saving throws on
// rolls of 2 or less (printed p. 142).
inline int dewAutoFailLesserDeity()
    { return 2; }

// the intermediate-deity failure floor: intermediate deities fail on rolls of
// 1 (printed p. 142).
inline int dewAutoFailIntermediateDeity()
    { return 1; }

// the greater-deity failure floor: greater deities need not roll at all -
// they never fail; the fail number is zero (printed p. 142).
inline int dewAutoFailGreaterDeity()
    { return 0; }

// the always-a-chance rule: barring a special circumstance that makes the
// save unnecessary (a successful magic-resistance roll, immunity to the
// attack form), there is always a chance a character can fail (printed p.
// 142).
inline bool dewAutoFailAlwaysPossible()
    { return true; }

// the bonus-proof rule: the automatic failure stands no matter how many
// bonuses the roll receives from magical items, spells, ability scores and
// the like (printed p. 142).
inline bool dewAutoFailIgnoresBonuses()
    { return true; }

// the adjusted-roll reading: a saving-throw success number of 3 or less from
// Table 60 or Table 36 refers to the character's adjusted die roll, not the
// actual number rolled (printed p. 143).
inline bool dewSaveNumberIsAdjustedRoll()
    { return true; }

// the greater-deity immunity: greater deities need not roll at all - they
// never fail their saving throws (printed p. 142).
inline bool dewGreaterDeityNeverFails()
    { return true; }

// ---- the DMO Wulf worked-example pins ----

// the Wulf worked example: Wulf, a 21st-level priest, has a saving-throw
// number of 2 against paralyzation, poison or death magic (printed p. 143).
inline int dewWulfParSaveNumber()
    { return 2; }

// the Wulf worked example: a particularly virulent poison imposes a -3
// penalty to the saving throw (printed p. 143).
inline int dewWulfPoisonPenalty()
    { return -3; }

// the Wulf worked example: the save succeeds on a roll of 5 or higher - the
// roll beats the automatic-failure number and still equals 2 after the -3
// modifier (printed p. 143).
inline int dewWulfSuccessRoll()
    { return 5; }

// ---- the DMO T36 usage-doctrine pins ----

// the non-spell exclusion: saving throws against poisons, breath weapons, or
// any other attack that is not a spell or spell-like ability from a creature
// or device use the standard saving-throw tables, not Table 36 (printed p.
// 143).
inline bool dewT36NotForNonSpells()
    { return true; }

// the device column rule: rods, staves, wands and other magical devices use
// the Table 36 column that is closest to their effects (printed p. 143).
inline bool dewDeviceClosestColumn()
    { return true; }

// the device-level rule: the wielder's level or Hit Dice is irrelevant when a
// device is used - the device type determines the attacker's level (printed
// p. 143).
inline bool dewWielderLevelIrrelevant()
    { return true; }

// the worked device example: a fireball from a wand of fire uses the spell
// column of Table 36 (printed p. 143).
inline bool dewFireballUsesSpellColumn()
    { return true; }

// the worked device example: a paralyzation beam from a wand of paralyzation
// uses the paralyzation or death magic column (printed p. 143).
inline bool dewWandParalyzationUsesParColumn()
    { return true; }

// the concealment doctrine: during play the DM should conceal the attacker's
// true level of power - announce the attack form, then the success or failure
// on the adjusted roll (printed p. 143).
inline bool dewDmConcealsCasterLevel()
    { return true; }

// the intended use: Table 36 is intended primarily for magical dueling, see
// Chapter 5; in regular play it is somewhat cumbersome (printed p. 143).
inline bool dewT36ForDuelsOnly()
    { return true; }

// ---- the DMO T36 row-band chains ----

// the rogue row base: the rogue bands of Table 36 sit at grid rows 7 through
// 12 (printed p. 143).
inline int dewRogueRowBase()
    { return 7; }

// the warrior row base: the warrior bands of Table 36 sit at grid rows 13
// through 22 (printed p. 143).
inline int dewWarriorRowBase()
    { return 13; }

// the wizard row base: the wizard bands of Table 36 sit at grid rows 23
// through 27 (printed p. 143).
inline int dewWizardRowBase()
    { return 23; }

// the priest row band of Table 36: the defender's level minus the caster's
// level maps -7 or less to row 0, -4 to -6 to row 1, -1 to -3 to row 2, 0 to
// row 3, +1 to +3 to row 4, +4 to +6 to row 5, and +7 or more to row 6
// (printed p. 143).
inline int dewPriestRow(int x)
    {
        if (x <= -7) return 0;
        if (x <= -4) return 1;
        if (x <= -1) return 2;
        if (x <= 0) return 3;
        if (x <= 3) return 4;
        if (x <= 6) return 5;
        return 6;
    }

// the rogue row band of Table 36: -9 or less to row 0, -5 to -8 to row 1, -1
// to -4 to row 2, 0 to row 3, +1 to +4 to row 4, and +5 or more to row 5
// (printed p. 143).
inline int dewRogueRow(int x)
    {
        if (x <= -9) return 0;
        if (x <= -5) return 1;
        if (x <= -1) return 2;
        if (x <= 0) return 3;
        if (x <= 4) return 4;
        return 5;
    }

// the warrior row band of Table 36: -7 or less to row 0, -5 to -6 to row 1,
// -3 to -4 to row 2, -1 to -2 to row 3, 0 to row 4, +1 to +2 to row 5, +3 to
// +4 to row 6, +5 to +6 to row 7, +7 to +8 to row 8, and +9 or more to row 9
// (printed p. 143).
inline int dewWarriorRow(int x)
    {
        if (x <= -7) return 0;
        if (x <= -5) return 1;
        if (x <= -3) return 2;
        if (x <= -1) return 3;
        if (x <= 0) return 4;
        if (x <= 2) return 5;
        if (x <= 4) return 6;
        if (x <= 6) return 7;
        if (x <= 8) return 8;
        return 9;
    }

// the wizard row band of Table 36: -6 or less to row 0, -1 to -5 to row 1, 0
// to row 2, +1 to +5 to row 3, and +6 or more to row 4 (printed p. 143).
inline int dewWizardRow(int x)
    {
        if (x <= -6) return 0;
        if (x <= -1) return 1;
        if (x <= 0) return 2;
        if (x <= 5) return 3;
        return 4;
    }

// ---- the DMO Table 36 grid ----

// the Table 36 row count: 28 rows in four group bands - priest 7, rogue 6,
// warrior 10, wizard 5 (printed p. 143).
inline int dewT36RowCount()
    { return 28; }

// the paralyzation or death magic column: priest 10 down to 2, rogue 13 down
// to 8, warrior 16 down to 3, wizard 14 down to 8 across the
// defender-minus-caster bands (printed p. 143).
inline int dewT36Par(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 13;
        case 8:
            return 12;
        case 9:
            return 11;
        case 10:
            return 10;
        case 11:
            return 9;
        case 12:
            return 8;
        case 13:
            return 16;
        case 14:
            return 14;
        case 15:
            return 13;
        case 16:
            return 11;
        case 17:
            return 10;
        case 18:
            return 8;
        case 19:
            return 7;
        case 20:
            return 5;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 14;
        case 24:
            return 13;
        case 25:
            return 11;
        case 26:
            return 10;
        case 27:
            return 8;
        default:
            return -99;
        }
    }

// the petrification or polymorph column: priest 13 down to 5, rogue 12 down
// to 7, warrior 17 down to 4, wizard 13 down to 5 (printed p. 143).
inline int dewT36Petr(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 12;
        case 2:
            return 10;
        case 3:
            return 9;
        case 4:
            return 8;
        case 5:
            return 7;
        case 6:
            return 5;
        case 7:
            return 12;
        case 8:
            return 11;
        case 9:
            return 10;
        case 10:
            return 9;
        case 11:
            return 8;
        case 12:
            return 7;
        case 13:
            return 17;
        case 14:
            return 15;
        case 15:
            return 14;
        case 16:
            return 12;
        case 17:
            return 11;
        case 18:
            return 9;
        case 19:
            return 8;
        case 20:
            return 6;
        case 21:
            return 5;
        case 22:
            return 4;
        case 23:
            return 13;
        case 24:
            return 11;
        case 25:
            return 9;
        case 26:
            return 7;
        case 27:
            return 5;
        default:
            return -99;
        }
    }

// the spell column (excluding death, petrification or polymorph attacks):
// priest 15 down to 7, rogue 15 down to 5, warrior 19 down to 6, wizard 12
// down to 4 (printed p. 143).
inline int dewT36Spell(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 14;
        case 2:
            return 12;
        case 3:
            return 11;
        case 4:
            return 10;
        case 5:
            return 9;
        case 6:
            return 7;
        case 7:
            return 15;
        case 8:
            return 13;
        case 9:
            return 11;
        case 10:
            return 9;
        case 11:
            return 7;
        case 12:
            return 5;
        case 13:
            return 19;
        case 14:
            return 17;
        case 15:
            return 16;
        case 16:
            return 14;
        case 17:
            return 13;
        case 18:
            return 11;
        case 19:
            return 10;
        case 20:
            return 8;
        case 21:
            return 7;
        case 22:
            return 6;
        case 23:
            return 12;
        case 24:
            return 10;
        case 25:
            return 8;
        case 26:
            return 6;
        case 27:
            return 4;
        default:
            return -99;
        }
    }

// ---- the DMO Table 37 device-level pins ----

// the device casting level: a rod attacks at caster level 12 (Table 37,
// printed p. 144).
inline int dewRodLevel()
    { return 12; }

// the device casting level: a staff attacks at caster level 8 (Table 37,
// printed p. 144).
inline int dewStaffLevel()
    { return 8; }

// the device casting level: a wand attacks at caster level 6 (Table 37,
// printed p. 144).
inline int dewWandLevel()
    { return 6; }

// the device casting level: any other magical item attacks at caster level 12
// (Table 37, printed p. 144).
inline int dewOtherItemLevel()
    { return 12; }

// the device casting level: an artifact attacks at caster level 20 (Table 37,
// printed p. 144).
inline int dewArtifactLevel()
    { return 20; }

// ---- the DMO Table 38 penalty pins ----

// the Table 38 caster-level band (printed p. 144): levels 1-12 fall in band
// 0, 13-15 in band 1, 16-18 in band 2, 19-21 in band 3, 22-24 in band 4,
// 25-27 in band 5, 28-30 in band 6, and the band holds at 6 beyond 30; the
// penalty itself reads from the dewT38Penalty column by band.
inline int dewT38Band(int x)
    {
        if (x <= 12) return 0;
        if (x <= 15) return 1;
        if (x <= 18) return 2;
        if (x <= 21) return 3;
        if (x <= 24) return 4;
        if (x <= 27) return 5;
        return 6;
    }

// the Table 38 band count: seven caster-level bands, 1-12 through 28-30 plus
// the beyond-30 tail (printed p. 144).
inline int dewT38BandCount()
    { return 7; }

// the penalty by band: 0, -1, -2, -3, -4, -5, -6 - a quicker and easier
// method than Table 36; if you use this table, do not use Table 36 (printed
// p. 144).
inline int dewT38Penalty(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return -2;
        case 3:
            return -3;
        case 4:
            return -4;
        case 5:
            return -5;
        case 6:
            return -6;
        default:
            return -99;
        }
    }

// the either-or rule: if you use Table 38, do not use Table 36; use Table 60
// from the Player's Handbook instead (printed p. 144).
inline bool dewT38ExcludesT36()
    { return true; }

// ---- the DMO Table 39 THACO-limit pins ----

// the THACO limit: a priest's THACO advancement stops at 8 (Table 39, printed
// p. 144).
inline int dewThacoLimitPriest()
    { return 8; }

// the THACO limit: a rogue's THACO advancement stops at 11 (Table 39, printed
// p. 144).
inline int dewThacoLimitRogue()
    { return 11; }

// the THACO limit: a warrior's THACO advancement stops at 1 - warriors
// improve THACO the most (Table 39, printed p. 144).
inline int dewThacoLimitWarrior()
    { return 1; }

// the THACO limit: a wizard's THACO advancement stops at 14 (Table 39,
// printed p. 144).
inline int dewThacoLimitWizard()
    { return 14; }

// the automatic miss: no matter what the attacker's THACO, an attack roll of
// 1 is always a miss (printed p. 144).
inline int dewAutoMissRoll()
    { return 1; }

// the limit doctrine: a character's THACO advancement is limited -
// professional skills and training extend a creature's natural talents only
// so far (printed p. 144).
inline bool dewThacoAdvancementLimited()
    { return true; }

// the warrior emphasis: warriors, naturally, can improve THACO the most
// (printed p. 144).
inline bool dewWarriorsImproveThacoMost()
    { return true; }

// the monster exception: monsters have no THACO limits (printed p. 144).
inline bool dewMonstersNoThacoLimit()
    { return true; }

}   // namespace rules
