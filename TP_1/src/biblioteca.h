/*
 * biblioteca.h
 *
 *  Created on: Apr 15, 2022
 *      Author: alex
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
float calcularDebito(float);
float calcularTC(float);
float calcularBTC(float);
float calcularPrecioKM(float, float);

int elegirOperacion(void) {
	int eleccion;

	sleep(1);
	printf(
			"\nIngrese una opcion: \n    1.Ingresar kilometros a viajar.\n    2.Ingresar el precio de los vuelos.\n    3.Calcular todos los costos.\n    4.Informar resultados.\n    5.Carga forzada de datos.\n    6.Salir del programa\n");
	scanf("%d", &eleccion);
	__fpurge(stdin);
	if (eleccion > 0 && eleccion < 7) {
		return eleccion;
	} else {
		while (eleccion > 7 || eleccion < 1) {
			printf(
					"\nAlgo ocurrio mal. Probemos de vuelta: \nIngrese una opcion: \n    1.Ingresar kilometros a viajar.\n    2.Ingresar el precio de los vuelos.\n    3.Calcular todos los costos.\n    4.Informar resultados.\n    5.Carga forzada de datos.\n    6.Salir del programa\n");
			__fpurge(stdin);
			scanf("%d", &eleccion);

		}
		return eleccion;
	}
}

void cargaSubmenu(int eleccion, float *p_kilometros, float *p_Aerolineas,
		float *p_Latam) {

	float kilometros;
	float precioAA;
	float precioLatam;

	if (eleccion == 1) {

		printf(
				"\nElegiste ingresar los kilometros a recorrer.\nPor favor, ingresa este dato:\n");
		__fpurge(stdin);
		scanf("%f", &kilometros);

		//Tomo 1km como valido y 40075kms como tope, ya que es el primero total de la tierra.
		while (kilometros < 0 || kilometros > 40075) {
			printf(
					"Entrada invalida. Por favor ingrese nuevamente los kilometros a viajar: ");
			scanf("%f", &kilometros);
		}

		(*p_kilometros) = kilometros;

	} else {

		printf("\nElegiste ingresar el precio del viaje.");
		printf("\nPor favor, ingresa el precio para Aerolineas Argentinas:\n");
		__fpurge(stdin);
		scanf("%f", &precioAA);

		//Le pongo como valores validos mil y un millon ars: principalmente para hacerlo un poco mas "real" y que no muestre resultados negativos o irrisorios
		while (precioAA < 1000 || precioAA > 1000000) {
			printf(
					"Entrada invalida. Por favor ingrese nuevamente el precio del pasaje: ");
			scanf("%f", &precioAA);
		}
		(*p_Aerolineas) = precioAA;

		printf("\nPor favor, ingresa el precio para Latam:\n");
		__fpurge(stdin);
		scanf("%f", &precioLatam);

		while (precioLatam < 1000 || precioLatam > 1000000) {
			printf(
					"Entrada invalida. Por favor ingrese nuevamente el precio del pasaje: ");
			scanf("%f", &precioLatam);
		}
		(*p_Latam) = precioLatam;

	}
}

void calcularCostos(float kilometros, float precioAerolineas, float precioLatam,
		float aerolineasArr[], float latamArr[]) {

	float tarjetaDebitoAA;
	float tarjetaCreditoAA;
	float bitcoinAA;
	float precioKmAA;

	float tarjetaDebitoLatam;
	float tarjetaCreditoLatam;
	float bitcoinLatam;
	float precioKmLatam;

	tarjetaDebitoAA = calcularDebito(precioAerolineas);
	tarjetaCreditoAA = calcularTC(precioAerolineas);
	bitcoinAA = calcularBTC(precioAerolineas);
	precioKmAA = calcularPrecioKM(precioAerolineas, kilometros);

	tarjetaDebitoLatam = calcularDebito(precioLatam);
	tarjetaCreditoLatam = calcularTC(precioLatam);
	bitcoinLatam = calcularBTC(precioLatam);
	precioKmLatam = calcularPrecioKM(precioLatam, kilometros);

// Cada indice del array hace referencia a info particular para cada aerolinea.
	aerolineasArr[0] = precioAerolineas;
	aerolineasArr[1] = tarjetaDebitoAA;
	aerolineasArr[2] = tarjetaCreditoAA;
	aerolineasArr[3] = bitcoinAA;
	aerolineasArr[4] = precioKmAA;

	latamArr[0] = precioLatam;
	latamArr[1] = tarjetaDebitoLatam;
	latamArr[2] = tarjetaCreditoLatam;
	latamArr[3] = bitcoinLatam;
	latamArr[4] = precioKmLatam;

}

void informarResultados(float resultadosAerolineas[], float resultadosLatam[]) {
//	system("clear");
	printf("\nPrecio Aerolineas Argentinas: %.2f", resultadosAerolineas[0]);
	printf("\n    a) Precio con tarjeta de debito: $%.2f",
			resultadosAerolineas[1]);
	printf("\n    b) Precio con tarjeta de credito: $%.2f",
			resultadosAerolineas[2]);
	printf("\n    c) Precio pagando con Bitcoin: $%.8f",
			resultadosAerolineas[3]);
	printf("\n    d) Precio por kilometro: $%.2f", resultadosAerolineas[4]);

	printf("\n\nPrecio Latam: %.2f", resultadosLatam[0]);
	printf("\n    a) Precio con tarjeta de debito: $%.2f", resultadosLatam[1]);
	printf("\n    b) Precio con tarjeta de credito: $%.2f", resultadosLatam[2]);
	printf("\n    c) Precio pagando con Bitcoin: $%.8f", resultadosLatam[3]);
	printf("\n    d) Precio por kilometro: $%.2f", resultadosLatam[4]);

//La valicación es para ver que los numeros no sean iguales y que no haya resultados negativos
	if (resultadosAerolineas[0] == resultadosLatam[0]) {
		printf("\nNo hay diferencia de precio entre ambos.");
	} else if (resultadosAerolineas[0] > resultadosLatam[0]) {
		printf("\n\nLa diferencia entre ambas es de $%.2f",
				resultadosAerolineas[0] - resultadosLatam[0]);
	} else {

		printf("\nLa diferencia entre ambas es de $%.2f",
				resultadosLatam[0] - resultadosAerolineas[0]);
	}

}

void mostrarDatosHC(void) {
// Esta funcion muestra los datos hardcodeados.
	float kilometros = 9000;
	float precioAA = 100000;
	float precioLatam = 90000;
	float resultadosAerolineas[5];
	float resultadosLatam[5];

	calcularCostos(kilometros, precioAA, precioLatam, resultadosAerolineas,
			resultadosLatam);

	informarResultados(resultadosAerolineas, resultadosLatam);

}

#endif /* BIBLIOTECA_H_ */
