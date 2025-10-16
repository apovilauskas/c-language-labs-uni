// Apibrėžkite funkciją, skirtą vartotojo sąsajoje pateikiamam 
// meniu spausdinti ir vartotojo pasirinkimui gauti.Funkcijos prototipas: 
// int showMenu(char *menuTitle, char *menuOptions[], 
// int menuSize, char *inputMsg)
// Aprašymas: funkcija turi atspausdinti meniu antraštę 
// (parametras menuTitle), tuomet atspausdinti meniu iš menuSize
// pasirinkimų, kur meniu elementų (eilučių) pavadinimai 
// pateikiami (eilučių) masyve menuOptions. Tuomet funkcija
// atspausdina tekstinę eilutę inputMsg, kurioje perduodamas 
// vartotojui skirtas tekstas, kuriame prašoma įvesti savo
// pasirinkimą, ir gavusi iš vartotojo skaičių (atitinkamo meniu 
// punkto numerį) jį ir grąžina; jeigu vartotojo įvedimas
// nekorektiškas (įvedamas ne skaičius arba tokio meniu punkto nėra), 
// visas spausdinimo procesas (antraštė, meniu,
// prašymas įvesti) kartojamas iš naujo, tol, kol įvedimas netaps korektiškas.

#include <stdio.h>

int showMenu(const char *menuTitle, const char *menuOptions[], 
int menuSize, const char *inputMsg){

    int choice;
    int success = 0;
    while(!success){
        success=1;
        printf("%s\n", menuTitle);
        for(int i=0; i<menuSize; ++i){
        printf("%s\n", menuOptions[i]);
        }
        printf("%s", inputMsg);
        scanf("%d", &choice);
        while(getchar() != '\n')success =0;
        if(choice > menuSize || choice < 1)success =0;
    }
    return choice;

}

int main() {
    
    const char *pasirinkimai[4] = {
    "   Arklio desra",
    "   Dygliakiauliu spageti",
    "   TicTac is rankinuko",
    "   Mulo pastetas"
    };
    
    int pasirinkimas = showMenu("\nAugusto restorano meniu:", pasirinkimai, 4, "pasirinkite numeri: ");
    printf("Jus pasirinkote patiekala nr. %d", pasirinkimas);
    
    return 0;
}