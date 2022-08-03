/*
 * controller.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"

int Lopez_Pokemon_CargarTexto(char* path,LinkedList* pokemonList)
{
	int retorno=-1;
	FILE* pArchivo;
	if(path!=NULL && pokemonList != NULL){
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL){
			//printf("entro");
			parser_PokemonFromText(pArchivo, pokemonList);
			retorno=1;
			printf("Se cargo correctamente el archivo\n");
		}
		else{
			printf("No se pudo leer el archivo\n");
		}
		fclose(pArchivo);
	}

    return retorno;
}
int Lopez_Pokemon_ListPokemon(LinkedList* pokemonList)
{
	int retorno = 0;
	int size;
	size=ll_len(pokemonList);
	ePokemon* nuevoPokemon=NULL;
	if(pokemonList != NULL){
		printf("------------------------------------------------------------------------\n");
		printf("                       LISTA DE POKEMONES                               \n");
		printf("------------------------------------------------------------------------\n");
		printf("NUMERO  |    NOMBRE   |   TIPO   | TAMANIO | ATAQUE CARGADO | VALOR DE ATAQUE | VARIO COLOR |\n");
		for(int i=0; i<size;i++){
		nuevoPokemon = (ePokemon*)ll_get(pokemonList,i);
		if(nuevoPokemon!=NULL){
			Pokemon_ShowAPokemon(nuevoPokemon);
		}
	 }
		retorno = 1;
	}
    return retorno;
}
int Lopez_PokemonEdit(LinkedList* pokemonList)
{
	int numero;
	int tam;
	int index;
	int option;
	int valorAtaque;

	ePokemon* pokemonModificar;
	if(pokemonList !=NULL){

		tam=ll_len(pokemonList);
		do{
			pedirEntero(&numero, "ingrese el numero del pokemon a modificar: ","el numero no esta dentro de los parametros 1/150", 1, tam);
			index=BuscarPokemon(pokemonList, &numero);
			//printf("este es el index %d",index);
		}while(index==-1);

		pokemonModificar=(ePokemon*)ll_get(pokemonList,index);
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("                          		POKEMON A MODIFICAR                                              \n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("NUMERO  |    NOMBRE   |   TIPO   | TAMANIO | ATAQUE CARGADO | VALOR DE ATAQUE | VARIO COLOR |\n");
		Pokemon_ShowAPokemon(pokemonModificar);
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("				    >>Seleccione Para Modificar<<						    \n");
		printf("							1.VALOR DE ATAQUE         			   \n");
		printf("						    2.SALIR	      \n");

		pedirEntero(&option, "Opcion->", "no esta dentro de los limites: ", 1, 2);

		switch(option){
		case 1:
			printf("------MENU DE VALOR DE ATAQUE-----\n");
			printf("valor de ataque viejo -> %d\n",pokemonModificar->valorAtaque);
			pedirEntero(&valorAtaque, "nuevo valor de ataque: ", "no esta dentro de los limites: ", 1, 999999);
			Pokemon_setValorDeAtaque(pokemonModificar, valorAtaque);
		break;
		case 2:
		printf("SALIENDO.....");
		break;
		}
	}
    return 1;
}
void Lopez_Pokemon_FiltroFuego(LinkedList* listaPokemonesAux,LinkedList* listaPokemones){
	listaPokemonesAux = ll_filter(listaPokemones, Pokemon_FiltroDeFuego);
	Lopez_Pokemon_ListPokemon(listaPokemonesAux);
}
void Lopez_Pokemon_FiltroVeneno(LinkedList* listaPokemonesAux,LinkedList* listaPokemones){
	listaPokemonesAux = ll_filter(listaPokemones,Pokemon_FiltroDeVenenoYXl );
		Lopez_Pokemon_ListPokemon(listaPokemonesAux);
}
void Lopez_Pokemon_MapAtaque(LinkedList* listaPokemones){
	listaPokemones=ll_map(listaPokemones, Pokemon_MapAtaque);
	Lopez_Pokemon_ListPokemon(listaPokemones);
}
void Lopez_Pokemon_BatallaJefe(LinkedList* listaPokemones, int contador){
	contador=ll_count(listaPokemones, Pokemon_Batalla);
	if(contador>=3){
		printf("tienes %d Pokemones para vencer al jefe, Te felicito, ganaste esta batalla\n",contador);
	}
	else{
		printf("tienes %d pokemones, no eres los suficientemente fuerte, lo siento\n",contador);
	}
}
