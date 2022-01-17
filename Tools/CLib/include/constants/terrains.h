#pragma once

enum
{
    // Terrain identifiers

    // I'm going by the FE8 in-game names + some old FE7 nmm for this
    // TODO: figure out in better details

    TERRAIN_TILE_00    = 0x00,
    TERRAIN_PLAINS     = 0x01,
    TERRAIN_ROAD       = 0x02,
    TERRAIN_VILLAGE    = 0x03,
    TERRAIN_VILLAGE_CLOSED = 0x04,
    TERRAIN_HOUSE      = 0x05,
    TERRAIN_ARMORY     = 0x06,
    TERRAIN_VENDOR     = 0x07,
    TERRAIN_ARENA_08   = 0x08,
    TERRAIN_C_ROOM_09  = 0x09,
    TERRAIN_FORT       = 0x0A,
    TERRAIN_GATE_0B    = 0x0B,
    TERRAIN_FOREST     = 0x0C,
    TERRAIN_THICKET    = 0x0D,
    TERRAIN_SAND       = 0x0E,
    TERRAIN_DESERT     = 0x0F,
    TERRAIN_RIVER      = 0x10,
    TERRAIN_MOUNTAIN   = 0x11,
    TERRAIN_PEAK       = 0x12,
    TERRAIN_BRIDGE     = 0x13,
    TERRAIN_DRAWBRIDGE = 0x14,
    TERRAIN_SEA        = 0x15,
    TERRAIN_LAKE       = 0x16,
    TERRAIN_FLOOR_17   = 0x17,
    TERRAIN_FLOOR_18   = 0x18,
    TERRAIN_FENCE_19   = 0x19,
    TERRAIN_WALL_1A    = 0x1A,
    TERRAIN_WALL_1B    = 0x1B,
    TERRAIN_RUBBLE     = 0x1C,
    TERRAIN_PILLAR     = 0x1D,
    TERRAIN_DOOR       = 0x1E,
    TERRAIN_THRONE     = 0x1F,
    TERRAIN_CHEST_OPENED = 0x20,
    TERRAIN_CHEST      = 0x21,
    TERRAIN_ROOF       = 0x22,
    TERRAIN_GATE_23    = 0x23,
    TERRAIN_CHURCH     = 0x24,
    TERRAIN_RUINS      = 0x25,
    TERRAIN_CLIFF      = 0x26,
    TERRAIN_BALLISTA   = 0x27,
    TERRAIN_LONGBALLISTA = 0x28,
    TERRAIN_KILLERBALLISTA = 0x29,
    TERRAIN_SHIP_FLAT  = 0x2A,
    TERRAIN_SHIP_WRECK = 0x2B,
    TERRAIN_TILE_2C    = 0x2C,
    TERRAIN_STAIRS     = 0x2D,
    TERRAIN_TILE_2E    = 0x2E,
    TERRAIN_GLACIER    = 0x2F,
    TERRAIN_ARENA_30   = 0x30,
    TERRAIN_VALLEY     = 0x31,
    TERRAIN_FENCE_32   = 0x32,

    // TERRAIN_SNAG       = 0x33,
    // TERRAIN_BRIDGE_34  = 0x34,
    // TERRAIN_SKY        = 0x35,
    // TERRAIN_DEEPS      = 0x36,
    // TERRAIN_RUINS_37   = 0x37,
    // TERRAIN_INN        = 0x38,
    // TERRAIN_BARREL     = 0x39,
    // TERRAIN_BONE       = 0x3A,
    // TERRAIN_DARK       = 0x3B,
    // TERRAIN_WATER      = 0x3C,
    // TERRAIN_GUNNELS    = 0x3D,
    // TERRAIN_DECK       = 0x3E,
    // TERRAIN_BRACE      = 0x3F,
    // TERRAIN_MAST       = 0x40,

    TERRAIN_COUNT,
};
