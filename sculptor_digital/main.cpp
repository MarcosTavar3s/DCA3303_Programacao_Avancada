#include "sculptor.h"

int main(void)
{
    // cria um escultor cuja matriz tem 50x50x50 voxels
    Sculptor pinguim(50, 50, 50);

    // eixos auxiliares para desenho
    // pinguim.putVoxel(35, 40, 40);
    // x - vermelho
    // pinguim.setColor(1.0, 0.0, 0.0, 1.0);
    // pinguim.putBox(0, 49, 0, 1, 0, 1);
    // // y - verde
    // pinguim.setColor(0.0, 1.0, 0.0, 1.0);
    // pinguim.putBox(0, 1, 0, 49, 0, 1);
    // // z - azul
    // pinguim.setColor(0.0, 0.0, 1.0, 1.0);
    // pinguim.putBox(0, 1, 0, 1, 0, 49);

    // cabeca do pinguim
    pinguim.setColor(0.2, 0.2, 0.2, 1.0);

    // parte preta
    pinguim.putSphere(40, 40, 25, 7);

    // parte branca
    pinguim.setColor(1.0, 1.0, 1.0, 1.0);
    pinguim.cutSphere(37, 40, 25, 5);
    pinguim.putSphere(37, 40, 25, 5);

    pinguim.cutBox(32, 35, 35, 45, 20, 30);

    // olhos do pinguim
    pinguim.setColor(0.3, 0.0, 0.5, 1.0);
    pinguim.putVoxel(35, 42, 27);
    pinguim.putVoxel(35, 42, 28);

    pinguim.putVoxel(35, 42, 22);
    pinguim.putVoxel(35, 42, 23);

    // bico
    pinguim.setColor(1.0, 0.4, 0.13, 1.0);
    pinguim.putBox(31, 35, 38, 40, 24, 27);

    // conexao com o bico
    pinguim.setColor(0.2, 0.2, 0.2, 1.0);
    pinguim.putBox(35, 36, 40, 45, 24, 27);
    pinguim.putBox(34, 35, 40, 44, 24, 27);

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


    // pe do pinguim
    pinguim.setColor(1.0, 0.4, 0.13, 1.0);
    pinguim.putBox(30, 42, 4, 7, 20, 23);
    pinguim.putBox(30, 42, 4, 7, 28, 31);

    // bracos do pinguim
    pinguim.setColor(0.2, 0.2, 0.2, 1.0);

    // braco 1
    pinguim.putEllipsoid(40, 20, 35, 4, 8, 2);
    pinguim.cutVoxel(40, 20, 33);
    pinguim.cutVoxel(40, 20, 37);

    //braco 2
    pinguim.putEllipsoid(40, 20, 15, 4, 8, 2);
    pinguim.cutVoxel(40, 20, 13);
    pinguim.cutVoxel(40, 20, 17);

    // conexoes do braco
    pinguim.putBox(38, 42, 27, 29, 16, 20);
    pinguim.putBox(38, 42, 27, 29, 31, 35);


    // gravando a escultura no arquivo
    pinguim.writeOFF("pinguim.off");
}
