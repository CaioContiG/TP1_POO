#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <windows.h>
using namespace std;

class Matriz
{
    private:
        int **mat;
        int linhas;
        int colunas;

    public:
        Matriz();
        Matriz(int l, int c, const double &valor=0);
        ~Matriz();
        Matriz(const Matriz& M);

        int getRows();
        int getCols();

        //funcoes
        void unit();
        void const imprimir();
        void zeros();
        void ones();

        //sobrecarga
        Matriz &operator= (const Matriz &a);
        int& operator() (int lin,int col);

        const Matriz operator- (const Matriz &a) const;
        Matriz operator-= (const Matriz &a);

        const Matriz operator* (const Matriz &a) const;
        Matriz operator*= (const int &a);

        bool operator !=(const Matriz &a);

        friend istream& operator >>(istream &in, Matriz &a);
};

inline int Matriz::getRows(){return linhas;}

inline int Matriz::getCols(){return colunas;}

inline int &Matriz::operator()(int lin,int col){return mat[lin-1][col-1];}
#endif // MATRIZ_H
