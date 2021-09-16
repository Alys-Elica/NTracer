#include "nt3dobjectplane.h"

NT3DObjectPlane::NT3DObjectPlane(const NCore::NCVector3D &position, const NCore::NCVector3D &normal) :
    NT3DObject(position)
{
    m_normal = normal;

    m_normal.normalize();
}

NT3DObjectPlane::~NT3DObjectPlane()
{
}

bool NT3DObjectPlane::intersect(const NTRay &ray, NTIntersection &intersect)
{
    double dv = NCore::NCVector3D::dotProduct(m_normal, ray.directionVector());

    if (dv == 0.0)
        return false;

    double t = ((-(NCore::NCVector3D::dotProduct(m_normal, ray.startVector() - m_position))) / dv);

    if (t < 0)
        return false;

    if (dv < 0)
        intersect.setNormal(m_normal);
    else
        intersect.setNormal(-m_normal);

    intersect.setPoint(ray.startVector() + ray.directionVector() * t);
    intersect.setObject(this);

    return true;
}
