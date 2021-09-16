#ifndef LTCAMERA_H
#define LTCAMERA_H

#include "NT_3DObjects/nt3dobject.h"

class NTCamera
{
public:
    NTCamera(int width, int height, const NCore::NCVector3D &position, const NCore::NCVector3D &lookPoint, const NCore::NCVector3D &upVector);

    int width() const;
    int height() const;
    NCore::NCVector3D getDirectionVector(double x, double y);
    NCore::NCVector3D getPosition() const;
    NCore::NCVector3D getDirection() const;
    NCore::NCVector3D getUpVector() const;
    NCore::NCVector3D getRightVector() const;

private:
    int m_width;
    int m_height;

    double m_viewplaneWidth;
    double m_viewplaneHeight;
    double m_viewplaneDist;
    NCore::NCVector3D m_viewPlaneUpLeft;

    NCore::NCVector3D m_position;
    NCore::NCVector3D m_direction;
    NCore::NCVector3D m_upVector;
    NCore::NCVector3D m_rightVector;
};

#endif // LTCAMERA_H
