#include "FuncionesAuxiliares.hpp"

int EvaluarPolHorner(int a[], int n, int x)
{
    int polyval = a[0];

    for (int i = 1; i < n + 1; i++)
    {
        polyval = polyval * x + a[i];
    }

    return polyval;
}

int EvaluarPol(int a[], int n, int x)
{
    int polyval = a[n];
    int term;

    for (int i = 1; i <= n; ++i)
    {
        term = a[n - i];

        for (int j = 0; j < i; ++j)
        {
            term = term * x;
        }

        polyval = polyval + term;

    }

    return polyval;
}