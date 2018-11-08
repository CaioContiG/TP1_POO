#include "Matriz.h"
#include <iostream>
#include <windows.h>
using namespace std;

//construtor 1
Matriz::Matriz()
{
   mat = new int*[0];
   mat[0] = new int[0];

   linhas = 0;
   colunas = 0;
}

//contrutor 2
Matriz::Matriz(int l, int c, const double &valor) : linhas(l), colunas(c)
{

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

//construtor 3
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

//Destrutor
Matriz::~Matriz()
{
    for(int i = 0;i < linhas; i++){
        delete []mat[i];}
    delete []mat;
}


///funcoes------------------------------------------------------------

//imprimir inicial de teste
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
    try{
        if(this->linhas != this->colunas){throw 01;}

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
    }catch (const int error){cout<<"Matriz nao e quadrada!"<<error<<endl;}
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


///Funcoes de sobrecarga---------------------------------------------------------

Matriz &Matriz::operator=(const Matriz &a){

    try{
        if(a.linhas != this->linhas || a.colunas != this->colunas){throw 01;}

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

  }catch(const int error){cout<<"Erro, linha ou coluna diferentes"<<error<<endl;}
}

//---
Matriz Matriz::operator~(){
        Matriz A(colunas,linhas);
        for(int i = 0; i < linhas;i++){
            for(int j = 0; j< colunas;j++){
                A.mat[i][j] = mat[j][i];
            }
        }
        return A;
}

//---
const Matriz Matriz::operator-(const Matriz &a) const{
    Matriz AUX(*this);
    try{
            if (a.linhas != linhas || a.colunas != colunas){throw 01;}

            for(int i = 0;i < linhas; i++){
                for(int j = 0;j < colunas; j++){
                    AUX.mat[i][j] = this->mat[i][j] - a.mat[i][j];
                    }
                }
            return AUX;

    }catch(const int error){cout<<"As matrizes tem valores diferentes de linhas ou colunas"<<error<<endl;}
}

//---
Matriz &Matriz::operator-= (const Matriz &a){
    try{if (a.linhas != linhas || a.colunas != colunas){throw 01;}

        for(int i = 0;i < linhas; i++){
            for(int j = 0;j < colunas; j++){
                this->mat[i][j] = this->mat[i][j] - a.mat[i][j];
                }
            }
        return *this;
    }catch(const int error){cout<<"As matrizes tem valores diferentes de linhas ou colunas"<<error<<endl;}
}


//---
const Matriz Matriz::operator+ (const Matriz &A)const{
   try{ Matriz C(linhas,colunas);
    if (A.linhas != linhas || A.colunas != colunas){
        throw 01;
            }
    for(int i = 0;i <linhas;++i)
        for(int j = 0;j <colunas;++j)
           C.mat[i][j] = A.mat[i][j] + mat[i][j];

        return C;
        }catch (const int error){
        cout<<"Erro, linha ou coluna"<< error<<endl;}
}


//--
Matriz &Matriz::operator+= (const Matriz &a){
    try{if (a.linhas != linhas || a.colunas != colunas){
        throw 01;
            }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j<colunas; j++){
            this->mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
   return *this;}catch(const int error){
                cout<<"Erro, linha ou coluna"<< error<<endl;}

}

//---
const Matriz Matriz:: operator* (const Matriz &a) const{

    try{if(this->colunas != a.linhas){throw 01;}
        Matriz AUX(this->linhas,a.colunas, 0);
        for (int i=0;i<this->linhas; i++) {
            for (int j=0; j<a.colunas; j++) {
                for (int k=0; k<this->colunas; k++) {
                    AUX.mat[i][j] = AUX.mat[i][j] + (this->mat[i][k] * a.mat[k][j]);
                    }
                }
            }
        return AUX;
        }catch(const int error){cout<<"Matrizes nao podem ser multiplicadas."<<error<<endl;}

}
const Matriz Matriz:: operator*= (const Matriz &a){

  try{if(this->colunas != a.linhas){throw 01;}
        Matriz AUX(this->linhas,a.colunas, 0);
        for (int i=0;i<this->linhas; i++) {
            for (int j=0; j<a.colunas; j++) {
                for (int k=0; k<this->colunas; k++) {
                    AUX.mat[i][j] = AUX.mat[i][j] + (this->mat[i][k] * a.mat[k][j]);
                    }
                }
            }
            *this = AUX;
        return *this;
        }catch(const int error){cout<<"Matrizes nao podem ser multiplicadas."<<error<<endl;}

}

//---
Matriz Matriz:: operator*= (const int &a){

    for(int i = 0; i < this->linhas; i++){
        for(int j = 0; j< this->colunas; j++){
            this->mat[i][j] = (mat[i][j])*a;
        }
    }
    return *this;
}

//---
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


//--
bool Matriz::operator ==(const Matriz &a){
    if(this->linhas != a.linhas || this->colunas != a.colunas){
       return false;
    }

    for(int i = 0; i < this->linhas; i++){
        for(int j = 0; j< this->colunas; j++){
        if(mat[i][j] == a.mat[i][j]){
            return true;
            }
        }
    }
    return false;
}

//---
istream &operator>>(istream &in, const Matriz &a ){
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

//---
ostream& operator<< (ostream& out,const Matriz& a){
        for(int i = 0;i<a.linhas;++i) {
        out <<endl;
            for(int j = 0;j<a.colunas;++j){
                out << a.mat[i][j];
                out << " ";}
                }
        out <<endl;
                return out;
}

