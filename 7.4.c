// Apibrėžkite funkciją, kuri leidžia užpildyti masyvą 
// atsitiktinėmis reikšmėmis.Funkcijos prototipas: 
// void generateArray(int data[], int size, int low, int high)
// Aprašymas: kiekvienam iš size elementų, esančių masyve data, 
// funkcija turi priskirti atsitiktinę reikšmę iš intervalo [low;high]; 
// nieko papildomai grąžinti nereikia, t.y. funkcijos rezultatas 
// yra masyve esančios (naujos) reikšmės.

#include <stdio.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high){
    for(int i=0; i<size; i++){
        data[i] =  + rand() % (high-low+1)+low;
    }
}

int main() {
    
    int array[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(array)/sizeof(array[0]);
    int low = 12; 
    int high = 24;
    generateArray(array, size, low, high);
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}