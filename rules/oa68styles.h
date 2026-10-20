// =========================================================================================
// Adnd1 - rules/oa68styles.h
// OA TABLE 68, printed capture pp. 224-225 - the common martial styles round
// census 611 -> 612.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: the four common styles - Karate the 3/1 at the
// d6 and AC 8, Hand principal, six maneuver ranks (Strike 1,2,3, Kick 1,
// Movement 1, Mental 1); Kung-fu the 2/1 at the d6 and AC 6 - the most
// protective, Hand, eight ranks (Lock 1,2,3, Strike 1,2, Kick 2, Movement 4,
// Mental 5); Tae Kwon Do the 1/1 at the lone d8 and AC 8, the only Foot
// principal, six ranks (Kick 1,2,3, Strike 1, Throw 4, Movement 5); Jujutsu
// the 2/1 at the d6 and AC 7, Hand, the eleven ranks - the most maneuver-rich
// (Throw 1,2,3,4, Movement 1,3, Vital Area 1,2, Mental 1,2,3). THE PROSE: the
// attacks style-dependent and possibly different from weapons; the defensive
// styles low damage; the AC born of the training; the principal form free so
// long as the body part is - the Karate fist with legs held; the maneuvers
// the secrets of the art. The grid codifies per the R431 calculus
//
// the gap census after this round: 142 closed, 93 open - the Table 68 box
// flips (census 611 -> 612); NEXT - R690: the Creating a Style doctrine
// (capture pp. 225-228), prefix djd (verify free at the landing), audit "R690
// OA creating a style audit", include after rules/oa68styles.h
//
namespace rules {

// ---- the Table 68 common styles grid ----

// the Table 68 attacks numerators by style ordinal (print capture p. 224):
// the styles read 1 Karate, 2 Kung-fu, 3 Tae Kwon Do, 4 Jujutsu - the 3/1,
// 2/1, 1/1 and 2/1 rates of the four common styles
inline int djcOA68AtkNum(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return 0;
        }
    }

// the Table 68 attacks denominators by style ordinal (print capture p. 224):
// every common style a per-round rate, all four denominators the 1
inline int djcOA68AtkDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// the Table 68 damage dice by style ordinal (print capture p. 224): Karate
// the d6, Kung-fu the d6, Tae Kwon Do the d8 - the only d8, Jujutsu the d6
inline int djcOA68DmgDie(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 6;
        default:
            return 0;
        }
    }

// the Table 68 armor classes by style ordinal (print capture p. 224): Karate
// 8, Kung-fu 6 - the best, Tae Kwon Do 8, Jujutsu 7; the lower the better,
// Kung-fu the most protective style
inline int djcOA68AC(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 7;
        default:
            return 0;
        }
    }

// the Table 68 principal attack forms by style ordinal (print capture p.
// 224): 1 Hand, 2 Foot - Karate the Hand, Kung-fu the Hand, Tae Kwon Do the
// Foot - the only Foot style, Jujutsu the Hand
inline int djcOA68Principal(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// the Table 68 special maneuver rank counts by style ordinal (print capture
// p. 224) - the number of listed maneuver ranks: Karate Strike 1,2,3 + Kick 1
// + Movement 1 + Mental 1 = 6; Kung-fu Lock 1,2,3 + Strike 1,2 + Kick 2 +
// Movement 4 + Mental 5 = 8; Tae Kwon Do Kick 1,2,3 + Strike 1 + Throw 4 +
// Movement 5 = 6; Jujutsu Throw 1,2,3,4 + Movement 1,3 + Vital Area 1,2 +
// Mental 1,2,3 = 11 - the most maneuver-rich style
inline int djcOA68ManeuverRanks(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 6;
        case 3:
            return 11;
        default:
            return 0;
        }
    }

// ---- the Table 68 prose pins ----

// the Table 68 style count - the four common martial styles (Karate, Kung-fu,
// Tae Kwon Do, Jujutsu), the loop bound of the emitted grid audit (print
// capture p. 224)
inline int djcOA68StyleCount()
    { return 4; }

// the attacks explanation - the number of attacks depends on the style used
// and may differ from the number of attacks with weapons, a character's
// ability to attack able to increase, decrease or remain the same when using
// martial arts (print capture p. 225)
inline bool djcOA68AttacksStyleDependent()
    { return true; }

// the damage explanation - the damage die rolled to determine the effect of a
// hit, the defensive styles generally doing low damage, the offensive the
// opposite (print capture p. 225)
inline bool djcOA68DamageDefensiveLow()
    { return true; }

// the armor class explanation - a measure of the degree of protection the
// character gains when using the style, the protection coming from the
// training that allows him to avoid, deflect or withstand blows (print
// capture p. 225)
inline bool djcOA68ACFromTraining()
    { return true; }

// the principal attack form explanation - the part or parts of body most
// often used, the attacks continuing so long as the listed body part is free
// - Karate emphasizing the fist, the character attacking even though his legs
// may be held (print capture p. 225)
inline bool djcOA68PrincipalBodyPartFree()
    { return true; }

// the special maneuvers explanation - the secrets of the art allowing
// fantastic feats but difficult to learn: Backward Kick, Sticking Touch,
// Great Throw, Ironskin and other normally impossible abilities (print
// capture p. 225)
inline bool djcOA68ManeuversSecrets()
    { return true; }

}   // namespace rules
