// =========================================================================================
// Adnd1 - rules/dsgcamp2.h
// THE REST OF WORLDS OF ADVENTURE, R551: printed pp. 101-103 (pdf 102-104) -
// the second half of the setting-design doctrine: the location-type variety
// (underworld settings lack the surface's climate criterion and still require
// variety; natural and artificial settings as the source; each area's size,
// shape and physical features carrying one or two unique characteristics; the
// inhabitants as another variety source - the all-orcs-and-ogres expedition
// boring quickly without tactical ingenuity; the individualistic monsters -
// the orc chieftain fancying himself a fashion judge outfitting his troops
// garishly, the chieftain starved for outside news keeping captives alive for
// stories; the stale-campaign surprise cure), the dangerous/safe mix (the
// kill-or-be-killed game losing its lustre for even the bloodthirsty; the
// friendly NPC encounters dropped in now and then; the realistic shoot-first
// consequences; the tranquil havens making the danger more exciting; the
// no-regular-haven-violations rule - adventurers lose their basic motivations
// without any expectation of peace), Consistency (the fantastic location
// built on an underlying idea of why it is there and how it functions; the
// familiarity-over-realism doctrine with the dragon example - unreal, yet
// familiar by extrapolation to its world; the source consistency without
// slavish re-creation - the augmenting pieces used, the inconsistent ignored;
// the medieval-Europe familiarity of the castle and the blacksmith/serf/
// merchant roles; the world founded on rules all creatures and civilizations
// live and die by, the established principles stable absent very strong
// reason; the simple nature laws - seasons, snowy mountaintops, regular tides
// - fixed for the campaign's duration; the growing exploration familiarity;
// the social-interaction familiarity with the caught treasury thief paying
// the stiff lawful penalty, laws extending into fantasy, the thief's role
// very dull without them), the Intelligent Races questionnaire (the foresight
// demand - quickly designed races blowing up in the DM's face, the original
// race extensive, the known-race branch a base to expand upon; the appearance
// central with the game statistics, creatures looking the way they do for a
// reason, the related-race framework, the challenge/terrify/befriend role
// fit; the livelihood - food and its source, the anti-devouring defenses, the
// specialized combat tactics, the neighbor problem, the infighting; the
// civilization extent - literacy, metalworking and building, beyond-borders
// knowledge - and its consequences for conflicts and documented vs oral
// history; the settlement scale with the manufactured/ natural dwelling split
// and the technology level; the customs - the forgotten ritual reasons, the
// societal-preservation roots, the empty-palm/ handshake show-no-weapon
// example, the outsider puzzlement, the develop-a-few-per-race advice; the
// limitations - weaknesses, leader skill, weapons, combat morale, immunities
// and invulnerabilities; the preferences - the glock-devouring dislike, the
// isolation-vs-trade split, the resemblance-driven first impressions), and
// Uniqueness (every DM's own style making each campaign unique to an extent;
// the within-world creative additions - unusual names, new architecture and
// plant life, original city- problem handling, unusual superstitions; the
// faithful-recreation exception - the fantasy-book DM as true to the source's
// spirit as possible).
// census 474 -> 475.
//
// djvu lines 13013-13326 with the Capture-layer pdf 102-104 cross-read (the
// pure-python extractor of the R550 note, parser page = printed page). The
// two reads agree across the round. The one settled garble: the Capture layer
// reads 'determinatibn' - settled as determination by the djvu read. The
// glocks passage reads identically in both machine reads (the invented
// neighboring race). The two-column Capture pages interleave in extraction,
// but every load-bearing claim was matched sentence-for-sentence against the
// djvu. A CLEAN-READ ROUND, no OCR-failure cells. A ZERO-FLIP ROUND: the pp.
// 99-113 Campaign Considerations child stays open (plotted pp. 100-113 still
// in flight).
//
// The campaign chapter: R550 the opener, R551 the worlds of adventure tail,
// next the plot and counterplot pp. 103-106.
//
namespace rules {

// ---- the Consistency section ----

// any fantastic setting should be created with an underlying idea of why it
// is there and how it functions, the reasons often based in the real world
inline bool dcdUnderlyingIdea()
    { return true; }

// a feeling of familiarity about an area is more important than realism to
// the success of the campaign
inline bool dcdFamiliarityOverRealism()
    { return true; }

// the dragon example - not and never real, yet the familiar huge
// fire-breathing reptile gives players familiarity with the creature and by
// extrapolation with its world
inline bool dcdDragonFamiliarity()
    { return true; }

// be consistent with the world's source to the extent it fits your plans -
// use the pieces that augment the game, ignore the pieces inconsistent with
// your goals, never slavish re-creation at gaming's expense
inline bool dcdSourceConsistency()
    { return true; }

// with medieval Europe as the basis (as it is for the game itself), the
// familiar aspects - the castle's well-known characteristics, the
// blacksmith/serf/merchant NPC roles
inline bool dcdHistoricalFamiliarity()
    { return true; }

// the world must be founded on a set of rules that all creatures and
// civilizations live and die by; established principles remain consistent
// unless there is a very strong reason for change
inline bool dcdWorldRulesStable()
    { return true; }

// simple laws of nature - the changing seasons, the snow-and-ice-capped
// mountaintops, the regular tides - once determined remain in effect for the
// campaign's duration
inline bool dcdNatureLaws()
    { return true; }

// as PCs explore a new world it grows increasingly familiar and they feel
// more at home - not omniscience, a natural growth contributing to enjoyment
inline bool dcdFamiliarityGrows()
    { return true; }

// social interactions base on real-world analogies - the consequences of the
// PCs' actions fit society's interpretation of those actions
inline bool dcdSocialFamiliarity()
    { return true; }

// the caught treasury thief pays a stiff penalty consistent with the laws of
// the land; civilizations develop laws to control members, extended logically
// into fantasy - without laws and consequences the thief's role is very dull
inline bool dcdLawConsequences()
    { return true; }

// ---- the Intelligent Races section ----

// intelligent-race creation requires great DM attention and foresight -
// quickly designed races often blow up in the DM's face, unlike casually
// generated monster bands
inline bool dcdRacesNeedForesight()
    { return true; }

// a completely original and unique race makes the task extensive; a branch or
// variation of a known race, including humans, provides a base of information
// to expand upon
inline bool dcdOriginalRaceExtensive()
    { return true; }

// appearance is central - the game statistics for all applicable areas
// included; creatures generally look the way they do for a reason; related
// races give the initial framework; the stats fit the planned role:
// challenge, terrify, or befriend the PCs
inline bool dcdRaceAppearance()
    { return true; }

// how the race lives - what members eat and where the food comes from, how
// they avoid being devoured, the specialized combat tactics planned out now,
// the nature of any neighbor problem, whether they fight among themselves
inline bool dcdRaceLivelihood()
    { return true; }

// intelligence is not civilization - the hallmarks: literacy, the ability to
// work metals and build things, knowledge of the world beyond the race's
// borders
inline bool dcdCivilizationHallmarks()
    { return true; }

// the civilization level often determines how the race fares in neighbor
// conflicts, and how much of its history is known - documented or passed
// along by word of mouth
inline bool dcdCivilizationConsequences()
    { return true; }

// civilization determines the settlement - generally the more advanced the
// civilization the larger the settlement; not all civilized members live in
// cities; manufactured dwellings or natural shelters, with the technology
// level required
inline bool dcdSettlementScale()
    { return true; }

// any intelligent race develops customs - often with reasons no longer
// apparent, attaining ritual status for time-honored but forgotten purposes;
// others rooted in the preservation of the society and its members
inline bool dcdRaceCustoms()
    { return true; }

// the empty palm or the handshake could well be outgrowths of the ancient
// custom of showing another that you raise no weapon against him; customs can
// be complicated and puzzling to outsiders
inline bool dcdHandshakeCustom()
    { return true; }

// all customs need not be determined before introduction - new ones can
// develop the story or explain creature actions; it is wise to develop a few
// per race for detail at first encounter
inline bool dcdCustomsIncremental()
    { return true; }

// the race's limitations - significant weaknesses PCs can exploit, leader
// skill, weapon types, combat morale, specific immunities or
// invulnerabilities
inline bool dcdRaceLimitations()
    { return true; }

// the likes and dislikes as natural outgrowths - the race surviving by
// slaughtering and devouring the neighboring glocks fairly dislikes them;
// isolation means disliking strangers; trade usually welcomes newcomers
inline bool dcdRacePreferences()
    { return true; }

// appearance and first impressions matter - creatures naturally feel
// friendlier toward those that resemble them, and may be completely horrified
// at very different-looking creatures
inline bool dcdFirstImpressions()
    { return true; }

// ---- the Uniqueness section ----

// every DM has his own style of play, making each campaign unique to a
// certain extent - also strive for uniqueness within the world
inline bool dcdUniquenessStyle()
    { return true; }

// add your own creative elements even on a real-life source - unusual names
// for places, people, or even objects give the campaign a distinctive touch
inline bool dcdUnusualNames()
    { return true; }

// create unusual or new forms of architecture and plant life; devise original
// ways of handling the typical problems of city and village life; unusual
// superstitions and practices differentiate the world
inline bool dcdNewForms()
    { return true; }

// when re-creating a world someone else designed, strive to be as true to the
// original as possible - the DM basing his world on a fantasy book faithful
// to the spirit of the source
inline bool dcdFaithfulRecreation()
    { return true; }

// ---- the dangerous and safe mix section ----

// provide a variety of dangerous and safe places, and encounters with
// creatures of good and evil
inline bool dcdEncounterMix()
    { return true; }

// the kill-or-be-killed game soon loses its lustre for even the most
// bloodthirsty players - drop in a friendly or helpful NPC encounter now and
// then
inline bool dcdFriendlyEncounters()
    { return true; }

// include realistic consequences should the PCs decide to shoot first and ask
// questions later
inline bool dcdShootFirstConsequences()
    { return true; }

// some places should be tranquil havens for rest and recovery - the rest
// periods make the danger and adventure seem that much more exciting
inline bool dcdTranquilHavens()
    { return true; }

// an occasional dangerous encounter in a haven is fine but not a regular
// practice - without any expected peace, adventurers lose basic motivations
inline bool dcdHavenRespect()
    { return true; }

// ---- the location variety section ----

// the world must have different types of locations; underworld settings lack
// the surface's climate criterion and still require variety
inline bool dcdLocationTypes()
    { return true; }

// natural and artificial settings provide a source of variety; each area's
// sizes, shapes and physical features should have at least one or two unique
// characteristics
inline bool dcdNaturalArtificial()
    { return true; }

// the inhabitants provide another variety source - an expedition meeting
// nothing but orcs and ogres becomes boring very quickly without tactical
// ingenuity and variety
inline bool dcdInhabitantVariety()
    { return true; }

// add a few individualistic monsters - the orc chieftain fancying himself a
// skilled judge of fashion outfitting his troops garishly, the chieftain
// starved for outside news letting captives live while they entertain him
// with stories
inline bool dcdIndividualistic()
    { return true; }

// a predictable campaign long unsuprising is the ideal time to spring an
// unusual setting or encounter - a sudden surprise makes up for a few weeks
// of stale adventuring
inline bool dcdStaleSurprise()
    { return true; }

}   // namespace rules
