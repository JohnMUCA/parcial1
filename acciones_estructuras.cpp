#include <acciones_estructuras.h>

unsigned short** devolverPunteroMatriz(int n)
{
    unsigned short** matriz = new unsigned short*[n];
    for (int i = 0; i < n; i++) matriz[i] = new unsigned short[n];
    return matriz;
}

void rotacionAntiHorario(unsigned short** matrix, int N, int rotaciones)
{
    unsigned short veces = rotaciones % 4; // Para evitar rotaciones innecesarias
    for (int r = 0; r < veces; r++) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - i - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = temp;
            }
        }
    }
}

unsigned short** alinearmatriz(unsigned short** matriz2, unsigned short n1, unsigned short n2,unsigned short rotaciones)
{
    unsigned short fila0_1 = (n1-1)/2;
    unsigned short col0_1 = fila0_1;
    unsigned short fila0_2 = (n2-1)/2;
    unsigned short col0_2 = fila0_2;

    // Calcular diferencia en las posiciones del 0
    unsigned short dif_fila = fila0_2 - fila0_1;
    unsigned short dif_col = col0_2 - col0_1;

    // Crear la matriz resultante
    unsigned short** matriz_resultante = devolverPunteroMatriz(n1);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            matriz_resultante[i][j] = matriz2[i+dif_fila][j+dif_col];
        }
    }

    // Realizar rotaciones en la matriz resultante
    rotacionAntiHorario(matriz_resultante, n1, rotaciones);


    // Imprimir la matriz resultante
    cout << "Matriz resultante:" << endl;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            cout << matriz_resultante[i][j] << " ";
        }
        cout << endl;
    }

    // No liberar memoria aquí, la matriz resultante se devuelve

    return matriz_resultante;
}
