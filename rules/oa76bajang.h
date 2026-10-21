// =========================================================================================
// Adnd1 - rules/oa76bajang.h
// OA MONSTERS - THE BAJANG, printed capture pp. 253-254 - the lesser spirit
// round
// census 627 -> 628.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE STAT BLOCK: the very rare, the 1 appearing, the AC 2,
// the move 12, the HD 6, the 20% lair, the treasure P, the 2 attacks of
// 1-4/1-4, the spells and the poison special attacks, the nil special
// defenses, the 10% magic resistance, the high intelligence, the chaotic
// evil, the size S, the V/500 + 6 per hp. THE DESCRIPTION: the evil and
// malignant tropical-jungle creature; the true form the stunted humanoid with
// bird-like feet and clawed hands; the wildcat shape at will, the most
// commonly seen appearance; the eight spells (the curse, the omen, the
// divination, the fate, the ghost light, the wind breath, the steam breath,
// the transfix) cast three times per day; the ancient curse once per day; the
// claw poison the -1 on all hit and saving throw rolls for the 2-7 rounds,
// cumulative; the spirit limitations; the tree lifeforce - the tree
// destroyed, the bajang instantly slain, the location concealed; the village
// predation by night, the victims taken sleeping; the evil sorcerer's
// familiar service; the intelligent and extremely devious temperament; the
// own language and the common area language. The prose codifies per the R431
// calculus
//
// the gap census after this round: 158 closed, 77 open - the Bajang box flips
// (census 627 -> 628); NEXT - R706: the Bakemono (capture pp. 254-255),
// prefix djt (verify free at the landing), audit "R706 OA monsters Bakemono
// audit", include after rules/oa76bajang.h
//
namespace rules {

// ---- the stat block ----

// the Bajang frequency - the very rare of the stat block (print capture p.
// 253)
inline int djsBajangFrequencyClass()
    { return 1; }

// the Bajang appearance count - the 1 of the stat block (print capture p.
// 253)
inline int djsBajangNoAppearing()
    { return 1; }

// the Bajang armor class - the 2 of the stat block (print capture p. 253)
inline int djsBajangAC()
    { return 2; }

// the Bajang movement - the 12 of the stat block (print capture p. 254)
inline int djsBajangMove()
    { return 12; }

// the Bajang hit dice - the 6 of the stat block (print capture p. 254)
inline int djsBajangHD()
    { return 6; }

// the Bajang lair chance - the 20% of the stat block (print capture p. 254)
inline int djsBajangLairPct()
    { return 20; }

// the Bajang attack count - the 2 of the stat block (print capture p. 254)
inline int djsBajangAttacks()
    { return 2; }

// the Bajang damage per claw - the minimum of the 1-4/1-4 (print capture p.
// 254)
inline int djsBajangDmgMin()
    { return 1; }

// the Bajang damage per claw - the maximum of the 1-4/1-4 (print capture p.
// 254)
inline int djsBajangDmgMax()
    { return 4; }

// the Bajang magic resistance - the 10% of the stat block (print capture p.
// 254)
inline int djsBajangMRPct()
    { return 10; }

// the Bajang XP value - the 500 of the V/500 + 6 per hp (print capture p.
// 254)
inline int djsBajangXPBase()
    { return 500; }

// the Bajang XP value - the 6 per hp of the V/500 + 6 per hp (print capture
// p. 254)
inline int djsBajangXPPerHP()
    { return 6; }

// ---- the powers and the poison ----

// the Bajang spell count - the eight spells of the three-per-day list (print
// capture p. 254)
inline int djsBajangSpellCount()
    { return 8; }

// the Bajang spell uses - the curse, omen, divination, fate, ghost light,
// wind breath, steam breath, and transfix cast three times per day (print
// capture p. 254)
inline int djsBajangSpellUsesPerDay()
    { return 3; }

// the Bajang ancient curse - once per day (print capture p. 254)
inline int djsBajangAncientCursePerDay()
    { return 1; }

// the Bajang claw poison - the -1 on all hit and saving throw rolls on a
// failed save vs. poison (print capture p. 254)
inline int djsBajangPoisonPenalty()
    { return 1; }

// the Bajang claw poison duration - the minimum of the 2-7 rounds (print
// capture p. 254)
inline int djsBajangPoisonMinRounds()
    { return 2; }

// the Bajang claw poison duration - the maximum of the 2-7 rounds (print
// capture p. 254)
inline int djsBajangPoisonMaxRounds()
    { return 7; }

// the Bajang claw poison - the -1 penalty effect is cumulative (print capture
// p. 254)
inline bool djsBajangPoisonCumulative()
    { return true; }

// ---- the nature and the description ----

// the Bajang - a lesser spirit, subject to all the limitations of spirit
// creatures as regards spells which affect these creatures (print capture pp.
// 253-254)
inline bool djsBajangLesserSpirit()
    { return true; }

// the Bajang habitat - an evil and malignant creature found in tropical
// jungles (print capture p. 254)
inline bool djsBajangTropicalJungle()
    { return true; }

// the Bajang true form - a stunted evil-looking humanoid with bird-like feet
// and clawed hands (print capture p. 254)
inline bool djsBajangTrueFormHumanoid()
    { return true; }

// the Bajang shapechange - it changes shape at will assuming the form of a
// small wildcat, the most commonly seen appearance (print capture p. 254)
inline bool djsBajangWildcatShapeCommon()
    { return true; }

// the Bajang lifeforce - tied to some tree in its forest; the tree destroyed,
// the bajang instantly slain; the tree location concealed (print capture p.
// 254)
inline bool djsBajangTreeLifeforce()
    { return true; }

// the Bajang predation - lives near a small village or habitation, striking
// at night to take victims while sleeping (print capture p. 254)
inline bool djsBajangNightVillagePredator()
    { return true; }

// the Bajang service - sometimes serves a powerful sorcerer of evil nature as
// their familiar (print capture p. 254)
inline bool djsBajangEvilSorcererFamiliar()
    { return true; }

// the Bajang temperament - intelligent and extremely devious (print capture
// p. 254)
inline bool djsBajangIntelligentDevious()
    { return true; }

// the Bajang languages - the own language, the common area language, and the
// devious tongue of its intelligence (print capture p. 254)
inline int djsBajangLangCount()
    { return 3; }

}   // namespace rules
