#ifndef GENERACION_ESTRUCTURAS_H
#define GENERACION_ESTRUCTURAS_H

#include <iostream>

using namespace std;

unsigned short* devolverPunteroArreglon(unsigned short n);
unsigned short** devolverPunteroMatrizmxn(unsigned short m);
unsigned short*** devolverPunteroCerradura(unsigned short N, unsigned short* dimensiones);
void rellenarMatrizmxn(unsigned short** p, int n);
void delMemoriaDinamicaArreglon(unsigned short* arreglo);
void delMemoriaDinamicaMatrizmxn(unsigned short** matriz, unsigned short m);
void delMemoriaDinamicaCerradura(unsigned short*** cerradura, unsigned short *dimensiones, unsigned short N);

#endif // GENERACION_ESTRUCTURAS_H
