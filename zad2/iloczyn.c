#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fin1;
    FILE *fin2;
    FILE *fin3;

    fin1 = fopen(argv[1], "r");
    fin2 = fopen(argv[2], "r");

    float M1[10][10], M2[10];
    fscanf(fin1, "%f %f %f %f %f %f %f %f", &M1[0][0], &M1[1][0], &M1[2][0], &M1[2][1], &M1[3][0], &M1[3][1], &M1[4][0], &M1[4][1]);
    fscanf(fin2, "%f %f %f %f %f ", &M2[0], &M2[1], &M2[2], &M2[3], &M2[4]);
 
    float M3[10];
    M3[0] = 1;
    M3[1] = 3;
    M3[2] = M1[2][0]*M2[2]+M1[2][1]*M2[3];
    M3[3] = M1[3][0]*M2[2]+M1[3][1]*M2[3];
    M3[4] = M1[4][0]*M2[2]+M1[4][1]*M2[3];

    fin3 = fopen(argv[3], "w");
    fprintf(fin3, "%1.0f\n%1.0f\n%1.1f\n%1.1f\n%1.1f\n", M3[0], M3[1], M3[2], M3[3], M3[4]);
    fclose(fin3);

    return 0;
}