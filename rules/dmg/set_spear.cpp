// R-refactor: split from set_spear.h - definitions
#include "rules/dmg/set_spear.h"

int Set_spear::spsSetFeederRound() { return 189; }

int Set_spear::spsSpearSetRound() { return 781; }

int Set_spear::spsSetDamageMultiplier() { return 2; }

bool Set_spear::spsSpearSetReceivesTheClosingFoe() { return true; }

bool Set_spear::spsTheStanceConsumesTheRound() { return true; }

int Set_spear::spsAcFeederRound() { return 145; }

int Set_spear::spsSpeedPage() { return 66; }

int Set_spear::spsLanceAcRowCount() { return 3; }

bool Set_spear::spsLanceAcCellsRideTheCompilation() { return true; }

bool Set_spear::spsTieReadsTheSpeedLadder() { return true; }

bool Set_spear::spsWeaponVsSpellReadsTheSegment() { return true; }

bool Set_spear::spsExtraAttacksOpenAfterRoundOne() { return true; }

bool Set_spear::spsMissileWeaponsCarryNoFactor() { return true; }
