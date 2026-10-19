// =========================================================================================
// Adnd1 - rules/oaweaponspec.h
// WEAPON PROFICIENCIES AND SPECIALIZATION, printed capture pp. 99-101 - the
// OA proficiencies arc opener
// census 572 -> 573.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the section -
// the chapter opener intro on capture p. 99 and the weapon proficiencies and
// specialization prose on pp. 100-101 of the print pass, cross-checked
// paragraph-by-paragraph between the two passes (compressed pp. 52-53); every
// printed number agrees. One OCR artifact class: the compressed pass
// systematically renders the specialization bonuses with minus signs - the
// +1/+2 melee, the +3 double, the +2/+2 and +1 bow reads all print as
// negatives - and each such read contradicts its own sentence (an increase to
// a bonus, a doubled base damage), so the print + signs stand per the R643
// pattern; likewise the print pocked read of the arrow-ready doctrine is a
// letter slip, settled as nocked. The Chapter 6 parent box opens this round
// with the proficiency slot system pinned: all characters receive slots at
// 1st level, some or all fillable with weapon training and the rest with
// other skills, unfilled slots saveable, and a selected proficiency never
// changed for any reason. The specialization doctrine pins as consts and
// bools: a weapon proficiency costs one slot; only samurai and bushi
// specialize; the bushi any-one-weapon at-creation rule and the samurai
// katana-and-bow two-weapon rule (the katana at creation, the bow delayable);
// melee or crossbow specialization costs two slots, other missile weapons
// three; unarmed combat cannot be a weapon proficiency except under a master;
// the specific-type-not-general-class rule; the melee specialist +1 to hit
// and +2 damage, the iaijutsu fast-draw benefit, the next-higher-rank
// multiple-attack rule with the 3/2 first-level and 2/1 fifth-level samurai
// examples, and double specialization at one more slot for +3 to hit and
// damage. The bow specialist gains the point blank band (5 to 30 feet, +2 to
// hit and damage, the base damage doubled with strength and magic added to
// the final total), +1 at short range, no special bonus at medium and longer,
// no damage bonuses beyond point blank, and the ready-arrow auto-fire before
// initiative; the crossbow specialist the same point blank benefits within 5
// to 60 feet, +1 to hit and damage at short range, +1 to hit at medium, and
// the same ready benefit; other missile specialists +1 to hit and +2 damage,
// with the higher-level extra attacks listed on Table 57 (its own box) and
// the per-class numbers on Table 56 (likewise). The p. 101 restrictions pin:
// class-disallowed weapons usable at the non-proficiency penalty (worst for
// split class) but never kept and carried; the under-5-feet 12-foot
// weapon-length bound; the under-4-feet daikyu ban; and the under-100-pounds
// heavy crossbow, over-200-gp and two-handed-sword bans - prohibitions that
// override the penalty since the weapons cannot be wielded at all
//
// the gap census after this round: 102 closed, 133 open - the Chapter 6
// parent box opens and the weapon proficiencies and specialization prose box
// flips (census 572 -> 573); NEXT - R651: Table 57 (Missile Weapon
// Specializations), capture p. 100, the specialist attacks-per-round grid,
// prefix dhl (verify free), audit "R651 OA missile specializations audit",
// include after rules/oaweaponspec.h
//
namespace rules {

// ---- the proficiency slot system pins ----

// all characters receive their number of proficiency slots at 1st level
// (capture p. 99 of the print pass; compressed p. 52)
inline int dhkSlotsAtFirstLevel()
    { return 1; }

// the artistic and peaceful skills are as important to a character as his
// ability to fight - the society emphasizes creative talents almost as much
// as combat prowess (capture p. 99 of the print pass; compressed p. 52)
inline bool dhkPeacefulAsImportant()
    { return true; }

// depending on the character's class, some or all slots can be filled with
// weapon training, and any not devoted to weapons can be filled with other
// skills (capture p. 99 of the print pass; compressed p. 52)
inline bool dhkSlotsWeaponOrPeaceful()
    { return true; }

// the character is not required to fill all his proficiency slots - those not
// filled can be saved and used at a later time (capture p. 99 of the print
// pass; compressed p. 52)
inline bool dhkSlotsSaveable()
    { return true; }

// once a proficiency has been selected it cannot be changed for any reason
// (capture p. 99 of the print pass; compressed p. 52)
inline bool dhkNoChangeAfterSelection()
    { return true; }

// each weapon proficiency costs one proficiency slot from those the character
// has available (capture p. 100 of the print pass; compressed p. 52)
inline int dhkWeaponProfSlotCost()
    { return 1; }

// unarmed combat cannot be taken as a weapon proficiency unless the character
// is studying under a master (capture p. 100 of the print pass; compressed p.
// 52)
inline bool dhkUnarmedNeedsMaster()
    { return true; }

// only samurai and bushi can choose to use weapon specialization (capture p.
// 100 of the print pass; compressed p. 52)
inline bool dhkOnlySamuraiBushiSpec()
    { return true; }

// the bushi can choose any one weapon to specialize in, the selection made as
// soon as the character is created, except for samurai (capture p. 100 of the
// print pass; compressed p. 52)
inline bool dhkBushiOneWeapon()
    { return true; }

// only the samurai can specialize in two weapons at once - the katana and the
// bow; he must specialize in the katana as soon as created but can delay the
// bow for a later time (capture p. 100 of the print pass; compressed p. 52)
inline bool dhkSamuraiKatanaBow()
    { return true; }

// weapon specialization in any melee weapon or crossbow counts as two
// proficiency slots (capture p. 100 of the print pass; compressed p. 52)
inline int dhkSpecMeleeSlots()
    { return 2; }

// specialization in any other missile weapon counts as three proficiency
// slots (capture p. 100 of the print pass; compressed p. 52)
inline int dhkSpecMissileSlots()
    { return 3; }

// melee specialization must be a specific weapon type, not a general class of
// weapons - the katana yes, all swords no (capture p. 100 of the print pass;
// compressed p. 52)
inline bool dhkSpecSpecificType()
    { return true; }

// ---- the melee specialist pins ----

// the melee specialist is +1 on to hit rolls with the specialized weapon
// (capture p. 100 of the print pass; compressed p. 52, where the minus read
// is the plus-as-minus OCR artifact)
inline int dhkMeleeSpecHit()
    { return 1; }

// the melee specialist is +2 on damage rolls with the specialized weapon
// (capture p. 100 of the print pass; compressed p. 52)
inline int dhkMeleeSpecDmg()
    { return 2; }

// the specialist has learned the art of iaijutsu, the fast draw, with the
// specialized weapon and receives the benefits explained under that
// proficiency (capture p. 100 of the print pass; compressed p. 52)
inline bool dhkSpecGivesIaijutsu()
    { return true; }

// the specialist can make extra multiple attacks beyond those given on the
// Multiple Attacks Table, utilizing the next higher rank when fighting with
// his specialized weapon (capture p. 100 of the print pass; compressed p. 52)
inline bool dhkSpecNextAttackRank()
    { return true; }

// a first-level samurai makes 3/2 attacks per round with his specialized
// weapon - the numerator of the printed example (capture p. 100 of the print
// pass; compressed p. 52)
inline int dhkSpecFirstAttNum()
    { return 3; }

// the 3/2 denominator of the first-level attack example (capture p. 100 of
// the print pass; compressed p. 52)
inline int dhkSpecFirstAttDen()
    { return 2; }

// at fifth level the same character makes 2 attacks per round with his
// specialized weapon - the numerator (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhkSpecFifthAttNum()
    { return 2; }

// the 2/1 denominator of the fifth-level attack example (capture p. 100 of
// the print pass; compressed p. 52)
inline int dhkSpecFifthAttDen()
    { return 1; }

// an additional proficiency slot spent to double specialize once the
// character advances beyond 1st level (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhkDoubleSpecSlotCost()
    { return 1; }

// double specialization increases the bonus to +3 on to hit (capture p. 100
// of the print pass; compressed p. 52)
inline int dhkDoubleSpecHit()
    { return 3; }

// double specialization increases the bonus to +3 on damage (capture p. 100
// of the print pass; compressed p. 52)
inline int dhkDoubleSpecDmg()
    { return 3; }

// ---- the missile specialist pins ----

// the bow specialist's point blank range begins at 5 feet (capture p. 100 of
// the print pass; compressed p. 52)
inline int dhkBowPointBlankMin()
    { return 5; }

// the point blank range extends to 30 feet (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhkBowPointBlankMax()
    { return 30; }

// the bow specialist is +2 to hit at any target within point blank (capture
// p. 100 of the print pass; compressed p. 52)
inline int dhkBowPointBlankHit()
    { return 2; }

// the bow specialist is +2 damage at any target within point blank (capture
// p. 100 of the print pass; compressed p. 52)
inline int dhkBowPointBlankDmg()
    { return 2; }

// at short range the bow specialist is +1 on his to hit rolls (capture p. 100
// of the print pass; compressed p. 52)
inline int dhkBowShortHit()
    { return 1; }

// the base damage done at point blank is automatically doubled; bonuses to
// damage for strength and magic are not doubled - they are added to the final
// total (capture p. 100 of the print pass; compressed p. 52)
inline bool dhkBowPointBlankDmgDoubled()
    { return true; }

// at medium range and longer the bow specialist has no special bonus to hit,
// and at all ranges beyond point blank there are no bonuses to damage
// (capture p. 100 of the print pass; compressed p. 52)
inline bool dhkBowNoBonusBeyond()
    { return true; }

// a bow specialist who begins the round with his arrow ready - nocked, drawn
// and aimed on a target - can automatically fire before any initiative check
// is made (capture p. 100 of the print pass; compressed p. 52; the print
// pocked read is a letter slip, settled as nocked)
inline bool dhkBowReadyFiresFirst()
    { return true; }

// the crossbow specialist's point blank range begins at 5 feet (capture p.
// 100 of the print pass; compressed p. 52)
inline int dhkXbowPointBlankMin()
    { return 5; }

// the crossbow point blank range extends to 60 feet (capture p. 100 of the
// print pass; compressed p. 52)
inline int dhkXbowPointBlankMax()
    { return 60; }

// within point blank the crossbow specialist receives the same benefits as a
// bow specialist, including the weapon-ready benefit at the start of the
// round; the multiple attacks depend on the type of crossbow (capture p. 100
// of the print pass; compressed p. 52)
inline bool dhkXbowPointBlankSame()
    { return true; }

// at short range the crossbow specialist is +1 on to hit rolls (capture p.
// 100 of the print pass; compressed p. 52)
inline int dhkXbowShortHit()
    { return 1; }

// at short range the crossbow specialist is +1 on damage rolls (capture p.
// 100 of the print pass; compressed p. 52)
inline int dhkXbowShortDmg()
    { return 1; }

// at medium range the crossbow specialist is +1 on his chances to hit
// (capture p. 100 of the print pass; compressed p. 52)
inline int dhkXbowMediumHit()
    { return 1; }

// specializing in other missile weapons gains +1 on to hit rolls (capture p.
// 100 of the print pass; compressed p. 52)
inline int dhkOtherMissileHit()
    { return 1; }

// specializing in other missile weapons gains +2 on damage (capture p. 100 of
// the print pass; compressed p. 52)
inline int dhkOtherMissileDmg()
    { return 2; }

// ---- the weapon restriction pins ----

// weapons not permitted to a class may be picked up and used, but the
// non-proficiency penalty for that class always applies - the worst penalty
// for split class characters - and such disallowed weapons cannot be kept and
// carried by the character for use later (capture p. 101 of the print pass;
// compressed p. 53)
inline bool dhkClassNonprofApplies()
    { return true; }

// characters under 5 feet in height cannot effectively use any weapon over 12
// feet in length - the height bound (capture p. 101 of the print pass;
// compressed p. 53)
inline int dhkHeightLimitFeet()
    { return 5; }

// the weapon-length bound of the under-5-feet rule (capture p. 101 of the
// print pass; compressed p. 53)
inline int dhkWeaponLenLimitFeet()
    { return 12; }

// characters under 4 feet in height cannot use the daikyu, the great bow
// (capture p. 101 of the print pass; compressed p. 53)
inline int dhkDaikyuHeightFeet()
    { return 4; }

// characters of less than 100 pounds body weight cannot use a heavy crossbow,
// any weapon weighing more than 200 gp, or a two-handed sword - the weight
// bound (capture p. 101 of the print pass; compressed p. 53)
inline int dhkBodyWeightPounds()
    { return 100; }

// the weapon-weight bound of the under-100-pounds rule, in gold-piece weight
// (capture p. 101 of the print pass; compressed p. 53)
inline int dhkHeavyWeaponGp()
    { return 200; }

// the height and weight prohibitions override the non-proficiency stipulation
// - the penalty is immaterial, since these weapons cannot be wielded at all
// (capture p. 101 of the print pass; compressed p. 53)
inline bool dhkProhibitionsOverride()
    { return true; }

}   // namespace rules
