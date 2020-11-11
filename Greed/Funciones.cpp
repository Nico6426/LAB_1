#include <iostream>
using namespace std;
#include <clocale>
#include "Funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace rlutil;

void menu(int topTen[], char nick1[], char nick2[]){
    setlocale(LC_ALL, "Spanish");
    cls();
    setBackgroundColor(GREEN);
    setColor(YELLOW);
    int opcion;
    cout<<"-------------------------------"<<endl<<endl;
    cout<<"Bienvenido a GREED!"<<endl<<endl;
    cout<<"-------------------------------"<<endl<<endl;
    system("pause");
    do{
        system("cls");
        cout<<"Menu principal"<<endl<<"-------------------------------"<<endl;
        cout<<"1) Modo UN jugador "<<endl;
        cout<<"2) Modo DOS jugadores "<<endl;
        cout<<"3) Estadísticas"<<endl;
        cout<<"4) INSTRUCCIONES "<<endl;
        cout<<"5) Créditos "<<endl<<"-------------------------------"<<endl;
        cout<<"6) Salir "<<endl<<endl;
        cin>>opcion;

        switch(opcion){
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
    }while(opcion!=6);
}

void dados(int vec[], int tam){
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        vec[i] = rand() % 6 + 1;
    }
}

void mostrar(int vec[], int tam){
for(int i=0; i<tam; i++){
        cout << vec[i] << "   ";
}
}

int sumar(int vec[], int tam){
    int acu=0;
    for (int i=0; i<tam; i++){
        acu+=vec[i];
    }
    return acu;
}

int eliminar(int vec1[], int tam1, int vec2[], int tam2){
    int acu=0;
    for(int i=0; i<tam1; i++){
        for(int x=0; x<tam2; x++){
            if (vec1[i]==vec2[x]){
                vec1[i]=0;
                acu++;
            }
        }
    }
    return acu;
}

void ponerCero(int vec[], int tam){
for(int i=0; i<tam; i++){
        vec[i]=0;
}
}

void jugador1(int topTen[], char nickJ1[]){
    setBackgroundColor(WHITE);
    setColor(BLACK);
    const int T=5, B=2;
    int bloqueadores[B];
    int tirada[T];
    char seguir='s';
    int acuTotal = 0;
    cout << "Ingrese su Nick Name: ";
    cin >> nickJ1;
for (int i=1; i<=3; i++){
    int contador=1, acuRonda = 0, bloq = 0;
    system("cls");
    cout << "Ronda" << i << endl << endl;
    dados(bloqueadores, B);
    cout << "BLOQUEADORES            ";
    mostrar(bloqueadores, B);
    cout << endl << endl;
    do{
        cout << "Tiro #" << contador++ << ":   ";
        dados(tirada, T-bloq);
        mostrar(tirada, T-bloq);
        bloq += eliminar(tirada, T, bloqueadores, B);
        acuRonda += sumar(tirada, T);
        ponerCero(tirada, T);
        if(bloq >= T){
            setColor(RED);
            cout << "¡¡Perdio todos los puntos de esta ronda!!" << endl << endl;
            setColor(BLACK);
            seguir = 'N';
            acuRonda = 0;
        }
        else{
        cout << "¿Desea seguir jugando?    ";
        cin >> seguir;
        }
    }while (seguir == 'S' || seguir == 's');
    acuTotal+=acuRonda;
    cout << "PUNTAJE TOTAL DE LA RONDA " << i << ": " << acuRonda << endl;
    system("pause");
}
cout << "PUNTAJE FINAL: " << acuTotal << endl << endl;
system("pause");
}

