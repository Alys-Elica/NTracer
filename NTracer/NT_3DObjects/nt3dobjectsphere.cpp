#include "nt3dobjectsphere.h"

#include <cmath>

NT3DObjectSphere::NT3DObjectSphere(const NCore::NCVector3D &position, const double radius) :
    NT3DObject(position)
{
    m_radius = radius;
}

NT3DObjectSphere::~NT3DObjectSphere()
{
}

bool NT3DObjectSphere::intersect(const NTRay &ray, NTIntersection &intersect)
{
    NCore::NCVector3D rayOrg = ray.startVector() - m_position;

    NCore::NCVector3D dir = ray.directionVector();

    double a = NCore::NCVector3D::dotProduct(dir, dir);
    double b = 2.0 * NCore::NCVector3D::dotProduct(dir, rayOrg);
    double c = NCore::NCVector3D::dotProduct(rayOrg, rayOrg) - (m_radius * m_radius);

    double delta = (b * b) - (4.0 * a * c);

    if (delta < 0.0)
        return false; // Pas d'intersection

    double t;
    if (delta != 0.0) {
        delta = std::sqrt(delta);
        double t1 = (-b + delta) / 2;
        double t2 = (-b - delta) / 2;

        if (t1 < t2)
            t = t1;
        else
            t = t2;
    } else {
        t = -b / 2.0;
    }

    intersect.setPoint(ray.startVector() + dir * t);
    intersect.setNormal(((intersect.point() - m_position)).normalized());
    intersect.setObject(this);

    return true;
}
