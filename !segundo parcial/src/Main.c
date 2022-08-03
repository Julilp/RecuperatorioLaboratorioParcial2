/*
 ============================================================================
 Name        : !segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "pokemon.h"
#include "parser.h"
#include "LinkedList.h"
int main(void) {

	setbuf(stdout,NULL);
	LinkedList* listaPokemones=ll_newLinkedList();
	LinkedList* listaPokemonesAux = ll_newLinkedList();
	int opcion;
	do{
		printf("-------------------------------------------------------------\n");
		printf("1.Cargar el archivo de pokemones\n");
		printf("2.Modificar valor de ataque\n");
		printf("3.Imprimir pokemones\n");
		printf("4.Filtrar tipo de fuego\n");
		printf("5.Filtrar extra-grandes\n");
		printf("6.Salir\n");
		printf("-------------------------------------------------------------\n");
		printf("ingrese una opcion: ");
		scanf("%d",&opcion);

		switch(opcion){
		case 1:
			Lopez_Pokemon_CargarTexto("C:\\Users\\Julian lopez\\eclipse-workspace\\!segundo parcial\\src\\Data_Pokemones.csv", listaPokemones);
			break;
		case 2:
			if(ll_isEmpty(listaPokemones)==0)
				{
					Lopez_PokemonEdit(listaPokemones);

				}
				else
				{
					printf("No hay pokemones cargados para mostrar.\n");
				}

			break;
		case 3:
			if(ll_isEmpty(listaPokemones)==0)
				{
					Lopez_Pokemon_ListPokemon(listaPokemones);

				}
				else
				{
					printf("No hay pokemones cargados para mostrar.\n");
				}

			break;
		case 4:
			if(ll_isEmpty(listaPokemones)==0)
			{
				listaPokemonesAux = ll_filter(listaPokemones, Pokemon_FiltroDeFuego);
				Lopez_Pokemon_ListPokemon(listaPokemonesAux);
			}
			else
			{
				printf("No hay pokemones cargados para mostrar.\n");
			}
			break;
		case 5:
			if(ll_isEmpty(listaPokemones)==0)
				{
				listaPokemonesAux = ll_filter(listaPokemones,Pokemon_FiltroDeVenenoYXl );
					Lopez_Pokemon_ListPokemon(listaPokemonesAux);
				}
				else
				{
					printf("No hay pokemones cargados para mostrar.\n");
				}
			break;

		}

	}while(opcion!=6);
}
