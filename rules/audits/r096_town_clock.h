    // ---- R96: town clock audit ----
    {
        int bad = 0;
        // training costs days equal to the new level
        if (trainingDays(2) != 2) ++bad;
        if (trainingDays(3) != 3) ++bad;
        if (trainingDays(9) != 9) ++bad;
        // the 1st rank is never free, the 20th never
        // costs more than the keep's patience (bound 1..20)
        if (trainingDays(1) < 1) ++bad;
        if (trainingDays(20) > 20) ++bad;
        // a town week: three inn nights and one promotion
        // to 3rd level - 3 + 3 days, no more, no less
        {
            Party p;
            p.careerDays = 0;
            p.careerDays += 1;                     // inn night
            p.careerDays += 1;                     // inn night
            p.careerDays += 1;                     // inn night
            p.careerDays += trainingDays(3);       // the drills
            if (p.careerDays != 6) ++bad;
        }
        printf("R96 town clock audit: bad %d\n", bad);
        if (bad) return 1;
    }
