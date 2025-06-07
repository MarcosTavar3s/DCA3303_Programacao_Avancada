#include "sculptor.h"

int main(void)
{
    // cria um escultor cuja matriz tem 50x50x50 voxels
    Sculptor pinguim(50, 50, 50);

    // eixos auxiliares para desenho
    // pinguim.putVoxel(35, 40, 40);
    // x - vermelho
    pinguim.setColor(1.0, 0.0, 0.0, 1.0);
    pinguim.putBox(0, 49, 0, 1, 0, 1);
    // y - verde
    pinguim.setColor(0.0, 1.0, 0.0, 1.0);
    pinguim.putBox(0, 1, 0, 49, 0, 1);
    // z - azul
    pinguim.setColor(0.0, 0.0, 1.0, 1.0);
    pinguim.putBox(0, 1, 0, 1, 0, 49);

    // cabeca do pinguim
    pinguim.setColor(0.2, 0.2, 0.2, 1.0);
    // insere esfera
    pinguim.putSphere(40, 40, 25, 7);

    // corta voxels extremos que ressaltam a cabeça do pinguim
    // pinguim.cutVoxel(47, 40, 40);
    // pinguim.cutVoxel(40, 47, 40);
    // pinguim.cutVoxel(40, 40, 47);
    // pinguim.cutVoxel(33, 40, 40);
    // pinguim.cutVoxel(40, 33, 40);
    // pinguim.cutVoxel(40, 40, 33);

    // parte branca
    pinguim.setColor(1.0, 1.0, 1.0, 1.0);

    pinguim.cutSphere(37, 40, 25, 5);
    pinguim.putSphere(37, 40, 25, 5);
    pinguim.cutBox(32, 35, 35, 45, 20, 30);


    // olhos do pinguim
    pinguim.setColor(0.0, 0.0, 0.5, 1.0);
    pinguim.putVoxel(35, 42, 27);
    pinguim.putVoxel(35, 42, 28);

    pinguim.putVoxel(35, 42, 22);
    pinguim.putVoxel(35, 42, 23);

    // bico
    pinguim.setColor(1.0, 0.4, 0.13, 1.0);
    pinguim.putBox(31, 35, 37, 39, 24, 27);

    // pe do pinguim
    pinguim.setColor(1.0, 0.4, 0.13, 1.0);
    pinguim.putBox(30, 42, 5, 7, 20, 23);
    pinguim.putBox(30, 42, 5, 7, 28, 31);

    // bracos do pinguim

    // barriga do pinguim - parte cinza
    pinguim.setColor(0.2, 0.2, 0.2, 1.0);
    pinguim.putEllipsoid(40, 20, 25, 8, 16, 8);

    // barriga do pinguim - parte branca
    pinguim.setColor(1.0, 1.0, 1.0, 1.0);

    // pinguim.putBox(35, 45, 10, 35, 35, 46);
    pinguim.putEllipsoid(38, 20, 25, 7, 11, 6);
    pinguim.cutVoxel(31, 20, 25);

    pinguim.setColor(1.0, 1.0, 1.0, 1.0);
    pinguim.cutBox(32, 34, 8, 28, 34, 46);

    // gravando a escultura no arquivo
    pinguim.writeOFF("pinguim.off");
}
