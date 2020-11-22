#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dziekanat.h"
#include "studenci.h"



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
        pozycja = znajdz_p( dane[i].kod_przed, kod_przed, ile_przed);
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
        pozycja = znajdz_p( dane[i].kod_przed, kod_przed, ile_przed);
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

void najlepszy_student(student dane[100], int ile_rekordow) {
    
    char nr_albumow[100][10];
    int ile_studentow;

    float sumy_wazonych_ocen[100] = {0};
    int sumy_ects[100] = {0};
    float srednie[100] = {0};

    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_s( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}