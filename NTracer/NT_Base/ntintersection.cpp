#include "ntintersection.h"

NTIntersection::NTIntersection()
{

}

NCore::NCVector3D NTIntersection::point() const
{
    return m_point;
}

void NTIntersection::setPoint(const NCore::NCVector3D &point)
{
    m_point = point;
}

NCore::NCVector3D NTIntersection::normal() const
{
    return m_normal;
}

void NTIntersection::setNormal(const NCore::NCVector3D &normal)
{
    m_normal = normal;
}

NT3DObject *NTIntersection::object() const
{
    return m_object;
}

void NTIntersection::setObject(NT3DObject *object)
{
    m_object = object;
}
