#include <iostream>
using namespace std;
#include <clocale>
#include "Funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace rlutil;

void menu(){
    srand(time(NULL));
    char mejorPlayer[11];
    char nick1[11];
    char nick2[11];
    setlocale(LC_ALL, "Spanish");
    setBackgroundColor(GREEN);
    cls();
    setColor(YELLOW);
    int opcion;
    int mayorPuntaje = 0;
    cout<<"-------------------------------"<<endl<<endl;
    cout<<"Bienvenido a GREED!"<<endl<<endl;
    cout<<"-------------------------------"<<endl<<endl;
    system("pause");
    do{
        system("cls");
        cout<<"Menu principal"<<endl<<"-------------------------------"<<endl;
        cout<<"1) Modo UN jugador "<<endl;
        cout<<"2) Modo DOS jugadores "<<endl;
        cout<<"3) Mejor puntuacion"<<endl;
        cout<<"4) INSTRUCCIONES "<<endl;
        cout<<"5) Créditos "<<endl<<"-------------------------------"<<endl;
        cout<<"6) Salir "<<endl<<endl;
        cin>>opcion;
        while (opcion < 1 || opcion > 6){
            cout << "Ingrese una opcion correcta: ";
            cin >> opcion;
        }

        switch(opcion){
            case 1:
                singlePlayer(nick1, mejorPlayer, &mayorPuntaje);
            break;
            case 2:
                multiPlayer(nick1, nick2, mejorPlayer, &mayorPuntaje);
            break;
            case 3:
                mostrarMejor(mejorPlayer, mayorPuntaje);
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

void mayus(char vec[]){
for (int i=0; i<11; i++){
    vec[i] = toupper(vec[i]);
}
}

void mostrarMejor(char nombre[], int puntos){
int colorF;
for (int i=0; i<5; i++){
        colorF = rand() % 15 + 1;
        setBackgroundColor(colorF);
        system("cls");
        gotoxy(45, 10);
        cout << "** ¡¡MEJOR PUNTAJE!! **" << endl << endl;
        gotoxy(50, 13);
        cout << nombre << " CON " << puntos << " PUNTOS" << endl << endl;
        msleep(500);
    }
anykey();
setBackgroundColor(GREEN);
setColor(YELLOW);
}

void mostrarNuevo(char nombre[], int puntos){
int colorF;
for (int i=0; i<5; i++){
        colorF = rand() % 15 + 1;
        setBackgroundColor(colorF);
        system("cls");
        gotoxy(45, 10);
        cout << "** ¡¡ NUEVO MEJOR PUNTAJE!! **" << endl << endl;
        gotoxy(50, 13);
        cout << nombre << " CON " << puntos << " PUNTOS" << endl << endl;
        msleep(500);
    }
anykey();
setBackgroundColor(GREEN);
setColor(YELLOW);
}

void mostrarGanador(char nombre[], int puntos){
int colorF;
for (int i=0; i<5; i++){
        colorF = rand() % 15 + 1;
        setBackgroundColor(colorF);
        system("cls");
        gotoxy(45, 10);
        cout << "** ¡¡ GANADOR !! **" << endl << endl;
        gotoxy(50, 13);
        cout << nombre << " CON " << puntos << " PUNTOS" << endl << endl;
        msleep(500);
    }
anykey();
setBackgroundColor(GREEN);
setColor(YELLOW);
}

void singlePlayer(char nick1[], char  mejorP[], int *mayor){
    setBackgroundColor(WHITE);
    setColor(BLACK);
    system("cls");
    const int T=5, B=2;
    int bloqueadores[B];
    int tirada[T];
    char seguir;
    int acuTotal = 0;
    cout << "Ingrese su Nick Name: ";
    cin >> nick1;
    mayus(nick1);
for (int i=1; i<=3; i++)
    {
    int contador = 0, acuRonda = 0, bloq = 0;
    setColor(GREEN);
    system("cls");
    cout << "Ronda " << i << endl << endl;
    setColor(BLACK);
    dados(bloqueadores, B);
    cout << "BLOQUEADORES            ";
    mostrar(bloqueadores, B);
    cout << endl << endl;

        do
        {
        contador++;
        cout << "Tiro #" << contador << ":   ";
        dados(tirada, T-bloq);
        mostrar(tirada, T-bloq);
        bloq += eliminar(tirada, T, bloqueadores, B);
        acuRonda += sumar(tirada, T);
        ponerCero(tirada, T);

        if(bloq >= T)
            {
            setColor(RED);
            cout << "¡¡Se perdieron todos los puntos de esta ronda!!" << endl << endl;
            setColor(BLACK);
            seguir = 'N';
            acuRonda = 0;
        }
        else
            {
            cout << "¿Desea seguir jugando?  (S/N)   ";
            cin >> seguir;
            seguir = toupper(seguir);
        }
    }
    while (seguir == 'S');
    acuTotal+=acuRonda;
    setColor(BLUE);
    cout << endl << "Resultados RONDA " << i << " para ";
    cout << nick1 << endl << endl;
    setColor(BLACK);
    cout << "Esta ronda: " << acuRonda << endl;
    cout << "Acumulado parcial: " << acuTotal << endl;
    system("pause");
}
cout << "** PUNTAJE FINAL **" << endl << endl;
cout << nick1 << ": " << acuTotal << endl << endl;

if (acuTotal > *mayor){
    *mayor = acuTotal;
    strcpy(mejorP, nick1);
    mostrarNuevo(mejorP, *mayor);
}
else{
    cout << nick1 << endl;
    cout << "PUNTAJE FINAL: " << acuTotal << endl << endl;
    system("pause");
}
setBackgroundColor(GREEN);
cls();
setColor(YELLOW);
}

void multiPlayer(char nick1[], char nick2[], char mejorP[], int *mayor){
    setBackgroundColor(WHITE);
    setColor(BLACK);
    system("cls");

    const int T=5, B=2;
    int bloqueadores[B];
    int tirada[T];
    char seguir;
    int acuTotalP1 = 0, acuTotalP2 = 0;;

    cout << "Ingrese el nick Player 1: ";
    cin >> nick1;
    mayus(nick1);
    cout << "Ingrese el nick Player 2: ";
    cin >> nick2;
    mayus(nick2);

for (int i=1; i<=3; i++){
    for (int x=1; x<3; x++){
            if (x==1){
                int contador=0, acuRonda = 0, bloq = 0;
                system("cls");
                setColor(GREEN);
                cout << "<<Ronda" << i << ">>" << endl;
                cout << "**PLAYER: " << x << "**" << endl << endl;
                setColor(BLACK);
                dados(bloqueadores, B);
                cout << "BLOQUEADORES            ";
                mostrar(bloqueadores, B);
                cout << endl << endl;

                do{
                    contador++;
                    cout << "Tiro #" << contador << ":   ";
                    dados(tirada, T-bloq);
                    mostrar(tirada, T-bloq);
                    bloq += eliminar(tirada, T, bloqueadores, B);
                    acuRonda += sumar(tirada, T);
                    ponerCero(tirada, T);
                    if(bloq >= T){
                        setColor(RED);
                        cout << "¡¡Se perdieron todos los puntos de esta ronda!!" << endl << endl;
                        setColor(BLACK);
                        seguir = 'N';
                        acuRonda = 0;
                    }
                    else{
                    cout << "¿Desea seguir jugando?  (S/N)  ";
                    cin >> seguir;
                    seguir = toupper(seguir);
                    }
                }while (seguir == 'S');

                acuTotalP1+=acuRonda;

                setColor(BLUE);
                cout << endl << "Resultados RONDA " << i << " para ";
                cout << nick1 << endl << endl;
                setColor(BLACK);
                cout << "Esta ronda: " << acuRonda << endl;
                cout << "Acumulado parcial: " << acuTotalP1 << endl;
                system("pause");
            }
            else {
             int contador=0, acuRonda = 0, bloq = 0;
                system("cls");
                setColor(GREEN);
                cout << "<<Ronda" << i << ">>" << endl;
                cout << "**PLAYER: " << x << "**" << endl << endl;
                setColor(BLACK);
                dados(bloqueadores, B);
                cout << "BLOQUEADORES            ";
                mostrar(bloqueadores, B);
                cout << endl << endl;

                do{
                    contador++;
                    cout << "Tiro #" << contador << ":   ";
                    dados(tirada, T-bloq);
                    mostrar(tirada, T-bloq);
                    bloq += eliminar(tirada, T, bloqueadores, B);
                    acuRonda += sumar(tirada, T);
                    ponerCero(tirada, T);
                    if(bloq >= T){
                        setColor(RED);
                        cout << "¡¡Se perdieron todos los puntos de esta ronda!!" << endl << endl;
                        setColor(BLACK);
                        seguir = 'N';
                        acuRonda = 0;
                    }
                    else{
                    cout << "¿Desea seguir jugando?    ";
                    cin >> seguir;
                    seguir = toupper(seguir);
                    }
                }while (seguir == 'S');

                acuTotalP2+=acuRonda;
                setColor(RED);
                cout << endl << "Resultados RONDA " << i << " para ";
                cout << nick2 << endl << endl;
                setColor(BLACK);
                cout << "Esta ronda: " << acuRonda << endl;
                cout << "Acumulado parcial: " << acuTotalP2 << endl;
                system("pause");
            }
}
}
if (acuTotalP1>acuTotalP2)
{
    mostrarGanador(nick1, acuTotalP1);
    if (acuTotalP1 > *mayor){
    *mayor = acuTotalP1;
    strcpy(mejorP, nick1);
    mostrarNuevo(mejorP, *mayor);
}
}
else
{
    mostrarGanador(nick2, acuTotalP2);
   if (acuTotalP2 > *mayor){
    *mayor = acuTotalP2;
    strcpy(mejorP, nick2);
    mostrarNuevo(mejorP, *mayor);
}
}
}

