#ifndef LTINTERSECTION_H
#define LTINTERSECTION_H

#include <NCore/ncvector3d.h>

class NT3DObject;
class NTIntersection
{
public:
    NTIntersection();

    NCore::NCVector3D point() const;
    void setPoint(const NCore::NCVector3D &point);

    NCore::NCVector3D normal() const;
    void setNormal(const NCore::NCVector3D &normal);

    NT3DObject *object() const;
    void setObject(NT3DObject *object);

private:
    NCore::NCVector3D m_point;
    NCore::NCVector3D m_normal;
    NT3DObject *m_object = nullptr;
};

#endif // LTINTERSECTION_H
