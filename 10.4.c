// 1) parašykite nepraeinantį testą (angl. failed test),
// 2) įgyvendinkite funkciją tiek ir tik tiek, kad testas praeitų ir
// 3) paleiskite visus testus, kad įsitikinti, jog jie visi praeina.
// Pateiktoms užduotims atlikti pasirinktinai įgyvendinkite pasirinktas 
// funkcijas iš string.h, o vienetų testams vykdyti naudokite assert.h.
#include <stdio.h>
#include <assert.h>

char *strchr(char str[], char ch){
    int i=0; 
    while(str[i] != '\0'){
        if(str[i] == ch) return &(str[i]);
        i++;
    }
    if(ch =='\0')return &(str[i]);
    return NULL;
}

int main() {
    
    char s[]="";
    assert(strchr(s, '\0') == s); // 1. Tuščias stringas, ieškome '\0' 
    assert(strchr(s, 'a') == NULL); // 2. Ieškome simbolio, kurio nėra

    char s1[] = "x"; 
    assert(strchr(s1, 'x') == s1);// 3. Vienas simbolis
    assert(strchr(s1, '\0') == s1 + 1); 
    assert(strchr(s, 'y') == NULL);  

    char s2[] ="xyz";
    assert(strchr(s2, 'y') == s2 + 1); // 4. Simbolis viduryje
    assert(strchr(s2, 'x') == s2); // 5. Pirmas simbolis

    char s3[] = "antis";
    assert(strchr(s3, 's') == s3 + 4); // 6. Paskutinis simbolis (prieš '\0')    
    
    return 0;
}