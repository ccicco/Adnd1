-- ua: promoted from rules/ua/uascharts.h (the The UA APPENDIX S clerical);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 407,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA APPENDIX S clerical",
      "provenance" = "quick-reference charts, R407: the five charts (pp. 121-122) - the second data round riding the R405 deity layer seam. The R406 stat-block precedent: the scan-clean cells pin; the pantheon prose stays open.  Each chart prints one row per deity, 8 columns: DEITY, the SPHERE OF CONTROL, the RAIMENT head and body, the color(s), the HOLY DAYS, and the SACRIFICE/PROPITIATION frequency and form.  The pantheon order rides the R406 stat table (dwarves 0-4, elves 5-9, halflings 10-13, gnomes 14-17, orcs 18-22).  The sacred-animal table: 13 named (Aerdrie any bird, Solonor stag; the halfling four; Baervan raccoon, Urdlen white mole, Segojan badger; Bahgtru ox, Shargaas bat, Yurtrus skeleton, Luthic cave bear); null = none (the five dwarves - the print says NO dwarven god has a sacred animal - plus Flandal and Ilneval).  The cleric gender reads: the dwarven split (males of the male deities, females of the female ones), the elf and halfling either-gender, the all-male never-druid gnomish clerics.",
    },
  "consts" = { {
      "name" = "uscChartRowCount",
      "value" = 23,
      "comment" = "",
    }, {
      "name" = "uscChartCount",
      "value" = 5,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uscDwarfClericGenderSplit",
      "value" = true,
      "comment" = "The cleric gender reads. The dwarven split: only male dwarves may become clerics of the male deities, females of the female ones.",
    }, {
      "name" = "uscElfClericsEitherGender",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uscHalflingClericsEitherGender",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uscGnomeClericsNeverDruids",
      "value" = true,
      "comment" = "Gnomish clerics are never druids and are all males.",
    }, {
      "name" = "uscGnomishClericsAllMale",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uscStrEq",
      "comment" = "A tiny string equality (no library includes in the header).",
      "kind" = "header pin",
      "body" = "int i = 0; while (a[i] != 0 && b[i] != 0) { if (a[i] != b[i]) return false; ++i; } return a[i] == b[i];",
    }, {
      "name" = "uscChartRow",
      "comment" = "The five charts, 23 rows in the pantheon order of the R406 stat table.",
      "kind" = "header pin",
      "body" = "static const UscChartRow T[23] = { // ---- the dwarves ---- { \"Clanggedin\", \"war, battle\", \"war helm\", \"chain mail\", \"silver\", \"before battle\", \"before battle\", \"weapons\" }, { \"Vergadain\", \"suspicion, trickery\", \"helmet\", \"chain mail\", \"gold\", \"full moon\", \"monthly\", \"gold\" }, { \"Dumathoin\", \"secrets, earth\", \"bare\", \"leather\", \"brown\", \"new moon\", \"monthly\", \"gems & jewels\" }, { \"Abbathor\", \"evil, greed\", \"leather cap\", \"leather\", \"red\", \"solar eclipses\", \"annually\", \"blood & gems\" }, { \"Berronar\", \"safety, truth\", \"silvered helm\", \"chain mail\", \"silver\", \"new year's day\", \"annually\", \"silver\" }, // ---- the elves ---- { \"Aerdrie\", \"air, weather, birds\", \"one feather\", \"sky-blue robes\", \"sky blue\", \"spring & fall equinoxes\", \"semi-annual\", \"beautiful feathers\" }, { \"Erevan\", \"mischief, change, thieves\", \"leather cap\", \"leather armor\", \"black\", \"eclipses\", \"varies\", \"stolen treasures\" }, { \"Solonor\", \"archery, hunting\", \"green hood\", \"elfin chain & silver\", \"leaf green\", \"full moon\", \"monthly\", \"hunting trophies\" }, { \"Hanali\", \"romance, beauty\", \"bare\", \"gold robes\", \"gold\", \"full moon\", \"monthly\", \"beautiful objects\" }, { \"Labelas\", \"longevity, time\", \"bare\", \"gray robes\", \"light gray\", \"sunset\", \"daily\", \"prayers & knowledge\" }, // ---- the halflings ---- { \"Sheela\", \"agriculture, weather\", \"bare\", \"green robes\", \"green\", \"full moon\", \"monthly\", \"seeds\" }, { \"Arvoreen\", \"defense, warriors\", \"helmet\", \"chainmail\", \"silver\", \"before battle\", \"varies\", \"silvered weapons\" }, { \"Cyrrollalee\", \"trust, protection\", \"bare\", \"brown robes\", \"brown\", \"first day of month\", \"monthly\", \"prayers\" }, { \"Brandobaris\", \"thieves\", \"feathered cap\", \"leather armor\", \"gray\", \"new moon\", \"monthly\", \"stolen items\" }, // ---- the gnomes ---- { \"Baervan\", \"adventure, thieves\", \"green cap\", \"brown clothes\", \"wood brown\", \"full moon\", \"monthly\", \"treasure items\" }, { \"Urdlen\", \"evil\", \"bare\", \"white cloak\", \"white\", \"winter solstice\", \"annually\", \"blood & jewels\" }, { \"Segojan\", \"earth, nature\", \"fur cap\", \"leather armor\", \"gray & dark brown\", \"first day of each season\", \"quarterly\", \"gemstones\" }, { \"Flandal\", \"metalworking\", \"steel helm\", \"leather armor\", \"red\", \"midsummer's day\", \"annually\", \"forged weapons\" }, // ---- the orcs ---- { \"Bahgtru\", \"strength\", \"bare\", \"loincloth\", \"n/a\", \"battle days\", \"before battle\", \"bones of enemies\" }, { \"Shargaas\", \"night, thieves\", \"leather cap\", \"leather armor\", \"red & black\", \"new moon\", \"monthly\", \"stolen items\" }, { \"Ilneval\", \"warriors\", \"red metal helmet\", \"red metal armor\", \"red\", \"battle days\", \"before & after battle\", \"blood & weapons\" }, { \"Yurtrus\", \"death, plague\", \"bare\", \"skins\", \"white\", \"full moon\", \"monthly\", \"sacrifices\" }, { \"Luthic\", \"caves, healing, females\", \"fur cap\", \"leather armor\", \"brown & black\", \"midwinter's day\", \"yearly\", \"treasures\" }, }; if (i < 0) i = 0; if (i > 22) i = 22; return T[i];",
    }, {
      "name" = "uscSacredAnimal",
      "comment" = "The sacred animals, by the same deity index; null = none.",
      "kind" = "string array",
      "count" = 23,
      "values" = { "", "", "", "", "", "any bird", "", "stag", "", "", "butterfly", "war dog", "squirrel", "mouse", "raccoon", "white mole", "badger", "", "ox", "bat", "", "skeleton", "cave bear" },
    }, {
      "name" = "uscNamedSacredAnimalCount",
      "comment" = "The named sacred animals (the non-null cells): 13.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uscSacredAnimal(i) != 0) ++n; return n;",
    }, {
      "name" = "uscFrequencyCount",
      "comment" = "The frequency drift catches: 10 rows print monthly, 4 print annually, 2 print before battle.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 23; ++i) if (uscStrEq(uscChartRow(i).freq, freq)) ++n; return n;",
    }, {
      "name" = "uscWorshipSite",
      "comment" = "R784: the worship-site strings - the print's place-of-worship reads, the prose under the five clerical charts (pp. 121-122). The kind codes and the cleric-gender grid pin in rules/worshipsites.h; the strings ride here, one row per deity in the registry order. The compilation's Hanali row carries Solonor's cells wholesale; the print's fountain-or-spring stands. Erevan's read rides the print's own \"can by worshiped\" typo in the prose.",
      "kind" = "string array",
      "count" = 23,
      "values" = { "battlefield", "underground temple", "underground temple", "underground temple", "underground temple", "open hilltops", "never the same place twice", "deep forest", "by a fountain or spring", "small grove", "open field", "anywhere", "the home", "anywhere", "forest clearing", "underground cavern", "subterranean temple", "underground forge", "battlefield", "anywhere", "anywhere", "underground crypt", "in a temple within a cave", "" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uscChartRowCount']() != 23  or m['uscChartRowCount']() !=m['uasDeityCount']()  or m['uscChartCount']() != 5  or m['uscChartCount']() !=m['nhdChartCount']()",
      "note" = "---- the census ----",
    }, {
      "expr" = "strcmp(m['uscChartRow'](0).name, \"Clanggedin\") != 0  or strcmp(m['uscChartRow'](0).sphere, \"war, battle\") != 0  or strcmp(m['uscChartRow'](0).head, \"war helm\") != 0  or strcmp(m['uscChartRow'](0).form, \"weapons\") != 0",
      "note" = "---- the spot checks ---- Clanggedin (the first row)",
    }, {
      "expr" = "strcmp(m['uscChartRow'](4).days, \"new year's day\") != 0",
      "note" = "Berronar: the new-year day",
    }, {
      "expr" = "strcmp(m['uscChartRow'](5).days, \"spring & fall equinoxes\") != 0",
      "note" = "Aerdrie: the equinoxes",
    }, {
      "expr" = "strcmp(m['uscChartRow'](7).body, \"elfin chain & silver\") != 0",
      "note" = "Solonor: the elfin chain",
    }, {
      "expr" = "strcmp(m['uscChartRow'](10).form, \"seeds\") != 0",
      "note" = "Sheela: the seeds",
    }, {
      "expr" = "strcmp(m['uscChartRow'](13).form, \"stolen items\") != 0",
      "note" = "Brandobaris: the stolen items",
    }, {
      "expr" = "strcmp(m['uscChartRow'](16).days, \"first day of each season\") != 0  or strcmp(m['uscChartRow'](16).freq, \"quarterly\") != 0",
      "note" = "Segojan: the season days",
    }, {
      "expr" = "strcmp(m['uscChartRow'](17).form, \"forged weapons\") != 0",
      "note" = "Flandal: the forged weapons",
    }, {
      "expr" = "strcmp(m['uscChartRow'](18).color, \"n/a\") != 0  or strcmp(m['uscChartRow'](18).form, \"bones of enemies\") != 0",
      "note" = "Bahgtru: the n/a color",
    }, {
      "expr" = "strcmp(m['uscChartRow'](20).freq, \"before & after battle\") != 0",
      "note" = "Ilneval: the two-sided days",
    }, {
      "expr" = "strcmp(m['uscChartRow'](22).sphere, \"caves, healing, females\") != 0  or strcmp(m['uscChartRow'](22).freq, \"yearly\") != 0  or strcmp(m['uscChartRow'](22).form, \"treasures\") != 0",
      "note" = "Luthic: the cave goddess",
    }, {
      "expr" = "m['uscNamedSacredAnimalCount']() != 13",
      "note" = "---- the sacred animals ----",
    }, {
      "expr" = "m['uscSacredAnimal'](0) != 0  or m['uscSacredAnimal'](1) != 0  or m['uscSacredAnimal'](2) != 0  or m['uscSacredAnimal'](3) != 0  or m['uscSacredAnimal'](4) != 0  or strcmp(m['uscSacredAnimal'](5), \"any bird\") != 0  or strcmp(m['uscSacredAnimal'](7), \"stag\") != 0  or strcmp(m['uscSacredAnimal'](10), \"butterfly\") != 0  or strcmp(m['uscSacredAnimal'](11), \"war dog\") != 0  or strcmp(m['uscSacredAnimal'](12), \"squirrel\") != 0  or strcmp(m['uscSacredAnimal'](13), \"mouse\") != 0  or strcmp(m['uscSacredAnimal'](14), \"raccoon\") != 0  or strcmp(m['uscSacredAnimal'](15), \"white mole\") != 0  or strcmp(m['uscSacredAnimal'](16), \"badger\") != 0  or m['uscSacredAnimal'](17) != 0  or strcmp(m['uscSacredAnimal'](18), \"ox\") != 0  or strcmp(m['uscSacredAnimal'](19), \"bat\") != 0  or m['uscSacredAnimal'](20) != 0  or strcmp(m['uscSacredAnimal'](21), \"skeleton\") != 0  or strcmp(m['uscSacredAnimal'](22), \"cave bear\") != 0",
      "note" = "the dwarven no-animal read: all five null",
    }, {
      "expr" = "m['uscDwarfClericGenderSplit']() != 1  or  m['uscElfClericsEitherGender']() != 1  or  m['uscHalflingClericsEitherGender']() != 1  or  m['uscGnomeClericsNeverDruids']() != 1  or  m['uscGnomishClericsAllMale']() != 1",
      "note" = "---- the cleric gender reads ----",
    }, {
      "expr" = "m['uscFrequencyCount'](\"monthly\") != 10  or m['uscFrequencyCount'](\"annually\") != 4  or m['uscFrequencyCount']( \"before battle\") != 2  or m['uscFrequencyCount'](\"quarterly\") != 1",
      "note" = "---- the frequency drift catch ----",
    } },
  "audit" = {
      "label" = "R407: the UA Appendix S clerical charts pin audit",
      "comment" = "The second data round rides the R405 seam: the five 8-column charts pin their 23 rows (sphere, raiment, colors, holy days, the sacrifice frequency and form), the 13 named sacred animals pin, the cleric gender reads pin, and the frequency counts (monthly 10, annually 4, before battle 2) catch any cell drift; the pantheon prose stays open; census 333 -> 334.",
    },
}
