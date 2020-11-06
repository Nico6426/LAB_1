#include <iostream>
using namespace std;
#include <clocale>
#include "Funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace rlutil;

void menu(int topTen[], char nick1[], char nick2[])
{
    setlocale(LC_ALL, "Spanish");
    int opcion;
    cout<<"-------------------------------"<<endl<<endl;
    cout<<"Bienvenido a GREED!"<<endl<<endl;
    cout<<"-------------------------------"<<endl<<endl;
    system("pause");
    do
    {
        system("cls");
        cout<<"Menu principal"<<endl<<"-------------------------------"<<endl;
        cout<<"1) Modo UN jugador "<<endl;
        cout<<"2) Modo DOS jugadores "<<endl;
        cout<<"3) Estadísticas"<<endl;
        cout<<"4) INSTRUCCIONES "<<endl;
        cout<<"5) Créditos "<<endl<<"-------------------------------"<<endl;
        cout<<"6) Salir "<<endl<<endl;
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            jugador1(topTen, nick1);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    }
    while(opcion!=6);
}

void dados(int vec[], int tam)
{
    srand(time(NULL));
    for(int i=0; i<tam; i++)
    {
        vec[i] = rand() % 6 + 1;
    }
}


void jugador1(int topTen[], char nickJ1[])
{
    const int T=5, B=2;
    int bloqueadores[B];
    int tirada[T];
    char seguir='s';
    cout << "Ingrese su Nick Name: ";
    cin >> nickJ1;
    for (int i=1; i<=3; i++)
    {
        cout << "Ronda" << i << endl << endl;
        dados(bloqueadores, B);
        cout << "BLOQUEADORES            ";
        for(int x=0; x<B; x++)
        {
            cout << bloqueadores[x] << "   ";
        }
        cout << endl << endl;
        cout << "Tiro #1:   ";
        dados(tirada, T);
        for(int x=0; x<T; x++)
        {
            cout << tirada[x] << "   ";
        }

        system("pause");
    }
}

