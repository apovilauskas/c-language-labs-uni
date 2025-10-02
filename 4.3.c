// Vartotojas įveda tris neneigiamus sveikuosius skaičius (a, b, c). 
// Programa turi atspausdinti c-ąjį skaičių fc, kur
// fc=fc-1+fc-2, o f0 = a ir f1 = b. Jei a=0 ir b=1, 
// fc yra c-asis garsiosios Fibonačio sekos skaičius.


#include <stdio.h>

int main(){

    int a, b;
    long c;
    printf("Iveskite tris neneigiamus sveikuosius skaicius\n");
    scanf("%d %d %ld", &a, &b, &c);

    int count =2; //how many members of sequence covered so far
    int fib; //current highest value
    while(count++ < c){
        fib = a+b;
        if(count %2 ==0)b=fib;
        else a=fib;
    }

    printf("\n %d-asis narys yra %d ", c, fib);


    return 0;
}


