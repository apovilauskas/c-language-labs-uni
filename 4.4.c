// Vartotojas įveda skaičių n, o po to – n realiųjų skaičių. 
// Programa turi suskaičiuoti šių skaičių sumą ir vidurkį,
// o taip pat mažiausią (minimumą) ir didžiausią (maksimumą) 

#include <stdio.h>
#include <math.h>
#include <float.h>

int main(){

    int n;
    printf("Iveskite kiek bus skaiciu: ");
    scanf("%d", &n);

    double sum=0;
    double minn=DBL_MAX, maxx=-DBL_MAX;
    for(int i=0; i<n; i++){

        double temp;
        printf("\nIrasykite skaiciu %d: ", i+1);
        scanf("%lf", &temp);

        sum+= temp;
        if(temp <minn)minn = temp;
        if(temp >maxx)maxx = temp;
    }

    printf("\nSuma %.2lf", sum);
    printf("\nVidurkis %.2lf", sum/n);
    printf("\nMinimumas %.2lf", minn);
    printf("\nMaksimumas %.2lf", maxx);
   


    return 0;
}