    // ---- R738 OA standard item mods audit ----
    // OA round one hundred twenty-five (capture p. 286): the Modifications to
    // Standard Magical Items prose - the occidental items rule with the
    // gajin, curiosity, and caster sources, the form changes of the lyre,
    // cloak, boots, and bags, the DM form decision leaving function
    // untouched, the capture misreads pinned against the print, single-pass
    // pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkzGajinThreshold() != 3
            || dkzFormChangeCount() != 4
            || !dkzMajorityAvailable()
            || !dkzSomeParticularlyOccidental()
            || !dkzDoNotAppearNormally()
            || !dkzOrSomewhatDifferent()
            || !dkzLittleOrNoUse()
            || !dkzNotWithinCulture()
            || !dkzNotToSayCannotAppear()
            || !dkzConstructionFarFromCommon()
            || !dkzGeneralRuleIfAsPresented()
            || !dkzBroughtInByGajin()
            || !dkzImportedAsCuriosities()
            || !dkzAssembledByInspiredCaster()
            || !dkzGenerallyOccidentalForm()
            || !dkzLyreSamisenOrFlute()
            || !dkzCloakRobeOrJacket()
            || !dkzBootsSandals()
            || !dkzBagsBoxes()
            || !dkzDMDecidesForm()
            || !dkzFunctionUnaffected()
        )
            ++bad;
        // the first paragraph - the occidental items rule, healthy values,
        // each condition false
    if (dkzMajorityAvailable() != 1
            || dkzSomeParticularlyOccidental() != 1
            || dkzDoNotAppearNormally() != 1
            || dkzOrSomewhatDifferent() != 1
            || dkzLittleOrNoUse() != 1
            || dkzNotWithinCulture() != 1
            || dkzNotToSayCannotAppear() != 1
            || dkzConstructionFarFromCommon() != 1
        )
            ++bad;
        // the three sources - the gajin, the curiosity, and the caster,
        // healthy values, each condition false
    if (dkzGeneralRuleIfAsPresented() != 1
            || dkzBroughtInByGajin() != 1
            || dkzImportedAsCuriosities() != 1
            || dkzAssembledByInspiredCaster() != 1
            || dkzGajinThreshold() != 3
        )
            ++bad;
        // the second paragraph - the form changes and the function clause,
        // healthy values, each condition false
    if (dkzGenerallyOccidentalForm() != 1
            || dkzLyreSamisenOrFlute() != 1
            || dkzCloakRobeOrJacket() != 1
            || dkzBootsSandals() != 1
            || dkzBagsBoxes() != 1
            || dkzDMDecidesForm() != 1
            || dkzFunctionUnaffected() != 1
            || dkzFormChangeCount() != 4
        )
            ++bad;
        printf("R738 OA standard item mods audit: bad %d\n", bad);
        if (bad) return 1;
    }
