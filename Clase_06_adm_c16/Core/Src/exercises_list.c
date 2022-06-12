/*
 * exercises_list01.c
 *
 *  Created on: 29 may. 2022
 *      Author: carlo
 */
#include <exercises_list.h>

/*
 * Ejercicio 01
 */
void zeros(uint32_t *vector, uint32_t longitud) {
	for (uint32_t var = 0; var < longitud; ++var) {
		*(vector + var) = 0;
	}
}

/*
 * Ejercicio 02
 */
void productoEscalar32(uint32_t *vectorIn, uint32_t *vectorOut,
		uint32_t longitud, uint32_t escalar) {
	for (uint32_t var = 0; var < longitud; ++var) {
		*(vectorOut + var) = *(vectorIn + var) * escalar;
	}
}

/*
 * Ejercicio 03
 */
void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut,
		uint32_t longitud, uint16_t escalar) {
	for (uint32_t var = 0; var < longitud; ++var) {
		*(vectorOut + var) = *(vectorIn + var) * escalar;
	}
}

/*
 * Ejercicio 04
 */
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

/*
 * Ejercicio 05
 */
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

/*
 * Ejercicio 06
 */
void pack32to16(int32_t *vectorIn, int16_t *vectorOut, uint32_t longitud) {
	while (longitud > 0) {
		*(vectorOut + (longitud - 1)) = *(vectorIn + (longitud - 1)) >> 16;
		longitud--;
	}
}

/*
 * Ejercicio 07
 */
int32_t max(int32_t *vectorIn, uint32_t longitud) {
	if (longitud < 1) {
		return -1;
	}

	int32_t max_val = 0;

	uint32_t pos = longitud - 1;

	while (longitud > 0) {
		if (*(vectorIn + longitud - 1) > max_val) {
			pos = longitud - 1;
			max_val = *(vectorIn + longitud - 1);
		}
		longitud--;
	}
	return pos;
}

/*
 * Ejercicio 08
 */
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

/*
 * Ejercicio 09
 */
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

/*
 * Ejercicio 11
 */
void corr(int16_t *vectorX, int16_t *vectorY, int64_t *vectorCorr,
		uint32_t longitud) {
	int64_t min_index_l = ((int32_t) longitud - 1) * -1;
	int64_t max_index_l = ((int32_t) longitud - 1);
	int32_t accum = 0;
	for (int l = min_index_l; l < max_index_l + 1; ++l) {
		accum = 0;
		for (int n = 0; n < longitud; ++n) {
			if (n - l > -1 && n - l < longitud) {
				accum = *(vectorX + n) * *(vectorY + n - l) + accum;
			}
		}
		*(vectorCorr + (l + longitud - 1)) = accum;
	}

}
