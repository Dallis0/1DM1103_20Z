#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dziekanat.h"
#include "studenci.h"

//argv[1] - nazwa pliku ze studentami
//argv[2] - nazwa funkcji (najlepszy_student, najtrudniejszy_przedmiot, najlatwiejszy_przedmiot)

int main(int argc, char **argv)
{
  student dane[100];
  int ile = wczytaj(dane, argv[1]);

  if(strcmp(argv[2],"najtrudniejszy_przedmiot") == 0)
    najtrudniejszy_przedmiot(dane, ile);
  
  if(strcmp(argv[2], "najlatwiejszy_przedmiot") == 0)
    najlatwiejszy_przedmiot(dane, ile);
  
  if(strcmp(argv[2], "najlepszy_student") == 0)
    najlepszy_student(dane, ile);
  
  return 0;
}