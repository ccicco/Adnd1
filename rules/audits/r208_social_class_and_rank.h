    // ---- R208: the social class and rank audit ----
    // DMG pp.88-89: the government forms,
    // the worked example aristocracy, the
    // town and city social structure and
    // offices, the knights and the noble
    // title ladders.
    {
        Socialrank socialrank;
        int bad = 0;
        // the government forms: 19 named,
        // each with its print definition trait
        if (socialrank.govFormCount() != 19) ++bad;
        static const int kTrait[19] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 11, 12, 13, 14, 15, 16, 17, 18,
        };
        for (int f = 0; f < 19; ++f)
            if (socialrank.govFormTrait(f) != kTrait[f]) ++bad;
        // the distinctive definitions, pinned
        if (socialrank.govFormTrait(GOV_GYNARCHY)
                != GOVT_FEMALES_ONLY ||
            socialrank.govFormTrait(GOV_MATRIARCHY)
                != GOVT_ELDEST_FEMALES) ++bad;
        if (socialrank.govFormTrait(GOV_THEOCRACY)
                != GOVT_GOD_RULE) ++bad;
        if (socialrank.govFormTrait(GOV_MAGOCRACY)
                != GOVT_MAGIC_USERS_ONLY ||
            socialrank.govFormTrait(GOV_PLUTOCRACY)
                != GOVT_THE_WEALTHY) ++bad;
        if (socialrank.govFormTrait(GOV_PEDOCRACY)
                != GOVT_THE_LEARNED ||
            socialrank.govFormTrait(GOV_GERIATOCRACY)
                != GOVT_ELDERLY_ONLY) ++bad;
        if (socialrank.govFormTrait(GOV_SYNDICRACY)
                != GOVT_SYNDICS_BUSINESS) ++bad;
        if (socialrank.govFormTrait(GOV_FEUDALITY)
                != GOVT_LAYERED_FEALTY ||
            socialrank.govFormTrait(GOV_HIERARCHY)
                != GOVT_RELIGIOUS_LIKE_FEUDAL) ++bad;
        if (socialrank.govFormTrait(GOV_MONARCHY)
                != GOVT_SINGLE_HEREDITARY_SOVEREIGN
            || socialrank.govFormTrait(GOV_OLIGARCHY)
                != GOVT_FEW_COEQUAL) ++bad;
        // the worked example aristocracy: all
        // three - service, land, income tax
        if (!socialrank.aristocratEligible(true, 100, 10) ||
            socialrank.aristocratEligible(false, 100, 10) ||
            socialrank.aristocratEligible(true, 99, 10) ||
            socialrank.aristocratEligible(true, 100, 9) ||
            !socialrank.aristocratEligible(true, 500, 50))
            ++bad;
        // the merchant waiver: land waived at
        // 20 gold pieces of annual business tax
        if (!socialrank.aristocratMerchantEligible(true, 20) ||
            socialrank.aristocratMerchantEligible(true, 19) ||
            !socialrank.aristocratMerchantEligible(true, 100) ||
            socialrank.aristocratMerchantEligible(false, 20))
            ++bad;
        // the offices: aristocrats only; the
        // senate from their number; tribunals
        // from former senators; the police
        // appointment from former officers
        if (!socialrank.officeEligible(true) ||
            socialrank.officeEligible(false) ||
            !socialrank.senateEligible(true) ||
            socialrank.senateEligible(false)) ++bad;
        if (!socialrank.tribunalEligible(true) ||
            socialrank.tribunalEligible(false) ||
            !socialrank.policeAppointedFrom(true) ||
            socialrank.policeAppointedFrom(false)) ++bad;
        // the town classes: three, and what
        // each draws
        if (socialrank.townClassCount() != 3) ++bad;
        if (!socialrank.townDrawsImportantLawmakers(
                TOWN_UPPER) ||
            socialrank.townDrawsImportantLawmakers(
                TOWN_MIDDLE) ||
            socialrank.townDrawsImportantLawmakers(
                TOWN_LOWER)) ++bad;
        if (!socialrank.townProvidesLesserOfficials(
                TOWN_MIDDLE) ||
            socialrank.townProvidesLesserOfficials(
                TOWN_UPPER) ||
            socialrank.townProvidesLesserOfficials(
                TOWN_LOWER)) ++bad;
        if (!socialrank.townDrawsCommonCouncil(
                TOWN_LOWER) ||
            socialrank.townDrawsCommonCouncil(
                TOWN_UPPER) ||
            socialrank.townDrawsCommonCouncil(
                TOWN_MIDDLE)) ++bad;
        // the mayor: three titles, lifetime,
        // upper class only
        if (socialrank.mayorTitleCount() != 3 ||
            !socialrank.mayorOfficeLifetime() ||
            socialrank.mayorOfficeSourceClass()
                != TOWN_UPPER) ++bad;
        // the aldermen: three titles, chosen by
        // the upper class as major officers,
        // elected by the middle class
        if (socialrank.aldermanTitleCount() != 3 ||
            !socialrank.aldermenChosenBy(TOWN_UPPER) ||
            socialrank.aldermenChosenBy(TOWN_MIDDLE) ||
            socialrank.aldermenChosenBy(TOWN_LOWER) ||
            !socialrank.aldermenElectedBy(TOWN_MIDDLE) ||
            socialrank.aldermenElectedBy(TOWN_UPPER))
            ++bad;
        // the strata: judiciary and military
        // command upper; law, customs and tax
        // officials middle
        if (socialrank.townJudiciaryStratum()
                != TOWN_UPPER ||
            socialrank.townMilitaryCommandStratum()
                != TOWN_UPPER) ++bad;
        if (socialrank.lawEnforcementSourceClass()
                != TOWN_MIDDLE ||
            socialrank.customsOfficialSourceClass()
                != TOWN_MIDDLE ||
            socialrank.taxOfficialSourceClass()
                != TOWN_MIDDLE) ++bad;
        // the councilors: selected by upper
        // and middle and the free lower; petty
        // officials lower, administrative only
        if (!socialrank.councilorSelectedBy(
                TOWN_UPPER) ||
            !socialrank.councilorSelectedBy(
                TOWN_MIDDLE) ||
            socialrank.councilorSelectedBy(
                TOWN_LOWER)) ++bad;
        if (!socialrank.councilorSelectedByLower(true) ||
            socialrank.councilorSelectedByLower(false) ||
            socialrank.pettyOfficialsSourceClass()
                != TOWN_LOWER ||
            !socialrank.pettyOfficialRoleAdministrative())
            ++bad;
        // the constabulary: citizen soldiers,
        // watch or police, militia in great
        // need; the bulk hired mercenaries
        if (!socialrank.constabularyIncludesCitizenSoldiers() ||
            !socialrank.constabularyIncludesWatchOrPolice() ||
            !socialrank.militiaCalledInGreatNeed() ||
            !socialrank.soldieryBulkMercenaries()) ++bad;
        // the knights: non-hereditary peers,
        // precedence varying by order
        if (socialrank.knightsHereditary() ||
            !socialrank.knightPrecedenceVariesByOrder())
            ++bad;
        // the northern European ladder: 10
        // secular titles, emperor highest,
        // knight lowest; duke precedes prince
        // per the print table
        if (socialrank.nobleTitleRNCount() != 10 ||
            socialrank.nobleTitleRNPrecedence(
                NT_EMPEROR) != 0 ||
            socialrank.nobleTitleRNPrecedence(
                NT_KING) != 1 ||
            socialrank.nobleTitleRNPrecedence(
                NT_DUKE) != 2 ||
            socialrank.nobleTitleRNPrecedence(
                NT_PRINCE) != 3 ||
            socialrank.nobleTitleRNPrecedence(
                NT_MARQUIS) != 4 ||
            socialrank.nobleTitleRNPrecedence(
                NT_COUNT_EARL) != 5 ||
            socialrank.nobleTitleRNPrecedence(
                NT_VISCOUNT) != 6 ||
            socialrank.nobleTitleRNPrecedence(
                NT_BARON_THANE) != 7 ||
            socialrank.nobleTitleRNPrecedence(
                NT_BARONET) != 8 ||
            socialrank.nobleTitleRNPrecedence(
                NT_KNIGHT) != 9) ++bad;
        // the ecclesiastical ranks among the
        // nobility: archbishop, bishop, abbot,
        // prior
        if (socialrank.ecclesiasticalRanksAmongNobility() != 4)
            ++bad;
        // the German equivalents: seven mapped
        if (socialrank.germanEquivalentCount() != 7 ||
            socialrank.germanEquivalentOf(NT_KNIGHT)
                != GT_RITTER ||
            socialrank.germanEquivalentOf(NT_EMPEROR)
                != -1 ||
            socialrank.germanEquivalentOf(NT_DUKE)
                != GT_PFALZGRAF ||
            socialrank.germanEquivalentOf(NT_PRINCE)
                != GT_HERZOG ||
            socialrank.germanEquivalentOf(NT_BARON_THANE)
                != -1) ++bad;
        // the Asian titles: twenty listed
        if (socialrank.asianTitleCount() != 20) ++bad;
        printf("R208 social class and rank audit: bad %d\n", bad);
        if (bad) return 1;
    }
