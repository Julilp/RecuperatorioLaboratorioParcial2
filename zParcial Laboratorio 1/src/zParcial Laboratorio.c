/*
 ============================================================================
 Name        : PRIMER.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#include "listados.h"
#define TAMMEDICOS 4
#define TAMENFERMERAS 4
#define TAMLOCALIDADES 4
#define TAMESPECIALIDADES 4
#define TAMENFERMEDADES 4

int main(void)
{

	setbuf(stdout,NULL);
	iniciarPrograma(listaDeConsultas, TAM);
	int opcion;
	int bandera=1;
	eEnfermera listaEnfermeras[TAMENFERMERAS];
	eDiagnostico diagnosticos[TAMENFERMEDADES];
	eEspecialidad listaEspecialidades[TAMESPECIALIDADES];
	eMedico listaMedicos [TAMMEDICOS];
	eLocalidad listaDeLocalidades [TAMLOCALIDADES];
	datosHardcodeadas(listaMedicos, listaEspecialidades, listaEnfermeras, diagnosticos,listaDeLocalidades);
	consultasHardcodeadas(listaDeConsultas);
	do
	{

		printf( " ====================================\n"
				" |           1-ALTA CONSULTA         |\n"
				" |           2-MODIFICAR CONSULTA    |\n"
				" |           3-CANCELAR CONSULTA     |\n"
				" |           4-DIAGNOSTICAR          |\n"
				" |           5-LISTAR                |\n "
				"|           6-SALIR                 |\n"
				" =====================================\n");

		opcion=IngresarEntero( "Ingrese una opcion: ",1,6);

		switch(opcion)
		{
		case 1:
			pedirDatos( listaDeConsultas,TAM);
			bandera=1;
		break;
		case 2:
			if(bandera==1)
			{
				if(modificarConsulta( listaDeConsultas,TAM,listaMedicos,listaEspecialidades,TAMESPECIALIDADES)==1){
					printf("Se han guardado los cambios correctamente\n");
				}
				else{
					printf("Hubo un error guardando las modificaciones\n");
				}
			}
			else
			{
				printf("Primero debe realizarse un alta...");
			}
		break;
		case 3:
			if(bandera==1)
			{
				if(bajaDeConsulta( listaDeConsultas,TAM)==1){
					printf("Se elimino de manera exitosa la consulta\n");
				}
				else{
					printf("No se elimino la consulta\n");
				}
			}
			else
			{
				printf("Primero debe realizarse un alta...");
			}
		break;
		case 4:
			if(bandera==1)
			{
				if(diagnosticar ( listaDeConsultas, listaMedicos, diagnosticos, TAM,listaEnfermeras,listaEspecialidades,listaDeLocalidades,TAMENFERMERAS,TAMESPECIALIDADES)==1){
					printf("Se diagnostico la consulta Correctamente\n");
				}
				else{
					printf("Hubo un error al diagnosticar al paciente\n");
				}
			}
			else
			{
				printf("Primero debe realizarse un alta...");
			}
		break;
		case 5:
				subMenuListar(listaDeConsultas, listaMedicos, diagnosticos,listaEnfermeras,listaEspecialidades,listaDeLocalidades,TAMMEDICOS,TAMENFERMERAS,TAMLOCALIDADES,TAMESPECIALIDADES,TAMESPECIALIDADES);
		break;


		}

	}while(opcion!=6);

	return 0;
}
