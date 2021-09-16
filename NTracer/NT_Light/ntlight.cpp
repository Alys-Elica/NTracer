#include "ntlight.h"

NTLight::NTLight(const NCore::NCVector3D &position, const NTColor &lightColor, const double diffuseColor, const double specularColor)
{
    m_position = position;
    m_lightColor = lightColor;
    m_diffuseColor = diffuseColor;
    m_specularColor = specularColor;
}

NTLight::~NTLight()
{

}

NCore::NCVector3D NTLight::getPosition() const
{
    return m_position;
}

void NTLight::setPosition(const NCore::NCVector3D &position)
{
    m_position = position;
}

NTColor NTLight::getLightColor() const
{
    return m_lightColor;
}

void NTLight::setLightColor(const NTColor &lightColor)
{
    m_lightColor = lightColor;
}

double NTLight::getDiffuseColor() const
{
    return m_diffuseColor;
}

void NTLight::setDiffuseColor(double diffuseColor)
{
    m_diffuseColor = diffuseColor;
}

double NTLight::getSpecularColor() const
{
    return m_specularColor;
}

void NTLight::setSpecularColor(double specularColor)
{
    m_specularColor = specularColor;
}
