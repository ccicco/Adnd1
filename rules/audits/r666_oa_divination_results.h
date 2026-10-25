    // ---- R666 OA divination results audit ----
    // OA round fifty-three (capture p. 117): Table 63 - the divination
    // results of the omen spell, the five 1d10 bands with their mechanical
    // modifiers, cross-checked between the passes
    {
        using namespace rules;
        int bad = 0;
    if (diaBandCount() != 5
            || diaDieFaces() != 10
            || diaNeutralFaces() != 3
            || diaIllOmenBand() != 0
            || diaGreatDangerBand() != 1
            || diaNeutralBand() != 2
            || diaFavorableBand() != 3
            || diaAuspiciousBand() != 4
            || diaDoubledEncounterBands() != 2
            || diaReactionPenaltyPct() != 10
            || diaFavorableSaveBonus() != 1
            || diaTravelBoostPct() != 50
            || diaIllOmenIgnorePenalty() != 1
            || diaOmenWeeklyLimit() != 1
        )
            ++bad;
        // the divination results grid: the party, foe, encounter, reaction,
        // save and travel modifiers by omen band
        int CT63Data[5][6] = {
            {-1,-1,0,2,-10,0},
            {0,0,1,2,-10,0},
            {0,0,0,1,0,0},
            {0,0,-1,1,0,1},
            {0,1,-1,1,0,1},
            };
        for (int b = 0;
             b < diaBandCount();
             ++b) {
            int vals[6];
            vals[0] = diaPartyHit(b);
            vals[1] = diaPartySave(b);
            vals[2] = diaFoeHit(b);
            vals[3] = diaEncMult(b);
            vals[4] = diaReaction(b);
            vals[5] = diaTravel(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT63Data[b][c])
                    ++bad;
            }
        }
        // the diaOmenBand band-for boundaries
    if (diaOmenBand(1) != 0
            || diaOmenBand(2) != 0
            || diaOmenBand(4) != 1
            || diaOmenBand(3) != 1
            || diaOmenBand(7) != 2
            || diaOmenBand(5) != 2
            || diaOmenBand(9) != 3
            || diaOmenBand(8) != 3
            || diaOmenBand(10) != 4
        )
            ++bad;
        // the count pins - five bands, the 1d10 faces, the neutral band the
        // widest at three faces, the two doubled encounter bands
    if (diaBandCount() != 5
            || diaDieFaces() != 10
            || diaNeutralFaces() != 3
            || diaDoubledEncounterBands() != 2
        )
            ++bad;
        // the band ordinal pins - ill omen 0, great danger 1, neutral 2,
        // favorable 3, auspicious 4
    if (diaIllOmenBand() != 0
            || diaGreatDangerBand() != 1
            || diaNeutralBand() != 2
            || diaFavorableBand() != 3
            || diaAuspiciousBand() != 4
        )
            ++bad;
        // the chain pins - the die roll mapped to its band: 1 and 2 the ill
        // omen band 0, 3 and 4 the great danger band 1, 5 through 7 the
        // neutral band 2, 8 and 9 the favorable band 3, 10 the auspicious
        // band 4
    if (diaOmenBand(1) != 0
            || diaOmenBand(2) != 0
            || diaOmenBand(3) != 1
            || diaOmenBand(4) != 1
            || diaOmenBand(5) != 2
            || diaOmenBand(7) != 2
            || diaOmenBand(8) != 3
            || diaOmenBand(9) != 3
            || diaOmenBand(10) != 4
        )
            ++bad;
        // the party modifier pins - the ill omen to hit and save penalties
        // (the ignored advice); the auspicious save bonus; great danger,
        // neutral and favorable carry none
    if (diaPartyHit(0) != -1
            || diaPartySave(0) != -1
            || diaPartySave(4) != 1
            || diaPartyHit(1) != 0
            || diaPartySave(1) != 0
            || diaPartyHit(2) != 0
            || diaPartySave(3) != 0
        )
            ++bad;
        // the foe to hit pins - the adversaries +1 in the great danger band,
        // -1 against the characters in the favorable and auspicious bands,
        // none in the ill omen and neutral bands
    if (diaFoeHit(1) != 1
            || diaFoeHit(3) != -1
            || diaFoeHit(4) != -1
            || diaFoeHit(0) != 0
            || diaFoeHit(2) != 0
        )
            ++bad;
        // the encounter and reaction pins - the chance doubled and the -10
        // reaction modifier in the ill omen and great danger bands, normal in
        // the other three
    if (diaEncMult(0) != 2
            || diaEncMult(1) != 2
            || diaEncMult(2) != 1
            || diaEncMult(3) != 1
            || diaEncMult(4) != 1
            || diaReaction(0) != -10
            || diaReaction(1) != -10
            || diaReaction(2) != 0
            || diaReaction(4) != 0
        )
            ++bad;
        // the travel pins - the boost in the favorable and auspicious bands,
        // none in the other three; the modifier consts - the +50 percent
        // travel boost, the -10 reaction percentage, the auspicious save
        // bonus and the ill omen ignored penalty
    if (diaTravel(3) != 1
            || diaTravel(4) != 1
            || diaTravel(0) != 0
            || diaTravel(2) != 0
            || diaTravelBoostPct() != 50
            || diaReactionPenaltyPct() != 10
            || diaFavorableSaveBonus() != 1
            || diaIllOmenIgnorePenalty() != 1
        )
            ++bad;
        // the weekly limit pin - the omen spell usable once per week
    if (diaOmenWeeklyLimit() != 1
        )
            ++bad;
        printf("R666 OA divination results audit: bad %d\n", bad);
        if (bad) return 1;
    }
