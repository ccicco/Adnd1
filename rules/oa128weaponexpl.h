// =========================================================================================
// Adnd1 - rules/oa128weaponexpl.h
// OA TREASURE - THE EXPLANATION OF WEAPON PROPERTIES, printed capture pp.
// 294-296 - the big weapons prose round
// census 679 -> 680.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 210 closed, 25 open - the explanation box
// flips (census 679 -> 680); NEXT - R758: Oriental Magical Items prose with
// Table 86 and the item descriptions (capture pp. 296-301), prefix dlt
// (verify free at the landing), audit "R758 OA magical items prose audit",
// include after rules/oa128weaponexpl.h
//
namespace rules {

// ---- the quality by class ----

// the sword and melee quality value die - the 2d6 times the normal price
// (print capture p. 294)
inline int dlsSwordQualityValueDie()
    { return 6; }

// the sword and melee quality - the finest steel and razor sharpness, not
// magical, the +1 to hit only, worth the 2d6 times (print capture p. 294)
inline int dlsSwordMeleeQuality()
    { return 1; }

// the bow quality value die - the 2d4 times the normal price (print capture
// p. 294)
inline int dlsBowQualityValueDie()
    { return 4; }

// the bow quality - perfectly balanced for pull and weight, each range
// treated as the next lowest, worth the 2d4 times (print capture p. 294)
inline int dlsBowQuality()
    { return 1; }

// the missile quality price minimum - the 2 of the 2-5 times the normal price
// (print capture p. 294)
inline int dlsMissileQualityPriceMin()
    { return 2; }

// the missile quality price maximum - the 5 of the 2-5 times (print capture
// p. 294)
inline int dlsMissileQualityPriceMax()
    { return 5; }

// the missile quality - balanced to fly true and strike hard, the +1 to hit
// only, worth the 2-5 times (print capture p. 294)
inline int dlsMissileQuality()
    { return 1; }

// the martial arts price minimum - the 2 of the 2-5 times the normal price
// (print capture p. 294)
inline int dlsMartialArtsPriceMin()
    { return 2; }

// the martial arts price maximum - the 5 of the 2-5 times (print capture p.
// 294)
inline int dlsMartialArtsPriceMax()
    { return 5; }

// the martial arts quality - made by masters, the +1 to hit only when used by
// those trained in a style, quite plain, worth the 2-5 times (print capture
// p. 294)
inline int dlsMartialArtsQuality()
    { return 1; }

// the ninja assembly rounds - the large weapons disassembled and reassembled
// in one round (print capture p. 294)
inline int dlsNinjaAssembleRounds()
    { return 1; }

// the ninja quality - razor sharp and finely balanced, the +1 to damage,
// extremely lightweight and compact, the large weapons disassembling for
// concealment (print capture p. 294)
inline int dlsNinjaQuality()
    { return 1; }

// ---- the plus grades and the cursed ----

// the plus grades - the +1, +2, +3 magical, the bonus to both the chance to
// hit and the damage (print capture p. 294)
inline int dlsPlusGrades()
    { return 1; }

// the damage grades - the +1, +2, +3 damage causing the extra damage but no
// bonus to hit (print capture p. 294)
inline int dlsDamageBonusGrades()
    { return 1; }

// the to-hit grades - the +1, +2, +3 to hit increasing the chance to hit but
// not the damage (print capture p. 294)
inline int dlsToHitBonusGrades()
    { return 1; }

// the versus smaller - the +1 to hit and damage against man-sized and larger,
// the +2 against smaller than man-sized (print capture p. 294)
inline int dlsVsSmaller()
    { return 1; }

// the versus larger - the +1 to hit and damage against man-sized and smaller,
// the +2 against larger than man-sized (print capture p. 294)
inline int dlsVsLarger()
    { return 1; }

// the cursed bow return roll - the to hit roll of 1 sending the missile back
// full force on the firer (print capture p. 294)
inline int dlsCursedReturnRoll()
    { return 1; }

// the cursed concealment - undetectable from the normal +1 items, revealing
// the true nature only in earnest combat (print capture p. 294)
inline int dlsCursedUndetectable()
    { return 1; }

// the cursed bows - the -1 to hit, the to hit roll of 1 returning the missile
// full force on the firer for normal damage (print capture p. 294)
inline int dlsCursedBowsReturn()
    { return 1; }

// the cursed melee - the -1 to hit, the owner preferring it to all others,
// never voluntarily discarding it, the remove curse freeing the character
// (print capture p. 294)
inline int dlsCursedMeleePreference()
    { return 1; }

// ---- the special properties ----

// the accuracy - the +3 to hit and damage, all ranges considered short with
// no range modifier (print capture p. 295)
inline int dlsAccuracyAllShort()
    { return 1; }

// the balance tightrope percent - the ninja tightrope walking bonus (print
// capture p. 295)
inline int dlsBalanceTightropePct()
    { return 10; }

// the balance - appearing the normal +1 and the +1 to hit and damage, the
// exceptional balance, the automatic save versus death to regain the footing
// (print capture p. 295)
inline int dlsBalanceSaveRegain()
    { return 1; }

// the dancing fight minimum - the 2 of the 2-5 rounds (print capture p. 295)
inline int dlsDancingFightMin()
    { return 2; }

// the dancing fight maximum - the 5 of the 2-5 rounds (print capture p. 295)
inline int dlsDancingFightMax()
    { return 5; }

// the dancing stay limit - the weapon not straying more than five feet from
// the character (print capture p. 295)
inline int dlsDancingStayFt()
    { return 5; }

// the dancing - appearing the +2 and the +2 to hit and damage, the command
// word after a preceding combat round, the weapon fighting the 2-5 rounds
// within the five feet, once every turn, the martial arts proficiency
// required (print capture p. 295)
inline int dlsDancingWeapon()
    { return 1; }

// the detection - the +1 to hit and damage, the d8 subtable of the detected
// thing, the hold and command word, the gentle tug (print capture p. 295)
inline int dlsDetectionWeapon()
    { return 1; }

// the disruption - functioning identically to the mace of disruption of the
// DMG (print capture p. 295)
inline int dlsDisruptionPerDMG()
    { return 1; }

// the distance - the +1 to hit and damage, firing to double all the normal
// range categories (print capture p. 295)
inline int dlsDistanceDoubleRange()
    { return 1; }

// the flame extra damage die - the 2d4 additional points on a successful hit
// (print capture p. 295)
inline int dlsFlameExtraDie()
    { return 4; }

// the flame ignite percent - the combustibles ignited 40% of the time (print
// capture p. 295)
inline int dlsFlameIgnitePct()
    { return 40; }

// the flame light radius - the 15-foot light of the magical flame (print
// capture p. 295)
inline int dlsFlameLightFt()
    { return 15; }

// the flame - the +1 to hit and damage, the command word bursting the magical
// flame, the 2d4 extra, the 40% ignition, the 15-foot light, the flame
// harmless to the weapon (print capture p. 295)
inline int dlsFlameWeapon()
    { return 1; }

// the weapon intelligence die - the 1d6 plus 11 of the 12-17 range (print
// capture p. 295)
inline int dlsIntelligenceDie()
    { return 6; }

// the weapon intelligence minimum - the 12 of the 12-17 range (print capture
// p. 295)
inline int dlsIntelligenceMin()
    { return 12; }

// the weapon intelligence maximum - the 17 of the 12-17 range (print capture
// p. 295)
inline int dlsIntelligenceMax()
    { return 17; }

// the intelligence - the +3 to hit and damage, the intelligence of the
// intelligent swords per the DMG, the semi-empathy the communication limit
// (print capture p. 295)
inline int dlsIntelligenceWeapon()
    { return 1; }

// the silence moving silently percent - the ninja move silently improvement
// (print capture p. 295)
inline int dlsSilenceMovePct()
    { return 15; }

// the silence hide percent - the ninja hiding in shadows improvement (print
// capture p. 295)
inline int dlsSilenceHidePct()
    { return 20; }

// the silence - the +1 to hit and damage, the muffling field, the ninja 15%
// move silently and 20% hide improvements, the sonic attacks reduced, no
// protection against clumsiness (print capture p. 295)
inline int dlsSilenceWeapon()
    { return 1; }

// the slaying - the +3 weapon marked distinctively, the markings identifying
// the affected creature, the instant slaying on a successful hit, the missile
// losing all magic once successfully used (print capture p. 296)
inline int dlsSlayingWeapon()
    { return 1; }

// the speed - the +1 to hit and damage, the bows firing at the double rate
// and self-nocking, the first automatic shot, the complete surprise
// second-segment shot, the throwing weapons leaping and the automatic first
// attack (print capture p. 296)
inline int dlsSpeedWeapon()
    { return 1; }

// the unbreakable break percent - the chance the opponent weapon breaks on
// the Weapon Breaker attempt (print capture p. 296)
inline int dlsUnbreakableBreakPct()
    { return 75; }

// the unbreakable - treated as the +2 to hit and damage, not breakable by the
// Weapon Breaker, the 75% chance of breaking the opponent weapon instead
// (print capture p. 296)
inline int dlsUnbreakableWeapon()
    { return 1; }

// the venom - identical to the dagger of venom in the DMG (print capture p.
// 296)
inline int dlsVenomPerDMG()
    { return 1; }

// the roll twice - the Table 79 grid instruction of the martial arts and
// ninja tails, rolling twice on the same grid (print capture p. 292)
inline int dlsRollTwice()
    { return 1; }

// ---- the subtables ----

// the detection row count - the eight bands of the d8 detection subtable
// (print capture p. 295)
inline int dlsDetectRowCount()
    { return 8; }

// the detection type code - 1 the evil; 2 the good; 3 the poison (touch); 4
// the lifeforms; 5 the back attacks; 6 the invisible creatures and objects; 7
// the traps; 8 the secret doors (print capture p. 295)
inline int dlsDetectType(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return 0;
        }
    }

// the detection range feet - the 10, the touch 0, the 1 of the back attacks,
// and the 5 of the traps (print capture p. 295)
inline int dlsDetectRangeFt(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 1;
        case 5:
            return 10;
        case 6:
            return 5;
        case 7:
            return 10;
        default:
            return 0;
        }
    }

// the slaying creature count - the twenty-four creatures of the example list,
// the print running two columns (print capture p. 296)
inline int dlsSlayingCreatureCount()
    { return 24; }

// the slaying creature code - 1 the bajang; 2 the bushi; 3 the dragons; 4 the
// elementals; 5 the giants; 6 the hengeyokai; 7 the hu hsien; 8 the humans; 9
// the kalau; 10 the korobokuru; 11 the kuei; 12 the nats; 13 the ninja; 14
// the ogre magi; 15 the ogres; 16 the oni; 17 the poh; 18 the samurai; 19 the
// shukenja; 20 the sohei; 21 the spiders; 22 the spirit folk; 23 the wu jen;
// 24 the yakuza, the print reading the left column then the right (print
// capture p. 296)
inline int dlsSlayCreatureCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        case 17:
            return 18;
        case 18:
            return 19;
        case 19:
            return 20;
        case 20:
            return 21;
        case 21:
            return 22;
        case 22:
            return 23;
        case 23:
            return 24;
        default:
            return 0;
        }
    }

}   // namespace rules
