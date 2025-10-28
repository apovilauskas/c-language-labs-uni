// Parašyti funkciją, kuri duotame tekste perrašo žodžius 
// atvirkščia tvarka (žodžių tvarka nesikeičia, 
// bet keičiasi simbolių tvarka žodyje).

// Programoje turi būti numatyti atvejai: vartotojo nurodyto duomenų failo nėra; rezultatų
// failo negalima sukurti.)

// Failų pavadinimai įvedami naudojant komandinės eilutės argumentus

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define cmax 900

void reverse(char *eilute, int ilgis){

    int tarpas=0;
    int i=0;
    int j=0;
    char temp;

    while(tarpas <= ilgis){
        if(eilute[tarpas] == ' ' || tarpas == ilgis){
            j= tarpas -1;
            while(i<j){
                temp = eilute[i];
                eilute[i] = eilute[j];
                eilute[j] = temp;
                i++;
                j--;
            }
            i = tarpas +1;
            tarpas=i;
        }
        else tarpas ++;
    }
}

int main(int argc, char *argv[]) {
    
    FILE *read = fopen(argv[1], "r");
    FILE *write = fopen(argv[2], "w");

    if(!read){
        printf("Nepavyko atidaryti failo");
        return 1;
    }
    if(!write){
        printf("Nepavyko sukurti failo");
        return 1;
    }

    char eilute[cmax];
    while(fgets(eilute, cmax, read)){
        int len = strlen(eilute);
        if (len > 0 && eilute[len - 1] == '\n') {
            len--;
        }
        reverse(eilute, len);
        fprintf(write, "%s", eilute);
    }

    fclose(read);
    fclose(write);
    
    return 0;
}
