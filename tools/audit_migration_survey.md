# The audit-region survey (R823 prep)

## File facts

- regtest.cpp md5: a3143ba9262a0381b853c3bb26283cb6
- regtest.cpp bytes: 5721422, lines: 144420
- 'audit: bad' occurrences: 745 (the census)
- 'audit: bad ' (trailing space) occurrences: 745
- include lines: 623
- last include line: 623: #include "rules/uwfight.h"  // R313: the underwater fight
- R227 anchor line: 139952:     // ---- R227: the wis mental save wiring audit ----

## Segmentation

- head-comment lines matching "// ---- RNNN": 778
- printf lines carrying "audit: bad": 745

## The audit blocks (head + printf), in file order

- blocks (head + audit printf): 745
- heads WITHOUT an audit printf in segment: 33
- audit printfs NOT under any head: 0
- blocks with nonzero brace delta: 0
- blocks containing a bare "return 0;": 0

## The digest (one line per audit block)

idx | headln | endln | d | ret0 | label | head text
0 | 967 | 1008 | 0 | - | R79 claim/caps audit | // ---- R79: ammo bundle claims + carried caps -----------------------
1 | 1009 | 1041 | 0 | - | R80 quiver audit | // ---- R80: quiver bundle math --------------------------------------
2 | 1099 | 1143 | 0 | - | R81 rings/scrolls/status audit | // ---- R81: ring claims, scroll picks, status helpers --------
3 | 1144 | 1176 | 0 | - | R82 death/revival audit | // ---- R82: death and revival -----------------------------------
4 | 1177 | 1207 | 0 | - | R83 teleport audit | // ---- R83: teleport + L4-6 casting gates audit ----
5 | 1208 | 1290 | 0 | - | R85 pack audit | // ---- R85: the pack audit ----
6 | 1291 | 1338 | 0 | - | R86 cursed/hire audit | // ---- R86: cursed/hire audit ----
7 | 1339 | 1423 | 0 | - | R87 burden audit | // ---- R87: burden audit ----
8 | 1424 | 1506 | 0 | - | R88 warning audit | // ---- R88: warning audit ----
9 | 1507 | 1569 | 0 | - | R89 pace audit | // ---- R89: pace audit ----
10 | 1570 | 1615 | 0 | - | R90 clock audit | // ---- R90: clock audit ----
11 | 1616 | 1632 | 0 | - | R91 stairs audit | // ---- R91: stairs audit ----
12 | 1633 | 1658 | 0 | - | R92 road audit | // ---- R92: road audit ----
13 | 1659 | 1691 | 0 | - | R93 ledger audit | // ---- R93: ledger audit ----
14 | 1692 | 1730 | 0 | - | R94 nerve audit | // ---- R94: nerve audit ----
15 | 1731 | 1759 | 0 | - | R95 calendar audit | // ---- R95: calendar audit ----
16 | 1760 | 1785 | 0 | - | R96 town clock audit | // ---- R96: town clock audit ----
17 | 1786 | 1825 | 0 | - | R97 gray beard audit | // ---- R97: gray beard audit ----
18 | 1826 | 1940 | 0 | - | R114 aging audit | // ---- R114: aging audit ----
19 | 1941 | 1959 | 0 | - | R115 magic weapon gate audit | // ---- R115: magic weapon gate audit ----
20 | 1960 | 2050 | 0 | - | R115 magic aging audit | // ---- R115: magic aging audit ----
21 | 2051 | 2092 | 0 | - | R116 missile range audit | // ---- R116: missile range audit ----
22 | 2093 | 2160 | 0 | - | R117 encounter reactions audit | // ---- R117: encounter reactions audit ----
23 | 2161 | 2235 | 0 | - | R118 listening at doors audit | // ---- R118: listening at doors audit ----
24 | 2236 | 2254 | 0 | - | R119 forced rest audit | // ---- R119: forced rest audit ----
25 | 2255 | 2281 | 0 | - | R120 parley and listening audit | // ---- R120: parley and listening wiring audit ----
26 | 2282 | 2317 | 0 | - | R121 crew officers audit | // ---- R121: crew officers audit ----
27 | 2318 | 2444 | 0 | - | R122 treasure line-diff audit | // ---- R122: treasure line-diff audit ---------------------------------
28 | 2445 | 2593 | 0 | - | R123 outdoor movement audit | // ---- R123: outdoor movement audit ---------------------------------
29 | 2594 | 3111 | 0 | - | R124 appendix A dressing audit | // ---- R124: appendix A dressing audit ----------------------------------
30 | 3112 | 3182 | 0 | - | R125 traps and tricks audit | // ---- R125: traps and tricks audit (App G/H) ----
31 | 3183 | 3288 | 0 | - | R126 wilderness line-diff audit | // ---- R126: wilderness line-diff audit ----
32 | 3289 | 3392 | 0 | - | R127 waterborne line-diff audit | // ---- R127: waterborne line-diff audit ----
33 | 3393 | 3459 | 0 | - | R128 special rooms audit | // ---- R128: special rooms audit ----
34 | 3460 | 3509 | 0 | - | R130 high-level slots audit | // ---- R130: high-level slots audit ----
35 | 3510 | 3543 | 0 | - | R131 slot plumbing audit | // ---- R131: slot plumbing audit ----
36 | 3544 | 3568 | 0 | - | R147 dwarf CON save bonus audit | // ---- R147: dwarf CON magic-save bonus audit ----
37 | 3569 | 3614 | 0 | - | R147 matrix II.D audit | // ---- R147: matrix II.D audit ----
38 | 3615 | 3709 | 0 | - | R147 Appendix P audit | // ---- R147: Appendix P audit ----
39 | 3710 | 3933 | 0 | - | R150 appendix I dressing audit | // ---- R150: appendix I dressing audit ------------------------------
40 | 3934 | 4058 | 0 | - | R151 Appendix O encumbrance audit | // ---- R151: Appendix O encumbrance audit -----------------------------
41 | 4059 | 4116 | 0 | - | R152 becoming-lost audit | // ---- R152: becoming-lost check audit -------------------------------
42 | 4117 | 4206 | 0 | - | R153 exceptional strength audit | // ---- R153: exceptional strength audit -------------------------------
43 | 4207 | 4466 | 0 | - | R154 PC races audit | // ---- R154: PC races audit ---------------------------------
44 | 4467 | 4552 | 0 | - | R155 classed monsters audit | // ---- R155: classed monsters audit ------------------------
45 | 4553 | 4634 | 0 | - | R156 convention party audit | // ---- R156: convention party audit --------------------
46 | 4635 | 4775 | 0 | - | R157 grenade missiles audit | // ---- R157: grenade-like missiles audit ---------------
47 | 4776 | 4864 | 0 | - | R158 weapon speed factors audit | // ---- R158: weapon speed factors audit ---------------
48 | 4865 | 4948 | 0 | - | R159 striking to subdue audit | // ---- R159: striking to subdue audit ---------------
49 | 4949 | 5251 | 0 | - | R160 weaponless combat audit | // ---- R160: weaponless combat audit --------------------
50 | 5252 | 5292 | 0 | - | R161 two weapons audit | // ---- R161: attacks with two weapons audit --------
51 | 5293 | 5360 | 0 | - | R162 level title ladders audit | // ---- R162: level title ladders audit ---------
52 | 5361 | 5429 | 0 | - | R176 printed XP tables audit | // ---- R176: the printed XP tables audit -------
53 | 5430 | 5481 | 0 | - | R178c DEX and CON tables audit | // ---- R178c: the DEX and CON tables audit ----
54 | 5482 | 5592 | 0 | - | R179 subclass registry audit | // ---- R179: the subclass registry audit -------
55 | 5593 | 5715 | 0 | - | R180 qualification and race gates audit | // ---- R180: the qualification and race gates audit ----
56 | 5716 | 5815 | 0 | - | R230 subclass creation seam audit | // ---- R230: the subclass creation seam audit ----
57 | 5816 | 5945 | 0 | - | R231 subclass leveling seam audit | // ---- R231: the subclass leveling seam audit ----
58 | 5946 | 6017 | 0 | - | R232 subclass specials hooks audit | // ---- R232: the subclass specials hooks audit ----
59 | 6018 | 6068 | 0 | - | R233a multi-class seam audit | // ---- R233a: the multi-class seam audit ----
60 | 6069 | 6133 | 0 | - | R233 multi-class engine audit | // ---- R233: the multi-class engine audit ----
61 | 6134 | 6163 | 0 | - | R234a dual-class seam audit | // ---- R234a: the dual-class seam audit ----
62 | 6164 | 6249 | 0 | - | R234 dual-class engine audit | // ---- R234: the dual-class engine audit ----
63 | 6250 | 6315 | 0 | - | R235a bard career seam audit | // ---- R235a: the bard career seam audit ----
64 | 6316 | 6396 | 0 | - | R235 bard engine audit | // ---- R235: the bard engine audit ----
65 | 6397 | 6441 | 0 | - | R236 bard specials audit | // ---- R236: the bard specials audit ----
66 | 6442 | 6529 | 0 | - | R181 attacks per melee round audit | // ---- R181: the attacks per melee round audit ----
67 | 6530 | 6614 | 0 | - | R182 druid spell layer audit | // ---- R182: the druid spell layer audit ----
68 | 6615 | 6714 | 0 | - | R183 illusionist spell layer audit | // ---- R183: the illusionist spell layer audit ----
69 | 6715 | 6813 | 0 | - | R184 paladin and ranger spell layers audit | // ---- R184: the paladin and ranger spell layers audit ----
70 | 6814 | 6938 | 0 | - | R185 multi-class and dual-class audit | // ---- R185: the multi-class and dual-class audit ----
71 | 6939 | 7258 | 0 | - | R186 the bard audit | // ---- R186: the bard audit ----
72 | 7259 | 7444 | 0 | - | R187 per-subclass specials audit | // ---- R187: the per-subclass specials audit ----
73 | 7445 | 7534 | 0 | - | R188 prime requisite XP adjustment audit | // ---- R188: the prime requisite XP adjustment audit ----
74 | 7535 | 7773 | 0 | - | R189 weapon tables verify audit | // ---- R189: the weapon tables verify audit ----
75 | 7774 | 7815 | 0 | - | R190 starting money audit | // ---- R190: the starting money audit ----
76 | 7816 | 7890 | 0 | - | R191 armor class ratings audit | // ---- R191: the armor class ratings audit ----
77 | 7891 | 7984 | 0 | - | R192 wisdom tables audit | // ---- R192: the wisdom tables audit ----
78 | 7985 | 8037 | 0 | - | R193 charisma table audit | // ---- R193: the charisma table audit ----
79 | 8038 | 8070 | 0 | - | R194 wisdom defense repin audit | // ---- R194: the wisdom magical defense repin audit ----
80 | 8071 | 8099 | 0 | - | R195 INT languages repin audit | // ---- R195: the INT languages repin audit ----
81 | 8100 | 8155 | 0 | - | R196 INT table II audit | // ---- R196: the INT Table II audit ----
82 | 8156 | 8200 | 0 | - | R197 mental-form flag audit | // ---- R197: the mental-form flag audit ----
83 | 8201 | 8331 | 0 | - | R198 class weapon allowlists audit | // ---- R198: the class weapon allowlists audit ----
84 | 8332 | 8370 | 0 | - | R199 oil and poison columns audit | // ---- R199: the oil and poison columns audit ----
85 | 8371 | 8417 | 0 | - | R200 falling ladder audit | // ---- R200: the falling-while-climbing ladder audit ----
86 | 8418 | 8466 | 0 | - | R201 NPC monk alignment audit | // ---- R201: the NPC monk alignment split audit ----
87 | 8467 | 8539 | 0 | - | R203 apparent armor AC audit | // ---- R203: the apparent armor AC audit ----
88 | 8540 | 8649 | 0 | - | R204 item saving throw matrix audit | // ---- R204: the item saving throw matrix audit ----
89 | 8650 | 8781 | 0 | - | R205 spying tables audit | // ---- R205: the spying tables audit ----
90 | 8782 | 8966 | 0 | - | R206 pursuit and evasion audit | // ---- R206: the pursuit and evasion audit ----
91 | 8967 | 9042 | 0 | - | R207 town taxation audit | // ---- R207: the town taxation audit ----
92 | 9043 | 9235 | 0 | - | R208 social class and rank audit | // ---- R208: the social class and rank audit ----
93 | 9236 | 9457 | 0 | - | R209 NPC personae facts audit | // ---- R209: the NPC personae facts audit ----
94 | 9458 | 9644 | 0 | - | R210 NPC personae traits audit | // ---- R210: the NPC personae traits audit ----
95 | 9645 | 9871 | 0 | - | R211 NPC body and language audit | // ---- R211: the NPC body and language audit ----
96 | 9872 | 10044 | 0 | - | R212 hire costs and non-human troops audit | // ---- R212: the hire costs and non-human troops audit ----
97 | 10045 | 10269 | 0 | - | R213 construction and siege economics audit | // ---- R213: the construction and siege economics audit ----
98 | 10270 | 10516 | 0 | - | R214 war machine fire and siege values audit | // ---- R214: the war machine fire and siege values audit ----
99 | 10517 | 10590 | 0 | - | R215 conducting the game pins audit | // ---- R215: the conducting the game pins audit ----
100 | 10591 | 10681 | 0 | - | R216 magical research pins audit | // ---- R216: the magical research pins audit ----
101 | 10682 | 10762 | 0 | - | R217 scroll manufacture and fabrication pins audit | // ---- R217: the scroll manufacture and fabrication pins audit ----
102 | 10763 | 10809 | 0 | - | R218 use of magic items and energy draining pins audit | // ---- R218: the use of magic items and energy draining pins audit ----
103 | 10810 | 10971 | 0 | - | R219 treasure random determination tables audit | // ---- R219: the treasure random determination tables audit ----
104 | 10972 | 11095 | 0 | - | R220 combined hoard table pins audit | // ---- R220: the combined hoard table pins audit ----
105 | 11096 | 11176 | 0 | - | R221 potions prose pins audit | // ---- R221: the III.A potions prose pins audit ----
106 | 11177 | 11313 | 0 | - | R222 scrolls prose pins audit | // ---- R222: the III.B scrolls prose pins audit ----
107 | 11314 | 11398 | 0 | - | R223 rings footnote pins audit | // ---- R223: the III.C rings footnote pins audit ----
108 | 11399 | 11499 | 0 | - | R224 rods staves wands pins audit | // ---- R224: the III.D rods/staves/wands pins audit ----
109 | 11500 | 11602 | 0 | - | R225 misc table 1 pins audit | // ---- R225: the III.E table 1 pins audit ----
110 | 11603 | 11709 | 0 | - | R226 misc table 2 pins audit | // ---- R226: the III.E table 2 pins audit ----
111 | 11710 | 11860 | 0 | - | R237 misc table 3 pins audit | // ---- R237: the III.E table 3 pins audit ----
112 | 11861 | 12041 | 0 | - | R238 misc table 4 pins audit | // ---- R238: the III.E table 4 pins audit ----
113 | 12042 | 12156 | 0 | - | R239 misc table 5 pins audit | // ---- R239: the III.E table 5 pins audit ----
114 | 12157 | 12244 | 0 | - | R240 special artifacts pins audit | // ---- R240: the III.E Special artifacts pins audit ----
115 | 12245 | 12328 | 0 | - | R241 armor and shield pins audit | // ---- R241: the III.F armor and shield pins audit ----
116 | 12329 | 12425 | 0 | - | R242 swords pins audit | // ---- R242: the III.G swords pins audit ----
117 | 12426 | 12534 | 0 | - | R243 misc weapons pins audit | // ---- R243: the III.H misc weapons pins audit ----
118 | 12535 | 12677 | 0 | - | R244 rods prose pins audit | // ---- R244: the III.D rods explanation prose pins audit ----
119 | 12678 | 12797 | 0 | - | R245 staves prose pins audit | // ---- R245: the III.D staves explanation prose pins audit ----
120 | 12798 | 12885 | 0 | - | R246 wands prose pins audit | // ---- R246: the III.D wands explanation prose pins audit ----
121 | 12886 | 12986 | 0 | - | R247 wands prose part 2 pins audit | // ---- R247: the III.D wands explanation prose part 2 pins audit ----
122 | 12987 | 13069 | 0 | - | R248 wand of wonder effect table pins audit | // ---- R248: the III.D wand of wonder effect table pins audit ----
123 | 13070 | 13176 | 0 | - | R249 potions prose part 1 pins audit | // ---- R249: the III.A potions explanation prose part 1 pins audit ----
124 | 13177 | 13334 | 0 | - | R250 potions prose part 2 pins audit | // ---- R250: the III.A potions explanation prose part 2 pins audit ----
125 | 13335 | 13482 | 0 | - | R251 potions prose part 3 pins audit | // ---- R251: the III.A potions explanation prose part 3 pins audit ----
126 | 13483 | 13650 | 0 | - | R252 scrolls prose pins audit | // ---- R252: the III.B scrolls explanation prose pins audit ----
127 | 13651 | 13743 | 0 | - | R253 rings prose pins audit | // ---- R253: the III.C rings explanation prose pins audit ----
128 | 13744 | 13869 | 0 | - | R254 rings prose part 2 pins audit | // ---- R254: the III.C rings explanation prose part 2 pins audit ----
129 | 13870 | 14037 | 0 | - | R256 rings prose part 3 pins audit | // ---- R256: the III.C rings explanation prose part 3 pins audit ----
130 | 14038 | 14156 | 0 | - | R257 misc magic prose part 1 pins audit | // ---- R257: the III.E misc magic explanation prose part 1 pins audit ----
131 | 14157 | 14309 | 0 | - | R258 misc magic prose part 2 pins audit | // ---- R258: the III.E misc magic explanation prose part 2 pins audit ----
132 | 14310 | 14432 | 0 | - | R259 misc magic prose part 3 pins audit | // ---- R259: the III.E misc magic explanation prose part 3 pins audit ----
133 | 14433 | 14549 | 0 | - | R260 misc magic prose part 4 pins audit | // ---- R260: the III.E misc magic explanation
134 | 14550 | 14687 | 0 | - | R261 misc magic prose part 5 pins audit | // ---- R261: the III.E misc magic explanation
135 | 14688 | 14829 | 0 | - | R262 misc magic prose part 6 pins audit | // ---- R262: the III.E misc magic explanation
136 | 14830 | 14929 | 0 | - | R263 misc magic prose part 7 pins audit | // ---- R263: the III.E misc magic explanation
137 | 14930 | 15017 | 0 | - | R264 misc magic prose part 8 pins audit | // ---- R264: the III.E misc magic explanation
138 | 15018 | 15125 | 0 | - | R265 misc magic prose part 9 pins audit | // ---- R265: the III.E misc magic explanation
139 | 15126 | 15271 | 0 | - | R266 misc magic prose part 10 pins audit | // ---- R266: the III.E misc magic explanation
140 | 15272 | 15435 | 0 | - | R267 misc magic prose part 11 pins audit | // ---- R267: the III.E misc magic explanation
141 | 15436 | 15651 | 0 | - | R268 misc magic prose part 12 pins audit | // ---- R268: the III.E misc magic explanation
142 | 15652 | 15878 | 0 | - | R269 misc magic prose part 13 pins audit | // ---- R269: the III.E misc magic explanation
143 | 15879 | 16030 | 0 | - | R270 misc magic prose part 14 pins audit | // ---- R270: the III.E misc magic explanation
144 | 16031 | 16157 | 0 | - | R271 misc magic prose part 15 pins audit | // ---- R271: the III.E misc magic explanation
145 | 16158 | 16275 | 0 | - | R272 misc magic prose part 16 pins audit | // ---- R272: the III.E misc magic explanation
146 | 16276 | 16395 | 0 | - | R273 misc magic prose part 17 pins audit | // ---- R273: the III.E misc magic explanation
147 | 16396 | 16608 | 0 | - | R274 misc magic prose part 18 pins audit | // ---- R274: the III.E misc magic explanation
148 | 16609 | 16802 | 0 | - | R275 misc magic prose part 19 pins audit | // ---- R275: the III.E misc magic explanation
149 | 16803 | 16924 | 0 | - | R276 misc magic prose part 20 pins audit | // ---- R276: the III.E misc magic explanation
150 | 16925 | 17077 | 0 | - | R277 misc magic prose part 21 pins audit | // ---- R277: the III.E misc magic explanation
151 | 17078 | 17281 | 0 | - | R278 misc magic prose part 22 pins audit | // ---- R278: the III.E misc magic explanation
152 | 17282 | 17580 | 0 | - | R279 misc magic prose part 23 pins audit | // ---- R279: the III.E misc magic explanation
153 | 17581 | 17633 | 0 | - | R280 special artifacts prose part 1 pins audit | // ---- R280: the III.E Special artifacts
154 | 17634 | 17748 | 0 | - | R281 special artifacts prose part 2 pins audit | // ---- R281: the III.E Special artifacts
155 | 17749 | 17841 | 0 | - | R282 special artifacts prose part 3 pins audit | // ---- R282: the III.E Special artifacts
156 | 17842 | 17969 | 0 | - | R283 special artifacts prose part 4 pins audit | // ---- R283: the III.E Special artifacts
157 | 17970 | 18059 | 0 | - | R284 special artifacts prose part 5 pins audit | // ---- R284: the III.E Special artifacts
158 | 18060 | 18163 | 0 | - | R285 special artifacts prose part 6 pins audit | // ---- R285: the III.E Special artifacts
159 | 18164 | 18265 | 0 | - | R286 special artifacts prose part 7 pins audit | // ---- R286: the III.E Special artifacts
160 | 18266 | 18372 | 0 | - | R287 special artifacts prose part 8 pins audit | // ---- R287: the III.E Special artifacts
161 | 18373 | 18446 | 0 | - | R288 special artifacts prose part 9 pins audit | // ---- R288: the III.E Special artifacts
162 | 18447 | 18565 | 0 | - | R289 special artifacts prose part 10 pins audit | // ---- R289: the III.E Special artifacts
163 | 18566 | 18689 | 0 | - | R290 special artifacts prose part 11 pins audit | // ---- R290: the III.E Special artifacts
164 | 18690 | 18793 | 0 | - | R291 special artifacts prose part 12 pins audit | // ---- R291: the III.E Special artifacts
165 | 18794 | 18889 | 0 | - | R292 special artifacts prose part 13 pins audit | // ---- R292: the III.E Special artifacts
166 | 18890 | 18984 | 0 | - | R293 special artifacts prose part 14 pins audit | // ---- R293: the III.E Special artifacts
167 | 18985 | 19086 | 0 | - | R294 special artifacts prose part 15 pins audit | // ---- R294: the III.E Special artifacts
168 | 19087 | 19204 | 0 | - | R295 special artifacts prose part 16 pins audit | // ---- R295: the III.E Special artifacts
169 | 19205 | 19338 | 0 | - | R297 weapon proficiency table pins audit | // ---- R297: the weapon proficiency table pins audit ----
170 | 19339 | 19490 | 0 | - | R298 thief function take table pins audit | // ---- R298: the thief function take table pins audit ----
171 | 19491 | 19563 | 0 | - | R299a party kit recordings seam audit | // ---- R299a: the party kit recordings seam audit ----
172 | 19564 | 19740 | 0 | - | R299 party kit recordings engine audit | // ---- R299: the party kit recordings engine audit ----
173 | 19741 | 19807 | 0 | - | R300a equipment cost columns seam audit | // ---- R300a: the equipment cost columns seam audit ----
174 | 19808 | 19889 | 0 | - | R300 equipment costs engine audit | // ---- R300: the equipment costs engine audit ----
175 | 19890 | 19954 | 0 | - | R301a thief percentile seam audit | // ---- R301a: the thief percentile seam audit ----
176 | 19955 | 20155 | 0 | - | R301 thief trap rolls engine audit | // ---- R301: the thief trap rolls engine audit ----
177 | 20156 | 20207 | 0 | - | R302a thief silence seam audit | // ---- R302: the thief silence seam audit ----
178 | 20208 | 20327 | 0 | - | R302 thief silence engine audit | // ---- R302: the thief silence engine audit ----
179 | 20328 | 20372 | 0 | - | R303a thief pockets seam audit | // ---- R303: the thief pockets seam audit ----
180 | 20373 | 20535 | 0 | - | R303 thief pockets engine audit | // ---- R303: the thief pockets engine audit ----
181 | 20536 | 20589 | 0 | - | R304a thief locks seam audit | // ---- R304a: the thief locks seam audit ----
182 | 20590 | 20748 | 0 | - | R304 thief locks engine audit | // ---- R304: the thief locks engine audit ----
183 | 20749 | 20794 | 0 | - | R305a door force seam audit | // ---- R305a: the door force seam audit ----
184 | 20795 | 21063 | 0 | - | R305 door force engine audit | // ---- R305: the door force engine audit ----
185 | 21064 | 21129 | 0 | - | R306a thief functions seam audit | // ---- R306a: the thief functions seam audit ----
186 | 21130 | 21452 | 0 | - | R306 thief functions engine audit | // ---- R306: the thief functions engine audit ----
187 | 21453 | 21565 | 0 | - | R308 general equipment lists audit | // ---- R308: the general equipment lists audit ----
188 | 21566 | 21699 | 0 | - | R309 hirelings cost tables audit | // ---- R309: the hirelings cost tables audit ----
189 | 21700 | 22093 | 0 | - | R310 sage subsection audit | // ---- R310: the sage subsection audit ----
190 | 22094 | 22277 | 0 | - | R311 underwater environment audit | // ---- R311: the underwater environment audit ----
191 | 22278 | 22337 | 0 | - | R312a flooded crossing seam audit | // ---- R312a: the flooded crossing seam audit ----
192 | 22338 | 22535 | 0 | - | R312 flooded crossing engine audit | // ---- R312: the flooded crossing engine audit ----
193 | 22536 | 22578 | 0 | - | R313a underwater fight seam audit | // ---- R313a: the underwater fight seam audit ----
194 | 22579 | 22792 | 0 | - | R313 underwater fight engine audit | // ---- R313: the underwater fight engine audit ----
195 | 22793 | 22835 | 0 | - | R314a crossbow and aquatic seam audit | // ---- R314a: the crossbow and the aquatic
196 | 22836 | 23020 | 0 | - | R314 crossbow and aquatic engine audit | // ---- R314: the crossbow and the
197 | 23021 | 23202 | 0 | - | R315 net throwers engine audit | // ---- R315: the net throwers engine
198 | 23203 | 23307 | 0 | - | R316 underwater vision seam audit | // ---- R316: the underwater vision seam
199 | 23308 | 23414 | 0 | - | R317 infravision fold audit | // ---- R317: the infravision fold audit
200 | 23415 | 23566 | 0 | - | R318 net entrap layer audit | // ---- R318: the net entrap layer audit
201 | 23567 | 23783 | 0 | - | R319 underwater vision multiples audit | // ---- R319: the underwater vision
202 | 23784 | 23955 | 0 | - | R320 breathing aids audit | // ---- R320: the breathing aids audit ----
203 | 23956 | 24159 | 0 | - | R321 aerial chapter audit | // ---- R321: the aerial chapter audit ----
204 | 24160 | 24349 | 0 | - | R322 comeliness pins audit | // ---- R322: the comeliness pins audit ----
205 | 24350 | 24692 | 0 | - | R323 subrace layer seam audit | // ---- R323: the subrace layer seam audit ----
206 | 24693 | 25333 | 0 | - | R324 subrace level limits audit | // ---- R324: the Race Table II audit ----
207 | 25334 | 25651 | 0 | - | R325 subrace level cap audit | // ---- R325: the Race Table II fold audit ----
208 | 25652 | 25868 | 0 | - | R326 subrace creation audit | // ---- R326: the creation round audit ----
209 | 25869 | 26014 | 0 | - | R327 class tables pin audit | // ---- R327: the class tables pin
210 | 26015 | 26323 | 0 | - | R328 cavalier pin audit | // ---- R328: the cavalier pin audit ----
211 | 26324 | 26443 | 0 | - | R329 paladin reparent pin audit | // ---- R329: the paladin reparent pin
212 | 26444 | 26698 | 0 | - | R330 druid hierophant pin audit | // ---- R330: the druid hierophant pin
213 | 26699 | 26902 | 0 | - | R331 weapon spec prose pin audit | // ---- R331: the weapon specialization
214 | 26903 | 27122 | 0 | - | R332 barbarian pin audit | // ---- R332: the barbarian pin audit ----
215 | 27123 | 27294 | 0 | - | R333 ranger expansion pin audit | // ---- R333: the ranger expansion pin audit ----
216 | 27295 | 27521 | 0 | - | R334 thief armor and attacks pin audit | // ---- R334: the thief armor and attacks pin audit ----
217 | 27522 | 27839 | 0 | - | R335 thief-acrobat pin audit | // ---- R335: the thief-acrobat pin audit ----
218 | 27840 | 28009 | 0 | - | R336 cavalier money pin audit | // ---- R336: the cavalier money pin audit ----
219 | 28010 | 28208 | 0 | - | R337 UA weight and damage pin audit | // ---- R337: the UA weight and damage pin audit ----
220 | 28209 | 28441 | 0 | - | R338 UA missile data pin audit | // ---- R338: the UA missile data pin audit ----
221 | 28442 | 28611 | 0 | - | R339 UA proficiency pin audit | // ---- R339: the UA proficiency pin audit ----
222 | 28612 | 28817 | 0 | - | R340 UA new weapons prose pin audit | // ---- R340: the UA new weapons prose pin audit ----
223 | 28818 | 29072 | 0 | - | R341 UA spell tables pin audit | // ---- R341: the UA spell tables pin audit ----
224 | 29073 | 29371 | 0 | - | R342 UA MU and IL tables pin audit | // ---- R342: the UA MU and illusionist tables pin audit ----
225 | 29372 | 29637 | 0 | - | R343 UA cleric 1st level spells pin audit | // ---- R343: the UA new cleric 1st level spells pin audit ----
226 | 29638 | 29874 | 0 | - | R344 UA cleric 2nd level spells pin audit | // ---- R344: the UA new cleric 2nd level spells pin audit ----
227 | 29875 | 30184 | 0 | - | R345 UA cleric 3rd level spells pin audit | // ---- R345: the UA new cleric 3rd level spells pin audit ----
228 | 30185 | 30511 | 0 | - | R346 UA cleric 4th level spells pin audit | // ---- R346: the UA new cleric 4th level spells pin audit ----
229 | 30512 | 30832 | 0 | - | R347 UA cleric 5th level spells pin audit | // ---- R347: the UA new cleric 5th level spells pin audit ----
230 | 30833 | 30953 | 0 | - | R348 UA cleric 6th level spells pin audit | // ---- R348: the UA new cleric 6th level spells pin audit ----
231 | 30954 | 31091 | 0 | - | R349 UA cleric 7th level spells pin audit | // ---- R349: the UA new cleric 7th level spells pin audit ----
232 | 31092 | 31344 | 0 | - | R350 UA druid 1st level spells pin audit | // ---- R350: the UA new druid 1st level spells pin audit ----
233 | 31345 | 31552 | 0 | - | R351 UA druid 2nd level spells pin audit | // ---- R351: the UA new druid 2nd level spells pin audit ----
234 | 31553 | 31725 | 0 | - | R352 UA druid 3rd level spells pin audit | // ---- R352: the UA new druid 3rd level spells pin audit ----
235 | 31726 | 31851 | 0 | - | R353 UA druid 5th level spells pin audit | // ---- R353: the UA new druid 5th level spells pin audit ----
236 | 31852 | 31969 | 0 | - | R354 UA druid 6th level spells pin audit | // ---- R354: the UA new druid 6th level spells pin audit ----
237 | 31970 | 32120 | 0 | - | R355 UA druid 7th level spells pin audit | // ---- R355: the UA new druid 7th level spells pin audit ----
238 | 32121 | 32421 | 0 | - | R356 UA MU 1st level spells pin audit | // ---- R356: the UA new magic-user 1st level spells pin audit ----
239 | 32422 | 32753 | 0 | - | R357 UA MU 2nd level spells pin audit | // ---- R357: the UA new magic-user 2nd level spells pin audit ----
240 | 32754 | 32995 | 0 | - | R358 UA MU 3rd level spells pin audit | // ---- R358: the UA new magic-user 3rd level spells pin audit ----
241 | 32996 | 33226 | 0 | - | R359 UA MU 4th level spells pin audit | // ---- R359: the UA new magic-user 4th level spells pin audit ----
242 | 33227 | 33634 | 0 | - | R360 UA MU 5th/6th level spells pin audit | // ---- R360: the UA new magic-user 5th and
243 | 33635 | 33963 | 0 | - | R361 UA MU 7th level spells pin audit | // ---- R361: the UA new magic-user 7th level
244 | 33964 | 34251 | 0 | - | R362 UA MU 8th/9th level spells pin audit | // ---- R362: the UA new magic-user 8th and 9th
245 | 34252 | 34707 | 0 | - | R363 UA IL cantrips/1st/2nd pin audit | // ---- R363: the UA new illusionist
246 | 34708 | 35046 | 0 | - | R364 UA IL 3rd/4th/5th spells pin audit | // ---- R364: the UA new illusionist
247 | 35047 | 35342 | 0 | - | R365 UA IL 6th/7th and DM pin audit | // ---- R365: the UA new illusionist
248 | 35343 | 35583 | 0 | - | R366 UA DM-section spells pin audit | // ---- R366: the UA DM-section spells
249 | 35584 | 35735 | 0 | - | R367 UA social/birth pin audit | // ---- R367: the UA campaign social
250 | 35736 | 35872 | 0 | - | R368 UA Cavaliers Table I pin audit | // ---- R368: the UA Cavaliers Table I
251 | 35873 | 35966 | 0 | - | R369 UA cantrip acquisition pin audit | // ---- R369: the UA cantrip
252 | 35967 | 36127 | 0 | - | R370 UA DM-section smalls pin audit | // ---- R370: the UA DM-section
253 | 36128 | 36273 | 0 | - | R371 UA expanded armor pin audit | // ---- R371: the UA expanded armor
254 | 36274 | 36484 | 0 | - | R372 UA cavalier followers pin audit | // ---- R372: the UA cavalier
255 | 36485 | 36612 | 0 | - | R373 UA comeliness note pin audit | // ---- R373: the UA comeliness
256 | 36613 | 36692 | 0 | - | R374 UA treasure dial pin audit | // ---- R374: the UA treasure
257 | 36693 | 36801 | 0 | - | R375 UA determination skeleton pin audit | // ---- R375: the UA determination
258 | 36802 | 36982 | 0 | - | R376 UA new potions prose part 1 pin audit | // ---- R376: the UA new potions
259 | 36983 | 37158 | 0 | - | R377 UA new scrolls protection pin audit | // ---- R377: the UA new scrolls
260 | 37159 | 37269 | 0 | - | R378 UA new rings prose pin audit | // ---- R378: the UA new rings
261 | 37270 | 37434 | 0 | - | R379 UA new rods staves prose pin audit | // ---- R379: the UA new rods
262 | 37435 | 37614 | 0 | - | R380 UA new wands prose pin audit | // ---- R380: the UA new wands
263 | 37615 | 37898 | 0 | - | R381 UA misc magic prose part 1 pin audit | // ---- R381: the UA misc magic
264 | 37899 | 38191 | 0 | - | R382 UA misc magic prose part 2 pin audit | // ---- R382: the UA misc magic
265 | 38192 | 38458 | 0 | - | R383 UA misc magic prose part 3 pin audit | // ---- R383: the UA misc magic
266 | 38459 | 38795 | 0 | - | R384 UA misc magic prose part 4 pin audit | // ---- R384: the UA misc magic
267 | 38796 | 39129 | 0 | - | R385 UA misc magic prose part 5 pin audit | // ---- R385: the UA misc magic
268 | 39130 | 39400 | 0 | - | R386 UA misc magic prose part 6 pin audit | // ---- R386: the UA misc magic
269 | 39401 | 39712 | 0 | - | R387 UA armor and swords prose pin audit | // ---- R387: the UA armor and
270 | 39713 | 40196 | 0 | - | R388 UA misc weapons prose pin audit | // ---- R388: the UA misc
271 | 40197 | 40544 | 0 | - | R389 UA weaponless combat pin audit | // ---- R389: the UA
272 | 40545 | 40687 | 0 | - | R390 UA non-lethal combat pin audit | // ---- R390: the UA
273 | 40688 | 40904 | 0 | - | R391 UA pole-arm nomenclature pin audit | // ---- R391: the UA
274 | 40905 | 41054 | 0 | - | R392 UA players tables pin audit | // ---- R392: the UA players tables pin audit ----
275 | 41055 | 41133 | 0 | - | R393 PDF-read completion pin audit | // ---- R393: the PDF-read completion sweep
276 | 41134 | 41291 | 0 | - | R394 UA DM tables manifest pin audit | // ---- R394: the UA DM tables
277 | 41292 | 41981 | 0 | - | R395 UA treasure row bodies pin audit | // ---- R395: the UA treasure row
278 | 41982 | 42127 | 0 | - | R396 UA potions prose completion pin audit | // ---- R396: the UA potions
279 | 42128 | 42665 | 0 | - | R397 UA treasure smalls pin audit | // ---- R397: the UA treasure smalls pin
280 | 42666 | 42810 | 0 | - | R398 UA misc magic holes pin audit | // ---- R398: the UA misc magic
281 | 42811 | 42910 | 0 | - | R399 UA armor weapons holes pin audit | // ---- R399: the UA armor
282 | 42911 | 43044 | 0 | - | R400 UA comeliness site audit | // ---- R400: the UA comeliness
283 | 43045 | 43202 | 0 | - | R401 UA cantrip tier seam audit | // ---- R401: the UA cantrip tier
284 | 43203 | 43309 | 0 | - | R402 UA treasure dial seam audit | // ---- R402: the UA treasure
285 | 43310 | 43409 | 0 | - | R403 mount layer seam audit | // ---- R403: the mount layer
286 | 43410 | 43499 | 0 | - | R404 psionics seam audit | // ---- R404: the psionics seam
287 | 43500 | 43653 | 0 | - | R405 deity layer seam audit | // ---- R405: the deity layer seam
288 | 43654 | 43803 | 0 | - | R406 UA appendix S stat blocks pin audit | // ---- R406: the UA Appendix S
289 | 43804 | 43951 | 0 | - | R407 UA appendix S clerical charts pin audit | // ---- R407: the UA Appendix S
290 | 43952 | 44066 | 0 | - | R408 UA armor class table pin audit | // ---- R408: the UA p. 26 armor
291 | 44067 | 44475 | 0 | - | R409 UA appendix S stat lines pin audit | // ---- R409: the UA Appendix S
292 | 44476 | 44693 | 0 | - | R410 UA appendix S class lines pin audit | // ---- R410: the UA Appendix S
293 | 44694 | 44781 | 0 | - | R411 UA appendix S MOVE values pin audit | // ---- R411: the UA Appendix S
294 | 44782 | 44964 | 0 | - | R412 UA useful cantrips pin audit | // ---- R412: the UA useful
295 | 44965 | 45144 | 0 | - | R413 UA reversed cantrips pin audit | // ---- R413: the UA
296 | 45145 | 45277 | 0 | - | R414 UA legerdemain cantrips pin audit | // ---- R414: the UA
297 | 45278 | 45455 | 0 | - | R415 UA person-affecting cantrips pin audit | // ---- R415: the UA
298 | 45456 | 45654 | 0 | - | R416 UA personal cantrips pin audit | // ---- R416: the UA personal
299 | 45655 | 45805 | 0 | - | R417 UA haunting-sound cantrips pin audit | // ---- R417: the UA
300 | 45806 | 45878 | 0 | - | R418 UA cantrip cast-times part 1 pin audit | // ---- R418: the cantrip
301 | 45879 | 46007 | 0 | - | R419 UA cantrip cast-times part 2 pin audit | // ---- R419: the cantrip
302 | 46008 | 46119 | 0 | - | R421 UA IL cantrip cast-times pin audit | // ---- R421: the IL cantrip
303 | 46120 | 46179 | 0 | - | R422 UA appendix R resolution pin audit | // ---- R422: the appendix R
304 | 46180 | 46331 | 0 | - | R423 UA appendix S pantheon prose pin audit | // ---- R423: the UA appendix S
305 | 46332 | 46402 | 0 | - | R424 UA appendix T resolution pin audit | // ---- R424: the appendix T
306 | 46403 | 46585 | 0 | - | R425 WSG proficiencies pin audit | // ---- R425: the WSG
307 | 46586 | 46819 | 0 | - | R426 WSG dressing pin audit | // ---- R426: the WSG
308 | 46820 | 47064 | 0 | - | R427 WSG environment pin audit | // ---- R427: the WSG
309 | 47065 | 47289 | 0 | - | R429 WSG special weather pin audit | // ---- R429 WSG special weather pin audit ----
310 | 47290 | 47570 | 0 | - | R430 WSG heat and cold pin audit | // ---- R430 WSG heat and cold pin audit ----
311 | 47571 | 47639 | 0 | - | R431 WSG equipment pin audit | // ---- R431 WSG equipment pin audit ----
312 | 47640 | 47905 | 0 | - | R432 WSG encumbrance pin audit | // ---- R432 WSG encumbrance pin audit ----
313 | 47906 | 48116 | 0 | - | R433 WSG animals pin audit | // ---- R433 WSG animals pin audit ----
314 | 48117 | 48236 | 0 | - | R434 WSG vehicles pin audit | // ---- R434 WSG vehicles pin audit ----
315 | 48237 | 48419 | 0 | - | R435 WSG climbing pin audit | // ---- R435 WSG climbing pin audit ----
316 | 48420 | 48573 | 0 | - | R436 WSG climbing checks pin audit | // ---- R436 WSG climbing checks pin audit ----
317 | 48574 | 48663 | 0 | - | R437 WSG falling damage pin audit | // ---- R437 WSG falling damage pin audit ----
318 | 48664 | 48791 | 0 | - | R438 WSG tumbling damage pin audit | // ---- R438 WSG tumbling damage pin audit ----
319 | 48792 | 48899 | 0 | - | R439 WSG stopping a fall pin audit | // ---- R439 WSG stopping a fall pin audit ----
320 | 48900 | 48951 | 0 | - | R440 WSG rope use pin audit | // ---- R440 WSG rope use pin audit ----
321 | 48952 | 49024 | 0 | - | R441 WSG roping-together pin audit | // ---- R441 WSG roping-together pin audit ----
322 | 49025 | 49084 | 0 | - | R442 WSG rappelling pin audit | // ---- R442 WSG rappelling pin audit ----
323 | 49085 | 49166 | 0 | - | R443 WSG belaying pin audit | // ---- R443 WSG belaying pin audit ----
324 | 49167 | 49331 | 0 | - | R444 WSG grappling hooks pin audit | // ---- R444 WSG grappling hooks pin audit ----
325 | 49332 | 49445 | 0 | - | R445 WSG chasm crossing pin audit | // ---- R445 WSG chasm crossing pin audit ----
326 | 49446 | 49508 | 0 | - | R446 WSG mountaineering pin audit | // ---- R446 WSG mountaineering pin audit ----
327 | 49509 | 49558 | 0 | - | R447 WSG slippery surface movement pin audit | // ---- R447 WSG slippery surface movement pin audit ----
328 | 49559 | 49701 | 0 | - | R448 WSG jumping pin audit | // ---- R448 WSG jumping pin audit ----
329 | 49702 | 49832 | 0 | - | R449 WSG reduced visibility pin audit | // ---- R449 WSG reduced visibility pin audit ----
330 | 49833 | 49986 | 0 | - | R450 WSG swimming pin audit | // ---- R450 WSG swimming pin audit ----
331 | 49987 | 50070 | 0 | - | R451 WSG moving water pin audit | // ---- R451 WSG moving water pin audit ----
332 | 50071 | 50181 | 0 | - | R452 WSG diving and surfacing pin audit | // ---- R452 WSG diving and surfacing pin audit ----
333 | 50182 | 50240 | 0 | - | R453 WSG treading water pin audit | // ---- R453 WSG treading water pin audit ----
334 | 50241 | 50331 | 0 | - | R454 WSG holding breath pin audit | // ---- R454 WSG holding breath pin audit ----
335 | 50332 | 50557 | 0 | - | R455 WSG waterborne vehicles pin audit | // ---- R455 WSG waterborne vehicles pin audit ----
336 | 50558 | 50719 | 0 | - | R456 WSG capsizing pin audit | // ---- R456 WSG capsizing pin audit ----
337 | 50720 | 50847 | 0 | - | R457 WSG boating pin audit | // ---- R457 WSG boating pin audit ----
338 | 50848 | 50954 | 0 | - | R458 WSG portaging pin audit | // ---- R458 WSG portaging pin audit ----
339 | 50955 | 51014 | 0 | - | R459 WSG capsized use pin audit | // ---- R459 WSG capsized use pin audit ----
340 | 51015 | 51310 | 0 | - | R460 WSG flying mounts pin audit | // ---- R460 WSG flying mounts pin audit ----
341 | 51311 | 51388 | 0 | - | R461 WSG airborne fall chance pin audit | // ---- R461 WSG airborne fall chance pin audit ----
342 | 51389 | 51620 | 0 | - | R462 WSG food and water pin audit | // ---- R462 WSG food and water pin audit ----
343 | 51621 | 51874 | 0 | - | R463 WSG foraging pin audit | // ---- R463 WSG foraging pin audit ----
344 | 51875 | 52088 | 0 | - | R464 WSG hunting pin audit | // ---- R464 WSG hunting pin audit ----
345 | 52089 | 52254 | 0 | - | R465 WSG fishing pin audit | // ---- R465 WSG fishing pin audit ----
346 | 52255 | 52506 | 0 | - | R466 WSG food carrying pin audit | // ---- R466 WSG food carrying pin audit ----
347 | 52507 | 53242 | 0 | - | R467 WSG finding water pin audit | // ---- R467 WSG finding water pin audit ----
348 | 53243 | 53325 | 0 | - | R468 WSG where water pin audit | // ---- R468 WSG where water pin audit ----
349 | 53326 | 53398 | 0 | - | R469 WSG water in the desert pin audit | // ---- R469 WSG water in the desert pin audit ----
350 | 53399 | 53501 | 0 | - | R470 WSG purifying water pin audit | // ---- R470 WSG purifying water pin audit ----
351 | 53502 | 53724 | 0 | - | R471 WSG natural shelters pin audit | // ---- R471 WSG natural shelters pin audit ----
352 | 53725 | 54025 | 0 | - | R472 WSG portable shelters pin audit | // ---- R472 WSG portable shelters pin audit ----
353 | 54026 | 54409 | 0 | - | R473 WSG sleep and shelter pin audit | // ---- R473 WSG sleep and shelter pin audit ----
354 | 54410 | 54709 | 0 | - | R474 WSG rest quality and fire pin audit | // ---- R474 WSG rest quality and fire pin audit ----
355 | 54710 | 55049 | 0 | - | R475 WSG fuel and fire safety pin audit | // ---- R475 WSG fuel and fire safety pin audit ----
356 | 55050 | 55182 | 0 | - | R476 WSG uncontrollable fires pin audit | // ---- R476 WSG uncontrollable fires pin audit ----
357 | 55183 | 55283 | 0 | - | R477 WSG damage from fire pin audit | // ---- R477 WSG damage from fire pin audit ----
358 | 55284 | 55462 | 0 | - | R478 WSG medicinal plants pin audit | // ---- R478 WSG medicinal plants pin audit ----
359 | 55463 | 55484 | 0 | - | R479 WSG plant lore pin audit | // ---- R479 WSG plant lore pin audit ----
360 | 55485 | 55598 | 0 | - | R480 WSG injuries treatment pin audit | // ---- R480 WSG injuries treatment pin audit ----
361 | 55599 | 55668 | 0 | - | R481 WSG first aid equipment pin audit | // ---- R481 WSG first aid equipment pin audit ----
362 | 55669 | 55733 | 0 | - | R482 WSG normal vision pin audit | // ---- R482 WSG normal vision pin audit ----
363 | 55734 | 55846 | 0 | - | R483 WSG infravision pin audit | // ---- R483 WSG infravision pin audit ----
364 | 55847 | 56006 | 0 | - | R484 WSG ultravision pin audit | // ---- R484 WSG ultravision pin audit ----
365 | 56007 | 56151 | 0 | - | R485 WSG artificial illumination pin audit | // ---- R485 WSG artificial illumination pin audit ----
366 | 56152 | 56465 | 0 | - | R486 WSG natural hazards pin audit | // ---- R486 WSG natural hazards pin audit ----
367 | 56466 | 56706 | 0 | - | R487 WSG hazards closer pin audit | // ---- R487 WSG hazards closer pin audit ----
368 | 56707 | 57031 | 0 | - | R488 WSG wilderness combat opener pin audit | // ---- R488 WSG wilderness combat opener pin audit ----
369 | 57032 | 57325 | 0 | - | R489 WSG fatigue chapter pin audit | // ---- R489 WSG fatigue chapter pin audit ----
370 | 57326 | 57821 | 0 | - | R490 WSG mounts and beasts pin audit | // ---- R490 WSG mounts and beasts pin audit ----
371 | 57822 | 58255 | 0 | - | R491 WSG magic in the wilderness pin audit | // ---- R491 WSG magic in the wilderness pin audit ----
372 | 58256 | 58441 | 0 | - | R492 WSG DM section pin audit | // ---- R492 WSG DM section pin audit ----
373 | 58442 | 59995 | 0 | - | R493 WSG weather generation audit | // ---- R493 WSG weather generation audit ----
374 | 59996 | 62323 | 0 | - | R494 WSG weather effects audit | // ---- R494 WSG weather effects audit ----
375 | 62324 | 62628 | 0 | - | R495 WSG compiled tables audit | // ---- R495 WSG compiled tables audit ----
376 | 62629 | 62823 | 0 | - | R496 WSG gap reconciliation audit | // ---- R496 WSG gap reconciliation audit ----
377 | 62824 | 63224 | 0 | - | R497 WSG overview audit | // ---- R497 WSG overview audit ----
378 | 63225 | 63882 | 0 | - | R498 WSG proficiencies prose audit | // ---- R498 WSG proficiencies prose audit ----
379 | 63883 | 64010 | 0 | - | R499 WSG temperature fold audit | // ---- R499 WSG temperature fold audit ----
380 | 64011 | 64164 | 0 | - | R500 WSG swimmer motion fold audit | // ---- R500 WSG swimmer motion fold audit ----
381 | 64165 | 64322 | 0 | - | R501 WSG movement fall fold audit | // ---- R501 WSG movement fall fold audit ----
382 | 64323 | 64529 | 0 | - | R502 WSG camp chain fold audit | // ---- R502 WSG camp chain fold audit ----
383 | 64530 | 64844 | 0 | - | R503 DSG overview audit | // ---- R503 DSG overview audit ----
384 | 64845 | 65607 | 0 | - | R504 DSG movement I audit | // ---- R504 DSG movement I audit ----
385 | 65608 | 66094 | 0 | - | R505 DSG movement II audit | // ---- R505 DSG movement II audit ----
386 | 66095 | 66650 | 0 | - | R506 DSG proficiencies audit | // ---- R506 DSG proficiencies audit ----
387 | 66651 | 67143 | 0 | - | R507 DSG combat audit | // ---- R507 DSG combat audit ----
388 | 67144 | 67467 | 0 | - | R508 DSG battlesystem audit | // ---- R508 DSG battlesystem audit ----
389 | 67468 | 67772 | 0 | - | R509 DSG air and gases audit | // ---- R509 DSG air and gases audit ----
390 | 67773 | 68071 | 0 | - | R510 DSG odor detection audit | // ---- R510 DSG odor detection audit ----
391 | 68072 | 68350 | 0 | - | R511 DSG cave-in causes audit | // ---- R511 DSG cave-in causes audit ----
392 | 68351 | 68643 | 0 | - | R512 DSG chain reaction audit | // ---- R512 DSG chain reaction audit ----
393 | 68644 | 68860 | 0 | - | R513 DSG DPV and hypothermia audit | // ---- R513 DSG DPV and hypothermia audit ----
394 | 68861 | 69092 | 0 | - | R514 DSG lodestone and NPC reactions audit | // ---- R514 DSG lodestone and NPC reactions audit ----
395 | 69093 | 69148 | 0 | - | R516 DSG structural decay audit | // ---- R516 DSG structural decay audit ----
396 | 69149 | 69438 | 0 | - | R517 DSG underground waterways audit | // ---- R517 DSG underground waterways audit ----
397 | 69439 | 69766 | 0 | - | R518 DSG water travel audit | // ---- R518 DSG water travel audit ----
398 | 69767 | 69830 | 0 | - | R519 DSG mining prospecting audit | // ---- R519 DSG mining prospecting audit ----
399 | 69831 | 70016 | 0 | - | R520 DSG mining excavation audit | // ---- R520 DSG mining excavation audit ----
400 | 70017 | 70184 | 0 | - | R521 DSG mining products audit | // ---- R521 DSG mining products audit ----
401 | 70185 | 70360 | 0 | - | R522 DSG mine product quality audit | // ---- R522 DSG mine product quality audit ----
402 | 70361 | 70471 | 0 | - | R523 DSG mining tail audit | // ---- R523 DSG mining tail audit ----
403 | 70472 | 70576 | 0 | - | R524 DSG loyalty hazards audit | // ---- R524 DSG loyalty hazards audit ----
404 | 70577 | 70747 | 0 | - | R525 DSG equipment costs audit | // ---- R525 DSG equipment costs audit ----
405 | 70748 | 70919 | 0 | - | R526 DSG equipment descriptions audit | // ---- R526 DSG equipment descriptions audit ----
406 | 70920 | 70976 | 0 | - | R527 DSG proficiency descriptions audit | // ---- R527 DSG proficiency descriptions audit ----
407 | 70977 | 71083 | 0 | - | R528 DSG improving-play opener audit | // ---- R528 DSG improving-play opener audit ----
408 | 71084 | 71180 | 0 | - | R529 DSG improving-play tail audit | // ---- R529 DSG improving-play tail audit ----
409 | 71181 | 71303 | 0 | - | R530 DSG underground environment audit | // ---- R530 DSG underground environment audit ----
410 | 71304 | 71429 | 0 | - | R531 DSG geography and theories audit | // ---- R531 DSG geography and theories audit ----
411 | 71430 | 71558 | 0 | - | R532 DSG cultures of the underdark audit | // ---- R532 DSG cultures of the underdark audit ----
412 | 71559 | 71698 | 0 | - | R533 DSG Deepearth opener audit | // ---- R533 DSG Deepearth opener audit ----
413 | 71699 | 71833 | 0 | - | R534 DSG Deepearth areas 1-3 audit | // ---- R534 DSG Deepearth areas 1-3 audit ----
414 | 71834 | 71969 | 0 | - | R535 DSG Deepearth areas 4-5 audit | // ---- R535 DSG Deepearth areas 4-5 audit ----
415 | 71970 | 72078 | 0 | - | R536 DSG Deepearth areas 6-7 audit | // ---- R536 DSG Deepearth areas 6-7 audit ----
416 | 72079 | 72177 | 0 | - | R537 DSG Deepearth areas 8-9 audit | // ---- R537 DSG Deepearth areas 8-9 audit ----
417 | 72178 | 72267 | 0 | - | R538 DSG Deepearth areas 10-11 audit | // ---- R538 DSG Deepearth areas 10-11 audit ----
418 | 72268 | 72355 | 0 | - | R539 DSG Deepearth areas 12-13 audit | // ---- R539 DSG Deepearth areas 12-13 audit ----
419 | 72356 | 72456 | 0 | - | R540 DSG Deepearth areas 14-15 audit | // ---- R540 DSG Deepearth areas 14-15 audit ----
420 | 72457 | 72610 | 0 | - | R541 DSG Deepearth areas 16-17 audit | // ---- R541 DSG Deepearth areas 16-17 audit ----
421 | 72611 | 72765 | 0 | - | R542 DSG Deepearth areas 18-19 audit | // ---- R542 DSG Deepearth areas 18-19 audit ----
422 | 72766 | 72908 | 0 | - | R543 DSG Deepearth areas 20-21 audit | // ---- R543 DSG Deepearth areas 20-21 audit ----
423 | 72909 | 73011 | 0 | - | R544 DSG Deepearth areas 22-23 audit | // ---- R544 DSG Deepearth areas 22-23 audit ----
424 | 73012 | 73137 | 0 | - | R545 DSG Deepearth areas 24-25 audit | // ---- R545 DSG Deepearth areas 24-25 audit ----
425 | 73138 | 73202 | 0 | - | R546 DSG Deepearth areas 26-27 audit | // ---- R546 DSG Deepearth areas 26-27 audit ----
426 | 73203 | 73271 | 0 | - | R547 DSG Deepearth areas 28-29 audit | // ---- R547 DSG Deepearth areas 28-29 audit ----
427 | 73272 | 73352 | 0 | - | R548 DSG Deepearth areas 30-31 audit | // ---- R548 DSG Deepearth areas 30-31 audit ----
428 | 73353 | 73366 | 0 | - | R549 DSG Deepearth closed audit | // ---- R549 DSG Deepearth closed audit ----
429 | 73367 | 73492 | 0 | - | R550 DSG campaign opener audit | // ---- R550 DSG campaign opener audit ----
430 | 73493 | 73601 | 0 | - | R551 DSG worlds of adventure audit | // ---- R551 DSG worlds of adventure audit ----
431 | 73602 | 73721 | 0 | - | R552 DSG plot and counterplot audit | // ---- R552 DSG plot and counterplot audit ----
432 | 73722 | 73858 | 0 | - | R553 DSG story elements tail audit | // ---- R553 DSG story elements tail audit ----
433 | 73859 | 73985 | 0 | - | R554 DSG story design techniques audit | // ---- R554 DSG story design techniques audit ----
434 | 73986 | 74072 | 0 | - | R555 DSG help from the players audit | // ---- R555 DSG help from the players audit ----
435 | 74073 | 74091 | 0 | - | R556 DSG campaign closed audit | // ---- R556 DSG campaign closed audit ----
436 | 74092 | 74197 | 0 | - | R557 DSG mapping settings audit | // ---- R557 DSG mapping settings audit ----
437 | 74198 | 74275 | 0 | - | R558 DSG compiled tables audit | // ---- R558 DSG compiled tables audit ----
438 | 74276 | 74293 | 0 | - | R559 DSG map plates closed audit | // ---- R559 DSG map plates closed audit ----
439 | 74294 | 74347 | 0 | - | R560 DSG index audit | // ---- R560 DSG index audit ----
440 | 74348 | 74362 | 0 | - | R561 DSG DM section audit | // ---- R561 DSG DM section audit ----
441 | 74363 | 74418 | 0 | - | R562 DSG intro frame audit | // ---- R562 DSG intro frame audit ----
442 | 74419 | 74434 | 0 | - | R563 DSG final census audit | // ---- R563 DSG final census audit ----
443 | 74435 | 74492 | 0 | - | R564 MotP intro audit | // ---- R564 MotP intro audit ----
444 | 74493 | 74532 | 0 | - | R565 MotP spell summary audit | // ---- R565 MotP spell summary audit ----
445 | 74533 | 74614 | 0 | - | R566 MotP Ethereal audit | // ---- R566 MotP Ethereal audit ----
446 | 74615 | 74703 | 0 | - | R567 MotP inner planes audit | // ---- R567 MotP inner planes audit ----
447 | 74704 | 74782 | 0 | - | R568 MotP Air plane audit | // ---- R568 MotP Air plane audit ----
448 | 74783 | 74868 | 0 | - | R569 MotP Fire plane audit | // ---- R569 MotP Fire plane audit ----
449 | 74869 | 74960 | 0 | - | R570 MotP Earth plane audit | // ---- R570 MotP Earth plane audit ----
450 | 74961 | 75043 | 0 | - | R571 MotP Water plane audit | // ---- R571 MotP Water plane audit ----
451 | 75044 | 75127 | 0 | - | R572 MotP para-planes audit | // ---- R572 MotP para-planes audit ----
452 | 75128 | 75201 | 0 | - | R573 MotP energy planes audit | // ---- R573 MotP energy planes audit ----
453 | 75202 | 75291 | 0 | - | R574 MotP positive quasi-planes audit | // ---- R574 MotP positive quasi-planes audit ----
454 | 75292 | 75400 | 0 | - | R575 MotP negative quasi-planes audit | // ---- R575 MotP negative quasi-planes audit ----
455 | 75401 | 75569 | 0 | - | R576 Astral Plane audit | // ---- R576 Astral Plane audit ----
456 | 75570 | 75713 | 0 | - | R577 outer planes general audit | // ---- R577 outer planes general audit ----
457 | 75714 | 75812 | 0 | - | R578 Nirvana-Arcadia audit | // ---- R578 Nirvana-Arcadia audit ----
458 | 75813 | 75902 | 0 | - | R579 Heavens-Twins audit | // ---- R579 Heavens-Twins audit ----
459 | 75903 | 75997 | 0 | - | R580 Elysium-Beastlands audit | // ---- R580 Elysium-Beastlands audit ----
460 | 75998 | 76093 | 0 | - | R581 Olympus-Gladsheim audit | // ---- R581 Olympus-Gladsheim audit ----
461 | 76094 | 76204 | 0 | - | R582 Limbo-Pandemonium audit | // ---- R582 Limbo-Pandemonium audit ----
462 | 76205 | 76323 | 0 | - | R583 Abyss audit | // ---- R583 Abyss audit ----
463 | 76324 | 76434 | 0 | - | R584 Tarterus audit | // ---- R584 Tarterus audit ----
464 | 76435 | 76533 | 0 | - | R585 Hades audit | // ---- R585 Hades audit ----
465 | 76534 | 76635 | 0 | - | R586 Gehenna audit | // ---- R586 Gehenna audit ----
466 | 76636 | 76752 | 0 | - | R587 Nine Hells audit | // ---- R587 Nine Hells audit ----
467 | 76753 | 76854 | 0 | - | R588 Acheron audit | // ---- R588 Acheron audit ----
468 | 76855 | 76975 | 0 | - | R589 Opposition audit | // ---- R589 Opposition audit ----
469 | 76976 | 77038 | 0 | - | R590 Beyond audit | // ---- R590 Beyond audit ----
470 | 77039 | 77081 | 0 | - | R591 Outer seal audit | // ---- R591 Outer seal audit ----
471 | 77082 | 77194 | 0 | - | R592 Primes audit | // ---- R592 Primes audit ----
472 | 77195 | 77302 | 0 | - | R593 AppII audit | // ---- R593 AppII audit ----
473 | 77303 | 77392 | 0 | - | R594 AppIII audit | // ---- R594 AppIII audit ----
474 | 77393 | 77540 | 0 | - | R595 AppIV audit | // ---- R595 AppIV audit ----
475 | 77541 | 77616 | 0 | - | R596 Indices audit | // ---- R596 Indices audit ----
476 | 77617 | 77719 | 0 | - | R598 Ether cyclone audit | // ---- R598 Ether cyclone audit ----
477 | 77720 | 77801 | 0 | - | R599 DMO opener audit | // ---- R599 DMO opener audit ----
478 | 77802 | 77965 | 0 | - | R600 DMO maxims audit | // ---- R600 DMO maxims audit ----
479 | 77966 | 78153 | 0 | - | R601 DMO adventures audit | // ---- R601 DMO adventures audit ----
480 | 78154 | 78554 | 0 | - | R602 DMO world-ratings audit | // ---- R602 DMO world-ratings audit ----
481 | 78555 | 79529 | 0 | - | R603 DMO legendary-monsters audit | // ---- R603 DMO legendary-monsters audit ----
482 | 79530 | 80434 | 0 | - | R604 DMO spells-and-items audit | // ---- R604 DMO spells-and-items audit ----
483 | 80435 | 81524 | 0 | - | R605 DMO item-creation audit | // ---- R605 DMO item-creation audit ----
484 | 81525 | 83217 | 0 | - | R606 DMO magical-duels audit | // ---- R606 DMO magical-duels audit ----
485 | 83218 | 84791 | 0 | - | R607 DMO true-dweomers audit | // ---- R607 DMO true-dweomers audit ----
486 | 84792 | 85282 | 0 | - | R608 DMO auto-save-failure audit | // ---- R608 DMO auto-save-failure audit ----
487 | 85283 | 87039 | 0 | - | R609 DMO high-level skills audit | // ---- R609 DMO high-level skills audit ----
488 | 87040 | 89301 | 0 | - | R610 DMO wizard-priest audit | // ---- R610 DMO wizard-priest audit ----
489 | 89302 | 91061 | 0 | - | R611 DMO rogues audit | // ---- R611 DMO rogues audit ----
490 | 91062 | 91369 | 0 | - | R612 DMO ascension audit | // ---- R612 DMO ascension audit ----
491 | 91370 | 93188 | 0 | - | R613 DMO dueling appendix audit | // ---- R613 DMO dueling appendix audit ----
492 | 93189 | 93325 | 0 | - | R614 OA opener audit | // ---- R614 OA opener audit ----
493 | 93326 | 94012 | 0 | - | R615 OA ability tables audit | // ---- R615 OA ability tables audit ----
494 | 94013 | 94302 | 0 | - | R616 OA ability prose audit | // ---- R616 OA ability prose audit ----
495 | 94303 | 94680 | 0 | - | R617 OA class combos audit | // ---- R617 OA class combos audit ----
496 | 94681 | 95073 | 0 | - | R618 OA races audit | // ---- R618 OA races audit ----
497 | 95074 | 95606 | 0 | - | R619 OA barbarian bushi audit | // ---- R619 OA barbarian bushi audit ----
498 | 95607 | 95959 | 0 | - | R620 OA kensai audit | // ---- R620 OA kensai audit ----
499 | 95960 | 96524 | 0 | - | R621 OA monk audit | // ---- R621 OA monk audit ----
500 | 96525 | 97150 | 0 | - | R622 OA ninja audit | // ---- R622 OA ninja audit ----
501 | 97151 | 97611 | 0 | - | R623 OA samurai audit | // ---- R623 OA samurai audit ----
502 | 97612 | 98082 | 0 | - | R624 OA shukenja audit | // ---- R624 OA shukenja audit ----
503 | 98083 | 98474 | 0 | - | R625 OA sohei audit | // ---- R625 OA sohei audit ----
504 | 98475 | 98906 | 0 | - | R626 OA wu jen audit | // ---- R626 OA wu jen audit ----
505 | 98907 | 99350 | 0 | - | R627 OA yakuza audit | // ---- R627 OA yakuza audit ----
506 | 99351 | 99709 | 0 | - | R628 OA character abilities audit | // ---- R628 OA character abilities audit ----
507 | 99710 | 100004 | 0 | - | R629 OA families audit | // ---- R629 OA families audit ----
508 | 100005 | 100235 | 0 | - | R630 OA family structures audit | // ---- R630 OA family structures audit ----
509 | 100236 | 100508 | 0 | - | R631 OA ancestry audit | // ---- R631 OA ancestry audit ----
510 | 100509 | 100574 | 0 | - | R632 OA holdings audit | // ---- R632 OA holdings audit ----
511 | 100575 | 100835 | 0 | - | R633 OA birthrights audit | // ---- R633 OA birthrights audit ----
512 | 100836 | 101015 | 0 | - | R634 OA honor audit | // ---- R634 OA honor audit ----
513 | 101016 | 101403 | 0 | - | R635 OA effects of honor audit | // ---- R635 OA effects of honor audit ----
514 | 101404 | 101647 | 0 | - | R636 OA money audit | // ---- R636 OA money audit ----
515 | 101648 | 101796 | 0 | - | R637 OA starting money audit | // ---- R637 OA starting money audit ----
516 | 101797 | 102028 | 0 | - | R638 OA exchange audit | // ---- R638 OA exchange audit ----
517 | 102029 | 102702 | 0 | - | R639 OA equipment audit | // ---- R639 OA equipment audit ----
518 | 102703 | 103015 | 0 | - | R640 OA weapons audit | // ---- R640 OA weapons audit ----
519 | 103016 | 103215 | 0 | - | R641 OA handheld audit | // ---- R641 OA handheld audit ----
520 | 103216 | 103404 | 0 | - | R642 OA hurled audit | // ---- R642 OA hurled audit ----
521 | 103405 | 103487 | 0 | - | R643 OA armor audit | // ---- R643 OA armor audit ----
522 | 103488 | 103582 | 0 | - | R644 OA piece armor audit | // ---- R644 OA piece armor audit ----
523 | 103583 | 103705 | 0 | - | R645 OA encumbrance audit | // ---- R645 OA encumbrance audit ----
524 | 103706 | 103808 | 0 | - | R646 OA barding audit | // ---- R646 OA barding audit ----
525 | 103809 | 103894 | 0 | - | R647 OA misc equipment audit | // ---- R647 OA misc equipment audit ----
526 | 103895 | 103956 | 0 | - | R648 OA barding prose audit | // ---- R648 OA barding prose audit ----
527 | 103957 | 104107 | 0 | - | R649 OA armor descriptions audit | // ---- R649 OA armor descriptions audit ----
528 | 104108 | 104265 | 0 | - | R650 OA proficiencies audit | // ---- R650 OA proficiencies audit ----
529 | 104266 | 104391 | 0 | - | R651 OA missile specializations audit | // ---- R651 OA missile specializations audit ----
530 | 104392 | 104508 | 0 | - | R652 OA non-weapon proficiencies audit | // ---- R652 OA non-weapon proficiencies audit ----
531 | 104509 | 104595 | 0 | - | R653 OA character proficiencies audit | // ---- R653 OA character proficiencies audit ----
532 | 104596 | 104687 | 0 | - | R654 OA artisan proficiencies audit | // ---- R654 OA artisan proficiencies audit ----
533 | 104688 | 104771 | 0 | - | R655 OA barbarian proficiencies audit | // ---- R655 OA barbarian proficiencies audit ----
534 | 104772 | 104877 | 0 | - | R656 OA common proficiencies audit | // ---- R656 OA common proficiencies audit ----
535 | 104878 | 104967 | 0 | - | R657 OA court proficiencies audit | // ---- R657 OA court proficiencies audit ----
536 | 104968 | 105153 | 0 | - | R658 OA shukenja spells audit | // ---- R658 OA shukenja spells audit ----
537 | 105154 | 105321 | 0 | - | R659 OA first level spells audit | // ---- R659 OA first level spells audit ----
538 | 105322 | 105499 | 0 | - | R660 OA second level spells audit | // ---- R660 OA second level spells audit ----
539 | 105500 | 105691 | 0 | - | R661 OA third level spells audit | // ---- R661 OA third level spells audit ----
540 | 105692 | 105886 | 0 | - | R662 OA fourth level spells audit | // ---- R662 OA fourth level spells audit ----
541 | 105887 | 106066 | 0 | - | R663 OA fifth level spells audit | // ---- R663 OA fifth level spells audit ----
542 | 106067 | 106243 | 0 | - | R664 OA sixth level spells audit | // ---- R664 OA sixth level spells audit ----
543 | 106244 | 106419 | 0 | - | R665 OA seventh level spells audit | // ---- R665 OA seventh level spells audit ----
544 | 106420 | 106568 | 0 | - | R666 OA divination results audit | // ---- R666 OA divination results audit ----
545 | 106569 | 106702 | 0 | - | R667 OA speak with dead audit | // ---- R667 OA speak with dead audit ----
546 | 106703 | 106832 | 0 | - | R668 OA fate audit | // ---- R668 OA fate audit ----
547 | 106833 | 107043 | 0 | - | R669 OA wu jen spell list audit | // ---- R669 OA wu jen spell list audit ----
548 | 107044 | 107257 | 0 | - | R670 OA wu jen first level spells audit | // ---- R670 OA wu jen first level spells audit ----
549 | 107258 | 107482 | 0 | - | R671 OA wu jen second level spells audit | // ---- R671 OA wu jen second level spells audit ----
550 | 107483 | 107700 | 0 | - | R672 OA wu jen third level spells audit | // ---- R672 OA wu jen third level spells audit ----
551 | 107701 | 107932 | 0 | - | R673 OA wu jen fourth level spells audit | // ---- R673 OA wu jen fourth level spells audit ----
552 | 107933 | 108149 | 0 | - | R674 OA wu jen fifth level spells audit | // ---- R674 OA wu jen fifth level spells audit ----
553 | 108150 | 108373 | 0 | - | R675 OA wu jen sixth level spells audit | // ---- R675 OA wu jen sixth level spells audit ----
554 | 108374 | 108554 | 0 | - | R676 OA wu jen seventh level spells audit | // ---- R676 OA wu jen seventh level spells audit ----
555 | 108555 | 108751 | 0 | - | R677 OA wu jen eighth level spells audit | // ---- R677 OA wu jen eighth level spells audit ----
556 | 108752 | 108941 | 0 | - | R678 OA wu jen ninth level spells audit | // ---- R678 OA wu jen ninth level spells audit ----
557 | 108942 | 109019 | 0 | - | R679 OA combat sequence audit | // ---- R679 OA combat sequence audit ----
558 | 109020 | 109069 | 0 | - | R680 OA iaijutsu surprise audit | // ---- R680 OA iaijutsu surprise audit ----
559 | 109070 | 109141 | 0 | - | R681 OA initiative modifiers audit | // ---- R681 OA initiative modifiers audit ----
560 | 109142 | 109189 | 0 | - | R682 OA combat procedures audit | // ---- R682 OA combat procedures audit ----
561 | 109190 | 109254 | 0 | - | R683 OA horseback bowfire modifiers audit | // ---- R683 OA horseback bowfire modifiers audit ----
562 | 109255 | 109355 | 0 | - | R684 OA unhorsing audit | // ---- R684 OA unhorsing audit ----
563 | 109356 | 109394 | 0 | - | R685 OA disarming audit | // ---- R685 OA disarming audit ----
564 | 109395 | 109438 | 0 | - | R686 OA subduing audit | // ---- R686 OA subduing audit ----
565 | 109439 | 109492 | 0 | - | R687 OA psychic duel audit | // ---- R687 OA psychic duel audit ----
566 | 109493 | 109528 | 0 | - | R688 OA martial arts opener audit | // ---- R688 OA martial arts opener audit ----
567 | 109529 | 109611 | 0 | - | R689 OA common martial styles audit | // ---- R689 OA common martial styles audit ----
568 | 109612 | 109662 | 0 | - | R690 OA creating a style audit | // ---- R690 OA creating a style audit ----
569 | 109663 | 109755 | 0 | - | R691 OA style combinations audit | // ---- R691 OA style combinations audit ----
570 | 109756 | 109927 | 0 | - | R692 OA special maneuvers audit | // ---- R692 OA special maneuvers audit ----
571 | 109928 | 110102 | 0 | - | R693 OA principal methods audit | // ---- R693 OA principal methods audit ----
572 | 110103 | 110174 | 0 | - | R694 OA mental and physical training audit | // ---- R694 OA mental and physical training audit ----
573 | 110175 | 110240 | 0 | - | R695 OA learning martial arts audit | // ---- R695 OA learning martial arts audit ----
574 | 110241 | 110324 | 0 | - | R696 OA calendar audit | // ---- R696 OA calendar audit ----
575 | 110325 | 110428 | 0 | - | R697 OA yearly events audit | // ---- R697 OA yearly events audit ----
576 | 110429 | 110606 | 0 | - | R698 OA yearly events prose audit | // ---- R698 OA yearly events prose audit ----
577 | 110607 | 110770 | 0 | - | R699 OA monthly events audit | // ---- R699 OA monthly events audit ----
578 | 110771 | 110999 | 0 | - | R700 OA monthly events prose audit | // ---- R700 OA monthly events prose audit ----
579 | 111000 | 111205 | 0 | - | R701 OA daily events audit | // ---- R701 OA daily events audit ----
580 | 111206 | 111455 | 0 | - | R702 OA daily events prose audit | // ---- R702 OA daily events prose audit ----
581 | 111456 | 111629 | 0 | - | R703 OA terrain encounter tables audit | // ---- R703 OA terrain encounter tables audit ----
582 | 111630 | 111705 | 0 | - | R704 OA climate groupings audit | // ---- R704 OA climate groupings audit ----
583 | 111706 | 111793 | 0 | - | R705 OA monsters Bajang audit | // ---- R705 OA monsters Bajang audit ----
584 | 111794 | 111901 | 0 | - | R706 OA monsters Bakemono audit | // ---- R706 OA monsters Bakemono audit ----
585 | 111902 | 112024 | 0 | - | R707 OA monsters Bisan audit | // ---- R707 OA monsters Bisan audit ----
586 | 112025 | 112169 | 0 | - | R708 OA monsters Buso audit | // ---- R708 OA monsters Buso audit ----
587 | 112170 | 112298 | 0 | - | R709 OA monsters Giant Carp audit | // ---- R709 OA monsters Giant Carp audit ----
588 | 112299 | 112413 | 0 | - | R710 OA monsters Con-Tinh audit | // ---- R710 OA monsters Con-Tinh audit ----
589 | 112414 | 112522 | 0 | - | R711 OA monsters Doc Cu'o'c audit | // ---- R711 OA monsters Doc Cu'o'c audit ----
590 | 112523 | 112768 | 0 | - | R712 OA monsters Oriental Dragons audit | // ---- R712 OA monsters Oriental Dragons audit ----
591 | 112769 | 112992 | 0 | - | R713 OA monsters Gaki audit | // ---- R713 OA monsters Gaki audit ----
592 | 112993 | 113232 | 0 | - | R714 OA monsters Gargantua audit | // ---- R714 OA monsters Gargantua audit ----
593 | 113233 | 113429 | 0 | - | R715 OA monsters Animal Generals audit | // ---- R715 OA monsters Animal Generals audit ----
594 | 113430 | 113587 | 0 | - | R716 OA monsters Goblin Rat audit | // ---- R716 OA monsters Goblin Rat audit ----
595 | 113588 | 113761 | 0 | - | R717 OA monsters Goblin Spider audit | // ---- R717 OA monsters Goblin Spider audit ----
596 | 113762 | 113945 | 0 | - | R718 OA monsters Hai Nu audit | // ---- R718 OA monsters Hai Nu audit ----
597 | 113946 | 114111 | 0 | - | R719 OA monsters Hsing-Sing audit | // ---- R719 OA monsters Hsing-Sing audit ----
598 | 114112 | 114535 | 0 | - | R720 OA monsters Hu Hsien audit | // ---- R720 OA monsters Hu Hsien audit ----
599 | 114536 | 114697 | 0 | - | R721 OA monsters Kala audit | // ---- R721 OA monsters Kala audit ----
600 | 114698 | 114908 | 0 | - | R722 OA monsters Kappa audit | // ---- R722 OA monsters Kappa audit ----
601 | 114909 | 115086 | 0 | - | R723 OA monsters Kuei audit | // ---- R723 OA monsters Kuei audit ----
602 | 115087 | 115258 | 0 | - | R724 OA monsters Men Wako audit | // ---- R724 OA monsters Men Wako audit ----
603 | 115259 | 115504 | 0 | - | R725 OA monsters Nat audit | // ---- R725 OA monsters Nat audit ----
604 | 115505 | 115718 | 0 | - | R726 OA monsters Nature Spirits audit | // ---- R726 OA monsters Nature Spirits audit ----
605 | 115719 | 115835 | 0 | - | R727 OA monsters Ningyo audit | // ---- R727 OA monsters Ningyo audit ----
606 | 115836 | 116040 | 0 | - | R728 OA monsters Oni audit | // ---- R728 OA monsters Oni audit ----
607 | 116041 | 116172 | 0 | - | R729 OA monsters P oh audit | // ---- R729 OA monsters P oh audit ----
608 | 116173 | 116321 | 0 | - | R730 OA monsters Shan Sao audit | // ---- R730 OA monsters Shan Sao audit ----
609 | 116322 | 116490 | 0 | - | R731 OA monsters Shirokinukatsukami audit | // ---- R731 OA monsters Shirokinukatsukami audit ----
610 | 116491 | 116741 | 0 | - | R732 OA monsters Tengu audit | // ---- R732 OA monsters Tengu audit ----
611 | 116742 | 116849 | 0 | - | R733 OA treasure class usage audit | // ---- R733 OA treasure class usage audit ----
612 | 116850 | 116894 | 0 | - | R734 OA random treasure prose audit | // ---- R734 OA random treasure prose audit ----
613 | 116895 | 117296 | 0 | - | R735 OA Table 74 monetary treasure audit | // ---- R735 OA Table 74 monetary treasure audit ----
614 | 117297 | 117401 | 0 | - | R736 OA Table II.A. Orient audit | // ---- R736 OA Table II.A. Orient audit ----
615 | 117402 | 117504 | 0 | - | R737 OA Table III Orient audit | // ---- R737 OA Table III Orient audit ----
616 | 117505 | 117573 | 0 | - | R738 OA standard item mods audit | // ---- R738 OA standard item mods audit ----
617 | 117574 | 117704 | 0 | - | R739 OA potions audit | // ---- R739 OA potions audit ----
618 | 117705 | 117745 | 0 | - | R740 OA scrolls audit | // ---- R740 OA scrolls audit ----
619 | 117746 | 117836 | 0 | - | R741 OA rods staves wands audit | // ---- R741 OA rods staves wands audit ----
620 | 117837 | 117905 | 0 | - | R742 OA misc magic audit | // ---- R742 OA misc magic audit ----
621 | 117906 | 117940 | 0 | - | R743 OA armor shield audit | // ---- R743 OA armor shield audit ----
622 | 117941 | 118023 | 0 | - | R744 OA Table 75 armor audit | // ---- R744 OA Table 75 armor audit ----
623 | 118024 | 118091 | 0 | - | R745 OA Table 76 properties audit | // ---- R745 OA Table 76 properties audit ----
624 | 118092 | 118171 | 0 | - | R746 OA Table 77 special audit | // ---- R746 OA Table 77 special audit ----
625 | 118172 | 118260 | 0 | - | R747 OA armor explanation audit | // ---- R747 OA armor explanation audit ----
626 | 118261 | 118297 | 0 | - | R748 OA weapons prose audit | // ---- R748 OA weapons prose audit ----
627 | 118298 | 118365 | 0 | - | R749 OA Table 78 weapons audit | // ---- R749 OA Table 78 weapons audit ----
628 | 118366 | 118457 | 0 | - | R750 OA Table 79 properties audit | // ---- R750 OA Table 79 properties audit ----
629 | 118458 | 118527 | 0 | - | R751 OA Table 80 sword audit | // ---- R751 OA Table 80 sword audit ----
630 | 118528 | 118607 | 0 | - | R752 OA Table 81 bow class audit | // ---- R752 OA Table 81 bow class audit ----
631 | 118608 | 118680 | 0 | - | R753 OA Table 82 misc melee audit | // ---- R753 OA Table 82 misc melee audit ----
632 | 118681 | 118752 | 0 | - | R754 OA Table 83 missile audit | // ---- R754 OA Table 83 missile audit ----
633 | 118753 | 118825 | 0 | - | R755 OA Table 84 martial arts audit | // ---- R755 OA Table 84 martial arts audit ----
634 | 118826 | 118899 | 0 | - | R756 OA Table 85 ninja audit | // ---- R756 OA Table 85 ninja audit ----
635 | 118900 | 119078 | 0 | - | R757 OA weapon explanation audit | // ---- R757 OA weapon explanation audit ----
636 | 119079 | 119259 | 0 | - | R758 OA magical items prose audit | // ---- R758 OA magical items prose audit ----
637 | 119260 | 119358 | 0 | - | R759 OA Table 86 items audit | // ---- R759 OA Table 86 items audit ----
638 | 119359 | 119446 | 0 | - | R760 OA Kara-Tur overview audit | // ---- R760 OA Kara-Tur overview audit ----
639 | 119447 | 119513 | 0 | - | R761 OA Shou Lung audit | // ---- R761 OA Shou Lung audit ----
640 | 119514 | 119599 | 0 | - | R762 OA Tu Lung audit | // ---- R762 OA Tu Lung audit ----
641 | 119600 | 119680 | 0 | - | R763 OA Wa audit | // ---- R763 OA Wa audit ----
642 | 119681 | 119748 | 0 | - | R764 OA Kozakura audit | // ---- R764 OA Kozakura audit ----
643 | 119749 | 119804 | 0 | - | R765 OA Gajin audit | // ---- R765 OA Gajin audit ----
644 | 119805 | 119881 | 0 | - | R766 OA Daily Life Food audit | // ---- R766 OA Daily Life Food audit ----
645 | 119882 | 119967 | 0 | - | R767 OA Daily Life Buildings audit | // ---- R767 OA Daily Life Buildings audit ----
646 | 119968 | 120024 | 0 | - | R768 OA Daily Life Manners audit | // ---- R768 OA Daily Life Manners audit ----
647 | 120025 | 120095 | 0 | - | R769 OA Daily Life Names audit | // ---- R769 OA Daily Life Names audit ----
648 | 120096 | 120172 | 0 | - | R770 OA Back matter audit | // ---- R770 OA Back matter audit ----
649 | 120173 | 120219 | 0 | - | R771 OA open boxes audit | // ---- R771 OA open boxes audit ----
650 | 120220 | 120335 | 0 | - | R772 OA Weapons prose audit | // ---- R772 OA Weapons prose audit ----
651 | 120336 | 120397 | 0 | - | R773 OA daily-life misses audit | // ---- R773 OA daily-life misses audit ----
652 | 120398 | 120425 | 0 | - | R774 file-patch seam audit | // ---- R774 file-patch seam audit ----
653 | 120426 | 120450 | 0 | - | R775 RT seam audit | // ---- R775 RT seam audit ----
654 | 120451 | 120481 | 0 | - | R776 mount site audit | // ---- R776 mount site audit ----
655 | 120482 | 120512 | 0 | - | R777 saddle audit | // ---- R777 saddle audit ----
656 | 120513 | 120581 | 0 | - | R778 mounted movement audit | // ---- R778 mounted movement audit ----
657 | 120582 | 120615 | 0 | - | R779 lance charge audit | // ---- R779 lance charge audit ----
658 | 120616 | 120646 | 0 | - | R780 lance speed factors audit | // ---- R780 lance speed factors audit ----
659 | 120647 | 120691 | 0 | - | R781 set spear and speed seam audit | // ---- R781 set spear and speed seam audit ----
660 | 120692 | 120773 | 0 | - | R782 owed pins audit | // ---- R782 owed pins audit ----
661 | 120819 | 121035 | 0 | - | R783 deity stat lines audit | // ---- R783 deity stat lines audit ----
662 | 121036 | 121225 | 0 | - | R784 worship sites audit | // ---- R784 worship sites audit ----
663 | 121270 | 121411 | 0 | - | R785 UA spell table ledger audit | // ---- R785 UA spell table ledger audit ----
664 | 121412 | 121653 | 0 | - | R786 dwarven deity prose audit | // ---- R786 dwarven deity prose audit ----
665 | 121654 | 121890 | 0 | - | R787 elven deity prose audit | // ---- R787 elven deity prose audit ----
666 | 121891 | 122134 | 0 | - | R788 halfling deity prose audit | // ---- R788 halfling deity prose audit ----
667 | 122135 | 122358 | 0 | - | R789 gnomish deity prose audit | // ---- R789 gnomish deity prose audit ----
668 | 122359 | 122565 | 0 | - | R790 orcish deity prose audit | // ---- R790 orcish deity prose audit ----
669 | 122566 | 122632 | 0 | - | R791 registry promotion wiring audit | // ---- R791 registry promotion wiring audit ----
670 | 122633 | 122713 | 0 | - | R792 registry promotion defs audit | // ---- R792 registry promotion defs audit ----
671 | 122714 | 122787 | 0 | - | R793 registry promotion def name fix audit | // ---- R793 registry promotion def name fix audit ----
672 | 122788 | 122855 | 0 | - | R794 tooling data files git add audit | // ---- R794 tooling data files git add audit ----
673 | 122856 | 122916 | 0 | - | R795 rn self-patch guard audit | // ---- R795 rn self-patch guard audit ----
674 | 122917 | 123001 | 0 | - | R796 MM2 arc opener audit | // ---- R796 MM2 arc opener audit ----
675 | 123002 | 123404 | 0 | - | R797 MM2 letter A audit | // ---- R797 MM2 letter A audit ----
676 | 123450 | 124375 | 0 | - | R798 MM2 letters BC audit | // ---- R798 MM2 letters BC audit ----
677 | 124441 | 125181 | 0 | - | R799 MM2 letter D part 1 audit | // ---- R799 MM2 letter D part 1 audit ----
678 | 125231 | 125455 | 0 | - | R800 MM2 letter D part 2 audit | // ---- R800 MM2 letter D part 2 audit ----
679 | 125498 | 125972 | 0 | - | R801 MM2 devil section audit | // ---- R801 MM2 devil section audit ----
680 | 126027 | 126373 | 0 | - | R802 MM2 dinosaur section audit | // ---- R802 MM2 dinosaur section audit ----
681 | 126448 | 126939 | 0 | - | R803 MM2 dragon section audit | // ---- R803 MM2 dragon section audit ----
682 | 127013 | 127356 | 0 | - | R804 MM2 letter E walk audit | // ---- R804 MM2 letter E walk audit ----
683 | 127435 | 127882 | 0 | - | R805 MM2 letters FG walk audit | // ---- R805 MM2 letters FG walk audit ----
684 | 128051 | 128413 | 0 | - | R806 MM2 letters HI walk audit | // ---- R806 MM2 letters HI walk audit ----
685 | 128490 | 128936 | 0 | - | R807 MM2 letters JK walk audit | // ---- R807 MM2 letters JK walk audit ----
686 | 129018 | 129967 | 0 | - | R808 MM2 letters LMN walk audit | // ---- R808 MM2 letters LMN walk audit ----
687 | 130054 | 130386 | 0 | - | R809 MM2 letter O walk audit | // ---- R809 MM2 letter O walk audit ----
688 | 130450 | 131060 | 0 | - | R810 MM2 letter P walk audit | // ---- R810 MM2 letter P walk audit ----
689 | 131149 | 131374 | 0 | - | R811 MM2 letter Q walk audit | // ---- R811 MM2 letter Q walk audit ----
690 | 131435 | 131708 | 0 | - | R812 MM2 letter R walk audit | // ---- R812 MM2 letter R walk audit ----
691 | 131777 | 132677 | 0 | - | R813 MM2 letter S walk audit | // ---- R813 MM2 letter S walk audit ----
692 | 132798 | 133623 | 0 | - | R814 MM2 letters TUV walk audit | // ---- R814 MM2 letters TUV walk audit ----
693 | 133729 | 134312 | 0 | - | R815 MM2 letters WXYZ walk audit | // ---- R815 MM2 letters WXYZ walk audit ----
694 | 134406 | 134951 | 0 | - | R816 MM2 dungeon encounter grids audit | // ---- R816 MM2 dungeon encounter grids audit ----
695 | 135311 | 137176 | 0 | - | R817 MM2 outdoor encounter grids audit | // ---- R817 MM2 outdoor encounter grids audit ----
696 | 138140 | 138925 | 0 | - | R818 MM2 aquatic encounter grids audit | // ---- R818 MM2 aquatic encounter grids audit ----
697 | 139127 | 139356 | 0 | - | R819 MM2 index census audit | // ---- R819 MM2 index census audit ----
698 | 139467 | 139583 | 0 | - | R820 lammasu promotion audit | // ---- R820 lammasu promotion audit ----
699 | 139637 | 139789 | 0 | - | R821 lung promotion audit | // ---- R821 lung promotion audit ----
700 | 139879 | 139951 | 0 | - | R822 audit files wiring audit | // ---- R822 audit files wiring audit ----
701 | 139952 | 140002 | 0 | - | R227 wis mental save wiring audit | // ---- R227: the wis mental save wiring audit ----
702 | 140003 | 140125 | 0 | - | R228 druid registry parameters audit | // ---- R228: the druid registry parameters audit ----
703 | 140126 | 140230 | 0 | - | R229 illusionist registry parameters audit | // ---- R229: the illusionist registry parameters audit ----
704 | 140231 | 140352 | 0 | - | R163 poison table audit | // ---- R163: the poison table audit -------------
705 | 140353 | 140419 | 0 | - | R164 assassination table audit | // ---- R164: the assassination table audit -------
706 | 140420 | 140476 | 0 | - | R165 potion miscibility audit | // ---- R165: potion miscibility audit ------------
707 | 140477 | 140621 | 0 | - | R166 intoxication and insanity audit | // ---- R166: intoxication and insanity audit ------
708 | 140622 | 140810 | 0 | - | R167 disease and infestation audit | // ---- R167: disease and infestation audit --------
709 | 140811 | 140960 | 0 | - | R168 underwater spell use audit | // ---- R168: underwater spell use audit ------------
710 | 140961 | 141125 | 0 | - | R169 humanoid racial preferences audit | // ---- R169: humanoid racial preferences audit ----
711 | 141126 | 141482 | 0 | - | R170 followers by class audit | // ---- R170: followers by class audit ----------------
712 | 141483 | 141915 | 0 | - | R171 appendices K L and M audit | // ---- R171: appendices K L and M audit -------------
713 | 141916 | 142057 | 0 | - | R175 appendix L 5-and-up table audit | // ---- R175: appendix L 5-and-up table audit -----
714 | 142058 | 142451 | 0 | - | R172 appendix J herbs audit | // ---- R172: appendix J herbs audit --------------
715 | 142452 | 142523 | 0 | - | R173 secondary skills audit | // ---- R173: secondary skills audit ------------------
716 | 142524 | 142603 | 0 | - | R146 city flavor audit | // ---- R146: city flavor subtables audit ----
717 | 142604 | 142678 | 0 | - | R174 city fiction notes audit | // ---- R174: city fiction notes audit ----
718 | 142679 | 142772 | 0 | - | R145 weapon table audit | // ---- R145: PHB p.38 weapon table audit ----
719 | 142773 | 142880 | 0 | - | R144 golden melee audit | // ---- R144: p.71 golden melee audit ----
720 | 142881 | 142944 | 0 | - | R143 crypt wing audit | // ---- R143: crypt wing audit ----
721 | 142945 | 143036 | 0 | - | R142 sample dungeon audit | // ---- R142: sample dungeon audit ----
722 | 143037 | 143069 | 0 | - | R141 engagement geometry audit | // ---- R141: engagement geometry audit ----
723 | 143070 | 143132 | 0 | - | R140 final sweep audit | // ---- R140: final sweep audit ----
724 | 143133 | 143186 | 0 | - | R139 engine-deep change-family audit | // ---- R139: engine-deep change-family audit ----
725 | 143187 | 143230 | 0 | - | R138 talk-flavor parley audit | // ---- R138: talk-flavor parley audit ----
726 | 143231 | 143248 | 0 | - | R137 deliberate-engage hook audit | // ---- R137: deliberate-engage hook audit ----
727 | 143249 | 143287 | 0 | - | R136 odds-and-ends slice audit | // ---- R136: odds-and-ends slice audit ----
728 | 143288 | 143324 | 0 | - | R135 room-geometry slice audit | // ---- R135: room-geometry slice audit ----
729 | 143325 | 143357 | 0 | - | R134 deep-effects slice audit | // ---- R134: deep-effects slice audit ----
730 | 143358 | 143395 | 0 | - | R133 third-effects slice audit | // ---- R133: third-effects slice audit ----
731 | 143396 | 143438 | 0 | - | R132 second-effects slice audit | // ---- R132: second-effects slice audit ----
732 | 143439 | 143532 | 0 | - | R129 caster aging audit | // ---- R129: caster aging audit ----
733 | 143533 | 143584 | 0 | - | R100 hire's years audit | // ---- R100: hire's years audit ----
734 | 143585 | 143663 | 0 | - | R101 plate kit audit | // ---- R101: plate kit audit ----
735 | 143664 | 143721 | 0 | - | R102 ledger audit | // ---- R102: ledger of everything audit ----
736 | 143722 | 143793 | 0 | - | R103 carrot audit | // ---- R103: carrot audit ----
737 | 143794 | 143826 | 0 | - | R104 scales audit | // ---- R104: scales audit ----
738 | 143827 | 143889 | 0 | - | R105 crew nerve audit | // ---- R105: crew nerve audit ----
739 | 143890 | 143960 | 0 | - | R106 keep ledger audit | // ---- R106: keep ledger audit ----
740 | 143961 | 144042 | 0 | - | R109 turn audit | // ---- R109: turning undead audit (DMG p.75-76 matrix III) ----
741 | 144043 | 144126 | 0 | - | R110 saves audit | // ---- R110: saving throws audit (DMG p.79-80 matrix I) ----
742 | 144127 | 144192 | 0 | - | R111 attack matrix audit | // ---- R111: fighter attack matrix audit (DMG p.75 I.B) ----
743 | 144193 | 144287 | 0 | - | R112 monster matrix audit | // ---- R112: monster attack matrix audit (DMG p.75-76 II) ----
744 | 144288 | 144417 | 0 | - | R113 class matrix audit | // ---- R113: class attack matrices audit (DMG p.75 I.A/I.C/I.D) ----

## Full text: the first 12 audit blocks, mid samples, last 3

### block 0 (head line 967, 41 lines, delta 0)

    // ---- R79: ammo bundle claims + carried caps -----------------------
    {
        int bad = 0;
        Character c;
        c.name = "Rolf";
        c.hp = 10;
        c.rangedWeapon.id = items::WPN_SHORT_BOW;
        c.missileAmmo = 4;
        // enchanted arrows fit the bow
        if (!claimAmmoBundle(c, "Arrow +2", 12)) ++bad;
        if (c.missileAmmo != 16) ++bad;
        // bolts do not fit a bow
        if (claimAmmoBundle(c, "Bolt +2", 10)) ++bad;
        // a crossbow takes bolts
        c.rangedWeapon.id = items::WPN_CROSSBOW_LIGHT;
        if (!claimAmmoBundle(c, "Bolt +2", 10)) ++bad;
        // the singular specials never claim
        if (claimAmmoBundle(c, "Arrow of Slaying", 1)) ++bad;
        if (claimAmmoBundle(c, "Arrow of Direction", 1)) ++bad;
        // a long bow takes arrows too
        c.rangedWeapon.id = items::WPN_LONG_BOW;
        if (!claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        // the dead claim nothing
        c.hp = 0;
        if (claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        c.hp = 10;
        // quiver cap: the bundle still pockets (true), the count
        // just stops at the cap
        c.quiver.clear();   // R80: bundle semantics
        c.missileAmmo = QUIVER_CAP;
        if (!claimAmmoBundle(c, "Arrow +1", 20)) ++bad;
        if (c.missileAmmo != QUIVER_CAP) ++bad;
        // carried-stack cap: clamps up, never down
        int stack = CARRIED_CAP - 4;
        addCapped(stack, 100, CARRIED_CAP);
        if (stack != CARRIED_CAP) ++bad;
        addCapped(stack, -50, CARRIED_CAP);
        if (stack != CARRIED_CAP - 50) ++bad;
        printf("R79 claim/caps audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 1 (head line 1009, 32 lines, delta 0)

    // ---- R80: quiver bundle math --------------------------------------
    {
        int bad = 0;
        Character c;
        c.hp = 10;
        // same-plus merge + tail-trim cap
        quiverAdd(c.quiver, 0, 4);
        quiverAdd(c.quiver, 2, 3);
        quiverAdd(c.quiver, 0, 2);      // merges into the 0-band
        if (quiverTotal(c.quiver) != 9) ++bad;
        if (quiverNextPlus(c.quiver) != 0) ++bad;
        quiverAdd(c.quiver, 5, 1000);   // over the cap: tail trims
        if (quiverTotal(c.quiver) != QUIVER_CAP) ++bad;
        // front-first consumption: mundane before magic
        c.quiver.clear();
        quiverAdd(c.quiver, 0, 4);
        quiverAdd(c.quiver, 2, 3);
        quiverConsumeShots(c.quiver, 5);
        if (quiverTotal(c.quiver) != 2) ++bad;
        if (quiverNextPlus(c.quiver) != 2) ++bad;
        quiverConsumeShots(c.quiver, 99);   // drains
        if (quiverTotal(c.quiver) != 0) ++bad;
        // restock refills the mundane band only
        quiverRestock(c.quiver, 20);
        if (quiverTotal(c.quiver) != 20) ++bad;
        quiverAdd(c.quiver, 2, 3);
        quiverRestock(c.quiver, 20);   // leaves the +2 band alone
        if (quiverTotal(c.quiver) != 23) ++bad;
        if (quiverNextPlus(c.quiver) != 0) ++bad;
        printf("R80 quiver audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 2 (head line 1099, 44 lines, delta 0)

    // ---- R81: ring claims, scroll picks, status helpers --------
    {
        int bad = 0;
        Character c;
        c.hp = 10;
        // a member takes the ring
        if (!claimRing(c, "Ring of Protection", 1)) ++bad;
        if (c.ringPlus != 1) ++bad;
        // one ring per member
        if (claimRing(c, "Ring of Protection", 1)) ++bad;
        c.ringPlus = 0;
        // other rings never claim
        if (claimRing(c, "Ring of Fire Resistance", 1)) ++bad;
        // bundles never claim
        if (claimRing(c, "Ring of Protection", 2)) ++bad;
        // the dead claim nothing
        c.hp = 0;
        if (claimRing(c, "Ring of Protection", 1)) ++bad;
        c.hp = 10;
        // scroll-study pick: the lowest-level unknown MU spell,
        // deterministic id order
        c.classIndex = 1;
        c.knownSpells.clear();
        int sid = pickStudySpell(c);
        if (sid < 0) ++bad;
        const spells::SpellDef& s0 =
            spells::spell((spells::SpellId)sid);
        if (s0.sclass != spells::SPELL_MU || s0.level != 1) ++bad;
        c.knownSpells.push_back(sid);
        int sid2 = pickStudySpell(c);
        if (sid2 == sid) ++bad;   // moves on to the next unknown
        // a complete book yields -1
        for (int id = 0; id < spells::SPELL_COUNT; ++id)
            if (spells::spell((spells::SpellId)id).sclass ==
                spells::SPELL_MU)
                c.knownSpells.push_back(id);
        if (pickStudySpell(c) != -1) ++bad;
        // fire shield reflect math: half, rounded up, min 1
        if (spelleffects::fireShieldDamage(1) != 1) ++bad;
        if (spelleffects::fireShieldDamage(5) != 3) ++bad;
        if (spelleffects::fireShieldDamage(8) != 4) ++bad;
        printf("R81 rings/scrolls/status audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 3 (head line 1144, 32 lines, delta 0)

    // ---- R82: death and revival -----------------------------------
    {
        int bad = 0;
        // Death Spell HD budget: 4 x caster level, min level 1
        if (spelleffects::deathSpellBudget(1) != 4) ++bad;
        if (spelleffects::deathSpellBudget(6) != 24) ++bad;
        if (spelleffects::deathSpellBudget(12) != 48) ++bad;
        if (spelleffects::deathSpellBudget(0) != 4) ++bad;   // clamp
        // Raise Dead eligibility: living cleric 7th+
        Character c;
        c.classIndex = 2;
        c.level = 6;
        c.hp = 10;
        if (canRaiseDead(c)) ++bad;
        c.level = 7;
        if (!canRaiseDead(c)) ++bad;
        // a fighter never raises
        c.classIndex = 0;
        if (canRaiseDead(c)) ++bad;
        // the dead cleric cannot raise
        c.classIndex = 2;
        c.hp = 0;
        if (canRaiseDead(c)) ++bad;
        // resurrection survival table sanity (PHB CON table):
        // every value is a percent in 35..100
        for (int con = 3; con <= 18; ++con) {
            int sv = rules::conResSurvival((uint8_t)con);
            if (sv < 30 || sv > 100) ++bad;
        }
        printf("R82 death/revival audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 4 (head line 1177, 30 lines, delta 0)

    // ---- R83: teleport + L4-6 casting gates audit ----
    {
        int bad = 0;
        // the Teleport registry row (values from kSpells)
        const spells::SpellDef& tp =
            spells::spell(spells::MU_TELEPORT);
        if (std::string(tp.name) != "Teleport") ++bad;
        if (tp.sclass != spells::SPELL_MU) ++bad;
        if (tp.level != 5) ++bad;
        if (tp.castingTime < 1) ++bad;
        if (tp.saveCategory != -1) ++bad;
        if (tp.target != spells::TARGET_SPECIAL) ++bad;
        if (tp.reversible) ++bad;
        // L5 MU slots start at class level 9 (kMuSlots row 9)
        if (spells::spellSlots(spells::SPELL_MU, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 8, 5) != 0) ++bad;
        // INT gates the L5 (PHB p.10): 15 reaches L5, 16 reaches L6
        if (spells::maxSpellLevelForInt(15) != 5) ++bad;
        if (spells::maxSpellLevelForInt(16) != 6) ++bad;
        // every registry row sits in 1..9 (the R83 gate
        // domain, widened R129 alongside the R80 band: the
        // six p.14 caster-aging spells ride as levels 7-9)
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s2 =
                spells::spell((spells::SpellId)id);
            if (s2.level < 1 || s2.level > 9) ++bad;
        }
        printf("R83 teleport audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 5 (head line 1208, 82 lines, delta 0)

    // ---- R85: the pack audit ----
    {
        int bad = 0;
        // packAdd honors the cap
        Character c;
        c.hp = 10;
        PackItem p0{};
        p0.kind = 0;
        p0.id = (int)items::WPN_LONG_SWORD;
        p0.plus = 1;
        p0.gp = 100;
        int added = 0;
        while (packAdd(c, p0) && added < 99) ++added;
        if (added != PACK_CAP) ++bad;
        if (packAdd(c, p0)) ++bad;   // full pack refuses
        // names reconstruct from the tables
        PackItem w{};
        w.kind = 0;
        w.id = (int)items::WPN_LONG_SWORD;
        w.plus = 2;
        w.gp = 500;
        if (packItemName(w) != "Long Sword +2") ++bad;
        PackItem a{};
        a.kind = 1;
        a.id = (int)items::ARMOR_CHAIN_MAIL;
        a.plus = 0;
        a.gp = 75;
        if (packItemName(a) != "Chain Mail") ++bad;
        PackItem s{};
        s.kind = 2;
        s.id = 0;
        s.plus = 1;
        s.gp = 50;
        if (packItemName(s) != "Shield +1") ++bad;
        PackItem sb{};
        sb.kind = 2;
        sb.id = 0;
        sb.plus = 0;
        sb.gp = 10;
        if (packItemName(sb) != "Shield") ++bad;
        // improves routing
        c.pack.clear();
        c.weapon.id = items::WPN_LONG_SWORD;
        c.weapon.plus = 0;
        if (!packImproves(c, w)) ++bad;   // +2 over mundane
        c.weapon.plus = 2;
        if (packImproves(c, w)) ++bad;    // equal plus: no swap
        c.shield = false;
        c.shieldPlus = 0;
        if (!packImproves(c, s)) ++bad;   // no shield: wear it
        c.shield = true;
        c.shieldPlus = 3;
        if (packImproves(c, s)) ++bad;    // worse plus: no
        // armor routing via effectiveAc
        c.armor.id = items::ARMOR_LEATHER;
        c.armor.plus = 0;
        PackItem a2{};
        a2.kind = 1;
        a2.id = (int)items::ARMOR_CHAIN_MAIL;
        a2.plus = 0;
        a2.gp = 75;
        if (!packImproves(c, a2)) ++bad;  // chain beats leather
        c.armor.id = items::ARMOR_PLATE;
        if (packImproves(c, a2)) ++bad;   // plate wins: no
        // ranged routing: missile weapons look at the RANGED slot
        PackItem b{};
        b.kind = 0;
        b.id = (int)items::WPN_SHORT_BOW;
        b.plus = 1;
        b.gp = 100;
        c.rangedWeapon.id = items::WPN_SHORT_BOW;
        c.rangedWeapon.plus = 0;
        c.weapon.plus = 5;   // melee far better - must not matter
        if (!packImproves(c, b)) ++bad;
        c.rangedWeapon.plus = 3;
        if (packImproves(c, b)) ++bad;
        // dead members never improve
        c.hp = 0;
        if (packImproves(c, w)) ++bad;
        printf("R85 pack audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 6 (head line 1291, 47 lines, delta 0)

    // ---- R86: cursed/hire audit ----
    {
        int bad = 0;
        // the cursed-name routing the claim guard depends on:
        // cursed items never reach the gear cases, so they can
        // never become pack cargo (the carry invariant)
        {
            dm::treasure::MagicItem mi;
            mi.name = "Sword +1, Cursed";
            if (!mi.cursed()) ++bad;
            mi.name = "Shield -1, Vulnerability";
            if (!mi.cursed()) ++bad;
            mi.name = "Hematite attractor of Armor";
            if (!mi.cursed()) ++bad;
            mi.name = "Sword -2, Backbiter";
            if (!mi.cursed()) ++bad;
            mi.name = "Sword +2, Frost Brand";
            if (mi.cursed()) ++bad;
            mi.name = "Chain Mail +2";
            if (mi.cursed()) ++bad;
        }
        // defense in depth: a negative-plus item never improves
        // a kit even if some future path offered it as cargo
        {
            Character c;
            c.hp = 10;
            c.weapon.id = items::WPN_LONG_SWORD;
            c.weapon.plus = 0;
            PackItem cw{};
            cw.kind = 0;
            cw.id = (int)items::WPN_LONG_SWORD;
            cw.plus = -1;
            cw.gp = 300;
            if (packImproves(c, cw)) ++bad;
            // any shield beats none (even a cursed one would),
            // so wear a mundane shield first: -1 must lose
            c.shield = true;
            c.shieldPlus = 0;
            PackItem cs{};
            cs.kind = 2;
            cs.plus = -1;
            cs.gp = 50;
            if (packImproves(c, cs)) ++bad;
        }
        printf("R86 cursed/hire audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 7 (head line 1339, 84 lines, delta 0)

    // ---- R87: burden audit ----
    {
        int bad = 0;
        // item weights come from the tables (gp units)
        PackItem w1{};
        w1.kind = 0;
        w1.id = (int)items::WPN_LONG_SWORD;
        if (packItemWeight(w1) != 75) ++bad;    // PHB p.37
        PackItem a1{};
        a1.kind = 1;
        a1.id = (int)items::ARMOR_PLATE;
        if (packItemWeight(a1) != 450) ++bad;   // PHB p.36
        PackItem s1{};
        s1.kind = 2;
        if (packItemWeight(s1) != 100) ++bad;
        PackItem badId{};
        badId.kind = 0;
        badId.id = 999;
        if (packItemWeight(badId) != 0) ++bad;  // out of range
        // band + movement sanity (STR 10 scale = 350/700/1050)
        if (items::encumbranceBand(0, 10) !=
            items::ENC_UNENCUMBERED) ++bad;
        if (items::encumbranceBand(700, 10) != items::ENC_LIGHT)
            ++bad;
        if (items::encumbranceBand(1050, 10) !=
            items::ENC_MODERATE) ++bad;
        if (items::encumbranceBand(1051, 10) !=
            items::ENC_HEAVY) ++bad;
        if (items::movementForBand(items::ENC_UNENCUMBERED) != 120)
            ++bad;
        if (items::movementForBand(items::ENC_HEAVY) != 30) ++bad;
        // STR 18 scales the bands up (heavy 1050 -> 1890)
        if (items::encumbranceBand(1890, 18) !=
            items::ENC_MODERATE) ++bad;
        // the packAdd encumbrance gate: a STR 10 member in
        // plate kit (dagger 20 + plate 450 = 470 worn) can
        // carry ONE spare plate (920, moderate) - the second
        // would go heavy (1370 > 1050) and is refused
        {
            Character c;
            c.hp = 10;
            c.armor.id = items::ARMOR_PLATE;
            if (carriedWeight(c) != 470) ++bad;
            if (!packAdd(c, a1)) ++bad;    // 920: moderate, ok
            if (packAdd(c, a1)) ++bad;     // 1370: heavy, no
            if (c.pack.size() != 1) ++bad;
        }
        // STR 18 shoulders more before the gate trips
        {
            Character c;
            c.hp = 10;
            c.abilities.str = 18;
            c.armor.id = items::ARMOR_PLATE;
            if (!packAdd(c, a1)) ++bad;    // 920
            if (!packAdd(c, a1)) ++bad;    // 1370
            if (!packAdd(c, a1)) ++bad;    // 1820 <= 1890
            if (packAdd(c, a1)) ++bad;     // 2270: heavy, no
            if (c.pack.size() != 3) ++bad;
        }
        // the R85 cap still binds first for mundane loot
        {
            Character c;
            c.hp = 10;
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            int added = 0;
            while (packAdd(c, sw) && added < 99) ++added;
            if (added != PACK_CAP) ++bad;  // 470 gp: cap, not wt
        }
        // the hire's load: sword 75 + plate 450 + shield 100
        // = 625 worn; STR 12 heavy threshold is 1260
        {
            Party p;
            p.henchmanPresent = true;
            p.henchmanPlate = true;   // plate kit (R46 ladder top)
            if (henchmanCarryWeight(p) != 625) ++bad;
            if (!henchmanCanShoulder(p, a1)) ++bad;   // 1075
            p.henchmanPack.push_back(a1);
            if (henchmanCanShoulder(p, a1)) ++bad;    // 1525
        }
        printf("R87 burden audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 8 (head line 1424, 82 lines, delta 0)

    // ---- R88: warning audit ----
    {
        int bad = 0;
        // the company moves at the slowest living member's
        // band; dead members and empty packs do not slow it
        {
            Party p;
            // default kit: dagger + no armor = 20 gp
            if (partyMoveRate(p) != 120) ++bad;   // nobody: base
            Character a;
            a.hp = 10;                            // STR 10, kit
            if (carriedWeight(a) != 20) ++bad;
            p.members.push_back(a);
            int wa = carriedWeight(a);
            int ma = partyMoveRate(p);
            if (ma != items::movementForBand(
                    items::encumbranceBand(wa, 10))) ++bad;
            // a HEAVY companion drags the whole company to 30
            Character h;
            h.hp = 10;
            h.abilities.str = 10;
            h.armor.id = items::ARMOR_PLATE;      // 470 worn
            PackItem a1{};
            a1.kind = 1;
            a1.id = (int)items::ARMOR_PLATE;
            if (!packAdd(h, a1)) ++bad;            // 920: moderate
            if (packAdd(h, a1)) ++bad;             // 1370: refused
            // push the weight over heavy via direct pack
            // push (bypasses the R87 gate on purpose)
            PackItem big{};
            big.kind = 1;
            big.id = (int)items::ARMOR_PLATE;
            h.pack.push_back(big);                // 1370: heavy
            if (items::encumbranceBand(carriedWeight(h), 10) !=
                items::ENC_HEAVY) ++bad;
            p.members.push_back(h);
            if (partyMoveRate(p) != 30) ++bad;
            // the dead do not slow the company
            Character d;
            d.hp = 0;
            d.armor.id = items::ARMOR_PLATE;
            PackItem many{};
            many.kind = 1;
            many.id = (int)items::ARMOR_PLATE;
            for (int i = 0; i < 6; ++i) d.pack.push_back(many);
            p.members.push_back(d);
            if (partyMoveRate(p) != 30) ++bad;    // h still slow
            p.members.pop_back();
            p.members.pop_back();                 // drop h
            if (partyMoveRate(p) !=
                items::movementForBand(
                    items::encumbranceBand(wa, 10))) ++bad;
        }
        // the [E] swap weight pin: equipping plate from the
        // pack CONSERVES carriedWeight (the old leather kit
        // returns to the pack as the keepsake) - the swap
        // can never create a HEAVY load by itself; the [E]
        // warning is a state echo, not a cause
        {
            Character c;
            c.hp = 10;
            c.armor.id = items::ARMOR_LEATHER;
            PackItem a1{};
            a1.kind = 1;
            a1.id = (int)items::ARMOR_PLATE;
            c.pack.push_back(a1);
            int before = carriedWeight(c);        // 20+150+450
            if (before != 620) ++bad;
            // simulate the townSwapGear armor branch
            PackItem old{};
            old.kind = 1;
            old.id = (int)c.armor.id;
            old.plus = c.armor.plus;
            c.armor.id = (items::ArmorId)a1.id;
            c.armor.plus = a1.plus;
            c.pack[0] = old;
            int after = carriedWeight(c);
            if (after != before) ++bad;            // conserved
        }
        printf("R88 warning audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 9 (head line 1507, 62 lines, delta 0)

    // ---- R89: pace audit ----
    {
        int bad = 0;
        // the coin share: 10 coins per gp unit, split across
        // the living only
        {
            Party p;
            if (coinWeightShare(p) != 0) ++bad;   // no gold
            p.gold = 4000;
            if (coinWeightShare(p) != 0) ++bad;   // nobody living
            Character a, b2, c2, d2;
            a.hp = 10; b2.hp = 10; c2.hp = 10; d2.hp = 10;
            p.members.push_back(a);
            p.members.push_back(b2);
            p.members.push_back(c2);
            p.members.push_back(d2);
            if (coinWeightShare(p) != 100) ++bad;  // 4000/10/4
            p.members[3].hp = 0;                   // the dead
            if (coinWeightShare(p) != 133) ++bad;  // 4000/10/3
            p.gold = 4999;                         // floor
            if (coinWeightShare(p) != 166) ++bad;  // 4999/30
        }
        // the true load: kit + cargo + coin share
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            // default kit: dagger 20 gp
            if (memberLoad(p, c) != 20) ++bad;
            p.gold = 1000;
            if (memberLoad(p, c) != 120) ++bad;    // +100 coin
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            c.pack.push_back(sw);
            if (memberLoad(p, c) != 195) ++bad;    // +75 cargo
        }
        // the pace cost: 120'->10, 90'->13, 60'->20, 30'->40
        if (paceStepTenths(120) != 10) ++bad;
        if (paceStepTenths(90)  != 13) ++bad;
        if (paceStepTenths(60)  != 20) ++bad;
        if (paceStepTenths(30)  != 40) ++bad;
        // coins slow the company: a lone STR 10 member hauling
        // 20,000 gp carries 2000 wt -> HEAVY -> 30' -> four
        // wander bites per step
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            if (partyMoveRate(p) != 120) ++bad;
            p.gold = 20000;
            if (partyMoveRate(p) != 30) ++bad;
            if (paceStepTenths(partyMoveRate(p)) != 40) ++bad;
            // spending it all in town is instant relief
            p.gold = 0;
            if (partyMoveRate(p) != 120) ++bad;
        }
        printf("R89 pace audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 10 (head line 1570, 45 lines, delta 0)

    // ---- R90: clock audit ----
    {
        int bad = 0;
        // the camp costs: 48 turns complete, 4 interrupted
        if (restTurns(false) != 48) ++bad;
        if (restTurns(true)  != 4)  ++bad;
        // the tick math: a 90' company (13 tenths/step) ticks
        // late but never loses time - 10 steps = 13 turns
        {
            int debt = 0;
            int ticks = 0;
            for (int i = 0; i < 10; ++i)
                ticks += ticksFromDebt(debt, 13);
            if (ticks != 13 || debt != 0) ++bad;
        }
        // a 30' company (40 tenths) ticks 4 per step, no debt
        {
            int debt = 0;
            if (ticksFromDebt(debt, 40) != 4) ++bad;
            if (debt != 0) ++bad;
        }
        // a 120' company (10 tenths) ticks exactly 1 per step
        {
            int debt = 0;
            for (int i = 0; i < 100; ++i) {
                if (ticksFromDebt(debt, 10) != 1) ++bad;
                if (debt != 0) ++bad;
            }
        }
        // the debt never leaks across an odd pace change:
        // 3 steps at 13 -> 3 ticks, debt 9; one more at 10
        // -> 9+10=19 -> a tick, debt 9 again (the remainder
        // carries; time is conserved, never lost)
        {
            int debt = 0;
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 13->3
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 16->6
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 19->9
            if (debt != 9) ++bad;
            if (ticksFromDebt(debt, 10) != 1) ++bad;  // 19->9
            if (debt != 9) ++bad;
        }
        printf("R90 clock audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 11 (head line 1616, 16 lines, delta 0)

    // ---- R91: stairs audit ----
    {
        int bad = 0;
        // the descent costs 6 hours (36 turns) - rest parity:
        // hours of time, pace-free, one wander bite at the end
        if (descentTurns() != 36) ++bad;
        // the clock model is coherent: camp 48, interrupted
        // watch 4, stairs 36 - all under a 120' day (144 turns)
        if (restTurns(false) + descentTurns() > 144) ++bad;
        if (restTurns(true) + descentTurns() > 144) ++bad;
        // a descend-then-camp day (36 + 48) plus a 60-step
        // unburdened march (60) still fits the day
        if (36 + 48 + 60 > 144) ++bad;
        printf("R91 stairs audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 200 (head line 23415, 152 lines, delta 0)

    // ---- R318: the net entrap layer audit
    // ----
    // The MM hooked nets: the R315 net
    // throwers entrapt on a volley hit
    // (resolveMissile, no wound - nets are
    // used to entrap); STATUS_ENTANGLED
    // bars action (the held precedent); a
    // strength of 16 or greater tears free
    // at the round start (uwNetEntrapStrTear,
    // the stepRound fold BEFORE the end
    // conditions); weaker victims stay held
    // (no escape roll - the print bars it).
    // The volley hit rides the R37 dice (the
    // R315 convention).
    {
        int bad = 0;
        // N1: the gate - an entrapped actor
        // cannot act (Actor-level, no dice)
        {
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.hp = 10; a.maxHp = 10;
            a.str = 10;
            if (!a.canAct()) ++bad;
            spelleffects::StatusEffect st;
            st.kind =
                spelleffects::STATUS_ENTANGLED;
            a.addStatus(st);
            if (a.canAct()) ++bad;
        }
        // N2: the tear - STR 17 tears free at
        // the round start (no dice: the fold
        // reads the pin)
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.classIndex = 0; a.level = 1;
            a.dex = 10;
            a.str = 17;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            spelleffects::StatusEffect st;
            st.kind =
                spelleffects::STATUS_ENTANGLED;
            st.roundsRemaining = 0;   // until torn
            a.addStatus(st);
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.stepRound();
            bool torn = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("tears free of the net")
                    != std::string::npos)
                    torn = true;
            if (!torn) ++bad;
            if (enc.party().empty() ||
                enc.party()[0].hasStatus(
                    spelleffects::STATUS_ENTANGLED))
                ++bad;
        }
        // N3: the hold - STR 10 stays
        // entrapped (the hooks, no escape
        // roll exists)
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.classIndex = 0; a.level = 1;
            a.dex = 10;
            a.str = 10;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            spelleffects::StatusEffect st;
            st.kind =
                spelleffects::STATUS_ENTANGLED;
            st.roundsRemaining = 0;   // until torn
            a.addStatus(st);
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.stepRound();
            for (const auto& ln : enc.log())
                if (ln.text.find("tears free of the net")
                    != std::string::npos)
                    ++bad;
            if (enc.party().empty() ||
                !enc.party()[0].hasStatus(
                    spelleffects::STATUS_ENTANGLED))
                ++bad;
            // R318b: the hooks re-assert - the
            // hold must survive a second
            // round-end tick
            enc.stepRound();
            for (const auto& ln : enc.log())
                if (ln.text.find("tears free of the net")
                    != std::string::npos)
                    ++bad;
            if (enc.party().empty() ||
                !enc.party()[0].hasStatus(
                    spelleffects::STATUS_ENTANGLED))
                ++bad;
        }
        // N4: the pins (the MM data)
        {
            if (rules::uwNetEntrapStrTear() != 16)
                ++bad;
        }
        // N5: the mark - the sahuagin net
        // thrower carries the entrap flag in
        // the water fight, not on land
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
            st.party.members.push_back(arc);
            st.party.x = 5; st.party.y = 5;
            st.map.set(5, 5, world::TILE_WATER);
            std::vector<ai::Actor> foes;
            ai::Actor m;
            m.team = 1; m.hitDice = 2;
            m.hp = 11; m.maxHp = 11;
            foes.push_back(m);
            st.beginCombat(std::move(foes), -1,
                           "sahuagin");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                !st.combat.encounter->monsters()[0]
                    .netVolley) ++bad;
        }
        printf("R318 net entrap layer audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 350 (head line 53399, 103 lines, delta 0)

    // ---- R470 WSG purifying water pin audit ----
    // The purification baseline (the 10% taint remainder after a sufficient
    // boil, the 2-5 round boil at sea level plus the elevation time adder,
    // the early-removal nullification, the evaporation cost ladder at the
    // 5,000-foot break), the tainted-water effects (the mild 6-hour and
    // severe 18-hour minimum durations vs the food 12/24), the taint-severity
    // geography (low elevation and warm climates) and the bad-water warnings
    // (the taste-and-appearance deception, the bacteria and poison layer, the
    // skeletal-remains waterhole) - every const and bool verified against the
    // model.
    {
        using namespace rules;
        int bad = 0;
    if (wpuBoilTaintRemainPct() != 10
            || wpuBoilRoundsMin() != 2
            || wpuBoilRoundsMax() != 5
            || wpuElevStepFt() != 1000
            || wpuEvapBreakFt() != 5000
            || wpuEvapLowPctPerMin() != 5
            || wpuEvapHighPctPerMin() != 3
            || wpuMildMinHours() != 6
            || wpuMildFoodBaseHours() != 12
            || wpuSevereMinHours() != 18
            || wpuSevereFoodBaseHours() != 24
            || !wpuSuspectTaintAlmostAlways()
            || !wpuBoilBestNonmagical()
            || !wpuEarlyRemovalNoGood()
            || !wpuQuantityOverQuality()
            || !wpuEffectsMatchTaintedFood()
            || !wpuSeverityDMRuling()
            || !wpuSevereLikelyLowWarm()
            || !wpuColdDoesNotKill()
            || !wpuTasteNotIndicator()
            || !wpuBacteriaAndPoisonLayer()
            || !wpuWaterholeDeadGiveaway()
            || !wpuCautionCommonSense()
        )
            ++bad;
        // the boil time at sea level: 2-5 rounds (1d4+1)
    if (wpuBoilRoundsMin() != 2
            || wpuBoilRoundsMax() != 5
            || wpuBoilRoundsMin() >= wpuBoilRoundsMax()
        )
            ++bad;
        // the taint remainder after a sufficient boil: only 10%
    if (wpuBoilTaintRemainPct() != 10
        )
            ++bad;
        // the evaporation ladder: the 5,000-foot break with 5% below and 3%
        // above
    if (wpuEvapBreakFt() != 5000
            || wpuEvapLowPctPerMin() != 5
            || wpuEvapHighPctPerMin() != 3
            || wpuEvapLowPctPerMin() <= wpuEvapHighPctPerMin()
        )
            ++bad;
        // the elevation adder: an extra 1d2 minutes per 1,000 feet
    if (wpuElevStepFt() != 1000
        )
            ++bad;
        // the mild taint: a 6-hour minimum against the 12-hour food baseline
    if (wpuMildMinHours() != 6
            || wpuMildFoodBaseHours() != 12
            || wpuMildMinHours() >= wpuMildFoodBaseHours()
        )
            ++bad;
        // the severe taint: an 18-hour minimum against the 24-hour food
        // baseline
    if (wpuSevereMinHours() != 18
            || wpuSevereFoodBaseHours() != 24
            || wpuSevereMinHours() >= wpuSevereFoodBaseHours()
        )
            ++bad;
        // the severe ladder climbs above the mild ladder
    if (wpuSevereMinHours() <= wpuMildMinHours()
        )
            ++bad;
        // the boil mechanics: the best nonmagical purification, the
        // early-removal nullification and the quantity-over-quality tradeoff
    if (wpuBoilBestNonmagical() != 1
            || wpuEarlyRemovalNoGood() != 1
            || wpuQuantityOverQuality() != 1
        )
            ++bad;
        // the taint-severity geography: the low-warm likelihood and the
        // cold-does-not-kill exception
    if (wpuSevereLikelyLowWarm() != 1
            || wpuColdDoesNotKill() != 1
            || wpuSeverityDMRuling() != 1
        )
            ++bad;
        // the bad-water warnings: the taste deception, the
        // bacteria-and-poison layer, the skeletal-remains waterhole and the
        // caution-and-common-sense close
    if (wpuTasteNotIndicator() != 1
            || wpuBacteriaAndPoisonLayer() != 1
            || wpuWaterholeDeadGiveaway() != 1
            || wpuCautionCommonSense() != 1
        )
            ++bad;
        printf("R470 WSG purifying water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 500 (head line 96525, 626 lines, delta 0)

    // ---- R622 OA ninja audit ----
    // OA round nine (capture pp. 35-39): the ninja - the dual-class doctrine,
    // the capability ladders of Tables 22, 23 and 24, the ki powers, the
    // honor mechanics and the nukenin
    {
        using namespace rules;
        int bad = 0;
    if (dgiNinjaMinDex() != 14
            || dgiNinjaMinCha() != 14
            || dgiNinjaMinInt() != 15
            || dgiNinjaXpSplitDiv() != 2
            || dgiNinjaHpMin() != 1
            || dgiNinjaHpMax() != 2
            || dgiNinjaOtherHpDiv() != 2
            || dgiNinjaExampleHpMin() != 2
            || dgiNinjaExampleHpMax() != 7
            || dgiNinjaSlots() != 2
            || dgiNinjaNightingaleDiv() != 2
            || dgiNinjaTightropeAngle() != 45
            || dgiNinjaTightropeCheckFeet() != 60
            || dgiNinjaTightropeMove() != 60
            || dgiNinjaTightropeBalanceBonus() != 10
            || dgiNinjaTightropeModerateWind() != -10
            || dgiNinjaTightropeStrongWind() != -20
            || dgiNinjaTightropeGustingWind() != -30
            || dgiNinjaTightropeFightPenalty() != -5
            || dgiNinjaVaultRunFeet() != 30
            || dgiNinjaVaultPoleExtraFeet() != 4
            || dgiNinjaVaultObstacleReduction() != 1
            || dgiNinjaVaultDistanceMult() != 2
            || dgiNinjaEscapeRoundsDie() != 10
            || dgiNinjaOpenLocksPerLevel() != 1
            || dgiNinjaDisguiseSexDiv() != 2
            || dgiNinjaDisguisePersonDiv() != 2
            || dgiNinjaDisguiseObserveDays() != 30
            || dgiNinjaKiBreathLevel() != 1
            || dgiNinjaKiWaterLevel() != 5
            || dgiNinjaKiWaterFeetPerLevel() != 5
            || dgiNinjaKiWaterMove() != 30
            || dgiNinjaKiWaterPerDayMult() != 1
            || dgiNinjaKiWallLevel() != 12
            || dgiNinjaKiWallPrepRounds() != 3
            || dgiNinjaKiWallDurationRounds() != 1
            || dgiNinjaKiWallFeetPerLevel() != 1
            || dgiNinjaNukeXpMult() != 2
            || dgiT22RowCount() != 12
            || dgiT22XpBeyond() != 300000
            || dgiT22HpBeyond() != 1
            || dgiT23RowCount() != 10
            || dgiT23FirstScore() != 9
            || dgiT24RowCount() != 20
            || dgiT24VaultHalfFoot() != 2
            || !dgiNinjaHumanOnly()
            || !dgiNinjaSplitClassOnly()
            || !dgiNinjaNoPrimeBonus()
            || !dgiNinjaNoConBonusHp()
            || !dgiNinjaOtherHpRoundedUp()
            || !dgiNinjaThiefSaves()
            || !dgiNinjaOtherCombatTable()
            || !dgiNinjaWeaponsNoHonorLoss()
            || !dgiNinjaCrossSlotHonorLoss()
            || !dgiNinjaOtherClassArmor()
            || !dgiNinjaMagicItemsUnion()
            || !dgiNinjaSilentNoMetal()
            || !dgiNinjaHideWatched()
            || !dgiNinjaHideInfravision()
            || !dgiNinjaTrapsSmallOnly()
            || !dgiNinjaTrapsOneAttempt()
            || !dgiNinjaClimbChainMail()
            || !dgiNinjaClimbMidpointCheck()
            || !dgiNinjaDisguiseClassOnly()
            || !dgiNinjaDisguiseFailForever()
            || !dgiNinjaAssassinatePlanned()
            || !dgiNinjaVaultNoMetal()
            || !dgiNinjaFallChainMail()
            || !dgiNinjaFallVerticalSurface()
            || !dgiNinjaEscapeOneAttempt()
            || !dgiNinjaOpenLocksLockedForever()
            || !dgiNinjaBackstabUnnoticed()
            || !dgiNinjaKiBreathOnceDaily()
            || !dgiNinjaKiWaterBrokenByInjury()
            || !dgiNinjaKiWallCostsAllKi()
            || !dgiNinjaFamilyRule()
            || !dgiNinjaIdentityCost()
            || !dgiNinjaMissionRetryable()
            || !dgiNinjaMissionRefusalAllHonor()
            || !dgiNinjaHonorAboveFamily()
            || !dgiNinjaNukeDeathOrNukenin()
            || !dgiNinjaMissionsFromHead()
        )
            ++bad;
        // the Table 22 grid: the xp bounds and the hit points per level
        // (capture pp. 35-36)
        int CT22[12][2] = {
            {4000,2},
            {8000,2},
            {15000,2},
            {30000,2},
            {60000,2},
            {120000,2},
            {240000,2},
            {500000,2},
            {1000000,2},
            {1300000,1},
            {1600000,1},
            {1900000,1},
            };
        int nT22[2] = {0,0};
        int eT22[2] = {0,0};
        for (int b = 0;
             b < dgiT22RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgiT22XpMax(b);
            vals[1] = dgiT22HpMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT22[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT22[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT22[c] != eT22[c])
                ++bad;
        // the Table 23 grid: the five thief-skill Dexterity adjustments
        // (capture p. 36)
        int CT23[10][5] = {
            {-15,-10,-20,-10,-15},
            {-10,-10,-15,-5,-10},
            {-5,-5,-10,0,-5},
            {0,0,-5,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {5,0,5,5,5},
            {10,5,10,10,10},
            };
        int nT23[5] = {0,0,0,0,0};
        int eT23[5] = {0,0,0,0,0};
        for (int b = 0;
             b < dgiT23RowCount();
             ++b) {
            int vals[5];
            vals[0] = dgiT23Pockets(b);
            vals[1] = dgiT23Traps(b);
            vals[2] = dgiT23Silent(b);
            vals[3] = dgiT23Hide(b);
            vals[4] = dgiT23Locks(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT23[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT23[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nT23[c] != eT23[c])
                ++bad;
        // the Table 24 grid: the eleven capability columns, levels 1-20
        // (capture pp. 38-39)
        int CT24[20][11] = {
            {10,15,20,85,20,25,20,16,0,10,2},
            {15,21,25,86,24,29,25,18,0,14,2},
            {20,27,30,87,28,33,30,19,10,18,2},
            {25,33,35,88,32,37,35,20,15,22,2},
            {31,40,40,89,36,42,40,21,20,26,3},
            {37,47,45,90,40,47,45,22,25,30,3},
            {43,55,50,91,44,52,50,23,30,34,3},
            {49,62,55,92,48,57,55,24,35,38,3},
            {56,70,60,93,52,62,60,25,40,42,3},
            {63,78,65,94,56,67,65,26,45,46,4},
            {70,86,70,95,60,72,70,27,50,50,4},
            {77,94,75,96,64,77,75,28,55,54,4},
            {85,95,80,97,68,82,80,29,60,58,4},
            {93,96,85,98,72,87,85,30,65,62,4},
            {94,97,90,99,76,92,90,31,70,66,4},
            {95,98,95,99,80,97,95,32,75,70,4},
            {96,99,95,99,84,99,96,33,80,74,4},
            {97,99,95,99,88,99,97,34,85,78,4},
            {98,99,95,99,92,99,98,35,90,82,4},
            {99,99,95,99,96,99,99,36,95,86,5},
            };
        int nT24[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eT24[11] = {0,0,0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dgiT24RowCount();
             ++b) {
            int vals[11];
            vals[0] = dgiT24Hide(b);
            vals[1] = dgiT24Silent(b);
            vals[2] = dgiT24Traps(b);
            vals[3] = dgiT24Climb(b);
            vals[4] = dgiT24Disguise(b);
            vals[5] = dgiT24Locks(b);
            vals[6] = dgiT24Tightrope(b);
            vals[7] = dgiT24Vault(b);
            vals[8] = dgiT24Fall(b);
            vals[9] = dgiT24Escape(b);
            vals[10] = dgiT24Backstab(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CT24[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT24[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nT24[c] != eT24[c])
                ++bad;
        // the dgiNinjaMinDex pin
    if (dgiNinjaMinDex() != 14
        )
            ++bad;
        // the dgiNinjaMinCha pin
    if (dgiNinjaMinCha() != 14
        )
            ++bad;
        // the dgiNinjaMinInt pin
    if (dgiNinjaMinInt() != 15
        )
            ++bad;
        // the dgiNinjaXpSplitDiv pin
    if (dgiNinjaXpSplitDiv() != 2
        )
            ++bad;
        // the dgiNinjaHpMin pin
    if (dgiNinjaHpMin() != 1
        )
            ++bad;
        // the dgiNinjaHpMax pin
    if (dgiNinjaHpMax() != 2
        )
            ++bad;
        // the dgiNinjaOtherHpDiv pin
    if (dgiNinjaOtherHpDiv() != 2
        )
            ++bad;
        // the dgiNinjaExampleHpMin pin
    if (dgiNinjaExampleHpMin() != 2
        )
            ++bad;
        // the dgiNinjaExampleHpMax pin
    if (dgiNinjaExampleHpMax() != 7
        )
            ++bad;
        // the dgiNinjaSlots pin
    if (dgiNinjaSlots() != 2
        )
            ++bad;
        // the dgiNinjaNightingaleDiv pin
    if (dgiNinjaNightingaleDiv() != 2
        )
            ++bad;
        // the dgiNinjaTightropeAngle pin
    if (dgiNinjaTightropeAngle() != 45
        )
            ++bad;
        // the dgiNinjaTightropeCheckFeet pin
    if (dgiNinjaTightropeCheckFeet() != 60
        )
            ++bad;
        // the dgiNinjaTightropeMove pin
    if (dgiNinjaTightropeMove() != 60
        )
            ++bad;
        // the dgiNinjaTightropeBalanceBonus pin
    if (dgiNinjaTightropeBalanceBonus() != 10
        )
            ++bad;
        // the dgiNinjaTightropeModerateWind pin
    if (dgiNinjaTightropeModerateWind() != -10
        )
            ++bad;
        // the dgiNinjaTightropeStrongWind pin
    if (dgiNinjaTightropeStrongWind() != -20
        )
            ++bad;
        // the dgiNinjaTightropeGustingWind pin
    if (dgiNinjaTightropeGustingWind() != -30
        )
            ++bad;
        // the dgiNinjaTightropeFightPenalty pin
    if (dgiNinjaTightropeFightPenalty() != -5
        )
            ++bad;
        // the dgiNinjaVaultRunFeet pin
    if (dgiNinjaVaultRunFeet() != 30
        )
            ++bad;
        // the dgiNinjaVaultPoleExtraFeet pin
    if (dgiNinjaVaultPoleExtraFeet() != 4
        )
            ++bad;
        // the dgiNinjaVaultObstacleReduction pin
    if (dgiNinjaVaultObstacleReduction() != 1

... (326 more lines, capped)

### block 650 (head line 120220, 116 lines, delta 0)

    // ---- R772 OA Weapons prose audit ----
    // OA round one hundred fifty-nine (capture pp. 84-93): the weapons prose
    // - the forty-seven weapon descriptions pinned as the
    // essence-of-the-weapon doctrines, the tool-and-weapon duality, the ninja
    // concealment thread, and the mechanics consts of the chu-ko-nu magazine,
    // the needle burst die, the lasso pulls, the man catcher, the metsubishi,
    // the nekode climb bonus, the shuriken star points, and the tetsu-bishi
    // area rules (the descriptions re-captured at pp. 42-51 of the
    // compressed-3 re-upload)
    {
        using namespace rules;
        int bad = 0;
    if (dnjChuKoNuMagazineQuarrels() != 10
            || dnjChuKoNuReloadPerRound() != 2
            || dnjChuKoNuFullReloadRounds() != 5
            || dnjNeedleMouthCarryMax() != 20
            || dnjNeedleAllFiredDieSides() != 20
            || dnjShurikenStarPointMinimum() != 3
            || dnjNekodeClimbBonusPercent() != 5
            || dnjLassoLineCuttingDamage() != 2
            || dnjLassoBipedalPullPercent() != 25
            || dnjLassoExtraPullerBonusPercent() != 20
            || dnjManCatcherOffFeetPercent() != 25
            || dnjManCatcherHaftCuttingDamage() != 6
            || dnjMetsubishiIncapacitationMaxRounds() != 6
            || dnjTetsubishiBaseCount() != 10
            || dnjTetsubishiBaseAreaSquareFeet() != 25
            || dnjTetsubishiHalfCountSavePenalty() != 4
            || dnjTetsubishiPerFiveExtraSavePenalty() != 2
            || dnjTetsubishiStepDamageMax() != 4
            || dnjTetsubishiLameDurationHours() != 24
            || !dnjArrowsDoctrine()
            || !dnjBoStickDoctrine()
            || !dnjBokuTohDoctrine()
            || !dnjChainDoctrine()
            || !dnjChijirikiDoctrine()
            || !dnjChopsticksDoctrine()
            || !dnjChuKoNuDoctrine()
            || !dnjDaikyuDoctrine()
            || !dnjFangDoctrine()
            || !dnjGunsenDoctrine()
            || !dnjJitteDoctrine()
            || !dnjJoStickDoctrine()
            || !dnjKamaDoctrine()
            || !dnjKatanaDoctrine()
            || !dnjKatanaHonorDoctrine()
            || !dnjKauSinKeDoctrine()
            || !dnjKawanagaDoctrine()
            || !dnjKiseruDoctrine()
            || !dnjKumadeDoctrine()
            || !dnjKusariGamaDoctrine()
            || !dnjKyoketsuogiDoctrine()
            || !dnjLajatangDoctrine()
            || !dnjLassoDoctrine()
            || !dnjManCatcherDoctrine()
            || !dnjMetsubishiDoctrine()
            || !dnjNagimakiDoctrine()
            || !dnjNaginataDoctrine()
            || !dnjNeedleDoctrine()
            || !dnjNekodeDoctrine()
            || !dnjNinjaToDoctrine()
            || !dnjNunchakuDoctrine()
            || !dnjParangDoctrine()
            || !dnjPelletBowDoctrine()
            || !dnjSaiDoctrine()
            || !dnjSangKauwDoctrine()
            || !dnjShakenDoctrine()
            || !dnjShakujoYariDoctrine()
            || !dnjShikomiZueDoctrine()
            || !dnjShurikenDoctrine()
            || !dnjSiangkamDoctrine()
            || !dnjSodeGaramiDoctrine()
            || !dnjTetsubishiDoctrine()
            || !dnjTetsuboDoctrine()
            || !dnjThreePieceRodDoctrine()
            || !dnjTuiFaDoctrine()
            || !dnjUchiNeDoctrine()
            || !dnjWakizashiDoctrine()
            || !dnjWhipDoctrine()
        )
            ++bad;
        // the chu-ko-nu reload math - five rounds at two per round fills the
        // ten-quarrel magazine
    if (dnjChuKoNuFullReloadRounds() * dnjChuKoNuReloadPerRound() !=
        dnjChuKoNuMagazineQuarrels()
        )
            ++bad;
        // the needle burst die - all twenty fired at once roll the
        // twenty-sided die
    if (dnjNeedleAllFiredDieSides() != dnjNeedleMouthCarryMax()
        )
            ++bad;
        // the lasso pull math - the base chance minus the extra-puller bonus
        // is five
    if (dnjLassoBipedalPullPercent() - dnjLassoExtraPullerBonusPercent() != 5
        )
            ++bad;
        // the pull chances agree - the lasso and the man catcher both pull at
        // twenty-five
    if (dnjManCatcherOffFeetPercent() != dnjLassoBipedalPullPercent()
        )
            ++bad;
        // the tetsu-bishi save math - the halved-count penalty plus the
        // per-five penalty is six
    if (dnjTetsubishiHalfCountSavePenalty() +
        dnjTetsubishiPerFiveExtraSavePenalty() != 6
        )
            ++bad;
        // the tetsu-bishi lame watch - twenty-four hours is six times the
        // step damage maximum
    if (dnjTetsubishiLameDurationHours() != dnjTetsubishiStepDamageMax() * 6
        )
            ++bad;
        printf("R772 OA Weapons prose audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 742 (head line 144127, 65 lines, delta 0)

    // ---- R111: fighter attack matrix audit (DMG p.75 I.B) ----
    {
        int bad = 0;
        // the printed table, pinned band by band
        {
            struct TC { int lvl, ac, want; };
            const TC tc[] = {
                // AC 10 row across the bands (the negatives are the
                // book's own: a 17+ fighter hits AC 10 on any roll)
                { 1, 10, 10}, { 2, 10, 10},   // band 1-2 mates
                { 3, 10,  8}, { 4, 10,  8},   // band 3-4
                { 5, 10,  6}, { 9, 10,  2},   // bands 5-6, 9-10
                {11, 10,  0}, {15, 10, -4}, {17, 10, -6},
                {20, 10, -6},                // 17+ is the last band
                // 0-level column (0-level humans and halflings)
                { 0, 10, 11}, { 0,  0, 20}, { 0, -5, 21}, { 0, -10, 26},
                // AC 0 row down the bands
                { 1,  0, 20}, { 3,  0, 18}, { 5,  0, 16},
                { 7,  0, 14}, { 9,  0, 12}, {11,  0, 10},
                {13,  0,  8}, {15,  0,  6}, {17,  0,  4},
                // the deep-AC rows
                { 1, -1, 20}, { 1, -5, 20}, { 1, -10, 25},
                {17, -10, 14},
                // negatives mid-table
                {13,  7,  1}, {15,  6,  0}, {17,  5, -1},
                // AC clamps: past 10 uses the AC 10 row,
                // past -10 the AC -10 row
                { 1, 12, 10}, { 1, -12, 25},
            };
            for (const TC& t : tc) {
                if (rules::attackMatrixFighter(t.lvl, t.ac) != t.want)
                    ++bad;
            }
        }
        // the table only improves with level, only worsens with AC,
        // and stays in the book's bounds at every cell
        for (int lvl = 0; lvl <= 20; ++lvl) {
            int prevAc = -99;
            for (int ac = 12; ac >= -12; --ac) {
                int v = rules::attackMatrixFighter(lvl, ac);
                if (v < -6 || v > 26) ++bad;
                if (v < prevAc) ++bad;   // better AC never easier
                prevAc = v;
            }
        }
        for (int ac = 10; ac >= -10; --ac) {
            int prevLvl = 99;
            for (int lvl = 0; lvl <= 20; ++lvl) {
                int v = rules::attackMatrixFighter(lvl, ac);
                if (v > prevLvl) ++bad;  // level never worsens
                prevLvl = v;
            }
        }
        // a negative target hits on everything but a natural 1
        {
            rules::Rng rng(111);
            rules::Dice dice(rng);
            int hits = 0;
            for (int i = 0; i < 20000; ++i) {
                if (rules::attackRollHits(dice, -6, 0)) ++hits;
            }
            if (hits == 0 || hits == 20000) ++bad;
        }
        printf("R111 attack matrix audit: bad %d\n", bad);
    }


### block 743 (head line 144193, 94 lines, delta 0)

    // ---- R112: monster attack matrix audit (DMG p.75-76 II) ----
    {
        int bad = 0;
        // the printed table: a representative hit dice for each
        // of the 12 bands, pinned at notable ACs
        {
            struct MC { float hd; int ac, want; };
            const MC mc[] = {
                {0.50f,  10,  11},  // band 0
                {0.50f,   0,  20},  // band 0
                {0.50f,  -5,  21},  // band 0
                {0.50f, -10,  26},  // band 0
                {1.00f,  10,  10},  // band 1
                {1.00f,   0,  20},  // band 1
                {1.00f,  -5,  20},  // band 1
                {1.00f, -10,  25},  // band 1
                {1.30f,  10,   9},  // band 2
                {1.30f,   0,  19},  // band 2
                {1.30f,  -5,  20},  // band 2
                {1.30f, -10,  24},  // band 2
                {1.60f,  10,   8},  // band 3
                {1.60f,   0,  18},  // band 3
                {1.60f,  -5,  20},  // band 3
                {1.60f, -10,  23},  // band 3
                {2.00f,  10,   6},  // band 4
                {2.00f,   0,  16},  // band 4
                {2.00f,  -5,  20},  // band 4
                {2.00f, -10,  21},  // band 4
                {4.00f,  10,   5},  // band 5
                {4.00f,   0,  15},  // band 5
                {4.00f,  -5,  20},  // band 5
                {4.00f, -10,  20},  // band 5
                {6.00f,  10,   3},  // band 6
                {6.00f,   0,  13},  // band 6
                {6.00f,  -5,  18},  // band 6
                {6.00f, -10,  20},  // band 6
                {8.00f,  10,   2},  // band 7
                {8.00f,   0,  12},  // band 7
                {8.00f,  -5,  17},  // band 7
                {8.00f, -10,  20},  // band 7
                {10.00f, 10,   0},  // band 8
                {10.00f,  0,  10},  // band 8
                {10.00f, -5,  15},  // band 8
                {10.00f, -10, 20},  // band 8
                {12.00f, 10,  -1},  // band 9
                {12.00f,  0,   9},  // band 9
                {12.00f, -5,  14},  // band 9
                {12.00f, -10, 19},  // band 9
                {14.00f, 10,  -2},  // band 10
                {14.00f,  0,   8},  // band 10
                {14.00f, -5,  13},  // band 10
                {14.00f, -10, 18},  // band 10
                {16.00f, 10,  -3},  // band 11
                {16.00f,  0,   7},  // band 11
                {16.00f, -5,  12},  // band 11
                {16.00f, -10, 17},  // band 11
                {0.99f,  10,  11},  // band 0
                {1.00f,  10,  10},  // band 1
                {1.25f,  10,   9},  // band 2
                {1.50f,  10,   8},  // band 3
                {2.00f,  10,   6},  // band 4
                {3.99f,  10,   6},  // band 4
                {4.00f,  10,   5},  // band 5
                {15.99f, 10,  -2},  // band 10
                {16.00f, 10,  -3},  // band 11
                {40.00f, 10,  -3},  // band 11
            };
            for (const MC& m : mc) {
                if (rules::attackMatrixMonster(m.hd, m.ac) != m.want)
                    ++bad;
            }
        }
        // the table only improves with hit dice, only worsens
        // with AC, and stays in the book's bounds everywhere
        for (float hd = 0.25f; hd < 40.0f; hd += 0.25f) {
            int prevAc = -99;
            for (int ac = 12; ac >= -12; --ac) {
                int v = rules::attackMatrixMonster(hd, ac);
                if (v < -3 || v > 26) ++bad;
                if (v < prevAc) ++bad;
                prevAc = v;
            }
        }
        for (int ac = 10; ac >= -10; --ac) {
            int prevHd = 99;
            for (float hd = 0.25f; hd < 40.0f; hd += 0.25f) {
                int v = rules::attackMatrixMonster(hd, ac);
                if (v > prevHd) ++bad;
                prevHd = v;
            }
        }
        printf("R112 monster matrix audit: bad %d\n", bad);
        if (bad) return 1;
    }


### block 744 (head line 144288, 130 lines, delta 0)

    // ---- R113: class attack matrices audit (DMG p.75 I.A/I.C/I.D) ----
    {
        int bad = 0;
        // the printed tables: a representative level for each band,
        // pinned at notable ACs (fighter keeps I.B, R111's audit)
        {
            struct CC { int cls, level, ac, want; };
            const CC cc[] = {
                {2,  1,  10,  10},  // cleric band 0
                {2,  1,   0,  20},  // cleric band 0
                {2,  1,  -5,  20},  // cleric band 0
                {2,  1, -10,  25},  // cleric band 0
                {2,  4,  10,   8},  // cleric band 1
                {2,  4,   0,  18},  // cleric band 1
                {2,  4,  -5,  20},  // cleric band 1
                {2,  4, -10,  23},  // cleric band 1
                {2,  7,  10,   6},  // cleric band 2
                {2,  7,   0,  16},  // cleric band 2
                {2,  7,  -5,  20},  // cleric band 2
                {2,  7, -10,  21},  // cleric band 2
                {2, 10,  10,   4},  // cleric band 3
                {2, 10,   0,  14},  // cleric band 3
                {2, 10,  -5,  19},  // cleric band 3
                {2, 10, -10,  20},  // cleric band 3
                {2, 13,  10,   2},  // cleric band 4
                {2, 13,   0,  12},  // cleric band 4
                {2, 13,  -5,  17},  // cleric band 4
                {2, 13, -10,  20},  // cleric band 4
                {2, 16,  10,   0},  // cleric band 5
                {2, 16,   0,  10},  // cleric band 5
                {2, 16,  -5,  15},  // cleric band 5
                {2, 16, -10,  20},  // cleric band 5
                {2, 19,  10,  -1},  // cleric band 6
                {2, 19,   0,   9},  // cleric band 6
                {2, 19,  -5,  14},  // cleric band 6
                {2, 19, -10,  19},  // cleric band 6
                {1,  1,  10,  11},  // MU band 0
                {1,  1,   0,  20},  // MU band 0
                {1,  1,  -5,  21},  // MU band 0
                {1,  1, -10,  26},  // MU band 0
                {1,  6,  10,   9},  // MU band 1
                {1,  6,   0,  19},  // MU band 1
                {1,  6,  -5,  20},  // MU band 1
                {1,  6, -10,  24},  // MU band 1
                {1, 11,  10,   6},  // MU band 2
                {1, 11,   0,  16},  // MU band 2
                {1, 11,  -5,  20},  // MU band 2
                {1, 11, -10,  21},  // MU band 2
                {1, 16,  10,   3},  // MU band 3
                {1, 16,   0,  13},  // MU band 3
                {1, 16,  -5,  18},  // MU band 3
                {1, 16, -10,  20},  // MU band 3
                {1, 21,  10,   1},  // MU band 4
                {1, 21,   0,  11},  // MU band 4
                {1, 21,  -5,  16},  // MU band 4
                {1, 21, -10,  20},  // MU band 4
                {3,  1,  10,  11},  // thief band 0
                {3,  1,   0,  20},  // thief band 0
                {3,  1,  -5,  21},  // thief band 0
                {3,  1, -10,  26},  // thief band 0
                {3,  5,  10,   9},  // thief band 1
                {3,  5,   0,  19},  // thief band 1
                {3,  5,  -5,  20},  // thief band 1
                {3,  5, -10,  24},  // thief band 1
                {3,  9,  10,   6},  // thief band 2
                {3,  9,   0,  16},  // thief band 2
                {3,  9,  -5,  20},  // thief band 2
                {3,  9, -10,  21},  // thief band 2
                {3, 13,  10,   4},  // thief band 3
                {3, 13,   0,  14},  // thief band 3
                {3, 13,  -5,  19},  // thief band 3
                {3, 13, -10,  20},  // thief band 3
                {3, 17,  10,   2},  // thief band 4
                {3, 17,   0,  12},  // thief band 4
                {3, 17,  -5,  17},  // thief band 4
                {3, 17, -10,  20},  // thief band 4
                {3, 21,  10,   0},  // thief band 5
                {3, 21,   0,  10},  // thief band 5
                {3, 21,  -5,  15},  // thief band 5
                {3, 21, -10,  20},  // thief band 5
                {2,  1,  10,  10},  // cleric L1 band 0
                {2,  3,  10,  10},  // cleric L3 band 0 edge
                {2,  4,  10,   8},  // cleric L4 band 1
                {2, 18,  10,   0},  // cleric L18 band 5
                {2, 19,  10,  -1},  // cleric L19+ band 6
                {1,  5,  10,  11},  // MU L5 band 0 edge
                {1,  6,  10,   9},  // MU L6 band 1
                {1, 20,  10,   3},  // MU L20 band 3
                {1, 21,  10,   1},  // MU L21+ band 4
                {3,  4,  10,  11},  // thief L4 band 0 edge
                {3,  5,  10,   9},  // thief L5 band 1
                {3, 20,  10,   2},  // thief L20 band 4
                {3, 21,  10,   0},  // thief L21+ band 5
            };
            for (const CC& m : cc) {
                if (rules::attackNumber(m.cls, m.level, m.ac) != m.want)
                    ++bad;
            }
        }
        // fighter (classIndex 0) still rides matrix I.B
        {
            int v = rules::attackNumber(0, 1, 10);
            if (v != 10) ++bad;
            v = rules::attackNumber(0, 0, 10);
            if (v != 11) ++bad;   // 0-level: I.B band 0
        }
        // each table only improves with level, only worsens
        // with AC, and stays in the book's bounds everywhere
        for (int cls = 1; cls <= 3; ++cls) {
            for (int level = 1; level <= 21; ++level) {
                int prevAc = -99;
                for (int ac = 12; ac >= -12; --ac) {
                    int v = rules::attackNumber(cls, level, ac);
                    if (v < -6 || v > 26) ++bad;
                    if (v < prevAc) ++bad;
                    prevAc = v;
                }
            }
            for (int ac = 10; ac >= -10; --ac) {
                int prevLvl = 99;
                for (int level = 1; level <= 21; ++level) {
                    int v = rules::attackNumber(cls, level, ac);
                    if (v > prevLvl) ++bad;
                    prevLvl = v;
                }
            }
        }
        printf("R113 class matrix audit: bad %d\n", bad);
        if (bad) return 1;
    }


## The file tail (last 30 lines)

144391|             v = rules::attackNumber(0, 0, 10);
144392|             if (v != 11) ++bad;   // 0-level: I.B band 0
144393|         }
144394|         // each table only improves with level, only worsens
144395|         // with AC, and stays in the book's bounds everywhere
144396|         for (int cls = 1; cls <= 3; ++cls) {
144397|             for (int level = 1; level <= 21; ++level) {
144398|                 int prevAc = -99;
144399|                 for (int ac = 12; ac >= -12; --ac) {
144400|                     int v = rules::attackNumber(cls, level, ac);
144401|                     if (v < -6 || v > 26) ++bad;
144402|                     if (v < prevAc) ++bad;
144403|                     prevAc = v;
144404|                 }
144405|             }
144406|             for (int ac = 10; ac >= -10; --ac) {
144407|                 int prevLvl = 99;
144408|                 for (int level = 1; level <= 21; ++level) {
144409|                     int v = rules::attackNumber(cls, level, ac);
144410|                     if (v > prevLvl) ++bad;
144411|                     prevLvl = v;
144412|                 }
144413|             }
144414|         }
144415|         printf("R113 class matrix audit: bad %d\n", bad);
144416|         if (bad) return 1;
144417|     }
144418|     return 0;
144419|             }
144420| 

