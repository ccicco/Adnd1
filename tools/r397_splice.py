#!/usr/bin/env python3
# R397: the UA scrolls rings
# rods staves wands prose
# completion - the four
# PDF-gated treasure items
# close in one round.
#
# The clean PDF read (pp.
# 91-98, the same clean OCR
# as R394-R396) delivers every
# description the extract
# garbled:
#
# 1. rules/uaprotscr.h (R377):
#    the cold, electricity and
#    two weapons scrolls pin;
#    the ledger flips 11/4 ->
#    15/0.
# 2. rules/uaringprose.h (R378):
#    boccob, chameleon power,
#    clumsiness, faerie, ram,
#    shocking grasp,
#    sustenance pin; 6/7 ->
#    13/0.
# 3. rules/uarodstave.h (R379):
#    flailing, passage,
#    splendor, staff-spear,
#    swarming insects,
#    thunder and lightning,
#    woodlands pin; 4/7 ->
#    11/0.
# 4. rules/uawandprose.h (R380):
#    the two flagged holes
#    (defoliation's opening,
#    metal command's verb)
#    fill and the five garbled
#    wands (buckler, earth and
#    stone, force, size
#    alteration, steam and
#    vapor) pin; 5/2/5 ->
#    12/0/0.
# 5. regtest.cpp: the four
#    ledgers and their seams
#    flip; the two hole-flag
#    asserts invert; a new
#    R397 audit block lands
#    before the R227 anchor;
#    the census 323 -> 324.
# 6. tools/ua_gap_report.md:
#    all four items flip
#    AMENDED R397: closed.
# 7. The seed takes the R396
#    record.
import io

NL = chr(10)
BS = chr(92)
NN = BS + 'n'

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def B(*lines):
    return NL.join(lines) + NL


def die(msg):
    raise SystemExit('R397 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


def flipall(path, old, new, expect, label):
    s = rd(path)
    if s.count(new) == expect:
        already.append(label)
        return
    n = s.count(old)
    if n != expect:
        die('%s: old text count %d, expected %d'
            % (label, n, expect))
    wr(path, s.replace(old, new))
    applied.append(label)


# ===== the data: (name, value, prose) =====
# bool values pin as true/
# false, ints as numbers; the
# prose wraps into header
# comment lines.

SCROLLS = [
    ('the protection from cold scroll', [
        ('uapsColdReadingSegs', 3,
         'Reading 3 segments; a 3"'
         ' sphere; normal cold'
         ' resisted down to'
         ' absolute zero.'),
        ('uapsColdSphereDiamIn', 3, ''),
        ('uapsColdNormalToAbsoluteZero', True, ''),
        ('uapsColdActsAsResistCold', True,
         'Against magical cold'
         ' the scroll acts as the'
         ' clerical resist cold'
         ' spell with enhanced'
         ' benefits.'),
        ('uapsColdMagicalSaveBonus', 6, ''),
        ('uapsColdNoSaveDmgQuarter', True,
         'Magical cold damages'
         ' one-quarter normal'
         ' without a save,'
         ' one-eighth with one.'),
        ('uapsColdSavedDmgEighth', True, ''),
        ('uapsColdDurationLoTurns', 5,
         'The duration 5-8 turns'
         ' (d4 + 4).'),
        ('uapsColdDurationHiTurns', 8, ''),
    ]),
    ('the protection from electricity scroll', [
        ('uapsElecReadingSegs', 5,
         'Reading 5 segments; a'
         ' 2" sphere; immunity to'
         ' any electrical attacks'
         ' and associated'
         ' effects; 3-12 rounds'
         ' (3d4).'),
        ('uapsElecSphereDiamIn', 2, ''),
        ('uapsElecImmuneAll', True, ''),
        ('uapsElecDurationLoRounds', 3, ''),
        ('uapsElecDurationHiRounds', 12, ''),
    ]),
    ('the protection from weapons, magical scroll', [
        ('uapsWeapMagReadingRounds', 1,
         'Reading 1 round; the'
         ' reader only; the'
         ' indicated magic weapon'
         ' cannot touch or harm;'
         ' missile protection does'
         ' NOT extend to missiles'
         ' created by spell'
         ' casting (such as magic'
         ' missile) or a'
         ' spell-like power; 5-8'
         ' rounds (d4 + 4).'),
        ('uapsWeapMagReaderOnly', True, ''),
        ('uapsWeapMagExemptsSpellMissiles', True, ''),
        ('uapsWeapMagDurationLoRounds', 5, ''),
        ('uapsWeapMagDurationHiRounds', 8, ''),
    ]),
    ('the protection from weapons, non-magic scroll', [
        ('uapsWeapNonMagReadingRounds', 1,
         'Reading 1 round; a 1"'
         ' sphere; the indicated'
         ' non-magical weapon'
         ' cannot touch or harm;'
         ' missile protection does'
         ' NOT extend to normal'
         ' missiles of large size'
         ' (catapult projectiles,'
         ' objects hurled by'
         ' giants); 5-8 rounds'
         ' (d4 + 4).'),
        ('uapsWeapNonMagSphereDiamIn', 1, ''),
        ('uapsWeapNonMagExemptsLargeMissiles',
         True, ''),
        ('uapsWeapNonMagDurationLoRounds', 5, ''),
        ('uapsWeapNonMagDurationHiRounds', 8, ''),
    ]),
]

RINGS = [
    ('the ring of boccob', [
        ('uarpBoccobAppearsNonMagical', True,
         'An ornate ring that'
         ' appears valuable but'
         ' non-magical; even the'
         ' strongest magical'
         ' detection reveals'
         ' nothing.'),
        ('uarpBoccobUndetectable', True, ''),
        ('uarpBoccobContactsDeviceFails', True,
         'A contacting magical'
         ' device malfunctions and'
         ' fails to affect its'
         ' target.'),
        ('uarpBoccobFailedSaveNonMagical', True,
         'A device failing its'
         ' save versus the ring'
         ' turns non-magical.'),
        ('uarpBoccobQuiescenceLoHours', 1,
         'Each cancellation'
         ' silences the ring 1-4'
         ' hours.'),
        ('uarpBoccobQuiescenceHiHours', 4, ''),
        ('uarpBoccobSingleUseNotCancelled', True,
         'Single-use items (a'
         ' magic arrow, a'
         ' javelin of lightning)'
         ' are not cancelled,'
         ' only their magic is'
         ' blunted.'),
        ('uarpBoccobNormalDamageStill', True,
         'The immunity never'
         ' prevents the normal'
         ' damage of such an'
         ' item.'),
        ('uarpBoccobSaveAutoFailRoll', 1,
         'Item saves versus the'
         ' cancellation: 1'
         ' automatic failure; 2'
         ' relics; 3 artifacts; 4'
         ' hand-held weapons; 5'
         ' rods and staves; 6 all'
         ' other items; 7-20 any'
         ' item saves.'),
        ('uarpBoccobSaveRelicRoll', 2, ''),
        ('uarpBoccobSaveArtifactRoll', 3, ''),
        ('uarpBoccobSaveHandWeaponRoll', 4, ''),
        ('uarpBoccobSaveRodStaffRoll', 5, ''),
        ('uarpBoccobSaveOtherRoll', 6, ''),
        ('uarpBoccobSaveAnySavesLo', 7, ''),
        ('uarpBoccobSaveAnySavesHi', 20, ''),
    ]),
    ('the ring of chameleon power', [
        ('uarpChamInvisibilityPct', 90,
         'Magical blending with'
         ' the surroundings:'
         ' 90% invisibility in'
         ' foliage, against'
         ' walls, and so forth.'),
        ('uarpChamAssociateIntMin', 4,
         'Amid creatures of'
         ' intelligence 4 or'
         ' greater within 6",'
         ' the wearer seems one'
         ' of them; each turn of'
         ' association carries'
         ' a 5% cumulative'
         ' detection chance.'),
        ('uarpChamAssociateRangeIn', 6, ''),
        ('uarpChamDetectPctPerTurn', 5, ''),
        ('uarpChamMaxAssociationTurns', 20,
         'The association never'
         ' persists past 20'
         ' turns - the chance'
         ' reaches 100%.'),
        ('uarpChamIntBonusMin', 16,
         'Creatures of'
         ' intelligence 16 or'
         ' greater add their'
         ' intelligence score to'
         ' the base chance.'),
        ('uarpChamLowIntMax', 3,
         'Creatures of'
         ' intelligence 3 or'
         ' lower detect the'
         ' wearer instinctively'
         ' within 1".'),
        ('uarpChamLowIntRangeIn', 1, ''),
    ]),
    ('the ring of clumsiness', [
        ('uarpClumDisguisesBanefulNature', True,
         'A cursed ring'
         ' radiating a'
         ' disguising secondary'
         ' dweomer; it takes'
         ' effect only under'
         ' stress - combat,'
         ' stealth, delicate'
         ' activity.'),
        ('uarpClumTriggersUnderStress', True, ''),
        ('uarpClumSecondaryPowerCount', 7,
         'The secondary powers'
         ' roll d%: 01-10 free'
         ' action, 11-20 feather'
         ' falling, 21-35'
         ' invisibility, 36-50'
         ' jumping, 51-60'
         ' swimming, 61-80'
         ' warmth, 81-00 water'
         ' walking.'),
        ('uarpClumFreeActionLo', 1, ''),
        ('uarpClumFreeActionHi', 10, ''),
        ('uarpClumFeatherFallLo', 11, ''),
        ('uarpClumFeatherFallHi', 20, ''),
        ('uarpClumInvisibilityLo', 21, ''),
        ('uarpClumInvisibilityHi', 35, ''),
        ('uarpClumJumpingLo', 36, ''),
        ('uarpClumJumpingHi', 50, ''),
        ('uarpClumSwimmingLo', 51, ''),
        ('uarpClumSwimmingHi', 60, ''),
        ('uarpClumWarmthLo', 61, ''),
        ('uarpClumWarmthHi', 80, ''),
        ('uarpClumWaterWalkLo', 81, ''),
        ('uarpClumWaterWalkHi', 100, ''),
        ('uarpClumDexHalvedDown', True,
         'Dexterity drops to'
         ' half normal, rounded'
         ' down; stealth and'
         ' precise-action'
         ' chances halve the'
         ' same way.'),
        ('uarpClumStealthHalved', True, ''),
        ('uarpClumComponentNeedsSave', True,
         'Casting that handles a'
         ' material or somatic'
         ' component succeeds'
         ' only on a save versus'
         ' spell - else the'
         ' spell is botched and'
         ' annulled.'),
        ('uarpClumRemovalIsDispel', True,
         'Only a dispel magic'
         ' versus 12th-level'
         ' magic removes the'
         ' ring, destroying both'
         ' dweomers.'),
        ('uarpClumRemovalVsLevel', 12, ''),
        ('uarpClumRemovalDestroysBoth', True, ''),
    ]),
    ('the ring of faerie', [
        ('uarpFaerieGreyElfGift', True,
         'Given by the grey'
         ' elves to their closest'
         ' associates and'
         ' allies only; each'
         ' ring aligns to evil'
         ' (5%), good (75%), or'
         ' neutrality (20%).'),
        ('uarpFaerieEvilPct', 5, ''),
        ('uarpFaerieGoodPct', 75, ''),
        ('uarpFaerieNeutralPct', 20, ''),
        ('uarpFaerieAlignmentMustMatch', True,
         'A ring of contrary'
         ' alignment will not'
         ' function.'),
        ('uarpFaerieWoodlandHideInvisible', True,
         'In woodlands the'
         ' wearer is detectable'
         ' only by creatures able'
         ' to detect invisible'
         ' objects.'),
        ('uarpFaerieSilenceNeedsAlone', True,
         'Alone and not in'
         ' metal armor, the'
         ' wearer moves'
         ' silently: a 01-67'
         ' roll (66 and two-thirds'
         ' percent) succeeds and'
         ' grants surprise on 1-4'
         ' on a d6.'),
        ('uarpFaerieSilenceNoMetalArmor', True,
         ''),
        ('uarpFaerieSilentSuccessHi', 67, ''),
        ('uarpFaerieNoiseFeetMin', 68,
         'A 68 or higher means'
         ' the movement noise'
         ' carries that many'
         ' feet.'),
        ('uarpFaerieSurpriseDieMin', 1, ''),
        ('uarpFaerieSurpriseDieMax', 4, ''),
        ('uarpFaerieInfravisionFeet', 60,
         'Infravision to 60'
         ' feet.'),
        ('uarpFaerieConcealedPassDie', 1,
         'Concealed doors'
         ' noted 16 and'
         ' two-thirds percent (1'
         ' on d6) in passing,'
         ' 50% when actively'
         ' searched.'),
        ('uarpFaerieConcealedSearchedPct',
         50, ''),
        ('uarpFaerieSecretSearchedDieMin', 1,
         'Secret doors found'
         ' 33 and one-third'
         ' percent (1-2 on d6)'
         ' when actively'
         ' searched.'),
        ('uarpFaerieSecretSearchedDieMax',
         2, ''),
    ]),
    ('the ring of the ram', [
        ('uarpRamDmgLoOneCharge', 1,
         'The ram-force'
         ' strikes one target:'
         ' 1-6 at 1 charge,'
         ' 2-12 at 2, 3-18 at'
         ' 3 (the maximum);'
         ' range 3".'),
        ('uarpRamDmgHiOneCharge', 6, ''),
        ('uarpRamDmgLoTwoCharges', 2, ''),
        ('uarpRamDmgHiTwoCharges', 12, ''),
        ('uarpRamDmgLoThreeCharges', 3, ''),
        ('uarpRamDmgHiThreeCharges', 18, ''),
        ('uarpRamMaxChargesPerAttack', 3, ''),
        ('uarpRamRangeIn', 3, ''),
        ('uarpRamFailedSaveKnockedFree', True,
         'A failed save versus'
         ' spell knocks the'
         ' victim free - off'
         ' walls, ladders,'
         ' ledges.'),
        ('uarpRamAdjSmaller', -1,
         'Save adjustments:'
         ' smaller than'
         ' man-sized -1, larger'
         ' +2, Strength under'
         ' 12 -1, Strength 18-20'
         ' +3, Strength over 20'
         ' +6, four or more'
         ' legs +4, over 1,000'
         ' pounds +2, 2 charges'
         ' -1, 3 charges -2.'),
        ('uarpRamAdjLarger', 2, ''),
        ('uarpRamAdjStrUnder12', -1, ''),
        ('uarpRamAdjStr18to20', 3, ''),
        ('uarpRamAdjStrOver20', 6, ''),
        ('uarpRamAdjFourLegs', 4, ''),
        ('uarpRamAdjOver1000Lbs', 2, ''),
        ('uarpRamAdjTwoCharges', -1, ''),
        ('uarpRamAdjThreeCharges', -2, ''),
        ('uarpRamDoorStrBase', 18,
         'Doors open as an'
         ' 18/00 Strength; 2'
         ' charges as Strength'
         ' 19, 3 as Strength'
         ' 20; held or locked'
         ' portals included.'),
        ('uarpRamDoorStrTwoCharges', 19, ''),
        ('uarpRamDoorStrThreeCharges', 20, ''),
        ('uarpRamStructuralAsBatteringRam',
         True,
         'Structural damage'
         ' matches an actual'
         ' battering ram, with'
         ' double or triple'
         ' damage at 2 or 3'
         ' charges.'),
        ('uarpRamStructuralDoubleTriple', True,
         ''),
        ('uarpRamItemsSaveOnlyAtThree', True,
         'Magic items struck'
         ' save versus'
         ' crushing blow only'
         ' at the full 3'
         ' charges; non-magical'
         ' items always save'
         ' against the'
         ' impact.'),
        ('uarpRamItemsSaveVsCrushing', True,
         ''),
        ('uarpRamChargesLo', 6,
         'Discovered with 6-60'
         ' charges; recharged'
         ' by enchant an item'
         ' plus Bigby\'s'
         ' Clenched Fist.'),
        ('uarpRamChargesHi', 60, ''),
        ('uarpRamRechargeNeedsFist', True, ''),
    ]),
    ('the ring of shocking grasp', [
        ('uarpShockFaintUnidentifiable', True,
         'Only a faint,'
         ' unidentifiable aura'
         ' radiates; a'
         ' successful touch'
         ' attack with the'
         ' ring hand delivers'
         ' 7-14 (d8 + 6).'),
        ('uarpShockNeedsTouchHit', True, ''),
        ('uarpShockDmgLo', 7, ''),
        ('uarpShockDmgHi', 14, ''),
        ('uarpShockDmgDieSides', 8, ''),
        ('uarpShockDmgPlus', 6, ''),
        ('uarpShockDischargesBeforeRest', 3,
         'After three'
         ' discharges the ring'
         ' goes inert for 1'
         ' turn.'),
        ('uarpShockRestTurns', 1, ''),
    ]),
    ('the ring of sustenance', [
        ('uarpSustNoFoodOrDrink', True,
         'Life-sustaining'
         ' nourishment without'
         ' food or drink; two'
         ' hours of sleep give'
         ' the benefit of'
         ' eight.'),
        ('uarpSustSleepHours', 2, ''),
        ('uarpSustSleepBenefitHours', 8, ''),
        ('uarpSustWearWeeks', 1,
         'A full week of'
         ' wearing attunes the'
         ' ring; removal'
         ' immediately drops'
         ' the benefits and'
         ' demands a fresh'
         ' week.'),
        ('uarpSustRemovalResets', True, ''),
        ('uarpSustReattuneWeeks', 1, ''),
        ('uarpSustConsecutiveDays', 7,
         'After any seven'
         ' consecutive days of'
         ' functioning the'
         ' ring rests one'
         ' week.'),
        ('uarpSustRestWeeks', 1, ''),
    ]),
]

RODS = [
    ('the rod of flailing', [
        ('uaroFlailAlterationDweomer', True,
         'A faint alteration'
         ' dweomer; upon'
         ' command a'
         ' normal-seeming rod'
         ' becomes a'
         ' double-headed'
         ' flail.'),
        ('uaroFlailDoubleHeaded', True, ''),
        ('uaroFlailMountedIsHorseman', True,
         'Mounted or in close'
         ' quarters it is the'
         ' small horseman\'s'
         ' weapon: 2-5/2-5;'
         ' otherwise the'
         ' footman\'s:'
         ' 2-7/2-8 (S-M/L).'),
        ('uaroFlailHorsemanDmgHi', 5, ''),
        ('uaroFlailFootmanSmHi', 7, ''),
        ('uaroFlailFootmanLHi', 8, ''),
        ('uaroFlailDmgLo', 2, ''),
        ('uaroFlailBonus', 3,
         'Either form strikes'
         ' at +3 to hit and'
         ' damage.'),
        ('uaroFlailBothHeadsChecked', True,
         'Both heads are'
         ' checked when the'
         ' possessor attacks:'
         ' double hits on one'
         ' opponent or two'
         ' man-sized-or-smaller'
         ' opponents standing'
         ' side by side.'),
        ('uaroFlailDoubleHitsPossible', True,
         ''),
        ('uaroFlailProtectionCharges', 1,
         'One charge grants'
         ' +4 protection and'
         ' +4 saving throws'
         ' for 1 turn -'
         ' without needing'
         ' the weapon form.'),
        ('uaroFlailProtectionBonus', 4, ''),
        ('uaroFlailProtectionTurns', 1, ''),
        ('uaroFlailTransformFree', True,
         'Transforming the rod'
         ' into a weapon or'
         ' back expends no'
         ' charges.'),
    ]),
    ('the rod of passage', [
        ('uaroPassFunctionCount', 5,
         'One at a time, one'
         ' per round: astral'
         ' travel, dimension'
         ' door, passwall,'
         ' phase door,'
         ' teleport without'
         ' error.'),
        ('uaroPassPerRound', 1, ''),
        ('uaroPassEachOncePerActivation', True,
         'One charge activates'
         ' the rod; each'
         ' function is usable'
         ' once per'
         ' activation.'),
        ('uaroPassActivationCharges', 1, ''),
        ('uaroPassActiveDays', 1,
         'The charge holds'
         ' one day or until'
         ' all five functions'
         ' are used; a second'
         ' charge re-opens all'
         ' five.'),
        ('uaroPassSecondChargeResets', True,
         ''),
        ('uaroPassAstralCreaturesMax', 5,
         'Astral travel may'
         ' carry up to five'
         ' creatures (the'
         ' wielder included),'
         ' but cancels the'
         ' remaining'
         ' functions.'),
        ('uaroPassAstralCancelsRest', True,
         ''),
        ('uaroPassTravelsToAstral', True,
         'The rod travels'
         ' along and cannot'
         ' be used or'
         ' reactivated until'
         ' returned from the'
         ' Astral Plane.'),
        ('uaroPassUnusableUntilReturned',
         True, ''),
        ('uaroPassRechargeMuLevel', 20,
         'Recharge demands a'
         ' magic-user of 20th'
         ' or higher level.'),
    ]),
    ('the rod of splendor', [
        ('uaroSplendorChaContinual', 18,
         'The possessor'
         ' carries a'
         ' continual charisma'
         ' of 18 while the'
         ' rod is held; at 18'
         ' or greater there is'
         ' no further'
         ' enhancement.'),
        ('uaroSplendorNoGainAt18', True, ''),
        ('uaroSplendorGarbCharges', 1,
         'One charge creates'
         ' and garbs noble'
         ' apparel worth'
         ' 7,000-10,000 gp'
         ' (d4 + 6).'),
        ('uaroSplendorGarbLoGp', 7000, ''),
        ('uaroSplendorGarbHiGp', 10000, ''),
        ('uaroSplendorFabricGp', 1000,
         'The fabric 1,000 gp,'
         ' furs 5,000 gp,'
         ' jewel trim'
         ' 1,000-4,000 gp.'),
        ('uaroSplendorFurGp', 5000, ''),
        ('uaroSplendorJewelLoGp', 1000, ''),
        ('uaroSplendorJewelHiGp', 4000, ''),
        ('uaroSplendorSaleDestroysAll', True,
         'Selling any part, or'
         ' any forcible'
         ' taking, destroys'
         ' all of the apparel;'
         ' freely given'
         ' garments stay'
         ' whole.'),
        ('uaroSplendorForcedDestroysAll',
         True, ''),
        ('uaroSplendorGiftPersists', True,
         ''),
        ('uaroSplendorSecondChargeWasted',
         True,
         'A second charge'
         ' while wearing the'
         ' created garb is'
         ' wasted.'),
        ('uaroSplendorTentCharges', 1,
         'One charge also'
         ' raises a palatial'
         ' silk tent of'
         ' 1,500-3,000 square'
         ' feet for 100'
         ' persons, lasting'
         ' one day.'),
        ('uaroSplendorTentLoSqFt', 1500,
         ''),
        ('uaroSplendorTentHiSqFt', 3000,
         ''),
        ('uaroSplendorTentPersons', 100,
         ''),
        ('uaroSplendorTentDays', 1, ''),
        ('uaroSplendorRechargeable', False,
         'The rod cannot be'
         ' recharged.'),
    ]),
    ('the staff-spear', [
        ('uaroSsAlterationAura', True,
         'An alteration aura;'
         ' three commands: a'
         ' spear blade from'
         ' the upper end,'
         ' elongation to a'
         ' full 12 feet,'
         ' recall to staff'
         ' form.'),
        ('uaroSsCommandCount', 3, ''),
        ('uaroSsElongateFeet', 12, ''),
        ('uaroSsTableRowCount', 6,
         'Die-roll table: 1-6'
         ' is +1 at 1,000 xp/'
         ' 5,000 gp; 7-10 +2,'
         ' 1,500/7,500; 11-13'
         ' +3, 2,000/10,000;'
         ' 14-16 +4,'
         ' 2,500/15,000;'
         ' 17-19 +5,'
         ' 3,000/20,000; 20'
         ' +3*, 3,500/25,000.'),
        ('uaroSsBonusMin', 1, ''),
        ('uaroSsBonusMax', 5, ''),
        ('uaroSsTopRollBonus', 3, ''),
        ('uaroSsTopRanseur', True,
         'The starred 20'
         ' entry does damage'
         ' as a ranseur'
         '(2-8) yet still'
         ' thrusts and sets'
         ' as a spear.'),
        ('uaroSsRanseurDmgLo', 2, ''),
        ('uaroSsRanseurDmgHi', 8, ''),
        ('uaroSsXpLo', 1000, ''),
        ('uaroSsXpHi', 3500, ''),
        ('uaroSsGpLo', 5000, ''),
        ('uaroSsGpHi', 25000, ''),
    ]),
    ('the staff of swarming insects', [
        ('uaroSwarmClericalOnly', True,
         'Cleric-types only'
         ' (cleric, druid,'
         ' shaman, witch'
         ' doctor); a charge'
         ' creates a swarm of'
         ' winged biting and'
         ' stinging insects.'),
        ('uaroSwarmRangeBaseIn', 6,
         'Range 6" plus 1" per'
         ' clerical level.'),
        ('uaroSwarmRangePerLevelIn', 1,
         ''),
        ('uaroSwarmBaseInsects', 60,
         'Sixty insects plus'
         ' ten per level; every'
         ' ten insects inflict'
         ' 1 point of damage'
         ' regardless of armor'
         ' class.'),
        ('uaroSwarmInsectsPerLevel', 10,
         ''),
        ('uaroSwarmInsectsPerDmg', 10,
         ''),
        ('uaroSwarmIgnoresArmorClass', True,
         ''),
        ('uaroSwarmLargeNaturalAcMin', 5,
         'Creatures larger'
         ' than man-sized with'
         ' natural armor class'
         ' 5 or better are'
         ' unaffected; the'
         ' victim can do'
         ' nothing but'
         ' dislodge or kill'
         ' the swarm.'),
        ('uaroSwarmAttackRounds', 1,
         'The attack lasts 1'
         ' round.'),
        ('uaroSwarmCarvingsVanish', True,
         'One carved'
         ' insect-shape'
         ' vanishes per use -'
         ' the carvings count'
         ' the charges.'),
        ('uaroSwarmMaxCharges', 50,
         'As many as 50'
         ' charges initially;'
         ' never recharged.'),
        ('uaroSwarmRechargeable', False,
         ''),
    ]),
    ('the staff of thunder and lightning', [
        ('uaroThunderBaseBonus', 2,
         'A stout quarterstaff'
         ' of ash, oak or'
         ' bronzewood,'
         ' iron-bound with'
         ' silver rivets; a'
         ' +2 weapon without'
         ' any charge.'),
        ('uaroThunderStrikeBonus', 3,
         'THUNDER: strikes at'
         ' +3; a failed save'
         ' versus rods staves'
         ' wands stuns the'
         ' opponent for the'
         ' rest of the round'
         ' struck and grants'
         ' it last initiative'
         ' the following'
         ' round; 1 charge.'),
        ('uaroThunderStunCharges', 1, ''),
        ('uaroThunderStunRestOfRound', True,
         ''),
        ('uaroThunderLastInitiative', True,
         ''),
        ('uaroThunderShockDmgLo', 2,
         'LIGHTNING: 2-12'
         ' extra points of'
         ' shock accompany the'
         ' strike; metal armor'
         ' is discounted -'
         ' the target is'
         ' effectively armor'
         ' class 10; 1'
         ' charge.'),
        ('uaroThunderShockDmgHi', 12, ''),
        ('uaroThunderShockCharges', 1, ''),
        ('uaroThunderDiscountsMetal', True,
         ''),
        ('uaroThunderEffectiveAc', 10, ''),
        ('uaroClapCharges', 2,
         'THUNDERCLAP: a cone'
         ' of deafening noise,'
         ' half an inch at the'
         ' apex, 4" long, 2"'
         ' wide at the far'
         ' end; failed saves'
         ' stun 1-2 rounds and'
         ' deafen 1-2 more;'
         ' savers are deaf'
         ' 1-4 rounds only; 2'
         ' charges.'),
        ('uaroClapApexHalfIn', 1, ''),
        ('uaroClapLengthIn', 4, ''),
        ('uaroClapFarWidthIn', 2, ''),
        ('uaroClapStunLo', 1, ''),
        ('uaroClapStunHi', 2, ''),
        ('uaroClapDeafLo', 1, ''),
        ('uaroClapDeafHi', 2, ''),
        ('uaroClapSaverDeafLo', 1, ''),
        ('uaroClapSaverDeafHi', 4, ''),
        ('uaroStrokeCharges', 2,
         'LIGHTNING STROKE:'
         ' eight dice (8d6),'
         ' 16-48 points,'
         ' rolls of 1 count'
         ' as 2; single or'
         ' forked; 2 charges.'),
        ('uaroStrokeDice', 8, ''),
        ('uaroStrokeDmgLo', 16, ''),
        ('uaroStrokeDmgHi', 48, ''),
        ('uaroStrokeOnesAsTwo', True, ''),
        ('uaroStrokeForkedOrSingle', True,
         ''),
        ('uaroCombinedCharges', 4,
         'THUNDER AND'
         ' LIGHTNING: the'
         ' thunderclap plus a'
         ' forked bolt; 8d6'
         ' with 1s and 2s'
         ' counted as 3,'
         ' 24-48 points; a'
         ' save means deafness'
         ' and half damage; 4'
         ' charges.'),
        ('uaroCombinedDice', 8, ''),
        ('uaroCombinedDmgLo', 24, ''),
        ('uaroCombinedDmgHi', 48, ''),
        ('uaroCombinedOnesTwosAsThree', True,
         ''),
        ('uaroCombinedSaveDeafHalf', True,
         ''),
        ('uaroActivationSegsEqualCharges',
         True,
         'Any function'
         ' activates in'
         ' segments equal to'
         ' the charges it'
         ' expends.'),
    ]),
    ('the staff of the woodlands', [
        ('uaroWoodDruidOnly', True,
         'Oak, ash, or yew,'
         ' bronze-bound and'
         ' shod; effective'
         ' only for a'
         ' druid.'),
        ('uaroWoodChargePowerCount', 3,
         'Per charge: wall of'
         ' thorns; animal'
         ' friendship plus'
         ' speak with animals;'
         ' animate tree.'),
        ('uaroWoodThornWallCharges', 1, ''),
        ('uaroWoodAnimalCharges', 1, ''),
        ('uaroWoodAnimateCharges', 1, ''),
        ('uaroWoodAnimateMoveIn', 3,
         'The animated tree'
         ' moves at 3" and'
         ' attacks as a'
         ' largest-sized'
         ' treant - a virtual'
         ' treant for eight'
         ' rounds per'
         ' charge.'),
        ('uaroWoodAnimateRounds', 8, ''),
        ('uaroWoodAnimateRoundToStart', 1,
         'One round animates'
         ' the tree; it'
         ' re-roots on the'
         ' eighth round, so'
         ' only six rounds'
         ' are usable.'),
        ('uaroWoodAnimateUsableRounds', 6,
         ''),
        ('uaroWoodAnimateRerootsOnEighth',
         True, ''),
        ('uaroWoodTopBonus', 4,
         'Weapon values with'
         ' once-per-day'
         ' extras: the +4'
         ' staff has none;'
         ' the +3 adds pass'
         ' without trace;'
         ' the +2 adds'
         ' barkskin; the +1'
         ' adds the tree'
         ' spell.'),
        ('uaroWoodPlus3Extras', 1, ''),
        ('uaroWoodPlus2Extras', 2, ''),
        ('uaroWoodPlus1Extras', 3, ''),
        ('uaroWoodExtrasOncePerDay', True,
         ''),
        ('uaroWoodTypeDieSides', 4,
         'Even chances (d4)'
         ' decide the staff'
         ' sort discovered.'),
    ]),
]

WANDS = [
    ('the buckler wand', [
        ('uawdBuckLengthTenthsFt', 15,
         'A shortish, thick'
         ' wand about one and'
         ' a half feet long;'
         ' an exceptionally'
         ' sharp point at one'
         ' end, the trigger'
         ' mechanism at the'
         ' blunt other end.'),
        ('uawdBuckSharpTipOneEnd', True,
         ''),
        ('uawdBuckTriggerOtherEnd', True,
         ''),
        ('uawdBuckBlocksCleric', True,
         'Usable by any'
         ' character except a'
         ' cleric; activation'
         ' takes a single'
         ' segment.'),
        ('uawdBuckActivateSegs', 1, ''),
        ('uawdBuckTipDaggerPlusOne', True,
         'Grasped thick end,'
         ' trigger pressed:'
         ' the tip equals a'
         ' dagger +1, the'
         ' shaft a buckler +1'
         ' shield; the whole'
         ' a spiked buckler'
         ' +1.'),
        ('uawdBuckShaftBucklerPlusOne',
         True, ''),
        ('uawdBuckWholeSpikedPlusOne', True,
         ''),
        ('uawdBuckMuMayEmploy', True,
         'Magic-users may'
         ' employ it, but no'
         ' spells may be cast'
         ' while it is in'
         ' buckler form'
         ' unless the caster'
         ' is multi-classed'
         ' with fighter and'
         ' magic-user'
         ' abilities.'),
        ('uawdBuckMuNoSpellsInForm', True,
         ''),
        ('uawdBuckMulticlassException', True,
         ''),
        ('uawdBuckThiefNoClimbing', True,
         'A thief employing it'
         ' cannot climb walls'
         ' or use other'
         ' hand-requiring'
         ' abilities while'
         ' holding the'
         ' device.'),
    ]),
    ('the wand of earth and stone', [
        ('uawdEarthDigCostTenths', 5,
         'A shortish'
         ' mineral-tipped'
         ' wand: dig costs a'
         ' half charge,'
         ' passwall 1, move'
         ' earth 2.'),
        ('uawdEarthPasswallCharges', 1, ''),
        ('uawdEarthMoveEarthCharges', 2, ''),
        ('uawdEarthPctWithExtras', 50,
         'Half of these wands'
         ' (the'
         ' higher-valued)'
         ' add transmute mud'
         ' to rock and'
         ' transmute rock to'
         ' mud, 1 charge'
         ' each.'),
        ('uawdEarthExtrasAreHigherValued',
         True, ''),
        ('uawdEarthExtraPowerCount', 2, ''),
        ('uawdEarthMudToRockCharges', 1, ''),
        ('uawdEarthRockToMudCharges', 1, ''),
    ]),
    ('the wand of force', [
        ('uawdForceFunctionCount', 3,
         'A tri-function'
         ' device; the third'
         ' demands operator'
         ' knowledge.'),
        ('uawdForceShaftFeet', 4,
         'First: a nearly'
         ' invisible blue-white'
         ' shaft of energy,'
         ' 4 feet long, equal'
         ' to a +5 bastard'
         ' sword; 1 charge'
         ' per turn.'),
        ('uawdForceShaftPlusFive', True,
         ''),
        ('uawdForceShaftIsBastard', True,
         ''),
        ('uawdForceShaftChargesPerTurn', 1,
         ''),
        ('uawdForceWallCasterLevel', 10,
         'Second: a wall of'
         ' force as a'
         ' 10th-level'
         ' magic-user; 1'
         ' charge per wall,'
         ' a single usage per'
         ' round.'),
        ('uawdForceWallCharges', 1, ''),
        ('uawdForceWallOncePerRound', True,
         ''),
        ('uawdForceHandNeedsMu', True,
         'Third: a Bigby\'s'
         ' Forceful Hand'
         ' plane; the user'
         ' must be a'
         ' magic-user with a'
         ' Bigby\'s Hand or'
         ' Fist spell recorded'
         ' in the books; half'
         ' a charge per'
         ' round.'),
        ('uawdForceHandNeedsSpellRecorded',
         True, ''),
        ('uawdForceHandCostTenths', 5, ''),
        ('uawdForceFightersUseFirstTwo', True,
         'Fighters of all'
         ' types use the'
         ' first and second'
         ' functions;'
         ' recharge by a'
         ' magic-user of 16th'
         ' or higher.'),
        ('uawdForceRechargeMuLevel', 16,
         ''),
        ('uawdForceTouchDisintegrates', True,
         'Touching a Bigby\'s'
         ' Hand or Fist, a'
         ' Mordenkainen\'s'
         ' Sword, or a wall'
         ' of force'
         ' disintegrates the'
         ' manifestation and'
         ' absorbs one'
         ' charge.'),
        ('uawdForceTouchKinds', 3, ''),
        ('uawdForceTouchAbsorbsCharge', True,
         ''),
    ]),
    ('the wand of size alteration', [
        ('uawdSizeChangePct', 50,
         'Any single creature'
         ' enlarges or'
         ' diminishes by'
         ' half; strength and'
         ' power scale'
         ' proportionally for'
         ' humanoids - 9 feet'
         ' matches a hill'
         ' giant\'s Strength'
         ' 19, 13 feet a fire'
         ' giant\'s 22.'),
        ('uawdSizeHillGiantFeet', 9, ''),
        ('uawdSizeHillGiantStr', 19, ''),
        ('uawdSizeFireGiantFeet', 13, ''),
        ('uawdSizeFireGiantStr', 22, ''),
        ('uawdSizeRangeIn', 1,
         'Range 1"; the target'
         ' and all it wears'
         ' or carries are'
         ' affected unless'
         ' the save'
         ' succeeds - a'
         ' willing target'
         ' forgoes the save.'),
        ('uawdSizeGearAffected', True, ''),
        ('uawdSizeWillingForgoesSave', True,
         ''),
        ('uawdSizeDispelNeedsShock', True,
         'A dispel magic'
         ' removal demands a'
         ' system shock roll;'
         ' the possessor may'
         ' cancel the effect'
         ' at will before it'
         ' expires.'),
        ('uawdSizePossessorMayCancel', True,
         ''),
        ('uawdSizeChargesPerUse', 1,
         'Each usage expends 1'
         ' charge; the'
         ' cancellation is'
         ' free; recharge by'
         ' a magic-user of'
         ' 12th or higher.'),
        ('uawdSizeCancellationFree', True,
         ''),
        ('uawdSizeRechargeMuLevel', 12,
         ''),
    ]),
    ('the wand of steam and vapor', [
        ('uawdSteamCharges', 1,
         'Two functions, 1'
         ' charge each.'),
        ('uawdSteamActivateSegs', 1,
         'STEAM: in one'
         ' segment a jet of'
         ' superheated steam,'
         ' a cone of 1" by 3"'
         ' by 5"; 6-36 (6d6)'
         ' the first round,'
         ' 4d6 the second,'
         ' 2d6 the third and'
         ' last; saves apply'
         ' for half.'),
        ('uawdSteamConeLoIn', 1, ''),
        ('uawdSteamConeMidIn', 3, ''),
        ('uawdSteamConeHiIn', 5, ''),
        ('uawdSteamRound1Dice', 6, ''),
        ('uawdSteamRound2Dice', 4, ''),
        ('uawdSteamRound3Dice', 2, ''),
        ('uawdSteamSaveForHalf', True, ''),
        ('uawdSteamFireCreaturesImmune',
         True,
         'Fire-dwelling or'
         ' fire-using'
         ' creatures are'
         ' unharmed - unless'
         ' dampness harms'
         ' them.'),
        ('uawdSteamDampnessException',
         True, ''),
        ('uawdVaporCharges', 1,
         'VAPOR: in one'
         ' segment billows of'
         ' warm steamy vapor,'
         ' a fog cloud of 4"'
         ' depth, 6" height,'
         ' 8" breadth; it'
         ' persists 6 rounds,'
         ' stationary unless'
         ' winds move it.'),
        ('uawdVaporActivateSegs', 1, ''),
        ('uawdVaporDepthIn', 4, ''),
        ('uawdVaporHeightIn', 6, ''),
        ('uawdVaporBreadthIn', 8, ''),
        ('uawdVaporRounds', 6, ''),
        ('uawdVaporStationaryUnlessWinds',
         True, ''),
        ('uawdVaporColdUserDmg', 1,
         'Cold-using'
         ' creatures inside'
         ' suffer 1 point per'
         ' round;'
         ' cold-dwelling'
         ' creatures take'
         ' twice that.'),
        ('uawdVaporColdDwellerDmg', 2, ''),
    ]),
]


# ===== the emitters =====

def wrap(text, width=34):
    out = []
    cur = ''
    for w in text.split():
        if cur and len(cur) + 1 + len(w) > width:
            out.append(cur)
            cur = w
        else:
            cur = (cur + ' ' + w).strip()
    if cur:
        out.append(cur)
    return out


def hdr_fills(sections):
    parts = []
    for title, entries in sections:
        for ln in wrap('---- ' + title
                       + ' (the R397 clean'
                       ' read) ----'):
            parts.append('// ' + ln)
        for nm, val, prose in entries:
            if prose:
                for ln in wrap(prose):
                    parts.append('// ' + ln)
            ty = ('bool' if val is True
                  or val is False else 'int')
            rv = ('true' if val is True
                  else 'false' if val is False
                  else str(val))
            parts.append('inline %s %s()' % (ty, nm))
            parts.append('    { return %s; }' % rv)
            parts.append('')
    return NL.join(parts).rstrip(NL)


def audit_lines(sections):
    out = []
    for title, entries in sections:
        for ln in wrap('---- the '
                       + title.split(' the ')[-1]
                       + ' ----'):
            out.append('        // ' + ln)
        for nm, val, prose in entries:
            if val is True:
                cond = '!' + nm + '()'
            elif val is False:
                cond = nm + '()'
            else:
                cond = '%s() != %d' % (nm, val)
            stmt = 'if (%s) ++bad;' % cond
            if 12 + len(stmt) <= 78:
                out.append('            ' + stmt)
            else:
                out.append('            if (%s)' % cond)
                out.append('                ++bad;')
    return out


def flat(sections):
    r = []
    for _, entries in sections:
        r.extend(entries)
    return r


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = B(
    '- R396 landed 2026-10-13:',
    '  commit daaad4a (census 323,',
    '  preflight GREEN), the UA',
    '  new-potions prose',
    '  completion: the clean pp.',
    '  90-91 read fills the',
    '  seven PDF-gated',
    '  descriptions (the oils of',
    '  acid resistance,',
    '  disenchantment, elemental',
    '  invulnerability, impact,',
    '  and the philters of',
    '  beauty, glibness,',
    '  stammering) - rules/',
    '  uapotprose.h takes the',
    '  fill sections, the part',
    '  ledger flips 12/7 ->',
    '  19/0, the R376 item',
    '  flips AMENDED R396: closed',
    '  - every UA potions-band',
    '  description pins. The',
    '  ./nn save hash diverged',
    '  for the fourth round',
    '  running yet the copy',
    '  passed the battery -',
    '  stable and benign; the',
    '  md5 stays advisory.').rstrip(NL)
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R396 landed 2026-10-13' in s:
    already.append('seed: the R396 record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R396 record')
s = rd(SD)
if s.count('R396 landed 2026-10-13') != 1:
    die('the R396 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ============ (b) the four headers ============
SCR = 'rules/uaprotscr.h'
RIN = 'rules/uaringprose.h'
ROD = 'rules/uarodstave.h'
WAN = 'rules/uawandprose.h'
LED = '// ---- the extract ledger ----'

pair(SCR, B(
    '// four garbled types (cold,',
    '// electricity, the two weapons',
    '// scrolls) await the PDF - the',
    '// gap item stays open. The').rstrip(NL),
    B(
    '// four PDF-gated types (cold,',
    '// electricity, the two weapons',
    '// scrolls) the R397 clean read',
    '// filled - the gap item',
    '// closed. The').rstrip(NL),
    'uaprotscr: the header note')

pair(SCR, LED, hdr_fills(SCROLLS) + NL + LED,
     'uaprotscr: the four fill sections')

pair(SCR, B(
    '// Eleven of the fifteen types',
    '// pin clean; the four garbled',
    '// types (cold, electricity,',
    '// the two weapons scrolls)',
    '// stay PDF-gated.',
    'inline int uapsCleanCount()',
    '    { return 11; }',
    '',
    'inline int uapsGarbledCount()',
    '    { return 4; }').rstrip(NL),
    B(
    '// All fifteen types pin -',
    '// the R397 clean read filled',
    '// the four the extract',
    '// garbled.',
    'inline int uapsCleanCount()',
    '    { return 15; }',
    '',
    'inline int uapsGarbledCount()',
    '    { return 0; }').rstrip(NL),
    'uaprotscr: the extract ledger')

pair(RIN, B(
    "// ram's adjustment tail,",
    "// shocking grasp's opening,",
    "// sustenance's reattune) await",
    '// the PDF - the gap item',
    '// stays open. The scrolls and').rstrip(NL),
    B(
    "// ram's adjustment tail,",
    "// shocking grasp's opening,",
    "// sustenance's reattune) the",
    '// R397 clean read filled -',
    '// the gap item closed. The',
    '// scrolls and').rstrip(NL),
    'uaringprose: the header note')

pair(RIN, LED, hdr_fills(RINGS) + NL + LED,
     'uaringprose: the seven fill sections')

pair(RIN, B(
    '// Six of the thirteen',
    '// descriptions pin; the',
    '// seven garbled ones stay',
    '// PDF-gated.',
    'inline int uarpCleanCount()',
    '    { return 6; }',
    '',
    'inline int uarpGarbledCount()',
    '    { return 7; }').rstrip(NL),
    B(
    '// All thirteen descriptions',
    '// pin - the R397 clean read',
    '// filled the seven the',
    '// extract garbled.',
    'inline int uarpCleanCount()',
    '    { return 13; }',
    '',
    'inline int uarpGarbledCount()',
    '    { return 0; }').rstrip(NL),
    'uaringprose: the extract ledger')

pair(ROD, B(
    '// (flailing, passage,',
    '// splendor, staff-spear,',
    '// swarming insects, thunder',
    '// and lightning, woodlands)',
    '// await the PDF - the gap',
    '// item stays open. The rings').rstrip(NL),
    B(
    '// (flailing, passage,',
    '// splendor, staff-spear,',
    '// swarming insects, thunder',
    '// and lightning, woodlands)',
    '// the R397 clean read filled',
    '// - the gap item closed. The',
    '// rings').rstrip(NL),
    'uarodstave: the header note')

pair(ROD, LED, hdr_fills(RODS) + NL + LED,
     'uarodstave: the seven fill sections')

pair(ROD, B(
    '// Four of the eleven',
    '// descriptions pin; the',
    '// seven garbled ones stay',
    '// PDF-gated.',
    'inline int uaroCleanCount()',
    '    { return 4; }',
    '',
    'inline int uaroGarbledCount()',
    '    { return 7; }').rstrip(NL),
    B(
    '// All eleven descriptions',
    '// pin - the R397 clean read',
    '// filled the seven the',
    '// extract garbled.',
    'inline int uaroCleanCount()',
    '    { return 11; }',
    '',
    'inline int uaroGarbledCount()',
    '    { return 0; }').rstrip(NL),
    'uarodstave: the extract ledger')

pair(WAN, B(
    '// plus two mechanics-clean',
    "// with flagged holes",
    "// (defoliation's opening",
    "// sentence, metal command's",
    '// dropped verb). The five',
    '// garbled types (buckler,',
    '// earth and stone, force,',
    '// size alteration, steam and',
    '// vapor) await the PDF - the',
    '// gap item stays open. The').rstrip(NL),
    B(
    '// plus two whose holes',
    "// (defoliation's opening",
    "// sentence, metal command's",
    '// dropped verb) and five',
    '// garbled types (buckler,',
    '// earth and stone, force,',
    '// size alteration, steam and',
    '// vapor) the R397 clean read',
    '// filled - the gap item',
    '// closed. The').rstrip(NL),
    'uawandprose: the header note')

pair(WAN, B(
    '// The opening construction',
    '// sentence interleaves in the',
    '// extract - the hole flagged;',
    '// all charge mechanics read',
    '// clean. Never wood - ivory',
    '// or bone.',
    'inline bool uawdDefOpeningHoleFlagged()',
    '    { return true; }').rstrip(NL),
    B(
    '// The opening construction',
    '// sentence reads clean in',
    '// the R397 PDF pass: the',
    '// wand is never constructed',
    '// of wood - ivory or bone',
    '// is the major component.',
    'inline bool uawdDefNeverWood()',
    '    { return true; }',
    '',
    'inline bool uawdDefIvoryOrBone()',
    '    { return true; }',
    '',
    'inline bool uawdDefOpeningHoleFlagged()',
    '    { return false; }').rstrip(NL),
    'uawandprose: the defoliation hole')

pair(WAN, B(
    '// The transmutation sentence',
    '// drops its verb in the',
    '// extract - the hole flagged;',
    '// all three charge functions',
    '// read clean. Appears as a',
    '// wand of metal and mineral',
    '// detection; operational only',
    '// in the hands of a dwarf or',
    '// gnome.',
    'inline bool uawdMcVerbHoleFlagged()',
    '    { return true; }').rstrip(NL),
    B(
    '// The transmutation sentence',
    '// reads clean in the R397',
    '// PDF pass: in the hands of',
    '// a dwarf or gnome its',
    '// exceptional powers become',
    '// operational. Appears as a',
    '// wand of metal and mineral',
    '// detection.',
    'inline bool'
    ' uawdMcPowersOperational()',
    '    { return true; }',
    '',
    'inline bool uawdMcVerbHoleFlagged()',
    '    { return false; }').rstrip(NL),
    'uawandprose: the metal-command hole')

pair(WAN, LED, hdr_fills(WANDS) + NL + LED,
     'uawandprose: the five fill sections')

pair(WAN, B(
    '// Five fully clean, two',
    '// mechanics-clean with',
    '// flagged holes, five',
    '// garbled - twelve types.',
    'inline int uawdCleanCount()',
    '    { return 5; }',
    '',
    'inline int uawdFlaggedCount()',
    '    { return 2; }',
    '',
    'inline int uawdGarbledCount()',
    '    { return 5; }').rstrip(NL),
    B(
    '// All twelve types pin - the',
    '// R397 clean read filled the',
    '// two flagged holes and the',
    '// five the extract garbled.',
    'inline int uawdCleanCount()',
    '    { return 12; }',
    '',
    'inline int uawdFlaggedCount()',
    '    { return 0; }',
    '',
    'inline int uawdGarbledCount()',
    '    { return 0; }').rstrip(NL),
    'uawandprose: the extract ledger')

# ============ (c) the gap report ============
GP = 'tools/ua_gap_report.md'

pair(GP, B(
    '        garbled remainder.',
    '- [ ] **The new rings**'
 ' (pp. 92-94).').rstrip(NL),
    B(
    '        garbled remainder.',
    '      - AMENDED R397: closed -',
    '        the clean PDF read (the',
    '        same clean OCR as',
    '        R394-R396) fills all',
    '        four: cold (the 3"',
    '        sphere, absolute-zero',
    '        normal cold, the',
    '        resist-cold +6 save',
    '        with quarter/eighth',
    '        damage), electricity',
    '        (the 2" sphere,',
    '        immunity, 3-12',
    '        rounds), weapons',
    '        magical (reader only,',
    '        the spell-missile',
    '        exemption) and',
    '        non-magic (the 1"',
    '        sphere, the',
    '        large-missile',
    '        exemption) - all',
    '        fifteen types pin',
    '        (rules/uaprotscr.h).',
    '- [ ] **The new rings**'
 ' (pp. 92-94).').rstrip(NL),
    'gap: the new-scrolls item')

pair(GP, B(
    '        for the garbled',
    '        remainder.',
    '- [ ] **The new rods and staves**'
 ' (pp.').rstrip(NL),
    B(
    '        for the garbled',
    '        remainder.',
    '      - AMENDED R397: closed -',
    '        the clean PDF read fills',
    '        all seven: boccob (the',
    '        1-6 item-save list,',
    '        7-20 auto-save, the',
    '        1-4 hour quiescence),',
    '        chameleon power (90%,',
    '        the 5% cumulative',
    '        detection, int 16+',
    '        bonus), clumsiness (the',
    '        seven-band d% table,',
    '        halved dexterity, the',
    '        dispel-vs-12th',
    '        removal), faerie (the',
    '        5/75/20 alignment, the',
    '        01-67 silence, the',
    '        door dice), ram (the',
    '        1-6/2-12/3-18 charge',
    '        ladder, the nine-entry',
    '        adjustment list, the',
    '        18/00-19-20 door',
    '        strengths, 6-60',
    '        charges), shocking',
    '        grasp (7-14, d8+6, three',
    '        discharges), sustenance',
    '        (the two-hours-for-',
    '        eight sleep, the',
    '        reattune week) - all',
    '        thirteen descriptions',
    '        pin (rules/uaringprose.h).',
    '- [ ] **The new rods and staves**'
 ' (pp.').rstrip(NL),
    'gap: the new-rings item')

pair(GP, B(
    '        garbled remainder.',
    '- [ ] **The new wands**'
 ' (pp. 96-97).').rstrip(NL),
    B(
    '        garbled remainder.',
    '      - AMENDED R397: closed -',
    '        the clean PDF read fills',
    '        all seven: flailing (the',
    '        horseman/footman damage,',
    '        +3, both heads, the +4',
    '        protection charge),',
    '        passage (the five',
    '        functions, the astral',
    '        five, the MU-20th',
    '        recharge), splendor (the',
    '        continual 18 charisma,',
    '        the 7,000-10,000 gp',
    '        garb, the 1,500-3,000',
    '        square foot tent, not',
    '        rechargeable), the',
    '        staff-spear (the three',
    '        commands, the six-row',
    '        bonus/x.p./g.p. table),',
    '        swarming insects (60',
    '        plus ten per level, ten',
    '        insects per point, the',
    '        natural-AC-5 cutoff,',
    '        never recharged),',
    '        thunder and lightning',
    '        (the +2/+3 base, the',
    '        16-48 stroke, the',
    '        segments-equal-charges',
    '        rule), woodlands (the',
    '        three charge powers,',
    '        the +1-to-+4 ladder,',
    '        the d4 even chances) -',
    '        all eleven descriptions',
    '        pin (rules/uarodstave.h).',
    '- [ ] **The new wands**'
 ' (pp. 96-97).').rstrip(NL),
    'gap: the new-rods item')

pair(GP, B(
    '        for the garbled',
    '        remainder.',
    '- [ ] **The new miscellaneous magic').rstrip(NL),
    B(
    '        for the garbled',
    '        remainder.',
    '      - AMENDED R397: closed -',
    '        the clean PDF read fills',
    '        the two flagged holes',
    "        (defoliation's never-",
    '        wood opening, metal',
    "        command's dropped",
    '        operational verb) and',
    '        all five garbled types:',
    '        buckler (the one-and-a-',
    '        half foot wand, the',
    '        cleric block, the',
    '        dagger/buckler/spiked',
    '        forms), earth and stone',
    '        (the half/1/2 charge',
    '        mapping, the 50% mud-',
    '        transmuters), force (the',
    '        4-foot +5 bastard-sword',
    '        shaft, the wall of',
    '        force, the hand at',
    '        half charge), size',
    '        alteration (the 50%',
    '        change, the hill/fire',
    '        giant strengths, the',
    '        system-shock removal),',
    '        steam and vapor (the',
    '        1-3-5 cone, the 6/4/2',
    '        dice decay, the 4-6-8',
    '        fog cloud) - all twelve',
    '        types pin',
    '        (rules/uawandprose.h).',
    '- [ ] **The new miscellaneous magic').rstrip(NL),
    'gap: the new-wands item')

# ============ (d) regtest.cpp ============
RT = 'regtest.cpp'

pair(RT, B(
    '    // The four garbled types',
    '    // (cold, electricity, the',
    '    // two weapons scrolls) stay',
    '    // PDF-gated. The R376 seam').rstrip(NL),
    B(
    '    // The four garbled types',
    '    // (cold, electricity, the',
    '    // two weapons scrolls)',
    '    // filled by the R397 clean',
    '    // read. The R376 seam').rstrip(NL),
    'regtest R377: the block comment')

flipall(RT,
    'if (uapsCleanCount() != 11) ++bad;',
    'if (uapsCleanCount() != 15) ++bad;',
    2, 'regtest: the scrolls clean ledger')

flipall(RT,
    'if (uapsGarbledCount() != 4) ++bad;',
    'if (uapsGarbledCount() != 0) ++bad;',
    2, 'regtest: the scrolls garbled ledger')

pair(RT, B(
    '    // truth. The seven garbled',
    '    // descriptions stay',
    '    // PDF-gated. The R377 seam').rstrip(NL),
    B(
    '    // truth. The seven garbled',
    '    // descriptions filled by',
    '    // the R397 clean read. The',
    '    // R377 seam').rstrip(NL),
    'regtest R378: the block comment')

flipall(RT,
    'if (uarpCleanCount() != 6) ++bad;',
    'if (uarpCleanCount() != 13) ++bad;',
    2, 'regtest: the rings clean ledger')

flipall(RT,
    'if (uarpGarbledCount() != 7) ++bad;',
    'if (uarpGarbledCount() != 0) ++bad;',
    2, 'regtest: the rings garbled ledger')

pair(RT, B(
    '    // slinging. The seven',
    '    // garbled descriptions stay',
    '    // PDF-gated. The R378 seam').rstrip(NL),
    B(
    '    // slinging. The seven',
    '    // garbled descriptions',
    '    // filled by the R397 clean',
    '    // read. The R378 seam').rstrip(NL),
    'regtest R379: the block comment')

flipall(RT,
    'if (uaroCleanCount() != 4) ++bad;',
    'if (uaroCleanCount() != 11) ++bad;',
    2, 'regtest: the rods clean ledger')

flipall(RT,
    'if (uaroGarbledCount() != 7) ++bad;',
    'if (uaroGarbledCount() != 0) ++bad;',
    2, 'regtest: the rods garbled ledger')

pair(RT, B(
    '    // command). The five',
    '    // garbled types stay',
    '    // PDF-gated. The R379 seam').rstrip(NL),
    B(
    '    // command), their holes',
    '    // and the five garbled',
    '    // types filled by the',
    '    // R397 clean read. The',
    '    // R379 seam').rstrip(NL),
    'regtest R380: the block comment')

flipall(RT,
    'if (uawdCleanCount() != 5) ++bad;',
    'if (uawdCleanCount() != 12) ++bad;',
    2, 'regtest: the wands clean ledger')

flipall(RT,
    'if (uawdFlaggedCount() != 2) ++bad;',
    'if (uawdFlaggedCount() != 0) ++bad;',
    2, 'regtest: the wands flagged ledger')

flipall(RT,
    'if (uawdGarbledCount() != 5) ++bad;',
    'if (uawdGarbledCount() != 0) ++bad;',
    2, 'regtest: the wands garbled ledger')

pair(RT, B(
    '            if (!uawdDefOpeningHoleFlagged())',
    '                ++bad;').rstrip(NL),
    B(
    '            if (uawdDefOpeningHoleFlagged())',
    '                ++bad;').rstrip(NL),
    'regtest: the defoliation hole assert')

pair(RT, B(
    '            if (!uawdMcVerbHoleFlagged())'
    ' ++bad;').rstrip(NL),
    B(
    '            if (uawdMcVerbHoleFlagged())'
    ' ++bad;').rstrip(NL),
    'regtest: the metal-command hole assert')

# the new R397 audit block

AUD = ['    // ---- R397: the UA'
       ' treasure smalls pin',
       '    // audit ----',
       '    // The clean read fills the',
       '    // four scrolls, the seven',
       '    // rings, the seven rods and',
       '    // staves, the two wand holes',
       '    // and the five garbled',
       '    // wands (pp. 91-98) - all',
       '    // four items close.',
       '    {',
       '        using namespace rules;',
       '        int bad = 0;']
AUD.extend(audit_lines(SCROLLS))
AUD.extend(audit_lines(RINGS))
AUD.extend(audit_lines(RODS))
AUD.extend(audit_lines(WANDS))
AUD.extend([
    '        // ---- the cross-checks',
    '        // ----',
    '            // the boccob list runs',
    '            // contiguously 1-20',
    '            if (uarpBoccobSaveAutoFailRoll()',
    '                    + 1',
    '                    != uarpBoccobSaveRelic'
    'Roll())',
    '                ++bad;',
    '            if (uarpBoccobSaveAnySavesLo()',
    '                    - uarpBoccobSaveOther'
    'Roll()',
    '                    != 1) ++bad;',
    '            // the clumsiness bands',
    '            // tile 1-100 without',
    '            // gaps or overlap',
    '            if (uarpClumFreeActionHi()',
    '                    + 1',
    '                    != uarpClumFeatherFall'
    'Lo())',
    '                ++bad;',
    '            if (uarpClumFeatherFallHi()',
    '                    + 1',
    '                    != uarpClumInvisibility'
    'Lo())',
    '                ++bad;',
    '            if (uarpClumInvisibilityHi()',
    '                    + 1',
    '                    != uarpClumJumpingLo())',
    '                ++bad;',
    '            if (uarpClumJumpingHi()',
    '                    + 1',
    '                    != uarpClumSwimmingLo())',
    '                ++bad;',
    '            if (uarpClumSwimmingHi()',
    '                    + 1',
    '                    != uarpClumWarmthLo())',
    '                ++bad;',
    '            if (uarpClumWarmthHi()',
    '                    + 1',
    '                    != uarpClumWaterWalkLo())',
    '                ++bad;',
    '            // the faerie alignments',
    '            // sum to a full d%',
    '            if (uarpFaerieEvilPct()',
    '                    + uarpFaerieGoodPct()',
    '                    + uarpFaerieNeutralPct()',
    '                    != 100) ++bad;',
    '            // the ram damage is n',
    '            // charges of d6',
    '            if (uarpRamDmgHiTwoCharges()',
    '                    != 2 * uarpRamDmgHi'
    'OneCharge())',
    '                ++bad;',
    '            if (uarpRamDmgHiThreeCharges()',
    '                    != 3 * uarpRamDmgHi'
    'OneCharge())',
    '                ++bad;',
    '            // the shocking grasp',
    '            // band is d8 + 6, so the',
    '            // low end is one die',
    '            // plus the bonus',
    '            if (uarpShockDmgHi()',
    '                    - uarpShockDmgLo() + 1',
    '                    != uarpShockDmgDieSides())',
    '                ++bad;',
    '            if (uarpShockDmgLo()',
    '                    - uarpShockDmgPlus() != 1)',
    '                ++bad;',
    '            // the staff-spear g.p.',
    '            // column is five times',
    '            // the x.p. column',
    '            if (uaroSsGpLo()',
    '                    != 5 * uaroSsXpLo())',
    '                ++bad;',
    '            if (uaroSsXpHi()',
    '                    - uaroSsXpLo() != 2500)',
    '                ++bad;',
    '            // the swarm damage is',
    '            // the insect count',
    '            // divided by ten',
    '            if (uaroSwarmBaseInsects()',
    '                    / uaroSwarmInsectsPerDmg()',
    '                    != 6) ++bad;',
    '            // the thunder stroke',
    '            // runs 16-48 on 8d6',
    '            // with 1s counted as 2',
    '            if (uaroStrokeDmgHi()',
    '                    != 2 * uaroStrokeDice()'
    '                    * 3) ++bad;',
    '            if (uaroStrokeDmgLo()',
    '                    != 2 * uaroStrokeDice())',
    '                ++bad;',
    '            // the activation runs',
    '            // in segments equal to',
    '            // the charges, so the',
    '            // 4-charge combined',
    '            // power takes 4',
    '            // segments',
    '            if (uaroCombinedCharges() != 4)',
    '                ++bad;',
    '            // the woodlands ladder',
    '            // counts its extras up',
    '            // as the bonus walks',
    '            // down',
    '            if (uaroWoodPlus3Extras()',
    '                    + 1',
    '                    != uaroWoodPlus2Extras())',
    '                ++bad;',
    '            if (uaroWoodPlus2Extras()',
    '                    + 1',
    '                    != uaroWoodPlus1Extras())',
    '                ++bad;',
    '            if (uaroWoodTopBonus()',
    '                    - uaroWoodPlus1Extras()',
    '                    != 1) ++bad;',
    '            // the steam cone is',
    '            // 1-3-5 inches and the',
    '            // dice halve twice',
    '            if (uawdSteamConeMidIn()',
    '                    - uawdSteamConeLoIn()',
    '                    != uawdSteamConeHiIn()',
    '                    - uawdSteamConeMidIn())',
    '                ++bad;',
    '            if (uawdSteamRound2Dice()',
    '                    >= uawdSteamRound1Dice())',
    '                ++bad;',
    '            if (uawdSteamRound3Dice()',
    '                    != uawdSteamRound2Dice()',
    '                    / 2) ++bad;',
    '            // the vapor cloud is',
    '            // 4-6-8 inches deep,',
    '            // high, broad',
    '            if (uawdVaporHeightIn()',
    '                    - uawdVaporDepthIn()',
    '                    != uawdVaporBreadthIn()',
    '                    - uawdVaporHeightIn())',
    '                ++bad;',
    '            // the cold scroll',
    '            // quarters and then',
    '            // halves',
    '            if (uapsColdMagicalSaveBonus()',
    '                    != 6) ++bad;',
    '            // the size alteration',
    '            // strengths rise with',
    '            // the heights',
    '            if (uawdSizeHillGiantStr()',
    '                    >= uawdSizeFireGiant'
    'Str())',
    '                ++bad;',
    '            if (uawdSizeHillGiantFeet()',
    '                    >= uawdSizeFireGiant'
    'Feet())',
    '                ++bad;',
    '        // ---- the ledger seam ----',
    '            // the four ledgers and',
    '            // their seams carry',
    '            // the flipped counts',
    '            if (uapsCleanCount() != 15)',
    '                ++bad;',
    '            if (uapsGarbledCount() != 0)',
    '                ++bad;',
    '            if (uarpCleanCount() != 13)',
    '                ++bad;',
    '            if (uarpGarbledCount() != 0)',
    '                ++bad;',
    '            if (uaroCleanCount() != 11)',
    '                ++bad;',
    '            if (uaroGarbledCount() != 0)',
    '                ++bad;',
    '            if (uawdCleanCount() != 12)',
    '                ++bad;',
    '            if (uawdFlaggedCount() != 0)',
    '                ++bad;',
    '            if (uawdGarbledCount() != 0)',
    '                ++bad;',
    '        printf("R397 UA treasure'
    ' smalls pin audit: bad %d'
    + NN + '", bad);',
    '        if (bad) return 1;',
    '    }'])

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, NL.join(AUD) + NL + R227,
     'regtest: the R397 audit block')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 324:
    die('the census %d' % s.count('audit: bad'))
if s.count('R397 UA treasure smalls'
           ' pin audit') != 1:
    die('the R397 audit label')

for old in ('if (uapsCleanCount() != 15)'
            ' ++bad;',
            'if (uapsGarbledCount() != 0)'
            ' ++bad;',
            'if (uarpCleanCount() != 13)'
            ' ++bad;',
            'if (uarpGarbledCount() != 0)'
            ' ++bad;',
            'if (uaroCleanCount() != 11)'
            ' ++bad;',
            'if (uaroGarbledCount() != 0)'
            ' ++bad;',
            'if (uawdCleanCount() != 12)'
            ' ++bad;',
            'if (uawdFlaggedCount() != 0)'
            ' ++bad;',
            'if (uawdGarbledCount() != 0)'
            ' ++bad;'):
    if s.count(old) != 2:
        die('the flipped ledger %r'
            ' count %d' % (old, s.count(old)))
if s.count('if (uawdDefOpeningHoleFlagged())') != 1:
    die('the defoliation hole assert')
if s.count('if (uawdMcVerbHoleFlagged())') != 1:
    die('the metal-command hole assert')

BASE_INLINE = {SCR: 65, RIN: 50, ROD: 58, WAN: 75}
BASE_FALSE = {SCR: 0, RIN: 1, ROD: 0, WAN: 1}
WAND_EXTRA = 3  # def/mc hole pins


def nfalse(sections):
    return sum(1 for _, v, _ in flat(sections)
               if v is False)


for path, sections in ((SCR, SCROLLS), (RIN, RINGS),
                       (ROD, RODS), (WAN, WANDS)):
    p = rd(path)
    want = (BASE_INLINE[path]
            + len(flat(sections))
            + (WAND_EXTRA if path == WAN else 0))
    if p.count('inline') != want:
        die('%s inline count %d, expected %d'
            % (path, p.count('inline'), want))
    wantf = (BASE_FALSE[path] + nfalse(sections)
             + (2 if path == WAN else 0))
    if p.count('return false;') != wantf:
        die('%s false count %d, expected %d'
            % (path, p.count('return false;'),
               wantf))
    if not p.endswith(NL):
        die('%s trailing newline' % path)

g = rd(GP)
if g.count('AMENDED R397') != 4:
    die('the gap amended count %d'
        % g.count('AMENDED R397'))

print('R397 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the clean PDF read fills the'
      ' four PDF-gated')
print('  treasure items - the scrolls,'
      ' the rings, the rods')
print('  and staves, the wands; every'
      ' garbled description')
print('  pins and the two wand holes close;'
      ' census 323 -> 324')
print('commit: R397: the UA scrolls rings'
      ' rods staves wands prose'
      ' completion (census 324)')

