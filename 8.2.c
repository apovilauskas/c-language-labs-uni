// Apibrėžkite funkciją, kuri gauna argc-1 failų vardų per 
// komandinės eilutės parametrus, ir grąžina daugiausiai baitų
// atmintyje užimančio failo vardą.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cmax 100
typedef char string[50];

string* maxbytes(int argc, char* filename[]){
    long int maxx=0;
    static string maxfile;
    for(int i=0; i<argc; i++){
        FILE *read = fopen(filename[i], "rb");
        fseek(read, 0, SEEK_END);
        long int tempsize = ftell(read);
        if(tempsize > maxx){
            maxx = tempsize;
            strcpy(maxfile, filename[i]);
        }
        fclose(read);
    }

    return &maxfile;
}

int main(int argc, char *argv[]) {
    
    string *didziausioFailoPavadinimas = maxbytes(argc-1, argv+1);
     
    return 0;
}