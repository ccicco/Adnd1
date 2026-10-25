    // ---- R763 OA Wa audit ----
    // OA round one hundred fifty (capture p. 304): the island of Wa - the
    // unified military state, the honorary emperor, the shogun of the
    // Hidetomi family, the fief system of the daimyos, the samurai stipend of
    // rice, the walled wards, single-pass pins per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlySocialClassCount() != 4
            || !dlyUnifiedMilitaryState()
            || !dlyEmperorHonorary()
            || !dlyShogunRealPower()
            || !dlyBarbarianSuppressingGeneral()
            || !dlyShogunHidetomiFamily()
            || !dlyFiefsGrantedByShogun()
            || !dlyDaimyoPerFief()
            || !dlyDaimyoTotalControl()
            || !dlyCourtLimitedScope()
            || !dlyConfiscateAndResettle()
            || !dlyDaimyoServiceAndAdmin()
            || !dlyWarriorStatusRaised()
            || !dlySamuraiStipendOfRice()
            || !dlySamuraiAbsoluteService()
            || !dlySocialClassLadder()
            || !dlyRigidClassLaws()
            || !dlyWalledWards()
            || !dlyArmedGatesNightCurfew()
            || !dlySamuraiPrivileges()
            || !dlyTravelStrictlyControlled()
            || !dlyPreventRebellionIntent()
        )
            ++bad;
        // the state example
    if (dlyUnifiedMilitaryState() != 1
            || dlyEmperorHonorary() != 1
            || dlyShogunRealPower() != 1
        )
            ++bad;
        // the shogun example
    if (dlyBarbarianSuppressingGeneral() != 1
            || dlyShogunHidetomiFamily() != 1
            || dlyConfiscateAndResettle() != 1
        )
            ++bad;
        // the fief example
    if (dlyFiefsGrantedByShogun() != 1
            || dlyDaimyoPerFief() != 1
            || dlyDaimyoTotalControl() != 1
        )
            ++bad;
        // the court example
    if (dlyCourtLimitedScope() != 1
            || dlyDaimyoServiceAndAdmin() != 1
        )
            ++bad;
        // the warrior example
    if (dlyWarriorStatusRaised() != 1
            || dlySamuraiStipendOfRice() != 1
            || dlySamuraiAbsoluteService() != 1
        )
            ++bad;
        // the class example
    if (dlySocialClassCount() != 4
            || dlySocialClassLadder() != 1
            || dlyRigidClassLaws() != 1
        )
            ++bad;
        // the city example
    if (dlyWalledWards() != 1
            || dlyArmedGatesNightCurfew() != 1
            || dlySamuraiPrivileges() != 1
        )
            ++bad;
        // the intent example
    if (dlyTravelStrictlyControlled() != 1
            || dlyPreventRebellionIntent() != 1
        )
            ++bad;
        printf("R763 OA Wa audit: bad %d\n", bad);
        if (bad) return 1;
    }
