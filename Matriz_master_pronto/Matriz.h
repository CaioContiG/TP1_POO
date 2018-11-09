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

        //construtores e destrutores
        Matriz();
        Matriz(int l, int c, const double &valor=0);
        Matriz(const Matriz& M);
        ~Matriz();

        //pegar linhas ou colunas
        int getRows() const;
        int getCols() const;

        //funcoes
        void unit();    //Matriz unidade
        void zeros();   //preenche matriz com 0
        void ones();    //preenche matriz com 1
        void const imprimir();  //print inicial de teste

        //sobrecargas---------------------
        Matriz &operator= (const Matriz &a);
        int& operator() (int lin,int col);
        Matriz operator~(); //faz a transposta


        const Matriz operator- (const Matriz &a) const;
        Matriz &operator-= (const Matriz &a);


        const Matriz operator+ (const Matriz &A)const;
        Matriz &operator+= (const Matriz &a);

        const Matriz operator* (const Matriz &a) const;
        Matriz operator*= (const int &a);
        const Matriz operator*= (const Matriz &a);

        bool operator !=(const Matriz &a);
        bool operator == (const Matriz &a);

        //operadores para entrada e saida de dados
        friend istream& operator >>(istream &in, const Matriz &a);
        friend ostream& operator<< (ostream &out,const Matriz& a);
};

inline int Matriz::getRows() const {return linhas;}
inline int Matriz::getCols() const {return colunas;}

inline int &Matriz::operator()(int lin,int col){return mat[lin-1][col-1];}
#endif // MATRIZ_H
