/*
 * inputs.c
 *
 *  Created on: 28 jul. 2022
 *      Author: Julian lopez
 */

/*
 * inputs.c
 *
 *  Created on: 3 jun. 2022
 *      Author: Julian lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max, int val)
{
	int retorno = -1;
	char buffer[256];
	int tam;
	int validacion;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);
		if(val==1){
			validacion=validacionDeCaracteres(buffer);
			while(validacion==-1){
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%[^\n]", buffer);
				validacion=validacionDeCaracteres(buffer);
			}
		}
		while(tam > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}

		strcpy(cadena, buffer);
		retorno = 0;
	}

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

int isChar(char string[])
{
	int isOk = 0;
	int i;
	int stringTam = strlen(string);

	for(i = 0; i<stringTam; i++)
	{
		if((string[i] == ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
		{
			isOk = -1;
			break;
		}
	}

	return isOk;
}

int getString(char input[], int tam)
{
    char auxString[tam];
    int isOk = -1;

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        fgets(auxString,tam,stdin);
        if (auxString[strlen(auxString)-1]=='\n')//le cambia el enter por el final
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= tam)
        {
            strncpy(input, auxString, tam);//copia cadena en la variable destino
            isOk=0;
        }
    }
    return isOk;
}

int SizeString(char string[])
{
	int isOk = -1;
	int i = 0;

	if(string != NULL)
	{
		strlwr(string);//convierte la cadena en minuscula
		string[0] = toupper(string[0]); //toupper convierte la primer letra en mayuscula
		while(string[i] != '\0')
		{
			if(string[i] == ' ')
			{
				string[i + 1] = toupper(string[i + 1]);
				isOk = 0;
			}
			i++;
		}
	}
	return isOk;
}

int utn_getString(char input[], char mensaje[], char mensajeError[], int tam, int reintentos)
{
	int isOk = 1;
    char auxString[tam];

    if(input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0 && reintentos >= 0)
    {
        do{
        	printf("%s", mensaje);
            if(!(getString(auxString,tam)) && !(isChar(auxString)))
            {
                strncpy(input,auxString,tam);
                isOk = 0;
                break;
            }
            else
            {
            	printf("%s", mensajeError);
            	reintentos--;
            }

        }while(reintentos>=0);
    }
    return isOk;
}
//-----------------------------------INT-----------------------------------
int isInt(char input[])
{
    int isOk = 0;
    int i = 0;
    int stringTam = strlen(input); //devuelve la longitud de la cadena sin contar el nulo final \0

    for(i=0; i<stringTam ;i++)
    {
    	if(input[i]< '0' || input[i]> '9' )
        {
    		isOk=-1;
            break;
        }
    }
    return isOk;
}

int getInt(int* input)
{
    char auxString[400];
    int isOk = -1;

    if(!(getString(auxString,sizeof(auxString))) && !(isInt(auxString))) //podria usar sizeof(auxString) en vez del valor fijo 400
    {
    	*input=atoi(auxString); // RECIBE UNA CADENA Y DEVUELVE UN VALOR INT
    	isOk=0;
    }
    return isOk;
}

int utn_getInt(int* input, char mensaje[], char mensajeError[], int min, int max, int reintentos)
{
    int isOk=-1;
    int auxInt;

   if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 && input != NULL)
   {
	   do
	   {
			reintentos--;
			printf("%s", mensaje);
			if(!(getInt(&auxInt)) && auxInt >= min && auxInt <= max)
			{
				*input= auxInt;
				isOk = 0;
				break;
			}
			else
			{
				printf("%s ",mensajeError);
			}
	   }
	   while(reintentos >= 0);
   }
    return isOk;
}
//-----------------------------------FLOAT-----------------------------------
int isFloat(char input[])
{
    int isOk = 0;
    int i;
    int stringTam = strlen(input);

    for(i=0; i<stringTam ;i++)
    {
        if((input[i]< '0' || input[i]> '9' ) && (input[i]!='.'))
        {
        	isOk = -1;
            break;
        }
    }

    return isOk;
}

int getFloat(float* input)
{
    char auxString[200];
    int isOk =-1;

    if(!(getString(auxString,200)) && !(isFloat(auxString)))
    {
        *input = atof(auxString); //CONVIERTE A FLOAT LA CADENA
        isOk = 0;
    }

    return isOk;
}

int utn_getFloat(float* input, char mensaje[], char mensajeError[], float min, float max, int reintentos)
{
    int isOk = -1;
    float auxFloat;

    if(input != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
        	printf("%s", mensaje);
        	if(!(getFloat(&auxFloat)) && auxFloat >= min && auxFloat <= max)
        	{
        		*input= auxFloat;
        		isOk = 0;
        		break;
        	}
        	else
        	{
        		printf("%s ",mensajeError);
        		reintentos--;
        	}
        }
        while(reintentos >= 0);
    }
    return isOk;
}
int validacionDeCaracteres (char* cadena)
{
	int size = strlen(cadena);
	int validacion=-1;

	for(int i=0;i<size;i++)
	{
		if((*(cadena+i) > 64 &&*(cadena+i) < 91) || (*(cadena+i) > 96 &&*(cadena+i) < 123))
		{
			validacion=0;
		}
		else{
			validacion=-1;
			break;
		}
	}
	return validacion;
}
