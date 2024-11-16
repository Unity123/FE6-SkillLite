#include "masseffect.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "battle.h"
#include "trap.h"
#include "bmfx.h"
#include "faction.h"
#include "action.h"
#include "targetlist.h"
#include "unitsprite.h"
#include "ui.h"
#include "mu.h"
#include "manim.h"
#include "eventinfo.h"
#include "save_stats.h"
#include "common.h"
#include "random.h"
#include "proc.h"
#include "item.h"
#include "support.h"
#include "arena.h"
#include "chapterinfo.h"
#include "save_game.h"

#include "constants/iids.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"

void PoisonDamageDisplay_Display_New(struct GenericProc * proc)
{
    struct SelectTarget * target = GetTarget(proc->unk4C);
    struct Unit * unit = GetUnit(target->uid);
    if (unit->psn_counter == 0) {
        unit -> psn_counter = 1;
    }
    target->extra = target->extra * unit->psn_counter;
    unit->psn_counter *= 2;
    HideUnitSprite(unit);
    BeginPoisonDamageAnim(unit, target->extra);
}