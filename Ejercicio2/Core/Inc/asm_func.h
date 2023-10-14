#pragma once

#include <stdint.h>


void asm_svc (void);
uint32_t asm_sum (uint32_t firstOperand, uint32_t secondOperand);
//Ejercicio 1

void asm_zeros(uint32_t * vectorIn, uint32_t longitud);

//Ejercicio 2
void asm_productoescalar32(uint32_t * vectorIn, uint32_t * vectorOut ,uint32_t longitud, uint32_t escalar);

//Ejercicio 3
void asm_productoEscalar16 (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);

//Ejercicio 4

void asm_productoEscalar12 (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);


//Ejercicio 5


//Ejercicio 6
void asm_pack32to16(int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);

//Promedio en ASM normal

void asm_prom(uint16_t *vectorOut,uint16_t *vectorX,uint16_t *vectorY,uint16_t longitud);

//Promedio en ASM con SIMD

void asm_promSIMD(uint16_t *vectorOut,uint16_t *vectorX,uint16_t *vectorY,uint16_t longitud);


