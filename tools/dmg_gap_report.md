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

R213 landed the construction and siege
economics (DMG pp.106-108, the CONSTRUCTION
& SIEGE head) - a seam with zero prior
coverage (only incidental castle-artillery
counts elsewhere). rules/construct.h (the
grenade.h pattern): the MINING cubic volume
table (8 miner groups x 3 rock types,
cubic feet per 8 hours per miner - stone
giant 500/350/175 at the top), the linear
multiple-workers volume, the max miners
per 10-foot shaft (16/12/8/6/4), the
24-hour shifts with the 8-hour worker cap,
the natural cave area chances (limestone 1
in 10, other sedimentary 1 in 50, lava 1 in
20, other igneous 1 in 100 - pinned as
percents), the slave labor efficiency bands
(foreman ratio 1:16 through 1:4 = 50
through 80 percent) with the 1-guard-per-
4-workers minimum, the CONSTRUCTION TIME
pins (the ditch crew and heavy clay, the
stone week per 10-foot cube with the 150
percent = double and 250 percent = triple
rate maximum, the 4-month stone and 2-month
wood buildings, the 10-foot-per-day
hoardings, the four castle estimates with
the citizen labor 50 percent), the 44-row
CONSTRUCTIONS cost table (arrow slit 3 gp
through barred window 10 gp), the per-
square-foot door and port adjustments, the
stone course formula (the worked 950 gp
example), the tunnel ground factors (soft
1x, hard earth 2x, solid rock 5x), the
ditch-rampart 20 percent, the battlement
composition, the buttress count, and the
12-row siege engine costs (ballista 75 gp
through trebuchet 500 gp). PAGE-LABEL
CORRECTION: the print TOC places the
personae/hiring/troops seams at pp.100-106
(height of characters p.102, non-human
soldiers pp.105-106) - the R211 pp.115-116
and R212 pp.116-118 include-comment labels
read high; the pinned content is
unaffected. New R213 battery audit; census
129. Next: the DMG-only sweep continues -
the war machine fire tables, the siege
attack values, and the construction
defensive values (pp.108-110).

R214 landed the war machine fire tables,
the siege attack values, and the defensive
values (DMG pp.108-110, the CONSTRUCTION &
SIEGE tail) - a seam with zero prior
coverage (the R157 grenade scatter and the
R111 attack matrices are cross-links, not
overlap). GROUND TRUTH NOTE: the upload OCR
scrambles the crew column and interleaves
the fire columns; the 1eonline compilation
(seadow.htm) is the recovery source (the
R209/R210 rule) and matches the upload cell
values everywhere else - both sources agree
on the attack matrix and the defensive
tables. rules/siegefire.h (the grenade.h
pattern): the six firing devices (field of
fire 45/15/30/-/-/10 degrees, ranges in
quarter-inch units, S-M and L damage edges,
rate of fire in hundredths - the ballista
1/4 to 1/2 at 2 to 4 crew, the ram and sow
1/2 at 10 to 20), the crew rules (below
minimum 50 percent, only the ballista
doubles at max crew), the hit determination
conventions (AC 0 targets, ballista AC 10,
the movement, size, weather and direct-fire
d20 modifiers), the trajectory and cover
rules (flat ballista blocked, arched
catapult fire over, unseen target = the
grenade scatter, ballista fire impossible),
the 22-row SIEGE ATTACK VALUES matrix in
quarter-point units (Bigby fist 1/-/1/2-1/4
per round through trebuchet missile
8/-/5/3; the horn of blasting 18/6/8/4;
dig earth 10; move earth 20; the
per-caster-level fireball and lightning
bolt with the wet-wood 50 percent clause;
the earthquake dice rows 5-60/5-30; the sow
screw clause), the 26-row CONSTRUCTION
DEFENSIVE VALUES with the ranges (building
wood 8-16, drawbridge 10-15, gate 8-12,
palisade 6-12, tower round 40-80, tower
square 30-50) and the barbican, supports,
rampart and curtain-wall footnotes, the
12-device MHP table (the ram catcher has no
print value - pinned 0 with the note), and
the additional attack forms (the mining
breach 10 feet or 10 points, sapping per
turn). New R214 battery audit; census 130.
Next: the DMG-only sweep continues - the
CONDUCTING THE GAME chapter (the dice
control, the troublesome players, the
campaign integration seams, DMG pp.110-112
area, upload lines ~8560+).

R215 landed the conducting the game pins
(DMG pp.110-112) - a prose-heavy chapter
whose numeric bones are now pinned.
rules/conduct.h (the grenade.h pattern):
the divine intervention procedure (the
exemplary first-time asker 10 percent
creature-sent chance; the 00 roll with the
chance the deity itself comes equal to the
character level; the six modifiers - each
previous intervention STACKS -5 as a count,
medial alignment -5, borderline -10,
required direct confrontation -10,
opposing diametric forces +1, proximate
service +25, the five flags clamped to
once each and no floor, the print sets
none), the planes rule (Prime Material,
Astral and Ethereal yes, Elemental DM
option, Outer and Positive/Negative no,
the elemental-gods block), the 7 secret
dice-roll kinds, the system shock
untouchability (never tampered, failure is
forever dead), the player integration
numbers (the d4+1 averaging die 2-5, the
8th-level ceiling, the 4th-level start
above it, the neophyte full-cooperation
level 3), the multiple characters rules
(no prohibition, no free interchange), and
the troublesome-player measures (the
charisma point, the always-surprising
ethereal mummy). The Boot Hill / Gamma
World conversion tables (pp.112-114) stay
OUT by design. Compilation cross-check
(the DDG divine intervention page) matches
the upload, adding only the asked-for-not-
received clarifying note. New R215 battery
audit; census 131. Next: the DMG-only
sweep continues - the ongoing campaign
chapter and its seams (the campaign
economics and time pins already landed; the
likely next pin material is the tables of
the AD&D campaign milieu sections, upload
lines ~8720+).

R216 landed the magical research pins
(DMG pp.114-119) - the holy/unholy
water receptacles, the spell research
economics, the manufacture gates and
the potion rules. rules/magres.h (the
grenade.h pattern): the five metals
(copper, silver, electrum, gold,
platinum) with vial capacity 6/10/18/
32/50, the basin cost ranges 130-180 /
1900-2400 / 8000-12000 / 19000-22000 /
110000-200000 gp, font costs 200/500/
1000/1500/2000 gp, vials 2-5 gp, font
construction 4-10 weeks (2d4+2), one
creation per week, 8 hours rest, one
font per edifice, the defilement remake
20-50 percent over 4-6 weeks, the
lycanthropy delay 1-4 turns per vial,
and mixed metals interpolating capacity
(the print copper/silver 50/50 = 8
vials, rounded to nearest); the spell
research economics (200 gp per level
per week base + 100-400 gp variable, no
library x10, minimum weeks level + 1,
interruption day = week lost, 8 h/day,
chance 10 percent + 10 per extra 2000
gp per level capped 50 + INT/WIS +
level - 2 x spell level, impossible
beyond MU 9th / cleric 7th, combo spells
sum + 1, library gathering 1 week per
level); the manufacture gates (cleric
11, wizard 12, illusionist 11; books,
artifacts, relics and the dwarven/elven
specials DM-only); and the potion rules
(MU 7th with alchemist, 11th optional at
-50 percent, one at a time, lab 200-1000
gp + 10 percent monthly upkeep, cost and
days = the XP award, each 100 gp or
fraction a day, no-XP base 200 gp,
assassin poison 9th, delusion failure
5-20 percent). Compilation cross-check:
the sr.htm page is a Dragon editorial
and stays OUT per the ground-truth rule;
the upload is clean at this seam and is
the sole source. New R216 battery audit;
census 132. Next: the scroll and other
magic item manufacture seams (upload
lines ~9100+, pp.119+).

R217 landed the scroll manufacture and
fabrication pins (DMG pp.118-121) - the
MANUFACTURE OF SCROLLS seam and the
FABRICATION material that follows it.
rules/scrollfab.h (the grenade.h pattern):
the inscription gates (cleric, druid,
magic-user, illusionist at 7th or higher,
the spell one the inscriber can employ;
the protection scroll split - clerical
devils/possession/undead vs magic-user
demons/elementals/lycanthropes/magic/
petrification, curse scrolls by any spell
user), the materials (papyrus 2 gp and up
+5 percent, parchment 4 gp and up +/-0,
vellum 8 gp and up -5 percent, a fresh
virgin quill per spell from a strange or
magical creature - the 6 named quill
beasts, ink from giant squid sepia or
giant octopus ink with a different ink
per spell), the preparation (one full day
per spell level, continuous - leaving
breaks the magic), the failure chance (20
percent + 1 per spell level - the
character level + the material modifier;
the print example: 14th level cleric, 7th
level spell, parchment = 13 percent; a
percentile roll over the chance is a
success, the print sets no floor),
multiple spells (a failure blocks further
spells, 7 spells maximum per scroll),
transcription off a scroll (read magic
plus the same time as scribing, the spell
then disappears), the fabrication of
other items (enchant an item - save
clerical items; rest one day per 100 gp
of XP value - 2000 xp = 20 days, no
adventuring or spell use; permanency for
permanent dweomers but not chargeable
items), the cleric and druid retreat (a
fortnight in retreat, a sennight fasting,
a day of purification, a cumulative 1
percent per day empowerment, 24 hours to
charge), the illusionist gates (scrolls
7th, one-shot and charged items 11th with
major creation and the 16-hour instilling
window, permanent dweomers 14th with
alter reality and the unflawed 10000 gp
gem), and the charmed or enslaved
magic-user rule (totally unable to
fabricate any magic item, the attempts
fruitless). The non-standard items and
command words seams remain; the upload is
the sole source at this seam. New R217
battery audit; census 133. Next: the USE
OF MAGIC ITEMS seam - command words,
crystal balls and scrying, drinking
potions and applying oils, and the potion
miscibility tables (upload lines ~9320+,
pp.121+).

R218 landed the use of magic items and
energy draining pins (DMG pp.119-122) -
the USE OF MAGIC ITEMS seam and the
ENERGY DRAINING BY UNDEAD OR DEVICE
section that follows it (the potion
miscibility table between them is already
pinned by R165 and stays out).
rules/energydrain.h (the grenade.h pattern):
drinking potions (one segment to open and
consume, then a d4+1 = 2-5 segment delay
to full effect), applying oils (one segment
to decant, 2-5 segments to spread),
command words (a rod, staff or wand usually
needs the proper word - learned from the
possessor, hidden records, or the three
informational spells: contact other plane,
legend lore, speak with dead), crystal
balls and scrying (detectable; a spell-user
target checks the DETECTION OF INVISIBILITY
table each round; darkness stops the viewing
for the spell duration, dispel magic for a
full day), the energy drain mechanics (the
hit points gained with the level including
the constitution bonus, all abilities of
the level, XP to the mid-point of the next
lower level; below 1st is a 0 level person
never capable of gaining again; a 0 level
individual drained is dead), the multiclass
drain rules (always the highest level, ties
to the greatest-XP class, a two-level drain
splits one level per class), and the
drained-all fate (an undead of the same
sort as the slayer, lesser undead at half
hit dice controlled by their master, the
lesser vampire at half the former
professional level - the print example: an
8th level thief returns as a 4th level
thief vampire, odd levels round down - and
the full-hit-dice regain upon the
destruction of the slayer). The treasure
random determination tables (upload lines
~9330+, the map/monetary/magic/combined
hoard tables) are the natural next seam.
New R218 battery audit; census 134. Next:
R219 - the TREASURE RANDOM DETERMINATION
tables (I. map or magic, II. the map table
and its outdoor distance/containment
sub-tables, II.A monetary, II.B magic,
II.C combined hoard, upload lines ~9330+,
pp.122-125).

R219 landed the treasure random determination
tables pins (DMG pp.120-123, upload lines
~9330-9480) - the top-level determination
tables the engine never implemented (the
R122 line-diff closed the III.A-H item
tables and the lair types; the gap report
claim that dm/treasure.cpp implements the
map/monetary/magic structure referred to
the lair-type coin bundles, and these
determination tables existed nowhere).
rules/treasdet.h (the grenade.h pattern):
Table I map or magic (01-10 the map table,
11-00 the magic items table), Table II the
map table (01-05 false, 06-70 monetary,
71-90 magic, 91-00 a combined hoard; a map
never lists its treasure, only the
location), the outdoor destination
sub-table (01-20 lair caves, 21-60 outdoors
5-8 miles, 61-90 10-40 miles, 91-00 50-500
miles; direction d8 with 1 north counting
round), the containment sub-table (01-10
buried unguarded, 11-20 water, 21-70 lair,
71-80 ruins, 81-90 crypt, 91-00 town),
Table II.A monetary treasure (the nine d20
rows: cp 20,000-80,000 at 2d4 x 10,000; sp
20,000-50,000 at d4+1 x 10,000; ep
5,000-30,000 at 5d6 x 1,000; gp 3,000-
18,000 at 3d6 x 1,000; pp 500-2,000 at 5d4
x 100; gems 10-100 at d10 x 10; jewelry
5-50 pieces at 5d10; row 18 roll twice and
row 19 roll thrice discounting rolls above
17; row 20 each monetary item above - read
as one of each row 1 through 17, rows 18
and 19 being re-roll instructions), and
Table II.B magic treasure (1-5 any item
plus 4 potions; 6-8 any 2 items; 9-12 one
sword, one armor or shield, one misc
weapon; 13-14 any 3 items with no sword or
potions; 15-18 any 6 potions and any 6
scrolls; 19 any 4 items, 1 a ring and 1 a
rod; 20 any 5 items, 1 a rod and 1 misc
magic) plus the design notes (the
abandonment theft chance DM-set, low-value
treasures less guarded, the magic table
deliberately weighted to keep potent magic
rare). The II.C combined hoard table is the
R220 candidate. New R219 battery audit;
census 135. Next: R220 - the II.C combined
hoard table (upload lines ~9440-9470, the
ten percentile rows mixing constrained
monetary and magic sub-rolls with map
leads, DMG p.123).

R220 landed the combined hoard table pins
(DMG p.123, upload lines ~9430-9470) - the
II.C COMBINED HOARD table, the R219
companion. rules/hoard.h (the grenade.h
pattern): the ten percentile bands (01-20,
21-40, 41-55, 56-65, 66-75, 76-80, 81-85,
86-90, 91-96, 97-00) with their on-hand
monetary rows (b0: 1-2; b1: 6-10; b2: 3-5
and 6-10; b3: 1-2, 3-5 and 6-10; b4: 6-10
and 11-12; b5: 3-5, 6-10, 11-12 and 16-17;
b6/b7: the 20 row; b8/b9 none), their
on-hand magic rows (b0/b1: 1-5; b2: 1-5 and
15-18; b3: 9-12 and 13-14; b4: 6-8 and
15-18; b5: 1-5 and 9-12; b6/b7 none; b8:
20; b9: 15-18 and 20), the map-to-magic
references of bands 81-90 (to 1-5 and to
19), the map-to-monetary references of
bands 91-00 (to 1-2 and 3-5; to 11-12 and
13-15), and the design notes (the real
finds; hidden, trapped, guarded, distant).
The row references are stored as the R219
sub-table band indices so the two headers
interlock; the die 18/19 monetary re-roll
instructions are never referenced by this
table. With this round the whole RANDOM
TREASURE DETERMINATION top-level structure
(I, II, II.A, II.B, II.C) is pinned; the
III.A-H item tables were already closed by
R122. New R220 battery audit; census 136.
Next: R221 - the III.A potions table
prose rules that frame the item tables (the
(F) fighter-only marks, the delusion and
poison DM-misleading notes, the control-
type die rolls, upload lines ~9480-9520,
DMG p.125-126), or the first un-pinned
III.A-H surrounding prose seam.

R221 landed the III.A potions prose pins
(DMG pp.125-126, upload lines ~9480-9520)
- the three footnotes that frame the
III.A POTIONS table. rules/potions.h
(the grenade.h pattern), keyed to the 35
die bands of the engine III.A table in
kPotions order: the * control potions
(Animal Control, Dragon Control, Giant
Control, Giant Strength, Human Control,
Undead Control - effectiveness on the
type of creature controlled must be
determined by die roll; consult the item
explanation); the ** DM-misleading potions
(Delusion, Poison - the DM must mislead
the holder so as to convince him the
potion is not harmful); the (F)
fighter-only potions (Giant Strength,
Heroism, Invulnerability, Super-Heroism).
JUDGMENTS: Plant Control prints with NO
star (unlike every other control potion)
and is pinned control-less as printed;
Giant Strength prints BOTH * and (F). The
row VALUES and dice-band continuity were
already pinned by the R122 line-diff audit
(magicTablePin), so this round pins only
the footnote flags and re-pins the band
edges. New R221 battery audit; census 137.
Next: R222 - the III.B scrolls footnotes
and prose (DMG pp.126-127, upload lines
~9525+), or the first un-pinned III.A-H
surrounding prose seam.

R222 landed the III.B scrolls prose pins
(DMG pp.126-127, upload lines ~9532-9595)
- the structure and prose of the III.B
SCROLLS table. rules/scrollpins.h (the
grenade.h pattern): the 16 spell-scroll
rows (dice bands 01-60, spell counts and
level ranges re-pinned, plus the printed
ILLUSIONIST ALTERNATIVE RANGES - the or
X-Y* halves on the 17-19, 25-27, 33-35,
40-42, 47-49, 53-54 and 60 bands; JUDGMENT:
pinned as data even though the engine
roller reads only the main range, as the
print gives no dice split for which half
a found scroll uses; alt lo = main lo, alt
hi lower on every alt row); the 8
protection scroll rows with their
table-printed x.p. values (2500, 2500,
1500, 1000, 1500, 2000, 2000, 1500); the
8-row curse sub-table (01-25 polymorph to
equal-level monster that attacks, 26-30
liquid, 31-40 transported 200-1,200 miles
random direction, 41-50 another planet/
plane/continuum, 51-75 disease fatal in
2-8 turns unless cured, 76-90 explosive
runes, 91-99 nearby item de-magicked,
00 random spell at 12th level of
magic-use); and the prose: 100 x.p. per
spell level awarded only to characters
who can use the spell, spell scrolls sell
at 3x x.p. on the open market, protection
scrolls at 5x, the DM must do his utmost
to convince players a cursed scroll
should be read (duplicity, coercion and
threat), unread scrolls may fade in
normal air, and a curse takes effect
immediately. The engine III.B structure
(kSpellScrolls, the protection list and
the cursed-scroll name) was already in
dm/treasure.cpp and faithful; this round
pins what was never pinned. New R222
battery audit; census 138. Next: R223 -
the III.C rings footnotes (the (M)
magic-user-only mark and the charge-
limited double-dagger rows, DMG p.127,
upload lines ~9600-9640), or the next
un-pinned III.A-H surrounding prose seam.

R223 landed the III.C rings footnote pins
(DMG p.127, upload lines ~9596-9623) - the
two footnotes that frame the III.C RINGS
table. rules/rings.h (the grenade.h
pattern), keyed to the 24 die bands of the
engine III.C table in kRings order: the
double-dagger charge-limited rings (Djinni
Summoning, Human Influence, Mammal
Control, Multiple Wishes, Telekinesis,
Three Wishes, Wizardry - these contain
the most powerful magical abilities and
may possess only a limited number of
magical charges before being depleted,
at the DM option) and the (M) ring
(Wizardry: magic-user use only). JUDGMENT:
Ring of Wizardry prints BOTH the
double-dagger and the (M); both flags
are set. The row VALUES were already
pinned by the R122 line-diff audit; this
round pins the footnote flags and the
band edges. New R223 battery audit;
census 139. Next: R224 - the III.D rods,
staves and wands footnotes (the
point-value asterisk, the class marks C/M/
F/T/any and the charge notes, DMG
pp.127-128, upload lines ~9625+), or the
next un-pinned III.A-H surrounding prose
seam.

R224 landed the III.D rods/staves/wands
footnote pins (DMG pp.127-128, upload
lines ~9625-9658) - the class-usable
marks and the full-charges asterisk that
frame the III.D RODS, STAVES, & WANDS
table. rules/rodswands.h (the grenade.h
pattern), keyed to the 30 die bands of the
engine III.D table in kRods order: the (C)
cleric-only, (M) magic-user-only, (F)
fighter-only, (T) thief-only and (any)
any-class marks (10 any rows, 10 cleric,
14 magic-user, 2 fighter, 1 thief -
Beguiling the only (T); Lordly Might the
only (F); Smiting the (C, F); Absorption,
Command, Striking and Fear the (C, M)
rows; the staves Curing, the Magi, Power,
the Serpent, Withering per the print),
and the column-header asterisk: both the
x.p. and g.p. values assume FULL charges
are in the item. JUDGMENT: the (any) rows
carry no individual class marks - the any
flag and the four class flags are mutually
exclusive per row, verified both ways in
the audit. The row VALUES were already
pinned by the R122 line-diff audit; this
round pins the class marks and the band
edges. New R224 battery audit; census 140.
Next: R225 - the III.E miscellaneous magic
table 1 class marks and footnotes (DMG
p.128, upload lines ~9665+), or the next
un-pinned III.A-H surrounding prose seam.

R225 landed the III.E table 1 footnote
pins (DMG p.128, upload lines ~9674-9722)
- the class marks and special rows that
frame TABLE (III.E.) 1. rules/miscmagic1.h
(the grenade.h pattern), keyed to the 33
die bands of the engine III.E.1 table in
kMisc1 order: the (C) marks (Book of
Exalted Deeds, Book of Vile Darkness)
and the (M) marks (Bowl Commanding
Water Elementals, Bowl of Watery Death,
Brazier Commanding Fire Elementals,
Brazier of Sleep Smoke); the Artifact
or Relic row (17, no values - see the
Special table hereafter); the Bracers of
Defense asterisk (60-79: the x.p. and
g.p. values are PER ARMOR CLASS POINT
above 10 - AC 6 worth 2,000 x.p. /
12,000 g.p., four points); and Bucknard
Everfull Purse (99-00) as the tiered-
values row (the R122-pinned 1500-4000 /
15000-40000 ranges match the printed
1,500/2,500/4,000 tiers). The row VALUES
were already pinned by the R122 line-diff
audit; this round pins the class marks,
the special rows and the band edges.
New R225 battery audit; census 141.
Next: R226 - the III.E table 2 class
marks and the Cloak of Protection and
Crystal Ball asterisk/notes (DMG p.128,
upload lines ~9724-9760), or the next
un-pinned III.A-H surrounding prose seam.

R226 landed the III.E table 2 footnote
pins (DMG p.128, upload lines ~9724-9760)
- the class marks and asterisk rows that
frame TABLE (III.E.) 2. rules/miscmagic2.h
(the grenade.h pattern), keyed to the 30
die bands of the engine III.E.2 table in
kMisc2 order: the (C) mark (Candle of
Invocation); the (M) marks (the two
Censers, Crystal Ball, Crystal Hypnosis
Ball, Eyes of Charming); the Cloak of
Protection per-plus asterisk (33-55:
1,000 x.p. / 10,000 g.p. per plus of
protection - a +2 cloak is 2,000 /
20,000); the Crystal Ball double
asterisk (56-60: base 1,000 x.p. /
5,000 g.p., add 100% for each
additional feature); and the Eyes of
Petrification triple asterisk (00:
---*** in both value columns). The row
VALUES were already pinned by the R122
line-diff audit; this round pins the
class marks, the asterisk rows and the
band edges. New R226 battery audit;
census 142. Next: R227 - the III.E
table 3 footnotes (Figurine per-hit-die
asterisk, DMG p.129, upload lines
~9765+), or the next un-pinned III.A-H
surrounding prose seam.

R237 landed the III.E table 3 footnote
pins (DMG p.129, upload lines ~9765-9825)
- the class marks and the asterisk ladder
that frame TABLE (III.E.) 3.
rules/miscmagic3.h (the grenade.h
pattern), keyed to the 33 die bands of
the engine III.E.3 table in kMisc3
order: the (C, F, T) marks (Gauntlets of
Ogre Power 21-22, Gauntlets of Swimming
and Climbing 23-25, Girdle of
Femininity/Masculinity 28, Girdle of
Giant Strength 29); the (C, F) mark
(Horn of the Tritons 50-53); the (C)
marks (Incense of Meditation 66-70,
Incense of Obsession 71); the (F) marks
(Javelin of Lightning 81-85, Javelin of
Piercing 86-90); NO (M) rows ride this
table. The asterisk ladder: the Figurine
of Wondrous Power (01-15) single star -
100 x.p. / 1,000 g.p. PER HIT DIE of
the figurine; the Horn of Valhalla
(54-60) double star - double for a
bronze horn, triple for an iron horn;
the Ioun Stones (72) triple star - per
stone; the Instrument of the Bards
(73-78) QUADRUPLE star - 1,000 x.p. /
5,000 g.p. per level of instrument for
bards (the fourth footnote the book
upload DROPS - restored from the
1eonline.info compilation, the R175
precedent); and the Jewel of
Flawlessness (92) per-facet row (no
x.p., 1,000 g.p. per facet). The row
VALUES were already pinned by the R122
line-diff audit; this round pins the
class marks, the asterisk ladder and
the band edges. New R237 battery audit;
census 156. Next: R238 - the III.E
table 4 footnotes (the Libram and
Manual class marks, the Necklace of
Missiles per-hit-die asterisk, the
Medallion dual values and the Pearl
of Power per-spell-level star, DMG
p.129-130, upload lines ~9827+), or
the next un-pinned III.A-H surrounding
prose seam.

R238 landed the III.E table 4 footnote
pins (DMG p.129-130, upload lines
~9817-9898) - the class marks, the
asterisk ladder and the dual-value rows
that frame TABLE (III.E.) 4.
rules/miscmagic4.h (the grenade.h
pattern), keyed to the 36 die bands of
the engine III.E.4 table in kMisc4 order:
the (M) marks (the three Librams, the
Manual of Golems with C, the Mirror of
Life Trapping, the Pearl of Power); the
(C) marks (the Manual of Golems with M,
the Necklace of Prayer Beads, the Pearl
of Wisdom, the two Nets with F and T,
the three Phylacteries); the (F) marks
(the Manual of Puissant Skill at Arms,
the Mattock of the Titans, the Nets);
the (T) marks (the Manual of Stealthy
Pilfering, the Nets). The asterisk
ladder: the Necklace of Missiles (24-27)
single star - 50 x.p. / 200 g.p. PER HIT
DIE of each missile; the Necklace of
Prayer Beads (28-33) double star - PER
SPECIAL BEAD; the Marvelous Pigments
(43-44) triple star - PER POT of
pigments; the Pearl of Power (45-46)
quadruple star - PER LEVEL OF SPELL (all
four footnotes ride the book upload this
time - no restoration needed). The two
DUAL-VALUE rows: the Medallion of ESP
(13-15) at 1,000/3,000 x.p. and
10,000/30,000 g.p., and the Feather
Token (86-00) at 500/1,000 x.p. and
2,000/7,000 g.p. (a new walk flag - the
R225 tiered-purse analog). Cross-checked
against the 1eonline.info compilation
(which drops the Golems and Beads marks
the upload carries - the upload is the
book-text source, the R225/R226
convention). The row VALUES were
already pinned by the R122 line-diff
audit; this round pins the class marks,
the asterisk ladder, the dual-value rows
and the band edges. New R238 battery
audit; census 157. Next: R239 - the
III.E table 5 footnotes (the Robe and
Rug class marks, the Saw and Spade (F)
marks, DMG p.130, upload lines ~9898+),
or the next un-pinned III.A-H
surrounding prose seam.

R239 landed the III.E table 5 footnote
pins (DMG p.130, upload lines ~9898-9915)
- the class marks that frame TABLE
(III.E.) 5, the LAST of the miscellaneous
magic sub-tables. rules/miscmagic5.h (the
grenade.h pattern), keyed to the 35 die
bands of the engine III.E.5 table in
kMisc5 order: the (M) marks (the Robe of
the Archmagi, Robe of Eyes, Robe of
Powerlessness, Robe of Scintillating
Colors with C, Robe of Useful Items, Rug
of Welcome, Sphere of Annihilation,
Talisman of the Sphere - count 8); the
(C) marks (the Robe of Scintillating
Colors with M, the Talismans of Pure
Good and Ultimate Evil, the Tridents of
Fish Command and Warning - count 5);
the (F) marks (the Saw of Mighty Cutting,
the Spade of Colossal Excavation, the
Trident of Submission, the command/
warning Tridents - count 5); the (T)
marks (the Tridents of Fish Command and
Warning - count 2). VERIFIED: NO asterisk
rows, dual-value rows or footnotes ride
this table - the print runs straight from
the 91-00 Wings of Flying row to the
TABLE (III.E.) Special artifacts table
(a pure class-marks round, the R224 rods
shape). The row VALUES were already
pinned by the R122 line-diff audit; this
round pins the class marks and the band
edges. New R239 battery audit; census
158. Next: R240 - the III.E Special
artifacts table pins (the artifact names
and the printed g.p. sale values, the
no-x.p. convention, DMG p.130-131,
upload lines ~9917+), or the next
un-pinned III.A-H surrounding prose seam.

R240 landed the III.E Special artifacts
pins (DMG p.130-131, upload lines ~9917-
9946) - the artifact g.p. sale value
table that closes the III.E magic item
block, TABLE (III.E.) Special.: 29 rows
in kArtifacts order, the Axe of the
Dwarvish Lords 01 through the Wand of
Orcus 00 (band 100). rules/specart.h
(the grenade.h pattern): the printed
sale values (26 single-value rows,
saSaleGp); the Orb of the Dragonkind
41-47 uniform range 10-80,000 (read
10,000 through 80,000 - saSaleGpHi,
the R225 dual-value analog, count 1);
the Teeth of Dahlver-Nar 93-98 at
5,000 PER TOOTH (count 1); the Throne
of the Gods 99 prints NO sale value
(0 g.p., count 1); and the no-x.p.
convention - the table footnote reads
These items bring no experience points.
(saXpValue, all 29 rows zero). The row
NAMES were already pinned by the R122
line-diff audit; this round pins the
sale values, band edges and the value
conventions. New R240 battery audit;
census 159. Next: R241 - the III.F
armor and shield table pins (DMG
p.129-130; the armor size footnote:
65% of all armor is man-sized, 20% is
elf-sized, 10% is dwarf-sized, and but
5% gnome or halfling sized, upload
lines ~9902+), or the next un-pinned
III.A-H surrounding prose seam.

R241 landed the III.F armor and shield
pins (DMG p.129-130, upload lines
~9870-9902, the RIGHT column of the
two-column layout). rules/armorshield.h
(the grenade.h pattern, as prefix):
26 rows in kArmor order, Chain Mail +1
01-05 through Shield -1 missile
attractor 98-00 (band 100) - the x.p.
point values and the g.p. sale values
of every row (asXpValue, asSaleGp);
the TWO cursed no-x.p. rows - Plate
Mail of Vulnerability 40-44 and Shield
-1 missile attractor 98-00 print ---
(asNoXpCount 2, the R240 no-x.p.
convention on just two rows); and the
armor SIZE footnote: 65% of all armor
is man-sized, 20% elf-sized, 10%
dwarf-sized, 5% gnome or halfling
sized (asManSizedPct, asElfSizedPct,
asDwarfSizedPct, asSmallUserPct - sum
100). NO class marks, asterisks or
dual-value rows ride this table. The
row NAMES were already pinned by the
R122 line-diff audit; this round pins
the values, band edges and the size
footnote. New R241 battery audit;
census 160. Next: R242 - the III.G
swords table pins (DMG p.131; the
sword size note: 70% longswords, 20%
broadswords, 5% short swords, 4%
bastard swords, 1% two-handed; the
three cursed swords print --- g.p.
sale values, upload lines ~9917+), or
the next un-pinned III.A-H
surrounding prose seam.

R242 landed the III.G swords pins (DMG
p.131, upload lines ~9906-9947, the
RIGHT column of the two-column print).
rules/swords.h (the grenade.h pattern,
sw prefix): 26 rows in kSwords order,
Sword +1 01-25 through Sword, Cursed
Berserking 96-00 (band 100) - the x.p.
point values and g.p. sale values of
every row (swXpValue, swSaleGp); the
THREE cursed swords print --- g.p.
sale values (Sword +1 Cursed 86-90,
Sword -2 Cursed 91-95, Sword, Cursed
Berserking 96-00 - swNoSaleCount 3,
pinned as 0 g.p.); the sword SIZE
note: 70% longswords, 20% broadswords,
5% short (small) swords, 4% bastard
swords, 1% two-handed (swLongswordPct
etc., sum 100); and the TWO
tiered-bonus wrapped rows: the Flame
Tongue +2 vs. regenerating, +3 vs.
cold-using/inflammable/avian, +4 vs.
undead, the Frost Brand +6 vs. fire
using/dwelling (swFlameVsRegenBonus
etc.). NO class marks or asterisks
ride this table; the no-x.p. footnote
after it belongs to the III.E Special
table (pinned R240). The row NAMES
were already pinned by the R122
line-diff audit; this round pins the
values, band edges, the size note and
the tiered bonuses. New R242 battery
audit; census 161. Next: R243 - the
III.H misc weapons table pins (DMG
p.131-132; the quantity ranges ride
the arrow/bolt rows, upload lines
~9949+), or the next un-pinned III.A-H
surrounding prose seam.

R243 landed the III.H misc weapons pins
(DMG p.131-132, upload lines ~9949-9987)
- the miscellaneous weapons table, the
LAST of the III.A-H magic item tables.
rules/mweapons.h (the grenade.h pattern,
mw prefix): 36 rows in kWeapons order,
Arrow +1 01-08 through Trident (Military
Fork) +3 00 (band 100) - the x.p. point
values and g.p. sale values of every row
(mwXpValue, mwSaleGp); the FOUR ammo
quantity ranges printed as the N-M in
number suffixes (Arrow +1 2-24, Arrow +2
2-16, Arrow +3 2-12, Bolt +2 2-20 -
mwQtyLo/mwQtyHi, the 0/0 cells mean a
single item, mwQtyRangeCount 4); the TWO
duplicate Hammer +2 rows (57-60 at
300/2,500 and 61-62 at 650/6,000, both
printed verbatim, Curtiss-verified
against p.125 - mwDuplicateNameCount 2);
and the cursed Spear, Cursed Backbiter
98-99 prints --- x.p. (mwNoXpCount 1).
NO class marks or asterisks ride this
table. The row NAMES were already
pinned by the R122 line-diff audit; this
round pins the values, band edges and
the quantity ranges. New R243 battery
audit; census 162. MILESTONE: the whole
III.A-H magic item table block is now
fully pinned (potions, scrolls, rings,
rods/staves/wands, misc tables 1-5, the
Special artifacts, armor and shields,
swords and misc weapons). Next: R244 -
the next un-pinned III.A-H surrounding
prose seam (the EXPLANATIONS AND
DESCRIPTIONS prose that follows the
tables, upload lines ~9995+; the potions
prose was pinned R221, the scrolls prose
R222, the rings footnotes R223 - the
candidate seams are the rods/staves/
wands and misc item explanation prose),
or the next ranked gap.

R244 landed the III.D rods explanation
prose pins (DMG pp.141-142, upload
lines ~10562-10687 - the FIRST prose
round of the EXPLANATIONS AND
DESCRIPTIONS section, upload ~9996+).
rules/rodsprose.h (the grenade.h
pattern, rp prefix): the section
conventions (rods 50 charges minus
0-9/d10-1, staves 25 minus 0-5/d6-1,
wands 100 minus 0-19/d20-1 - six
accessors; the completely drained
item crumbles to powder, the
distance-discharge command-word rule,
magical silence stops the device) and
the per-item facts of the SEVEN rods:
Absorption (50 spell levels,
1-segment casting, never recharged),
Beguiling (2" radius, intelligence 1+,
no save, 1 turn per charge,
rechargeable), Cancellation (the 11-row
item saving throw table - potion 20,
scroll 19, ring 17, rod 14, staff 13,
wand 15, misc magic 12, artifact/relic
3, armor/shield 11 (8 if +5), sword 9
(7 holy), misc weapon 10; drained
items never restorable, the rod goes
brittle), Lordly Might (10 lb, 16 Str,
3 spell-like functions at 1 charge
each, fear 6", drain 2-8 hp; the 4
weapon forms +2/+1/+4/+3; the 3
mundane uses, pole to 50 ft, 4,000 lb,
doors at 30 ft, storm giant force;
never recharged), Resurrection (once
per day; the 11-class and 7-race
charge tables; multi-classed takes the
least favorable; never recharged),
Rulership (12", 200-500 hit dice, save
at intelligence 15 and 12 hit
dice/levels, 5 segments to activate,
1 turn per charge, never recharged),
Smiting (+3, 4-11 damage, 8-22 and a
20+ destroy vs golems with 1 charge
per hit, 20+ vs outer-planar draws 1
charge and triples damage, never
recharged). The seven rods are the
first seven rows of the engine III.D
table (kRods bands 01-19, the staff
rows from 20 - cross-checked against
the R224 rodswands.h bands in the
audit). New R244 battery audit;
census 163. Next: R245 - the staves
explanation prose (upload ~10688+),
then the wands (upload ~10786+); the
potions/scrolls/rings explanation prose
(upload ~9998-10561) is also still
open, as is the misc magic item
explanation prose (upload ~10949+).

R245 landed the III.D staves explanation
prose pins (DMG pp.142-143, upload
lines ~10688-10785 - the second prose
round of the EXPLANATIONS AND
DESCRIPTIONS section). rules/
stavesprose.h (the grenade.h pattern,
stf prefix, 76 accessors): the staff
conventions (8th level of magic-use,
2 segments to discharge and 8 to build
up again, nominal damage 8d6) and the
SEVEN staves - Command (3 functions,
2 for a magic-user; 1 charge per
suggestion/charm, 1 per turn of
control, 1 per 1" square of plants
per turn; rechargeable), Curing (4
functions, cure wounds 6-21 hp =
3d6+3, 1 charge each, once per person
per day, max twice per function, 8
uses per 24 hours, rechargeable), the
Magi (5 free powers, 10 at 1 charge,
4 at 2 charges; elementals 8 hit dice,
telekinesis 200 lb, +2 saves,
absorption the only recharge), Power
(6 one-charge and 3 two-charge powers;
+2 AC and saves, smite +2 3-8 hp, 1
charge doubles but 2 do not triple;
paralyzation cone 4" long 2" wide;
rechargeable), the Serpent (python +2
3-8 hp, snake 25 ft AC 3 49 hp 9"
move, constriction 4-10 hp per round;
adder +1 2-4 hp, head AC 5 20 hp 1
turn, save versus poison or die; no
charges, 60% pythons), Striking (+3,
4-9 = d6+3, bonuses 3/6/9 at 1/2/3
charges, max 3 per strike,
rechargeable), Withering (+1, 2-5 hp,
2 charges age 10 years, 3 wither a
limb unless saved, ageless immune; NO
recharge statement printed - unpinned).
The retributive strike pins: globe 3"
radius, damage 8/6/4 times the spell
levels (1-25) by distance band, save
for half, 50% plane travel for the
breaker, 2 items capable (the magi and
the power). The seven staves are the
engine kRods rows 8-14, bands 20-33,
the wand rows from 34 (cross-checked
against the R224 rodswands.h bands in
the audit). New R245 battery audit;
census 164. Next: R246 - the wands
explanation prose (upload
~10786-10948, incl. the wand of
wonder effect table), then the
potions/scrolls/rings explanation
prose (upload ~9998-10561) and the
misc magic item explanations
(~10949+).

R246 landed the III.D wands
explanation prose pins, part 1 of 3
(DMG pp.143-144, upload lines
~10786-10826). rules/wandsprose.h
(the grenade.h pattern, wd prefix,
65 scalar accessors - no arrays
this round): the section
conventions (wands perform at 6th
level of experience; at DM option
1% of all wands are trapped to
backfire) and the FIRST FIVE
wands - Conjuration (11 recognized
conjuration/summoning spells counted
from print; monster summoning max
6 charges at 1 per level, 5
segments; curtain of blackness 600
sq ft at 2 charges; prismatic
sphere 1 charge per color; each
function 5 segments, 1 per round;
rechargeable), Enemy Detection (6"
sphere, 1 charge per turn,
rechargeable), Fear (cone 6" x 2",
1 segment, flee 6 rounds, 1 charge
per use, once per round,
rechargeable), Fire (4 functions:
burning hands 10 ft wide 12 ft long
6 hp 1 segment 1 charge;
pyrotechnics 2 segments 1 charge;
fireball range 16", 2 segments, 2
charges, 6 dice with 1s counted as
2s = 12-36 hp; wall of fire 12
square", 6 rounds, 8-18 hp touched
(2d6+6), 2-8 within 1", 1-4 within
2", ring circle 2.25 inch diameter
- pinned as 9 quarter-inches; once
per round, rechargeable), and Frost
(3 functions: ice storm 6"
distant, 1 segment, 1 charge; wall
of ice 6 inches thick, 6" square
area, 2 segments, 1 charge; cone of
cold 6" long 2" terminal diameter,
2 segments, c. -100 F, 6 dice
12-36, 2 charges; once per round,
rechargeable). The five wands are
the engine kRods wand rows 1-5,
bands 34-47, illumination from 48
(cross-checked against the R224
rodswands.h bands in the audit).
New R246 battery audit; census 165.
Next: R247 - the remaining ten
wands (upload ~10828-10865:
Illumination, Illusion, Lightning,
Magic Detection, Metal and Mineral
Detection, Magic Missiles,
Negation, Paralyzation,
Polymorphing, Secret Door and Trap
Location), then R248 the wand of
wonder effect table (upload
~10867-10947). The potions/
scrolls/rings explanation prose
(upload ~9998-10561) and the misc
magic item explanations (~10949+)
remain open after that.

R247 landed the III.D wands
explanation prose pins, part 2 of 3
(DMG pp.144-145, upload lines
~10828-10865). rules/wandsprose2.h
(the grenade.h pattern, wd prefix,
73 scalar accessors - no arrays
this round): the remaining TEN
wands - Illumination (4 functions:
dancing lights 1 segment 1 charge;
light 2 segments 1 charge;
continual light 2 segments 2
charges; sunburst 12" range,
duration 1/10 of a second (pinned
as 1 tenth), 4" globe, undead
6-36 hp no save, others blinded
2-12 segments, 3 segments 3
charges; rechargeable), Illusion
(14" range, 3 segments, 1 charge to
effect and 1 per round to
continue, rechargeable), Lightning
(2 functions: shock 1-10 hp no
save, metallic armor and shield
discounted AC 10, 1 charge; bolt
12-36 hp 6d6 with 1s counted as
2s, 2 charges 2 segments; 1
function per round, rechargeable),
Magic Detection (3" radius, 1
round, 1 charge per turn or
fraction, 2% cumulative chance per
round of malfunction,
rechargeable), Metal and Mineral
Detection (3" radius, 1 round,
1 charge per full turn,
rechargeable), Magic Missiles (2-5
hp, 3 segments, 1 charge, max 2
per round, rechargeable), Negation
(100% any wand function, 75% other
devices, 1 segment, once per
round, 1 charge; the one wand
that cannot be recharged),
Paralyzation (ray 6", 5-20 rounds,
3 segments, 1 charge, once per
round, rechargeable), Polymorphing
(ray 6", 3 segments, 1 charge,
1 function per round,
rechargeable), and Secret Door and
Trap Location (radius 1.5 inch for
secret doors - pinned as 3
half-inches, the first half-inch
pin since the 2.25 inch
quarter-inch of R246 - and 3" for
traps, 1 round, 1 charge,
rechargeable). The ten wands are
the engine kRods wand rows 6-15,
bands 48-94, the wand of wonder
from 95 (cross-checked against the
R224 rodswands.h bands in the
audit). New R247 battery audit;
census 166. Next: R248 - the wand
of wonder effect table (upload
~10867-10947, 19 bands). The
potions/scrolls/rings explanation
prose (upload ~9998-10561) and
the misc magic item explanations
(~10949+) remain open after that.

R248 landed the III.D wand of wonder
effect table pins (DMG p.145, upload
lines ~10867-10947) - the round that
CLOSES the III.D wands arc (rods
R244, staves R245, wands R246-R247,
wonder R248). rules/wonder.h (the
grenade.h pattern, wonder prefix, 42
accessors - the 19-band table plus
39 scalar effect facts, the first
array header since R224): the bands
tile 01-100 with no gaps or overlaps
- 01-10 slow creature 1 turn, 11-18
delude wielder 1 round (a second die
roll), 19-25 gust of wind double
force, 26-30 stinking cloud 3" range,
31-33 heavy rain 1 round 6" radius,
34-36 summon rhino 1-25 elephant
26-50 mouse 51-00, 37-46 lightning
bolt 7" x 0.5" as wand (the width
pinned as 1 half-inch, continuing the
R247 half-inch workaround), 47-49
600 large butterflies 2 rounds
blinding everyone including the
wielder, 50-53 enlarge within 6",
54-58 darkness 3" diameter
hemisphere at 3" center distance,
59-62 grass 16" square or 10 times
normal size, 63-65 vanish non-living
up to 1,000 pounds and 30 cubic
feet, 66-69 diminish wielder to 1"
height, 70-79 fireball as wand,
80-84 invisibility covers the
wielder, 85-87 leaves grow within
6", 88-90 10-40 gems of 1 g.p. base
value in a 3" stream each 1 h.p.
with 5d4 for the number of hits
(note: 5d4 gives 5-20 hits, not
10-40 - the gem count and the hit
roll are separate facts), 91-97
shimmering colors 4" x 3" blinded
1-6 rounds, 98-00 flesh to stone or
reverse within 6". The wand uses 1
charge per function and may not be
recharged. The wonder is the engine
kRods row 30, bands 95-100
(cross-checked against the R224
rodswands.h pins in the audit). New
R248 battery audit; census 167. The
III.D explanation prose is now fully
pinned. The remaining open seams:
the potions/scrolls/rings explanation
prose (upload ~9998-10561) and the
misc magic item explanations
(~10949+).

R249 landed the III.A potions
explanation prose pins, part 1 of 3
(DMG pp.133-134, upload lines
~9998-10062) - the sixth prose arc
of the EXPLANATIONS section, the
first after the III.D arc closed at
R248. The TREASURE (POTIONS) etc.
headings inside this seam are the
book running page headers, not
tables - the III.A/B/C tables were
pinned by R122/R221-R224 long ago.
rules/potionsprose.h (the grenade.h
pattern, pot prefix - distinct from
the R221 potion prefix - 56
accessors, of which 5 are array
walkers for the animal/dragon type
sub-tables and the climbing armor
table): the conventions (duration 4
turns plus 1-4 more on d4; onset
2-5 segments) and the first NINE
potions - Animal Control (5-20
rat-size, 3-12 man-size, 1-4
half-ton-plus; save at intelligence
5+; the 7-row d20 type sub-table
tiling 1-20), Clairaudience (3", 2
turns), Clairvoyance (3", 1 turn),
Climbing (base 1% slip, 01 falls at
the halfway d% check, 1 turn +
5-20 rounds, +1% per 1,000 g.p.;
armor rows studded leather 1, ring
mail 2, scale mail 4, chainmail 7,
banded/splinted 8, plate 10, magic
armor 1), Delusion (90% tasters
agree), Diminution (5% size, 50% on
half dose, 6 turns + 2-5 d4+1),
Dragon Control (charm within 6",
save -2; the 12-row d20 type
sub-table white 1-2 through good
20, tiling 1-20; 5-20 5d4 rounds),
ESP (5-40 5d8 rounds), and
Extra-Healing (6-27 3d8+3 whole,
1-8 per third). The nine potions
are the engine kPotions rows 1-9,
bands 01-26, fire resistance from
27 (cross-checked against the R221
potions.h pins in the audit). New
R249 battery audit; census 168.
Next: R250 - potions part 2 (Fire
Resistance through Invisibility,
upload ~10063-10128), R251 -
potions part 3 (Invulnerability
through Water Breathing, upload
~10129-10189), then the scrolls
explanations (upload ~10191-10280)
and the rings explanations (upload
~10282-10561), then the misc magic
item explanations (~10949+).

R250 landed the III.A potions
explanation prose pins, part 2 of 3
(DMG pp.134-136, upload lines
~10063-10128) - potions 10 through
19 of the EXPLANATIONS section.
rules/potionsprose2.h (the
wandsprose2.h part-2 pattern, the
pot prefix continues - 53 accessors,
of which 15 are array walkers):
Fire Resistance (damage -2 per die,
saves +4; half dose -1 and +2; 1
turn or 5 rounds), Flying (as the fly
spell, 3rd level magic-user),
Gaseous Form (base speed 3" per
round, whirlwind double damage),
Giant Control (1-2 giants, save -4
if 1 / +2 if 2; the 6-row d20 giant
type sub-table hill 1-5 through
storm 20, tiling 1-20; 5-30 5d6
rounds), Giant Strength (the 6-row
die table: weight allowances
4500-12000, damage bonuses +7
through +12, rock base ranges
8/16/10/12/14/16 inches, rock
damage 1-6/1-12/1-8/1-8/1-10/1-12,
bend bars/lift gates 50-100 percent
- the upload table is cell-mangled
and the ground truth parses it row
by row), Growth (6 feet per quarter,
24 feet full), Healing (4-10 2d4+2),
Heroism (below 10 levels; the 3-row
consumer table - energy levels 3/2/1
for 1st-3rd/4th-6th/7th-9th,
accumulated damage 3+1/2+2/1+3 on
d10; the stray 04 4 upload row is
paste noise and is skipped), Human
Control (up to 32 levels/hit dice;
the 8-row d20 type table dwarves 1-2
through the mixed 20 row, the 20 row
band and name in separate pipe
cells; 5-30 rounds), and Invisibility
(a gulp is 1/8 of the contents, 3-6
turns). The ten potions are the
engine kPotions rows 10-19, bands
27-54, invulnerability from 55
(cross-checked band by band against
the R221 potions.h pins in the
audit). New R250 battery audit;
census 169. Next: R251 - potions
part 3 (Invulnerability through
Water Breathing, upload ~10129-10189),
then the scrolls explanations (upload
~10191-10280) and the rings
explanations (upload ~10282-10561),
then the misc magic item
explanations (~10949+).

R251 landed the III.A potions
explanation prose pins, part 3 of 3
(DMG pp.136-137, upload lines
~10129-10189) - the final sixteen
potions, Invulnerability through
Water Breathing. THIS CLOSES THE
III.A POTIONS ARC END TO END (the
R249 conventions through the R251
final row, engine bands 01-100).
rules/potionsprose3.h (the part-3
pattern, the pot prefix continues -
69 accessors, of which 5 are array
walkers): Invulnerability (fewer
than 4 hit dice cannot harm, armor
class +2 classes, saves +2, 5-20
rounds), Levitation (second level
spell, 6,000 g.p. maximum),
Longevity (1-12 years, 1% cumulative
reversal), Oil of Etherealness (3
rounds onset, 4 + 1-4 turns), Oil
of Slipperiness (95% per round
floor slip, 8 hours), Philter of
Love (charm 4 + 1-4 turns), Philter
of Persuasiveness (+25% reaction
dice, suggest once per turn within
3"), Plant Control (intelligence 5+
save, 2" x 2" square, range 9",
5-20 rounds), Poison (weak +1/+4,
deadly -1/-4 or more, neutralize
40%), Polymorph self (fourth level
spell), Speed (+100%, 9" becomes
18", ages 1 year, 5-20 rounds),
Super-Heroism (below 13 levels; the
4-row consumer table - energy
levels 5/4/3/2, accumulated damage
4+1/3+2/2+3/1+4 on d10; 5-30 melee
rounds; the stray 06 5 upload row
is paste noise and is skipped),
Sweet Water (100,000 cubic feet
water, 1,000 acid, initial period
5-20 rounds), Treasure Finding
(within 24", 10,000 copper or 100
gems, 5-20 rounds), Undead Control
(16 hit dice, saves -2, 5-20
rounds; the 10-row d10 undead type
table ghasts through zombies, the
printed 0 row pinned as the 10
face; the upload table is
cell-mangled - the band digit and
the name share a cell with no
space on some rows), and Water
Breathing (75% two doses, 25% four,
one hour per dose plus 1-10
rounds). The TREASURE (POTIONS)
running page header splits the Oil
of Slipperiness paragraph mid-
sentence (upload ~10138) - stripped
by the ground truth, per the R249
page-header lesson. The sixteen
potions are the engine kPotions
rows 20-35, bands 55-100, closing
the table at 100 (cross-checked band
by band against the R221 potions.h
pins in the audit). New R251
battery audit; census 170. Next:
the scrolls explanations (upload
~10191-10280), then the rings
explanations (upload ~10282-10561),
then the misc magic item
explanations III.E (part1 ~10948-
11067 continuing seamlessly into
part2; global line = part1 line or
~11065 + part2 line, the TREASURE
(MISCELLANEOUS MAGIC) headers are
running page headers mid-paragraph).

R252 landed the III.B scrolls
explanation prose pins (DMG
pp.137-139, upload lines
~10191-10280) - the second
EXPLANATIONS arc opens: the general
scroll mechanics and the EIGHT
protection scrolls. rules/
scrollsprose.h (the grenade.h
pattern, the scp prefix - distinct
from the R222 scroll prefix - 88
accessors, of which 7 are array
walkers): the class table (01-70
magic-user then 01-10 illusionist,
71-00 cleric then 01-25 druid -
matching the engine 30% clerical
of which 25% druidical and 10%
illusionist flavor note), unread
scrolls 5-30% likely to fade
(d6 option), scroll spells written
1 level above usable level never
below 6th (sixth at 13th, seventh
at 15th), the scroll fireball 6
dice 6d6, spell failure 5% per
level difference (the wish example
18 - 1 = 17 x 5% = 85%), the
6-row level-difference table
(total failure 95/85/75/65/50/30,
reverse-or-harmful 5/15/25/35/50/
70), the scroll of 7 spells reducing
to 6 on a read, and the eight
protection scrolls: Demons (1 full
round / 7 segments type VI / 3
segments type III, 10 foot radius,
5-20 5d4 rounds), Devils (1 round /
7 greater / 3 lesser), Elementals
(6 segments, the 5-variety table
air 01-15 through all 61-00, 10
foot radius, 24 hit dice specific
16 all, 5-40 5d8 rounds),
Lycanthropes (4 segments, the
7-type table werebears 01-05
through shape-changers 99-00, 10
foot radius, 49 hit dice, pluses
rounded down unless they exceed
+2, 5-30 rounds), Magic (8
segments, 5 foot radius, 50% drain
save 11 or better on d20, 5-30 5d6
rounds), Petrification (5 segments,
10 foot radius, 5-20 5d4 rounds),
Possession (1 round, 10 foot
radius, 10-60 rounds in 90% of
scrolls, 10% have 10-60 turns but
stationary), and Undead (4
segments, 5 foot radius, 10 undead
types cross-pinned against the
R251 potUndeadTypeRowCount - the
prose Cf. sanctions it - 35 hit
dice/levels, 10-80 10d8 rounds).
The eight scrolls are the engine
III.B table rows 61-97 (rollScroll,
the R222 scrollpins.h pins) -
cross-checked band by band in the
audit. The TREASURE (SCROLLS) and
TREASURE (RINGS) running page
headers are stripped by the ground
truth - the RINGS header splits the
Possession paragraph mid-sentence
(upload ~10277), per the R249
page-header lesson. New R252
battery audit; census 171. Next:
the rings explanations (upload
~10282-10561, likely 3 parts),
then the misc magic item
explanations III.E (part1 ~10948-
11067 continuing seamlessly into
part2; global line = part1 line or
~11065 + part2 line, the TREASURE
(MISCELLANEOUS MAGIC) headers are
running page headers mid-paragraph).

R253 landed the III.C rings
explanation prose part 1 of 3
(DMG pp.137-138, upload lines
~10281-10392) - the general ring
mechanics and the four lead
rings: Contrariness, Delusion,
Djinni Summoning, Elemental
Command. rules/ringsprose.h (the
grenade.h pattern, the rgp
prefix - distinct from the R223
ring prefix - 47 accessors, of
which 3 are array walkers): max
2 rings worn (none function if
more), 1 per hand, 12th level of
magic use, 20% malfunction for
gnomes/dwarves/halflings, the 3
cursed rings named (contrariness,
delusion, weakness), the
double-dagger charge note;
Contrariness (the 6-band
additional-properties table
01-20 Flying through 81-00
Strength 18/00, shocking grasp
once per round, cumulative remove
curse 00 = 100%); Delusion
(removable at any time); Djinni
Summoning (the djinni appears
the next round, a killed servant
makes the ring worthless);
Elemental Command (4 types,
elementals kept 5 feet away,
charm attempt save -2, plane
creatures attack at -1, wearer
damage -1 per hit die, wearer
saves +2, wearer attacks +4 or
elemental saves -4, wearer
damage +6 total, the 4-plane save
penalty list all -2, only one
power at a time, the four power
lists - Air 5, Earth 6, Fire 5,
Water 8 - with the once/twice
per round/turn/day/week
frequencies, water breathing 5
foot radius, the four lesser-ring
disguises, additional powers 5
segments). Engine cross-check:
the four kRings rows 1-15 vs the
R223 rings.h band edges, djinni
double-dagger vs
ringIsChargeLimited row 2. The
TREASURE (RINGS) running page
header splits the Earth power
list mid-list (upload ~10369),
stripped by the ground truth per
the R249 page-header lesson; the
plane anchors mix hyphen and em
dashes. New R253 battery audit;
census 172. Next: part 2 (upload
~10393-10457, Feather Falling
through Shooting Stars), then
part 3 (~10458-10561, Spell
Storing through X-Ray Vision),
then the misc magic item
explanations III.E (part1
~10948-11067 continuing
seamlessly into part2; global
line = part1 line or ~11065 +
part2 line, the TREASURE
(MISCELLANEOUS MAGIC) headers
are running page headers
mid-paragraph).

R254 landed the III.C rings
explanation prose part 2 of 3
(DMG pp.138-139, upload lines
~10393-10457) - Feather Falling
through Shooting Stars.
rules/ringsprose2.h (the rgp
prefix, part 2 - 67 accessors,
of which 6 are array walkers):
Feather Falling (5 feet),
Fire Resistance (immune normal
fires; very hot 10 per round /
1 per segment; exceptionally
hot saves +4, -2 per die floor
1; the 24 hp / 25+ rule of
thumb), Free Action (web hold
slow, underwater, no water
breathing), Human Influence
(charisma 18, 21 levels, once
per day, 3 segments,
double-dagger), Invisibility
(10% also inaudible), Mammal
Control (intelligence 4 or
less, 30 hit dice, 3 segments,
double-dagger), Multiple
Wishes (2-8 2d4,
double-dagger), Protection
(the 7-row value table 01-70
+1 through 98-00 +6 AC +1
saves, rows 83 and 91 the 5
foot radius saves-only, NO
double-dagger), Regeneration
(2 forms, 1 hp per turn,
vampiric one-half, 01-90 /
91-00), Shooting Stars (2
modes; dancing lights once per
hour, light twice per night 12
range, ball lightning once per
night - 1 to 4 balls, 12
range, 4 rounds, 4 per round
move, 3 foot diameter, the 4
charge tiers 4/3/2/1 balls; 3
stars per week, 12 impact +
24 burst in a 1 diameter
sphere, 7 range, saves -3
within 2 / -1 within 2 to 4;
indoors faerie fire twice per
day, spark shower once per day
- 20 feet to 10 feet breadth,
2-8 no metal / 4-16 metal;
casting 5 segments). ENGINE
CROSS-CHECK: the ten kRings
rows 16-63 vs the R223 rings.h
band edges; dagger cross-pins
Human Influence and Multiple
Wishes. DIVERGENCE FOUND BY
THE GROUND TRUTH BEFORE ANY
PIN (the ranked fix candidate,
RESOLVED by R255):
the R223 rings.h
ringIsChargeLimited array flags
Protection (row 11) and NOT
Mammal Control (row 9), while
the R223 comment names Mammal
Control and the prose carries
the double-dagger on Mammal
Control but not Protection -
the R223 audit kChg pins the
wrong array too; the fix round
must swap rows 9 and 11 in
rings.h and in the R223 audit
kChg + its per-index asserts.
The R254 audit deliberately
does NOT assert the divergent
rows. The TREASURE (RINGS)
header at ~10432 splits the
ball lightning paragraph
mid-sentence (stripped, the
R249 lesson); the upload drops
the ball lightning charge die
bands (only the 4/3/2/1 ball
counts survive). New R254
battery audit; census 173.
Next: R255 the
ringIsChargeLimited fix round
(rings.h + the R223 audit
amendment), then part 3
(~10458-10561, Spell Storing
through X-Ray Vision), then
III.E (part1 ~10948-11067
continuing seamlessly into
part2; global line = part1
line or ~11065 + part2 line,
the TREASURE (MISCELLANEOUS
MAGIC) headers are running
page headers mid-paragraph).

R255 landed the
ringIsChargeLimited fix (the
R223 divergence resolved -
DMG p.137 table, upload
~9590-9617: the double-
dagger rows are Djinni
Summoning, Human Influence,
MAMMAL CONTROL, Multiple
Wishes, Telekinesis, Three
Wishes, Wizardry; the
landed array wrongly flagged
Protection row 11 instead of
Mammal Control row 9). Fixed
in rings.h ringIsChargeLimited
(row 9 0->1, row 11 1->0,
count stays 7); the R223
regtest audit (kChg array
swapped; the truthy assert
list now 2/7/9/10/17/18/22;
the negative list gains 11);
the R254 audit NOTE (its
cross-pin if now asserts
rows 9 and 11 directly); the
ringsprose2.h divergence
comments (header banner,
Mammal Control dagger flag,
Protection dagger flag) now
record the resolution; this
gap note flipped. Five
content files with the
splice. No new audit line;
census stays 173. Next: R256
- rings part 3 (~10458-10561:
Spell Storing d4+1 and the
level table, Spell Turning (3
exceptions, the percentile
tables, the 09-or-less/
91-or-more save note),
Swimming (21 inch base, 50
foot dive, 4 rounds),
Telekinesis (the weight
table), Three Wishes (25%
limited), Warmth (+2 saves,
-1 per die), Water Walking,
Weakness (1 point per turn
to 3, the invisible doubling,
5% berserk reversal), Wizardry
(the doubling table), X-Ray
Vision (20 feet, the
penetration depths)), then
III.E (part1 ~10948-11067
continuing seamlessly into
part2; global line = part1
line or ~11065 + part2 line,
the TREASURE (MISCELLANEOUS
MAGIC) headers are running
page headers mid-paragraph).

R256 landed the III.C rings
explanation prose part 3 of 3
(DMG pp.139-140, upload lines
~10458-10561) - Spell Storing
through X-Ray Vision.
rules/ringsprose3.h (the rgp
prefix, part 3 - 89 accessors:
78 scalars + 11 array walkers):
Spell Storing (2-5 d4+1, the
cleric d6-to-d4 and
magic-user d8-to-d6 level
tables, druid and illusionist
as cleric, the 12th level MU
restore example, 5 segments),
Spell Turning (3 exceptions,
the scroll-is-not-a-device
note, percentile rounding
1-5 down 6-9 up, 05 = 0% and
96 = 100%, saves +1 per 10%
below 100%, the 09-or-less /
91-or-more special save band,
5% per 10% turned, the maze
example 34% / 15% / 30% on
15-20, the 4-row resonating
field table, remove to
receive, psionics are not
spell casting), Swimming (21
inch base, 50 foot dive, 1.5
feet depth per 10 feet, 4
rounds breath, 4 hours + 1
hour rest), Telekinesis (the
5-row weight table 250 to
4000 gp, 1 segment,
double-dagger), Three Wishes
(3 wishes, 25% limited,
double-dagger), Warmth (1 hp
per turn, +2 saves, -1 per
die), Water Walking (1200
pounds, the 1.5 foot by 1
inch per 100 pounds
depressions), Weakness (1
point per turn to 3, the
invisible doubling, remove
curse + dispel magic, the 5%
berserk reversal to 18s),
Wizardry (the 8-row doubling
table, MU-only +
double-dagger), X-Ray Vision
(20 feet, the 5-substance
penetration table, 100 sq ft
per round, 90% secret doors,
the 6-turn constitution drain
2 points at 3 turns per hour,
2 points recovery per day,
exhausted at 2, resume at 3).
ENGINE CROSS-CHECK: kRings
rows 64-100 vs the R223 band
pins; dagger cross-pins
Telekinesis / Three Wishes /
Wizardry against the
R255-FIXED charge array;
Weakness and X-Ray correctly
unflagged. Upload notes: the
TREASURE (RINGS) page header
at 10531 splits the Water
Walking paragraph
mid-sentence (stripped, the
R249 lesson); the Spell
Turning damage example table
is mangled in the upload
(only fragment lines 2-8 /
2-12 / 5-20 / 4-48 survive)
- the rounding facts are
pinned, the dropped table is
not. New R256 battery audit;
census 174. Next: III.E misc
magic explanations (part1
~10948-11067 continuing
seamlessly into part2; global
line = part1 line or ~11065 +
part2 line, the TREASURE
(MISCELLANEOUS MAGIC) headers
are running page headers
mid-paragraph).

R257 landed the III.E misc
magic explanation prose part 1
(part1 10949-11065 stitched
into part2 at line 3 - the
FIRST TWO-PART-FILE round).
rules/miscprose1.h (the mmp
prefix, 65 accessors: 60
scalars + 5 array walkers):
the section intro (not more
than 2 or 3 duplicates; books:
a second wish for exact
contents), Alchemy Jug (11
liquids - 16 gallons salt water
down to 4 drams cyanide; 1 kind
and 7 pourings per day; 2
gallons per round, 8 rounds for
the salt water), Amulet of
Inescapable Location (DOUBLES
likelihood and range - the
cursed lure), Amulet of Life
Protection (7 full days),
Amulet of the Planes (d6: 1-3
no add, 4-6 add 12 to d12; the
17-row plane table 1-2 through
21-24; the alternates 22
Ethereal / 23 Astral / 24
alternate Earth), Amulet of
Proof (no aura), Apparatus of
Kwalish (10 levers, 3 forward 6
backward, pincers 4 feet 2-12
damage at 25%, 900 feet depth,
2 occupants, 2-5 hours air,
AC 0, 100 leak 200 stave),
Arrow of Direction (once per
day, 7 times in 7 turns, 5
request kinds), Bag of Beans
(5-20 explosion in 10 feet,
3-12 optimum, 1-2 beneficial,
the 7-row bean table: 5-20
berries of 100/500 gp gems, 50
feet 5 turn smoke blinding 1-6
rounds, 20 feet 1 turn gas),
Bag of Devouring (90% ignore,
60% close, base 75% less 5% per
+1, the 18/65% and 5/80%
examples, 30 cubic feet, acts
as bag of holding normal
capacity, the 5% cumulative per
turn swallow - THE SEAM FACT
from part2 line 3 - creatures
consumed in 7 segments). THE
SEAM PINNED EXACTLY: part1 has
11067 lines, last content line
11065 ends IT HAS A 5%; part2
line 1 is the page header,
line 3 completes the sentence;
the stitched sentence carries
each turn it has a 5%
cumulative chance of; global
line = part1 line or 11065 +
part2 line. ENGINE CROSS-
CHECK: kMisc1 rows 0-6 (Alchemy
Jug 1-2 through Arrow of
Direction 14-16), row 8 Bag of
Beans 18-20, row 9 Bag of
Devouring 21 against the
R225 m1 band pins. The TABLE
(III.E.) 1. header at 10962
is a running page header,
stripped (the R249 lesson).
New R257 battery audit; census
175. Next: part 2 - Bag of
Holding onward in part2 (line
5 onward; global = 11065 +
part2 line), through the end
of the III.E explanations.

R258 landed the III.E misc
magic explanation prose part 2
(part2 lines 5-66; global =
11065 + part2 line; no page
headers inside the slice).
rules/miscprose2.h (the mmp
prefix again, 83 accessors: 74
scalars + 9 array walkers): Bag
of Holding (the 4-row quality
table 01-30 15/250/30 through
91-00 60/1500/250; overload or
sharp pierce ruptures, contents
lost in nilspace), Bag of
Transmuting (one of the 4
quality types, 2-5 proper uses,
metals and gems to no worth,
magic items to lead/glass/wood
no save), Bag of Tricks (toss
1-20 feet; d10 type bands 1-5,
6-8, 9-0; 8 animals each; only
the bands and counts are
pinned - the animal stat
columns are mangled in the
upload, the R256 lesson; 1
drawn at a time, slain or 1
turn then ordered back, 10 per
week), Beaker of Plentiful
Potions (2-5 doses of 2-5
potions, d4+1 count, 1 round
pours of 1 dose, delusion and
poison possible, 2: 1/day
3/week, 3: 1/day 2/week, 4-5:
1/week, 1 type lost per month),
Boat, Folding (box 12/6/6
inches; boat 10x4x2 with 1 pair
of oars, holds 3-4; ship 24x8x6
with 5 oar sets, carries 15; 3
command words), Book of
Exalted Deeds (1 week perusal,
+1 wisdom halfway XP, neutral
20,000-80,000, evil -1 level +
50% for 2-5 adventures, MU -1
int or 2,000-20,000, thief 5-30
hp -1 dex 10-60% convert at
wisdom 15, assassin 5-40 hp,
vanishes after perusal). ENGINE
CROSS-CHECK: kMisc1 rows 10-15
(Holding 22-26, Transmuting 27,
Tricks 28-29, Beaker 30-31,
Boat 32, Exalted 33) plus the
Exalted (C) class mark at row
15 (Boat row 14 as the
negative control) against the
R225 m1 pins. New R258 battery
audit; census 176. Next: part 3
- Book of Infinite Spells onward
in part2 from line 67 (global =
11065 + part2 line; the TREASURE
page header at line 70 splits
its page table).

R259 landed the III.E misc
magic explanation prose part 3
(part2 lines 67-108; global =
11065 + part2 line). TWO page
headers inside the slice, both
stripped (the R249 lesson): line
70 splits the page table from
the Book of Infinite Spells
intro, line 102 splits the Boots
of Levitation paragraph
mid-sentence - the seam pinned
exactly (line 100 ends the
ascent/descent speed phrase,
line 104 continues ROUND
(MINUTE); the stray table-title
line 83 is a duplicated header,
noted not pinned).
rules/miscprose3.h (the mmp
prefix again, 76 accessors: 73
scalars + 3 array walkers): Book
of Infinite Spells (5-20 hp,
5-20 turns stunned on first
read; 23-30 = 22 + d8 pages; the
5-row page table; d10 level die,
d12 for magic-user, 8-10 / 10-12
reroll to d6 / d8; 1 cast per
day, 4 if already castable; the
10/20/25/30 page-turn ladder;
vanishes at the last page), Book
of Vile Darkness (1 week, +1
wisdom halfway XP; neutral
30,000-120,000 or turn evil, 50%
either; good clerics 2 saves then
250,000 less 10,000 per wisdom;
other good 5-30 hp with 80% night
hag; neutral 5-20 hp), Boots of
Dancing (the other 4 useful types
until melee or fleeing, AC
penalty 4, remove curse only),
Boots of Elvenkind (95% worst,
100% best), Boots of Levitation
(20 inches per round; d20 in 14
pound increments over 280 base,
294 to 560), Boots of Speed (24
inch base, 1 inch per 10 pounds
over 200, the 180/60 example at
20, the 500 coin sack at 5, 1
rest hour per move hour, 8 hours
max, AC +2), Boots of Striding
and Springing (12 inch base, 12
hours + 12 recharge; 3 foot
paces, 30/9/15 jumps; 20% stumble
less 3% per dex above 12, the
17/14/11/8/5/2 ladder; AC +1).
ENGINE CROSS-CHECK: kMisc1 rows
16-22 (Infinite 34, Vile 35,
Dancing 36, Elvenkind 37-42,
Levitation 43-47, Speed 48-51,
Striding 52-55) plus the Vile
(C) class mark at row 17
(Infinite row 16 as the
negative control) against the
R225 m1 pins. New R259 battery
audit; census 177. Next: part 4
- Bowl Commanding Water
Elementals onward in part2 from
line 110 (global = 11065 +
part2 line).

R260 landed the III.E misc
magic explanation prose part
4 (part2 lines 110-153;
global = 11065 + part2
line), Bowl Commanding Water
Elementals through Bucknard
Everfull Purse - completing
the kMisc1 table rows
23-32. ONE page header
inside the slice, stripped
(the R249 lesson): line 127
splits the Bracers of
Defense AC table from
Bracers of Defenselessness -
no mid-sentence seam this
time. rules/miscprose4.h
(the mmp prefix again, 53
accessors: 48 scalars + 5
array walkers, no name
collisions with parts 1-3):
Bowl Commanding Water
Elementals (12 HD; words 1
round; fresh or salt; salt
+2 per die, max 8 hp per
die), Bowl of Watery Death
(save versus magic or shrunk
to ant size; salt save at
minus 2; drowns in 3-8
rounds; freed only by animal
growth, enlarge or wish;
growth potion the same;
sweet water another save;
death permanent, even wish
fails), Bracers of Defense
(the 7-row AC table 01-05:8
through 86-00:2; useless
with armor, stack with
other protections), Bracers
of Defenselessness (serves
until attacked in anger by
a dangerous enemy; AC 10,
negates all protections and
dex bonuses; remove curse
only), Brazier Commanding
Fire Elementals (12 HD; fire
lit 1 round; sulphur +1 per
die, 2-9 hp per die),
Brazier of Sleep Smoke (1
inch radius cloud; save or
deep sleep; a 12 HD fire
elemental attacks the
nearest creature; dispel
magic or remove curse
awakens), Brooch of
Shielding (90% without gems;
absorbs 101 hp of magic
missile damage, then melts),
Broom of Animated Attack
(loop-the-loop dumps the
rider 6-9 feet; attacks
twice per round as a 4 HD
monster; straw end blinds 1
round; handle 1-3 damage;
AC 7, 18 hp to destroy),
Broom of Flying (30 inch
speed; 182 pounds; 14 pounds
per 1 inch slow; 30 degree
climb or dive; fetches at 30
inches), Bucknard Everfull
Purse (26 coins per type the
next morning; the 3 type
bands 01-50 / 51-90 /
91-00; emptied kills the
magic; gems base 10 gp, max
100 gp; abilities never
change; the spice design
note - the mangled coin
columns noted not pinned,
the R256 lesson). ENGINE
CROSS-CHECK: kMisc1 rows
23-32 (Bowl Cmd 56-58,
Watery 59, Bracers 60-79,
Defenseless 80-81, Brazier
Fire 82-84, Sleep Smoke 85,
Brooch 86-92, Broom Attack
93, Broom Fly 94-98, Purse
99-00) plus the (M) class
marks on the two Bowls and
two Braziers against the
R225 m1 pins. FIX: the R225
per-AC asterisk off-by-one
- m1IsPerAcPointValued
flagged row 26 (80-81
Defenselessness) but the
printed asterisk row is
60-79 Bracers of Defense
(row 25); the flag, the
R225 audit kBrac table and
its direct assertions now
mark row 25, and the R260
audit pins the printed AC 6
example (2000 xp / 12000
gp, four points above 10).
New R260 battery audit;
census 178. Next: part 5 -
Candle of Invocation onward
in part2 from line 155
(global 11220; the TABLE
(III.E.) 2. header at 155
and the TREASURE header at
159 both strip; the Candle
seam: line 157 ends one of
the, line 161 continues
nine alignments).

R261 landed the III.E misc
magic explanation prose part
5 (part2 lines 155-220;
global = 11065 + part2
line), Candle of Invocation
through Cloak of Protection -
completing the kMisc2 rows
0-10. THREE page headers
inside the slice, all
stripped (the R249 lesson):
155 (TABLE (III.E.) 2.),
159 and 183 (both TREASURE).
TWO seams pinned exactly:
the Candle (line 157 ends one
of the, line 161 continues
nine alignments) and the
Cloak of Displacement (line
180 ends with such as
spells,, line 185 continues
gaze weapon attacks).
rules/miscprose5.h (the mmp
prefix again, 60 accessors:
50 scalars + 10 array
walkers, no name collisions
with parts 1-4): Candle of
Invocation (nine alignments;
cleric level +2 while
aflame; any burning casts a
gate, taper consumed; 4
hour burn), Carpet of
Flying (the 4-row table
01-20 3x5 1 person 42
through 81-00 6x9 4 persons
24; command word, voice
range; repairs only in the
East), Censer Controlling
Air Elementals (12 HD next
round; incense of meditation
+3 per die and obeys;
extinguished turns on the
summoner; half foot wide, 1
foot high), Censer of
Summoning Hostile Air
Elementals (cursed; 1-4
enraged elementals, 1 per
round; burns until the
summoner or elementals die),
Chime of Opening (mithral
tube 1 foot; defeats hold
portal and wizard lock below
15th level; 1 round per
function; the chained and
locked chest 4-5 soundings;
silence negates; 20-80
charges, 20 + d6 x 10),
Chime of Hunger (6 inch
radius; eat at least 1
round, save each round
after; mirrors a chime of
opening first), Cloak of
Displacement (1-2 foot
offset; first attack auto
miss; then +2 AC and +2
saves; 75% human/elven
sized, 25% small), Cloak of
Elvenkind (the 9-row
invisibility table: heavy
growth 100, light growth 99,
open fields 95, rocky 98,
buildings 90, bright room
50, torch 95, infravision
90, light 50; 90% human or
elven sized, 10% small),
Cloak of the Manta Ray
(salt water trigger; 90%
manta likeness; breathe
underwater; move 18; AC at
least 6; tail spine 1-6, no
stun; arms free), Cloak of
Poisonousness (handled
safely; neutralize poison no
effect; worn is stone dead;
remove curse destroys the
magic, then neutralize plus
raise dead at minus 10%),
Cloak of Protection (the
5-row plus table 01-35 +1
through 96-00 +5; +1 AC and
+1 save per plus; the +1
example AC 10 to 9; stacks
with items and leather only,
never magical armor, other
armor, or shields). ENGINE
CROSS-CHECK: kMisc2 rows
0-10 (Candle 1-6, Carpet
7-8, Censer Air 9-10, Censer
Hostile 11, Chime Open
12-13, Chime Hunger 14,
Displacement 15-18,
Elvenkind 19-27, Manta
28-30, Poisonous 31-32,
Protection 33-55) plus the
(C) mark on the Candle and
the (M) marks on the two
Censers, and the per-plus
asterisk on row 10 -
VERIFIED CORRECT, no
R260-style off-by-one (the
R226 pin already sat on row
10). The R261 audit
cross-pins the +2 cloak
example (1000 xp / 10000 gp
per plus -> 2000 / 20000).
New R261 battery audit;
census 179. Next: part 6 -
Crystal Ball onward in
part2 from line 222 (global
11287; the Crystal Ball
locating chance table and
the Crystal Hypnosis Ball
follow; the double-asterisk
feature row 56-60 is
R226-pinned).

R262 landed the III.E misc
magic explanation prose part
6 (part2 lines 222-283;
global = 11065 + part2
line), Crystal Ball and
Crystal Hypnosis Ball -
completing the kMisc2 rows
11-12. ONE page header
inside the slice strips (the
279 TREASURE page, the R249
lesson); the slice is
table-dense: the locating
chance table (well known
100, slightly 85, pictured
50, part 50, garment 25,
informed 25, slightly
informed 20, other plane
-25), the viewing period
table (1 hour 3 times a day
down to 1/6 hour once), the
additional powers table
(01-50 plain, 51-75
clairaudience, 76-90 ESP,
91-00 telepathy,
communication only), the
notice-by-class table
(Fighter 2, Thief 6,
Paladin 6, Assassin 5,
Ranger 4, Monk 1, Bard 3).
The spell function is 10th
level; notice needs int 12
or better; the int ladder
1, 3, 6, 10, 15, 21 at int
13-18 plus 1 percent per
level; a dispel magic shuts
the ball down 1 day; the
spell-user detection uses
the page 60 table; clerics
and druids may take water
basin or mirror scriers.
Crystal Hypnosis Ball:
cursed, indistinguishable,
radiates magic not evil; the
gazer gets a telepathic
suggestion and slides under
the influence (magic-user,
lich, or other-planar power;
servant, tool, or possession
object), gradual or sudden
at the referee call. ENGINE
CROSS-CHECK: kMisc2 rows
11-12 (Crystal Ball 56-60,
Hypnosis 61), the (M) marks
on both, and the
double-asterisk row 11 -
the R226 pin VERIFIED
CORRECT (1000 xp / 5000 gp
base, +100 percent per
feature: clairaudience
2000/10000, ESP 3000/15000,
telepathy 4000/20000). New
R262 battery audit; census
180. Next: part 7 - Cube of
Force onward in part2 from
line 285 (global 11350; the
cube of force charge table
and the attack-form
surcharge table follow).

R263 landed the III.E misc
magic explanation prose part
7 (part2 lines 285-322;
global = 11065 + part2
line), Cube of Force through
Decanter of Endless Water -
completing the kMisc2 rows
13-17. ZERO page headers
inside the slice (a first);
ONE seam pins exactly (the
Daern: line 314 ends but the
person or, line 316 continues
persons nearby). Cube of
Force (36 charges, restored
daily; wall of force 1 inch
per side; the 6-face table
1/1, 2/8, 3/6, 4/4, 6/3,
0/normal; the 14-form attack
surcharge table catapult 1
through wall of fire 2; no
casting into or out; mineral,
ivory or bone), Cube of
Frost Resistance (65 degrees
F inside; absorbs cone of
cold, ice storm, dragon
breath; collapses over 50 hp
per turn, renews after 1
hour, destroyed over 100 hp;
minus 40 F withstands only
42 hp, the 2-per-minus-10
math pinned), Cubic Gate
(carnelian; 6 sides, 1 Prime
Material, 5 chosen; 1 press
opens a nexus, 10 percent per
turn something comes
through; 2 presses draw all
within 5 feet; max 1 link),
Daern Instant Fortress (20
foot square, 30 high, 10 into
ground; owner-only door;
walls ignore all but
catapults; 200 hp collapse,
damage cumulative, wish
restores 10; springs up in 1
round, catching growth costs
10-100 hp), Decanter of
Endless Water (stream 1
gallon, fountain 5 foot at 5,
geyser 20 foot at 30; fresh
or salt; geyser knocks the
holder over and kills small
animals; ceases on command).
ENGINE CROSS-CHECK: kMisc2
rows 13-17 (62-63, 64-65,
66-67, 68-69, 70-72) and the
negative-control stretch -
no (C), no (M), no asterisk
rows on 13-17; row 12 still
carries its (M). The frost
math cross-pins 50 - 2 x 4 =
42. New R263 battery audit;
census 181. Next: part 8 -
Deck of Many Things onward
in part2 from line 324
(global 11389; the 22-plaque
table and the per-plaque
explanations follow; the
deck sits on kMisc2 row 18,
73-76).

R264 landed the III.E misc
magic explanation prose part
8 (part2 lines 324-400;
global = 11065 + part2
line), the Deck of Many
Things - pinning the kMisc2
row 18 (73-76). ONE page
header inside the slice
strips (the 360 TREASURE
page); ZERO mid-sentence
seams (a first). The deck:
13 or 22 plaques at 75/25
percent; draws announced
beforehand (1, or 2, 3,
even 4); the jester gives 2
more draws; plaques replaced
unless jester or fool;
asterisk marks the 9 extras
of the 22-pack; The Void
and Donjon in bold face
make the deck disappear.
Per-plaque: Sun (item plus
50000 xp), Moon (1-4
wishes, ninth level spell,
used in that many turns),
Star (2 points, 19 cap, the
6-ability fallback order),
Comet (solo the next
monster: mid-point of next
level), Throne (charisma 18
and a keep; already-18
still +25 percent
reactions), Key (map +20
percent, 1 usable weapon),
Knight (4th level fighter,
+1 per die, 18 max), Gem
(20 jewelry or 50 gems at
1000 gp base, xp capped at
1 level), The Void (soul
trapped, wish fails),
Flames (Greater devil,
enmity until death), Skull
(minor Death AC -4, 33 hp,
scythe 2-16 never missing
and first; helpers summon
their own Deaths; undead
for spells; ignores cold,
fire, electrical), Talons
(all magic items instantly
gone), Ruin (all wealth and
property lost forever),
Euryale (minus 3 saves,
Fates or gods only), Rogue
(1 henchman forever
hostile), Balance (change
alignment or be judged),
Jester (10000 xp or 2 draws,
discarded), Fool (mandatory
payment and draw, 10000 xp),
Vizier (one full answer),
Idiot (1-4 int lost, redraw
optional), Fates (cancel
one event, party endures),
Donjon (imprisoned, gear
and spells stripped). The
battery caught an assistant
index error pre-splice (the
fifth M mark sits on engine
row 26, Eyes of Charming,
not 25) - the print was
clean. New R264 battery
audit; census 182. Next:
part 9 - Drums of Deafening
onward in part2 from line
402 (global 11467; the two
drums, the four dusts, the
bottles and the eyes follow;
rows 19+).

R265 landed the III.E misc
magic explanation prose part
9 (part2 lines 402-429;
global = 11065 + part2
line), Drums of Deafening
through Eyes of Petrification
plus the eye-mix note -
pinning the kMisc2 rows
19-29, the slice that
COMPLETES the 30-row table
(Candle of Invocation through
Eyes of Petrification). ONE
page header inside the slice
strips (the 417 TREASURE
page), cutting the
Eversmoking Bottle paragraph
mid-sentence (until the /
eversmoking bottle is
stoppered) - one seam,
restored. The R264 pointer
said four dusts; the print
shows three (Appearance,
Disappearance, Sneezing and
Choking). The items: Drums
of Deafening (both drums:
permanent deafness within 7
inches, heal or similar
cures; 1 inch zone stunned
2-8 rounds), Drums of Panic
(12 inches, safe zone 2
inches, flee 1 turn per
failed save, 3 rest rounds
per 1 turn of flight, int 2
saves -2, int 1 or less
-4; both drum pairs are
1.5 feet hemispheres), Dust
of Appearance (2-20 turns;
packet 10 feet radius, tube
cone 1 to 15 feet wide and
20 long; 5-50 containers;
reveals invisible, out of
phase, astral, ethereal;
images; negates the
displacement, elvenkind and
blending cloaks), Dust of
Disappearance (2-20 turns,
11-20 sprinkled; even
detect invisibility fails;
the dust of appearance
exception; AC 4 places
better; attack does not
obviate it), Dust of
Sneezing and Choking (20
feet radius; failed poison
save dies, survivors
choked 5-20 rounds),
Efreeti Bottle (brass or
bronze, lead stopper; 10
percent insane attack, 10
percent 3 wishes only, 80
percent serve; issues in 1
segment), Eversmoking
Bottle (urn identical to
the efreeti bottle; 50000
cubic feet in 1 round,
10000 more per round to
120000; smokes until
stoppered; command word
reseals), Eyes of Charming
(1 person per round; both
lenses save -2, one lens
+2), Eyes of the Eagle
(100x at 1 foot or more;
2000 vs 20 feet; one cusp
dizzy-stunned 1 round,
then always cover 1 eye),
Eyes of Minute Seeing (100x
at 1 foot or less; seams,
marks, compartments),
Eyes of Petrification
(instant stone; 25 percent
as basilisk gaze including
reflection), Mixing eye
types (immediate insanity
2-8 turns, 2d4). Engine
rows 19-29: 77, 78-79,
80-85, 86-91, 92, 93, 94,
95, 96-97, 98-99, 100;
only Eyes of Charming (M);
row 29 the triple star.
New R265 battery audit;
census 183. Next: part 10 -
Figurines of Wondrous Power
onward in part2 from line
433 (global 11498; TABLE
III.E. 3, the kMisc3 rows,
begins; the figurines,
gauntlets and girdles
follow).

R266 landed the III.E misc
magic explanation prose part
10 (part2 lines 433-479;
global = 11065 + part2
line), Figurines of
Wondrous Power - pinning
the kMisc3 row 0 (the
Figurine band 01-15, the
single asterisk, per hit
die values 100 xp / 1000
gp, no class marks). ONE
page header inside the
slice strips (the 477
TREASURE page), cutting
the Serpentine Owl
paragraph mid-sentence
(the owl in / smaller
form) - one seam,
restored; the compilation
also wraps the Goat of
Travelling paragraph at a
bare blank line (450/452,
no page header) - one
wrap artifact, restored.
The figurine type table:
01-15 ebony fly, 16-30
golden lions, 31-40 ivory
goats, 41-55 marble
elephant, 56-65 obsidian
steed, 66-85 onyx dog,
86-00 serpentine owl.
The figurines: Ebony Fly
(pony size; AC 4, 4+4 HD,
air maneuver class C; 48
inches unladen, 36 at up
to 210 pounds, 24 at
211-350; 3 uses per week,
12 hours per day), Golden
Lions (2 adult lions, AC
5/6, 5+2 HD; slain: 1
full week; otherwise
daily), Ivory Goats (a
trio; after 3 uses each
loses magic forever) -
Travelling (mount AC 6,
24 hp, 2 horn attacks
1-8, 4 HD; 48 inches at
280 pounds, minus 1 inch
per 14 extra pounds; 24
hours per week; rests 1
day), Travail (hooves
4-10, bite 2-8, horns
2-12; charging: horns
only at +6, 8-18 per
horn; AC 0, 96 hp, 16 HD;
once per month; moves 24
inches), Terror (destrier
mount, 36 inches, AC 2,
48 hp, no own attacks;
horns a +3 spear lance
and a +6 sword; terror
radius 3 inches, save or
lose 50 percent strength
and at least -3 to hit;
once every 2 weeks),
Marble Elephant (hand
size statuette; types
01-50 Asiatic, 51-90
African, 91-93 Mammoth,
94-00 Mastodon; 24 hours
per use, 4 uses per
month), Obsidian Steed (a
nightmare; a good rider:
10 percent per use to the
Hades first layer floor,
then statuette; 24 hours
once per week; astral and
ethereal carry rider and
gear), Onyx Dog (war dog
with int 8-10 and common
speech; scent 100 percent
within 1 hour, minus 10
per hour after;
infravision 90 feet;
hidden 80, invisible 65,
phased 50 percent; 6
hours once per week;
obeys only its owner),
Serpentine Owl (horned
owl AC 7, 24 inches, 2-4
hp, 1-2 damage; giant
form 3 uses only, then
burnout; 95 percent
silent, infravision 90
feet, dark vision as full
light and 2x human; mouse
at 60 feet; counter-
stealth reduced 50
percent; telepathy reports
to owner; int 2-4; giant
form equals the giant
owl). 90 accessors: 86
scalars + 4 walkers (the
figurine type and the
elephant type tables).
New R266 battery audit;
census 184. Next: part 11
- Flask of Curses onward
in part2 from line 481
(global 11546; the
gauntlets, gems, girdles
and helms follow; kMisc3
rows 1+).

R267 landed the III.E misc
magic explanation prose part
11 (part2 lines 481-530;
global = 11065 + part2
line), Flask of Curses
through the Girdle of Giant
Strength - pinning the
kMisc3 rows 1-9, the (C, F,
T) marks riding rows 4
(Ogre Power), 5 (Swimming
and Climbing), 8
(Femininity/Masculinity) and
9 (Giant Strength). ONE
page header inside the slice
strips (the 493 TREASURE
page), cutting the Gem of
Brightness paragraph
mid-sentence (at the /
option of the gem owner) -
one seam, restored. The
items: Flask of Curses
(beaker-like, detection
hides its nature; first
unstopper curses nearby,
then harmless), Gauntlets of
Dexterity (+4 if dex 6 or
less, +2 at 7-13, +1 at 14+;
non-thieves as a 4th level
thief, thieves +10 percent),
Gauntlets of Fumbling (mimic
dexterity or ogre power;
curse: 50 percent drop
chance per round, not both
singly; dex -2; remove
curse or wish only),
Gauntlets of Ogre Power
(18/00 strength; +3 to hit,
+6 damage), Gauntlets of
Swimming and Climbing
(triton 15 inches under,
merman 18 on top; no water
breathing; climb 95
percent, thieves 99.5), Gem
of Brightness (3 lights:
pale cone 10 feet at 2.5
radius free; ray 1 feet wide
50 long, dazzle 1-4 rounds,
1 charge; flash cone 30
feet at 5 radius, blind
1-4 rounds then -1 to -4
permanent eye damage, 5
charges; cure blindness or
heal; 50 charges, no
recharge; darkness drains 1
or 1 round useless;
continual darkness: 1 day
useless or 5 charges), Gem
of Seeing (30 inches
cursory, 10 careful; 1
round per 200 feet square,
2 per 100; 5 percent
hallucination), Girdle of
Femininity/Masculinity
(changes sex, then
powerless; wish 50 percent,
a god certain; 10 percent
remove all sex), Girdle of
Giant Strength (Hill 19
+3/+7, Stone 20 +3/+8,
Frost 21 +4/+9, Fire 22
+4/+10, Cloud 23 +5/+11,
Storm 24 +6/+12; open
doors 7 in 8 (3), 7 in 8
(3), 9 in 10 (4), 11 in 12
(4), 11 in 12 (5), 19 in 20
(7 in 8); weight allowance
+4500 to +12000; rock
range 8 to 16 inches,
damage 1-6 to 1-12,
missile weight 140 to 212,
bend bars 50 to 100
percent; not cumulative
except with ogre power
gauntlets and magic war
hammers). 63 accessors:
49 scalars + 14 walkers
(the strength and rock
tables; the strength,
damage and bend-bars
ladders are arithmetic
checks). New R267 battery
audit; census 185. Next:
part 12 - Helm of
Brilliance onward in
part2 from line 532
(global 11597; the helm
jewel functions, horns,
horseshoes, incenses and
instruments follow; kMisc3
rows 10+).

R268 landed the III.E misc
magic explanation prose part
12 (part2 lines 532-579;
global = 11065 + part2
line), Helm of Brilliance
through the Horn of Bubbles -
pinning the kMisc3 rows 10-17,
NO class marks and NO
asterisks ride these rows. ONE
page header inside the slice
(the 541 TREASURE page) falls
between the jewel functions
table and the Each gem
paragraph of the Brilliance
item - restored. The jewel
functions table: the book
upload flattens the four gem
rows into the Diamond cell
(the Ruby, Fire Opal and Opal
cells empty) - the four-row
table restored from the
compilation (the R175
precedent): Diamond prismatic
spray (7th illusionist), Ruby
wall of fire (5th druid), Fire
Opal fireball (3rd
magic-user), Opal light (1st
cleric). The items: Helm of
Brilliance (+2 armor, 10
diamonds, 20 rubies, 30 fire
opals, 40 opals; each gem one
spell in 1 segment once, the
helm once per round, spell
level doubled; undead glow at
30 feet, pain 1-6, skeletons
and zombies exempt; sword of
flame in 1 round, additional
to specials; produce flame as
a 5th level druid; double
strength fire resistance, no
augment; spent gems turn to
powder, removal destroys, no
re-magicking; a failed save
versus magical fire: another
save for the helm without
magic, failed: the gems
overload, multiple effects),
Helm of Comprehending
Languages and Reading Magic
(90 percent strange tongues,
80 magic writings, all or
none; not spell use; a helmet
of armor class 5), Helm of
Opposite Alignment
(indeterminate dweomer; curse
on donning; good to evil,
neutral to LE LG CE CG; the
alteration desired; wish or
alter reality only; no self
return; paladin quest and
atone; powerless after
functioning), Helm of
Telepathy (thoughts within 6
inches; racial tongue over
common over alignment
tongues; 3 feet of stone, a
quarter foot of iron, lead or
gold sheeting blocks;
directional, conscious effort;
language or empathy;
suggestion +5 percent per 2
intelligence above, -5 per 1
below; the subject save
minus 1 per 2 below, plus 1
per 1 above, equal flat; +4
psionic attacks; +40 psionic
strength), Helm of
Teleportation (once per day
as a magic-user, destination
known, risk; a magic-user
memorizes and refreshes:
repeat 3 times and still
personally teleport; the
spell retained: 6 personal
teleports, then a helm
usage), Helm of Underwater
Action (see and breathe;
lenses from two compartments;
5 times farther vision;
obstructions block; the
command word: an air globe
until repeated), Horn of
Blasting (a normal trumpet; a
sound cone 12 inches by 3;
save: stunned 1, deafened 2;
fail: 1-10 damage, stunned 2,
deafened 4; an ultrasonic
pulse 1 foot by 10 inches; 3
times a large catapult hit =
18 structural points, smash a
drawbridge or flatten a
cottage; over once a day: 10
percent cumulative explode,
5-50 on the user; no
charges; 2 percent cumulative
shiver, no wielder damage),
Horn of Bubbles (the bubbles
blind the blower 2-20
rounds; only when a slayer
actively seeks the
character; appearance may
delay). 91 accessors: 87
scalars + 4 walkers (the
jewel functions table; the
gem, spell-level, structural
and explosion ladders are
arithmetic checks). New R268
battery audit; census 186.
Next: part 13 - Horn of
Collapsing onward in part2
from line 581 (global 11646;
the tritons, Valhalla,
horseshoes, incenses and
instruments follow; kMisc3
rows 18+).

R269 landed the III.E misc
magic explanation prose part
13 (part2 lines 581-626;
global = 11065 + part2
line), Horn of Collapsing
through the Incense of
Meditation - pinning the
kMisc3 rows 18-23: the (C, F)
mark on the Horn of the
Tritons (row 19), the (C)
mark on the Incense of
Meditation (row 23), the
Valhalla double asterisk
(row 20). ONE page header
inside the slice (the 592
TREASURE page) cuts the
Collapsing proper-use
paragraph mid-sentence (at
the 10 feet radius from
the / central aiming
point) - restored. ONE OCR
artifact restored from the
compilation (the R175
precedent): the meditation
survival clause reads
(rounded down), the upload
prints grounded down). The
items: Horn of Collapsing
(misfire without the rune
or 10 percent anyway;
outside: 2-12 fist-sized
rocks at 1-6 each; indoors:
3-36; underground: 5-20
base times 1 per 10 feet
of drop height; proper
use aims at the roof 30-60
feet beyond, collapses up
to 20 by 20 feet, a 10
feet radius, damage only
indoors or underground),
Horn of the Tritons (conch
shell; once per day, a
triton 3; calm 1 mile,
dispels water elemental or
weird; summon on a d6 band
1-2 hippocampi 5-20, 3-5
giant sea horses 5-30, 6
sea lions 1-10, friendly;
panic animal-or-lower
intelligence, flee unless
save, the savers minus 5
to hit for 3-18 turns =
30-180 rounds; heard by
tritons 1 league), Horn of
Valhalla (4 varieties,
blown once every 7 days;
silver 1-8, 4-10 at 2nd,
any class; brass 9-15, 3-9
at 3rd, C F T; bronze
16-18, 2-8 at 4th, C F;
iron 19-20, 2-5 at 5th, F;
the wrong class is
attacked; AC 4, 6 hp per
die, sword and spear or
axe and spear 50 50;
fights until slain or
6 turns; 50 percent
aligned, radical
difference: the blower
attacked; bronze doubles
and iron triples the
1,000 xp / 15,000 gp base
- the row 20 double
asterisk), Horseshoes of
Speed (4 iron shoes, never
wear out; double speed; 1
percent per 7 leagues that
1 drops; one lost: 150
percent; two lost: normal),
Horseshoes of a Zephyr
(travel without touching
ground, water crossed, no
tracks; normal speeds; no
tire for 12 hours per day),
Incense of Meditation
(recognizable by a
5th-plus cleric when
burning; 8 hours of prayer:
full and best spell
effects, cure always max,
broadest area, saves at
minus 1, the dead revived
with the not-surviving
chance halved (rounded
down); 2-8 pieces, one
burns 8 hours, effects 24
hours). 73 accessors: 60
scalars + 13 walkers (the
triton summon and Valhalla
variety tables; the dice,
level, percent and
turn-rounds ladders are
arithmetic checks). New
R269 battery audit; census
187. Next: part 14 - Incense
of Obsession onward in
part2 from line 630 (global
11695; the ioun stones and
instruments follow; kMisc3
rows 24+).

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
