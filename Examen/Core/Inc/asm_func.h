#pragma once

#include <stdint.h>


//Prototipo funcion normal
void asm_medDif(int8_t * e, int8_t *x, int8_t *y, uint16_t longitud);

//Prototipo con SIMD
void asm_medDif_DSP(int8_t * e, int8_t *x, int8_t *y, uint16_t longitud);



