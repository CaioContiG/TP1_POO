#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz
{   private:
        int linhas;
        int colunas;
        int **mat;
    public:
        Matriz();
        Matriz(int l,int c,const double &valor=0);
        void Print();
        ~Matriz();
        Matriz(const Matriz& other);
        int getRows();
        int getCols();

        //sobrecargas
        int& operator() (int lin,int col);
        Matriz operator+ (const Matriz &A)const;
        Matriz operator~ ();
        Matriz &operator= (const Matriz &a);
        Matriz &operator*= (const int& right);
        Matriz &operator+= (const Matriz &a);
        bool operator == (const Matriz &a);
        friend ostream& operator<< (ostream &out,const Matriz& a);
    protected:

};
inline int Matriz::getRows(){return linhas;}

inline int Matriz::getCols(){return colunas;}


#endif // MATRIZ_H

