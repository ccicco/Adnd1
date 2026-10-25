    // ---- R423: the UA appendix S
    // pantheon prose pin audit ----
    // The five intro sections pin
    // (rules/uapantheon.h, prefix
    // uapn) with the censuses
    // cross-checked LIVE against
    // the R405 seam: the five
    // described counts mirror
    // nhdPantheonSize row for row
    // and the sum mirrors the 23
    // deity census; the Moradin
    // height, the size minimum,
    // the never-living symbols and
    // the dual charismas mirror
    // their seam functions.
    {
        using namespace rules;
        int bad = 0;
        // the dwarven intro
        if (!uapnDwarfIntroPowerful()
                || !uapnDwarfMoradinTallest()
                || !uapnDwarfDemigodNormalH()
                || !uapnDwarfSymbolNoLife()
                || !uapnDwarfNoRaceAbove()
                || !uapnDwarfNoDwarfWorship()
                || !uapnDwarfDualCharisma()
                || !uapnDwarfCrossIsSmith())
            ++bad;
        if (uapnDwarfGreaterSizeMin() != 2
                || uapnDwarfMoradinFeet() != 20
                || uapnDwarfSymbolCats() != 4
                || uapnDwarfDescribed() != 5
                || uapnDwarfSpheres() != 10
                || uapnDwarfSpheresAbsent() != 6
                || uapnDwarfCrossMythos() != 2)
            ++bad;
        // the elven intro
        if (!uapnElfHomeArvandor()
                || !uapnElfCollectiveName()
                || !uapnElfFellowship()
                || !uapnElfSoleGreater()
                || !uapnElfNoneEvil()
                || !uapnElfSkerritExample()
                || !uapnElfColorReads()
                || !uapnElfLolthDrowSeam()
                || !uapnElfSmallOwnGods()
                || !uapnElfHalfElfCleric()
                || !uapnElfHalfElfHanali())
            ++bad;
        if (uapnElfLawfulMax() != 3
                || uapnElfHeightMin() != 4
                || uapnElfHeightMax() != 8
                || uapnElfDescribed() != 5
                || uapnElfSpheres() != 15
                || uapnElfSpheresAbsent() != 5
                || uapnElfDeathMax() != 2)
            ++bad;
        if (uapnElfCorellonCompels())
            ++bad;
        // the halfling intro
        if (!uapnHalfYondallaTop()
                || !uapnHalfBrandobarisLoose()
                || !uapnHalfPledged()
                || !uapnHalfGreenFields()
                || !uapnHalfBrandobarisRoams()
                || !uapnHalfGreekCompare()
                || !uapnHalfPowerFemale()
                || !uapnHalfNotAggressive()
                || !uapnHalfYondallaFuneral()
                || !uapnHalfUrogalanNeutral()
                || !uapnHalfUrogalanEarth()
                || !uapnHalfUrogalanConcord())
            ++bad;
        if (uapnHalfGreaterCount() != 1
                || uapnHalfWorshipMax() != 5
                || uapnHalfConcordantMin() != 2
                || uapnHalfSpheres() != 11
                || uapnHalfSpheresAbsent() != 5
                || uapnHalfDescribed() != 4)
            ++bad;
        // the gnomish intro
        if (!uapnGnomeFewest()
                || !uapnGnomeGarlException()
                || !uapnGnomeGoldenHills()
                || !uapnGnomeUrdlenAbyss()
                || !uapnGnomeAllMasculine()
                || !uapnGnomeUrdlenSexless()
                || !uapnGnomeUrdlenNoFriends()
                || !uapnGnomePranks()
                || !uapnGnomeDwarfContact())
            ++bad;
        if (uapnGnomeCountMin() != 6
                || uapnGnomeCountMax() != 7
                || uapnGnomeCompanions() != 3
                || uapnGnomeDescribed() != 4)
            ++bad;
        // the orcish intro
        if (!uapnOrcLotTale()
                || !uapnOrcWarForWrath()
                || !uapnOrcCorellonFailed()
                || !uapnOrcGruumshFirst()
                || !uapnOrcHateElvesMost()
                || !uapnOrcDwarfConflict()
                || !uapnOrcNineHells()
                || !uapnOrcTribeSymbol()
                || !uapnOrcGruumshTop()
                || !uapnOrcTribalWarfare()
                || !uapnOrcClericIncludes())
            ++bad;
        if (uapnOrcLotRaces() != 5
                || uapnOrcHabitatClaims() != 3
                || uapnOrcTribeNames() != 3
                || uapnOrcSphereExamples() != 7
                || uapnOrcDescribed() != 5)
            ++bad;
        // the LIVE seam mirrors
        // (the R405/R406 pattern)
        if (uapnDwarfDescribed()
                != nhdPantheonSize(0)
                || uapnElfDescribed()
                != nhdPantheonSize(1)
                || uapnHalfDescribed()
                != nhdPantheonSize(2)
                || uapnGnomeDescribed()
                != nhdPantheonSize(3)
                || uapnOrcDescribed()
                != nhdPantheonSize(4))
            ++bad;
        if (uapnDwarfDescribed()
                + uapnElfDescribed()
                + uapnHalfDescribed()
                + uapnGnomeDescribed()
                + uapnOrcDescribed()
                != nhdDeityCount())
            ++bad;
        if (uapnDwarfMoradinFeet()
                != nhdMoradinHeightFeet()
                || uapnDwarfGreaterSizeMin()
                != nhdGreaterDwarfSizeMultiple()
                || !uapnDwarfSymbolNoLife()
                != !nhdDwarfSymbolNeverLiving()
                || !uapnDwarfDualCharisma()
                != !nhdDwarfDeityDualCharisma())
            ++bad;
        if (uapnElfHeightMin()
                >= uapnElfHeightMax()
                || uapnGnomeCountMin()
                > uapnGnomeCountMax())
            ++bad;
        printf("R423 UA appendix S pantheon prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
