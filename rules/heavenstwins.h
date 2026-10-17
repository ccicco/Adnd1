// =========================================================================================
// Adnd1 - rules/heavenstwins.h
// THE SEVEN HEAVENS AND THE TWIN PARADISES - printed pp. 87-90, the next two
// Upper Planes in one round: the seven ascending layers of goodness and law
// with the archon ladder and Moradin's Soul Forge, and the two facing layers
// of the book with no spine with the gnomish pantheon and Ukko's blizzards.
// census 502 -> 503.
//
// verified against printed pp. 87-90 of the uploaded motp.pdf OCR; the two
// planes ride together as the good-Law and good-neutral pair (the R578
// pattern), each carrying its layers, portals, natives and Powers exactly as
// printed.
//
// the gap census after this round: 63 closed, 27 open - TWO boxes fall (the
// Seven Heavens, the Twin Paradises); Elysium and the Happy Hunting Grounds
// continue the Upper Planes next.
//
namespace rules {

// ---- the heavens and twins pins ----

// the Seven Heavens structure: seven layers ascending (the illusion of
// ascendency - the crossable barriers sit only at the highest physical point
// of each layer, opening at the lowest point of the next, so each layer seems
// above the last, the mirror of the Nine Hells' pit); gravity constant
// throughout, each layer bathed in the soft light of its own heaven.
inline int ddhHeavenLayerCount()
    { return 7; }

// the Twin Paradises structure: a book with no spine - two facing layers
// (Dothion the pastoral topmost, Shurrock the challenging lower), surfaces 20
// miles apart sea level to sea level, each hanging overhead upside down from
// the other's view; the barrier sits in midair halfway between, crossed by
// flight (the Wisdom check) or by paired mountains that meet it.
inline int ddhTwinSeparationMiles()
    { return 20; }

// the Elysium-relevant Oceanus rule (the flow links the Twin Paradises'
// neighbors): river travel between layers or planes runs 1d10 days, with
// normal encounters and a 10% per-day chance of blocking cascades or snags -
// but the Paradise layers themselves are positive and industrious, natives
// crossing for a change of clime, neither side the better.
inline int ddhOceanusTransitDays()
    { return 10; }

// the archons, natives of the Heavens as the demons are to the hells: five
// types identified - Lanterns (spirits of the newly dead, soft bubbles of
// light), Hounds (dog-headed guardians, shapechange at will), Wardens (golden
// or silver bears with grasping hands, any divination spell), Swords (winged
// lion-headed leaders with prodigious casting), Tomes (hawk-headed, the power
// of knowledge); archons defer to devas, planetars and solars, rarely leaving
// the Heavens, Arcadia and the Twin Paradises.
inline int ddhArchonTypeCount()
    { return 5; }

// Lunia the Silver Heaven: the first layer holds all Astral portals, a dark
// sky of silvery stars, and arrival ALWAYS in the surf of a mountain-island
// ocean of fresh water that functions as holy water - immersion destroys all
// but the most powerful holy-water-affected beings; an astral viewing portal
// cannot be steered to a dry landing, but flyers can enter above the wet.
inline bool ddhLuniaSurfRule()
    { return true; }

// the seven layers: Lunia (silver), Mercuria the Golden (armory and
// mustering, Bahamut's court), Venya the Pearl (green moors, the halfling
// Green Fields), Solania the Electrum (silver-glow mountains, Moradin's Soul
// Forge in Ereokhar), Mertion the Platinum (citadels and black domes,
// marshalling the paladins), Jovar the Glittering (ruby and garnet vault, the
// Jovarian archons and the rumored ziggurat council), Chronias the
// Illuminated (goodness raised or evil extinguished by the plane itself, home
// of a ruling archon if one exists).
inline bool ddhHeavenLayersDoctrine()
    { return true; }

// the Heaven portals: free-standing permanent blocks of finished stone -
// black granite shot with gold to Arcadia, white granite shot with silver to
// the Twin Paradises, red spattered with blue to Concordant Opposition; the
// plane hosts planetars, solars, devas, agathia, foo creatures, hollyphants,
// shedu, lammasu, ki-rin, dragon horses and an occasional titan.
inline bool ddhHeavenPortalsRule()
    { return true; }

// the Heavens' Powers: Yondalla's halfling mythos (Avoreen, Cyroclaise,
// Brandobaris the bolt-hole demigod) on Venya's Green Fields, on good terms
// with the archons (who appear in halfling bodies to their followers);
// Moradin and Berronar beneath Solania, the Soul Forge's heat warming the
// layer and its smoke the vale mists; Bahamut the Platinum Dragon (equal
// chance: the Heavens, the plane of Air, or a Prime; the palace placed on
// four different layers at different times); Chung Kuel and Kuan Yin on
// Solania; Vishnu and Surya on Mercuria with Garuda common to both; Ebisu of
// Lunia greeting travelers as a poor fisherman; Girru of Mercuria; and every
// deity gains its home-plane benefits ANYWHERE on the plane.
inline bool ddhHeavenPowers()
    { return true; }

// the Twin Paradises portals: caverns with shining patterns - concentric
// circles to the Seven Heavens, radiating lines to Elysium, spiderwebs to
// Concordant Opposition; each layer glows golden-white; Dothion is mild
// (gentle seasons, intelligent speechless animals), Shurrock dramatic
// (thunder squalls, hard winters, hot summers, everyone at work).
inline bool ddhTwinPortalPatterns()
    { return true; }

// the Twin Paradises' Powers: the gnomish pantheon on Dothion - Garl
// Glittergold, Baervan Wildwanderer (with the oak Whisperleaf on a barrier
// mountain), Segojan Earthcaller, Flandal Steelskin (winter labs in
// Shurrock), occasional gnomish archons; Ukko of the Finnish pantheon across
// the barrier in cold snowy Shurrock, venting wrath as a full blizzard,
// served by air maidens; and the wandering greater titan Epinetheus, who
// destroys each home he settles, understood by the gnomes, contained by Ukko.
inline bool ddhTwinPowers()
    { return true; }

// the Twin Paradises law: NO additional restrictions beyond the general
// outer-plane rules (the mildest of the named planes); the layers host
// hollyphants, planetars, foo creatures, devas, solars, agathia and baku,
// plus sentient animals (average-plus intelligence, speechless) and sentient
// trees (treated as treants).
inline bool ddhTwinNoRestrictions()
    { return true; }

}   // namespace rules
