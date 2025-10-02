// Parašykite programą, kuri leidžia vesti ir įsimena vartotojo 
// vedamus teigiamus skaičius iki tol, kol jis įveda pirmą
// neteigiamą reikšmę. Programa turi atspausdinti visus įvestus 
// pirminius skaičius, kiekvieną pirminį skaičių spausdindama
// tik vieną kartą, t. y. išvedant rezultatus sykį jau atspausdinta 
// pirminio skaičiaus reikšmė nebekartojama.

#include <stdio.h>
#include <limits.h>

int pirminis(int sk){
    if(sk < 2) return 0;
    if(sk == 2) return 1;
    if(sk % 2 == 0) return 0;
    for(int i=3; i*i<=sk; i+=2){
        if(sk%i == 0)return 0;
    }
    return 1;
}

int main() {
    
    int index =0;
    int arr[1000];
    int num;
    printf("Veskite teigiamus skaicius: \n");
    int baigti = 0;

    while(baigti ==0){
        scanf("%d", &num);
        int tinka =1;

        while(getchar() != '\n')tinka =0;

        if(tinka ==0)printf("Iveskite teigiamus skaicius\n");
        else if(num <= 0)baigti = 1; 
        else if(num > 0 && num < INT_MAX) {
            arr[index++] = num;
        }
        else printf("netinkamas skaicius\n");
    }

    for(int i=0; i<index-1; i++){
        for(int j=i+1; j<index; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    if(pirminis(arr[0]) ==1) printf("%d ", arr[0]);
    for(int i=1; i<index; i++){
         if(pirminis(arr[i]) == 1 && arr[i]!=arr[i-1]){
             printf("%d ", arr[i]); 
         }
    }
    
    return 0;
}