#include "common-chax.h"
#include "unit.h"
#include "item.h"
#include "skill-system.h"

typedef int (*const msg_func)(struct Unit *unit, int old_status);
extern msg_func ModularHpGetter[],  ModularPowGetter[], ModularMagGetter[], ModularSklGetter[], ModularSpdGetter[], \
                ModularLckGetter[], ModularDefGetter[], ModularResGetter[], ModularMovGetter[];

int msg_test_func(struct Unit *unit, int old_status)
{
    return old_status + 1;
}

LYN_REPLACE_CHECK(GetUnitMaxHp);
int GetUnitMaxHp(struct Unit *unit)
{
    int status;
    msg_func *it;
    int hp_bonus;

    /* Internal modular */
    status = unit->max_hp;
    hp_bonus = GetItemHpBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        hp_bonus *= 2;
    }
    status += hp_bonus;
    status += SkillTester(unit, SID_HpBonus) ? 5 : 0;

    /* External modular */
    for (it = ModularHpGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

LYN_REPLACE_CHECK(GetUnitPower);
int GetUnitPower(struct Unit *unit)
{
    int status;
    msg_func *it;
    int pow_bonus;

    /* Internal modular */
    status = unit->pow;
    pow_bonus = GetItemPowBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        pow_bonus *= 2;
    }
    status += pow_bonus;
    status += SkillTester(unit, SID_StrBonus) ? 2 : 0;

    /* External modular */
    for (it = ModularPowGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

LYN_REPLACE_CHECK(GetUnitSkill);
int GetUnitSkill(struct Unit *unit)
{
    int status;
    msg_func *it;
    int skl_bonus;

    /* Internal modular */
    status = unit->flags & UNIT_FLAG_RESCUING ? unit->skl / 2 : unit->skl;
    skl_bonus = GetItemSklBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        skl_bonus *= 2;
    }
    status += skl_bonus;
    status += SkillTester(unit, SID_SklBonus) ? 2 : 0;

    /* External modular */
    for (it = ModularSklGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

LYN_REPLACE_CHECK(GetUnitSpeed);
int GetUnitSpeed(struct Unit *unit)
{
    int status;
    msg_func *it;
    int spd_bonus;

    /* Internal modular */
    status = unit->flags & UNIT_FLAG_RESCUING ? unit->spd / 2 : unit->spd;
    spd_bonus = GetItemSpdBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        spd_bonus *= 2;
    }
    status += spd_bonus;
    status += SkillTester(unit, SID_SpdBonus) ? 2 : 0;

    /* External modular */
    for (it = ModularSpdGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

LYN_REPLACE_CHECK(GetUnitDefense);
int GetUnitDefense(struct Unit *unit)
{
    int status;
    msg_func *it;
    int def_bonus;

    /* Internal modular */
    status = unit->def;
    def_bonus = GetItemDefBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        def_bonus *= 2;
    }
    status += def_bonus;
    status += SkillTester(unit, SID_DefBonus) ? 2 : 0;

    /* External modular */
    for (it = ModularDefGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

LYN_REPLACE_CHECK(GetUnitResistance);
int GetUnitResistance(struct Unit *unit)
{
    int status;
    msg_func *it;
    int res_bonus;

    /* Internal modular */
    status = unit->res;
    res_bonus = GetItemResBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        res_bonus *= 2;
    }
    status += res_bonus;
    status += SkillTester(unit, SID_ResBonus) ? 2 : 0;
    status += unit->barrier;

    /* External modular */
    for (it = ModularResGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

LYN_REPLACE_CHECK(GetUnitLuck);
int GetUnitLuck(struct Unit *unit)
{
    int status;
    msg_func *it;
    int lck_bonus;

    /* Internal modular */
    status = unit->lck;
    lck_bonus = GetItemLckBonus(GetUnitEquippedWeapon(unit));
    if (GetItemKind(GetUnitEquippedWeapon(unit)) == ITEM_KIND_AXE && SkillTester(unit, SID_AxeCrazy)) {
        lck_bonus *= 2;
    }
    status += lck_bonus;
    status += SkillTester(unit, SID_LckBonus) ? 2 : 0;

    /* External modular */
    for (it = ModularLckGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}

int GetUnitMove(struct Unit *unit)
{
    int status;
    msg_func *it;

    /* Internal modular */
    status = UNIT_CON_BASE(unit);
    status += unit->bonus_mov;
    status += SkillTester(unit, SID_MovBonus) ? 2 : 0;

    /* External modular */
    for (it = ModularMovGetter; *it; it++)
        status = (*it)(unit, status);

    LIMIT_AREA(status, 0, UNIT_MAX_STATUS);
    return status;
}
