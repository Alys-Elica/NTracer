#include "ntscene.h"

NTScene::NTScene()
{

}

NTScene::~NTScene()
{
    clearScene();
}

void NTScene::clearScene()
{
    delete m_camera;
    m_camera = nullptr;
    for (NT3DObject *obj : m_objects)
        delete obj;
    m_objects.clear();
    for (NTLight *lht : m_lights)
        delete lht;
    m_lights.clear();
}

void NTScene::setCamera(NTCamera *camera)
{
    m_camera = camera;
}

void NTScene::addObject(NT3DObject *object)
{
    m_objects.push_back(object);
}

void NTScene::addLight(NTLight *light)
{
    m_lights.push_back(light);
}

NTCamera *NTScene::camera() const
{
    return m_camera;
}

std::list<NT3DObject *> NTScene::objects() const
{
    return m_objects;
}

std::list<NTLight *> NTScene::lights() const
{
    return m_lights;
}
