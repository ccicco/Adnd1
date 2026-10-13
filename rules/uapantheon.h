// ===========================================================================
// Adnd1 - rules/uapantheon.h
// The UA APPENDIX S PANTHEON
// PROSE, R423: the five pantheon
// intro sections (pp. 110-120)
// - the last open Appendix S item.
// The sixth data round riding the
// R406 stat-block precedent; the
// clean OCR read pins the prose-
// level facts with the censuses
// cross-checked LIVE against the
// R405 seam (the described counts
// mirror nhdPantheonSize row for
// row, the sum mirrors the 23).
// Pin-era pattern (R322).
//
// The judgment: the intro prose
// reads scan-clean - no flagged
// holes, no sentinels; every pin
// below is the printed text.
namespace rules {

// ---- the dwarven intro ----

// One of the most powerful of
// all the non-human pantheons.
inline bool uapnDwarfIntroPowerful()
    { return true; }
// The greater dwarven gods are at
// least twice as large as normal
// dwarves.
inline int uapnDwarfGreaterSizeMin()
    { return 2; }
// Ranging up to Moradin's 20-foot
// height.
inline int uapnDwarfMoradinFeet()
    { return 20; }
// No dwarven deity is taller than
// Moradin, the Soul Forger.
inline bool uapnDwarfMoradinTallest()
    { return true; }
// Demigods are roughly normal
// dwarven height.
inline bool uapnDwarfDemigodNormalH()
    { return true; }
// The holy symbols are invariably
// not living objects.
inline bool uapnDwarfSymbolNoLife()
    { return true; }
// The symbol categories: tools,
// weapons, mountains, minerals -
// four.
inline int uapnDwarfSymbolCats()
    { return 4; }
// Moradin ruled the dwarves must
// hold no other race above them.
inline bool uapnDwarfNoRaceAbove()
    { return true; }
// Moradin said dwarves should not
// ever worship each other.
inline bool uapnDwarfNoDwarfWorship()
    { return true; }
// All dwarven gods possess dual
// charismas.
inline bool uapnDwarfDualCharisma()
    { return true; }
// Five commonly accepted deities
// are described in the text.
inline int uapnDwarfDescribed()
    { return 5; }
// The lesser-deity spheres:
// fighting and warfare,
// guardianship, the earth, metals,
// craftsmanship, volcanoes and
// earthquakes, fire and lava, the
// protection of the dead,
// medicine, strength - ten.
inline int uapnDwarfSpheres()
    { return 10; }
// The absent spheres: the sea, the
// air and atmospheric phenomena,
// plant life and forests, comedy,
// animals, chaos - six.
inline int uapnDwarfSpheresAbsent()
    { return 6; }
// Dwarves on rare occasions worship
// other pantheons: Goibhnie (the
// Celtic) and Hephaestus (the
// Greek) - two.
inline int uapnDwarfCrossMythos()
    { return 2; }
// The cross-mythos draw: powers of
// smith-work and the earth.
inline bool uapnDwarfCrossIsSmith()
    { return true; }

// ---- the elven intro ----

// The elven pantheon is primarily
// located on one of the planes of
// Olympus, in an area known as
// Arvandor, "The High Forest."
inline bool uapnElfHomeArvandor()
    { return true; }
// The collective name: the
// Seldarine.
inline bool uapnElfCollectiveName()
    { return true; }
// The Seldarine roughly translates
// as the fellowship of brothers and
// sisters of the wood.
inline bool uapnElfFellowship()
    { return true; }
// Of all the Seldarine, only
// Corellon Larethian is a greater
// god.
inline bool uapnElfSoleGreater()
    { return true; }
// None are evil.
inline bool uapnElfNoneEvil()
    { return true; }
// A very few are lawful - two or
// three at the most.
inline int uapnElfLawfulMax()
    { return 3; }
// Corellon compels none of them to
// perform any task.
inline bool uapnElfCorellonCompels()
    { return false; }
// The tolerance example: the cult
// of Skerrit the Forester.
inline bool uapnElfSkerritExample()
    { return true; }
// Elven deities in elven form are
// usually between 4 and 8 feet
// tall.
inline int uapnElfHeightMin()
    { return 4; }
inline int uapnElfHeightMax()
    { return 8; }
// The color reads: Rillifane the
// oak and bark-armored elf, Deep
// Sashelas sea-green, Aerdrie
// deep blue like the sky.
inline bool uapnElfColorReads()
    { return true; }
// Evil elvenkind worship the demon
// princes and arch-devils; Lolth
// the demon queen of spiders takes
// power from the drow.
inline bool uapnElfLolthDrowSeam()
    { return true; }
// The smaller elf-like beings have
// their own demigod-level
// deities.
inline bool uapnElfSmallOwnGods()
    { return true; }
// Half-elves may worship any god
// in the Seldarine and may become
// clerics or druids of them; a
// fair number honor Hanali Celanil.
inline bool uapnElfHalfElfCleric()
    { return true; }
inline bool uapnElfHalfElfHanali()
    { return true; }
// Five deities are described.
inline int uapnElfDescribed()
    { return 5; }
// The sphere census (among others):
// elvenkind, nature, magic, dancing
// and play, love, beauty, time,
// celestial phenomena, running
// water, weapon skills,
// craftsmanship, secrecy, comedy
// and joy, chaos, mischief - 15.
inline int uapnElfSpheres()
    { return 15; }
// The absent spheres: law,
// underground phenomena, violence
// without cause, warfare,
// non-mammalian or non-avian life
// - five.
inline int uapnElfSpheresAbsent()
    { return 5; }
// One or two are concerned with
// death - peaceful, good-aligned.
inline int uapnElfDeathMax()
    { return 2; }

// ---- the halfling intro ----

// A small pantheon: one greater
// deity (Yondalla) plus several
// lesser deities and demigods.
inline int uapnHalfGreaterCount()
    { return 1; }
// Most communities worship only a
// few - four or five at most.
inline int uapnHalfWorshipMax()
    { return 5; }
// Yondalla is the top authority,
// though her control over
// Brandobaris is minimal at times.
inline bool uapnHalfYondallaTop()
    { return true; }
inline bool uapnHalfBrandobarisLoose()
    { return true; }
// All the halfling deities are
// pledged to work together against
// the enemies of the halfling
// people.
inline bool uapnHalfPledged()
    { return true; }
// Most reside on one of the planes
// of the Seven Heavens, the Green
// Fields.
inline bool uapnHalfGreenFields()
    { return true; }
// Sheela Peryroyl and one or two
// other deities live on Concordant
// Opposition - the printed minimum
// is two.
inline int uapnHalfConcordantMin()
    { return 2; }
// Brandobaris roams the Prime
// Material Plane.
inline bool uapnHalfBrandobarisRoams()
    { return true; }
// The Greek comparison: as the
// Greek gods come to Olympus to
// meet, so the halfling deities
// come to the Green Fields.
inline bool uapnHalfGreekCompare()
    { return true; }
// The more powerful halfling
// deities tend to be females; the
// dwarven tend male, the elven a
// combination of both genders.
inline bool uapnHalfPowerFemale()
    { return true; }
// Halfling deities are not
// aggressive by and large; even
// Brandobaris avoids combat if he
// can help it.
inline bool uapnHalfNotAggressive()
    { return true; }
// The sphere census: security,
// sufficiency, the earth, youth,
// play and humor, good luck, law,
// peace, secrecy, love, friendship
// - eleven.
inline int uapnHalfSpheres()
    { return 11; }
// No deities of evil nature, or
// war, suffering, fire and water,
// or death - five absent.
inline int uapnHalfSpheresAbsent()
    { return 5; }
// Yondalla is invoked at funerals
// as a protector of the departed
// souls.
inline bool uapnHalfYondallaFuneral()
    { return true; }
// Urogalan: a neutral-aligned
// masculine lesser deity, the judge
// and protector of the dead,
// primarily an earth god, living
// on Concordant Opposition.
inline bool uapnHalfUrogalanNeutral()
    { return true; }
inline bool uapnHalfUrogalanEarth()
    { return true; }
inline bool uapnHalfUrogalanConcord()
    { return true; }
// Four deities are described.
inline int uapnHalfDescribed()
    { return 4; }

// ---- the gnomish intro ----

// The demi-human pantheon with the
// fewest members.
inline bool uapnGnomeFewest()
    { return true; }
// By most counts only six or seven
// deities govern the gnomish folk.
inline int uapnGnomeCountMin()
    { return 6; }
inline int uapnGnomeCountMax()
    { return 7; }
// All gnomish gods, with the
// exception of Urdlen the Crawler,
// are ruled by Garl Glittergold.
inline bool uapnGnomeGarlException()
    { return true; }
// All but one live on the Twin
// Paradises, the Golden Hills,
// where the souls of faithful
// gnomes go at death.
inline bool uapnGnomeGoldenHills()
    { return true; }
// The exception is Urdlen, who
// lives in the Abyss.
inline bool uapnGnomeUrdlenAbyss()
    { return true; }
// All the known gnomish deities
// are masculine, worshiped by
// male and female gnomes with
// equal reverence.
inline bool uapnGnomeAllMasculine()
    { return true; }
// Urdlen is sexless (though still
// referred to as a "he").
inline bool uapnGnomeUrdlenSexless()
    { return true; }
// The named companions: Garl's
// intelligent battle axe Arumdina,
// Baervan's raccoon friend
// Chiktikka, Segojan's intelligent
// stone golem - three; Urdlen, the
// exception, has no friends.
inline int uapnGnomeCompanions()
    { return 3; }
inline bool uapnGnomeUrdlenNoFriends()
    { return true; }
// Pranks and practical jokes are a
// major response of gnomish gods
// to their enemies.
inline bool uapnGnomePranks()
    { return true; }
// Gnomish deities usually only
// associate with the other
// gnomish deities, though they
// maintain loose contact with a
// few dwarven gods.
inline bool uapnGnomeDwarfContact()
    { return true; }
// Four deities are described.
inline int uapnGnomeDescribed()
    { return 4; }

// ---- the orcish intro ----

// The shaman tale frame: the gods
// met and drew lots for the parts
// of the world.
inline bool uapnOrcLotTale()
    { return true; }
// The lot races: human, elven,
// dwarven, gnomish, halfling -
// five, with the orcs excluded.
inline int uapnOrcLotRaces()
    { return 5; }
// Gruumsh's three habitat claims:
// the mountains (rifts and
// chasms), the hills (shaking,
// dust-covered), the meadows
// (gouged bare).
inline int uapnOrcHabitatClaims()
    { return 3; }
// Orcs make war, ceaseless and
// endless: war for the wrath of
// Gruumsh.
inline bool uapnOrcWarForWrath()
    { return true; }
// The Corellon battle: Corellon
// tried to shoot out Gruumsh's
// eye with his bow, but failed;
// Gruumsh started the fight by
// trying to paralyze the elven
// god with his spear.
inline bool uapnOrcCorellonFailed()
    { return true; }
inline bool uapnOrcGruumshFirst()
    { return true; }
// Because of the battle, orcs of
// all sects and cults hate elves
// more than all other non-orc
// races.
inline bool uapnOrcHateElvesMost()
    { return true; }
// The dwarven-orcish battle for
// ownership of the mountains: the
// orcs drawn by brutal majesty
// and stark barrenness, the
// dwarves by isolation, beauty
// and the ores beneath.
inline bool uapnOrcDwarfConflict()
    { return true; }
// The eternal battles on the
// plains of the Nine Hells between
// the goblins and orcs, each side
// led by their respective gods.
inline bool uapnOrcNineHells()
    { return true; }
// The named tribes: Evil Eye,
// Death Moon, Broken Bone - three
// (an open list).
inline int uapnOrcTribeNames()
    { return 3; }
// The tribal symbol is the holy
// symbol of the tribe's patron
// god.
inline bool uapnOrcTribeSymbol()
    { return true; }
// The sphere examples: strength,
// swordsmanship, military power,
// the night, death, fertility,
// hunting - seven (an open list).
inline int uapnOrcSphereExamples()
    { return 7; }
// Each god is part of a rigid chain
// of command with Gruumsh at the
// top.
inline bool uapnOrcGruumshTop()
    { return true; }
// Warfare between tribes is
// encouraged - eliminating the
// unfit and weak, promoting the
// strong.
inline bool uapnOrcTribalWarfare()
    { return true; }
// Five of the most powerful
// orcish gods besides Gruumsh are
// described.
inline int uapnOrcDescribed()
    { return 5; }
// Any use of "cleric" in the
// descriptions also includes
// shamans and witch doctors (the
// DMG).
inline bool uapnOrcClericIncludes()
    { return true; }

}   // namespace rules
