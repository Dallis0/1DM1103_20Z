#ifndef kalkulator_h
#define kalkulator_h

#include "wczytaj.h"


struct macierz sum(struct macierz *M1, struct macierz *M2, int argc, char **argv);

struct macierz subtract(struct macierz *M1, struct macierz *M2, int argc, char **argv);

struct macierz prod(struct macierz *M1, struct macierz *M2, int argc, char **argv);

struct macierz multiply(struct macierz *M, float k, int argc, char **argv);

float norm(struct macierz *M, int argc, char **argv);


#endif