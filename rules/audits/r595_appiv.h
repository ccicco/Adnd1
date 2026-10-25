    // ---- R595 AppIV audit ----
    // APPENDIX IV: ABILITIES OF THE POWERS, printed pp. 124-126, the divine
    // ability ladder from the at-will standard set to the native-plane
    // heights: the four ability types (specialized to a named Power like
    // Zeus's roundly lightning bolt, standard at will to all, individual by
    // rank, native only on the home plane); the sixteen standard divine
    // abilities used at will (astral travel in physical or projected form,
    // command with no save for followers or believers, continual light and
    // darkness, the eight-part cure and twelve-part detect lists used one at
    // a time with the reverse spells and the undetectable lie, ethereal
    // travel with the Greater and Lesser crossing of living fields but no
    // emerging into occupied space, enlarge to 300%, geas, levitate,
    // polymorph self, protection from cantrips and from evil/good, the
    // no-failure cross-planar sending, teleport without error, the four-spell
    // understand languages, vocalize); the caster levels of magic use
    // 30/20/15 by Greater/Lesser/Demi rank unless the Power has a defined
    // level, the 4/3/2-round command durations, the 30/20/10-foot protection
    // radii; the individual abilities by intensity in the campaign day -
    // Greater: the at-will eight (atonement through regenerate), the
    // six-a-day fourteen (anti-magic shell through summon), the three-a-day
    // eleven (debth spell through holy/unholy word), no harmful side effects,
    // resurrection without rest, the 2d6 same-alignment summon capped at 40
    // hit dice; Lesser: alter self at will, four a day, two a day, the vision
    // servitude exception, the 1d6 summon of 30 hit dice; Demi: the three
    // at-will, three a day, one a day, affected by malefic side effects, the
    // 1d3 summon of 20 hit dice, the limited wish; the wish rules - Prime
    // inhabitants only, no other Power in his home plane, no effect on the
    // granting Power, violations void; and the native abilities - Greater:
    // six-a-day to at will, three to six, doubled hit points, the 120% domain
    // magic resistance, the always-on Astral and Border Ethereal senses, no
    // conjuration summoning or necromantic harm, unslayable at home turning
    // to sparkling vapor reforming in a tenth of a day, the hundred-year
    // slayer-plane ban and ten-year own-plane confinement, sealed color pools
    // and the forced pull, twenty spells of a hundred levels altered, the
    // silver cord cut at AC -5, the Aspect built in a tenth of a year;
    // Lesser: doubled hit points on the native layer, 100% resistance, the
    // conscious look, permanently slayable at home and hundred-year banished
    // abroad, twenty spells of eighty levels, the soul object of Orcus's
    // wand; Demi: the 80% personal resistance, the observe-only senses, the
    // reversible home-plane debth, the opaque pools, the attempted cord.
    {
        using namespace rules;
        int bad = 0;
    if (debGreaterMagicLevel() != 30
            || debGreaterCommandRounds() != 4
            || debLesserCommandRounds() != 3
            || debDemiCommandRounds() != 2
            || debProtectionRadiusGreater() != 30
            || debGreaterDailyLimit() != 6
            || debLesserDailyLimit() != 4
            || debDemiDailyLimit() != 3
            || debGreaterSummonDice() != 2
            || debGreaterSummonHD() != 40
            || debLesserSummonHD() != 30
            || debDemiSummonHD() != 20
            || !debAbilityTypes()
            || !debStandardAbilities()
            || !debCureDetectLists()
            || !debEtherealTravelRule()
            || !debWishRules()
            || !debGreaterNativePowers()
            || !debLesserNativePowers()
            || !debDemiNativePowers()
        )
            ++bad;
        // the GreaterMagicLevel pin
    if (debGreaterMagicLevel() != 30
        )
            ++bad;
        // the GreaterCommandRounds pin
    if (debGreaterCommandRounds() != 4
        )
            ++bad;
        // the LesserCommandRounds pin
    if (debLesserCommandRounds() != 3
        )
            ++bad;
        // the DemiCommandRounds pin
    if (debDemiCommandRounds() != 2
        )
            ++bad;
        // the ProtectionRadiusGreater pin
    if (debProtectionRadiusGreater() != 30
        )
            ++bad;
        // the GreaterDailyLimit pin
    if (debGreaterDailyLimit() != 6
        )
            ++bad;
        // the LesserDailyLimit pin
    if (debLesserDailyLimit() != 4
        )
            ++bad;
        // the DemiDailyLimit pin
    if (debDemiDailyLimit() != 3
        )
            ++bad;
        // the GreaterSummonDice pin
    if (debGreaterSummonDice() != 2
        )
            ++bad;
        // the GreaterSummonHD pin
    if (debGreaterSummonHD() != 40
        )
            ++bad;
        // the LesserSummonHD pin
    if (debLesserSummonHD() != 30
        )
            ++bad;
        // the DemiSummonHD pin
    if (debDemiSummonHD() != 20
        )
            ++bad;
        // the AbilityTypes pin
    if (debAbilityTypes() != 1
        )
            ++bad;
        // the StandardAbilities pin
    if (debStandardAbilities() != 1
        )
            ++bad;
        // the CureDetectLists pin
    if (debCureDetectLists() != 1
        )
            ++bad;
        // the EtherealTravelRule pin
    if (debEtherealTravelRule() != 1
        )
            ++bad;
        // the WishRules pin
    if (debWishRules() != 1
        )
            ++bad;
        // the GreaterNativePowers pin
    if (debGreaterNativePowers() != 1
        )
            ++bad;
        // the LesserNativePowers pin
    if (debLesserNativePowers() != 1
        )
            ++bad;
        // the DemiNativePowers pin
    if (debDemiNativePowers() != 1
        )
            ++bad;
        printf("R595 AppIV audit: bad %d\n", bad);
        if (bad) return 1;
    }
