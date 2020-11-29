#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wczytaj.h"

struct macierz wczytaj(char *file){
  int i, j;
  struct macierz *M;
  FILE *fin = fopen(file, "r");
  M = (struct macierz*) malloc(sizeof(struct macierz));
  
  fscanf(fin, "%d", &M->r);
  fscanf(fin, "%d", &M->c);

  M->tab = (float**) malloc(sizeof(float*) * M->r);
  for (i=0;i<M->r;i++){
    M->tab[i] = (float*) malloc(sizeof(float) * M->c);
    for (j=0;j< M->c; j++)
      fscanf(fin, "%f", &M->tab[i][j]);
  }
  return *M;
}

void zwolnij(struct macierz *M){
  for(int i=0;i<M->r; i++)
    free(M->tab[i]);
  free(M->tab);
  free(M);
}
