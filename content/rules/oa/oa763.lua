-- oa763: promoted from rules/oa/oa134wa.h (the OA SETTING - THE ISLAND OF WA, printed capture p. 304 - the unified);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 763,
  "prefix" = "oa763",
  "banner" = {
      "title" = "OA SETTING - THE ISLAND OF WA, printed capture p. 304 - the unified",
      "provenance" = "military state of the shogun census 685 -> 686.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 216 closed, 19 open - the Wa box flips (census 685 -> 686); NEXT - R764: Kozakura (capture p. 304), prefix dlz (verify free at the landing), audit \"R764 OA Kozakura audit\", include after rules/oa/oa134wa.h",
    },
  "consts" = { {
      "name" = "dlyUnifiedMilitaryState",
      "value" = 1,
      "comment" = "the unified military state - the island of Wa is a unified military state (print capture p. 304)",
    }, {
      "name" = "dlyEmperorHonorary",
      "value" = 1,
      "comment" = "the emperor honorary - although there is an emperor, the title is honorary (print capture p. 304)",
    }, {
      "name" = "dlyShogunRealPower",
      "value" = 1,
      "comment" = "the shogun real power - real power rests in the hands of the shogun (print capture p. 304)",
    }, {
      "name" = "dlyBarbarianSuppressingGeneral",
      "value" = 1,
      "comment" = "the barbarian-suppressing general - the shogun or barbarian-suppressing general (print capture p. 304)",
    }, {
      "name" = "dlyShogunHidetomiFamily",
      "value" = 1,
      "comment" = "the shogun Hidetomi family - the shogun is always a member of the Hidetomi family (print capture p. 304)",
    }, {
      "name" = "dlyFiefsGrantedByShogun",
      "value" = 1,
      "comment" = "the fiefs granted by the shogun - the island divided into fiefs, granted by the shogun (print capture p. 304)",
    }, {
      "name" = "dlyDaimyoPerFief",
      "value" = 1,
      "comment" = "the daimyo per fief - the fiefs ruled individually by daimyos (print capture p. 304)",
    }, {
      "name" = "dlyDaimyoTotalControl",
      "value" = 1,
      "comment" = "the daimyo total control - each daimyo has total control over his lands, provided he obeys and enacts the orders of the shogun (print capture p. 304)",
    }, {
      "name" = "dlyCourtLimitedScope",
      "value" = 1,
      "comment" = "the court limited scope - the court of the shogun only involves itself in threats against its power and in cases between different fiefs (print capture p. 304)",
    }, {
      "name" = "dlyConfiscateAndResettle",
      "value" = 1,
      "comment" = "the confiscate and resettle - the shogun retains the power to confiscate lands or resettle a daimyo to a different fief, a power that helps his family retain control (print capture p. 304)",
    }, {
      "name" = "dlyDaimyoServiceAndAdmin",
      "value" = 1,
      "comment" = "the daimyo service and administration - in return for his fief, the daimyo is expected to provide military service and administer his lands (print capture p. 304)",
    }, {
      "name" = "dlyWarriorStatusRaised",
      "value" = 1,
      "comment" = "the warrior status raised - the status of the warrior, particularly the samurai, raised above all others (print capture p. 304)",
    }, {
      "name" = "dlySamuraiStipendOfRice",
      "value" = 1,
      "comment" = "the samurai stipend of rice - each daimyo maintains a household of samurai, paying them a stipend of rice in return for their service (print capture p. 304)",
    }, {
      "name" = "dlySamuraiAbsoluteService",
      "value" = 1,
      "comment" = "the samurai absolute service - the samurai expected to give absolute and loyal service to their daimyo (print capture p. 304)",
    }, {
      "name" = "dlySocialClassCount",
      "value" = 4,
      "comment" = "the social class count - under the warriors come the peasants, then the craftsmen, and finally the merchants, four social classes (print capture p. 304)",
    }, {
      "name" = "dlySocialClassLadder",
      "value" = 1,
      "comment" = "the social class ladder - under the warriors come the peasants, then the craftsmen, and finally the merchants (print capture p. 304)",
    }, {
      "name" = "dlyRigidClassLaws",
      "value" = 1,
      "comment" = "the rigid class laws - rigid laws have been enacted to keep each social class separate (print capture p. 304)",
    }, {
      "name" = "dlyWalledWards",
      "value" = 1,
      "comment" = "the walled wards - cities customarily divided into walled wards (print capture p. 304)",
    }, {
      "name" = "dlyArmedGatesNightCurfew",
      "value" = 1,
      "comment" = "the armed gates night curfew - those living in a ward must pass through armed gates to visit other parts of the city and must return to their own ward at night (print capture p. 304)",
    }, {
      "name" = "dlySamuraiPrivileges",
      "value" = 1,
      "comment" = "the samurai privileges - the samurai given special privileges, particularly those of the vendetta and the right to avenge insults, as befits their military upbringing (print capture p. 304)",
    }, {
      "name" = "dlyTravelStrictlyControlled",
      "value" = 1,
      "comment" = "the travel strictly controlled - travel is strictly controlled and leaving or entering the island is difficult (print capture p. 304)",
    }, {
      "name" = "dlyPreventRebellionIntent",
      "value" = 1,
      "comment" = "the prevent rebellion intent - the intent of these laws and regulations is to prevent any possibility of rebellion or civil war against the shogun (print capture p. 304)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dlySocialClassCount']() != 4  or  m['dlyUnifiedMilitaryState']() != 1  or  m['dlyEmperorHonorary']() != 1  or  m['dlyShogunRealPower']() != 1  or  m['dlyBarbarianSuppressingGeneral']() != 1  or  m['dlyShogunHidetomiFamily']() != 1  or  m['dlyFiefsGrantedByShogun']() != 1  or  m['dlyDaimyoPerFief']() != 1  or  m['dlyDaimyoTotalControl']() != 1  or  m['dlyCourtLimitedScope']() != 1  or  m['dlyConfiscateAndResettle']() != 1  or  m['dlyDaimyoServiceAndAdmin']() != 1  or  m['dlyWarriorStatusRaised']() != 1  or  m['dlySamuraiStipendOfRice']() != 1  or  m['dlySamuraiAbsoluteService']() != 1  or  m['dlySocialClassLadder']() != 1  or  m['dlyRigidClassLaws']() != 1  or  m['dlyWalledWards']() != 1  or  m['dlyArmedGatesNightCurfew']() != 1  or  m['dlySamuraiPrivileges']() != 1  or  m['dlyTravelStrictlyControlled']() != 1  or  m['dlyPreventRebellionIntent']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dlyUnifiedMilitaryState']() != 1  or m['dlyEmperorHonorary']() != 1  or m['dlyShogunRealPower']() != 1",
      "note" = "the state example",
    }, {
      "expr" = "m['dlyBarbarianSuppressingGeneral']() != 1  or m['dlyShogunHidetomiFamily']() != 1  or m['dlyConfiscateAndResettle']() != 1",
      "note" = "the shogun example",
    }, {
      "expr" = "m['dlyFiefsGrantedByShogun']() != 1  or m['dlyDaimyoPerFief']() != 1  or m['dlyDaimyoTotalControl']() != 1",
      "note" = "the fief example",
    }, {
      "expr" = "m['dlyCourtLimitedScope']() != 1  or m['dlyDaimyoServiceAndAdmin']() != 1",
      "note" = "the court example",
    }, {
      "expr" = "m['dlyWarriorStatusRaised']() != 1  or m['dlySamuraiStipendOfRice']() != 1  or m['dlySamuraiAbsoluteService']() != 1",
      "note" = "the warrior example",
    }, {
      "expr" = "m['dlySocialClassCount']() != 4  or m['dlySocialClassLadder']() != 1  or m['dlyRigidClassLaws']() != 1",
      "note" = "the class example",
    }, {
      "expr" = "m['dlyWalledWards']() != 1  or m['dlyArmedGatesNightCurfew']() != 1  or m['dlySamuraiPrivileges']() != 1",
      "note" = "the city example",
    }, {
      "expr" = "m['dlyTravelStrictlyControlled']() != 1  or m['dlyPreventRebellionIntent']() != 1",
      "note" = "the intent example",
    } },
  "audit" = {
      "label" = "R763 OA Wa audit",
      "comment" = "OA round one hundred fifty (capture p. 304): the island of Wa - the unified military state, the honorary emperor, the shogun of the Hidetomi family, the fief system of the daimyos, the samurai stipend of rice, the walled wards, single-pass pins per the R679 provenance shift",
    },
}
