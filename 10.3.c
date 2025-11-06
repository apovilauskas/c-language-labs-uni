// 1) parašykite nepraeinantį testą (angl. failed test),
// 2) įgyvendinkite funkciją tiek ir tik tiek, kad testas praeitų ir
// 3) paleiskite visus testus, kad įsitikinti, jog jie visi praeina.
// Pateiktoms užduotims atlikti pasirinktinai įgyvendinkite pasirinktas 
// funkcijas iš string.h, o vienetų testams vykdyti naudokite assert.h.

#include <stdio.h>
#include <assert.h>

//<0 if str1 comes first, >0 if str2 comes first, 0 if identical
int strncmp(const char *str1, const char *str2, int n) {
    int i = 0;
    while (i < n && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    if (i < n) {
        return str1[i] - str2[i]; 
    }
    return 0; 
}

int main() {
    
    assert(strncmp("", "",1) == 0); //tuscia
    assert(strncmp("a", "b", 1) <0); //vienas simbolis
    assert(strncmp("arbc", "arbb",3) ==0); //antras eina pirmas bet limitas neleidzia
    assert(strncmp("arba", "arbb",4) <0); //pirmas eina pirmas
    assert(strncmp("arba", "arba",5) == 0); //vienodi ir ilgis vienodas
    assert(strncmp("arba", "arba",2) == 0); //vienodi ir ilgis vienodas plius limitas
    assert(strncmp("arba", "arbata",5) <0); //vienodi bet pirmas trumpesnis tai eina pirmas
    assert(strncmp("arba", "arbata",4) ==0); //vienodi bet pirmas trumpesnis tai eina pirmas, bet limitas neleidzia
    assert(strncmp("abc", "abc", 10) == 0);// limitas didesnis už abi eilutes (bet eilutės vienodos)
   
    return 0;
}