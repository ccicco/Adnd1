// =========================================================================================
// Adnd1 - rules/wrm.h
// The witch remainders and the Friedman elf sub-race table - the
// might-be-usable micro-round: the familiars, the unpinned witch items, the
// Group B effect details and the editorially endorsed elf d20 table (Dragon
// #5)
// census 827 -> 828.
//
// Pinned from The Dragon Vol. 1 No. 5 (March 1977), the archive.org scan
// voice (the upload cross-check reached page 5 only; pages 6-32 remain
// single-voice, and this round's ink sits at folios 4-9, 28 - all
// single-voice pages; the R902 provenance stands). The witch remainders,
// adjudicated might-be-usable at the 2026-10-29 issue-5 ledger review: the
// witch familiar die (1,2 basilisk; 3 wyvern; 4 warlock with ring and wand;
// 5,6 one undead, no vampires, the familiars cooperating over the whole
// circle, the good witch exempt); the unpinned items - the Assassin's Eyes at
// 12 inches per turn invisible and immaterial with the one-turn kill window
// and the Charm or Death Ray, the Leech Dust ladder (weak at two turns,
// paralyzed at three, dead at four, plate armor buying two, holy water the
// only cure), the Mountain Seeds' castle swell, the Witch Wand's 30-foot ESP
// and lycanthrope/undead/elemental shield, the three-wand canon, the Ivy
// Bracelet, the Locket of Satan at 7 inches over 3 chaotic creatures with the
// two-turn 15-percent corruption, the Snake Belt at 3 feet, 6 per turn, 1
// die, the Skull of Death's repeatable Finger of Death and Animate Dead, the
// Luck Charm remainder (the 70-percent wish, the two limited weekly, the
// 10-percent lair bonus, the 20/50 per-category enhancement at 75 percent),
// the Potion Cauldron's one-duplicate-per-hour and the Treasure-Finding
// blood-pledge doctrine; the spell effect details - the 12-hit-dice delayed
// elemental, the 50-foot Wither, the Weight spell's 1-10 targets at triple or
// one-third, the Volcanic Circle at 4 feet per turn behind a 10-foot line for
// 10 dice, the two-turn Reflections with its Banish/Disintegrate exceptions,
// the Solidify true-matter doctrine, the Undead Control over 1-6 with the
// crystal-ball range, the Curse's 75-percent silver enclosure and
// no-immediate-death law, the Poison Touch's 3 objects and two-turn contact
// death, the Curtain Wall's 10-by-20 room behind the two-control-agent bar,
// the Fire Box's 10-foot cube, the Diminish halving ladder, and the 25-foot
// Circle of Blindness. The Friedman elf sub-race table, adjudicated
// might-be-usable at the same review: the Out On A Limb letter proposing a
// 20-sided die for elf sub-races - 1-16 Silvan, 17-19 Sindar, 20 Noldor -
// editorially endorsed in print.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon, and
// this round is pure remainder bookkeeping over the already-adjudicated R902
// chains - no new registry defs, no transcripts, no gap flips, the report 005
// state verified untouched at 1 closed / 0 open. The Friedman table carries
// its honest boundary as a pinned bool: Silvan, Sindar and Noldor are
// Tolkien's names, echoed in D&D's Wood, Grey and High elf convention - the
// pin rides the variant layer with provenance, never a core rewrite, and the
// editorial endorsement is pinned as the provenance fact it is. No duplicate
// ink: every const here was unpinned at R902/R904 (the spell matrix carried
// the R/D cells only; the quotas, the lair lines and the wilderness table
// were pinned there and are not repeated).
//
namespace rules {

// ---- the witch familiars (folio 8) ----

// the witch familiar die, the basilisk band minimum - 1 on a six-sided die
// (folio 8)
inline int wrmFamiliarBasiliskMin()
    { return 1; }

// the basilisk band maximum - 2 (folio 8)
inline int wrmFamiliarBasiliskMax()
    { return 2; }

// the wyvern familiar - 3 (folio 8)
inline int wrmFamiliarWyvernRoll()
    { return 3; }

// the warlock familiar with one ring and one wand - 4 (folio 8)
inline int wrmFamiliarWarlockRoll()
    { return 4; }

// the undead familiar band minimum - 5 (folio 8)
inline int wrmFamiliarUndeadMin()
    { return 5; }

// the undead familiar band maximum - 6 (folio 8)
inline int wrmFamiliarUndeadMax()
    { return 6; }

// the undead familiar is one undead character - no vampires (folio 8)
inline bool wrmFamiliarNoVampires()
    { return true; }

// the individual familiars cooperate to protect the entire circle of witches,
// not just their own owner (folio 8)
inline bool wrmFamiliarsCooperate()
    { return true; }

// good witches lack the posted-familiar guard defense - only the evil witches
// roll the familiar die (folio 8)
inline bool wrmGoodWitchNoGuardFamiliar()
    { return true; }

// ---- the witch items remainder (folios 7-9) ----

// the Assassin's Eyes flight - 12 inches per turn (folio 7)
inline int wrmAssassinEyesSpeed()
    { return 12; }

// the Assassin's Eyes - the failed-spell victim has one turn to kill them
// before they turn immaterial and return (folio 7)
inline int wrmAssassinEyesVictimTurns()
    { return 1; }

// the Assassin's Eyes are normally invisible and immaterial, passing any
// solid barrier - visible only to attack, and vulnerable only then (folio 7)
inline bool wrmAssassinEyesImmaterial()
    { return true; }

// the Assassin's Eyes attack - a Charm Person spell or Death Ray, the victim
// allowed saving throws (folio 7)
inline bool wrmAssassinEyesCharmOrDeath()
    { return true; }

// the Leech Dust throw - up to 2 inches, forming a cloud the dimensions of
// Cloudkill (folio 7)
inline int wrmLeechDustRange()
    { return 2; }

// the Leech Dust - in two turns the victim is unable to fight or use spells
// (folio 7)
inline int wrmLeechDustUnableTurns()
    { return 2; }

// the Leech Dust - paralyzed at three turns (folio 7)
inline int wrmLeechDustParalyzeTurns()
    { return 3; }

// the Leech Dust - dead at four turns (folio 7)
inline int wrmLeechDustDeathTurns()
    { return 4; }

// wearing plate armor in the dust cloud prolongs death two turns (folio 7)
inline int wrmLeechDustPlateBonusTurns()
    { return 2; }

// the Leech Dust is removed only by a sprinkling of holy water; a victim
// freed before death needs a full week of rest (folio 7)
inline bool wrmLeechDustHolyWaterOnly()
    { return true; }

// the Mountain Seeds - like the Hill Seeds but much deadlier: swelling to the
// size of a castle almost immediately, crushing armies or destroying a town
// (folio 7)
inline bool wrmMountainSeedCastleSize()
    { return true; }

// the Witch Wand also acts as a 30-foot ESP medallion (folio 8)
inline int wrmWandEspRange()
    { return 30; }

// the Witch Wand gives protection from normal missiles and shields the holder
// from lycanthropes, undead and elementals like scrolls (folio 8)
inline bool wrmWandLycanthropeShield()
    { return true; }

// the only three wands a witch ever uses - the Illusion Wand, the Polymorph
// Wand and the Witch Wand (folio 9)
inline bool wrmWitchThreeWands()
    { return true; }

// the Illusion Wand is usable only by witches and magic-users (folio 9)
inline bool wrmIllusionWandRestricted()
    { return true; }

// the Ivy Bracelet - Plant Control as the potion until removed, and Speak
// with Plants as a Patriarch (folio 9)
inline bool wrmIvyBraceletPlantControl()
    { return true; }

// the Ivy Bracelet - a fragile band of enchanted forest ivy, found only in
// forest coven hoards, destroyed by a firm wind or vigorous combat (folio 9)
inline bool wrmIvyBraceletFragile()
    { return true; }

// the Locket of Satan - commands any 3 chaotic creatures within the 7-inch
// range, no saving throws (folio 9)
inline int wrmLocketSatanRange()
    { return 7; }

// the Locket of Satan commands up to 3 chaotic creatures regardless of
// intervening substances (folio 9)
inline int wrmLocketSatanCommandMax()
    { return 3; }

// the Locket of Satan - two turns of concentrated power against a lawful
// character (folio 9)
inline int wrmLocketSatanCorruptTurns()
    { return 2; }

// the Locket of Satan - a 15 percent chance the lawful victim turns
// permanently evil and corrupted (folio 9)
inline int wrmLocketSatanCorruptPct()
    { return 15; }

// the Locket of Satan has no effect upon clerics, lawful or otherwise; found
// only with evil witches, usable by neutral and chaotic man-types (folio 9)
inline bool wrmLocketSatanClericImmune()
    { return true; }

// the Snake Belt - the snake staff in 3-foot belt form, usable by everyone
// (folio 9)
inline int wrmSnakeBeltLengthFeet()
    { return 3; }

// the Snake Belt crawls anywhere its owner mentally directs, at speeds up to
// 6 feet per turn (folio 9)
inline int wrmSnakeBeltSpeed()
    { return 6; }

// the Snake Belt does 1 die of damage to any creature it strikes (folio 9)
inline int wrmSnakeBeltDamageDice()
    { return 1; }

// the Snake Belt is killed only by fire and lightning; strong enough to
// strangle a wyvern (folio 9)
inline bool wrmSnakeBeltFireLightningOnly()
    { return true; }

// the Skull of Death - the wearer also gains The Finger of Death and Animate
// Dead, both usable repeatedly (folio 7)
inline bool wrmSkullPowersRepeatable()
    { return true; }

// the Luck Charm category d - grants 1 wish (70 percent chance) or 2 wishes
// of limited power per week (folio 28)
inline int wrmLuckCharmWishPct()
    { return 70; }

// the Luck Charm - 2 wishes of limited power per week when not the single
// wish (folio 28)
inline int wrmLuckCharmLimitedWishes()
    { return 2; }

// the Luck Charm category e - increases the chance of finding an opponent's
// lair by 10 percent (folio 28)
inline int wrmLuckCharmLairBonusPct()
    { return 10; }

// the Luck Charm - if the lair is found, each treasure category's presence
// chance enhances by 20 percent (75 percent chance of this) (folio 28)
inline int wrmLuckCharmTreasure20Pct()
    { return 75; }

// the Luck Charm - the 20-percent per-category enhancement (folio 28)
inline int wrmLuckCharmTreasureBonus20()
    { return 20; }

// the Luck Charm - the alternative 50-percent per-category enhancement (folio
// 28)
inline int wrmLuckCharmTreasureBonus50()
    { return 50; }

// the Potion Cauldron duplicates an available potion at the rate of one
// duplicate per hour (folio 8)
inline int wrmPotionDupPerHour()
    { return 1; }

// the Potion Cauldron is usable only by witches, producing any potion from
// the book-2 potion list in one game-day (folio 8)
inline bool wrmPotionCauldronWitchesOnly()
    { return true; }

// the Treasure-Finding potion doctrine - witches sell it only if forced or
// offered half the treasure, against a blood pledge, a broken word bringing
// prompt cursing (folio 8)
inline bool wrmTreasureFindingDoctrine()
    { return true; }

// ---- the spell effect details (folios 4-7) ----

// the witch's Summon Elemental - the elemental has 12 hit dice (folio 4)
inline int wrmWitchElementalHd()
    { return 12; }

// the elemental appears the turn after it has been summoned (folio 4)
inline int wrmWitchElementalDelayTurns()
    { return 1; }

// the elemental vanishes if the witch loses her concentration (folio 4)
inline bool wrmWitchElementalConcentration()
    { return true; }

// the Wither - all living plants and creatures within a 50-foot diameter
// circle rapidly age and die (folio 7)
inline int wrmWitherCircleFeet()
    { return 50; }

// the Weight Concentration/Dilution - from 1 (folio 7)
inline int wrmWeightAffectedMin()
    { return 1; }

// the Weight Concentration/Dilution - up to 10 creatures or objects affected
// (folio 7)
inline int wrmWeightAffectedMax()
    { return 10; }

// the witch may triple a target's weight or cut it to one-third, chosen per
// target (folio 7)
inline int wrmWeightFactor()
    { return 3; }

// the Volcanic Circle - the lava flows outward from the witch at 4 feet per
// turn, the radius growing 4 feet per turn (folio 7)
inline int wrmVolcanicFlowFeet()
    { return 4; }

// the Volcanic Circle - the line remains 10 feet thick as it expands, never
// thinning (folio 7)
inline int wrmVolcanicLineFeet()
    { return 10; }

// a ground creature caught and passed under by the molten rock takes 10 dice
// of damage unless immune to ordinary fire (folio 7)
inline int wrmVolcanicDamageDice()
    { return 10; }

// the Reflections - for two turns no magic can harm the witch, and any spell,
// potion or magic device used against her returns to the attacker regardless
// of range (folio 7)
inline int wrmReflectionsTurns()
    { return 2; }

// the Reflections reflect everything except Banish, Disintegrate and the
// sense magics such as ESP, Detect Evil and Clairaudience (folio 7)
inline bool wrmReflectionsExceptions()
    { return true; }

// the Solidify - the atmosphere coagulates into rock in one-half turn; true
// matter unaffected by Dispell Magic or Dissipation, but slightly porous so
// the trapped may still breathe (folio 7)
inline bool wrmSolidifyTrueMatter()
    { return true; }

// the Undead Control - from 1 undead character of any type (folio 5)
inline int wrmUndeadControlMin()
    { return 1; }

// the Undead Control - up to 6 undead characters of any type within the
// 10-inch radius (folio 5)
inline int wrmUndeadControlMax()
    { return 6; }

// the Undead Control may be maintained at any range if the witch has a
// crystal ball with her, though the spell must be established within 10
// inches (folio 5)
inline bool wrmUndeadControlCrystalBall()
    { return true; }

// the Curse - anything more than 75 percent enclosed by silver is safe; a
// silver helmet, shield and plate would protect, a single silver piece would
// not (folio 5)
inline int wrmCurseSilverPct()
    { return 75; }

// the Curse - it is not possible to curse a creature with immediate death;
// holy items, enchanted items and the witchcraft-immune are also safe (folio
// 5)
inline bool wrmCurseNoImmediateDeath()
    { return true; }

// the Poison Touch - the first 3 objects handled by the witch are permanently
// contaminated, or a 4-by-4-foot flat surface (folio 5)
inline int wrmPoisonTouchObjects()
    { return 3; }

// the Poison Touch contamination - after two turns of contact the victim
// dies; gloves protect (folio 5)
inline int wrmPoisonTouchDeathAfterTurns()
    { return 2; }

// a poisoned item identified and treated with a Neutralize Poison spell
// becomes harmless again; holy items, silver and magic objects may not be
// poisoned (folio 5)
inline bool wrmPoisonTouchNeutralizable()
    { return true; }

// the Curtain Wall - a curtain 10 feet wide floats vertically just off the
// ground (folio 5)
inline int wrmCurtainWidthFeet()
    { return 10; }

// the Curtain Wall room - 10 feet high and wide, 20 feet from back wall to
// front curtain (folio 5)
inline int wrmCurtainRoomDepthFeet()
    { return 20; }

// the Curtain Wall - the witch's will is great and two control agents are
// required simultaneously to force her to summon her lair (folio 5)
inline bool wrmCurtainTwoAgents()
    { return true; }

// the Fire Box - a hollow 10-foot cube of fire forms about the target and
// remains six turns (folio 5)
inline int wrmFireBoxCubeFeet()
    { return 10; }

// the Fire Box - destroyed by cold, rain or magic; it moves with the object
// it surrounds and does not suffocate or harm what is trapped inside (folio
// 5)
inline bool wrmFireBoxElements()
    { return true; }

// the Diminish - successive uses reduce a target to 1/2, then 1/4, 1/8 and so
// on of its original size (folio 5)
inline bool wrmDiminishHalving()
    { return true; }

// the Circle of Blindness - all creatures within 25 feet of the impact point
// are affected, a 50-foot circle (folio 5)
inline int wrmBlindnessRadiusFeet()
    { return 25; }

// the Circle of Blindness exempts Djinn, Efreet, Clerics and witches; it
// counteracts vision, hearing, ESP, detection magic and devices alike (folio
// 5)
inline bool wrmBlindnessExceptions()
    { return true; }

// ---- the Friedman elf sub-race table (folio 14) ----

// the Friedman elf sub-race table row count - 3 rows: the Silvan, the Sindar
// and the Noldor (folio 14)
inline int wrmElfSubraceCount()
    { return 3; }

// the elf sub-race check - a 20-sided die, per the Friedman letter to Out On
// A Limb (folio 14)
inline int wrmElfTableDieSides()
    { return 20; }

// the elf sub-race table carries the editorial endorsement in print - "Sounds
// good to me - any objections out there? Ed." (folio 14)
inline bool wrmElfTableEditorEndorsed()
    { return true; }

// the honest boundary - Silvan, Sindar and Noldor are Tolkien's sub-race
// names, echoed in D&D's Wood, Grey and High elf convention; the variant
// layer carries the provenance, never core canon (folio 14)
inline bool wrmElfTableTolkienNames()
    { return true; }

// the die band minimum by sub-race - Silvan from 1, Sindar from 17, Noldor at
// 20 (folio 14)
inline int wrmElfSubraceMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 17;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

// the die band maximum by sub-race - Silvan to 16, Sindar to 19, Noldor at 20
// (folio 14)
inline int wrmElfSubraceMax(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 19;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

}   // namespace rules
