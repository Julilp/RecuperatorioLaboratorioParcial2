/*
 * pokemon.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"
#include"Controller.h"
#include"pokemon.h"

ePokemon* Pokemon_new(){
	ePokemon* nuevoPokemon=NULL;
	nuevoPokemon=(ePokemon*)malloc(sizeof(ePokemon)*1);

	if(nuevoPokemon!=NULL){
		Pokemon_setNumero(nuevoPokemon, 0);
		Pokemon_setNombre(nuevoPokemon, "");
		Pokemon_settipo(nuevoPokemon, "");
		Pokemon_settamanio(nuevoPokemon, "");
		Pokemon_setataqueCargado(nuevoPokemon, "");
		Pokemon_setValorDeAtaque(nuevoPokemon, 0);
		Pokemon_setesVariocolor(nuevoPokemon, 0);
	}
	return nuevoPokemon;
}
int Pokemon_setNumero(ePokemon* this,int numero){

	int retorno=-1;
	if(this !=NULL && numero>0){
		this->numero=numero;
		retorno=1;
	}

	return retorno;

}
int Pokemon_getNumero(ePokemon* this,int* numero){

	int retorno =-1;
	if(this!=NULL){
		*numero=this->numero;
		retorno =1;
	}

	return retorno;
}
int Pokemon_setValorDeAtaque(ePokemon* this,int valorAtaque){

	int retorno=-1;
	if(this !=NULL && valorAtaque>0){
		this->valorAtaque=valorAtaque;
		retorno=1;
	}

	return retorno;

}
int Pokemon_getValorDeAtaque(ePokemon* this,int* valorAtaque){

	int retorno =-1;
	if(this!=NULL){
		*valorAtaque=this->valorAtaque;
		retorno =1;
	}

	return retorno;
}
int Pokemon_setesVariocolor(ePokemon* this,int esVariocolor){

	int retorno=-1;
	if(this !=NULL && esVariocolor>=0){
		this->esVariocolor=esVariocolor;
		retorno=1;
	}

	return retorno;

}
int Pokemon_getesVariocolor(ePokemon* this,int* esVariocolor){

	int retorno =-1;
	if(this!=NULL){
		*esVariocolor=this->esVariocolor;
		retorno =1;
	}

	return retorno;
}
int Pokemon_setNombre(ePokemon* this,char* nombre){

	int retorno =-1;

	if(this!=NULL && nombre !=NULL){

		strcpy(this->nombre,nombre);

		retorno =1;
	}
	return retorno;
}
int Pokemon_getNombre(ePokemon* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno =1;
	}
	return retorno;
}
int Pokemon_settipo(ePokemon* this,char* tipo){

	int retorno =-1;

	if(this!=NULL && tipo !=NULL){

		strcpy(this->tipo,tipo);

		retorno =1;
	}
	return retorno;
}
int Pokemon_gettipo(ePokemon* this,char* tipo){
	int retorno=-1;
	if(this!=NULL && tipo != NULL){
		strcpy(tipo,this->tipo);
		retorno =1;
	}
	return retorno;
}
int Pokemon_setataqueCargado(ePokemon* this,char* ataqueCargado){

	int retorno =-1;

	if(this!=NULL && ataqueCargado !=NULL){

		strcpy(this->ataqueCargado,ataqueCargado);

		retorno =1;
	}
	return retorno;
}
int Pokemon_getataqueCargado(ePokemon* this,char* ataqueCargado){
	int retorno=-1;
	if(this!=NULL && ataqueCargado != NULL){
		strcpy(ataqueCargado,this->ataqueCargado);
		retorno =1;
	}
	return retorno;
}
int Pokemon_settamanio(ePokemon* this,char* tamanio){

	int retorno =-1;

	if(this!=NULL && tamanio !=NULL){

		strcpy(this->tamanio,tamanio);

		retorno =1;
	}
	return retorno;
}
int Pokemon_gettamanio(ePokemon* this,char* tamanio){
	int retorno=-1;
	if(this!=NULL && tamanio != NULL){
		strcpy(tamanio,this->tamanio);
		retorno =1;
	}
	return retorno;
}
ePokemon* Pokemon_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataquecargadoStr,char* valorataqueStr,char* esvariocolorStr){

	ePokemon* nuevopokemon = NULL;
	if(numeroStr!=NULL && nombreStr!=NULL && nombreStr!=NULL && tipoStr!=NULL && tamanioStr!=NULL && ataquecargadoStr!=NULL && valorataqueStr != NULL && esvariocolorStr!= NULL){

		nuevopokemon = Pokemon_new();

		if(nuevopokemon !=NULL){
			if( (Pokemon_setNumero(nuevopokemon, atoi(numeroStr)))==-1||
					(Pokemon_setNombre(nuevopokemon, nombreStr))==-1||
					(Pokemon_settipo(nuevopokemon, tipoStr))==-1||
					(Pokemon_settamanio(nuevopokemon, tamanioStr))==-1||
					(Pokemon_setataqueCargado(nuevopokemon, ataquecargadoStr))==-1||
					(Pokemon_setValorDeAtaque(nuevopokemon,atoi(valorataqueStr)))==-1||
					(Pokemon_setesVariocolor(nuevopokemon ,atoi(esvariocolorStr)))==-1){
				Pokemon_delete(nuevopokemon);

				nuevopokemon=NULL;
			}

		}
	}
	return nuevopokemon;
}
void Pokemon_delete(ePokemon* this){
	if(this!=NULL){
		free(this);
		this =NULL;
	}
}
void Pokemon_ShowAPokemon(ePokemon* unP) {
	printf("%-8d|%-13s|%-10s|%-9s|%-16s|%-17d|%-13d| \n", unP->numero,unP->nombre,unP->tipo,unP->tamanio,unP->ataqueCargado,unP->valorAtaque,unP->esVariocolor );
}
int BuscarPokemon(LinkedList* listaPokemones,int* idABuscar){
	int retorno=-1;
	int id;
	ePokemon* unPokemon;

	if(listaPokemones !=NULL && idABuscar!=NULL){
		for(int i=0;i<ll_len(listaPokemones);i++){
			unPokemon=(ePokemon*)ll_get(listaPokemones,i);
			Pokemon_getNumero(unPokemon, &id);
			if(*idABuscar==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int Pokemon_FiltroDeFuego(void* unPokemon)
{
	int validacion = 0;
	char tipo[100];


	Pokemon_gettipo(unPokemon, tipo);

	if((strcmp(tipo, "Fire") == 0))
	{
		validacion = 1;
	}

	return validacion;
}
int Pokemon_FiltroDeVenenoYXl(void* unPokemon)
{
	int validacion = 0;
	char tamanio [10];
	char tipo[100];

	Pokemon_gettamanio(unPokemon, tamanio);
	Pokemon_gettipo(unPokemon, tipo);

	if((strcmp(tipo, "Poison") == 0) && (strcmp(tamanio, "XL") ==0))
	{
		validacion = 1;
	}

	return validacion;
}



