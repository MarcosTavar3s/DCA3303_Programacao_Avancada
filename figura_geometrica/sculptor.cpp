#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream> // debug

// construtor------------------------------
Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;

    // aloca a matriz de voxels v
    v = new Voxel **[nx];

    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel *[ny];

        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                v[i][j][k].show = false;
            }
        }
    }
}
// fim do construtor------------------------

// destrutor-------------------------------
Sculptor::~Sculptor() {
    // liberacao da memoria
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }

        delete[] v[i];
    }

    delete[] v;
}
// fim do destrutor-------------------------

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    // verifica se esta dentro do range da matriz
    if (x>=0 && y>=0 && z>=0 && x < nx && y < ny && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].b = b;
        v[x][y][z].g = g;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    // verifica se esta dentro do range da matriz
    if (x < nx && y < ny && z < nz) {
        v[x][y][z].show = false;
    }
}

void Sculptor::writeOFF(const char *filename) {
    std::ofstream fout;
    int nvoxels = 0;

    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }
    fout << "OFF\n";

    // conta quantos voxels estao marcados com show == true
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].show) {
                    nvoxels++;
                }
            }
        }
    }

    // numero de vertices e numero de faces
    fout << nvoxels * 8 << " " << nvoxels * 6 << " 0\n";

    // escrever os vertices
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].show) {

                    fout << (i - 0.5) << " " << (j + 0.5) << " " << (k - 0.5)
                    << std::endl;
                    fout << (i - 0.5) << " " << (j - 0.5) << " " << (k - 0.5)
                         << std::endl;
                    fout << (i + 0.5) << " " << (j - 0.5) << " " << (k - 0.5)
                         << std::endl;
                    fout << (i + 0.5) << " " << (j + 0.5) << " " << (k - 0.5)
                         << std::endl;
                    fout << (i - 0.5) << " " << (j + 0.5) << " " << (k + 0.5)
                         << std::endl;
                    fout << (i - 0.5) << " " << (j - 0.5) << " " << (k + 0.5)
                         << std::endl;
                    fout << (i + 0.5) << " " << (j - 0.5) << " " << (k + 0.5)
                         << std::endl;
                    fout << (i + 0.5) << " " << (j + 0.5) << " " << (k + 0.5)
                         << std::endl;
                }
            }
        }
    }

    int voxel_aux = 0;

    // escrever as faces
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].show) {
                    fout << std::fixed << std::setprecision(1);
                    fout << "4" << " " << voxel_aux << " " << voxel_aux + 3 << " "
                         << voxel_aux + 2 << " " << voxel_aux + 1 << " " << v[i][j][k].r
                         << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << std::endl;

                    fout << "4" << " " << voxel_aux + 4 << " " << voxel_aux + 5 << " "
                         << voxel_aux + 6 << " " << voxel_aux + 7 << " " << v[i][j][k].r
                         << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << std::endl;

                    fout << "4" << " " << voxel_aux << " " << voxel_aux + 1 << " "
                         << voxel_aux + 5 << " " << voxel_aux + 4 << " " << v[i][j][k].r
                         << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << std::endl;

                    fout << "4" << " " << voxel_aux << " " << voxel_aux + 4 << " "
                         << voxel_aux + 7 << " " << voxel_aux + 3 << " " << v[i][j][k].r
                         << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << std::endl;

                    fout << "4" << " " << voxel_aux + 3 << " " << voxel_aux + 7 << " "
                         << voxel_aux + 6 << " " << voxel_aux + 2 << " " << v[i][j][k].r
                         << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << std::endl;

                    fout << "4" << " " << voxel_aux + 1 << " " << voxel_aux + 2 << " "
                         << voxel_aux + 6 << " " << voxel_aux + 5 << " " << v[i][j][k].r
                         << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << std::endl;

                    voxel_aux += 8;
                }
            }
        }
    }

    fout.close();
}
