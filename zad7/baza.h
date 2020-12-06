#ifndef _BAZA_H
#define _BAZA_H

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przed;
    char * nazwa_przed;
    char * sem;

    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;

    float ocena;
    char * komentarz;

    struct _Ocena *nast;
} Ocena;

typedef struct _SBaza {
    Student *lista_studentow;
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

Student *wczytaj_s(FILE *fin);

Przedmiot *wczytaj_p(FILE *fin);

Ocena *wczytaj_o(FILE *fin);

SBaza * wczytaj(char *file);

SBaza * zapisz(char *file, SBaza * baza);

int ile_s(SBaza *baza);

int ile_p(SBaza *baza);

int ile_o(SBaza *baza);

void listuj_studentow(SBaza *baza);

SBaza *dodaj_s(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);

void dodaj_p(SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem);

SBaza * przypisz(SBaza *baza, char *kod_przedmiotu, char *nr_albumu, float ocena, char *komentarz);

void zwolnij_s(Student *S);

void zwolnij_p(Przedmiot *S);

void zwolnij_o(Ocena *S);

void zwolnij(SBaza *baza);

void zwolnij_ls(Student *S);

void zwolnij_lp(Przedmiot *S);

void zwolnij_lo(Ocena *S);

void zwolnij(SBaza *baza);

#endif