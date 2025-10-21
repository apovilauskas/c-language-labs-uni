// Apibrėžkite funkciją splitData, kuri moka vieną masyvą padalinti į 
// dvi dalis, dinaminėje atmintyje sukurdama du naujus
// masyvus (į pirmą masyvą įrašydama skaičius esančius pradinio masyvo pradžioje,
// o į antrą masyvą – pradinio masyvo
// likusią dalį). Ši funkcija gauna penkis parametrus. Du pirmi parametrai 
// leidžia gauti pradinio masyvo duomenis ir dydį,
// trečias parametras nurodo pirmosios dalies dydį (pagal jį nustatoma, 
// kurioje vietoje vyksta perskėlimas), o likę du
// parametrai skirti perduoti (grąžinti) tuos du naujai sukurtus masyvus 
// (pirmųjų elementų adresus) iš funkcijos į likusią
// programą. Funkcija pirmiausia patikrina, ar visų (!) parametrų reikšmės 
// korektiškos, tuomet sukuria du naujus atitinkamų
// dydžių masyvus dinaminėje atmintyje, po ko perkelia reikiamą skaičių 
// elementų į atitinkamai pirmą ir į antrą masyvą.
// Funkcija tikisi, jog iki ją iškviečiant šie du masyvai dar nebus sukurti, 
// t.y. tikisi, jog gaus parametrų reikšmes lygias NULL ir
// sukurs masyvus savo viduje. Sėkmės atveju, funkcija grąžina skaičių 0, 
// nesėkmės atveju -1.

#include <stdio.h>
#include <stdlib.h>
#define cmax 100

int splitData(int array[], int size, int size1, int *array1[], int *array2[]){

    if(array == NULL || size < 1 || size1 < 1 || size1 > size || array1 == NULL || array2 == NULL)
        return -1;
    if(*array1 != NULL || *array2 != NULL)
        return -1;

    *array1 = (int*)malloc(size1*sizeof(int));
    *array2 = (int*)malloc((size-size1)*sizeof(int));
        
    for(int i=0; i<size1; i++){
        (*array1)[i] = array[i];
    }
    for(int i=0; i<size-size1; i++){
        (*array2)[i] = array[size1+i];
    }
    return 0;
}

int main() {
    
    int masyvas[] = {1,2,3,4,5,6,7,8,9,0};
    int size = 10;
    int *arr1= NULL;
    int *arr2= NULL;
    int riba = 4;
    int res = splitData(masyvas, size, riba, &arr1, &arr2);


    free(arr1);
    free(arr2);
    return 0;
}