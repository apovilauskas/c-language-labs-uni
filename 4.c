// Parašykite programą, kuri patikrina, ar eilutėje yra korektiškai įvesta data,
// formatu YYYY-MM-DD. Jei taip, programa turi atspausdinti, kokia tai 
// savaitės diena. 
// Savaitės dienų pavadinimai turi būti skaitomi iš tekstinio failo „week.txt“, 
// kuriame yra iš anksto įrašytos septynios eilutės su atitinkamų 
// dienų pavadinimais. Pakeitus pavadinimus faile (pvz. iš lietuvių
// kalbos į anglų), programoje spausdinamos reikšmės 
// irgi turi pasikeisti (automatiškai)

#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    int year, month, day;
    char string[12];

    printf("Iveskite data formatu yyyy-mm-dd: ");
    
    int success=0;
    while(!success){
        scanf("%s", string);
        int n;
        if(sscanf(string, "%d-%d-%d%n", &year, &month, &day, &n) != 3 || string[n] != '\0'){
            printf("Netinkama ivestis. Bandykite vel: ");
        }
        else if(year<0 || year >9999 || month >12 || month <1 || day<1){
            printf("Netinkama ivestis. Bandykite vel: ");
        }
        else {
            int max_day = 31;
            if (month == 4 || month == 6 || month == 9 || month == 11) max_day = 30;
            else if (month == 2) {
                int leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                max_day = leap ? 29 : 28;
            }
            if (day > max_day) {
                printf("Netinkama ivestis. Bandykite vel: ");
            } else {
                success = 1;
            }
        }
    }

    struct tm date = {0};
    date.tm_year = year-1900;
    date.tm_mon = month-1;
    date.tm_mday = day-1;
    
    mktime(&date);

    FILE *file = fopen("week.txt", "r");
    if (!file) {
        printf("Nepavyko atidaryti failo week.txt\n");
        return 1;
    }

    char days[7][20];
    for(int i=0; i<7; i++){
        if(fgets(days[i], sizeof(days[i]), file) == NULL){
            printf("Nepavyko atidaryti failo week.txt\n") ;
            return 1;
        }
        days[i][strcspn(days[i], "\n")]= '\0';
    }
    fclose(file);

    printf("Day of the week: %s\n", days[date.tm_wday]);
    
    return 0;
}