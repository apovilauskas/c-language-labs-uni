// Vartotojas įveda tris sveikus skaičius (a, b, c). 
//Programa turi atspausdinti visus teigiamus sveikus skaičius iš
//intervalo (a; b], kurie dalijasi iš skaičiaus c su liekana 1.

#include <stdio.h>

int main(){

    int a, b, c;
    printf("Iveskite tris sveikuosius skaicius\n");
    scanf("%d %d %d", &a, &b, &c);

    while(++a<=b){
        if(a%c == 1)printf("%d ", a);
    }

    return 0;
}


