// =========================================================================================
// Adnd1 - rules/oat63divination.h
// TABLE 63 DIVINATION RESULTS, printed capture p. 117 - the OA divination
// results round
// census 588 -> 589.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print p. 117;
// compressed pp. 59-60); the five band rows cross-checked line by line
// between the passes, zero contested reads - the only OCR variance is
// typographic (the compressed dropping a period on the neutral row and a
// stray quote mark on the favorable to hit line). The table answers the omen
// spell: a 1d10 rolled when the DM has no information on which to base his
// judgment. The bands pin as a chain (the die roll mapped to its band: 1-2
// ill omen, 3-4 great danger, 5-7 neutral, 8-9 favorable, 10 auspicious - the
// neutral band the widest at three faces) and a six-column grid: the party to
// hit and save modifiers, the foe to hit modifier, the encounter chance
// multiplier, the reaction modifier and the travel boost. The ill omen band
// is conditional: the -1 party penalties apply only if the characters ignore
// the advice (the diaIllOmenIgnorePenalty pin), while the doubled encounters
// and the -10% reaction apply outright - great danger shares the doubled
// encounters and the reaction penalty and adds the adversaries to hit at +1.
// The favorable band travels at half again the normal rate (pinned +50
// percent) with opponents to hit at -1; the auspicious band stacks all the
// favorable effects plus the +1 on all saving throws that day. The band names
// ride the column comments, the omen prose closes in its own round. The table
// tag T63Data identifier-safe per the R639 lesson
//
// the gap census after this round: 119 closed, 116 open - the Table 63
// Divination Results box flips (census 588 -> 589); NEXT - R667: the Table 64
// Speak with Dead (capture p. 132), prefix dib (verify free), audit "R667 OA
// speak with dead audit"
//
namespace rules {

// ---- the band count pins ----

// the five divination result bands (print p. 117; compressed pp. 59-60)
inline int diaBandCount()
    { return 5; }

// the omen roll is 1d10, the table consulted when the DM has no information
// (print p. 117; compressed pp. 59-60)
inline int diaDieFaces()
    { return 10; }

// the neutral band is the widest at three faces (die 5-7); the other bands
// one or two (print p. 117; compressed pp. 59-60)
inline int diaNeutralFaces()
    { return 3; }

// the ill omen band - die 1-2: the characters should not undertake the task
// this day (print p. 117; compressed pp. 59-60)
inline int diaIllOmenBand()
    { return 0; }

// the great danger band - die 3-4: doubled encounters, the -10% reaction and
// the adversaries to hit at +1 (print p. 117; compressed pp. 59-60)
inline int diaGreatDangerBand()
    { return 1; }

// the neutral omen band - die 5-7: no special modifiers apply (print p. 117;
// compressed pp. 59-60)
inline int diaNeutralBand()
    { return 2; }

// the favorable omen band - die 8-9: travel at half again the normal rate and
// opponents to hit at -1 (print p. 117; compressed pp. 59-60)
inline int diaFavorableBand()
    { return 3; }

// the auspicious omen band - die 10: all the favorable omen effects plus a +1
// on all saving throws that day (print p. 117; compressed pp. 59-60)
inline int diaAuspiciousBand()
    { return 4; }

// the two bands doubling the chance for encounters - ill omen and great
// danger (print p. 117; compressed pp. 59-60)
inline int diaDoubledEncounterBands()
    { return 2; }

// the -10% reaction modifier applied to all encounters in the ill omen and
// great danger bands (print p. 117; compressed pp. 59-60)
inline int diaReactionPenaltyPct()
    { return 10; }

// the auspicious band alone grants the +1 on all saving throws made that day
// (print p. 117; compressed pp. 59-60)
inline int diaFavorableSaveBonus()
    { return 1; }

// the favorable and auspicious bands travel at half again the normal rate -
// pinned as +50 percent (print p. 117; compressed pp. 59-60)
inline int diaTravelBoostPct()
    { return 50; }

// the ill omen penalty - if the advice is ignored, all characters suffer a -1
// on to hit and saving throw rolls for the rest of the day (print p. 117;
// compressed pp. 59-60)
inline int diaIllOmenIgnorePenalty()
    { return 1; }

// the omen spell can only be used once per week - the strain of the casting
// (print p. 117; compressed pp. 59-60)
inline int diaOmenWeeklyLimit()
    { return 1; }

// ---- the band chain ----

// the 1d10 roll mapped to its band (print p. 117; compressed pp. 59-60): 1-2
// the ill omen band 0, 3-4 the great danger band 1, 5-7 the neutral band 2,
// 8-9 the favorable band 3, 10 the auspicious band 4
inline int diaOmenBand(int d)
    {
        if (d <= 2) return 0;
        if (d <= 4) return 1;
        if (d <= 7) return 2;
        if (d <= 9) return 3;
        return 4;
    }

// ---- the band modifier grid ----

// the party to hit modifier by band (print p. 117; compressed pp. 59-60). The
// band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3
// favorable, 4 auspicious - the -1 applies only in the ill omen band, and
// there only if the advice is ignored (the diaIllOmenIgnorePenalty pin); the
// other bands carry no party to hit modifier
inline int diaPartyHit(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 0;
        }
    }

// the party saving throw modifier by band (print p. 117; compressed pp.
// 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2
// neutral, 3 favorable, 4 auspicious - the -1 in the ill omen band (again
// only if the advice is ignored) and the +1 in the auspicious band; great
// danger, neutral and favorable carry none
inline int diaPartySave(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        default:
            return 0;
        }
    }

// the foe to hit modifier by band (print p. 117; compressed pp. 59-60). The
// band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3
// favorable, 4 auspicious - the adversaries gain +1 in the great danger band
// and suffer -1 against the characters in the favorable and auspicious bands;
// the ill omen and neutral bands carry none
inline int diaFoeHit(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return -1;
        case 4:
            return -1;
        default:
            return 0;
        }
    }

// the encounter chance multiplier by band (print p. 117; compressed pp.
// 59-60). The band list rides this comment: 0 ill omen, 1 great danger, 2
// neutral, 3 favorable, 4 auspicious - the chance for encounters is doubled
// in the ill omen and great danger bands (pinned 2), the other three bands
// the normal 1
inline int diaEncMult(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        default:
            return 0;
        }
    }

// the reaction modifier by band (print p. 117; compressed pp. 59-60). The
// band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3
// favorable, 4 auspicious - the -10 reaction modifier (pinned as a
// percentage, the diaReactionPenaltyPct const) applies to all encounters in
// the ill omen and great danger bands; the other bands carry none
inline int diaReaction(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -10;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            return 0;
        }
    }

// the travel rate boost by band (print p. 117; compressed pp. 59-60). The
// band list rides this comment: 0 ill omen, 1 great danger, 2 neutral, 3
// favorable, 4 auspicious - the favorable and auspicious bands travel at half
// again their normal traveling rate that day (pinned 1, the +50 percent
// riding the diaTravelBoostPct const); the other bands carry none
inline int diaTravel(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
