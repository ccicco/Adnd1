// =========================================================================================
// Adnd1 - rules/oa77bakemono.h
// OA MONSTERS - THE BAKEMONO, printed capture pp. 254-255 - the goblin
// cousins round
// census 628 -> 629.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE STAT BLOCK: the uncommon, the 1-100 appearing, the AC
// 6, the move 6, the HD 1-1, the 40% lair, the treasure A, the 1 attack of
// 1-6 or by weapon type, the nil specials, the standard magic resistance, the
// low intelligence, the chaotic evil, the size S, the 1/10 + 1 per hp. THE
// DESCRIPTION: the western-goblin cousins similar in characteristics and
// habits; the variety of shapes and sizes, no two alike, the
// orange-and-red-to-deep-blue skin, the referee's free imagination; the bands
// for raiding and banditry ruled by an oni or ogre mage; the lieutenant of
// greater size per 20 members (the HD 2, the AC 4, the D 1-8) commanding
// absolutely; the abandoned-temples-and-villages lair, the bad repair, the
// long-deserted appearance, the 40% wooden stockade; the scavenged-not-made
// equipment doctrine with the seven-row table (the katana 5%, the naginata
// and short sword 20%, the spear 40%, the tetsubo and short sword 10%, the
// short sword and shortbow 10%, the chain and shuriken 5%, the kusari-gama
// and trident 10%); the 20% of a large force at AC 5 from worn pieces
// unusable by player characters; the four languages; the easily tricked; the
// sake weakness. The prose codifies per the R431 calculus
//
// the gap census after this round: 159 closed, 76 open - the Bakemono box
// flips (census 628 -> 629); NEXT - R707: the Bisan, Lesser Spirit (capture
// pp. 255-256), prefix dju (verify free at the landing), audit "R707 OA
// monsters Bisan audit", include after rules/oa77bakemono.h
//
namespace rules {

// ---- the stat block ----

// the Bakemono appearance count - the minimum of the 1-100 of the stat block
// (print capture p. 254)
inline int djtBakemonoNoAppearingMin()
    { return 1; }

// the Bakemono appearance count - the maximum of the 1-100 of the stat block
// (print capture p. 254)
inline int djtBakemonoNoAppearingMax()
    { return 100; }

// the Bakemono armor class - the 6 of the stat block (print capture p. 254)
inline int djtBakemonoAC()
    { return 6; }

// the Bakemono movement - the 6 of the stat block (print capture p. 254)
inline int djtBakemonoMove()
    { return 6; }

// the Bakemono hit dice - the 1-1 of the stat block, the dice count (print
// capture p. 254)
inline int djtBakemonoHDNum()
    { return 1; }

// the Bakemono hit dice - the 1-1 of the stat block, the negative modifier
// (print capture p. 254)
inline int djtBakemonoHDMod()
    { return 1; }

// the Bakemono lair chance - the 40% of the stat block (print capture p. 254)
inline int djtBakemonoLairPct()
    { return 40; }

// the Bakemono attack count - the 1 of the stat block (print capture p. 254)
inline int djtBakemonoAttacks()
    { return 1; }

// the Bakemono damage - the minimum of the 1-6 or by weapon type (print
// capture p. 254)
inline int djtBakemonoDmgMin()
    { return 1; }

// the Bakemono damage - the maximum of the 1-6 or by weapon type (print
// capture p. 254)
inline int djtBakemonoDmgMax()
    { return 6; }

// the Bakemono XP value - the 10 of the 1/10 + 1 per hp (print capture p.
// 255)
inline int djtBakemonoXPBase()
    { return 10; }

// the Bakemono XP value - the 1 per hp of the 1/10 + 1 per hp (print capture
// p. 255)
inline int djtBakemonoXPPerHP()
    { return 1; }

// ---- the band and the lair ----

// the Bakemono band organization - one lieutenant of greater size for every
// 20 members in the band (print capture p. 255)
inline int djtBakemonoBandPerLieutenant()
    { return 20; }

// the Bakemono lieutenant - the HD 2 of the greater-size lieutenant (print
// capture p. 255)
inline int djtBakemonoLieutenantHD()
    { return 2; }

// the Bakemono lieutenant - the AC 4 of the greater-size lieutenant (print
// capture p. 255)
inline int djtBakemonoLieutenantAC()
    { return 4; }

// the Bakemono lieutenant - the 1-8 damage of the greater-size lieutenant
// (print capture p. 255)
inline int djtBakemonoLieutenantDmgMax()
    { return 8; }

// the Bakemono stockade - on occasion 40%, the wooden stockade built and
// manned around the lair (print capture p. 255)
inline int djtBakemonoStockadePct()
    { return 40; }

// the Bakemono society - organized in bands for raiding and banditry (print
// capture p. 255)
inline bool djtBakemonoBandsForRaiding()
    { return true; }

// the Bakemono rule - the bands ruled by an oni or ogre mage (print capture
// p. 255)
inline bool djtBakemonoRuledByOniOrOgreMage()
    { return true; }

// the Bakemono lieutenant - receives his orders from the oni or ogre mage and
// commands absolutely the 20 bakemono under him (print capture p. 255)
inline bool djtBakemonoLieutenantAbsoluteCommand()
    { return true; }

// the Bakemono lair - abandoned temples or villages, preferring to drive the
// rightful inhabitants out, always in bad repair, long deserted in appearance
// (print capture p. 255)
inline bool djtBakemonoLairAbandonedTemples()
    { return true; }

// ---- the equipment and the armor ----

// the Bakemono equipment table - the seven scavenged-equipment rows of the
// typical force (print capture p. 255)
inline int djtBakemonoEquipCount()
    { return 7; }

// the Bakemono equipment - the katana 5% (print capture p. 255)
inline int djtBakemonoEquipKatanaPct()
    { return 5; }

// the Bakemono equipment - the naginata and short sword 20% (print capture p.
// 255)
inline int djtBakemonoEquipNaginataPct()
    { return 20; }

// the Bakemono equipment - the spear 40% (print capture p. 255)
inline int djtBakemonoEquipSpearPct()
    { return 40; }

// the Bakemono equipment - the tetsubo and short sword 10% (print capture p.
// 255)
inline int djtBakemonoEquipTetsuboPct()
    { return 10; }

// the Bakemono equipment - the short sword and shortbow 10% (print capture p.
// 255)
inline int djtBakemonoEquipShortswordBowPct()
    { return 10; }

// the Bakemono equipment - the chain and shuriken 5% (print capture p. 255)
inline int djtBakemonoEquipChainShurikenPct()
    { return 5; }

// the Bakemono equipment - the kusari-gama and trident 10% (print capture p.
// 255)
inline int djtBakemonoEquipKusariGamaPct()
    { return 10; }

// the Bakemono armor - when a large force is encountered, 20% have an Armor
// Class of 5 from worn pieces (print capture p. 255)
inline int djtBakemonoArmoredPct()
    { return 20; }

// the Bakemono armor - the Armor Class 5 of the armored 20% (print capture p.
// 255)
inline int djtBakemonoArmoredAC()
    { return 5; }

// the Bakemono equipment - they seldom make their own weapons or armor,
// preferring scavenged and looted items (print capture p. 255)
inline bool djtBakemonoScavengeNotMake()
    { return true; }

// the Bakemono armor - the worn pieces are in poor repair, drastically
// altered to fit, and cannot be worn by player characters (print capture p.
// 255)
inline bool djtBakemonoArmorUnusableByPCs()
    { return true; }

// ---- the nature ----

// the Bakemono origin - cousins to the western goblin, similar in
// characteristics and habits (print capture p. 255)
inline bool djtBakemonoGoblinCousins()
    { return true; }

// the Bakemono variety - a variety of shapes and sizes, no two creatures
// alike, the skin orange and red to deep blue, the features the referee's
// free imagination (print capture p. 255)
inline bool djtBakemonoNoTwoAlike()
    { return true; }

// the Bakemono languages - the trade language, the human area language, the
// language of oni, and their own similar-to-oni tongue (print capture p. 255)
inline int djtBakemonoLangCount()
    { return 4; }

// the Bakemono temperament - not particularly bright, easily tricked or
// outwitted (print capture p. 255)
inline bool djtBakemonoEasilyTricked()
    { return true; }

// the Bakemono weakness - a great weakness for sake and strong drink (print
// capture p. 255)
inline bool djtBakemonoSakeWeakness()
    { return true; }

}   // namespace rules
