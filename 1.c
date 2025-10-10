// Parašykite programą, kuri paprašo įvesti vieną teigiamą skaičių, 
// ir suskaičiuoja jo faktorialą, kurį atspausinda ekrane ir
// taip pat įrašo į rezultatų failą „out.txt“

// pasako ka programa darys
// pasako kokius duomenis ivesti 
// validacija
// pasako ar teisingai nuskaityti 
// kas blogai buvo

#include <stdio.h>

int faktorialas(int num){

    int ans=1;
    for(int i=1; i<=num; i++){
        ans*=i;
    }
    return ans;

}

int main() {
    
    printf("Si programa suskaiciuoja faktoriala ir isveda ji ir i ekrana, ir i faila \"out.txt\" ");
    printf("\nIrasykite naturaluji skaiciu: ");

    int num;
    while(1){
        scanf("%d", &num);
        int tinka = 1;
        while(getchar() != '\n')tinka =0;

        if(tinka == 0){
            printf("iveskite tik teigiamus, sveikus skaicius: ");
        }
        else if(num < 1){
            printf("skaicius turi buti teigiamas: ");
        }
        else if(tinka ==1)break;

    }

    printf("duomenys nuskaityti teisingai\n");

    int ats = faktorialas(num);
    printf("Apskaiciuotas faktorialas yra %d", ats);

    FILE *write = fopen ("out.txt", "w");
    fprintf(write, "%d", ats); 
    
    return 0;
}
