// =========================================================================================
// Adnd1 - rules/appendixiiioutercreatures.h
// APPENDIX III: CREATURES FROM THE OUTER PLANES - printed pp. 122-123, the
// new-creature summary: the einheriar spirit legions with their class and
// level dies and seven named hosts, Rudra's maruts, the mortal cloud of the
// Beastlands, and the five archons from the reforming lanterns to the
// radiance-handed tomes.
// census 517 -> 518.
//
// verified against printed pp. 122-123 of the uploaded motp.pdf OCR; the stat
// blocks and special abilities are pinned exactly as printed (the infravision
// and bracers restored against the OCR slips, legend lore restored); Appendix
// IV: Abilities of the Powers is left for the round that owns it.
//
// the gap census after this round: 88 closed, 2 open - ONE box falls
// (Appendix III); only the Abilities of the Powers and the indices remain.
//
namespace rules {

// ---- the appendix iii outer creatures pins ----

// the einheriar (spirit legions): common on the planes where they exist,
// 10d10 appearing (the general patrol figure, the numbers varying by plane),
// AC by type, move 12, HD varying, 0% in lair, no treasure, 2 attacks by
// weapon, 5% magic resistance, low-to-high intelligence, size M, alignment
// that of the plane encountered in - properly the glorious dead of Asgard,
// but the general name for humanoid spirits employed in the outer planes as
// servants, warriors, patrols or guards, primarily in the neutral-to-good
// planes and much less common in the lower.
inline int ddzEinheriarPatrolDice()
    { return 10; }

// the einheriar kit: a 5% chance per level of magical armor and weapons with
// no special functions - typically plate +1 or +2 and a +1 weapon for
// fighters, bracers of defense (AC 4) and a wand for magic-users; no items
// with exceptional functions (armor of etherealness, a flametongue sword);
// generally immune to fear, and if slain returning after a set time to their
// duties (usually a standard day), following the directives of their Power or
// its lieutenants without question or hesitation.
inline int ddzEinheriarMagicPctPerLevel()
    { return 5; }

// the maruts: servants of Rudra usually found on his disk in Nirvana
// (uncommon in Rudra's Chasm, very rare elsewhere in Nirvana or the Primes),
// 1d10 appearing, AC 0, move 15/24, 15 HD, 10% in lair, treasure H, one
// attack for 8d10, 10% magic resistance, high intelligence, lawful with good
// tendencies, size L - appearing as great red-eyed unliving giants carved
// from polished black stone, dressed in gold armor with wide shoulder plates
// and armbands; once every hour a marut can cast an earthquake, hurl a 15-die
// lightning bolt, or control winds.
inline int ddzMarutHourlyPowers()
    { return 1; }

// the archon common powers: the primary inhabitants of the Seven Heavens, the
// armies of good and Law - in addition to their listed abilities all archons
// have continual light, infravision and ultravision, tongues, and
// teleportation without error (the four common powers).
inline int ddzArchonCommonPowers()
    { return 4; }

// the lantern archons: common on the native plane, 2d10 appearing, AC 10,
// move 12, HD 1/2, 0% in lair, two attacks for 1d3 each, low intelligence,
// lawful good, size S (about 1d3 feet diameter) - spherical bubbles radiating
// a soft glow, not true archons but proto-archons from whom the archons draw
// their recruits; unaffected by nonmagical weapons, and if slain reforming in
// a single day.
inline int ddzLanternReformDay()
    { return 1; }

// the sword archons: rare, 1d4 appearing, AC -5, move 12/24, 12 HD, 15% in
// lair, treasure F, four attacks for 2d4 or by weapon, 70% magic resistance,
// exceptional intelligence, size L (7 and a half feet tall) - humanoids with
// feathered wings and cat heads, casting as 15th-level magic-users or clerics
// (50% each), able to gate in 1d6 hound archons or 1d3 warden archons each
// turn, carrying only one weapon yet attacking four times a round, and only
// hit by weapons of +2 or better.
inline int ddzSwordGateTurn()
    { return 6; }

// the einheriar class and level dies: class - 1-40 fighter, 41-45 ranger or
// fighter, 46-50 cavalier or fighter, 51-65 barbarian or fighter, 66-85
// cleric, 86-90 thief or fighter, 91-98 magic-user, 99-00 bard; level - 1-50
// level 4, 51-75 level 5, 76-88 level 6, 89-94 level 7, 95-97 level 8, 98
// level 9, 99 level 10, 00 levels 11-16; if the plane's alignment precludes
// certain classes, another roll is made - and they are armed and armored as
// best for their class, in the style of the Power they serve.
inline bool ddzEinheriarTables()
    { return true; }

// the einheriar hosts: the Soldiers of Anu in Arcadia, the Horusyr (with the
// additional ability to shape change into giant hawks), the dwarvish host of
// Clanggedin, the spirit folk of Arcadia and Elysium, the Hindari, the
// Einheriar of Valhalla, and the Spirit Legions of Acheron - particular
// einheriar under specific Powers granted additional abilities, the Horusyr
// shape change the printed example.
inline bool ddzEinheriarHosts()
    { return true; }

// the mortal: uncommon in the Happy Hunting Grounds, one appearing, AC -5,
// move 48, 20 HD, 100% in lair, no treasure, one attack for 10d6, 50% magic
// resistance, godlike intelligence, neutral good with chaotic tendencies,
// size L, psionic ability undetermined or none - appearing as huge clouds
// with the faces of humans, humanoids or other creatures, glowing with a
// pulsing golden light in the deepest levels of Arcadia and tending to ignore
// most ground activity; special abilities: legend lore at will without
// penalty or time requirements, and the use of all spells utilizing air,
// wind, weather or clouds (including cloudkill) at will.
inline bool ddzMortalRule()
    { return true; }

// the hound and warden archons: hounds common in the Seven Heavens, 1d6
// appearing, AC 1, move 15, 9 HD, 10% in lair, treasure C, three attacks for
// 1d4/1d4/1d8 or by weapon, 40% magic resistance, average intelligence, size
// M - humans with dog-like heads and powerful fists striking twice with fists
// and biting in the same round; shape change into dog or wolf, detect
// invisible astral and ethereal creatures at will, only hit by +1 or better
// magical weapons. Wardens uncommon, 1d6 appearing, AC -1, move 12, 10 HD,
// 10% in lair, treasure B, three or two attacks for 1d8/1d8/2d6 or by weapon,
// 50% magic resistance, high intelligence, size L - bears with human hands
// and intelligent eyes; all divination spells, only hit by weapons of +2 or
// better.
inline bool ddzHoundWardenRule()
    { return true; }

// the tome archons: very rare, 1d3 appearing, AC -5, move 12/24, 10 HD, 0% in
// lair, no treasure, two attacks for 1d10 each, 75% magic resistance, genius
// intelligence, size L (8 feet tall) - hawk-headed winged humanoids; the
// special abilities: all divination, alteration and beneficial necromantic
// magic, one of each per day; a radiance from the hands inflicting 2d10
// points of damage to all in its path (a 6-inch-long cone 3 inches wide at
// the base); affecting undead as a 20th-level cleric; and only hit by weapons
// of +2 or better.
inline bool ddzTomeRule()
    { return true; }

}   // namespace rules
