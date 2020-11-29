#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "kalkulator.h"


int main(int argc, char **argv)
{
if(strcmp(argv[1], "sum")==0){
  struct macierz M1 = wczytaj(argv[2]);
  struct macierz M2 = wczytaj(argv[3]); 
  sum(&M1, &M2, argc, argv);
  }
if(strcmp(argv[1], "subtract")==0){
  struct macierz M1 = wczytaj(argv[2]);
  struct macierz M2 = wczytaj(argv[3]); 
  subtract(&M1, &M2, argc, argv);
  }
if(strcmp(argv[1], "prod")==0)
{
  struct macierz M1 = wczytaj(argv[2]);
  struct macierz M2 = wczytaj(argv[3]); 
  prod(&M1, &M2, argc, argv);
}
if(strcmp(argv[1], "multiply")==0)
{
  struct macierz M = wczytaj(argv[2]);
  float k = atof(argv[3]);
  multiply(&M, k, argc, argv);
}
if(strcmp(argv[1],"norm")==0){
  struct macierz M = wczytaj(argv[2]);
  norm(&M, argc, argv);
}
return 0;
}
