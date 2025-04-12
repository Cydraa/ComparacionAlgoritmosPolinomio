#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <stdio.h>

#include "FuncionesAuxiliares.hpp"
#include "AlgoritmosEval.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using namespace std::chrono;
using fn = int(int[], int, int);

#define MIN_GRADO 10 // Tamaño mínimo del arreglo
#define MAX_GRADO 1000 // Tamaño máximo del arreglo (columnas)  El grado del polinomio maximo es 1000.
#define NUM_PRUEBAS 1000 // Número de pruebas
#define INCREMENTO 10 // Incremento del tamaño del arreglo (este es el incremento del grado!!)
#define NUM_ALGORITMOS 2 // Número de algoritmos

int main()
{
    srand(time(NULL));
    int grado,valor_x,suma,promedio;

    //Arreglo de funciones
    fn* algoritmos[NUM_ALGORITMOS] = { EvaluarPol, EvaluarPolHorner };

    //Arreglo de datos para descargar datos al CSV
    int** datos = CrearArreglo(MAX_GRADO/INCREMENTO, NUM_ALGORITMOS+1);

    //Vector de nombres del algoritmo
    string nombresAlgoritmo[NUM_ALGORITMOS] = { "EVALUACION ESTANDAR", "EVALUACION POR REGLA DE HORNER" };

    //Bucle de grados
    for (int g = 0; g < MAX_GRADO/INCREMENTO; ++g)
    {
        //Obtenemos el grado
        grado = (g + 1) * INCREMENTO;
        datos[g][0] = grado;

        //Generacion del polinomio
        int* polinomio = new int[grado + 1];

        for (int i = 0; i <= grado; i++)
        {
            polinomio[i] = Aleatorizar(-10, 10);
        }

        //Obtenemos el valor de x a evaluar
        valor_x = Aleatorizar(-10, 10);

        cout << ">> Procesando los polinomios de grado " << grado << "..." << endl;

        //Bucle de algoritmos
        for (int a = 0; a < NUM_ALGORITMOS; a++)
        {
            suma = 0;
            cout << "  >> Algoritmo: " << nombresAlgoritmo[a] << endl;

            //Bucle de repeticiones
            for (int p = 0; p < NUM_PRUEBAS; p++)
            {
                const auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
                algoritmos[a](polinomio, grado, valor_x);
                const auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
                auto duracion = end - start;

                suma += duracion;
            }

            promedio = suma / NUM_PRUEBAS;
            cout << "  Terminado. Duracion promedio: " << promedio << " nanosegundos.\n" << endl;

            datos[g][a+1] = promedio;

        }

        delete[] polinomio;

    }

    // Impresion de datos
    ofstream InsercionTiempos("ComparacionAlg_EvaluacionPolinomio.csv");
    InsercionTiempos << "GRADO,ESTANDARD,HORNER";
    InsercionTiempos << endl;

    for (int fila = 0; fila < MAX_GRADO/INCREMENTO; ++fila)
    {
        for (int columna = 0; columna < NUM_ALGORITMOS+1;++columna)
        {
            InsercionTiempos << datos[fila][columna];
            InsercionTiempos << ",";
        }

        InsercionTiempos << endl;
    }

    InsercionTiempos.close();

    DestruirArreglo(datos, MAX_GRADO / INCREMENTO);

    StopSystem();
    return 0;
}