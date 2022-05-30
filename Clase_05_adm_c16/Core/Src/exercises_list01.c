/*
 * exercises_list01.c
 *
 *  Created on: 29 may. 2022
 *      Author: carlo
 */
#include "exercises_list01.h"

void zeros(uint32_t *vector, uint32_t longitud) {
	for (uint32_t var = 0; var < longitud; ++var) {
		*(vector + var) = 0;
	}
}

void productoEscalar32(uint32_t *vectorIn, uint32_t *vectorOut,
		uint32_t longitud, uint32_t escalar) {
	for (uint32_t var = 0; var < longitud; ++var) {
		*(vectorOut + var) = *(vectorIn + var ) * escalar;
	}
}

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut,
		uint32_t longitud, uint16_t escalar) {
	for (uint32_t var = 0; var < longitud; ++var) {
		*(vectorOut + var) = *(vectorIn + var) * escalar;
	}
}

void productoEscalar12(uint16_t *vectorIn, uint16_t *vectorOut,
		uint32_t longitud, uint16_t escalar) {
	uint32_t aux_val=0;
	for (uint32_t var = 0; var < longitud; ++var) {
		aux_val = *(vectorIn + var) * escalar;
		if (aux_val >= 0b0000111111111111) {
			aux_val= 0b0000111111111111;
		}
		*(vectorOut + var) = aux_val;
	}
}
