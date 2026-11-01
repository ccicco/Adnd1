-- oa705: promoted from rules/oa76bajang.h (the OA MONSTERS - THE BAJANG, printed capture pp. 253-254 - the lesser spirit);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 705,
  "prefix" = "oa705",
  "banner" = {
      "title" = "OA MONSTERS - THE BAJANG, printed capture pp. 253-254 - the lesser spirit",
      "provenance" = "round census 627 -> 628.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE STAT BLOCK: the very rare, the 1 appearing, the AC 2, the move 12, the HD 6, the 20% lair, the treasure P, the 2 attacks of 1-4/1-4, the spells and the poison special attacks, the nil special defenses, the 10% magic resistance, the high intelligence, the chaotic evil, the size S, the V/500 + 6 per hp. THE DESCRIPTION: the evil and malignant tropical-jungle creature; the true form the stunted humanoid with bird-like feet and clawed hands; the wildcat shape at will, the most commonly seen appearance; the eight spells (the curse, the omen, the divination, the fate, the ghost light, the wind breath, the steam breath, the transfix) cast three times per day; the ancient curse once per day; the claw poison the -1 on all hit and saving throw rolls for the 2-7 rounds, cumulative; the spirit limitations; the tree lifeforce - the tree destroyed, the bajang instantly slain, the location concealed; the village predation by night, the victims taken sleeping; the evil sorcerer's familiar service; the intelligent and extremely devious temperament; the own language and the common area language. The prose codifies per the R431 calculus  the gap census after this round: 158 closed, 77 open - the Bajang box flips (census 627 -> 628); NEXT - R706: the Bakemono (capture pp. 254-255), prefix djt (verify free at the landing), audit \"R706 OA monsters Bakemono audit\", include after rules/oa76bajang.h",
    },
  "consts" = { {
      "name" = "djsBajangFrequencyClass",
      "value" = 1,
      "comment" = "the Bajang frequency - the very rare of the stat block (print capture p. 253)",
    }, {
      "name" = "djsBajangNoAppearing",
      "value" = 1,
      "comment" = "the Bajang appearance count - the 1 of the stat block (print capture p. 253)",
    }, {
      "name" = "djsBajangAC",
      "value" = 2,
      "comment" = "the Bajang armor class - the 2 of the stat block (print capture p. 253)",
    }, {
      "name" = "djsBajangMove",
      "value" = 12,
      "comment" = "the Bajang movement - the 12 of the stat block (print capture p. 254)",
    }, {
      "name" = "djsBajangHD",
      "value" = 6,
      "comment" = "the Bajang hit dice - the 6 of the stat block (print capture p. 254)",
    }, {
      "name" = "djsBajangLairPct",
      "value" = 20,
      "comment" = "the Bajang lair chance - the 20% of the stat block (print capture p. 254)",
    }, {
      "name" = "djsBajangAttacks",
      "value" = 2,
      "comment" = "the Bajang attack count - the 2 of the stat block (print capture p. 254)",
    }, {
      "name" = "djsBajangDmgMin",
      "value" = 1,
      "comment" = "the Bajang damage per claw - the minimum of the 1-4/1-4 (print capture p. 254)",
    }, {
      "name" = "djsBajangDmgMax",
      "value" = 4,
      "comment" = "the Bajang damage per claw - the maximum of the 1-4/1-4 (print capture p. 254)",
    }, {
      "name" = "djsBajangMRPct",
      "value" = 10,
      "comment" = "the Bajang magic resistance - the 10% of the stat block (print capture p. 254)",
    }, {
      "name" = "djsBajangXPBase",
      "value" = 500,
      "comment" = "the Bajang XP value - the 500 of the V/500 + 6 per hp (print capture p. 254)",
    }, {
      "name" = "djsBajangXPPerHP",
      "value" = 6,
      "comment" = "the Bajang XP value - the 6 per hp of the V/500 + 6 per hp (print capture p. 254)",
    }, {
      "name" = "djsBajangSpellCount",
      "value" = 8,
      "comment" = "the Bajang spell count - the eight spells of the three-per-day list (print capture p. 254)",
    }, {
      "name" = "djsBajangSpellUsesPerDay",
      "value" = 3,
      "comment" = "the Bajang spell uses - the curse, omen, divination, fate, ghost light, wind breath, steam breath, and transfix cast three times per day (print capture p. 254)",
    }, {
      "name" = "djsBajangAncientCursePerDay",
      "value" = 1,
      "comment" = "the Bajang ancient curse - once per day (print capture p. 254)",
    }, {
      "name" = "djsBajangPoisonPenalty",
      "value" = 1,
      "comment" = "the Bajang claw poison - the -1 on all hit and saving throw rolls on a failed save vs. poison (print capture p. 254)",
    }, {
      "name" = "djsBajangPoisonMinRounds",
      "value" = 2,
      "comment" = "the Bajang claw poison duration - the minimum of the 2-7 rounds (print capture p. 254)",
    }, {
      "name" = "djsBajangPoisonMaxRounds",
      "value" = 7,
      "comment" = "the Bajang claw poison duration - the maximum of the 2-7 rounds (print capture p. 254)",
    }, {
      "name" = "djsBajangLangCount",
      "value" = 3,
      "comment" = "the Bajang languages - the own language, the common area language, and the devious tongue of its intelligence (print capture p. 254)",
    } },
  "bools" = { {
      "name" = "djsBajangPoisonCumulative",
      "value" = true,
      "comment" = "the Bajang claw poison - the -1 penalty effect is cumulative (print capture p. 254)",
    }, {
      "name" = "djsBajangLesserSpirit",
      "value" = true,
      "comment" = "the Bajang - a lesser spirit, subject to all the limitations of spirit creatures as regards spells which affect these creatures (print capture pp. 253-254)",
    }, {
      "name" = "djsBajangTropicalJungle",
      "value" = true,
      "comment" = "the Bajang habitat - an evil and malignant creature found in tropical jungles (print capture p. 254)",
    }, {
      "name" = "djsBajangTrueFormHumanoid",
      "value" = true,
      "comment" = "the Bajang true form - a stunted evil-looking humanoid with bird-like feet and clawed hands (print capture p. 254)",
    }, {
      "name" = "djsBajangWildcatShapeCommon",
      "value" = true,
      "comment" = "the Bajang shapechange - it changes shape at will assuming the form of a small wildcat, the most commonly seen appearance (print capture p. 254)",
    }, {
      "name" = "djsBajangTreeLifeforce",
      "value" = true,
      "comment" = "the Bajang lifeforce - tied to some tree in its forest; the tree destroyed, the bajang instantly slain; the tree location concealed (print capture p. 254)",
    }, {
      "name" = "djsBajangNightVillagePredator",
      "value" = true,
      "comment" = "the Bajang predation - lives near a small village or habitation, striking at night to take victims while sleeping (print capture p. 254)",
    }, {
      "name" = "djsBajangEvilSorcererFamiliar",
      "value" = true,
      "comment" = "the Bajang service - sometimes serves a powerful sorcerer of evil nature as their familiar (print capture p. 254)",
    }, {
      "name" = "djsBajangIntelligentDevious",
      "value" = true,
      "comment" = "the Bajang temperament - intelligent and extremely devious (print capture p. 254)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djsBajangFrequencyClass']() != 1  or m['djsBajangNoAppearing']() != 1  or m['djsBajangAC']() != 2  or m['djsBajangMove']() != 12  or m['djsBajangHD']() != 6  or m['djsBajangLairPct']() != 20  or m['djsBajangAttacks']() != 2  or m['djsBajangDmgMin']() != 1  or m['djsBajangDmgMax']() != 4  or m['djsBajangMRPct']() != 10  or m['djsBajangSpellUsesPerDay']() != 3  or m['djsBajangSpellCount']() != 8  or m['djsBajangAncientCursePerDay']() != 1  or m['djsBajangPoisonPenalty']() != 1  or m['djsBajangPoisonMinRounds']() != 2  or m['djsBajangPoisonMaxRounds']() != 7  or m['djsBajangXPBase']() != 500  or m['djsBajangXPPerHP']() != 6  or m['djsBajangLangCount']() != 3  or  m['djsBajangLesserSpirit']() != 1  or  m['djsBajangTropicalJungle']() != 1  or  m['djsBajangTrueFormHumanoid']() != 1  or  m['djsBajangWildcatShapeCommon']() != 1  or  m['djsBajangPoisonCumulative']() != 1  or  m['djsBajangTreeLifeforce']() != 1  or  m['djsBajangNightVillagePredator']() != 1  or  m['djsBajangEvilSorcererFamiliar']() != 1  or  m['djsBajangIntelligentDevious']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djsBajangFrequencyClass']() != 1  or m['djsBajangNoAppearing']() != 1  or m['djsBajangAC']() != 2  or m['djsBajangMove']() != 12  or m['djsBajangHD']() != 6  or m['djsBajangLairPct']() != 20  or m['djsBajangAttacks']() != 2  or m['djsBajangDmgMin']() != 1  or m['djsBajangDmgMax']() != 4  or m['djsBajangMRPct']() != 10  or m['djsBajangXPBase']() != 500  or m['djsBajangXPPerHP']() != 6",
      "note" = "the stat block - the very rare, the 1, the AC 2, the move 12, the HD 6, the 20% lair, the treasure P, the 2 attacks of 1-4, the spells and poison, the 10% MR, the XP 500 + 6 per hp",
    }, {
      "expr" = "m['djsBajangSpellCount']() != 8  or m['djsBajangSpellUsesPerDay']() != 3  or m['djsBajangAncientCursePerDay']() != 1",
      "note" = "the spells - the eight cast three per day, the ancient curse once per day",
    }, {
      "expr" = "m['djsBajangPoisonPenalty']() != 1  or m['djsBajangPoisonMinRounds']() != 2  or m['djsBajangPoisonMaxRounds']() != 7  or m['djsBajangPoisonCumulative']() != 1",
      "note" = "the claw poison - the -1 penalty, the 2-7 rounds, the cumulative effect",
    }, {
      "expr" = "m['djsBajangLesserSpirit']() != 1  or m['djsBajangTropicalJungle']() != 1  or m['djsBajangTrueFormHumanoid']() != 1  or m['djsBajangWildcatShapeCommon']() != 1  or m['djsBajangTreeLifeforce']() != 1  or m['djsBajangNightVillagePredator']() != 1  or m['djsBajangEvilSorcererFamiliar']() != 1  or m['djsBajangIntelligentDevious']() != 1  or m['djsBajangLangCount']() != 3",
      "note" = "the nature - the lesser spirit, the tropical jungle, the humanoid true form, the wildcat the common shape, the tree lifeforce, the night predation, the sorcerer familiar, the devious intelligence, the languages",
    } },
  "audit" = {
      "label" = "R705 OA monsters Bajang audit",
      "comment" = "OA round ninety-two (capture pp. 253-254): the Chapter 12 monster roster opener - the Bajang (Lesser Spirit), the stat block and the description riding together, single-pass pins per the Chapter 9 provenance shift",
    },
}
