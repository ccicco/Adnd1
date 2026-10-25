    // ---- R686 OA subduing audit ----
    // OA round seventy-three (capture pp. 221-222): the Subduing Opponents
    // doctrine - the intelligence gate, the quarter damage split with the
    // starting-hit-point surrender threshold, the normal-damage voiding, the
    // oath mechanics and the captive clause, single-pass pins per the Chapter
    // 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dizOASubdualHitLossNum() != 1
            || dizOASubdualHitLossDen() != 4
            || dizOASubdualDamageNum() != 3
            || dizOASubdualDamageDen() != 4
            || !dizOASubdualDoctrine()
            || !dizOASubdualIntelligenceGate()
            || !dizOASubdualGeniusVoluntary()
            || !dizOASubdualAnyCreature()
            || !dizOASubdualPCNeverForced()
            || !dizOASubdualMustDeclare()
            || !dizOASubdualDamageNormal()
            || !dizOASubdualRecordedSeparately()
            || !dizOASubdualSurrenderAtStartHP()
            || !dizOASubdualNormalDamageVoids()
            || !dizOASubduedMustStop()
            || !dizOASubdualOathCheck()
            || !dizOASubdualCaptiveEscape()
        )
            ++bad;
        // the quarter split - the 1/4 hit-point loss against the 3/4 subdual
        // share
    if (dizOASubdualHitLossNum() != 1
            || dizOASubdualHitLossDen() != 4
            || dizOASubdualDamageNum() != 3
            || dizOASubdualDamageDen() != 4
        )
            ++bad;
        // the split integrity - the two shares summing to the whole
    if (dizOASubdualHitLossNum() + dizOASubdualDamageNum() !=
        dizOASubdualHitLossDen()
        )
            ++bad;
        printf("R686 OA subduing audit: bad %d\n", bad);
        if (bad) return 1;
    }
