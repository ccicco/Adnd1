// =========================================================================================
// Adnd1 - rules/oa87goblinrat.h
// OA MONSTERS - THE GOBLIN RAT, printed capture p. 266 - the shapechanger
// round
// census 638 -> 639.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 169 closed, 66 open - the goblin rat box
// flips (census 638 -> 639); NEXT - R717: the Goblin Spider (capture p. 267),
// prefix dke (verify free at the landing), audit "R717 OA monsters Goblin
// Spider audit", include after rules/oa87goblinrat.h
//
namespace rules {

// ---- the stat block ----

// the appearing minimum - the 1 of the 1-20 appearing (print capture p. 266)
inline int dkdAppearMin()
    { return 1; }

// the appearing maximum - the 20 of the 1-20 appearing (print capture p. 266)
inline int dkdAppearMax()
    { return 20; }

// the goblin rat armor class - the AC 7 of the stat block (print capture p.
// 266)
inline int dkdAC()
    { return 7; }

// the goblin rat move - the 9 of the move 9 (print capture p. 266)
inline int dkdMove()
    { return 9; }

// the goblin rat hit dice - the 3 of the stat block (print capture p. 266)
inline int dkdHD()
    { return 3; }

// the in-lair percentage - the 20% of the stat block (print capture p. 266)
inline int dkdLairPct()
    { return 20; }

// the frequency - the rare of the stat block (print capture p. 266)
inline int dkdFrequencyRare()
    { return 1; }

// the treasure type - the B of the stat block (print capture p. 266)
inline int dkdTreasureTypeB()
    { return 1; }

// the attack count - the 1 of the number of attacks (print capture p. 266)
inline int dkdAttackCount()
    { return 1; }

// the bite damage minimum - the 1 of the 1-8 or by weapon type (print capture
// p. 266)
inline int dkdBiteDmgMin()
    { return 1; }

// the bite damage maximum - the 8 of the 1-8 or by weapon type (print capture
// p. 266)
inline int dkdBiteDmgMax()
    { return 8; }

// the damage clause - the 1-8 or by weapon type of the stat block (print
// capture p. 266)
inline int dkdDamageByWeaponType()
    { return 1; }

// the special attacks - the nil of the stat block (print capture p. 266)
inline int dkdSpecialAttacksNil()
    { return 1; }

// the special defense - the shapechange of the stat block (print capture p.
// 266)
inline int dkdSpecialDefenseShapechange()
    { return 1; }

// the magic resistance - the 10% of the stat block (print capture p. 266)
inline int dkdMagicResistPct()
    { return 10; }

// the intelligence - the low to standard of the stat block (print capture p.
// 266)
inline int dkdIntelligenceLowToStandard()
    { return 1; }

// the alignment - the lawful evil of the stat block (print capture p. 266)
inline int dkdAlignmentLawfulEvil()
    { return 1; }

// the size class - the S of the S 3-4 (print capture p. 266)
inline int dkdSizeSmall()
    { return 1; }

// the size minimum - the 3 of the S 3-4 (print capture p. 266)
inline int dkdSizeMinFeet()
    { return 3; }

// the size maximum - the 4 of the S 3-4 (print capture p. 266)
inline int dkdSizeMaxFeet()
    { return 4; }

// the psionic ability - the nil of the stat block (print capture p. 266)
inline int dkdPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of the stat block (print capture p.
// 266)
inline int dkdPsionicModesNil()
    { return 1; }

// the level value - the VI of the VI/1,000 + 10/hp (print capture p. 266)
inline int dkdLevelVI()
    { return 1; }

// the xp base - the 1,000 of the VI/1,000 + 10 per hp (print capture p. 266)
inline int dkdXPBase()
    { return 1000; }

// the xp per hit point - the 10 of the VI/1,000 + 10/hp (print capture p.
// 266)
inline int dkdXPPerHP()
    { return 10; }

// ---- the shapechanger ----

// the nature - an intelligent shapechanging animal, similar to a hengeyokai
// (print capture p. 266)
inline int dkdHengeyokaiKin()
    { return 1; }

// the form count - the two forms of the shapechange, the giant rat and the
// ratman (print capture p. 266)
inline int dkdFormsCount()
    { return 2; }

// the first form - a particularly foul and ugly giant rat (print capture p.
// 266)
inline int dkdGiantRatForm()
    { return 1; }

// the second form - the ratman of the shapechange (print capture p. 266)
inline int dkdRatmanForm()
    { return 1; }

// the either-form clause - the full hit points and abilities in either form
// (print capture p. 266)
inline int dkdFullHpEitherForm()
    { return 1; }

// ---- the bite and the ratman arms ----

// the animal form attack - while in animal form, the creature attacks with
// its bite (print capture p. 266)
inline int dkdAnimalFormBite()
    { return 1; }

// the bite disease chance - the 5% per successful hit of the animal form
// (print capture p. 266)
inline int dkdDiseasePct()
    { return 5; }

// the bite disease - each successful hit carries the chance of transmitting a
// disease to the victim (print capture p. 266)
inline int dkdBiteTransmitsDisease()
    { return 1; }

// the common disease count - the cholera, plague, and fevers (print capture
// p. 266)
inline int dkdCommonDiseaseCount()
    { return 3; }

// the disease roster - the cholera, plague, and fevers as the most common
// (print capture p. 266)
inline int dkdDiseasesCholeraPlagueFever()
    { return 1; }

// the ratman arms - in its ratman form the goblin rat fights with weapons
// (print capture p. 266)
inline int dkdRatmanFightsWithWeapons()
    { return 1; }

// the ratman armor - in its ratman form the goblin rat can wear armor (print
// capture p. 266)
inline int dkdRatmanWearsArmor()
    { return 1; }

// the preferred weapon count - the spears, naginatas, and two-handed swords
// (print capture p. 266)
inline int dkdPreferredWeaponCount()
    { return 3; }

// the first preferred weapon - the spear (print capture p. 266)
inline int dkdPrefersSpears()
    { return 1; }

// the second preferred weapon - the naginata (print capture p. 266)
inline int dkdPrefersNaginatas()
    { return 1; }

// the third preferred weapon - the two-handed sword (print capture p. 266)
inline int dkdPrefersTwoHandedSwords()
    { return 1; }

// ---- the king of the group ----

// the king threshold - the group of 10 or more that has a king (print capture
// p. 266)
inline int dkdKingGroupThreshold()
    { return 10; }

// the kings per group - the one king of the 10-plus group (print capture p.
// 266)
inline int dkdKingCountPerGroup()
    { return 1; }

// the king hit dice - the 5 HD of the group king (print capture p. 266)
inline int dkdKingHD()
    { return 5; }

// the king armor class - the AC 4 of the group king (print capture p. 266)
inline int dkdKingAC()
    { return 4; }

// the king bite bonus - the +2 points of damage with the bite (print capture
// p. 266)
inline int dkdKingBiteDmgBonus()
    { return 2; }

// the king - when 10 or more are encountered, one of the creatures is the
// king of the group (print capture p. 266)
inline int dkdKingOfTheGroup()
    { return 1; }

// ---- the feline antipathy ----

// the feline fear - the great fear of all types of feline creatures (print
// capture p. 266)
inline int dkdFearsAllFelines()
    { return 1; }

// the feline save - must make a saving throw vs. paralyzation when faced by a
// feline (print capture p. 266)
inline int dkdFelineSaveVsParalyzation()
    { return 1; }

// the failed save - those which fail flee in panic (print capture p. 266)
inline int dkdFailedSaveFleesInPanic()
    { return 1; }

// the made save - a successful saving throw leaves the goblin rat unaffected
// (print capture p. 266)
inline int dkdSuccessfulSaveUnaffected()
    { return 1; }

// the feline to-hit edge - the +1 on all hit rolls for cat-like creatures
// (print capture p. 266)
inline int dkdCatLikeToHitBonus()
    { return 1; }

// the cat edge source - the antipathy between the two and the superstitious
// fear of the goblin rats (print capture p. 266)
inline int dkdAntipathyAndSuperstition()
    { return 1; }

// the painted ward - even life-like paintings of cats protect a household
// from goblin rats (print capture p. 266)
inline int dkdCatPaintingsWardHousehold()
    { return 1; }

// the ward standard - a life-like painting equals a painting of quality if
// painted for this express purpose (print capture p. 266)
inline int dkdWardPaintingOfQuality()
    { return 1; }

// ---- the lair and the tongue ----

// the habitat - lives on the fringes of human settlements (print capture p.
// 267)
inline int dkdFringeOfSettlements()
    { return 1; }

// the raiding - steals food and livestock (print capture p. 267)
inline int dkdStealsFoodAndLivestock()
    { return 1; }

// the hunting - occasionally preys on lone travelers (print capture p. 267)
inline int dkdPreysOnLoneTravelers()
    { return 1; }

// the lair - typically a deserted temple or an abandoned forest hut, the
// inhabitants slain or driven off (print capture p. 267)
inline int dkdLairDesertedTempleOrHut()
    { return 1; }

// the tongue - does not have a language of its own (print capture p. 267)
inline int dkdNoLanguageOfOwn()
    { return 1; }

// the borrowed tongue - speaks the trade language and the local human
// language (print capture p. 267)
inline int dkdSpeaksTradeAndHuman()
    { return 1; }

}   // namespace rules
