#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char n[100];
    int i;
    char n2[] = "Wielki i długi napis.";
    char n3[20];
    char tab[10][10];

    strcpy(tab[0], "akuku");
    strcpy(tab[1], "hello");
    strcpy(n, "Ala\n");
    
    
   
    printf("%s, %s, %s", n, tab[0], tab[1]);

    for(i = 0; i<3; i++){
        printf("[%d] %c, %d\n", i + 1, n[i], n[i]);
    }

    printf("Trzeci znak z pierwszego napisu Argv: %c\n", argv[0][2]);
    printf("Trzeci znak z drugiego napisu Argv: %c\n", argv[1][2]);

    return 0;
}