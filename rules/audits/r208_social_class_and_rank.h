    // ---- R208: the social class and rank audit ----
    // DMG pp.88-89: the government forms,
    // the worked example aristocracy, the
    // town and city social structure and
    // offices, the knights and the noble
    // title ladders.
    {
        int bad = 0;
        // the government forms: 19 named,
        // each with its print definition trait
        if (rules::govFormCount() != 19) ++bad;
        static const int kTrait[19] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 11, 12, 13, 14, 15, 16, 17, 18,
        };
        for (int f = 0; f < 19; ++f)
            if (rules::govFormTrait(f) != kTrait[f]) ++bad;
        // the distinctive definitions, pinned
        if (rules::govFormTrait(rules::GOV_GYNARCHY)
                != rules::GOVT_FEMALES_ONLY ||
            rules::govFormTrait(rules::GOV_MATRIARCHY)
                != rules::GOVT_ELDEST_FEMALES) ++bad;
        if (rules::govFormTrait(rules::GOV_THEOCRACY)
                != rules::GOVT_GOD_RULE) ++bad;
        if (rules::govFormTrait(rules::GOV_MAGOCRACY)
                != rules::GOVT_MAGIC_USERS_ONLY ||
            rules::govFormTrait(rules::GOV_PLUTOCRACY)
                != rules::GOVT_THE_WEALTHY) ++bad;
        if (rules::govFormTrait(rules::GOV_PEDOCRACY)
                != rules::GOVT_THE_LEARNED ||
            rules::govFormTrait(rules::GOV_GERIATOCRACY)
                != rules::GOVT_ELDERLY_ONLY) ++bad;
        if (rules::govFormTrait(rules::GOV_SYNDICRACY)
                != rules::GOVT_SYNDICS_BUSINESS) ++bad;
        if (rules::govFormTrait(rules::GOV_FEUDALITY)
                != rules::GOVT_LAYERED_FEALTY ||
            rules::govFormTrait(rules::GOV_HIERARCHY)
                != rules::GOVT_RELIGIOUS_LIKE_FEUDAL) ++bad;
        if (rules::govFormTrait(rules::GOV_MONARCHY)
                != rules::GOVT_SINGLE_HEREDITARY_SOVEREIGN
            || rules::govFormTrait(rules::GOV_OLIGARCHY)
                != rules::GOVT_FEW_COEQUAL) ++bad;
        // the worked example aristocracy: all
        // three - service, land, income tax
        if (!rules::aristocratEligible(true, 100, 10) ||
            rules::aristocratEligible(false, 100, 10) ||
            rules::aristocratEligible(true, 99, 10) ||
            rules::aristocratEligible(true, 100, 9) ||
            !rules::aristocratEligible(true, 500, 50))
            ++bad;
        // the merchant waiver: land waived at
        // 20 gold pieces of annual business tax
        if (!rules::aristocratMerchantEligible(true, 20) ||
            rules::aristocratMerchantEligible(true, 19) ||
            !rules::aristocratMerchantEligible(true, 100) ||
            rules::aristocratMerchantEligible(false, 20))
            ++bad;
        // the offices: aristocrats only; the
        // senate from their number; tribunals
        // from former senators; the police
        // appointment from former officers
        if (!rules::officeEligible(true) ||
            rules::officeEligible(false) ||
            !rules::senateEligible(true) ||
            rules::senateEligible(false)) ++bad;
        if (!rules::tribunalEligible(true) ||
            rules::tribunalEligible(false) ||
            !rules::policeAppointedFrom(true) ||
            rules::policeAppointedFrom(false)) ++bad;
        // the town classes: three, and what
        // each draws
        if (rules::townClassCount() != 3) ++bad;
        if (!rules::townDrawsImportantLawmakers(
                rules::TOWN_UPPER) ||
            rules::townDrawsImportantLawmakers(
                rules::TOWN_MIDDLE) ||
            rules::townDrawsImportantLawmakers(
                rules::TOWN_LOWER)) ++bad;
        if (!rules::townProvidesLesserOfficials(
                rules::TOWN_MIDDLE) ||
            rules::townProvidesLesserOfficials(
                rules::TOWN_UPPER) ||
            rules::townProvidesLesserOfficials(
                rules::TOWN_LOWER)) ++bad;
        if (!rules::townDrawsCommonCouncil(
                rules::TOWN_LOWER) ||
            rules::townDrawsCommonCouncil(
                rules::TOWN_UPPER) ||
            rules::townDrawsCommonCouncil(
                rules::TOWN_MIDDLE)) ++bad;
        // the mayor: three titles, lifetime,
        // upper class only
        if (rules::mayorTitleCount() != 3 ||
            !rules::mayorOfficeLifetime() ||
            rules::mayorOfficeSourceClass()
                != rules::TOWN_UPPER) ++bad;
        // the aldermen: three titles, chosen by
        // the upper class as major officers,
        // elected by the middle class
        if (rules::aldermanTitleCount() != 3 ||
            !rules::aldermenChosenBy(rules::TOWN_UPPER) ||
            rules::aldermenChosenBy(rules::TOWN_MIDDLE) ||
            rules::aldermenChosenBy(rules::TOWN_LOWER) ||
            !rules::aldermenElectedBy(rules::TOWN_MIDDLE) ||
            rules::aldermenElectedBy(rules::TOWN_UPPER))
            ++bad;
        // the strata: judiciary and military
        // command upper; law, customs and tax
        // officials middle
        if (rules::townJudiciaryStratum()
                != rules::TOWN_UPPER ||
            rules::townMilitaryCommandStratum()
                != rules::TOWN_UPPER) ++bad;
        if (rules::lawEnforcementSourceClass()
                != rules::TOWN_MIDDLE ||
            rules::customsOfficialSourceClass()
                != rules::TOWN_MIDDLE ||
            rules::taxOfficialSourceClass()
                != rules::TOWN_MIDDLE) ++bad;
        // the councilors: selected by upper
        // and middle and the free lower; petty
        // officials lower, administrative only
        if (!rules::councilorSelectedBy(
                rules::TOWN_UPPER) ||
            !rules::councilorSelectedBy(
                rules::TOWN_MIDDLE) ||
            rules::councilorSelectedBy(
                rules::TOWN_LOWER)) ++bad;
        if (!rules::councilorSelectedByLower(true) ||
            rules::councilorSelectedByLower(false) ||
            rules::pettyOfficialsSourceClass()
                != rules::TOWN_LOWER ||
            !rules::pettyOfficialRoleAdministrative())
            ++bad;
        // the constabulary: citizen soldiers,
        // watch or police, militia in great
        // need; the bulk hired mercenaries
        if (!rules::constabularyIncludesCitizenSoldiers() ||
            !rules::constabularyIncludesWatchOrPolice() ||
            !rules::militiaCalledInGreatNeed() ||
            !rules::soldieryBulkMercenaries()) ++bad;
        // the knights: non-hereditary peers,
        // precedence varying by order
        if (rules::knightsHereditary() ||
            !rules::knightPrecedenceVariesByOrder())
            ++bad;
        // the northern European ladder: 10
        // secular titles, emperor highest,
        // knight lowest; duke precedes prince
        // per the print table
        if (rules::nobleTitleRNCount() != 10 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_EMPEROR) != 0 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_KING) != 1 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_DUKE) != 2 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_PRINCE) != 3 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_MARQUIS) != 4 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_COUNT_EARL) != 5 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_VISCOUNT) != 6 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_BARON_THANE) != 7 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_BARONET) != 8 ||
            rules::nobleTitleRNPrecedence(
                rules::NT_KNIGHT) != 9) ++bad;
        // the ecclesiastical ranks among the
        // nobility: archbishop, bishop, abbot,
        // prior
        if (rules::ecclesiasticalRanksAmongNobility() != 4)
            ++bad;
        // the German equivalents: seven mapped
        if (rules::germanEquivalentCount() != 7 ||
            rules::germanEquivalentOf(rules::NT_KNIGHT)
                != rules::GT_RITTER ||
            rules::germanEquivalentOf(rules::NT_EMPEROR)
                != -1 ||
            rules::germanEquivalentOf(rules::NT_DUKE)
                != rules::GT_PFALZGRAF ||
            rules::germanEquivalentOf(rules::NT_PRINCE)
                != rules::GT_HERZOG ||
            rules::germanEquivalentOf(rules::NT_BARON_THANE)
                != -1) ++bad;
        // the Asian titles: twenty listed
        if (rules::asianTitleCount() != 20) ++bad;
        printf("R208 social class and rank audit: bad %d\n", bad);
        if (bad) return 1;
    }
