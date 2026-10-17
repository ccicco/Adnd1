// =========================================================================================
// Adnd1 - rules/dsgequip2.h
// The DSG NEW EQUIPMENT DESCRIPTIONS AND TRANSPORTATION, R526: printed pp.
// 56-57 (pdf 57-58) - the item descriptions: the air bladder (an airtight
// leather sack, flotation at a 1/3 kick rate with no exertion or swimming
// needed, hypothermia still a danger, and a full turn of rest air rising at
// the air-supply proportions when exerting), the baskets (woven, lidded, not
// waterproof), the beacon (a mounted very-bright lantern throwing a 240-foot
// cone two feet wide at the source broadening to a 90-foot fan, a pint of oil
// per 10 turns, tightly shutterable), the birdcage (a wicker cage for up to
// three songbirds, 18 inches high and a foot in diameter), the boxes (small
// metal boxes about 2 x 2 feet and 1 1/2 inches deep, lightproof and airtight
// when sealed, foiling magical inspection and holding light-enchanted
// objects), the crampons (boot spikes for ice and slippery surfaces), the
// iron drill (a one-inch-wide, up-to-nine-inch-deep hole, one inch of wood
// per turn and stone in three, the grinding noise audible at 120 feet), the
// grappling hooks (two- or three-pronged, nearly always rope-attached), the
// waterproof lantern (a shielded flame; underwater a 10-foot radius instead
// of 30, the flame surviving the water but not the missing air - a secret d6
// of remaining rounds), the lard pint (a lubricant squeezing a character
// through a passage 80% of the minimum, too stubborn to burn as a weapon but
// adding 2 hp per round of fire damage for 1d6 rounds, and an insulating
// coating per the hypothermia rules), the waterproofing oil (seal- and
// mink-harvested, a pint coating two square yards of leather or wool but
// never cotton, repelling pouring water 1d6 x 6 turns, immersion 1d6 turns,
// then wetter for 1d6 turns until saturated), the pickaxe (the miner's
// essential, the excavation rate halved without it; a desperate weapon at an
// inherent -2 dealing 1d10 to small/medium and 1d20 to large creatures), the
// chalk powder (imagination-limited: floor footprints, a 10-foot dust cloud
// revealing invisible creatures, covering a 20-foot square or eight humans),
// the pulleys (one, two or three rope loops; two single pulleys double the
// lift, two double quadruple it, two triple sextuple it), the hollow reed
// (submerged breathing periscope-style, 1/3 movement with a 10% per-round
// ripple risk while moving, none while floating), the shovel (daily
// excavation halved without one) and the whistle (piercing, audible at 1,000
// feet); and the transportation equipment: the collapsible boat (a
// skin-and-spar package filling a backpack, unfolding into a small-rowboat
// equivalent in 1d3 turns, twice the listed weight when carried wet), the
// canoe (swifter and more maneuverable than a rowboat but easier to capsize,
// carrying three characters with normal gear or two with heavy gear; the
// large canoe nine or six), and the kayak (a one-character craft for rough or
// cold water, the oilskin layer sealing everything but the kayaker's opening
// so even capsizing does not fill it)
// census 449 -> 450.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~7255-7470) with the pdf Acrobat-Capture layer as the second read (idx 133
// = the printed p. 57 window); the compiled-tables appendix has no reprint of
// this prose. A CLEAN-READ ROUND: both machine reads agree on every
// load-bearing number - the beacon 240/2/90 cone and 10-turn pint, the drill
// 1x9 hole with the wood-per-turn and three-turn stone, the 120-ft noise, the
// lantern 10/30 radii with the d6 burn, the lard 80% passage and 2-hp 1d6
// fire, the oil 2-sq-yd pint with the 1d6x6 pour, 1d6 immersion and 1d6
// wetting, the pickaxe 50% rate, -2, 1d10/1d20, the chalk 20-ft
// square/8/10-ft cloud, the reed 1/3 and 10% ripple, the 50% shovel rate, the
// 1,000-ft whistle, the 1d3-turn unfold with the doubled wet weight, and the
// canoe 3/2/9/6 crews. The only garbles are the standing glyph classes (djvu
// "809/" reading as 80%, the box depth "1 1/2" glyph). SEAMS: the air-supply
// page-36 and hypothermia page-42 references (R515/R516), the movement-rules
// page-21 passage width, the R520 pickaxe-and-shovel excavation rates, and
// the climbing rules for crampons and grappling hooks. The
// Equipment-for-Proficiencies descriptions prose (the armorer through weaver
// paragraphs) sits after the transportation section and lands with the next
// chapter block; nothing auto-credits.
//
// A prose round: no tables pin. The numbers pin as consts per the R508
// convention: the beacon cone (240/2/90 ft, 10 turns per pint), the birdcage
// (18 in, 12 in, 3 birds), the box (2x2 ft, 1 1/2 in deep), the drill (1-in x
// 9-in hole, 1-in wood per turn, stone in 3, 120-ft noise), the lantern
// (10/30-ft radii, the secret d6 burn), the lard (80% passage, 2 hp, 1d6
// rounds), the oil (2 sq yd, 1d6 x 6 pour, 1d6 immersion, 1d6 wetting), the
// pickaxe (50% rate, -2 attack, 1d10/1d20), the chalk (400 sq ft, 8
// creatures, 10-ft cloud), the reed (1/3 movement, 10% ripple), the shovel
// (50% rate), the whistle (1,000 ft), the pulleys (2x/4x/6x), and the
// transportation numbers (1d3 unfold, 2x wet weight, canoe 3/2 and 9/6
// crews). The rest pins as prose bools: the item purposes and caveats (the
// bladder flotation and air-supply roles, the beacon mounting and shutter,
// the lightproof boxes, the shielded lantern dousing by missing air, the lard
// lubricant/insulator double life, the oil sources, the pickaxe miner's-kit
// role, the chalk discovery uses, the pulley loop ladder, the reed periscope
// and ripple, the sealed kayak). The R515/R516/R520/page-21 seams are noted;
// nothing auto-credits.
//
namespace rules {

// ---- the flotation and air items ----

// by kicking, a character holding an air bladder moves at 1/3 of his normal
// swimming speed.
inline int dnetBladderKickDiv()
    { return 3; }

// a resting character with an air bladder gets enough air to last a full turn
// (10 rounds).
inline int dnetBladderRestTurns()
    { return 10; }

// the air bladder is an airtight leather sack with two principal purposes: a
// flotation device and a very limited air supply container, generally with
// several straps for holding.
inline bool dnetBladderFlotationAndAir()
    { return true; }

// a character holding an air bladder does not have to exert himself to remain
// afloat, nor does he need to be able to swim - though hypothermia can still
// endanger him (the R516 seam).
inline bool dnetBladderNoSwimNeeded()
    { return true; }

// the secondary function provides air to a character who might otherwise
// suffocate or drown: resting, a full turn of air; exerting, the consumption
// rate rises at the air-supply proportions (page 36, the R515 seam).
inline bool dnetBladderAirSupply()
    { return true; }

// ---- the light items ----

// a beacon projects light in a cone up to 240 feet from its source.
inline int dnetBeaconRangeFt()
    { return 240; }

// the beacon cone is only two feet wide at its source.
inline int dnetBeaconSourceWidFt()
    { return 2; }

// the beacon cone broadens into a 90-foot-wide fan at its extreme end.
inline int dnetBeaconEndWidFt()
    { return 90; }

// a beacon burns a pint of oil in 10 turns of operation.
inline int dnetBeaconOilTurns()
    { return 10; }

// a beacon is essentially a very bright lantern too large to be carried by
// hand - it must be mounted on a structure such as a building, wagon, or
// boat.
inline bool dnetBeaconMounted()
    { return true; }

// a beacon can be tightly shuttered so as not to emit even a trace of light.
inline bool dnetBeaconShuttered()
    { return true; }

// a waterproof lantern taken underwater illuminates a 10-foot radius.
inline int dnetLanternUwRadiusFt()
    { return 10; }

// the normal (dry) lantern radius is 30 feet.
inline int dnetLanternNormRadiusFt()
    { return 30; }

// the submerged-lantern burn roll is one die, made secretly by the DM.
inline int dnetLanternBurnDice()
    { return 1; }

// a submerged waterproof lantern burns d6 rounds - the secret roll result.
inline int dnetLanternBurnSides()
    { return 6; }

// the waterproof lantern produces light equivalent to a normal lantern, its
// flame carefully shielded against water dousing and gusts of wind.
inline bool dnetLanternShielded()
    { return true; }

// underwater the illumination shrinks to a 10-foot radius; water does not
// extinguish the flame, but lack of air soon does - the DM makes the secret
// d6 roll for the rounds it continues to burn.
inline bool dnetLanternUwDouseByAir()
    { return true; }

// ---- the containers ----

// the woven baskets are not waterproof but hold most nonliquid substances;
// each comes with a lid that can be latched tightly.
inline bool dnetBasketsLatched()
    { return true; }

// a birdcage is about 18 inches high.
inline int dnetBirdcageHeightIn()
    { return 18; }

// a birdcage is about one foot (12 inches) in diameter.
inline int dnetBirdcageDiaIn()
    { return 12; }

// a birdcage is capable of holding up to three songbirds.
inline int dnetBirdcageBirds()
    { return 3; }

// the birdcage is a wicker cage for up to three songbirds.
inline bool dnetBirdcageWicker()
    { return true; }

// the boxes are about two feet wide.
inline int dnetBoxWidFt()
    { return 2; }

// the boxes are about two feet long.
inline int dnetBoxLenFt()
    { return 2; }

// the boxes are about 1 1/2 inches deep (the "1 1/2" glyph garbles in both
// machine reads - pinned by the R521-style small-measure convention, 18
// half-inches).
inline int dnetBoxDeepIn()
    { return 18; }

// the small metal boxes are completely light proof and airtight when sealed -
// useful against magical inspection, and handy containers for gems or
// permanently light-enchanted objects.
inline bool dnetBoxesLightproof()
    { return true; }

// ---- the climbing and boring tools ----

// the crampons are iron spikes attached to a character's boots, providing
// better footing on ice or other slippery surfaces (the climbing seam).
inline bool dnetCramponsIce()
    { return true; }

// the drill bores a hole about one inch wide.
inline int dnetDrillHoleWidthIn()
    { return 1; }

// the drill bores up to nine inches deep.
inline int dnetDrillHoleDepthIn()
    { return 9; }

// a heavily exerting character drills through one inch of wood in a turn.
inline int dnetDrillWoodInPerTurn()
    { return 1; }

// one inch of stone takes three turns.
inline int dnetDrillStoneInPerTurnFrac()
    { return 3; }

// the drill makes a grinding noise audible up to 120 feet away.
inline int dnetDrillNoiseFt()
    { return 120; }

// the iron drill slowly bores through wooden or stone barriers, with a
// grinding noise audible up to 120 feet.
inline bool dnetDrillBore()
    { return true; }

// the grappling hooks are two- or three-pronged hooks thrown at a catchable
// surface, nearly always with a rope attached (the climbing seam).
inline bool dnetGrapplingHooks()
    { return true; }

// ---- the lubricant and waterproofing ----

// a lard-smeared character can squeeze through a passage only 80% as wide as
// the minimum passage needed (the movement-rules page-21 seam).
inline int dnetLardPassagePct()
    { return 80; }

// a lard-smeared character sustaining fire-based damage suffers 2 hp extra
// per round.
inline int dnetLardExtraHp()
    { return 2; }

// the extra-damage duration is one die.
inline int dnetLardExtraDice()
    { return 1; }

// the fire extra damage lasts 1d6 rounds.
inline int dnetLardExtraSides()
    { return 6; }

// lard is occasionally employed as a lubricant to help large objects,
// including characters, squeeze through small holes; it is mildly flammable
// but burns too stubbornly to function as a weapon.
inline bool dnetLardLubricant()
    { return true; }

// lard can also serve as an insulating coating for swimmers entering very
// cold water - see the hypothermia rules (page 42) for exact effects (the
// R516 seam).
inline bool dnetLardInsulator()
    { return true; }

// one pint of waterproofing oil thoroughly coats two square yards of leather
// or wool.
inline int dnetOilSqYards()
    { return 2; }

// the pouring-water waterproof duration is one die.
inline int dnetOilPourDice()
    { return 1; }

// treated material repels pouring or showering water for 1d6 x 6 turns.
inline int dnetOilPourSides()
    { return 6; }

// the pour duration multiplies the 1d6 result by 6.
inline int dnetOilPourMult()
    { return 6; }

// the immersion waterproof duration is one die.
inline int dnetOilImmerseDice()
    { return 1; }

// immersed material remains completely waterproof for only 1d6 turns.
inline int dnetOilImmerseSides()
    { return 6; }

// the slow-wetting leak duration is one die.
inline int dnetOilWetDice()
    { return 1; }

// a leaking material grows slowly wetter for 1d6 turns, after which it is
// completely saturated.
inline int dnetOilWetSides()
    { return 6; }

// waterproofing oil is harvested from creatures with very effective
// insulation systems - seals and minks are common sources; cotton cannot be
// effectively waterproofed.
inline bool dnetOilSources()
    { return true; }

// ---- the mining kit tools ----

// the excavation rate is only 1/2 of maximum without pickaxes (the R520
// seam).
inline int dnetPickNoPickaxeRatePct()
    { return 50; }

// a pickaxe used as a weapon suffers an inherent -2 on all attack rolls.
inline int dnetPickAtkPenalty()
    { return 2; }

// a pickaxe blow inflicts 1d10 points of damage to small or medium creatures.
inline int dnetPickDmgSidesSm()
    { return 10; }

// a pickaxe blow inflicts 1d20 points of damage against large creatures.
inline int dnetPickDmgSidesLg()
    { return 20; }

// the pickaxe is an essential ingredient of every miner's kit, required for
// full excavation efficiency; in desperate conditions it can serve as a
// weapon with the nonproficiency penalties plus the inherent unwieldiness
// penalty.
inline bool dnetPickMinerKit()
    { return true; }

// a container of chalk powder thoroughly covers a 20-foot-square (400 sq ft)
// section of floor.
inline int dnetChalkFloorSqft()
    { return 400; }

// a container holds enough chalk powder to cover up to eight human-sized
// characters.
inline int dnetChalkCreatures()
    { return 8; }

// hurled or smashed chalk creates a 10-foot-diameter cloud of dust.
inline int dnetChalkCloudDiaFt()
    { return 10; }

// the chalk powder serves a wide variety of purposes limited only by
// imagination: scattered on the floor it shows footprints, and hurled or
// smashed it creates a dust cloud settling on creatures in the area -
// discovering invisible creatures and lightening dark objects.
inline bool dnetChalkUses()
    { return true; }

// the shovel is another standard item of every miner's supplies (the R520
// seam).
inline bool dnetShovelMinerKit()
    { return true; }

// a group without shovels has its daily excavation amount reduced by 50% (the
// R520 seam).
inline int dnetNoShovelRatePct()
    { return 50; }

// ---- the movement aids ----

// pulleys come with a wooden block and sturdy hooks; standard pulleys accept
// one loop of rope, others two or even three loops, and a single pulley
// changes the direction of force - very solid attachment required.
inline bool dnetPulleyLoops()
    { return true; }

// two single-rope pulleys double the weight that can be lifted.
inline int dnetPulleyDoubleLiftMult()
    { return 2; }

// two double-rope pulleys quadruple the lift.
inline int dnetPulleyQuadLiftMult()
    { return 4; }

// two triple-rope pulleys increase the lift six times.
inline int dnetPulleyTripleLiftMult()
    { return 6; }

// a reed-breathing character can move at only 1/3 of his normal swimming
// movement rate.
inline int dnetReedMoveDiv()
    { return 3; }

// a character moving while breathing through a reed stands a 10% chance per
// round of creating a tell-tale ripple.
inline int dnetReedRipplePct()
    { return 10; }

// the hollow reed is a slender straw that, used carefully, lets a character
// breathe completely submerged - inserted in the mouth with the nose sealed,
// lying on the back with the straw up like a small periscope.
inline bool dnetReedBreathing()
    { return true; }

// the upside-down position makes concealment while moving very difficult, and
// moving risks the tell-tale ripple; simply floating with the current entails
// no such risk.
inline bool dnetReedHardToHide()
    { return true; }

// a whistle creates a piercing sound audible up to 1,000 feet away.
inline int dnetWhistleRangeFt()
    { return 1000; }

// the whistle is a simple device of hollowed wood, bone, or reed with a
// piercing sound audible up to 1,000 feet away.
inline bool dnetWhistleSimple()
    { return true; }

// ---- the transportation equipment ----

// the collapsible-boat unfold roll is one die.
inline int dnetBoatUnfoldDice()
    { return 1; }

// the collapsible boat unfolds into a shallow boat (a small rowboat
// equivalent) in 1d3 turns.
inline int dnetBoatUnfoldSides()
    { return 3; }

// a collapsible boat carried when wet weighs twice the listed amount.
inline int dnetBoatWetMult()
    { return 2; }

// the collapsible boat's skin hull and folding-spar frame fold into a
// backpack-sized package (filling the backpack), unfolding into a shallow
// boat equivalent to a small rowboat.
inline bool dnetBoatBackpack()
    { return true; }

// a canoe can carry three characters with normal gear.
inline int dnetCanoeNormalCrew()
    { return 3; }

// a canoe can carry two characters with heavy gear.
inline int dnetCanoeHeavyCrew()
    { return 2; }

// a large canoe can hold nine characters with normal gear.
inline int dnetCanoeLgNormalCrew()
    { return 9; }

// a large canoe can hold six characters with heavy gear.
inline int dnetCanoeLgHeavyCrew()
    { return 6; }

// the canoe is designed for light loads and easy paddling - much swifter and
// more maneuverable than a rowboat, but more susceptible to capsizing.
inline bool dnetCanoeLight()
    { return true; }

// the one-character kayak works well in rough or cold water, its oilskin
// layer completely surrounding the frame except the kayaker's opening - even
// capsizing does not fill it with water.
inline bool dnetKayakSealed()
    { return true; }

}   // namespace rules
