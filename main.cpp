#include <combinaciones_cerradura.h>
#include <generacion_estructuras.h>

int main()
{
    int* K;
    int* Kaux;
    bool bandera = 1;
    int cont = 0;
    unsigned short N;


    K = new int[4];

    while(bandera)
    {
        cin >> K[cont];
        if (cont > 1)
        {
            if (K[cont] == 0 || K[cont] == 1 || K[cont] == -1)
            {
                if (cont > 2)
                {
                    Kaux = new int[cont + 2];
                    for (int i = 0; i <= cont; i++)
                    {
                        Kaux[i] = K[i];
                    }
                    delete[] K;

                    K = new int[cont + 2];
                    for (int i = 0; i <= cont +1; i++)
                    {
                        K[i] = Kaux[i];
                    }
                    delete[] Kaux;
                }

            }
            else
            {
                if (K[cont] == 2)
                {
                    Kaux = new int[cont];
                    for (int i = 0; i < cont; i++)
                    {
                        Kaux[i] = K[i];
                    }
                    delete[] K;

                    K = new int[cont];
                    for (int i = 0; i < cont; i++)
                    {
                        K[i] = Kaux[i];
                    }
                    delete[] Kaux;
                    bandera = 0;
                }
                else
                {
                    cout << "comparacion no definida, ingrese una comparacion valida." << endl;
                    cont -= 1;
                }

            }

        }
        cont += 1;

    }
    N = cont - 2;

    unsigned short* x = devolverPunteroArreglon(N);
    unsigned short* R = devolverPunteroArreglon(N-1);
    unsigned short*** X;

    X = crearCerraduraX(K, N, x, R);

    for (unsigned short M = 0; M < N; M++)
        for (int m = 0; m < x[M]; m++)
        {
            for (int n = 0; n < x[M]; n++) cout << X[M][m][n] << " ";
            cout << endl;
        }

    delMemoriaDinamicaCerradura(X, x, N);

    return 0;

}
