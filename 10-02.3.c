// Parašykite programą, kuri paprašo vartotojo įvesti du skaičius 
// (s ir n), o po to nuskaito lygiai n teigiamų būsimo masyvo x
// elementų reikšmių. Jei reikšmė neteigiama – prašykite kartoti 
// to reikšmės įvedimą. Programa turi atspausdinti visas
// masyve esančių skaičių poras (xi, xj) tokias kad xi ir xj 
// sandauga yra lygi s.

#include <stdio.h>
#include <limits.h>

int main() {
    
int s,n;
int arr[1000];
int index=0;

    printf("Irasykite skaiciu s: ");

    while(1){
    scanf("%d", &s);
    int tinka =1;
    while(getchar() != '\n')tinka = 0;
    if(tinka == 0){
        printf("Irasykite tik sveikus skaicius\n");
    }
    else if(s >INT_MIN && s<INT_MAX)break;
    else printf("Netinkamas skaicius\n");
    }
    
    printf("Irasykite skaiciu n: ");

    while(1){
    scanf("%d", &n);
    int tinka =1;
    while(getchar() != '\n')tinka = 0;
    if(tinka == 0){
        printf(" Irasykite tik sveikus teigiamus skaicius\n");
    }
    else if(n >0 && n<INT_MAX)break;
    else printf("Irasykite tik sveikus teigiamus skaicius\n");
    }

    for(int i=0; i<n; i++){
        int num;
        printf("Irasykite skaiciu: ");

        while(1){
        scanf("%d", &num);
        int tinka =1;
        while(getchar() != '\n')tinka = 0;
        if(tinka == 0){
            printf("Irasykite tik sveikus teigiamus skaicius\n");
        }
        else if(num >0 && num<INT_MAX)break;
        else printf("Irasykite tik sveikus teigiamus skaicius\n");
        }
        arr[index++] = num;

    }

    for(int i=0; i<index-1; i++){
        for(int j=i+1; j<index; j++){
            if(arr[i]*arr[j] == s){
                printf("%d ir %d\n", arr[i], arr[j]);
            }
        }
    }


    return 0;
}