#include "sculptor.h"

int main(void)
{
    // cria um escultor cuja matriz tem 50x50x50 voxels
    Sculptor pinguim(50, 50, 50);

    // cabeca do pinguim
    pinguim.setColor(0.2, 0.2, 0.2, 1.0);
    // insere esfera
    pinguim.putSphere(40, 40, 40, 7);

    // corta voxels extremos que ressaltam a cabeça do pinguim
    pinguim.cutVoxel(47, 40, 40);
    pinguim.cutVoxel(40, 47, 40);
    pinguim.cutVoxel(40, 40, 47);
    pinguim.cutVoxel(33, 40, 40);
    pinguim.cutVoxel(40, 33, 40);
    pinguim.cutVoxel(40, 40, 33);

    pinguim.setColor(1.0, 1.0, 1.0, 1.0);

    pinguim.cutSphere(37, 40, 40, 5);
    pinguim.putSphere(37, 40, 40, 5);
    pinguim.cutBox(32, 35, 35, 45, 35, 45);
        // // para mudar a cor do voxel
        // trono.setColor(0, 0.5, 1.0, 1.0); // azul
        // // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
        // trono.putEllipsoid(6, 5, 5, 3, 4, 3);
        // // trono.putBox(0, 9, 0, 9, 0, 9);
        // // trono.putSphere(50, 50, 50, 30);
        // // trono.cutSphere(6, 6, 6, 2);
        // // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
        // // trono.cutBox(1, 8, 1, 9, 1, 9);
        // // grava a escultura digital no arquivo "trono.off"
        // trono.writeOFF("trono.off");
    pinguim.writeOFF("pinguim.off");
}
