#include <stdio.h>
#include <math.h>
 
// skaito konstantas
void skaityti(int *arr, int *n, int *x) { //masyvas, polinomo laipsnis, kintamasis
    printf("Iveskite polinomo laipsni: ");
    scanf("%d", n);

    for (int i = 0; i <= *n; i++) {
        printf("Iveskite %d-ojo nario konstanta: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Iveskite kintamojo x reiksme: ");
    scanf("%d", &(*x));

}

// skaiciuoja polinomo suma
int suma(int *arr, int n, int x) {
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum += arr[n-i] * pow(x, i);
    }
    return sum;
}

int main() {
    int n;             // laipsnis
    int arr[20];       // konstantos
    int x, ats;

    skaityti(arr, &n, &x);

    ats = suma(arr, n, x);

    printf("Polinomo reiksme: %d\n", ats);

    return 0;
}
