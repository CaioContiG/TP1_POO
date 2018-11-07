#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    int li,lin1,co;
    cout << "Digita linha e depois coluna" << endl;
    cin >> li;
    cin >> co;

    const double p = 2;
    const double h = 2;
    Matriz x(li,co,p);
    Matriz z(li,co,h);

    cout <<"Colunas = " << x.getCols()<< endl;

    cout <<"Linhas = "<< z.getRows();

    x(1,2) = 5;
    x.Print();

    cout << endl;
    x.Print();
    cout << endl;
    z.Print();
    cout << endl;
    x = x+z;

    cout <<"transposta";
    z = ~x;
    cout << endl;
    x+=z;

    cout << endl;
    z.Print();
    cout << endl;
    cout << x << endl;
    x.Print();
    if (x==z){
        cout << "arroz" <<endl;}
    return 0;
}
