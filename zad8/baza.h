#ifndef _BAZA_H
#define _BAZA_H

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przed;
    char * nazwa_przed;
    char * sem;

    struct _Przedmiot *poprz;
    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przedmiotu;
    float ocena;
    char * komentarz;

    struct _Ocena *poprz;
    struct _Ocena *nast;
} Ocena;

typedef struct _SBaza {
    Student *lista_studentow;
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

//----------------------------------------

Student *wczytaj_s(FILE *fin);

Przedmiot *wczytaj_p(FILE *fin);

Ocena *wczytaj_o(FILE *fin);


SBaza * wczytaj(char *file);

SBaza * zapisz(char *file, SBaza * baza);

//------------------------------------------

int ile_s(SBaza *baza);

int ile_p(SBaza *baza);

int ile_o(SBaza *baza);

//---------------------------------------------------

Student *sortuj_studentow_malejaco(Student *glowa);

Student *sortuj_studentow_rosnaco(Student *glowa);

void listuj_studentow(SBaza *baza);

void listuj_studentow_od_konca(SBaza *baza);

//-------------------------------------------------------

Przedmiot *sortuj_kodprzed_malejaco(Przedmiot *glowa);

Przedmiot *sortuj_kodprzed_rosnaco(Przedmiot *glowa);

void listuj_przed(SBaza *baza);

void listuj_przed_od_konca(SBaza *baza);

//--------------------------------------------------------

Przedmiot *sortuj_nazprzed_malejaco(Przedmiot *glowa);

Przedmiot *sortuj_nazprzed_rosnaco(Przedmiot *glowa);

//--------------------------------------------------------


Student * usun_s(Student * glowa, Student *el);

Ocena * usun_o(Ocena * glowa, Ocena *el);

Przedmiot * usun_p(Przedmiot * glowa, Przedmiot *el);

//--------------------------------------------------------

Ocena * filtruj_oceny_przedmiotu(Ocena * glowa, char *kod_przedmiotu);

Ocena * filtruj_oceny_studenta(Ocena * glowa, char * nr_albumu);

void listuj_oceny(SBaza *baza);

//-----------------------------------------------------------------------------------

SBaza *dodaj_s(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);

void dodaj_p(SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem);

SBaza * dodaj_o(SBaza *baza, char *kod_przedmiotu, char *nr_albumu, float ocena, char *komentarz);

//----------------------------------------------

void zwolnij_s(Student *S);

void zwolnij_p(Przedmiot *S);

void zwolnij_o(Ocena *S);

void zwolnij(SBaza *baza);

void zwolnij_ls(Student *S);

void zwolnij_lp(Przedmiot *S);

void zwolnij_lo(Ocena *S);

void zwolnij(SBaza *baza);

#endif