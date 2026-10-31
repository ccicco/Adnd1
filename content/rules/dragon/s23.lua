-- s23: promoted from tools/spec_r951.json (the The Dragon issue-23 opener part two - the Lower Planes creature generator);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 951,
  "prefix" = "s23",
  "banner" = {
      "title" = "The Dragon issue-23 opener part two - the Lower Planes creature generator",
      "provenance" = "The part-two round of the issue-23 four-round shape - the single chain of the Sorceror Scroll DMG preview, the table round of the walk: the Random Generation of Creatures from the Lower Planes system, Gary Gygax on the Abyss, Tarterus, Hades, Gehenna and Hell. Pinned from The Dragon Vol. III No. 9 (March 1979) print 15 through 18 at extract/dragon/023, PRINT FOLIO = PDF PAGE this issue, the transcript of the Curtiss-provided scan. The Rihn and Pickens antecedents ride the frame; the EXXEDUUNUSSE sign-off rides the general characteristics; the two inherited watches - the Sullin levels 7-9 and the brawling sequel - print nowhere in issue 23 and ride to TD 24.",
    },
  "consts" = { {
      "name" = "s23LowerPlanes",
      "value" = 5,
      "comment" = "the five named lower planes - the Abyss, Tarterus, Hades, Gehenna and Hell the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23RihnIssue",
      "value" = 20,
      "comment" = "the Gregory Rihn Demonology Made Easy article that prompted the system, TD 20 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PickensIssue",
      "value" = 13,
      "comment" = "the Jon Pickens random demons article re-read for the system, TD 13 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FreqBands",
      "value" = 3,
      "comment" = "the frequency bands - common, uncommon or rare on the d6 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AppearMin",
      "value" = 1,
      "comment" = "the number appearing floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AppearMax",
      "value" = 8,
      "comment" = "the number appearing ceiling of two to eight the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AcDice",
      "value" = 4,
      "comment" = "the armor class d4 - zero through minus three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AcWorst",
      "value" = 0,
      "comment" = "the worst armor class of the range, zero the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AcBest",
      "value" = -3,
      "comment" = "the best armor class of the range, minus three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MoveDie",
      "value" = 8,
      "comment" = "the base move d8 with six through eight rolling the d4 reroll the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MoveRerollFrom",
      "value" = 6,
      "comment" = "the d8 face where the move rerolls on the d4 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MoveRerollDie",
      "value" = 4,
      "comment" = "the reroll die for the base move the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MoveIncrement",
      "value" = 3,
      "comment" = "the three-inch increments added to swimming or flying speed the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MoveBonusMax",
      "value" = 4,
      "comment" = "the one-to-four increments of the speed bonus the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SwimLo",
      "value" = 1,
      "comment" = "the swimming d6 floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SwimHi",
      "value" = 2,
      "comment" = "the swimming d6 ceiling of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FlyLo",
      "value" = 3,
      "comment" = "the flying d6 floor of three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FlyHi",
      "value" = 6,
      "comment" = "the flying d6 ceiling of six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdBase",
      "value" = 6,
      "comment" = "the hit die formula base, d4 plus six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdDice",
      "value" = 4,
      "comment" = "the hit die formula die of four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdMin",
      "value" = 7,
      "comment" = "the hit dice floor of seven the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdMax",
      "value" = 10,
      "comment" = "the hit dice ceiling of ten the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdBonusOn",
      "value" = 4,
      "comment" = "the second d4 face of four that grants bonus hit points per die the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdBonusMin",
      "value" = 1,
      "comment" = "the bonus hit points per hit die floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HdBonusMax",
      "value" = 4,
      "comment" = "the bonus hit points per hit die ceiling of four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MrPerDie",
      "value" = 5,
      "comment" = "the standard magic resistance of five percent per hit die the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23IntBands",
      "value" = 4,
      "comment" = "the intelligence bands - low, average, very or high on the d4 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SizeDice",
      "value" = 8,
      "comment" = "the size d8 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SizeSmallHi",
      "value" = 1,
      "comment" = "the size d8 ceiling of the small band, one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SizeMedHi",
      "value" = 4,
      "comment" = "the size d8 ceiling of the medium band, two through four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PsiNil",
      "value" = 90,
      "comment" = "the ninety percent psionic nil chance the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PsiBase",
      "value" = 95,
      "comment" = "the psionic ability roll base, d20 plus ninety-five the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PsiDie",
      "value" = 20,
      "comment" = "the psionic ability roll die of twenty the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PsiMin",
      "value" = 96,
      "comment" = "the psionic ability floor of ninety-six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PsiMax",
      "value" = 115,
      "comment" = "the psionic ability ceiling of one hundred fifteen the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AtkModeCount",
      "value" = 4,
      "comment" = "the four attack modes A through D on the d4 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AtkModeDie",
      "value" = 4,
      "comment" = "the attack mode die of four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23DefModeCount",
      "value" = 3,
      "comment" = "the three defense modes F through H on the d6 the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23DefModeDie",
      "value" = 6,
      "comment" = "the defense mode die of six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23DefBandWidth",
      "value" = 2,
      "comment" = "the two-face defense bands - F on one to two, F and G on three to four, and so on the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HornsMax",
      "value" = 4,
      "comment" = "the horns adornment rolled one to four in the appearance table the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23EyesMid",
      "value" = 2,
      "comment" = "the eyes result of two on the d6 two-to-four band the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23EyesHighMin",
      "value" = 3,
      "comment" = "the eyes result floor of three on the d6 five-to-six band the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23EyesHighMax",
      "value" = 4,
      "comment" = "the eyes result ceiling of four on the d6 five-to-six band the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthAvgLo",
      "value" = 2,
      "comment" = "the average-mouth d6 floor of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthAvgHi",
      "value" = 3,
      "comment" = "the average-mouth d6 ceiling of three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthHugeLo",
      "value" = 5,
      "comment" = "the huge-mouth d6 floor of five the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthHugeHi",
      "value" = 6,
      "comment" = "the huge-mouth d6 ceiling of six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BipedLo",
      "value" = 1,
      "comment" = "the bipedal d6 floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BipedHi",
      "value" = 4,
      "comment" = "the bipedal d6 ceiling of four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23QuadLo",
      "value" = 5,
      "comment" = "the quadrapedal d6 floor of five the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23QuadHi",
      "value" = 6,
      "comment" = "the quadrapedal d6 ceiling of six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23ArmsMin",
      "value" = 2,
      "comment" = "the arms floor of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BipedArmsMax",
      "value" = 4,
      "comment" = "the bipedal arms choices, two or four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23OtherArmsMax",
      "value" = 6,
      "comment" = "the otherwise arms choices, two, four or six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandsAlikeHi",
      "value" = 3,
      "comment" = "the all-alike hands d6 ceiling of three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandsDiffLo",
      "value" = 4,
      "comment" = "the different hands d6 floor of four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23TailLo",
      "value" = 1,
      "comment" = "the tail d6 floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23TailHi",
      "value" = 4,
      "comment" = "the tail d6 ceiling of four - one to four the creature has a tail the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AntlerDiceMin",
      "value" = 1,
      "comment" = "the antlers-or-horns damage floor, one die of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AntlerSidesMin",
      "value" = 2,
      "comment" = "the antlers-or-horns damage floor sides of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AntlerDiceMax",
      "value" = 2,
      "comment" = "the antlers-or-horns damage ceiling of two dice the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AntlerSidesMax",
      "value" = 8,
      "comment" = "the antlers-or-horns damage ceiling sides of eight the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthDmgMin",
      "value" = 1,
      "comment" = "the mouth damage floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthDmgMaxDice",
      "value" = 3,
      "comment" = "the mouth damage ceiling of three dice the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthDmgMaxSides",
      "value" = 12,
      "comment" = "the mouth damage ceiling sides of twelve the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23TailDmgMin",
      "value" = 1,
      "comment" = "the tail damage floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23TailDmgMax",
      "value" = 6,
      "comment" = "the tail damage ceiling of six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandDiceMin",
      "value" = 1,
      "comment" = "the hands damage floor, one die of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandSidesMin",
      "value" = 2,
      "comment" = "the hands damage floor sides of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandDiceMax",
      "value" = 2,
      "comment" = "the hands damage ceiling of two dice the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandSidesMax",
      "value" = 12,
      "comment" = "the hands damage ceiling sides of twelve the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FootDiceMin",
      "value" = 1,
      "comment" = "the feet damage floor, one die of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FootSidesMin",
      "value" = 2,
      "comment" = "the feet damage floor sides of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FootDiceMax",
      "value" = 3,
      "comment" = "the feet damage ceiling of three dice the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FootSidesMax",
      "value" = 12,
      "comment" = "the feet damage ceiling sides of twelve the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HugeClawDice",
      "value" = 2,
      "comment" = "the huge-clawed-hands damage rating of two dice per hit the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HugeClawSides",
      "value" = 8,
      "comment" = "the huge-clawed-hands damage sides of eight the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpineDmgMin",
      "value" = 1,
      "comment" = "the incidental spine-type damage floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpineDmgMax",
      "value" = 6,
      "comment" = "the incidental spine-type damage ceiling of six the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23StrSubFifty",
      "value" = 50,
      "comment" = "the exceptional-strength subroll ceiling of the forty-five-to-sixty band, one to fifty the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23StrSubSeventyFive",
      "value" = 75,
      "comment" = "the exceptional-strength subroll ceiling of the sixty-one-to-seventy band, fifty-one to seventy-five the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23StrSubNinety",
      "value" = 90,
      "comment" = "the exceptional-strength subroll ceiling of the seventy-one-to-eighty band, seventy-six to ninety the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23StrSubNinetyNine",
      "value" = 99,
      "comment" = "the exceptional-strength subroll ceiling of the eighty-one-to-ninety band, ninety-one to ninety-nine the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecAtkMin",
      "value" = 1,
      "comment" = "the special attacks floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecAtkMax",
      "value" = 3,
      "comment" = "the special attacks ceiling of three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecAtkOptions",
      "value" = 8,
      "comment" = "the eight special attack options from ability drain to summon or gate the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23LesserSpellMin",
      "value" = 1,
      "comment" = "the lesser-creature spell and spell-like floor of one each the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23LesserSpellMax",
      "value" = 2,
      "comment" = "the lesser-creature spell and spell-like ceiling of two each the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PowerSpellMin",
      "value" = 2,
      "comment" = "the powerful-creature spells floor of two the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PowerSpellMax",
      "value" = 5,
      "comment" = "the powerful-creature spells ceiling of five the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecDefMin",
      "value" = 1,
      "comment" = "the special defenses floor of one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecDefMax",
      "value" = 4,
      "comment" = "the special defenses ceiling of four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecDefOptions",
      "value" = 10,
      "comment" = "the ten special defense options from acid immunity to weapon immunity the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23RegenBase",
      "value" = 1,
      "comment" = "the regeneration base of one hit point per turn, one per round the maximum the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpellImmuMin",
      "value" = 1,
      "comment" = "the spell immunity floor of one pre-determined spell the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpellImmuMax",
      "value" = 4,
      "comment" = "the spell immunity ceiling of four pre-determined spells the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MetalKinds",
      "value" = 3,
      "comment" = "the metal immunity kinds - iron, silver or steel the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23WeaponImmuMinPlus",
      "value" = 1,
      "comment" = "the weapon immunity magic bonus floor of plus one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PoisonChance",
      "value" = 4,
      "comment" = "the optionally-poisoned chance of four in six on the double-starred parts the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23InsanityRoundsMax",
      "value" = 4,
      "comment" = "the poison insanity result of one to four rounds the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23WeaknessPoints",
      "value" = 1,
      "comment" = "the poison weakness result of one point per hit permanently lost the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23OtherAbilities",
      "value" = 3,
      "comment" = "the three optional other abilities - audial superiority, surprise capability and visual superiority the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HeadCount",
      "value" = 8,
      "comment" = "the head option count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AdornCount",
      "value" = 8,
      "comment" = "the head adornment count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23VisageCount",
      "value" = 6,
      "comment" = "the overall visage count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23EarsCount",
      "value" = 6,
      "comment" = "the ears count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23EyeFormCount",
      "value" = 6,
      "comment" = "the eye form and color count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23NoseCount",
      "value" = 6,
      "comment" = "the nose count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthCount",
      "value" = 6,
      "comment" = "the mouth type count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BipedCount",
      "value" = 6,
      "comment" = "the bipedal torso count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23QuadCount",
      "value" = 7,
      "comment" = "the quadrapedal torso count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23CharCount",
      "value" = 8,
      "comment" = "the general characteristics count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BackCount",
      "value" = 4,
      "comment" = "the back count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SkinCount",
      "value" = 10,
      "comment" = "the skin count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23WingsCount",
      "value" = 4,
      "comment" = "the wings count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23ColorCount",
      "value" = 10,
      "comment" = "the predominate color count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23TailTypeCount",
      "value" = 8,
      "comment" = "the tail type count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23OdorCount",
      "value" = 8,
      "comment" = "the body odor count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23HandTypeCount",
      "value" = 6,
      "comment" = "the hands count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FeetCount",
      "value" = 8,
      "comment" = "the legs and feet count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BirdFootCount",
      "value" = 6,
      "comment" = "the bird-like feet count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MoveCount",
      "value" = 5,
      "comment" = "the base move count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MrVarCount",
      "value" = 6,
      "comment" = "the magic resistance variance count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PoisonCount",
      "value" = 6,
      "comment" = "the optional-poison count the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23StrCount",
      "value" = 9,
      "comment" = "the strength band count the Sorceror Scroll lower-planes generator (print 15-18)",
    } },
  "bools" = { {
      "name" = "s23OfficialApproach",
      "value" = true,
      "comment" = "what follows is the current official approach to lower-planes creatures the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23DmgPreview",
      "value" = true,
      "comment" = "what you read here will be included in the forth coming DUNGEON MASTERS GUIDE the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23RihnPickensThanks",
      "value" = true,
      "comment" = "the Gygax thanks to both Greg and Jon in the opening paragraph the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23FormatMonsterManual",
      "value" = true,
      "comment" = "the format is straight from the AD&D MONSTER MANUAL for ease of recording the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23CircumstancesDictate",
      "value" = true,
      "comment" = "the circumstances-must-dictate note printed three times - number appearing, percent in lair and treasure type the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23EyesPlusCatch",
      "value" = true,
      "comment" = "the print catch - the eyes count line prints the roll-one result as the formula one plus one the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MouthFourCatch",
      "value" = true,
      "comment" = "the print catch - the mouth size line skips the d4 result, one tiny, two to three average, five to six huge the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpecialEffectsMinimum",
      "value" = true,
      "comment" = "the special effects from the attack forms - poison, energy drain, heat, cold, electrical discharge, paralysis - kept to a minimum the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23StrOverlapCatch",
      "value" = true,
      "comment" = "the print catch - the strength bands overlap at forty-five, twenty-six-to-forty-five and forty-five-to-sixty the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23ImmunityOverFourConditional",
      "value" = true,
      "comment" = "the immunities above four possible only if the general class - demons, devils and the rest - has more the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23MetalExcludesMagic",
      "value" = true,
      "comment" = "the metal immunity excludes magical weaponry, iron, silver, steel or combinations the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23WeaponImmunityMagicalOnly",
      "value" = true,
      "comment" = "the weapon immunity refers to creatures hit only by magical weapons of a certain value the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23SpellImmunityPredetermined",
      "value" = true,
      "comment" = "the spell immunity must be limited to the pre-determined spells the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23AudialNegatesSurprise",
      "value" = true,
      "comment" = "the audial or visual superiority tending to negate surprise and enable detection through sound or vision the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23VisualInfravisual",
      "value" = true,
      "comment" = "the visual superiority referring to infravisual and ultravisual capabilities the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23ExxeduunusseSignoff",
      "value" = true,
      "comment" = "the mid-article sign-off gag - EXXEDUUNUSSE, BUT I NEED A VACATION, SEE YA NEXT MONTH, printed at the feet of the general characteristics the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23ForthComingCatch",
      "value" = true,
      "comment" = "the print catch - the opening paragraph prints forth coming as two words in the DMG preview sentence the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23QuadrapedalEtalCatch",
      "value" = true,
      "comment" = "the print catch - the body attributes line prints quadrapedal etal, the quadrupedal and so on the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23DfForCfCatch",
      "value" = true,
      "comment" = "the print catch - the Demonology Made Easy citation prints Df. for cf. the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23PredominateCatch",
      "value" = true,
      "comment" = "the print catch - the color list heading prints Predominate Color for predominant the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23BirdAsteriskCatch",
      "value" = true,
      "comment" = "the print catch - the bird-like head carries an asterisk footnoted two pages later with the six bird-like feet the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23DefEtcCatch",
      "value" = true,
      "comment" = "the print catch - the defense mode line ends with the bare etc., F on one to two, F and G on three to four the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "name" = "s23TarterusCanon",
      "value" = false,
      "comment" = "the negative pin - Tarterus is the AD&D canon spelling, not a print catch the Sorceror Scroll lower-planes generator (print 15-18)",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "s23Head",
      "tag" = "Hd",
      "count" = "s23HeadCount",
      "sentinel" = -99,
      "audit_comment" = "the head table - bat-like, bird-like, crocodilian, horse-like, human-like, monkey-like, snake-like, weasel-like the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23HeadOpt" },
      "col_comments" = { "the head option ordinal - bat-like through weasel-like the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 } },
    }, {
      "name" = "s23HeadAdorn",
      "tag" = "Ha",
      "count" = "s23AdornCount",
      "sentinel" = -99,
      "audit_comment" = "the head adornment table - antlers, crest or peak, horns, knobs, ridges, ruff, spines, none the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23AdornOpt" },
      "col_comments" = { "the head adornment ordinal - antlers through none the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 } },
    }, {
      "name" = "s23Visage",
      "tag" = "Vi",
      "count" = "s23VisageCount",
      "sentinel" = -99,
      "audit_comment" = "the overall visage table - gibbering-drooling, glaring-menacing, rotting, skeletal, twitching-moving, wrinkled-seamed the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23VisageOpt" },
      "col_comments" = { "the overall visage ordinal - gibbering-drooling through wrinkled-seamed the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23Ears",
      "tag" = "Ea",
      "count" = "s23EarsCount",
      "sentinel" = -99,
      "audit_comment" = "the ears table - dog-like, elephant-like, human tiny, human huge, trumpet-like, none the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23EarsOpt" },
      "col_comments" = { "the ears ordinal - dog-like through none the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23EyeForm",
      "tag" = "Ef",
      "count" = "s23EyeFormCount",
      "sentinel" = -99,
      "audit_comment" = "the eye form and color grid - small multi-faceted amber through huge protruding orange-red the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23EyeFormOpt", "s23EyeColorOpt" },
      "col_comments" = { "the eye form ordinal - small multi-faceted through huge protruding the Sorceror Scroll lower-planes generator (print 15-18)", "the eye color ordinal - amber through orange-red the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 }, { 6, 6 } },
    }, {
      "name" = "s23Nose",
      "tag" = "No",
      "count" = "s23NoseCount",
      "sentinel" = -99,
      "audit_comment" = "the nose table - flat misshapen, huge bulbous, slits only, snouted, tiny, trunk-like, if necessary the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23NoseOpt" },
      "col_comments" = { "the nose ordinal - flat misshapen through trunk-like the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23Mouth",
      "tag" = "Mo",
      "count" = "s23MouthCount",
      "sentinel" = -99,
      "audit_comment" = "the mouth table - fanged, mandibled, sucker-like, toothed small or ridged, toothed large, tusked the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23MouthOpt" },
      "col_comments" = { "the mouth type ordinal - fanged through tusked the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23BipedTorso",
      "tag" = "Bt",
      "count" = "s23BipedCount",
      "sentinel" = -99,
      "audit_comment" = "the bipedal torso table - ape-like, bear-like, bird-like, human-like, pig-like, rat-like the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23BipedOpt" },
      "col_comments" = { "the bipedal torso ordinal - ape-like through rat-like the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23QuadTorso",
      "tag" = "Qt",
      "count" = "s23QuadCount",
      "sentinel" = -99,
      "audit_comment" = "the quadrapedal or other torso table - amoeba-like, bison-like, crab-like, horse-like, insect-like, serpent-like or reptilian, spider-like the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23QuadOpt" },
      "col_comments" = { "the quadrapedal or other torso ordinal - amoeba-like through spider-like the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 } },
    }, {
      "name" = "s23Character",
      "tag" = "Gc",
      "count" = "s23CharCount",
      "sentinel" = -99,
      "audit_comment" = "the general characteristics table - fat, long, short, thin, broad, muscled, narrow, rubbery the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23CharOpt" },
      "col_comments" = { "the general characteristics ordinal - fat through rubbery the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 } },
    }, {
      "name" = "s23Back",
      "tag" = "Bk",
      "count" = "s23BackCount",
      "sentinel" = -99,
      "audit_comment" = "the back table - humped-hunched, maned, normal, spiked-spined-ridged the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23BackOpt" },
      "col_comments" = { "the back ordinal - humped-hunched through spiked-spined-ridged the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 } },
    }, {
      "name" = "s23Skin",
      "tag" = "Sk",
      "count" = "s23SkinCount",
      "sentinel" = -99,
      "audit_comment" = "the skin table - bald-smooth, furred, hairy-bristled, leathery-leprous, scaled, slimed, warted-bumpy, wrinkled-folded, feathered, translucent the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23SkinOpt" },
      "col_comments" = { "the skin ordinal - bald-smooth through translucent the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 }, { 10 } },
    }, {
      "name" = "s23Wings",
      "tag" = "Wg",
      "count" = "s23WingsCount",
      "sentinel" = -99,
      "audit_comment" = "the wings-if-any table - bat-like, bird-like, insect-like, membranous or fan-like the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23WingOpt" },
      "col_comments" = { "the wings ordinal - bat-like through membranous or fan-like the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 } },
    }, {
      "name" = "s23Color",
      "tag" = "Cl",
      "count" = "s23ColorCount",
      "sentinel" = -99,
      "audit_comment" = "the predominate color table - blackish, bluish, brownish, grayish-whitish, greenish, orangy, pinkish, purplish, reddish, yellowish-tannish the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23ColorOpt" },
      "col_comments" = { "the predominate color ordinal - blackish through yellowish-tannish the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 }, { 10 } },
    }, {
      "name" = "s23Tail",
      "tag" = "Tl",
      "count" = "s23TailTypeCount",
      "sentinel" = -99,
      "audit_comment" = "the tail type table - barbed, dog-like, goat-like, horse-like, lion-like, pig-like, prehensile, stingered the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23TailTypeOpt" },
      "col_comments" = { "the tail type ordinal - barbed through stingered the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 } },
    }, {
      "name" = "s23Odor",
      "tag" = "Od",
      "count" = "s23OdorCount",
      "sentinel" = -99,
      "audit_comment" = "the body odor table - bloody, fishy, fecal, gangrenous, moldy, sweaty, urine, vomit the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23OdorOpt" },
      "col_comments" = { "the body odor ordinal - bloody through vomit the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 } },
    }, {
      "name" = "s23Hand",
      "tag" = "Hn",
      "count" = "s23HandTypeCount",
      "sentinel" = -99,
      "audit_comment" = "the hands table - clawed, human nailed, pincered, taloned, tentacle fingered, withered and boney the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23HandTypeOpt" },
      "col_comments" = { "the hands ordinal - clawed through withered and boney the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23Feet",
      "tag" = "Ft",
      "count" = "s23FeetCount",
      "sentinel" = -99,
      "audit_comment" = "the legs and feet table - clawed, hooved, human-like, insect-like, snake-like, suctioned, taloned, webbed the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23FeetOpt" },
      "col_comments" = { "the legs and feet ordinal - clawed through webbed, all swimmers the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 } },
    }, {
      "name" = "s23BirdFeet",
      "tag" = "Bf",
      "count" = "s23BirdFootCount",
      "sentinel" = -99,
      "audit_comment" = "the bird-like feet table - duck-like, hawk-like, owl-like, pelican-like, stork-like, turkey-like the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23BirdFootOpt" },
      "col_comments" = { "the bird-like feet ordinal - duck-like through turkey-like the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 } },
    }, {
      "name" = "s23Move",
      "tag" = "Mv",
      "count" = "s23MoveCount",
      "sentinel" = -99,
      "audit_comment" = "the base move table - six, nine, twelve, fifteen or eighteen inches the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23MoveInch" },
      "col_comments" = { "the base move speeds in inches - six through eighteen the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 6 }, { 9 }, { 12 }, { 15 }, { 18 } },
    }, {
      "name" = "s23MrVar",
      "tag" = "Mr",
      "count" = "s23MrVarCount",
      "sentinel" = -99,
      "audit_comment" = "the magic resistance variance table - minus five, minus ten, plus five, plus ten, plus fifteen, standard the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23MrMod" },
      "col_comments" = { "the magic resistance d6 variance modifier, zero the standard on six the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { -5 }, { -10 }, { 5 }, { 10 }, { 15 }, { 0 } },
    }, {
      "name" = "s23Poison",
      "tag" = "Ps",
      "count" = "s23PoisonCount",
      "sentinel" = -99,
      "audit_comment" = "the optional-poison save table - plus one, normal, minus one, minus two, insanity for one to four rounds, weakness one point per hit permanently lost the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23PoisonOpt", "s23PoisonMod" },
      "col_comments" = { "the optional-poison d6 result ordinal, one through six the Sorceror Scroll lower-planes generator (print 15-18)", "the save modifier - plus one through minus two, the sentinel marking the insanity and weakness rows the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1, 1 }, { 2, 0 }, { 3, -1 }, { 4, -2 }, { 5, -99 }, { 6, -99 } },
    }, {
      "name" = "s23Strength",
      "tag" = "St",
      "count" = "s23StrCount",
      "sentinel" = -99,
      "audit_comment" = "the strength-to-hit-damage table - the nine percentile bands from one through twenty-five to ninety-nine and double zero, the overlap at forty-five printed as scanned the Sorceror Scroll lower-planes generator (print 15-18)",
      "cols" = { "s23StrLo", "s23StrHi", "s23StrVal", "s23StrHit", "s23StrDmg" },
      "col_comments" = { "the strength percentile band floor the Sorceror Scroll lower-planes generator (print 15-18)", "the strength percentile band ceiling, the hundred standing for double zero the Sorceror Scroll lower-planes generator (print 15-18)", "the strength score of the band - seventeen through twenty the Sorceror Scroll lower-planes generator (print 15-18)", "the to-hit bonus of the band - plus one through plus three the Sorceror Scroll lower-planes generator (print 15-18)", "the damage bonus of the band - plus one through plus eight the Sorceror Scroll lower-planes generator (print 15-18)" },
      "data" = { { 1, 25, 17, 1, 1 }, { 26, 45, 18, 1, 2 }, { 45, 60, 18, 1, 3 }, { 61, 70, 18, 2, 3 }, { 71, 80, 18, 2, 4 }, { 81, 90, 18, 2, 5 }, { 91, 95, 18, 3, 6 }, { 96, 98, 19, 3, 7 }, { 99, 100, 20, 3, 8 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['s23LowerPlanes']() != 5 or m['s23RihnIssue']() != 20 or m['s23PickensIssue']() != 13 or m['s23OfficialApproach']() != 1 or m['s23DmgPreview']() != 1",
      "note" = "the frame - the five lower planes, the Rihn and Pickens antecedents, the official approach riding into the forth coming DMG the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23FreqBands']() != 3 or m['s23AppearMax']() != 8 or m['s23AcDice']() != 4 or m['s23AcBest']() != -3 or m['s23AcWorst']() != 0",
      "note" = "the base block - the frequency bands, the number appearing ceiling, the armor class d4 from zero to minus three the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23HdBase']() != 6 or m['s23HdMax']() != 10 or m['s23HdBonusOn']() != 4 or m['s23HdBonusMax']() != 4 or m['s23MrPerDie']() != 5",
      "note" = "the hit dice and magic resistance - d4 plus six for seven to ten dice, the four-face bonus hit points, five percent per die the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23PsiNil']() != 90 or m['s23PsiBase']() != 95 or m['s23PsiDie']() != 20 or m['s23PsiMin']() != 96 or m['s23PsiMax']() != 115",
      "note" = "the psionic block - ninety percent nil, else d20 plus ninety-five for ninety-six to one hundred fifteen the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23AtkModeCount']() != 4 or m['s23DefModeCount']() != 3 or m['s23DefModeDie']() != 6 or m['s23DefBandWidth']() != 2 or m['s23DefEtcCatch']() != 1",
      "note" = "the psionic modes - A through D on the d4, F through H on the d6 in two-face bands ending at the bare etc. the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23EyesMid']() != 2 or m['s23EyesHighMin']() != 3 or m['s23EyesHighMax']() != 4 or m['s23EyesPlusCatch']() != 1 or m['s23EyeFormCount']() != 6",
      "note" = "the eyes - the two-to-four and five-to-six bands, the one-plus-one formula catch, the six-row form and color grid the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23MouthAvgHi']() != 3 or m['s23MouthHugeLo']() != 5 or m['s23MouthFourCatch']() != 1 or m['s23MouthCount']() != 6",
      "note" = "the mouth - the average and huge bands with the skipped four, the six mouth types the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23BipedHi']() != 4 or m['s23QuadLo']() != 5 or m['s23QuadCount']() != 7 or m['s23QuadrapedalEtalCatch']() != 1",
      "note" = "the body attributes - the bipedal and quadrapedal etal bands, the seven quadrapedal torso options the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23SkinCount']() != 10 or m['s23ColorCount']() != 10 or m['s23PredominateCatch']() != 1 or m['s23CharCount']() != 8",
      "note" = "the coverings - the ten skin options, the ten predominate colors, the eight general characteristics the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23TailHi']() != 4 or m['s23PoisonChance']() != 4 or m['s23InsanityRoundsMax']() != 4 or m['s23WeaknessPoints']() != 1 or m['s23TailTypeCount']() != 8",
      "note" = "the tail and poison - the one-to-four tail band, the four-in-six optional poison, the insanity and weakness rows the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23StrSubFifty']() != 50 or m['s23StrSubNinety']() != 90 or m['s23StrSubNinetyNine']() != 99 or m['s23StrOverlapCatch']() != 1",
      "note" = "the exceptional strength subrolls - the fifty, seventy-five, ninety and ninety-nine ceilings, the forty-five overlap the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23AntlerSidesMax']() != 8 or m['s23MouthDmgMaxSides']() != 12 or m['s23HandSidesMax']() != 12 or m['s23FootSidesMax']() != 12 or m['s23HugeClawDice']() != 2",
      "note" = "the attack forms - antlers to two-eight, mouth to three-twelve, hands to two-twelve, feet to three-twelve, the huge claw floor the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23SpecAtkMax']() != 3 or m['s23SpecAtkOptions']() != 8 or m['s23PowerSpellMax']() != 5 or m['s23SpecDefMax']() != 4 or m['s23SpecDefOptions']() != 10",
      "note" = "the special attacks and defenses - one to three of eight attacks, one to four of ten defenses, the two-to-five spell ceiling the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23RegenBase']() != 1 or m['s23SpellImmuMax']() != 4 or m['s23MetalKinds']() != 3 or m['s23WeaponImmuMinPlus']() != 1 or m['s23ImmunityOverFourConditional']() != 1",
      "note" = "the defense limits - the regeneration base, the one-to-four pre-determined spells, the three metals, the plus-one weapon floor the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23ForthComingCatch']() != 1 or m['s23DfForCfCatch']() != 1 or m['s23BirdAsteriskCatch']() != 1 or m['s23ExxeduunusseSignoff']() != 1",
      "note" = "the print-catch roll - the two-word forth coming, the Df. citation, the bird asterisk, the EXXEDUUNUSSE vacation sign-off the Sorceror Scroll lower-planes generator (print 15-18)",
    }, {
      "expr" = "m['s23OtherAbilities']() != 3 or m['s23TarterusCanon']() != 0 or m['s23CircumstancesDictate']() != 1",
      "note" = "the closing notes - the three optional abilities, the Tarterus canon pin, the thrice circumstances-must-dictate the Sorceror Scroll lower-planes generator (print 15-18)",
    } },
  "audit" = {
      "label" = "R951 issue-23 Lower Planes generation audit",
      "comment" = "THE SORCEROR SCROLL LOWER-PLANES GENERATOR AUDIT - the issue-23 part-two table round, the Random Generation of Creatures from the Lower Planes system headed into the forth coming DUNGEON MASTERS GUIDE. The base stat block, the twenty-three appearance and generation grids, the strength-to-hit-damage bands, the attack forms, the special attacks and defenses and the optional-poison footnote all ride this single chain, print 15 through 18.",
    },
}
