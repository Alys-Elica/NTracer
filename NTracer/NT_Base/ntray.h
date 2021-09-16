#ifndef LTRAY_H
#define LTRAY_H

#include <NCore/ncvector3d.h>

class NT3DObject;
class NTRay
{
public:
    NTRay();

    NCore::NCVector3D startVector() const;
    void setStartVector(const NCore::NCVector3D &startVector);

    NCore::NCVector3D directionVector() const;
    void setDirectionVector(const NCore::NCVector3D &directionVector);

    NT3DObject *origin() const;
    void setOrigin(NT3DObject *origin);

private:
    NCore::NCVector3D m_startVector;
    NCore::NCVector3D m_directionVector;
    NT3DObject *m_origin = nullptr;
};

#endif // LTRAY_H
