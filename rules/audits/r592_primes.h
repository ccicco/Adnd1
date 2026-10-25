    // ---- R592 Primes audit ----
    // APPENDIX I: THE PRIME MATERIAL PLANES, printed pp. 117-119, the
    // Alternate Primes doctrine: the universes most familiar, each bordering
    // its own Ethereal with the Astral reaching all - the ways in (the plane
    // shift tuning fork, the amulet of the planes and the well of many
    // worlds, the guarded free-standing gates, the psionic probability
    // travel), and the ways around (no direct Prime-to-Prime spell, the
    // Ethereal-to-inner-to-alternate-Ethereal relay). The Polyverse: an
    // infinite number of Primes, each measured against the traveler's home
    // (0,0,0) by three factors. The physical factor, the level of scientific
    // reality: 1d10 for value, 1d4 odd-negative even-positive for sign, the
    // ladder from +10 (explosive matter, sentience impossible) through the
    // firearms-possible +5, the standard 0, the giant-white-rabbit -3, the
    // aware-chairs -7, to the wholly-aware -10; survival comfortable within 5
    // either way, home abilities retained abroad. The magical factor, the
    // permeation of magic: from the +10 universal casting that dissolves
    // planes into mage-ruled demi-planes, the +6 visible spells and
    // spell-free saves, the +3 bookless casting, down through the -1
    // 8th-level cap, the -5 Power-spell ban, the -7 where songs disappear, to
    // the -10 where sentient life is impossible - the wizard powerless at -6,
    // the innately magical pooka saving vs. death or dying of deprivation.
    // The temporal factor, the divergence of the planes: +10 the differently
    // colored suns, +6 the methane-breathers, +4 the reshuffled continents, 0
    // the counterpart individuals of varying alignment, and the negatives the
    // home Prime's own past or future by weeks, years, centuries, millennia,
    // millions of years - the time-travel digression: one's own past
    // unreachable (at least unproven), but the low-negative-timeline
    // alternate the effective equivalent. The general laws: time, gravity,
    // vision and bodily needs the same in all Primes, no general hostility.
    // The class rules: casters limited by the lesser of home and current
    // magical factors; the cleric deity rule (the shared inner, Astral and
    // outer planes against the other-Prime deity's 1st-and-2nd limit); druids
    // and rangers within 2, barbarians within 1, the paladin's mount staying
    // sentient; thieves, fighters, cavaliers, monks normal. The encounters:
    // complete worlds, adapt the tables to the three factors; combat normal
    // at low factors with the high factors arming the unusual and ruining the
    // standard; magic capped by the plane's factor for all casters. And the
    // examples: the same-rules campaign at (0,0,0) with magical drift of 1 or
    // 2 and temporal of at most 5, and the typical 20th-century world at
    // (5,-4,5).
    {
        using namespace rules;
        int bad = 0;
    if (ddxPfValueDie() != 10
            || ddxPfSignDie() != 4
            || ddxPfComfortRange() != 5
            || ddxDruidPhysRange() != 2
            || ddxBarbarianPhysRange() != 1
            || ddxClericLowSpellCap() != 2
            || !ddxPrimesDoctrine()
            || !ddxPolyverseRule()
            || !ddxMagicalFactorRule()
            || !ddxTemporalFactorRule()
            || !ddxSurvivalRule()
            || !ddxClassRule()
            || !ddxEncounterRule()
        )
            ++bad;
        // the PfValueDie pin
    if (ddxPfValueDie() != 10
        )
            ++bad;
        // the PfSignDie pin
    if (ddxPfSignDie() != 4
        )
            ++bad;
        // the PfComfortRange pin
    if (ddxPfComfortRange() != 5
        )
            ++bad;
        // the DruidPhysRange pin
    if (ddxDruidPhysRange() != 2
        )
            ++bad;
        // the BarbarianPhysRange pin
    if (ddxBarbarianPhysRange() != 1
        )
            ++bad;
        // the ClericLowSpellCap pin
    if (ddxClericLowSpellCap() != 2
        )
            ++bad;
        // the PrimesDoctrine pin
    if (ddxPrimesDoctrine() != 1
        )
            ++bad;
        // the PolyverseRule pin
    if (ddxPolyverseRule() != 1
        )
            ++bad;
        // the MagicalFactorRule pin
    if (ddxMagicalFactorRule() != 1
        )
            ++bad;
        // the TemporalFactorRule pin
    if (ddxTemporalFactorRule() != 1
        )
            ++bad;
        // the SurvivalRule pin
    if (ddxSurvivalRule() != 1
        )
            ++bad;
        // the ClassRule pin
    if (ddxClassRule() != 1
        )
            ++bad;
        // the EncounterRule pin
    if (ddxEncounterRule() != 1
        )
            ++bad;
        printf("R592 Primes audit: bad %d\n", bad);
        if (bad) return 1;
    }
