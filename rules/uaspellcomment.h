// ===========================================================================
// Adnd1 - rules/uaspellcomment.h
// The UA SPELL EXPLANATIONS - the referee commentary
// (pp. 81-82 print) pins, R366: the permanency lists
// and the Serten's spell immunity commentary.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the permanency object/area list interleaves with
//     the constitution-loss note in the print - the 22
//     names pin from the two fragments (the note
//     counted separately).
//   - the Serten's bonus bands detach from their spell
//     groups in the print (a stray +9/+7/+5 column) -
//     the three values and the 24 spell names pin, the
//     band assignment is flagged garbled pending the
//     PDF.
//   - a stray "from normal" fragment rides the
//     personal permanency list - flagged, no decode.
// ===========================================================================

#pragma once

namespace rules {

// ---- the personal permanency list ----
inline int uapcPermPersonalCount()
    { return 6; }

inline bool uapcPermPersonalDetectEvil()
    { return true; }

inline bool uapcPermPersonalDetectIllusion()
    { return true; }

inline bool uapcPermPersonalDetectInvisibility()
    { return true; }

inline bool uapcPermPersonalDetectMagic()
    { return true; }

inline bool uapcPermPersonalInfravision()
    { return true; }

inline bool uapcPermPersonalProtectionFromEvil()
    { return true; }

inline bool uapcPersonalListFromNormalFragment()
    { return true; }

// ---- the object/creature or area permanency list ----
inline int uapcPermObjectCount()
    { return 22; }

inline bool uapcPermObjectAlarm()
    { return true; }

inline bool uapcPermObjectDeeppockets()
    { return true; }

inline bool uapcPermObjectDispelMagic()
    { return true; }

inline bool uapcPermObjectEnlarge()
    { return true; }

inline bool uapcPermObjectFear()
    { return true; }

inline bool uapcPermObjectForcecage()
    { return true; }

inline bool uapcPermObjectGustOfWind()
    { return true; }

inline bool uapcPermObjectInvisibility()
    { return true; }

inline bool uapcPermObjectMagicMouth()
    { return true; }

inline bool uapcPermObjectMissiles()
    { return true; }

inline bool uapcPermObjectPreserve()
    { return true; }

inline bool uapcPermObjectPrismaticSphere()
    { return true; }

inline bool uapcPermObjectReadMagic()
    { return true; }

inline bool uapcPermObjectRun()
    { return true; }

inline bool uapcPermObjectStinkingCloud()
    { return true; }

inline bool uapcPermObjectTongues()
    { return true; }

inline bool uapcPermObjectUltravision()
    { return true; }

inline bool uapcPermObjectUnseenServant()
    { return true; }

inline bool uapcPermObjectWallOfFire()
    { return true; }

inline bool uapcPermObjectWallOfForce()
    { return true; }

inline bool uapcPermObjectWeb()
    { return true; }

inline bool uapcPermObjectWindWall()
    { return true; }

inline bool uapcObjectListInterleavedWithNote()
    { return true; }

// ---- the constitution-loss reads ----
// Only a 5 percent chance of losing a constitution
// point when permanency is cast upon a non-living
// thing; 100 percent when applied as a charge in a
// device (a ring of spell storing, the printed
// example).
inline int uapcConLossPctNonLiving()
    { return 5; }

inline int uapcConLossPctDeviceCharge()
    { return 100; }

inline bool uapcDeviceExampleRingOfSpellStoring()
    { return true; }

// ---- the Serten's spell immunity commentary ----
// The spell grants saving throw bonuses against the
// 24 listed magics, bestows a saving throw against
// all of them even if none is normally allowed, but
// not against the fascination effect of comeliness.
inline int uapcSertenSpellCount()
    { return 24; }

inline const char* uapcSertenName(int i)
{
    static const char* const n[24] = {
        "beguiling", "charm", "suggestion",
        "forget", "hypnotism",
        "ray of enfeeblement",
        "person-affecting cantrips",
        "command", "domination", "fear",
        "hold", "scare", "spook", "eyebite",
        "cloak of fear", "geas", "quest",
        "chaos", "feeblemind",
        "Otto's irresistible dance",
        "dolor", "demand", "torment",
        "Leomund's lamentable"
        " belabourment",
    };
    return (i >= 0 && i < 24) ? n[i] : "";
}

inline int uapcSertenBonusHigh()
    { return 9; }

inline int uapcSertenBonusMid()
    { return 7; }

inline int uapcSertenBonusLow()
    { return 5; }

inline bool uapcSertenBandAssignmentGarbled()
    { return true; }

inline bool uapcSertenSaveEvenIfNoneAllowed()
    { return true; }

inline bool uapcSertenNotVsComelinessFascination()
    { return true; }

}   // namespace rules

