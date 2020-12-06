#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) 
{
    SBaza *baza;
    baza = wczytaj(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) 
        listuj_studentow(baza);
    else if (strcmp("add_student", argv[2]) == 0) 
        dodaj_s(baza, argv[3], argv[4], argv[5], argv[6]);
    else if (strcmp("count_students", argv[2]) == 0)
        printf("Liczba studentów: %d\n", ile_s(baza));
    else if (strcmp("add_course", argv[2]) == 0)
        dodaj_p(baza, argv[3], argv[4], argv[5]);
    else if (strcmp("count_courses", argv[2]) == 0) 
        printf("Liczba przedmiotow: %d\n", ile_p(baza));
    else if (strcmp("add_student_to_course", argv[2]) == 0) 
        przypisz(baza, argv[3], argv[4], atof(argv[5]), argv[6]);
    
    zapisz(argv[1], baza);
    zwolnij(baza);

    return 0;
}