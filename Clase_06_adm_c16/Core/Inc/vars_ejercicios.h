/*
 * vars_ejercicios.h
 *
 *  Created on: 10 jun. 2022
 *      Author: carlo
 */

#ifndef INC_VARS_EJERCICIOS_H_
#define INC_VARS_EJERCICIOS_H_

/*
 * Ejercicio 01:
 * 	void zeros (uint32_t * vector, uint32_t longitud);
 *
 * Entrada:		uint32_t vectorIN_zeros_32bit[]
 */
uint32_t vectorIN_zeros_32bit[] = { 3253827241, 733923345, 119396060, 841052654,
		4145934 };

/*
 * Ejercicio 02:
 * 	void productoEscalar32 (uint32_t * vectorIn, uint32_t * vectorOut uint32_t longitud, uint32_t escalar);
 *
 * Entrada:		uint32_t vectorIN_32b[]
 * Salida:		uint32_t vectorOUT_32b[5]
 */
//uint32_t vectorIN_32b[]={3253827241,733923345,119396060,841052654,4145934};
uint32_t vectorIN_32b[] = { 2, 3, 4, 5, 6 };
uint32_t vectorOUT_32b[5] = { 0 };

/*
 * Ejercicio 03:
 * 	void productoEscalar16 (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
 *
 * Entrada:		uint16_t vectorIN_16b[]
 * Salida:		uint16_t vectorOUT_16b[5]
 */
uint16_t vectorIN_16b[] = { 50000, 227, 23761, 2226, 5399 };
uint16_t vectorOUT_16b[5] = { 0 };

/*
 * Ejercicio 04:
 * 	void productoEscalar12 (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
 *
 * Entrada:		uint16_t vectorIN_16b[]
 * Salida:		uint16_t vectorOUT_16b[5]
 */
uint16_t vectorIN_12b[] = { 327, 3442, 327, 2221, 1794 };
uint16_t vectorOUT_12b[5] = { 0 };

/**************Segunda Parte***************/

/*
 * Ejercicio 05:
 * 	void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
 *
 * Entrada:		uint16_t vectorIN_P05[]
 * Salida:		uint16_t vectorOUT_P05[sizeof(vectorIN_P05) / sizeof(uint16_t)]
 */
uint16_t vectorIN_P05[] = { 947, 1111, 2026, 1362, 195, 2569, 757, 253, 295,
		833, 1927, 415, 1873, 2189, 2651, 2265, 783, 2310, 1700, 2655, 2562,
		1662, 1185, 1287, 1, 2728, 95, 2165, 1712, 2703, 1030, 1920, 2771, 1341,
		1686, 2682, 610, 344, 2828, 478, 2679, 2924, 21, 2978, 2631, 2177, 292,
		2784, 421, 1785, 1454, 2993, 1960, 1783, 1521, 2982, 533, 2880, 975,
		473, 487, 1070, 595, 1689, 2377, 868, 365, 194, 2362, 2315, 1702, 2301,
		1565, 1066, 2794, 306, 1537, 737, 2652, 2440, 748, 1515, 693, 531, 518,
		905, 1398, 930, 2743, 2111, 161, 2419, 919, 2480, 388, 1499, 738, 890,
		2644, 204, 1460, 2533, 751, 499, 2578, 394, 2411 };
uint16_t vectorOUT_P05[sizeof(vectorIN_P05) / sizeof(uint16_t)] = { 0 };

uint16_t ASMvectorIN_P05[] = { 947, 1111, 2026, 1362, 195, 2569, 757, 253, 295,
		833, 1927, 415, 1873, 2189, 2651, 2265, 783, 2310, 1700, 2655, 2562,
		1662, 1185, 1287, 1, 2728, 95, 2165, 1712, 2703, 1030, 1920, 2771, 1341,
		1686, 2682, 610, 344, 2828, 478, 2679, 2924, 21, 2978, 2631, 2177, 292 };
uint16_t ASMvectorOUT_P05[sizeof(ASMvectorIN_P05) / sizeof(uint16_t)] = { 0 };

/*
 * Ejercicio 06:
 * 	void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
 *
 * Entrada:		int32_t vectorIN_P06[]
 * Salida:		int16_t vectorOUT_P06[sizeof(vectorIN_P06) / sizeof(int32_t)]
 */
int32_t vectorIN_P06[] = { 673442447, 1016059352, 152699397, 3917358632,
		3255809211, 1112063115, 1623556123, 752698063, 3768095820, 1776671775 };
int16_t vectorOUT_P06[sizeof(vectorIN_P06) / sizeof(int32_t)] = { 0 };

int32_t ASMvectorIN_P06[] = { 673442447, 1016059352, 152699397, 3917358632,
		3255809211, 1112063115, 1623556123, 752698063, 3768095820, 1776671775 };
int16_t ASMvectorOUT_P06[sizeof(ASMvectorIN_P06) / sizeof(int32_t)] = { 0 };

/*
 * Ejercicio 07:
 * 	int32_t max (int32_t * vectorIn, uint32_t longitud);
 *
 * Entrada:		int32_t vectorIN_P07[]
 */
int32_t vectorIN_P07[] = { 673442447, 1016059352, 2147483647, 3917358632,
		3255809211, 1112063115, 1623556123, 752698063, 3768095820, 1776671775 };

//int32_t ASMvectorIN_P07[] = { 673442447, 1016059352, 2147483647, 3917358632,
//		3255809211, 1112063115, 1623556123, 752698063, 3768095820, 1776671775 };

int32_t ASMvectorIN_P07[] = { 67, 101, 214, 39, 32, 32, 16, 75, 37, 17 };

/*
 * Ejercicio 08:
 * 	void downsampleM (int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);
 *
 * Entrada:		int32_t vectorIN_P08[]
 * Salida:		int32_t vectorOUT_P08[sizeof(vectorIN_P08) / sizeof(int32_t)]
 */
int32_t vectorIN_P08[] = { 947, 1111, 2026, 1362, 195, 2569, 757, 253, 295, 833,
		1927, 415, 1873, 2189, 2651, 2265, 783, 2310, 1700, 2655, 2562 };
int32_t vectorOUT_P08[sizeof(vectorIN_P08) / sizeof(int32_t)] = { 0 };

int32_t ASMvectorIN_P08[] = { 947, 1111, 2026, 1362, 195, 2569, 757, 253, 295,
		833, 1927, 415, 1873, 2189, 2651, 2265, 783, 2310, 1700, 2655, 2562 };
int32_t ASMvectorOUT_P08[sizeof(ASMvectorIN_P08) / sizeof(int32_t)] = { 0 };

/*
 * Ejercicio 09:
 * 	void invertir (uint16_t * vector, uint32_t longitud);
 *
 * Entrada:		uint16_t vectorIN_P09[]
 */
//uint16_t vectorIN_P09[] = { 947, 1111, 2026, 1362, 195, 2569, 757, 253, 295,
//		833, 1927, 415, 1873, 2189, 2651, 2265, 783, 2310, 1700, 2655, 2562 };
uint16_t vectorIN_P09[] = { 947, 1111, 2026, 1362, 195, 2569, 757 };

uint16_t ASMvectorIN_P09[] = { 947, 1111, 2026, 1362, 195, 2569, 757 };

/*
 * Ejercicio 09:
 * 	void corr (int16_t * vectorX, int16_t * vectorY, int32_t * vectorCorr, uint32_t longitud);
 *
 * Entrada 1:		int16_t * vectorX
 * Entrada 2:		int16_t * vectorY
 * Salida:		uint16_t vectorIN_P09[]
 *
 */
int16_t vectorX_P11[] = { 100, 84, 71, 59, 50, 42, 35, 30, 25, 21, 17, 15, 12,
		10, 9, 7 };

int16_t vectorY_P11[] = { 15, 12, 10, 9, 7, 100, 84, 71, 59, 50, 42, 35, 30, 25,
		21, 17 };
int32_t vectorCorr_P11[2 * (sizeof(vectorX_P11) / sizeof(int16_t)) - 1] = { 0 };

int16_t ASMvectorX_P11[] = {100,84,71,59,50,42,35,30,25,21,17,15,12,10,9,7};//,6};

int16_t ASMvectorY_P11[] = { 15,12,10,9,7,6,100,84,71,59,50,42,35,30,25,21,17};//,15};

int32_t ASMvectorCorr_P11[2 * (sizeof(ASMvectorX_P11) / sizeof(int16_t)) - 1] = { 0 };
// Resultado esperado en vectorCorr 1700, 3528, 5471, 7594, 9884, 12509, 15510,
//									18942, 23024, 27755, 33322, 28710, 25031,
//									21992, 19715, 18051, 15052, 12539, 10331,
//									8473, 6868, 5542, 4310, 3269, 2335, 1408,
//									599, 453, 328, 219, 105,

// Resultado 2 esperado en vector Corr 1500,2960,4593,6356,8344,10514,13034,
//										15960,19317,23339,28010,33547,28790,
//										24897,21788,19335,17434,14559,12165,
//										10062,8299,6781,5545,4400,3447,2615,
//										1790,1095,410,315,232,144,72

#endif /* INC_VARS_EJERCICIOS_H_ */
