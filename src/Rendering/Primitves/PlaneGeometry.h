//
// Created by erdem on 26.12.2022.
//

#ifndef CRIMSON_PLANEGEOMETRY_H
#define CRIMSON_PLANEGEOMETRY_H

#include <Rendering/Geometry.h>

namespace Crimson
{
    class PlaneGeometry : public Geometry{
    public:
        PlaneGeometry(float width, float height, float uvScale=1.0f);
        float width;
        float height;
    };


}

#endif //CRIMSON_PLANEGEOMETRY_H
