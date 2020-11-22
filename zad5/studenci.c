#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dziekanat.h"
#include "studenci.h"

int wczytaj(student dane[100], char *fnazwa)
{
    FILE *fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;
    


    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);

    for(i=0; i<cnt; i++)
    {
        fgets(bufor, 1023, fin);

        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL,"|");
        strncpy(dane[i].nazwisko, w, 50);

        w = strtok(NULL,"|");
        strncpy(dane[i].nr_albumu, w, 10);

        w = strtok(NULL,"|");
        strncpy(dane[i].kod_przed, w, 10);

        w = strtok(NULL,"|");
        strncpy(dane[i].nazwa_przed, w, 255);

        w = strtok(NULL,"|");
        dane[i].ocena = atof(w);

        w = strtok(NULL,"|");
        dane[i].ects = atoi(w);
    }


    fclose(fin);
    return cnt;
}

int znajdz_p(char *szukany_nr, char kod_przed[100][10], int n)
{
    int i;
    for(i=0;i<n; i++)
    {
        if(strcmp(szukany_nr, kod_przed[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n)
{
    int i;
    int ile_przed = 0;

    for(i=0;i<n; i++)
    {
        if(znajdz_p(dane[i].kod_przed, kod_przed, ile_przed) == -1)
        {
            strncpy(kod_przed[ile_przed], dane[i].kod_przed, 9);
            ile_przed++;
        }
    }
    return ile_przed;
}

int znajdz_s(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_stud = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz_s(dane[i].nr_albumu, nr_albumow, ile_stud ) == -1) {
            strncpy(nr_albumow[ile_stud], dane[i].nr_albumu, 9);
            ile_stud++;
        }
    }
    return ile_stud;
}