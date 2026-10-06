# DMG Gap Report - the book vs the repo

R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers.

R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws).
R111 CLOSED divergence 3 of 6 (fighter attack
matrix).
R112 CLOSED divergence 5 of 6 (monster attack
matrix).
R113 CLOSED divergence 4 of 6 (class attack
matrices).
R114 CLOSED divergence 6 of 6 (aging) - all
six of the original divergences are closed.
R115 verified the magic-weapon-to-hit gate
(p.76 - already the book's) and wired the
first magical aging cause (haste, p.14).
R116 CLOSED the missile range modifiers
(p.75) - -2 medium, -5 long, on the
engagement distance.
R117 CLOSED encounter reactions (p.64) -
the book's percentile seven-band table
replaces R8's 2d6 stand-in.
R118 CLOSED listening at doors (p.60) -
the book's racial d20 table replaces R11's
d6 bands; abilities.cpp joins the battery
build (it was compiled by nothing).
R119 CLOSED forced rest (p.38) - one turn
in six plus a turn after combat, gated.
R120 WIRED parley (R117's reaction roll
gates room and wandering encounters;
only the starred bands attack) and
listening at doors ([H], R118's table) -
first callers for both.
R121 CLOSED crew officers (p.35) - a
captain, a lieutenant and two mates
join the crew: wages 40 -> 300 gp, the
take's cut 5% -> 37% (PC keeps 63%).
R122 CLOSED the treasure line-diff
(pp.120-125) - every implemented table
diffed row-by-row against the book:
383 rows, dice bands, xp and gp values,
bundle quantities, no divergence. The
tables are now pinned, not just rolled.
R123 CLOSED outdoor movement (pp.58-59)
- the daily rates wired: afoot by
burden and terrain (the company at its
slowest walker's pace, true miles
tracked and logged), the coaster on
the book's sailed sea rate (50/day),
the mounted and afloat tables pinned
as data. Census 41.
R124 CLOSED Appendix A dressing
details (pp.169-172) - every table of
the random dungeon generation appendix
pinned row-by-row in the new
dm/appendixa.h: periodic check, doors,
side passages, widths, special passages
with their bridge/boat/jumping
chances, turns, chamber and room
shapes, unusual shape and size, exits,
contents and the stairway variant,
treasure by level, containers, guards,
hiding, stairs, tricks/traps, gas,
caves, pools, lakes and magic pools.
The walk's four helper rolls (width,
features, room size, contents) are
rewired to the exact tables - the
verification debt paid. Census 42.
R149 CLOSED the book-verify pass (the standing
debt): the fresh DMG/PHB uploads diffed end to
end - the Appendix G trap list, the Appendix H
attribute fragments, the Faerie / Pleistocene /
Age of Dinosaurs wilderness tables, the printing
variants, the city flavor cells and the p.71
example all verify; the p.38 rows eight of
fifteen, the rest unarbitratable against the
upload OCR; the noble gender split corrected to
75/25; the axe in the p.71 example is a hand
axe, its +1 no error at all. Appendix I dressing
named unpinned (a new open box). The compilation
site has gone dark - the fresh uploads are the
last standing source. Census 67.
R150 PINNED the Appendix I dressing lists (the
R149 bycatch): dm/appendixi.h, the appendixa.h
pattern - the five band lists (air currents,
odors, air, general items, unexplained sounds)
pinned edge for edge, with the R149 box band
counts corrected (14/54/58, not 16/100/68; the
band content was right). Census 68.
R151 PINNED the Appendix O encumbrance table (DMG
p.225): dm/appendixo.h, the appendixa.h pattern -
the 64 standard-item weights in g.p. units (57
exact rows; the four chests, gem, small jewelry
and tapestry ranges both ends; the tapestry open
tail), the 1500 g.p. (150#) carry max and the
four exemption wordings. The caller is
items::encumbranceBand (PHB p.38). Census 69.
R152 PINNED the becoming-lost check (DMG p.49): the
dm/outdoormove.h lost section - the 8 terrain chances
in 10 (plain 1 through forest 7), the three direction
limitations (60 degrees on five terrains, 120 on
mountains, any on forest and marsh) and the
lost-heading dice read clockwise (no result ever the
desired direction, as printed). The lost-party
procedure (back-track, re-roll the next day, describe
terrain as if on course) is judge narration, printed
and named, not engine data. Census 70.
R153 PINNED the exceptional strength table (PHB p.9),
a DIVERGENCE FIX round: the original transcription
carried unsourced carry and press numbers and misread
two band cells - the printed 18/91-99 row is +2 hit /
+5 damage (not +3/+6) and the 18/51-75 damage is +3
(not +4). The full STR Table II now pins all five
columns for the whole 3-18/00 table: hit probability,
damage, the g.p. weight allowance (-350 through
+3,000), open doors on a d6 with the locked-door
parentheticals (18/91-99: 1, 18/00: 2, one attempt
ever) and bend bars/lift gates (0% through 40%).
Census 71.
R154 PINNED the PC races layer (PHB pp.15-18, Race
Tables I-III): the racial ability adjustments with
the Table III minimums and maximums (male and female
columns), infravision, elven 90% and half-elven 30%
sleep-and-charm resistance, the CON magic-save bonus
for dwarf, gnome and halfling (the R147 shape), Race
Table I class limitations, the footnoted Race Table
II level caps, the goblin-kind and giant-kind
to-hit lists and the detection lists - and the
creation flow gains the RACE stage (ROLL -> RACE ->
CLASS -> NAME; appstate + the Win32 shell). FINDING:
the print gives the gnome the magic-save bonus ONLY -
no poison line rides it (dwarf and halfling carry
both); the open box claimed gnome poison saves, the
print wins. Census 72.
R155 PINNED matrix II.C (DMG p.80) - the classed
monsters: a classed foe saves on its MOST FAVORABLE
matrix (footnotes 1-2). The five MM1 write-ups that
print class abilities (brownie, dolphin, displacer
beast, couatl, ki-rin) gain the Lua saveAs key (class
bits + per-class levels; the couatl carries MU 5 AND
cleric 7), mostFavorableSaveTarget mins the save in
spelleffects and the ai save helper, and the displacer
+2 save die rides the actor saveBonus. FINDING: the
displacer magicResistance write-up (a save-as note)
misparsed as 12% MR - fixed to read 0. Judgment left
for a later lane: ixitxachitl (clerical, per-leader)
and the humanoid classed leaders are per-encounter
extras, not base-monster data. Census 73.
R156 PINNED the Appendix P caller (DMG pp.225-226) -
the convention-party generator: rollSpurMember rolls
the band/option level, the six 4d6-best-of scores and
the magic kit, and rollConventionParty (dm/encounters)
maps it onto the encounter party - rollMemberMagic,
the R147 tables, gain their first engine caller. The
multi-class level math and the alignment curation are
player-side (the print hands them to the table); the
ability scores stay player-side too - the encounter
party carries combat fields only. Census 74.
R157 PINNED grenade-like missiles + holy/unholy water
(DMG pp.64-65) - the thrown-flask layer: container sizes,
the effect table (direct hit + splash dice), the 3-inch
range bands, the item-save break rule (the p.80 matrix:
ceramic flask 18/12, crystal vial 19/14), the 3-foot
splash-save radius, the d6/d8 miss tables, the p.65
holy/unholy water targeting (non-material undead
unaffected), the flaming-oil crossing damage, the 2-5 gp
vial cost and the boulder drops. JUDGMENT: the acid flask
rides the ceramic row and the poison vial the crystal row
(the print names only the oil flask and the holy-water
vial); a drop under 10 feet reads at the window edge. The
to-hit throw itself stays in the missile-fire lane; poison
damage stays print-special (the caller holds the poison
lane). Census 75.
R158 PINNED weapon speed factors in initiative (DMG
p.66 + the PHB p.38 factor column) - rules/weaponspeed.h:
the named factor table (fist 1 through pike 13; the spear
prints 6-8 and defaults 7, footman/horseman mace and
flail named per the print), the simultaneous-initiative
tie order (lower factor strikes first), the extra-attacks
rule (difference at least twice the lower factor or 5+ =
two attacks before the slower acts; 10+ adds a third
simultaneous; never when closing or charging), and the
weapon-vs-activity strike segment (factor minus the
losing initiative die, negatives as positive, no
modification on a tied round). rules/turn verified first:
the scheduler carries NO factor logic and needs none - the
DMG limits factor use to these caller-detected cases. The
fireball example (sword 5 vs casting 3, dagger 2 vs 3,
the two-handed no-chance) is pinned in the audit.
Census 76.
R159 PINNED striking to subdue (DMG p.67 + the MM
dragon rules) - rules/subdue.h: the flat/butt/haft/
pommel strike (otherwise a normal attack), the 75/25
accounting (the print example 40 subdual = 10 real,
cumulative, floored), applicability (MM-stated or
humanoid size and type, never player characters), and
the knockout JUDGMENT (cumulative subdual meets or
exceeds remaining hit points). Dragon capture: announce
intent before combat (killing form otherwise, fixed
per dragon), silver/gold/chromatic/platinum unsubduable
(brass, bronze, copper can be), the average-or-better
attacker intelligence gate (JUDGMENT: 9), the percent
ratio with halves up (the MM example 44/88 = 50, 67/88
= 76, 77/88 = 88), the automatic 1:1 subdual, the
100-800 gp per hit point d8 sale price, and the ridden
convention. Census 77.
R160 PINNED weaponless combat (DMG pp.72-73) -
rules/weaponless.h: PUMMEL, GRAPPLE, OVERBEAR - the
shared variable (attacker column + d6, defender column +
d4, spent on the base chance or the attack score,
unconscious parties get none), the initiative priority
(surprise, charging, dex, die roll), the damage
accounting (25% actual pummel and grapple, 50% overbear,
the rest restored 1 hp per round; 0 hp = unconscious
1 round + 1 per point beyond, 4 beyond = 5 rounds; the
1-round truss), the base scores (pummel opponent AC x
10; grapple/overbear attacker AC x 10, magic devices
ignored, +1% per armor plus), every printed modifier,
the three result tables with their damage bases, the
hold ladder (higher-percentage holds break lower), and
the general notes (behind negates shield+dex, the
weapon wielder fends first unless surprised, monster
mode selection, bears grapple, monks unimpeded).
R161 PINNED attacks with two weapons (DMG p.70) -
rules/twoweapon.h: one weapon in each hand (the shield
option discarded), the second weapon a dagger or hand
axe only, the penalty ladder (primary -2, secondary
-4; eased above dex 15 - 16: -1/-3, 17: 0/-2, 18:
0/-1 - never a positive rating), dex below 6 adding
the PHB Reaction/Attacking Adjustment to EACH attack
(caller-side), and the secondary weapon never acting
as a shield or parrying device. Census 79.
R162 PINNED level title ladders (PHB pp.20-31
class tables) - rules/classes.cpp: the printed
per-level titles for the four engine classes,
replacing the placeholder ladders (the all-Conjurer
MU run, the Curate run, the all-Rogue thief).
Fighter: Veteran, Warrior, Swordsman, Hero,
Swashbuckler, Myrmidon, Champion, Superhero,
Lord. Magic-user: Prestidigitator, Evoker,
Conjurer, Theurgist, Thaumaturgist, Magician,
Enchanter, Warlock, Sorcerer, Necromancer,
Wizard. Cleric: Acolyte, Adept, Priest, Curate,
Canon, Lama, Patriarch, High Priest. Thief:
Rogue (Apprentice), Footpad, Cutpurse, Robber,
Burglar, Filcher, Sharper, Magsman, Thief,
Master Thief. JUDGMENT: the cleric level 5 title
cell prints blank and carries Curate down. The
PHB display rows above the engine caps (Lord
(10th Level) and the like) sit beyond
CLASS_LEVEL_CAP and stay out of engine scope.
The HP_BEYOND_CAP convention (3/1/2/2) is
print-verified in passing. R162 FINDING while
discharging the classes.h debt: the xpForLevel
rows DIVERGED from the print from mid-table on
(fighter level 5 read 16000 against the printed
18000 boundary; the MU, cleric and thief rows
diverged above that) - CLOSED R176: the rows
repinned to the print cell by cell.
Census 80.
R163 PINNED the poison table (DMG p.20) -
rules/poison.h: the purchased-poison types,
ingestive A-E and insinuative A-D, each with
cost per dose (5-1,000 gp ingestive, 10-1,500
insinuative), onset time with its unit (rounds,
ingestive D 1 segment, ingestive E 1-4 turns),
the damage classes (damage if saved, damage or
death if not), the footnote victim save bonuses
(+4/+3/+2/+1) and detection chances
(80/65/40/15). JUDGMENT: grade E prints no
footnotes - no save bonus, detection 0. The
class rules: a studied assassin gives no
penalty, an unstudied assassin +1 on the victim
save, everyone else +2; monster poison is
all-or-nothing and dual-use. The DMG p.28 blade
venom decay rides here: insinuative, full the
first day or hit, half the second, gone by the
third, +4 on saves once decayed. The caller
holds the save roll (the monster venom layer
keeps its per-monster saves). Census 81.
R164 PINNED the assassination table (DMG p.75) -
rules/assassinate.h: the assassins table for
assassinations, 15 rows (assassin level 1-15)
against 10 victim bands (0-1 through 18+), every
printed cell pinned; the printed dashes read as no
chance. JUDGMENT: an attacker below level 1
reads row 1, above 15 reads row 15. The footnote:
the table also governs attacks on helpless
opponents by any character class. The percentages
are near optimum conditions - the caller adjusts
up for perfect conditions (asleep and unguarded,
absolute trust, very drunk and unguarded) and down
for a wary, prepared or guarded victim; weapon
damage always occurs and may kill even when the
assassination roll fails (caller-side). The
percentile roll is caller-side (the grenade.h
pattern). Census 82.
R165 PINNED potion miscibility (DMG p.119) -
rules/miscibility.h: test whenever two potions are
intermingled or one is consumed while another is
still in effect (the roll made secretly). The d100
bands: 01 explosion (internal 6-60 hp; an
external mix blasts 1-10 hp within a 5 foot
radius and 4-24 hp in a 10 foot radius, no save -
the print renders the near radius as 5 double-
prime feet, read as 5 feet); 02-03 lethal poison
(the imbiber dead; an external mix a 10 foot gas
cloud, save versus poison or die); 04-08 mild
poison (nausea, -1 strength and -1 dexterity for
5-20 rounds, no save; one potion cancelled, the
other at half strength and duration, random
which); 09-15 both destroyed; 16-25 one
cancelled, the other normal; 26-35 both at half
efficacy; 36-90 miscible (contradictory effects
simply cancel); 91-99 one potion at 150 percent
efficacy; 00 discovery (one potion only functions,
its effect permanent, possible harmful side
effects). The campaign-fixed certain results the
print suggests (delusion mixes with anything,
treasure finding plus any potion is lethal poison,
oil of slipperiness plus etherealness: 50 percent
lost in the Ethereal for 5-30 days) are named
options, the print marking them as the DMs own
decisions. The d100 roll and all damage and
duration bookkeeping are caller-side. Census 83.
R166 PINNED intoxication and insanity (DMG
pp.82-83) - rules/insanity.h: the intoxication
table (bravery +1/+2/+4, morale +5/+10/+15
percent, intelligence -1/-3/-6, wisdom
-1/-4/-7, dexterity 0/-2/-5, charisma 0/-1/-4,
attack dice 0/-1/-5 with opponent magic saves
raised by the same, hit points 0/+1/+3; beyond
great, comatose with 7-10 hours of sleep); the
recovery table (slight 1-2 hours, moderate 2-4,
great 4-6, comatose 7-10; mild stimulants x
.80/.85/.90/.95, strong x .50/.55/.55/.60; a
strong stimulant risks a permanent -1
constitution at 5 percent per application); and
the 20 named insanity types with the four MILD
ones (dipsomania, kleptomania, schizoid,
pathological liar) subject to psionic attack, the
psionic-section duration classes (permanent
until heal, restoration or wish, two forms;
temporary 2-12 weeks; mild 1-4 weeks, one
form), and each form printed numeric parameter
(dipsomania 50/10, kleptomania seen 90 with
thief stealing -10, dementia praecox 25,
melancholia 50, schizophrenia 1-4 personalities
at 1 in 6 per day, mania 1 in 6 per turn for
2-12 turns with the 18/50, 18/75, 18/00
strength states, manic-depressive 1-4 days at 90
percent, hallucinatory 50 then 1-20 turns,
sado-masochism 1-3 days, homicidal 1-4 day
intervals then 1-6 day melancholia, hebephrenia
75 then 1-6 hours, suicidal 10-80 percent with
2-8 turn mania and 2-12 day melancholy,
catatonia 1 percent cumulative per round). The
behavioral prose is caller-side - the caller plays
the insane character. Census 84.
R167 PINNED PC disease and parasitic infestation
(DMG pp.13-14) - rules/disease.h: the monthly
contraction check (weekly when favorable, on
every carrier exposure) with the 2 percent disease
base and its eleven printed modifiers and the 3
percent parasite base and its six; the 16-row
disease (or disorder) table (body area by d100,
occurrence acute or chronic by d8, severity by d8,
three areas with no terminal column) and the
6-row parasite table, every cell pinned; the
severity effects (mild 1-3 weeks rest; severe hit
points to 50 percent, disabled 1-2 weeks plus 1-2
weeks mild; terminal death or function loss in
1-12 days with the per-area exceptions); the
occurrence and severity die roll adjustments (the
constitution ladder +2 through -4, chronic disease
+1, severe infestation +1, under 25 percent hit
points +1, a score of 0 or less means no
contraction, never used for parasites); the
per-area ability losses with their percent chances
(blood 1/1 per week, brain 1/1 per occurrence
with terminal in 1-12 hours, connective tissue
1 each per month with terminal treated as chronic
severe, eyes blind one or both at 50/50, muscles
25 percent permanent, nose-throat 10 percent,
respiratory 10 percent checked separately, skin
10/10/25, urinary 20 percent); and death from
disease or infestation (90 percent relapse unless
a curative is used, permanent losses never fixed
by any curative). The monster-borne layer
(mummy rot) stays as wired; the caller rolls
the dice and tracks the disability. Census 85.
R168 PINNED underwater spell use (DMG p.57) -
rules/uwspells.h: the general limits (spell
ranges and distances as in dungeons, material
components altered by water, fire-based spells do
not function except within an airy water radius,
electrical spells conducted to the entire
surrounding area); the cannot-cast lists cell
by cell - cleric 9 (speak with dead, lower
water, speak with plants, atonement, flame
strike, insect plague, aerial servant, control
weather, wind walk), druid 22 (predict
weather; fire trap, heat metal - its chill
metal reverse works - produce flame; call
lightning, pyrotechnics; animal summoning I,
call woodland beings, produce fire; animal
summoning II, control winds, insect plague,
pass plant, wall of fire; animal summoning
III, conjure fire elemental, fire seeds,
weather summoning; Chariot of Sustarre,
control weather, creeping doom, fire storm),
magic-user 10 (affect normal fires, burning
hands, find familiar, pyrotechnics, fireball,
flame arrow, gust of wind, fire charm, fire
shield - the hot flame version, its cold flame
version still functions - and fire trap); the
11 asterisked entries pinned as the printed
mark (the re-upload OCR shows no footnote for
it, so it rides as a flag); the altered-effects
list: cleric part water (a tunnel no wider
than 10 feet) and earthquake (shock waves
stunning all in range who fail a save vs
death magic for 5-20 rounds), druid conjure
earth elemental (confined to the water floor),
magic-user fly (swim at any depth even
encumbered, maximum speed 9 inches),
lightning bolt (a 2 inch radius sphere, save
for half), ice storm (hail 1-10 damage, sleet
no effect), wall of ice (floats to the
surface), conjure elemental (air and fire
impossible, earth as the druid spell, water
fine), Otiluke freezing sphere (50 cubic
feet per level, rounds per level, suffocation
unless immediate aid), part water (as the
clerical spell). The caller decides casting;
the encounter tables stay pinned R60/R127.
Census 86.
R169 PINNED the humanoid racial preferences table
(DMG p.106) - rules/humrpref.h: the nine-race
basic acceptability matrix (bugbear, gnoll,
goblin, hill giant, hobgoblin, kobold, ogre,
orc, troll - each rated against the same nine),
all 81 cells pinned with the star marks (18
single-star cells: the race will bully and
harass such humanoids; 3 double-star self
cells - hobgoblin, orc, troll - where the
others of the race are of a rival tribe or
family group, the other six self cells print
P); the six-letter key (P preference, G
goodwill, T tolerate, N neutral negative, A
antipathy - desert if leaders are weak, H
hatred - breaks into open hostilities at the
first opportunity or desert near a strong
body of the hated); the usage prose (fighting
or serving side by side within 12 inches,
no intervening troops or screen); and the
compatibility prose (demi-human troops use
the PHB RACIAL PREFERENCES TABLE; lizard men
hated by all save kobolds, and even kobolds
suspicious, just as human troops are).
JUDGMENT: the OCR wraps each row across
lines; the reconstruction was cross-validated
against the known print readings and every
probe matched. The caller reads the letter
and plays the troops. Census 87.
R170 PINNED followers for upper level player
characters by class (DMG pp.16-18) -
rules/followers.h: the cleric 7-category list
(roll for each, all 0 level men-at-arms, every
armor and weapon string pinned); the fighter
leader and troops bands (levels 5/6/6/7 with
the magic gear, the four company
compositions); the ranger 2d12 count with the
d% adjustment ladder (the +10 and +5 first
roll only, the rerule, scores over 70
special, one group per category); the thief
4d6 count with the level modifier ladder, the
six category bands, the race and level of
thief tables, the humans table I, the
12-row demi-humans table II, the multi-class
thief professions and the always neutral good
note; the animals, mounts, creatures and
special creatures tables; the assassin 7d4
guild count with the 75 percent desert, the
race and level of assassin tables, the 25
percent multi-class chance and the
multi-classed assassin professions; the
Grandfather/Grandmother ladder (1 8th, 2
7th, 3 6th, 4 5th, 5 4th, 6 3rd, 7 2nd = 28,
plus 4-16 1st level, up to 44 for the new
leader); the arrival timing (d10 with d6 tens
the first day 1-30, intervals 1-8 days, wait
1-4 then gone forever, a henchman may
receive); and the paladin warhorse (from 4th
level, within a 7 days ride, a task of 2 or
more weeks, possibly wild or guarded by an
evil fighter of the same level, 10 years of
service). JUDGMENTs: the OCR drops the
half-orcish 26-50 band of the race of
assassin table (pinned as the print runs);
the OCR interleaves the multi-classed
assassin table (the dwarf, elf and half-elf
rows each print no other class permitted);
the printed asterisks ride as flags. The
caller rolls the dice and builds the
rosters. Census 88.
R171 PINNED Appendices K, L and M (DMG
pp.221-224) - rules/klm.h: Appendix K - the
appearance and consistency list (10), the
transparency list (10 with the printed
parentheticals, four asking the reader to
determine), the color list (74 words in the 11
printed groups METALLIC through ORANGE) and the
taste and/or odor list (28), with the use
alongside Appendix I dungeon dressing;
Appendix L - the conjure animals prose (the
fractional hit point cost charged against the
total, random selection where several
possibilities exist, the caster cannot specify)
and the four hit dice category tables cell by
cell (5, 4, 15 and 13 rows with every band,
name and quarter cost), the printed 5-and-up
animal roster, the whale 36 hit dice cost cap
and the water note (swimmers and flying ones
only); Appendix M - the summoned monsters
prose (the evil parenthesis, the DM purview)
and all 20 tables cell by cell: the 7 land
tables (6, 6, 12, 12, 12, 16 and 34 rows) and
the 13 fresh/salt water tables (31 rows).
JUDGMENTs: the K lists were cell-verified
against the 1eonline.info compilation (the
repo-trusted source, the R146 precedent),
which agrees with the upload wherever legible;
the Appendix L 5-and-up band columns were OCR
debt, CLOSED R175 (the trusted compilation
supplies the full 26-row table - see the R175
header note);
the Appendix M water tables for summonings
II-VI are dropped by the upload and come
from the trusted compilation, which agrees
with the upload cell for cell on the I and VII
water tables the upload shows; the herbs
material interleaved in the upload K region
belongs to Appendix J (p.220, a separate open
box). The caller rolls and selects. Census 89.
R172 PINNED Appendix J (DMG p.220) - herbs, spices
and medicinal vegetables - rules/herbs.h: the
alphabetical plant and uses table, 171 rows, cell
by cell (the compilation drops the turnip row and
truncates the celery uses - both restored from the
print), the 10 rows the book leaves with unknown
uses, the one cross-reference row (blueberry - see
bilberry) and the intro and closing prose.
JUDGMENTs: the structure follows the 1eonline.info
compilation (the repo-trusted source, the R146
precedent), cell-verified against the book upload
wherever legible, with per-run cell-count
arithmetic used to detect compilation omissions;
print spellings win where they differ; the benzoin
anti-septic line break is read as antiseptic; the
compilation artifacts are normalized; Appendix J was
OUT of scope by design until this round reversed it
(user-authorized). Census 90.
R173 PINNED Secondary skills (DMG p.12) - the
player character non-professional skills -
rules/secondary.h: the 23-band SECONDARY SKILLS
TABLE cell by cell (the 21 named skills Armorer
01-02 through Woodworker/cabinetmaker 65-67, the
NO SKILL OF MEASURABLE WORTH band 68-85 and the
ROLL TWICE IGNORING THIS RESULT HEREAFTER band
86-00) and the when-to-use guidance (the intro,
assignment and adjudication prose). JUDGMENTs:
cell-verified against the book upload (band
arithmetic 1-100 clean) and independently
confirmed band for band by the mjyoung.net
transcription; the upload spelling wins where the
transcription paraphrases. Census 91.
R174 PINNED the R146 fiction leftovers (DMG p.191-192)
- the two city flavor notes the R149 book-verify pass
confirmed: the noble gender coin (nobleman-with-
retainers 75% / noblewoman 25%) with the noblewoman
75% sedan-chair likelihood (carriers and linkboys at
night), and the ruffian matrix footnote (1 in 4 can
be half-orc or of humanoid race - goblin, hobgoblin,
kobold, orc - banded as five equal fifths of the
quarter, the weights the book leaves unstated).
Fiction-only descriptors, the R146 precedent:
cityNobleKind / cityNoblewomanSedan / cityRuffianKind
in dm/encounters.cpp, wired to the city streets
excursion lines (game/state_sea.cpp), audited by the
R174 battery block. Census 92.
R175 PINNED the Appendix L 5-and-up table (DMG
p.222) - the R171 OCR-debt finding closed: the
book upload drops the band columns, but the
1eonline.info compilation (alive - its
conjure-animals page carries the complete
table) supplies the full section: hit dice
categories 5-14, 26 rows cell by cell (the
banded categories 5, 6, 7, 8, 10 and 12 with
every dice-score column; the bandless rows 9,
11, 13 and 14 the print dashes), every name
and quarter cost. JUDGMENTs: the pinned
20-name roster was incomplete (buffalo, skunk
giant, lion, bear cave and boar giant were
absent) - replaced by the full table; the
compilation spelling woolly corrects the
pinned wooly; the bandless rows pin as lo/hi
0 (the printed dash). rules/klm.h; the R175
battery audit carries the cell-by-cell check.
R176 PINNED the printed XP tables (PHB pp.20-31
class tables) - the R162 FINDING closed: the PHB
upload DOES carry the four printed XP boundary
columns (the R162 round had read the title
columns only). All four xpForLevel rows repinned
to the print cell by cell - fighter 0, 2000,
4000, 8000, 18000, 35000, 70000, 125000, 250000,
500000, 750000, then 250k per level past the
11th; MU 0, 2500, 5000, 10000, 22500, 40000,
60000, 90000, 135000, 250000, 375000, 750000,
1125000, then 375k past the 12th; cleric 0,
1500, 3000, 6000, 13000, 27500, 55000, 110000,
225000, 450000, 675000, then 225k past the
11th; thief 0, 1250, 2500, 5000, 10000, 20000,
42500, 70000, 110000, 160000, 220000, 440000,
660000, then 220k past the 12th. JUDGMENT: the
attain convention is the printed band lower
bound - 1 (fighter level 5: 18,001-35,000 gives
18000 - the old row read 16000); the engine
linear-beyond convention is kept, now anchored
on the printed adders. rules/classes.cpp; the
R176 battery audit carries the row walk, the
beyond-table probes and the clamps.
Census 94.
R177 CREATED the PHB gap report
(tools/phb_gap_report.md) - the sibling
whole-book inventory for the Players Handbook,
same conventions: verified boxes, ranked
divergences, open items, out-of-scope notes.
The founding read verified FIVE ability-table
divergences (the character.cpp ladders
transcribed from project notes - the R162 XP
finding class) plus the prime-requisite ladder
as an open verify. A report round adds no
audit; census stays 94.
R178 OPENED the subclass arc (the scope round,
no audit - census stays 94): full subclass
support is now engine scope - the six
subclasses, multi-class and dual-class, and
the full spell lists. The arc plan and round
queue live in the PHB gap report (the
subclass arc section). The live ability-table
divergences (DEX, CON) stay queued before the
arc rounds.
R178b AMENDED the arc scope: the bard (PHB
Appendix II - the fighter-then-thief-then-druid
progression, human or half-elf, always neutral)
joins the arc as R186, after the multi-class
round; the per-subclass specials renumber to
R187+. No audit; census stays 94.
R178c CLOSED the PHB report divergences 1 and 2
(the live bugs first, per the arc ordering
rule): rules/character.cpp - the DEX reaction
ladder repinned (3 -3, 4 -2, 18 +3; missile
attacks and surprise now read the print), the
CON system-shock (35-99) and resurrection-
survival (40-100) columns repinned cell by cell
(the raise-dead roll), the CON 6 hit-point cell
repinned -1, and the unsourced poison-save
accessor retired. New R178c battery audit;
census 95.
R179 PINNED the six subclass foundations (the
arc registry round): rules/subclasses.h CREATED,
data-driven - the six PHB subclasses with the
base-class map, caps, hit dice, the XP attain
rows and title ladders from the printed tables,
the adders, and the two-dice first levels
(ranger, monk). New R179 battery audit; census
96. The wiring rounds follow (qualification,
attacks, spells, multi-class, the bard).
R179b FIXED the R179 build: regtest.cpp now
includes rules/subclasses.h (the R179 audit
referenced the registry without the include -
preflight failed with 20 errors and the census
failed downstream of the missing binary).
LESSON: the acid test must SYNTAX-CHECK the
touched TUs (clang++ -fsyntax-only) whenever a
round adds code that regtest includes - a
header verified in isolation is not a build.
Census stays 96 (no new audit).
R180 landed the qualification and race gates:
rules/subclassgates.h CREATED (the ability
minimums, the Table I alignment letters, the XP
bonus rules, Race Table I and Race Table II cell
by cell, the halfling-druid NPC-only (6), the
footnote-8 gnome illusionist conditional). The
include landed with the audit (the R179 lesson
held). New R180 battery audit; census 97. The
assassin XP bonus pinned NONE - the class text
prints no bonus despite the thief-group pattern.
Next: R181 attacks per melee round.
R181 landed the attacks per melee round:
rules/attacksround.h CREATED (the fighter-group
bands with the printed level edges, the
under-one-hit-die note, the monk unarmed ladder
cell by cell, the monk weapon-damage bonus).
rules/turn.cpp meleeAttacksPerRound repinned - the
level-8+ original note replaced by the print (the
3/2 band opens at 7th; heavy-round convention, the
full rates in the header). New R181 battery audit;
census 98. Next: R182 the druid spell layer.
R182 landed the druid spell layer:
rules/druidspells.h CREATED (the 14x7
spells-usable table cell by cell, the 77-
spell roster with the reversible flags;
the printed dash pins as 0, past-14th
clamps to the 14th row). New R182 battery
audit; census 99. Next: R183 the illusionist
spell layer.
R183 landed the illusionist spell layer:
rules/illusionspells.h CREATED (the 26x7
spells-usable table cell by cell, the 61-
spell roster in the printed book order; no
reversible flags - the section prints none).
New R183 battery audit; census 100. Next:
R184 the paladin and ranger spell layers.
R184 landed the paladin and ranger spell
layers: rules/palrangerspells.h CREATED (the
paladin 9-20 x 4 progression, the ranger 8-17
x 5 progression, the shared-list wiring, lay
on hands, cure disease, the giant-class
roster and bonus). New R184 battery audit;
census 101. Next: R185 multi-class and
dual-class.
R185 landed the multi-class and dual-class
rules: rules/multiclass.h CREATED (the 22
per-race combos, the hit-point quotient, the
even XP split, the stalled hit dice, the
thief and cleric allowances, the half-elf
cleric WIS 13, the dual-class gates). New
R185 battery audit; census 102. Next: R186
the bard (Appendix II).
R186 landed the bard: rules/bard.h CREATED
(the progression gates, the ability and
race minimums, Bards Table I, Table II and
Table III, the druid cast cap, the poetics
layers, the henchmen ladder, the musical
item bonuses). New R186 battery audit;
census 103. Next: the gap report names the
next round.
R187 landed the per-subclass specials:
rules/subclassspecials.h CREATED (the fee table,
the disguise layer, backstab, the skill sharing,
the monk specials A-K with stun/kill and the
quivering palm, the ranger surprise numbers, the
paladin turn ladder). New R187 battery audit;
census 104. Next: the gap report names the next
round.
R188 landed the prime requisite XP adjustment:
rules/xpadjust.h CREATED (the printed per-class
+10% gates, the worked-example rounding), and the
character.cpp comment now records the verify - the
engine +5/0/-10/-20 rungs are unsourced convention
(the DMG has no prime-requisite ladder at all). New
R188 battery audit; census 105. Next: the gap report
names the next round.
R189 landed the weapon tables verify:
rules/weapontables.h CREATED (the 50-row weight and
damage chart, the speed cross-verify - all 18
readable cells confirm the R158 ladder - and the
printed notes; the R144/R145 AC standing note closes
with the OCR limitation recorded). New R189 battery
audit; census 106. Next: the gap report names the next
round.
R190 landed the starting money by class:
rules/startmoney.h CREATED (the PHB STARTING MONEY
table - cleric 3d6, fighter 5d4, magic-user 2d4,
thief 2d6, all x10 gp; the monk row 5d4 with NO x10,
the DMG MONEY-section ascetic note) and the DMG
companion pin: the PLAYER CHARACTER EXPENSES rule,
not less than 100 gp per level per month
(pcMonthlySupportCost). New R190 battery audit; census
107. Next: the gap report names the next round.
R191 landed the armor class ratings:
rules/armorratings.h CREATED (the printed ARMOR
CLASS TABLE ladder, the shield step, the magic rule
and the printed notes). The verify found ONE
divergence: the engine None armor row read 9 against
the printed 10 - repinned in items/items.cpp (the p.38
worked examples already said unarmored AC 10); the
other nine rows verified cell for cell. New R191
battery audit; census 108. Next: the gap report names
the next round.
R192 landed the wisdom wiring: rules/wisdom.h
CREATED (Wisdom Table I - the magical attack ladder
and the Wis 17/18 high-circle gates; Wisdom Table II -
the cumulative cleric bonus-spell ladder and the
low-wisdom spell failure percent), wired into
spells/spells.cpp: clericSpellSlotsWithWis and
rollClericSpellFailure. The R130 wisdom-not-modeled
engine limit closes. New R192 battery audit; census
109. Next: the gap report names the next round.
R193 landed the charisma repin (PHB divergence 5,
the live one): rules/character.cpp chaReactionAdj,
chaLoyaltyBase and chaHenchmenMax repinned cell for
cell to the printed CHARISMA TABLE - the reaction
and loyalty ladders are now the printed PERCENT
ladders (-25..+35, -30..+40); the d100 reaction
bands read the percents directly; the two divergent
henchmen cells repinned (cha 4 = 1, cha 12 = 5).
New R193 battery audit; census 110. Next: the PHB
divergences 3 (WIS) and 4 (INT).
R194 landed the wisdom defense repin (PHB divergence
3): rules/character.cpp wisMagDefAdj repinned to the
printed Wisdom Table I ladder (-3..+4) by delegating to
the R192 header pin rules::wisMagicalAttackAdj; the
saves.h modifier note repins (mental attack forms
only; the save rolls still do not call it - the caller
assembles). New R194 battery audit; census 111. Next:
the last PHB divergence, 4 (INT languages).
R195 landed the INT languages repin (the LAST
founding-read divergence, 4): rules/character.cpp
intExtraLanguages repinned to the printed
INTELLIGENCE TABLE I column (3-7 none through 18
seven); the engine convention diverged at every
score above 3. New R195 battery audit; census 112.
THE FOUNDING-READ LIST IS EMPTY - all six PHB
ability tables print-pinned (STR R153, DEX R178c,
CON R178c, INT R195, WIS R194, CHA R193). Next:
the gap report names the next round.
R196 landed the INT Table II repin (a NEW seam
find, post-founding-read): spells.cpp
chanceToLearnPct diverged from the print at 10,
16, 17 and 18 - repinned (9 35, 10-12 45, 13-14
55, 15-16 65, 17 75, 18 85, 19+ 95); the live
spell-learning rolls now read the printed
percents. The two unmodeled columns pin as new
accessors: minSpellsPerLevel / maxSpellsPerLevel
(4/6 through 10/All; All = -1). New R196 battery
audit; census 113. Next: the gap report names
the next round.
R197 landed the per-spell mental-form flag (the R194
seam): spells::spellIsMentalForm flags the registry two
will-force forms (charm person - charming; charm
monster - mass charming); spellSaveModWis assembles the
WIS magical defense adjustment via wisMagicalAttackAdj on
those, 0 on everything else. JUDGMENT: the holds are NOT
will-force forms - the PHB Serten spell immunity print
groups hold with command, domination, fear and scare, apart
from beguiling/charm/suggestion. Fear, hypnosis,
suggestion, the phantasmal forces ride the flag when their
registry rows arrive. New R197 battery audit; census 114.
Next: the gap report names the next round.
R198 landed the class weapon allowlists - the CHARACTER
CLASSES TABLE II weapons column, the monk list home:
rules/weapontables.h pins classUsesAnyWeapon (fighter,
paladin, ranger, assassin), the limited lists (cleric 7
chart rows, druid 9, MU/illusionist 3, thief 8, monk 24)
and weaponAllowedForClass. JUDGMENTs: the family words
expand to chart variants (flail/mace = footman + horseman,
staff = quarterstaff, sling = bullet + stone, hammer =
the plain hammer, NOT the lucern); thief sword = short/
broad/long per the printed footnote, never bastard or
two-handed; monk pole arm = the chart 15 pole-arm rows
(pikes and picks out); crossbow pins by name for the monk
alone (the chart prints only its quarrels). New R198
battery audit; census 115. Next: the two allowance
columns right of the weapons column.
R199 landed the oil and poison columns of the CHARACTER
CLASSES TABLE II - the table is now complete in the
engine. The three-valued allowance encoding (1 yes, 0
never, -1 referee discretion): classOilUse - yes for
every class but the monk (the prose: not even flaming
oil is usable by them); classPoisonUse - cleric never,
paladin never, assassin yes, the rest the question mark;
the evil-cleric footnote as its own modifier,
classPoisonUseForAlignment - the prohibition is strictly
for clerics NOT of evil alignment; the paladin never is
unconditional. New R199 battery audit; census 116. Next:
the seam reports name the monk falling rows.
R200 landed the monk falling-while-climbing ladder (the
print rows under the thief-ability paragraph): 4th
(Disciple) fall up to 20 feet within 1 of a wall, 6th
(Master) 30 within 4, 13th (Master of Winter) any
distance within 8, with the wall-contact rule (damage-
free only when periodic contact is possible; tree trunk,
cliff face serve). rules/subclassspecials.h:
monkWallAssistedFallFeet (0/20/30/-1-any), the proximity
column (0/1/4/8), the contact rule. New R200 battery
audit; census 117. Next: the NPC monk alignment split.
R201 landed the NPC monk alignment split (the monk prose
pin: NPC monks align 50% lawful good, 35% lawful
neutral, 15% lawful evil): rules/subclassspecials.h -
the three percent accessors plus monkNpcAlignRollRange
(the cumulative d100 bands: LG 1-50, LN 51-85, LE
86-100; out-of-range index the 0-100 miss band). The PC
side stays gated by SUB_ALIGN_LAWFUL_ONLY. New R201
battery audit; census 118. THE MONK PROSE SEAM IS FULLY
MINED - surprise ladder, stun/kill, quivering palm,
save advantages, falling ladder, NPC alignment split.
Next: the DMG-only tables still unpinned.

R203 landed the apparent-armor-AC repin - the p.38
weapon-vs-armor column keys the armor the defender
wears, not the magic/DEX-shifted effective AC (the DMG
p.38 note: the adjustments are "for weapons versus
specific types of armor, not necessarily against
actual armor class"). items::apparentArmorAc(armor,
shield) - armor base + shield one better, the plus and
DEX do not shift it - is the new p.38 row key;
weaponAcAdjustment/attackAdjustment read defenderArmorAc;
the two ai/actor.cpp callers pass apparentArmorAc. The
to-hit target still reads the full effective AC; the
monster approximation (rows applied to every defender)
stays named. Closes the R144/R145 named approximation.
New R203 battery audit; census 119. Next: the DMG-only
tables still unpinned.

R204 landed the item saving throw matrix (DMG p.80,
matrix III, magical and non-magical items) - the
DMG-only sweep seam grenade.h named and deferred:
rules/itemsavethrow.h (the grenade.h pattern), the
14 material rows x 11 attack forms cell for cell,
the ceramic 18/12 and crystal 19/14 BLOW cells
independently confirmed by the R157 break-save pins.
The printed modifiers ride it: the magical ladder
(+2 and +1 per plus above +1), the own-mode +5, the
fall surfaces (hard 0, wood-like +1, fleshy +5)
with the per-5-feet distance penalty, the hard-metal
cold-strike -10 footnote, the normal-fire exposure
rounds (parchment 1, cloth 2, bone 3). The save:
d20 + adj >= cell. New R204 battery audit; census
120. Next: the DMG-only sweep continues.

R205 landed the spying tables (DMG pp.19-20,
the SPYING section after the assassin guild
tables) - the lane rules/assassinate.h
named and deferred in R164. rules/spying.h
(the grenade.h pattern): the ASSASSIN SPYING
TABLE (spy level 1-17 x simple/difficult/
extraordinary, all 51 cells), the mission
days (1-8 / 5-40 / as required), the chance
of discovery (cumulative 1 percent per day
capped at 10, minus the spy level, floor 1
percent) with the four precaution tiers
(none flat 1 percent per week; minimal the
modified percent per week; moderate twice
per week; strong doubled twice per week; a
leading spy reads none) and the tenfold
20-50-day post-capture window; the SPY
FAILURE TABLE (the five bands, doubling as
the discovery table) with the modifiers
(difficult +10, extraordinary -5,
discovered +25); the torture outcomes (1-2
dead, 3-4 revealed, 5-6 turncoat); the
fanatical rule (never a double agent, over
60 suicide); the hired-spy 8th-level cap.
New R205 battery audit; census 121. Next:
the DMG-only sweep continues.

R206 landed pursuit and evasion of pursuit
(DMG pp.67-69) - a seam with no prior
coverage in any rules/ file and no mention
in either gap report. rules/pursuit.h
(the grenade.h pattern): underground,
the pursuit likelihood ladder (semi-
intelligent motivated 80 percent; low
intelligence 20/40/80 by numbers, 100
when the outnumbering pursuers feel
greatly superior), the three end-
condition cases by relative speed
(100/50 feet/5 rounds; 150/80 feet/1
turn; 200 feet/no cap), the food and
treasure distractions with their d10
arithmetic, the multiple-choice rule and
the detection radii (corner 60 feet;
metal 90, boots 60, quiet 30), the
movement procedure (3 phases = 1 round,
contact at 10 feet); outdoor, the BASE
CHANCE OF EVADING PURSUIT table - base
80 percent with the speed, terrain,
size and light rows cell for cell -
the surprise rule (surprised them:
automatic; surprised: impossible) and
the hourly recheck (0 or less:
immediate confrontation). New R206
battery audit; census 122. Next: the
DMG-only sweep continues.

R207 landed the town taxation system (DMG
p.90, DUTIES, EXCISES, FEES, TARIFFS,
TAXES, TITHES, AND TOLLS) - the print
worked example town, a seam with zero
prior coverage. rules/taxation.h (the
grenade.h pattern): the seven named tax
kinds defined in place; the import duty
(1 percent, doubled for foreigners),
the 5 percent luxury tariff, the entry
fee (1 copper a citizen, 5 a
non-citizen, per head or wheel), the
annual head tax (1 copper a peasant, 1
silver a freeman, 1 gold a gentleman or
noble), the 10 percent foreigner sales
tax (no service tax on them), the tithe
pledge, the 5 percent annual property
tax, citizenship (one month plus 10
gold), foreign currency (the 5 percent
merchant fine, the 90 percent exchange -
10 foreign coppers bring 9 domestic -
the 100-noble limit with the 50 percent
fine and the 24-hour changer grace, the
10 percent gem surtax), and toll
evasion (confiscation, fine and
imprisonment possible). New R207 battery
audit; census 123. Next: the DMG-only
sweep continues.

R208 landed the social class and rank
system (DMG pp.88-89) - the 19
government forms with their defining
traits, the worked example aristocracy
(the service, land and income-tax rule
with the 20 gold piece merchant land
waiver; the senators, the tribunals and
the senatorial police appointments), the
town and city social structure (the
upper, middle and lower classes and what
each draws), the municipal offices (the
lifetime mayor, the aldermen chosen by
the upper and elected by the middle
class, the strata of judiciary, military
command, law, customs and tax officials,
the common council and the petty
officials, the constabulary), the
non-hereditary knights with
order-varying precedence, the northern
European title ladder (emperor down to
knight, 10, duke preceding prince per
the print table) with the German
equivalents and the 20 Asian titles. New
R208 battery audit; census 124. Next:
the DMG-only sweep continues.

R209 landed the NPC personae facts
tables (DMG pp.114-115, PERSONAE OF
NON-PLAYER CHARACTERS) - a seam with
zero prior coverage. rules/npcpersonae.h
(the grenade.h pattern): the classed NPC
ability dice adjustments (cleric wisdom
+2; the as-fighter ranger and paladin
rows; magic-user, thief; the as-thief
assassin adding strength +1; the druid
12/14, ranger 12, paladin 17,
illusionist 15/15 and monk 12/15/15
minimums; the ability-limit clamp), the
three occupations (laborer strength +1
to +3, the level-0 mercenary with
strength +1, constitution +3 and 4
minimum hit points, the merchant 12/12
intelligence/charisma minimums), the DMG
demi-human adjustment table (dwarf, elf,
gnome, halfling - its own table, not the
PHB one), and the FACTS TABLES: alignment
d10, possessions d10, appearance age and
general d10s, sanity d10 with the
insane/maniacal asterisk reroll rule,
plus the p.11 die rules (general
characters read any 1 as a 3 and any 6
as a 4; special characters +1 per die
under 6) and the three-tendency floor.
The compilation annotations not in the
print (wealth multipliers, sanity
reaction percents) excluded. New R209
battery audit; census 125. Next: the
DMG-only sweep continues - the personae
traits tables.

R210 landed the NPC personae traits
tables (DMG pp.115-116, TRAITS TABLES) -
a seam with zero prior coverage.
rules/npctraits.h (the grenade.h pattern):
the 24 General Tendencies (the d12 with the
d6 half split: 1-3 the first twelve, 4-6 the
second), the three-column Personality (d8
d8 - average 1-5, extroverted 6-7,
introverted 8, with the shared words as
per-column codes), the 24 Interests (the d6
halves, the four collector rows 17-20),
Disposition, Intellect (the dreaming-through-
brilliant rating modifiers), Collections,
Nature, Materialism, Honesty, Bravery,
Energy, Thrift, Morals (the perverted/sadistic/
depraved asterisk reroll rule - the same
shape as the R209 sanity rule) and Piety -
plus the print encounter/offer reaction
adjustment percents (neurotic the print
asymmetry: minus 1 to plus 6; insane 1-10;
maniacal 1-20; disposition 1-6; nature 1-4;
tendencies 1-8; bravery 1-20; personality
1-8; materialism 1-20). The compilation
annotation columns (per-word percents) not
in the print, excluded. New R210 battery
audit; census 126. Next: the DMG-only sweep
continues - the personae height and weight
tables, the language determination.

R211 landed the NPC height and weight
tables and the language determination
(DMG pp.115-116, the personae chapter
tail) - a seam with zero prior coverage.
rules/npcbody.h (the grenade.h pattern):
the MALES and FEMALES height/weight
tables (7 races: the averages, the under
and over dice - the print range cells
2-16 = 2d8, 4-40 = 4d10, 5-60 = 5d12,
packed count*100+sides), the HEIGHT AND
WEIGHT DETERMINATION percent bands (per
race, both sexes: under/average/over
edges for height and weight), and the
RANDOM LANGUAGE DETERMINATION TABLE -
100 faces, 55 kinds: brownie through
xorn, the ten dragon faces, the eight
giant faces (hill on 31-33), the three
naga faces, 86-00 human foreign or other.
GROUND TRUTH NOTE: the live compilation
editorializes this seam (a Human NPC/PC
row split with d20x10 entries citing
OSRIC; half-orc male over-weight read as
d20, human male over-weight as 5d6) - the
book upload carries the print ranges and
one human row, and is pinned (the
R209/R210 exclusion rule). New R211
battery audit; census 127. Next: the
DMG-only sweep continues - the special
roles of the DM, hiring NPCs to cast
spells, monsters and organization.

R212 landed the NPC hire spell prices
and the non-human troop control table
(DMG pp.116-118) - a seam with zero
prior coverage. rules/hirecost.h (the
grenade.h pattern): the 40 cleric spell
hire prices (the 18-row first table
astral spell through earthquake plus
the 22-row second table exorcise
through true seeing - the upload OCR
split names and costs into two lists;
they pair by order, 22 and 22), each
as base gold plus rate times a unit-
selected quantity (flat, per person,
per caster level, per recipient level,
per person per caster level, per point
of healing, base plus per question,
base plus per caster level, base plus
per recipient level - the restoration
like-amount clause reads base 10000
plus 1000 per recipient level); the
travel x2 not-at-risk and x5-or-refuse
at-risk factors, the 25% charm-opposite
rule, the deliberate attack-spell and
no-accompanying omissions, the
interruption clause; and the USE OF
NON-HUMAN TROOPS table (7 races x 3
columns: no officers and weak leader,
no officers and strong leader, officers
and strong leader), the 25% friendly-
humans fight chance, the weak-leader-
plus-officers impossibility, the high-
pay-is-weakness clause, and the demi-
human master rule. New R212 battery
audit; census 128. Next: the DMG-only
sweep continues - construction, siege
and the underworld.

Categories:
- [x] = verified against the book text
- [~] = verified DIVERGENT: the repo's rule
       differs from the book, and a fix round
       is the candidate (ranked below)
- [ ] = open item (worth having; a round should
       close it)
- OUT = out of scope by design (the repo is a
       tile-based dungeon crawler, not a war
       game or domain simulator)

## Verified exact (the book receipts)

- [x] **Start ages (p.12)** - R97's values are
      EXACT: cleric 18+1d4, fighter 15+1d4,
      magic-user 24+2d8, thief 18+1d4.
- [x] **Turn clock (p.38)** - "ten one-minute
      rounds to the turn, and six turns to the
      hour" - R95's 144-turn day derives
      correctly (6x24).
- [x] **Crew share (p.35)** - "the crewmen
      share between them 5%" - the repo's
      delveGold/20 is EXACT.
- [x] **The gift (p.37)** - "given a choice
      gift or bonus ... +5%" - R103's
      loyaltyGift()=5 is an exact match.
- [x] **Morale base 50% (p.37)** - "Base
      unmodified morale score is 50%".
- [x] **Henchmen come unequipped (p.37)** -
      "no armor or weapons, nothing!".
- [x] **Appendix C, Monster Level I (p.175)** -
      re-verified line for line against
      dm/encounters.cpp kLevel1, including both
      footnoted substitutions (Badger becomes
      Hobgoblin at 29-33; Halfling becomes Giant
      Rat at 27-28 and 71-83). EXACT.
- [x] **XP table (p.85)** - monsters/
      MonsterXp.cpp matches the printed tier
      lists (the repo's array index starts one
      tier below the book's first bracket,
      consistently), and the additive formula
      reproduces the book's owlbear worked
      example (405). R59's alignment holds.
- [x] **Monster saves use character matrices
      (p.79-80, matrix II)** - the book's rule
      that all monsters save as characters, with
      HD equating to level and +hp stepping by
      4, is the repo's approach; R110 aligned
      the character matrices and added the
      book's own HD-to-level stepping
      (monsterSaveLevel).

## Verified DIVERGENT (fix-round candidates, ranked)

- [x] 1. **Turning undead (p.75-76, matrix III;
      procedure p.77)** - CLOSED R109 (the fix-up
      R109b landed the battery audit and this box
      flip in the same commit). The repo now
      carries the book's table cell for cell:
      13 undead rows in the book's own order (the
      OCR's row-6 "Ghost" was GHAST; slot 11 is
      the true Ghost), columns cleric level
      1-8 / 9-13 / 14+, d20 match-or-exceed,
      T / D / D* / dash, counts 1-12 (7-12
      starred, 1-2 Special), paladins two levels
      below. Pinned by the R109 battery audit.
- [x] 2. **Saving throws (p.79-80, matrix I)** -
      CLOSED R110. The repo now carries the
      book's BANDED matrices per class
      (fighter 0/1-2/.../17+ incl. the 0-level
      row; cleric 1-3/.../19+; MU 1-5/.../21+;
      thief 1-4/.../21+), replacing the
      per-level linear rows. The headline fix:
      the cleric level-1 death save is now the
      book's 10 (was 14). Also landed: the
      book's rule that a natural 1 is ALWAYS
      failure, and the monster matrix II rule -
      HD equates to level with +hp stepping by
      4 (monsterSaveLevel). Pinned by the R110
      battery audit.
- [x] 3. **Fighter attack matrix (p.75 I.B)** -
      CLOSED R111. The repo now carries the
      book's own banded table: level bands
      0, 1-2, 3-4, 5-6, 7-8, 9-10, 11-12,
      13-14, 15-16, 17+ vs AC 10 down to
      AC -10, transcribed cell for cell with
      the book's negative targets intact (the
      17+ band hits AC 10 on any roll; the
      0-level human needs 11). The per-level
      approximation and its floor-2 clamp are
      gone. The book's optional 5%-per-level
      variant is not adopted. Pinned by the
      R111 battery audit.
- [x] 4. **Class attack matrices (p.75 I.A,
      I.C, I.D)** - CLOSED R113. The repo now
      carries the book's own tables for
      clerics (I.A, 7 level bands), magic-
      users (I.C, 5 bands) and thieves
      (I.D, 6 bands), each 21 AC rows
      transcribed cell for cell; fighters
      keep matrix I.B (R111). The
      effectiveAttackLevel row-shift
      approximation is gone: a book MU
      level 1 needs 11 to hit AC 10 (the
      shifts asked 10). The book's thief
      superscripts are backstab damage
      multipliers, not attack numbers.
      The book's missile note (-5 long,
      -2 medium) is still an open item.
      Pinned by the R113 battery audit.
- [x] 5. **Monster attack matrix (p.75-76
      II)** - CLOSED R112. The repo now carries
      the book's own HD-banded monster table:
      12 hit-dice bands (up to 1-1 through
      16+) vs AC 10 down to AC -10, transcribed
      cell for cell (monsters do NOT attack as
      fighters; a 16+ HD monster hits AC 10 on
      any roll, target -3). The repo's float HD
      cannot split the book's 1-1 vs 1 columns
      (both store 1.0; goblin, the battery's
      1.0 monster, is book 1-1 - documented
      interpretation). Monster saves also now
      step by monsterSaveLevel (matrix II.B,
      from R110). Pinned by the R112 battery
      audit.
- [x] 6. **Aging (p.13-14)** - CLOSED R114.
      The book's five human brackets (young
      adult 14-20, mature 21-40, middle aged
      41-60, old 61-90, venerable 91+) with
      its per-bracket cumulative adjustments
      (p.14) replace R98's symmetric bend.
      Humans only (no race field; documented),
      young adult is the as-rolled baseline,
      WIS clipped at 18 (documented). Magical
      aging causes are an open item below
      (haste wired R115).

## Simplified or accepted by design

- [x] **Henchman offer (p.35)** - the repo's
      flat 100 gp hire fee is the book's floor
      for a 1st-level hire; accepted.
- [x] **Crew hired at morale 60** - a house
      value (willing signers) above the book's
      base 50; accepted.
- [x] **Spy cost, loyalty situation tables,
      gift cooldown** - condensed forms of the
      book's material; accepted.
- [x] **Treasure determination (pp.120-125)** -
      dm/treasure.cpp implements the map/
      monetary/magic structure, and the battery
      pins 20k-roll behavior; the line-by-line
      table diff was done R122 - no divergence
      (the item below is closed).

## Open gaps (worth a round)

- [x] **Magic-weapon-to-hit gate (p.76)** -
      VERIFIED R115: already implemented -
      monsters' requiredPlus comes from the
      Lua specials text (MonsterRegistry),
      and rules::weaponSufficient gates both
      the melee and missile paths
      (ai/actor.cpp; the quiver's ammo
      enchant counts toward it, R80).
      Attacking monsters are always
      sufficient: the book's attacker HD
      column (+1 at HD 4+1...) governs
      monsters hitting gated creatures,
      which this repo's encounters (monsters
      vs characters) never do - documented.
      Pinned by the R115 battery audit.
- [x] **Magical aging causes, remainder
      (p.14)** - CLOSED R129: the six
      caster-aged causes enter the spell
      registry - Limited Wish (MU7, ages the
      caster 1), Alter Reality (MU7, 3),
      Wish (MU9, 3), Gate (MU9, 5),
      Restoration (CL7, 2), Resurrection
      (CL7, 3) - appended ids so saved
      knownSpells indices stay valid. Their
      rows are TARGET_SELF: the R115 aging
      rider ages the rider's target, which
      for these spells IS the caster (the
      book's semantics; the years land at
      the fight-end sync, persisted as
      "mageage"). The rows are "known, cast
      pending" (the R80 utility convention):
      the slot tables encode levels 1-6, so
      spellSlots yields 0 for 7-9 until the
      high-level (name level+) tables arrive
      in a future round - documented; the
      p.14 pins ride magicalAgingYears
      regardless. Two documented engine
      limits remain, named for the record:
      the speed potion's 1 year (found
      potions collapse into the healing
      stack - no identity survives pickup)
      and the hire's stolen years (no hire
      brackets exist). Pinned by the R129
      battery audit; census 47.
- [x] **Encounter reactions (p.64)** -
      CLOSED R117: the book's percentile
      table (seven bands, 01-05 violently
      hostile through 96-00
      enthusiastically friendly) replaces
      R8's 2d6 stand-in, which carried a
      verification-debt NOTE. d100 +
      chaReactionAdj (the hireling reaction
      adjustment - the book's "as if the
      creature were a henchman" charisma
      machinery); the loyalty adjustment
      applies only where a loyalty score
      exists, which an encountered
      creature has none (documented -
      a caller with a real score
      pre-adjusts). The starred bands read
      "or morale check if appropriate" -
      the caller's call, noted in the
      enum. Pinned by the R117 battery
      audit (all 13 band edges, both
      clamps, enum order, 200-roll smoke).
      No callers yet - the parley hook is
      a future round (dead code until
      then, but the book's own shape).
- [x] **Listening at doors (p.60)** -
      CLOSED R118: the book's table is
      racial d20 chances - dwarf 2, elf 3,
      gnome 4, half-elf 2, halfling 3,
      half-orc 3, human 2 in 20 (all seven
      pinned) - replacing R11's d6-band
      approximation. No race field, so
      callers use the human band
      (documented, R114 convention). The
      keen-eared bonus (1 or 2 in 20) is
      per-character state the repo does
      not track - the caller passes it
      (the DM notes it on the first
      listen, per the book). Thieves ride
      their hear-noise skill as pct/5
      in-20 bands (documented derivation;
      the PHB table's verification-debt
      NOTE rides). Silent creatures,
      sleeping/resting/alerted creatures:
      the caller's gate (the book's own
      rule). No callers yet - a door-
      listening hook is a future round.
      Pinned by the R118 battery audit;
      abilities.cpp now in the battery
      build (it was compiled by nothing
      on Termux before).
- [x] **Forced rest (p.38)** - CLOSED
      R119: the book requires rest at
      least one turn in six, plus a turn
      after every combat or other
      strenuous activity. Pure helpers
      (forcedRestDue: five active turns,
      the sixth owed; strenuousRestTurns:
      one) pin-able by the battery;
      tickActivity counts every active
      turn (movement ticks and the [F]
      search); endCombat owes the turn
      for a living company; when rest is
      due the explore gate closes (too
      winded to press on) until a
      COMPLETED rest pays it - the camp
      [R] or the inn (interrupted camps
      restore nothing, fatigue included;
      the slots precedent). A fresh
      delve starts fresh-legged. Pinned
      by the R119 battery audit.
- [x] **Crew officers (p.35)** - CLOSED R121:
      for every 20 crewmen the book requires
      1 lieutenant and 2 mates; the coaster's
      company (R46, which admitted its
      simplification) now ships a captain,
      a lieutenant and two mates. Wages:
      masters/captains/lieutenants 100 gp per
      level per month (L1 hires - documented
      simplification; the book prices by
      level), mates are serjeants at 30 gp
      (p.34) - 40 gp becomes 300 gp per
      return. Shares: the captain 25%, the
      lieutenant 5%, the mates 1% each, the
      crew 5% among themselves (37% total;
      the PC keeps 63%). No new save fields -
      the officers ride the crewHired flag.
      Pinned by the R121 battery audit.
- [x] **Missile range modifiers (p.75)** -
      CLOSED R116: rules::missileRangeMod (-5
      long, -2 medium, the book's own note)
      rides the engagement distance in
      resolveMissile - fired missile weapons
      only. Medium is 2x and long 3x the
      registry's short range (documented
      derivation - the M/L columns are not in
      the registry); hurled weapons are
      exempt (no thrown ranges in the
      registry - documented); the monsters'
      volley is the 50' short convention
      (R37, mod 0). Beyond long range no
      shot is possible (nothing spent).
      Under R43's 50' engagement geometry the
      long band is unreachable in play (it
      activates if the geometry ever opens);
      the sling's opening volley is medium,
      -2. Pinned by the R116 battery audit.
- [x] **Treasure line-diff (pp.120-125)** -
      VERIFIED R122: every implemented table
      diffed line-by-line against the book -
      383 rows across III.A/C-H plus the
      Special artifact table (35+24+30+33+30+
      33+36+35+29+26+26+36), dice bands, xp
      and gp values, bundle quantities: no
      divergence. The repo's name corrections
      are the treasure.h print-errata list.
      The III dispatch bands, the Map table
      and the scroll structure (16 spell
      bands, 8 protection scrolls, the 5x/3x
      sale rules) verified with it. The book's
      II.A/II.B/II.C hoard-construction
      tables are DM tools the repo replaces
      with MM Treasure Types (p.105, R71) -
      documented, not a divergence. Pinned by
      the R122 battery audit.
- [x] **Outdoor movement (p.58-59)** - CLOSED
      R123: the book's daily rates wired -
      the afoot table (light/average/heavy
      burden x normal/rugged/very-rugged
      terrain: 30/20/10, 20/10/5, 10/5/2
      miles/day) with the burden classes
      from the true loads (<=25 / 26-60 /
      61-90 lbs of gear; the strength/race
      adjustment lives in the dungeon bands,
      PHB p.76 - documented), the terrain
      classes mapped to the 8 routes
      (plains/scrub/desert normal,
      forest/rough/hills rugged,
      mountains/marsh very rugged), and the
      company pace = the slowest walker
      (hire included, the fallen skipped);
      each march day logs its true miles and
      tracks milesOut. The coaster sails
      the book's small-merchant sea rate
      (50 miles/day - the 50-60 band is
      the lake column; the roll stays
      generic lo..hi). The mounted
      table (60/25/5, 40/20/5, 30/15/5,
      draft 30/15/5, cart 25/15 and wagon
      25/10 road-only) and both afloat
      tables (oared and sailed, 8 vessels x
      5 waters) are pinned as data - no
      mounts or other vessels are in play
      yet. The d4 long-voyage reduction is
      a weeks-scale rule this day cadence
      does not model - documented. Pinned
      by the R123 battery audit.
- [x] **Appendix A dungeon dressing details
      (pp.169-172)** - CLOSED R124: all tables
      pinned row-by-row in the new
      dm/appendixa.h (Tables I-VIII.C:
      periodic check, doors, side passages,
      passage width, special passages with
      the stream/river/chasm bridge-boat-
      jumping chances, turns, chamber/room
      shape and size, unusual shape and
      size, exits count/location/direction,
      room contents + the stairway variant
      (the book's print skips band 6 - 1-5,
      7-8 - pinned as printed, documented),
      treasure by level, containers,
      guarded-by, hidden-by, stairs with
      their egress doors, trick/trap, gas,
      caves, pools, lakes, magic pools and
      their sub-tables). The walk's four
      helpers (passage width, passage
      features, room size, room contents)
      are rewired to the exact tables -
      R8's stand-in shapes and their
      verification-debt notes are gone
      (rooms use Table V's room column -
      the blank 18-20 rows re-roll; the
      chamber column and all unrendered
      tables are pinned data for the future
      layers). Pinned by the R124 battery
      audit; census 42.
- [x] **Traps and dressing lists (pp.216-217)**
      - CLOSED R125: Appendix G's trap list (the d% TRAP
      LIST, 46 kinds - band weights checked against a scan
      of the printed page) is pinned row-by-row in the new
      dm/appendixgh.h, and the R45 dart-trap set now rolls
      its NAME from the table at arming: spring/disarm/
      sprung-room lines quote the book name verbatim (the
      book lists names only, so the R45 save-or-2d6 set
      stays the effect). Appendix H's dressing lists (37
      features, 65 attributes) are pinned as data for the
      future special-rooms layer (trickSummary helper).
      Pinned by the R125 battery audit; census 43. NOTE:
      name spellings and the H lists are transcribed from
      the 1eonline.info compilation of the pages and ride
      the book-verify debt with the printed table as the
      winner.
- [x] **Wilderness encounter tables
      (pp.182-189)** - CLOSED R126: the R63 climate
      matrices (Arctic, Sub-Arctic, Temperate Wild,
      Temperate Inhabited, Faerie, Pleistocene, Age of
      Dinosaurs, Tropical) and the eleven terrain-column
      subtables (plus the tropical single-column Sphinx
      footnote) are line-diffed against the 1eonline.info
      Appendix C compilation: the five climates it carries
      match band-for-band modulo the documented OCR folds,
      and the two undocumented printed-gap resolutions
      (temperate wild scrub Humanoid 36-32 -> 26-32,
      tropical rough giant scorpion 84-84 -> 84-85) are now
      documented in-row. The compilation omits the Faerie,
      Pleistocene and Age of Dinosaurs tables - those three
      ride the book-verify debt with the printed table as
      the winner, as do the printing-variant readings
      (tropical mountains dervish 29-30; marsh Men
      nomad/tribesman). Pinned by the R126 battery audit;
      census 44.
- [x] **Waterborne/aerial encounter tables
      (p.190)** - CLOSED R127: the four p.190 waterborne
      tables (fresh water small/large body, salt water
      shallow/coastal and deep) are pinned row-by-row,
      line-diffed against the 1eonline.info Appendix C
      compilation, and wired into the sea travel loop
      (R70 had rolled the R60 underwater set; the coaster
      now rolls surface encounters - buccaneers,
      merchants, pirates, mermaids, whales - and the
      underwater set stays pinned data for the future
      diving layer). Dinosaur rows resolve on the shared
      p.190 Dinosaur Subtable; the fresh-water warm gate
      rides the parent row per the R60 convention.
      Aerial: the DMG prints no separate aerial table -
      airborne play resolves on the wilderness tables'
      airborne rows (the ^75^ markers, pinned R63/R126),
      documented. Substitutions pinned in-row (pirate ->
      buccaneer, tribesman small craft -> caveman,
      mermaid -> merman). Pinned by the R127 battery
      audit; census 45.
- [x] **Special rooms (Appendix H tricks,
      pp.216-217)** - CLOSED R128: the R125-pinned dressing
      lists are wired: an unoccupied, untrapped room has a
      20% chance (the design figure - the book's H lists
      are selection lists, not frequency tables, so no
      printed weights exist; the odds ride the design debt)
      to hold a curiosity - a uniform feature (of 37) +
      attribute (of 65) rolled at populate, announced on
      first entry via trickSummary ("Something odd commands
      the room: Fountain (Talks singing)."). A room is a
      snare OR a curiosity, never both (documented). The
      first-effects slice pays out once (trickDone):
      releases coins (2d6 x 10 x level, the delve take),
      releases gems (1d3 at the DMG gem appraisal),
      releases magic item (the R44 unidentified-pickup
      shape), and shoots / poison strike a random living
      member with the trap shape (save vs death/poison or
      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box), R135's five
      geometry (the R135 box), R136's five
      odds-and-ends (the R136 box). The other 36
      attributes stay dressing - documented; their
      effects ride future rounds.
      Transient like trapKind: rooms re-populate on load.
      Pinned by the R128 battery audit; census 46.
- [x] **High-level spell slot tables (PHB
      class tables)** - CLOSED R130: the slot tables
      themselves were the last print-omission in the
      spell pipeline - line-diffed against the
      1eonline.info PHB compilation (class Table I +
      the SPELLS USABLE appendix): 9 spell levels
      encoded, MU printed rows to L20, cleric to L29,
      final row holds beyond the print; the R80
      project-notes rows 7-12 corrected to print; the
      cleric 7th gate lands at 17 (the printed Wis-18
      footnote at 16 not modeled - engine limit); the
      INT gate extends 17 -> 7th, 18 -> 8th/9th (the
      "highest intelligence" note - a convention
      extension riding the standing verification
      debt). The tables and gates now encode levels
      7-9 (the R129 caster-aging spells resolve at
      name level); the per-day slotsByLevel plumbing
      still tracks 6 - named debt, rides future
      rounds. Pinned by the R130 battery audit;
      census 48.
- [x] **Per-day slot plumbing 6 -> 9 (the R130
      named debt)** - CLOSED R131: both
      slotsByLevel arrays (Character and the
      combat Actor) widened to nine, and every
      loop that touches them widened with them:
      the creation-time pool, restoreSlots (the
      load-time rebuild - slots are not saved,
      so the widen is v1-save-compatible), the
      level-up rest-like refill, the encounter
      spawn fill, the post-combat spent-slot
      copy-back, toActor's pool carry, and the
      foe cleric cast gate. Levels 7-9 are now
      castable in play at name level (the R129
      caster-aging spells resolve end to end).
      The wisdom footnotes stay engine limits;
      the printed tables still ride the
      verification debt. Pinned by the R131
      battery audit; census 49.
- [x] **Appendix H second-effects slice (the R128
      dressing debt, first six)** - CLOSED R132: the
      mechanical set grows 5 -> 11. Ages: 10 years on
      a random living member (the print's altar
      example, via the R115 magical-aging shape).
      Flesh to stone: save vs petrification or turned
      to stone (the print's face example - save
      versus magic or be transformed). Electrical
      shock, metallic or magical: 5-50 hp on a
      random living member, no save (the print's
      pedestal example prints none). Releases
      counterfeit: a shower of coins that crumbles
      worthless - nothing gained. Takes/steals:
      10-60 gp from the purse (the print gives no
      figure - a rebuild convention, documented).
      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box), R135's
      five geometry (the R135 box). The
      remaining 41 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
- [x] **Appendix H third-effects slice (the R128
      dressing debt, second five)** - CLOSED R133: the
      mechanical set grows 11 -> 16. Attacks:
      the animated feature strikes a random living
      member for 1d8, no save. Fruit: a random
      living member eats and heals 2d4+2 (the
      potion shape, capped at max hp). Greed: a
      scramble costs 10% of the purse. Teleports:
      the company blinks to a random room center
      on this level (the print's intra-level AREA
      example). Collapsing: the ceiling comes down
      - every living member saves vs death/poison
      or takes 2d6. All five are rebuild
      conventions (the print gives no figures);
      documented. The R134 slice wires the three deep
      waters (the R134 box), R135's five geometry
      (the R135 box), R136's five odds-and-ends
      (the R136 box). The remaining 36
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
- [x] **Appendix H deep-effects slice (the deep
      waters)** - CLOSED R134: the mechanical set
      grows 16 -> 19. Wish: a boon table roll - the
      whole company healed, or a random living member
      restored, or a gold shower (1d6 x 100 gp).
      Gravity greater: the pull doubles - every living
      member takes 1d6 crushing, no save. Polymorph:
      a random living member saves vs
      petrification/polymorph or takes 3d4 reshaping
      damage. All three are rebuild conventions (the
      print gives no figures); documented. The
      remaining 46 attributes stay dressing; their
      effects ride future rounds. Pinned by the R134
      battery audit; census 52.
- [x] **Appendix H room-geometry slice (the
      positional five)** - CLOSED R135: the mechanical
      set grows 19 -> 24. One-way: the way back seals
      - the company is committed to the room's center.
      Pivots: the room turns a quarter - the company's
      position rotates 90 degrees about the room
      center, clamped inside. Spinning: a full
      half-turn - the position rotates 180 degrees.
      Shifting: the walls flex - the position mirrors
      across the room's center line. Sliding: the floor
      tilts - the company is shoved to a random room
      edge. All five are positional conventions (the
      print gives no mechanics); documented. The
      remaining 41 attributes stay dressing; their
      effects ride future rounds. Pinned by the R135
      battery audit; census 53.
- [x] **Appendix H odds-and-ends slice (the
      stragglers)** - CLOSED R136: the mechanical set
      grows 24 -> 29. Rising: water floods the room -
      every living member saves vs death/poison or
      takes 1d6. Suspends: gravity nil - the company
      floats and drifts to a random interior tile.
      Appearing: the feature manifests, startles, and
      melts away - the room's trick is spent.
      Invisible: an unseen strike - 1d6 on a random
      living member, no save. Gaseous: a poison cloud -
      every living member saves vs death/poison or
      takes 1d6. Anti-magic STAYS dressing (an honest
      suppression zone needs a magic-use hook the
      engine does not expose yet); documented. All five
      wired effects are rebuild conventions (the
      print gives no figures). The remaining 36
      attributes stay dressing; their effects ride
      future rounds. Pinned by the R136 battery audit;
      census 54.
- [x] **Deliberate-engage hook (the standing debt)** -
      CLOSED R137: the special-rooms layer no longer
      springs a mechanical curiosity on first sight -
      describeRoom announces the feature and prompts;
      the company chooses. The X key (dungeon mode)
      calls engageTrick: inside a trick room with an
      unfired mechanical feature it fires (trickDone
      set, applyTrick); elsewhere it logs guidance.
      The prompt phrase is pure data
      (trickEngagePrompt, dm/appendixgh.h) and the
      battery pins it exact. Pinned by the R137 hook
      audit; census 55.
- [x] **Talk-flavor parley hook (the standing debt)** -
      CLOSED R138: the talks-class Appendix H
      attributes (asks, directs, points, suggests,
      intelligent, and the six talks variants) stay
      non-mechanical by design - they answer the
      deliberate-engage hook instead. The X key in a
      talky trick room logs the attribute's flavor
      line (trickTalkLine, dm/appendixgh.h;
      repeatable - talk never spends the trick), and
      first sight shows the engage prompt. The battery
      pins the eleven-line set: count, non-mechanical,
      ASCII, pairwise distinct, and the smart line
      exact. Pinned by the R138 parley audit; census 56.
- [x] **Engine-deep change-family slice (the hardest
      mapping left)** - CLOSED R139: eleven Appendix H
      attributes wired, mechanical set 29 -> 40, all
      conventions (the print gives names only). Change
      align (save or WIS and CHA drop), change
      attribute (save or two abilities swap), change
      class (save or training unravels - xp resets),
      change minds (save or INT drops), change sex
      (save or CHA drops), distorted WL (the bent
      weapon, 1d6), distorted HD (save or max hp
      drops), resisting general (the company is
      repelled), resisting specific (repelled, and the
      trick is not spent), geases (save or WIS drops),
      disintegrates (save or gone). The battery pins
      the set at forty, the eleven mechanical, the
      honest deeps (anti-magic, enrages) dressing, and
      the eleven never talky. Pinned by the R139
      change-family audit; census 57.
- [x] **The final Appendix H sweep (closing the
      list)** - CLOSED R140: twelve odds-ends wired -
      animated (the company is buffeted, 1d4 each),
      combination (a 1d6 strike and a repulse),
      enlarges (save or STR rises, DEX thins), false
      (only light and shadow - the trick is spent),
      gravity lesser (a bob and drop), gravity nil
      (the company floats to the room's center),
      gravity varying (save or 1d6, everyone), moves
      (carried to a random tile), randomly-acts (a
      d3: strike, gift, or still), sloping (the low
      edge takes the company), symbiotic (save or a
      passenger settles - CON drops), wish reversal
      (the inverted boon table: harm, aging, or the
      purse bleeds). THE 65-ATTRIBUTE LIST IS CLOSED:
      52 mechanical, 11 talky, and 2 dressing by
      design (anti-magic needs a magic-use hook,
      enrages needs a berserk hook - neither engine
      exists; documented and pinned). Pinned by the
      R140 final sweep audit; census 58.
- [x] **Engagement geometry (the R43 50' standing
      debt)** - CLOSED R141: a room fight now OPENS at
      the chamber's own geometry - the longest interior
      dimension in 10' bands (rules::engagementBands,
      floored at the 50' corridor convention, capped at
      120') - and the range closes one band per round as
      before. A wide chamber therefore opens wide, and
      the R116 long-range band (-5, DMG p.75) is finally
      reachable in play: a 12-tile chamber opens at
      120', where a sling's long shot (40' short range)
      is exactly possible at -5. Wandering and overland
      engagements keep the 50' convention (no room to
      measure). The battery pins the helper's floor,
      cap, and longest-dimension rule, and the
      long-band-in-play scenario. Pinned by the R141
      engagement geometry audit; census 59.
- [x] **The sample dungeon (DMG pp.94-96)** - CLOSED R142:
      the MONASTERY CELLARS & SECRET CRYPTS, the book's own
      teaching delve, walk as pure data
      (dm/sampledungeon.h): the three keyed rooms - the 30
      foot square entry chamber (exactly 3x3 tiles at 10
      feet; the large spider lairs per the text, and the
      goblin skull holds 19 sp and a 50 gp garnet, with
      the book's 25 percent yellow-mold sack: save vs
      poison or die), the water room (the stream, the
      ivory tube with its water-ruined vellum map, the
      abbot's curious key), and the ceremonial dome (the 9
      foot platform, the seven stone knobs over empty
      socket holes) - plus the book's two d4 wandering
      tables (the halls column wired to the wander roll;
      the crypt column is data for the future crypts, as
      are the crypt-cleric row and the crypts behind the
      seventh knob). The M key in the delve summons the
      keyed map at kSampleSeed; every other seed walks the
      generated dungeon exactly as before. Pinned by the
      R142 sample dungeon audit; census 60.
- [x] **The sample dungeon's crypts (the future-crypts
      debt)** - CLOSED R143: the SECRET CRYPTS are delved.
      Three crypt chambers (the book's own crypt wandering
      column names their lairs - area 24 ghouls, area 27
      skeletons, areas 35-37 the cleric's hobgoblins; the
      book itself keys no crypt rooms, so the chambers and
      lair counts are conventions) hang off a spine south
      of the ceremonial dome, SEALED behind the seventh
      knob's door - rock until the X key turns the knob in
      the dome. South of that door the wander roll switches
      to the book's crypt column, and its second row walks
      at last: the evil 3rd-level cleric, built as a
      Character foe beside his 2 hobgoblins (the book
      gives the crypt column as straight encounters - no
      reaction gate on that row, documented). The crypt
      texts speak on first sight; the abbot's key is
      flavor (the book's secret door 28-29 is a crypt
      lock here by convention). Pinned by the R143 crypt
      wing audit; census 61.
- [x] **The p.71 Example of Melee golden test (the old
      rules-core debt, never scheduled)** - CLOSED R144:
      the book's own worked fight (Aggro the Axe's party
      vs. Gutboy Barrelhouse's, transcribed from the
      1eonline.info compilation - the DMG re-upload's OCR
      died in the preface) is pinned against the engine's
      combat core. The engine matches every printed
      number it models: the seven matrix cells (F4/AC 10
      = 8, T2/AC 10 = 11, F6/AC 5 = 11, F4/AC 5 = 13,
      C4/AC 1 = 17, and the monk Balto's base 18 - via the
      fighter approximation, the engine having no monk
      class), STR 17 = +1 to hit/+1 damage, the 6th-level
      fighter spell save of 14, and the mace-vs-plate +1
      (17 - 1 = 16). The example's other numbers are the
      book's OWN errors (Gygax: the example 'was added by
      the editors, thus slipped past and never got
      corrected' - Balto's staff '-7', the magic missile
      '4-10') or per-weapon rows beyond the engine's
      3-class p.38 approximation (the sling's +3 vs. no
      armor, the axe's +1, the hammer's +1 vs. scale):
      the engine deliberately does not copy the errors,
      and the approximation rows are now STANDING
      APPROXIMATIONS (a per-weapon p.38 table is a future
      lane), as was the dwarf CON magic-save bonus until
      R147 closed it (PHB p.16 - rules::dwarfConSaveBonus;
      see the R147 boxes). R149 BOOK-VERIFIED
      against the fresh DMG upload (the p.71
      example is fully readable there): every
      pinned number prints as pinned - the seven
      matrix cells, the STR +1/+1, the F6 spell
      save of 14, the mace +1 (17 - 1 = 16), the
      sling bullet +3 vs. no armor, the hammer
      +1 vs. scale, and both acknowledged errors
      print as called (the staff -7 mislabeled a
      sword, and 18 - 7 is not 20; the magic
      missile 4-10). AXE CORRECTION: the example
      weapon is a HAND axe, and its +1 vs. no
      armor is the p.38 hand axe row AC 10 cell -
      NOT an editorial error (the battle-axe
      reading was never in play; the R145 box is
      corrected with it). BONUS CONFIRMATION: the
      example dwarf, constitution 16, saves at
      +4 - exactly the R147 formula (16 x 2 / 7
      = 4) - and needs 10 instead of 14, the same
      F6 spell save cell the engine pins. Pinned
      by the
      R144 golden melee audit; census 62.
- [x] **The per-weapon p.38 'to hit' table (R144's standing
      approximation)** - CLOSED R145: every weapon now
      carries its own PHB p.38 armor-class adjustment row
      (15 weapons x 11 columns, AC 0-10), replacing the
      3-class bludgeon/pierce/slash approximation at the
      items::attackAdjustment choke point (the old class
      table stays as the rules-layer fallback, still pinned
      by the R144 audit). Rows transcribed from the
      1eonline.info compilation - the repo-trusted source -
      both p.38 charts (melee rows from the first, the
      short bow / long bow / light crossbow / sling rows
      from the hurled-and-missile chart; the sling is the
      bullet's row, the DMG p.71 example's own weapon);
      the PHB re-upload's book-verify debt stands (the bow
      rows' cell gaps are pinned as the source prints them -
      the composite bows show the same quirk). Standing
      approximations, named: (1) the column is the
      defender's full effective AC (magic, DEX, and shield
      all shift the column; the book keys apparent armor AC
      and says magic/DEX do not shift it); (2) the rows
      apply to every defender - monsters included - where
      the book limits them to humans, demihumans, and
      humanoids; (3) below AC 0 reads column 0 (the book's
      table stops at AC 0); (4) Gygax himself ignored the
      table (the 1eonline FAQ and Delta's D&D Hotspot both
      note it) - the engine pins it anyway, by design. The
      p.71 example's sling bullet +3 vs. no armor - R144's
      named approximation - is now the engine's own row; the
      example's axe is a HAND axe, and its +1 vs. no armor
      is the p.38 hand axe row AC 10 cell - NOT an editorial
      error (the R149 fresh-print correction: the battle-axe
      claim was a misreading of the example weapon; the R144
      box is corrected with it); the example's
      hammer has no engine weapon (the 15-weapon registry
      carries no war hammer - the R144 pin stands). R149
      BOOK-VERIFIED against the fresh PHB upload, the
      printed p.38 charts: eight of the fifteen rows verify
      cell for cell - dagger, club, morning star, long
      sword and short sword from the melee chart, short
      bow, long bow and sling bullet from the missile
      chart - and the bow-row worry is PAID: the premium
      print itself shows the short bow -4 to -1 gap and
      the long bow single -1, exactly as pinned (the
      composite bows print the same shape). The sling
      bullet AC 10 cell of +3 is independently confirmed
      by the p.71 example (R144). The premium melee
      chart prints only AC 2-10 - the AC 0/1 columns
      stay compilation-sourced. The other seven rows
      cannot be arbitrated against this upload: four
      print locally-clean disagreements (hand axe,
      flail, quarterstaff, light crossbow) and the rest
      are OCR cell-fused beyond reading (mace, battle
      axe, spear) - the same chart carries gross fusion
      artifacts in a dozen adjacent rows, so the
      disagreements are more plausibly OCR folds than
      print variants; those cells stay
      compilation-pinned, the debt narrowed and named.
      The compilation site itself has gone dark - the
      fresh uploads are now the last standing source,
      and a cleaner scan is the future winner. Pinned by
      the R145
      weapon table audit; census 63.
- [x] **The city flavor subtables (R64's named omissions)**
      - CLOSED R146: the p.191 drunk identity table ("the
      character(s) found drunk should be diced for" - 20
      bands, assassin 01-02 through tradesman 98-00) and
      the famous p.192 harlot type table (12 bands, the
      slovenly trull 01-10 through the rich panderer
      99-00 - Gygax, on why the table exists: built from
      boredom with the genre's continual 'whores'
      references, included in a spirit of
      vocabulary-building, "no particular regrets") are
      pinned as fiction-only descriptors and wired into
      the city streets flavor strings (the book's MU /
      Merc print in full; the compilation's 'Haughy
      courtesan' is the printed 'haughty', corrected and
      documented). Cell-verified at the raw-HTML level of
      the 1eonline.info compilation - the repo-trusted
      source; the DMG re-upload's OCR debt stands. Still
      unmodeled fiction, named: noble gender and
      the ruffian note - R149 BOOK-VERIFIED against
      the fresh DMG upload and CORRECTED: the print
      reads nobleman-with-retainers 75% / noblewoman
      25% (the 70/25/no-last-5 reading was wrong; a
      clean coin, not a five-way hole), the
      noblewoman 75% sedan-chair detail prints with
      it, and the ruffian 1-in-4 half-orc/humanoid
      note is the printed matrix footnote, confirmed.
      R174 CLOSED the pair: the noble gender coin, the
      noblewoman sedan-chair likelihood and the
      ruffian 1-in-4 note are pinned as fiction-only
      descriptors (cityNobleKind / cityNoblewomanSedan
      / cityRuffianKind), audited by the R174 battery
      block. Pinned by the R146 city
      flavor audit; census 64.
- [x] **The dwarf CON magic-save bonus + matrix II
      footnote D (R144's named standing approximation
      + the p.80 footnote)** - CLOSED R147: dwarves add
      their constitution to saves vs. wands/staves/rods,
      spells, and poison "in the same manner" (PHB
      p.16) - pinned as rules::dwarfConSaveBonus (con*2/7
      clamped 0..5, matching every printed band 4-6 +1
      through 18 +5); NPC foes carry the rolled p.176
      race on the Actor (the half-elf and half-orc
      race-only bands now mark the race where they
      previously fell through), and asTarget / trySaveVs
      apply the bonus to wands, spells, and death-poison
      saves (the party is human - only NPC-foe dwarves
      benefit). Footnote D: non-intelligence saves at
      half hit dice rounded up except vs. death/poison -
      pinned as spelleffects::effectiveSaveLevel, consumed
      by both trySave and the ai trySaveVs; toActor maps
      MM intelligence "non" (containsCI, no dash -
      "non-" wordings excluded; exactly 90 of the 408,
      census-pinned; "animal" keeps the II.B step, a
      named judgment call). Matrix II.C (classed monsters
      saving on their most favorable matrix) stays a
      named gap - the per-monster class pass is a future
      lane. Pinned by the R147 dwarf CON + II.D audits;
      census 67.
- [x] **Appendix P: creating a party on the spur of the
      moment (DMG pp.225-226)** - CLOSED R147: pinned as
      the header-only dm/appendixp.h (the appendixa.h
      pattern - data + rollers, the caller decides when).
      The three level-band options per range (low 1-2 /
      1-3 / 2-4, medium 5-7 / 5-8 / 7-9, upper 8-10 /
      8-11 / 9-12), the 4d6-drop-lowest ability rolls,
      the protective and weapons per-level percentage
      tables (the four primary classes; the book's
      subclass and UA/OA rows are its own variants, out
      of scope), the potion rows (per-level chance, max
      carried, the 10 printed types - the book's "0."
      prints as type 10), the item/+2/+3 chance chain
      (item = level x pct; above-90 excess folds into the
      +2 chance; +3 is a straight 1% per level), and the
      rollMemberMagic kit builder (one armor sort
      chain/ring/chain/leather by class, one weapon sort
      sword/dagger/mace/sword, a shield try for the
      armored classes). Gonzo's worked example pinned:
      15%/level chain at 9th = 135%, +2 chance 9 + 45 =
      54 (rolled 51 - at least +2), +3 check 9 (rolled
      99 - just +2). No caller yet - data + rollers
      only (the p.176 convention-party generator is a
      future lane). Pinned by the R147 Appendix P audit;
      census 67.
- [x] **The book-verify pass (the standing debt)** -
      CLOSED R149: the fresh DMG/PHB uploads
      (2026-10-04) diffed end to end against the repo.
      PAID IN FULL: the Appendix G trap list (R125 -
      all 46 kinds, bands and spellings, byte for
      byte, and double-confirmed against a clean book
      read); the Appendix H attribute fragments (65
      attributes, no contradiction - the 37-feature
      list did not survive the upload OCR and stays
      compilation-pinned, named, though the printed
      example NAMES all corroborate the pinned
      feature and attribute spellings); the Faerie,
      Pleistocene and Age of Dinosaurs wilderness
      tables (R126 - 39 + 23 rows exact, plus all
      readable Dinosaur Age cells; the Pleistocene
      camel reading is an OCR column shift, resolved
      by band continuity); the printing variants
      (R126 - scrub Humanoid 26-32 and the tropical
      mountains dervish 29-30 both print as the repo
      resolved them, and the marsh Men defects are
      the premium print itself, pinned as
      print-defect corrections); the city flavor
      cells (R146 - both tables exact, haughty
      confirmed, noble gender corrected to 75/25);
      and the p.71 example (R144 - every pinned
      number prints; the axe is a hand axe, claim
      corrected; the dwarf CON 16 save at +4
      independently confirms the R147 formula).
      PARTIALLY PAID, named: the p.38 weapon rows
      (R145 - eight of fifteen verify exact, the
      rest unarbitratable against the upload OCR;
      the box carries the detail). The compilation
      site has gone dark - the fresh uploads are
      the last standing source, and a cleaner scan
      wins any future cell.
- [x] **Appendix I, dungeon dressing (pp.219-221)** -
      PINNED R150: dm/appendixi.h, the appendixa.h
      pattern (pure data, header-only, no caller yet;
      the audit is the regtest.cpp R150 block). The
      five band lists pinned edge for edge: air
      currents, odors, air, general items and
      unexplained sounds. COUNT CORRECTIONS (the
      R149 box's own slips, named in the header): the
      prints read 14 air-current bands (not 16), 54
      general-item bands (not 100) and 58 sound bands
      (not 68); odors (14) and air (6) were right -
      the band CONTENT the box quoted was correct all
      along. The selection-aid lists the book prints
      alongside them (furnishings, torture chamber,
      magic-user and religious furnishings, container
      contents, misc items, jewelry, foodstuffs) are
      choose-as-desired aids, not band tables, and
      stay unpinned (named).
- [x] **PC races layer (PHB pp.15-18, Race Tables I-III)**
      - PINNED R154, re-authored against current main in
      the new rules/races layer: the adjustments, the
      Table III min/max (M/F), infravision, sleep-and-
      charm resistance, the CON magic-save bonuses
      (gnome poison corrected OUT - the print names
      magic only), Race Tables I and II with every
      printed footnote, the goblin-kind/giant-kind
      to-hit lists and the detection lists; creation
      gains the RACE stage and the save gains the
      optional race line (the audit is the regtest.cpp
      R154 block).
- [x] **Matrix II.C (classed monsters, most favorable
      matrix)** - pinned by R155: the saveAs data pass
      (class bits + per-class levels, the Lua key) and
      mostFavorableSaveTarget min the save in
      spelleffects/trySave and the ai save helper; the
      five MM1 classed write-ups carry the data.
- [x] **Appendix P caller (the convention-party
      generator)** - pinned by R156: rollSpurMember
      (level, the six 4d6-best-of scores, the kit) and
      rollConventionParty in dm/encounters - the R147
      tables, first engine caller. The p.176 subtable
      rows keep their own R55 magic ladder (a different
      print; not conflated).
- [x] **Grenade-like missiles + holy/unholy water
      (pp.64-65)** - pinned by R157: rules/grenade.h, the
      header-only flask layer (sizes, effect dice, range
      bands, item-save breaks, the d8 direction cone,
      holy/unholy targeting, oil crossing, vial cost,
      boulder drops); the throw itself rides the
      missile-fire lane.
- [x] **Weapon speed factors in initiative (p.66)** - pinned
      by R158: rules/weaponspeed.h (the p.38 factor table,
      the tie order, the extra-attack windows, the
      weapon-vs-spell strike segment); rules/turn verified
      first and deliberately untouched - the print applies
      factors only in caller-detected cases.
- [x] **Striking to subdue (p.67)** - pinned by R159:
      rules/subdue.h (the 75/25 accounting, applicability,
      the knockout threshold, and the MM dragon capture:
      the kind table, the int gate, the percent ratio,
      the automatic subdual, the sale price).
- [x] **Weaponless combat (pp.72-73)** - pinned by R160:
      rules/weaponless.h (the shared variable, the
      initiative priority, the 25/25/50 accounting, the
      base scores, every modifier, the three tables, the
      hold ladder, the general notes).
- [x] **Attacks with two weapons (p.70)** - pinned by
      R161: rules/twoweapon.h (the dagger/hand-axe
      gate, the penalty ladder with the dex easing,
      the low-dex add-to-each rule, no shield or
      parry from the second weapon).
- [x] **Level title ladders (PHB class tables)** - pinned by
      R162: rules/classes.cpp (the four printed ladders
      through the name levels; the cleric level 5 blank
      cell carries Curate down; the XP-row divergence is
      CLOSED R176 - the rows repinned to the print).
- [x] **The poison table (p.20)** - pinned by R163:
      rules/poison.h (the ingestive/insinuative grade
      table with cost, onset, damage classes, save
      bonuses and detection chances; the efficiency
      ladder; the blade-venom decay).
- [x] **The assassination table (p.75)** - pinned by
      R164: rules/assassinate.h (the 15x10 odds matrix
      with the dashes as no chance, the band mapping,
      the level clamps, the helpless-opponents
      footnote).
- [x] **Potion miscibility (p.119)** - pinned by R165:
      rules/miscibility.h (the d100 band table with the
      explosion, poison and boost numbers; the trigger
      conditions; the named campaign options).
- [x] **Intoxication and insanity (pp.82-83)** - pinned
      by R166: rules/insanity.h (the intoxication and
      recovery tables; the 20 insanity types with
      the mild-star, the duration classes and the
      per-form numbers).
- [x] **PC disease + parasitic infestation (pp.13-14)**
      - pinned by R167: rules/disease.h (the
      contraction chances with every modifier, the
      occurrence and severity tables cell by cell,
      the die roll adjustments, the per-area
      losses, the death relapse).
- [x] **Underwater spell use (p.57)** - PINNED
      R168: rules/uwspells.h (the cannot-cast and
      altered spell lists cell by cell, the general
      limits, the altered-effect numerics).
- [x] **Chances of becoming lost (p.49)** - PINNED
      R152: the dm/outdoormove.h lost section (the audit
      is the regtest.cpp R152 block): the chance in 10
      per terrain, the direction limitation per terrain
      and the deterministic heading mapping - the dice
      are the callers. The R123 movement rates next to
      it are the same outdoor march this check gates.
- [x] **Humanoid racial preferences (p.106)** - PINNED
      R169: rules/humrpref.h (the 81-cell matrix with
      the star marks, the letter key, the usage and
      the compatibility prose).
- [x] **Appendices K + L + M (pp.221-224)** - PINNED
      R171: rules/klm.h (the substance word lists, the
      conjured animals categories, the 20 summoned
      monsters tables; the Appendix L 5-and-up band
      columns were the OCR-debt finding, CLOSED
      R175: the full 26-row table is pinned from
      the trusted compilation).
- [x] **Appendix O, encumbrance of standard items
      (p.225)** - PINNED R151: dm/appendixo.h, the
      appendixa.h pattern (pure data, header-only; the
      audit is the regtest.cpp R151 block): the 64
      printed weights in g.p. units, the 57 exact rows
      and the 7 printed ranges (the four chests, gem,
      small jewelry, tapestry) both ends, the tapestry
      open tail, the 1500 g.p. (150#) carry max and
      the four exemption wordings. The caller is
      items::encumbranceBand (PHB p.38) - this is its
      printed per-item source.
- [x] **Exceptional strength (PHB p.9)** - PINNED R153,
      a divergence fix: the percentile roll itself was
      already sound (rollExceptionalStrength, R120s),
      but the band data misread two cells and carried
      unsourced carry/press numbers - corrected to the
      printed Table II, all five columns, 3-18/00 (the
      audit is the regtest.cpp R153 block). The
      locked-door parentheticals and the
      one-attempt-ever footnote are pinned with it.
- [x] **Followers by class (pp.16-18)** - PINNED
      R170: rules/followers.h (the cleric, fighter,
      ranger, thief and assassin recruitment tables
      cell by cell, the multi-class tables, the
      Grandfather ladder, the arrival timing and
      the paladin warhorse).
- [x] **Secondary skills (p.12)** - PINNED R173:
      rules/secondary.h (the 23-band table cell by
      cell; the when-to-use guidance).
- [x] **R146 fiction (the named omissions)** - CLOSED
      R174: the noble gender coin (nobleman 75% /
      noblewoman 25%, the R149 correction), the
      noblewoman 75% sedan-chair detail and the
      ruffian 1-in-4 half-orc/humanoid note are all
      pinned as fiction-only descriptors
      (cityNobleKind / cityNoblewomanSedan /
      cityRuffianKind), audited by the R174 battery
      block. Census 92.

## Out of scope by design

- OUT: Aerial and naval combat systems, siege
  and war-machine rules, stronghold domain
  income beyond the keep's ledger, disease and
  heal-craft subgames, psionic combat (p.77
  IV.A and following), planar travel tables,
  and the full non-standard-procedure magic
  items list beyond what the battery pins, the Boot
  Hill / Gamma World / Metamorphosis Alpha
  conversion tables (pp.112-114). Appendix J was
  OUT until R172 reversed it - pinned now (see the
  R172 note and the box below).

- [x] **Appendix J: herbs, spices and medicinal
      vegetables (p.220)** - PINNED R172:
      rules/herbs.h (the 171-row plant and uses
      table cell by cell; the turnip row the
      compilation drops restored).

## How this doc lives

Each fix round flips its box HERE, in the same
commit, and names its book page in the round
message. The ranked divergences above are the
natural next rounds: turning first, saves
second, then the attack matrices.
