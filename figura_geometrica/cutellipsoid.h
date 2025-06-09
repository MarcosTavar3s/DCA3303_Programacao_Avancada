#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

class CutEllipsoid:public FiguraGeometrica
{
private:
    int x0, y0, z0, raiox, raioy, raioz;
public:
    CutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz);
    ~CutEllipsoid();
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
