#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 10

void wypisz(int tab[ROZMIAR][ROZMIAR], int rozmiar)
{
    for(int a = 0; a < rozmiar; a++, printf("\n"))
    {
        for(int b = 0; b < rozmiar; b++)
        {
            printf("%4d", tab[a][b]);
        }
    }
}


void uzupelnij(int tab[ROZMIAR][ROZMIAR], int rozmiar)
{
    for(int a = 0; a < rozmiar; a++)
    {
        for(int b = 0; b < rozmiar; b++)
        {
            tab[a][b]=(a+1)*(b+1);
        }
        
    }
}

void main(void)
{
    int tabliczka[ROZMIAR][ROZMIAR];


    uzupelnij(tabliczka, ROZMIAR);
    wypisz(tabliczka, ROZMIAR);

}