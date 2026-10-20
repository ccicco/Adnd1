// =========================================================================================
// Adnd1 - rules/oadisarming.h
// OA DISARMING, printed capture p. 221 - the disarm doctrine round
// census 607 -> 608.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE DOCTRINE: at times characters must disarm an opponent
// - the charmed party member, the capture without harm. THE TWO METHODS:
// parrying the weapon out through superior weapon skill, or wresting it from
// the grasp with one's bare hands. THE WEAPON DISARM: a melee weapon of equal
// or greater size than the victim's, declared at the beginning of the round,
// a normal to hit roll doing no damage - the victim passing a saving throw
// versus petrification or losing the weapon, which falls 1d6 feet away, one
// round to recover. THE BARE HANDS: the UA weaponless combat system or the
// martial arts skills - which knock loose a weapon of any size, the victim at
// +2 on the save. THE TWO-HANDED RULE: one hand knocked loose per success,
// two successful attempts in the same round to disarm, otherwise the simple
// regrip at the end of the round. The prose codifies per the R431 calculus
//
// the gap census after this round: 138 closed, 97 open - the Disarming box
// flips (census 607 -> 608); NEXT - R686: the Subduing Opponents doctrine
// (capture p. 221), prefix diz (verify free at the landing - diu, div, diw,
// dix and diy TAKEN by the R681-R685 call families), audit "R686 OA subduing
// audit", include after rules/oadisarming.h
//
namespace rules {

// ---- the disarm number pins ----

// the disarm weapon fall - the disarmed weapon falling 1d6 feet away from the
// disarmed character (print capture p. 221)
inline int diyOADisarmWeaponFallDice()
    { return 6; }

// the disarm recovery - one round needed to recover the fallen weapon (print
// capture p. 221)
inline int diyOADisarmRecoverRounds()
    { return 1; }

// the martial-arts disarm save bonus - when using martial arts the character
// can attempt to knock loose a weapon of any size, the process the same as
// disarming with a weapon except the victim allowed a +2 to his saving throw
// (print capture p. 221)
inline int diyOADisarmMartialArtsSaveBonus()
    { return 2; }

// the two-handed weapon disarm - a successful attempt against a two-handed
// weapon knocks loose only one hand, so two successful disarming attempts
// must be made in the same round to disarm; should only one succeed, the
// opponent simply regrips his weapon at the end of the round (print capture
// p. 221)
inline int diyOADisarmTwoHandedAttemptsNeeded()
    { return 2; }

// ---- the disarm doctrine pins ----

// the doctrine frame - at times characters find it necessary to disarm an
// opponent: a party member charmed into attacking his friends, or the wish to
// capture an opponent without being harmed greatly (print capture p. 221)
inline bool diyOADisarmDoctrine()
    { return true; }

// the two methods - disarming done by parrying the weapon out of the
// opponent's grasp through superior weapon skill or by wresting it from his
// grasp with one's bare hands (print capture p. 221)
inline bool diyOADisarmTwoMethods()
    { return true; }

// the size rule - to disarm with a weapon, the character must be using a
// melee weapon of equal or greater size than that of the victim (print
// capture p. 221)
inline bool diyOADisarmEqualOrGreaterSize()
    { return true; }

// the declaration rule - the character must declare at the beginning of the
// round that he is attempting to disarm (print capture p. 221)
inline bool diyOADisarmMustDeclare()
    { return true; }

// the no-damage attack - a normal to hit roll is made but the attack does no
// damage (print capture p. 221)
inline bool diyOADisarmNoDamage()
    { return true; }

// the disarm save - the victim must pass a saving throw versus petrification
// or have the weapon knocked from his grasp (print capture p. 221)
inline bool diyOADisarmSaveVersusPetrification()
    { return true; }

// the bare-hands systems - to disarm with one's bare hands the character can
// use either the weaponless combat system explained in Unearthed Arcana or,
// if he has the proficiency, the martial arts skills explained later in these
// rules (print capture p. 221)
inline bool diyOADisarmBareHandsSystems()
    { return true; }

}   // namespace rules
