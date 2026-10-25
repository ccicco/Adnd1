    // ---- R371: the UA expanded armor
    // pin audit ----
    // The UA expanded armor (pp. 75-76):
    // the armor and encumbrance table
    // rows (banded through studded
    // leather, the shield rows, the
    // never-sold elfin chain footnote)
    // and the four descriptions - the
    // bronze plate (the AC 4, the +2
    // rear-attack exposure, the rust
    // immunity), the elfin chain (the
    // thief-wearable read), the field
    // plate (the 1 point per die
    // absorption, the 12 point cap, the
    // 100 gp per point repair), the full
    // plate. The R191 seam cross-checks
    // the plate AC ladder, the R334 seam
    // the thief elfin rows, the R370 seam
    // the barding weight read. Two items
    // flip CLOSED; the census 297 -> 298.
    {
        using namespace rules;
        int bad = 0;
        // ---- the table rows ----
            if (uaarmBandedWeight() != 35) ++bad;
            if (uaarmBandedMove() != 9) ++bad;
            if (uaarmBandedCost() != 90) ++bad;
            if (!uaarmBandedBulky()) ++bad;
            if (uaarmBronzePlateWeight() != 45)
                ++bad;
            if (uaarmBronzePlateMove() != 6)
                ++bad;
            if (uaarmBronzePlateCost() != 100)
                ++bad;
            if (!uaarmBronzePlateBulky()) ++bad;
            if (uaarmFieldPlateWeight() != 55)
                ++bad;
            if (uaarmFieldPlateMove() != 6)
                ++bad;
            if (uaarmFieldPlateCost() != 2000)
                ++bad;
            if (!uaarmFieldPlateFairlyBulky())
                ++bad;
            if (uaarmFullPlateWeight() != 65)
                ++bad;
            if (uaarmFullPlateMove() != 6) ++bad;
            if (uaarmFullPlateCost() != 4000)
                ++bad;
            if (!uaarmFullPlateFairlyBulky())
                ++bad;
            if (uaarmRingMailWeight() != 25) ++bad;
            if (uaarmRingMailMove() != 9) ++bad;
            if (uaarmRingMailCost() != 30) ++bad;
            if (uaarmScaleMailWeight() != 40) ++bad;
            if (uaarmScaleMailMove() != 6) ++bad;
            if (uaarmScaleMailCost() != 45) ++bad;
            if (uaarmSplintMailWeight() != 40) ++bad;
            if (uaarmSplintMailMove() != 6) ++bad;
            if (uaarmSplintMailCost() != 80) ++bad;
            if (uaarmStuddedLeatherWeight() != 20)
                ++bad;
            if (uaarmStuddedLeatherMove() != 9)
                ++bad;
            if (uaarmStuddedLeatherCost() != 15)
                ++bad;
            if (!uaarmElfinNeverOnOpenMarket())
                ++bad;
            if (uaarmShieldBucklerWeight() != 3)
                ++bad;
            if (uaarmShieldBucklerCost() != 5)
                ++bad;
            if (uaarmShieldLargeWeight() != 10)
                ++bad;
            if (uaarmShieldLargeCost() != 15) ++bad;
            if (uaarmShieldSmallWeight() != 5) ++bad;
            if (uaarmShieldSmallCost() != 10) ++bad;
            // the cost ladder: field plate
            // is half the full plate cost
            if (2 * uaarmFieldPlateCost()
                    != uaarmFullPlateCost()) ++bad;
            // the heavy armors share the
            // 6 inch move; the light the 9
            if (uaarmBronzePlateMove()
                    != uaarmFieldPlateMove()) ++bad;
            if (uaarmBandedMove()
                    != uaarmRingMailMove()) ++bad;
        // ---- the descriptions ----
            if (uaarmBronzeAc() != 4) ++bad;
            if (uaarmBronzeRearAttackBonus() != 2)
                ++bad;
            if (!uaarmBronzeRustImmune()) ++bad;
            if (!uaarmBronzeEarlierCheaperVersion())
                ++bad;
            if (!uaarmElfinElvenMade()) ++bad;
            if (!uaarmElfinExtremelyRare()) ++bad;
            if (!uaarmElfinThiefWearable()) ++bad;
            if (!uaarmElfinSomewhatImpairsThiefAbilities())
                ++bad;
            if (uaarmFieldPlateAbsorbPerDie() != 1)
                ++bad;
            if (uaarmFieldPlateAbsorbCap() != 12)
                ++bad;
            if (uaarmFieldPlateRepairCostPerPoint()
                    != 100) ++bad;
            if (uaarmFieldPlateRepairDaysPerPoint()
                    != 1) ++bad;
            if (!uaarmFieldPlateFittedToWearer())
                ++bad;
            if (!uaarmFieldPlateBulkyAsChain())
                ++bad;
            if (!uaarmFullPlateInterlockedBackedWithChain())
                ++bad;
            if (!uaarmFullPlateBulkyAsChain()) ++bad;
            // the field plate repair: the
            // full cap costs 1200 gp and
            // 12 days
            if (uaarmFieldPlateRepairCostPerPoint()
                    * uaarmFieldPlateAbsorbCap()
                    != 1200) ++bad;
            // the full plate outweighs
            // the field plate
            if (uaarmFullPlateWeight()
                    <= uaarmFieldPlateWeight())
                ++bad;
        // ---- the R191 seam ----
            // the plate mail AC 3 sits at
            // the ladder top; the bronze
            // plate reads one worse (4)
            if (armorRatingAc(10) != 3) ++bad;
            if (armorRatingAc(10) + 1
                    != uaarmBronzeAc()) ++bad;
            if (strcmp(armorRatingName(10),
                    "plate mail") != 0) ++bad;
        // ---- the R334 seam ----
            if (!thiefArmorElfinUnderNormalClothing())
                ++bad;
        // ---- the R370 seam ----
            // the elfin chain barding
            // weighs as leather
            if (!uasm1UnicornGriffonElfinWeightAsLeather())
                ++bad;
        printf("R371 UA expanded armor pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
