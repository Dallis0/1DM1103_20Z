#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int znajdz(char *szukany_nr, char kod_przed[100][10], int n)
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
        if(znajdz(dane[i].kod_przed, kod_przed, ile_przed) == -1)
        {
            strncpy(kod_przed[ile_przed], dane[i].kod_przed, 9);
            ile_przed++;
        }
    }
    return ile_przed;
}

void najlatwiejszy_przedmiot(student dane[100], int ile_rekordow) 
{
    char kod_przed[100][10];
    char nazwa_przed[100][255];
    int ile_przed;

    float sumy_wazonych_ocen[100] = {0};
    int sumy_ects[100] = {0};

    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 6.0f;

    ile_przed = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) 
    {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przed);
        strcpy(nazwa_przed[pozycja], dane[i].nazwa_przed);
        
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }

    //printf("%d\n%s\n", sumy_ects[0], dane[0].nazwa_przed);

    for (i=0; i < ile_przed; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }
    //printf("%d", najlepsza_pozycja);
    printf("Najlepsza średnia: %s - %s : %.2f\n", kod_przed[najlepsza_pozycja],
    nazwa_przed[najlepsza_pozycja], sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]);
    
}

void najtrudniejszy_przedmiot(student dane[100], int ile_rekordow) 
{
    char kod_przed[100][10];
    char nazwa_przed[100][255];
    int ile_przed;

    float sumy_wazonych_ocen[100] = {0};
    int sumy_ects[100] = {0};

    int i;
    int pozycja;
    int najgorsza_pozycja;
    float najgorsza = 6.0f;

    ile_przed = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) 
    {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przed);
        strcpy(nazwa_przed[pozycja], dane[i].nazwa_przed);

        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }

    //printf("%d\n%s\n", sumy_ects[0], dane[0].nazwa_przed);

    for (i=0; i < ile_przed; i++) {
        if (najgorsza > sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najgorsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najgorsza_pozycja = i;
        }
    }
    //printf("%d", najgorsza_pozycja);

    printf("Najgorsza średnia: %s - %s : %.2f\n", kod_przed[najgorsza_pozycja],
    nazwa_przed[najgorsza_pozycja], sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]);
    
}

int main(int argc, char **argv)
{
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
   
    najlatwiejszy_przedmiot(dane, ile);
    najtrudniejszy_przedmiot(dane, ile);

    return 0;
}