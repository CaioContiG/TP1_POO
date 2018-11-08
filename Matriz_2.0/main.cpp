#include <iostream>
#include <windows.h>
#include "Matriz.h"

using namespace std;

int main()
{

    Matriz Y;
    Matriz m(3,3,6);
    Matriz m1(3,3,4);
    Matriz m2(3,3,1);
    Matriz m3(3,3);
    Matriz m4(3,2);
    Matriz m5(3,2);

    m(2,1) = 10;


    cout << "valores originais: "<< endl;
    m.Matriz::imprimir();
    m2.Matriz::imprimir();
    m3.Matriz::imprimir();

    cout<<"subtracao " << endl;
    m3 =  m - m2 -m1;
    m3.imprimir();

    cout << "multiplicacao: " <<endl;
    m4(1,1) = 1;
    m4(1,2) = 4;
    m4(2,1) = 2;
    m4(2,2) = 5;
    m4(3,1) = 3;
    m4(3,2) = 6;

   // cin >> m4;
    m3(1,1) =6;
    m3(1,2) =8;
    m3(1,3) =11;
    m3(2,1) =7;
    m3(2,2) =3;
    m3(2,3) =1;
    m3(3,1) =5;
    m3(3,2) =2;
    m3(3,3) =9;

    cout << "imprimir matrizes m3 e m4" << endl;
    m3.imprimir();
    m4.imprimir();
    m5 = m3*m4;
    m5.imprimir();

    cout << "verificando igualdade" << endl;
    if(m != m3){
        cout<<"m1 != m3" << endl;
    }
    if(m3 != m4){
        cout<<"m3 != m4" << endl;
    }
    if(m4 != m5){
        cout<<"m4 != m5" << endl;
    }
    if(m != m1){
        cout<<"m != m1" << endl;
    }
    else{
        cout <<"m == m1" << endl;
    }
     //m.Matriz::unit();
    // m.Matriz::imprimir();

    // m.Matriz::zeros();
    // m.Matriz::imprimir();

    // m.Matriz::ones();
    //m.Matriz::imprimir();

    return 0;
}
