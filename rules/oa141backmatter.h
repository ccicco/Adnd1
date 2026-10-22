// =========================================================================================
// Adnd1 - rules/oa141backmatter.h
// OA BACK MATTER - THE BIBLIOGRAPHY, printed capture pp. 313-314 - the book
// closes
// census 692 -> 693.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 225 closed, 10 open - the Back matter box
// flips and the missed Chapter 14 and 15 parents close (the R613b lesson
// caught pre-landing, census 692 -> 693); NEXT - R771: the open-boxes sweep -
// the ten remaining: the Chapter 2, 3, 8, 9, 10, 11, 12, and 13 parents plus
// the Weapons prose and the Celestial Emperor items; audit what each holds
// before authoring, prefix dng (verify free at the landing), audit "R771 OA
// open boxes audit", include after rules/oa141backmatter.h
//
namespace rules {

// ---- the bibliography doctrine ----

// the bibliography header - the back matter of Oriental Adventures closes on
// the bibliography, the listed sources of the Oriental campaign (print
// capture pp. 313-314)
inline int dmfBibliographyHeader()
    { return 1; }

// the plus marked background - titles marked by + provide a good general
// background (print capture pp. 313-314)
inline int dmfPlusMarkedBackground()
    { return 1; }

// the Hearn titles count - Lafcadio Hearn with four titles in the
// bibliography: In Ghostly Japan, Japan: An Interpretation, Kotto, and
// Kwaidan (print capture pp. 313-314)
inline int dmfHearnTitlesCount()
    { return 4; }

// the Hearn Japan titles - the Hearn titles of Japanese curios, ghostly
// Japan, and strange things (print capture pp. 313-314)
inline int dmfHearnJapanTitles()
    { return 1; }

// ---- the samurai warfare shelf ----

// the Turnbull samurai titles count - S. R. Turnbull with two samurai titles:
// Samurai Armies 1550-1615 and The Samurai (print capture pp. 313-314)
inline int dmfTurnbullSamuraiTitlesCount()
    { return 2; }

// the Sun Tzu Art of War - the bibliography lists Sun Tzu, The Art of War
// (print capture pp. 313-314)
inline int dmfSunTzuArtOfWar()
    { return 1; }

// the Musashi five rings - Miyamoto Musashi, A Book of Five Rings (print
// capture pp. 313-314)
inline int dmfMusashiFiveRings()
    { return 1; }

// the secrets of samurai - Ratti and Westbrook, Secrets of the Samurai, with
// Storry, The Way of the Samurai (print capture pp. 313-314)
inline int dmfSecretsOfSamurai()
    { return 1; }

// the budoshoshinshu entry - Wilson, Budoshoshinshu: The Warrior Primer of
// Daidoji Yuzan (print capture pp. 313-314)
inline int dmfBudoshoshinshuEntry()
    { return 1; }

// ---- the ninja shelf ----

// the ninjutsu entries - Hatsumi, Ninjutsu: History and Tradition, with Kim,
// Ninja: Secrets of Invisibility (print capture pp. 313-314)
inline int dmfNinjutsuEntries()
    { return 1; }

// ---- the folklore shelf ----

// the Chinese mythology titles - Dragons, Gods and Spirits from Chinese
// Mythology, Chinese Fairy Tales and Fantasies, The Magic Knife, and Chinese
// Folktales (print capture pp. 313-314)
inline int dmfChineseMythologyTitles()
    { return 1; }

// the folk tale titles - The Japanese Fairy Book, Tales From the Japanese
// Storytellers, Folk Tales From China, and Japanese Folklore in English
// (print capture pp. 313-314)
inline int dmfFolkTaleTitles()
    { return 1; }

// ---- the culture and craft shelf ----

// the architecture titles - Feudal Architecture of Japan, Traditional
// Domestic Architecture of Japan, A Pictorial History of Chinese
// Architecture, and Japanese Homes and Their Surroundings (print capture pp.
// 313-314)
inline int dmfArchitectureTitles()
    { return 1; }

// the arms and armor titles - Stone, A Glossary of the Construction,
// Decoration, and Use of Arms and Armor, with Japan Ancient Armor, Chinese
// Weapons, Introduction to Ancient Chinese Weapons, and Comprehensive Asian
// Fighting Arts (print capture pp. 313-314)
inline int dmfArmsAndArmorTitles()
    { return 1; }

// the daily life titles - Daily Life in Japan at the Time of the Samurai,
// Things Chinese, and Far Eastern Beginnings (print capture pp. 313-314)
inline int dmfDailyLifeTitles()
    { return 1; }

// the religion titles - Chinese Religions, Taoist Mysteries and Magic, Songs
// of Gods, Songs of Humans, and Japanese Mythology (print capture pp.
// 313-314)
inline int dmfReligionTitles()
    { return 1; }

// the Chinese classic titles - Wu Cheng-en, Monkey, with A Treasury of
// Chinese Literature, Stories From a Ming Collection, and Six Records of a
// Floating Life (print capture pp. 313-314)
inline int dmfChineseClassicTitles()
    { return 1; }

// the Chinese symbolism titles - Outlines of Chinese Symbolism and Art
// Motives, with The Asian Animal Zodiac and Feng Shui, the Chinese Art of
// Placement (print capture pp. 313-314)
inline int dmfChineseSymbolismTitles()
    { return 1; }

}   // namespace rules
