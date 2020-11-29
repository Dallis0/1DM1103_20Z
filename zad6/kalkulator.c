#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "kalkulator.h"

struct macierz sum(struct macierz *M1, struct macierz *M2, int argc, char **argv)
{
  if(M1->r == M2->r)
  {
    if(M1->c == M2->c)
    {
      int i, j;
      struct macierz  *suma;
      suma = (struct macierz*) malloc(sizeof(struct macierz));

      suma->r = M1->r;
      suma->c = M1->c;

      suma->tab = (float**) malloc(sizeof(float*) * suma->r);
        for(i=0;i<suma->r; i++){
          suma->tab[i] = (float*) malloc(sizeof(float) *  suma->c);
          for(j=0;j<suma->c;j++)
            suma->tab[i][j] = M1->tab[i][j] + M2->tab[i][j];
        }
    
      if(argc == 5)
      {
        FILE * fin = fopen(argv[4], "w");
        fprintf(fin, "%d\n",  suma->r);
        fprintf(fin, "%d\n",  suma->c);

        for(i=0; i<suma->r; i++){
          for(j=0;j<suma->c; j++)
          {
            fprintf(fin, "%.1f  ",  suma->tab[i][j]);
          }
      fprintf(fin,"\n");
        }
      fclose(fin);
      }
      if(argc < 5)
      {
          printf("[");
          for(int i=0; i<suma->r; i++)
          {
              for(int j=0;j<suma->c; j++)
                  {
                  printf("%5.1f ", suma->tab[i][j]);
                  }
              if(i<M1->r-1)
                  printf("\n ");
          }
          printf(" ]\n");
      }
      zwolnij(suma);
    }
    else
      printf("Macierzy nie da się dodać.\n");
  }
  else
    printf("Macierzy nie da się dodać.\n");
}

struct macierz subtract(struct macierz *M1, struct macierz *M2, int argc, char **argv)
{
  if(M1->r == M2->r)
  {
    if(M1->c == M2->c)
    {
      int i, j;
      struct macierz *roz;
      roz = (struct macierz*) malloc(sizeof(struct macierz));

      roz->r = M1->r;
      roz->c = M1->c;

      roz->tab = (float**) malloc(sizeof(float*) * roz->r);
        for(i=0;i<roz->r; i++){
          roz->tab[i] = (float*) malloc(sizeof(float) *  roz->c);
          for(j=0;j<roz->c;j++)
            roz->tab[i][j] = M1->tab[i][j] - M2->tab[i][j];
        }
    
      if(argc == 5)
      {
        FILE * fin = fopen(argv[4], "w");
        fprintf(fin, "%d\n",  roz->r);
        fprintf(fin, "%d\n",  roz->c);

        for(i=0; i<roz->r; i++){
          for(j=0;j<roz->c; j++)
          {
            fprintf(fin, "%.1f  ",  roz->tab[i][j]);
          }
      fprintf(fin,"\n");
        }
      fclose(fin);
      }
      if(argc < 5)
      {
          printf("[");
          for(int i=0; i<roz->r; i++)
          {
              for(int j=0;j<roz->c; j++)
                  {
                  printf("%5.1f ",  roz->tab[i][j]);
                  }
              if(i<M1->r-1)
                  printf("\n ");
          }
          printf(" ]\n");
      }
      zwolnij(roz);
    }
    else
      printf("Macierzy nie da się odjąć.\n");
  }
  else
    printf("Macierzy nie da się odjąć.\n");
}

struct macierz prod(struct macierz *M1, struct macierz *M2, int argc, char **argv)
{
  if(M1->c == M2->r)
  {
    int i, j, k, kr;
    struct macierz *pro;
    pro = (struct macierz*) malloc(sizeof(struct macierz));

    pro->r = M1->r;
    pro->c = M2->c;
    kr = M1->c;

    pro->tab = (float**) malloc(sizeof(float*) * pro->r);
      for(i=0;i<pro->r; i++){
        pro->tab[i] = (float*) malloc(sizeof(float) *  pro->c);
        for(j=0;j<pro->c;j++)
          for(k=0; k<kr; k++)
          pro->tab[i][j] += M1->tab[i][k]*M2->tab[k][j];
      }
  
    if(argc == 5)
    {
      FILE * fin = fopen(argv[4], "w");
      fprintf(fin, "%d\n",  pro->r);
      fprintf(fin, "%d\n",  pro->c);

      for(i=0; i<pro->r; i++)
      {
        for(j=0;j<pro->c; j++)
        {
          fprintf(fin, "%.1f  ", pro->tab[i][j]);
        }
        fprintf(fin,"\n");
      }
    fclose(fin);
    }
    if(argc < 5)
    {
        printf("[");
        for(int i=0; i<pro->r; i++)
        {
            for(int j=0;j<pro->c; j++)
                {
                printf("%5.1f ", pro->tab[i][j]);
                }
            if(i<M1->r-1)
                printf("\n ");
        }
        printf(" ]\n");
    }
    zwolnij(pro);
  }
  else
    printf("Macierzy nie da się pomnożyć.\n");
}

struct macierz multiply(struct macierz *M, float k, int argc, char **argv)
{
  int i, j;
  struct macierz *mpl;
  mpl = (struct macierz*) malloc(sizeof(struct macierz));

  mpl->r = M->r;
  mpl->c = M->c;

  mpl->tab = (float**) malloc(sizeof(float*) * mpl->r);
    for(i=0;i<mpl->r; i++){
      mpl->tab[i] = (float*) malloc(sizeof(float) *  mpl->c);
      for(j=0;j<mpl->c;j++)
        mpl->tab[i][j] = k * M->tab[i][j];
    }

  if(argc == 5)
  {
    FILE * fin = fopen(argv[4], "w");
    fprintf(fin, "%d\n",  mpl->r);
    fprintf(fin, "%d\n",  mpl->c);

    for(i=0; i<mpl->r; i++){
      for(j=0;j<mpl->c; j++)
      {
        fprintf(fin, "%.1f  ",  mpl->tab[i][j]);
      }
  fprintf(fin,"\n");
    }
  fclose(fin);
  }
  if(argc < 5)
  {
      printf("[");
      for(int i=0; i<mpl->r; i++)
      {
          for(int j=0;j<mpl->c; j++)
              {
              printf("%5.1f ",  mpl->tab[i][j]);
              }
          if(i<M->r-1)
              printf("\n ");
      }
      printf(" ]\n");
  }
  zwolnij(mpl);
}

float norm(struct macierz *M, int argc, char **argv)
{
  float s = 0;
  int i, j;

  for (i = 0; i < M->r; i++) 
      for (j=0; j < M->c; j++) 
          s += M->tab[i][j] * M->tab[i][j];
  if(argc == 4)
  {
    FILE *fin = fopen(argv[3], "w");
    fprintf(fin, "%4.1f", sqrt(s));
    fclose(fin);
  }
  if(argc < 4)
    printf("%4.1f\n", sqrt(s));
}
