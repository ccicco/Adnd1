// =========================================================================================
// Adnd1 - rules/dsgmove2.h
// The DSG MOVEMENT CHAPTER PART II, R505: the printed pp. 19-22 (pdf 20-23)
// second half of the movement chapter - the bridge rules (the maintained
// no-check rule, the suspension/wooden/stone permanent bridges, the rope and
// log impromptu bridges with the move-log ladder), the expanded falling rules
// (the cumulative 1d6-per-10-feet dice, the 20d6 and 10d6 caps, the 50-foot
// stop window, the landing ladder, the slope slides), spelunking with TABLE 7
// MINIMUM PASSAGEWAY SIZES, the excavation with TABLE 8 ARMOR EFFECTS ON
// CHARACTER WIDTH, the fatigue and exhaustion ladders, the darkness movement
// with TABLE 9 COURSE CHANGES IN DARKNESS, and the slippery horizontal
// surfaces with the crampon rules. The movement chapter parent closes this
// round: the whole chapter is pinned.
// census 429 -> 430.
//
// the DSG scan (the user own copy), printed pp. 19-22 = pdf 20-23, pulled
// per-page on the r504-extraction branch (p020-p023) with the tsv confidence
// tables and the 300-dpi page images under extract/r504/ on main; the Table 7
// human/dwarf/half-orc rows and the Table 8 splint/banded/plate/field cells
// were image-only reads, each cross-checked against the tsv fragments (the
// residual cautions live in the r504 extraction grids file).
//
// THE SETTLE: census 429 -> 430; the gap report 27/128 -> 38 closed / 117
// open (the seven movement-chapter boxes from bridges through slippery
// surfaces, the movement parent, and the manifest tables 7-9; the movement
// chapter is now fully closed). CROSS-BOOK SEAM: the fall dice ladder, the
// 20d6 cap and the 50-foot stop window verified const-for-const against
// rules/wsgfall.h and rules/wsgstop.h (agreement at every compared value);
// the slippery rules against rules/wsgslip.h and the waterfall against the
// WSG water pins (no divergence; the 10d6 waterfall cap is DSG-only, the WSG
// has no cap pin); the fatigue against rules/wsgfatig.h (const-for-const
// agreement on the 4/2 cycle, the 6-then-5-then-shrinking check interval, the
// -2 effects, the 12-turn clear and the 6-turn recoveries - ONE FRAMING
// DIVERGENCE: the WSG exhausted penalty is an additional -2, the DSG a -4
// instead of the fatigue -2; both total -4 and the DSG pins as printed).
// NOTHING auto-credited.
//
namespace rules {

// ---- bridges - the permanent bridges ----

// a bridge maintained periodically and not sabotaged is crossed without any
// checks, regardless of type.
inline bool dmxMaintainedBridgeNoChecks()
    { return true; }

// an old suspension bridge stands a 25 percent chance per character crossing
// it of giving way at some crucial point.
inline int dmxSuspensionGiveWayPct()
    { return 25; }

// the suspension give-way chance is rolled per character crossing, not per
// crossing.
inline bool dmxSuspensionGiveWayPerChar()
    { return true; }

// a character who fails the first suspension check and tries to catch a piece
// of the bridge with only one hand free checks at -25 percent; he can drop
// what he is holding to free both hands.
inline int dmxSuspensionCatchBridgeModPct()
    { return -25; }

// sabotaging an anchor point of a suspension bridge takes 1d8 rounds.
inline int dmxAnchorSabotageDie()
    { return 8; }

// anchor sabotage can only be detected by a thief find traps roll.
inline bool dmxAnchorSabotageThiefDetectOnly()
    { return true; }

// sawing through a rope support of a suspension bridge can be done in one
// round.
inline int dmxSawRopeRounds()
    { return 1; }

// a sawed rope support is readily visible to any character who examines the
// bridge.
inline bool dmxSawRopeVisible()
    { return true; }

// a wooden bridge not inspected and repaired within the past year stands a 5
// percent chance per year of sustaining rot.
inline int dmxWoodRotPctPerYear()
    { return 5; }

// the actual supporting beams of a wooden bridge last 1d20+20 years before
// beginning to rot; rot first affects the planks and railings.
inline int dmxWoodBeamDie()
    { return 20; }

// the beam-rot base: 1d20 plus 20 years.
inline int dmxWoodBeamBaseYears()
    { return 20; }

// each character crossing a rotted wooden bridge stands a 50 percent chance
// of stepping onto a rotten portion.
inline int dmxRottenStepPct()
    { return 50; }

// a character who steps onto a rotten portion makes Climbing Checks to
// determine whether he falls, as described for suspension bridges.
inline bool dmxRottenStepSuspensionChecks()
    { return true; }

// stone bridges are the most solid, virtually impervious to the effects of
// sabotage and age.
inline bool dmxStoneBridgeSabotageImmune()
    { return true; }

// even a weakened stone bridge will rarely collapse because of the added
// weight of a character.
inline bool dmxStoneWeightCollapseRare()
    { return true; }

// if the center of a stone bridge arch is destroyed (transmute rock to mud),
// the entire bridge collapses in 1d4 rounds.
inline int dmxArchCenterCollapseDie()
    { return 4; }

// if a stone bridge foundation is destroyed, the bridge collapses instantly.
inline bool dmxFoundationCollapseInstant()
    { return true; }

// a foundation collapse runs in both directions from the ruined foundation
// until it reaches the next foundation or the end of the bridge.
inline bool dmxFoundationCollapseToNext()
    { return true; }

// ---- bridges - the impromptu bridges ----

// a character crossing a rope bridge (one rope for the feet, one for the
// hands) makes a Climbing Check with a +50 percent modifier.
inline int dmxRopeBridgeModPct()
    { return 50; }

// armor and race modifiers affect the rope bridge roll normally.
inline bool dmxRopeBridgeArmorRaceApply()
    { return true; }

// a character on a rope bridge when one rope is chopped through makes an
// unmodified Climbing Check or falls.
inline bool dmxRopeSabotageUnmodifiedCheck()
    { return true; }

// a character clinging to the sabotaged rope with his hands checks at -20
// percent, or may elect to hold on and swing down with it.
inline int dmxRopeSabotageClingModPct()
    { return -20; }

// a log bridge must be 1/4 or less of the character height in diameter to
// require a check; wider log bridges are crossed automatically.
inline int dmxLogDiaHeightDiv()
    { return 4; }

// a log bridge wider than 1/4 the character height is crossed without a
// check.
inline bool dmxLogWiderAutoCross()
    { return true; }

// crossing a log bridge requires a Climbing Check with a +40 percent
// modifier.
inline int dmxLogBridgeModPct()
    { return 40; }

// if the log bridge slopes upward or downward, the modifier drops to +20
// percent.
inline int dmxLogSlopedModPct()
    { return 20; }

// if the character crawls or has both hands free, the log bridge modifier is
// +80 percent.
inline int dmxLogCrawlModPct()
    { return 80; }

// the move-log ladder floor: a normal human can move a log of 10 feet or
// shorter length (a 1 1/2-foot diameter log).
inline int dmxHumanLogFt()
    { return 10; }

// a human with 17 or 18 Strength, or a creature like an ogre, can move a
// 20-foot log.
inline int dmxStr17LogFt()
    { return 20; }

// a hill giant, or a fairly young dragon, can move a 30-foot log.
inline int dmxHillGiantLogFt()
    { return 30; }

// a large giant or dragon can move a 40-foot log.
inline int dmxLargeGiantLogLoFt()
    { return 40; }

// a large giant or dragon can move a log of up to 50 feet in length.
inline int dmxLargeGiantLogHiFt()
    { return 50; }

// ---- falling - the expanded rules ----

// falling damage is 1d6 for the first 10 feet, 2d6 for the second, 3d6 for
// the third, and so on - each 10-foot band adds one more die, cumulative.
inline int dmxFallIncrementPer10Ft()
    { return 1; }

// the printed example: a 30-foot fall inflicts a total of 6d6 (1+2+3).
inline int dmxThirtyFtFallDice()
    { return 6; }

// the maximum damage any fall can inflict is 20d6, regardless of the height.
inline int dmxFallCapDice()
    { return 20; }

// the maximum damage a character can sustain by falling over a waterfall is
// 10d6.
inline int dmxWaterfallCapDice()
    { return 10; }

// for purposes of game balance, a character falls 1,000 feet in one round
// unless the fall is interrupted.
inline int dmxFallFtPerRound()
    { return 1000; }

// an attempt to slow a fall by catching onto a wall or climbing surface can
// only be made in the first 50 feet - past that the momentum is too great.
inline int dmxStopWindowFt()
    { return 50; }

// on a nonslippery climbing surface the fall is stopped on a d100 roll less
// than or equal to 1/2 the Climbing Rating.
inline int dmxStopNonslipDiv()
    { return 2; }

// a slightly slippery surface can be caught on 1/4 the Climbing Rating - half
// the nonslippery chance.
inline int dmxStopSlightDiv()
    { return 4; }

// a slippery climbing surface cannot be used to stop a fall.
inline bool dmxStopSlipperyImpossible()
    { return true; }

// ---- falling - the landing ladder ----

// a landing on broken rocks, debris, or a slanted surface that ricochets the
// character inflicts double the normal fall damage.
inline int dmxRoughLandingMult()
    { return 2; }

// each spike or weapon-like feature of a landing area inflicts an extra d6 of
// damage beyond the fall.
inline int dmxSpikeDamageDie()
    { return 6; }

// a 1d6 grouping of spikes means the character impales himself on 1 to 6 of
// them.
inline int dmxSparseSpikeMinDice()
    { return 1; }

// the sparse spike grouping impales on up to 6 spikes.
inline int dmxSparseSpikeMaxDice()
    { return 6; }

// a 3d6 grouping of densely packed spikes impales on 3 to 18 spikes.
inline int dmxDenseSpikeMinDice()
    { return 3; }

// the dense spike grouping impales on up to 18 spikes, 3-18 d6 of damage in
// addition to the fall.
inline int dmxDenseSpikeMaxDice()
    { return 18; }

// a soft landing on sand, mud, soft loam, pine branches or flesh inflicts
// only half the normal fall damage.
inline int dmxSoftLandingDiv()
    { return 2; }

// a character making a very soft landing (a prepared cushion of feathers or
// straw) makes a saving throw vs. paralyzation.
inline bool dmxVerySoftSaveVsParalysis()
    { return true; }

// a failed very-soft save still halves the fall damage.
inline int dmxVerySoftFailDiv()
    { return 2; }

// a successful Dexterity Check into water costs 1d6 of damage for every 100
// feet of the fall.
inline int dmxWaterLandingDiePer100Ft()
    { return 1; }

// the water-landing damage dice are rounded up: a 250-foot fall costs 3d6.
inline bool dmxWaterLandingRoundUp()
    { return true; }

// the printed example: a character falling 250 feet into water with a
// successful Dexterity Check suffers only 3d6.
inline int dmxExample250FtWaterDice()
    { return 3; }

// a character cannot attempt to stop a fall by catching a climbing surface
// and make a Dexterity Check to land in water during the same round.
inline bool dmxNoCatchAndWaterSameRound()
    { return true; }

// if the fall lasts more than one round, the character can attempt the
// Dexterity Check on the second round.
inline bool dmxWaterCheckSecondRoundAllowed()
    { return true; }

// ---- falling - sliding down slopes ----

// a character sliding down a sloping surface suffers no damage in the first
// 20 feet of the slide.
inline int dmxSlideFreeFt()
    { return 20; }

// past the first 20 feet, a slide inflicts 1d6 of damage for each 10 feet of
// the slide (the abrasions), unless the slope is very slippery.
inline int dmxSlideDiePer10Ft()
    { return 1; }

// the landing after a slide inflicts 1d6 for each 40 feet of the slide.
inline int dmxSlideLandingDiePer40Ft()
    { return 1; }

// on a smooth and relatively slippery slope the character sustains no damage
// while sliding.
inline bool dmxSlipperySlideNoDamage()
    { return true; }

// a slide down a slippery slope takes double the normal damage upon landing.
inline int dmxSlipperySlideLandingMult()
    { return 2; }

// ---- spelunking - the tight squeeze ----

// if the tunnel ceiling is lower than the character height but at least 2/3
// of it, he can walk upright.
inline int dmxUprightMinCeilNum()
    { return 2; }

// the upright-walk ceiling floor is 2/3 the character height.
inline int dmxUprightMinCeilDen()
    { return 3; }

// walking upright under a low ceiling moves at 2/3 of the normal movement
// rate, with no adverse combat effects.
inline int dmxUprightRateNum()
    { return 2; }

// the upright low-ceiling rate denominator: 2/3 normal.
inline int dmxUprightRateDen()
    { return 3; }

// a character traveling on hands and knees (a tunnel under 2/3 his height)
// moves at 1/2 his normal movement rate.
inline int dmxHandsKneesRateDiv()
    { return 2; }

// a character fighting on hands and knees suffers a -5 penalty to all his
// attack rolls.
inline int dmxHandsKneesAtkMod()
    { return -5; }

// a hands-and-knees character also loses all Dexterity and shield bonuses to
// AC.
inline bool dmxHandsKneesLoseDexShieldAc()
    { return true; }

// weapons such as longbows, broadswords and battleaxes cannot be employed in
// these close quarters (the Space Required listing on the Weapons Tables is
// the guide).
inline bool dmxHandsKneesLongWeaponsUnusable()
    { return true; }

// in a tunnel whose diameter is 1/4 or less of his height, the character must
// slither along prone.
inline int dmxProneCeilDiv()
    { return 4; }

// a prone character is limited to 1/4 of his normal rate of movement.
inline int dmxProneRateDiv()
    { return 4; }

// a prone character suffers a -8 modifier to all his attack rolls.
inline int dmxProneAtkMod()
    { return -8; }

// a prone character can gain no Armor Class benefits from a shield or a
// Dexterity bonus.
inline bool dmxProneNoShieldDexAc()
    { return true; }

// the prone space limits his choice of weapons even further than the
// hands-and-knees position.
inline bool dmxProneWeaponLimitsWorse()
    { return true; }

// the passageway sizes assume no bulky armor or backpack - a character
// usually drags his pack behind him, negotiating tighter passages.
inline bool dmxDragPackTighter()
    { return true; }

// Table 7 has six race rows: human, half-orc, dwarf, gnome, elf and halfling.
inline int dmxPassagewayRowCount()
    { return 6; }

// The minimum tunnel width in inches by race row: human 24, half-orc 24,
// dwarf 24, gnome 18, elf 18, halfling 12 - the printed 2, 2, 2, 1 1/2, 1 1/2
// and 1 feet.
inline int dmxT7WidthIn(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 24;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 12;
        default:
            return 0;
        }
    }

// The minimum tunnel crawl height in inches by race row: human 12, half-orc
// 16, dwarf 12, gnome 9, elf 9, halfling 8 - the printed 1, 1 1/3, 1, 3/4,
// 3/4 and 2/3 feet.
inline int dmxT7HeightIn(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 16;
        case 2:
            return 12;
        case 3:
            return 9;
        case 4:
            return 9;
        case 5:
            return 8;
        default:
            return 0;
        }
    }

// ---- excavation - rubble and solid barriers ----

// in one turn of excavation a character can clear 1d4 feet of loosely packed
// rubble passageway to the Table 7 minimum width.
inline int dmxRubbleClearFtDie()
    { return 4; }

// if the passage is only partially blocked, the distance cleared in a turn is
// 2d4 feet.
inline int dmxRubblePartialDieMult()
    { return 2; }

// the solid-barrier excavation rates assume the characters use pickaxes.
inline bool dmxSolidPickaxesAssumed()
    { return true; }

// if other metal tools (shovels, swords) are substituted for pickaxes, the
// excavation rate is only 1/4 the Table 27 rate.
inline int dmxSolidRateDiv()
    { return 4; }

// Table 8 has eleven armor rows: leather, padded, studded leather, scale,
// ring, chain, splint, banded, plate, field plate and full plate.
inline int dmxArmorWidthRowCount()
    { return 11; }

// The increase in the character width in inches by armor row: leather 0,
// padded 2, studded leather 2, scale 3, ring 2, chain 3, splint 3, banded 6,
// plate 8, field plate 10, full plate 12 - the printed none, 1/6, 1/6, 1/4,
// 1/6, 1/4, 1/4, 1/2, 2/3, 5/6 and 1 foot.
inline int dmxT8WidthAddIn(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 6;
        case 8:
            return 8;
        case 9:
            return 10;
        case 10:
            return 12;
        default:
            return 0;
        }
    }

// ---- fatigue and exhaustion ----

// a character can avoid fatigue by resting for two turns after each four
// turns of unusually strenuous activity - keep the pattern and he is never
// susceptible.
inline int dmxFatigueWorkTurns()
    { return 4; }

// the paired rest: two turns of rest per four turns of work.
inline int dmxFatigueRestTurns()
    { return 2; }

// six turns of unusually strenuous activity without the two turns of rest
// force a Constitution Check; failure fatigues the character.
inline int dmxFatigueFirstCheckTurns()
    { return 6; }

// after a successful first check, five more turns of strenuous activity force
// another Constitution Check.
inline int dmxFatigueSecondCheckAfterTurns()
    { return 5; }

// each subsequent successful check shortens the interval by one turn - five,
// then four, and so on until the character must check every turn.
inline int dmxFatigueIntervalStepTurns()
    { return 1; }

// a character whose checks have all succeeded fully recovers by spending an
// hour (six turns) resting.
inline int dmxFatigueRecoveryTurns()
    { return 6; }

// a fatigued character has all his attribute scores lowered by 2, with the
// attendant temporary losses of hit points, spells and combat bonuses.
inline int dmxFatigueAttrMod()
    { return -2; }

// a fatigued character applies a -2 penalty to all his attack rolls, damage
// rolls and saves.
inline int dmxFatigueCombatMod()
    { return -2; }

// the fatigue effects last until the character rests for two hours (12
// turns).
inline int dmxFatigueEffectTurns()
    { return 12; }

// henchmen will not desert because of the temporary Charisma lowering.
inline bool dmxFatigueHenchmenStay()
    { return true; }

// a fatigued character who continues the strenuous activity must make a
// Constitution Check every turn.
inline bool dmxFatigueContinuingCheckEveryTurn()
    { return true; }

// the fatigued every-turn checks roll against his revised Constitution score.
inline bool dmxFatigueCheckVsRevisedCon()
    { return true; }

// merely marching along, even over difficult terrain, is not an unusually
// strenuous activity; fighting, running, continuous climbing, chopping wood,
// rough or swift swimming, and moving while encumbered are.
inline bool dmxFatigueMarchNotStrenuous()
    { return true; }

// an exhausted character cannot perform any voluntary physical labor and must
// rest until he recovers.
inline bool dmxExhaustedNoVoluntaryLabor()
    { return true; }

// an exhausted character forced to act suffers a -4 penalty to all the
// attribute and combat scores affected by fatigue.
inline int dmxExhaustedMod()
    { return -4; }

// the exhausted -4 is instead of, not in addition to, the fatigue penalties
// (a WSG divergence - the WSG frames exhaustion as an additional -2; both
// books total -4).
inline bool dmxExhaustedInsteadOfFatigue()
    { return true; }

// after one hour of uninterrupted rest an exhausted character rolls a
// Constitution Check (revised score); success makes him merely fatigued,
// failure forces another full hour.
inline int dmxExhaustRecoveryTurns()
    { return 6; }

// a successful exhaustion-recovery check leaves the character fatigued, not
// fresh.
inline bool dmxExhaustCheckToFatigued()
    { return true; }

// ---- movement effects of darkness ----

// a character moving at normal rates in darkness who encounters an obstacle
// must make a Dexterity Check or his momentum carries him into it.
inline bool dmxDarkObstacleDexCheck()
    { return true; }

// characters in the dark can safely move at 1/3 their normal movement rates,
// probing the ground ahead.
inline int dmxDarkSafeRateDiv()
    { return 3; }

// without some means of determining direction, such as trailing a hand along
// a corridor wall, it is virtually impossible to walk a straight line in
// complete darkness.
inline bool dmxDarkNeedDirectionMeans()
    { return true; }

// the DM makes a secret roll on 1d12 for the unknown course changes that
// occur walking in complete darkness.
inline int dmxDarkCourseDie()
    { return 12; }

// the course roll is made after every three turns spent walking in darkness.
inline int dmxDarkCourseRollEveryTurns()
    { return 3; }

// if the uncharted movement lasted less than three turns, the roll is still
// made, with a -1 modifier to the d12 for each turn short.
inline int dmxDarkCourseShortModPerTurn()
    { return -1; }

// each failed Dexterity Check on a rough or uneven floor means the character
// sustains 1 point of damage in a rough fall.
inline int dmxDarkRoughFallDamage()
    { return 1; }

// characters traveling rough floors in darkness prevent the accidents by
// slowing to 1/6 their normal rate.
inline int dmxDarkRoughSafeRateDiv()
    { return 6; }

// Table 9 has twelve d12 rows, 1 through 12.
inline int dmxCourseChangeRowCount()
    { return 12; }

// The course change in degrees by d12 row: rows 1-3 straight ahead (0), rows
// 4-5 forty-five right, rows 6-7 forty-five left, row 8 sixty right, row 9
// sixty left, row 10 ninety right, row 11 ninety left, row 12 one hundred
// thirty-five.
inline int dmxT9Deg(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 45;
        case 4:
            return 45;
        case 5:
            return 45;
        case 6:
            return 45;
        case 7:
            return 60;
        case 8:
            return 60;
        case 9:
            return 90;
        case 10:
            return 90;
        case 11:
            return 135;
        default:
            return 0;
        }
    }

// The direction by d12 row: 0 straight, 1 right, 2 left, and 3 the 135-degree
// row whose direction rolls on 1d6 (1-3 right, 4-6 left).
inline int dmxT9Dir(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// the 135-degree row resolves its direction on 1d6.
inline int dmxT9RolledDirDie()
    { return 6; }

// on the 135-degree row, a 1-3 rolls the course to the right.
inline int dmxT9RolledRightLo()
    { return 1; }

// the right-direction ceiling on the rolled row: 1-3 of the 1d6.
inline int dmxT9RolledRightHi()
    { return 3; }

// ---- movement on slippery horizontal surfaces ----

// characters cautiously treading a slippery surface can travel at their
// normal movement rate as long as they move in a straight line.
inline bool dmxSlipStraightLineSafe()
    { return true; }

// if the character attempts to turn, stop suddenly, or break into a run on a
// slippery surface, he must make a Dexterity Check or fall down.
inline bool dmxSlipTurnStopRunDexCheck()
    { return true; }

// a character who falls down on a slippery surface suffers no damage.
inline bool dmxSlipFallNoDamage()
    { return true; }

// a character who falls on a slippery surface spends a full round climbing to
// his feet.
inline int dmxSlipRiseRounds()
    { return 1; }

// a character moving at 1/2 his normal movement rate can turn without making
// a Dexterity Check.
inline bool dmxSlipHalfRateTurnFree()
    { return true; }

// a character can spend a round slowing down from normal speed to 1/2 speed,
// and then turn without a check.
inline int dmxSlipSlowdownRounds()
    { return 1; }

// characters engaging in melee combat on a slippery surface must make a
// Dexterity Check before every attack; a failed check means no attack and a
// fall.
inline bool dmxSlipMeleeCheckEveryAttack()
    { return true; }

// a character who fails the melee Dexterity Check on a slippery surface
// suffers a +4 penalty to his Armor Class for the round.
inline int dmxSlipFailAcPenalty()
    { return 4; }

// after a failed melee slip the character spends the next round getting to
// his feet, the AC penalty remaining in effect, and cannot attack that round.
inline int dmxSlipFailRiseRounds()
    { return 1; }

// a character who elects to fight from the ground keeps the +4 AC penalty and
// incurs a -4 penalty on all his attack rolls.
inline int dmxSlipGroundAtkMod()
    { return -4; }

// characters wearing crampons always retain their footing on slick surfaces -
// no Dexterity Checks are needed while turning or fighting.
inline bool dmxCramponsNeverFall()
    { return true; }

// a pair of crampons requires one turn to attach.
inline int dmxCramponAttachTurns()
    { return 1; }

// crampons take half a turn to remove.
inline bool dmxCramponRemoveHalfTurn()
    { return true; }

// a character walking on a nonslippery surface in crampons makes twice as
// much noise as he otherwise would.
inline int dmxCramponNoiseMult()
    { return 2; }

// walking on nonslippery surfaces wears the crampons out in 1d6 miles of such
// abuse.
inline int dmxCramponWearDie()
    { return 6; }

}   // namespace rules
