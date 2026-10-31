// =========================================================================================
// Adnd1 - rules/s23.h
// The Dragon issue-23 opener part two - the Lower Planes creature generator
// census 873 -> 874.
//
// The part-two round of the issue-23 four-round shape - the single chain of
// the Sorceror Scroll DMG preview, the table round of the walk: the Random
// Generation of Creatures from the Lower Planes system, Gary Gygax on the
// Abyss, Tarterus, Hades, Gehenna and Hell. Pinned from The Dragon Vol. III
// No. 9 (March 1979) print 15 through 18 at extract/dragon/023, PRINT FOLIO =
// PDF PAGE this issue, the transcript of the Curtiss-provided scan. The Rihn
// and Pickens antecedents ride the frame; the EXXEDUUNUSSE sign-off rides the
// general characteristics; the two inherited watches - the Sullin levels 7-9
// and the brawling sequel - print nowhere in issue 23 and ride to TD 24.
//
namespace rules {

// ---- the Sorceror Scroll lower-planes generator (print 15-18) ----

// the five named lower planes - the Abyss, Tarterus, Hades, Gehenna and Hell
// the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23LowerPlanes()
    { return 5; }

// the Gregory Rihn Demonology Made Easy article that prompted the system, TD
// 20 the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23RihnIssue()
    { return 20; }

// the Jon Pickens random demons article re-read for the system, TD 13 the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23PickensIssue()
    { return 13; }

// the frequency bands - common, uncommon or rare on the d6 the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23FreqBands()
    { return 3; }

// the number appearing floor of one the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23AppearMin()
    { return 1; }

// the number appearing ceiling of two to eight the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AppearMax()
    { return 8; }

// the armor class d4 - zero through minus three the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AcDice()
    { return 4; }

// the worst armor class of the range, zero the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23AcWorst()
    { return 0; }

// the best armor class of the range, minus three the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AcBest()
    { return -3; }

// the base move d8 with six through eight rolling the d4 reroll the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23MoveDie()
    { return 8; }

// the d8 face where the move rerolls on the d4 the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23MoveRerollFrom()
    { return 6; }

// the reroll die for the base move the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23MoveRerollDie()
    { return 4; }

// the three-inch increments added to swimming or flying speed the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23MoveIncrement()
    { return 3; }

// the one-to-four increments of the speed bonus the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23MoveBonusMax()
    { return 4; }

// the swimming d6 floor of one the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23SwimLo()
    { return 1; }

// the swimming d6 ceiling of two the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23SwimHi()
    { return 2; }

// the flying d6 floor of three the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23FlyLo()
    { return 3; }

// the flying d6 ceiling of six the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23FlyHi()
    { return 6; }

// the hit die formula base, d4 plus six the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HdBase()
    { return 6; }

// the hit die formula die of four the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23HdDice()
    { return 4; }

// the hit dice floor of seven the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23HdMin()
    { return 7; }

// the hit dice ceiling of ten the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23HdMax()
    { return 10; }

// the second d4 face of four that grants bonus hit points per die the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23HdBonusOn()
    { return 4; }

// the bonus hit points per hit die floor of one the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23HdBonusMin()
    { return 1; }

// the bonus hit points per hit die ceiling of four the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23HdBonusMax()
    { return 4; }

// the standard magic resistance of five percent per hit die the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23MrPerDie()
    { return 5; }

// the intelligence bands - low, average, very or high on the d4 the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23IntBands()
    { return 4; }

// the size d8 the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23SizeDice()
    { return 8; }

// the size d8 ceiling of the small band, one the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23SizeSmallHi()
    { return 1; }

// the size d8 ceiling of the medium band, two through four the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23SizeMedHi()
    { return 4; }

// the ninety percent psionic nil chance the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23PsiNil()
    { return 90; }

// the psionic ability roll base, d20 plus ninety-five the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23PsiBase()
    { return 95; }

// the psionic ability roll die of twenty the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23PsiDie()
    { return 20; }

// the psionic ability floor of ninety-six the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23PsiMin()
    { return 96; }

// the psionic ability ceiling of one hundred fifteen the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23PsiMax()
    { return 115; }

// the four attack modes A through D on the d4 the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AtkModeCount()
    { return 4; }

// the attack mode die of four the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23AtkModeDie()
    { return 4; }

// the three defense modes F through H on the d6 the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23DefModeCount()
    { return 3; }

// the defense mode die of six the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23DefModeDie()
    { return 6; }

// the two-face defense bands - F on one to two, F and G on three to four, and
// so on the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23DefBandWidth()
    { return 2; }

// the horns adornment rolled one to four in the appearance table the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23HornsMax()
    { return 4; }

// the eyes result of two on the d6 two-to-four band the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23EyesMid()
    { return 2; }

// the eyes result floor of three on the d6 five-to-six band the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23EyesHighMin()
    { return 3; }

// the eyes result ceiling of four on the d6 five-to-six band the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23EyesHighMax()
    { return 4; }

// the average-mouth d6 floor of two the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23MouthAvgLo()
    { return 2; }

// the average-mouth d6 ceiling of three the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23MouthAvgHi()
    { return 3; }

// the huge-mouth d6 floor of five the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23MouthHugeLo()
    { return 5; }

// the huge-mouth d6 ceiling of six the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23MouthHugeHi()
    { return 6; }

// the bipedal d6 floor of one the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23BipedLo()
    { return 1; }

// the bipedal d6 ceiling of four the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23BipedHi()
    { return 4; }

// the quadrapedal d6 floor of five the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23QuadLo()
    { return 5; }

// the quadrapedal d6 ceiling of six the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23QuadHi()
    { return 6; }

// the arms floor of two the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23ArmsMin()
    { return 2; }

// the bipedal arms choices, two or four the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23BipedArmsMax()
    { return 4; }

// the otherwise arms choices, two, four or six the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23OtherArmsMax()
    { return 6; }

// the all-alike hands d6 ceiling of three the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HandsAlikeHi()
    { return 3; }

// the different hands d6 floor of four the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HandsDiffLo()
    { return 4; }

// the tail d6 floor of one the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23TailLo()
    { return 1; }

// the tail d6 ceiling of four - one to four the creature has a tail the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23TailHi()
    { return 4; }

// the antlers-or-horns damage floor, one die of two the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AntlerDiceMin()
    { return 1; }

// the antlers-or-horns damage floor sides of two the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AntlerSidesMin()
    { return 2; }

// the antlers-or-horns damage ceiling of two dice the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AntlerDiceMax()
    { return 2; }

// the antlers-or-horns damage ceiling sides of eight the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AntlerSidesMax()
    { return 8; }

// the mouth damage floor of one the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23MouthDmgMin()
    { return 1; }

// the mouth damage ceiling of three dice the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23MouthDmgMaxDice()
    { return 3; }

// the mouth damage ceiling sides of twelve the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23MouthDmgMaxSides()
    { return 12; }

// the tail damage floor of one the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23TailDmgMin()
    { return 1; }

// the tail damage ceiling of six the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23TailDmgMax()
    { return 6; }

// the hands damage floor, one die of two the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HandDiceMin()
    { return 1; }

// the hands damage floor sides of two the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HandSidesMin()
    { return 2; }

// the hands damage ceiling of two dice the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HandDiceMax()
    { return 2; }

// the hands damage ceiling sides of twelve the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23HandSidesMax()
    { return 12; }

// the feet damage floor, one die of two the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23FootDiceMin()
    { return 1; }

// the feet damage floor sides of two the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23FootSidesMin()
    { return 2; }

// the feet damage ceiling of three dice the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23FootDiceMax()
    { return 3; }

// the feet damage ceiling sides of twelve the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23FootSidesMax()
    { return 12; }

// the huge-clawed-hands damage rating of two dice per hit the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23HugeClawDice()
    { return 2; }

// the huge-clawed-hands damage sides of eight the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23HugeClawSides()
    { return 8; }

// the incidental spine-type damage floor of one the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23SpineDmgMin()
    { return 1; }

// the incidental spine-type damage ceiling of six the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23SpineDmgMax()
    { return 6; }

// the exceptional-strength subroll ceiling of the forty-five-to-sixty band,
// one to fifty the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23StrSubFifty()
    { return 50; }

// the exceptional-strength subroll ceiling of the sixty-one-to-seventy band,
// fifty-one to seventy-five the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23StrSubSeventyFive()
    { return 75; }

// the exceptional-strength subroll ceiling of the seventy-one-to-eighty band,
// seventy-six to ninety the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23StrSubNinety()
    { return 90; }

// the exceptional-strength subroll ceiling of the eighty-one-to-ninety band,
// ninety-one to ninety-nine the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23StrSubNinetyNine()
    { return 99; }

// the special attacks floor of one the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23SpecAtkMin()
    { return 1; }

// the special attacks ceiling of three the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23SpecAtkMax()
    { return 3; }

// the eight special attack options from ability drain to summon or gate the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23SpecAtkOptions()
    { return 8; }

// the lesser-creature spell and spell-like floor of one each the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23LesserSpellMin()
    { return 1; }

// the lesser-creature spell and spell-like ceiling of two each the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23LesserSpellMax()
    { return 2; }

// the powerful-creature spells floor of two the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23PowerSpellMin()
    { return 2; }

// the powerful-creature spells ceiling of five the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23PowerSpellMax()
    { return 5; }

// the special defenses floor of one the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23SpecDefMin()
    { return 1; }

// the special defenses ceiling of four the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23SpecDefMax()
    { return 4; }

// the ten special defense options from acid immunity to weapon immunity the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23SpecDefOptions()
    { return 10; }

// the regeneration base of one hit point per turn, one per round the maximum
// the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23RegenBase()
    { return 1; }

// the spell immunity floor of one pre-determined spell the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23SpellImmuMin()
    { return 1; }

// the spell immunity ceiling of four pre-determined spells the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23SpellImmuMax()
    { return 4; }

// the metal immunity kinds - iron, silver or steel the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23MetalKinds()
    { return 3; }

// the weapon immunity magic bonus floor of plus one the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23WeaponImmuMinPlus()
    { return 1; }

// the optionally-poisoned chance of four in six on the double-starred parts
// the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23PoisonChance()
    { return 4; }

// the poison insanity result of one to four rounds the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23InsanityRoundsMax()
    { return 4; }

// the poison weakness result of one point per hit permanently lost the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23WeaknessPoints()
    { return 1; }

// the three optional other abilities - audial superiority, surprise
// capability and visual superiority the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23OtherAbilities()
    { return 3; }

// the head option count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23HeadCount()
    { return 8; }

// the head adornment count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23AdornCount()
    { return 8; }

// the overall visage count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23VisageCount()
    { return 6; }

// the ears count the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23EarsCount()
    { return 6; }

// the eye form and color count the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23EyeFormCount()
    { return 6; }

// the nose count the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23NoseCount()
    { return 6; }

// the mouth type count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23MouthCount()
    { return 6; }

// the bipedal torso count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23BipedCount()
    { return 6; }

// the quadrapedal torso count the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23QuadCount()
    { return 7; }

// the general characteristics count the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23CharCount()
    { return 8; }

// the back count the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23BackCount()
    { return 4; }

// the skin count the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23SkinCount()
    { return 10; }

// the wings count the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23WingsCount()
    { return 4; }

// the predominate color count the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23ColorCount()
    { return 10; }

// the tail type count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23TailTypeCount()
    { return 8; }

// the body odor count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23OdorCount()
    { return 8; }

// the hands count the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23HandTypeCount()
    { return 6; }

// the legs and feet count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23FeetCount()
    { return 8; }

// the bird-like feet count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23BirdFootCount()
    { return 6; }

// the base move count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23MoveCount()
    { return 5; }

// the magic resistance variance count the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23MrVarCount()
    { return 6; }

// the optional-poison count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23PoisonCount()
    { return 6; }

// the strength band count the Sorceror Scroll lower-planes generator (print
// 15-18)
inline int s23StrCount()
    { return 9; }

// what follows is the current official approach to lower-planes creatures the
// Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23OfficialApproach()
    { return true; }

// what you read here will be included in the forth coming DUNGEON MASTERS
// GUIDE the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23DmgPreview()
    { return true; }

// the Gygax thanks to both Greg and Jon in the opening paragraph the Sorceror
// Scroll lower-planes generator (print 15-18)
inline bool s23RihnPickensThanks()
    { return true; }

// the format is straight from the AD&D MONSTER MANUAL for ease of recording
// the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23FormatMonsterManual()
    { return true; }

// the circumstances-must-dictate note printed three times - number appearing,
// percent in lair and treasure type the Sorceror Scroll lower-planes
// generator (print 15-18)
inline bool s23CircumstancesDictate()
    { return true; }

// the print catch - the eyes count line prints the roll-one result as the
// formula one plus one the Sorceror Scroll lower-planes generator (print
// 15-18)
inline bool s23EyesPlusCatch()
    { return true; }

// the print catch - the mouth size line skips the d4 result, one tiny, two to
// three average, five to six huge the Sorceror Scroll lower-planes generator
// (print 15-18)
inline bool s23MouthFourCatch()
    { return true; }

// the special effects from the attack forms - poison, energy drain, heat,
// cold, electrical discharge, paralysis - kept to a minimum the Sorceror
// Scroll lower-planes generator (print 15-18)
inline bool s23SpecialEffectsMinimum()
    { return true; }

// the print catch - the strength bands overlap at forty-five,
// twenty-six-to-forty-five and forty-five-to-sixty the Sorceror Scroll
// lower-planes generator (print 15-18)
inline bool s23StrOverlapCatch()
    { return true; }

// the immunities above four possible only if the general class - demons,
// devils and the rest - has more the Sorceror Scroll lower-planes generator
// (print 15-18)
inline bool s23ImmunityOverFourConditional()
    { return true; }

// the metal immunity excludes magical weaponry, iron, silver, steel or
// combinations the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23MetalExcludesMagic()
    { return true; }

// the weapon immunity refers to creatures hit only by magical weapons of a
// certain value the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23WeaponImmunityMagicalOnly()
    { return true; }

// the spell immunity must be limited to the pre-determined spells the
// Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23SpellImmunityPredetermined()
    { return true; }

// the audial or visual superiority tending to negate surprise and enable
// detection through sound or vision the Sorceror Scroll lower-planes
// generator (print 15-18)
inline bool s23AudialNegatesSurprise()
    { return true; }

// the visual superiority referring to infravisual and ultravisual
// capabilities the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23VisualInfravisual()
    { return true; }

// the mid-article sign-off gag - EXXEDUUNUSSE, BUT I NEED A VACATION, SEE YA
// NEXT MONTH, printed at the feet of the general characteristics the Sorceror
// Scroll lower-planes generator (print 15-18)
inline bool s23ExxeduunusseSignoff()
    { return true; }

// the print catch - the opening paragraph prints forth coming as two words in
// the DMG preview sentence the Sorceror Scroll lower-planes generator (print
// 15-18)
inline bool s23ForthComingCatch()
    { return true; }

// the print catch - the body attributes line prints quadrapedal etal, the
// quadrupedal and so on the Sorceror Scroll lower-planes generator (print
// 15-18)
inline bool s23QuadrapedalEtalCatch()
    { return true; }

// the print catch - the Demonology Made Easy citation prints Df. for cf. the
// Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23DfForCfCatch()
    { return true; }

// the print catch - the color list heading prints Predominate Color for
// predominant the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23PredominateCatch()
    { return true; }

// the print catch - the bird-like head carries an asterisk footnoted two
// pages later with the six bird-like feet the Sorceror Scroll lower-planes
// generator (print 15-18)
inline bool s23BirdAsteriskCatch()
    { return true; }

// the print catch - the defense mode line ends with the bare etc., F on one
// to two, F and G on three to four the Sorceror Scroll lower-planes generator
// (print 15-18)
inline bool s23DefEtcCatch()
    { return true; }

// the negative pin - Tarterus is the AD&D canon spelling, not a print catch
// the Sorceror Scroll lower-planes generator (print 15-18)
inline bool s23TarterusCanon()
    { return false; }

// the head option ordinal - bat-like through weasel-like the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23HeadOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the head adornment ordinal - antlers through none the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23AdornOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the overall visage ordinal - gibbering-drooling through wrinkled-seamed the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23VisageOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the ears ordinal - dog-like through none the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23EarsOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the eye form ordinal - small multi-faceted through huge protruding the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23EyeFormOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the eye color ordinal - amber through orange-red the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23EyeColorOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the nose ordinal - flat misshapen through trunk-like the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23NoseOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the mouth type ordinal - fanged through tusked the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23MouthOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the bipedal torso ordinal - ape-like through rat-like the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23BipedOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the quadrapedal or other torso ordinal - amoeba-like through spider-like
// the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23QuadOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        default:
            return -99;
        }
    }

// the general characteristics ordinal - fat through rubbery the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23CharOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the back ordinal - humped-hunched through spiked-spined-ridged the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23BackOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return -99;
        }
    }

// the skin ordinal - bald-smooth through translucent the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23SkinOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the wings ordinal - bat-like through membranous or fan-like the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23WingOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        default:
            return -99;
        }
    }

// the predominate color ordinal - blackish through yellowish-tannish the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23ColorOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the tail type ordinal - barbed through stingered the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23TailTypeOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the body odor ordinal - bloody through vomit the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23OdorOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the hands ordinal - clawed through withered and boney the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23HandTypeOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the legs and feet ordinal - clawed through webbed, all swimmers the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23FeetOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return -99;
        }
    }

// the bird-like feet ordinal - duck-like through turkey-like the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23BirdFootOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the base move speeds in inches - six through eighteen the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23MoveInch(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 18;
        default:
            return -99;
        }
    }

// the magic resistance d6 variance modifier, zero the standard on six the
// Sorceror Scroll lower-planes generator (print 15-18)
inline int s23MrMod(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 0;
        default:
            return -99;
        }
    }

// the optional-poison d6 result ordinal, one through six the Sorceror Scroll
// lower-planes generator (print 15-18)
inline int s23PoisonOpt(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the save modifier - plus one through minus two, the sentinel marking the
// insanity and weakness rows the Sorceror Scroll lower-planes generator
// (print 15-18)
inline int s23PoisonMod(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return -2;
        case 4:
            return -99;
        case 5:
            return -99;
        default:
            return -99;
        }
    }

// the strength percentile band floor the Sorceror Scroll lower-planes
// generator (print 15-18)
inline int s23StrLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 26;
        case 2:
            return 45;
        case 3:
            return 61;
        case 4:
            return 71;
        case 5:
            return 81;
        case 6:
            return 91;
        case 7:
            return 96;
        case 8:
            return 99;
        default:
            return -99;
        }
    }

// the strength percentile band ceiling, the hundred standing for double zero
// the Sorceror Scroll lower-planes generator (print 15-18)
inline int s23StrHi(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 45;
        case 2:
            return 60;
        case 3:
            return 70;
        case 4:
            return 80;
        case 5:
            return 90;
        case 6:
            return 95;
        case 7:
            return 98;
        case 8:
            return 100;
        default:
            return -99;
        }
    }

// the strength score of the band - seventeen through twenty the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23StrVal(int b)
    {
        switch (b) {
        case 0:
            return 17;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 20;
        default:
            return -99;
        }
    }

// the to-hit bonus of the band - plus one through plus three the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23StrHit(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 3;
        default:
            return -99;
        }
    }

// the damage bonus of the band - plus one through plus eight the Sorceror
// Scroll lower-planes generator (print 15-18)
inline int s23StrDmg(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        default:
            return -99;
        }
    }

}   // namespace rules
