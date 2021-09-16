#include "ntcamera.h"

NTCamera::NTCamera(int width, int height, const NCore::NCVector3D &position, const NCore::NCVector3D &lookPoint, const NCore::NCVector3D &upVector)
{
    m_width = width;
    m_height = height;
    m_position = position;
    m_upVector = upVector;

    m_viewplaneWidth = 0.5;
    m_viewplaneHeight = 0.35;
    m_viewplaneDist = 1.0;

    // Nous calculons le vecteur directeur de la camera
    m_direction = lookPoint - m_position;
    m_direction.normalize();

    // Maintenant nous calculons le vecteur droite (en utilisant le produit en croix)
    m_rightVector = NCore::NCVector3D::crossProduct(m_upVector, m_direction);

    // De meme pour le "vrai" vecteur haut.
    m_upVector = NCore::NCVector3D::crossProduct(m_direction, m_rightVector);

    // Maintenant nous avons toutes les informations pour détérminer la position
    // en haut à gauche du viewplane.
    m_viewPlaneUpLeft = m_position + ((m_direction * m_viewplaneDist) + (m_upVector * (m_viewplaneHeight / 2.0))) - (m_rightVector * (m_viewplaneWidth / 2.0));
}

int NTCamera::width() const
{
    return m_width;
}

int NTCamera::height() const
{
    return m_height;
}

NCore::NCVector3D NTCamera::getDirectionVector(double x, double y)
{
    double xIndent = m_viewplaneWidth / (double)m_width;
    double yIndent = m_viewplaneHeight / (double)m_height;

    return (m_viewPlaneUpLeft + m_rightVector * xIndent * x - m_upVector * yIndent * y) - m_position;
}

NCore::NCVector3D NTCamera::getPosition() const
{
    return m_position;
}

NCore::NCVector3D NTCamera::getDirection() const
{
    return m_direction;
}

NCore::NCVector3D NTCamera::getUpVector() const
{
    return m_upVector;
}

NCore::NCVector3D NTCamera::getRightVector() const
{
    return m_rightVector;
}
