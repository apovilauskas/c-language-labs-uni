#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int length(double num) {
    char number[20];
    sprintf(number, "%.3lf", num);
    int count = 0;
    for (int i = 0; i < strlen(number); i++) { 
        if (number[i] != '0' && number[i] != '.') ++count;
    }
    return count;
}

int valid(char *filename, double *number) { 
    FILE *read = fopen(filename, "r");  
    if (!read) {
        return -1;
    }

    // 0 - valid, 1 - ne skaicius, 2 - netinka dydis, 3 - kablelis, -1 - neatsidare

    if (fscanf(read, "%lf", number) != 1) {
        return 1; // ne skaicius
    }
    
    int ch;
    while ((ch = fgetc(read)) != EOF && ch != '\n') return 1;

    if(*number < 10 || *number > 1000) {
        return 2; // netinkamas dydis
    } 
    char string[40];
    sprintf(string, "%lf", *number); // convert to string with 3 decimals max
    int dot=0, count=0;
    for(int i=0; i<strlen(string); i++){
        if(string[i] == '.')dot =1;
        if(dot ==1 && isdigit(string[i]) && string[i]!='0')count++;
    }
    if(count >= 3)return 3; //>3 po kablelio skatimenys

    fclose(read);
    return 0;
}

int main() {

    double num; //skaicius kurio tikimes
    char filename[50] = "ivestis.txt";
    FILE *write = fopen("isvestis.txt", "w");
    int len = -1; 

    printf("Programa is failo \"%s\" nuskenuoja realuji skaiciu nuo 10 iki 1000 ir isveda jo ilgi. skaicius privalo tureti ne daugiau 3 skaitmenu po kablelio.\n", filename);

    while (1) {
        int validacija = valid(filename, &num);
        if (validacija == -1) printf("Nepavyko atidaryti failo ");
        if (validacija == 0) {
            len = length(num);
            printf("\nIlgis yra %d\n", len);
            fprintf(write, "%d", len);
            fclose(write);
            return 0;
        }
        else if (validacija ==1) printf("Tai ne skaicius. Iveskite realu skaiciu. ");
        else if (validacija ==2) printf("Skaicius turi buti nuo 10 iki 1000. ");
        else if (validacija ==3) printf("Per daug skaiciu po kablelio. ");
        printf("\nIrasykite kito failo pavadinima: ");
        scanf("%s", filename);
    }   

    return 0;
}
