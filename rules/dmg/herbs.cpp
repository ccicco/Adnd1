// R-refactor: split from herbs.h - definitions
#include "rules/dmg/herbs.h"

int Herbs::rowCount() { return 171; }

const HerbRow& Herbs::row(int i) {
    static const HerbRow k[171] = {
        { "abscess root (sweet root)", "respiratory disorders" },
        { "acacia (Gum Arabic)", "tissue repair" },
        { "aconite (monkshood, wolfsbane, friar's cap, etc.)", "sedative/drives off werewolves" },
        { "acorn", "tissue hardening" },
        { "adder's tongue", "emetic, emollient" },
        { "adrue", "anti-vomiting, sedative" },
        { "agar-agar (jelly)", "anti-inflammation, nutrient" },
        { "agaric", "astringent, purgative" },
        { "agrimony (cocklebur, stickwort)", "muscle toner, diuretic" },
        { "alder", "anti-inflammation, tonic" },
        { "alkanet root", "emollient, antiseptic, wormer" },
        { "all-heal (wound-wort)", "antiseptic, anti-spasmodic" },
        { "almond milk/powder", "nutrient/emollient" },
        { "aloe (bitter aloe)", "bites, burns, laxative, tonic/insect repellent" },
        { "amaranth (red cockscomb, love-lies-bleeding)", "astringent, anti-hemorrhaging" },
        { "ammoniacum (Persian Gum)", "stimulant, respiratory aid" },
        { "angelica", "lungs, liver, spleen, vision, hearing" },
        { "anise", "antacid, digestion, coughing" },
        { "arbutus (mayflower)", "astringent, bladder infection" },
        { "areca nut (betel nut)", "astringent, tape wormer" },
        { "arenaria rubra (sandwort)", "diuretic, urinary diseases" },
        { "arrach (goosefoot)", "sedative (nervous tension or hysteria in particular)" },
        { "artichoke juice", "jaundice curative" },
        { "asafetida (gum asafetida, devil's dung, food of the gods)", "aphrodisiac, brain and nervous stimulant, tonic, many more" },
        { "asarabacca (hazelwort, wild nard)", "emetic, purgative" },
        { "ash (bark and leaves of)", "laxative, anti-inflammation, fever" },
        { "asparagus juice/root", "sedative, heart problems/anti-oxalic acid" },
        { "avens (colewort, herb bennet)", "astringent, anti-hemorrhaging, anti-weakness, tonic, more" },
        { "bael", "anti-inflammation, ulcers" },
        { "balm (sweet balm) leaves", "calms nerves, fevers" },
        { "balm of gilead", "nutrient, organ stimulant (general)" },
        { "balmony (bitter herb, snake head)", "tissue builder and strengthener, liver ailments, wormer" },
        { "barley", "nutrient (recuperative)" },
        { "basil", "nervous disorders" },
        { "bay leaf", "?" },
        { "beet", "organic cleanser" },
        { "belladonna (deadly nightshade, dwale, black cherry root)", "diuretic, sedative, pain reliever, anti-opiate, circulation, stimulant, poison/lycanthropy cure" },
        { "benne (sesam, sesame)", "respiratory disorders, eye infections, more" },
        { "benzoin (gum benzoin)", "expectorant, stimulant, antiseptic, wounds and sores" },
        { "berberis", "fevers" },
        { "beth root (lamb's quarters)", "astringent, coughs, tonic, anti-hemorrhaging, more" },
        { "bilberry (huckleberry, hurtleberry, whortleberry)", "anti-thirst, dropsy, typhoid, more" },
        { "birch (white birch)", "intestines and stomach, venereal diseases, skin conditions" },
        { "birthwort", "circulatory stimulant" },
        { "bistort (adderwort)", "astringent" },
        { "bittersweet (felonwort, scarlet berry, woody nightshade)", "abscesses, lymph infections, swelling and inflammation" },
        { "blackberry (dewberry)", "astringent, tonic, dysentery" },
        { "black currant", "diuretic, antiseptic, blood purifier" },
        { "black willow (pussy willow) bark", "astringent, antiseptic" },
        { "blueberry - see bilberry", "" },
        { "blue flag (flag lily, poison flag, water flag, water lily)", "diuretic, cathartic, blood purifier (vs. poison), wound healing, venereal disease, much more" },
        { "blue mallow (common mallow)", "coughs, colds" },
        { "boneset (thoughtwort)", "fevers, tonic, skin diseases" },
        { "borage", "coughs, lung infections" },
        { "box leaves", "tonic, blood purifier" },
        { "bryony", "paralysis, bruises" },
        { "bugle", "gastrointestinal disorders, hemorrhaging" },
        { "burdock", "laxative, tuberculosis, more" },
        { "butterbur", "fevers, urinary complaints" },
        { "cabbage juice", "ulcer and stomach treatment" },
        { "calotopis (mudar bark)", "skin leprosy, elephantiasis, more" },
        { "camphor (gum camphor)", "bruises, sprains, chills, fevers, cardiac stimulant" },
        { "caraway", "antacid, aids digestion" },
        { "cardamom", "?" },
        { "carrot juice and seeds", "tonic for improved health" },
        { "castor oil bush", "purgative, cathartic" },
        { "catnip", "colds, fevers, anti-spasmodic, hysteria" },
        { "cayenne", "stimulant" },
        { "celery", "liver functions, tonic, stimulant" },
        { "chamomile", "nervous conditions, ear and tooth aches" },
        { "chaulmoogra oil", "fevers, sedative, skin eruptions" },
        { "cherry gum", "respiratory infections/food substitute" },
        { "chervil", "?" },
        { "chives", "colds, general diseases/evil eye" },
        { "cinnamon", "disinfectant, nausea, preservative" },
        { "cleavers (goosegrass)", "fevers, circulation, blood purifier, wounds, liver disease" },
        { "clover", "tonic" },
        { "cloves", "anesthetic, circulation, germicide, disinfectant" },
        { "comfrey root (healing herb)", "colds, respiratory conditions, wounds, bone fractures, gangrene, much, much more" },
        { "coriander", "tonic" },
        { "couchgrass", "bladder and urinary infections" },
        { "cucumber", "inflammation" },
        { "cumin seed", "stimulant" },
        { "dandelion", "diuretic, purgative, tonic" },
        { "digitalis (dead men's bells, fairy bells, fairy cap, fairy fingers, foxglove, etc.)", "heart stimulant, tonic, kidney treatment (poison)" },
        { "dill", "nausea" },
        { "ergot (rye smut)", "hemorrhaging, venereal diseases" },
        { "eyebright", "astringent, eye infections" },
        { "fennel", "digestion, weight control, muscle tone, reflexes, vision, much, much more" },
        { "fenugreek", "stimulant" },
        { "fig", "demulcent" },
        { "figwort (scrofula plant, throatwort)", "abscesses, wounds, pain killer" },
        { "fireweed", "astringent, anti-spasmodic" },
        { "fluellin", "astringent, tissue strengthener" },
        { "garden burnet", "?" },
        { "garlic", "coughs, colds, blood purifier, detoxifier, kills parasites/wards off vampires" },
        { "gelsemium (wild woodbine)", "sedative, nerve tonic, fevers, more" },
        { "gentian (bitter root, felwort)", "tonic, fevers, anti-venom" },
        { "geranium (sweet geranium)", "alkalizer" },
        { "ginger", "stimulant, colds, cramps" },
        { "ginseng", "glandular stimulant, vision, dizziness, headaches, weakness" },
        { "goat's rue", "diuretic, wormer (vermifuge)" },
        { "grape juice", "blood fortifier" },
        { "hartstongue", "cough, liver, spleen, bladder" },
        { "hawthorn", "heart, arteries" },
        { "hedge mustard", "throat, lungs" },
        { "hellebore", "heart tonic (rootlets are poison)" },
        { "honeysuckle", "liver, spleen, respiratory disorders" },
        { "horehound, white", "coughs, pulmonary diseases, anti-venom" },
        { "horehound, black", "stimulant, wormer, hemorrhaging" },
        { "horseradish", "tonic, antiseptic, wormer" },
        { "hyssop", "respiratory ailments, jaundice, blood purifier, tonic, cuts and wounds, more" },
        { "ipecac", "dysentery, mouth infections, more" },
        { "irish moss", "coughs, scalds, burns" },
        { "jambul seed", "blood purifier, diabetes" },
        { "jewel weed (balsam weed, pale touch-me-not)", "diuretic, kidneys, skin growths, fungus, infections, liver" },
        { "juniper berry", "aphrodisiac, stimulant, disinfectant, venereal disease, more" },
        { "jurubera", "anemia" },
        { "kelp (seawrack)", "thyroid, heart, arteries, much more" },
        { "larkspur (knight's spur)", "external parasites" },
        { "leek", "same as chives" },
        { "lily-of-the-valley", "heart tonic" },
        { "lotus", "?" },
        { "lucerne (alfalfa)", "strength" },
        { "lycopodium (common club moss, fox tail, lamb's tail)", "wounds, lungs, kidneys, more" },
        { "mace", "stimulant" },
        { "marigold", "fevers, varicosities, eyes, heart" },
        { "marjoram", "melancholia, dizziness, brain disorders, toothaches" },
        { "masterwort", "stimulates organs, anti-spasmodic, more" },
        { "mistletoe", "convulsions, hysteria, narcotic, tonic, typhoid fever, heart" },
        { "muira-puama", "aphrodisiac" },
        { "mustard", "emetic, counter-irritant, colds, fevers" },
        { "nutmeg", "nausea, vomiting, diarrhea" },
        { "nux vomica (poison nut)", "stimulant, debility tonic" },
        { "onion", "poultice, colds (as chives)" },
        { "oregano", "germicide, pain killer" },
        { "paprika", "stimulant, poultice" },
        { "parsley", "blood purifier" },
        { "parsnip", "fevers" },
        { "peach seed", "fevers, blood tonic" },
        { "pepper, black", "sprains, neuritis" },
        { "peppermint", "?" },
        { "pitcher plant", "small pox preventative and cure, stomach, liver, kidneys" },
        { "plantain (ripple grass, waybread)", "minor wounds, stings, rashes" },
        { "pomegranate", "nerve sedative, wormer" },
        { "poppy", "?" },
        { "pumpkin seed", "virility, organ tonic" },
        { "quince", "eye disease, dysentery, skin disorders" },
        { "radish", "blood purifier, liver" },
        { "raspberry", "fevers, tonic" },
        { "rhubarb", "astringent, cathartic" },
        { "rose", "colds, fevers" },
        { "rosemary", "germicide, muscle tonic/drives off evil spirits" },
        { "saffron", "scarlet fever, measles, respiratory infections" },
        { "sage", "tonic, wounds" },
        { "sarsaparilla (china root, spikenard)", "system balance, blood purifier, venereal disease, many more" },
        { "scopolis", "nerve and muscle sedative, pain killer, coughs" },
        { "scullcap (madweed)", "nervous disorders, rabies" },
        { "senna", "purgative" },
        { "spearmint", "?" },
        { "strawberry", "vision, swelling and inflammation" },
        { "summer savory", "blood purifier, palsy" },
        { "tamarind", "infection, gangrene" },
        { "tansy", "tonic, narcotic, wormer" },
        { "tarragon", "?" },
        { "tea", "poison antidote" },
        { "thyme", "antiseptic, blood purifier" },
        { "turmeric", "?" },
        { "turnip", "mouth disease, throat" },
        { "watercress", "blood tonic (anemia)" },
        { "white bryony (mandragora)", "cathartic, respiratory diseases, heart, kidneys" },
    };
    if (i < 0) i = 0;
    if (i > 170) i = 170;
    return k[i];
}

int Herbs::unknownUsesCount() { return 10; }

bool Herbs::isCrossReference(int i) {
    static const bool k[171] = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, true,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false,
    };
    if (i < 0) i = 0;
    if (i > 170) i = 170;
    return k[i];
}

bool Herbs::introHundredsReputedMedicinalAndMagic() {
    return true;
}

bool Herbs::introNotWithinScopeToDetailAll() {
    return true;
}

bool Herbs::introAlphabeticalOneOrTwoComments() {
    return true;
}

bool Herbs::introHerbologistPursuesScholarlyTexts() {
    return true;
}

bool Herbs::closingGuideForPotionsInksItems() {
    return true;
}

bool Herbs::closingAddOrDeleteAsDesired() {
    return true;
}

bool Herbs::closingFolkUsesMagicDMPurview() {
    return true;
}
