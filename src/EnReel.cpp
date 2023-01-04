#include "EnReel.h"
#include "math.h"

#include "orderdoubles/804dc518_804dc520.inc"

void EnReel::calculateTransformMatrix()
{
    m005C = calculateLookAtAngle(mNormalDirectionToDestPosition.z, mNormalDirectionToDestPosition.x) * ANGLE_TO_FLOAT;

    f32 t = func_80127870(calculateXZMagSquared(mNormalDirectionToDestPosition.x, mNormalDirectionToDestPosition.z));
    m0058 = calculateLookAtAngle(t, -mNormalDirectionToDestPosition.y) * ANGLE_TO_FLOAT;

    Mtx xMtx, yMtx;

    MTXRotRad(xMtx, 'X', m0058 * DEG_TO_RAD);
    MTXRotRad(yMtx, 'Y', m005C * DEG_TO_RAD);
    MTXConcat(yMtx, xMtx, mRotationMatrix);

    MTXTrans(mTranslationMatrix, mDestPosition.x, mDestPosition.y, mDestPosition.z);
    MTXConcat(mTranslationMatrix, mRotationMatrix, mTransformMatrix);
}

f32 EnReel::getScaleModifier()
{
    return mCurrentScaleModifier;
}

void EnReel::setScaleModifier(f32 newScale)
{
    mCurrentScaleModifier = newScale;
}
