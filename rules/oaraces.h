// =========================================================================================
// Adnd1 - rules/oaraces.h
// THE ORIENTAL RACES, printed capture pp. 17-22 - the OA races round
// census 540 -> 541.
//
// verified against capture pp. 17-22 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). OCR NORMALIZATIONS: the
// capture prints infraction for infravision - the physical copy confirms the
// clean infravision (a pure OCR garble); the korobokuru save ladder - the
// physical copy CONFIRMS the book itself prints 41h, a printed misprint read
// as the intended 4 1/2, pinned as the divisor 2, the flag RESOLVED; the
// percent signs garble as 7596, 5094 and -2096 - read clean as 75, 50 and
// -20; the hare prints as here. BOOK QUIRK: the prose cites a badger
// hengeyokai though badger is not among the twelve Table 11 forms (the evil
// forms are fox, raccoon dog and rat) - pinned as printed, flagged. The Table
// 11 modifications pin as four columns: the plus, its ability code (ST 0, DE
// 1, CO 2, IN 3, WI 4, CH 5), the minus and its code.
//
// the gap census after this round: 27 closed, 208 open - the three races and
// Table 11 flip; the races run of Chapter 2 is done, the ten classes begin
// next (census 540 -> 541); NEXT - R619: the Oriental Barbarian and Bushi -
// the class doctrines, Tables 14, 15, 16 and 17, prefix dgf (verify free),
// audit "R619 OA barbarian bushi audit", include after rules/oaraces.h
//
namespace rules {

// ---- the korobokuru race pins ----

// Korobokuru prose (capture p. 17): four permitted classes - barbarian,
// bushi, samurai, wu jen
inline int dgeKoroClasses()
    { return 4; }

// Korobokuru prose (capture p. 17): barbarians are the most common korobokuru
// class
inline bool dgeKoroBarbarianCommon()
    { return true; }

// Korobokuru prose (capture p. 17): korobokuru samurai are rare - they must
// be sponsored by a human clan
inline bool dgeKoroSamuraiSponsored()
    { return true; }

// Korobokuru prose (capture p. 17): the saving-throw bonus - +1 for every 4
// 1/2 points of Constitution vs. rods, staves, wands and spells, and the same
// vs. poison - the PHYSICAL COPY CONFIRMS the book itself prints 41h (a
// printed misprint for 4 1/2); read as the intended 4 1/2, the divisor pins
// as 2 (half the Con score per +1), the flag resolved
inline int dgeKoroSaveDivisor()
    { return 2; }

// Korobokuru prose (capture p. 17): the same +1 ladder applies against poison
// saves
inline bool dgeKoroSavePoisonToo()
    { return true; }

// Korobokuru prose (capture p. 17): infravision range in feet - the OCR
// prints infraction
inline int dgeKoroInfravision()
    { return 120; }

// Korobokuru prose (capture p. 17): the chance to recognize and identify
// normal plants and animals
inline int dgeKoroPlantIdPct()
    { return 66; }

// Korobokuru prose (capture p. 17): the +1 to hit bakemono, goblins, goblin
// rats and hobgoblins
inline bool dgeKoroGoblinBonus()
    { return true; }

// Korobokuru prose (capture p. 17): giants, oni, ogres, ogre magi and titans
// suffer -4 to hit korobokuru
inline bool dgeKoroGiantPenalty()
    { return true; }

// Korobokuru prose (capture p. 17): cannot use the go-daichi, any polearm but
// the naginata, or any bow but the horsebow
inline bool dgeKoroSizeLimits()
    { return true; }

// Korobokuru prose (capture p. 18): speak the tribal, trade, spirit-folk and
// hengeyokai languages; no alignment languages and none learnable
inline bool dgeKoroLanguages()
    { return true; }

// Korobokuru prose (capture p. 18): +1 initial Strength
inline int dgeKoroStrAdj()
    { return 1; }

// Korobokuru prose (capture p. 18): +1 initial Constitution
inline int dgeKoroConAdj()
    { return 1; }

// Korobokuru prose (capture p. 18): -2 initial Intelligence
inline int dgeKoroIntAdj()
    { return -2; }

// Korobokuru prose (capture p. 18): the modified scores cannot exceed 19 nor
// fall below 8, 12 or 3 respectively - the pre-eligibility modifications
inline bool dgeKoroScoreBounds()
    { return true; }

// Korobokuru prose (capture p. 18): player characters must belong to a family
inline bool dgeKoroFamilyRequired()
    { return true; }

// ---- the hengeyokai race pins ----

// Hengeyokai prose (capture p. 18): shapechange is natural - no moon cycles,
// no silver susceptibility, no wound transmission, no change-shape healing
inline bool dgeHengeNotLycanthrope()
    { return true; }

// Hengeyokai prose (capture p. 18): four permitted classes - shukenja,
// kensai, bushi, wu jen; never samurai or ninja (not human)
inline int dgeHengeClasses()
    { return 4; }

// Table 11 (capture p. 18): twelve traditional animal forms
inline int dgeHengeFormCount()
    { return 12; }

// Hengeyokai prose (capture p. 19): form changes per day equal the character
// level - the 1st-level one-change example, the 3rd-level three
inline int dgeHengeFormsPerDay()
    { return 1; }

// Hengeyokai prose (capture p. 19): changing form takes one complete round;
// armor and equipment do not change with the body
inline bool dgeHengeChangeRound()
    { return true; }

// Hengeyokai prose (capture p. 19): level and ability scores are unchanged in
// all forms; the hengeyokai language is speakable in all forms
inline bool dgeHengeScoresUnchanged()
    { return true; }

// Hengeyokai prose (capture p. 19): the animal form is real, not illusory -
// undetectable by illusion-revealing spells
inline bool dgeHengeAnimalReal()
    { return true; }

// Hengeyokai prose (capture p. 19): infravision 120 feet and
// speak-with-normal-animals in animal form
inline bool dgeHengeAnimalInfravision()
    { return true; }

// Hengeyokai prose (capture p. 19): no weapons, armor, equipment or spells in
// animal form; only hengeyokai and animal speech
inline bool dgeHengeAnimalNoGear()
    { return true; }

// Hengeyokai prose (capture p. 19): animal form carries one-half the hit
// points, rounded up - the 23-to-12 printed example; wounds carry over
// point-for-point; no change that would reach 0 or fewer; 0 hit points in any
// form is death
inline int dgeHengeAnimalHpHalved()
    { return 2; }

// Hengeyokai prose (capture pp. 19-20): bipedal form - full hit points, all
// languages, infravision 120, all class gear; movement rate 12; no animal
// movement powers; easily identified
inline bool dgeHengeBipedalFull()
    { return true; }

// Hengeyokai prose (capture p. 20): human form - full hit points, all class
// gear and spells, indistinguishable but for one retained animal feature; no
// infravision, no animal speech (understanding only), 12 movement
inline bool dgeHengeHumanFull()
    { return true; }

// Hengeyokai prose (capture p. 20): hengeyokai belong to no clan - no kinship
// benefits or penalties; never establish families or strongholds
inline bool dgeHengeNoClan()
    { return true; }

// Hengeyokai prose (capture p. 20): good-aligned hengeyokai may become
// protectors of a family or village at the family-establishing level -
// offerings of food, gifts and service in return
inline bool dgeHengeProtector()
    { return true; }

// ---- the Table 11 hengeyokai creatures grid ----

// Table 11 (capture p. 18): twelve creature rows - carp, cat, crab, crane,
// dog, drake, fox, hare, monkey, raccoon dog, rat, sparrow
inline int dgeT11RowCount()
    { return 12; }

// Table 11 (capture p. 18): the dash sentinel - no natural damage
inline int dgeT11NoDamage()
    { return 0; }

// Table 11 (capture p. 18): the dash sentinel - no land, fly or swim movement
inline int dgeT11NoMove()
    { return 0; }

// Table 11 (capture p. 18): the any-good alignment tier
inline int dgeT11AlignGood()
    { return 1; }

// Table 11 (capture p. 18): the any-chaotic alignment tier
inline int dgeT11AlignChaotic()
    { return 2; }

// Table 11 (capture p. 18): the any alignment tier (crab)
inline int dgeT11AlignAny()
    { return 3; }

// Table 11 (capture p. 18): the any-evil alignment tier
inline int dgeT11AlignEvil()
    { return 4; }

// the alignment tier column: good (carp, crane, dog, drake, hare, sparrow),
// chaotic (cat, monkey), any (crab), evil (fox, raccoon dog, rat) (capture p.
// 18).
inline int dgeT11Align(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 1;
        default:
            return -99;
        }
    }

// the damage-die column: the natural-weapon die - 0 for the dash (carp,
// drake, hare, monkey, sparrow), 2 for the crane 1-2, 3 for the
// cat-crab-fox-rat 1-3, 6 for the dog and raccoon dog 1-6 (capture p. 18).
inline int dgeT11DmgDie(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 6;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 6;
        case 10:
            return 3;
        case 11:
            return 0;
        default:
            return -99;
        }
    }

// the animal-form AC column: sparrow 3, hare 5, rat 5, fox 6, monkey 6, carp
// 7, drake 7, crab 8, cat 9, crane 9, dog 9, raccoon dog 9 (capture p. 18).
inline int dgeT11Ac(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 9;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 9;
        case 5:
            return 7;
        case 6:
            return 6;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 9;
        case 10:
            return 5;
        case 11:
            return 3;
        default:
            return -99;
        }
    }

// the land movement column: crab and sparrow 3, crane and drake 6,
// cat-dog-monkey 12, raccoon dog and rat 9, fox 15, hare 18, carp 0 - the
// carp cannot cross land (capture p. 18).
inline int dgeT11Move(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 12;
        case 2:
            return 3;
        case 3:
            return 6;
        case 4:
            return 12;
        case 5:
            return 6;
        case 6:
            return 15;
        case 7:
            return 18;
        case 8:
            return 12;
        case 9:
            return 9;
        case 10:
            return 9;
        case 11:
            return 3;
        default:
            return -99;
        }
    }

// the fly column: crane, drake and sparrow 12, 12 and 15; zero elsewhere
// (capture p. 18).
inline int dgeT11Fly(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 12;
        case 4:
            return 0;
        case 5:
            return 12;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 15;
        default:
            return -99;
        }
    }

// the swim column: carp 12, crab 6, drake 9; zero elsewhere (capture p. 18).
inline int dgeT11Swim(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 9;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        default:
            return -99;
        }
    }

// the ability plus column: the +1 or +2 of the modifications (capture p. 18).
inline int dgeT11Plus(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        default:
            return -99;
        }
    }

// the ability code column: ST 0, DE 1, CO 2, IN 3, WI 4, CH 5 - the
// plus-ability of the modifications (capture p. 18).
inline int dgeT11PlusAb(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 4;
        default:
            return -99;
        }
    }

// the ability minus column: the -1 or -2 of the modifications (capture p.
// 18).
inline int dgeT11Minus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -2;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -2;
        case 9:
            return -2;
        case 10:
            return -2;
        case 11:
            return -2;
        default:
            return -99;
        }
    }

// the minus-ability code column: the minus-ability of the modifications
// (capture p. 18).
inline int dgeT11MinusAb(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 3;
        default:
            return -99;
        }
    }

// ---- the spirit folk race pins ----

// Spirit Folk prose (capture p. 20): three permitted classes - samurai,
// kensai, bushi
inline int dgeSpiritClasses()
    { return 3; }

// Spirit Folk prose (capture p. 20): all spirit folk must belong to a family
// or clan; they hold land and establish families when class and level allow
inline bool dgeSpiritFamilyRequired()
    { return true; }

// Spirit Folk prose (capture pp. 20-21): the spirit lord summons must be
// answered and obeyed - failure or dishonor brings natural disasters on the
// spirit folk and its human family; the spirit lord wins any conflict of
// interests
inline bool dgeSpiritLordSummon()
    { return true; }

// Bamboo spirit folk prose (capture p. 21): the chance to identify normal
// plants
inline int dgeBambooPlantPct()
    { return 75; }

// Bamboo spirit folk prose (capture p. 21): the chance to identify normal
// animals
inline int dgeBambooAnimalPct()
    { return 50; }

// Bamboo spirit folk prose (capture p. 21): alone on foot through woodland,
// forest or grassland - no trail; with others a -20 percent (-4 on 1d20) to
// track the group
inline bool dgeBambooTrail()
    { return true; }

// Bamboo spirit folk prose (capture p. 21): the chance to hide in shadows in
// woods or forest
inline int dgeBambooHidePct()
    { return 75; }

// Bamboo spirit folk prose (capture p. 21): one forest-animal language
// learned per experience level, player-chosen
inline bool dgeBambooLanguagePerLevel()
    { return true; }

// Bamboo spirit folk prose (capture p. 21): +1 saves vs. spells, rods,
// staves, wands and misc. magic of earth and wood
inline bool dgeBambooSaveBonus()
    { return true; }

// Bamboo spirit folk prose (capture p. 21): the life force tied to a bamboo
// grove - grove damage suffers equal damage, grove destruction is instant
// death, entering the grove cures all wounds and diseases; the grove never
// moves, its shoots carry no power
inline bool dgeBambooGrove()
    { return true; }

// River spirit folk prose (capture p. 21): breathe in any fresh water, swim
// at normal rate, carried items stay perfectly dry
inline bool dgeRiverBreatheSwim()
    { return true; }

// River spirit folk prose (capture p. 21): once per day lower a river or
// stream 10 feet for five rounds
inline int dgeRiverLowerWaterFeet()
    { return 10; }

// River spirit folk prose (capture p. 21): the lower-water duration in rounds
inline int dgeRiverLowerWaterRounds()
    { return 5; }

// River spirit folk prose (capture p. 21): +1 saves vs. water-elemental
// magic; -1 vs. fire attacks
inline bool dgeRiverSaveBonus()
    { return true; }

// River spirit folk prose (capture p. 21): speak the fish language, the court
// language and the trade language
inline bool dgeRiverLanguages()
    { return true; }

// River spirit folk prose (capture p. 21): the life force tied to one river
// in its natural banks - bathing cures all; drought weakens, flooding
// maddens, damming kills; drawn-off water is no longer the river
inline bool dgeRiverLifeForce()
    { return true; }

// Sea spirit folk prose (capture p. 21): breathe any salt water, swim at
// normal rate, gear never wets
inline bool dgeSeaBreatheSwim()
    { return true; }

// Sea spirit folk prose (capture p. 21): once per day predict the next 24
// hours of weather at 75 percent (the OCR prints 7596)
inline int dgeSeaWeatherPct()
    { return 75; }

// Sea spirit folk prose (capture p. 21): the weather prediction window in
// hours
inline int dgeSeaWeatherHours()
    { return 24; }

// Sea spirit folk prose (capture p. 21): +1 saves vs. fire-based attacks
inline bool dgeSeaSaveBonus()
    { return true; }

// Sea spirit folk prose (capture p. 22): unaffected by changes in the sea and
// gain no healing from it
inline bool dgeSeaNoSeaTie()
    { return true; }

// Sea spirit folk prose (capture p. 22): one favor from the sea per year - a
// specific request; two opposing requests cancel and both lose the favor
inline int dgeSeaFavorsPerYear()
    { return 1; }

// Sea spirit folk prose (capture p. 22): at honor 85 the Lord of the Sea
// bestows a gift - treasure, a service or a magic item (the pearl of rising
// tide named), no conditions
inline int dgeSeaGiftHonor()
    { return 85; }

}   // namespace rules
