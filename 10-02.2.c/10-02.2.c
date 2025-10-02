// Parašykite programą, kurios viduje apibrėžiamas masyvas, galintis sutalpinti 1000 elementų. Ši programa turi paprašyti
// vartotojo įvesti tris skaičius (a, b, c), į masyvą įrašyti c atsitiktinai sugeneruotų reikšmių, kurių kiekviena priklauso
// intervalui [a; b], ir atspausdinti masyvo turinį (tas c reikšmių) į ekraną.

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int arr[1000];
    int a, b, c;
    printf("irasykite tris skaicius: ");

while(1){
    scanf("%d", &a);
    int tinka =1;
    while(getchar() != '\n')tinka = 0;

    if(tinka == 0){
        printf("irasykite tik sveikus skaicius\n");
    }

    if(a > INT_MIN && a < INT_MAX)break;
    else printf("netinkamas skaicius\n");
}

while(1){
    scanf("%d", &b);
    int tinka =1;
    while(getchar() != '\n')tinka = 0;

    if(tinka == 0){
        printf("irasykite tik sveikus skaicius\n");
    }

    if(b > a && b < INT_MAX)break;
    else printf("netinkamas skaicius\n");
    
}

while(1){
    scanf("%d", &c);
    int tinka =1;
    while(getchar() != '\n')tinka = 0;

    if(tinka == 0){
        printf("irasykite tik sveikus skaicius\n");
    }

    if(c > 0 && c < 1000)break;
    else printf("netinkamas skaicius\n");
    
}

int i=0;
for(int j=0; j<c; j++){
    int num = a + rand()%(b-a+1);
    arr[i++] = num;
}

for(int j=0; j<c; j++){
    printf("%d ", arr[j]);
}



    return 0;
}