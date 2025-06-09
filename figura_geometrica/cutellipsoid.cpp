#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz) {
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->raiox = raiox;
    this->raioy = raioy;
    this->raioz = raioz;
}

CutEllipsoid::~CutEllipsoid(){}

void CutEllipsoid::draw(Sculptor &t){
    for (int i = -raiox; i <= raiox; ++i) {
        for (int j = -raioy; j <= raioy; ++j) {
            for (int k = -raioz; k <= raioz; ++k) {
                if (((i * i) / float(raiox * raiox)) + ((j * j) / float(raioy * raioy)) + ((k * k) / float(raioz * raioz)) <= 1) {
                    t.cutVoxel(x0 + i, y0 + j, z0 + k);
                };
            }
        }
    }
}
