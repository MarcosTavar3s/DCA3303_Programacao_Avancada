#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int x0, int y0, int z0, int raio) {
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->raio = raio;
}

CutSphere::~CutSphere(){}

void CutSphere::draw(Sculptor &t){
    for (int i = 0; i <= raio; ++i) {
        for (int j = 0; j <= raio; ++j) {
            for (int k = 0; k <= raio; ++k) {

                if (sqrt((i * i) + (j * j) + (k * k)) <= raio) {
                    t.cutVoxel(x0 + i, y0 + j, z0 + k);
                    t.cutVoxel(x0 - i, y0 - j, z0 - k);
                    t.cutVoxel(x0 - i, y0 - j, z0 + k);
                    t.cutVoxel(x0 - i, y0 + j, z0 - k);
                    t.cutVoxel(x0 - i, y0 + j, z0 + k);
                    t.cutVoxel(x0 + i, y0 - j, z0 - k);
                    t.cutVoxel(x0 + i, y0 + j, z0 - k);
                    t.cutVoxel(x0 + i, y0 - j, z0 + k);
                }
            }
        }
    }
}
