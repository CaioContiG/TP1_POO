#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz
{
    public:
        int linhas;
        int colunas;
        int **mat;
        Matriz();
        Matriz(int l,int c,const double &valor);
        void Print(Matriz x);
        ~Matriz();
        Matriz(const Matriz& other);
        int getRows();
        int getCols();
        int& operator() (int lin,int col);
        Matriz operator+ (const Matriz &A)const;

    protected:

    private:

};

#endif // MATRIZ_H

