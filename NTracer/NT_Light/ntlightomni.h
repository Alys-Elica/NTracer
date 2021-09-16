#ifndef LTLIGHTOMNI_H
#define LTLIGHTOMNI_H

#include "NT_Light/ntlight.h"

class NTLightOmni : public NTLight
{
public:
    NTLightOmni(const NCore::NCVector3D &position, const NTColor &lightColor, const double diffuseColor, const double specularColor);
    ~NTLightOmni() override;

    virtual NTColor getLightAt(NCore::NCVector3D normal, NCore::NCVector3D intersection, NTMaterial material) override;
};

#endif // LTLIGHTOMNI_H
