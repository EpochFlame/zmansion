#pragma once

#include "types.h"

extern const f32 DEG_TO_RAD;
extern const f32 ANGLE_TO_FLOAT;

extern u16 calculateLookAtAngle(f32, f32);
extern f32 func_80127870(f32);

inline f32 calculateXZMagSquared(f32 x, f32 z)
{
    x *= x;
    z *= z;

    return x + z;
}
