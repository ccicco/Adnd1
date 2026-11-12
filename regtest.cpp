#include "monsters/MonsterRegistry.h"
#include "dm/encounters.h"
#include "dm/outdoormove.h"   // R123: pp.58-59 daily rates
#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables
#include "dm/appendixgh.h"  // R125: pp.216-217 Appendix G/H lists
#include "dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon
#include "dm/appendixp.h"  // R147: pp.225-226 Appendix P tables
#include "dm/appendixi.h"  // R150: pp.217-220 Appendix I dressing
#include "dm/appendixo.h"  // R151: p.225 Appendix O item weights
#include "dm/dungeon.h"    // R124: generator smoke in the audit
#include "game/party.h"
#include "game/appstate.h"  // R233: the multi-class audit
#include "ai/actor.h"  // R782: the deity bridge site block
#include "rules/engine/combat.h"
#include "rules/engine/saves.h"
#include "spells/spells.h"
#include "abilities/abilities.h"
#include "rules/engine/races.h"   // R154: pp.15-18 Race Tables I-III
#include "rules/dmg/grenade.h"  // R157: pp.64-65 grenade-like missiles
#include "rules/dmg/weaponspeed.h"  // R158: p.66 weapon speed factors
#include "rules/dmg/subdue.h"  // R159: p.67 striking to subdue
#include "rules/dmg/weaponless.h"  // R160: pp.72-73 weaponless combat
#include "rules/dmg/twoweapon.h"  // R161: p.70 attacks with two weapons
#include "rules/dmg/poison.h"  // R163: p.20 the poison table
#include "rules/dmg/assassinate.h"  // R164: p.75 the assassination table
#include "rules/dmg/miscibility.h"  // R165: p.119 potion miscibility
#include "rules/dmg/insanity.h"  // R166: pp.82-83 intoxication and insanity
#include "rules/seams/psionics.h"  // R404: the psionics seam
#include "rules/dmg/disease.h"  // R167: pp.13-14 disease and parasitic infestation
#include "rules/dmg/uwspells.h"  // R168: p.57 underwater spell use
#include "rules/seams/aerial.h"  // R321: pp.49-53 aerial combat
#include "rules/ua/comeliness.h"  // R322: UA comeliness pins
#include "rules/ua/subraces.h"  // R323: UA subrace layer
#include "rules/ua/subracelevels.h"  // R324: UA Race Table II
#include "rules/ua/subracecap.h"  // R325: UA Race Table II fold
#include "rules/ua/classtables.h"  // R327: UA Classes Tables I-II
#include "rules/ua/cavalier.h"  // R328: the UA cavalier
#include "rules/ua/paladin.h"  // R329: the paladin reparent
#include "rules/ua/hierophant.h"  // R330: the UA druid hierophant
#include "rules/ua/weaponspec.h"  // R331: the UA weapon spec
#include "rules/ua/barbarian.h"  // R332: the UA barbarian
#include "rules/ua/uaranger.h"  // R333: the UA ranger expansion
#include "rules/ua/thiefarmor.h"  // R334: the UA thief armor and attacks
#include "rules/ua/acrobat.h"  // R335: the UA thief-acrobat
#include "rules/ua/cavmoney.h"  // R336: the UA cavalier money
#include "rules/ua/uaweapontable.h"  // R337: the UA weight and damage
#include "rules/ua/uamissile.h"  // R338: the UA hurled and missile data
#include "rules/ua/uaprof.h"  // R339: the UA weapon proficiency
#include "rules/ua/uanewweapons.h"  // R340: the UA new weapons prose
#include "rules/ua/uaspelltables.h"  // R341: the UA spell tables part 1
#include "rules/ua/uaspelltables2.h"  // R342: the UA MU and illusionist tables
#include "rules/ua/uaclericspells1.h"  // R343: the UA new cleric 1st level
#include "rules/ua/uaclericspells2.h"  // R344: the UA new cleric 2nd level
#include "rules/ua/uaclericspells3.h"  // R345: the UA new cleric 3rd level
#include "rules/ua/uaclericspells4.h"  // R346: the UA new cleric 4th level
#include "rules/ua/uaclericspells5.h"  // R347: the UA new cleric 5th level
#include "rules/ua/uaclericspells6.h"  // R348: the UA new cleric 6th level
#include "rules/ua/uaclericspells7.h"  // R349: the UA new cleric 7th level
#include "rules/ua/uadruidspells1.h"  // R350: the UA new druid 1st level
#include "rules/ua/uadruidspells2.h"  // R351: the UA new druid 2nd level
#include "rules/ua/uadruidspells3.h"  // R352: the UA new druid 3rd level
#include "rules/ua/uadruidspells5.h"  // R353: the UA new druid 5th level
#include "rules/ua/uadruidspells6.h"  // R354: the UA new druid 6th level
#include "rules/ua/uadruidspells7.h"  // R355: the UA new druid 7th level
#include "rules/ua/uamuspells1.h"  // R356: the UA new magic-user 1st level
#include "rules/ua/uamuspells2.h"  // R357: the UA new magic-user 2nd level
#include "rules/ua/uamuspells3.h"  // R358: the UA new magic-user 3rd level
#include "rules/ua/uamuspells4.h"  // R359: the UA new magic-user 4th level
#include "rules/ua/uamuspells5.h"  // R360: the UA new magic-user 5th level
#include "rules/ua/uamuspells6.h"  // R360: the UA new magic-user 6th level
#include "rules/ua/uamuspells7.h"  // R361: the UA new magic-user 7th level
#include "rules/ua/uamuspells8.h"  // R362: the UA new magic-user 8th level
#include "rules/ua/uamuspells9.h"  // R362: the UA new magic-user 9th level
#include "rules/ua/uailcantrips.h"  // R363: the UA new illusionist cantrips
#include "rules/ua/uailspells1.h"  // R363: the UA new illusionist 1st level
#include "rules/ua/uailspells2.h"  // R363: the UA new illusionist 2nd level
#include "rules/ua/uailspells3.h"  // R364: the UA new illusionist 3rd level
#include "rules/ua/uailspells4.h"  // R364: the UA new illusionist 4th level
#include "rules/ua/uailspells5.h"  // R364: the UA new illusionist 5th level
#include "rules/ua/uailspells6.h"  // R365: the UA new illusionist 6th level
#include "rules/ua/uailspells7.h"  // R365: the UA new illusionist 7th level
#include "rules/ua/uailacquisition.h"  // R365: the UA illusionist acquisition
#include "rules/ua/uaspellcost.h"  // R365: the UA spell casting cost
#include "rules/ua/uaspellbooks.h"  // R366: the UA spell books
#include "rules/ua/uaspellcomment.h"  // R366: the UA spell commentary
#include "rules/ua/uauwspelluse.h"  // R366: the UA underwater spells
#include "rules/ua/uadarkness.h"  // R366: the UA effects of darkness
#include "rules/ua/uasocialclass.h"  // R367: the UA social class
#include "rules/ua/uabirth.h"  // R367: the UA circumstances of birth
#include "rules/ua/uacavtable.h"  // R368: the UA Cavaliers Table I
#include "rules/ua/uacantacq.h"  // R369: the UA cantrip acquisition
#include "rules/ua/uasmalls1.h"  // R370: the UA DM-section smalls
#include "rules/ua/uaarmor.h"  // R371: the UA expanded armor
#include "rules/ua/uafollowers.h"  // R372: the UA cavalier followers
#include "rules/ua/uacomnote.h"  // R373: the UA comeliness note
#include "rules/ua/uatreasuredial.h"  // R374: the UA treasure dial
#include "rules/ua/uadetskel.h"  // R375: the UA determination skeleton
#include "rules/ua/uadetrows.h"  // R395: the UA determination row bodies
#include "rules/ua/uapotprose.h"  // R376: the UA new potions prose
#include "rules/ua/uaprotscr.h"  // R377: the UA new scrolls prose
#include "rules/ua/uaringprose.h"  // R378: the UA new rings prose
#include "rules/ua/uarodstave.h"  // R379: the UA new rods staves prose
#include "rules/ua/uawandprose.h"  // R380: the UA new wands prose
#include "rules/ua/uamiscprose1.h"  // R381: the UA misc magic prose 1
#include "rules/ua/uamiscprose2.h"  // R382: the UA misc magic prose 2
#include "rules/ua/uamiscprose3.h"  // R383: the UA misc magic prose 3
#include "rules/ua/uamiscprose4.h"  // R384: the UA misc magic prose 4
#include "rules/ua/uamiscprose5.h"  // R385: the UA misc magic prose 5
#include "rules/ua/uamiscprose6.h"  // R386: the UA misc magic prose 6
#include "rules/ua/uaarmprose.h"  // R387: the UA armor prose
#include "rules/ua/uamweapprose.h"  // R388: the UA misc weapons prose
#include "rules/ua/uaappendq.h"  // R389: the UA weaponless combat
#include "rules/ua/uaappendr.h"  // R390: the UA non-lethal combat
#include "rules/ua/uaappendt.h"  // R391: the UA pole-arm nomenclature
#include "rules/ua/uaequip26.h"  // R392: the UA equipment costs
#include "rules/ua/uaac26.h"  // R408: the UA p. 26 AC table
#include "rules/ua/uahandheld.h"  // R392: the UA hand-held data
#include "rules/ua/cantriptier.h"  // R401: the UA cantrip tier
#include "rules/ua/uacantrips1.h"  // R412: the UA useful cantrips
#include "rules/ua/uacantrips2.h"  // R413: the UA reversed cantrips
#include "rules/ua/uacantrips3.h"  // R414: the UA legerdemain cantrips
#include "rules/ua/uacantrips4.h"  // R415: the UA person-affecting cantrips
#include "rules/ua/uacantrips5.h"  // R416: the UA personal cantrips
#include "rules/ua/uacantrips6.h"  // R417: the UA haunting-sound cantrips
#include "rules/dmg/humrpref.h"  // R169: p.106 humanoid racial preferences
#include "rules/seams/deities.h"  // R405: the deity layer seam
#include "rules/ua/uaappends.h"  // R406: the UA Appendix S stat blocks
#include "rules/ua/uasstatlines.h"  // R409: the UA Appendix S stat lines
#include "rules/ua/uasclasslines.h"  // R410: the UA Appendix S class lines
#include "rules/ua/uamoves.h"  // R411: the UA Appendix S MOVE values
#include "rules/ua/uapantheon.h"  // R423: the UA Appendix S pantheon prose
#include "rules/wsg/wsgprof.h"  // R425: the WSG wilderness proficiencies
#include "rules/wsg/wsgdress.h"  // R426: the WSG dressing for the weather
#include "rules/wsg/wsgenvfx.h"  // R427: the WSG environment effects
#include "rules/wsg/wsgsplwx.h"  // R429: the WSG special weather tables
#include "rules/wsg/wsgheat.h"  // R430: the WSG heat and cold damage tables
#include "rules/wsg/wsgequip.h"  // R431: the WSG effects on equipment
#include "rules/wsg/wsgencum.h"  // R432: the WSG encumbrance and movement
#include "rules/wsg/wsganimal.h"  // R433: the WSG land-based animals
#include "rules/wsg/wsgvehicle.h"  // R434: the WSG land-based vehicles
#include "rules/wsg/wsgclimb.h"  // R435: the WSG climbing
#include "rules/wsg/wsgcheck.h"  // R436: the WSG climbing checks
#include "rules/wsg/wsgfall.h"  // R437: the WSG damage from falling
#include "rules/wsg/wsgtumble.h"  // R438: the WSG tumbling damage
#include "rules/wsg/wsgstop.h"  // R439: the WSG stopping a fall
#include "rules/wsg/wsgrope.h"  // R440: the WSG rope use
#include "rules/wsg/wsgtog.h"  // R441: the WSG roping together
#include "rules/wsg/wsgrapp.h"  // R442: the WSG rappelling
#include "rules/wsg/wsgbelay.h"  // R443: the WSG belaying
#include "rules/wsg/wsggrap.h"  // R444: the WSG grappling hooks
#include "rules/wsg/wsgchasm.h"  // R445: the WSG chasm crossing
#include "rules/wsg/wsgmntnr.h"  // R446: the WSG mountaineering proficiency
#include "rules/wsg/wsgslip.h"  // R447: the WSG slippery surface movement
#include "rules/wsg/wsgjump.h"  // R448: the WSG jumping rules
#include "rules/wsg/wsgvis.h"  // R449: the WSG movement in reduced visibility
#include "rules/wsg/wsgswim.h"  // R450: the WSG swimming rules
#include "rules/wsg/wsgmwater.h"  // R451: the WSG other effects of moving water
#include "rules/wsg/wsgdive.h"  // R452: the WSG diving and surfacing
#include "rules/wsg/wsgtread.h"  // R453: the WSG treading water
#include "rules/wsg/wsgbreath.h"  // R454: the WSG holding one breath
#include "rules/wsg/wsgvessels.h"  // R455: the WSG movement in waterborne vehicles
#include "rules/wsg/wsgcapsizing.h"  // R456: the WSG capsizing and damage to craft
#include "rules/wsg/wsgboat.h"  // R457: the WSG boating proficiency
#include "rules/wsg/wsgportage.h"  // R458: the WSG portaging
#include "rules/wsg/wsgcapsized.h"  // R459: the WSG use of a capsized vessel
#include "rules/wsg/wsgflymounts.h"  // R460: the WSG flying mounts
#include "rules/wsg/wsgfallair.h"  // R461: the WSG airborne fall chance
#include "rules/wsg/wsgfood.h"  // R462: the WSG going without food and water
#include "rules/wsg/wsgforage.h"  // R463: the WSG food gathering, foraging and Table 30
#include "rules/wsg/wsghunt.h"  // R464: the WSG hunting, stalking and Table 31
#include "rules/wsg/wsgfish.h"  // R465: the WSG hunting proficiency, fishing and Table 32
#include "rules/wsg/wsgcarry.h"  // R466: the WSG consuming and carrying food and Table 33
#include "rules/wsg/wsgwater.h"  // R467: the WSG finding water and Table 34
#include "rules/wsg/wsgwhere.h"  // R468: the WSG where water is found
#include "rules/wsg/wsgdesert.h"  // R469: the WSG water in the desert and permafrost
#include "rules/wsg/wsgpurify.h"  // R470: the WSG purifying water and tainted water
#include "rules/wsg/wsgshelter.h"  // R471: the WSG natural shelters and Table 35
#include "rules/wsg/wsgtents.h"  // R472: the WSG portable shelters and Table 36
#include "rules/wsg/wsgsleep.h"  // R473: the WSG shelter mechanics, rest and sleep, and Table 37
#include "rules/wsg/wsgfire.h"  // R474: the WSG rest quality, armor timing and campfires, and Table 38
#include "rules/wsg/wsgfuel.h"  // R475: the WSG fuel availability and fire safety, and Table 39
#include "rules/wsg/wsgblaze.h"  // R476: the WSG uncontrollable fires, and the fire discipline and extinguishing rules
#include "rules/wsg/wsgdmg.h"  // R477: the WSG damage from fire, and the firebreak and heat rules
#include "rules/wsg/wsgmed.h"  // R478: the WSG medicinal plants, and the Table 40 grids
#include "rules/wsg/wsglore.h"  // R479: the WSG plant lore proficiency prose
#include "rules/wsg/wsginj.h"  // R480: the WSG injuries and treatment rules
#include "rules/wsg/wsgfae.h"  // R481: the WSG first aid equipment gear rules
#include "rules/wsg/wsgnvis.h"  // R482: the WSG normal vision definition and range rules
#include "rules/wsg/wsginfra.h"  // R483: the WSG infravision and Table 41 range rules
#include "rules/wsg/wsgultra.h"  // R484: the WSG ultravision and infravision effectiveness rules
#include "rules/wsg/wsglight.h"  // R485: the WSG artificial illumination light-source rules
#include "rules/wsg/wsghazd.h"  // R486: the WSG volcano, earthquake and tidal wave hazard rules
#include "rules/wsg/wsghazd2.h"  // R487: the WSG flood, avalanche, mudslide and quicksand hazard rules
#include "rules/wsg/wsgfight.h"  // R488: the WSG wilderness combat rules
#include "rules/wsg/wsgfatig.h"  // R489: the WSG fatigue and exhaustion rules
#include "rules/wsg/wsgmount.h"  // R490: the WSG mounts and beasts of burden rules
#include "rules/wsg/wsgmagic.h"  // R491: the WSG magic in the wilderness rules
#include "rules/wsg/wsgdm.h"  // R492: the WSG Dungeon Master section rules
#include "rules/wsg/wsgweather.h"  // R493: the WSG World of Weather generation rules
#include "rules/wsg/wsgweathx.h"  // R494: the WSG World of Weather special weather and optional rules
#include "rules/wsg/wsgtables.h"  // R495: R495: the WSG compiled tables manifest
#include "rules/wsg/wsgrecon.h"  // R496: the WSG gap reconciliation bookkeeping
#include "rules/wsg/wsgoverview.h"  // R497: the WSG overview chapter pins
#include "rules/wsg/wsgprofd.h"  // R498: the WSG proficiencies prose pins
#include "rules/wsg/wsgtempfold.h"  // R499: the WSG temperature-chain fold pins
#include "rules/wsg/wsgswimfold.h"  // R500: the WSG swimmer's motion-chain fold pins
#include "rules/wsg/wsgmovefold.h"  // R501: the WSG movement/fall-chain fold pins
#include "rules/wsg/wsgcampfold.h"  // R502: the WSG camp-chain fold pins
#include "rules/dsg/dsgoverview.h"  // R503: the DSG overview pins
#include "rules/dsg/dsgmove.h"  // R504: the DSG movement I pins
#include "rules/dsg/dsgmove2.h"  // R505: the DSG movement II pins
#include "rules/dsg/dsgprof.h"  // R506: the DSG proficiencies pins
#include "rules/dsg/dsgfight.h"  // R507: the DSG combat pins
#include "rules/dsg/dsgbatt.h"  // R508: the DSG battlesystem pins
#include "rules/dsg/dsgair.h"  // R509: the DSG air and gases pins
#include "rules/dsg/dsgodor.h"  // R510: the DSG odor detection pins
#include "rules/dsg/dsgcavein.h"  // R511: the DSG cave-in causes pins
#include "rules/dsg/dsgcavein2.h"  // R512: the DSG chain reaction pins
#include "rules/dsg/dsgdpv.h"  // R513: the DSG DPV and hypothermia pins
#include "rules/dsg/dsglode.h"  // R514: the DSG lodestone and NPC reaction pins
#include "rules/dsg/dsgdecay.h"  // R516: the DSG structural decay pins
#include "rules/dsg/dsgwater.h"  // R517: the DSG underground waterways pins
#include "rules/dsg/dsgboat.h"  // R518: the DSG underground water travel pins
#include "rules/dsg/dsgmine.h"  // R519: the DSG mining where-to-mine and types pins
#include "rules/dsg/dsgmine2.h"  // R520: the DSG mining excavation veins and shoring pins
#include "rules/dsg/dsgmine3.h"  // R521: the DSG mining products pins
#include "rules/dsg/dsgmine4.h"  // R522: the DSG mine product quality pins
#include "rules/dsg/dsgmine5.h"  // R523: the DSG mining tail pins
#include "rules/dsg/dsgmine6.h"  // R524: the DSG hireling loyalty and hazards pins
#include "rules/dsg/dsgequip.h"  // R525: the DSG equipment costs pins
#include "rules/dsg/dsgequip2.h"  // R526: the DSG equipment descriptions pins
#include "rules/dsg/dsgequip3.h"  // R527: the DSG proficiency descriptions pins
#include "rules/dsg/dsgplay.h"  // R528: the DSG improving-play opener pins
#include "rules/dsg/dsgplay2.h"  // R529: the DSG improving-play tail pins
#include "rules/dsg/dsgenv.h"  // R530: the DSG underground environment pins
#include "rules/dsg/dsggeo.h"  // R531: the DSG underground geography and theories pins
#include "rules/dsg/dsgcult.h"  // R532: the DSG cultures of the underdark pins
#include "rules/dsg/dsgland.h"  // R533: the DSG lands of Deepearth opener pins
#include "rules/dsg/dsgarea1.h"  // R534: the DSG Deepearth areas 1-3 pins
#include "rules/dsg/dsgarea2.h"  // R535: the DSG Deepearth areas 4-5 pins
#include "rules/dsg/dsgarea3.h"  // R536: the DSG Deepearth areas 6-7 pins
#include "rules/dsg/dsgarea4.h"  // R537: the DSG Deepearth areas 8-9 pins
#include "rules/dsg/dsgarea5.h"  // R538: the DSG Deepearth areas 10-11 pins
#include "rules/dsg/dsgarea6.h"  // R539: the DSG Deepearth areas 12-13 pins
#include "rules/dsg/dsgarea7.h"  // R540: the DSG Deepearth areas 14-15 pins
#include "rules/dsg/dsgarea8.h"  // R541: the DSG Deepearth areas 16-17 pins
#include "rules/dsg/dsgarea9.h"  // R542: the DSG Deepearth areas 18-19 pins
#include "rules/dsg/dsgarea10.h"  // R543: the DSG Deepearth areas 20-21 pins
#include "rules/dsg/dsgarea11.h"  // R544: the DSG Deepearth areas 22-23 pins
#include "rules/dsg/dsgarea12.h"  // R545: the DSG Deepearth areas 24-25 pins
#include "rules/dsg/dsgarea13.h"  // R546: the DSG Deepearth areas 26-27 pins
#include "rules/dsg/dsgarea14.h"  // R547: the DSG Deepearth areas 28-29 pins
#include "rules/dsg/dsgarea15.h"  // R548: the DSG Deepearth areas 30-31 pins
#include "rules/dsg/dsgdeep.h"  // R549: the DSG Deepearth closure
#include "rules/dsg/dsgcamp.h"  // R550: the DSG campaign opener pins
#include "rules/dsg/dsgcamp2.h"  // R551: the DSG worlds of adventure pins
#include "rules/dsg/dsgcamp3.h"  // R552: the DSG plot and counterplot pins
#include "rules/dsg/dsgcamp4.h"  // R553: the DSG story elements tail pins
#include "rules/dsg/dsgcamp5.h"  // R554: the DSG techniques of story and campaign design pins
#include "rules/dsg/dsgcamp6.h"  // R555: the DSG help from the players pins
#include "rules/dsg/dsgcamp7.h"  // R556: the DSG campaign considerations closure
#include "rules/dsg/dsgmap.h"  // R557: the DSG mapping your settings pins
#include "rules/dsg/dsgtabs.h"  // R558: the DSG compiled tables pins
#include "rules/dsg/dsgplate.h"  // R559: the DSG perspective map plates closure
#include "rules/dsg/dsgindex.h"  // R560: the DSG index roster pins
#include "rules/dsg/dsgdmsec.h"  // R561: the DSG DM section parent closure
#include "rules/dsg/dsgintro.h"  // R562: the DSG what-is-it front matter pins
#include "rules/dsg/dsgfin.h"  // R563: the DSG arc final census closure
#include "rules/mop/motpintro.h"  // R564: the MotP introduction opener pins
#include "rules/mop/motpspell.h"  // R565: the MotP spell summary pins
#include "rules/mop/motpeth.h"  // R566: the MotP Ethereal chapter pins
#include "rules/mop/motpinner.h"  // R567: the MotP inner planes doctrine pins
#include "rules/mop/motpair.h"  // R568: the MotP Air plane pins
#include "rules/mop/motpfire.h"  // R569: the MotP Fire plane pins
#include "rules/mop/motpearth.h"  // R570: the MotP Earth plane pins
#include "rules/mop/motpwater.h"  // R571: the MotP Water plane pins
#include "rules/mop/motppara.h"  // R572: the MotP para-planes pins
#include "rules/mop/motpenergy.h"  // R573: the MotP energy planes pins
#include "rules/mop/motpquasipos.h"  // R574: the MotP positive quasi-planes pins
#include "rules/mop/motpquasineg.h"  // R575: the MotP negative quasi-planes pins
#include "rules/mop/astralplane.h"  // R576: the Astral Plane pins
#include "rules/mop/outerplanes.h"  // R577: the outer planes general pins
#include "rules/mop/nirvanaarcadia.h"  // R578: the Nirvana and Arcadia pins
#include "rules/mop/heavenstwins.h"  // R579: the Seven Heavens and Twin Paradises pins
#include "rules/mop/elysiumbeasts.h"  // R580: the Elysium and Beastlands pins
#include "rules/mop/olympusgladsheim.h"  // R581: the Olympus and Gladsheim pins
#include "rules/mop/limbopandemonium.h"  // R582: the Limbo and Pandemonium pins
#include "rules/mop/abyss.h"  // R583: the Abyss pins
#include "rules/mop/tarterus.h"  // R584: the Tarterus pins
#include "rules/mop/hades.h"  // R585: the Hades pins
#include "rules/mop/gehenna.h"  // R586: the Gehenna pins
#include "rules/mop/ninehells.h"  // R587: the Nine Hells pins
#include "rules/mop/acheron.h"  // R588: the Acheron pins
#include "rules/mop/concordantopposition.h"  // R589: the Concordant Opposition pins
#include "rules/mop/beyondouterplanes.h"  // R590: the Beyond the outer planes pins
#include "rules/mop/outerplanesseal.h"  // R591: the Outer Planes chapter seal pins
#include "rules/mop/appendixiprimes.h"  // R592: the Appendix I Prime Material Planes pins
#include "rules/mop/appendixiiinnercreatures.h"  // R593: the Appendix II inner creatures pins
#include "rules/mop/appendixiiioutercreatures.h"  // R594: the Appendix III outer creatures pins
#include "rules/mop/appendixivabilitiespowers.h"  // R595: the Appendix IV Powers abilities pins
#include "rules/mop/indices.h"  // R596: the Indices closing pins
#include "rules/mop/motpethcyclone.h"  // R598: the MotP Ether cyclone pins
#include "rules/dmo/dmomaxims.h"  // R599: the DMO arc opener pins
#include "rules/dmo/dmocampaign.h"  // R600: the DMO maxim-doctrine pins
#include "rules/dmo/dmoadventures.h"  // R601: the DMO adventure-doctrine pins
#include "rules/dmo/dmoworlds.h"  // R602: the DMO world-rating pins
#include "rules/dmo/dmomonsters.h"  // R603: the DMO monster-doctrine pins
#include "rules/dmo/dmospells.h"  // R604: the DMO spells-and-items pins
#include "rules/dmo/dmoitems.h"  // R605: the DMO item-creation pins
#include "rules/dmo/dmoduels.h"  // R606: the DMO magical-duels pins
#include "rules/dmo/dmodweomers.h"  // R607: the DMO true-dweomer pins
#include "rules/dmo/dmohighlevel.h"  // R608: the DMO high-level save pins
#include "rules/dmo/dmohighskills.h"  // R609: the DMO high-level skills pins
#include "rules/dmo/dmohighwizpri.h"  // R610: the DMO wizard and priest pins
#include "rules/dmo/dmohighrogues.h"  // R611: the DMO rogue pins
#include "rules/dmo/dmohighascend.h"  // R612: the DMO demihuman and ascension pins
#include "rules/dmo/dmoduelroster.h"  // R613: the DMO spell dueling roster pins
#include "rules/oa/oacreating.h"  // R614: the OA arc opener pins
#include "rules/oa/oaabilities.h"  // R615: the OA ability tables pins
#include "rules/oa/oaabilityprose.h"  // R616: the OA ability prose pins
#include "rules/oa/oaclasscombos.h"  // R617: the OA class combos pins
#include "rules/oa/oaraces.h"  // R618: the OA races pins
#include "rules/oa/oabarbbushi.h"  // R619: the OA barbarian and bushi pins
#include "rules/oa/oakensai.h"  // R620: the OA kensai pins
#include "rules/oa/oamonk.h"  // R621: the OA monk pins
#include "rules/oa/oaninja.h"  // R622: the OA ninja pins
#include "rules/oa/oasamurai.h"  // R623: the OA samurai pins
#include "rules/oa/oashukenja.h"  // R624: the OA shukenja pins
#include "rules/oa/oasohei.h"  // R625: the OA sohei pins
#include "rules/oa/oawujen.h"  // R626: the OA wu jen pins
#include "rules/oa/oayakuza.h"  // R627: the OA yakuza pins
#include "rules/oa/oacharab.h"  // R628: the OA character abilities pins
#include "rules/oa/oabirth.h"  // R629: the OA families pins
#include "rules/oa/oafamstr.h"  // R630: the OA family structures pins
#include "rules/oa/oaanc.h"  // R631: the OA ancestry pins
#include "rules/oa/oahold.h"  // R632: the OA holdings pins
#include "rules/oa/oabr.h"  // R633: the OA birthrights pins
#include "rules/oa/oahonor.h"  // R634: the OA honor pins
#include "rules/oa/oaeff.h"  // R635: the OA effects of honor pins
#include "rules/oa/oamoney.h"  // R636: the OA money pins
#include "rules/oa/oastart.h"  // R637: the OA starting money pins
#include "rules/oa/oaexch.h"  // R638: the OA exchange pins
#include "rules/oa/oaequip.h"  // R639: the OA equipment pins
#include "rules/oa/oaweapon.h"  // R640: the OA weapons pins
#include "rules/oa/oahandheld.h"  // R641: the OA hand-held pins
#include "rules/oa/oahurled.h"  // R642: the OA hurled pins
#include "rules/oa/oaarmor.h"  // R643: the OA armor pins
#include "rules/oa/oapiece.h"  // R644: the OA piece armor pins
#include "rules/oa/oaencumb.h"  // R645: the OA armor encumbrance pins
#include "rules/oa/oabarding.h"  // R646: the OA barding pins
#include "rules/oa/oagrenade.h"  // R647: the OA grenades pins
#include "rules/oa/oabardprose.h"  // R648: the OA barding prose pins
#include "rules/oa/oaarmordesc.h"  // R649: the OA armor descriptions pins
#include "rules/oa/oaweaponspec.h"  // R650: the OA weapon specialization pins
#include "rules/oa/oamslspec.h"  // R651: the OA missile specializations pins
#include "rules/oa/oanwprof.h"  // R652: the OA non-weapon proficiency pins
#include "rules/oa/oacharprof.h"  // R653: the OA character proficiencies pins
#include "rules/oa/oaartprof.h"  // R654: the OA artisan proficiencies pins
#include "rules/oa/oabarbprof.h"  // R655: the OA barbarian proficiencies pins
#include "rules/oa/oacomprof.h"  // R656: the OA common proficiencies pins
#include "rules/oa/oacourtprof.h"  // R657: the OA court proficiencies pins
#include "rules/oa/oashkspells.h"  // R658: the OA shukenja spell list pins
#include "rules/oa/oal1spells.h"  // R659: the OA first level spells pins
#include "rules/oa/oal2spells.h"  // R660: the OA second level spells pins
#include "rules/oa/oal3spells.h"  // R661: the OA third level spells pins
#include "rules/oa/oal4spells.h"  // R662: the OA fourth level spells pins
#include "rules/oa/oal5spells.h"  // R663: the OA fifth level spells pins
#include "rules/oa/oal6spells.h"  // R664: the OA sixth level spells pins
#include "rules/oa/oal7spells.h"  // R665: the OA seventh level spells pins
#include "rules/oa/oat63divination.h"  // R666: the OA divination results pins
#include "rules/oa/oat64speakdead.h"  // R667: the OA speak with dead pins
#include "rules/oa/oat65fate.h"  // R668: the OA fate pins
#include "rules/oa/oawjspelllist.h"  // R669: the OA wu jen spell list pins
#include "rules/oa/oawjl1spells.h"  // R670: the OA wu jen first level spells pins
#include "rules/oa/oawjl2spells.h"  // R671: the OA wu jen second level spells pins
#include "rules/oa/oawjl3spells.h"  // R672: the OA wu jen third level spells pins
#include "rules/oa/oawjl4spells.h"  // R673: the OA wu jen fourth level spells pins
#include "rules/oa/oawjl5spells.h"  // R674: the OA wu jen fifth level spells pins
#include "rules/oa/oawjl6spells.h"  // R675: the OA wu jen sixth level spells pins
#include "rules/oa/oawjl7spells.h"  // R676: the OA wu jen seventh level spells pins
#include "rules/oa/oawjl8spells.h"  // R677: the OA wu jen eighth level spells pins
#include "rules/oa/oawjl9spells.h"  // R678: the OA wu jen ninth level spells pins
#include "rules/oa/oacombatseq.h"  // R679: the OA combat sequence pins
#include "rules/oa/oaiaijutsu.h"  // R680: the OA iaijutsu surprise pins
#include "rules/oa/oainitmods.h"  // R681: the OA initiative modifiers pins
#include "rules/oa/oahorsefire.h"  // R682: the OA mounted bowfire pins
#include "rules/oa/oa67bowfire.h"  // R683: the OA Table 67 bowfire modifier pins
#include "rules/oa/oaunhorsing.h"  // R684: the OA unhorsing pins
#include "rules/oa/oadisarming.h"  // R685: the OA disarming pins
#include "rules/oa/oasubdual.h"  // R686: the OA subduing pins
#include "rules/oa/oapsychicduel.h"  // R687: the OA psychic duel pins
#include "rules/oa/oamartialopen.h"  // R688: the OA martial arts opener pins
#include "rules/oa/oa68styles.h"  // R689: the OA Table 68 common styles pins
#include "rules/oa/oacreatestyle.h"  // R690: the OA creating a style pins
#include "rules/oa/oa69combos.h"  // R691: the OA Table 69 style combinations pins
#include "rules/oa/oa70maneuvers.h"  // R692: the OA Table 70 special maneuvers pins
#include "rules/oa/oamethods.h"  // R693: the OA principal methods pins
#include "rules/oa/oatrain.h"  // R694: the OA mental and physical training pins
#include "rules/oa/oalearn.h"  // R695: the OA learning martial arts pins
#include "rules/oa/oacalendar.h"  // R696: the OA calendar pins
#include "rules/oa/oa71yearly.h"  // R697: the OA Table 71 yearly events pins
#include "rules/oa/oa71explain.h"  // R698: the OA yearly events explanation pins
#include "rules/oa/oa72monthly.h"  // R699: the OA Table 72 monthly events pins
#include "rules/oa/oa72explain.h"  // R700: the OA monthly events explanation pins
#include "rules/oa/oa73daily.h"  // R701: the OA Table 73 daily events pins
#include "rules/oa/oa73explain.h"  // R702: the OA daily events explanation pins
#include "rules/oa/oa74terrain.h"  // R703: the OA Chapter 11 terrain encounter tables pins
#include "rules/oa/oa75climate.h"  // R704: the OA climate groupings pins
#include "rules/oa/oa76bajang.h"  // R705: the OA Bajang pins
#include "rules/oa/oa77bakemono.h"  // R706: the OA Bakemono pins
#include "rules/oa/oa78bisan.h"  // R707: the OA Bisan pins
#include "rules/oa/oa79buso.h"  // R708: the OA Buso pins
#include "rules/oa/oa80carp.h"  // R709: the OA Giant Carp pins
#include "rules/oa/oa81continh.h"  // R710: the OA Con-Tinh pins
#include "rules/oa/oa82doccuoc.h"  // R711: the OA Doc Cu'o'c pins
#include "rules/oa/oa83dragons.h"  // R712: the OA Oriental Dragons pins
#include "rules/oa/oa84gaki.h"  // R713: the OA Gaki pins
#include "rules/oa/oa85gargantua.h"  // R714: the OA Gargantua pins
#include "rules/oa/oa86generals.h"  // R715: the OA Animal Generals pins
#include "rules/oa/oa87goblinrat.h"  // R716: the OA Goblin Rat pins
#include "rules/oa/oa88goblinspider.h"  // R717: the OA Goblin Spider pins
#include "rules/oa/oa89hainu.h"  // R718: the OA Hai Nu pins
#include "rules/oa/oa90hsingsing.h"  // R719: the OA Hsing-Sing pins
#include "rules/oa/oa91huhuien.h"  // R720: the OA Hu Hsien pins
#include "rules/oa/oa92kala.h"  // R721: the OA Kala pins
#include "rules/oa/oa93kappa.h"  // R722: the OA Kappa pins
#include "rules/oa/oa94kuei.h"  // R723: the OA Kuei pins
#include "rules/oa/oa95menwako.h"  // R724: the OA Men Wako pins
#include "rules/oa/oa96nat.h"  // R725: the OA Nat pins
#include "rules/oa/oa97naturespirit.h"  // R726: the OA Nature Spirits pins
#include "rules/oa/oa98ningyo.h"  // R727: the OA Ningyo pins
#include "rules/oa/oa99oni.h"  // R728: the OA Oni pins
#include "rules/oa/oa100poh.h"  // R729: the OA P oh pins
#include "rules/oa/oa101shansao.h"  // R730: the OA Shan Sao pins
#include "rules/oa/oa102shiro.h"  // R731: the OA Shirokinukatsukami pins
#include "rules/oa/oa103tengu.h"  // R732: the OA Tengu pins
#include "rules/oa/oa104classuse.h"  // R733: the OA class usage pins
#include "rules/oa/oa105randtres.h"  // R734: the OA random treasure pins
#include "rules/oa/oa106table74.h"  // R735: the OA Table 74 pins
#include "rules/oa/oa107tableiia.h"  // R736: the OA Table II.A. pins
#include "rules/oa/oa108tableiii.h"  // R737: the OA Table III pins
#include "rules/oa/oa109itemmods.h"  // R738: the OA item mods pins
#include "rules/oa/oa110potions.h"  // R739: the OA potions pins
#include "rules/oa/oa111scrolls.h"  // R740: the OA scrolls pins
#include "rules/oa/oa112rods.h"  // R741: the OA rods pins
#include "rules/oa/oa113miscmagic.h"  // R742: the OA misc magic pins
#include "rules/oa/oa114armorprose.h"  // R743: the OA armor prose pins
#include "rules/oa/oa115table75.h"  // R744: the OA Table 75 pins
#include "rules/oa/oa116table76.h"  // R745: the OA Table 76 pins
#include "rules/oa/oa117table77.h"  // R746: the OA Table 77 pins
#include "rules/oa/oa118armorexpl.h"  // R747: the OA armor explanation pins
#include "rules/oa/oa119weaponsprose.h"  // R748: the OA weapons prose pins
#include "rules/oa/oa120table78.h"  // R749: the OA Table 78 pins
#include "rules/oa/oa121table79.h"  // R750: the OA Table 79 pins
#include "rules/oa/oa122table80.h"  // R751: the OA Table 80 pins
#include "rules/oa/oa123table81.h"  // R752: the OA Table 81 pins
#include "rules/oa/oa124table82.h"  // R753: the OA Table 82 pins
#include "rules/oa/oa125table83.h"  // R754: the OA Table 83 pins
#include "rules/oa/oa126table84.h"  // R755: the OA Table 84 pins
#include "rules/oa/oa127table85.h"  // R756: the OA Table 85 pins
#include "rules/oa/oa128weaponexpl.h"  // R757: the OA weapon explanation pins
#include "rules/oa/oa129magitemsprose.h"  // R758: the OA magical items prose pins
#include "rules/oa/oa130table86.h"  // R759: the OA Table 86 pins
#include "rules/oa/oa131karaturintro.h"  // R760: the OA Kara-Tur overview pins
#include "rules/oa/oa132shoulung.h"  // R761: the OA Shou Lung pins
#include "rules/oa/oa133tulung.h"  // R762: the OA Tu Lung pins
#include "rules/oa/oa134wa.h"  // R763: the OA Wa pins
#include "rules/oa/oa135kozakura.h"  // R764: the OA Kozakura pins
#include "rules/oa/oa136gajin.h"  // R765: the OA Gajin pins
#include "rules/oa/oa137food.h"  // R766: the OA Daily Life Food pins
#include "rules/oa/oa138buildings.h"  // R767: the OA Daily Life Buildings pins
#include "rules/oa/oa139manners.h"  // R768: the OA Daily Life Manners pins
#include "rules/oa/oa140names.h"  // R769: the OA Daily Life Names pins
#include "rules/oa/oa141backmatter.h"  // R770: the OA Back matter pins
#include "rules/oa/oa142celestial.h"  // R771: the OA Celestial Emperor pins
#include "rules/oa/oa143weaponsprose.h"  // R772: the OA Weapons prose pins
#include "rules/oa/oa144dailylife.h"  // R773: the OA daily-life misses pins
#include "rules/meta/file_patch_seam.h"  // R774: the file-patch seam tooling pins
#include "rules/meta/rt_seam.h"  // R775: the RT seam fix pins
#include "rules/seams/mountcombat.h"  // R776: the mount site pins
#include "rules/seams/saddle.h"  // R777: the saddle acquisition pins
#include "rules/seams/mountmove.h"  // R778: the mounted movement pins
#include "rules/seams/lancecharge.h"  // R779: the lance charge pins
#include "rules/seams/lancespeed.h"  // R780: the lance speed pins
#include "rules/dmg/spearset.h"  // R781: the set spear pins
#include "rules/seams/owedpins.h"  // R782: the owed pins
#include "rules/seams/deitylines.h"  // R783: the deity stat lines
#include "rules/seams/worshipsites.h"  // R784: the worship sites
#include "rules/ua/spelltableledger.h"  // R785: the UA spell table ledger
#include "rules/ua/uadeityprose1.h"  // R786: the dwarven deity prose
#include "rules/ua/uadeityprose2.h"  // R787: the elven deity prose
#include "rules/ua/uadeityprose3.h"  // R788: the halfling deity prose
#include "rules/ua/uadeityprose4.h"  // R789: the gnomish deity prose
#include "rules/ua/uadeityprose5.h"  // R790: the orcish deity prose
#include "rules/meta/registry_promotion_wiring.h"  // R791: the registry promotion wiring
#include "rules/meta/registry_promotion_defs.h"  // R792: the registry promotion defs
#include "rules/meta/registry_def_name_fix.h"  // R793: the registry promotion def name fix
#include "rules/meta/tooling_datafiles_adaptation.h"  // R794: the tooling data_files adaptation
#include "rules/meta/rn_selfpatch_guard.h"  // R795: the rn self-patch guard
#include "rules/mm/mm2_arc_opener.h"  // R796: the MM2 arc opener
#include "rules/mm/mm2a.h"  // R797: the MM2 letter A
#include "rules/mm/mm2bc.h"  // R798: the MM2 letters B and C
#include "rules/mm/mm2dp.h"  // R799: the MM2 letter D part 1 - the planar evil families
#include "rules/mm/mm2dv.h"  // R800: the MM2 letter D part 2 - the deva turn
#include "rules/mm/mm2df.h"  // R801: the MM2 letter D part 3 - the devil section
#include "rules/mm/mm2dn.h"  // R802: the MM2 letter D part 4 - the diakk and dinosaur walk
#include "rules/mm/mm2dg.h"  // R803: the MM2 letter D part 5 - the dracolisk, dragon and dustdigger turns
#include "rules/mm/mm2de.h"  // R804: the MM2 letter E walk - the eagle, elf and executioner hood turns
#include "rules/mm/mm2fg.h"  // R805: the MM2 letters FG walk - the falcon, foo creature, giant and grue turns
#include "rules/mm/mm2hi.h"  // R806: the MM2 letters HI walk - the hangman tree, haunt, hollyphant, hordling and hybsil turns
#include "rules/mm/mm2jk.h"  // R807: the MM2 letters JK walk - the jann, mustard jelly, kampfult, kech, korred and kraken turns
#include "rules/mm/mm2lmn.h"  // R808: the MM2 letters LMN walk - the land lamprey, luck eater, lycanthrope, magman, mandragora, giant mantis, mantrap, margoyle, marid, shadow mastiff, mihstu, miner, minimal, modron, russet mold, mongrelman, moon dog, muckdweller, mud-man, myconid, nereid and narwhale turns
#include "rules/mm/mm2o.h"  // R809: the MM2 letter O walk - the obliviax, ogre aquatic (merrow), oliphant, ophidian, opinicus, otter and owl turns
#include "rules/mm/mm2p.h"  // R810: the MM2 letter P walk - the para-elemental (ice, smoke, magma and ooze), pech, pedipalp (large, huge and giant), phantom, phoenix, phycomid, planetar, pseudo-undead, deadly pudding (brown, dun and white) and pyrolisk turns
#include "rules/mm/mm2q.h"  // R811: the MM2 letter Q walk - the quasi-elemental lightning, quickling and quickwood turns
#include "rules/mm/mm2r.h"  // R812: the MM2 letter R walk - the rat (ordinary and vapor), raven (ordinary, huge and giant), retch plant and rock reptile turns
#include "rules/mm/mm2s.h"  // R813: the MM2 letter S walk - the sandling to taer turns
#include "rules/mm/mm2tuv.h"  // R814: the MM2 letters TUV walk - the tarrasque to vulture turns
#include "rules/mm/mm2wxyz.h"  // R815: the MM2 letters WXYZ walk - the weasel to zygom turns
#include "rules/mm/mm2encd.h"  // R816: the MM2 dungeon encounter tables walk - the ten monster level grids
#include "rules/mm/mm2enco.h"  // R817: the MM2 outdoor encounter tables walk - the 36 terrain grids
#include "rules/mm/mm2enca.h"  // R818: the MM2 aquatic encounter tables walk - the 12 surface and depths grids
#include "rules/mm/mm2enci.h"  // R819: the MM2 index walk - the merged MM1/FF/MM2 index census
#include "rules/mm/mm2_lammasu_promotion.h"  // R820: the lammasu promotion
#include "rules/ff/lung_dragons_promotion.h"  // R821: the lung promotion
#include "rules/engine/audit_wiring.h"  // R822: the audit files decomposition wiring
#include "rules/meta/migration_wiring.h"  // R823: the audit blocks migration wiring
#include "rules/meta/migration_batch_pilot.h"  // R824: the pilot migration round
#include "rules/meta/migration_batch_dmg_appendix.h"  // R825: the DMG appendix migration batch
#include "rules/meta/migration_batch_dmg_tables.h"  // R826: the DMG tables migration batch
#include "rules/meta/migration_batch_subclass.h"  // R827: the subclass migration batch
#include "rules/meta/migration_batch_hundred.h"  // R828: the hundred-block migration batch
#include "rules/meta/migration_batch_ua_wsg.h"  // R829: the UA and WSG migration batch
#include "rules/meta/migration_batch_wsg_tail_dsg.h"  // R830: the WSG tail and DSG migration batch
#include "rules/meta/migration_batch_planes_oa.h"  // R831: the planes and OA migration batch
#include "rules/meta/migration_batch_oa_tail.h"  // R832: the OA tail migration batch
#include "rules/meta/migration_batch_final_digest.h"  // R833: the final digest migration batch
#include "rules/meta/tooling_holdback_patch.h"  // R834: the holdback tooling patch
#include "rules/meta/migration_batch_final_holdback.h"  // R835: the final holdback batch
#include "rules/ff/promo_batch1.h"  // R836: the first FF promotion batch
#include "rules/ff/promo_batch2.h"  // R837: the second FF promotion batch
#include "rules/ff/promo_batch3.h"  // R838: the third FF promotion batch
#include "rules/ff/promo_batch4.h"  // R839: the fourth FF promotion batch
#include "rules/ff/hornet_promotion.h"  // R840: the hornet promotion
#include "rules/ff/index_walk.h"  // R841: the FF index line walk
#include "rules/ff/promo_batch5.h"  // R842: the fifth FF promotion batch
#include "rules/ff/promo_batch6.h"  // R843: the sixth FF promotion batch
#include "rules/ff/promo_batch7.h"  // R844: the seventh FF promotion batch
#include "rules/ff/promo_batch8.h"  // R845: the eighth FF promotion batch
#include "rules/ff/monster_level_tables.h"  // R846: the FF monster level tables
#include "rules/ff/encounter_listings.h"  // R847: the FF encounter listings
#include "rules/ff/magic_item_tables.h"  // R848: the FF magic item tables
#include "rules/ddg/ddg_frontmatter.h"  // R849: the DDG front matter
#include "rules/ddg/mythos_american_indian.h"  // R850: the American Indian mythos
#include "rules/ddg/mythos_arthurian.h"  // R851: the Arthurian mythos
#include "rules/ddg/mythos_babylonian.h"  // R852: the Babylonian mythos
#include "rules/ddg/mythos_celtic.h"  // R853: the Celtic mythos
#include "rules/ddg/mythos_central_american.h"  // R854: the Central American mythos
#include "rules/ddg/mythos_chinese.h"  // R855: the Chinese mythos
#include "rules/ddg/mythos_cthulhu.h"  // R856: the Cthulhu mythos
#include "rules/ddg/mythos_egyptian.h"  // R857: the Egyptian mythos
#include "rules/ddg/mythos_finnish.h"  // R858: the Finnish mythos
#include "rules/ddg/mythos_greek.h"  // R859: the Greek mythos
#include "rules/ddg/mythos_indian.h"  // R860: the Indian mythos
#include "rules/ddg/mythos_japanese.h"  // R861: the Japanese mythos
#include "rules/ddg/mythos_melnibonean.h"  // R862: the Melnibonean mythos
#include "rules/ddg/mythos_nehwon.h"  // R863: the Nehwon mythos
#include "rules/ddg/nonhumans_deities.h"  // R864: the Nonhumans' Deities
#include "rules/ddg/mythos_norse.h"  // R865: the Norse mythos
#include "rules/ddg/mythos_sumerian.h"  // R866: the Sumerian mythos
#include "rules/ddg/appendix1_known_planes.h"  // R867: the known planes of existence
#include "rules/ddg/appendix2_temple_trappings.h"  // R868: temple trappings
#include "rules/ddg/cqc_batch1.h"  // R869: the clerical chart, batch one
#include "rules/ddg/cqc_batch2.h"  // R870: the clerical chart, batch two
#include "rules/ddg/cqc_batch3.h"  // R871: the clerical chart, batch three
#include "rules/ddg/cqc_batch4.h"  // R872: the clerical chart, batch four
#include "rules/ddg/cqc_batch5.h"  // R873: the clerical chart, batch five
#include "rules/ddg/cqc_batch6.h"  // R874: the clerical chart, batch six
#include "rules/ddg/cqc_batch7.h"  // R875: the clerical chart, batch seven
#include "rules/ddg/cqc_batch8.h"  // R876: the clerical chart, batch eight
#include "rules/ddg/appendix4_index.h"  // R877: Appendix 4 and the index
#include "rules/ddg/alignment_figures.h"  // R878: the alignment figures
#include "rules/meta/registry_schema.h"  // R879: the registry schema
#include "rules/ddg/lua_promo_batch1.h"  // R880: the DDG lua promotion, batch one
#include "rules/ddg/lua_promo_batch2.h"  // R881: the DDG lua promotion, batch two
#include "rules/ddg/lua_promo_batch3.h"  // R882: the DDG lua promotion, batch three
#include "rules/ddg/lua_promo_batch4.h"  // R883: the DDG lua promotion, batch four
#include "rules/ddg/lua_promo_batch5.h"  // R884: the DDG lua promotion, batch five
#include "rules/ddg/lua_promo_batch6.h"  // R885: the DDG lua promotion, batch six
#include "rules/ddg/lua_promo_batch7.h"  // R886: the DDG lua promotion, batch seven
#include "rules/dragon/issue001_ives_tables.h"  // R887: the Ives attribute tables, the Dragon opener
#include "rules/dragon/issue001_small_variants.h"  // R888: the Dragon small-variant set
#include "rules/dragon/aronson_illusionist_deltas.h"  // R889: the Aronson illusionist deltas
#include "rules/dragon/issue002_remorhaz_lore.h"  // R890: the Remorhaz lore, the issue-2 opener
#include "rules/dragon/class_alchemist.h"  // R891: the Alchemist class
#include "rules/dragon/fischer_hints_magic_items.h"  // R892: the Fischer Hints magic items
#include "rules/dragon/systems_round.h"  // R893: the systems round
#include "rules/dragon/artificer_devices.h"  // R894: the Ward Artificer devices items sweep
#include "rules/dragon/issue003_women_magic_notes.h"  // R895: the Lakofka women round
#include "rules/dragon/specialists_healers_scribes.h"  // R896: the Healer and Scribe specialists round
#include "rules/dragon/fighting_subclasses.h"  // R897: the Samurai and Berserker fighting sub-classes round
#include "rules/dragon/dwarves_birth_eldar.h"  // R898: the Dwarves, birth tables and Eldar deltas character round
#include "rules/dragon/idiot_jester_dex_mods.h"  // R899: the Idiot, Jester and dexterity mods comedy round
#include "rules/dragon/issue004_creature_features.h"  // R900: the Dragon issue-4 opener, the Creature Features monsters
#include "rules/dragon/issue004_close.h"  // R901: the Creature Features box closing round
#include "rules/dragon/issue005_opener.h"  // R902: the Dragon issue-5 opener, the Witchcraft Supplement, the Anhkheg and the Wizard Research Rules
#include "rules/dragon/issue005_close.h"  // R903: the Dragon issue-5 box closing round
#include "rules/dragon/witchcraft_wilderness_table.h"  // R904: the witchcraft wilderness encounter table round, the upload cross-check resolution
#include "rules/dragon/witch_remainders_elf_subraces.h"  // R905: the witch remainders and the Friedman elf sub-race table, the might-be-usable micro-round
#include "rules/dragon/issue006_opener.h"  // R906: the Dragon issue-6 opener, the Sea Trade system, the psionic option, the morale system and the Death Angel
#include "rules/dragon/issue006_close.h"  // R907: the Dragon issue-6 box closing round, the four-chain walk complete
#include "rules/dragon/issue007_prowler.h"  // R908: the Dragon issue-7 opener, the Prowler, the thin single-chain harvest
#include "rules/dragon/issue007_close.h"  // R909: the Dragon issue-7 box closing round, the thin walk complete
#include "rules/dragon/issue008_opener.h"  // R910: the Dragon issue-8 opener, the Gygax Planes article, the Watson towns article and the Kuntz gems re-evaluation
#include "rules/dragon/issue008_close.h"  // R911: the Dragon issue-8 box closing round, the three-chain walk complete
#include "rules/dragon/issue009_opener.h"  // R912: the Dragon issue-9 opener, the Gygax alignment article and the Ward Tombs & Crypts article
#include "rules/dragon/issue009_close.h"  // R913: the Dragon issue-9 box closing round, the two-chain walk complete
#include "rules/dragon/issue010_opener1.h"  // R914: the Dragon issue-10 opener part one, the Orgies Inc. article, the Clifton wilderness article and the Random Monsters article
#include "rules/dragon/issue010_opener2.h"  // R915: the Dragon issue-10 opener part two, the Gilbert dungeon method article, the Weights & Measures article and the Holsinger level ritual article
#include "rules/dragon/issue010_close.h"  // R916: the Dragon issue-10 box closing round, the six-chain walk complete
#include "rules/dragon/issue011_opener.h"  // R917: the Dragon issue-11 opener, the Kuntz brawling article and the Ward quarterstaff article
#include "rules/dragon/issue011_close.h"  // R918: the Dragon issue-11 box closing round, the two-chain walk complete
#include "rules/dragon/issue012_opener1.h"  // R919: the Dragon issue-12 opener part one, the Ovalle illusionist article and the Endersby and Carroll ship cargo article
#include "rules/dragon/issue012_opener2.h"  // R920: the Dragon issue-12 opener part two, the Persian Mythos and the Lovecraftian Mythos
#include "rules/dragon/issue012_close.h"  // R921: the Dragon issue-12 box closing round, the four-chain walk complete
#include "rules/dragon/issue013_opener1.h"  // R922: the Dragon issue-13 opener part one, the Shlump da Orc giant physics article and the Jon Pickens demon generation article
#include "rules/dragon/issue013_opener2.h"  // R923: the Dragon issue-13 opener part two, The Japanese Mythos by Jerome Arkenberg
#include "rules/dragon/issue013_close.h"  // R924: the Dragon issue-13 box closing round, the three-chain walk complete
#include "rules/dragon/issue014_opener.h"  // R925: the Dragon issue-14 opener, the Name That Monster Contest #1 winners and the Rihn lycanthropy variant
#include "rules/dragon/issue014_close.h"  // R926: the Dragon issue-14 box closing round, the two-chain walk complete
#include "rules/dragon/issue015_opener.h"  // R927: the Dragon issue-15 opener, Dragon Magic and the four rider chains
#include "rules/dragon/issue015_close.h"  // R928: the Dragon issue-15 box closing round, the five-chain walk complete
#include "rules/dragon/issue016_opener.h"  // R929: the Dragon issue-16 opener, the Near Eastern Mythos and the Ninja chains
#include "rules/dragon/issue016_close.h"  // R930: the Dragon issue-16 box closing round, the two-chain walk complete
#include "rules/dragon/issue017_opener1.h"  // R931: the Dragon issue-17 opener part one, the seven-chain round
#include "rules/dragon/issue017_opener2.h"  // R932: the Dragon issue-17 opener part two, the Ward wizard variants round
#include "rules/dragon/issue017_close.h"  // R933: the Dragon issue-17 box closing round, the eight-chain walk complete
#include "rules/dragon/issue018_opener1.h"  // R934: the Dragon issue-18 opener part one, the four-chain round
#include "rules/dragon/issue018_opener2.h"  // R935: the Dragon issue-18 opener part two, the three-chain round
#include "rules/dragon/issue018_close.h"  // R936: the Dragon issue-18 box closing round, the seven-chain walk complete
#include "rules/dragon/issue019_opener1.h"  // R937: the Dragon issue-19 opener part one, the three-chain round
#include "rules/dragon/issue019_opener2.h"  // R938: the Dragon issue-19 opener part two, the three-chain round
#include "rules/dragon/issue019_close.h"  // R939: the Dragon issue-19 box closing round, the six-chain walk complete
#include "rules/dragon/issue020_opener1.h"  // R940: the Dragon issue-20 opener part one, the three-chain round
#include "rules/dragon/issue020_opener2.h"  // R941: the Dragon issue-20 opener part two, the two-chain round
#include "rules/dragon/issue020_close.h"  // R942: the Dragon issue-20 box closing round, the five-chain walk complete
#include "rules/dragon/issue021_opener1.h"  // R943: the Dragon issue-21 opener part one, the three-chain round
#include "rules/dragon/issue021_opener2.h"  // R944: the Dragon issue-21 opener part two, the four-chain round
#include "rules/dragon/issue021_close.h"  // R945: the Dragon issue-21 box closing round, the seven-chain walk complete
#include "rules/dragon/issue022_opener1.h"  // R946: the Dragon issue-22 opener part one, the three-chain round
#include "rules/dragon/issue022_opener2.h"  // R947: the Dragon issue-22 opener part two, the DMG sneak preview table round
#include "rules/dragon/issue022_opener3.h"  // R948: the Dragon issue-22 opener part three, the five-chain commentary round
#include "rules/dragon/issue022_close.h"  // R949: the Dragon issue-22 box closing round, the four-round walk complete
#include "rules/dragon/issue023_opener1.h"  // R950: the Dragon issue-23 opener part one, the three-chain variant round
#include "rules/dragon/issue023_opener2.h"  // R951: the Dragon issue-23 opener part two, the Lower Planes creature-generation table round
#include "rules/dragon/issue023_opener3.h"  // R952: the Dragon issue-23 opener part three, the six-chain commentary round
#include "rules/dragon/issue023_close.h"  // R953: the Dragon issue-23 box closing round, the second four-round walk complete
#include "rules/dragon/issue024_opener1.h"  // R954: the Dragon issue-24 opener part one, the three-chain variant round
#include "rules/dragon/issue024_opener2.h"  // R955: the Dragon issue-24 opener part two, the alignment pantheon table round
#include "rules/dragon/issue024_opener3.h"  // R956: the Dragon issue-24 opener part three, the ten-chain commentary round
#include "rules/dragon/issue024_close.h"  // R957: the Dragon issue-24 box closing round, the third four-round walk complete
#include "rules/dragon/issue025_opener1.h"  // R958: the Dragon issue-25 opener part one, the three-chain opener set
#include "rules/dragon/issue025_opener2.h"  // R959: the Dragon issue-25 opener part two, the war game and the vampire roster table round
#include "rules/dragon/issue025_opener3.h"  // R960: the Dragon issue-25 opener part three, the three-chain commentary set
#include "rules/dragon/issue025_close.h"  // R961: the Dragon issue-25 box closing round, the fourth four-round walk complete
#include "rules/dragon/issue026_opener1.h"  // R962: the Dragon issue-26 opener part one, the five-chain opener set
#include "rules/dragon/issue026_opener2.h"  // R963: the Dragon issue-26 opener part two, the four-chain table round
#include "rules/dragon/issue026_opener3.h"  // R964: the Dragon issue-26 opener part three, the four-chain commentary set
#include "rules/dragon/issue026_close.h"  // R965: the Dragon issue-26 box closing round, the fifth four-round walk complete
#include "rules/meta/content_structure_charter.h"  // R966: the content-structure charter round
#include "rules/meta/content_tree_creation.h"  // R967: the content tree creation round
#include "rules/meta/rules_record_format.h"  // R968: the rules record format round
#include "rules/dragon/promo_batch01.h"  // R969: the Dragon promotion batch one
#include "rules/dragon/promo_batch02.h"  // R970: the Dragon promotion batch two
#include "rules/dragon/promo_batch03.h"  // R971: the Dragon promotion batch three
#include "rules/dragon/promo_batch04.h"  // R972: the Dragon promotion batch four
#include "rules/dragon/promo_batch05.h"  // R973: the Dragon promotion batch five
#include "rules/dragon/promo_batch06.h"  // R974: the Dragon promotion batch six
#include "rules/dragon/promo_batch07.h"  // R975: the Dragon promotion batch seven
#include "rules/dragon/promo_batch08.h"  // R976: the Dragon promotion batch eight
#include "rules/dragon/promo_batch09.h"  // R977: the Dragon promotion batch nine
#include "rules/dragon/promo_batch10.h"  // R978: the Dragon promotion batch ten
#include "rules/dragon/promo_batch11.h"  // R979: the Dragon promotion batch eleven
#include "rules/dragon/promo_batch12.h"  // R980: the Dragon promotion batch twelve
#include "rules/oa/oa1.h"  // R981: the OA promotion batch one
#include "rules/oa/oa2.h"  // R982: the OA promotion batch two
#include "rules/oa/oa3.h"  // R983: the OA promotion batch three
#include "rules/oa/oa4.h"  // R984: the OA promotion batch four
#include "rules/oa/oa5.h"  // R985: the OA promotion batch five
#include "rules/oa/oa6.h"  // R986: the OA promotion batch six
#include "rules/oa/oa7.h"  // R987: the OA promotion batch seven
#include "rules/oa/oa8.h"  // R988: the OA promotion batch eight
#include "rules/wsg/wsg1.h"  // R989: the WSG promotion batch one
#include "rules/wsg/wsg2.h"  // R990: the WSG promotion batch two
#include "rules/wsg/wsg3.h"  // R991: the WSG promotion batch three
#include "rules/wsg/wsg4.h"  // R992: the WSG promotion batch four
#include "rules/wsg/wsg5.h"  // R993: the WSG promotion batch five
#include "rules/dsg/dsg1.h"  // R994: the DSG promotion batch one
#include "rules/dsg/dsg2.h"  // R995: the DSG promotion batch two
#include "rules/dsg/dsg3.h"  // R996: the DSG promotion batch three
#include "rules/dsg/dsg4.h"  // R997: the DSG promotion batch four
#include "rules/dsg/dsg5.h"  // R998: the DSG promotion batch five
#include "rules/ua/ua1.h"  // R999: the UA promotion batch one
#include "rules/ua/ua2.h"  // R1000: the UA promotion batch two
#include "rules/ua/ua3.h"  // R1001: the UA promotion batch three
#include "rules/ua/ua4.h"  // R1002: the UA promotion batch four
#include "rules/ua/ua5.h"  // R1003: the UA promotion batch five
#include "rules/ua/ua6.h"  // R1004: the UA promotion batch six
#include "rules/ua/ua7.h"  // R1005: the UA promotion batch seven
#include "rules/meta/promotions_mop_batch1.h"  // R1006: the promotions mop round one - the FF never-load repair
#include "rules/meta/promotions_mop_batch2.h"  // R1007: the promotions mop round two - the MM1 text completion
#include "rules/meta/promotions_mop_batch3.h"  // R1008: the promotions mop round three - the MM1 collation half
#include "rules/mm/mm1_normalization_batch1.h"  // R1009: the MM1 normalization batch one
#include "rules/mm/mm1_normalization_batch2.h"  // R1010: the MM1 normalization batch two
#include "rules/mm/mm1_normalization_batch3.h"  // R1011: the MM1 normalization batch three
#include "rules/mm/mm1_normalization_batch4.h"  // R1012: the MM1 normalization batch four
#include "rules/mm/mm1_normalization_batch5.h"  // R1013: the MM1 normalization batch five
#include "rules/mm/mm1_normalization_batch6.h"  // R1014: the MM1 normalization batch six
#include "rules/oa/oa9.h"  // R1015: the OA table promotion batch nine
#include "rules/oa/oap1.h"  // R1016: the OA normalization batch
#include "rules/mm/mm2_normalization_batch1.h"  // R1017: the MM2 normalization batch one
#include "rules/mm/mm2_normalization_batch2.h"  // R1018: the MM2 normalization batch two
#include "rules/mm/mm2_normalization_batch3.h"  // R1019: the MM2 normalization batch three
#include "rules/mm/mm2_normalization_batch4.h"  // R1020: the MM2 normalization batch four
#include "rules/ff/normalization_batch1.h"  // R1021: the FF normalization batch one
#include "rules/ff/normalization_batch2.h"  // R1022: the FF normalization batch two
#include "rules/ff/normalization_batch3.h"  // R1023: the FF normalization batch three
#include "rules/meta/wt1.h"  // R1024: the WSG+MOP normalization tail batch
#include "rules/dragon/registry_normalization.h"  // R1025: the DRG normalization batch
#include "rules/ddg/legends_lore_parity.h"  // R1026: the deity seam close
#include "rules/ua/uascharts.h"  // R407: the UA Appendix S clerical charts
#include "rules/dmg/followers.h"  // R170: pp.16-18 followers by class
#include "rules/dmg/dmg_appendices_klm.h"  // R171: pp.221-224 appendices K L and M
#include "rules/dmg/herbs.h"  // R172: p.220 appendix J herbs spices and medicinal vegetables
#include "rules/dmg/secondary.h"  // R173: p.12 secondary skills
#include "rules/phb/subclasses.h"  // R179: the subclass registry
#include "rules/phb/subclassgates.h"  // R180: the qualification and race gates
#include "rules/phb/attacksround.h"  // R181: attacks per melee round
#include "rules/phb/druidspells.h"  // R182: the druid spell layer
#include "rules/phb/illusionspells.h"  // R183: the illusionist spell layer
#include "rules/phb/palrangerspells.h"  // R184: the paladin and ranger spell layers
#include "rules/phb/multiclass.h"  // R185: the multi-class and dual-class rules
#include "rules/phb/bard.h"  // R186: the bard (Appendix II)
#include "rules/phb/subclassspecials.h"  // R187: the per-subclass specials
#include "rules/phb/xpadjust.h"  // R188: the prime requisite XP adjustment
#include "rules/phb/weapontables.h"  // R189: the weapon weight and damage table
#include "rules/seams/mountlayer.h"  // R403: the mount layer seam
#include "rules/phb/startmoney.h"  // R190: the starting money by class
#include "rules/phb/armorratings.h"  // R191: the armor class ratings
#include "rules/phb/wisdom.h"  // R192: Wisdom Tables I and II
#include "rules/dmg/itemsavethrow.h"  // R204: p.80 item saving throw matrix
#include "rules/dmg/spying.h"  // R205: pp.19-20 the spying tables
#include "rules/dmg/pursuit.h"  // R206: pp.67-69 pursuit and evasion
#include "rules/dmg/taxation.h"  // R207: p.90 the town taxation system
#include "rules/dmg/socialrank.h"  // R208: pp.88-89 social class and rank
#include "rules/dmg/npcpersonae.h"  // R209: pp.114-115 NPC personae facts
#include "rules/dmg/npctraits.h"  // R210: pp.115-116 NPC personae traits
#include "rules/dmg/npcbody.h"  // R211: pp.115-116 height, weight, languages
#include "rules/dmg/hirecost.h"  // R212: pp.116-118 hire spell costs, troop control
#include "rules/dmg/construct.h"  // R213: pp.106-108 construction and siege economics
#include "rules/dmg/siegefire.h"  // R214: pp.108-110 war machine fire, siege attack, defensive values
#include "rules/dmg/conduct.h"  // R215: pp.110-112 conducting the game pins
#include "rules/dmg/magres.h"  // R216: pp.114-119 magical research pins
#include "rules/dmg/scrollfab.h"  // R217: pp.118-121 scroll manufacture and fabrication pins
#include "rules/dmg/energydrain.h"  // R218: pp.119-122 use of magic items and energy draining pins
#include "rules/dmg/treasdet.h"  // R219: pp.120-123 treasure random determination tables
#include "rules/dmg/hoard.h"  // R220: p.123 the combined hoard table
#include "rules/dmg/potions.h"  // R221: pp.125-126 the potions prose pins
#include "rules/dmg/scrollpins.h"  // R222: pp.126-127 the scrolls prose pins
#include "rules/dmg/rings.h"  // R223: p.127 the rings footnote pins
#include "rules/dmg/rodswands.h"  // R224: pp.127-128 the rods/staves/wands pins
#include "rules/dmg/miscmagic1.h"  // R225: p.128 the misc table 1 pins
#include "rules/dmg/miscmagic2.h"  // R226: p.128 the misc table 2 pins
#include "rules/dmg/miscmagic3.h"  // R237: p.129 the misc table 3 pins
#include "rules/dmg/miscmagic4.h"  // R238: p.129-130 the misc table 4 pins
#include "rules/dmg/miscmagic5.h"  // R239: p.130 the misc table 5 pins
#include "rules/dmg/specart.h"  // R240: p.130-131 the III.E Special artifacts pins
#include "rules/dmg/armorshield.h"  // R241: p.129-130 the III.F armor and shield pins
#include "rules/dmg/swords.h"  // R242: p.131 the III.G swords pins
#include "rules/dmg/mweapons.h"  // R243: p.131-132 the III.H misc weapons pins
#include "rules/dmg/rodsprose.h"  // R244: pp.141-142 the III.D rods prose pins
#include "rules/dmg/stavesprose.h"  // R245: pp.142-143 the III.D staves prose pins
#include "rules/dmg/wandsprose.h"  // R246: pp.143-144 the III.D wands prose pins
#include "rules/dmg/wandsprose2.h"  // R247: pp.144-145 the III.D wands prose part 2 pins
#include "rules/dmg/wonder.h"  // R248: p.145 the III.D wand of wonder effect table pins
#include "rules/dmg/potionsprose.h"  // R249: pp.133-134 the III.A potions prose part 1 pins
#include "rules/dmg/potionsprose2.h"  // R250: pp.134-136 the III.A potions prose part 2 pins
#include "rules/dmg/potionsprose3.h"  // R251: pp.136-137 the III.A potions prose part 3 pins
#include "rules/dmg/scrollsprose.h"  // R252: pp.137-139 the III.B scrolls explanation prose pins
#include "rules/dmg/ringsprose.h"  // R253: pp.137-138 the III.C rings explanation prose part 1 pins
#include "rules/dmg/ringsprose2.h"  // R254: pp.138-139 the III.C rings explanation prose part 2 pins
#include "rules/dmg/ringsprose3.h"  // R256: pp.139-140 the III.C rings explanation prose part 3 pins
#include "rules/dmg/miscprose1.h"  // R257: the III.E misc magic explanation prose part 1 pins
#include "rules/dmg/miscprose2.h"  // R258: the III.E misc magic explanation prose part 2 pins
#include "rules/dmg/miscprose3.h"  // R259: the III.E misc magic explanation prose part 3 pins
#include "rules/dmg/miscprose4.h"  // R260: the III.E misc magic explanation prose part 4 pins
#include "rules/dmg/miscprose5.h"  // R261: the III.E misc magic explanation prose part 5 pins
#include "rules/dmg/miscprose6.h"  // R262: the III.E misc magic explanation prose part 6 pins
#include "rules/dmg/miscprose7.h"  // R263: the III.E misc magic explanation prose part 7 pins
#include "rules/dmg/miscprose8.h"  // R264: the III.E misc magic explanation prose part 8 pins
#include "rules/dmg/miscprose9.h"  // R265: the III.E misc magic explanation prose part 9 pins
#include "rules/dmg/miscprose10.h"  // R266: the III.E misc magic explanation prose part 10 pins
#include "rules/dmg/miscprose11.h"  // R267: the III.E misc magic explanation prose part 11 pins
#include "rules/dmg/miscprose12.h"  // R268: the III.E misc magic explanation prose part 12 pins
#include "rules/dmg/miscprose13.h"  // R269: the III.E misc magic explanation prose part 13 pins
#include "rules/dmg/miscprose14.h"  // R270: the III.E misc magic explanation prose part 14 pins
#include "rules/dmg/miscprose15.h"  // R271: the III.E misc magic explanation prose part 15 pins
#include "rules/dmg/miscprose16.h"  // R272: the III.E misc magic explanation prose part 16 pins
#include "rules/dmg/miscprose17.h"  // R273: the III.E misc magic explanation prose part 17 pins
#include "rules/dmg/miscprose18.h"  // R274: the III.E misc magic explanation prose part 18 pins
#include "rules/dmg/miscprose19.h"  // R275: the III.E misc magic explanation prose part 19 pins
#include "rules/dmg/miscprose20.h"  // R276: the III.E misc magic explanation prose part 20 pins
#include "rules/dmg/miscprose21.h"  // R277: the III.E misc magic explanation prose part 21 pins
#include "rules/dmg/miscprose22.h"  // R278: the III.E misc magic explanation prose part 22 pins
#include "rules/dmg/miscprose23.h"  // R279: the III.E misc magic explanation prose part 23 pins
#include "rules/dmg/specartprose.h"  // R280: the III.E Special artifacts explanation prose part 1 pins
#include "rules/dmg/specartprose2.h"  // R281: the III.E Special artifacts explanation prose part 2 pins
#include "rules/phb/weaponprof.h"  // R297: the PHB Weapon Proficiency Table
#include "rules/phb/thieffunc.h"  // R298: the thief function take table and DEX Table II
#include "rules/dmg/locktime.h"  // R304: the DMG lock time pins
#include "rules/dmg/doorforce.h"  // R305: the DMG door force pins
#include "rules/phb/equipcosts.h"  // R300: the equipment cost columns
#include "rules/dmg/hirelings.h"  // R309: the hirelings cost tables
#include "rules/dmg/sage.h"  // R310: the sage subsection
#include "rules/seams/underwater.h"  // R311: the underwater environment
#include "rules/dmg/swimcross.h"  // R312: the flooded crossing
#include "rules/dmg/uwfight.h"  // R313: the underwater fight
#include <cstdio>
#include <cstring>  // R327: the acrobat name reads
#include <string>

// R126: does the band list carry this exact (key, lo, hi)
// pin? - the wilderness line-diff audit's spot-check helper
static bool bandHas(const std::vector<dm::OutdoorBand>& b,
                    const char* k, int lo, int hi) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi) return true;
    return false;
}

// R127: the waterborne spot-check helper - exact key, band,
// and footnote-gate flags (1 = cool only, 2 = warm only,
// 4 = deep only)
static bool waterBandHas(const std::vector<dm::WaterborneBand>& b,
                         const char* k, int lo, int hi, int fl) {
    for (const auto& x : b)
        if (x.key == k && x.lo == lo && x.hi == hi
            && x.flags == fl) return true;
    return false;
}

int main() {
    monsters::MonsterRegistry reg;

    // R71fix: the 408 monster lua files live in letter subdirectories
    // (content/monsters/a/aarakocra.lua, ...), but loadDirectory() reads
    // only one flat directory level. Load every letter dir and total the
    // counts; a missing/empty dir contributes 0 (loadDirectory returns
    // -1 only if the directory itself cannot be opened, so ignore -1).
    int n = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::string dir = "content/monsters/";
        dir.push_back(c);
        int m = reg.loadDirectory(dir);
        if (m > 0) n += m;
    }
    printf("loaded %d, errors %zu\n", n, reg.errors().size());
    for (auto& e : reg.errors()) printf("ERR: %s\n", e.c_str());
    for (const char* k : {"wight", "purple_worm", "ankheg", "goblin"}) {
        auto* d = reg.find(k);
        if (d) printf("%-12s AC%3d HD %.1f atk %d dmg 1d%d xp %d und %d\n",
            k, d->armorClass, d->hitDice, d->attacks, d->damageSides,
            d->xpValue, (int)d->undead);
    }

    // ---- R73: XP sanity audit over the full bestiary ------------------
    // merged_mm1 entries carry cross-checked book XP (R49); anything
    // with a non-positive xp there, or a negative xpPerHp, or an
    // unrecognized xpSource, is an anomaly worth eyeballing.
    {
        int anom = 0, checked = 0;
        for (const auto& kv : reg.all()) {
            const auto& d = kv.second;
            ++checked;
            bool bad = false;
            if (d.xpSource == "merged_mm1" && d.xpValue <= 0) bad = true;
            if (d.xpPerHp < 0) bad = true;
            if (d.xpSource != "merged_mm1" && d.xpSource != "perm_x10" &&
                d.xpSource != "role_variant" && d.xpSource != "by_hit_dice" &&
                d.xpSource != "age_bracket" && d.xpSource != "by_head_count" &&
                d.xpSource != "by_level" && d.xpSource != "oa_print" &&
                d.xpSource != "wsg_print" && d.xpSource != "mop_print" &&
                d.xpSource != "mm2_print" &&
                d.xpSource != "ff_print" &&
                d.xpSource != "dragon_print") bad = true;
            if (bad && anom < 10) {
                printf("ANOM: %-24s xpSource=%s xpValue=%d xpPerHp=%d\n",
                       kv.first.c_str(), d.xpSource.c_str(),
                       d.xpValue, d.xpPerHp);
            }
            if (bad) ++anom;
        }
        printf("xp audit: %d defs checked, %d anomalies\n", checked, anom);
    }

    // ---- R74: encounter generator smoke test --------------------------
    // Deterministic + statistical checks over rollEncounter():
    //   - every pick resolves to a loaded def
    //   - count within [min,max] unless clamped to the cap
    //   - lairPct==0 monsters never generate a lair
    //   - unique monsters excluded unless allowed
    {
        rules::Rng rng(12345);
        rules::Dice dice(rng);
        dm::encounters::EncounterOptions opt;
        int n = 2000, bad = 0, lairs = 0, clamped = 0;
        for (int i = 0; i < n; ++i) {
            dm::encounters::Encounter e;
            if (!dm::encounters::rollEncounter(reg, dice, opt, e)) {
                ++bad; continue;
            }
            if (!e.def) { ++bad; continue; }
            int lo = e.def->noAppearingMin, hi = e.def->noAppearingMax;
            if (hi < lo) hi = lo;
            if (lo == 0 && hi == 0) {   // R75b: no data - count forced 1
                if (e.count != 1) ++bad;
            } else if (!e.clamped && (e.count < lo || e.count > hi)) ++bad;
            if (e.count < 1 || e.count > opt.countCap) ++bad;
            if (e.clamped && e.rawCount <= opt.countCap) ++bad;
            if (e.inLair && e.def->lairPct <= 0) ++bad;
            if (e.def->frequency == "unique" || e.def->xpSource == "perm_x10")
                ++bad;
            if (e.inLair) ++lairs;
            if (e.clamped) ++clamped;
        }
        // statistical: with 2000 rolls and the full bestiary, some
        // lairs and clamped counts (goblin "40-400") must have appeared
        if (lairs == 0 || clamped == 0) ++bad;
        printf("encounter smoke: %d rolls, %d bad, %d lairs, %d clamped\n",
               n, bad, lairs, clamped);
        // alignment-filter sanity: every pick matches the filter
        dm::encounters::EncounterOptions eo;
        eo.alignmentFilter = "chaotic";
        int fbad = 0;   // R75b: own counter - the smoke's `bad` leaked here
        for (int i = 0; i < 500; ++i) {
            dm::encounters::Encounter e;
            if (!dm::encounters::rollEncounter(reg, dice, eo, e) ||
                e.def->alignment.compare(0, 7, "chaotic") != 0) { ++fbad; break; }
        }
        printf("encounter filter: %s\n", fbad ? "FAIL" : "OK");
    }

    // ---- R75: specials audit + toActor copy check ----------------------
    // The bug: toActor() never copied def.specials onto the Actor, so
    // R18's resolveSpecial was dead code for every registry monster.
    {
        int withSp = 0, drain = 0, pois = 0, para = 0, breath = 0;
        for (const auto& kv : reg.all()) {
            if (kv.second.specials.empty()) continue;
            ++withSp;
            for (const auto& sp : kv.second.specials) {
                if (sp.type == monsters::SPECIAL_ENERGY_DRAIN) ++drain;
                if (sp.type == monsters::SPECIAL_POISON)       ++pois;
                if (sp.type == monsters::SPECIAL_PARALYSIS)    ++para;
                if (sp.type == monsters::SPECIAL_BREATH_WEAPON) ++breath;
            }
        }
        printf("specials census: %d monsters, drain %d poison %d "
               "paralysis %d breath %d\n",
               withSp, drain, pois, para, breath);
        // census must be non-degenerate: a 408-monster bestiary with
        // the keyword derivation MUST have found some of each class
        if (drain < 1 || pois < 5 || para < 1 || breath < 5) {
            printf("FAIL: specials census degenerate\n");
            return 1;
        }

        // toActor must copy specials (the R75 fix) - test the first
        // monster of each special type rather than hardcoded keys
        rules::Rng rng2(999);
        rules::Dice dice2(rng2);
        int bad = 0;
        const char* probe[4] = { nullptr, nullptr, nullptr, nullptr };
        for (const auto& kv : reg.all()) {
            for (const auto& sp : kv.second.specials) {
                int t = (int)sp.type;
                if (t >= 1 && t <= 4 && !probe[t - 1])
                    probe[t - 1] = kv.second.key.c_str();
            }
        }
        for (int t = 1; t <= 4; ++t) {
            if (!probe[t - 1]) {
                printf("FAIL: no monster with special type %d\n", t);
                return 1;
            }
            auto* d = reg.find(probe[t - 1]);
            ai::Actor a = reg.toActor(probe[t - 1], dice2);
            if (a.specials.size() != d->specials.size()) { ++bad; continue; }
            for (size_t i = 0; i < a.specials.size(); ++i)
                if (a.specials[i].type != (int)d->specials[i].type ||
                    a.specials[i].drainLevels != d->specials[i].drainLevels)
                    ++bad;
        }
        printf("toActor specials: %s\n", bad ? "FAIL" : "OK");
        if (bad) return 1;
    }

    // ---- R76: magic item category audit --------------------------------
    // Every rolled item carries its DMG III category; healing potions
    // are detectable by name+category; weapon plus parses from names.
    {
        rules::Rng rng3(777);
        rules::Dice dice3(rng3);
        int n = 20000, bad = 0, potions = 0, scrolls = 0, swords = 0,
            armor = 0, healing = 0;
        bool seenCat[12] = { false };
        for (int i = 0; i < n; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(dice3);
            if (m.category < 0 || m.category > 11) { ++bad; continue; }
            seenCat[m.category] = true;
            if (m.category == dm::treasure::MIC_POTION) {
                ++potions;
                // category contract: III.A rows are "Potion of ..." plus
                // the printed Oil (64-69) and Philter (70-75) bands
                if (m.name.compare(0, 9, "Potion of") != 0 &&
                    m.name.compare(0, 7, "Oil of ") != 0 &&
                    m.name.compare(0, 11, "Philter of ") != 0) ++bad;
                if (m.isHealingPotion()) {
                    ++healing;
                    if (m.name != "Potion of Healing" &&
                        m.name != "Potion of Extra-Healing") ++bad;
                }
            }
            if (m.category == dm::treasure::MIC_SCROLL) ++scrolls;
            if (m.category == dm::treasure::MIC_SWORD) {
                ++swords;
                if (m.name.compare(0, 5, "Sword") != 0) ++bad;
                // plus rows must parse to 1-5
                int plus = m.weaponPlus();
                if (plus > 5) ++bad;
            }
            if (m.category == dm::treasure::MIC_ARMOR) ++armor;
        }
        // statistical: 20000 rolls must hit every category, and the
        // potion band (20%) must include healing draughts
        for (int c = 0; c < 12; ++c)
            if (!seenCat[c]) ++bad;
        if (potions < 500 || scrolls < 300 || swords < 300 ||
            armor < 500 || healing < 30) ++bad;
        printf("magic item audit: %d rolls, bad %d, potions %d "
               "(healing %d), scrolls %d, swords %d, armor %d\n",
               n, bad, potions, healing, scrolls, swords, armor);

        // deterministic helper unit checks (own counter - the audit's
        // `bad` must not leak here, the R75b lesson twice over)
        int hbad = 0;
        dm::treasure::MagicItem u;
        u.category = dm::treasure::MIC_POTION;
        u.name = "Potion of Healing";        if (!u.isHealingPotion()) ++hbad;
        u.name = "Potion of Flying";        if (u.isHealingPotion()) ++hbad;
        u.name = "Potion of Extra-Healing"; if (!u.isHealingPotion()) ++hbad;
        u.category = dm::treasure::MIC_SWORD;   // category gates potions
        if (u.isHealingPotion()) ++hbad;
        u.name = "Sword +3, Frost Brand";
        if (u.weaponPlus() != 3) ++hbad;
        u.name = "Sword, Vorpal Weapon";
        if (u.weaponPlus() != 0) ++hbad;
        u.name = "Arrow +2";
        if (u.weaponPlus() != 2) ++hbad;
        u.name = "Cloak of Protection +4";
        if (u.weaponPlus() != 4) ++hbad;      // parse works anywhere
        printf("magic helpers: %s\n", hbad ? "FAIL" : "OK");
        if (bad || hbad) return 1;
    }

    // ---- R77: kind & curse classification audit -------------------------
    // kind() must agree with category+name; cursed rows must carry
    // the flag (claim layers skip them).
    {
        int kbad = 0;
        // deterministic units
        dm::treasure::MagicItem u;
        u.category = dm::treasure::MIC_SWORD;
        u.name = "Sword +3, Frost Brand";
        if (u.kind() != dm::treasure::MIK_SWORD) ++kbad;
        if (u.cursed()) ++kbad;
        u.category = dm::treasure::MIC_SCROLL;
        if (u.kind() != dm::treasure::MIK_SCROLL) ++kbad;
        u.category = dm::treasure::MIC_ARMOR;
        u.name = "Shield +2";
        if (u.kind() != dm::treasure::MIK_SHIELD) ++kbad;
        u.name = "Chain Mail +1";
        if (u.kind() != dm::treasure::MIK_ARMOR) ++kbad;
        u.category = dm::treasure::MIC_WEAPON;
        u.name = "Arrow +2";
        if (u.kind() != dm::treasure::MIK_AMMO) ++kbad;
        u.name = "Bow +1";
        if (u.kind() != dm::treasure::MIK_MISSILE) ++kbad;
        u.name = "Mace +2";
        if (u.kind() != dm::treasure::MIK_MELEE) ++kbad;
        u.name = "Sword +1, Cursed";
        if (!u.cursed()) ++kbad;               // curse detector
        u.category = dm::treasure::MIC_ARMOR;
        u.name = "Plate Mail of Vulnerability";
        if (!u.cursed()) ++kbad;
        u.name = "Shield -1, missile attractor";
        if (!u.cursed()) ++kbad;
        u.category = dm::treasure::MIC_WEAPON;
        u.name = "Spear, Cursed Backbiter";
        if (!u.cursed()) ++kbad;

        // statistical: rolled items agree with category constraints
        rules::Rng rng4(4242);
        rules::Dice dice4(rng4);
        int n = 20000, swords = 0, shields = 0, armor = 0,
            melee = 0, missile = 0, ammo = 0, cursed = 0;
        for (int i = 0; i < n; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(dice4);
            switch (m.kind()) {
            case dm::treasure::MIK_SWORD:
                ++swords;
                if (m.category != dm::treasure::MIC_SWORD) ++kbad;
                break;
            case dm::treasure::MIK_SHIELD:
                ++shields;
                if (m.category != dm::treasure::MIC_ARMOR ||
                    m.name.find("Shield") == std::string::npos)
                    ++kbad;
                break;
            case dm::treasure::MIK_ARMOR:
                ++armor;
                if (m.category != dm::treasure::MIC_ARMOR) ++kbad;
                break;
            case dm::treasure::MIK_MELEE:
                ++melee;
                if (m.category != dm::treasure::MIC_WEAPON) ++kbad;
                break;
            case dm::treasure::MIK_MISSILE:
                ++missile;
                if (m.category != dm::treasure::MIC_WEAPON) ++kbad;
                break;
            case dm::treasure::MIK_AMMO:
                ++ammo;
                if (m.category != dm::treasure::MIC_WEAPON) ++kbad;
                break;
            default:
                break;
            }
            if (m.cursed()) {
                ++cursed;
                // curse words must actually appear (no false positives)
                if (m.name.find("Cursed") == std::string::npos &&
                    m.name.find("Vulnerability") == std::string::npos &&
                    m.name.find("attractor") == std::string::npos &&
                    m.name.find("Backbiter") == std::string::npos)
                    ++kbad;
            }
        }
        // every claimable band must occur across 20000 rolls
        if (swords < 200 || shields < 100 || armor < 200 ||
            melee < 100 || missile < 20 || ammo < 40 || cursed < 10)
            ++kbad;
        printf("kind audit: %d rolls, bad %d, swords %d, shields %d, "
               "armor %d, melee %d, missile %d, ammo %d, cursed %d\n",
               n, kbad, swords, shields, armor, melee, missile,
               ammo, cursed);
        if (kbad) return 1;
    }

    #include "rules/audits/r079_ammo_claims.h"  // R824: migrated
    #include "rules/audits/r080_quiver_math.h"  // R824: migrated
    // ---- R80: spell table L4-6 -----------------------------------------
    {
        int bad = 0, mu = 0, cl = 0, dr = 0, il = 0, l46 = 0;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            // R129: the band widens to 1-9 - the p.14
            // caster-aging spells ride as levels 7-9
            if (s.level < 1 || s.level > 9) ++bad;
            // R228: the druid registry rows ride
            // SPELL_DRUID (77 spells, levels 1-7);
            // R229: the illusionist rows ride
            // SPELL_ILLUSIONIST (61 spells)
            if (s.sclass != spells::SPELL_MU &&
                s.sclass != spells::SPELL_CLERIC &&
                s.sclass != spells::SPELL_DRUID &&
                s.sclass != spells::SPELL_ILLUSIONIST) ++bad;
            if (s.sclass == spells::SPELL_MU) ++mu;
            else if (s.sclass == spells::SPELL_DRUID) ++dr;
            else if (s.sclass == spells::SPELL_ILLUSIONIST) ++il;
            else ++cl;
            if (s.level >= 4 && s.level <= 6) {
                ++l46;
                // a slot row exists that can cast it
                if (spells::spellSlots(s.sclass, 12, s.level) < 1)
                    ++bad;
            }
        }
        if (l46 < 12) ++bad;   // the R80 roster landed
        // R228: the druid rows match the R182 roster
        // cell by cell (level, reversible, class)
        for (int i = 0; i < rules::druidSpellTotal(); ++i) {
            const spells::SpellDef& s = spells::spell(
                (spells::SpellId)(
                    spells::DR_ANIMAL_FRIENDSHIP + i));
            if (s.level != rules::druidSpell(i).level ||
                (s.reversible ? 1 : 0) !=
                    rules::druidSpell(i).reversible ||
                s.sclass != spells::SPELL_DRUID) ++bad;
        }
        // R229: the illusionist rows match the R183
        // roster cell by cell (level, class; the
        // illusionist print carries no reversible
        // markers)
        for (int i = 0; i < rules::illusionistSpellTotal(); ++i) {
            const spells::SpellDef& s = spells::spell(
                (spells::SpellId)(
                    spells::IL_AUDIBLE_GLAMER + i));
            if (s.level != rules::illusionistSpell(i).level ||
                s.sclass != spells::SPELL_ILLUSIONIST) ++bad;
        }
        printf("R80 spells audit: %d spells (MU %d, CL %d, DR %d, IL %d), "
               "L4-6 %d, bad %d\n",
               spells::SPELL_COUNT, mu, cl, dr, il, l46, bad);
        if (bad) return 1;
    }

    #include "rules/audits/r081_ring_claims.h"  // R824: migrated
    #include "rules/audits/r082_death_revival.h"  // R824: migrated
    #include "rules/audits/r083_teleport_gates.h"  // R824: migrated
    #include "rules/audits/r085_pack_math.h"  // R824: migrated
    #include "rules/audits/r086_cursed_hire.h"  // R824: migrated
    #include "rules/audits/r087_burden.h"  // R824: migrated
    #include "rules/audits/r088_warning.h"  // R824: migrated
    #include "rules/audits/r089_pace.h"  // R824: migrated
    #include "rules/audits/r090_clock.h"  // R824: migrated
    #include "rules/audits/r091_stairs.h"  // R824: migrated
    #include "rules/audits/r092_road.h"  // R824: migrated
    #include "rules/audits/r093_ledger.h"  // R824: migrated
    #include "rules/audits/r094_nerve.h"  // R824: migrated
    #include "rules/audits/r095_calendar.h"  // R824: migrated
    #include "rules/audits/r096_town_clock.h"  // R824: migrated
    #include "rules/audits/r097_gray_beard.h"  // R824: migrated
    #include "rules/audits/r114_aging.h"  // R825: migrated
    #include "rules/audits/r115_weapon_gate.h"  // R825: migrated
    #include "rules/audits/r115_magic_aging.h"  // R825: migrated
    #include "rules/audits/r116_missile_range.h"  // R825: migrated
    #include "rules/audits/r117_encounter_reactions.h"  // R825: migrated
    #include "rules/audits/r118_listening_doors.h"  // R825: migrated
    #include "rules/audits/r119_forced_rest.h"  // R825: migrated
    #include "rules/audits/r120_parley_listening.h"  // R825: migrated
    #include "rules/audits/r121_crew_officers.h"  // R825: migrated
    #include "rules/audits/r122_treasure_linediff.h"  // R825: migrated
    #include "rules/audits/r123_outdoor_move.h"  // R825: migrated
    #include "rules/audits/r124_appendix_a.h"  // R825: migrated
    #include "rules/audits/r125_traps_tricks.h"  // R825: migrated
    #include "rules/audits/r126_wilderness_linediff.h"  // R825: migrated
    #include "rules/audits/r127_waterborne_linediff.h"  // R825: migrated
    #include "rules/audits/r128_special_rooms.h"  // R825: migrated
    #include "rules/audits/r130_high_level_slots.h"  // R825: migrated
    #include "rules/audits/r131_slot_plumbing.h"  // R825: migrated
    #include "rules/audits/r147_dwarf_con_save.h"  // R826: migrated
    #include "rules/audits/r147_matrix_ii_d.h"  // R826: migrated
    #include "rules/audits/r147_appendix_p.h"  // R826: migrated
    #include "rules/audits/r150_appendix_i.h"  // R826: migrated
    #include "rules/audits/r151_appendix_o.h"  // R826: migrated
    #include "rules/audits/r152_becoming_lost.h"  // R826: migrated
    #include "rules/audits/r153_exceptional_str.h"  // R826: migrated
    #include "rules/audits/r154_pc_races.h"  // R826: migrated
    #include "rules/audits/r155_classed_monsters.h"  // R826: migrated
    #include "rules/audits/r156_convention_party.h"  // R826: migrated
    #include "rules/audits/r157_grenade_missiles.h"  // R826: migrated
    #include "rules/audits/r158_weapon_speed.h"  // R826: migrated
    #include "rules/audits/r159_striking_subdue.h"  // R826: migrated
    #include "rules/audits/r160_weaponless_combat.h"  // R826: migrated
    #include "rules/audits/r161_two_weapons.h"  // R826: migrated
    #include "rules/audits/r162_level_titles.h"  // R826: migrated
    #include "rules/audits/r176_printed_xp_tables.h"  // R826: migrated
    #include "rules/audits/r178c_dex_con_tables.h"  // R826: migrated
    #include "rules/audits/r179_subclass_registry.h"  // R827: migrated
    #include "rules/audits/r180_qualification_and_race.h"  // R835: migrated
    #include "rules/audits/r184_paladin_and_ranger_spell.h"  // R835: migrated
    #include "rules/audits/r185_multi_class_and.h"  // R835: migrated
    #include "rules/audits/r188_prime_requisite_xp.h"  // R835: migrated
    #include "rules/audits/r194_wisdom_defense_repin.h"  // R835: migrated
    #include "rules/audits/r200_falling_ladder.h"  // R835: migrated
    #include "rules/audits/r209_npc_personae_facts.h"  // R835: migrated
    #include "rules/audits/r210_npc_personae_traits.h"  // R835: migrated
    #include "rules/audits/r211_npc_body_and_language.h"  // R835: migrated
    #include "rules/audits/r212_hire_costs_and_non_human.h"  // R835: migrated
    #include "rules/audits/r213_construction_and_siege.h"  // R835: migrated
    #include "rules/audits/r214_war_machine_fire_and.h"  // R835: migrated
    #include "rules/audits/r217_scroll_manufacture_and.h"  // R835: migrated
    #include "rules/audits/r218_use_of_magic_items_and.h"  // R835: migrated
    #include "rules/audits/r219_treasure_random_tables.h"  // R835: migrated
    #include "rules/audits/r243_misc_weapons_pins.h"  // R835: migrated
    #include "rules/audits/r257_misc_magic_prose_part_1.h"  // R835: migrated
    #include "rules/audits/r258_misc_magic_prose_part_2.h"  // R835: migrated
    #include "rules/audits/r259_misc_magic_prose_part_3.h"  // R835: migrated
    #include "rules/audits/r280_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r281_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r282_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r283_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r284_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r285_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r286_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r287_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r288_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r289_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r290_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r291_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r292_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r293_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r294_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r295_special_artifacts_prose.h"  // R835: migrated
    #include "rules/audits/r493_wsg_weather_generation.h"  // R835: migrated
    #include "rules/audits/r494_wsg_weather_effects.h"  // R835: migrated
    #include "rules/audits/r603_dmo_legendary_monsters.h"  // R835: migrated
    #include "rules/audits/r604_dmo_spells_and_items.h"  // R835: migrated
    #include "rules/audits/r605_dmo_item_creation.h"  // R835: migrated
    #include "rules/audits/r606_dmo_magical_duels.h"  // R835: migrated
    #include "rules/audits/r607_dmo_true_dweomers.h"  // R835: migrated
    #include "rules/audits/r609_dmo_high_level_skills.h"  // R835: migrated
    #include "rules/audits/r610_dmo_wizard_priest.h"  // R835: migrated
    #include "rules/audits/r611_dmo_rogues.h"  // R835: migrated
    #include "rules/audits/r613_dmo_dueling_appendix.h"  // R835: migrated
    // ---- R782: the deity bridge site block ----
    // THE SITE BLOCK - the behavioral checks the pin
    // mirror cannot see (the engine class, the R400
    // lesson): every Appendix S stat block rides the
    // bridge and the printed cells land whole on the
    // Actor. This printf carries no census marker (the
    // census counts the pin audit alone; a bad here
    // still fails the battery by the return). The R406
    // hole cells ride their sentinels verbatim: the
    // attack holes (0/-1) floor to one routine on the
    // bridge and the check mirrors the floor; the AC
    // hole 99 and the unrecorded damage spans (-1)
    // round-trip the block cells whole
    {
        using namespace rules;
        int bad = 0;
        for (int i = 0; i < uasDeityCount(); ++i) {
            const UasStatBlock& b = uasStat(i);
            ai::Actor a = ai::toDeityActor(b);
            int wantAtk = b.atkHalves / 2;
            if (wantAtk < 1) wantAtk = 1;
            if (a.isCharacter || a.team != 1
                || a.name != b.name || a.hp != b.hp
                || a.maxHp != b.hp
                || a.armorClass() != b.ac
                || a.attacksPerRound() != wantAtk
                || a.monsterDamageSides !=
                   b.dmgMax - b.dmgMin + 1
                || a.monsterDamagePlus != b.dmgMin - 1)
                ++bad;
        }
        // the flips this round struck
        if (!nhdDeitySiteExists()
            || nhdStatBlocksOpen())
            ++bad;
        // the spear length spread reads its cells
        if (spearSpeedFactorByLengthFt(5) != 6
            || spearSpeedFactorByLengthFt(1) != 6
            || spearSpeedFactorByLengthFt(7) != 7
            || spearSpeedFactorByLengthFt(13) != 8
            || spearSpeedFactorByLengthFt(20) != 8)
            ++bad;
        printf("R782 deity bridge site: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r783_deity_stat_lines.h"  // R833: migrated
    #include "rules/audits/r784_worship_sites.h"  // R833: migrated
    // ---- R784: the worship-site strings block ----
    // THE STRINGS BLOCK - the authored seam the
    // pin mirror cannot see (the R782 site-block
    // precedent): every worship-site string the
    // uascharts.h accessor returns matches the
    // print read, row for row, fail-on-wrong via
    // the tiny in-header string equality. This
    // printf carries no census marker (the census
    // counts the pin audit alone; a bad here
    // still fails the battery by the return)
    {
        using namespace rules;
        static const char* const want[23] = {
            "battlefield",
            "underground temple",
            "underground temple",
            "underground temple",
            "underground temple",
            "open hilltops",
            "never the same place twice",
            "deep forest",
            "by a fountain or spring",
            "small grove",
            "open field",
            "anywhere",
            "the home",
            "anywhere",
            "forest clearing",
            "underground cavern",
            "subterranean temple",
            "underground forge",
            "battlefield",
            "anywhere",
            "anywhere",
            "underground crypt",
            "in a temple within a cave",
        };
        int bad = 0;
        for (int i = 0; i < 23; ++i)
            if (!uscStrEq(uscWorshipSite(i), want[i]))
                ++bad;
        printf("R784 worship site strings: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r785_ua_spell_table_ledger.h"  // R833: migrated
    #include "rules/audits/r786_dwarven_deity_prose.h"  // R833: migrated
    #include "rules/audits/r787_elven_deity_prose.h"  // R833: migrated
    #include "rules/audits/r788_halfling_deity_prose.h"  // R833: migrated
    #include "rules/audits/r789_gnomish_deity_prose.h"  // R833: migrated
    #include "rules/audits/r790_orcish_deity_prose.h"  // R833: migrated
    #include "rules/audits/r791_registry_promotion_wirin.h"  // R833: migrated
    #include "rules/audits/r792_registry_promotion_defs.h"  // R833: migrated
    #include "rules/audits/r793_registry_promotion_def_n.h"  // R833: migrated
    #include "rules/audits/r794_tooling_data_files_git_a.h"  // R833: migrated
    #include "rules/audits/r795_rn_self_patch_guard.h"  // R833: migrated
    #include "rules/audits/r796_mm2_arc_opener.h"  // R833: migrated
    #include "rules/audits/r797_mm2_letter_a.h"  // R833: migrated
    // ---- R797: the MM2 letter A live def walk (no census marker) ----
    // The 13 promoted letter-A defs cross-checked live against the
    // mm2a pins: every stat cell of the 12-form grid, the mm2_print
    // xp source, the xpValue formula, the plane strings, the Amaimon
    // sentinels, and the registry census 478 -> 491.
    {
        using namespace rules;
        int bad = 0;
        static const char* kA[13] = {
            "aboleth", "afanc", "agathion", "annis", "ant_lion",
            "ascomoid", "aspis_drone", "aspis_larva", "aspis_cow",
            "atomie", "aurumvorax", "azer", "amaimon"
        };
        for (int i = 0; i < 13; ++i) {
            const auto* d = reg.find(kA[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase + d->avgHp * d->xpPerHp) ++bad;
            if (i < 12) {
                if (d->armorClass != mm2aStatAC(i)) ++bad;
                if (d->hitDiceNum != mm2aStatHd(i)) ++bad;
                if (d->hitDiceBonus != mm2aStatHdBonus(i)) ++bad;
                if (d->avgHp != mm2aStatAvgHp(i)) ++bad;
                if (d->attacks != mm2aStatAttacks(i)) ++bad;
                if (d->xpBase != mm2aStatXp(i)) ++bad;
                if (d->xpPerHp != mm2aStatXpHp(i)) ++bad;
                if (d->lairPct != mm2aStatLairPct(i)) ++bad;
                if (d->moveRate != mm2aStatMove(i)) ++bad;
            }
        }
        const auto* az = reg.find("azer");
        const auto* am = reg.find("amaimon");
        if (!az || az->plane != "Elemental Plane of Fire") ++bad;
        if (!am || am->plane != "Elemental Plane of Fire") ++bad;
        if (am) {
            if (am->hitDiceNum != mm2aAmaimonHdNum()) ++bad;
            if (am->hitDiceBonus != mm2aAmaimonHdBonus()) ++bad;
            if (am->avgHp != mm2aAmaimonAvgHp()) ++bad;
            if (am->xpBase != 0 || am->xpPerHp != 0) ++bad;
            if (am->magicResist != mm2aAmaimonMR()) ++bad;
        }
        if ((int)reg.all().size() < mm2aRegistryAfter()) ++bad;
        printf("R797 MM2 letter A live defs: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r798_mm2_letters_bc.h"  // R835: migrated
    // ---- R798: the MM2 letters BC live def walk (no census marker) ----
    // The 43 promoted letters-B-and-C defs cross-checked live
    // against the mm2bc pins: every stat cell of the 26-row B
    // grid and the 17-row C grid, the mm2_print xp source, the
    // xpValue formula, the plane strings, and the registry
    // census floor 491 -> 534 (the arc grows the
    // registry in later letter rounds; the walk demands
    // at least the landing count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kB[26] = {
            "baku", "banderlog", "barghest", "barkburr", "basidirond",
            "basilisk_greater", "bat_mobat", "bat_ordinary", "fire_bat",
            "bear_northern", "bee_worker", "bee_soldier", "bee_bumblebee",
            "beetle_death_watch", "beetle_slicer", "behemoth", "behir",
            "bloodthorn", "boalisk", "bodak", "boggart", "boggle", "boobrie",
            "bookworm", "bowler", "buckawn",
        };
        for (int i = 0; i < 26; ++i) {
            const auto* d = reg.find(kB[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2bcBStatAC(i)) ++bad;
            if (d->hitDiceNum != mm2bcBStatHd(i)) ++bad;
            if (d->hitDiceBonus != mm2bcBStatHdBonus(i)) ++bad;
            if (d->avgHp != mm2bcBStatAvgHp(i)) ++bad;
            if (d->attacks != mm2bcBStatAttacks(i)) ++bad;
            if (d->xpBase != mm2bcBStatXp(i)) ++bad;
            if (d->xpPerHp != mm2bcBStatXpHp(i)) ++bad;
            if (d->lairPct != mm2bcBStatLairPct(i)) ++bad;
            if (d->moveRate != mm2bcBStatMove(i)) ++bad;
        }
        static const char* kC[17] = {
            "cat_domestic", "cat_wild", "cat_lord", "catfish_giant",
            "cave_cricket", "cave_fisher", "cave_moray", "centipede_huge",
            "centipede_megalo", "cheetah", "choke_creeper", "cloaker",
            "cooshee", "crane_giant", "crysmal", "crystal_ooze", "cyclopskin",
        };
        for (int i = 0; i < 17; ++i) {
            const auto* d = reg.find(kC[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2bcCStatAC(i)) ++bad;
            if (d->hitDiceNum != mm2bcCStatHd(i)) ++bad;
            if (d->hitDiceBonus != mm2bcCStatHdBonus(i)) ++bad;
            if (d->avgHp != mm2bcCStatAvgHp(i)) ++bad;
            if (d->attacks != mm2bcCStatAttacks(i)) ++bad;
            if (d->xpBase != mm2bcCStatXp(i)) ++bad;
            if (d->xpPerHp != mm2bcCStatXpHp(i)) ++bad;
            if (d->lairPct != mm2bcCStatLairPct(i)) ++bad;
            if (d->moveRate != mm2bcCStatMove(i)) ++bad;
        }
        const auto* fb = reg.find("fire_bat");
        const auto* cr = reg.find("crysmal");
        if (!fb || fb->plane != "Elemental Plane of Fire") ++bad;
        if (!cr || cr->plane != "Elemental Plane of Earth") ++bad;
        if ((int)reg.all().size() < mm2bcRegistryAfter()) ++bad;
        printf("R798 MM2 letters BC live defs: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r799_mm2_letter_d_part_1.h"  // R833: migrated
    // ---- R799: the MM2 letter D part 1 live def walk ----
    // The 29 promoted planar-evil defs cross-checked live
    // against the mm2dp pins: every stat cell of the 29-row
    // DpStats grid, the mm2_print xp source, the xpValue
    // formula, the dao plane string, the cambion parentage
    // cells, the derro xp-0 sentinel, and the registry census
    // floor 534 -> 563 (the arc grows the registry in later
    // letter rounds; the walk demands at least the landing
    // count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kD[29] = {
            "arcanadaemon", "charon", "charonadaemon", "derghodaemon",
            "hydrodaemon", "oinodaemon", "piscodaemon", "ultrodaemon",
            "yagnodaemon", "dao", "crimson_death", "demilich", "farastu",
            "kelubar", "shator", "alu_demon", "babau", "baphomet",
            "bar_lgura", "cambion", "chasme", "dretch", "fraz_urbluu",
            "grazzt", "kostchtchie", "nabassu", "pazuzu", "rutterkin",
            "derro",
        };
        for (int i = 0; i < 29; ++i) {
            const auto* d = reg.find(kD[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2dpDpStatAC(i)) ++bad;
            if (d->hitDiceNum != mm2dpDpStatHd(i)) ++bad;
            if (d->hitDiceBonus != mm2dpDpStatHdBonus(i)) ++bad;
            if (d->avgHp != mm2dpDpStatAvgHp(i)) ++bad;
            if (d->attacks != mm2dpDpStatAttacks(i)) ++bad;
            if (d->xpBase != mm2dpDpStatXp(i)) ++bad;
            if (d->xpPerHp != mm2dpDpStatXpHp(i)) ++bad;
            if (d->lairPct != mm2dpDpStatLairPct(i)) ++bad;
            if (d->moveRate != mm2dpDpStatMove(i)) ++bad;
        }
        const auto* da = reg.find("dao");
        if (!da || da->plane != "Elemental Plane of Earth") ++bad;
        const auto* dr = reg.find("derro");
        if (!dr || dr->xpBase != 0 || dr->xpPerHp != 0
            || dr->xpValue != 0) ++bad;
        const auto* ca = reg.find("cambion");
        if (!ca || ca->armorClass != mm2dpCambionMajorLo(0)) ++bad;
        if (!ca || ca->hitDiceNum != mm2dpCambionMajorLo(1)) ++bad;
        if ((int)reg.all().size() < mm2dpRegistryAfter()) ++bad;
        printf("R799 MM2 letter D part 1 live defs: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r800_mm2_letter_d_part_2.h"  // R833: migrated
    // ---- R800: the MM2 letter D part 2 live def walk ----
    // The 3 promoted deva defs cross-checked live
    // against the mm2dv pins: every stat cell of
    // the 3-row DevaStats grid, the magic-resistance
    // column, the mm2_print xp source, the xpValue
    // formula, and the registry census floor
    // 563 -> 566 (the arc grows the registry in later
    // letter rounds; the walk demands at least the
    // landing count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kD[3] = {
            "astral_deva", "monadic_deva", "movanic_deva",
        };
        for (int i = 0; i < 3; ++i) {
            const auto* d = reg.find(kD[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2dvDevaStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2dvDevaStatHd(i))
                ++bad;
            if (d->hitDiceBonus != mm2dvDevaStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2dvDevaStatAvgHp(i)) ++bad;
            if (d->attacks != mm2dvDevaStatAttacks(i)) ++bad;
            if (d->xpBase != mm2dvDevaStatXp(i)) ++bad;
            if (d->xpPerHp != mm2dvDevaStatXpHp(i)) ++bad;
            if (d->lairPct != mm2dvDevaStatLairPct(i)) ++bad;
            if (d->moveRate != mm2dvDevaStatMove(i)) ++bad;
            if (d->magicResist != mm2dvDevaStatMr(i)) ++bad;
        }
        if ((int)reg.all().size() < mm2dvRegistryAfter())
            ++bad;
        printf("R800 MM2 letter D part 2 live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r801_mm2_devil_section.h"  // R833: migrated
    // ---- R801: the MM2 letter D part 3 live def walk ----
    // The 17 promoted devil defs cross-checked live
    // against the mm2df pins: every stat cell of
    // the 17-row DevStats grid, the magic-resistance
    // column, the mm2_print xp source, the xpValue
    // formula, the loader attack semantics (the
    // Amon 1-and-1 sum, the bearded 1-or-3 max, the
    // spined 1-and/or-2 sum), the nupperibo
    // Standard word, and the registry census floor
    // 566 -> 583 (the arc grows the registry in
    // later letter rounds; the walk demands at
    // least the landing count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kD[17] = {
            "black_abishai", "blue_abishai",
            "green_abishai", "red_abishai",
            "white_abishai", "amon", "bael",
            "bearded_devil", "belial", "glasya",
            "hutijin", "mammon", "mephistopheles",
            "moloch", "nupperibo", "titivilus",
            "spined_devil",
        };
        for (int i = 0; i < 17; ++i) {
            const auto* d = reg.find(kD[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2dfDevStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2dfDevStatHd(i))
                ++bad;
            if (d->hitDiceBonus != mm2dfDevStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2dfDevStatAvgHp(i)) ++bad;
            if (d->attacks != mm2dfDevStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2dfDevStatXp(i)) ++bad;
            if (d->xpPerHp != mm2dfDevStatXpHp(i)) ++bad;
            if (d->lairPct != mm2dfDevStatLairPct(i)) ++bad;
            if (d->moveRate != mm2dfDevStatMove(i)) ++bad;
            if (d->magicResist != mm2dfDevStatMr(i)) ++bad;
        }
        const auto* nu = reg.find("nupperibo");
        if (!nu || nu->magicResist != 0) ++bad;
        if ((int)reg.all().size() < mm2dfRegistryAfter())
            ++bad;
        printf("R801 MM2 letter D part 3 live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r802_mm2_dinosaur_section.h"  // R833: migrated
    // ---- R802: the MM2 letter D part 4 live def walk ----
    // The 20 promoted diakk-and-dinosaur defs
    // cross-checked live against the mm2dn pins:
    // every stat cell of the 20-row DinoStats
    // grid, the magic-resistance column, the
    // mm2_print xp source, the xpValue formula,
    // the loader attack semantics (the diakk
    // 1-or-2 max, the nothosaurus 1-and-2 sum,
    // the tennodontosaurus 1-and-1 sum, the
    // camptosaurus printed-0 clamp), the
    // compsognathus minus-1 bonus, the
    // podokesaurus print quirk (the empty text,
    // the prose rides the struthiomimus entry),
    // and the registry census floor 583 -> at
    // least 603 (the arc grows the registry in
    // later letter rounds; the walk demands at
    // least the landing count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kD[20] = {
            "diakk", "ankisaurus", "camptosaurus",
            "compsognathus", "dacentrurus",
            "deinonychus", "dilophosaurus",
            "dimetrodon", "euparkeria",
            "kentrosaurus", "mamenchisaurus",
            "massopondylus", "nothosaurus",
            "ornitholestes", "phororhacos",
            "podokesaurus", "giant_pterosaur",
            "struthiomimus", "tanystropheus",
            "tennodontosaurus",
        };
        for (int i = 0; i < 20; ++i) {
            const auto* d = reg.find(kD[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2dnDinoStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2dnDinoStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2dnDinoStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2dnDinoStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2dnDinoStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2dnDinoStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2dnDinoStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2dnDinoStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2dnDinoStatMove(i))
                ++bad;
            if (d->magicResist != mm2dnDinoStatMr(i))
                ++bad;
        }
        const auto* ca = reg.find("camptosaurus");
        if (!ca || ca->attacks != 1) ++bad;
        const auto* po = reg.find("podokesaurus");
        if (!po || !po->text.empty()) ++bad;
        const auto* st = reg.find("struthiomimus");
        if (!st || st->text.find("podokesaur")
            == std::string::npos) ++bad;
        if ((int)reg.all().size()
            < mm2dnRegistryAfter())
            ++bad;
        printf("R802 MM2 letter D part 4 live defs: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r803_mm2_dragon_section.h"  // R833: migrated
    // ---- R803: the MM2 letter D part 5 live def walk ----
    // The 12 promoted letter-D-part-5 defs
    // cross-checked live against the mm2dg pins: every
    // stat cell of the 12-row DgStats grid, the
    // mm2_print xp source and the xpValue formula
    // (the duergar by_level carry carries no xp
    // fields - the dervish and dwarf precedent), the
    // dracolisk petrify gaze prose, the shadow
    // dragon hide-in-shadows prose, the dustdigger
    // front-side armor class 7 prose, and the
    // registry census floor 603 -> at least 615 (the
    // arc grows the registry in later letter
    // rounds; the walk demands at least the landing
    // count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kD[12] = {
            "dracolisk", "cloud_dragon", "faerie_dragon",
            "mist_dragon", "shadow_dragon",
            "giant_dragonfly", "dragon_horse", "dragonnel",
            "drelb", "drider", "duergar", "dustdigger",
        };
        for (int i = 0; i < 12; ++i) {
            const auto* d = reg.find(kD[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print"
                && d->xpSource != "by_level")
                ++bad;
            if (d->xpSource == "mm2_print"
                && d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2dgDgStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2dgDgStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2dgDgStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2dgDgStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2dgDgStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2dgDgStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2dgDgStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2dgDgStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2dgDgStatMove(i))
                ++bad;
            if (d->magicResist != mm2dgDgStatMr(i))
                ++bad;
        }
        const auto* dk = reg.find("dracolisk");
        if (!dk || dk->text.find("petrify")
            == std::string::npos) ++bad;
        const auto* sd = reg.find("shadow_dragon");
        if (!sd || sd->text.find("hide in shadows")
            == std::string::npos) ++bad;
        const auto* du = reg.find("duergar");
        if (!du || du->xpSource != "by_level") ++bad;
        const auto* dd = reg.find("dustdigger");
        if (!dd || dd->text.find("armor class 7")
            == std::string::npos) ++bad;
        if ((int)reg.all().size()
            < mm2dgRegistryAfter())
            ++bad;
        printf("R803 MM2 letter D part 5 live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r804_mm2_letter_e_walk.h"  // R833: migrated
    // ---- R804: the MM2 letter E live def walk ----
    // The 7 promoted letter-E defs cross-checked
    // live against the mm2de pins: every stat cell
    // of the 7-row EgStats grid, the mm2_print xp
    // source and the xpValue formula, the grugach
    // "N, Q" treasure print (the capture "N, O"
    // the OCR misread), the grugach fighter/druids
    // prose (the capture "fluids" the misread),
    // the valley elf cooshee guards, the elfin cat
    // ESP prose, the executioner's hood sleep
    // immunity prose, and the registry census
    // floor 615 -> at least 622 (the arc grows the
    // registry in later letter rounds; the walk
    // demands at least the landing count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kE[7] = {
            "eagle", "eblis", "electric_eel", "grugach",
            "valley_elf", "elfin_cat", "executioners_hood",
        };
        for (int i = 0; i < 7; ++i) {
            const auto* d = reg.find(kE[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2deEgStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2deEgStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2deEgStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2deEgStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2deEgStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2deEgStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2deEgStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2deEgStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2deEgStatMove(i))
                ++bad;
            if (d->magicResist != mm2deEgStatMr(i))
                ++bad;
        }
        const auto* eg = reg.find("eagle");
        if (!eg || eg->text.find("rookery")
            == std::string::npos) ++bad;
        const auto* eb = reg.find("eblis");
        if (!eb || eb->text.find("whispering wind")
            == std::string::npos) ++bad;
        const auto* ee = reg.find("electric_eel");
        if (!ee || ee->text.find("stunned")
            == std::string::npos) ++bad;
        const auto* gr = reg.find("grugach");
        if (!gr || gr->text.find("fighter/druids")
            == std::string::npos) ++bad;
        const auto* ve = reg.find("valley_elf");
        if (!ve || ve->text.find("cooshee")
            == std::string::npos) ++bad;
        const auto* ec = reg.find("elfin_cat");
        if (!ec || ec->text.find("ESP")
            == std::string::npos) ++bad;
        const auto* hd = reg.find("executioners_hood");
        if (!hd || hd->text.find("sleep spells")
            == std::string::npos) ++bad;
        if ((int)reg.all().size()
            < mm2deRegistryAfter())
            ++bad;
        printf("R804 MM2 letter E live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r805_mm2_letters_fg_walk.h"  // R833: migrated
    // ---- R805: the MM2 letters FG live def walk ----
    // The 28 promoted letter-F and letter-G defs
    // cross-checked live against the mm2fg pins:
    // every stat cell of the 28-row FgStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the falcon plummeting dive and
    // blinding beak, the firefriend greenish-light
    // beam, the giant fly backward spring, the foo
    // barking roar, the forester bane snapper-saw,
    // the formian centaur-ants, the froghemoth
    // tadhemoths, the galeb duhr earth power
    // print, the fomorian deformed and wicked
    // giants, the firbolg bat-away-missiles read
    // (the capture "8 or better" the OCR misread,
    // the print reads 6, the 75% arithmetic the
    // settle), the verbeeg human behemoths, the
    // gibbering mouther all-mouths-and-eyes body,
    // the gloomwing tenebrous-worm larva, the
    // goat charge, the gorgimera sterile hybrid,
    // the greenhag rock-hard talons, the grippli
    // tribe mother, the grig Otto's Irresistible
    // Dance fiddler, the grim turn-undead
    // guardians, the chaggrin soil beast, the
    // harginn flame horror, the ildriss wind
    // terror, the varrdig fluid brute, and the
    // registry census floor 622 -> at least
    // 650 (the arc grows the registry in later
    // letter rounds; the walk demands at least
    // the landing count).
    {
        using namespace rules;
        int bad = 0;
        static const char* kFG[28] = {
            "falcon_small", "falcon_large",
            "firefriend", "fly_bluebottle",
            "fly_horsefly", "foo_dog",
            "foo_lion", "foresters_bane",
            "formian_myrmarch", "formian_warrior",
            "formian_worker", "froghemoth",
            "galeb_duh", "fomorian",
            "firbolg", "verbeeg",
            "gibbering_mouther", "gloomwing",
            "goat", "gorgimera",
            "greenhag", "grippli",
            "grig", "grim",
            "chaggrin", "harginn",
            "ildriss", "varrdig",
        };
        for (int i = 0; i < 28; ++i) {
            const auto* d = reg.find(kFG[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2fgFgStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2fgFgStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2fgFgStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2fgFgStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2fgFgStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2fgFgStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2fgFgStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2fgFgStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2fgFgStatMove(i))
                ++bad;
            if (d->magicResist != mm2fgFgStatMr(i))
                ++bad;
        }
        const auto* pp00 = reg.find("falcon_small");
        if (!pp00 || pp00->text.find("plummeting dive")
            == std::string::npos) ++bad;
        const auto* pp01 = reg.find("falcon_large");
        if (!pp01 || pp01->text.find("blinding 1 eye")
            == std::string::npos) ++bad;
        const auto* pp02 = reg.find("firefriend");
        if (!pp02 || pp02->text.find("greenish light")
            == std::string::npos) ++bad;
        const auto* pp03 = reg.find("fly_bluebottle");
        if (!pp03 || pp03->text.find("backward spring")
            == std::string::npos) ++bad;
        const auto* pp04 = reg.find("fly_horsefly");
        if (!pp04 || pp04->text.find("largest of all giant flies")
            == std::string::npos) ++bad;
        const auto* pp05 = reg.find("foo_dog");
        if (!pp05 || pp05->text.find("barking roar")
            == std::string::npos) ++bad;
        const auto* pp06 = reg.find("foo_lion");
        if (!pp06 || pp06->text.find("bush-tipped tails")
            == std::string::npos) ++bad;
        const auto* pp07 = reg.find("foresters_bane");
        if (!pp07 || pp07->text.find("snapper-saw")
            == std::string::npos) ++bad;
        const auto* pp08 = reg.find("formian_myrmarch");
        if (!pp08 || pp08->text.find("centaur-ants")
            == std::string::npos) ++bad;
        const auto* pp09 = reg.find("formian_warrior");
        if (!pp09 || pp09->text.find("raiding party")
            == std::string::npos) ++bad;
        const auto* pp10 = reg.find("formian_worker");
        if (!pp10 || pp10->text.find("22 strength points")
            == std::string::npos) ++bad;
        const auto* pp11 = reg.find("froghemoth");
        if (!pp11 || pp11->text.find("tadhemoths")
            == std::string::npos) ++bad;
        const auto* pp12 = reg.find("galeb_duh");
        if (!pp12 || pp12->text.find("earth power")
            == std::string::npos) ++bad;
        const auto* pp13 = reg.find("fomorian");
        if (!pp13 || pp13->text.find("deformed, and wicked")
            == std::string::npos) ++bad;
        const auto* pp14 = reg.find("firbolg");
        if (!pp14 || pp14->text.find("bat away missiles")
            == std::string::npos) ++bad;
        const auto* pp15 = reg.find("verbeeg");
        if (!pp15 || pp15->text.find("human behemoths")
            == std::string::npos) ++bad;
        const auto* pp16 = reg.find("gibbering_mouther");
        if (!pp16 || pp16->text.find("all mouths and eyes")
            == std::string::npos) ++bad;
        const auto* pp17 = reg.find("gloomwing");
        if (!pp17 || pp17->text.find("tenebrous worm")
            == std::string::npos) ++bad;
        const auto* pp18 = reg.find("goat");
        if (!pp18 || pp18->text.find("Buck goats may charge")
            == std::string::npos) ++bad;
        const auto* pp19 = reg.find("gorgimera");
        if (!pp19 || pp19->text.find("sterile hybrid")
            == std::string::npos) ++bad;
        const auto* pp20 = reg.find("greenhag");
        if (!pp20 || pp20->text.find("rock-hard talons")
            == std::string::npos) ++bad;
        const auto* pp21 = reg.find("grippli");
        if (!pp21 || pp21->text.find("tribe mother")
            == std::string::npos) ++bad;
        const auto* pp22 = reg.find("grig");
        if (!pp22 || pp22->text.find("Otto's Irresistible Dance")
            == std::string::npos) ++bad;
        const auto* pp23 = reg.find("grim");
        if (!pp23 || pp23->text.find("turn undead")
            == std::string::npos) ++bad;
        const auto* pp24 = reg.find("chaggrin");
        if (!pp24 || pp24->text.find("soil beast")
            == std::string::npos) ++bad;
        const auto* pp25 = reg.find("harginn");
        if (!pp25 || pp25->text.find("flame horror")
            == std::string::npos) ++bad;
        const auto* pp26 = reg.find("ildriss");
        if (!pp26 || pp26->text.find("wind terror")
            == std::string::npos) ++bad;
        const auto* pp27 = reg.find("varrdig");
        if (!pp27 || pp27->text.find("fluid brute")
            == std::string::npos) ++bad;
        if ((int)reg.all().size()
            < mm2fgRegistryAfter())
            ++bad;
        printf("R805 MM2 letters FG live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r806_mm2_letters_hi_walk.h"  // R833: migrated
    // ---- R806: the MM2 letters HI live def walk ----
    // The five promoted letter-H defs
    // cross-checked live against the mm2hi pins:
    // every stat cell of the 5-row HhStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the hangman tree rope-like
    // appendages and flat printed 61 hp, the
    // haunt restless-spirit possession and its
    // absent magic resistance line, the
    // hollyphant golden-furred trumpet and
    // globe of invulnerability, the hordling
    // Hordes of Hades tiers and the or-form
    // best 9-dice read, the hybsil antelope
    // centaurs and +4 saves, and the registry
    // census floor 650 -> at least 655 (the
    // letter-I span walks empty - the ildriss
    // is already pinned by the R805 FG walk).
    {
        using namespace rules;
        int bad = 0;
        static const char* kHI[5] = {
            "hangman_tree", "haunt",
            "hollyphant", "hordling",
            "hybsil",
        };
        for (int i = 0; i < 5; ++i) {
            const auto* d = reg.find(kHI[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2hiHhStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2hiHhStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2hiHhStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2hiHhStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2hiHhStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2hiHhStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2hiHhStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2hiHhStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2hiHhStatMove(i))
                ++bad;
            if (d->magicResist != mm2hiHhStatMr(i))
                ++bad;
        }
        const auto* pp00 = reg.find("hangman_tree");
        if (!pp00 || pp00->text.find("rope-like appendages")
            == std::string::npos) ++bad;
        const auto* pp01 = reg.find("haunt");
        if (!pp01 || pp01->text.find("restless spirit")
            == std::string::npos) ++bad;
        const auto* pp02 = reg.find("hollyphant");
        if (!pp02 || pp02->text.find("golden-furred")
            == std::string::npos) ++bad;
        const auto* pp03 = reg.find("hordling");
        if (!pp03 || pp03->text.find("Hordes of Hades")
            == std::string::npos) ++bad;
        const auto* pp04 = reg.find("hybsil");
        if (!pp04 || pp04->text.find("antelope centaurs")
            == std::string::npos) ++bad;
        if ((int)reg.all().size()
            < mm2hiRegistryAfter())
            ++bad;
        printf("R806 MM2 letters HI live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r807_mm2_letters_jk_walk.h"  // R833: migrated
    // ---- R807: the MM2 letters JK live def walk ----
    // The six promoted letters-JK defs
    // cross-checked live against the mm2jk pins:
    // every stat cell of the 6-row JkStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the jann weakest-genie chainmail
    // composite, the mustard jelly ochre-relative
    // and or-form attack read, the kampfult sinewy
    // mugger six-appendage load, the kech
    // forest-fiend treasure B (the capture "8" the
    // OCR misread), the korred dance-loving 6+1
    // dice (the capture "8+1" the misread) and
    // the kraken and-sum tentacle read clamped at
    // the 10 sanity ceiling (the R805 purple worm
    // convention meets the clamp), and the
    // registry census floor 655 -> at least 661.
    {
        using namespace rules;
        int bad = 0;
        static const char* kJK[6] = {
            "jann", "mustard_jelly",
            "kampfult", "kech",
            "korred", "kraken",
        };
        for (int i = 0; i < 6; ++i) {
            const auto* d = reg.find(kJK[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2jkJkStatAC(i))
                ++bad;
            if (d->hitDiceNum != mm2jkJkStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2jkJkStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2jkJkStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2jkJkStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2jkJkStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2jkJkStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2jkJkStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2jkJkStatMove(i))
                ++bad;
            if (d->magicResist != mm2jkJkStatMr(i))
                ++bad;
        }
        const auto* pp00 = reg.find("jann");
        if (!pp00
            || pp00->text.find(
                   "weakest of the elemental humanoids")
                   == std::string::npos) ++bad;
        const auto* pp01 = reg.find("mustard_jelly");
        if (!pp01
            || pp01->text.find("ochre jelly")
                   == std::string::npos) ++bad;
        const auto* pp02 = reg.find("kampfult");
        if (!pp02 || pp02->text.find("sinewy mugger")
            == std::string::npos) ++bad;
        const auto* pp03 = reg.find("kech");
        if (!pp03 || pp03->text.find("forest fiends")
            == std::string::npos) ++bad;
        const auto* pp04 = reg.find("korred");
        if (!pp04 || pp04->text.find("dance-loving")
            == std::string::npos) ++bad;
        const auto* pp05 = reg.find("kraken");
        if (!pp05 || pp05->text.find("airy water")
            == std::string::npos) ++bad;
        if ((int)reg.all().size()
            < mm2jkRegistryAfter())
            ++bad;
        printf("R807 MM2 letters JK live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r808_mm2_letters_lmn_walk.h"  // R835: migrated
    // ---- R808: the MM2 letters LMN live def walk ----
    // The 38 promoted letters-LMN defs
    // cross-checked live against the mm2lmn pins:
    // every stat cell of the 38-row LmStats grid,
    // the mm2_print xp source and the xpValue
    // formula (the by_level defs skipped - the
    // mandragora, the mongrelman and the myconid),
    // the per-def prose markers, and the registry
    // census floor 661 -> at least 699.
    {
        using namespace rules;
        int bad = 0;
        static const char* kLM[38] = {
            "land_lamprey", "luck_eater", "foxwoman", "seawolf_greater",
            "seawolf_lesser", "wereshark", "magman", "mandragora",
            "giant_mantis", "mantrap", "margoyle", "marid",
            "shadow_mastiff", "mihstu", "miner", "monodrone", "duodrone",
            "tridrone", "quadrone", "pentadrone", "decaton", "nonaton",
            "octon", "septon", "hexton", "quinton", "quarton", "tertian",
            "secundus", "primus", "russet_mold", "mongrelman", "moon_dog",
            "muckdweller", "mud_man", "myconid", "nereid", "narwhale",
        };
        static const char* kLMMark[38] = {
            "sphincter-like mouths", "golden-furred cat",
            "silver-furred elf with a fox-like head", "wolf-headed seal",
            "porpoise-like in shape", "great white sharks",
            "Para-elemental Plane of Heat", "confused with the mandrake",
            "vise-like forelimbs", "insidious plant attracts prey by scent",
            "horrid form of gargoyle", "most powerful of all geniekind",
            "Plane of Shadow", "clouds of swirling mist",
            "relative of the trapper", "single-function modrons",
            "bifunctional modrons", "3-sided pyramids", "cubic quadrones",
            "starfish on thin stilt-like legs", "10-tentacled spheres",
            "cylindrical modrons", "circular collar at shoulder level",
            "large bald heads", "a general in charge of 1 of the armies",
            "diamond inscribed in their foreheads",
            "administer the regions of Nirvana", "mace-like ball",
            "viceroys of the quarters",
            "ruler of all the planes of Nirvana", "vegepygmy",
            "mixture of many different creatures",
            "black hound or night prowler", "bipedal amphibian monster",
            "animated mud", "walking toadstools", "the honeyed ones",
            "unicorns of the ocean",
        };
        for (int i = 0; i < 38; ++i) {
            const auto* d = reg.find(kLM[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print"
                && d->xpSource != "by_level")
                ++bad;
            if (d->xpSource == "mm2_print"
                && d->xpValue != d->xpBase
                   + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2lmnLmStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2lmnLmStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2lmnLmStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2lmnLmStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2lmnLmStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2lmnLmStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2lmnLmStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2lmnLmStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2lmnLmStatMove(i))
                ++bad;
            if (d->magicResist != mm2lmnLmStatMr(i))
                ++bad;
            if (d->text.find(kLMMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2lmnRegistryAfter())
            ++bad;
        printf("R808 MM2 letters LMN live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r809_mm2_letter_o_walk.h"  // R833: migrated
    // ---- R809: the MM2 letter O live def walk ----
    // The 7 promoted letter O defs
    // cross-checked live against the mm2o pins:
    // every stat cell of the 7-row OStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the per-def prose markers, and the
    // registry census floor 699 -> at least 706.
    {
        using namespace rules;
        int bad = 0;
        static const char* kO[7] = {
            "obliviax", "merrow", "oliphant",
            "ophidian", "opinicus", "otter", "owl",
        };
        static const char* kOMark[7] = {
            "tiny moss imitation of the creature",
            "in association with scrags",
            "castle-like houdas",
            "lycanthrope-like affliction",
            "sun sparkles",
            "largest sort of ordinary otter",
            "used as decoys by hunters",
        };
        for (int i = 0; i < 7; ++i) {
            const auto* d = reg.find(kO[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2oOStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2oOStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2oOStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2oOStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2oOStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2oOStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2oOStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2oOStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2oOStatMove(i))
                ++bad;
            if (d->magicResist != mm2oOStatMr(i))
                ++bad;
            if (d->text.find(kOMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2oRegistryAfter())
            ++bad;
        printf("R809 MM2 letter O live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r810_mm2_letter_p_walk.h"  // R833: migrated
    // ---- R810: the MM2 letter P live def walk ----
    // The 17 promoted letter P defs
    // cross-checked live against the mm2p pins:
    // every stat cell of the 17-row PStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the per-def prose markers, and the
    // registry census floor 706 -> at least 723.
    {
        using namespace rules;
        int bad = 0;
        static const char* kP[17] = {
            "para_elemental_ice",
            "para_elemental_smoke",
            "para_elemental_magma",
            "para_elemental_ooze",
            "pech",
            "pedipalp_large",
            "pedipalp_huge",
            "pedipalp_giant",
            "phantom",
            "phoenix",
            "phycomid",
            "planetar",
            "pseudo_undead",
            "pudding_brown",
            "pudding_dun",
            "pudding_white",
            "pyrolisk",
        };
        static const char* kPMark[17] = {
            "coated with frost",
            "concentrated blast of black fog",
            "legs and torsos are molten rock",
            "dark writhing tendrils",
            "hard as granite",
            "cross between a spider and a scorpion",
            "same as that for opening doors",
            "discharge a noxious vapor",
            "soulless shells",
            "diamond-hard talons",
            "sprout mushroom-like growths",
            "right hand of a minor deity",
            "looks and smells exactly like its parallel",
            "dwells principally in marsh areas",
            "feed on silicates",
            "mistaken for snow and ice",
            "1 red feather in the tail",
        };
        for (int i = 0; i < 17; ++i) {
            const auto* d = reg.find(kP[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2pPStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2pPStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2pPStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2pPStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2pPStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2pPStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2pPStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2pPStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2pPStatMove(i))
                ++bad;
            if (d->magicResist != mm2pPStatMr(i))
                ++bad;
            if (d->text.find(kPMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2pRegistryAfter())
            ++bad;
        printf("R810 MM2 letter P live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r811_mm2_letter_q_walk.h"  // R833: migrated
    // ---- R811: the MM2 letter Q live def walk ----
    // The 3 promoted letter Q defs
    // cross-checked live against the mm2q pins:
    // every stat cell of the 3-row QStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the per-def prose markers, and the
    // registry census floor 723 -> at least 726.
    {
        using namespace rules;
        int bad = 0;
        static const char* kQ[3] = {
            "quasi_elemental_lightning",
            "quickling",
            "quickwood",
        };
        static const char* kQMark[3] = {
            "globe of ball lightning",
            "brownies who dabbled in magic",
            "distorted human face",
        };
        for (int i = 0; i < 3; ++i) {
            const auto* d = reg.find(kQ[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2qQStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2qQStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2qQStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2qQStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2qQStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2qQStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2qQStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2qQStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2qQStatMove(i))
                ++bad;
            if (d->magicResist != mm2qQStatMr(i))
                ++bad;
            if (d->text.find(kQMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2qRegistryAfter())
            ++bad;
        printf("R811 MM2 letter Q live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r812_mm2_letter_r_walk.h"  // R833: migrated
    // ---- R812: the MM2 letter R live def walk ----
    // The 7 promoted letter R defs
    // cross-checked live against the mm2r pins:
    // every stat cell of the 7-row RStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the per-def prose markers, and the
    // registry census floor 726 -> at least 733.
    {
        using namespace rules;
        int bad = 0;
        static const char* kR[7] = {
            "rat_ordinary",
            "rat_vapor",
            "raven_ordinary",
            "raven_huge",
            "raven_giant",
            "retch_plant",
            "rock_reptile",
        };
        static const char* kRMark[7] = {
            "filthy bite",
            "stinking cloud spell",
            "never be surprised during lighted conditions",
            "malicious disposition",
            "easily trained",
            "nauseating fluid",
            "pile of rubble or rocks",
        };
        for (int i = 0; i < 7; ++i) {
            const auto* d = reg.find(kR[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2rRStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2rRStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2rRStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2rRStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2rRStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2rRStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2rRStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2rRStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2rRStatMove(i))
                ++bad;
            if (d->magicResist != mm2rRStatMr(i))
                ++bad;
            if (d->text.find(kRMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2rRegistryAfter())
            ++bad;
        printf("R812 MM2 letter R live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r813_mm2_letter_s_walk.h"  // R835: migrated
    // ---- R813: the MM2 letter S live def walk ----
    // The 33 promoted letter S defs
    // cross-checked live against the mm2s pins:
    // every stat cell of the 33-row SStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the per-def prose markers, and the
    // registry census floor 733 -> at least 766.
    {
        using namespace rules;
        int bad = 0;
        static const char* kS[33] = {
            "sandling",
            "scorpion_large",
            "scorpion_huge",
            "scum_creeper",
            "selkie",
            "shade",
            "sirine",
            "skeleton_animal",
            "skunk",
            "slime_creature",
            "slime_olive",
            "snake_constrictor",
            "snake_poisonous",
            "solar",
            "solifugid_large",
            "solifugid_huge",
            "solifugid_giant",
            "spectator",
            "spider_giant_marine",
            "spriggan",
            "squealer",
            "squirrel_giant_black",
            "squirrel_ordinary",
            "squirrel_carnivorous_flying",
            "stegocentipede",
            "stench_kow",
            "stone_guardian",
            "storoper",
            "sundew_giant",
            "swan",
            "swanmay",
            "swordfish",
            "taer",
        };
        static const char* kSMark[33] = {
            "moving, sliding sand",
            "weaker than normal",
            "instantly killed",
            "shearing plates of hornlike substance",
            "becomes a sort of sealwere",
            "essence of shadowstuff",
            "save vs. poison or become an idiot",
            "1-1/2 per experience level",
            "cloud of stinking musk",
            "metamorphosed hosts of olive slime",
            "akin to green slime",
            "bite and coiling to constrict",
            "Use the table below to determine strength",
            "arrows of slaying",
            "sucker-like clamps",
            "nocturnal variety",
            "warm desert climates",
            "guard for up to 101 years",
            "huge air-filled underwater nests",
            "cousins of the gnomes",
            "grasp the limb it is upon",
            "small, shiny objects",
            "bite only in self defense",
            "range is 5 feet for every foot",
            "insane genetic manipulator",
            "cattle of the Nine Hells",
            "golem-like figure",
            "stone roper",
            "hundreds of tendrils",
            "blind and disorient",
            "feather token",
            "fearsome weapon",
            "polished teeth",
        };
        for (int i = 0; i < 33; ++i) {
            const auto* d = reg.find(kS[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2sSStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2sSStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2sSStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2sSStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2sSStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2sSStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2sSStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2sSStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2sSStatMove(i))
                ++bad;
            if (d->magicResist != mm2sSStatMr(i))
                ++bad;
            if (d->text.find(kSMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2sRegistryAfter())
            ++bad;
        printf("R813 MM2 letter S live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r814_mm2_letters_tuv_walk.h"  // R835: migrated
    // ---- R814: the MM2 letters TUV live def walk ----
    // The 26 promoted letters TUV defs
    // cross-checked live against the mm2tuv pins:
    // every stat cell of the 26-row TUVStats grid,
    // the mm2_print xp source and the xpValue
    // formula, the per-def prose markers, and the
    // registry census floor 766 -> at least 792.
    {
        using namespace rules;
        int bad = 0;
        static const char* kTUV[26] = {
            "tarrasque",
            "tasloi",
            "termite_worker",
            "termite_soldier",
            "termite_king",
            "termite_queen",
            "thessalhydra",
            "thri_kreen",
            "thunder_beast",
            "time_elemental",
            "thunderherder",
            "transposer",
            "tri_flower_frond",
            "scrag_freshwater",
            "scrag_saltwater",
            "twilight_bloom",
            "urchin_land",
            "ustilagor",
            "vagabond",
            "vargouille",
            "vegepygmy",
            "verme",
            "vilstrak",
            "vulchling",
            "vulture_giant",
            "vulture_ordinary",
        };
        static const char* kTUVMark[26] = {
            "ravishes the countryside for miles",
            "Masters of stealth",
            "weak-mandibled worker",
            "blind any creature struck",
            "hp 30 or more",
            "hp 40 or more",
            "fringe of snake-like heads",
            "carnivorous insectmen",
            "rumbling bellow",
            "cloud of fire dust",
            "distant cousins to the purple worm",
            "sucker-like members",
            "comatose slumber",
            "gilled form of the common troll",
            "armor made of shells and sharkskin",
            "syrupy poison",
            "mistaken for a bush",
            "brain-like growths",
            "parallel unverse",
            "spawned in Tarterus",
            "russet mold",
            "largest of fish",
            "marl muggers",
            "vaguely human features",
            "must actually be struck",
            "weaken past the point of resistance",
        };
        for (int i = 0; i < 26; ++i) {
            const auto* d = reg.find(kTUV[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2tuvTUVStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2tuvTUVStatHd(i))
                ++bad;
            if (d->hitDiceBonus != mm2tuvTUVStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2tuvTUVStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2tuvTUVStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2tuvTUVStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2tuvTUVStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2tuvTUVStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2tuvTUVStatMove(i))
                ++bad;
            if (d->magicResist != mm2tuvTUVStatMr(i))
                ++bad;
            if (d->text.find(kTUVMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2tuvRegistryAfter())
            ++bad;
        printf("R814 MM2 letters TUV live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r815_mm2_letters_wxyz_walk.h"  // R833: migrated
    // ---- R815: the MM2 letters WXYZ live def walk ----
    // The 17 promoted letters WXYZ defs
    // cross-checked live against the mm2wxyz pins:
    // every stat cell of the 17-row WXYZStats grid,
    // the mm2_print xp source and the xpValue
    // formula (the by_level exception at the
    // yuan ti), the per-def prose markers, and the
    // registry census floor 792 -> at least 809.
    {
        using namespace rules;
        int bad = 0;
        static const char* kWXYZ[17] = {
            "weasel",
            "webbird",
            "wemic",
            "willow_black",
            "wolf_in_sheeps_clothing",
            "wolfwere",
            "tenebrous_worm",
            "tunnel_worm",
            "xag_ya_xeg_yi",
            "xaren",
            "yeth_hound",
            "yochlol",
            "yuan_ti",
            "zombie_juju",
            "zombie_monster",
            "zorbo",
            "zygom",
        };
        static const char* kWXYZMark[17] = {
            "hunted for their pelts",
            "beakless bird",
            "large lion centaurs",
            "relishing elves, gnomes, and humans",
            "resemblance to a tree stump",
            "bane of humans and demihumans",
            "half-light of the Plane of Shadows",
            "giant cousin of the centipede",
            "reverse images of each other",
            "relatives of the xorn",
            "almost human appearance",
            "misty columns of gas",
            "degenerate and corrupt race",
            "hateful light burns",
            "animated corpses of huge humanoid",
            "absorb the natural armor class",
            "individual fungoid growths",
        };
        for (int i = 0; i < 17; ++i) {
            const auto* d = reg.find(kWXYZ[i]);
            if (!d) { ++bad; continue; }
            if (d->xpSource != "mm2_print"
                && i != 12)
                ++bad;
            if (i == 12
                && d->xpSource != "by_level")
                ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp)
                ++bad;
            if (d->armorClass != mm2wxyzWXYZStatAc(i))
                ++bad;
            if (d->hitDiceNum != mm2wxyzWXYZStatHd(i))
                ++bad;
            if (d->hitDiceBonus
                != mm2wxyzWXYZStatHdBonus(i))
                ++bad;
            if (d->avgHp != mm2wxyzWXYZStatAvgHp(i))
                ++bad;
            if (d->attacks != mm2wxyzWXYZStatAttacks(i))
                ++bad;
            if (d->xpBase != mm2wxyzWXYZStatXp(i))
                ++bad;
            if (d->xpPerHp != mm2wxyzWXYZStatXpHp(i))
                ++bad;
            if (d->lairPct != mm2wxyzWXYZStatLairPct(i))
                ++bad;
            if (d->moveRate != mm2wxyzWXYZStatMove(i))
                ++bad;
            if (d->magicResist != mm2wxyzWXYZStatMr(i))
                ++bad;
            if (d->text.find(kWXYZMark[i])
                == std::string::npos)
                ++bad;
        }
        if ((int)reg.all().size()
            < mm2wxyzRegistryAfter())
            ++bad;
        printf("R815 MM2 letters WXYZ live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    // ---- R900: the Dragon issue-4 Creature Features live def walk
    // (no census marker) ----
    // The three promoted Creature Features defs (the Mihalli, the
    // Vriyagga, the Qu'uni) cross-checked live against the numbers
    // the cfe pin header carries: the dragon_print xp source, the
    // XP formula, the hit dice, the armor classes, the lair
    // percents, the moves, and the registry census floor: 1308 loaded
    // base defs + the three promotions = 1311 live (the 1333 base
    // files include 25 long-standing load-error defs that never
    // enter the registry, a pre-R900 state not touched by this
    // round). (The walk pins the registry side with literals -
    // the audit header holds the cfe-side mirror, so the regtest
    // source stays free of the round prefix per the R411 gate.)
    {
        using namespace rules;
        int bad = 0;
        const auto* mi = reg.find("mihalli");
        const auto* vr = reg.find("vriyagga");
        const auto* qu = reg.find("qu_uni");
        if (!mi) ++bad;
        if (mi) {
            if (mi->xpSource != "dragon_print") ++bad;
            if (mi->armorClass != 1) ++bad;
            if (mi->hitDiceNum != 3) ++bad;
            if (mi->avgHp != 13) ++bad;
            if (mi->xpBase != 115) ++bad;
            if (mi->xpPerHp != 3) ++bad;
            if (mi->xpValue != 154) ++bad;
            if (mi->lairPct != 40) ++bad;
            if (mi->moveRate != 15) ++bad;
        }
        if (!vr) ++bad;
        if (vr) {
            if (vr->xpSource != "dragon_print") ++bad;
            if (vr->armorClass != 1) ++bad;
            if (vr->hitDiceNum != 15) ++bad;
            if (vr->avgHp != 67) ++bad;
            if (vr->xpBase != 5250) ++bad;
            if (vr->xpPerHp != 20) ++bad;
            if (vr->xpValue != 6590) ++bad;
            if (vr->lairPct != 40) ++bad;
            if (vr->moveRate != 12) ++bad;
        }
        if (!qu) ++bad;
        if (qu) {
            if (qu->xpSource != "dragon_print") ++bad;
            if (qu->armorClass != 3) ++bad;
            if (qu->hitDiceNum != 2) ++bad;
            if (qu->avgHp != 9) ++bad;
            if (qu->xpBase != 20) ++bad;
            if (qu->xpPerHp != 2) ++bad;
            if (qu->xpValue != 38) ++bad;
            if (qu->moveRate != 10) ++bad;
        }
        if ((int)reg.all().size()
            < 1311)
            ++bad;
        printf("R900 Dragon Creature Features live defs: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r816_mm2_dungeon_encounter_gr.h"  // R833: migrated
    // ---- R816: the MM2 dungeon encounter grids walk ----
    // The ten Monster Level grids cross-checked live:
    // the die contiguity 2-20, the one character-party
    // row per table at its die, the four unique-court
    // rows on Level X, the number ranges, and the
    // registry key for every walkable row (the MM2 and
    // MM1 creatures the walks promoted).
    {
        using namespace rules;
        int bad = 0;
        // (the level/row accessor table for the walk;
        //  every cell routes to the pinned grid)
        auto encDie = [](int L, int r) {
            switch (L) {
            case 0: return mm2encdD1Die(r);
            case 1: return mm2encdD2Die(r);
            case 2: return mm2encdD3Die(r);
            case 3: return mm2encdD4Die(r);
            case 4: return mm2encdD5Die(r);
            case 5: return mm2encdD6Die(r);
            case 6: return mm2encdD7Die(r);
            case 7: return mm2encdD8Die(r);
            case 8: return mm2encdD9Die(r);
            case 9: return mm2encdD10Die(r);
            }
            return 0;
        };
        auto encSrc = [](int L, int r) {
            switch (L) {
            case 0: return mm2encdD1Src(r);
            case 1: return mm2encdD2Src(r);
            case 2: return mm2encdD3Src(r);
            case 3: return mm2encdD4Src(r);
            case 4: return mm2encdD5Src(r);
            case 5: return mm2encdD6Src(r);
            case 6: return mm2encdD7Src(r);
            case 7: return mm2encdD8Src(r);
            case 8: return mm2encdD9Src(r);
            case 9: return mm2encdD10Src(r);
            }
            return 0;
        };
        auto encNumMin = [](int L, int r) {
            switch (L) {
            case 0: return mm2encdD1NumMin(r);
            case 1: return mm2encdD2NumMin(r);
            case 2: return mm2encdD3NumMin(r);
            case 3: return mm2encdD4NumMin(r);
            case 4: return mm2encdD5NumMin(r);
            case 5: return mm2encdD6NumMin(r);
            case 6: return mm2encdD7NumMin(r);
            case 7: return mm2encdD8NumMin(r);
            case 8: return mm2encdD9NumMin(r);
            case 9: return mm2encdD10NumMin(r);
            }
            return 0;
        };
        auto encNumMax = [](int L, int r) {
            switch (L) {
            case 0: return mm2encdD1NumMax(r);
            case 1: return mm2encdD2NumMax(r);
            case 2: return mm2encdD3NumMax(r);
            case 3: return mm2encdD4NumMax(r);
            case 4: return mm2encdD5NumMax(r);
            case 5: return mm2encdD6NumMax(r);
            case 6: return mm2encdD7NumMax(r);
            case 7: return mm2encdD8NumMax(r);
            case 8: return mm2encdD9NumMax(r);
            case 9: return mm2encdD10NumMax(r);
            }
            return 0;
        };
        auto encSpecial = [](int L, int r) {
            switch (L) {
            case 0: return mm2encdD1Special(r);
            case 1: return mm2encdD2Special(r);
            case 2: return mm2encdD3Special(r);
            case 3: return mm2encdD4Special(r);
            case 4: return mm2encdD5Special(r);
            case 5: return mm2encdD6Special(r);
            case 6: return mm2encdD7Special(r);
            case 7: return mm2encdD8Special(r);
            case 8: return mm2encdD9Special(r);
            case 9: return mm2encdD10Special(r);
            }
            return 0;
        };
        auto encPartyDie = [](int L) {
            switch (L) {
            case 0: return mm2encdPartyDieD1();
            case 1: return mm2encdPartyDieD2();
            case 2: return mm2encdPartyDieD3();
            case 3: return mm2encdPartyDieD4();
            case 4: return mm2encdPartyDieD5();
            case 5: return mm2encdPartyDieD6();
            case 6: return mm2encdPartyDieD7();
            case 7: return mm2encdPartyDieD8();
            case 8: return mm2encdPartyDieD9();
            case 9: return mm2encdPartyDieD10();
            }
            return 0;
        };
        static const char* kEncD[10][19] = {
            {
                "al_miraj",
                "webbird",
                "bullywug",
                "pedipalp_large",
                "bowler",
                "bat_giant",
                "goblin",
                "bandit",
                "bat_ordinary",
                "",
                "orc",
                "giant_rat",
                "kobold",
                "",
                "skeleton",
                "norker",
                "vulchling",
                "gnome",
                "nupperibo",
            },
            {
                "azer",
                "duergar",
                "coffer_corpse",
                "gas_spore",
                "lizard_man",
                "gnoll",
                "land_lamprey",
                "giant_centipede",
                "giant_toad",
                "",
                "troglodyte",
                "centipede_huge",
                "grimlock",
                "stirge",
                "mongrelman",
                "quaggoth",
                "pedipalp_huge",
                "poisonous_frog",
                "fire_bat",
            },
            {
                "leprechaun",
                "mephit_fire",
                "phantom",
                "ankheg",
                "ochre_jelly",
                "kenku",
                "luck_eater",
                "",
                "ogre",
                "boring_beetle",
                "",
                "scorpion_large",
                "bugbear",
                "gelatinous_cube",
                "ustilagor",
                "shocker",
                "giant_weasel",
                "thoqqua",
                "drow",
            },
            {
                "lava_children",
                "meenlock",
                "hook_horror",
                "pech",
                "owlbear",
                "rust_monster",
                "pseudo_undead",
                "",
                "yellow_mold",
                "scorpion_huge",
                "poisonous_toad",
                "gargoyle",
                "hornet_giant",
                "hydra",
                "ghast",
                "caterwaul",
                "solifugid_giant",
                "spectator",
                "githyanki",
            },
            {
                "chaggrin",
                "cloaker",
                "algoid",
                "phycomid",
                "minotaur",
                "",
                "giant_lizard",
                "cave_bear",
                "",
                "cockatrice",
                "giant_spider",
                "verbeeg",
                "hydra",
                "snake_poisonous",
                "margoyle",
                "rock_reptile",
                "doppelganger",
                "solifugid_giant",
                "hydra",
            },
            {
                "drider",
                "rakshasa",
                "green_slime",
                "basilisk",
                "grell",
                "otyugh",
                "wyvern",
                "wraith",
                "wight",
                "",
                "pseudo_undead",
                "carrion_crawler",
                "giant_scorpion",
                "troll",
                "",
                "black_dragon",
                "ogre_magi",
                "yuan_ti",
                "red_slaad",
            },
            {
                "dao",
                "basilisk_greater",
                "umber_hulk",
                "mimic",
                "chimera",
                "lurker_above",
                "frost_giant",
                "",
                "black_pudding",
                "hill_giant",
                "will_o_wisp",
                "giant_slug",
                "pseudo_undead",
                "sundew_giant",
                "mummy",
                "spectre",
                "invisible_stalker",
                "diakk",
                "mezzodaemon",
            },
            {
                "foo_lion",
                "xag_ya_xeg_yi",
                "chasme",
                "aurumvorax",
                "vampire",
                "pudding_brown",
                "alu_demon",
                "",
                "hydra",
                "pseudo_undead",
                "rust_monster",
                "will_o_wisp",
                "trapper",
                "",
                "purple_worm",
                "ghost",
                "black_dragon",
                "xag_ya_xeg_yi",
                "charonadaemon",
            },
            {
                "",
                "monadic_deva",
                "pit_fiend",
                "red_dragon",
                "hydra",
                "slaad_grey",
                "titan",
                "",
                "movanic_deva",
                "thessalhydra",
                "vampire",
                "stone_golem",
                "black_dragon",
                "kelubar",
                "nycadaemon",
                "titan",
                "baku",
                "ultrodaemon",
                "demilich",
            },
            {
                "",
                "",
                "quarton",
                "tarrasque",
                "red_dragon",
                "blue_dragon",
                "solar",
                "iron_golem",
                "planetar",
                "slaad_death",
                "beholder",
                "",
                "lich",
                "vampire",
                "cloud_dragon",
                "quinton",
                "titan",
                "charonadaemon",
                "",
            },
        };
        for (int L = 0; L < 10; ++L) {
            int party = 0;
            for (int r = 0; r < 19; ++r) {
                if (encDie(L, r) != r + 2)
                    ++bad;
                if (encSpecial(L, r) == 1) {
                    ++party;
                    if (encDie(L, r) != encPartyDie(L))
                        ++bad;
                    if (encSrc(L, r) != 0
                        || encNumMin(L, r) != 0
                        || encNumMax(L, r) != 0)
                        ++bad;
                }
                if (encSpecial(L, r) == 2) {
                    if (L != 9) ++bad;
                    if (encNumMin(L, r) != 0
                        || encNumMax(L, r) != 0)
                        ++bad;
                }
                if (encSpecial(L, r) == 0) {
                    if (encNumMin(L, r) < 1)
                        ++bad;
                    if (encNumMax(L, r)
                        < encNumMin(L, r))
                        ++bad;
                    if (encSrc(L, r) == 0)
                        ++bad;
                }
                const char* k = kEncD[L][r];
                if (k[0] != 0) {
                    const auto* d = reg.find(k);
                    if (!d) ++bad;
                }
            }
            if (party != 1) ++bad;
        }
        if (!reg.find("fire_giant")) ++bad;
        if ((int)reg.all().size()
            < mm2encdRegistryFloor())
            ++bad;
        printf("R816 MM2 dungeon encounter grids: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r817_mm2_outdoor_encounter.h"  // R835: migrated
    // ---- R817: the MM2 outdoor encounter grids walk ----
    // The 36 terrain grids cross-checked live:
    // the die contiguity 2-20, the Character
    // Party rows per grid (the cold civilized
    // desert grid carries two, dies 7 and 14), the
    // Castle/Fortress structure rows, the Patrol
    // men rows, and the registry key for every
    // walkable row (the MM1 and MM2 defs).
    {
        using namespace rules;
        int bad = 0;
        // (the grid/row accessor set for the walk;
        //  every cell routes to the pinned grid)
        auto encDie = [](int G, int r) {
            switch (G) {
            case 0: return mm2encoCW1Die(r);
            case 1: return mm2encoCW2Die(r);
            case 2: return mm2encoCW3Die(r);
            case 3: return mm2encoCW4Die(r);
            case 4: return mm2encoCW5Die(r);
            case 5: return mm2encoCW6Die(r);
            case 6: return mm2encoCC1Die(r);
            case 7: return mm2encoCC2Die(r);
            case 8: return mm2encoCC3Die(r);
            case 9: return mm2encoCC4Die(r);
            case 10: return mm2encoCC5Die(r);
            case 11: return mm2encoCC6Die(r);
            case 12: return mm2encoTW1Die(r);
            case 13: return mm2encoTW2Die(r);
            case 14: return mm2encoTW3Die(r);
            case 15: return mm2encoTW4Die(r);
            case 16: return mm2encoTW5Die(r);
            case 17: return mm2encoTW6Die(r);
            case 18: return mm2encoTC1Die(r);
            case 19: return mm2encoTC2Die(r);
            case 20: return mm2encoTC3Die(r);
            case 21: return mm2encoTC4Die(r);
            case 22: return mm2encoTC5Die(r);
            case 23: return mm2encoTC6Die(r);
            case 24: return mm2encoRW1Die(r);
            case 25: return mm2encoRW2Die(r);
            case 26: return mm2encoRW3Die(r);
            case 27: return mm2encoRW4Die(r);
            case 28: return mm2encoRW5Die(r);
            case 29: return mm2encoRW6Die(r);
            case 30: return mm2encoRC1Die(r);
            case 31: return mm2encoRC2Die(r);
            case 32: return mm2encoRC3Die(r);
            case 33: return mm2encoRC4Die(r);
            case 34: return mm2encoRC5Die(r);
            case 35: return mm2encoRC6Die(r);
            }
            return 0;
        };
        auto encSrc = [](int G, int r) {
            switch (G) {
            case 0: return mm2encoCW1Src(r);
            case 1: return mm2encoCW2Src(r);
            case 2: return mm2encoCW3Src(r);
            case 3: return mm2encoCW4Src(r);
            case 4: return mm2encoCW5Src(r);
            case 5: return mm2encoCW6Src(r);
            case 6: return mm2encoCC1Src(r);
            case 7: return mm2encoCC2Src(r);
            case 8: return mm2encoCC3Src(r);
            case 9: return mm2encoCC4Src(r);
            case 10: return mm2encoCC5Src(r);
            case 11: return mm2encoCC6Src(r);
            case 12: return mm2encoTW1Src(r);
            case 13: return mm2encoTW2Src(r);
            case 14: return mm2encoTW3Src(r);
            case 15: return mm2encoTW4Src(r);
            case 16: return mm2encoTW5Src(r);
            case 17: return mm2encoTW6Src(r);
            case 18: return mm2encoTC1Src(r);
            case 19: return mm2encoTC2Src(r);
            case 20: return mm2encoTC3Src(r);
            case 21: return mm2encoTC4Src(r);
            case 22: return mm2encoTC5Src(r);
            case 23: return mm2encoTC6Src(r);
            case 24: return mm2encoRW1Src(r);
            case 25: return mm2encoRW2Src(r);
            case 26: return mm2encoRW3Src(r);
            case 27: return mm2encoRW4Src(r);
            case 28: return mm2encoRW5Src(r);
            case 29: return mm2encoRW6Src(r);
            case 30: return mm2encoRC1Src(r);
            case 31: return mm2encoRC2Src(r);
            case 32: return mm2encoRC3Src(r);
            case 33: return mm2encoRC4Src(r);
            case 34: return mm2encoRC5Src(r);
            case 35: return mm2encoRC6Src(r);
            }
            return 0;
        };
        auto encSpecial = [](int G, int r) {
            switch (G) {
            case 0: return mm2encoCW1Special(r);
            case 1: return mm2encoCW2Special(r);
            case 2: return mm2encoCW3Special(r);
            case 3: return mm2encoCW4Special(r);
            case 4: return mm2encoCW5Special(r);
            case 5: return mm2encoCW6Special(r);
            case 6: return mm2encoCC1Special(r);
            case 7: return mm2encoCC2Special(r);
            case 8: return mm2encoCC3Special(r);
            case 9: return mm2encoCC4Special(r);
            case 10: return mm2encoCC5Special(r);
            case 11: return mm2encoCC6Special(r);
            case 12: return mm2encoTW1Special(r);
            case 13: return mm2encoTW2Special(r);
            case 14: return mm2encoTW3Special(r);
            case 15: return mm2encoTW4Special(r);
            case 16: return mm2encoTW5Special(r);
            case 17: return mm2encoTW6Special(r);
            case 18: return mm2encoTC1Special(r);
            case 19: return mm2encoTC2Special(r);
            case 20: return mm2encoTC3Special(r);
            case 21: return mm2encoTC4Special(r);
            case 22: return mm2encoTC5Special(r);
            case 23: return mm2encoTC6Special(r);
            case 24: return mm2encoRW1Special(r);
            case 25: return mm2encoRW2Special(r);
            case 26: return mm2encoRW3Special(r);
            case 27: return mm2encoRW4Special(r);
            case 28: return mm2encoRW5Special(r);
            case 29: return mm2encoRW6Special(r);
            case 30: return mm2encoRC1Special(r);
            case 31: return mm2encoRC2Special(r);
            case 32: return mm2encoRC3Special(r);
            case 33: return mm2encoRC4Special(r);
            case 34: return mm2encoRC5Special(r);
            case 35: return mm2encoRC6Special(r);
            }
            return 0;
        };
        static const char* kEncO[36][19] = {
            {  // grid 0, the cold wilderness mountains
                "",
                "hoar_fox",
                "galeb_duh",
                "ice_toad",
                "werebear",
                "white_dragon",
                "wolverine",
                "dwarf",
                "woolly_rhinoceros",
                "mammoth",
                "raven_ordinary",
                "ogre",
                "mountain_lion",
                "hill_giant",
                "frost_giant",
                "",
                "taer",
                "yeti",
                "red_dragon",
            },
            {  // grid 1, the cold wilderness hills and rough terrain
                "winter_wolf",
                "giant_owl",
                "badger",
                "",
                "bear_northern",
                "ice_troll",
                "mammoth",
                "hill_giant",
                "herd_animal",
                "wolf",
                "orc",
                "dwarf",
                "cave_bear",
                "poisonous_snake",
                "wild_boar",
                "giant_wolverine",
                "irish_deer",
                "remorhaz",
                "grugach",
            },
            {  // grid 2, the cold wilderness forest
                "frost_giant",
                "forlarren",
                "treant_mature_middle_aged",
                "pudding_white",
                "bear_northern",
                "giant_porcupine",
                "bugbear",
                "wolf",
                "ogre",
                "orc",
                "wild_dog",
                "werewolf",
                "manticore",
                "white_dragon",
                "baluchitherium",
                "ogrillon",
                "grim",
                "korred",
                "foxwoman",
            },
            {  // grid 3, the cold wilderness swamp and marsh
                "ice_troll",
                "winter_wolf",
                "dire_wolf",
                "tiger",
                "crystal_ooze",
                "pseudo_undead",
                "hydra",
                "wild_dog",
                "orc",
                "quaggoth",
                "ogre",
                "giant_rat",
                "volt",
                "herd_animal",
                "irish_deer",
                "moon_dog",
                "white_dragon",
                "giant_owl",
                "willow_black",
            },
            {  // grid 4, the cold wilderness plains and scrub
                "gorgon",
                "yeth_hound",
                "ice_troll",
                "dervish",
                "hill_giant",
                "poisonous_snake",
                "bandit",
                "mammoth",
                "mastodon",
                "herd_animal",
                "ogre",
                "camel_bactrian",
                "dervish",
                "white_dragon",
                "devil_dog",
                "wolf",
                "wolfwere",
                "giant_lynx",
                "remorhaz",
            },
            {  // grid 5, the cold wilderness desert
                "gold_dragon",
                "hobgoblin",
                "rock_reptile",
                "sandling",
                "hoar_fox",
                "dervish",
                "scorpion_huge",
                "wild_dog",
                "camel_bactrian",
                "herd_animal",
                "scorpion_large",
                "raven_ordinary",
                "tiger",
                "raven_giant",
                "wolf",
                "devil_dog",
                "bugbear",
                "gambado",
                "succubus",
            },
            {  // grid 6, the cold civilized mountains
                "denzelian",
                "xorn",
                "aarakocra",
                "berserker",
                "quaggoth",
                "goblin",
                "bugbear",
                "bandit",
                "",
                "",
                "dwarf",
                "falcon_small",
                "hobgoblin",
                "pilgrim",
                "merchant",
                "minotaur",
                "",
                "dire_wolf",
                "vampire",
            },
            {  // grid 7, the cold civilized hills and rough terrain
                "vampire",
                "ice_toad",
                "snyad",
                "dire_wolf",
                "berserker",
                "pseudo_undead",
                "hobgoblin",
                "bandit",
                "",
                "",
                "merchant",
                "dwarf",
                "mammoth",
                "bat_ordinary",
                "halfling",
                "goblin",
                "gnome",
                "bugbear",
                "xaren",
            },
            {  // grid 8, the cold civilized forest
                "shedu",
                "groaning_spirit",
                "",
                "werebear",
                "hobgoblin",
                "bat_ordinary",
                "bugbear",
                "",
                "wild_boar",
                "wolf",
                "ogre",
                "bandit",
                "elf",
                "",
                "goblin",
                "shadow",
                "norker",
                "bookworm",
                "shadow_mastiff",
            },
            {  // grid 9, the cold civilized swamp and marsh
                "alu_demon",
                "poltergeist",
                "luck_eater",
                "berserker",
                "giant_crab",
                "hobgoblin",
                "",
                "giant_centipede",
                "rat_ordinary",
                "bandit",
                "ogre",
                "",
                "ghoul",
                "pseudo_undead",
                "ghast",
                "penanggalan",
                "coffer_corpse",
                "bugbear",
                "varrdig",
            },
            {  // grid 10, the cold civilized plains and scrub
                "disenchanter",
                "hollyphant",
                "li_lung",
                "dire_wolf",
                "quaggoth",
                "osquip",
                "owl",
                "bandit",
                "",
                "merchant",
                "ogre",
                "wolf",
                "bugbear",
                "",
                "werewolf",
                "goblin",
                "dervish",
                "wererat",
                "luck_changer",
            },
            {  // grid 11, the cold civilized desert
                "shedu",
                "vortex",
                "gold_dragon",
                "falcon_large",
                "dire_wolf",
                "",
                "pilgrim",
                "merchant",
                "bandit",
                "goblin",
                "raven_ordinary",
                "camel_bactrian",
                "",
                "wolf",
                "dervish",
                "berserker",
                "griffon",
                "crypt_thing",
                "movanic_deva",
            },
            {  // grid 12, the temperate wilderness mountains
                "cave_fisher",
                "gorgimera",
                "red_dragon",
                "spotted_lion",
                "bat_mobat",
                "stone_giant",
                "blood_hawk",
                "vulture_ordinary",
                "large_spider",
                "dwarf",
                "bat_ordinary",
                "orc",
                "mountain_lion",
                "cockatrice",
                "black_bear",
                "caveman",
                "chimera",
                "khargra",
                "galeb_duh",
            },
            {  // grid 13, the temperate wilderness hills and rough terrain
                "gorgon",
                "displacer_beast",
                "ant_lion",
                "bee_bumblebee",
                "harpy",
                "verbeeg",
                "scorpion_large",
                "hill_giant",
                "wolf",
                "orc",
                "ogre",
                "werewolf",
                "tiger",
                "huge_spider",
                "giant_mantis",
                "aspis_drone",
                "hybsil",
                "vulture_giant",
                "manticore",
            },
            {  // grid 14, the temperate wilderness forest
                "beetle_death_watch",
                "grugach",
                "atomie",
                "bee_worker",
                "green_dragon",
                "giant_boar",
                "kobold",
                "warthog",
                "rhinoceros",
                "giant_centipede",
                "black_bear",
                "stag_beetle",
                "giant_porcupine",
                "clubnek",
                "owlbear",
                "kech",
                "greenhag",
                "elfin_cat",
                "basilisk_greater",
            },
            {  // grid 15, the temperate wilderness swamp and marsh
                "algoid",
                "mist_dragon",
                "troll",
                "shambling_mound",
                "phycomid",
                "poisonous_toad",
                "giant_lizard",
                "giant_toad",
                "vulture_ordinary",
                "large_spider",
                "crocodile",
                "orc",
                "wyvern",
                "basidirond",
                "caterwaul",
                "eblis",
                "pseudo_undead",
                "giant_crayfish",
                "beholder",
            },
            {  // grid 16, the temperate wilderness plains and scrub
                "ascomoid",
                "firbolg",
                "xvart",
                "troll",
                "tiger_fly",
                "kenku",
                "lion",
                "wild_boar",
                "wild_cattle",
                "wolf",
                "jackal",
                "scorpion_huge",
                "shadow_mastiff",
                "titanotherium",
                "bee_bumblebee",
                "blink_dog",
                "gnoll",
                "yeth_hound",
                "bulette",
            },
            {  // grid 17, the temperate wilderness desert
                "fire_giant",
                "dune_stalker",
                "lammasu",
                "purple_worm",
                "fly_horsefly",
                "giant_scorpion",
                "dustdigger",
                "camel_bactrian",
                "large_spider",
                "jackal",
                "vulture_ordinary",
                "scorpion_large",
                "ogre",
                "poisonous_snake",
                "ant_lion",
                "dervish",
                "thunderherder",
                "lamia",
                "wind_walker",
            },
            {  // grid 18, the temperate civilized mountains
                "dragonnel",
                "giant_spider",
                "minotaur",
                "ghoul",
                "li_lung",
                "gnoll",
                "bugbear",
                "bandit",
                "",
                "dwarf",
                "ogre",
                "large_spider",
                "goblin",
                "",
                "norker",
                "phase_spider",
                "vampire",
                "rakshasa",
                "ki_rin",
            },
            {  // grid 19, the temperate civilized hills and rough terrain
                "hollyphant",
                "obliviax",
                "scarecrow",
                "snyad",
                "fire_beetle",
                "basilisk",
                "killmoulis",
                "bandit",
                "werewolf",
                "merchant",
                "",
                "wolf",
                "gnoll",
                "hobgoblin",
                "jackal",
                "pedipalp_large",
                "dire_wolf",
                "jackalwere",
                "huecuva",
            },
            {  // grid 20, the temperate civilized forest
                "vampire",
                "bulette",
                "centipede_megalo",
                "ankheg",
                "berserker",
                "troll",
                "leprechaun",
                "stag_beetle",
                "bull",
                "bandit",
                "large_spider",
                "",
                "",
                "pilgrim",
                "thessalhydra",
                "giant_spider",
                "bar_lgura",
                "norker",
                "shedu",
            },
            {  // grid 21, the temperate civilized swamp and marsh
                "kelpie",
                "giant_crayfish",
                "goblin",
                "poisonous_frog",
                "wild_boar",
                "wererat",
                "",
                "bandit",
                "rat_ordinary",
                "giant_centipede",
                "vulture_ordinary",
                "giant_spider",
                "vulture_giant",
                "basilisk",
                "berserker",
                "crane_giant",
                "giant_crab",
                "mud_man",
                "zygom",
            },
            {  // grid 22, the temperate civilized plains and scrub
                "lammasu_greater",
                "ghost",
                "wererat",
                "",
                "ankheg",
                "owl",
                "pilgrim",
                "bandit",
                "wild_cattle",
                "merchant",
                "falcon_small",
                "",
                "",
                "bugbear",
                "halfling",
                "dervish",
                "goblin",
                "oliphant",
                "quasi_elemental_lightning",
            },
            {  // grid 23, the temperate civilized desert
                "copper_dragon",
                "hell_hound",
                "bat_ordinary",
                "goblin",
                "dervish",
                "lion",
                "",
                "bandit",
                "merchant",
                "huge_spider",
                "camel_bactrian",
                "jackal",
                "pilgrim",
                "osquip",
                "falcon_large",
                "pedipalp_large",
                "vortex",
                "griffon",
                "type_i_vrock",
            },
            {  // grid 24, the tropical wilderness mountains
                "aarakocra",
                "black_dragon",
                "wind_walker",
                "red_dragon",
                "caveman",
                "copper_dragon",
                "bugbear",
                "large_spider",
                "",
                "wild_dog",
                "bat_ordinary",
                "ogre",
                "fire_giant",
                "manticore",
                "firedrake",
                "storm_giant",
                "pyrolisk",
                "ogre_magi",
                "chaggrin",
            },
            {  // grid 25, the tropical wilderness hills and rough terrain
                "zorbo",
                "hangman_tree",
                "firenewt",
                "bee_bumblebee",
                "giant_ant",
                "witherweed",
                "kenku",
                "wild_cattle",
                "hill_giant",
                "werewolf",
                "large_spider",
                "wolf",
                "basilisk",
                "scorpion_large",
                "hyena",
                "hieracosphinx",
                "assassin_bug",
                "axe_beak",
                "vilstrak",
            },
            {  // grid 26, the tropical wilderness forest
                "green_dragon",
                "bloodthorn",
                "grippli",
                "ettercap",
                "baluchitherium",
                "ophidian",
                "kobold",
                "baboon",
                "warthog",
                "flightless_bird",
                "elephant_african",
                "ogre",
                "rhinoceros_beetle",
                "jaguar",
                "basidirond",
                "buckawn",
                "foresters_bane",
                "choke_creeper",
                "stegocentipede",
            },
            {  // grid 27, the tropical wilderness swamp and marsh
                "basilisk_greater",
                "crabman",
                "shambling_mound",
                "mongrelman",
                "muckdweller",
                "basilisk",
                "meazel",
                "giant_centipede",
                "scorpion_large",
                "huge_spider",
                "giant_toad",
                "rat_ordinary",
                "sundew_giant",
                "troll",
                "caterwaul",
                "cifal",
                "giant_dragonfly",
                "guardian_naga",
                "black_dragon",
            },
            {  // grid 28, the tropical wilderness plains and scrub
                "ascomoid",
                "cockatrice",
                "wyvern",
                "thri_kreen",
                "hybsil",
                "dakon",
                "owl",
                "baboon",
                "wild_boar",
                "wild_cattle",
                "ogre",
                "scorpion_large",
                "dervish",
                "ghoul",
                "cheetah",
                "axe_beak",
                "hill_giant",
                "blue_dragon",
                "movanic_deva",
            },
            {  // grid 29, the tropical wilderness desert
                "fire_giant",
                "boalisk",
                "gynosphinx",
                "sandman",
                "pudding_dun",
                "kenku",
                "flightless_bird",
                "camel_dromedary",
                "hyena",
                "jackal",
                "giant_scorpion",
                "large_spider",
                "dustdigger",
                "scorpion_large",
                "ant_lion",
                "moon_dog",
                "dune_stalker",
                "formian_worker",
                "jann",
            },
            {  // grid 30, the tropical civilized mountains
                "xaren",
                "",
                "lammasu",
                "norker",
                "quaggoth",
                "",
                "bugbear",
                "bandit",
                "bat_ordinary",
                "ogre",
                "vulture_ordinary",
                "large_spider",
                "",
                "pilgrim",
                "dwarf",
                "li_lung",
                "rothe",
                "wererat",
                "hell_hound",
            },
            {  // grid 31, the tropical civilized hills and rough terrain
                "penanggalan",
                "wereboar",
                "fire_beetle",
                "wild_boar",
                "falcon_large",
                "pilgrim",
                "pseudo_undead",
                "wild_cattle",
                "dwarf",
                "werewolf",
                "",
                "merchant",
                "",
                "hobgoblin",
                "oliphant",
                "pedipalp_huge",
                "shedu",
                "rakshasa",
                "lammasu_greater",
            },
            {  // grid 32, the tropical civilized forest
                "shadow_demon",
                "amphisbaena_snake",
                "goblin",
                "hobgoblin",
                "wild_cattle",
                "merchant",
                "stirge",
                "bandit",
                "elephant",
                "herd_animal",
                "",
                "bull",
                "",
                "elf",
                "shadow",
                "jackal",
                "halfling",
                "centipede_megalo",
                "revenant",
            },
            {  // grid 33, the tropical civilized swamp and marsh
                "haunt",
                "giant_crayfish",
                "mud_man",
                "poisonous_frog",
                "",
                "lion",
                "crane_giant",
                "bandit",
                "giant_centipede",
                "rat_ordinary",
                "huge_spider",
                "giant_toad",
                "wererat",
                "ghoul",
                "rat_vapor",
                "zombie_juju",
                "skeleton_animal",
                "vampire",
                "shade",
            },
            {  // grid 34, the tropical civilized plains and scrub
                "luck_changer",
                "zygom",
                "amphisbaena_snake",
                "jackalwere",
                "ankheg",
                "lion",
                "",
                "bandit",
                "",
                "merchant",
                "herd_animal",
                "jackal",
                "pilgrim",
                "poisonous_snake",
                "troll",
                "shedu",
                "basilisk",
                "disenchanter",
                "gold_dragon",
            },
            {  // grid 35, the tropical civilized desert
                "thunderherder",
                "griffon",
                "vortex",
                "jermlaine",
                "dervish",
                "constrictor_snake",
                "",
                "bandit",
                "merchant",
                "jackal",
                "camel_dromedary",
                "vulture_ordinary",
                "osquip",
                "poisonous_snake",
                "berserker",
                "constrictor_snake",
                "weretiger",
                "jann",
                "succubus",
            },
        };
        // (the expected Character Party row count
        //  per grid; the 0 grids carry none)
        static const int kEncPartyRows[36] = {
            0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0,
            0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0,
            1, 1,
        };
        int partyAll = 0;
        int partyGrids = 0;
        int structure = 0;
        int patrol = 0;
        int unres = 0;
        for (int G = 0; G < 36; ++G) {
            int party = 0;
            for (int r = 0; r < 19; ++r) {
                if (encDie(G, r) != r + 2)
                    ++bad;
                if (encSpecial(G, r) == 1) {
                    ++party;
                    if (encSrc(G, r) != 0)
                        ++bad;
                } else if (encSpecial(G, r) == 2) {
                    ++structure;
                    if (encSrc(G, r) != 0)
                        ++bad;
                } else if (encSpecial(G, r) == 3) {
                    ++patrol;
                    if (encSrc(G, r) != 0)
                        ++bad;
                } else {
                    if (encSrc(G, r) == 0) {
                        ++unres;
                    }
                    const char* k = kEncO[G][r];
                    if (k[0] != 0) {
                        const auto* d = reg.find(k);
                        if (!d) ++bad;
                    }
                }
            }
            if (party != kEncPartyRows[G]) ++bad;
            partyAll += party;
            if (party > 0) ++partyGrids;
        }
        if (partyAll != mm2encoCharacterPartyRows())
            ++bad;
        if (partyGrids != mm2encoGridsWithPartyRow())
            ++bad;
        if (structure != mm2encoStructureRows())
            ++bad;
        if (patrol != mm2encoPatrolRows())
            ++bad;
        if (unres != mm2encoUnresolvedRows())
            ++bad;
        // (the cold civilized desert grid, index 11,
        //  carries the two party rows at dies 7/14)
        if (encDie(11, 5) != 7
            || encDie(11, 12) != 14
            || encSpecial(11, 5) != 1
            || encSpecial(11, 12) != 1)
            ++bad;
        if (!reg.find("dervish")) ++bad;
        if ((int)reg.all().size()
            < mm2encoRegistryFloor())
            ++bad;
        printf("R817 MM2 outdoor encounter grids: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r818_mm2_aquatic_encounter_gr.h"  // R833: migrated
    // ---- R818: the MM2 aquatic encounter grids walk ----
    // The 12 surface and depths grids cross-checked
    // live: the die contiguity 2-20, the hazard rows
    // (ice, whirlpool, island, ghost ship, sunken ship,
    // seaweed), the pointer rows (the surface and land
    // reroutes), the lung dragon cross-refs, and the
    // registry key for every walkable row (the MM1 and
    // MM2 defs).
    {
        using namespace rules;
        int bad = 0;
        // (the grid/row accessor set for the walk;
        //  every cell routes to the pinned grid)
        auto encDie = [](int G, int r) {
            switch (G) {
            case 0: return mm2encaCFSDie(r);
            case 1: return mm2encaCFDDie(r);
            case 2: return mm2encaCSSDie(r);
            case 3: return mm2encaCSDDie(r);
            case 4: return mm2encaTFSDie(r);
            case 5: return mm2encaTFDDie(r);
            case 6: return mm2encaTSSDie(r);
            case 7: return mm2encaTSDDie(r);
            case 8: return mm2encaRFSDie(r);
            case 9: return mm2encaRFDDie(r);
            case 10: return mm2encaRSSDie(r);
            case 11: return mm2encaRSDDie(r);
            }
            return 0;
        };
        auto encSrc = [](int G, int r) {
            switch (G) {
            case 0: return mm2encaCFSSrc(r);
            case 1: return mm2encaCFDSrc(r);
            case 2: return mm2encaCSSSrc(r);
            case 3: return mm2encaCSDSrc(r);
            case 4: return mm2encaTFSSrc(r);
            case 5: return mm2encaTFDSrc(r);
            case 6: return mm2encaTSSSrc(r);
            case 7: return mm2encaTSDSrc(r);
            case 8: return mm2encaRFSSrc(r);
            case 9: return mm2encaRFDSrc(r);
            case 10: return mm2encaRSSSrc(r);
            case 11: return mm2encaRSDSrc(r);
            }
            return 0;
        };
        auto encSpecial = [](int G, int r) {
            switch (G) {
            case 0: return mm2encaCFSSpecial(r);
            case 1: return mm2encaCFDSpecial(r);
            case 2: return mm2encaCSSSpecial(r);
            case 3: return mm2encaCSDSpecial(r);
            case 4: return mm2encaTFSSpecial(r);
            case 5: return mm2encaTFDSpecial(r);
            case 6: return mm2encaTSSSpecial(r);
            case 7: return mm2encaTSDSpecial(r);
            case 8: return mm2encaRFSSpecial(r);
            case 9: return mm2encaRFDSpecial(r);
            case 10: return mm2encaRSSSpecial(r);
            case 11: return mm2encaRSDSpecial(r);
            }
            return 0;
        };
        static const char* kEncA[12][19] = {
            {  // grid 0, the the cold freshwater surface
                "dragon_turtle", "harpy", "greenhag", "water_naga", "ghoul",
                "snapping_turtle", "swan", "", "", "merchant", "",
                "crystal_ooze", "buccaneer", "merrow", "scrag_freshwater",
                "nixie", "falcon_large", "lung_wang",
                "swanmay",
            },
            {  // grid 1, the the cold freshwater depths
                "storm_giant", "verme", "quipper", "vodyanoi", "sirine", "ghoul",
                "gargoyle", "giant_crab", "giant_pike", "otter", "octopus",
                "giant_gar", "merrow", "snapping_turtle", "lamprey",
                "hippocampus", "morkoth", "giant_otter", "nereid",
            },
            {  // grid 2, the the cold saltwater surface
                "wind_walker", "", "white_dragon", "", "narwhale",
                "sea_turtle", "sea_lion", "merchant", "shark", "whale",
                "buccaneer", "", "dolphin", "", "scrag_saltwater",
                "will_o_wisp", "seawolf_greater", "selkie", "dragon_turtle",
            },
            {  // grid 3, the the cold saltwater depths
                "verme", "water_weird", "seawolf_lesser", "urchin_green", "urchin_red", "dolphin",
                "elf", "shark", "giant_crab", "narwhale", "octopus", "whale",
                "sea_lion", "gargoyle", "giant_squid", "octopus",
                "green_slime", "titan", "lung_wang",
            },
            {  // grid 4, the the temperate freshwater surface
                "giant_dragonfly", "carp_giant", "lizard_man",
                "crystal_ooze", "buccaneer", "merrow", "swan", "crocodile",
                "merchant", "throat_leech", "crane_giant", "", "giant_crayfish",
                "giant_frog", "sirine", "giant_otter", "scrag_freshwater",
                "red_dragon", "boobrie",
            },
            {  // grid 5, the the temperate freshwater depths
                "mud_man", "muckdweller", "giant_beaver", "giant_lamprey",
                "lizard_man", "snapping_turtle", "gargoyle", "water_beetle",
                "water_spider", "throat_leech", "crocodile", "giant_otter",
                "giant_crayfish", "lamprey", "carp_giant", "giant_gar",
                "octopus", "algoid", "lizard_man",
            },
            {  // grid 6, the the temperate saltwater surface
                "ki_rin", "cloud_dragon", "", "", "crabman", "giant_eel", "",
                "plesiosaurus", "merchant", "shark", "whale", "",
                "elasmosaurus", "will_o_wisp", "giant_crab", "ghoul",
                "bronze_dragon", "seawolf_greater", "verme",
            },
            {  // grid 7, the the temperate saltwater depths
                "morkoth", "kraken", "narwhale", "giant_lamprey",
                "giant_shark", "sea_lion", "urchin_black", "plesiosaurus", "sea_horse",
                "shark", "whale", "", "masher", "giant_eel", "dragon_turtle",
                "purple_worm", "seawolf_lesser", "eye_of_the_deep", "titan",
            },
            {  // grid 8, the the tropical freshwater surface
                "froghemoth", "couatl", "catfish_giant", "crystal_ooze",
                "mist_dragon", "giant_spider", "giant_crayfish", "merchant",
                "", "crocodile", "throat_leech", "behemoth", "giant_frog",
                "hippopotamus", "sirine", "merman", "manticore", "kelpie", "thork",
            },
            {  // grid 9, the the tropical freshwater depths
                "verme", "weed", "kelpie", "vodyanoi", "behemoth", "merman",
                "snapping_turtle", "water_beetle", "dinichthys",
                "water_spider", "throat_leech", "dragonfish", "archelon_ischyros", "gargoyle", "bunyip",
                "lizard_man", "shen_lung", "sea_hag", "water_weird",
            },
            {  // grid 10, the the tropical saltwater surface
                "wereshark", "seawolf_greater", "roc", "", "sahuagin",
                "portuguese_man_o_war", "sea_hag", "giant_crocodile",
                "plesiosaurus", "merchant", "shark", "whale", "buccaneer",
                "mosasaurus", "", "giant_shark", "androsphinx",
                "ixitxachitl", "triton",
            },
            {  // grid 11, the the tropical saltwater depths
                "morkoth", "urchin_silver", "giant_crocodile", "octopus", "pungi_ray",
                "sahuagin", "urchin_black", "dinichthys", "sting_ray", "shark", "",
                "strangle_weed", "barracuda", "nothosaurus", "electric_eel",
                "triton", "wereshark", "kraken", "ixitxachitl",
            },
        };
        int hazard = 0;
        int pointer = 0;
        int lung = 0;
        int keyed = 0;
        for (int G = 0; G < 12; ++G) {
            for (int r = 0; r < 19; ++r) {
                if (encDie(G, r) != r + 2)
                    ++bad;
                if (encSpecial(G, r) == 4) {
                    ++hazard;
                    if (encSrc(G, r) != 0)
                        ++bad;
                } else if (encSpecial(G, r) == 5) {
                    ++pointer;
                    if (encSrc(G, r) != 0)
                        ++bad;
                } else {
                    const char* k = kEncA[G][r];
                    if (k[0] != 0) {
                        ++keyed;
                        const auto* d = reg.find(k);
                        if (!d) ++bad;
                    } else if (encSrc(G, r) == 0) {
                        ++lung;
                    }
                }
            }
        }
        if (hazard != mm2encaHazardRows())
            ++bad;
        if (pointer != mm2encaPointerRows())
            ++bad;
        if (lung != mm2encaLungDragonRows()
            - lungpCellsRewired())
            ++bad;
        if (keyed != mm2encaWalkKeyRows())
            ++bad;
        // (the cold freshwater surface grid, index 0,
        //  carries the die 9 ice hazard row; the
        //  tropical freshwater surface grid, index 8,
        //  the die 10 land encounter pointer row)
        if (encDie(0, 7) != 9
            || encSpecial(0, 7) != 4
            || encSrc(0, 7) != 0
            || encDie(8, 8) != 10
            || encSpecial(8, 8) != 5
            || encSrc(8, 8) != 0)
            ++bad;
        if (!reg.find("verme")) ++bad;
        if (!reg.find("purple_worm")) ++bad;
        if (!reg.find("scrag_freshwater")) ++bad;
        if (!reg.find("scrag_saltwater")) ++bad;
        if ((int)reg.all().size()
            < mm2encaRegistryFloor())
            ++bad;
        printf("R818 MM2 aquatic encounter grids: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r819_mm2_index_census.h"  // R833: migrated
    // ---- R819: the MM2 index census walk ----
    // The merged index census cross-checked live:
    // the 26 letter rows, the ordinal contiguity
    // 1-26, the per-letter voice arithmetic (the
    // MM1 + FF + this-book columns sum to the
    // total column), the section extremes, and the
    // registry keys for the settled reclass reads
    // (the sirine, leprechaun, rock reptile and
    // scrag lines).
    {
        using namespace rules;
        int bad = 0;
        int mm1 = 0, ff = 0, book = 0, cross = 0;
        int lines = 0;
        int mx = 0, mn = 9999, mmmx = 0, ffmx = 0;
        int bk = 0, crmx = 0;
        for (int r = 0; r < mm2enciLetterCount();
             ++r) {
            if (mm2enciOrdinal(r) != r + 1)
                ++bad;
            if (mm2enciMm1(r) + mm2enciFf(r)
                + mm2enciThisBook(r)
                != mm2enciTotal(r))
                ++bad;
            if (mm2enciCrossRef(r) > mm2enciTotal(r))
                ++bad;
            mm1 += mm2enciMm1(r);
            ff += mm2enciFf(r);
            book += mm2enciThisBook(r);
            cross += mm2enciCrossRef(r);
            lines += mm2enciTotal(r);
            if (mm2enciTotal(r) > mx)
                mx = mm2enciTotal(r);
            if (mm2enciTotal(r) < mn)
                mn = mm2enciTotal(r);
            if (mm2enciMm1(r) > mmmx)
                mmmx = mm2enciMm1(r);
            if (mm2enciFf(r) > ffmx)
                ffmx = mm2enciFf(r);
            if (mm2enciThisBook(r) > bk)
                bk = mm2enciThisBook(r);
            if (mm2enciCrossRef(r) > crmx)
                crmx = mm2enciCrossRef(r);
        }
        if (mm1 != mm2enciMm1Lines()) ++bad;
        if (ff != mm2enciFfLines()) ++bad;
        if (book != mm2enciThisBookLines()) ++bad;
        if (cross != mm2enciCrossRefLines()) ++bad;
        if (lines != mm2enciTotalLines()) ++bad;
        if (mx != mm2enciLargestLetterTotal())
            ++bad;
        if (mn != mm2enciSmallestLetterTotal())
            ++bad;
        if (mmmx != mm2enciMaxMm1Letter()) ++bad;
        if (ffmx != mm2enciMaxFfLetter()) ++bad;
        if (bk != mm2enciMaxThisBookLetter()) ++bad;
        if (crmx != mm2enciLargestCrossRefLetter())
            ++bad;
        // (the per-letter total consts against the
        //  pinned cells, A through Z)
        if (mm2enciTotalA() != mm2enciTotal(0)
            || mm2enciTotalB() != mm2enciTotal(1)
            || mm2enciTotalC() != mm2enciTotal(2)
            || mm2enciTotalD() != mm2enciTotal(3)
            || mm2enciTotalE() != mm2enciTotal(4)
            || mm2enciTotalF() != mm2enciTotal(5)
            || mm2enciTotalG() != mm2enciTotal(6)
            || mm2enciTotalH() != mm2enciTotal(7)
            || mm2enciTotalI() != mm2enciTotal(8)
            || mm2enciTotalJ() != mm2enciTotal(9)
            || mm2enciTotalK() != mm2enciTotal(10)
            || mm2enciTotalL() != mm2enciTotal(11)
            || mm2enciTotalM() != mm2enciTotal(12)
            || mm2enciTotalN() != mm2enciTotal(13)
            || mm2enciTotalO() != mm2enciTotal(14)
            || mm2enciTotalP() != mm2enciTotal(15)
            || mm2enciTotalQ() != mm2enciTotal(16)
            || mm2enciTotalR() != mm2enciTotal(17)
            || mm2enciTotalS() != mm2enciTotal(18)
            || mm2enciTotalT() != mm2enciTotal(19)
            || mm2enciTotalU() != mm2enciTotal(20)
            || mm2enciTotalV() != mm2enciTotal(21)
            || mm2enciTotalW() != mm2enciTotal(22)
            || mm2enciTotalX() != mm2enciTotal(23)
            || mm2enciTotalY() != mm2enciTotal(24)
            || mm2enciTotalZ() != mm2enciTotal(25))
            ++bad;
        // (spot reads: the S row carries the 180
        //  total and the 64 MM1, 52 FF, 64 this-book
        //  lines; the X and Y rows carry no
        //  cross-references)
        if (mm2enciTotal(18) != 180
            || mm2enciMm1(18) != 64
            || mm2enciFf(18) != 52
            || mm2enciThisBook(18) != 64
            || mm2enciCrossRef(23) != 0
            || mm2enciCrossRef(24) != 0)
            ++bad;
        if (!reg.find("sirine")) ++bad;
        if (!reg.find("leprechaun")) ++bad;
        if (!reg.find("rock_reptile")) ++bad;
        if (!reg.find("scrag_saltwater")) ++bad;
        if (!reg.find("verme")) ++bad;
        if ((int)reg.all().size()
            < mm2enciRegistryFloor())
            ++bad;
        printf("R819 MM2 index census: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r820_lammasu_promotion.h"  // R833: migrated
    // ---- R820: the lammasu promotion walk ----
    // The promoted Lammasu, Greater def
    // cross-checked live against the registry:
    // every stat cell of the p. 79 block, the
    // mm2_print xp source, the xpValue formula,
    // the two rewired outdoor cells (src 2, the
    // walk-key census 570 -> 572), and the
    // registry census 809 -> 810.
    {
        using namespace rules;
        int bad = 0;
        const auto* d = reg.find("lammasu_greater");
        if (!d) { ++bad; }
        else {
            if (d->armorClass != lmpStatArmorClass())
                ++bad;
            if (d->hitDiceNum != lmpStatHitDice())
                ++bad;
            if (d->hitDiceBonus != lmpStatHitDiceBonus())
                ++bad;
            if (d->avgHp != lmpStatAvgHp()) ++bad;
            if (d->attacks != lmpStatNumAttacks())
                ++bad;
            if (d->magicResist != lmpStatMagicResistance())
                ++bad;
            if (d->xpBase != lmpStatXp()) ++bad;
            if (d->xpPerHp != lmpStatXpPerHp()) ++bad;
            if (d->xpValue != lmpStatXpValue()) ++bad;
            if (d->xpSource != "mm2_print") ++bad;
            if (d->xpValue != d->xpBase
                + d->avgHp * d->xpPerHp) ++bad;
        }
        // (the two rewired cells: the temperate
        //  civilized plains grid 22 die 2 cell and
        //  the tropical civilized hills grid 31
        //  die 20 cell, both src 2)
        if (mm2encoTC5Die(0) != lmpGridTC5Index() - 20
            || mm2encoTC5Src(0) != 2
            || mm2encoRC2Die(18) != 20
            || mm2encoRC2Src(18) != 2)
            ++bad;
        if (mm2encoWalkKeyRows()
            != lmpWalkKeyRowsAfter()) ++bad;
        if (mm2encoLammasuGreaterRows()
            != lmpCellsRewired()) ++bad;
        if (!reg.find("lammasu")) ++bad;
        if ((int)reg.all().size()
            < lmpRegistryAfter())
            ++bad;
        printf("R820 lammasu promotion: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r821_lung_promotion.h"  // R833: migrated
    // ---- R821: the lung promotion walk ----
    // The two promoted FF defs (the lung wang,
    // the shen lung) cross-checked live against
    // the registry: the stat cells of the p. 28
    // and p. 29 blocks, the ff_print xp source,
    // the xpValue formula, the three rewired
    // aquatic cells (src 0, the walk-key census
    // 189 -> 192), and the registry census
    // 810 -> 812.
    {
        using namespace rules;
        int bad = 0;
        const auto* w = reg.find("lung_wang");
        if (!w) { ++bad; }
        else {
            if (w->armorClass
                != lungpWangStatArmorClass())
                ++bad;
            if (w->hitDiceNum
                != lungpWangStatHitDice())
                ++bad;
            if (w->hitDiceBonus != 0) ++bad;
            if (w->avgHp
                != lungpWangStatAvgHp())
                ++bad;
            if (w->attacks
                != lungpWangStatNumAttacks())
                ++bad;
            if (w->xpBase != lungpWangStatXp())
                ++bad;
            if (w->xpPerHp
                != lungpWangStatXpPerHp()) ++bad;
            if (w->xpValue
                != lungpWangStatXpValue()) ++bad;
            if (w->xpSource != "ff_print") ++bad;
            if (w->xpValue != w->xpBase
                + w->avgHp * w->xpPerHp) ++bad;
        }
        const auto* s = reg.find("shen_lung");
        if (!s) { ++bad; }
        else {
            if (s->armorClass
                != lungpShenStatArmorClass())
                ++bad;
            if (s->hitDiceNum
                != lungpShenStatHitDice())
                ++bad;
            if (s->hitDiceBonus != 0) ++bad;
            if (s->avgHp
                != lungpShenStatAvgHp()) ++bad;
            if (s->attacks
                != lungpShenStatNumAttacks())
                ++bad;
            if (s->xpBase != lungpShenStatXp())
                ++bad;
            if (s->xpPerHp
                != lungpShenStatXpPerHp()) ++bad;
            if (s->xpValue
                != lungpShenStatXpValue()) ++bad;
            if (s->xpSource != "ff_print") ++bad;
            if (s->xpValue != s->xpBase
                + s->avgHp * s->xpPerHp) ++bad;
        }
        // (the three rewired cells: the CFS die 19
        //  and CSD die 20 sea dragon cells rekey
        //  lung_wang, the RFD die 18 spirit dragon
        //  cell rekeys shen_lung, all src 0)
        if (mm2encaCFSDie(lungpCellCfsRow()) != 19
            || mm2encaCFSSrc(lungpCellCfsRow())
            != 0
            || mm2encaCSDDie(lungpCellCsdRow()) != 20
            || mm2encaCSDSrc(lungpCellCsdRow())
            != 0
            || mm2encaRFDDie(lungpCellRfdRow()) != 18
            || mm2encaRFDSrc(lungpCellRfdRow())
            != 0)
            ++bad;
        if (mm2encaWalkKeyRows()
            != lungpWalkKeyRowsAfter()) ++bad;
        if (mm2encaLungDragonRows() != 3) ++bad;
        if (!reg.find("chiang_lung")) ++bad;
        if (!reg.find("dragon_turtle")) ++bad;
        if ((int)reg.all().size()
            < lungpRegistryAfter())
            ++bad;
        printf("R821 lung promotion: bad %d\n",
               bad);
        if (bad) return 1;
    }
    #include "rules/audits/r822_audit_files_wiring.h"  // R833: migrated
    // ---- R823 audit migration wiring audit ----
    // the tooling round: no block moves yet - the wiring rides the spec key,
    // the first real moves are the pilot round; the audit checks the wiring
    // constants themselves
    {
        using namespace rules;
        int bad = 0;
    if (migw_frag_gap() != 3
            || migw_head_walk() != 800
            || migw_width() != 78
            || migw_census() != 746
            || migw_blocks_total() != 745
            || migw_min_blocks() != 1
            || migw_anchor_pad() != 4
            || migw_bad_marker() != 1
            || migw_brace_delta() != 0
            || migw_label_len() != 33
            || !migw_frag_required()
            || !migw_verbatim()
            || !migw_no_bare_return()
            || !migw_include_inline()
            || !migw_census_holds()
            || !migw_gates_recheck()
            || !migw_last_wins()
            || !migw_rn_adds()
            || !migw_rverify_counts()
            || !migw_tooling_alone()
        )
            ++bad;
        // the pilot batch plus the floor stays the pilot batch
    if (migw_frag_gap() + migw_min_blocks() != 4
        )
            ++bad;
        // the walk reaches any label in the standing census
    if (migw_head_walk() != migw_blocks_total() + migw_frag_gap() + 52
        )
            ++bad;
        // the marker floor with a flat brace delta
    if (migw_bad_marker() + migw_brace_delta() != 1
        )
            ++bad;
        // the label length matches this round audit label
    if (migw_label_len() != migw_anchor_pad() + 29
        )
            ++bad;
        printf("R823 audit migration wiring audit: bad %d\n", bad);
        if (bad) return 1;
    }
#include "rules/audits/r824_pilot.h"  // R824: R824 pilot migration audit
#include "rules/audits/r825_dmg_batch.h"  // R825: R825 DMG batch audit
#include "rules/audits/r826_dmg_tables_batch.h"  // R826: R826 DMG tables batch audit
#include "rules/audits/r827_subclass_batch.h"  // R827: R827 subclass batch audit
#include "rules/audits/r828_hundred_block_batch.h"  // R828: R828 hundred-block batch audit
#include "rules/audits/r829_ua_wsg_batch.h"  // R829: R829 UA WSG batch audit
#include "rules/audits/r830_wsg_dsg_batch.h"  // R830: R830 WSG DSG batch audit
#include "rules/audits/r831_planes_oa_batch.h"  // R831: R831 planes OA batch audit
#include "rules/audits/r832_oa_tail_batch.h"  // R832: R832 OA tail batch audit
#include "rules/audits/r1026_deity_seam_close.h"  // R1026: R1026 deity seam close audit
#include "rules/audits/r1025_drg_normalization.h"  // R1025: R1025 DRG normalization audit
#include "rules/audits/r1024_wsg_mop_normalization.h"  // R1024: R1024 WSG+MOP normalization audit
#include "rules/audits/r1023_ff_normalization.h"  // R1023: R1023 FF normalization audit
#include "rules/audits/r1022_ff_normalization.h"  // R1022: R1022 FF normalization audit
#include "rules/audits/r1021_ff_normalization.h"  // R1021: R1021 FF normalization audit
#include "rules/audits/r1020_mm2_normalization.h"  // R1020: R1020 MM2 normalization audit
#include "rules/audits/r1019_mm2_normalization.h"  // R1019: R1019 MM2 normalization audit
#include "rules/audits/r1018_mm2_normalization.h"  // R1018: R1018 MM2 normalization audit
#include "rules/audits/r1017_mm2_normalization.h"  // R1017: R1017 MM2 normalization audit
#include "rules/audits/r1016_oa_normalization.h"  // R1016: R1016 OA normalization audit
#include "rules/audits/r1015_oa_table_promotion_batch_nine.h"  // R1015: R1015 OA table promotion batch nine audit
#include "rules/audits/r1014_mm1_normalization_batch_six.h"  // R1014: R1014 MM1 normalization batch six audit
#include "rules/audits/r1013_mm1_normalization_batch_five.h"  // R1013: R1013 MM1 normalization batch five audit
#include "rules/audits/r1012_mm1_normalization_batch_four.h"  // R1012: R1012 MM1 normalization batch four audit
#include "rules/audits/r1011_mm1_normalization_batch_three.h"  // R1011: R1011 MM1 normalization batch three audit
#include "rules/audits/r1010_mm1_normalization_batch_two.h"  // R1010: R1010 MM1 normalization batch two audit
#include "rules/audits/r1009_mm1_normalization_batch_one.h"  // R1009: R1009 MM1 normalization batch one audit
#include "rules/audits/r1008_promotions_mop_round_three.h"  // R1008: R1008 promotions mop round three audit
#include "rules/audits/r1007_promotions_mop_round_two.h"  // R1007: R1007 promotions mop round two audit
#include "rules/audits/r1006_promotions_mop_round_one.h"  // R1006: R1006 promotions mop round one audit
#include "rules/audits/r1005_ua_promotion_batch_seven.h"  // R1005: R1005 UA promotion batch seven audit
#include "rules/audits/r1004_ua_promotion_batch_six.h"  // R1004: R1004 UA promotion batch six audit
#include "rules/audits/r1003_ua_promotion_batch_five.h"  // R1003: R1003 UA promotion batch five audit
#include "rules/audits/r1002_ua_promotion_batch_four.h"  // R1002: R1002 UA promotion batch four audit
#include "rules/audits/r1001_ua_promotion_batch_three.h"  // R1001: R1001 UA promotion batch three audit
#include "rules/audits/r1000_ua_promotion_batch_two.h"  // R1000: R1000 UA promotion batch two audit
#include "rules/audits/r999_ua_promotion_batch_one.h"  // R999: R999 UA promotion batch one audit
#include "rules/audits/r998_dsg_promotion_batch_five.h"  // R998: R998 DSG promotion batch five audit
#include "rules/audits/r997_dsg_promotion_batch_four.h"  // R997: R997 DSG promotion batch four audit
#include "rules/audits/r996_dsg_promotion_batch_three.h"  // R996: R996 DSG promotion batch three audit
#include "rules/audits/r995_dsg_promotion_batch_two.h"  // R995: R995 DSG promotion batch two audit
#include "rules/audits/r994_dsg_promotion_batch_one.h"  // R994: R994 DSG promotion batch one audit
#include "rules/audits/r993_wsg_promotion_batch_five.h"  // R993: R993 WSG promotion batch five audit
#include "rules/audits/r992_wsg_promotion_batch_four.h"  // R992: R992 WSG promotion batch four audit
#include "rules/audits/r991_wsg_promotion_batch_three.h"  // R991: R991 WSG promotion batch three audit
#include "rules/audits/r990_wsg_promotion_batch_two.h"  // R990: R990 WSG promotion batch two audit
#include "rules/audits/r989_wsg_promotion_batch_one.h"  // R989: R989 WSG promotion batch one audit
#include "rules/audits/r988_oa_promotion_batch_eight.h"  // R988: R988 OA promotion batch eight audit
#include "rules/audits/r987_oa_promotion_batch_seven.h"  // R987: R987 OA promotion batch seven audit
#include "rules/audits/r986_oa_promotion_batch_six.h"  // R986: R986 OA promotion batch six audit
#include "rules/audits/r985_oa_promotion_batch_five.h"  // R985: R985 OA promotion batch five audit
#include "rules/audits/r984_oa_promotion_batch_four.h"  // R984: R984 OA promotion batch four audit
#include "rules/audits/r983_oa_promotion_batch_three.h"  // R983: R983 OA promotion batch three audit
#include "rules/audits/r982_oa_promotion_batch_two.h"  // R982: R982 OA promotion batch two audit
#include "rules/audits/r981_oa_promotion_batch_one.h"  // R981: R981 OA promotion batch one audit
#include "rules/audits/r980_dragon_promotion_batch_twelve.h"  // R980: R980 dragon promotion batch twelve audit
#include "rules/audits/r979_dragon_promotion_batch_eleven.h"  // R979: R979 dragon promotion batch eleven audit
#include "rules/audits/r978_dragon_promotion_batch_ten.h"  // R978: R978 dragon promotion batch ten audit
#include "rules/audits/r977_dragon_promotion_batch_nine.h"  // R977: R977 dragon promotion batch nine audit
#include "rules/audits/r976_dragon_promotion_batch_eight.h"  // R976: R976 dragon promotion batch eight audit
#include "rules/audits/r975_dragon_promotion_batch_seven.h"  // R975: R975 dragon promotion batch seven audit
#include "rules/audits/r974_dragon_promotion_batch_six.h"  // R974: R974 dragon promotion batch six audit
#include "rules/audits/r973_dragon_promotion_batch_five.h"  // R973: R973 dragon promotion batch five audit
#include "rules/audits/r972_dragon_promotion_batch_four.h"  // R972: R972 dragon promotion batch four audit
#include "rules/audits/r971_dragon_promotion_batch_three.h"  // R971: R971 dragon promotion batch three audit
#include "rules/audits/r970_dragon_promotion_batch_two.h"  // R970: R970 dragon promotion batch two audit
#include "rules/audits/r969_dragon_promotion_batch_one.h"  // R969: R969 dragon promotion batch one audit
#include "rules/audits/r968_rules_record_format.h"  // R968: R968 rules record format audit
#include "rules/audits/r967_content_tree_creation.h"  // R967: R967 content tree creation audit
#include "rules/audits/r966_content_structure_charter.h"  // R966: R966 content structure charter audit
#include "rules/audits/r965_dragon_issue_26_closure.h"  // R965: R965 Dragon issue-26 closure audit
#include "rules/audits/r964_issue_26_commentary_set.h"  // R964: R964 issue-26 commentary set audit
#include "rules/audits/r963_issue_26_table_round.h"  // R963: R963 issue-26 table round audit
#include "rules/audits/r962_issue_26_opener_set.h"  // R962: R962 issue-26 opener set audit
#include "rules/audits/r961_dragon_issue_25_closure.h"  // R961: R961 Dragon issue-25 closure audit
#include "rules/audits/r960_issue_25_commentary_set.h"  // R960: R960 issue-25 commentary set audit
#include "rules/audits/r959_issue_25_table_round.h"  // R959: R959 issue-25 table round audit
#include "rules/audits/r958_issue_25_opener_set.h"  // R958: R958 issue-25 opener set audit
#include "rules/audits/r957_dragon_issue_24_closure.h"  // R957: R957 Dragon issue-24 closure audit
#include "rules/audits/r956_issue_24_commentary_set.h"  // R956: R956 issue-24 commentary set audit
#include "rules/audits/r955_issue_24_alignment_pantheon.h"  // R955: R955 issue-24 alignment pantheon audit
#include "rules/audits/r954_issue_24_variant_triptych.h"  // R954: R954 issue-24 variant triptych audit
#include "rules/audits/r953_dragon_issue_23_closure.h"  // R953: R953 Dragon issue-23 closure audit
#include "rules/audits/r952_issue_23_commentary_set.h"  // R952: R952 issue-23 commentary set audit
#include "rules/audits/r951_issue_23_lower_planes_generation.h"  // R951: R951 issue-23 Lower Planes generation audit
#include "rules/audits/r950_issue_23_variant_triptych.h"  // R950: R950 issue-23 variant triptych audit
#include "rules/audits/r949_dragon_issue_22_closure.h"  // R949: R949 Dragon issue-22 closure audit
#include "rules/audits/r948_issue_22_commentary_set.h"  // R948: R948 issue-22 commentary set audit
#include "rules/audits/r947_issue_22_sneak_preview.h"  // R947: R947 issue-22 sneak preview audit
#include "rules/audits/r946_issue_22_opener_part_one.h"  // R946: R946 issue-22 opener part one audit
#include "rules/audits/r945_dragon_issue_21_closure.h"  // R945: R945 Dragon issue-21 closure audit
#include "rules/audits/r944_issue_21_opener_part_two.h"  // R944: R944 issue-21 opener part two audit
#include "rules/audits/r943_issue_21_opener_part_one.h"  // R943: R943 issue-21 opener part one audit
#include "rules/audits/r942_dragon_issue_20_closure.h"  // R942: R942 Dragon issue-20 closure audit
#include "rules/audits/r941_issue_20_opener_part_two.h"  // R941: R941 issue-20 opener part two audit
#include "rules/audits/r940_issue_20_opener_part_one.h"  // R940: R940 issue-20 opener part one audit
#include "rules/audits/r939_dragon_issue_19_closure.h"  // R939: R939 Dragon issue-19 closure audit
#include "rules/audits/r938_issue_19_opener_part_two.h"  // R938: R938 issue-19 opener part two audit
#include "rules/audits/r937_issue_19_opener_part_one.h"  // R937: R937 issue-19 opener part one audit
#include "rules/audits/r936_dragon_issue_18_closure.h"  // R936: R936 Dragon issue-18 closure audit
#include "rules/audits/r935_issue_18_opener_part_two.h"  // R935: R935 issue-18 opener part two audit
#include "rules/audits/r934_issue_18_opener_part_one.h"  // R934: R934 issue-18 opener part one audit
#include "rules/audits/r933_dragon_issue_17_closure.h"  // R933: R933 Dragon issue-17 closure audit
#include "rules/audits/r932_issue_17_wizard_article_part_two.h"  // R932: R932 issue-17 wizard article part two audit
#include "rules/audits/r931_issue_17_opener_part_one.h"  // R931: R931 issue-17 opener part one audit
#include "rules/audits/r930_dragon_issue_16_closure.h"  // R930: R930 Dragon issue-16 closure audit
#include "rules/audits/r929_issue_16_opener.h"  // R929: R929 issue-16 opener audit
#include "rules/audits/r928_dragon_issue_15_closure.h"  // R928: R928 Dragon issue-15 closure audit
#include "rules/audits/r927_issue_15_opener.h"  // R927: R927 issue-15 opener audit
#include "rules/audits/r926_dragon_issue_14_closure.h"  // R926: R926 Dragon issue-14 closure audit
#include "rules/audits/r925_issue_14_opener.h"  // R925: R925 issue-14 opener audit
#include "rules/audits/r924_dragon_issue_13_closure.h"  // R924: R924 Dragon issue-13 closure audit
#include "rules/audits/r923_issue_13_opener_part_two.h"  // R923: R923 issue-13 opener part two audit
#include "rules/audits/r922_issue_13_opener.h"  // R922: R922 issue-13 opener audit
#include "rules/audits/r921_dragon_issue_12_closure.h"  // R921: R921 Dragon issue-12 closure audit
#include "rules/audits/r920_issue_12_opener_part_two.h"  // R920: R920 issue-12 opener part two audit
#include "rules/audits/r919_issue_12_opener.h"  // R919: R919 issue-12 opener audit
#include "rules/audits/r918_dragon_issue_11_closure.h"  // R918: R918 Dragon issue-11 closure audit
#include "rules/audits/r917_issue_11_opener.h"  // R917: R917 issue-11 opener audit
#include "rules/audits/r916_dragon_issue_10_closure.h"  // R916: R916 Dragon issue-10 closure audit
#include "rules/audits/r915_issue_10_opener.h"  // R915: R915 issue-10 opener audit
#include "rules/audits/r914_issue_10_opener.h"  // R914: R914 issue-10 opener audit
#include "rules/audits/r913_dragon_issue_9_closure.h"  // R913: R913 Dragon issue-9 closure audit
#include "rules/audits/r912_issue_9_opener.h"  // R912: R912 issue-9 opener audit
#include "rules/audits/r911_dragon_issue_8_closure.h"  // R911: R911 Dragon issue-8 closure audit
#include "rules/audits/r910_issue_8_opener.h"  // R910: R910 issue-8 opener audit
#include "rules/audits/r909_dragon_issue_7_closure.h"  // R909: R909 Dragon issue-7 closure audit
#include "rules/audits/r908_prowler_opener.h"  // R908: R908 Prowler opener audit
#include "rules/audits/r907_dragon_issue_6_closure.h"  // R907: R907 Dragon issue-6 closure audit
#include "rules/audits/r906_issue_6_opener.h"  // R906: R906 issue-6 opener audit
#include "rules/audits/r905_witch_remainders.h"  // R905: R905 witch remainders audit
#include "rules/audits/r904_wilderness_encounter_table.h"  // R904: R904 wilderness encounter table audit
#include "rules/audits/r903_dragon_issue_5_closure.h"  // R903: R903 Dragon issue-5 closure audit
#include "rules/audits/r902_dragon_issue_5.h"  // R902: R902 Dragon issue-5 audit
#include "rules/audits/r901_creature_features_closure.h"  // R901: R901 Creature Features closure audit
#include "rules/audits/r900_dragon_creature_features.h"  // R900: R900 Dragon Creature Features audit
#include "rules/audits/r899_comedy_and_small_variants.h"  // R899: R899 comedy and small-variants audit
#include "rules/audits/r898_character_round.h"  // R898: R898 character round audit
#include "rules/audits/r897_fighting_sub_classes.h"  // R897: R897 fighting sub-classes audit
#include "rules/audits/r896_specialists.h"  // R896: R896 specialists audit
#include "rules/audits/r895_women_magic.h"  // R895: R895 women magic audit
#include "rules/audits/r894_artificer.h"  // R894: R894 Artificer audit
#include "rules/audits/r893_systems.h"  // R893: R893 systems audit
#include "rules/audits/r892_fischer_items.h"  // R892: R892 Fischer items audit
#include "rules/audits/r891_alchemist_class.h"  // R891: R891 Alchemist class audit
#include "rules/audits/r890_remorhaz_lore.h"  // R890: R890 Remorhaz lore audit
#include "rules/audits/r889_aronson_deltas.h"  // R889: R889 Aronson deltas audit
#include "rules/audits/r888_dragon_small_variants.h"  // R888: R888 Dragon small variants audit
#include "rules/audits/r887_ives_attribute.h"  // R887: R887 Ives attribute audit
#include "rules/audits/r886_ddg_promotion.h"  // R886: R886 DDG promotion audit
#include "rules/audits/r885_ddg_promotion.h"  // R885: R885 DDG promotion audit
#include "rules/audits/r884_ddg_promotion.h"  // R884: R884 DDG promotion audit
#include "rules/audits/r883_ddg_promotion.h"  // R883: R883 DDG promotion audit
#include "rules/audits/r882_ddg_promotion.h"  // R882: R882 DDG promotion audit
#include "rules/audits/r881_ddg_promotion.h"  // R881: R881 DDG promotion audit
#include "rules/audits/r880_ddg_promotion.h"  // R880: R880 DDG promotion audit
#include "rules/audits/r879_registry_schema.h"  // R879: R879 registry schema audit
#include "rules/audits/r878_alignment_figures.h"  // R878: R878 alignment figures audit
#include "rules/audits/r877_appendix_4_and_index.h"  // R877: R877 Appendix 4 and index audit
#include "rules/audits/r876_clerical_chart_batch_eight.h"  // R876: R876 clerical chart batch eight audit
#include "rules/audits/r875_clerical_chart_batch_seven.h"  // R875: R875 clerical chart batch seven audit
#include "rules/audits/r874_clerical_chart_batch_six.h"  // R874: R874 clerical chart batch six audit
#include "rules/audits/r873_clerical_chart_batch_five.h"  // R873: R873 clerical chart batch five audit
#include "rules/audits/r872_clerical_chart_batch_four.h"  // R872: R872 clerical chart batch four audit
#include "rules/audits/r871_clerical_chart_batch_three.h"  // R871: R871 clerical chart batch three audit
#include "rules/audits/r870_clerical_chart_batch_two.h"  // R870: R870 clerical chart batch two audit
#include "rules/audits/r869_clerical_chart_batch_one.h"  // R869: R869 clerical chart batch one audit
#include "rules/audits/r868_temple_trappings.h"  // R868: R868 temple trappings audit
#include "rules/audits/r867_known_planes.h"  // R867: R867 known planes audit
#include "rules/audits/r866_sumerian_mythos.h"  // R866: R866 Sumerian mythos audit
#include "rules/audits/r865_norse_mythos.h"  // R865: R865 Norse mythos audit
#include "rules/audits/r864_nonhumans_deities.h"  // R864: R864 nonhumans' deities audit
#include "rules/audits/r863_nehwon_mythos.h"  // R863: R863 Nehwon mythos audit
#include "rules/audits/r862_melnibonean_mythos.h"  // R862: R862 Melnibonean mythos audit
#include "rules/audits/r861_japanese_mythos.h"  // R861: R861 Japanese mythos audit
#include "rules/audits/r860_indian_mythos.h"  // R860: R860 Indian mythos audit
#include "rules/audits/r859_greek_mythos.h"  // R859: R859 Greek mythos audit
#include "rules/audits/r858_finnish_mythos.h"  // R858: R858 Finnish mythos audit
#include "rules/audits/r857_egyptian_mythos.h"  // R857: R857 Egyptian mythos audit
#include "rules/audits/r856_cthulhu_mythos.h"  // R856: R856 Cthulhu mythos audit
#include "rules/audits/r855_chinese_mythos.h"  // R855: R855 Chinese mythos audit
#include "rules/audits/r854_central_american_mythos.h"  // R854: R854 Central American mythos audit
#include "rules/audits/r853_celtic_mythos.h"  // R853: R853 Celtic mythos audit
#include "rules/audits/r852_babylonian_mythos.h"  // R852: R852 Babylonian mythos audit
#include "rules/audits/r851_arthurian_mythos.h"  // R851: R851 Arthurian mythos audit
#include "rules/audits/r850_american_indian_mythos.h"  // R850: R850 American Indian mythos audit
#include "rules/audits/r849_ddg_front_matter.h"  // R849: R849 DDG front matter audit
#include "rules/audits/r848_ff_magic_item_tables.h"  // R848: R848 FF magic item tables audit
#include "rules/audits/r847_ff_encounter_listings.h"  // R847: R847 FF encounter listings audit
#include "rules/audits/r846_ff_monster_level_tables.h"  // R846: R846 FF monster level tables audit
#include "rules/audits/r845_eighth_ff_promotion.h"  // R845: R845 eighth FF promotion audit
#include "rules/audits/r844_seventh_ff_promotion.h"  // R844: R844 seventh FF promotion audit
#include "rules/audits/r843_sixth_ff_promotion.h"  // R843: R843 sixth FF promotion audit
#include "rules/audits/r842_fifth_ff_promotion.h"  // R842: R842 fifth FF promotion audit
#include "rules/audits/r841_ff_index_line_walk.h"  // R841: R841 FF index line walk audit
#include "rules/audits/r840_hornet_promotion.h"  // R840: R840 hornet promotion audit
#include "rules/audits/r839_fourth_ff_promotion.h"  // R839: R839 fourth FF promotion audit
#include "rules/audits/r838_third_ff_promotion.h"  // R838: R838 third FF promotion audit
#include "rules/audits/r837_second_ff_promotion.h"  // R837: R837 second FF promotion audit
#include "rules/audits/r836_first_ff_promotion.h"  // R836: R836 first FF promotion audit
#include "rules/audits/r835_final_holdback_batch.h"  // R835: R835 final holdback batch audit
#include "rules/audits/r834_holdback_tooling_patch.h"  // R834: R834 holdback tooling patch audit
#include "rules/audits/r833_final_digest_batch.h"  // R833: R833 final digest batch audit
    #include "rules/audits/r227_wis_mental_save_wiring.h"  // R833: migrated
    #include "rules/audits/r228_druid_registry_parameter.h"  // R833: migrated
    #include "rules/audits/r229_illusionist_registry_par.h"  // R833: migrated
    #include "rules/audits/r163_poison_table.h"  // R833: migrated
    #include "rules/audits/r164_assassination_table.h"  // R833: migrated
    #include "rules/audits/r165_potion_miscibility.h"  // R833: migrated
    #include "rules/audits/r166_intoxication_and_insanit.h"  // R833: migrated
    #include "rules/audits/r167_disease_and_infestation.h"  // R833: migrated
    #include "rules/audits/r168_underwater_spell_use.h"  // R835: migrated
    #include "rules/audits/r169_humanoid_racial.h"  // R835: migrated
    #include "rules/audits/r170_followers_by_class.h"  // R835: migrated
    #include "rules/audits/r172_appendix_j_herbs.h"  // R835: migrated
    return 0;
            }
