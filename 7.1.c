// Apibrėžkite funkciją, kuri patikrina, ar duotas skaičius 
// papuola į nustatytą intervalą.
// Funkcijos prototipas: int isInRange(int number, 
// int low, int high)
// Aprašymas: funkcija turi grąžinti true, jei skaičius 
// number priklauso intervalui [low; high] (su sąlyga, 
// kad low neviršija
// high), kitaip ji turi grąžinti false.

#include <stdio.h>

int isInRange(int number, int low, int high){
    if(number <= high && number >= low)return 1;
    return 0;    
}

int main() {
    
int num=5, low=6, high=7;
int res = isInRange(num, low, high);
if(res)printf("Patenka");
else printf("Nepatenka"); 
    
    return 0;
}

