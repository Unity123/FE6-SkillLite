#include "skill-system.h"
#include "constants/pids.h"

const struct SkillRomTable Skills_PData[MAX_PIDS] = {

    [PID_ROY] = {
        .default_skills = {
            SID_SklBonus,
            SID_WindSweep,
        },
        .level_skills = {
            SID_BlowDeath, 2,
        },
    },

    [PID_LANCE] = {
        .default_skills = {
            SID_DefBonus,
            SID_BlowDeath,
        },
        .level_skills = {
            SID_CritUp, 4,
        },
    },

    [PID_MARCUS] = {
        .default_skills = {
            SID_AxeCrazy,
        },
        .level_skills = {

        },
    }
};
