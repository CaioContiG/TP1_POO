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
        Matriz(int l,int c,const double &valor=0);
        void Print();
        ~Matriz();
        Matriz(const Matriz& other);
        int getRows();
        int getCols();
        int& operator() (int lin,int col);

        //sobrecargas
        Matriz operator+ (const Matriz &A)const;
        Matriz operator~ ();
        Matriz &operator= (const Matriz &a);
        Matriz &operator*= (const int& right);
        Matriz &operator+= (const Matriz &a);
        bool operator == (const Matriz &a);
        friend ostream& operator<< (ostream &out,const Matriz& a);
    protected:

    private:

};

#endif // MATRIZ_H

