#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100

struct macierz
{
    int r;
    int c;
    float tab[N][N];
};

struct macierz wczytaj(FILE * fin, struct macierz *M)
{
    {
    fscanf(fin, "%d", &M->r);
    fscanf(fin, "%d", &M->c);

    for(int i=0; i<(*M).r;i++)
        for(int j=0; j<(*M).c; j++)
            fscanf(fin, "%f", &(*M).tab[i][j]);
    }
    return *M;
}

struct macierz sum(struct macierz M1, struct macierz M2)
{
    struct macierz suma;

    for(int i =0; i<M1.r; i++)
        for(int j=0; j<M1.c; j++)
        {
            suma.tab[i][j]= M1.tab[i][j]+M2.tab[i][j];
        }
    return suma;
}

struct macierz subtract(struct macierz M1, struct macierz M2)
{
    struct macierz roz;
    roz.r = M1.r;
    roz.c = M1.c;

    for(int i =0; i<roz.r; i++)
        for(int j=0; j<roz.c; j++)
        {
            roz.tab[i][j]= M1.tab[i][j]-M2.tab[i][j];
        }
    return roz;
}

struct macierz prod(struct macierz M1, struct macierz M2)
{
    struct macierz pro;
    pro.r = M1.r;
    pro.c = M2.c;
    int kr = M1.c;

    for(int i=0; i<pro.r;i++)
        for(int j=0;j<pro.c;j++)
            for(int k=0; k<kr; k++)
                pro.tab[i][j] += M1.tab[i][k]*M2.tab[k][j];
                
    return pro;
}

struct macierz multiply(struct macierz M1, float k)
{
    struct macierz mpl;
    mpl.r = M1.r;
    mpl.c = M1.c;
    
    for(int i=0; i<mpl.r;i++)
        for(int j=0; j<mpl.c; j++)
        {
            mpl.tab[i][j] = M1.tab[i][j]*k;
        }
    return mpl;
}

float norm(struct macierz M1) 
{
    float s = 0;
    int i,j;

    for (i = 0; i < M1.r; i++) 
        for (j=0; j < M1.c; j++) 
            s += M1.tab[i][j] * M1.tab[i][j];
    return sqrt(s);
}

int main(int argc, char *argv[])
{
    struct macierz M1;
    struct macierz M2;
    FILE * fin1 = fopen(argv[2], "r");
    

if(strcmp(argv[1], "sum") == 0)
    {
        FILE * fin2 = fopen(argv[3], "r");

        struct macierz suma = sum(wczytaj(fin1, &M1), wczytaj(fin2, &M2));
        suma.c = M1.c;
        suma.r = M1.r;

        if(M1.c == M2.c)
        {
            if(M1.r == M2.r)
            {
                if(argc == 5)
                {
                    FILE * fin3 = fopen(argv[4], "w");
                    fprintf(fin3, "%d\n", suma.r);
                    fprintf(fin3, "%d\n", suma.c);
                    for(int a=0; a<suma.r; a++)
                    {
                        for(int b=0;b<suma.c; b++)
                        {
                            fprintf(fin3, "%.1f  ", suma.tab[a][b]);
                        }
                    fprintf(fin3,"\n");
                    }
                    fclose(fin3);
                    
                }
                if(argc < 5)
                {
                    printf("[");
                    for(int i=0; i<suma.r; i++)
                    {
                        for(int j=0;j<suma.c; j++)
                            {
                            printf("%5.1f ", suma.tab[i][j]);
                            }
                        if(i<M1.r-1)
                            printf("\n ");
                    }
                    printf(" ]\n");
                }
            }
            else
                printf("Macierzy nie da się dodać.\n");
        }
        else
            printf("Macierzy nie da się dodać.\n");
            
        fclose(fin2);
    }

if(strcmp(argv[1],"subtract") == 0)
    {
        FILE * fin2 = fopen(argv[3], "r");

        struct macierz roz = subtract(wczytaj(fin1, &M1), wczytaj(fin2, &M2));
        roz.r = M1.r;
        roz.c = M1.c;

        if(M1.r == M2.r)
        {
            if(M1.c == M2.c)
            {
                if(argc == 5)
                {
                    FILE * fin3 = fopen(argv[4], "w");

                    fprintf(fin3, "%d\n", roz.r);
                    fprintf(fin3, "%d\n", roz.c);

                    for(int a=0; a<roz.r; a++)
                    {
                        for(int b=0;b<roz.c; b++)
                        {
                            fprintf(fin3, "%.1f  ", roz.tab[a][b]);
                        }
                    fprintf(fin3,"\n");
                    }
                    fclose(fin3);
                    
                }
                if(argc < 5)
                {
                    printf("[");
                    for(int i=0; i<roz.r; i++)
                    {
                        for(int j=0;j<roz.c; j++)
                            {
                            printf("%5.1f ", roz.tab[i][j]);
                            }
                        if(i<roz.r-1)
                            printf("\n ");
                    }
                    printf(" ]\n");
                }
            }
            else
                printf("Macierzy nie da się odjąć.\n");
        }
        else
            printf("Macierzy nie da się odjąć.\n");
              
        fclose(fin2);
    }

if(strcmp(argv[1], "prod") == 0)
    {
        FILE * fin2 = fopen(argv[3], "r");

        struct macierz pro = prod(wczytaj(fin1, &M1), wczytaj(fin2, &M2));
        pro.r = M1.r;
        pro.c = M2.c;

        if(M1.c == M2.r)
        {
        if(argc == 5)
        {
            FILE * fin3 = fopen(argv[4], "w");

            fprintf(fin3, "%d\n", pro.r);
            fprintf(fin3, "%d\n", pro.c);

            for(int a=0; a<pro.r; a++)
            {
                for(int b=0; b<pro.c; b++)
                {
                    fprintf(fin3, "%.1f  ", pro.tab[a][b]);
                }
            fprintf(fin3,"\n");
            }
            fclose(fin3);
            
        }
        if(argc < 5)
        {
            printf("[");
            for(int i=0; i<pro.r; i++)
            {
                for(int j=0;j<pro.c; j++)
                    {
                    printf("%5.1f ", pro.tab[i][j]);
                    }
                if(i<pro.r-1)
                    printf("\n ");
            }
            printf(" ]\n");
        }
        }
        else
        {
            printf("Macierzy nie da się pomnożyć.\n");
        }
        
        fclose(fin2);
    } 

if(strcmp(argv[1], "multiply") == 0)
    {
        float k = atof(argv[3]);
        
        struct macierz mpl = multiply(wczytaj(fin1, &M1), k);
        mpl.r = M1.r;
        mpl.c = M1.c;
    
        if(argc == 5)
        {
            FILE * fin3 = fopen(argv[4], "w");

            fprintf(fin3, "%d\n", mpl.r);
            fprintf(fin3, "%d\n", mpl.c);

            for(int a=0; a<mpl.r; a++)
            {
                for(int b=0; b<mpl.c; b++)
                {
                    fprintf(fin3, "%.1f  ", mpl.tab[a][b]);
                }
            fprintf(fin3,"\n");
            }
            fclose(fin3);
            
        }
        if(argc < 5)
        {
            printf("[");
            for(int i=0; i<mpl.r; i++)
            {
                for(int j=0;j<mpl.c; j++)
                    {
                    printf("%5.1f ", mpl.tab[i][j]);
                    }
                if(i<mpl.r-1)
                    printf("\n ");
            }
            printf(" ]\n");
        }
    }

if(strcmp(argv[1], "norm") == 0)
    {
        float no = norm(wczytaj(fin1, &M1));

        if(argc == 4)
        {
            FILE * fin2 = fopen(argv[3], "w");
            fprintf(fin2, "%f", no);
            fclose(fin2);
        } 
        if(argc < 4)
        {
            printf("%f\n", no);
        }
    }
    fclose(fin1);

    return 0;
}