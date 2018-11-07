#include<iostream>
#include "Matriz.h"
#include<exception>
using namespace std;

Matriz::Matriz()
{
    mat = new int*[0];
    mat[0] = new int[0];
    linhas = 0;
    colunas = 0;
    }

Matriz::Matriz(int l,int c,const double &valor)
{
    linhas = l;
    colunas = c;
    mat = new int*[l];
    for(int i = 0;i<l;i++)
        mat[i] = new int[c];
    for(int i = 0;i <l;++i)
        for(int j = 0;j < c;++j)
            mat[i][j]=valor;
    }
Matriz::~Matriz()
{
    for(int i=0; i <linhas;i++)
        delete[]mat[i];

    delete[]mat;
    //cout << endl << "destruido" << endl;
}

Matriz::Matriz(const Matriz& M) : linhas(M.linhas), colunas(M.colunas)
{
    mat = new int*[M.linhas];
    for(int i = 0;i<M.linhas;i++)
        mat[i] = new int[M.colunas];
    for(int i = 0;i <M.linhas;++i)
        for(int j = 0;j <M.colunas;++j)
            mat[i][j]=M.mat[i][j];
}
void Matriz::Print(){
        for(int i = 0;i<linhas;++i) {
        cout <<endl;
            for(int j = 0;j< colunas;++j){
                cout << mat[i][j];
                cout << " ";}}
}
int Matriz::getRows(){return linhas;}// testar como inline

int Matriz::getCols(){return colunas;}// testar como inline

int& Matriz::operator() (int lin,int col){return mat[lin-1][col-1];}// testar como inline

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


Matriz Matriz::operator+ (const Matriz &A)const{
   try{ Matriz C(linhas,colunas);
    if (A.linhas != linhas || A.colunas != colunas){
        throw 01;
            }
    for(int i = 0;i <linhas;++i)
        for(int j = 0;j <colunas;++j)
           C.mat[i][j] = A.mat[i][j] + mat[i][j];

        return C;
        }catch (const int error){
        cout<<"Erro"<< error<<endl;}
}
Matriz Matriz::operator~ (){
        Matriz A(colunas,linhas);
        for(int i = 0; i < linhas;i++){
            for(int j = 0; j< colunas;j++){
                A.mat[i][j] = mat[j][i];
            }
        }
        return A;
}
Matriz &Matriz::operator*= (const int& right){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j<colunas; j++){
            this->mat[i][j] = mat[i][j]*right ;
        }
    }
   return *this;
}
Matriz &Matriz::operator+= (const Matriz &a){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j<colunas; j++){
            this->mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
   return *this;

}
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
ostream& operator<< (ostream& out,const Matriz& a){
        for(int i = 0;i<a.linhas;++i) {
        out <<endl;
            for(int j = 0;j<a.colunas;++j){
                out << a.mat[i][j];
                out << " ";}
                }
                return out;
}

