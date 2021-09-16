#ifndef LTMATERIAL_H
#define LTMATERIAL_H

#include "NT_Base/ntcolor.h"

class NTMaterial
{
public:
    NTMaterial();

    NTColor specularColor() const;
    void setSpecularColor(const NTColor &value);

    NTColor diffuseColor() const;
    void setDiffuseColor(const NTColor &value);

    NTColor ambientColor() const;
    void setAmbientColor(const NTColor &value);

    NTColor selfIllumColor() const;
    void setSelfIllumColor(const NTColor &value);

    double shininess() const;
    void setShininess(double value);

    double shineStrength() const;
    void setShineStrength(double value);

    double transmittivity() const;
    void setTransmittivity(double value);

    double reflectivity() const;
    void setReflectivity(double value);

    double refractivity() const;
    void setRefractivity(double refractivity);

private:
    NTColor m_specularColor;
    NTColor m_diffuseColor;
    NTColor m_ambientColor;
    NTColor m_selfIllumColor;

    double m_shininess = 0.0;
    double m_shineStrength = 0.0;
    double m_transmittivity = 0.0;
    double m_reflectivity = 0.0;
    double m_refractivity = 0.0;
};

#endif // LTMATERIAL_H
