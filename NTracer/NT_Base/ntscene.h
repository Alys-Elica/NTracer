#ifndef LTSCENE_H
#define LTSCENE_H

#include <list>

#include "NT_Base/ntcamera.h"
#include "NT_3DObjects/nt3dobject.h"
#include "NT_Light/ntlight.h"

class NTScene
{
public:
    NTScene();
    ~NTScene();

    void clearScene();

    void setCamera(NTCamera* camera);
    void addObject(NT3DObject* object);
    void addLight(NTLight* light);

    NTCamera *camera() const;
    std::list<NT3DObject *> objects() const;
    std::list<NTLight *> lights() const;

private:
    NTCamera *m_camera;
    std::list<NT3DObject*> m_objects;
    std::list<NTLight*> m_lights;
};

#endif // LTSCENE_H
