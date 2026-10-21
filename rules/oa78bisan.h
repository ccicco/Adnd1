// =========================================================================================
// Adnd1 - rules/oa78bisan.h
// OA MONSTERS - THE BISAN, LESSER SPIRIT, printed capture pp. 255-256 - the
// tree spirit round
// census 629 -> 630.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 160 closed, 75 open - the Bisan box flips
// (census 629 -> 630); NEXT - R708: the Buso (capture pp. 256-257), prefix
// djv (verify free at the landing), audit "R708 OA monsters Buso audit",
// include after rules/oa78bisan.h
//
namespace rules {

// ---- the stat block ----

// the Bisan appearance count - the 1 of the stat block (print capture p. 255)
inline int djuBisanNoAppearing()
    { return 1; }

// the Bisan armor class - the AC 0 of the stat block (print capture p. 255)
inline int djuBisanAC()
    { return 0; }

// the Bisan movement rate - the move 24 of the stat block (print capture p.
// 255)
inline int djuBisanMove()
    { return 24; }

// the Bisan hit dice - the HD 10 of the stat block (print capture p. 255)
inline int djuBisanHD()
    { return 10; }

// the Bisan in-lair percentage - the 100% of the stat block (print capture p.
// 255)
inline int djuBisanLairPct()
    { return 100; }

// the Bisan treasure - the Q and T types of the stat block (print capture p.
// 255)
inline int djuBisanTreasureTypes()
    { return 2; }

// the Bisan attacks per round - the 1 of the stat block (print capture p.
// 255)
inline int djuBisanAttacks()
    { return 1; }

// the Bisan damage minimum - the 1 of the 1-10 of the stat block (print
// capture p. 255)
inline int djuBisanDmgMin()
    { return 1; }

// the Bisan damage maximum - the 10 of the 1-10 of the stat block (print
// capture p. 255)
inline int djuBisanDmgMax()
    { return 10; }

// the Bisan magic resistance - the 40% of the stat block (print capture p.
// 255)
inline int djuBisanMRPct()
    { return 40; }

// the Bisan experience level - the VII of the VII/2,100 of the stat block
// (print capture p. 256)
inline int djuBisanXPLevel()
    { return 7; }

// the Bisan base experience value - the 2,100 of the VII/2,100 (print capture
// p. 256)
inline int djuBisanXPBase()
    { return 2100; }

// the Bisan experience per hit point - the 14 per hp of the stat block (print
// capture p. 256)
inline int djuBisanXPPerHP()
    { return 14; }

// the Bisan frequency - the very rare of the stat block (print capture p.
// 255)
inline int djuBisanVeryRare()
    { return 1; }

// the Bisan intelligence - the High of the stat block (print capture p. 255)
inline int djuBisanIntHigh()
    { return 1; }

// the Bisan alignment - the Neutral of the stat block (print capture p. 256)
inline int djuBisanNeutral()
    { return 1; }

// the Bisan size - the M of the stat block (print capture p. 256)
inline int djuBisanSizeM()
    { return 1; }

// the Bisan psionics - the Nil ability and the Nil attack/defense modes of
// the stat block (print capture p. 256)
inline int djuBisanPsionicNil()
    { return 1; }

// ---- the tree and the harvest ----

// the Bisan nature - a lesser spirit tied to a tree harvested for its
// valuable wood, sap, gum, or oils (print capture p. 256)
inline int djuBisanTreeHarvestSpirit()
    { return 1; }

// the Bisan host tree - the camphor most common, the teak and mahogany and
// other valuable woods sometimes (print capture p. 256)
inline int djuBisanCamphorMostCommon()
    { return 1; }

// the Bisan natural form - a beautiful human woman (print capture p. 256)
inline int djuBisanNaturalFormBeautifulWoman()
    { return 1; }

// the Bisan preferred form - a small insect, the natural form seldom seen
// (print capture p. 256)
inline int djuBisanPrefersInsectForm()
    { return 1; }

// the Bisan guardianship - the protector of every same-type tree in its
// region, the camphor bisan watching all camphor trees (print capture p. 256)
inline int djuBisanProtectsSameTypeTrees()
    { return 1; }

// the Bisan personal tree - each bisan associated with a single tree in the
// forest (print capture p. 256)
inline int djuBisanOneTreePerBisan()
    { return 1; }

// the Bisan lifeforce - the personal tree damaged or cut down, the bisan
// suffers the same effect (print capture p. 256)
inline int djuBisanTreeDamageDamagesIt()
    { return 1; }

// the Bisan harvest allowance - the humans and others may take sap, branches,
// fruit, or leaves (print capture p. 256)
inline int djuBisanAllowsHarvest()
    { return 1; }

// the Bisan end-of-life rule - the trees at the end of their life spans may
// be cut down without incurring the bisan displeasure (print capture p. 256)
inline int djuBisanEndOfLifeFellingAllowed()
    { return 1; }

// the Bisan harvest exchange - the offering owed, normally part of each meal
// and a white cock (print capture p. 256)
inline int djuBisanRequiresOffering()
    { return 1; }

// the Bisan anger rule - should the offering not be done, the bisan becomes
// angry (print capture p. 256)
inline int djuBisanAngeredWithoutOffering()
    { return 1; }

// the Bisan offering terms - the part of each meal and the white cock (print
// capture p. 256)
inline int djuBisanOfferingsRequired()
    { return 2; }

// the Bisan language count - the language of their own race and no other
// (print capture p. 256)
inline int djuBisanLangCount()
    { return 1; }

// ---- the powers ----

// the Bisan power - the polymorph self at will (print capture p. 256)
inline int djuBisanPolymorphSelfAtWill()
    { return 1; }

// the Bisan power - the turn invisible at will (print capture p. 256)
inline int djuBisanTurnInvisibleAtWill()
    { return 1; }

// the Bisan power - the become ethereal at will (print capture p. 256)
inline int djuBisanBecomeEtherealAtWill()
    { return 1; }

// the Bisan battery entry - the bless cast together with its reverse (print
// capture p. 256)
inline int djuBisanBlessReversible()
    { return 1; }

// the Bisan casting rate - the once per round spell battery (print capture p.
// 256)
inline int djuBisanSpellsPerRound()
    { return 1; }

// the Bisan spell battery size - the nine entries: the bless and its reverse,
// the castigate, the cause paralysis, the pacify, the animate wood, the wood
// shape, the elemental turning, the quickgrowth, the ironwood (print capture
// p. 256)
inline int djuBisanSpellBatteryCount()
    { return 9; }

// ---- the nature ----

// the Bisan combat doctrine - the avoidance of combat whenever possible, the
// spells used to cause mischief and hardship (print capture p. 256)
inline int djuBisanAvoidsCombatMischief()
    { return 1; }

// the Bisan flight rule - if forced to fight, the flees at the first possible
// moment unless defending its personal tree (print capture p. 256)
inline int djuBisanFleesUnlessDefendingTree()
    { return 1; }

// the Bisan temperament - highly intelligent and clever, formidable enemies
// if angered (print capture p. 256)
inline int djuBisanFormidableIfAngered()
    { return 1; }

// the Bisan locale - the woodsmen know the bisan woods locations, many
// identified by local superstition (print capture p. 256)
inline int djuBisanWoodsKnownBySuperstition()
    { return 1; }

// the Bisan speech - the language of their own race and no other (print
// capture p. 256)
inline int djuBisanSpeaksOwnLanguageOnly()
    { return 1; }

}   // namespace rules
