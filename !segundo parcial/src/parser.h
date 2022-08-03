/*
 * parser.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "pokemon.h"

int parser_PokemonFromText(FILE* pFile , LinkedList* pokemonList);


#endif /* PARSER_H_ */
