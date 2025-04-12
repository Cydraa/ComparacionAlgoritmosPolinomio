#pragma once

/**
* \file
*/

/**
* \brief Aleatoriza valores dentro de un rango dado.
*
* \param inicio Inicio del rango.
* \param fin Fin del rango.
* \return Un n&uacute;mero al azar dentro del rango especificado.
*/
int Aleatorizar(int inicio, int fin);

/**
* \brief Crea un arreglo din&aacute;mico de dos dimensiones usando un puntero a puntero entero (tipo del arreglo) que apunta al arreglo blanco.
*
* \param m Renglones del arreglo 2D (tama&ntilde;o de arreglo de punteros).
* \param n Columnas del arreglo 2D (tama&ntilde;o de los arreglos blanco).
* \return Un puntero a puntero entero.
*/
int** CrearArreglo(int m, int n);

/**
* \brief Destruye un arreglo din&aacute;mico de dos dimensiones de la estructura usando un puntero a puntero entero (tipo del arreglo) que apunta al arreglo blanco.
*
* \param arreglo El arreglo de dos dimensiones.
* \param m Columnas del arreglo 2D.
*/
void DestruirArreglo(int**& arreglo, int m);

/**
* \brief Limpia el b&uacute;ffer de caracteres.
*/
void CleanBuffer();

/**
* \brief Realiza una pausa del programa, compatible con Linux y Windows.
*/
void StopSystem();


