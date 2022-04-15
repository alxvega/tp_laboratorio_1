/*
 * cuentas.c
 *
 *  Created on: Apr 15, 2022
 *      Author: alex
 */


float calcularDebito(float precioAerolinea) {
	float precioDebito;
	precioDebito = precioAerolinea - (precioAerolinea * 10 / 100);
	return precioDebito;
}
float calcularTC(float precioAerolinea) {
	float precioTC;
	precioTC = precioAerolinea + (precioAerolinea * 25 / 100);
	return precioTC;
}

float calcularBTC(float precioAerolinea) {
	float precioBTC;
	float cotizacionBitcoin = 4926973.42;

	precioBTC = precioAerolinea / cotizacionBitcoin;
	return precioBTC;
}
float calcularPrecioKM(float precioAerolinea, float kilometros) {
	float precioKm;

	precioKm = precioAerolinea / kilometros;
	return precioKm;
}
