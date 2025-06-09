#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz, float r, float g, float b, float a) {
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->raiox = raiox;
    this->raioy = raioy;
    this->raioz = raioz;
    this->r = r;
    this->b = b;
    this->g = g;
    this->a = a;
}

PutEllipsoid::~PutEllipsoid(){}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);

    for (int i = -raiox; i <= raiox; ++i) {
        for (int j = -raioy; j <= raioy; ++j) {
            for (int k = -raioz; k <= raioz; ++k) {
                if (((i * i) / float(raiox * raiox)) + ((j * j) / float(raioy * raioy)) + ((k * k) / float(raioz * raioz)) <= 1) {
                    t.putVoxel(x0 + i, y0 + j, z0 + k);
                };
            }
        }
    }
}
