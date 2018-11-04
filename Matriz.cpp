#include<iostream>
#include "Matriz.h"

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
    cout << endl << "destruido" << endl;
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
void Matriz::Print(Matriz x){
        for(int i = 0;i<linhas;++i) {
        cout <<endl;
            for(int j = 0;j< colunas;++j){
                cout << mat[i][j];
                cout << " ";}}
}
int Matriz::getRows(){return linhas;}// testar como inline

int Matriz::getCols(){return colunas;}// testar como inline

int& Matriz::operator() (int lin,int col){return mat[lin][col];}// testar como inline

Matriz Matriz::operator+ (const Matriz &A)const{
    const double x = 0;
    Matriz C(linhas,colunas,x);
    if (A.linhas != linhas || A.colunas != colunas){
        cout<< "Nao se pode somar matrizes com linhas ou colunas diferentes" << endl;
            }
 cout << 1;
    for(int i = 0;i <linhas;++i)
        for(int j = 0;j <colunas;++j)
           C.mat[i][j] = A.mat[i][j] + mat[i][j];

        return C;
}
