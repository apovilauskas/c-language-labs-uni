#include <stdio.h>
#include <math.h>

int main(){
    
    printf("Iveskite kelinto laipsnio bus daugianaris\n");

    int n; //laipsnis
    scanf("%d", &n);

    int arr[100];
    int i=0;
    for(; i<n+1; i++){
        printf("iveskite %d-aji nari\n", i+1);
        scanf("%d", &arr[i]);

    }

    int x;
    printf("iveskite kintamojo x reiksme\n");
    scanf("%d", &x);

    int sum = 0;
    i = n;
    for(int j=0; j<n+1; j++){
        int temp = ((pow(x, j)*arr[i--]));
        sum += temp;
    }

    printf("%d\n", sum);

    return 0;
}