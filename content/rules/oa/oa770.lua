-- oa770: promoted from rules/oa/oa141backmatter.h (the OA BACK MATTER - THE BIBLIOGRAPHY, printed capture pp. 313-314 - the book);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 770,
  "prefix" = "oa770",
  "banner" = {
      "title" = "OA BACK MATTER - THE BIBLIOGRAPHY, printed capture pp. 313-314 - the book",
      "provenance" = "closes census 692 -> 693.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 225 closed, 10 open - the Back matter box flips and the missed Chapter 14 and 15 parents close (the R613b lesson caught pre-landing, census 692 -> 693); NEXT - R771: the open-boxes sweep - the ten remaining: the Chapter 2, 3, 8, 9, 10, 11, 12, and 13 parents plus the Weapons prose and the Celestial Emperor items; audit what each holds before authoring, prefix dng (verify free at the landing), audit \"R771 OA open boxes audit\", include after rules/oa/oa141backmatter.h",
    },
  "consts" = { {
      "name" = "dmfBibliographyHeader",
      "value" = 1,
      "comment" = "the bibliography header - the back matter of Oriental Adventures closes on the bibliography, the listed sources of the Oriental campaign (print capture pp. 313-314)",
    }, {
      "name" = "dmfPlusMarkedBackground",
      "value" = 1,
      "comment" = "the plus marked background - titles marked by + provide a good general background (print capture pp. 313-314)",
    }, {
      "name" = "dmfHearnTitlesCount",
      "value" = 4,
      "comment" = "the Hearn titles count - Lafcadio Hearn with four titles in the bibliography: In Ghostly Japan, Japan: An Interpretation, Kotto, and Kwaidan (print capture pp. 313-314)",
    }, {
      "name" = "dmfHearnJapanTitles",
      "value" = 1,
      "comment" = "the Hearn Japan titles - the Hearn titles of Japanese curios, ghostly Japan, and strange things (print capture pp. 313-314)",
    }, {
      "name" = "dmfTurnbullSamuraiTitlesCount",
      "value" = 2,
      "comment" = "the Turnbull samurai titles count - S. R. Turnbull with two samurai titles: Samurai Armies 1550-1615 and The Samurai (print capture pp. 313-314)",
    }, {
      "name" = "dmfSunTzuArtOfWar",
      "value" = 1,
      "comment" = "the Sun Tzu Art of War - the bibliography lists Sun Tzu, The Art of War (print capture pp. 313-314)",
    }, {
      "name" = "dmfMusashiFiveRings",
      "value" = 1,
      "comment" = "the Musashi five rings - Miyamoto Musashi, A Book of Five Rings (print capture pp. 313-314)",
    }, {
      "name" = "dmfSecretsOfSamurai",
      "value" = 1,
      "comment" = "the secrets of samurai - Ratti and Westbrook, Secrets of the Samurai, with Storry, The Way of the Samurai (print capture pp. 313-314)",
    }, {
      "name" = "dmfBudoshoshinshuEntry",
      "value" = 1,
      "comment" = "the budoshoshinshu entry - Wilson, Budoshoshinshu: The Warrior Primer of Daidoji Yuzan (print capture pp. 313-314)",
    }, {
      "name" = "dmfNinjutsuEntries",
      "value" = 1,
      "comment" = "the ninjutsu entries - Hatsumi, Ninjutsu: History and Tradition, with Kim, Ninja: Secrets of Invisibility (print capture pp. 313-314)",
    }, {
      "name" = "dmfChineseMythologyTitles",
      "value" = 1,
      "comment" = "the Chinese mythology titles - Dragons, Gods and Spirits from Chinese Mythology, Chinese Fairy Tales and Fantasies, The Magic Knife, and Chinese Folktales (print capture pp. 313-314)",
    }, {
      "name" = "dmfFolkTaleTitles",
      "value" = 1,
      "comment" = "the folk tale titles - The Japanese Fairy Book, Tales From the Japanese Storytellers, Folk Tales From China, and Japanese Folklore in English (print capture pp. 313-314)",
    }, {
      "name" = "dmfArchitectureTitles",
      "value" = 1,
      "comment" = "the architecture titles - Feudal Architecture of Japan, Traditional Domestic Architecture of Japan, A Pictorial History of Chinese Architecture, and Japanese Homes and Their Surroundings (print capture pp. 313-314)",
    }, {
      "name" = "dmfArmsAndArmorTitles",
      "value" = 1,
      "comment" = "the arms and armor titles - Stone, A Glossary of the Construction, Decoration, and Use of Arms and Armor, with Japan Ancient Armor, Chinese Weapons, Introduction to Ancient Chinese Weapons, and Comprehensive Asian Fighting Arts (print capture pp. 313-314)",
    }, {
      "name" = "dmfDailyLifeTitles",
      "value" = 1,
      "comment" = "the daily life titles - Daily Life in Japan at the Time of the Samurai, Things Chinese, and Far Eastern Beginnings (print capture pp. 313-314)",
    }, {
      "name" = "dmfReligionTitles",
      "value" = 1,
      "comment" = "the religion titles - Chinese Religions, Taoist Mysteries and Magic, Songs of Gods, Songs of Humans, and Japanese Mythology (print capture pp. 313-314)",
    }, {
      "name" = "dmfChineseClassicTitles",
      "value" = 1,
      "comment" = "the Chinese classic titles - Wu Cheng-en, Monkey, with A Treasury of Chinese Literature, Stories From a Ming Collection, and Six Records of a Floating Life (print capture pp. 313-314)",
    }, {
      "name" = "dmfChineseSymbolismTitles",
      "value" = 1,
      "comment" = "the Chinese symbolism titles - Outlines of Chinese Symbolism and Art Motives, with The Asian Animal Zodiac and Feng Shui, the Chinese Art of Placement (print capture pp. 313-314)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmfHearnTitlesCount']() != 4  or m['dmfTurnbullSamuraiTitlesCount']() != 2  or  m['dmfBibliographyHeader']() != 1  or  m['dmfPlusMarkedBackground']() != 1  or  m['dmfSunTzuArtOfWar']() != 1  or  m['dmfMusashiFiveRings']() != 1  or  m['dmfSecretsOfSamurai']() != 1  or  m['dmfBudoshoshinshuEntry']() != 1  or  m['dmfNinjutsuEntries']() != 1  or  m['dmfHearnJapanTitles']() != 1  or  m['dmfChineseMythologyTitles']() != 1  or  m['dmfFolkTaleTitles']() != 1  or  m['dmfArchitectureTitles']() != 1  or  m['dmfArmsAndArmorTitles']() != 1  or  m['dmfDailyLifeTitles']() != 1  or  m['dmfReligionTitles']() != 1  or  m['dmfChineseClassicTitles']() != 1  or  m['dmfChineseSymbolismTitles']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dmfBibliographyHeader']() != 1  or m['dmfPlusMarkedBackground']() != 1",
      "note" = "the doctrine example",
    }, {
      "expr" = "m['dmfHearnTitlesCount']() != 4  or m['dmfHearnJapanTitles']() != 1",
      "note" = "the Hearn example",
    }, {
      "expr" = "m['dmfTurnbullSamuraiTitlesCount']() != 2  or m['dmfSunTzuArtOfWar']() != 1  or m['dmfMusashiFiveRings']() != 1",
      "note" = "the warfare example",
    }, {
      "expr" = "m['dmfSecretsOfSamurai']() != 1  or m['dmfBudoshoshinshuEntry']() != 1",
      "note" = "the samurai shelf example",
    }, {
      "expr" = "m['dmfNinjutsuEntries']() != 1",
      "note" = "the ninja example",
    }, {
      "expr" = "m['dmfChineseMythologyTitles']() != 1  or m['dmfFolkTaleTitles']() != 1",
      "note" = "the folklore example",
    }, {
      "expr" = "m['dmfArchitectureTitles']() != 1  or m['dmfArmsAndArmorTitles']() != 1",
      "note" = "the craft example",
    }, {
      "expr" = "m['dmfDailyLifeTitles']() != 1  or m['dmfReligionTitles']() != 1",
      "note" = "the culture example",
    }, {
      "expr" = "m['dmfChineseClassicTitles']() != 1  or m['dmfChineseSymbolismTitles']() != 1",
      "note" = "the classics example",
    } },
  "audit" = {
      "label" = "R770 OA Back matter audit",
      "comment" = "OA round one hundred fifty-seven (capture pp. 313-314): the back matter - the bibliography of Oriental Adventures, the plus-marked background, the samurai, ninja, folklore, and culture shelves, with the missed Chapter 14 and 15 parent boxes closed pre-landing, single-pass pins per the R679 provenance shift",
    },
}
