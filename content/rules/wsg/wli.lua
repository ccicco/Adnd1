-- wli: promoted from tools/spec_r485.json (the R485: the WSG ARTIFICIAL ILLUMINATION slice, printed pp. 74-75 - the fourth and final vision-and-visibility round, a pure prose round with NO table, CLOSING the vision chapter: the twilight-as-light frame with the radius-precedence rule and the 40-foot torch vs 300-yard twilight comparison, the four torch wind bands (calm, 11-25, 26-40, above 40) with their radius and burn-time degradation, the 25%-every-five-rounds extinguish risk, the torch-lighting time rule with the fire-building proficiency halving, the lantern and bullseye sighting geometry, the magic weapon glow rule with the dagger/short sword/long sword figures, the three campfire radii, and the group visibility rules with the lantern-holder blind spot and the fringe-sees-normally rule.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 485,
  "prefix" = "wli",
  "banner" = {
      "title" = "R485: the WSG ARTIFICIAL ILLUMINATION slice, printed pp. 74-75 - the fourth and final vision-and-visibility round, a pure prose round with NO table, CLOSING the vision chapter: the twilight-as-light frame with the radius-precedence rule and the 40-foot torch vs 300-yard twilight comparison, the four torch wind bands (calm, 11-25, 26-40, above 40) with their radius and burn-time degradation, the 25%-every-five-rounds extinguish risk, the torch-lighting time rule with the fire-building proficiency halving, the lantern and bullseye sighting geometry, the magic weapon glow rule with the dagger/short sword/long sword figures, the three campfire radii, and the group visibility rules with the lantern-holder blind spot and the fringe-sees-normally rule.",
      "provenance" = "The settle: two-way clean on the first pass - the tesseract full-text read, the pdfy layout read and the tsv coordinate read agree on every number of the page (the wind bands 11-25 and 26-40 mph, the 30/40 feet, the 4/6/2 turns, the 25% and five rounds, the 200/100/200/100 sighting yards, the 100/150/200 magic glows, the 80/120/150 campfire radii, the 30-foot lantern radius); the tesseract /arge for large is an italic-L scan artifact, pdfy reading it cleanly. The section began at the bottom of printed p. 74 (the PHB p. 102 pointer, the twilight frame and the 40-foot torch example, cut mid-word in il-) and its opening prose is pinned with this round. No contested cells, no vision reads needed.",
      "sentinel" = "Bounds held: the wind bands tile 10-25-40-41 with no gaps, the torch radius and burn time degrade monotonically (40 to 30 feet, 6 to 4 to 2 turns), every magic weapon glow is exactly ten times its radius, and the campfire radii strictly ascend 80 under 120 under the 150 floor.",
    },
  "consts" = { {
      "name" = "wliTorchRadiusFt",
      "value" = 40,
      "comment" = "the torch radius of illumination on a clear night (the PHB figure)",
    }, {
      "name" = "wliTwilightNoLightYards",
      "value" = 300,
      "comment" = "in actual twilight under a clear sky he would see 300 yards without a light source",
    }, {
      "name" = "wliWind1MaxMph",
      "value" = 10,
      "comment" = "wind below 10 mph: the Players Handbook figures apply",
    }, {
      "name" = "wliWind2MinMph",
      "value" = 11,
      "comment" = "the windy band starts at 11 mph",
    }, {
      "name" = "wliWind2MaxMph",
      "value" = 25,
      "comment" = "and ends at 25 mph",
    }, {
      "name" = "wliTorchWindyRadiusFt",
      "value" = 30,
      "comment" = "11-25 mph: reliable illumination only out to 30 feet instead of 40",
    }, {
      "name" = "wliTorchBurnTurns",
      "value" = 6,
      "comment" = "the PHB burning time: 6 turns",
    }, {
      "name" = "wliTorchWindyBurnTurns",
      "value" = 4,
      "comment" = "11-25 mph: the torch burns out in 4 turns instead of 6",
    }, {
      "name" = "wliWind3MinMph",
      "value" = 26,
      "comment" = "the gale band starts at 26 mph",
    }, {
      "name" = "wliWind3MaxMph",
      "value" = 40,
      "comment" = "and ends at 40 mph",
    }, {
      "name" = "wliTorchGaleBurnTurns",
      "value" = 2,
      "comment" = "26-40 mph: the flame lasts only 2 turns at most",
    }, {
      "name" = "wliExtinguishPct",
      "value" = 25,
      "comment" = "26-40 mph: a 25% chance of the torch being extinguished by the wind",
    }, {
      "name" = "wliExtinguishCheckRounds",
      "value" = 5,
      "comment" = "the extinguish chance is checked every five rounds",
    }, {
      "name" = "wliWind4MinMph",
      "value" = 41,
      "comment" = "above 40 mph: more than 40",
    }, {
      "name" = "wliTorchStormMaxRounds",
      "value" = 1,
      "comment" = "in wind of more than 40 mph a torch cannot be kept burning for more than 1 round",
    }, {
      "name" = "wliLightBaseRounds",
      "value" = 1,
      "comment" = "it takes 1 round to light a torch",
    }, {
      "name" = "wliLightWindStepMph",
      "value" = 10,
      "comment" = "plus 1 round for every 10 mph of wind velocity",
    }, {
      "name" = "wliTorchSeenYards",
      "value" = 200,
      "comment" = "in moonlight or darkness a lighted torch can be seen from 200 yards",
    }, {
      "name" = "wliLanternSeenYards",
      "value" = 100,
      "comment" = "regular lantern light can be seen from 100 yards away",
    }, {
      "name" = "wliBullseyeBackYards",
      "value" = 200,
      "comment" = "a bullseye lanthorn beam is seen from 200 yards if the viewer looks directly back toward the source",
    }, {
      "name" = "wliBullseyeAcrossYards",
      "value" = 100,
      "comment" = "or from 100 yards if the viewer's gaze is directed across the path of the beam",
    }, {
      "name" = "wliMagicGlowFactor",
      "value" = 10,
      "comment" = "the glow of a magic weapon can be seen from ten times its radius of illumination",
    }, {
      "name" = "wliDaggerRadiusFt",
      "value" = 10,
      "comment" = "magic dagger radius of illumination",
    }, {
      "name" = "wliDaggerGlowFt",
      "value" = 100,
      "comment" = "magic dagger glow seen from 100 feet",
    }, {
      "name" = "wliShortSwordRadiusFt",
      "value" = 15,
      "comment" = "magic short sword radius of illumination",
    }, {
      "name" = "wliShortSwordGlowFt",
      "value" = 150,
      "comment" = "magic short sword glow seen from 150 feet",
    }, {
      "name" = "wliLongSwordRadiusFt",
      "value" = 20,
      "comment" = "magic long sword radius of illumination",
    }, {
      "name" = "wliLongSwordGlowFt",
      "value" = 200,
      "comment" = "magic long sword glow seen from 200 feet",
    }, {
      "name" = "wliCampSmallRadiusFt",
      "value" = 80,
      "comment" = "a small campfire illuminates an 80-foot radius",
    }, {
      "name" = "wliCampMediumRadiusFt",
      "value" = 120,
      "comment" = "a medium campfire lights up 120 feet on all sides",
    }, {
      "name" = "wliCampLargeMinRadiusFt",
      "value" = 150,
      "comment" = "a large campfire has a radius of at least 150 feet",
    }, {
      "name" = "wliLanternRadiusFt",
      "value" = 30,
      "comment" = "the lantern of the worked example illuminates a 30-foot radius",
    } },
  "bools" = { {
      "name" = "wliSupplementsPHB",
      "value" = true,
      "comment" = "the section supplements the Players Handbook page 102 statistics with facts relevant to the outdoor environment",
    }, {
      "name" = "wliLightAsTwilight",
      "value" = true,
      "comment" = "an artificial light source in moonlight or darkness lets characters within the illuminated area see with normal vision as if the natural light was twilight",
    }, {
      "name" = "wliContinualLightAsDaylight",
      "value" = true,
      "comment" = "or perhaps daylight, as in the case of a continual light spell",
    }, {
      "name" = "wliRadiusTakesPrecedence",
      "value" = true,
      "comment" = "the specified radius of illumination of the light source takes precedence over the figures on the Range of Normal Vision Table",
    }, {
      "name" = "wliTorchWindAffects",
      "value" = true,
      "comment" = "both the radius of illumination and the burning time of a torch can be affected by wind velocity",
    }, {
      "name" = "wliWindyFlicker",
      "value" = true,
      "comment" = "in wind of 11-25 mph the flame of the torch struggles and flickers",
    }, {
      "name" = "wliGaleRadiusHeld",
      "value" = true,
      "comment" = "in wind of 26-40 mph the radius of illumination is not further reduced",
    }, {
      "name" = "wliGaleExtinguishRisk",
      "value" = true,
      "comment" = "in 26-40 mph wind there is a chance the torch is extinguished by the wind and must be reignited",
    }, {
      "name" = "wliStormImpossible",
      "value" = true,
      "comment" = "in a wind of more than 40 mph it is impossible to keep a torch burning for more than 1 round",
    }, {
      "name" = "wliLightProfHalved",
      "value" = true,
      "comment" = "the torch-lighting time is cut in half for a character with proficiency in fire building",
    }, {
      "name" = "wliLanternReliable",
      "value" = true,
      "comment" = "a lantern or bullseye lanthorn is much more reliable in the wilderness: the flame is protected, will not flicker or be extinguished by the wind, and the radius of illumination generally remains constant",
    }, {
      "name" = "wliMagicWeaponSmallerArea",
      "value" = true,
      "comment" = "a magic weapon illuminates a smaller area than a torch or a lantern",
    }, {
      "name" = "wliMagicNoFuelNoWind",
      "value" = true,
      "comment" = "a magic weapon needs no fuel and is not affected by the wind",
    }, {
      "name" = "wliCampLargeAtLeast",
      "value" = true,
      "comment" = "a large campfire's radius of illumination is at least 150 feet, perhaps more if the fire is especially large",
    }, {
      "name" = "wliCampfireSeeCamping",
      "value" = true,
      "comment" = "for other information on fires, see the section on Camping and Campfires",
    }, {
      "name" = "wliLightLimitsLongRange",
      "value" = true,
      "comment" = "the use of any artificial light source, including magical light, in moonlight or darkness limits long-range visibility to varying degrees for all characters within the illuminated area",
    }, {
      "name" = "wliHolderBlindBeyond",
      "value" = true,
      "comment" = "a character holding a lantern cannot make out any details in the darkness immediately beyond the radius the lantern illuminates",
    }, {
      "name" = "wliFringeSeesNormally",
      "value" = true,
      "comment" = "someone standing at the fringe of the illuminated area can still see normally into the darkness ahead of him",
    }, {
      "name" = "wliDMTracksPositions",
      "value" = true,
      "comment" = "for a group traveling at night with artificial light the Dungeon Master should note which characters carry light sources and where the others stand with respect to the light-holder",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the three wind bands are contiguous and ascend from the calm band",
      "expr" = "m['wliWind2MinMph']() != m['wliWind1MaxMph']() + 1 or m['wliWind3MinMph']() != m['wliWind2MaxMph']() + 1 or m['wliWind4MinMph']() != m['wliWind3MaxMph']() + 1",
    }, {
      "note" = "the torch radius and burning time degrade band by band: 40 to 30 feet, 6 to 4 to 2 turns",
      "expr" = "m['wliTorchWindyRadiusFt']() >= m['wliTorchRadiusFt']() or m['wliTorchWindyBurnTurns']() >= m['wliTorchBurnTurns']() or m['wliTorchGaleBurnTurns']() >= m['wliTorchWindyBurnTurns']()",
    }, {
      "note" = "the gale holds the radius but halves the windy burn time, and the storm allows only 1 round",
      "expr" = "m['wliTorchGaleBurnTurns']() != 2 * m['wliTorchStormMaxRounds']() or m['wliTorchStormMaxRounds']() >= m['wliTorchGaleBurnTurns']()",
    }, {
      "note" = "lighting takes 1 round plus 1 per 10 mph of wind",
      "expr" = "m['wliLightBaseRounds']() != 1 or m['wliLightWindStepMph']() != 10",
    }, {
      "note" = "every magic weapon glow is exactly ten times its radius: 100/10, 150/15, 200/20 feet",
      "expr" = "m['wliDaggerGlowFt']() != m['wliMagicGlowFactor']() * m['wliDaggerRadiusFt']() or m['wliShortSwordGlowFt']() != m['wliMagicGlowFactor']() * m['wliShortSwordRadiusFt']() or m['wliLongSwordGlowFt']() != m['wliMagicGlowFactor']() * m['wliLongSwordRadiusFt']()",
    }, {
      "note" = "the campfire radii strictly ascend: 80 under 120 under the 150 floor",
      "expr" = "m['wliCampSmallRadiusFt']() >= m['wliCampMediumRadiusFt']() or m['wliCampMediumRadiusFt']() >= m['wliCampLargeMinRadiusFt']()",
    }, {
      "note" = "sighting: the lantern (100) never outsees the torch (200), and the bullseye back-toward (200) doubles the across-beam (100)",
      "expr" = "m['wliLanternSeenYards']() >= m['wliTorchSeenYards']() or m['wliBullseyeBackYards']() != 2 * m['wliBullseyeAcrossYards']()",
    }, {
      "note" = "the clear-night torch radius (40 feet) is the PHB figure the windy band cuts to 30, and real twilight sees 300 yards",
      "expr" = "m['wliTorchRadiusFt']() != 40 or m['wliTwilightNoLightYards']() != 300",
    } },
  "audit" = {
      "label" = "R485 WSG artificial illumination pin audit",
      "comment" = "The artificial illumination rules: this section supplements the Players Handbook page 102 statistics with facts relevant to the outdoors. The use of an artificial light source in moonlight or darkness lets characters within the illuminated area see with normal vision as if the natural light was twilight (or perhaps daylight, as with a continual light spell), but the light source's specified radius of illumination takes precedence over the Range of Normal Vision Table figures - a torch holder on a clear night sees only his 40-foot radius, even though in actual twilight under a clear sky he would see 300 yards unaided. Torch: both the radius and the burning time are affected by wind velocity - below 10 mph the PHB figures apply; 11-25 mph the flame struggles and flickers, reliable illumination only out to 30 feet instead of 40 and a burn of 4 turns instead of 6; 26-40 mph the radius is not further reduced but the flame lasts only 2 turns at most, with a 25% chance checked every five rounds of being extinguished and needing reignition; above 40 mph it is impossible to keep a torch burning more than 1 round. Lighting a torch takes 1 round plus 1 per 10 mph of wind, halved with fire building proficiency. In moonlight or darkness a lighted torch can be seen from 200 yards. Lantern: much more reliable in the wilderness - the flame protected, no flicker or wind extinguishing, constant radius; regular lantern light is seen from 100 yards, a bullseye lanthorn beam from 200 yards if the viewer looks directly back toward the source, or 100 yards if his gaze crosses the beam path. Magic weapons: a smaller illuminated area than torch or lantern, but no fuel and no wind effect; the glow is seen from ten times the radius - 100 feet for a magic dagger, 150 for a magic short sword, 200 for a magic long sword. Campfires: small 80-foot radius, medium 120 feet on all sides, large at least 150 feet (perhaps more if especially large). Any artificial light (including magical) in moonlight or darkness limits long-range visibility for everyone within the illuminated area: the lantern holder cannot make out details beyond his 30-foot radius, but someone at the fringe still sees normally into the darkness ahead, and the DM should track who carries light and where the others stand.",
    },
}
