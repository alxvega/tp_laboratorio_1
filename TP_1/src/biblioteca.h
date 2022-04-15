/*
 * biblioteca.h
 *
 *  Created on: Apr 15, 2022
 *      Author: alex
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int elegirOperacion(void);
void cargaSubmenu(int, float*, float*, float*);
void calcularCostos(float, float, float, float[], float[]);
void informarResultados(float[], float[]);
void mostrarDatosHC(void);

#endif /* BIBLIOTECA_H_ */
