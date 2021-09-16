#ifndef LT3DOBJECT_H
#define LT3DOBJECT_H

#include "NT_Base/ntray.h"
#include "NT_Base/ntintersection.h"
#include "NT_Base/ntmaterial.h"

class NT3DObject
{
public:
    NT3DObject(const NCore::NCVector3D &position);
    virtual ~NT3DObject();

    virtual bool intersect(const NTRay &ray, NTIntersection &intersect) = 0;

    NCore::NCVector3D position() const;
    void setPosition(const NCore::NCVector3D &position);

    NTMaterial material() const;
    void setMaterial(const NTMaterial &material);

protected:
    NCore::NCVector3D m_position;
    NTMaterial m_material;
};

#endif // LT3DOBJECT_H
