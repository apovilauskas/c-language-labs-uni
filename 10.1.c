// 1) parašykite nepraeinantį testą (angl. failed test),
// 2) įgyvendinkite funkciją tiek ir tik tiek, kad testas praeitų ir
// 3) paleiskite visus testus, kad įsitikinti, jog jie visi praeina.
// Pateiktoms užduotims atlikti pasirinktinai įgyvendinkite pasirinktas 
// funkcijas iš string.h, o vienetų testams vykdyti
// pasinaudokite assert.h. Šių užduočių kontekste funkcija main – ne daugiau 
// nei vienetų testų vykdymo priemonė. Funkcijų
// viduje negali būti funkcionalumo, kuris netikrinamas main viduje 
// esančiais testais
#include <assert.h>
#include <stdio.h>

int strlen(const char str[]) {
    int len = 0;
    int i = 0;
    while (str[i++] != '\0') {
        len++;
    }
    return len;
}

int main() {
    assert(strlen("") == 0);

    assert(strlen("a") == 1);

    assert(strlen("hello") == 5);

    assert(strlen("hello world!") == 12);


    return 0;
}