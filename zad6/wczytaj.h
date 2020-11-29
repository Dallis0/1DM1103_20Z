#ifndef wczytaj_h
#define wczytaj_h

#include "kalkulator.h"

struct macierz{
  int r;
  int c;
  float **tab;
};

struct macierz wczytaj(char *file);

void zwolnij(struct macierz *M);

#endif