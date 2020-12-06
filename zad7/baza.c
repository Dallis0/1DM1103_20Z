#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

Student * wczytaj_s(FILE *fin){
    char bufor[255];
    int n, i;
    char *s;

    Student *last_student = NULL;
    Student *glowa = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot * wczytaj_p(FILE *fin){
    char bufor[255];
    int n, i;
    char *s;

    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;

    fgets(bufor, 254, fin); 
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if (last_przedmiot == NULL)
            glowa = przed;
        else
            last_przedmiot->nast = przed;
        last_przedmiot = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przed, s);

        s = strtok(NULL, ";");
        przed->nazwa_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa_przed, s);

        s = strtok(NULL, "\n");
        przed->sem = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->sem, s);
    }

    return glowa;
}

Ocena * wczytaj_o(FILE *fin){
    char bufor[255];
    int n, i;
    char *s;

    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;

    fgets(bufor, 254, fin); 
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *oc = (Ocena*) malloc(sizeof(Ocena));
        oc->nast = NULL;

        if (last_ocena == NULL)
            glowa = oc;
        else
            last_ocena->nast = oc;
        last_ocena = oc;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        oc->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->nr_albumu, s);

        s = strtok(NULL, ";");
        oc->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        oc->ocena = atof(s);

        s = strtok(NULL, "\n");
        oc->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oc->komentarz, s);
    }

    return glowa;
}

SBaza * wczytaj(char *file) {
    FILE *fin = fopen(file, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", file);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_s(fin);
    baza->lista_przedmiotow = wczytaj_p(fin);
    baza->lista_ocen = wczytaj_o(fin);

    fclose(fin);
    return baza;
}

SBaza * zapisz(char *file, SBaza * baza) {

    FILE *fin = fopen(file, "w+");
  	Student *S = baza->lista_studentow;
    Przedmiot *P = baza->lista_przedmiotow;
    Ocena *O = baza->lista_ocen;
	int i;

    fprintf(fin, "%d\n", ile_s(baza));
    for(i=0; i<ile_s(baza); i++){
        fprintf(fin, "%s;%s;%s;%s\n", S->imie, S->nazwisko, S->nr_albumu, S->email);
        S = S->nast;
    }
    
    fprintf(fin, "%d\n", ile_p(baza));   
  	for(i=0; i<ile_p(baza); i++){
        fprintf(fin, "%s;%s;%s\n", P->kod_przed, P->nazwa_przed, P->sem);
        P = P ->nast;
    }

    fprintf(fin, "%d\n", ile_o(baza));  	
  	for(i=0; i<ile_o(baza); i++){
        fprintf(fin, "%s;%s;%1.1f;%s\n", O->nr_albumu, O->kod_przedmiotu, O->ocena, O->komentarz);
        O = O->nast;
    }
    fclose(fin);
    
    return NULL;
}

int ile_s(SBaza *baza) {
    int n = 0;
    Student * S = baza->lista_studentow;
    while (S != NULL) {
        n++;
        S = S->nast;
    }
    return n;
}

int ile_p(SBaza *baza) {
    int n = 0;
    Przedmiot * P = baza->lista_przedmiotow;
    while (P != NULL) {
        n++;
        P = P->nast;
    }
    return n;
}

int ile_o(SBaza *baza) {
    int n = 0;
    Ocena *O = baza->lista_ocen;
    while (O != NULL) {
        n++;
        O = O->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) {
    Student * S = baza->lista_studentow;
    while (S != NULL) {
        printf("%s %s %s %s\n", S->imie, S->nazwisko, S->nr_albumu, S->email);
        S = S->nast;
    }
}

SBaza *dodaj_s(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email){
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *aktualnie = NULL;

  	nowy->nast = NULL;
    
  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);

    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);

    aktualnie=baza->lista_studentow;
    
    if(ile_s(baza) == 0){
      baza->lista_studentow = nowy;
    }
    else{
      for(int i=1; i<ile_s(baza); i++){
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }
        
    return NULL;
}

void dodaj_p(SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem){
    Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
  	Przedmiot *aktualnie = NULL;

  	nowy->nast = NULL;

  	nowy->kod_przed = (char*) malloc(sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);

    nowy->nazwa_przed = (char *)malloc(sizeof(char) * (strlen(nazwa_przed) + 1));
    strcpy(nowy->nazwa_przed, nazwa_przed);

    nowy->sem = (char*) malloc(sizeof(char) * (strlen(sem) + 1));
    strcpy(nowy->sem, sem);

    aktualnie = baza->lista_przedmiotow;
    
    if(ile_p(baza) == 0){
      baza->lista_przedmiotow = nowy;
    }
    else{
      for(int i=1; i<ile_p(baza); i++){
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }    
}

SBaza * przypisz(SBaza *baza, char *kod_przedmiotu, char *nr_albumu, float ocena, char *komentarz){
    Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));
  	Ocena *aktualnie = NULL;
    
  	nowy->nast = NULL;
    
  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->ocena=ocena;

    nowy->komentarz = (char*) malloc(sizeof(char) * (strlen(komentarz) + 1));
    strcpy(nowy->komentarz, komentarz);

    aktualnie=baza->lista_ocen;
    
    if(ile_o(baza) == 0){
      baza->lista_ocen = nowy;
    }
    else{
      for(int i=1; i<ile_o(baza); i++){
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }
        
    return NULL;
}

void zwolnij_s(Student *S){
    free(S->imie);
    free(S->nazwisko);
    free(S->nr_albumu);
    free(S->email);
    free(S);
}

void zwolnij_p(Przedmiot *S) {
    free(S->kod_przed);
    free(S->nazwa_przed);
    free(S->sem);
    free(S);
}

void zwolnij_o(Ocena *S) {
    free(S->nr_albumu);
    free(S->kod_przedmiotu);
    free(S->komentarz);
    free(S);
}

void zwolnij_ls(Student *S) {
    Student *N;
    while (S != NULL) {
        N = S->nast;
        zwolnij_s(S);
        S = N;
    }
}

void zwolnij_lp(Przedmiot *S) {
    Przedmiot *N;
    while (S != NULL) {
        N = S->nast;
        zwolnij_p(S);
        S = N;
    }
}

void zwolnij_lo(Ocena *S) {
    Ocena *N;
    while (S != NULL) {
        N = S->nast;
        zwolnij_o(S);
        S = N;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_ls(baza->lista_studentow);
    zwolnij_lp(baza->lista_przedmiotow);
    zwolnij_lo(baza->lista_ocen);
    free(baza);
}