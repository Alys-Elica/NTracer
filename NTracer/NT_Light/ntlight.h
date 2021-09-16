#ifndef LTLIGHT_H
#define LTLIGHT_H

#include <NCore/ncvector3d.h>

#include "NT_Base/ntmaterial.h"

class NTLight
{
public:
    NTLight(const NCore::NCVector3D &position, const NTColor &lightColor, const double diffuseColor, const double specularColor);
    virtual ~NTLight();

    virtual NTColor getLightAt(NCore::NCVector3D normal, NCore::NCVector3D intersection, NTMaterial material) = 0;

    NCore::NCVector3D getPosition() const;
    void setPosition(const NCore::NCVector3D &position);

    NTColor getLightColor() const;
    void setLightColor(const NTColor &lightColor);

    double getDiffuseColor() const;
    void setDiffuseColor(double diffuseColor);

    double getSpecularColor() const;
    void setSpecularColor(double specularColor);

protected:
    NCore::NCVector3D m_position;
    NTColor m_lightColor;
    double m_diffuseColor;
    double m_specularColor;
};

#endif // LTLIGHT_H
