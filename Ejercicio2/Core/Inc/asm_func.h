#pragma once

#include <stdint.h>


void asm_svc (void);
uint32_t asm_sum (uint32_t firstOperand, uint32_t secondOperand);
//Ejercicio 1

void asm_zeros(uint32_t * vectorIn, uint32_t longitud);

//Ejercicio 2
void asm_productoescalar32(uint32_t * vectorIn, uint32_t * vectorOut ,uint32_t longitud, uint32_t escalar);
