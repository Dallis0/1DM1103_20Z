#include <stdio.h>

int dlugosc(char napis[])
{
    int i = 0;
    while(napis[i++]);
    return i;
}

int zlicz(char napis[], char znak)
{
    int i = 0;
    int j = 0;
    while(napis[i] != 0)
    {
        if(napis[i++] == znak)
        {
            j++;
            
        }
        
    }
   return j; 
}
void main()
{
    char napis[] = "Elektromobilnosc jest bardzo fajna!\n";
   // dlugosc(napis[i]);
   printf("Litera l występuje %d razy.\n", zlicz(napis, 'l'));
}