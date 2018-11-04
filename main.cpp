#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    int li,co;
    cout << "Digita linha e depois coluna" << endl;
    cin >> li;
    cin >> co;

    const double p = 3;
    const double h = 2;
    Matriz x(li,co,p);
    Matriz z(li,co,h);

    //x.Print(x);
    //x(1,2) = 5;
    //x.Print(x);
    z.Print(z);
    x = x+z;
    x.Print(x);
    return 0;
}
