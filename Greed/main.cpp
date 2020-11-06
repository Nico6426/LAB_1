#include <iostream>
using namespace std;
#include "Funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace rlutil;

int main(){
    setlocale(LC_ALL, "Spanish");
    int topTen[10];
    char nickJ1[11];
    char nickJ2[11];
    menu(topTen, nickJ1, nickJ2);
}
