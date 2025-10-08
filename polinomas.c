#include <stdio.h>
#include <math.h>
 
// skaito konstantas
void skaityti(double *arr, int n, double *x) { //masyvas, polinomo laipsnis, kintamasis

    for (int i = 0; i <= n; i++) {
        printf("Iveskite %d-ojo nario konstanta: ", i + 1);
        scanf("%lf", &arr[i]);
    }

    printf("Iveskite kintamojo x reiksme: ");
    scanf("%lf", x);

}

// skaiciuoja polinomo suma
double suma(double *arr, int n, double x) {
    double sum = 0;
    for (int i = 0; i <= n; i++){
        sum += arr[n-i] * pow(x, i);
    }
    return sum;
}

int main() {
    int n;             // laipsnis

    printf("Iveskite polinomo laipsni: ");
    scanf("%d", &n);

    //sukuriamas dinaminis masyvas
    double *arr = (double*)malloc(n* sizeof(int));
    double x, ats;

    skaityti(arr, n, &x);
    ats = suma(arr, n, x);
    printf("Polinomo reiksme: %.4lf\n", ats);

    free(arr);
    return 0;
}
