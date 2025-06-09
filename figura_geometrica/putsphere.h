#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere: public FiguraGeometrica
{
private:
    int x0, y0, z0, raio;
public:
    PutSphere(int x0, int y0, int z0, int raio, float r, float g, float b, float a);
    ~PutSphere();
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
