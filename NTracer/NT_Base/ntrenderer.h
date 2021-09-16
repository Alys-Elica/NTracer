#ifndef LTRENDERER_H
#define LTRENDERER_H

#include <NCore/ncimage.h>
#include <NCore/ncrect.h>

#include "NT_Base/ntscene.h"

struct NTRenderBlock {
    int x;
    int y;
    NCore::NCImage image;
};

class LTRenderer
{
public:
    LTRenderer();

    static NCore::NCImage render(const NTScene &scene);
    static NTRenderBlock renderBlock(const NTScene &scene, const NCore::NCRect &rectangle);

private:
    static inline NTIntersection nearestIntersection(const NTScene &scene, const NTRay &ray);
    static inline NTColor rayTrace(const NTScene &scene, const NTRay &ray, const int recur);
};

#endif // LTRENDERER_H
