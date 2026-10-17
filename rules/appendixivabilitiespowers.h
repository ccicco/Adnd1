// =========================================================================================
// Adnd1 - rules/appendixivabilitiespowers.h
// APPENDIX IV: ABILITIES OF THE POWERS - printed pp. 124-126, the divine
// ladder: the four ability types and the sixteen at-will standard powers, the
// 30/20/15 magic levels and 4/3/2 command durations, the Greater
// six-and-three, Lesser four-and-two, Demi three-and-one daily groups, the
// wish limits, and the native heights from the vapor-reforming Greater to the
// soul-objected Lesser and the cord-cutting Demi.
// census 518 -> 519.
//
// verified against printed pp. 124-126 of the uploaded motp.pdf OCR (OCR
// pages 125-127); the tables are pinned exactly as printed, with regenerate
// restored from the OCR 'Regenarate'; the Indices are left for the round that
// owns them.
//
// the gap census after this round: 89 closed, 1 open - ONE box falls
// (Appendix IV); only the indices remain before the MotP report closes at
// 90/0.
//
namespace rules {

// ---- the appendix iv powers abilities pins ----

// the level of magic use: a Greater Power casts as a 30th-level caster
// (Lesser 20th, Demi 15th) where caster level is involved, unless the Power
// already has a defined level of spell use for the type of spell - a
// Demi-Power given 20th-level magic-user abilities casts remove curse at
// 20th, not 15th.
inline int debGreaterMagicLevel()
    { return 30; }

// the command durations by rank: the spell lasts four rounds for Greater
// Powers, three for Lesser (debLesserCommandRounds), two for Demi
// (debDemiCommandRounds), with no saving throw for followers or believers of
// that Power.
inline int debGreaterCommandRounds()
    { return 4; }

// command lasts three rounds for a Lesser Power - the middle rung of the
// 4/3/2 ladder, functioning as the spell of the same name with the no-save
// restriction for the faithful.
inline int debLesserCommandRounds()
    { return 3; }

// command lasts two rounds for a Demi-Power - the bottom rung of the 4/3/2
// ladder, still unsaveable for followers and believers.
inline int debDemiCommandRounds()
    { return 2; }

// the protection radii: protection from evil/good and protection from
// cantrips extend 30 feet for Greater Powers, 20 for Lesser, 10 for Demi -
// the aura thinning with the rank.
inline int debProtectionRadiusGreater()
    { return 30; }

// the Greater Power daily groups: any of the at-will eight (atonement, quest,
// fly, improved invisibility, improved phantasmal force, mirror image,
// mislead, regenerate); no more than six per day of the fourteen-item group
// (anti-magic shell through summon); no more than three per day of the
// eleven-item group (debth spell, gate, restoration, resurrection, symbol
// all, vision, wish, volley, time stop, holy/unholy word, heal).
inline int debGreaterDailyLimit()
    { return 6; }

// the Lesser Power daily groups: alter self, improved phantasmal force,
// improved invisibility and mirror image at will; no more than four per day
// of the nine-item group (anti-magic shield through true seeing); no more
// than two per day of the ten-item group.
inline int debLesserDailyLimit()
    { return 4; }

// the Demi-Power daily groups: alter self, invisibility and phantasmal force
// at will; no more than three per day of the four-item group (cure light
// wounds, dispel evil/good, dispel illusion, dispel magic); no more than one
// per day of the twelve-item group (anti-magic shell through holy/unholy
// word, including the limited wish).
inline int debDemiDailyLimit()
    { return 3; }

// the Greater Power summon: 2d6 creatures of the same alignment as the Power,
// total hit dice not exceeding 40 (debGreaterSummonHD) - ten creatures called
// for means a maximum of four hit dice each.
inline int debGreaterSummonDice()
    { return 2; }

// the 40-hit-dice cap on the Greater Power's 2d6 summon - the
// alignment-matched reinforcements whose total may not exceed the cap however
// the dice divide.
inline int debGreaterSummonHD()
    { return 40; }

// the Lesser Power summon: 1d6 creatures of no more than 30 total hit dice -
// half again short of the Greater standard.
inline int debLesserSummonHD()
    { return 30; }

// the Demi-Power summon: 1d3 creatures of no more than 20 total hit dice, of
// the same alignment as the Demi-Power - the humblest calling.
inline int debDemiSummonHD()
    { return 20; }

// the four ability types: specialized abilities belonging to a particular
// Power and listed in that Power's description (Zeus's lightning bolt each
// round); standard divine abilities available to all Powers at will unless
// otherwise noted; individual divine abilities shared by all Powers of the
// same rank; native divine abilities - the individual set usable only on the
// Power's native plane.
inline bool debAbilityTypes()
    { return true; }

// the sixteen standard divine abilities used at will: astral travel (physical
// or projected per the plane's limits), command, continual light/darkness,
// cure, detect, ethereal travel, enlarge up to 300%, geas, levitate,
// polymorph self, protection from cantrips, protection from evil/good,
// sending (no failure cross-planar to a follower or believer), teleport
// without error, understand languages (tongues plus comprehend, read
// languages and read magic, usable with other abilities), vocalize.
inline bool debStandardAbilities()
    { return true; }

// the standard-list contents, one at a time at will: cure covers cure
// blindness, cure disease, cure insanity, remove fear, cure debfness, cure
// feeblemind, remove curse, remove paralysis; detect covers detect balance,
// detect evil/good, detect invisibility, detect life, detect poison, know
// alignment, detect charm, detect illusion, detect lie, detect magic, detect
// traps - and the Powers also use the reverses, in particular the
// undetectable lie, in their deblings with mortals.
inline bool debCureDetectLists()
    { return true; }

// the ethereal travel rule: a Power enters the Ethereal plane if the present
// plane permits; Lesser and Greater Powers can travel through areas of the
// Border Ethereal occupied by the fields of living creatures but cannot leave
// the Border Ethereal into the same space as a living creature - and the
// teleport-without-error caveat, that Powers with other interplanar means
// avoid it for its inherent dangers.
inline bool debEtherealTravelRule()
    { return true; }

// the wish limits among the Powers: granted only to inhabitants of the Prime
// Material planes (one reason those planes are central to the wheeling and
// debling), unable to affect any other Power in his home plane, unable to
// affect the granting Power in any way - violations simply have no effect;
// Lesser Powers grant as Greater do, save that a failed vision can force them
// into servitude to a Greater Power; Demi-Powers grant limited wishes on the
// same terms and suffer every malefic side effect of what they use.
inline bool debWishRules()
    { return true; }

// the Greater Power in his home plane: the six-a-day group at will and the
// three-a-day group six times a day, hit points doubled, the Power and all
// nonliving objects of his domain 120% magic resistant (spells affect him
// only by his permission - tricking him is possible but very dangerous),
// senses always extended into the Astral and Border Ethereal, untouched by
// conjuration, summoning or necromantic spells unless he wishes, unslayable
// at home - reduced to 0 hit points he turns to sparkling vapor reforming in
// a tenth of a standard day, banned from the slayer's plane for 100 years (10
// if slain by a native of his own plane, and 10 years if slain elsewhere),
// sealer of nonpermanent color pools and puller of Astral or Ethereal
// observers, the modifier of up to twenty spells of no more than 100 total
// levels within his domain, the severer of silver cords (AC -5, magic
// resistance roll, automatic in his domain), and the creator of Aspects -
// lesser gods generated in a tenth of a year, during which he cannot
// physically leave the domain.
inline bool debGreaterNativePowers()
    { return true; }

// the Lesser Power in his home plane: the four-a-day group at will and the
// two-a-day group four times a day, hit points doubled on the native layer
// alone, the Power and his domain 100% magic resistant, senses reaching the
// Ethereal and Astral only by conscious look, permanently slayable in his
// home plane (slain elsewhere he is merely banished for 100 years), sealer of
// nonpermanent color pools and puller of Astral observers, modifier of twenty
// spells of no more than 80 spell levels (usable to reinstate spells the
// plane forbids, though not all Lesser Powers bother), attempted severer of
// the silver cord, and creator of a soul object - the single artifact-status
// device, the wand of Orcus or a lord's talisman, that houses his spirit and
// makes him a Greater Power in his home plane for purposes of being slain;
// hence the jealous guard.
inline bool debLesserNativePowers()
    { return true; }

// the Demi-Power in his home plane: the three-a-day group four times a day
// and the one-a-day group twice a day, the Power and his personal effects
// (not the domains) 80% magic resistant unless normally higher, the observer
// of the Ethereal and Astral who can take no other action while looking,
// slayable in his home plane - the debth permanent unless reversed by a
// greater authority, for a Demi-Power can be raised, the opaque-color-pool
// maker, and the attempted cord-cutter in the Greater fashion.
inline bool debDemiNativePowers()
    { return true; }

}   // namespace rules
