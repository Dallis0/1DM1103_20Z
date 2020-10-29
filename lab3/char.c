#include <stdio.h>
#include <stdlib.h>

int dlugosc(char napis[])
{
    int a = 0;
    while(napis[a] != 0)
        a++;
    return a-1;
}

void main()
{
    char napis[] = "Elektromobilnosc jest bardzo fajna!\n";

    printf("%d\n", dlugosc(napis));
}
