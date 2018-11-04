#include "Matriz.h"
#include <iostream>
#include <windows.h>
using namespace std;

Matriz::Matriz()
{
   mat = new int*[0];
   mat[0] = new int[0];

   linhas = 0;
   colunas = 0;
}

Matriz::Matriz(int l, int c, const double &valor)
{
    linhas = l;
    colunas = c;

   mat = new int *[linhas];
   for(int i = 0;i < linhas; i++){
        mat[i] = new int[colunas];
   }

     for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            mat[i][j] = valor;
        }
     }
}

Matriz::~Matriz()
{
    for(int i = 0;i < linhas; i++){
           // cout<<"coluna["<<i+1<<"] deletada"<<endl;
        delete []mat[i];
    }

    delete []mat;
}

Matriz::Matriz(const Matriz &M){

    this->linhas = M.linhas;
    this->colunas = M.colunas;

     this->mat = new int*[M.linhas];
    for(int i = 0;i < M.linhas; i++){
        this->mat[i] = new int[M.colunas];
   }

   for(int i = 0;i < M.linhas; i++){
        for(int j = 0;j < M.colunas; j++){
            this->mat[i][j] = M.mat[i][j];
        }
     }

}


//funcoes
void const Matriz::imprimir()
{
  for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            cout <<mat[i][j]<< " ";
        }
        cout << endl;
     }
     cout << endl;
}


void Matriz::unit(){

     for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            if(i==j){
            mat[i][j] = 1;
            }
            else{
             mat[i][j] = 0;
            }
        }
     }
}

void Matriz::zeros(){
    for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            mat[i][j] = 0;
            }
        }
    }

void Matriz::ones(){
    for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            mat[i][j] = 1;
            }
        }
    }

//aqui sao as funcoes de sobrecarga

Matriz &Matriz::operator=(const Matriz &a){
    this->linhas = a.linhas;
    this->colunas = a.colunas;

    this->mat = new int*[linhas];
    for(int i = 0; i < linhas; i++){
        this->mat[i] = new int[colunas];
    }

   for(int i = 0; i < linhas; i++){
    for(int j = 0; j<colunas; j++){
        this->mat[i][j] = a.mat[i][j];
    }
   }

   return *this;
}

const Matriz Matriz::operator-(const Matriz &a) const{
    Matriz AUX(*this);

     if (a.linhas != linhas || a.colunas != colunas){
        cout<< "As matrizes tem valores diferentes de linhas ou colunas" << endl;
            }

    else {
    for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            AUX.mat[i][j] = this->mat[i][j] - a.mat[i][j];
            }
        }
    }
    AUX.imprimir();

    return AUX;
}

Matriz Matriz::operator-= (const Matriz &a){

    for(int i = 0;i < linhas; i++){
        for(int j = 0;j < colunas; j++){
            this->mat[i][j] = this->mat[i][j] - a.mat[i][j];
            }
        }
    return *this;
}


const Matriz Matriz:: operator* (const Matriz &a) const{
    Matriz AUX(this->linhas,a.colunas, 0);
    for (int i=0;i<this->linhas; i++) {
      for (int j=0; j<a.colunas; j++) {
        for (int k=0; k<this->colunas; k++) {
          AUX.mat[i][j] = AUX.mat[i][j] + (this->mat[i][k] * a.mat[k][j]);
        }
      }
    }

    return AUX;
}

Matriz Matriz:: operator*= (const int &a){

    for(int i = 0; i < this->linhas; i++){
        for(int j = 0; j< this->colunas; j++){
            this->mat[i][j] = (mat[i][j])*a;
        }
    }
    return *this;
}

bool Matriz::operator !=(const Matriz &a){
    if(this->linhas != a.linhas || this->colunas != a.colunas){
        return true;
    }

    for(int i = 0; i < this->linhas; i++){
        for(int j = 0; j< this->colunas; j++){
        if(mat[i][j] != a.mat[i][j]){
            return true;
            }
        }
    }
    return false;
}

istream &operator>>(istream &in, Matriz &a ){
    for(int i = 0; i < a.linhas; i++){
        for(int j = 0; j < a.colunas; j++){
            {
                cout << "insira o [" << i+1 << "," << j+1 << "]: ";
                in >> a.mat[i][j];
            }
        }
    }
    return in;
}


