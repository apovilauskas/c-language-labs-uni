// Apibrėžkite funkciją, kuri grąžina failo dydį baitais.
// Funkcijos prototipas: long getFileSize(char *fileName)
// Aprašymas: funkcija gauna failo vardą kaip parametrą, bando jį atidaryti 
// (skaitymui binariniu režimu), ir peršokus į failo
// pabaigą (fseek) sužinoti (ftell) kiek baitų jis užima; 
// tą baitų skaičių funkcija ir grąžina (patikrinkite su OS rodomomis
// reikšmėmis), o jei kažkas nepavyko (pvz. tokio failo nėra),
//  funkcija grąžina reikšmę -1.

#include <stdio.h>

long getFileSize(char *fileName){
    FILE *file = fopen(fileName, "rb");
    if(!file)return -1;

    fseek(file, 0, SEEK_END); //how many bytes to move, from where to start moving
    long size = ftell(file); //read current position

    fclose(file);
    return size;
}

int main() {
    
    char failas[] = "failas.txt";
    long res = getFileSize(failas);
    printf("%ld", res);

    return 0;
}