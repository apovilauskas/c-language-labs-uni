#include <stdio.h>
#include <math.h>

int main() {
    
    printf("Irasykite 3 skaicius: ");
    double x, y, z;
    //scanf("%lf %lf %lf", &x, &y, &z );
    x=5.5, y=7, z=3.14159;

    //a
    double res1 = x + 4*y + pow(z, 3);
    printf("%.2lf \n", res1);

    //b
    double res2 = x + sqrt(y);
    res2 *= (pow(z, 4) - abs(z) + 46.3);
    printf("%.2lf \n", res2);

    return 0;
}