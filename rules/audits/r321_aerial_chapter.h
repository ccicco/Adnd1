    // ---- R321: the aerial chapter audit ----
    // The OUT reversal (the R172 appendix
    // J precedent): the DMG pp.49-53 pins
    // (rules/aerial.h) and the fly seams -
    // the STATUS_FLYING mark, the wing
    // fold, the potion claim. No aerial
    // fight site exists - the prints are
    // the charge. Draw-independent: the
    // row saves not, the pins read fixed.
    {
        int bad = 0;
        // A1: the maneuver table - the turn
        // degrees, the full-speed times,
        // the hover, the fly spell class
        {
            if (rules::aerialTurnDegreesPerRound(1)
                != 180) ++bad;
            if (rules::aerialTurnDegreesPerRound(2)
                != 120) ++bad;
            if (rules::aerialTurnDegreesPerRound(3)
                != 90) ++bad;
            if (rules::aerialTurnDegreesPerRound(4)
                != 60) ++bad;
            if (rules::aerialTurnDegreesPerRound(5)
                != 30) ++bad;
            if (rules::aerialTurnDegreesPerRound(0)
                != 0) ++bad;
            if (rules::aerialSegmentsToFullSpeed(1)
                != 1) ++bad;
            if (rules::aerialSegmentsToFullSpeed(2)
                != 6) ++bad;
            if (rules::aerialSegmentsToFullSpeed(3)
                != -1) ++bad;
            if (rules::aerialRoundsToFullSpeed(3)
                != 1) ++bad;
            if (rules::aerialRoundsToFullSpeed(4)
                != 2) ++bad;
            if (rules::aerialRoundsToFullSpeed(5)
                != 4) ++bad;
            if (rules::aerialRoundsToFullSpeed(1)
                != -1) ++bad;
            if (!rules::aerialHover(1)) ++bad;
            if (!rules::aerialHover(2)) ++bad;
            if (rules::aerialHover(3)) ++bad;
            if (rules::aerialHover(5)) ++bad;
            if (rules::aerialFlySpellManeuverClass()
                != 2) ++bad;
        }
        // A2: the flight, missile and wing
        // scalars
        {
            if (rules::aerialClimbRateDivisor()
                != 2) ++bad;
            if (rules::aerialDiveRateMultiple()
                != 2) ++bad;
            if (rules::aerialClimbFeetPerFootUp()
                != 3) ++bad;
            if (rules::aerialDiveFeetPerFootDown()
                != 1) ++bad;
            if (rules::aerialDiveEarthboundHeightFt()
                != 30) ++bad;
            if (rules::aerialCeilingFeet()
                != 5000) ++bad;
            if (rules::aerialMissileShortPenalty()
                != -2) ++bad;
            if (rules::aerialMissileMediumPenalty()
                != -5) ++bad;
            if (rules::aerialDragonBreathSaveBonus()
                != 2) ++bad;
            if (rules::aerialWingDamageLandPct()
                != 50) ++bad;
            if (rules::aerialWingDamagePlummetPct()
                != 75) ++bad;
            if (rules::aerialFeatheredWingBonusPct()
                != 50) ++bad;
        }
        // A3: the status - the spell engine
        // level (no save on the row)
        {
            rules::Rng r(11);
            rules::Dice d(r);
            ai::Actor t;
            t.team = 1; t.hitDice = 1;
            t.hp = 6; t.maxHp = 6;
            std::vector<spelleffects::TargetDesc>
                ds;
            ds.push_back(t.asTarget());
            spelleffects::SpellCastResult r1 =
                spelleffects::resolveSpell(
                    d, spells::MU_FLY, 5, ds);
            if (r1.perTarget.size() != 1) ++bad;
            if (!r1.perTarget.empty() &&
                r1.perTarget[0].status.kind !=
                    spelleffects::STATUS_FLYING)
                ++bad;
        }
        // A4: the wing fold - a party fly
        // cast marks the company
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.classIndex = 1; a.level = 5;
            a.slotsByLevel[2] = 1;
            a.hp = 30; a.maxHp = 30;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.resolveCast(
                enc.partyMutable()[0],
                spells::MU_FLY);
            if (!enc.flyActive()) ++bad;
            bool wg = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("takes wing") !=
                    std::string::npos)
                    wg = true;
            if (!wg) ++bad;
            // the slot spent
            if (enc.partyMutable()[0]
                    .slotsByLevel[2] != 0) ++bad;
        }
        // A5: the dry gate - a non-fly
        // cast never marks
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.classIndex = 1; a.level = 5;
            a.slotsByLevel[0] = 1;
            a.hp = 30; a.maxHp = 30;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.resolveCast(
                enc.partyMutable()[0],
                spells::MU_LIGHT);
            if (enc.flyActive()) ++bad;
            bool wg = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("takes wing") !=
                    std::string::npos)
                    wg = true;
            if (wg) ++bad;
        }
        // A6: the claim (the claimUwDraught
        // pattern)
        {
            Character c;
            c.hp = 10;
            if (!claimFlyPotion(
                    c, "Potion of Flying",
                    1)) ++bad;
            if (!c.flyPotion) ++bad;
            // one dose per member
            if (claimFlyPotion(
                    c, "Potion of Flying",
                    1)) ++bad;
            c.flyPotion = false;
            // other potions never claim
            if (claimFlyPotion(
                    c, "Potion of Healing",
                    1)) ++bad;
            // bundles never claim
            if (claimFlyPotion(
                    c, "Potion of Flying",
                    2)) ++bad;
            // the dead claim nothing
            c.hp = 0;
            if (claimFlyPotion(
                    c, "Potion of Flying",
                    1)) ++bad;
        }
        // A7: the name array - every kind
        // names (the std::string compare -
        // the R320 pointer-compare warning)
        {
            for (int k = 0;
                 k < (int)spelleffects::STATUS_COUNT;
                 ++k)
                if (spelleffects::statusName(
                        (spelleffects::StatusKind)k)
                    == nullptr) ++bad;
            if (std::string(spelleffects::statusName(
                    spelleffects::STATUS_FLYING))
                != "Flying") ++bad;
        }
        printf("R321 aerial chapter audit: bad %d\n", bad);
        if (bad) return 1;
    }
