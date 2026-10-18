// =========================================================================================
// Adnd1 - rules/dmoadventures.h
// THE ADVENTURE DOCTRINES - DMO Chapter 2 opens: the construction rules (show
// don't tell; prepare, don't over-plan; don't force the action - the backup
// plan; enhance, don't inflate; gifts vs. rewards; multiple threats; don't
// kill - scare; proactive and responsive foes; failures not catastrophic),
// the plot doctrine (the hook, the flexible decision-oriented plot), the
// twelve encounter types, the five linking methods, the five combat-plan
// elements, and the world-hopping doctrine (plane, pocket dimension,
// demiplane; the four aspects rated 2-20 on 2d10, the 10-12 typical band).
// census 523 -> 524.
//
// verified against printed pp. 30-45 of the uploaded DMO session capture
// (part 1, printed page N at OCR page N+1); the twelve encounter types from
// p. 36, the five plan elements from p. 43, the polymorphed-lich worked
// example from p. 35, the world types and aspects from pp. 44-45; the
// rating-table boxes (Tables 2-5) and the monster tables stay open for their
// own rounds.
//
// the gap census after this round: 14 closed, 82 open - the doctrine half of
// Chapter 2 is closed; the rating tables (Tables 2-5) and the
// monster-doctrine boxes follow.
//
namespace rules {

// ---- the DMO adventure-doctrine pins ----

// the encounter taxonomy: twelve different types of encounters are described
// - combat, deception, delay, dilemma, event, guardian, interaction,
// obstacle, puzzle, skirmish, surprise, and trap - the categories not
// definitive, with considerable overlap (printed p. 36).
inline int dekEncounterTypeCount()
    { return 12; }

// the adventure-linking methods: five ways to turn separate adventures into a
// series - chained adventures, ripples in a pond, interlocking adventures,
// multi-layered adventures, and revisited adventures (printed pp. 40-42).
inline int dekLinkingMethodCount()
    { return 5; }

// the combat-plan elements: a combat plan should consider five elements -
// attack power, mobility, organization, information, and terrain - with the
// planning depth riding the foe's intelligence and the encounter's plot
// importance (printed p. 43).
inline int dekCombatPlanElementCount()
    { return 5; }

// the delay economics: searching a 10' x 10' section of wall for a secret
// door requires a full turn (10 minutes) of game time, resolved in seconds of
// play - the model for delays that eat game time, not real time (printed p.
// 38).
inline int dekSecretDoorSearchTurns()
    { return 10; }

// the polymorph self duration: two turns per caster level - the
// rules-springboard doctrine worked through the polymorphed lich example
// (printed p. 35).
inline int dekPolymorphSelfTurnsPerLevel()
    { return 2; }

// the polymorphed lich: 60 turns (10 hours) at 30th level - the masquerade
// must renew the spell every 10 hours, the mumble to herself the neighbors
// noticed (printed p. 35).
inline int dekPolymorphLichTurns()
    { return 60; }

// the world types: three - the plane (infinitely large, no clear form or
// dimensions), the pocket dimension (a small discrete world attached to a
// parent, usually mirroring it, creatable artificially), and the demiplane (a
// discrete world floating in the Ethereal depths, creatable artificially,
// believed able to grow into full planes) (printed pp. 44-45).
inline int dekWorldTypeCount()
    { return 3; }

// the inner-plane census: 18 inner planes - elemental, para-elemental,
// energy, and quasi-elemental; any undiscovered ones likely exist between
// known planes (printed p. 44).
inline int dekInnerPlaneCount()
    { return 18; }

// the outer-plane census: 17 known outer planes - sixteen forming the great
// ring with Concordant Opposition (the Outlands) in the middle; new ones
// would form between existing planes or as additional layers (printed p. 44).
inline int dekOuterPlaneCount()
    { return 17; }

// the world aspects: four combine to define a world's unique reality -
// chronology, magic, technology, and environment (printed p. 45).
inline int dekWorldAspectCount()
    { return 4; }

// the world-rating floor: each aspect is rated on a scale ranging from 2 to
// 20, generated randomly with 2d10; the lower the rating, the weaker the
// aspect (printed p. 45).
inline int dekWorldAspectMin()
    { return 2; }

// the world-rating ceiling: 20 - ratings higher than 20 and lower than 2 are
// possible, but all known planes fall within these extremes (printed p. 45).
inline int dekWorldAspectMax()
    { return 20; }

// the typical campaign band, low end: ratings from 10 to 12 reflect
// conditions on typical AD&D campaign worlds - a 10 is weaker than a 12, but
// the difference is imperceptible to player characters (printed p. 45).
inline int dekWorldAspectTypicalLow()
    { return 10; }

// the typical campaign band, high end: 12 - the typical-world ceiling; a
// world's rating is usually fixed, though some shift slowly over time without
// the residents realizing (printed p. 45).
inline int dekWorldAspectTypicalHigh()
    { return 12; }

// the good-adventure checklist: begins with a hook, unfolds like a novel or
// short story plunging the characters into an ongoing web of activities,
// tests the skills of both player and character, contains plenty of
// excitement especially at beginning and end, and changes the world - always
// in a discernible way (printed p. 30).
inline bool dekGoodAdventureDoctrine()
    { return true; }

// the show-don't-tell rule: brief sensory descriptions for most scenes -
// colors, smells, textures, sounds - and the same for spells (the detect
// magic hues, the detect undead nausea, the fireball-or-delayed-blast
// ambiguity); sensory details control the mood (printed p. 32).
inline bool dekShowDontTell()
    { return true; }

// the prepare-don't-over-plan rule: high-level characters set their own
// agendas, so avoid work on encounters they might ignore; preparations mean
// hard data ready to hand - statistics, NPC personalities, treasure lists -
// not choreography; roll random events and rumors ahead of time and record
// them (printed p. 32).
inline bool dekPrepareDontOverplan()
    { return true; }

// the don't-force-the-action rule: treat the adventure as a story with an
// unwritten ending; build plots that stand up to PC tinkering; when something
// breaks the plan, put a backup plan into effect (the captured-villain worked
// example - the lie that still yields travel plans) (printed pp. 32-33).
inline bool dekDontForceAction()
    { return true; }

// the encounter-variety rule: don't use just one type of encounter - offer a
// mix of challenges (combat, trick/trap, negotiation), the bulk of them the
// kind the players like best (printed p. 33).
inline bool dekEncounterVariety()
    { return true; }

// the combat-vs-creativity rule: don't encourage combat, encourage creativity
// - most combat rolls are moot for high-level characters; give problems that
// can't be solved through combat (the raging forest fire) and combats that
// require brain power (the hidden fire elemental) (printed p. 33).
inline bool dekCombatVsCreativity()
    { return true; }

// the enhance-don't-inflate rule: resist bizarre new creatures with
// mind-boggling power, legions of high-level villains, or direct conflict
// with deities - enhancement challenges without overpowering (printed p. 33).
inline bool dekEnhanceDontInflate()
    { return true; }

// the gifts-vs-rewards rule: a gift is anything the PCs haven't truly earned
// - the dragon trapped where it can't fly or breathe, the vorpal blade in a
// random hoard; a reward follows a long epic quest, and any battle with a
// really big dragon should be an epic conflict (printed pp. 33-34).
inline bool dekGiftsVsRewards()
    { return true; }

// the multiple-threats doctrine: a single source of threat generates only one
// type of challenge and coasts to a halt when overcome; multiple threats are
// flexible, resistant to PC successes, and offer variety (the kidnapper chase
// made rich with the rival party, the jungle, the tanar'ri) (printed p. 34).
inline bool dekMultipleThreats()
    { return true; }

// the don't-kill-scare rule: grinding down high-level characters is
// monotonous - undermine confidence instead by attacking specific strengths
// (the silence 15' radius reminder, the antimagic shells, the heat metal and
// rust monster counters); undetectable foes make players assume the worst;
// lethal adventures drive retirement (printed p. 34).
inline bool dekDontKillScare()
    { return true; }

// the character-knowledge doctrine: don't waste time on knowledge arguments -
// prepare reference materials for common knowledge and a rumor list passed
// around at the game's start; specialists know their own areas (the archmage
// and the old spell's new twist) (printed p. 34).
inline bool dekCharacterKnowledgeDoctrine()
    { return true; }

// the don't-ignore-the-rules doctrine: the rules define reality for the PCs
// as physics does for real folks - interpret them consistently or players
// lose their basis for meaningful decisions; the rules are a creative
// springboard (the polymorphed-lich worked example with its renewal schedule,
// the aura and the chilling touch, the thick gloves) (printed pp. 34-35).
inline bool dekRulesConsistency()
    { return true; }

// the proactive-foes rule: foes capable of challenging high-level adventurers
// make plans and actively implement them - they notice encroachment and act
// before too much damage is done; even stay-at-homes follow a personal agenda
// (printed p. 35).
inline bool dekProactiveFoes()
    { return true; }

// the responsive-foes rule: PCs are a major disruption - plans already in
// motion should be dropped or altered to meet the situation; the keyed
// dungeon where occupants die room by room is the worst example - decide what
// goes on while the PCs are absent and make the locals react (printed p. 35).
inline bool dekResponsiveFoes()
    { return true; }

// the all-failures-not-catastrophic rule: not every situation should be
// all-or-nothing - if the PCs fail but survive, let the world change for the
// worse just a little and give them another chance; use failure to create
// further adventures (the dead king breaking the alliance, the deity's wrath)
// (printed p. 36).
inline bool dekFailuresNotCatastrophic()
    { return true; }

// the plot doctrine: a plot provides the unifying theme dealing with who,
// what, when, where, why, and how; it should arise from the campaign's
// structure, ride the player goals, and hook the characters through their
// personal goals or quirks; a good plot is flexible and decision-oriented -
// concentrate on what the players decide to do, not what their characters can
// accomplish (the worked newcomer example with its choice-preserving
// branches) (printed pp. 36-37).
inline bool dekPlotDoctrine()
    { return true; }

// the encounter-type doctrines: combat needs a logical tactical plan;
// deception fails when overused or unvaried; delays eaten sparingly control
// magic by exhausting durations; the dilemma forces choices with apparent
// stakes; events advance plots and warn; guardians must survive a major
// offensive; interactions test communication (the sweet-toothed wizardess);
// obstacles combine with combat (the stone giants across the chasm); puzzles
// test the players, not the characters; the skirmish softens and probes;
// surprises used very sparingly; traps hinder rather than dose out damage,
// mindful of the hit-point spread (printed pp. 36-40).
inline bool dekEncounterTaxonomyDoctrine()
    { return true; }

// the linking doctrines: the chain needs only superficial links (clues, maps,
// NPC statements) and gives players freedom; the ripple uses consequences as
// springboards in a specified order or any order; the interlock nests one
// adventure inside another or follows the loose ends; the multi-layer peels
// toward a final conflict whose nature is hidden at the start; the revisited
// site keeps generating play (the thieves' guild, the flaring feud) (printed
// pp. 40-43).
inline bool dekLinkingDoctrine()
    { return true; }

// the combat-plan doctrines: plan less for unintelligent creatures and always
// carefully for major foes; concentrate attacks against as few enemies as
// possible - wounded creatures fight on - and disrupt spellcasters; nonlethal
// forms (charms, wrestling, entanglement, disarming) often limit
// counterattacks better than damage; mobility need not mean speed (walls,
// slow, transmute rock to mud; darkness and the clouds); one clever leader
// suffices for organization; fight on what the foe knows and can discover,
// and remember the PCs gather information too; terrain chooses the fight -
// cover for defenders, exposure for attackers, the castle doctrine (printed
// pp. 43-45).
inline bool dekCombatPlanDoctrine()
    { return true; }

// the world-hopping doctrine: staging adventures on unfamiliar worlds keeps a
// high-level campaign fresh - even fairly weak creatures challenge when the
// spells and items act in unanticipated ways; the Ethereal connects the Prime
// with the Inner (travelers drift toward the Inner Planes or home, no
// Prime-to-Prime transit), the Astral connects the Prime to the Outer (and
// allows travel between Prime Material Worlds); both carry solid islands; the
// misconception corrected - only ONE Prime Material Plane, holding an
// infinity of crystal spheres (printed pp. 44-45).
inline bool dekWorldHoppingDoctrine()
    { return true; }

}   // namespace rules
