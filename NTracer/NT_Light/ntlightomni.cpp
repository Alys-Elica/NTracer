#include "ntlightomni.h"

NTLightOmni::NTLightOmni(const NCore::NCVector3D &position, const NTColor &lightColor, const double diffuseColor, const double specularColor) :
    NTLight(position, lightColor, diffuseColor, specularColor)
{

}

NTLightOmni::~NTLightOmni()
{

}

NTColor NTLightOmni::getLightAt(NCore::NCVector3D normal, NCore::NCVector3D intersection, NTMaterial material)
{
    NTColor finalColor(0.0, 0.0, 0.0);

    NCore::NCVector3D lightVector = intersection - m_position;

    lightVector.normalize();

    normal.normalize();

    double angle = NCore::NCVector3D::dotProduct(normal, -lightVector);

    if (angle > 0)
        finalColor = material.diffuseColor() * (m_lightColor * m_diffuseColor) * angle;

    return finalColor;
}
