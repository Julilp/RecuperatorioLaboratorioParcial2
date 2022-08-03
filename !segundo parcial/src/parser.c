/*
 * parser.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */
#include"parser.h"

int parser_PokemonFromText(FILE* pFile , LinkedList* listaPokemones)
{
	int retorno=-1;
	int validacion;
	char numero[128];
	char nombre[51];
	char tipo[51];
	char tamanio[51];
	char ataqueCargado[51];
	char valorAtaque[128];
	char esVariocolor[128];

	ePokemon* nuevoPokemon=NULL;

	if(pFile!=NULL && listaPokemones !=NULL){
		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" ,numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
		while(!feof(pFile)){
			validacion =fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" ,numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
			if(validacion == 7){
				nuevoPokemon= Pokemon_newParametros(numero, nombre, tipo, tamanio,ataqueCargado, valorAtaque, esVariocolor);
				if(nuevoPokemon!=NULL){
					ll_add(listaPokemones,nuevoPokemon);
					//printf("%s,%s,%s,%s,%s,%s,%s \n" ,numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
					retorno=1;
				}
			}
		}
	}
    return retorno;
}
