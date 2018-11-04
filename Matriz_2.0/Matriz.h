#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <windows.h>
using namespace std;

class Matriz
{
    public:
        int **mat;

        int linhas;
        int colunas;

        Matriz();
        Matriz(int l, int c, const double &valor=0);
        ~Matriz();
        Matriz(const Matriz& M);

        //funcoes
        void unit();
        void const imprimir();
        void zeros();
        void ones();

        //sobrecarga
        Matriz &operator= (const Matriz &a);
        const Matriz operator- (const Matriz &a) const;
        Matriz operator-= (const Matriz &a);
        const Matriz operator* (const Matriz &a) const;
        Matriz operator*= (const int &a);
        bool operator !=(const Matriz &a);
        friend istream& operator >>(istream &in, Matriz &a);

    protected:

    private:
};

#endif // MATRIZ_H
