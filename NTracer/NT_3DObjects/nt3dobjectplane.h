#ifndef LT3DOBJECTPLANE_H
#define LT3DOBJECTPLANE_H

#include "NT_3DObjects/nt3dobject.h"

class NT3DObjectPlane : public NT3DObject
{
public:
    NT3DObjectPlane(const NCore::NCVector3D &position, const NCore::NCVector3D &normal);
    virtual ~NT3DObjectPlane() override;

    virtual bool intersect(const NTRay &ray, NTIntersection &intersect) override;

private:
    NCore::NCVector3D m_normal;
};

#endif // LT3DOBJECTPLANE_H
