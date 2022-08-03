/*
 * inputs.h
 *
 *  Created on: 3 jun. 2022
 *      Author: Julian lopez
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
int validacionDeCaracteres (char* cadena);
int verificarConfirmacion(char* mensaje);
/**
 * @fn int pedirEntero(int*, char*, char*, min, max)
 * @brief funcion que imprime un mensaje solicitando un int, en caso de error en las validaciones imprime el mensaje de error hasta ingresarlo correctamente
 *
 * @param input el valor que ingreso el usuario
 * @param mensaje imprime un mensaje
 * @param mensajeError imprime un mensaje de error
 * @param min tamaño minimo que puede tomar el numero
 * @param max tamaño maximo que puede tomar el numero
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
/**
 * @fn int pedirCadena(char*, char*, char*, int )
 * @brief paso un mensaje pidiendo un input de tipo cadena, si encuentra un error envia el mensaje de error hasta ingresarlo correctamente
 *
 * @param input valor de tipo cadena que va a ingresar el usuario
 * @param mensaje imprime un mensaje
 * @param mensajeError imprime un mensaje de error
 * @param tam le paso el tamaño reservado
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max, int val);
/**
 * @fn int pedirCaracter(char*, char*)
 * @brief paso un caracter, si encuentra un error envia el mensaje de error hasta ingresarlo correctamente
 *
 * @param input valor del caracter ingresado por el usuario
 * @param mensaje imprime un mensaje
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int pedirCaracter(char* caracter, char* mensaje);

//-----------------------------------------------CHAR----------------------------------------------------
/**
 * @fn int isChar(char[])
 * @brief verifica si la cadena es de tipo texto
 *
 * @param string recibe una cadena
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int isChar(char string[]);
/**
 * @fn int getString(char[], int)
 * @brief verifica en mi cadena si tengo un enter y convierte mi \n en mi final \0
 *
 * @param string recibe una cadena
 * @param tam le paso el tamaño que va a tener la cadena
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int getString(char input[], int tam);
/**
 * @fn int SizeString(char[])
 * @brief convierte toda la cadena en minuscula excepto la primer letra
 *
 * @param string recibe una cadena
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int SizeString(char string[]);
/**
 * @fn int utn_getString(char[], char[], char[], int, int)
 * @brief paso un mensaje pidiendo un input de tipo cadena, si encuentra un error me descuenta en los reintentos y envia el mensaje de error
 *
 * @param mensaje imprime un mensaje
 * @param mensajeError imprime un mensaje de error
 * @param tam le paso el tamaño reservado
 * @param reintentos le paso la cantidad de intentos para que ingrese el input
 * @param input valor de tipo cadena que va a ingresar el usuario
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int utn_getString(char input[], char mensaje[], char mensajeError[], int tam, int reintentos);
//-----------------------------------------------INT-----------------------------------------------------
/**
 * @fn int isInt(char[])
 * @brief  revisa si la cadena tiene incluido numeros
 *
 * @param resultado la cadena a analizar
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int isInt(char input[]);
/**
 * @fn int getInt(int*)
 * @brief revisa que sea cadena de numeros tipo int
 *
 * @param input valor int ingresado por el usuario
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int getInt(int* input);
/**
 * @fn int utn_getInt(int*, char[], char[], int, int, int)
 * @brief funcion que imprime un mensaje solicitando un int, en caso de error en las validaciones imprime el mensaje de error y va descontando los reintentos
 *
 * @param mensaje imprime un mensaje
 * @param mensajeError imprime un mensaje de error
 * @param min tamaño minimo que puede tomar el numero
 * @param max tamaño maximo que puede tomar el numero
 * @param reintentos cantidad total de reintentos que tiene para equivocarse
 * @param input el valor que ingreso el usuario
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int utn_getInt(int* input, char mensaje[], char mensajeError[], int min, int max, int reintentos);
//----------------------------------------------FLOAT----------------------------------------------------
/**
 * @fn int isFloat(char[])
 * @brief revisa si es numero y tiene '.' para ser de tipo float
 *
 * @param resultadov recibe una cadena
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int isFloat(char input[]);
/**
 * @fn int getFloat(float*)
 * @brief revisa si es una cadena de flotantes
 *
 * @param input ingresa un valor tipo float
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int getFloat(float* input);
/**
 * @fn int utn_getFloat(float*, char[], char[], float, float, int)
 * @brief funcion que imprime un mensaje solicitando un float, en caso de error en las validaciones imprime el mensaje de error y va descontando los reintentos
 *
 * @param mensaje imprime un mensaje solicitando un numero float
 * @param mensajeError imprime un mensaje de error si se ingresa un parametro incorrecto
 * @param min tamaño minimo del numero float
 * @param max tamaño maximo del numero float
 * @param reintentos cantidad de reintentos para ingresar el numero
 * @param input el valor ingresado por el usuario
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int utn_getFloat(float* input, char mensaje[], char mensajeError[], float min, float max, int reintentos);


#endif /* INPUTS_H_ */


