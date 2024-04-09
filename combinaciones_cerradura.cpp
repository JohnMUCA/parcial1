#include <combinaciones_cerradura.h>

unsigned short*** crearCerraduraX(int *K, unsigned short N, unsigned short* x, unsigned short* R)
{
    x[0] = hallar_DimensionPrimeraM(K);
    unsigned short contMatricesExaminadas = 0;
    unsigned short dimension1 = x[0];
    unsigned short cantidadM = 1;
    unsigned short dimension2 = dimension1 + 2;
    unsigned short posR = 0;
    unsigned short posx = 1;
    unsigned short rotacion1 = 0;
    unsigned short rotacion2 = 0;
    unsigned short** MatrizAux1 = NULL;
    unsigned short** MatrizAux2 = NULL;
    bool banderaRotacion = 1;
    unsigned short posK = 2;

    while(cantidadM <= N)
    {
        if (contMatricesExaminadas < 4)
        {
            rotacion2 = 0;
        }

        MatrizAux1 = alinearmatriz(x[0], dimension1, rotacion1);
        MatrizAux2 = alinearmatriz(x[0], dimension2, rotacion2);
        banderaRotacion = 1;
        while ((rotacion2 <= 3) && banderaRotacion && (dimension1 != dimension2))
        {
            rotacionAntiHorario(MatrizAux2, dimension2, rotacion2);

            if (compararValores(MatrizAux1, MatrizAux2, K[0], K[1], K[posK]))
            {
                cantidadM += 1;
                x[posx] = dimension2;
                posx += 1;
                R[posR] = rotacion2;
                posR += 1;
                banderaRotacion = 0;
                dimension1 = dimension2;
                dimension2 = x[0] - 2;
                rotacion1 = rotacion2;
                contMatricesExaminadas = 0;
                rotacion2 = 0;
            }
            else rotacion2 += 1;
        }

        delMemoriaDinamicaMatrizmxn(MatrizAux1, x[posx - 2]);
        delMemoriaDinamicaMatrizmxn(MatrizAux2, x[posx - 1]);
        dimension2 += 2;
        if (rotacion2 == 4) contMatricesExaminadas += 1;
        if (contMatricesExaminadas > 3)
        {
            dimension2 = dimension1;
            posx -= 1;
            posR -= 1;
            dimension1 = x[posx - 1];
            cantidadM -= 1;
            rotacion2 = R[posR];
            rotacion1 = R[posx - 1];
        }
    }
    unsigned short*** X = devolverPunteroCerradura(N, x);
    return X;
}

unsigned short hallar_DimensionPrimeraM(int* K)
{
    unsigned short dimension;

    if (K[0] > K[1]) dimension = K[0];
    else dimension = K[1];

    if (dimension != 0)
    {
        if ((dimension % 2) == 0) dimension += 1;
        else dimension += 2;
    }
    else dimension = 3;

    return dimension;
}

bool compararValores(unsigned short** matriz1, unsigned short** matriz2, int fil, int col, int comparacion)
{
    bool bandera = 0;

    switch (comparacion)
    {
    case -1: if (matriz1[fil][col] < matriz2[fil][col]) bandera = 1;
        break;
    case 0: if (matriz1[fil][col] == matriz2[fil][col]) bandera = 1;
        break;
    case 1: if (matriz1[fil][col] > matriz2[fil][col]) bandera = 1;
        break;
    }

    return bandera;
}
