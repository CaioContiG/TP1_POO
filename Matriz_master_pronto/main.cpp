#include <iostream>
#include <windows.h>
#include "Matriz.h"

using namespace std;

int main()
{

    //Inicializando algumas matrizes
    Matriz Y;
    Matriz X(3,1), A(3,3), C(3,3);
    Matriz W = C;
    Matriz Z(A);

    Matriz m(3,3,6);
    Matriz m1(3,3,4);
    Matriz m2(3,3,1);

   //m3 e m4 serao multiplicados e m5 vai receber
    Matriz m3(3,3);
    Matriz m4(3,2);
    Matriz m5(3,2);

    //inserindo valores em m4
    m4(1,1) = 1;
    m4(1,2) = 4;
    m4(2,1) = 2;
    m4(2,2) = 5;
    m4(3,1) = 3;
    m4(3,2) = 6;

    //inserindo valores em m3
    m3(1,1) =6;
    m3(1,2) =8;
    m3(1,3) =11;
    m3(2,1) =7;
    m3(2,2) =3;
    m3(2,3) =1;
    m3(3,1) =5;
    m3(3,2) =2;
    m3(3,3) =9;


    cout << "Teste de impressao e de valores de inicializacao:"<< endl;
    cout <<"Matriz Y"<< Y << endl;
    cout <<"Matriz X"<< X << endl;
    cout <<"Matriz A"<< A << endl;
    cout <<"Matriz C"<< C << endl;
    cout <<"Matriz W"<< W << endl;
    cout <<"Matriz Z"<< Z << endl;

    cout<<"\nImprimindo as Matrizes mn--------------------------------------------" << endl;
    cout <<"Matriz m"<<  m << endl;
    cout <<"Matriz m1"<< m1 << endl;
    cout <<"Matriz m2"<< m2 << endl;
    cout <<"Matriz m3"<< m3 << endl;
    cout <<"Matriz m4"<< m4 << endl;
    cout <<"Matriz m5"<< m5 << endl;

    cout << "\nTestes das funcoes--------------------------------------------------\n" << endl;
    cout << "Funcoes Gets, pega o numero de linhas e colunas da matriz A:" << endl;
    int numeroLinhas = A.getRows();
    int numeroColunas = A.getCols();
    cout<< "Linhas: " << numeroLinhas << ", colunas: " << numeroColunas << endl;

    cout<< "matriz A na unit";
    A.unit();
    cout << A;

    cout<< "matriz A na zeros";
    A.zeros();
    cout << A;

    cout<< "matriz A na ones";
    A.ones();
    cout << A;

    cout<< "\ntestes das sobrecargas-------------------------------------------------------\n" << endl;

    cout << ">A e igual a transposta de m3 (sobrecarga ~)" << endl;
    A=~m3;
    cout <<"A matriz m3:" << m3;
    cout <<"A matriz A:" << A;

    cout << ">Multiplicacao por constante: A*= 2:";
    A *= 2;
    cout<<A;

    cout<<">Resultado da subtracao C = m - m2 - m1:";
    C =  m - m2 -m1;
    cout << C;

    cout<<">Resultado da soma C = m + m2 + m1:";
    C =  m + m2 +m1;
    cout << C;

    cout<<">Resultado da multiplicacao m5 = m3*m4:";
    m5 = m3*m4;
    cout << m5;

    cout <<">Resultado de m1+=m2:";
    m1+=m2;
    cout << m1;

    cout <<">Resultado de m1-=m2:";
    m1-=m2;
    cout << m1;

    cout <<">Resultado de m1*=m2";
    m1 *= m2;
    cout << m1;

    cout << "\n\nverificando m1 != m3, RESULTADO: ";

    if(m != m3){
        cout<<"Confirmado! E diferente" << endl;
    }
    else{
        cout<<"E igual" << endl;
    }

    cout<< "\ncolocando zeros em m e m3"<< endl;
    m.zeros();
    m3.zeros();
    cout << "Verificando m1 != m3, RESULTADO: ";
    if(m != m3){
        cout<<"Confirmado! E diferente" << endl;
    }
    else{
        cout<<"E igual" << endl;
    }

    cout << "Verificando m1 == m3, RESULTADO: ";
    if(m == m3){
        cout<<"Confirmado! E igual" << endl;
    }
    else{
        cout<<"E diferente" << endl;
    }
    cout<< "\n\ncolocando zeros em m e ones em m3"<< endl;
    m.zeros();
    m3.ones();
    cout << "Verificando m1 == m3, RESULTADO: ";
    if(m == m3){
        cout<<"Confirmado! E igual" << endl;
    }
    else{
        cout<<"E diferente" << endl;
    }

    cout<< "\n\nTeste do cin. Entre com valores para a matriz Z: " << endl;
    cin >> Z;
    cout<< "A matriz Z foi: " << Z;

    return 0;
}
