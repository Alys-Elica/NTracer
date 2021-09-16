#include "ntray.h"

NTRay::NTRay()
{

}

NCore::NCVector3D NTRay::startVector() const
{
    return m_startVector;
}

void NTRay::setStartVector(const NCore::NCVector3D &startVector)
{
    m_startVector = startVector;
}

NCore::NCVector3D NTRay::directionVector() const
{
    return m_directionVector;
}

void NTRay::setDirectionVector(const NCore::NCVector3D &directionVector)
{
    m_directionVector = directionVector;
}

NT3DObject *NTRay::origin() const
{
    return m_origin;
}

void NTRay::setOrigin(NT3DObject *origin)
{
    m_origin = origin;
}
