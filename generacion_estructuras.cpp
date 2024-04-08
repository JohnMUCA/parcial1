#include <generacion_estructuras.h>

unsigned short* devolverPunteroArreglon(unsigned short n)
{
    unsigned short* arreglo = new unsigned short[n];
    return arreglo;
}

unsigned short** devolverPunteroMatrizmxn(unsigned short m)
{
    //Se crean los espacios fila
    unsigned short** matrizmxn = new unsigned short*[m];
    //i: fila
    for (int i = 0; i < m; i++) matrizmxn[i] = devolverPunteroArreglon(m); // Se rellenan los espacios fila con los espacio columna
    return matrizmxn;
}

unsigned short*** devolverPunteroCerradura(unsigned short N, unsigned short* dimensiones)
{
    unsigned short*** cerradura = new unsigned short**[N]; // Se crean los espacios para cada estructura

    for (int i = 0; i < N; i++)
    {
        cerradura[i] = devolverPunteroMatrizmxn(dimensiones[i]); // Se rellenan los espacios de la cerradura con sus respectivas matrices
        rellenarMatrizmxn(cerradura[i], dimensiones[i]); //Se rellena con numeros cada matriz

    }
    return cerradura;
}

void rellenarMatrizmxn(unsigned short** estructuraM, int m)
{
    int i;
    int j;
    int num = 1;
    int centroMatriz = (m - 1)/2;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if ((i == centroMatriz) && (j == centroMatriz)) estructuraM[i][j] = 0;
            else
            {
                estructuraM[i][j] = (num);
                num += 1;
            }
        }
    }
}

void delMemoriaDinamicaArreglon(unsigned short* arreglo)
{
    delete[] arreglo;
}

void delMemoriaDinamicaMatrizmxn(unsigned short** matriz, unsigned short m)
{
    for (int i = 0; i < m; i++) delMemoriaDinamicaArreglon(matriz[i]);
}

void delMemoriaDinamicaCerradura(unsigned short*** cerradura, unsigned short* dimensiones,unsigned short N)
{
    for (int i = 0; i < N; i++) delMemoriaDinamicaMatrizmxn(cerradura[i], dimensiones[i]);
}
