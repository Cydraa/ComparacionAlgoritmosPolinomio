#pragma once

/**
* \file
*/

/**
* \brief Eval&uacute;a un polinomio usando la regla de Horner. El algoritmo calcula el valor del polinomio ( f(x) ), se le asigna el valor del polinomio inicial con el primer t&eacute;rmino, el valor actual se multiplica por x y se le suma el coeficiente siguiente m&aacute;s bajo del polinomio hasta llegar al final del polinomio.
*
* \param a Arreglo de los coeficientes del polinomio.
* \param n Grado del polinomio.
* \param x Valor de x a evaluar.
* \return f(x), El valor del polinomio evaluado en x como un entero.
*/
int EvaluarPolHorner(int a[], int n, int x);

/**
* \brief Eval&uacute;a un polinomio por el m&eacute;todo est&aacute;ndar. El algoritmo calcula el valor del polinomio ( f(x) ) realizando una sumatoria del calculo de t&eacute;rmino, comenzando por el &uacute;ltimo.
*
* \param a Arreglo de los coeficientes del polinomio.
* \param n Grado del polinomio.
* \param x Valor de x a evaluar.
* \return f(x), El valor del polinomio evaluado en x como un entero.
*/
int EvaluarPol(int a[], int n, int x);