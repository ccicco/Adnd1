    // ==== R1054: sage registry ===========
    // The R1054 de-wire: the 32 static
    // arrays of rules/dmg/sage.h ride
    // items::MiscItemRegistry from
    // content/tables/dm_sage/ (6 defs,
    // 29 named tables; the five [4][3]
    // grids retire FLATTENED scope-
    // major, the three name accessors
    // are rows readers). Seven sections:
    // load, counts, fields+categories,
    // characteristics, grids+terms,
    // seam, edges. Census 1082 -> 1089.
    // DO NOT hand-edit:
    // tools/r1054_splice.py is the only
    // writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/dm_sage");
            if (n != 6) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1054)
                    ++bad;
            if (!reg.find("dm_sage_fields")) ++bad;
            if (!reg.find("dm_sage_categories")) ++bad;
            if (!reg.find("dm_sage_characteristics")) ++bad;
            if (!reg.find("dm_sage_knowing")) ++bad;
            if (!reg.find("dm_sage_discovery")) ++bad;
            if (!reg.find("dm_sage_terms")) ++bad;
        }
        printf("R1054 sage registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_sage");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_fields");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "dm_sage_fieldsRowCount"
                        || d->pins[0].value != 7
                        || (int)d->tables.size() != 9)
                        ++bad;
                    if (d->tables[0].name
                        != "field_lo"
                        || (int)d->tables[0]
                            .values.size() != 7)
                        ++bad;
                    if (d->tables[1].name
                        != "field_hi"
                        || (int)d->tables[1]
                            .values.size() != 7)
                        ++bad;
                    if (d->tables[2].name
                        != "field_category_count"
                        || (int)d->tables[2]
                            .values.size() != 7)
                        ++bad;
                    if (d->tables[3].name
                        != "field_category_first"
                        || (int)d->tables[3]
                            .values.size() != 7)
                        ++bad;
                    if (d->tables[4].name
                        != "spell_kind"
                        || (int)d->tables[4]
                            .values.size() != 7)
                        ++bad;
                    if (d->tables[5].name
                        != "band_lo"
                        || (int)d->tables[5]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[6].name
                        != "band_hi"
                        || (int)d->tables[6]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[7].name
                        != "band_minor"
                        || (int)d->tables[7]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[8].name
                        != "band_special"
                        || (int)d->tables[8]
                            .values.size() != 6)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_sage_fields"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_sage_fields"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_sage_fields"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_sage_fields"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "dm_sage_fields"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "dm_sage_fields"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                    if (d->rows[6].set
                        != "dm_sage_fields"
                        || d->rows[6].bandLo != 6
                        || d->rows[6].bandHi != 6)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "Humankind")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "Demi-Humankind")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "Humanoids & Giantkind")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "Physical Universe(s)")
                    ++bad;
                if (std::string(
                    d->rows[4].name)
                    != "Fauna")
                    ++bad;
                if (std::string(
                    d->rows[5].name)
                    != "Flora")
                    ++bad;
                if (std::string(
                    d->rows[6].name)
                    != "Supernatural & Unusual")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_categories");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 68
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "dm_sage_categoriesRowCount"
                        || d->pins[0].value != 68
                        || (int)d->tables.size() != 1)
                        ++bad;
                    if (d->tables[0].name
                        != "category_field"
                        || (int)d->tables[0]
                            .values.size() != 68)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_sage_categories"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_sage_categories"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_sage_categories"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_sage_categories"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "dm_sage_categories"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "dm_sage_categories"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                    if (d->rows[6].set
                        != "dm_sage_categories"
                        || d->rows[6].bandLo != 6
                        || d->rows[6].bandHi != 6)
                        ++bad;
                    if (d->rows[7].set
                        != "dm_sage_categories"
                        || d->rows[7].bandLo != 7
                        || d->rows[7].bandHi != 7)
                        ++bad;
                    if (d->rows[8].set
                        != "dm_sage_categories"
                        || d->rows[8].bandLo != 8
                        || d->rows[8].bandHi != 8)
                        ++bad;
                    if (d->rows[9].set
                        != "dm_sage_categories"
                        || d->rows[9].bandLo != 9
                        || d->rows[9].bandHi != 9)
                        ++bad;
                    if (d->rows[10].set
                        != "dm_sage_categories"
                        || d->rows[10].bandLo != 10
                        || d->rows[10].bandHi != 10)
                        ++bad;
                    if (d->rows[11].set
                        != "dm_sage_categories"
                        || d->rows[11].bandLo != 11
                        || d->rows[11].bandHi != 11)
                        ++bad;
                    if (d->rows[12].set
                        != "dm_sage_categories"
                        || d->rows[12].bandLo != 12
                        || d->rows[12].bandHi != 12)
                        ++bad;
                    if (d->rows[13].set
                        != "dm_sage_categories"
                        || d->rows[13].bandLo != 13
                        || d->rows[13].bandHi != 13)
                        ++bad;
                    if (d->rows[14].set
                        != "dm_sage_categories"
                        || d->rows[14].bandLo != 14
                        || d->rows[14].bandHi != 14)
                        ++bad;
                    if (d->rows[15].set
                        != "dm_sage_categories"
                        || d->rows[15].bandLo != 15
                        || d->rows[15].bandHi != 15)
                        ++bad;
                    if (d->rows[16].set
                        != "dm_sage_categories"
                        || d->rows[16].bandLo != 16
                        || d->rows[16].bandHi != 16)
                        ++bad;
                    if (d->rows[17].set
                        != "dm_sage_categories"
                        || d->rows[17].bandLo != 17
                        || d->rows[17].bandHi != 17)
                        ++bad;
                    if (d->rows[18].set
                        != "dm_sage_categories"
                        || d->rows[18].bandLo != 18
                        || d->rows[18].bandHi != 18)
                        ++bad;
                    if (d->rows[19].set
                        != "dm_sage_categories"
                        || d->rows[19].bandLo != 19
                        || d->rows[19].bandHi != 19)
                        ++bad;
                    if (d->rows[20].set
                        != "dm_sage_categories"
                        || d->rows[20].bandLo != 20
                        || d->rows[20].bandHi != 20)
                        ++bad;
                    if (d->rows[21].set
                        != "dm_sage_categories"
                        || d->rows[21].bandLo != 21
                        || d->rows[21].bandHi != 21)
                        ++bad;
                    if (d->rows[22].set
                        != "dm_sage_categories"
                        || d->rows[22].bandLo != 22
                        || d->rows[22].bandHi != 22)
                        ++bad;
                    if (d->rows[23].set
                        != "dm_sage_categories"
                        || d->rows[23].bandLo != 23
                        || d->rows[23].bandHi != 23)
                        ++bad;
                    if (d->rows[24].set
                        != "dm_sage_categories"
                        || d->rows[24].bandLo != 24
                        || d->rows[24].bandHi != 24)
                        ++bad;
                    if (d->rows[25].set
                        != "dm_sage_categories"
                        || d->rows[25].bandLo != 25
                        || d->rows[25].bandHi != 25)
                        ++bad;
                    if (d->rows[26].set
                        != "dm_sage_categories"
                        || d->rows[26].bandLo != 26
                        || d->rows[26].bandHi != 26)
                        ++bad;
                    if (d->rows[27].set
                        != "dm_sage_categories"
                        || d->rows[27].bandLo != 27
                        || d->rows[27].bandHi != 27)
                        ++bad;
                    if (d->rows[28].set
                        != "dm_sage_categories"
                        || d->rows[28].bandLo != 28
                        || d->rows[28].bandHi != 28)
                        ++bad;
                    if (d->rows[29].set
                        != "dm_sage_categories"
                        || d->rows[29].bandLo != 29
                        || d->rows[29].bandHi != 29)
                        ++bad;
                    if (d->rows[30].set
                        != "dm_sage_categories"
                        || d->rows[30].bandLo != 30
                        || d->rows[30].bandHi != 30)
                        ++bad;
                    if (d->rows[31].set
                        != "dm_sage_categories"
                        || d->rows[31].bandLo != 31
                        || d->rows[31].bandHi != 31)
                        ++bad;
                    if (d->rows[32].set
                        != "dm_sage_categories"
                        || d->rows[32].bandLo != 32
                        || d->rows[32].bandHi != 32)
                        ++bad;
                    if (d->rows[33].set
                        != "dm_sage_categories"
                        || d->rows[33].bandLo != 33
                        || d->rows[33].bandHi != 33)
                        ++bad;
                    if (d->rows[34].set
                        != "dm_sage_categories"
                        || d->rows[34].bandLo != 34
                        || d->rows[34].bandHi != 34)
                        ++bad;
                    if (d->rows[35].set
                        != "dm_sage_categories"
                        || d->rows[35].bandLo != 35
                        || d->rows[35].bandHi != 35)
                        ++bad;
                    if (d->rows[36].set
                        != "dm_sage_categories"
                        || d->rows[36].bandLo != 36
                        || d->rows[36].bandHi != 36)
                        ++bad;
                    if (d->rows[37].set
                        != "dm_sage_categories"
                        || d->rows[37].bandLo != 37
                        || d->rows[37].bandHi != 37)
                        ++bad;
                    if (d->rows[38].set
                        != "dm_sage_categories"
                        || d->rows[38].bandLo != 38
                        || d->rows[38].bandHi != 38)
                        ++bad;
                    if (d->rows[39].set
                        != "dm_sage_categories"
                        || d->rows[39].bandLo != 39
                        || d->rows[39].bandHi != 39)
                        ++bad;
                    if (d->rows[40].set
                        != "dm_sage_categories"
                        || d->rows[40].bandLo != 40
                        || d->rows[40].bandHi != 40)
                        ++bad;
                    if (d->rows[41].set
                        != "dm_sage_categories"
                        || d->rows[41].bandLo != 41
                        || d->rows[41].bandHi != 41)
                        ++bad;
                    if (d->rows[42].set
                        != "dm_sage_categories"
                        || d->rows[42].bandLo != 42
                        || d->rows[42].bandHi != 42)
                        ++bad;
                    if (d->rows[43].set
                        != "dm_sage_categories"
                        || d->rows[43].bandLo != 43
                        || d->rows[43].bandHi != 43)
                        ++bad;
                    if (d->rows[44].set
                        != "dm_sage_categories"
                        || d->rows[44].bandLo != 44
                        || d->rows[44].bandHi != 44)
                        ++bad;
                    if (d->rows[45].set
                        != "dm_sage_categories"
                        || d->rows[45].bandLo != 45
                        || d->rows[45].bandHi != 45)
                        ++bad;
                    if (d->rows[46].set
                        != "dm_sage_categories"
                        || d->rows[46].bandLo != 46
                        || d->rows[46].bandHi != 46)
                        ++bad;
                    if (d->rows[47].set
                        != "dm_sage_categories"
                        || d->rows[47].bandLo != 47
                        || d->rows[47].bandHi != 47)
                        ++bad;
                    if (d->rows[48].set
                        != "dm_sage_categories"
                        || d->rows[48].bandLo != 48
                        || d->rows[48].bandHi != 48)
                        ++bad;
                    if (d->rows[49].set
                        != "dm_sage_categories"
                        || d->rows[49].bandLo != 49
                        || d->rows[49].bandHi != 49)
                        ++bad;
                    if (d->rows[50].set
                        != "dm_sage_categories"
                        || d->rows[50].bandLo != 50
                        || d->rows[50].bandHi != 50)
                        ++bad;
                    if (d->rows[51].set
                        != "dm_sage_categories"
                        || d->rows[51].bandLo != 51
                        || d->rows[51].bandHi != 51)
                        ++bad;
                    if (d->rows[52].set
                        != "dm_sage_categories"
                        || d->rows[52].bandLo != 52
                        || d->rows[52].bandHi != 52)
                        ++bad;
                    if (d->rows[53].set
                        != "dm_sage_categories"
                        || d->rows[53].bandLo != 53
                        || d->rows[53].bandHi != 53)
                        ++bad;
                    if (d->rows[54].set
                        != "dm_sage_categories"
                        || d->rows[54].bandLo != 54
                        || d->rows[54].bandHi != 54)
                        ++bad;
                    if (d->rows[55].set
                        != "dm_sage_categories"
                        || d->rows[55].bandLo != 55
                        || d->rows[55].bandHi != 55)
                        ++bad;
                    if (d->rows[56].set
                        != "dm_sage_categories"
                        || d->rows[56].bandLo != 56
                        || d->rows[56].bandHi != 56)
                        ++bad;
                    if (d->rows[57].set
                        != "dm_sage_categories"
                        || d->rows[57].bandLo != 57
                        || d->rows[57].bandHi != 57)
                        ++bad;
                    if (d->rows[58].set
                        != "dm_sage_categories"
                        || d->rows[58].bandLo != 58
                        || d->rows[58].bandHi != 58)
                        ++bad;
                    if (d->rows[59].set
                        != "dm_sage_categories"
                        || d->rows[59].bandLo != 59
                        || d->rows[59].bandHi != 59)
                        ++bad;
                    if (d->rows[60].set
                        != "dm_sage_categories"
                        || d->rows[60].bandLo != 60
                        || d->rows[60].bandHi != 60)
                        ++bad;
                    if (d->rows[61].set
                        != "dm_sage_categories"
                        || d->rows[61].bandLo != 61
                        || d->rows[61].bandHi != 61)
                        ++bad;
                    if (d->rows[62].set
                        != "dm_sage_categories"
                        || d->rows[62].bandLo != 62
                        || d->rows[62].bandHi != 62)
                        ++bad;
                    if (d->rows[63].set
                        != "dm_sage_categories"
                        || d->rows[63].bandLo != 63
                        || d->rows[63].bandHi != 63)
                        ++bad;
                    if (d->rows[64].set
                        != "dm_sage_categories"
                        || d->rows[64].bandLo != 64
                        || d->rows[64].bandHi != 64)
                        ++bad;
                    if (d->rows[65].set
                        != "dm_sage_categories"
                        || d->rows[65].bandLo != 65
                        || d->rows[65].bandHi != 65)
                        ++bad;
                    if (d->rows[66].set
                        != "dm_sage_categories"
                        || d->rows[66].bandLo != 66
                        || d->rows[66].bandHi != 66)
                        ++bad;
                    if (d->rows[67].set
                        != "dm_sage_categories"
                        || d->rows[67].bandLo != 67
                        || d->rows[67].bandHi != 67)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "Art & Music")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "Biology")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "Demography")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "History")
                    ++bad;
                if (std::string(
                    d->rows[4].name)
                    != "Languages")
                    ++bad;
                if (std::string(
                    d->rows[5].name)
                    != "Legends & Folklore")
                    ++bad;
                if (std::string(
                    d->rows[6].name)
                    != "Law & Customs")
                    ++bad;
                if (std::string(
                    d->rows[7].name)
                    != "Philosophy & Ethics")
                    ++bad;
                if (std::string(
                    d->rows[8].name)
                    != "Politics & Genealogy")
                    ++bad;
                if (std::string(
                    d->rows[9].name)
                    != "Psychology")
                    ++bad;
                if (std::string(
                    d->rows[10].name)
                    != "Sociology")
                    ++bad;
                if (std::string(
                    d->rows[11].name)
                    != "Theology & Myth")
                    ++bad;
                if (std::string(
                    d->rows[12].name)
                    != "Art & Music")
                    ++bad;
                if (std::string(
                    d->rows[13].name)
                    != "Biology")
                    ++bad;
                if (std::string(
                    d->rows[14].name)
                    != "Demography")
                    ++bad;
                if (std::string(
                    d->rows[15].name)
                    != "Languages")
                    ++bad;
                if (std::string(
                    d->rows[16].name)
                    != "Legends & Folklore")
                    ++bad;
                if (std::string(
                    d->rows[17].name)
                    != "Law & Customs")
                    ++bad;
                if (std::string(
                    d->rows[18].name)
                    != "Philosophy & Ethics")
                    ++bad;
                if (std::string(
                    d->rows[19].name)
                    != "Politics & Genealogy")
                    ++bad;
                if (std::string(
                    d->rows[20].name)
                    != "Psychology")
                    ++bad;
                if (std::string(
                    d->rows[21].name)
                    != "Sociology")
                    ++bad;
                if (std::string(
                    d->rows[22].name)
                    != "Theology & Myth")
                    ++bad;
                if (std::string(
                    d->rows[23].name)
                    != "Biology")
                    ++bad;
                if (std::string(
                    d->rows[24].name)
                    != "Demography")
                    ++bad;
                if (std::string(
                    d->rows[25].name)
                    != "History")
                    ++bad;
                if (std::string(
                    d->rows[26].name)
                    != "Languages")
                    ++bad;
                if (std::string(
                    d->rows[27].name)
                    != "Legends & Folklore")
                    ++bad;
                if (std::string(
                    d->rows[28].name)
                    != "Law & Customs")
                    ++bad;
                if (std::string(
                    d->rows[29].name)
                    != "Sociology")
                    ++bad;
                if (std::string(
                    d->rows[30].name)
                    != "Theology & Myth")
                    ++bad;
                if (std::string(
                    d->rows[31].name)
                    != "Architecture & Engineering")
                    ++bad;
                if (std::string(
                    d->rows[32].name)
                    != "Astronomy")
                    ++bad;
                if (std::string(
                    d->rows[33].name)
                    != "Chemistry")
                    ++bad;
                if (std::string(
                    d->rows[34].name)
                    != "Geography")
                    ++bad;
                if (std::string(
                    d->rows[35].name)
                    != "Geology & Mineralogy")
                    ++bad;
                if (std::string(
                    d->rows[36].name)
                    != "Mathematics")
                    ++bad;
                if (std::string(
                    d->rows[37].name)
                    != "Meteorology & Climatology")
                    ++bad;
                if (std::string(
                    d->rows[38].name)
                    != "Oceanography")
                    ++bad;
                if (std::string(
                    d->rows[39].name)
                    != "Physics")
                    ++bad;
                if (std::string(
                    d->rows[40].name)
                    != "Topography & Cartography")
                    ++bad;
                if (std::string(
                    d->rows[41].name)
                    != "Amphibians")
                    ++bad;
                if (std::string(
                    d->rows[42].name)
                    != "Arachnids")
                    ++bad;
                if (std::string(
                    d->rows[43].name)
                    != "Avians")
                    ++bad;
                if (std::string(
                    d->rows[44].name)
                    != "Cephalopods & Echinoderms")
                    ++bad;
                if (std::string(
                    d->rows[45].name)
                    != "Crustaceans & Mollusks")
                    ++bad;
                if (std::string(
                    d->rows[46].name)
                    != "Ichthyoids")
                    ++bad;
                if (std::string(
                    d->rows[47].name)
                    != "Insects")
                    ++bad;
                if (std::string(
                    d->rows[48].name)
                    != "Mammals")
                    ++bad;
                if (std::string(
                    d->rows[49].name)
                    != "Marsupials")
                    ++bad;
                if (std::string(
                    d->rows[50].name)
                    != "Reptiles")
                    ++bad;
                if (std::string(
                    d->rows[51].name)
                    != "Bushes & Shrubs")
                    ++bad;
                if (std::string(
                    d->rows[52].name)
                    != "Flowers")
                    ++bad;
                if (std::string(
                    d->rows[53].name)
                    != "Fungi")
                    ++bad;
                if (std::string(
                    d->rows[54].name)
                    != "Grasses & Grains")
                    ++bad;
                if (std::string(
                    d->rows[55].name)
                    != "Herbs")
                    ++bad;
                if (std::string(
                    d->rows[56].name)
                    != "Mosses & Ferns")
                    ++bad;
                if (std::string(
                    d->rows[57].name)
                    != "Trees")
                    ++bad;
                if (std::string(
                    d->rows[58].name)
                    != "Weeds")
                    ++bad;
                if (std::string(
                    d->rows[59].name)
                    != "Astrology & Numerology")
                    ++bad;
                if (std::string(
                    d->rows[60].name)
                    != "Cryptography")
                    ++bad;
                if (std::string(
                    d->rows[61].name)
                    != "Divination")
                    ++bad;
                if (std::string(
                    d->rows[62].name)
                    != "Dweomercraeft")
                    ++bad;
                if (std::string(
                    d->rows[63].name)
                    != "Heraldry, Signs & Sigils")
                    ++bad;
                if (std::string(
                    d->rows[64].name)
                    != "Medicine")
                    ++bad;
                if (std::string(
                    d->rows[65].name)
                    != "Metaphysics")
                    ++bad;
                if (std::string(
                    d->rows[66].name)
                    != "Planes (Astral, Elemental & Ethereal)")
                    ++bad;
                if (std::string(
                    d->rows[67].name)
                    != "Planes (Outer)")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_characteristics");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 9
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "dm_sage_characteristicsRowCount"
                        || d->pins[0].value != 9
                        || (int)d->tables.size() != 5)
                        ++bad;
                    if (d->tables[0].name
                        != "align_lo"
                        || (int)d->tables[0]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[1].name
                        != "align_hi"
                        || (int)d->tables[1]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[2].name
                        != "ability_dice"
                        || (int)d->tables[2]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[3].name
                        != "ability_dice_count"
                        || (int)d->tables[3]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[4].name
                        != "ability_plus"
                        || (int)d->tables[4]
                            .values.size() != 6)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_sage_characteristics"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_sage_characteristics"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_sage_characteristics"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_sage_characteristics"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "dm_sage_characteristics"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "dm_sage_characteristics"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                    if (d->rows[6].set
                        != "dm_sage_characteristics"
                        || d->rows[6].bandLo != 6
                        || d->rows[6].bandHi != 6)
                        ++bad;
                    if (d->rows[7].set
                        != "dm_sage_characteristics"
                        || d->rows[7].bandLo != 7
                        || d->rows[7].bandHi != 7)
                        ++bad;
                    if (d->rows[8].set
                        != "dm_sage_characteristics"
                        || d->rows[8].bandLo != 8
                        || d->rows[8].bandHi != 8)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "chaotic evil")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "chaotic good")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "chaotic neutral")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "lawful evil")
                    ++bad;
                if (std::string(
                    d->rows[4].name)
                    != "lawful good")
                    ++bad;
                if (std::string(
                    d->rows[5].name)
                    != "lawful neutral")
                    ++bad;
                if (std::string(
                    d->rows[6].name)
                    != "neutral")
                    ++bad;
                if (std::string(
                    d->rows[7].name)
                    != "neutral evil")
                    ++bad;
                if (std::string(
                    d->rows[8].name)
                    != "neutral good")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_knowing");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "dm_sage_knowingRowCount"
                        || d->pins[0].value != 4
                        || (int)d->tables.size() != 2)
                        ++bad;
                    if (d->tables[0].name
                        != "know_lo"
                        || (int)d->tables[0]
                            .values.size() != 12)
                        ++bad;
                    if (d->tables[1].name
                        != "know_hi"
                        || (int)d->tables[1]
                            .values.size() != 12)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_sage_knowing"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_sage_knowing"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_sage_knowing"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_sage_knowing"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "scope_0")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "scope_1")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "scope_2")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "scope_3")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_discovery");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "dm_sage_discoveryRowCount"
                        || d->pins[0].value != 4
                        || (int)d->tables.size() != 5)
                        ++bad;
                    if (d->tables[0].name
                        != "cost_per_day"
                        || (int)d->tables[0]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[1].name
                        != "free_spread_percent"
                        || (int)d->tables[1]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[2].name
                        != "time_lo"
                        || (int)d->tables[2]
                            .values.size() != 12)
                        ++bad;
                    if (d->tables[3].name
                        != "time_hi"
                        || (int)d->tables[3]
                            .values.size() != 12)
                        ++bad;
                    if (d->tables[4].name
                        != "time_unit"
                        || (int)d->tables[4]
                            .values.size() != 12)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_sage_discovery"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_sage_discovery"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_sage_discovery"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_sage_discovery"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "scope_0")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "scope_1")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "scope_2")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "scope_3")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_terms");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 3
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "dm_sage_termsRowCount"
                        || d->pins[0].value != 3
                        || (int)d->tables.size() != 7)
                        ++bad;
                    if (d->tables[0].name
                        != "offer_lo"
                        || (int)d->tables[0]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[1].name
                        != "offer_hi"
                        || (int)d->tables[1]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[2].name
                        != "eff_milestone_cost"
                        || (int)d->tables[2]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[3].name
                        != "eff_milestone_percent"
                        || (int)d->tables[3]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[4].name
                        != "improve_cost"
                        || (int)d->tables[4]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[5].name
                        != "improve_months"
                        || (int)d->tables[5]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[6].name
                        != "improve_max"
                        || (int)d->tables[6]
                            .values.size() != 4)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_sage_terms"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_sage_terms"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_sage_terms"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "offer_200_1200")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "offer_200_1200")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "offer_20000_20000")
                    ++bad;
                }
            }
        }
        printf("R1054 sage registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. fields + categories -------------------
        {
            const int wantSgFieldLo[] = {
                1, 31, 51, 61, 71, 81, 91,
            };
            for (int f = 0; f < 7;
                 ++f)
                if (rules::sageFieldLo(f)
                    != wantSgFieldLo[f])
                    ++bad;
            const int wantSgFieldHi[] = {
                30, 50, 60, 70, 80, 90, 100,
            };
            for (int f = 0; f < 7;
                 ++f)
                if (rules::sageFieldHi(f)
                    != wantSgFieldHi[f])
                    ++bad;
            const int wantSgFieldCategoryCount[] = {
                12, 11, 8, 10, 10, 8, 9,
            };
            for (int f = 0; f < 7;
                 ++f)
                if (rules::sageFieldCategoryCount(f)
                    != wantSgFieldCategoryCount[f])
                    ++bad;
            const int wantSgFieldCategoryFirst[] = {
                0, 12, 23, 31, 41, 51, 59,
            };
            for (int f = 0; f < 7;
                 ++f)
                if (rules::sageFieldCategoryFirst(f)
                    != wantSgFieldCategoryFirst[f])
                    ++bad;
            const int wantSgSpellKind[] = {
                0, 0, 0, 0, 1, 1, 2,
            };
            for (int f = 0; f < 7;
                 ++f)
                if (rules::sageSpellKind(f)
                    != wantSgSpellKind[f])
                    ++bad;
            const int wantSgBandLo[] = {
                1, 11, 31, 51, 71, 91,
            };
            for (int b = 0; b < 6;
                 ++b)
                if (rules::sageFieldsBandLo(b)
                    != wantSgBandLo[b])
                    ++bad;
            const int wantSgBandHi[] = {
                10, 30, 50, 70, 90, 100,
            };
            for (int b = 0; b < 6;
                 ++b)
                if (rules::sageFieldsBandHi(b)
                    != wantSgBandHi[b])
                    ++bad;
            const int wantSgBandMinor[] = {
                1, 1, 1, 2, 2, 2,
            };
            for (int b = 0; b < 6;
                 ++b)
                if (rules::sageFieldsBandMinor(b)
                    != wantSgBandMinor[b])
                    ++bad;
            const int wantSgBandSpecial[] = {
                2, 3, 4, 2, 3, 4,
            };
            for (int b = 0; b < 6;
                 ++b)
                if (rules::sageFieldsBandSpecial(b)
                    != wantSgBandSpecial[b])
                    ++bad;
            const int wantSgCategoryField[] = {
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
                2, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                3, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                4, 5, 5, 5, 5, 5, 5, 5, 5, 6,
                6, 6, 6, 6, 6, 6, 6, 6,
            };
            for (int i = 0; i < 68;
                 ++i)
                if (rules::sageCategoryField(i)
                    != wantSgCategoryField[i])
                    ++bad;
            if (std::string(
                rules::sageFieldName(0))
                != "Humankind")
                ++bad;
            if (std::string(
                rules::sageFieldName(1))
                != "Demi-Humankind")
                ++bad;
            if (std::string(
                rules::sageFieldName(2))
                != "Humanoids & Giantkind")
                ++bad;
            if (std::string(
                rules::sageFieldName(3))
                != "Physical Universe(s)")
                ++bad;
            if (std::string(
                rules::sageFieldName(4))
                != "Fauna")
                ++bad;
            if (std::string(
                rules::sageFieldName(5))
                != "Flora")
                ++bad;
            if (std::string(
                rules::sageFieldName(6))
                != "Supernatural & Unusual")
                ++bad;
            if (std::string(
                rules::sageCategoryName(0))
                != "Art & Music")
                ++bad;
            if (std::string(
                rules::sageCategoryName(1))
                != "Biology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(2))
                != "Demography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(3))
                != "History")
                ++bad;
            if (std::string(
                rules::sageCategoryName(4))
                != "Languages")
                ++bad;
            if (std::string(
                rules::sageCategoryName(5))
                != "Legends & Folklore")
                ++bad;
            if (std::string(
                rules::sageCategoryName(6))
                != "Law & Customs")
                ++bad;
            if (std::string(
                rules::sageCategoryName(7))
                != "Philosophy & Ethics")
                ++bad;
            if (std::string(
                rules::sageCategoryName(8))
                != "Politics & Genealogy")
                ++bad;
            if (std::string(
                rules::sageCategoryName(9))
                != "Psychology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(10))
                != "Sociology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(11))
                != "Theology & Myth")
                ++bad;
            if (std::string(
                rules::sageCategoryName(12))
                != "Art & Music")
                ++bad;
            if (std::string(
                rules::sageCategoryName(13))
                != "Biology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(14))
                != "Demography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(15))
                != "Languages")
                ++bad;
            if (std::string(
                rules::sageCategoryName(16))
                != "Legends & Folklore")
                ++bad;
            if (std::string(
                rules::sageCategoryName(17))
                != "Law & Customs")
                ++bad;
            if (std::string(
                rules::sageCategoryName(18))
                != "Philosophy & Ethics")
                ++bad;
            if (std::string(
                rules::sageCategoryName(19))
                != "Politics & Genealogy")
                ++bad;
            if (std::string(
                rules::sageCategoryName(20))
                != "Psychology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(21))
                != "Sociology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(22))
                != "Theology & Myth")
                ++bad;
            if (std::string(
                rules::sageCategoryName(23))
                != "Biology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(24))
                != "Demography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(25))
                != "History")
                ++bad;
            if (std::string(
                rules::sageCategoryName(26))
                != "Languages")
                ++bad;
            if (std::string(
                rules::sageCategoryName(27))
                != "Legends & Folklore")
                ++bad;
            if (std::string(
                rules::sageCategoryName(28))
                != "Law & Customs")
                ++bad;
            if (std::string(
                rules::sageCategoryName(29))
                != "Sociology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(30))
                != "Theology & Myth")
                ++bad;
            if (std::string(
                rules::sageCategoryName(31))
                != "Architecture & Engineering")
                ++bad;
            if (std::string(
                rules::sageCategoryName(32))
                != "Astronomy")
                ++bad;
            if (std::string(
                rules::sageCategoryName(33))
                != "Chemistry")
                ++bad;
            if (std::string(
                rules::sageCategoryName(34))
                != "Geography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(35))
                != "Geology & Mineralogy")
                ++bad;
            if (std::string(
                rules::sageCategoryName(36))
                != "Mathematics")
                ++bad;
            if (std::string(
                rules::sageCategoryName(37))
                != "Meteorology & Climatology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(38))
                != "Oceanography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(39))
                != "Physics")
                ++bad;
            if (std::string(
                rules::sageCategoryName(40))
                != "Topography & Cartography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(41))
                != "Amphibians")
                ++bad;
            if (std::string(
                rules::sageCategoryName(42))
                != "Arachnids")
                ++bad;
            if (std::string(
                rules::sageCategoryName(43))
                != "Avians")
                ++bad;
            if (std::string(
                rules::sageCategoryName(44))
                != "Cephalopods & Echinoderms")
                ++bad;
            if (std::string(
                rules::sageCategoryName(45))
                != "Crustaceans & Mollusks")
                ++bad;
            if (std::string(
                rules::sageCategoryName(46))
                != "Ichthyoids")
                ++bad;
            if (std::string(
                rules::sageCategoryName(47))
                != "Insects")
                ++bad;
            if (std::string(
                rules::sageCategoryName(48))
                != "Mammals")
                ++bad;
            if (std::string(
                rules::sageCategoryName(49))
                != "Marsupials")
                ++bad;
            if (std::string(
                rules::sageCategoryName(50))
                != "Reptiles")
                ++bad;
            if (std::string(
                rules::sageCategoryName(51))
                != "Bushes & Shrubs")
                ++bad;
            if (std::string(
                rules::sageCategoryName(52))
                != "Flowers")
                ++bad;
            if (std::string(
                rules::sageCategoryName(53))
                != "Fungi")
                ++bad;
            if (std::string(
                rules::sageCategoryName(54))
                != "Grasses & Grains")
                ++bad;
            if (std::string(
                rules::sageCategoryName(55))
                != "Herbs")
                ++bad;
            if (std::string(
                rules::sageCategoryName(56))
                != "Mosses & Ferns")
                ++bad;
            if (std::string(
                rules::sageCategoryName(57))
                != "Trees")
                ++bad;
            if (std::string(
                rules::sageCategoryName(58))
                != "Weeds")
                ++bad;
            if (std::string(
                rules::sageCategoryName(59))
                != "Astrology & Numerology")
                ++bad;
            if (std::string(
                rules::sageCategoryName(60))
                != "Cryptography")
                ++bad;
            if (std::string(
                rules::sageCategoryName(61))
                != "Divination")
                ++bad;
            if (std::string(
                rules::sageCategoryName(62))
                != "Dweomercraeft")
                ++bad;
            if (std::string(
                rules::sageCategoryName(63))
                != "Heraldry, Signs & Sigils")
                ++bad;
            if (std::string(
                rules::sageCategoryName(64))
                != "Medicine")
                ++bad;
            if (std::string(
                rules::sageCategoryName(65))
                != "Metaphysics")
                ++bad;
            if (std::string(
                rules::sageCategoryName(66))
                != "Planes (Astral, Elemental & Ethereal)")
                ++bad;
            if (std::string(
                rules::sageCategoryName(67))
                != "Planes (Outer)")
                ++bad;
        }
        printf("R1054 sage fields and categories audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. characteristics ----------------------
        {
            const int wantSgAlignLo[] = {
                1, 6, 11, 21, 31, 41, 61, 81, 91,
            };
            for (int b = 0; b < 9;
                 ++b)
                if (rules::sageAlignLo(b)
                    != wantSgAlignLo[b])
                    ++bad;
            const int wantSgAlignHi[] = {
                5, 10, 20, 30, 40, 60, 80, 90, 100,
            };
            for (int b = 0; b < 9;
                 ++b)
                if (rules::sageAlignHi(b)
                    != wantSgAlignHi[b])
                    ++bad;
            const int wantSgAbilityDice[] = {
                8, 4, 6, 6, 6, 6,
            };
            for (int a = 0; a < 6;
                 ++a)
                if (rules::sageAbilityDice(a)
                    != wantSgAbilityDice[a])
                    ++bad;
            const int wantSgAbilityDiceCount[] = {
                1, 1, 1, 3, 2, 2,
            };
            for (int a = 0; a < 6;
                 ++a)
                if (rules::sageAbilityDiceCount(a)
                    != wantSgAbilityDiceCount[a])
                    ++bad;
            const int wantSgAbilityPlus[] = {
                7, 14, 12, 0, 3, 2,
            };
            for (int a = 0; a < 6;
                 ++a)
                if (rules::sageAbilityPlus(a)
                    != wantSgAbilityPlus[a])
                    ++bad;
            if (std::string(
                rules::sageAlignName(0))
                != "chaotic evil")
                ++bad;
            if (std::string(
                rules::sageAlignName(1))
                != "chaotic good")
                ++bad;
            if (std::string(
                rules::sageAlignName(2))
                != "chaotic neutral")
                ++bad;
            if (std::string(
                rules::sageAlignName(3))
                != "lawful evil")
                ++bad;
            if (std::string(
                rules::sageAlignName(4))
                != "lawful good")
                ++bad;
            if (std::string(
                rules::sageAlignName(5))
                != "lawful neutral")
                ++bad;
            if (std::string(
                rules::sageAlignName(6))
                != "neutral")
                ++bad;
            if (std::string(
                rules::sageAlignName(7))
                != "neutral evil")
                ++bad;
            if (std::string(
                rules::sageAlignName(8))
                != "neutral good")
                ++bad;
        }
        printf("R1054 sage characteristics audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. grids + terms ------------------------
        {
            const int wantSgKnowLo[] = {
                31, 11, -1, 46, 31, 11, 61, 57, 26, 81,
                76, 61,
            };
            for (int s = 0; s < 4; ++s)
                for (int n = 0; n < 3; ++n)
                    if (rules::sageKnowLo(s, n)
                        != wantSgKnowLo[
                            s * 3 + n])
                        ++bad;
            const int wantSgKnowHi[] = {
                50, 20, -1, 65, 40, 20, 80, 60, 35, 100,
                96, 80,
            };
            for (int s = 0; s < 4; ++s)
                for (int n = 0; n < 3; ++n)
                    if (rules::sageKnowHi(s, n)
                        != wantSgKnowHi[
                            s * 3 + n])
                        ++bad;
            const int wantSgTimeLo[] = {
                1, 2, -1, 1, 2, 5, 1, 1, 3, 1,
                1, 2,
            };
            for (int s = 0; s < 4; ++s)
                for (int n = 0; n < 3; ++n)
                    if (rules::sageTimeLo(s, n)
                        != wantSgTimeLo[
                            s * 3 + n])
                        ++bad;
            const int wantSgTimeHi[] = {
                6, 24, -1, 4, 20, 40, 3, 12, 30, 2,
                10, 12,
            };
            for (int s = 0; s < 4; ++s)
                for (int n = 0; n < 3; ++n)
                    if (rules::sageTimeHi(s, n)
                        != wantSgTimeHi[
                            s * 3 + n])
                        ++bad;
            const int wantSgTimeUnit[] = {
                0, 2, 0, 0, 2, 2, 0, 2, 2, 0,
                1, 2,
            };
            for (int s = 0; s < 4; ++s)
                for (int n = 0; n < 3; ++n)
                    if (rules::sageTimeUnit(s, n)
                        != wantSgTimeUnit[
                            s * 3 + n])
                        ++bad;
            const int wantSgCostPerDay[] = {
                100, 1000, 500, 200,
            };
            for (int scope = 0; scope < 4;
                 ++scope)
                if (rules::sageCostPerDay(scope)
                    != wantSgCostPerDay[scope])
                    ++bad;
            const int wantSgFreeSpreadPercent[] = {
                20, 20, 20, 80,
            };
            for (int scope = 0; scope < 4;
                 ++scope)
                if (rules::sageFreeSpreadPercent(scope)
                    != wantSgFreeSpreadPercent[scope])
                    ++bad;
            const int wantSgOfferLo[] = {
                200, 200, 20000,
            };
            for (int i = 0; i < 3;
                 ++i)
                if (rules::sageOfferLo(i)
                    != wantSgOfferLo[i])
                    ++bad;
            const int wantSgOfferHi[] = {
                1200, 1200, 20000,
            };
            for (int i = 0; i < 3;
                 ++i)
                if (rules::sageOfferHi(i)
                    != wantSgOfferHi[i])
                    ++bad;
            const int wantSgEffMilestoneCost[] = {
                20000, 60000, 100000,
            };
            for (int i = 0; i < 3;
                 ++i)
                if (rules::sageEffMilestoneCost(i)
                    != wantSgEffMilestoneCost[i])
                    ++bad;
            const int wantSgEffMilestonePercent[] = {
                50, 90, 100,
            };
            for (int i = 0; i < 3;
                 ++i)
                if (rules::sageEffMilestonePercent(i)
                    != wantSgEffMilestonePercent[i])
                    ++bad;
            const int wantSgImproveCost[] = {
                5000, 10000, 100000, 200000,
            };
            for (int i = 0; i < 4;
                 ++i)
                if (rules::sageImproveCost(i)
                    != wantSgImproveCost[i])
                    ++bad;
            const int wantSgImproveMonths[] = {
                1, 1, 24, 24,
            };
            for (int i = 0; i < 4;
                 ++i)
                if (rules::sageImproveMonths(i)
                    != wantSgImproveMonths[i])
                    ++bad;
            const int wantSgImproveMax[] = {
                5, 5, 3, -1,
            };
            for (int i = 0; i < 4;
                 ++i)
                if (rules::sageImproveMax(i)
                    != wantSgImproveMax[i])
                    ++bad;
        }
        printf("R1054 sage grids and terms audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. seam ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_sage");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_fields");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "field_lo")
                            continue;
                        got = 1;
                        for (int f = 0;
                             f < 7;
                             ++f)
                            if ((int)t.values[f]
                                != rules::sageFieldLo(f))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "field_hi")
                            continue;
                        got = 1;
                        for (int f = 0;
                             f < 7;
                             ++f)
                            if ((int)t.values[f]
                                != rules::sageFieldHi(f))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "field_category_count")
                            continue;
                        got = 1;
                        for (int f = 0;
                             f < 7;
                             ++f)
                            if ((int)t.values[f]
                                != rules::sageFieldCategoryCount(f))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "field_category_first")
                            continue;
                        got = 1;
                        for (int f = 0;
                             f < 7;
                             ++f)
                            if ((int)t.values[f]
                                != rules::sageFieldCategoryFirst(f))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "spell_kind")
                            continue;
                        got = 1;
                        for (int f = 0;
                             f < 7;
                             ++f)
                            if ((int)t.values[f]
                                != rules::sageSpellKind(f))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "band_lo")
                            continue;
                        got = 1;
                        for (int b = 0;
                             b < 6;
                             ++b)
                            if ((int)t.values[b]
                                != rules::sageFieldsBandLo(b))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "band_hi")
                            continue;
                        got = 1;
                        for (int b = 0;
                             b < 6;
                             ++b)
                            if ((int)t.values[b]
                                != rules::sageFieldsBandHi(b))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "band_minor")
                            continue;
                        got = 1;
                        for (int b = 0;
                             b < 6;
                             ++b)
                            if ((int)t.values[b]
                                != rules::sageFieldsBandMinor(b))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "band_special")
                            continue;
                        got = 1;
                        for (int b = 0;
                             b < 6;
                             ++b)
                            if ((int)t.values[b]
                                != rules::sageFieldsBandSpecial(b))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                for (int f = 0; f < 7;
                     ++f)
                    if (d->rows[f].name !=
                        rules::sageFieldName(f))
                        ++bad;
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_categories");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "category_field")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 68;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageCategoryField(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                for (int i = 0; i < 68;
                     ++i)
                    if (d->rows[i].name !=
                        rules::sageCategoryName(i))
                        ++bad;
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_characteristics");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "align_lo")
                            continue;
                        got = 1;
                        for (int b = 0;
                             b < 9;
                             ++b)
                            if ((int)t.values[b]
                                != rules::sageAlignLo(b))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "align_hi")
                            continue;
                        got = 1;
                        for (int b = 0;
                             b < 9;
                             ++b)
                            if ((int)t.values[b]
                                != rules::sageAlignHi(b))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "ability_dice")
                            continue;
                        got = 1;
                        for (int a = 0;
                             a < 6;
                             ++a)
                            if ((int)t.values[a]
                                != rules::sageAbilityDice(a))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "ability_dice_count")
                            continue;
                        got = 1;
                        for (int a = 0;
                             a < 6;
                             ++a)
                            if ((int)t.values[a]
                                != rules::sageAbilityDiceCount(a))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "ability_plus")
                            continue;
                        got = 1;
                        for (int a = 0;
                             a < 6;
                             ++a)
                            if ((int)t.values[a]
                                != rules::sageAbilityPlus(a))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                for (int b = 0; b < 9;
                     ++b)
                    if (d->rows[b].name !=
                        rules::sageAlignName(b))
                        ++bad;
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_knowing");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "know_lo")
                            continue;
                        got = 1;
                        for (int s = 0; s < 4;
                             ++s)
                            for (int n = 0;
                                 n < 3;
                                 ++n)
                                if ((int)t
                                    .values[
                                    s * 3 + n]
                                    !=
                                    rules::sageKnowLo(
                                        s, n))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "know_hi")
                            continue;
                        got = 1;
                        for (int s = 0; s < 4;
                             ++s)
                            for (int n = 0;
                                 n < 3;
                                 ++n)
                                if ((int)t
                                    .values[
                                    s * 3 + n]
                                    !=
                                    rules::sageKnowHi(
                                        s, n))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_discovery");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "cost_per_day")
                            continue;
                        got = 1;
                        for (int scope = 0;
                             scope < 4;
                             ++scope)
                            if ((int)t.values[scope]
                                != rules::sageCostPerDay(scope))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "free_spread_percent")
                            continue;
                        got = 1;
                        for (int scope = 0;
                             scope < 4;
                             ++scope)
                            if ((int)t.values[scope]
                                != rules::sageFreeSpreadPercent(scope))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "time_lo")
                            continue;
                        got = 1;
                        for (int s = 0; s < 4;
                             ++s)
                            for (int n = 0;
                                 n < 3;
                                 ++n)
                                if ((int)t
                                    .values[
                                    s * 3 + n]
                                    !=
                                    rules::sageTimeLo(
                                        s, n))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "time_hi")
                            continue;
                        got = 1;
                        for (int s = 0; s < 4;
                             ++s)
                            for (int n = 0;
                                 n < 3;
                                 ++n)
                                if ((int)t
                                    .values[
                                    s * 3 + n]
                                    !=
                                    rules::sageTimeHi(
                                        s, n))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "time_unit")
                            continue;
                        got = 1;
                        for (int s = 0; s < 4;
                             ++s)
                            for (int n = 0;
                                 n < 3;
                                 ++n)
                                if ((int)t
                                    .values[
                                    s * 3 + n]
                                    !=
                                    rules::sageTimeUnit(
                                        s, n))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_sage_terms");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "offer_lo")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 3;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageOfferLo(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "offer_hi")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 3;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageOfferHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "eff_milestone_cost")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 3;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageEffMilestoneCost(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "eff_milestone_percent")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 3;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageEffMilestonePercent(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "improve_cost")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 4;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageImproveCost(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "improve_months")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 4;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageImproveMonths(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "improve_max")
                            continue;
                        got = 1;
                        for (int i = 0;
                             i < 4;
                             ++i)
                            if ((int)t.values[i]
                                != rules::sageImproveMax(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
            }
        }
        printf("R1054 sage registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. edges --------------------------------
        {
            if (rules::sageFieldLo(-1)
                != 1)
                ++bad;
            if (rules::sageFieldLo(7)
                != 91)
                ++bad;
            if (rules::sageFieldHi(-1)
                != 30)
                ++bad;
            if (rules::sageFieldHi(7)
                != 100)
                ++bad;
            if (rules::sageFieldCategoryCount(-1)
                != 12)
                ++bad;
            if (rules::sageFieldCategoryCount(7)
                != 9)
                ++bad;
            if (rules::sageFieldCategoryFirst(-1)
                != 0)
                ++bad;
            if (rules::sageFieldCategoryFirst(7)
                != 59)
                ++bad;
            if (rules::sageSpellKind(-1)
                != 0)
                ++bad;
            if (rules::sageSpellKind(7)
                != 2)
                ++bad;
            if (rules::sageFieldsBandLo(-1)
                != 1)
                ++bad;
            if (rules::sageFieldsBandLo(6)
                != 91)
                ++bad;
            if (rules::sageFieldsBandHi(-1)
                != 10)
                ++bad;
            if (rules::sageFieldsBandHi(6)
                != 100)
                ++bad;
            if (rules::sageFieldsBandMinor(-1)
                != 1)
                ++bad;
            if (rules::sageFieldsBandMinor(6)
                != 2)
                ++bad;
            if (rules::sageFieldsBandSpecial(-1)
                != 2)
                ++bad;
            if (rules::sageFieldsBandSpecial(6)
                != 4)
                ++bad;
            if (rules::sageCategoryField(-1)
                != 0)
                ++bad;
            if (rules::sageCategoryField(68)
                != 6)
                ++bad;
            if (rules::sageAlignLo(-1)
                != 1)
                ++bad;
            if (rules::sageAlignLo(9)
                != 91)
                ++bad;
            if (rules::sageAlignHi(-1)
                != 5)
                ++bad;
            if (rules::sageAlignHi(9)
                != 100)
                ++bad;
            if (rules::sageAbilityDice(-1)
                != 8)
                ++bad;
            if (rules::sageAbilityDice(6)
                != 6)
                ++bad;
            if (rules::sageAbilityDiceCount(-1)
                != 1)
                ++bad;
            if (rules::sageAbilityDiceCount(6)
                != 2)
                ++bad;
            if (rules::sageAbilityPlus(-1)
                != 7)
                ++bad;
            if (rules::sageAbilityPlus(6)
                != 2)
                ++bad;
            if (rules::sageCostPerDay(-1)
                != 100)
                ++bad;
            if (rules::sageCostPerDay(4)
                != 200)
                ++bad;
            if (rules::sageFreeSpreadPercent(-1)
                != 20)
                ++bad;
            if (rules::sageFreeSpreadPercent(4)
                != 80)
                ++bad;
            if (rules::sageOfferLo(-1)
                != 200)
                ++bad;
            if (rules::sageOfferLo(3)
                != 20000)
                ++bad;
            if (rules::sageOfferHi(-1)
                != 1200)
                ++bad;
            if (rules::sageOfferHi(3)
                != 20000)
                ++bad;
            if (rules::sageEffMilestoneCost(-1)
                != 20000)
                ++bad;
            if (rules::sageEffMilestoneCost(3)
                != 100000)
                ++bad;
            if (rules::sageEffMilestonePercent(-1)
                != 50)
                ++bad;
            if (rules::sageEffMilestonePercent(3)
                != 100)
                ++bad;
            if (rules::sageImproveCost(-1)
                != 5000)
                ++bad;
            if (rules::sageImproveCost(4)
                != 200000)
                ++bad;
            if (rules::sageImproveMonths(-1)
                != 1)
                ++bad;
            if (rules::sageImproveMonths(4)
                != 24)
                ++bad;
            if (rules::sageImproveMax(-1)
                != 5)
                ++bad;
            if (rules::sageImproveMax(4)
                != -1)
                ++bad;
            if (rules::sageKnowLo(-1, -1)
                != 31)
                ++bad;
            if (rules::sageKnowLo(9, 9)
                != 61)
                ++bad;
            if (rules::sageKnowHi(-1, -1)
                != 50)
                ++bad;
            if (rules::sageKnowHi(9, 9)
                != 80)
                ++bad;
            if (rules::sageTimeLo(-1, -1)
                != 1)
                ++bad;
            if (rules::sageTimeLo(9, 9)
                != 2)
                ++bad;
            if (rules::sageTimeHi(-1, -1)
                != 6)
                ++bad;
            if (rules::sageTimeHi(9, 9)
                != 12)
                ++bad;
            if (rules::sageTimeUnit(-1, -1)
                != 0)
                ++bad;
            if (rules::sageTimeUnit(9, 9)
                != 2)
                ++bad;
            if (std::string(
                rules::sageFieldName(-1))
                != "Humankind")
                ++bad;
            if (std::string(
                rules::sageFieldName(7))
                != "Supernatural & Unusual")
                ++bad;
            if (std::string(
                rules::sageCategoryName(-1))
                != "Art & Music")
                ++bad;
            if (std::string(
                rules::sageCategoryName(68))
                != "Planes (Outer)")
                ++bad;
            if (std::string(
                rules::sageAlignName(-1))
                != "chaotic evil")
                ++bad;
            if (std::string(
                rules::sageAlignName(9))
                != "neutral good")
                ++bad;
            if (rules::sageKnowNone(0, 2)
                != 1)
                ++bad;
            if (rules::sageKnowNone(0, 0)
                != 0)
                ++bad;
            if (rules::sageTimeNone(0, 2)
                != 1)
                ++bad;
            if (rules::sageTimeNone(0, 0)
                != 0)
                ++bad;
            if (rules::sageFieldCount() != 7)
                ++bad;
            if (rules::sageCategoryCount() != 68)
                ++bad;
            if (rules::sageFieldsBandCount() != 6)
                ++bad;
            if (rules::sageAbilityCount() != 6)
                ++bad;
            if (rules::sageAlignBandCount() != 9)
                ++bad;
            if (rules::sageHpDiceCount() != 8)
                ++bad;
            if (rules::sageHpDie() != 4)
                ++bad;
            if (rules::sageSpellKindCount() != 3)
                ++bad;
            if (rules::sageSpellMaxDie() != 4)
                ++bad;
            if (rules::sageSpellMaxPlus() != 2)
                ++bad;
            if (rules::sageSpellMaxLo() != 3)
                ++bad;
            if (rules::sageSpellMaxHi() != 6)
                ++bad;
            if (rules::sageSpellPerLevelLo() != 1)
                ++bad;
            if (rules::sageSpellPerLevelHi() != 4)
                ++bad;
            if (rules::sageSpellReadyPerLevel() != 1)
                ++bad;
            if (rules::sageOfferCount() != 3)
                ++bad;
            if (rules::sageEffMilestoneCount() != 3)
                ++bad;
            if (rules::sageEffStepCost() != 1000)
                ++bad;
            if (rules::sageEffHighCostPerPercent() != 4000)
                ++bad;
            if (rules::sageImproveCount() != 4)
                ++bad;
            if (rules::sageUnknownPercentLo() != 51)
                ++bad;
            if (rules::sageUnknownPercentHi() != 100)
                ++bad;
            if (rules::sageUnknownCostDivisor() != 2)
                ++bad;
            if (rules::sageShortTermCostPerDay() != 100)
                ++bad;
            if (rules::sageShortTermMaxDays() != 7)
                ++bad;
            if (rules::sageShortTermCooldownMonths() != 1)
                ++bad;
            if (rules::sagePermanentHireOnly() != 1)
                ++bad;
        }
        printf("R1054 sage registry edges audit: bad %d\n", bad);
    }
