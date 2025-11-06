// 1) parašykite nepraeinantį testą (angl. failed test),
// 2) įgyvendinkite funkciją tiek ir tik tiek, kad testas praeitų ir
// 3) paleiskite visus testus, kad įsitikinti, jog jie visi praeina.
// Pateiktoms užduotims atlikti pasirinktinai įgyvendinkite pasirinktas 
// funkcijas iš string.h, o vienetų testams vykdyti naudokite assert.h.

#include <stdio.h>
#include <assert.h>

//<0 if str1 comes first, >0 if str2 comes first, 0 if identical
int strcmp(const char *str1, const char *str2){
    int i=0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i]!=str2[i])return str1[i]-str2[i];
        i++;
    }
    return str1[i]-str2[i];

}

int main() {
    
    assert(strcmp("", "") == 0); //tuscia
    assert(strcmp("a", "b") <0); //vienas simbolis
    assert(strcmp("arbc", "arbb") >0); //antras eina pirmas
    assert(strcmp("arba", "arbb") <0); //pirmas eina pirmas
    assert(strcmp("arba", "arba") == 0); //vienodi ir ilgis vienodas
    assert(strcmp("arba", "arbata") <0); //vienodi bet pirmas trumpesnis tai eina pirmas

    return 0;
}