// ====================================================================
// Adnd1 - rules/dmg/energydrain.h
// R218: the use of magic items and
// energy draining pins (DMG pp.119-122) -
// the potion, oil, command word and
// scrying conventions, and the energy
// drain level-loss mechanics.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice, the hit die records and the actual
// draining; the tables and the numeric
// conventions read here).
//
// Conventions and judgments, named in
// place:
//   - Drinking potions: it takes but one
//     segment (6 seconds) to open and
//     consume the typical potion; then a
//     delay of d4+1 = 2-5 segments before
//     the dose takes full effect. Specific
//     per-potion times are possible but
//     not recommended.
//   - Applying oils: not consumed - one
//     segment of normal opening and
//     decanting, then 2-5 segments to
//     spread over hands and body.
//   - Command words: a rod, staff or wand
//     usually needs the proper command
//     word. It can be learned by noting
//     what the possessor says, forcing or
//     tricking the possessor into
//     divulging it, from hidden records,
//     or via the three informational spells
//     - contact other plane, legend lore
//     and speak with dead.
//   - Crystal balls and scrying: scrying
//     is detectable. If the observed
//     creature is a spell user, consult the
//     DETECTION OF INVISIBILITY table by
//     level/hit dice and intelligence,
//     checking each round. Darkness cast
//     upon the viewing spot stops the
//     scrying for the duration of the
//     darkness spell; dispel magic stops it
//     for a full day.
//   - Energy drain mechanics: losing an
//     energy level loses an experience
//     level - the hit points gained with
//     it (including the constitution
//     bonus), all abilities of that level,
//     and XP brought down to the mid-point
//     of the next lower level. Below 1st
//     level the individual is a 0 level
//     person never capable of gaining
//     experience again; a 0 level
//     individual drained an energy level is
//     dead. Players may be required to
//     record each hit die score so lost
//     points are known immediately.
//   - Multiclass drain: a multi-classed or
//     two-classed character drained of one
//     level always loses the highest level
//     gained; if all levels are equal, the
//     level of the class requiring the
//     greatest amount of experience points
//     is lost. A creature draining two
//     levels takes one level from each
//     class.
//   - The drained-all fate: a character
//     drained of all energy levels might
//     become an undead monster of the same
//     sort which killed him or her. These
//     lesser undead are controlled by their
//     slayer/drainer and have but half the
//     hit dice of a normal undead of the
//     same type. A lesser vampire has half
//     the former professional level - the
//     print example: an 8th level thief
//     returns as a 4th level thief vampire
//     (odd levels round down; the print
//     gives only the exact-half example).
//     Upon the destruction of the slayer,
//     the lesser undead gain levels from
//     those they slay/drain until reaching
//     full hit dice status, then they can
//     themselves control lesser undead.
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Energydrain (instance methods)
class Energydrain {
public:


// -----------------------------------------------------------------------
// Drinking potions and applying oils.
// -----------------------------------------------------------------------
    int potionOpenConsumeSegments();
    int potionDelayMin();
    int potionDelayMax();
    int oilDecantSegments();
    int oilSpreadMin();
    int oilSpreadMax();


// -----------------------------------------------------------------------
// Command words.
// -----------------------------------------------------------------------
    int rodStaffWandNeedsCommandWord();
    int commandWordInfoSpellCount();


// -----------------------------------------------------------------------
// Crystal balls and scrying.
// -----------------------------------------------------------------------
    int scryingDetectable();
    int scryingDetectionUsesInvisibilityTable();
    int scryingDarknessStopsForSpellDuration();
    int scryingDispelStopsHours();


// -----------------------------------------------------------------------
// The energy drain level-loss mechanics.
// -----------------------------------------------------------------------
    int drainLosesLevelHitPointsAndAbilities();
    int drainXpToMidpointOfNextLower();
    int drainBelowFirstIsZeroLevel();
    int zeroLevelNeverGainsAgain();
    int isDeadIfZeroLevelDrained(int level);


// -----------------------------------------------------------------------
// The multiclass drain rules.
// -----------------------------------------------------------------------
    int multiclassLosesHighestLevel();
    int equalLevelsLoseGreatestXpClass();
    int twoLevelDrainSplitsAcrossClasses();


// -----------------------------------------------------------------------
// The drained-all undead fate.
// -----------------------------------------------------------------------
    int drainedAllMayBecomeUndead();
    int lesserUndeadHalfHitDice();
    int lesserUndeadControlledBySlayer();
    int lesserVampireLevel(int level);
    int fullHdRegainUponSlayerDestruction();
};
