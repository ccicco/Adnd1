    // ---- R684 OA unhorsing audit ----
    // OA round seventy-one (capture pp. 220-221): the Unhorsing doctrine -
    // the slain-mount rule, the mounted natural-20 unhorsing with the
    // horsemanship proficiency check, the foot-soldier weapon bands, the
    // grapple doctrine, the footman pull ladder and the set defenses with the
    // stake line, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dixOAUnhorseMountedWeaponMinFeet() != 3
            || dixOAUnhorseFallDamageDice() != 3
            || dixOAUnhorseFootShortMinFeet() != 5
            || dixOAUnhorseFootShortMaxFeet() != 9
            || dixOAUnhorseFootLongMinFeet() != 10
            || dixOAUnhorseLongChancePercent() != 25
            || dixOAUnhorseLongRollMin() != 16
            || dixOAUnhorseGrappleFallDamageDice() != 6
            || dixOAUnhorseGrappleRiderHitPenalty() != -2
            || dixOAUnhorsePullSpeed6Penalty() != -2
            || dixOAUnhorsePullSpeed7Penalty() != -4
            || dixOAUnhorsePullSpeed13Penalty() != -6
            || dixOAUnhorsePullExtraFootmanPenalty() != -1
            || dixOAUnhorsePullMaxFootmen() != 4
            || dixOAUnhorseSurroundMen() != 8
            || dixOAStakesPrepMen() != 2
            || dixOAStakesPrepAreaFeet() != 10
            || dixOAStakesLengthMinFeet() != 4
            || dixOAStakesLengthMaxFeet() != 5
            || dixOAStakesDamageDice() != 6
            || dixOAStakesChainReduction() != 1
            || dixOAStakesPlateReduction() != 2
            || !dixOAUnhorseDoctrine()
            || !dixOAUnhorseSlainMountAuto()
            || !dixOAUnhorseProficiencyCheck()
            || !dixOAUnhorseGrappleEveryTurn()
            || !dixOAUnhorseGrappleHangOn()
            || !dixOAUnhorsePullManSizedOnly()
            || !dixOAUnhorsePullNoDamage()
            || !dixOAUnhorsePullFreeAttacks()
            || !dixOAUnhorseNormalAttacks()
            || !dixOAUnhorseSetDefenses()
            || !dixOAStakesJumpCheck()
            || !dixOAUnhorseOtherCreaturesApply()
        )
            ++bad;
        // the mounted unhorsing pins - the 3-feet weapon floor with the 1d3
        // fall damage
    if (dixOAUnhorseMountedWeaponMinFeet() != 3
            || dixOAUnhorseFallDamageDice() != 3
        )
            ++bad;
        // the foot-soldier bands - the 5-to-9 short band and the 10-feet long
        // band
    if (dixOAUnhorseFootShortMinFeet() != 5
            || dixOAUnhorseFootShortMaxFeet() != 9
            || dixOAUnhorseFootLongMinFeet() != 10
        )
            ++bad;
        // the long-band chance - the 25 percent riding the 16-20 of 1d20
    if (dixOAUnhorseLongChancePercent() != 25
            || dixOAUnhorseLongRollMin() != 16
        )
            ++bad;
        // the grapple pins - the 1d6 fall damage and the -2 rider penalty
    if (dixOAUnhorseGrappleFallDamageDice() != 6
            || dixOAUnhorseGrappleRiderHitPenalty() != -2
        )
            ++bad;
        // the footman pull ladder - the -2, -4 and -6 of the three speed
        // bands
    if (dixOAUnhorsePullSpeed6Penalty() != -2
            || dixOAUnhorsePullSpeed7Penalty() != -4
            || dixOAUnhorsePullSpeed13Penalty() != -6
        )
            ++bad;
        // the multi-footman pull - the -1 per extra man up to the 4 cap
    if (dixOAUnhorsePullExtraFootmanPenalty() != -1
            || dixOAUnhorsePullMaxFootmen() != 4
        )
            ++bad;
        // the surround rule - the eight men pulling both horse and rider down
    if (dixOAUnhorseSurroundMen() != 8
        )
            ++bad;
        // the stake defense - the two men, the 10-foot square, the 4-to-5
        // stakes
    if (dixOAStakesPrepMen() != 2
            || dixOAStakesPrepAreaFeet() != 10
            || dixOAStakesLengthMinFeet() != 4
        )
            ++bad;
        // the stake damage pins - the 2d6 per stake with the barding
        // reductions
    if (dixOAStakesDamageDice() != 6
            || dixOAStakesChainReduction() != 1
            || dixOAStakesPlateReduction() != 2
        )
            ++bad;
        printf("R684 OA unhorsing audit: bad %d\n", bad);
        if (bad) return 1;
    }
