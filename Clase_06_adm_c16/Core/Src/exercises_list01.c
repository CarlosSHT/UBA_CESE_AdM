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
		*(vectorOut + var) = *(vectorIn + var) * escalar;
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
	uint32_t aux_val = 0;
	for (uint32_t var = 0; var < longitud; ++var) {
		aux_val = *(vectorIn + var) * escalar;
		if (aux_val >= 0b0000111111111111) {
			aux_val = 0b0000111111111111;
		}
		*(vectorOut + var) = aux_val;
	}
}

// Segunda Parte Preguntas 5-9

void filtroVentana10(uint16_t *vectorIn, uint16_t *vectorOut,
		uint32_t longitudVectorIn) {
	uint8_t nn_win = 10;	 // <- modify size
	uint8_t aux_n_win = nn_win;
	uint32_t accum_val;
	uint32_t aux_lenVect = longitudVectorIn;
	while (aux_lenVect > 0) {
		accum_val = 0;
		while (aux_n_win > 0) {
			accum_val +=
					*(vectorIn
							+ (((aux_lenVect - 1) + (aux_n_win - 1))
									% longitudVectorIn));
			aux_n_win--;
		}
		aux_n_win = nn_win;
		*(vectorOut + aux_lenVect - 1) = accum_val / aux_n_win;
		aux_lenVect--;
	}
}

void pack32to16(int32_t *vectorIn, int16_t *vectorOut, uint32_t longitud) {
	while (longitud > 0) {
		*(vectorOut + (longitud - 1)) = *(vectorIn + (longitud - 1)) >> 16;
		longitud--;
	}
}

int32_t max(int32_t *vectorIn, uint32_t longitud) {
	if (longitud < 1) {
		return -1;
	}

	int32_t max_val = 0;

	uint32_t index = 0, pos = 0;

	while (index < longitud) {
		if (*(vectorIn + index) > max_val) {
			pos = index;
			max_val = *(vectorIn + index);
		}
		index++;
	}
	return pos;
}

void downsampleM(int32_t *vectorIn, int32_t *vectorOut, uint32_t longitud,
		uint32_t N) {
	uint32_t aux_inx_IN = 0, aux_inx_OUT = 0;

	while (aux_inx_IN < longitud) {
		if (N == 0) {
			break;
		}
		*(vectorOut + aux_inx_OUT) = *(vectorIn + aux_inx_IN);
		aux_inx_OUT++;
		if ((aux_inx_IN + 1) % N == 0) {
			aux_inx_OUT--;
			*(vectorOut + aux_inx_OUT) = 0;
		}
		aux_inx_IN++;
	}
}

void invertir(uint16_t *vector, uint32_t longitud) {
	uint16_t aux_val;
	uint32_t mid_long = longitud / 2, aux_idx = 0;
	while (aux_idx < mid_long) {
		aux_val = *(vector + aux_idx);
		*(vector + aux_idx) = *(vector + (longitud - 1 - aux_idx));
		*(vector + (longitud - 1 - aux_idx)) = aux_val;
		aux_idx++;
	}
}

