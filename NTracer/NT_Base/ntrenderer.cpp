#include "NT_Base/ntrenderer.h"

LTRenderer::LTRenderer()
{
}

NTIntersection LTRenderer::nearestIntersection(const NTScene &scene, const NTRay &ray)
{
    // TODO: Fix this
    NTIntersection nearInter;

    for (NT3DObject *obj : scene.objects()) {
        NTRay tmpRay = ray;

        if (obj == tmpRay.origin()) {
            const double epsilon = 0.00000000000000000001;
            NCore::NCVector3D point = ray.startVector() + (ray.directionVector() / epsilon);
            //point.normalize();
            tmpRay.setStartVector(point);
        }

        NTIntersection intersectPt;
        if (obj->intersect(tmpRay, intersectPt)) {
            // If no previous intersection or intersection closer
            double distRayInterPt = tmpRay.startVector().distanceToPoint(intersectPt.point());
            double distRayInterNear = tmpRay.startVector().distanceToPoint(nearInter.point());
            if (!nearInter.object() || (distRayInterPt < distRayInterNear)) {
                nearInter = intersectPt;
            }
        }
    }

    return nearInter;
}

NTColor LTRenderer::rayTrace(const NTScene &scene, const NTRay &ray, const int recur)
{
    NTColor resColor(0.0, 0.0, 0.0);

    // Nearest intersection
    NTIntersection nearInter = nearestIntersection(scene, ray);

    if (!nearInter.object())
        return resColor;

    bool activateReflection = true;
    bool activateRefraction = false;

    // Lights
    for (NTLight *lht : scene.lights()) {
        bool inShadow = false;
        NCore::NCVector3D lightVector = nearInter.point() - lht->getPosition();
        double lightToObjDist = lightVector.lengthSquared();
        lightVector.normalize();

        NTRay rayLht;
        rayLht.setStartVector(lht->getPosition());
        rayLht.setDirectionVector(lightVector);

        for (NT3DObject *obj : scene.objects()) {
            if (obj == nearInter.object() || obj == ray.origin())
                continue;

            NTIntersection intersectionLht;
            if (obj->intersect(rayLht, intersectionLht)) {
                double lhtToInterDist = (intersectionLht.point() - lht->getPosition()).lengthSquared();
                if (lhtToInterDist < lightToObjDist) {
                    inShadow = true;
                    break;
                }
            }
        }

        if (!inShadow)
            resColor += lht->getLightAt(nearInter.normal(), nearInter.point(), nearInter.object()->material());
    }

    double reflectivity = nearInter.object()->material().reflectivity();
    if (reflectivity > 0.0 && recur > 0 && activateReflection) {
        // TODO: Fix this
        NCore::NCVector3D dir = ray.directionVector();
        NCore::NCVector3D norm = nearInter.normal();
        dir.normalize();
        //norm.normalize(); // Already done

        NCore::NCVector3D reflectedVector = dir - (2.0 * norm * norm.dotProduct(dir));

        reflectedVector.normalize();

        NTRay reflectedRay;
        reflectedRay.setOrigin(nearInter.object());
        reflectedRay.setStartVector(nearInter.point());
        reflectedRay.setDirectionVector(reflectedVector);

        NTColor coulRefl = rayTrace(scene, reflectedRay, recur - 1);

        resColor *= (1.0 - reflectivity);
        resColor += (coulRefl * reflectivity);
    }

    double refractivity = nearInter.object()->material().refractivity();
    if (refractivity > 0.0 && recur > 0 && activateRefraction) {
        // TODO: Fix this
        NCore::NCVector3D dir = ray.directionVector();
        NCore::NCVector3D norm = nearInter.normal();

        double n = refractivity;

        double cosI = NCore::NCVector3D::dotProduct(dir, norm);

        NCore::NCVector3D refractedVector = dir * n - norm * (-cosI + n * cosI);

        NTRay refractedRay;
        refractedRay.setOrigin(nearInter.object());
        refractedRay.setStartVector(nearInter.point());
        refractedRay.setDirectionVector(refractedVector);
        NTColor coulRefr = rayTrace(scene, refractedRay, recur - 1);

        resColor *= (1.0 - refractivity);
        resColor += (coulRefr * refractivity);
    }

    return resColor;
}

NCore::NCImage LTRenderer::render(const NTScene &scene)
{
    int width = scene.camera()->width();
    int height = scene.camera()->width();

    NCore::NCImage img(width, height);

    const int gridSize = 80;
    std::list<NCore::NCRect> rects;

    for (int y = 0; y < height; y += gridSize) {
        for (int x = 0; x < width; x += gridSize) {
            NCore::NCRect gridRect(x, y, gridSize, gridSize);

            gridRect.setRight(std::min(width - 1, gridRect.right()));
            gridRect.setBottom(std::min(height - 1, gridRect.bottom()));

            rects.push_back(gridRect);
        }
    }

    for (const NCore::NCRect &rect : rects) {
        NTRenderBlock block = renderBlock(scene, rect);

        for (size_t x = 0; x < block.image.width(); ++x)
            for (size_t y = 0; y < block.image.height(); ++y)
                img.setPixel(x + block.x, y + block.y, block.image.pixel(x, y));
    }

    return img;
}

NTRenderBlock LTRenderer::renderBlock(const NTScene &scene, const NCore::NCRect &rectangle)
{
    NCore::NCImage img(rectangle.width(), rectangle.height());

    const int recursion = 20;

    for (int y = 0; y < rectangle.height(); ++y) {
        for (int x = 0; x < rectangle.width(); ++x) {
            NTRay ray;
            NCore::NCVector3D vectDir = scene.camera()->getDirectionVector(x + rectangle.left(), y + rectangle.top());
            vectDir.normalize();
            ray.setStartVector(scene.camera()->getPosition());
            ray.setDirectionVector(vectDir);

            NTColor resColor = rayTrace(scene, ray, recursion);

            // Set final color to image
            resColor.r = std::min(resColor.r, 1.0);
            resColor.g = std::min(resColor.g, 1.0);
            resColor.b = std::min(resColor.b, 1.0);
            NCore::NCRgb diffuse(resColor.r * 255, resColor.g * 255, resColor.b * 255);
            img.setPixel(x, y, diffuse);
        }
    }

    NTRenderBlock blk;
    blk.x = rectangle.left();
    blk.y = rectangle.top();
    blk.image = img;

    return blk;
}
