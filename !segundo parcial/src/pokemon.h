/*
 * pokemon.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */

#ifndef POKEMON_H_
#define POKEMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
struct
{
	int numero;
	char nombre[51];
	char tipo[51];
	char tamanio[51];
	char ataqueCargado[51];
	int valorAtaque;
	int esVariocolor;
}typedef ePokemon;

ePokemon* Pokemon_new();
#endif /* POKEMON_H_ */
int Pokemon_setNumero(ePokemon* this,int numero);
int Pokemon_getNumero(ePokemon* this,int* numero);
int Pokemon_setValorDeAtaque(ePokemon* this,int valorAtaque);
int Pokemon_getValorDeAtaque(ePokemon* this,int* valorAtaque);
int Pokemon_setesVariocolor(ePokemon* this,int esVariocolor);
int Pokemon_getesVariocolor(ePokemon* this,int* esVariocolor);
int Pokemon_setNombre(ePokemon* this,char* nombre);
int Pokemon_getNombre(ePokemon* this,char* nombre);
int Pokemon_settipo(ePokemon* this,char* tipo);
int Pokemon_gettipo(ePokemon* this,char* tipo);
int Pokemon_setataqueCargado(ePokemon* this,char* ataqueCargado);
int Pokemon_gettipo(ePokemon* this,char* ataqueCargado);
int Pokemon_settamanio(ePokemon* this,char* tamanio);
int Pokemon_gettamanio(ePokemon* this,char* tamanio);
ePokemon* Pokemon_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataquecargadoStr,char* valorataqueStr,char* esvariocolorStr);
void Pokemon_delete(ePokemon* this);
void Pokemon_ShowAPokemon(ePokemon* unP);
int BuscarPokemon(LinkedList* listaPokemones,int* idABuscar);
int Pokemon_FiltroDeFuego(void* unPokemon);
int Pokemon_FiltroDeVenenoYXl(void* unPokemon);

