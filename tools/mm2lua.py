#!/usr/bin/env python3
"""monsters2lua.py - ONE script: merged MM1 @-record file -> lua registry.

Usage:  python monsters2lua.py <merged_file.md> <outdir>
Input:  canvas adnd1-monsters body (@ records under family headings).
Output: <outdir>/<a..z>/<snake_case>.lua - ONE ENTRY PER XP FILE ROW.

Rework 2026-09-27 (Curtiss's requirements):
  - Entry count matches the Appendix E XP file: every CSV row (384) has an
    entry, named EXACTLY as the XP file (electric, octopus, sahuagin_king,
    piercer_smallest, treant_shrubling). The 20 no-XP MM monsters (4 classed
    demihumans + 16 App E omissions - all verified present in the printed
    MM by Curtiss) are kept as extra entries with xpSource flags.
  - EVERY entry carries a full statblock. xp_variant rows are PROMOTED to
    standalone entries whose stats are transcribed from the printed prose
    (Sahuagin Chieftain 4HD+4, Orc Chief AC4/3HD, titan AC/HD table, piercer
    sizes, treant ages, troglodyte ranks, whale HD ranges, ogre leaders...).
    Each promoted entry keeps variantOf = parent and inherits any field
    the prose does not override.
  - Roc & Gas Spore: their stat blocks were lost in the mm1.md extract but
    have been transcribed from the printed MM1 (p.82 / p.42) by the user,
    so both are now full verified records (see stat_block_source in the
    merged file). Gas Spore prose moved from Gargoyle to its own record.
    statBlockMissing/statNote fields remain in the schema but no entry
    uses them anymore.
  - text: = the record's own verbatim prose. familyText: = shared family
    prose on every family member. Promoted variants carry variantOf instead
    of duplicated prose.
  - New engine fields (2026-09-27): source = book the monster first
    appeared in ("MM1", parsed from the @ header; generalizes to MM2/
    Fiend Folio later); pages = page span in that book (start page to
    next entry's start page, book-order, page granularity);
    race = family field (per Curtiss's decision) - family members get
    the family name, promoted variants inherit the parent's PRINTED
    name, and singleton monsters are their own race using their
    printed name. Race always reflects the printed MM identity, NOT
    the registry (XP-file) name: all Piercer entries are race
    "Piercer", Treant ages are race "Treant", Electric is race
    "Electric Eel", etc.
  - XP: "5250 + 20/hp" -> xp/xpPerHp, xpValue = base + perHp*avgHp.
    "-1 (flag)" -> xpSource flag (engine computes). "none (...)" ->
    xpSource flag (engine computes). "none (...)" ->
    xpSource classed_human_matrix (legacy; now by_level) |
    app_e_omission (xpNote keeps text).
    "N (perm_x10)" -> xp = N, xpSource = perm_x10.
Filenames: lowercase, non-alnum -> _, collapsed. Folder = first letter.
"""
import json, os, re, sys

def q(s):
    return json.dumps(s, ensure_ascii=False)

def snake(name):
    s = re.sub(r'[^a-z0-9]+', '_', name.lower()).strip('_')
    m = re.search(r'[a-z]', s)
    return s, (m.group(0) if m else 'z')

# Entry names = XP-file names. mmName keeps the Monster Manual printed name
# when it differs (Electric Eel -> Electric, Giant Octopus -> Octopus, ...).
RENAMES = {
    'Electric Eel': 'Electric',
    'Weed Eel': 'Weed',
    'Giant Octopus': 'Octopus',
    'Giant Water Spider': 'Water Spider',
    'Giant Sea Horse': 'Sea Horse',
    'Giant Portuguese Man-o-war': 'Portuguese Man-o-war',
    'Giant Sea Turtle': 'Sea Turtle',
    'Giant Snapping Turtle': 'Snapping Turtle',
    'Piercer': 'Piercer (smallest)',
    'Treant': 'Treant Shrubling (young)',
}

# Printed stats for promoted variants, transcribed from the MM prose
# (verified against the merged canvas text blocks, 2026-09-27). Fields not
# listed inherit the parent statblock. statNote carries printed details
# that do not fit the schema.
VARIANT_STATS = {
    'Giant Badger': {'hitDice': '3', 'damage': '1-3/1-3/1-6', 'size': 'M',
                     'statNote': 'Very rare variety, twice normal size; otherwise identical to badger.'},
    'Type IV Demon Bilwhr': {'variantOfType': 'Type IV Demon (nalfeshnee)',
                             'statNote': 'Named Type IV demon; stats as Type IV.'},
    'Type IV Demon Johud': {'variantOfType': 'Type IV Demon (nalfeshnee)',
                            'statNote': 'Named Type IV demon; stats as Type IV.'},
    'Type V Demon Aishapra': {'variantOfType': 'Type V Demon (marilith)',
                              'statNote': 'Named Type V demon; stats as Type V.'},
    'Type V Demon Kevokulli': {'variantOfType': 'Type V Demon (marilith)',
                               'statNote': 'Named Type V demon; stats as Type V.'},
    'Type V Demon Rehnaremme': {'variantOfType': 'Type V Demon (marilith)',
                                'statNote': 'Named Type V demon; stats as Type V.'},
    'Type VI Demon Alzoll': {'variantOfType': 'Type VI Demon (balor)',
                             'statNote': 'Named Type VI demon; stats as Type VI.'},
    'Type VI Demon Errtu': {'variantOfType': 'Type VI Demon (balor)',
                            'statNote': 'Named Type VI demon; stats as Type VI.'},
    'Type VI Demon Ndulu': {'variantOfType': 'Type VI Demon (balor)',
                            'statNote': 'Named Type VI demon; stats as Type VI.'},
    'Type VI Demon Tersath': {'variantOfType': 'Type VI Demon (balor)',
                              'statNote': 'Named Type VI demon; stats as Type VI.'},
    'Type VI Demon Wendonai': {'variantOfType': 'Type VI Demon (balor)',
                               'statNote': 'Named Type VI demon; stats as Type VI.'},
    'Vampire Ixitxachitl': {'hitDice': '2 + 2 (double normal)',
                            'specialAttacks': 'energy drain; regenerates 3 hp per melee round',
                            'statNote': 'Vampiric form: similar to normal ixitxachitl but with double hit dice, regeneration and level draining.'},
    'Ogre Leader': {'armorClass': '3', 'hitDice': '7', 'damage': '2-12',
                    'statNote': 'Present if 11+ ogres; 30-33 hit points; attacks as a 7 hit dice creature.'},
    'Ogre Chieftain': {'armorClass': '4', 'hitDice': '7', 'damage': '4-14',
                      'statNote': 'Present if 16+ ogres; 34-37 hit points; attacks as a 7 hit dice monster.'},
    'Ogre Magi Chieftain': {'hitDice': '5 + 2 (+2 per die)',
                            'statNote': 'Chief of great strength: +2 on each hit die, attacks and saves as a 9 hit dice monster.'},
    'Orc Guard': {'armorClass': '4', 'hitDice': '2', 'damage': '2-7',
                  'statNote': '11 hit points; fights as a monster with 2 hit dice.'},
    'Orc Subchief': {'armorClass': '4', 'hitDice': '2', 'damage': '2-7',
                     'statNote': '11 hit points; fights as a monster with 2 hit dice.'},
    'Orc Chief': {'armorClass': '4', 'hitDice': '3', 'damage': '2-8',
                  'statNote': '13-16 hit points; attacks as a monster with 3 hit dice.'},
    'Orc Bodyguard': {'armorClass': '4', 'hitDice': '3', 'damage': '2-8',
                      'statNote': '13-16 hit points; attacks as a monster with 3 hit dice.'},
    'Piercer (small)': {'hitDice': '2', 'damage': '2-12'},
    'Piercer (medium)': {'hitDice': '3', 'damage': '3-18'},
    'Piercer (largest)': {'hitDice': '4', 'damage': '4-24',
                          'statNote': 'About 6\' long, 1\' base diameter, 500 pounds.'},
    'Sahuagin Baron': {'hitDice': '6 + 6',
                       'statNote': 'Lair contingent; in addition to normal lair groups.'},
    'Sahuagin Chieftain': {'hitDice': '4 + 4',
                          'statNote': 'Always leads a band; in addition to the group.'},
    'Sahuagin Cleric': {'statNote': '5th-8th level evil cleric (by_level XP); 1-4 assistant priestesses of 3rd-4th level.'},
    'Sahuagin Guard': {'hitDice': '3 + 3', 'statNote': 'Lair contingent.'},
    'Sahuagin Lieutenant': {'hitDice': '3 + 3', 'statNote': '1 per 10 band members.'},
    'Sahuagin King': {'statNote': 'Rules from an undersea city over 9 provinces; individual stats not printed in the MM text.'},
    'Sahuagin Mutant': {'specialAttacks': '4 fully usable arms',
                        'statNote': '1 in 216 sahuagin is a 4-armed mutation; otherwise as standard.'},
    'Sahuagin Prince': {'hitDice': '8 + 8',
                       'statNote': 'Rules 1 of 9 provinces; lair numbers double, 4-24 sharks present.'},
    'Lesser Titan (AC 2)': {'armorClass': '2', 'hitDice': '17', 'move': '21"'},
    'Lesser Titan (AC 1)': {'armorClass': '1', 'hitDice': '18', 'move': '21"'},
    'Major Titan (AC 0)': {'armorClass': '0', 'hitDice': '19'},
    'Major Titan (AC -1)': {'armorClass': '-1', 'hitDice': '20'},
    'Elder Titan (AC -2)': {'armorClass': '-2', 'hitDice': '21', 'damage': '8-48'},
    'Elder Titan (AC -3)': {'armorClass': '-3', 'hitDice': '22', 'damage': '8-48'},
    'Treant Mature (middle-aged)': {'hitDice': '9-10', 'damage': '3-18/attack',
                                    'size': 'L (16\'-19\')'},
    'Treant Moss Trunk (elder)': {'hitDice': '11-12', 'damage': '4-24/attack',
                                  'size': 'L (20\'-23\'+)'},
    'Triton Leader': {'hitDice': '9', 'statNote': 'Leads groups of 50+ tritons (by_level XP).'},
    'Troglodyte Chief Leader': {'hitDice': '6', 'statNote': 'Present if 60+ troglodytes.'},
    'Troglodyte Major Leader': {'hitDice': '4', 'statNote': '1 per 20 encountered.'},
    'Troglodyte Minor Leader/guard': {'hitDice': '3', 'statNote': '1 per 10 encountered.'},
    'Troglodyte Female': {'hitDice': '1 + 1', 'statNote': 'Females equal to 100% of males in lair.'},
    'Black Whale': {'hitDice': '18-21'},
    'Humpback Whale': {'hitDice': '26-33'},
    'Killer Whale': {'hitDice': '12-15', 'specialAttacks': 'always attacks humans'},
    'Right Whale': {'hitDice': '20-21'},
    'Sperm Whale': {'hitDice': '29-36', 'specialAttacks': 'swallows prey whole'},
    'White Whale (beluga)': {'hitDice': '12-13'},
    'Worg': {'size': 'L (pony-sized)', 'intelligence': 'average', 'alignment': 'neutral (evil)',
             'specialAttacks': 'has own language; often cooperates with goblins',
             'statNote': 'Evil-natured neo-dire wolf; can be ridden; otherwise conforms to wolves.'},
}

def parse_xp(x):
    """x like '5250 + 20/hp' | '33' | '-1 (flag)' | 'none (...)' | '63900 (perm_x10)'"""
    out = {'xp': None, 'xpPerHp': None, 'xpValue': None, 'xpSource': None, 'xpNote': None}
    m = re.fullmatch(r'(-?\d+)(?: \+ (\d+)/hp)?', x)
    if m:
        out['xp'] = int(m.group(1))
        if m.group(2):
            out['xpPerHp'] = int(m.group(2))
        out['xpSource'] = 'merged_mm1'
        return out
    m = re.fullmatch(r'-1 \(([a-z_]+)\)', x)
    if m:
        out['xpSource'] = m.group(1)
        return out
    m = re.fullmatch(r'(\d+) \((perm_x10)\)', x)
    if m:
        out['xp'] = int(m.group(1))
        out['xpSource'] = m.group(2)
        return out
    m = re.fullmatch(r'(-?\d+) \+ (\d+)/hp \((\d+) \+ (\d+)/hp\)', x)
    if m:
        # printed dual values (Giant Ant worker/soldier): keep both
        out['xp'] = int(m.group(1))
        out['xpPerHp'] = int(m.group(2))
        out['xpSource'] = 'merged_mm1'
        out['xpNote'] = 'alternate: %s + %s/hp' % (m.group(3), m.group(4))
        return out
    m = re.fullmatch(r'(\d+) \+ (\d+)/hp \(role_variant\)', x)
    if m:
        out['xp'] = int(m.group(1))
        out['xpPerHp'] = int(m.group(2))
        out['xpSource'] = 'role_variant'
        return out
    if x.startswith('none (classed'):
        # legacy form, no longer emitted (demihumans now use -1 (by_level))
        out['xpSource'] = 'by_level'
        out['xpNote'] = x
        return out
    if x.startswith('none (App E omission'):
        # legacy form, no longer emitted (all have printed HD; now
        # -1 (by_hit_dice) per DMG p.85)
        out['xpSource'] = 'by_hit_dice'
        out['xpNote'] = x
        return out
    out['xpSource'] = 'app_e_omission'
    out['xpNote'] = x
    return out

def parse_hd(h):
    """'16' -> (16,0,72); '4 + 3' -> (4,3,21); '1 hit point' -> (0,0,1);
    else (None,None,None). Gas Spore is the only '1 hit point' creature."""
    if (h or '').strip() == '1 hit point':
        return 0, 0, 1
    m = re.fullmatch(r'(\d+)(?: \+ (\d+))?', h or '')
    if m:
        n, b = int(m.group(1)), int(m.group(2) or 0)
        return n, b, int(round(n * 4.5 + b))
    return None, None, None

def atoi(v):
    if v is None:
        return None
    m = re.match(r'\s*(\d+)', v)
    return int(m.group(1)) if m else None

def pct(v):
    if v is None:
        return None
    m = re.match(r'\s*(\d+)%', v)
    if m:
        return int(m.group(1))
    if v == 'none':
        return 0
    if v.strip().isdigit():
        return int(v)
    return None

STAT_KEYS = {'frequency', 'no_appearing', 'armor_class', 'move', 'hit_dice',
             'pct_in_lair', 'treasure', 'attacks', 'damage', 'special_attacks',
             'special_defenses', 'magic_resistance', 'intelligence',
             'alignment', 'size', 'psionic', 'modes'}

# Family membership (the merged file's family design; unrelated monsters
# after a heading region must not inherit that family or its familyText).
FAMILY_MEMBERS = {
  'Ape': ['Ape', 'Carnivorous Ape'],
  'Badger': ['Badger'],
  'Bear': ['Black Bear', 'Brown Bear', 'Cave Bear'],
  'Giant Beetle': ['Bombardier Beetle', 'Boring Beetle', 'Fire Beetle',
                   'Rhinoceros Beetle', 'Stag Beetle', 'Water Beetle'],
  'Boar': ['Wild Boar', 'Giant Boar', 'Warthog'],
  'Crocodile': ['Crocodile', 'Giant Crocodile'],
  'Demon': ['Demogorgon', 'Juiblex', 'Manes', 'Orcus', 'Succubus',
            'Type I (vrock)', 'Type II (hezrou)', 'Type III (glabrezu)',
            'Type IV Demon (nalfeshnee)', 'Type V Demon (marilith)',
            'Type VI Demon (balor)', 'Yeenoghu'],
  'Devil': ['Asmodeus', 'Baalzebul', 'Barbed Devil', 'Bone Devil', 'Dispater',
            'Erinyes', 'Geryon', 'Horned Devil', 'Ice Devil', 'Lemure',
            'Pit Fiend'],
  'Dinosaur': ['Anatosaurus', 'Ankylosaurus', 'Antrodemus', 'Apatosaurus',
               'Archelon Ischyros', 'Brachiosaurus', 'Camarasaurus',
               'Ceratosaurus', 'Cetiosaurus', 'Dinichthys', 'Diplodocus',
               'Elasmosaurus', 'Gorgosaurus', 'Iguanodon', 'Lambeosaurus',
               'Megalosaurus', 'Monoclonius', 'Mosasaurus', 'Paleoscincus',
               'Pentaceratops', 'Plateosaurus', 'Plesiosaurus', 'Pteranodon',
               'Stegosaurus', 'Styracosaurus', 'Teratosaurus',
               'Triceratops', 'Tyrannosaurus Rex'],
  'Dog': ['War Dog', 'Wild Dog'],
  'Dragon': ['Black Dragon', 'Blue Dragon', 'Brass Dragon', 'Bronze Dragon',
             'Chromatic Dragon', 'Copper Dragon', 'Gold Dragon',
             'Green Dragon', 'Platinum Dragon', 'Red Dragon',
             'Silver Dragon', 'White Dragon'],
  'Eel': ['Electric Eel', 'Giant Eel', 'Weed Eel'],
  'Elemental': ['Air Elemental', 'Earth Elemental', 'Fire Elemental',
                'Water Elemental'],
  'Elephant': ['Elephant', 'Loxodont'],
  'Frog': ['Giant Frog', 'Killer Frog', 'Poisonous Frog'],
  'Giant': ['Cloud Giant', 'Fire Giant', 'Frost Giant', 'Hill Giant',
            'Stone Giant', 'Storm Giant'],
  'Golem': ['Clay Golem', 'Flesh Golem', 'Iron Golem', 'Stone Golem'],
  'Horse': ['Draft Horse', 'Heavy Horse', 'Light Horse', 'Medium Horse',
            'Pony', 'Wild Horse'],
  'Hyena': ['Hyena', 'Giant Hyena'],
  'Lamprey': ['Lamprey', 'Giant Lamprey'],
  'Lion': ['Lion', 'Mountain Lion', 'Spotted Lion'],
  'Lizard': ['Fire Lizard', 'Giant Lizard', 'Minotaur Lizard',
             'Subterranean Lizard'],
  'Lycanthrope': ['Werebear', 'Wereboar', 'Wererat', 'Weretiger', 'Werewolf'],
  'Men': ['Bandit', 'Berserker', 'Buccaneer', 'Caveman', 'Dervish',
          'Merchant', 'Pilgrim'],
  'Mold': ['Brown Mold', 'Yellow Mold'],
  'Naga': ['Guardian Naga', 'Spirit Naga', 'Water Naga'],
  'Ray': ['Manta Ray', 'Pungi Ray', 'Sting Ray'],
  'Rhinoceros': ['Rhinoceros', 'Woolly Rhinoceros'],
  'Shark': ['Shark', 'Giant Shark'],
  'Snake': ['Amphisbaena Snake', 'Constrictor Snake', 'Poisonous Snake',
             'Sea Snake', 'Spitting Snake'],
  'Sphinx': ['Androsphinx', 'Criosphinx', 'Gynosphinx', 'Hieracosphinx'],
  'Spider': ['Giant Spider', 'Huge Spider', 'Large Spider', 'Phase Spider',
             'Giant Water Spider'],
  'Stag': ['Stag', 'Giant Stag'],
  'Tiger': ['Tiger', 'Sabre-Tooth Tiger'],
  'Toad': ['Giant Toad', 'Ice Toad', 'Poisonous Toad'],
  'Turtle': ['Giant Sea Turtle', 'Giant Snapping Turtle'],
  'Wolf': ['Wolf', 'Dire Wolf', 'Winter Wolf'],
  'Wolverine': ['Wolverine', 'Giant Wolverine'],
}

def parse_records(lines):
    """State machine over the @-record format. Returns list of entry dicts."""
    recs, fam, famtext, cur, mode, famprose = [], None, None, None, None, []
    for ln in lines:
        if ln.startswith('#') or ln.startswith('---'):
            continue
        if not ln.strip():
            if mode == 'prose':
                cur.setdefault('_prose', []).append('')
            elif mode == 'famprose':
                famprose.append('')
            continue
        m = re.fullmatch(r'@ (.+?) \| source: (.+?) p\.([0-9]+) \| xp: (.+)', ln)
        if m:
            if mode == 'famprose':
                famtext = '\n'.join(famprose).strip()
            rname = m.group(1)
            rfamily = fam if (fam and rname in FAMILY_MEMBERS.get(fam, ())) else None
            cur = {'name': rname, 'source': m.group(2), 'page': m.group(3),
                   'xp_raw': m.group(4), 'family': rfamily,
                   'familyText': famtext if rfamily else None,
                   '_prose': [], 'variants': []}
            recs.append(cur); mode = 'fields'
            continue
        if ln.endswith('-,'):
            if mode == 'famprose' and famprose:
                famtext = '\n'.join(famprose).strip()
            fam = ln[:-2].strip(); famtext = None; famprose = []
            cur, mode = None, 'fam'
            continue
        if ln.startswith('xp_variant: '):
            v = ln[len('xp_variant: '):]
            parts = v.rsplit(',', 2)
            cur['variants'].append({'name': parts[0], 'raw': parts[1] + ',' + parts[2]})
            continue
        if ln.startswith('stat_block:'):
            cur['stat_block_missing'] = True
            cur['stat_note'] = ln[len('stat_block:'):].strip()
            mode = 'fam'
            continue
        if ln == 'text:':
            mode = 'prose'
            continue
        if ln == 'text_family:':
            if cur is None or cur.get('family') != fam:
                mode = 'famprose'
            else:
                cur['_carrier'] = True
                mode = 'prose'
            continue
        if mode == 'famprose':
            famprose.append(ln)
            continue
        if mode == 'prose':
            cur['_prose'].append(ln)
            continue
        if mode == 'fields':
            for seg in ln.split(' | '):
                fm = re.match(r'([a-z_]+): (.*)', seg)
                if fm and fm.group(1) in STAT_KEYS:
                    cur[fm.group(1)] = fm.group(2).strip()
    if mode == 'famprose' and famprose:
        famtext = '\n'.join(famprose).strip()
    for i, r in enumerate(recs):
        if r.get('_carrier'):
            ft = '\n'.join(r.get('_prose', [])).strip()
            for r2 in recs:
                if r2.get('family') == r.get('family') and r2.get('family') is not None:
                    r2['familyText'] = ft
    # Promote xp_variant rows to standalone entries with printed stats.
    entries = []
    for r in recs:
        entries.append(r)
        for v in r['variants']:
            stats = VARIANT_STATS.get(v['name'], {})
            # variant raw is 'value,flag': plain value when flag==none,
            # else '-1 (flag)' style for engine-computed variants
            m = re.fullmatch(r'(.*),([a-z_0-9]+)', v['raw'])
            val, flag = (m.group(1), m.group(2)) if m else (v['raw'], 'none')
            vxp_raw = val if flag == 'none' else '-1 (%s)' % flag
            ve = {
                'name': v['name'], 'page': r['page'], 'source': r.get('source'),
                'xp_raw': vxp_raw,
                'family': r.get('family'), 'familyText': r.get('familyText'),
                'variantOf': r['name'], '_prose': [], 'variants': [],
                'stat_note': stats.get('statNote'),
                'variant_of_type': stats.get('variantOfType'),
            }
            fmap = {'hitDice': 'hit_dice', 'armorClass': 'armor_class',
                    'damage': 'damage', 'size': 'size', 'move': 'move',
                    'specialAttacks': 'special_attacks',
                    'intelligence': 'intelligence', 'alignment': 'alignment'}
            for sk, rk in fmap.items():
                if stats.get(sk) is not None:
                    ve[rk] = stats[sk]
                elif r.get(rk) is not None and rk not in ('move',):
                    ve[rk] = r[rk]
            # move only inherits when the variant does not set its own
            if stats.get('move') is None:
                ve['move'] = r.get('move')
            for rk in ('frequency', 'no_appearing', 'pct_in_lair', 'treasure',
                       'attacks', 'special_defenses', 'magic_resistance',
                       'psionic', 'modes'):
                ve[rk] = r.get(rk)
            entries.append(ve)
    # Roc: full record recovered - stat block transcribed from printed MM1
    # p.82 by the user (2026-09-27); it parses from the merged file like any
    # other record, so no placeholder entry is needed anymore.
    # Page spans: the merged file is in book order, so each entry runs from
    # its start page to the next entry's start page (single page when the
    # next entry starts on the same page). Page-granularity only.
    for i, e in enumerate(entries):
        try:
            start = int(e['page'])
        except (TypeError, ValueError):
            e['pages'] = e.get('page')
            continue
        end = start
        for e2 in entries[i + 1:]:
            try:
                nxt = int(e2['page'])
            except (TypeError, ValueError):
                continue
            if nxt > start:
                end = nxt
            break
        e['pages'] = str(start) if end == start else '%d-%d' % (start, end)
    return entries

def prose_of(r):
    return '\n'.join(r.get('_prose', [])).strip('\n').strip()

ENTRY_KEYMAP = [
    ('name', 'name'), ('entry_name', None), ('mmName', None), ('page', 'page'),
    ('family', 'family'), ('variantOf', 'variantOf'),
    ('variantOfType', 'variant_of_type'),
    ('hitDice', 'hit_dice'), ('armorClass', 'armor_class'),
    ('numAttacks', 'attacks'), ('numAttacksRaw', 'attacks'),
    ('damage', 'damage'), ('frequency', 'frequency'),
    ('noAppearing', 'no_appearing'), ('lairPct', 'pct_in_lair'),
    ('lairPctRaw', 'pct_in_lair'), ('treasure', 'treasure'),
    ('move', 'move'), ('size', 'size'), ('intelligence', 'intelligence'),
    ('alignment', 'alignment'), ('specialAttacks', 'special_attacks'),
    ('specialDefenses', 'special_defenses'),
    ('magicResistance', 'magic_resistance'), ('psionic', 'psionic'),
    ('attackDefenseModes', 'modes'), ('text', None), ('familyText', 'familyText'),
    ('statBlockMissing', None), ('statNote', None),
]

def build_fields(rec):
    name = rec['name']
    entry_name = RENAMES.get(name, name)
    xp = parse_xp(rec['xp_raw'])
    hdn, hdb, avg = parse_hd(rec.get('hit_dice'))
    fields = {
        'name': entry_name, 'page': rec['page'], 'family': rec.get('family'),
        'source': rec.get('source') or 'MM1', 'pages': rec.get('pages'),
        # Race = family; singletons (no family heading) are their own race,
        # promoted variants inherit the parent's PRINTED name. Race always
        # uses the printed identity (pre-RENAME), so all Piercer entries
        # are race "Piercer" even though the base is renamed to
        # "Piercer (smallest)" in the registry (same for Treant ages ->
        # race "Treant" etc.).
        'race': (rec['family'] if rec.get('family') else
                 (rec['variantOf'] if rec.get('variantOf') else rec['name'])),
        'hitDice': rec.get('hit_dice'), 'hitDiceNum': hdn,
        'hitDiceBonus': hdb, 'avgHp': avg,
        'armorClass': rec.get('armor_class'),
        'numAttacks': atoi(rec.get('attacks')),
        'numAttacksRaw': rec.get('attacks'),
        'damage': rec.get('damage'),
        'xp': xp['xp'], 'xpPerHp': xp['xpPerHp'], 'xpValue': xp['xpValue'],
        'xpSource': xp['xpSource'], 'xpNote': xp['xpNote'],
        'frequency': rec.get('frequency'), 'noAppearing': rec.get('no_appearing'),
        'lairPct': pct(rec.get('pct_in_lair')), 'lairPctRaw': rec.get('pct_in_lair'),
        'treasure': rec.get('treasure'), 'move': rec.get('move'),
        'size': rec.get('size'), 'intelligence': rec.get('intelligence'),
        'alignment': rec.get('alignment'),
        'specialAttacks': rec.get('special_attacks'),
        'specialDefenses': rec.get('special_defenses'),
        'magicResistance': rec.get('magic_resistance'),
        'psionic': rec.get('psionic'), 'attackDefenseModes': rec.get('modes'),
        'text': prose_of(rec) or None,
        'familyText': rec.get('familyText'),
    }
    if entry_name != name:
        fields['mmName'] = name
    # renamed base entries take their per-size stats (the printed block is
    # the family range; the XP file names each size separately)
    if entry_name == 'Piercer (smallest)':
        fields['hitDice'] = '1'
        fields['hitDiceNum'] = 1
        fields['hitDiceBonus'] = 0
        fields['avgHp'] = 4
        fields['damage'] = '1-6'
    if rec.get('variantOf'):
        fields['variantOf'] = rec['variantOf']
        fields['text'] = None  # prose lives with the parent entry
    if rec.get('variant_of_type'):
        fields['variantOfType'] = rec['variant_of_type']
    if rec.get('_carrier'):
        fields['text'] = None
    if rec.get('stat_block_missing'):
        fields['family'] = None
        fields['familyText'] = None
        fields['statBlockMissing'] = True
    if rec.get('stat_note'):
        fields['statNote'] = rec['stat_note']
    if fields['xp'] is not None and fields['xpPerHp'] is not None and avg is not None:
        fields['xpValue'] = fields['xp'] + fields['xpPerHp'] * avg
    return fields

FIELD_ORDER = ['name', 'mmName', 'page', 'pages', 'source', 'family', 'race',
               'variantOf', 'variantOfType',
               'hitDice', 'hitDiceNum', 'hitDiceBonus', 'avgHp', 'armorClass',
               'numAttacks', 'numAttacksRaw', 'damage', 'xp', 'xpPerHp',
               'xpValue', 'xpSource', 'xpNote', 'frequency', 'noAppearing',
               'lairPct', 'lairPctRaw', 'treasure', 'move', 'size',
               'intelligence', 'alignment', 'specialAttacks', 'specialDefenses',
               'magicResistance', 'psionic', 'attackDefenseModes', 'text',
               'familyText', 'statBlockMissing', 'statNote']

def emit(rec, outdir):
    fields = build_fields(rec)
    out = ['-- %s: generated by monsters2lua.py from merged MM1 @-record file' % fields['name'],
           '-- DO NOT hand-edit; regenerate instead.',
           'return {']
    for k in FIELD_ORDER:
        if fields.get(k) is None:
            continue
        v = fields[k]
        if isinstance(v, str):
            out.append('  %s = %s,' % (k, q(v)))
        else:
            out.append('  %s = %s,' % (k, json.dumps(v)))
    out.append('}')
    fn, letter = snake(fields['name'])
    d = os.path.join(outdir, letter)
    os.makedirs(d, exist_ok=True)
    path = os.path.join(d, fn + '.lua')
    with open(path, 'w', encoding='utf-8') as f:
        f.write('\n'.join(out) + '\n')
    return path

def main():
    if len(sys.argv) != 3:
        sys.exit('usage: monsters2lua.py <merged_file.md> <outdir>')
    src, outdir = sys.argv[1], sys.argv[2]
    with open(src, encoding='utf-8', errors='replace') as f:
        lines = f.read().split('\n')
    recs = parse_records(lines)
    os.makedirs(outdir, exist_ok=True)
    for r in recs:
        emit(r, outdir)
    print('entries parsed  : %d' % len(recs))
    promoted = sum(1 for r in recs if r.get('variantOf'))
    print('promoted vars   : %d' % promoted)
    noxp = [build_fields(r)['name'] for r in recs if build_fields(r)['xp'] is None]
    print('xp=nil entries  : %d (%s)' % (len(noxp), ', '.join(noxp[:10]) +
          (' ...' if len(noxp) > 10 else '')))
    print('familyText on   : %d entries' % sum(1 for r in recs if r.get('familyText')))
    import glob
    print('files written   : %d' % len(glob.glob(os.path.join(outdir, '*', '*.lua'))))

if __name__ == '__main__':
    main()