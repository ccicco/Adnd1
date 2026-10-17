// =========================================================================================
// Adnd1 - rules/elysiumbeasts.h
// ELYSIUM AND THE HAPPY HUNTING GROUNDS - printed pp. 90-92, the next two
// Upper Planes in one round: the four Oceanus layers of the heroes' blessed
// rest with the moving realms and the moon-barque, and the triple Beastlands
// of the sentient spell-casting beasts with their wandering stars and the
// Masters of the Cults of the Beast.
// census 503 -> 504.
//
// verified against printed pp. 90-92 of the uploaded motp.pdf OCR; the two
// planes ride together as the neutral-good pair (the R578 pattern); ONE
// AMENDMENT against the report: the spell-casting-creatures table (p. 92)
// belongs to the Beastlands beasts, not to Olympus - the printed table sits
// in the Happy Hunting Grounds chapter and keys on beast intelligence.
//
// the gap census after this round: 66 closed, 24 open - THREE boxes fall
// (Elysium, the Beastlands, the spell-casting beasts table AMENDED out of
// Olympus's column); Olympus and Gladsheim continue the Upper Planes next.
//
namespace rules {

// ---- the elysium and beastlands pins ----

// the Elysium layers, innermost to outermost: Amoria (the arrival layer, the
// Oceanus banks at their best), Eronia (mountains, doubled obstruction
// chances on the river, Enlil's Sumerian realm), Bellerin (flat, ten-mile
// marshes before the trees, great island nations) and Thalasia (the great
// sea, the Isles of the Blessed - the final rest of those who died for good);
// the River Oceanus dominates all four, beginning in Thalasia and flowing
// down to Amoria.
inline int ddiElysiumLayerCount()
    { return 4; }

// the Oceanus travel: another layer or plane in 1d10 (10) days downstream or
// up (the flow doubles back), with a 10% per-day chance of blocking cascades,
// snags or fallen trees that may capsize or hole the craft; the Oceanus is a
// slow peaceful flow, navigable by mortals, with no Charon and no
// hydrodaemons.
inline int ddiOceanusTransitDays()
    { return 10; }

// the Beastlands layers: Krigala the topmost (the Oceanus runs a relatively
// straight course to Olympus, portals in hollow trees - the same tree type
// always leads to the same plane, the silver-plated beeches to Olympus; a
// midday sun fixed at the zenith, the weather changing realm to realm); Brux
// the second (a reddish sky with two rising-or-setting suns); Karasuthra the
// farthest (a starlit night, the stars unmoored and wandering at random).
inline int ddiBeastlandLayerCount()
    { return 3; }

// the Beastlands spell-casting beasts (the table the report attributed to
// Olympus, AMENDED: it is the Happy Hunting Grounds beasts table, printed p.
// 92): 10% of beasts with very-or-higher intelligence can cast - 1-20 one
// random magical spell per day, 21-40 one clerical, 41-60 1d10 magical, 61-80
// 1d10 clerical, 81-90 magic-user of 1d20 level without books, 91-99 cleric
// or druid of 2d8 level, 00 magic-user 1d10 AND cleric 1d8.
inline int ddiBeastCasterPct()
    { return 10; }

// the Beastlands beast modifications: double hit dice (minimum 2), AC one
// better, magic resistance 5% base plus 5% per Intelligence point above 7 -
// all sentient (minimum low) and capable of speech; these abilities apply
// only in the outer and Astral planes, lost in any other plane; magical and
// enchanted creatures are excluded.
inline int ddiBeastHdMult()
    { return 2; }

// the Elysium doctrine: ultimate good unsullied by hierarchy or anarchy - the
// spirits at final rest cannot be summoned or controlled, and the Powers
// answer only callings they deem worthy or profitable; the sky varies from
// indigo to robins-egg blue by the passage of the dawn, light, night and moon
// Powers' craft; barriers open at matched elevations, so no illusion of
// ascending or descending; magic obeys the general rules with realm-imposed
// exceptions.
inline bool ddiElysiumDoctrine()
    { return true; }

// the Amoria cavern portals: dark caverns with no clue to their destination
// (divination can sort the Twin Paradises, Concordant Opposition and the
// Happy Hunting Grounds apart), and any cavern that swallows the Oceanus flow
// leads to the Happy Hunting Grounds after an underground passage of 1d10
// turns - navigability not guaranteed.
inline bool ddiElysiumCavernRule()
    { return true; }

// the Elysium Powers (the realms MOVE between layers - get recent
// information): Isis on Amoria (lantern-lit paths, moon-dog patrols with
// piercing howls), Seker's movable sphere-realm Ro Stau (the Doors of the
// Corridors, shining as it flies, tending the Isles of the Blessed), Ishtar
// with her half-mile glowing fighting statue, Enlil and Nin-Hursag on Eronia
// (Enlil forms conduits like Anu), Nanna-Sin in his crescent moon-barque
// (unupsettable by falls, unblockable by trees or ice, radiance for the banks
// - but safe passage is bargained with the god himself), Ushas's reddish dome
// of dawn, Tsukiyomi's mirrored silver realm, and Bragi's yearly
// fealty-journey by longship to Odin.
inline bool ddiElysiumPowers()
    { return true; }

// the Elysium creatures: the standard upper-plane host - hollyphants,
// planetars, solars, foo creatures, agathia and baku - plus the phoenix at
// home in both sylvan and rocky reaches, and the moon dogs in great numbers
// as servants, watch beasts and vassals to the Powers.
inline bool ddiElysiumCreatures()
    { return true; }

// the Beastlands doctrine: good tending toward chaos, densely forested in
// every layer (cycads to pines to sequoids to oaks to beeches to birches,
// hanging moss and giant fungi); the ANIMALS call the plane the Beastlands
// and think of all three layers as a single realm, treating humanoid Powers
// as temporary settlers or invaders; all Prime animals and their giant
// versions live here, with the special abilities - the first visitors who
// named it a happy hunting ground of easy pickings were wrong.
inline bool ddiBeastlandDoctrine()
    { return true; }

// the Beastlands magic: all spells and abilities function with the standard
// limits, and identification and communication with plants and animals (not
// their summoning or control) works in ALL layers - but any attempt to
// control winds, weather or air is prevented by the creatures of the aerial
// regions (the mortals, the faces in the clouds, who hold complete weather
// control and legend lore any subject, and whom even the bird-spirits obey).
inline bool ddiBeastlandWindRule()
    { return true; }

// the Beastlands Powers: Great Powers few and close-held (a few bow-shots
// around their citadels); the true masters are the Beast Lords, the Masters
// of the Cults of the Beast - lesser or demi-god status, the ultimate
// examples of their race, with command and summoning powers over their kind
// functioning on EVERY plane where suitable creatures exist (the Cat Lord,
// the Generals of the Animal Kingdoms); the sole Legends and Lore resident is
// Skerrit the Forester, the centaur god of interlocked meadows, served by
// satyr and centaur spirits - on the best of terms with the Beast Lords, who
// consider him a temporary visitor.
inline bool ddiBeastLordRule()
    { return true; }

}   // namespace rules
