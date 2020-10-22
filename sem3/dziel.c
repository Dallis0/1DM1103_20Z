#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int a;
    int b = atof(argv[1]);
    int c = atof(argv[2]);

    for(a=0;a<10*b;a=a+b)
    {
        printf("%d + %d = %d   ",a,b,a+b);
        if((a+b)%c==0)
        {
            printf("%d + %d = %d * %d\n",a,b,c,(a+b)/c);
            printf("%d + %d jest podzielnie przez %d\n",a,b,c);

        }
        else
        {
            printf("\n");
            printf("%d + %d nie jest podzielne przez %d\n",a,b,c);
        }
        printf("\n");
    } 

}