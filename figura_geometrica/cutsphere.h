#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class CutSphere: public FiguraGeometrica
{
private:
    int x0, y0, z0, raio;
public:
    CutSphere(int x0, int y0, int z0, int raio);
    ~CutSphere();
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
