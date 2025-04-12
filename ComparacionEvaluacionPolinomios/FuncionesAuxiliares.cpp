#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int Aleatorizar(int inicio, int fin)
{
    return inicio + rand() % (fin - inicio + 1);
}

int** CrearArreglo(int m, int n) // m = renglones, n = columnas
{
    //Construccion de un arreglo dinamico 2D tipo** CrearArreglo(int m, int n)
    int** arreglo = new int* [m];
    for (int i = 0; i < m; ++i)
    {
        arreglo[i] = new int[n];
    }

    return arreglo;
}

void DestruirArreglo(int**& arreglo, int m)
{
    //Liberar arreglo dinamico void DestruirArreglo(tipo** &arreglo, int m)
    for (int i = 0; i < m; ++i)
    {
        delete[] arreglo[i];
    }
    delete[] arreglo;

    arreglo = NULL;  // Si ya no se va a usar
}

void CleanBuffer() {
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

void StopSystem() {
    cout << "Presiona ENTER para continuar...";
    CleanBuffer();
    getchar();
}

