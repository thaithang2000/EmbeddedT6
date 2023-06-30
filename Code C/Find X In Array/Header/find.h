#ifndef FIND_h
#define FIND_h
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t random_number(int minN, int maxN);
uint16_t *createArray(uint16_t length);
void sort(uint16_t arr[], uint64_t length);
uint16_t find(uint16_t arr[], uint16_t x, uint16_t min, uint16_t max);


#endif
