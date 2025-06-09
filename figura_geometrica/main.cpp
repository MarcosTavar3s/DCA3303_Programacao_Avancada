#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "figurageometrica.h"

#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"

#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"


int main(void){
    // classe abstrata que armazenará as figura
    std::vector<FiguraGeometrica*> figuras;

    // variaveis para a leitura do arquivo
    std::ifstream fin;
    std::string s;

    // variaveis para o tamanho do sculptor
    int nx, ny, nz;

    // abertura do arquivo
    fin.open("/");

    if(!fin.is_open()){
        std::cout << "Erro na leitura do arquivo" << std::endl;
        exit(0);
    }

    // leitura do cabecalho
    fin >> s;
    if(s.compare("dim")==0){
        std::cin >> nx >> ny >> nz;
    }
    else{
        std::cout<<"Arquivo no formato errado"<<std::endl;
        exit(0);
    }

    Sculptor sculptor(nx, ny, nz);

    while(fin.good()){
        fin >> s;

        if(!fin.good()){
            break;
        }

        if(s.compare("putvoxel")==0){
            int x0, y0, z0;
            float r, g, b, a;
            fin >> x0 >> y0 >> z0;
            fin >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
        }
        else if(s.compare("cutvoxel")==0){
            int x0, y0, z0;
            fin >> x0 >> y0 >> z0;
            figuras.push_back(new CutVoxel(x0, y0, z0));
        }
        else if(s.compare("putbox")==0){
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            fin >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(s.compare("cutbox")==0){
            int x0, x1, y0, y1, z0, z1;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
        else if(s.compare("putsphere")==0){
            int x0, y0, z0, raio;
            float r, g, b, a;
            fin >> x0 >> y0 >> z0 >> raio;
            fin >> r >> g >> b >> a;
            figuras.push_back(new PutSphere(x0, y0, z0, raio, r, g, b, a));
        }
        else if(s.compare("cutsphere")==0){
            int x0, y0, z0, raio;
            fin >> x0 >> y0 >> z0 >> raio;
            figuras.push_back(new CutSphere(x0, y0, z0, raio));
        }
        else if(s.compare("putellipsoid")==0){
            int x0, y0, z0, raiox, raioy, raioz;
            float r, g, b, a;
            fin >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz;
            fin >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(x0, y0, z0, raiox, raioy, raioz, r, g, b, a));
        }
        else if(s.compare("cutellipsoid")==0){
            int x0, y0, z0, raiox, raioy, raioz;
            fin >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz;
            figuras.push_back(new CutEllipsoid(x0, y0, z0, raiox, raioy, raioz));
        }


    }


    return 0;
}
