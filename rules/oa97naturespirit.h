// =========================================================================================
// Adnd1 - rules/oa97naturespirit.h
// OA MONSTERS - THE NATURE SPIRITS, printed capture pp. 278-279 - the
// lifeforce round
// census 648 -> 649.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 179 closed, 56 open - the nature spirits
// box flips (census 648 -> 649); NEXT - R727: the Ningyo (capture p. 279),
// prefix dko (verify free at the landing), audit "R727 OA monsters Ningyo
// audit", include after rules/oa97naturespirit.h
//
namespace rules {

// ---- the stat grid ----

// the nature spirit table row count - the lesser and the greater of the stat
// grid (print capture p. 278)
inline int dknNSCount()
    { return 2; }

// the armor class - the 7 of the lesser and the 2 of the greater (print
// capture p. 278)
inline int dknNSAC(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 2;
        default:
            return 0;
        }
    }

// the move - the 12 of both columns (print capture p. 278)
inline int dknNSMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        default:
            return 0;
        }
    }

// the hit dice minimum - the 2 of the 2 to 7 and the 8 of the 8 to 15 (print
// capture p. 278)
inline int dknNSHDMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 8;
        default:
            return 0;
        }
    }

// the hit dice maximum - the 7 and the 15 of the two ladders (print capture
// p. 278)
inline int dknNSHDMax(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 15;
        default:
            return 0;
        }
    }

// the in-lair percent - the 80% of the lesser and the 100% of the greater
// (print capture p. 278)
inline int dknNSLairPct(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 100;
        default:
            return 0;
        }
    }

// the attack count - the 1 of the lesser and the 2 of the greater (print
// capture p. 278)
inline int dknNSAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        default:
            return 0;
        }
    }

// the damage minimum - the 1 of the 1-8 and the 1-10 (print capture p. 278)
inline int dknNSDmgMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        default:
            return 0;
        }
    }

// the damage maximum - the 8 of the 1-8 and the 10 of the 1-10/1-10 (print
// capture p. 278)
inline int dknNSDmgMax(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 10;
        default:
            return 0;
        }
    }

// the magic resistance - the 20% of the lesser and the 70% of the greater
// (print capture p. 278)
inline int dknNSMRPct(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 70;
        default:
            return 0;
        }
    }

// the lesser frequency - the common of the stat grid header (print capture p.
// 278)
inline int dknLesserCommon()
    { return 1; }

// the greater frequency - the rare of the stat grid header (print capture p.
// 278)
inline int dknGreaterRare()
    { return 1; }

// the appearing - the 1 of both columns of the stat grid (print capture p.
// 278)
inline int dknAppear()
    { return 1; }

// the lesser treasure type - the I of the stat grid (print capture p. 278)
inline int dknTreasureLesserI()
    { return 1; }

// the greater treasure type - the H of the stat grid (print capture p. 278)
inline int dknTreasureGreaterH()
    { return 1; }

// the special attacks - the see below of both columns, the powers riding
// below (print capture p. 278)
inline int dknSpecialAttacksSeeBelow()
    { return 1; }

// the special defenses - the see below of both columns (print capture p. 278)
inline int dknSpecialDefensesSeeBelow()
    { return 1; }

// the lesser intelligence - the very to genius of the stat grid (print
// capture p. 278)
inline int dknIntLesserVeryToGenius()
    { return 1; }

// the greater intelligence - the genius of the stat grid (print capture p.
// 278)
inline int dknIntGreaterGenius()
    { return 1; }

// the alignment - the variable of the stat grid, the aspect doctrine below
// deciding (print capture p. 278)
inline int dknAlignmentVariable()
    { return 1; }

// the size - the variable of the stat grid (print capture p. 278)
inline int dknSizeVariable()
    { return 1; }

// the psionic ability - the nil of both columns of the stat grid (print
// capture p. 278)
inline int dknPsionicNil()
    { return 1; }

// the attack and defense modes - the nil of both columns (print capture p.
// 278)
inline int dknModesNil()
    { return 1; }

// ---- the xp ladders ----

// the xp ladder row count - the six rungs of each column, the 2 to 7 HD of
// the lesser and the 8 to 15 HD of the greater (print capture p. 278)
inline int dknXPCount()
    { return 6; }

// the lesser xp base - the 118, 160, 215, 280, 475, and 700 of the six rungs
// (print capture p. 278)
inline int dknXPLesserBase(int b)
    {
        switch (b) {
        case 0:
            return 118;
        case 1:
            return 160;
        case 2:
            return 215;
        case 3:
            return 280;
        case 4:
            return 475;
        case 5:
            return 700;
        default:
            return 0;
        }
    }

// the lesser xp per hit point - the 2, 3, 4, 5, 6, and 8 of the six rungs
// (print capture p. 278)
inline int dknXPLesserPerHP(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 8;
        default:
            return 0;
        }
    }

// the greater xp base - the 1,275, 2,000, 3,000, 4,400, 6,100, and 8,100 of
// the six rungs (print capture p. 278)
inline int dknXPGreaterBase(int b)
    {
        switch (b) {
        case 0:
            return 1275;
        case 1:
            return 2000;
        case 2:
            return 3000;
        case 3:
            return 4400;
        case 4:
            return 6100;
        case 5:
            return 8100;
        default:
            return 0;
        }
    }

// the greater xp per hit point - the 10, 12, 14, 16, 18, and 20 of the six
// rungs (print capture p. 278)
inline int dknXPGreaterPerHP(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 12;
        case 2:
            return 14;
        case 3:
            return 16;
        case 4:
            return 18;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// ---- the nature and the aspects ----

// the nature - the outward manifestations of the powers of various plants and
// inanimate objects found in nature (print capture p. 278)
inline int dknOutwardManifestations()
    { return 1; }

// the lesser kinds - the spirits of trees, flowers, rocks, and bamboo groves
// (print capture p. 278)
inline int dknLesserOfTreesFlowersRocksBamboo()
    { return 1; }

// the greater kinds - those of mountains, boulders, plains, extremely ancient
// trees, and small islands (print capture p. 278)
inline int dknGreaterOfMountainsBouldersPlainsIslands()
    { return 1; }

// the binding - all are associated with a particular object or place from
// which they derive their life force (print capture p. 278)
inline int dknLifeforceObjectOrPlace()
    { return 1; }

// the sympathy - damage done to the thing or place affects the spirit
// accordingly (print capture p. 278)
inline int dknDamageAffectsSpirit()
    { return 1; }

// the lesser example - cutting down the tree which is the lifeforce of a
// lesser nature spirit would cause the death of that spirit (print capture p.
// 278)
inline int dknTreeDeathKillsLesser()
    { return 1; }

// the greater example - an earthquake which strikes the mountain of a greater
// nature spirit may anger or injure it, depending on the havoc wreaked (print
// capture p. 278)
inline int dknEarthquakeMayAngerOrInjure()
    { return 1; }

// the two aspects - they are all possessed of a good and an evil aspect
// (print capture p. 278)
inline int dknTwoAspects()
    { return 1; }

// the good aspect - it leads the spirit to be gentle, helpful, and kind
// (print capture p. 278)
inline int dknGoodAspectGentle()
    { return 1; }

// the evil aspect - it causes the spirit to be malicious, savage, and cruel
// (print capture p. 278)
inline int dknEvilAspectMalicious()
    { return 1; }

// the good aspect chance - when encountered there is a 75% chance that the
// good aspect is dominant (print capture p. 278)
inline int dknGoodAspectChancePct()
    { return 75; }

// the seclusion - normally the spirit shuns contact with the mortal world,
// preferring to peacefully reside within the thing or place that forms its
// lifeforce (print capture p. 278)
inline int dknShunsMortalWorld()
    { return 1; }

// the manifestation clause - in times of danger the nature spirit manifests
// itself (print capture p. 278)
inline int dknAppearsInDanger()
    { return 1; }

// the testing clause - they often appear to meet or test people of renown and
// fame (print capture p. 278)
inline int dknMeetsPeopleOfRenown()
    { return 1; }

// ---- the common powers ----

// the first common power - become invisible (print capture p. 279)
inline int dknCommonInvisible()
    { return 1; }

// the second common power - polymorph self (print capture p. 279)
inline int dknCommonPolymorphSelf()
    { return 1; }

// the third common power - detect evil and good (print capture p. 279)
inline int dknCommonDetectEvilGood()
    { return 1; }

// the fourth common power - detect magic (print capture p. 279)
inline int dknCommonDetectMagic()
    { return 1; }

// the fifth common power - detect harmony (print capture p. 279)
inline int dknCommonDetectHarmony()
    { return 1; }

// the use rate - the common powers are usable once per round at will (print
// capture p. 279)
inline int dknCommonOncePerRoundAtWill()
    { return 1; }

// ---- the lesser ----

// the lesser haunt - most often encountered in the vicinity of their
// lifeforce (print capture p. 279)
inline int dknLesserFoundNearLifeforce()
    { return 1; }

// the lesser look - when encountered usually polymorphed into the form of a
// handsome man or beautiful maiden (print capture p. 279)
inline int dknLesserPolymorphedForm()
    { return 1; }

// the polymorphed Charisma - the 19 of the handsome man or beautiful maiden
// form (print capture p. 279)
inline int dknPolymorphCharisma()
    { return 19; }

// the polymorphed Comeliness - the 21 of the handsome man or beautiful maiden
// form, the capture misreading Corneliness (print capture p. 279)
inline int dknPolymorphComeliness()
    { return 21; }

// the lesser knowledge - complete knowledge of the area around their
// lifeforce (print capture p. 279)
inline int dknLesserCompleteAreaKnowledge()
    { return 1; }

// the lesser gift - able to find hidden treasures and lost items in that area
// without difficulty (print capture p. 279)
inline int dknLesserFindsTreasuresAndLostItems()
    { return 1; }

// the lesser limit - they possess no special abilities beyond those already
// listed (print capture p. 279)
inline int dknLesserNoAbilitiesBeyond()
    { return 1; }

// the lesser romance - not uncommon for one to become attracted to and marry
// a mortal, such romances forming the basis for many tales and legends (print
// capture p. 279)
inline int dknLesserMarriesMortals()
    { return 1; }

// ---- the greater ----

// the greater standing - considerably more powerful than those of the lesser
// kind (print capture p. 279)
inline int dknGreaterConsiderablyMorePowerful()
    { return 1; }

// the greater shape change uses - five times per day (print capture p. 279)
inline int dknGreaterShapechangePerDay()
    { return 5; }

// the greater at-will powers - know history and aura at will (print capture
// p. 279)
inline int dknGreaterKnowHistoryAura()
    { return 1; }

// the greater weekly reward - reward once per week (print capture p. 279)
inline int dknGreaterRewardOncePerWeek()
    { return 1; }

// the greater weekly curse - ancient curse once per week (print capture p.
// 279)
inline int dknGreaterAncientCurseOncePerWeek()
    { return 1; }

// the element spellcasting - able to cast all wu jen spells of the element of
// their lifeforce, except conjure elemental, once per day (print capture p.
// 279)
inline int dknGreaterCastsElementSpells()
    { return 1; }

// the mountain example - a greater mountain spirit can cast all earth-related
// spells (print capture p. 279)
inline int dknGreaterMountainEarthSpells()
    { return 1; }

// the island example - a greater island spirit could cast all water-related
// spells, the water more dominant than the land in this case (print capture
// p. 279)
inline int dknGreaterIslandWaterSpells()
    { return 1; }

// the greater weapon floor - they can only be struck by +4 weapons or better
// (print capture p. 279)
inline int dknGreaterPlusFourWeaponsOnly()
    { return 1; }

// the greater immunity - immune to magical attacks made using their element
// (print capture p. 279)
inline int dknGreaterImmuneToOwnElement()
    { return 1; }

// the greater knowledge - complete knowledge of all events and happenings
// within the area of their lifeforce (print capture p. 279)
inline int dknGreaterCompleteEventKnowledge()
    { return 1; }

// the greater temper - tend to be aloof, haughty, and irritable (print
// capture p. 279)
inline int dknGreaterAloofHaughtyIrritable()
    { return 1; }

// the slope example - should a village be built on a prominent mountain slope
// the mountain spirit may think ill of it and attempt to drive the settlers
// off (print capture p. 279)
inline int dknGreaterSlopeVillageDisdain()
    { return 1; }

// the mortal caution - mortals go to great pains to avoid upsetting them,
// presenting offerings and consulting shukenja before undertaking any
// enterprise which might upset the being (print capture p. 279)
inline int dknMortalsOfferAndConsultShukenja()
    { return 1; }

// the greater marriage clause - the greater nature spirits seldom intermarry
// with humans (print capture p. 279)
inline int dknGreaterSeldomIntermarry()
    { return 1; }

}   // namespace rules
