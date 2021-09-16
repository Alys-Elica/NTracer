#include "nt3dobject.h"

NT3DObject::NT3DObject(const NCore::NCVector3D &position)
{
    m_position = position;
}

NT3DObject::~NT3DObject()
{

}

NCore::NCVector3D NT3DObject::position() const
{
    return m_position;
}

void NT3DObject::setPosition(const NCore::NCVector3D &position)
{
    m_position = position;
}

NTMaterial NT3DObject::material() const
{
    return m_material;
}

void NT3DObject::setMaterial(const NTMaterial &material)
{
    m_material = material;
}
