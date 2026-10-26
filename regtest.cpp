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
#include "rules/combat.h"
#include "rules/saves.h"
#include "spells/spells.h"
#include "abilities/abilities.h"
#include "rules/races.h"   // R154: pp.15-18 Race Tables I-III
#include "rules/grenade.h"  // R157: pp.64-65 grenade-like missiles
#include "rules/weaponspeed.h"  // R158: p.66 weapon speed factors
#include "rules/subdue.h"  // R159: p.67 striking to subdue
#include "rules/weaponless.h"  // R160: pp.72-73 weaponless combat
#include "rules/twoweapon.h"  // R161: p.70 attacks with two weapons
#include "rules/poison.h"  // R163: p.20 the poison table
#include "rules/assassinate.h"  // R164: p.75 the assassination table
#include "rules/miscibility.h"  // R165: p.119 potion miscibility
#include "rules/insanity.h"  // R166: pp.82-83 intoxication and insanity
#include "rules/psionics.h"  // R404: the psionics seam
#include "rules/disease.h"  // R167: pp.13-14 disease and parasitic infestation
#include "rules/uwspells.h"  // R168: p.57 underwater spell use
#include "rules/aerial.h"  // R321: pp.49-53 aerial combat
#include "rules/comeliness.h"  // R322: UA comeliness pins
#include "rules/subraces.h"  // R323: UA subrace layer
#include "rules/subracelevels.h"  // R324: UA Race Table II
#include "rules/subracecap.h"  // R325: UA Race Table II fold
#include "rules/classtables.h"  // R327: UA Classes Tables I-II
#include "rules/cavalier.h"  // R328: the UA cavalier
#include "rules/paladin.h"  // R329: the paladin reparent
#include "rules/hierophant.h"  // R330: the UA druid hierophant
#include "rules/weaponspec.h"  // R331: the UA weapon spec
#include "rules/barbarian.h"  // R332: the UA barbarian
#include "rules/uaranger.h"  // R333: the UA ranger expansion
#include "rules/thiefarmor.h"  // R334: the UA thief armor and attacks
#include "rules/acrobat.h"  // R335: the UA thief-acrobat
#include "rules/cavmoney.h"  // R336: the UA cavalier money
#include "rules/uaweapontable.h"  // R337: the UA weight and damage
#include "rules/uamissile.h"  // R338: the UA hurled and missile data
#include "rules/uaprof.h"  // R339: the UA weapon proficiency
#include "rules/uanewweapons.h"  // R340: the UA new weapons prose
#include "rules/uaspelltables.h"  // R341: the UA spell tables part 1
#include "rules/uaspelltables2.h"  // R342: the UA MU and illusionist tables
#include "rules/uaclericspells1.h"  // R343: the UA new cleric 1st level
#include "rules/uaclericspells2.h"  // R344: the UA new cleric 2nd level
#include "rules/uaclericspells3.h"  // R345: the UA new cleric 3rd level
#include "rules/uaclericspells4.h"  // R346: the UA new cleric 4th level
#include "rules/uaclericspells5.h"  // R347: the UA new cleric 5th level
#include "rules/uaclericspells6.h"  // R348: the UA new cleric 6th level
#include "rules/uaclericspells7.h"  // R349: the UA new cleric 7th level
#include "rules/uadruidspells1.h"  // R350: the UA new druid 1st level
#include "rules/uadruidspells2.h"  // R351: the UA new druid 2nd level
#include "rules/uadruidspells3.h"  // R352: the UA new druid 3rd level
#include "rules/uadruidspells5.h"  // R353: the UA new druid 5th level
#include "rules/uadruidspells6.h"  // R354: the UA new druid 6th level
#include "rules/uadruidspells7.h"  // R355: the UA new druid 7th level
#include "rules/uamuspells1.h"  // R356: the UA new magic-user 1st level
#include "rules/uamuspells2.h"  // R357: the UA new magic-user 2nd level
#include "rules/uamuspells3.h"  // R358: the UA new magic-user 3rd level
#include "rules/uamuspells4.h"  // R359: the UA new magic-user 4th level
#include "rules/uamuspells5.h"  // R360: the UA new magic-user 5th level
#include "rules/uamuspells6.h"  // R360: the UA new magic-user 6th level
#include "rules/uamuspells7.h"  // R361: the UA new magic-user 7th level
#include "rules/uamuspells8.h"  // R362: the UA new magic-user 8th level
#include "rules/uamuspells9.h"  // R362: the UA new magic-user 9th level
#include "rules/uailcantrips.h"  // R363: the UA new illusionist cantrips
#include "rules/uailspells1.h"  // R363: the UA new illusionist 1st level
#include "rules/uailspells2.h"  // R363: the UA new illusionist 2nd level
#include "rules/uailspells3.h"  // R364: the UA new illusionist 3rd level
#include "rules/uailspells4.h"  // R364: the UA new illusionist 4th level
#include "rules/uailspells5.h"  // R364: the UA new illusionist 5th level
#include "rules/uailspells6.h"  // R365: the UA new illusionist 6th level
#include "rules/uailspells7.h"  // R365: the UA new illusionist 7th level
#include "rules/uailacquisition.h"  // R365: the UA illusionist acquisition
#include "rules/uaspellcost.h"  // R365: the UA spell casting cost
#include "rules/uaspellbooks.h"  // R366: the UA spell books
#include "rules/uaspellcomment.h"  // R366: the UA spell commentary
#include "rules/uauwspelluse.h"  // R366: the UA underwater spells
#include "rules/uadarkness.h"  // R366: the UA effects of darkness
#include "rules/uasocialclass.h"  // R367: the UA social class
#include "rules/uabirth.h"  // R367: the UA circumstances of birth
#include "rules/uacavtable.h"  // R368: the UA Cavaliers Table I
#include "rules/uacantacq.h"  // R369: the UA cantrip acquisition
#include "rules/uasmalls1.h"  // R370: the UA DM-section smalls
#include "rules/uaarmor.h"  // R371: the UA expanded armor
#include "rules/uafollowers.h"  // R372: the UA cavalier followers
#include "rules/uacomnote.h"  // R373: the UA comeliness note
#include "rules/uatreasuredial.h"  // R374: the UA treasure dial
#include "rules/uadetskel.h"  // R375: the UA determination skeleton
#include "rules/uadetrows.h"  // R395: the UA determination row bodies
#include "rules/uapotprose.h"  // R376: the UA new potions prose
#include "rules/uaprotscr.h"  // R377: the UA new scrolls prose
#include "rules/uaringprose.h"  // R378: the UA new rings prose
#include "rules/uarodstave.h"  // R379: the UA new rods staves prose
#include "rules/uawandprose.h"  // R380: the UA new wands prose
#include "rules/uamiscprose1.h"  // R381: the UA misc magic prose 1
#include "rules/uamiscprose2.h"  // R382: the UA misc magic prose 2
#include "rules/uamiscprose3.h"  // R383: the UA misc magic prose 3
#include "rules/uamiscprose4.h"  // R384: the UA misc magic prose 4
#include "rules/uamiscprose5.h"  // R385: the UA misc magic prose 5
#include "rules/uamiscprose6.h"  // R386: the UA misc magic prose 6
#include "rules/uaarmprose.h"  // R387: the UA armor prose
#include "rules/uamweapprose.h"  // R388: the UA misc weapons prose
#include "rules/uaappendq.h"  // R389: the UA weaponless combat
#include "rules/uaappendr.h"  // R390: the UA non-lethal combat
#include "rules/uaappendt.h"  // R391: the UA pole-arm nomenclature
#include "rules/uaequip26.h"  // R392: the UA equipment costs
#include "rules/uaac26.h"  // R408: the UA p. 26 AC table
#include "rules/uahandheld.h"  // R392: the UA hand-held data
#include "rules/cantriptier.h"  // R401: the UA cantrip tier
#include "rules/uacantrips1.h"  // R412: the UA useful cantrips
#include "rules/uacantrips2.h"  // R413: the UA reversed cantrips
#include "rules/uacantrips3.h"  // R414: the UA legerdemain cantrips
#include "rules/uacantrips4.h"  // R415: the UA person-affecting cantrips
#include "rules/uacantrips5.h"  // R416: the UA personal cantrips
#include "rules/uacantrips6.h"  // R417: the UA haunting-sound cantrips
#include "rules/humrpref.h"  // R169: p.106 humanoid racial preferences
#include "rules/deities.h"  // R405: the deity layer seam
#include "rules/uaappends.h"  // R406: the UA Appendix S stat blocks
#include "rules/uasstatlines.h"  // R409: the UA Appendix S stat lines
#include "rules/uasclasslines.h"  // R410: the UA Appendix S class lines
#include "rules/uamoves.h"  // R411: the UA Appendix S MOVE values
#include "rules/uapantheon.h"  // R423: the UA Appendix S pantheon prose
#include "rules/wsgprof.h"  // R425: the WSG wilderness proficiencies
#include "rules/wsgdress.h"  // R426: the WSG dressing for the weather
#include "rules/wsgenvfx.h"  // R427: the WSG environment effects
#include "rules/wsgsplwx.h"  // R429: the WSG special weather tables
#include "rules/wsgheat.h"  // R430: the WSG heat and cold damage tables
#include "rules/wsgequip.h"  // R431: the WSG effects on equipment
#include "rules/wsgencum.h"  // R432: the WSG encumbrance and movement
#include "rules/wsganimal.h"  // R433: the WSG land-based animals
#include "rules/wsgvehicle.h"  // R434: the WSG land-based vehicles
#include "rules/wsgclimb.h"  // R435: the WSG climbing
#include "rules/wsgcheck.h"  // R436: the WSG climbing checks
#include "rules/wsgfall.h"  // R437: the WSG damage from falling
#include "rules/wsgtumble.h"  // R438: the WSG tumbling damage
#include "rules/wsgstop.h"  // R439: the WSG stopping a fall
#include "rules/wsgrope.h"  // R440: the WSG rope use
#include "rules/wsgtog.h"  // R441: the WSG roping together
#include "rules/wsgrapp.h"  // R442: the WSG rappelling
#include "rules/wsgbelay.h"  // R443: the WSG belaying
#include "rules/wsggrap.h"  // R444: the WSG grappling hooks
#include "rules/wsgchasm.h"  // R445: the WSG chasm crossing
#include "rules/wsgmntnr.h"  // R446: the WSG mountaineering proficiency
#include "rules/wsgslip.h"  // R447: the WSG slippery surface movement
#include "rules/wsgjump.h"  // R448: the WSG jumping rules
#include "rules/wsgvis.h"  // R449: the WSG movement in reduced visibility
#include "rules/wsgswim.h"  // R450: the WSG swimming rules
#include "rules/wsgmwater.h"  // R451: the WSG other effects of moving water
#include "rules/wsgdive.h"  // R452: the WSG diving and surfacing
#include "rules/wsgtread.h"  // R453: the WSG treading water
#include "rules/wsgbreath.h"  // R454: the WSG holding one breath
#include "rules/wsgvessels.h"  // R455: the WSG movement in waterborne vehicles
#include "rules/wsgcapsizing.h"  // R456: the WSG capsizing and damage to craft
#include "rules/wsgboat.h"  // R457: the WSG boating proficiency
#include "rules/wsgportage.h"  // R458: the WSG portaging
#include "rules/wsgcapsized.h"  // R459: the WSG use of a capsized vessel
#include "rules/wsgflymounts.h"  // R460: the WSG flying mounts
#include "rules/wsgfallair.h"  // R461: the WSG airborne fall chance
#include "rules/wsgfood.h"  // R462: the WSG going without food and water
#include "rules/wsgforage.h"  // R463: the WSG food gathering, foraging and Table 30
#include "rules/wsghunt.h"  // R464: the WSG hunting, stalking and Table 31
#include "rules/wsgfish.h"  // R465: the WSG hunting proficiency, fishing and Table 32
#include "rules/wsgcarry.h"  // R466: the WSG consuming and carrying food and Table 33
#include "rules/wsgwater.h"  // R467: the WSG finding water and Table 34
#include "rules/wsgwhere.h"  // R468: the WSG where water is found
#include "rules/wsgdesert.h"  // R469: the WSG water in the desert and permafrost
#include "rules/wsgpurify.h"  // R470: the WSG purifying water and tainted water
#include "rules/wsgshelter.h"  // R471: the WSG natural shelters and Table 35
#include "rules/wsgtents.h"  // R472: the WSG portable shelters and Table 36
#include "rules/wsgsleep.h"  // R473: the WSG shelter mechanics, rest and sleep, and Table 37
#include "rules/wsgfire.h"  // R474: the WSG rest quality, armor timing and campfires, and Table 38
#include "rules/wsgfuel.h"  // R475: the WSG fuel availability and fire safety, and Table 39
#include "rules/wsgblaze.h"  // R476: the WSG uncontrollable fires, and the fire discipline and extinguishing rules
#include "rules/wsgdmg.h"  // R477: the WSG damage from fire, and the firebreak and heat rules
#include "rules/wsgmed.h"  // R478: the WSG medicinal plants, and the Table 40 grids
#include "rules/wsglore.h"  // R479: the WSG plant lore proficiency prose
#include "rules/wsginj.h"  // R480: the WSG injuries and treatment rules
#include "rules/wsgfae.h"  // R481: the WSG first aid equipment gear rules
#include "rules/wsgnvis.h"  // R482: the WSG normal vision definition and range rules
#include "rules/wsginfra.h"  // R483: the WSG infravision and Table 41 range rules
#include "rules/wsgultra.h"  // R484: the WSG ultravision and infravision effectiveness rules
#include "rules/wsglight.h"  // R485: the WSG artificial illumination light-source rules
#include "rules/wsghazd.h"  // R486: the WSG volcano, earthquake and tidal wave hazard rules
#include "rules/wsghazd2.h"  // R487: the WSG flood, avalanche, mudslide and quicksand hazard rules
#include "rules/wsgfight.h"  // R488: the WSG wilderness combat rules
#include "rules/wsgfatig.h"  // R489: the WSG fatigue and exhaustion rules
#include "rules/wsgmount.h"  // R490: the WSG mounts and beasts of burden rules
#include "rules/wsgmagic.h"  // R491: the WSG magic in the wilderness rules
#include "rules/wsgdm.h"  // R492: the WSG Dungeon Master section rules
#include "rules/wsgweather.h"  // R493: the WSG World of Weather generation rules
#include "rules/wsgweathx.h"  // R494: the WSG World of Weather special weather and optional rules
#include "rules/wsgtables.h"  // R495: R495: the WSG compiled tables manifest
#include "rules/wsgrecon.h"  // R496: the WSG gap reconciliation bookkeeping
#include "rules/wsgoverview.h"  // R497: the WSG overview chapter pins
#include "rules/wsgprofd.h"  // R498: the WSG proficiencies prose pins
#include "rules/wsgtempfold.h"  // R499: the WSG temperature-chain fold pins
#include "rules/wsgswimfold.h"  // R500: the WSG swimmer's motion-chain fold pins
#include "rules/wsgmovefold.h"  // R501: the WSG movement/fall-chain fold pins
#include "rules/wsgcampfold.h"  // R502: the WSG camp-chain fold pins
#include "rules/dsgoverview.h"  // R503: the DSG overview pins
#include "rules/dsgmove.h"  // R504: the DSG movement I pins
#include "rules/dsgmove2.h"  // R505: the DSG movement II pins
#include "rules/dsgprof.h"  // R506: the DSG proficiencies pins
#include "rules/dsgfight.h"  // R507: the DSG combat pins
#include "rules/dsgbatt.h"  // R508: the DSG battlesystem pins
#include "rules/dsgair.h"  // R509: the DSG air and gases pins
#include "rules/dsgodor.h"  // R510: the DSG odor detection pins
#include "rules/dsgcavein.h"  // R511: the DSG cave-in causes pins
#include "rules/dsgcavein2.h"  // R512: the DSG chain reaction pins
#include "rules/dsgdpv.h"  // R513: the DSG DPV and hypothermia pins
#include "rules/dsglode.h"  // R514: the DSG lodestone and NPC reaction pins
#include "rules/dsgdecay.h"  // R516: the DSG structural decay pins
#include "rules/dsgwater.h"  // R517: the DSG underground waterways pins
#include "rules/dsgboat.h"  // R518: the DSG underground water travel pins
#include "rules/dsgmine.h"  // R519: the DSG mining where-to-mine and types pins
#include "rules/dsgmine2.h"  // R520: the DSG mining excavation veins and shoring pins
#include "rules/dsgmine3.h"  // R521: the DSG mining products pins
#include "rules/dsgmine4.h"  // R522: the DSG mine product quality pins
#include "rules/dsgmine5.h"  // R523: the DSG mining tail pins
#include "rules/dsgmine6.h"  // R524: the DSG hireling loyalty and hazards pins
#include "rules/dsgequip.h"  // R525: the DSG equipment costs pins
#include "rules/dsgequip2.h"  // R526: the DSG equipment descriptions pins
#include "rules/dsgequip3.h"  // R527: the DSG proficiency descriptions pins
#include "rules/dsgplay.h"  // R528: the DSG improving-play opener pins
#include "rules/dsgplay2.h"  // R529: the DSG improving-play tail pins
#include "rules/dsgenv.h"  // R530: the DSG underground environment pins
#include "rules/dsggeo.h"  // R531: the DSG underground geography and theories pins
#include "rules/dsgcult.h"  // R532: the DSG cultures of the underdark pins
#include "rules/dsgland.h"  // R533: the DSG lands of Deepearth opener pins
#include "rules/dsgarea1.h"  // R534: the DSG Deepearth areas 1-3 pins
#include "rules/dsgarea2.h"  // R535: the DSG Deepearth areas 4-5 pins
#include "rules/dsgarea3.h"  // R536: the DSG Deepearth areas 6-7 pins
#include "rules/dsgarea4.h"  // R537: the DSG Deepearth areas 8-9 pins
#include "rules/dsgarea5.h"  // R538: the DSG Deepearth areas 10-11 pins
#include "rules/dsgarea6.h"  // R539: the DSG Deepearth areas 12-13 pins
#include "rules/dsgarea7.h"  // R540: the DSG Deepearth areas 14-15 pins
#include "rules/dsgarea8.h"  // R541: the DSG Deepearth areas 16-17 pins
#include "rules/dsgarea9.h"  // R542: the DSG Deepearth areas 18-19 pins
#include "rules/dsgarea10.h"  // R543: the DSG Deepearth areas 20-21 pins
#include "rules/dsgarea11.h"  // R544: the DSG Deepearth areas 22-23 pins
#include "rules/dsgarea12.h"  // R545: the DSG Deepearth areas 24-25 pins
#include "rules/dsgarea13.h"  // R546: the DSG Deepearth areas 26-27 pins
#include "rules/dsgarea14.h"  // R547: the DSG Deepearth areas 28-29 pins
#include "rules/dsgarea15.h"  // R548: the DSG Deepearth areas 30-31 pins
#include "rules/dsgdeep.h"  // R549: the DSG Deepearth closure
#include "rules/dsgcamp.h"  // R550: the DSG campaign opener pins
#include "rules/dsgcamp2.h"  // R551: the DSG worlds of adventure pins
#include "rules/dsgcamp3.h"  // R552: the DSG plot and counterplot pins
#include "rules/dsgcamp4.h"  // R553: the DSG story elements tail pins
#include "rules/dsgcamp5.h"  // R554: the DSG techniques of story and campaign design pins
#include "rules/dsgcamp6.h"  // R555: the DSG help from the players pins
#include "rules/dsgcamp7.h"  // R556: the DSG campaign considerations closure
#include "rules/dsgmap.h"  // R557: the DSG mapping your settings pins
#include "rules/dsgtabs.h"  // R558: the DSG compiled tables pins
#include "rules/dsgplate.h"  // R559: the DSG perspective map plates closure
#include "rules/dsgindex.h"  // R560: the DSG index roster pins
#include "rules/dsgdmsec.h"  // R561: the DSG DM section parent closure
#include "rules/dsgintro.h"  // R562: the DSG what-is-it front matter pins
#include "rules/dsgfin.h"  // R563: the DSG arc final census closure
#include "rules/motpintro.h"  // R564: the MotP introduction opener pins
#include "rules/motpspell.h"  // R565: the MotP spell summary pins
#include "rules/motpeth.h"  // R566: the MotP Ethereal chapter pins
#include "rules/motpinner.h"  // R567: the MotP inner planes doctrine pins
#include "rules/motpair.h"  // R568: the MotP Air plane pins
#include "rules/motpfire.h"  // R569: the MotP Fire plane pins
#include "rules/motpearth.h"  // R570: the MotP Earth plane pins
#include "rules/motpwater.h"  // R571: the MotP Water plane pins
#include "rules/motppara.h"  // R572: the MotP para-planes pins
#include "rules/motpenergy.h"  // R573: the MotP energy planes pins
#include "rules/motpquasipos.h"  // R574: the MotP positive quasi-planes pins
#include "rules/motpquasineg.h"  // R575: the MotP negative quasi-planes pins
#include "rules/astralplane.h"  // R576: the Astral Plane pins
#include "rules/outerplanes.h"  // R577: the outer planes general pins
#include "rules/nirvanaarcadia.h"  // R578: the Nirvana and Arcadia pins
#include "rules/heavenstwins.h"  // R579: the Seven Heavens and Twin Paradises pins
#include "rules/elysiumbeasts.h"  // R580: the Elysium and Beastlands pins
#include "rules/olympusgladsheim.h"  // R581: the Olympus and Gladsheim pins
#include "rules/limbopandemonium.h"  // R582: the Limbo and Pandemonium pins
#include "rules/abyss.h"  // R583: the Abyss pins
#include "rules/tarterus.h"  // R584: the Tarterus pins
#include "rules/hades.h"  // R585: the Hades pins
#include "rules/gehenna.h"  // R586: the Gehenna pins
#include "rules/ninehells.h"  // R587: the Nine Hells pins
#include "rules/acheron.h"  // R588: the Acheron pins
#include "rules/concordantopposition.h"  // R589: the Concordant Opposition pins
#include "rules/beyondouterplanes.h"  // R590: the Beyond the outer planes pins
#include "rules/outerplanesseal.h"  // R591: the Outer Planes chapter seal pins
#include "rules/appendixiprimes.h"  // R592: the Appendix I Prime Material Planes pins
#include "rules/appendixiiinnercreatures.h"  // R593: the Appendix II inner creatures pins
#include "rules/appendixiiioutercreatures.h"  // R594: the Appendix III outer creatures pins
#include "rules/appendixivabilitiespowers.h"  // R595: the Appendix IV Powers abilities pins
#include "rules/indices.h"  // R596: the Indices closing pins
#include "rules/motpethcyclone.h"  // R598: the MotP Ether cyclone pins
#include "rules/dmomaxims.h"  // R599: the DMO arc opener pins
#include "rules/dmocampaign.h"  // R600: the DMO maxim-doctrine pins
#include "rules/dmoadventures.h"  // R601: the DMO adventure-doctrine pins
#include "rules/dmoworlds.h"  // R602: the DMO world-rating pins
#include "rules/dmomonsters.h"  // R603: the DMO monster-doctrine pins
#include "rules/dmospells.h"  // R604: the DMO spells-and-items pins
#include "rules/dmoitems.h"  // R605: the DMO item-creation pins
#include "rules/dmoduels.h"  // R606: the DMO magical-duels pins
#include "rules/dmodweomers.h"  // R607: the DMO true-dweomer pins
#include "rules/dmohighlevel.h"  // R608: the DMO high-level save pins
#include "rules/dmohighskills.h"  // R609: the DMO high-level skills pins
#include "rules/dmohighwizpri.h"  // R610: the DMO wizard and priest pins
#include "rules/dmohighrogues.h"  // R611: the DMO rogue pins
#include "rules/dmohighascend.h"  // R612: the DMO demihuman and ascension pins
#include "rules/dmoduelroster.h"  // R613: the DMO spell dueling roster pins
#include "rules/oacreating.h"  // R614: the OA arc opener pins
#include "rules/oaabilities.h"  // R615: the OA ability tables pins
#include "rules/oaabilityprose.h"  // R616: the OA ability prose pins
#include "rules/oaclasscombos.h"  // R617: the OA class combos pins
#include "rules/oaraces.h"  // R618: the OA races pins
#include "rules/oabarbbushi.h"  // R619: the OA barbarian and bushi pins
#include "rules/oakensai.h"  // R620: the OA kensai pins
#include "rules/oamonk.h"  // R621: the OA monk pins
#include "rules/oaninja.h"  // R622: the OA ninja pins
#include "rules/oasamurai.h"  // R623: the OA samurai pins
#include "rules/oashukenja.h"  // R624: the OA shukenja pins
#include "rules/oasohei.h"  // R625: the OA sohei pins
#include "rules/oawujen.h"  // R626: the OA wu jen pins
#include "rules/oayakuza.h"  // R627: the OA yakuza pins
#include "rules/oacharab.h"  // R628: the OA character abilities pins
#include "rules/oabirth.h"  // R629: the OA families pins
#include "rules/oafamstr.h"  // R630: the OA family structures pins
#include "rules/oaanc.h"  // R631: the OA ancestry pins
#include "rules/oahold.h"  // R632: the OA holdings pins
#include "rules/oabr.h"  // R633: the OA birthrights pins
#include "rules/oahonor.h"  // R634: the OA honor pins
#include "rules/oaeff.h"  // R635: the OA effects of honor pins
#include "rules/oamoney.h"  // R636: the OA money pins
#include "rules/oastart.h"  // R637: the OA starting money pins
#include "rules/oaexch.h"  // R638: the OA exchange pins
#include "rules/oaequip.h"  // R639: the OA equipment pins
#include "rules/oaweapon.h"  // R640: the OA weapons pins
#include "rules/oahandheld.h"  // R641: the OA hand-held pins
#include "rules/oahurled.h"  // R642: the OA hurled pins
#include "rules/oaarmor.h"  // R643: the OA armor pins
#include "rules/oapiece.h"  // R644: the OA piece armor pins
#include "rules/oaencumb.h"  // R645: the OA armor encumbrance pins
#include "rules/oabarding.h"  // R646: the OA barding pins
#include "rules/oagrenade.h"  // R647: the OA grenades pins
#include "rules/oabardprose.h"  // R648: the OA barding prose pins
#include "rules/oaarmordesc.h"  // R649: the OA armor descriptions pins
#include "rules/oaweaponspec.h"  // R650: the OA weapon specialization pins
#include "rules/oamslspec.h"  // R651: the OA missile specializations pins
#include "rules/oanwprof.h"  // R652: the OA non-weapon proficiency pins
#include "rules/oacharprof.h"  // R653: the OA character proficiencies pins
#include "rules/oaartprof.h"  // R654: the OA artisan proficiencies pins
#include "rules/oabarbprof.h"  // R655: the OA barbarian proficiencies pins
#include "rules/oacomprof.h"  // R656: the OA common proficiencies pins
#include "rules/oacourtprof.h"  // R657: the OA court proficiencies pins
#include "rules/oashkspells.h"  // R658: the OA shukenja spell list pins
#include "rules/oal1spells.h"  // R659: the OA first level spells pins
#include "rules/oal2spells.h"  // R660: the OA second level spells pins
#include "rules/oal3spells.h"  // R661: the OA third level spells pins
#include "rules/oal4spells.h"  // R662: the OA fourth level spells pins
#include "rules/oal5spells.h"  // R663: the OA fifth level spells pins
#include "rules/oal6spells.h"  // R664: the OA sixth level spells pins
#include "rules/oal7spells.h"  // R665: the OA seventh level spells pins
#include "rules/oat63divination.h"  // R666: the OA divination results pins
#include "rules/oat64speakdead.h"  // R667: the OA speak with dead pins
#include "rules/oat65fate.h"  // R668: the OA fate pins
#include "rules/oawjspelllist.h"  // R669: the OA wu jen spell list pins
#include "rules/oawjl1spells.h"  // R670: the OA wu jen first level spells pins
#include "rules/oawjl2spells.h"  // R671: the OA wu jen second level spells pins
#include "rules/oawjl3spells.h"  // R672: the OA wu jen third level spells pins
#include "rules/oawjl4spells.h"  // R673: the OA wu jen fourth level spells pins
#include "rules/oawjl5spells.h"  // R674: the OA wu jen fifth level spells pins
#include "rules/oawjl6spells.h"  // R675: the OA wu jen sixth level spells pins
#include "rules/oawjl7spells.h"  // R676: the OA wu jen seventh level spells pins
#include "rules/oawjl8spells.h"  // R677: the OA wu jen eighth level spells pins
#include "rules/oawjl9spells.h"  // R678: the OA wu jen ninth level spells pins
#include "rules/oacombatseq.h"  // R679: the OA combat sequence pins
#include "rules/oaiaijutsu.h"  // R680: the OA iaijutsu surprise pins
#include "rules/oainitmods.h"  // R681: the OA initiative modifiers pins
#include "rules/oahorsefire.h"  // R682: the OA mounted bowfire pins
#include "rules/oa67bowfire.h"  // R683: the OA Table 67 bowfire modifier pins
#include "rules/oaunhorsing.h"  // R684: the OA unhorsing pins
#include "rules/oadisarming.h"  // R685: the OA disarming pins
#include "rules/oasubdual.h"  // R686: the OA subduing pins
#include "rules/oapsychicduel.h"  // R687: the OA psychic duel pins
#include "rules/oamartialopen.h"  // R688: the OA martial arts opener pins
#include "rules/oa68styles.h"  // R689: the OA Table 68 common styles pins
#include "rules/oacreatestyle.h"  // R690: the OA creating a style pins
#include "rules/oa69combos.h"  // R691: the OA Table 69 style combinations pins
#include "rules/oa70maneuvers.h"  // R692: the OA Table 70 special maneuvers pins
#include "rules/oamethods.h"  // R693: the OA principal methods pins
#include "rules/oatrain.h"  // R694: the OA mental and physical training pins
#include "rules/oalearn.h"  // R695: the OA learning martial arts pins
#include "rules/oacalendar.h"  // R696: the OA calendar pins
#include "rules/oa71yearly.h"  // R697: the OA Table 71 yearly events pins
#include "rules/oa71explain.h"  // R698: the OA yearly events explanation pins
#include "rules/oa72monthly.h"  // R699: the OA Table 72 monthly events pins
#include "rules/oa72explain.h"  // R700: the OA monthly events explanation pins
#include "rules/oa73daily.h"  // R701: the OA Table 73 daily events pins
#include "rules/oa73explain.h"  // R702: the OA daily events explanation pins
#include "rules/oa74terrain.h"  // R703: the OA Chapter 11 terrain encounter tables pins
#include "rules/oa75climate.h"  // R704: the OA climate groupings pins
#include "rules/oa76bajang.h"  // R705: the OA Bajang pins
#include "rules/oa77bakemono.h"  // R706: the OA Bakemono pins
#include "rules/oa78bisan.h"  // R707: the OA Bisan pins
#include "rules/oa79buso.h"  // R708: the OA Buso pins
#include "rules/oa80carp.h"  // R709: the OA Giant Carp pins
#include "rules/oa81continh.h"  // R710: the OA Con-Tinh pins
#include "rules/oa82doccuoc.h"  // R711: the OA Doc Cu'o'c pins
#include "rules/oa83dragons.h"  // R712: the OA Oriental Dragons pins
#include "rules/oa84gaki.h"  // R713: the OA Gaki pins
#include "rules/oa85gargantua.h"  // R714: the OA Gargantua pins
#include "rules/oa86generals.h"  // R715: the OA Animal Generals pins
#include "rules/oa87goblinrat.h"  // R716: the OA Goblin Rat pins
#include "rules/oa88goblinspider.h"  // R717: the OA Goblin Spider pins
#include "rules/oa89hainu.h"  // R718: the OA Hai Nu pins
#include "rules/oa90hsingsing.h"  // R719: the OA Hsing-Sing pins
#include "rules/oa91huhuien.h"  // R720: the OA Hu Hsien pins
#include "rules/oa92kala.h"  // R721: the OA Kala pins
#include "rules/oa93kappa.h"  // R722: the OA Kappa pins
#include "rules/oa94kuei.h"  // R723: the OA Kuei pins
#include "rules/oa95menwako.h"  // R724: the OA Men Wako pins
#include "rules/oa96nat.h"  // R725: the OA Nat pins
#include "rules/oa97naturespirit.h"  // R726: the OA Nature Spirits pins
#include "rules/oa98ningyo.h"  // R727: the OA Ningyo pins
#include "rules/oa99oni.h"  // R728: the OA Oni pins
#include "rules/oa100poh.h"  // R729: the OA P oh pins
#include "rules/oa101shansao.h"  // R730: the OA Shan Sao pins
#include "rules/oa102shiro.h"  // R731: the OA Shirokinukatsukami pins
#include "rules/oa103tengu.h"  // R732: the OA Tengu pins
#include "rules/oa104classuse.h"  // R733: the OA class usage pins
#include "rules/oa105randtres.h"  // R734: the OA random treasure pins
#include "rules/oa106table74.h"  // R735: the OA Table 74 pins
#include "rules/oa107tableiia.h"  // R736: the OA Table II.A. pins
#include "rules/oa108tableiii.h"  // R737: the OA Table III pins
#include "rules/oa109itemmods.h"  // R738: the OA item mods pins
#include "rules/oa110potions.h"  // R739: the OA potions pins
#include "rules/oa111scrolls.h"  // R740: the OA scrolls pins
#include "rules/oa112rods.h"  // R741: the OA rods pins
#include "rules/oa113miscmagic.h"  // R742: the OA misc magic pins
#include "rules/oa114armorprose.h"  // R743: the OA armor prose pins
#include "rules/oa115table75.h"  // R744: the OA Table 75 pins
#include "rules/oa116table76.h"  // R745: the OA Table 76 pins
#include "rules/oa117table77.h"  // R746: the OA Table 77 pins
#include "rules/oa118armorexpl.h"  // R747: the OA armor explanation pins
#include "rules/oa119weaponsprose.h"  // R748: the OA weapons prose pins
#include "rules/oa120table78.h"  // R749: the OA Table 78 pins
#include "rules/oa121table79.h"  // R750: the OA Table 79 pins
#include "rules/oa122table80.h"  // R751: the OA Table 80 pins
#include "rules/oa123table81.h"  // R752: the OA Table 81 pins
#include "rules/oa124table82.h"  // R753: the OA Table 82 pins
#include "rules/oa125table83.h"  // R754: the OA Table 83 pins
#include "rules/oa126table84.h"  // R755: the OA Table 84 pins
#include "rules/oa127table85.h"  // R756: the OA Table 85 pins
#include "rules/oa128weaponexpl.h"  // R757: the OA weapon explanation pins
#include "rules/oa129magitemsprose.h"  // R758: the OA magical items prose pins
#include "rules/oa130table86.h"  // R759: the OA Table 86 pins
#include "rules/oa131karaturintro.h"  // R760: the OA Kara-Tur overview pins
#include "rules/oa132shoulung.h"  // R761: the OA Shou Lung pins
#include "rules/oa133tulung.h"  // R762: the OA Tu Lung pins
#include "rules/oa134wa.h"  // R763: the OA Wa pins
#include "rules/oa135kozakura.h"  // R764: the OA Kozakura pins
#include "rules/oa136gajin.h"  // R765: the OA Gajin pins
#include "rules/oa137food.h"  // R766: the OA Daily Life Food pins
#include "rules/oa138buildings.h"  // R767: the OA Daily Life Buildings pins
#include "rules/oa139manners.h"  // R768: the OA Daily Life Manners pins
#include "rules/oa140names.h"  // R769: the OA Daily Life Names pins
#include "rules/oa141backmatter.h"  // R770: the OA Back matter pins
#include "rules/oa142celestial.h"  // R771: the OA Celestial Emperor pins
#include "rules/oa143weaponsprose.h"  // R772: the OA Weapons prose pins
#include "rules/oa144dailylife.h"  // R773: the OA daily-life misses pins
#include "rules/filepatchseam.h"  // R774: the file-patch seam tooling pins
#include "rules/rtseam.h"  // R775: the RT seam fix pins
#include "rules/mountcombat.h"  // R776: the mount site pins
#include "rules/saddle.h"  // R777: the saddle acquisition pins
#include "rules/mountmove.h"  // R778: the mounted movement pins
#include "rules/lancecharge.h"  // R779: the lance charge pins
#include "rules/lancespeed.h"  // R780: the lance speed pins
#include "rules/spearset.h"  // R781: the set spear pins
#include "rules/owedpins.h"  // R782: the owed pins
#include "rules/deitylines.h"  // R783: the deity stat lines
#include "rules/worshipsites.h"  // R784: the worship sites
#include "rules/spelltableledger.h"  // R785: the UA spell table ledger
#include "rules/uadeityprose1.h"  // R786: the dwarven deity prose
#include "rules/uadeityprose2.h"  // R787: the elven deity prose
#include "rules/uadeityprose3.h"  // R788: the halfling deity prose
#include "rules/uadeityprose4.h"  // R789: the gnomish deity prose
#include "rules/uadeityprose5.h"  // R790: the orcish deity prose
#include "rules/lreg.h"  // R791: the registry promotion wiring
#include "rules/prg.h"  // R792: the registry promotion defs
#include "rules/prf.h"  // R793: the registry promotion def name fix
#include "rules/rtk.h"  // R794: the tooling data_files adaptation
#include "rules/rns.h"  // R795: the rn self-patch guard
#include "rules/mma.h"  // R796: the MM2 arc opener
#include "rules/mm2a.h"  // R797: the MM2 letter A
#include "rules/mm2bc.h"  // R798: the MM2 letters B and C
#include "rules/mm2dp.h"  // R799: the MM2 letter D part 1 - the planar evil families
#include "rules/mm2dv.h"  // R800: the MM2 letter D part 2 - the deva turn
#include "rules/mm2df.h"  // R801: the MM2 letter D part 3 - the devil section
#include "rules/mm2dn.h"  // R802: the MM2 letter D part 4 - the diakk and dinosaur walk
#include "rules/mm2dg.h"  // R803: the MM2 letter D part 5 - the dracolisk, dragon and dustdigger turns
#include "rules/mm2de.h"  // R804: the MM2 letter E walk - the eagle, elf and executioner hood turns
#include "rules/mm2fg.h"  // R805: the MM2 letters FG walk - the falcon, foo creature, giant and grue turns
#include "rules/mm2hi.h"  // R806: the MM2 letters HI walk - the hangman tree, haunt, hollyphant, hordling and hybsil turns
#include "rules/mm2jk.h"  // R807: the MM2 letters JK walk - the jann, mustard jelly, kampfult, kech, korred and kraken turns
#include "rules/mm2lmn.h"  // R808: the MM2 letters LMN walk - the land lamprey, luck eater, lycanthrope, magman, mandragora, giant mantis, mantrap, margoyle, marid, shadow mastiff, mihstu, miner, minimal, modron, russet mold, mongrelman, moon dog, muckdweller, mud-man, myconid, nereid and narwhale turns
#include "rules/mm2o.h"  // R809: the MM2 letter O walk - the obliviax, ogre aquatic (merrow), oliphant, ophidian, opinicus, otter and owl turns
#include "rules/mm2p.h"  // R810: the MM2 letter P walk - the para-elemental (ice, smoke, magma and ooze), pech, pedipalp (large, huge and giant), phantom, phoenix, phycomid, planetar, pseudo-undead, deadly pudding (brown, dun and white) and pyrolisk turns
#include "rules/mm2q.h"  // R811: the MM2 letter Q walk - the quasi-elemental lightning, quickling and quickwood turns
#include "rules/mm2r.h"  // R812: the MM2 letter R walk - the rat (ordinary and vapor), raven (ordinary, huge and giant), retch plant and rock reptile turns
#include "rules/mm2s.h"  // R813: the MM2 letter S walk - the sandling to taer turns
#include "rules/mm2tuv.h"  // R814: the MM2 letters TUV walk - the tarrasque to vulture turns
#include "rules/mm2wxyz.h"  // R815: the MM2 letters WXYZ walk - the weasel to zygom turns
#include "rules/mm2encd.h"  // R816: the MM2 dungeon encounter tables walk - the ten monster level grids
#include "rules/mm2enco.h"  // R817: the MM2 outdoor encounter tables walk - the 36 terrain grids
#include "rules/mm2enca.h"  // R818: the MM2 aquatic encounter tables walk - the 12 surface and depths grids
#include "rules/mm2enci.h"  // R819: the MM2 index walk - the merged MM1/FF/MM2 index census
#include "rules/lmp.h"  // R820: the lammasu promotion
#include "rules/lungp.h"  // R821: the lung promotion
#include "rules/afw.h"  // R822: the audit files decomposition wiring
#include "rules/migw.h"  // R823: the audit blocks migration wiring
#include "rules/pmb.h"  // R824: the pilot migration round
#include "rules/nmb.h"  // R825: the DMG appendix migration batch
#include "rules/tmb.h"  // R826: the DMG tables migration batch
#include "rules/qmb.h"  // R827: the subclass migration batch
#include "rules/zmb.h"  // R828: the hundred-block migration batch
#include "rules/vmb.h"  // R829: the UA and WSG migration batch
#include "rules/xmb.h"  // R830: the WSG tail and DSG migration batch
#include "rules/kmb.h"  // R831: the planes and OA migration batch
#include "rules/jmb.h"  // R832: the OA tail migration batch
#include "rules/fmb.h"  // R833: the final digest migration batch
#include "rules/hmb.h"  // R834: the holdback tooling patch
#include "rules/ymb.h"  // R835: the final holdback batch
#include "rules/ffp.h"  // R836: the first FF promotion batch
#include "rules/ffs.h"  // R837: the second FF promotion batch
#include "rules/fft.h"  // R838: the third FF promotion batch
#include "rules/ffu.h"  // R839: the fourth FF promotion batch
#include "rules/ffh.h"  // R840: the hornet promotion
#include "rules/ffik.h"  // R841: the FF index line walk
#include "rules/ffj.h"  // R842: the fifth FF promotion batch
#include "rules/ffk.h"  // R843: the sixth FF promotion batch
#include "rules/ffl.h"  // R844: the seventh FF promotion batch
#include "rules/ffm.h"  // R845: the eighth FF promotion batch
#include "rules/ffn.h"  // R846: the FF monster level tables
#include "rules/ffo.h"  // R847: the FF encounter listings
#include "rules/ffq.h"  // R848: the FF magic item tables
#include "rules/dga.h"  // R849: the DDG front matter
#include "rules/dgb.h"  // R850: the American Indian mythos
#include "rules/dgc.h"  // R851: the Arthurian mythos
#include "rules/dgd.h"  // R852: the Babylonian mythos
#include "rules/dge.h"  // R853: the Celtic mythos
#include "rules/dgf.h"  // R854: the Central American mythos
#include "rules/dgg.h"  // R855: the Chinese mythos
#include "rules/cth.h"  // R856: the Cthulhu mythos
#include "rules/egp.h"  // R857: the Egyptian mythos
#include "rules/klv.h"  // R858: the Finnish mythos
#include "rules/grk.h"  // R859: the Greek mythos
#include "rules/idn.h"  // R860: the Indian mythos
#include "rules/jpn.h"  // R861: the Japanese mythos
#include "rules/mlb.h"  // R862: the Melnibonean mythos
#include "rules/nhw.h"  // R863: the Nehwon mythos
#include "rules/nhg.h"  // R864: the Nonhumans' Deities
#include "rules/uascharts.h"  // R407: the UA Appendix S clerical charts
#include "rules/followers.h"  // R170: pp.16-18 followers by class
#include "rules/klm.h"  // R171: pp.221-224 appendices K L and M
#include "rules/herbs.h"  // R172: p.220 appendix J herbs spices and medicinal vegetables
#include "rules/secondary.h"  // R173: p.12 secondary skills
#include "rules/subclasses.h"  // R179: the subclass registry
#include "rules/subclassgates.h"  // R180: the qualification and race gates
#include "rules/attacksround.h"  // R181: attacks per melee round
#include "rules/druidspells.h"  // R182: the druid spell layer
#include "rules/illusionspells.h"  // R183: the illusionist spell layer
#include "rules/palrangerspells.h"  // R184: the paladin and ranger spell layers
#include "rules/multiclass.h"  // R185: the multi-class and dual-class rules
#include "rules/bard.h"  // R186: the bard (Appendix II)
#include "rules/subclassspecials.h"  // R187: the per-subclass specials
#include "rules/xpadjust.h"  // R188: the prime requisite XP adjustment
#include "rules/weapontables.h"  // R189: the weapon weight and damage table
#include "rules/mountlayer.h"  // R403: the mount layer seam
#include "rules/startmoney.h"  // R190: the starting money by class
#include "rules/armorratings.h"  // R191: the armor class ratings
#include "rules/wisdom.h"  // R192: Wisdom Tables I and II
#include "rules/itemsavethrow.h"  // R204: p.80 item saving throw matrix
#include "rules/spying.h"  // R205: pp.19-20 the spying tables
#include "rules/pursuit.h"  // R206: pp.67-69 pursuit and evasion
#include "rules/taxation.h"  // R207: p.90 the town taxation system
#include "rules/socialrank.h"  // R208: pp.88-89 social class and rank
#include "rules/npcpersonae.h"  // R209: pp.114-115 NPC personae facts
#include "rules/npctraits.h"  // R210: pp.115-116 NPC personae traits
#include "rules/npcbody.h"  // R211: pp.115-116 height, weight, languages
#include "rules/hirecost.h"  // R212: pp.116-118 hire spell costs, troop control
#include "rules/construct.h"  // R213: pp.106-108 construction and siege economics
#include "rules/siegefire.h"  // R214: pp.108-110 war machine fire, siege attack, defensive values
#include "rules/conduct.h"  // R215: pp.110-112 conducting the game pins
#include "rules/magres.h"  // R216: pp.114-119 magical research pins
#include "rules/scrollfab.h"  // R217: pp.118-121 scroll manufacture and fabrication pins
#include "rules/energydrain.h"  // R218: pp.119-122 use of magic items and energy draining pins
#include "rules/treasdet.h"  // R219: pp.120-123 treasure random determination tables
#include "rules/hoard.h"  // R220: p.123 the combined hoard table
#include "rules/potions.h"  // R221: pp.125-126 the potions prose pins
#include "rules/scrollpins.h"  // R222: pp.126-127 the scrolls prose pins
#include "rules/rings.h"  // R223: p.127 the rings footnote pins
#include "rules/rodswands.h"  // R224: pp.127-128 the rods/staves/wands pins
#include "rules/miscmagic1.h"  // R225: p.128 the misc table 1 pins
#include "rules/miscmagic2.h"  // R226: p.128 the misc table 2 pins
#include "rules/miscmagic3.h"  // R237: p.129 the misc table 3 pins
#include "rules/miscmagic4.h"  // R238: p.129-130 the misc table 4 pins
#include "rules/miscmagic5.h"  // R239: p.130 the misc table 5 pins
#include "rules/specart.h"  // R240: p.130-131 the III.E Special artifacts pins
#include "rules/armorshield.h"  // R241: p.129-130 the III.F armor and shield pins
#include "rules/swords.h"  // R242: p.131 the III.G swords pins
#include "rules/mweapons.h"  // R243: p.131-132 the III.H misc weapons pins
#include "rules/rodsprose.h"  // R244: pp.141-142 the III.D rods prose pins
#include "rules/stavesprose.h"  // R245: pp.142-143 the III.D staves prose pins
#include "rules/wandsprose.h"  // R246: pp.143-144 the III.D wands prose pins
#include "rules/wandsprose2.h"  // R247: pp.144-145 the III.D wands prose part 2 pins
#include "rules/wonder.h"  // R248: p.145 the III.D wand of wonder effect table pins
#include "rules/potionsprose.h"  // R249: pp.133-134 the III.A potions prose part 1 pins
#include "rules/potionsprose2.h"  // R250: pp.134-136 the III.A potions prose part 2 pins
#include "rules/potionsprose3.h"  // R251: pp.136-137 the III.A potions prose part 3 pins
#include "rules/scrollsprose.h"  // R252: pp.137-139 the III.B scrolls explanation prose pins
#include "rules/ringsprose.h"  // R253: pp.137-138 the III.C rings explanation prose part 1 pins
#include "rules/ringsprose2.h"  // R254: pp.138-139 the III.C rings explanation prose part 2 pins
#include "rules/ringsprose3.h"  // R256: pp.139-140 the III.C rings explanation prose part 3 pins
#include "rules/miscprose1.h"  // R257: the III.E misc magic explanation prose part 1 pins
#include "rules/miscprose2.h"  // R258: the III.E misc magic explanation prose part 2 pins
#include "rules/miscprose3.h"  // R259: the III.E misc magic explanation prose part 3 pins
#include "rules/miscprose4.h"  // R260: the III.E misc magic explanation prose part 4 pins
#include "rules/miscprose5.h"  // R261: the III.E misc magic explanation prose part 5 pins
#include "rules/miscprose6.h"  // R262: the III.E misc magic explanation prose part 6 pins
#include "rules/miscprose7.h"  // R263: the III.E misc magic explanation prose part 7 pins
#include "rules/miscprose8.h"  // R264: the III.E misc magic explanation prose part 8 pins
#include "rules/miscprose9.h"  // R265: the III.E misc magic explanation prose part 9 pins
#include "rules/miscprose10.h"  // R266: the III.E misc magic explanation prose part 10 pins
#include "rules/miscprose11.h"  // R267: the III.E misc magic explanation prose part 11 pins
#include "rules/miscprose12.h"  // R268: the III.E misc magic explanation prose part 12 pins
#include "rules/miscprose13.h"  // R269: the III.E misc magic explanation prose part 13 pins
#include "rules/miscprose14.h"  // R270: the III.E misc magic explanation prose part 14 pins
#include "rules/miscprose15.h"  // R271: the III.E misc magic explanation prose part 15 pins
#include "rules/miscprose16.h"  // R272: the III.E misc magic explanation prose part 16 pins
#include "rules/miscprose17.h"  // R273: the III.E misc magic explanation prose part 17 pins
#include "rules/miscprose18.h"  // R274: the III.E misc magic explanation prose part 18 pins
#include "rules/miscprose19.h"  // R275: the III.E misc magic explanation prose part 19 pins
#include "rules/miscprose20.h"  // R276: the III.E misc magic explanation prose part 20 pins
#include "rules/miscprose21.h"  // R277: the III.E misc magic explanation prose part 21 pins
#include "rules/miscprose22.h"  // R278: the III.E misc magic explanation prose part 22 pins
#include "rules/miscprose23.h"  // R279: the III.E misc magic explanation prose part 23 pins
#include "rules/specartprose.h"  // R280: the III.E Special artifacts explanation prose part 1 pins
#include "rules/specartprose2.h"  // R281: the III.E Special artifacts explanation prose part 2 pins
#include "rules/weaponprof.h"  // R297: the PHB Weapon Proficiency Table
#include "rules/thieffunc.h"  // R298: the thief function take table and DEX Table II
#include "rules/locktime.h"  // R304: the DMG lock time pins
#include "rules/doorforce.h"  // R305: the DMG door force pins
#include "rules/equipcosts.h"  // R300: the equipment cost columns
#include "rules/hirelings.h"  // R309: the hirelings cost tables
#include "rules/sage.h"  // R310: the sage subsection
#include "rules/underwater.h"  // R311: the underwater environment
#include "rules/swimcross.h"  // R312: the flooded crossing
#include "rules/uwfight.h"  // R313: the underwater fight
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
    // (monsters/monsters/a/aarakocra.lua, ...), but loadDirectory() reads
    // only one flat directory level. Load every letter dir and total the
    // counts; a missing/empty dir contributes 0 (loadDirectory returns
    // -1 only if the directory itself cannot be opened, so ignore -1).
    int n = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::string dir = "monsters/monsters/";
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
                d.xpSource != "ff_print") bad = true;
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
#include "rules/audits/r826_batch.h"  // R826: R826 DMG tables batch audit
#include "rules/audits/r827_batch.h"  // R827: R827 subclass batch audit
#include "rules/audits/r828_batch.h"  // R828: R828 hundred-block batch audit
#include "rules/audits/r829_batch.h"  // R829: R829 UA WSG batch audit
#include "rules/audits/r830_batch.h"  // R830: R830 WSG DSG batch audit
#include "rules/audits/r831_batch.h"  // R831: R831 planes OA batch audit
#include "rules/audits/r832_batch.h"  // R832: R832 OA tail batch audit
#include "rules/audits/r864_batch.h"  // R864: R864 nonhumans' deities audit
#include "rules/audits/r863_batch.h"  // R863: R863 Nehwon mythos audit
#include "rules/audits/r862_batch.h"  // R862: R862 Melnibonean mythos audit
#include "rules/audits/r861_batch.h"  // R861: R861 Japanese mythos audit
#include "rules/audits/r860_batch.h"  // R860: R860 Indian mythos audit
#include "rules/audits/r859_batch.h"  // R859: R859 Greek mythos audit
#include "rules/audits/r858_batch.h"  // R858: R858 Finnish mythos audit
#include "rules/audits/r857_batch.h"  // R857: R857 Egyptian mythos audit
#include "rules/audits/r856_batch.h"  // R856: R856 Cthulhu mythos audit
#include "rules/audits/r855_batch.h"  // R855: R855 Chinese mythos audit
#include "rules/audits/r854_batch.h"  // R854: R854 Central American mythos audit
#include "rules/audits/r853_batch.h"  // R853: R853 Celtic mythos audit
#include "rules/audits/r852_batch.h"  // R852: R852 Babylonian mythos audit
#include "rules/audits/r851_batch.h"  // R851: R851 Arthurian mythos audit
#include "rules/audits/r850_batch.h"  // R850: R850 American Indian mythos audit
#include "rules/audits/r849_batch.h"  // R849: R849 DDG front matter audit
#include "rules/audits/r848_batch.h"  // R848: R848 FF magic item tables audit
#include "rules/audits/r847_batch.h"  // R847: R847 FF encounter listings audit
#include "rules/audits/r846_batch.h"  // R846: R846 FF monster level tables audit
#include "rules/audits/r845_batch.h"  // R845: R845 eighth FF promotion audit
#include "rules/audits/r844_batch.h"  // R844: R844 seventh FF promotion audit
#include "rules/audits/r843_batch.h"  // R843: R843 sixth FF promotion audit
#include "rules/audits/r842_batch.h"  // R842: R842 fifth FF promotion audit
#include "rules/audits/r841_batch.h"  // R841: R841 FF index line walk audit
#include "rules/audits/r840_batch.h"  // R840: R840 hornet promotion audit
#include "rules/audits/r839_batch.h"  // R839: R839 fourth FF promotion audit
#include "rules/audits/r838_batch.h"  // R838: R838 third FF promotion audit
#include "rules/audits/r837_batch.h"  // R837: R837 second FF promotion audit
#include "rules/audits/r836_batch.h"  // R836: R836 first FF promotion audit
#include "rules/audits/r835_batch.h"  // R835: R835 final holdback batch audit
#include "rules/audits/r834_batch.h"  // R834: R834 holdback tooling patch audit
#include "rules/audits/r833_batch.h"  // R833: R833 final digest batch audit
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
