#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) 
{
    SBaza *baza;
    baza = wczytaj(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) 
    {
        listuj_studentow(baza);
        listuj_oceny(baza);
    }

    else if (strcmp("list_students_backwards", argv[2]) == 0) 
        listuj_studentow_od_konca(baza);

    else if(strcmp("stud_descending", argv[2]) == 0)
    {
        baza->lista_studentow = sortuj_studentow_malejaco(baza->lista_studentow);
        listuj_studentow(baza);
    }

    else if(strcmp("stud_ascending", argv[2]) == 0)
    {
        baza->lista_studentow = sortuj_studentow_rosnaco(baza->lista_studentow);
        listuj_studentow(baza);
    }

    

    else if (strcmp("list_ccode", argv[2]) == 0) 
        listuj_przed(baza);

    else if (strcmp("list_ccode_backwards", argv[2]) == 0) 
        listuj_przed_od_konca(baza);

    else if(strcmp("ccode_descending", argv[2]) == 0)
    {
        baza->lista_przedmiotow = sortuj_kodprzed_malejaco(baza->lista_przedmiotow);
        listuj_przed(baza);
    }

    else if(strcmp("ccode_ascending", argv[2]) == 0)
    {
        baza->lista_przedmiotow = sortuj_kodprzed_rosnaco(baza->lista_przedmiotow);
        listuj_przed(baza);
    }

    else if(strcmp("cname_descending", argv[2]) == 0)
    {
        baza->lista_przedmiotow = sortuj_nazprzed_malejaco(baza->lista_przedmiotow);
        listuj_przed(baza);
    }

    else if(strcmp("cname_ascending", argv[2]) == 0)
    {
        baza->lista_przedmiotow = sortuj_nazprzed_rosnaco(baza->lista_przedmiotow);
        listuj_przed(baza);
    }       

    else if (strcmp("add_student", argv[2]) == 0) 
        dodaj_s(baza, argv[3], argv[4], argv[5], argv[6]);

    else if (strcmp("count_students", argv[2]) == 0)
        printf("Liczba studentów: %d\n", ile_s(baza));

    else if (strcmp("add_course", argv[2]) == 0)
        dodaj_p(baza, argv[3], argv[4], argv[5]);

    else if (strcmp("count_courses", argv[2]) == 0) 
        printf("Liczba przedmiotow: %d\n", ile_p(baza));

    else if (strcmp("count_grades", argv[2]) == 0) 
        printf("Liczba ocen: %d\n", ile_o(baza));    

    else if (strcmp("add_student_to_course", argv[2]) == 0) 
        dodaj_o(baza, argv[3], argv[4], atof(argv[5]), argv[6]);
    
    zapisz(argv[1], baza);


    if(strcmp("find_course", argv[2]) == 0)
    {
        baza->lista_ocen = filtruj_oceny_przedmiotu(baza->lista_ocen, argv[3]);
        listuj_oceny(baza);
        zwolnij(baza);
        return 0;
    }

    else if(strcmp("find_stud", argv[2]) == 0)
    {
        baza->lista_ocen = filtruj_oceny_studenta(baza->lista_ocen, argv[3]);
        listuj_oceny(baza);
        zwolnij(baza);
        return 0;
    }

    zwolnij(baza);

    return 0;
}