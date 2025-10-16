// Apibrėžkite funkciją, kuri suskaičiuoja duoto skaičiaus faktorialą.
// Funkcijos prototipas: int getFactorial(int number)
// Aprašymas: funkcija skaičiavimams naudojasi rekursija 
// ir grąžina neneigiamo skaičiaus number faktorialą, o jei jo
// suskaičiuoti negalima, grąžina 0.
// Įdomu: apibrėžkite (kitą) funkciją getFactorial2, kuri duoda tą patį rezultatą, 
// bet rekursija nesinaudoja

#include <stdio.h>

int getFactorial(int number){
   if(number < 0)return 0; 
   if(number == 0)return 1;
   return number * getFactorial(number-1);
}

int getFactorial2(int number){
    if(number < 0)return 0;
    if(number == 0)return 1;
    int res=1;
    while(number >0){
        res*= number--;
    }
    return res;

}

int main() {
    
    printf("%d\n", getFactorial(2));
    printf("%d\n", getFactorial2(2));
    
    return 0;
}