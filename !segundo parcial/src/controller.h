/*
 * controller.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "pokemon.h"
#include "parser.h"
#include "LinkedList.h"
#include "inputs.h"



int Lopez_Pokemon_CargarTexto(char* path , LinkedList* pokemonList);
int Lopez_Pokemon_ListPokemon(LinkedList* pokemonList);
int Lopez_PokemonEdit(LinkedList* pokemonList);
LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*));
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*));
#endif /* CONTROLLER_H_ */
