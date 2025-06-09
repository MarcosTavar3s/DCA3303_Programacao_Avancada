#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int x0, int y0, int z0, int raio, float r, float g, float b, float a) {
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->raio = raio;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutSphere::~PutSphere(){}

void PutSphere::draw(Sculptor &t){
    t.setColor(r,g,b,a);

    for (int i = 0; i <= raio; ++i) {
        for (int j = 0; j <= raio; ++j) {
            for (int k = 0; k <= raio; ++k) {

                if (sqrt((i * i) + (j * j) + (k * k)) <= raio) {
                    t.putVoxel(x0 + i, y0 + j, z0 + k);
                    t.putVoxel(x0 - i, y0 - j, z0 - k);
                    t.putVoxel(x0 - i, y0 - j, z0 + k);
                    t.putVoxel(x0 - i, y0 + j, z0 - k);
                    t.putVoxel(x0 - i, y0 + j, z0 + k);
                    t.putVoxel(x0 + i, y0 - j, z0 - k);
                    t.putVoxel(x0 + i, y0 + j, z0 - k);
                    t.putVoxel(x0 + i, y0 - j, z0 + k);
                }
            }
        }
    }

}
