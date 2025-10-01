#include <stdio.h>
#include <math.h>

int main(){

    int a,b,c;
    printf("Iveskite tris sveikuosius skaicius:\n");
    scanf(" %d %d %d", &a, &b, &c);

    int diskriminantas = pow(b, 4)-(4*a*c);

    if(diskriminantas > 0)printf("%d sprendiniai", 2);
    else if(diskriminantas == 0)printf("%d sprendinys", 1);
    else printf("%d sprendiniu", 0);


    return 0;
}