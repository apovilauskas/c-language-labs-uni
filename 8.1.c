// Apibrėžkite funkciją createArray, kuri dinaminėje atmintyje 
// leidžia sukurti (naują) sveikųjų skaičių masyvą, užpildytą
// atsitiktinėmis reikšmėmis iš nurodyto intervalo. Ši funkcija 
// gauna būsimo masyvo dydį size, išskiria atitinkamo dydžio
// bloką dinaminėje atmintyje, ir užpildo jį atsitiktiniais 
// skaičiais iš intervalo [low; high]. Paskutiniajam veiksmui atlikti, jei
// norite, galite pasinaudoti ankstesnėse (7) pratybose parengta 
// funkcija generateArray. Funkcija createArray sėkmės
// atveju turi grąžinti rodyklę į pirmą naujai sukurto masyvo elementą, 
// nesėkmės atveju – NULL.
// funkcijos viduje vietoje operatoriaus [] masyvo
// elementui pasiekti būtų naudojamas išrodyklinimo operatorius *, 
// adreso operatorius & ir rodyklių aritmetika.


#include <stdio.h>
#include <stdlib.h>

int *createArray(int size, int low, int high){ 

    int *arr = (int*)malloc(size*sizeof(int)); //padaro tiek vietos turinti masyva
    if(arr == NULL)return NULL; // nesėkmės atveju – NULL.
    for(int i=0; i<size; ++i){ //reiksmes uzpildo su random 20-30 intervale
        *(arr+i) = rand() % (high - low + 1) + low; 
    }
    return arr;
}

int main() {
    
    int size= 10; //norimo masyvo dydis
    int low = 20; //kiekvienas elementas bus intervale [20;30]
    int high = 30;
    
    int *newarray = createArray(size, low, high); 
    
    free(newarray);
    return 0;
}