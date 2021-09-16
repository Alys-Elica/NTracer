#include "ntmaterial.h"

NTMaterial::NTMaterial()
{

}

NTColor NTMaterial::specularColor() const
{
    return m_specularColor;
}

void NTMaterial::setSpecularColor(const NTColor &value)
{
    m_specularColor = value;
}

NTColor NTMaterial::diffuseColor() const
{
    return m_diffuseColor;
}

void NTMaterial::setDiffuseColor(const NTColor &value)
{
    m_diffuseColor = value;
}

NTColor NTMaterial::ambientColor() const
{
    return m_ambientColor;
}

void NTMaterial::setAmbientColor(const NTColor &value)
{
    m_ambientColor = value;
}

NTColor NTMaterial::selfIllumColor() const
{
    return m_selfIllumColor;
}

void NTMaterial::setSelfIllumColor(const NTColor &value)
{
    m_selfIllumColor = value;
}

double NTMaterial::shininess() const
{
    return m_shininess;
}

void NTMaterial::setShininess(double value)
{
    m_shininess = value;
}

double NTMaterial::shineStrength() const
{
    return m_shineStrength;
}

void NTMaterial::setShineStrength(double value)
{
    m_shineStrength = value;
}

double NTMaterial::transmittivity() const
{
    return m_transmittivity;
}

void NTMaterial::setTransmittivity(double value)
{
    m_transmittivity = value;
}

double NTMaterial::reflectivity() const
{
    return m_reflectivity;
}

void NTMaterial::setReflectivity(double value)
{
    m_reflectivity = value;
}

double NTMaterial::refractivity() const
{
    return m_refractivity;
}

void NTMaterial::setRefractivity(double refractivity)
{
    m_refractivity = refractivity;
}
