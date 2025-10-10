// Parašykite programą, kuri paprašo įvesti tris skaičius vienoje eilutėje, 
// be tarpų, teigiamus arba neigiamus, 
// kuriuos vieną nuo kito skiria kabliataškiai, 
// ir raskite vidurinį (pagal reikšmę) skaičių. 
// Jei įvestis korektiška, rezultatą (reikšmę) programa
// turi atspausdinti rezultatų faile, 
// kurio vardas įvedamas ir privalo baigtis simboliais „.txt“ 
// (jei taip nėra, prašoma failo vardą įvesti iš naujo).

#include <stdio.h>
#include <string.h>

int main() {
    double a, b, c;
    int success = 0;
    char string[30];
    printf("Irasykite tris skaicius atskirtus kabliataskiais (pvz. 3;-1;7):\n");
    while(!success){
        if(fgets(string, sizeof(string), stdin) == NULL)continue;

        // Patikrinam, ar yra tiksliai du kabliataškiai
        int count = 0;
        for (int i = 0; string[i]; i++) {
            if (string[i] == ';') count++;
        }
        if (count != 2) {
            printf("Turi buti trys skaiciai atskirti dviem kabliataskiais\n");
            continue;
        }
    int n;
    if (sscanf(string, " %lf;%lf;%lf %n", &a, &b, &c, &n) != 3 || (string[n] != '\0' && string[n] != '\n')) {
        printf("Netinkama ivestis\n");
        continue;
    }
        success =1;
    }

    

    printf("parasykite tekstini faila i kuri ivesti atsakyma: ");
    char failas[30];
    while(1){
    scanf("%s", failas);
    int txt=0;
    for(int i=0; i<strlen(failas); ++i){
        if(failas[i] == '.'){
            if(failas[i+1]== 't' && failas[i+2]== 'x' && failas[i+3]&& 't')txt=1;
        }
    }
    if(txt == 0){
        printf("failas turi buti .txt. bandykite vel: ");
        continue;
    }
    FILE *write= fopen(failas, "w");
    if((a>=b && b>=c) || (a<=b && b<=c))fprintf(write, "%lf", b);
    else if((b>=a && a>=c) || (b<=a && a<=c))fprintf(write, "%lf", a);
    else if((a>=c && c>=b) || (a<=c && c<=b))fprintf(write, "%lf", c);
    printf("\nsekmingai isspausdinta");
    break;
    }

    return 0;
}