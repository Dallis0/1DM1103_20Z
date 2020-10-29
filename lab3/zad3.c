#include <stdio.h>

int zlicz(char napis[], char znak)
{
    int i =0, cnt = 0;
    while(napis[i])
        napis[i++] == znak && cnt++;
    return cnt;
}

void main()
{
    char napis[] = "Elektromobilność jest bardzo fajna!\n";
    printf("Litera l występuje %d razy.\n", zlicz(napis, 'l'));

}

