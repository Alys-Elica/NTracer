#ifndef LT3DSPHERE_H
#define LT3DSPHERE_H

#include "NT_3DObjects/nt3dobject.h"

class NT3DObjectSphere : public NT3DObject
{
public:
    NT3DObjectSphere(const NCore::NCVector3D &position, const double radius);
    virtual ~NT3DObjectSphere() override;

    virtual bool intersect(const NTRay &ray, NTIntersection &intersect) override;

private:
    double m_radius;
};

#endif // LT3DSPHERE_H
