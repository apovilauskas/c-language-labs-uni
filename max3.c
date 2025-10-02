#include <stdio.h>

int main(){

double x,y,z;
//scanf("%lf %lf %lf", &x, &y, &z);
x=5.5; y=6.121; z = 4;

double ats;

//maximum
ats = x>y ? x : y;
ats = ats>z ? ats : z;

printf("maximum %.2lf \n", ats);

//minimum
ats = x>y ? y : x;
ats = ats>z? z : ats;

printf("minimum %.2lf \n", ats);



}