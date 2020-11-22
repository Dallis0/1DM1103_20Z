#ifndef studenci_h
#define studenci_h

#include "dziekanat.h"

typedef struct _student
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[225];
    float ocena;
    int ects;
}student, *pstudent;

int wczytaj(student dane[100], char *fnazwa);

int znajdz_p(char *szukany_nr, char kod_przed[100][10], int n);

int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n);

int znajdz_s(char *szukany_nr, char nr_albumow[100][10], int n);

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

#endif
