/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alex Vega
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <unistd.h>
#include "biblioteca.h"
#include "cuentas.h"


int main(void) {

	int finalizado = 0;
	int eleccion;
	int flag_km = 0;
	int flag_precio = 0;
	int flag_carga = 0;
	char confirmacion;
	float kilometros;
	float precioAA;
	float precioLatam;
	float resultadosAerolineas[5];
	float resultadosLatam[5];

	setbuf(stdout, NULL);
	printf("   ----Bienvenido al calculador de viajes de la UTN----"
			"\n     ----Autor: Alex Vega Div F 2022.----");

	while (finalizado == 0) {

		eleccion = elegirOperacion();

		switch (eleccion) {

		case 1:
			cargaSubmenu(eleccion, &kilometros, &precioAA, &precioLatam);
			flag_km = 1;
			printf("Kilometros a recorrer: %.0f.\n", kilometros);
			break;

		case 2:
			cargaSubmenu(eleccion, &kilometros, &precioAA, &precioLatam);
			flag_precio = 1;
			printf("%.2f Este es el precio a priori de AA.\n", precioAA);
			printf("%.2f Este es el precio a priori LATAM.\n", precioLatam);
			break;

		case 3:

			if (flag_km == 1 && flag_precio == 1) {
				printf("Calculando costos...");
				calcularCostos(kilometros, precioAA, precioLatam,
						resultadosAerolineas, resultadosLatam);
				flag_carga = 1;

			} else {
				printf(
						"No se pueden calcular los ya que hubo faltante de datos ingresados, en km o precio. Intenta nuevamente :)");
			}
			break;

		case 4:
			if (flag_carga == 1) {

				informarResultados(resultadosAerolineas, resultadosLatam);
				finalizado = 1;
			} else {

				printf(
						"No se pueden informar los resultados ya que aun no se calcularon. Ingresa la opcion 3 y volve luego aqui :)");
			}

			break;
		case 5:
			switch (flag_carga) {
			case 1:
				printf(
						"Veo tenes datos cargados, deseas aun asi ver los datos predeterminados? 's' para continuar o cualquier caracter para volver al menu: ");
				scanf("%c", &confirmacion);
				if (confirmacion == 's') {
					mostrarDatosHC();
					finalizado = 1;
				} else {
					continue;
				}
				break;
			default:
				mostrarDatosHC();
				finalizado = 1;

			}
			break;

		case 6:
			printf("Elegiste salir del programa. ¡Nos vemos! :)");
			finalizado = 1;
			break;

		}

	}

	return EXIT_SUCCESS;

}




