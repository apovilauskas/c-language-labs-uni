// Apibrėžkite funkciją, kuri leidžia gauti (įvesti) vieną 
// skaičių iš standartinio įvedimo srauto.
// Funkcijos prototipas: int getPositiveNumber(char *msg)
// Aprašymas: funkcija atspausdina į ekraną tekstinę eilutę msg 
// (kurioje tikisi gauti vartotojui skirtą pranešimą apie tai, ką
// reikia įvesti), ir ją (eilutę ekrane) kartoja 
// (prašo vartotojo įvesti vėl ir vėl) tol, kol vartotojas 
// neįveda vieno teigiamo skaičiaus eilutėje, kurį ši funkcija ir grąžina.

#include <stdio.h>

int getPositiveNumber(char *msg){
    int num;
    int success = 0;
    while(!success){
    success = 1;
    printf("%s", msg);
    scanf("%d", &num);
    while(getchar() != '\n')success = 0;
    if(num <1)success = 0;
    }
    return num;
}

int main() {
    
    char message[] = "Iveskite viena teigiama skaiciu: \n";
    printf("\nJusu teigiamas skaicius yra %d", getPositiveNumber(message));
    
    return 0;
}