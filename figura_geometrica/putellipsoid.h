#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class PutEllipsoid: public FiguraGeometrica
{
private:
    int x0, y0, z0, raiox, raioy, raioz;
    float r, g, b, a;
public:
    PutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz, float r, float g, float b, float a);
    ~PutEllipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
