// Parašykite programą, kuri patikrina, ar eilutėje yra korektiškai 
// įvestas el.pašto adresas. Laikykite, kad jis korektiškas, jei
// eilutėje yra vienas simbolis @ ir (po jo) bent vienas taškas, 
// o prieš @, po taško ir tarp šių dviejų simbolių – ne mažiau nei
// vienas kitoks simbolis. Jei įvestis korektiška, programa turi 
// atspausdinti domeną, t.y. el.pašto dalį po simbolio @. Visi kada
// nors pateikti korektiški elektroninio pašto adresai turi būti 
// kaupiami (append) tekstiniame faile “emails.txt”.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
        
    char domenas[30]="@";
    int j=0; //indexavimui
    int index=0;
    char email[50];
    FILE *append = fopen("emails.txt", "a");
    if (!append) {
            printf("Nepavyko atidaryti failo.\n");
            return 1;
        }
    
    while(1){
        printf("parasykite emailo adresa: ");
        scanf("%s", email);

        //ilgis
        int ilgis = strlen(email);
        if(ilgis <5){ //a@b.c
            printf("Per trumpas adresas. Bandykite dar karta.\n");
            continue;
        }

        //pirmas/paskutinis negali buti ne alphanum
        if(!isalnum(email[0]) || !isalnum(email[strlen(email)-1])){
            printf("netinkamas formatas. Bandykite dar karta.\n");
            continue;
        }      

        //vienas @
        //domeno radimas
        //.@ @. .. 
        int etacount=0;
        int etaindex=0;
        int taskaspoeta=0;
        int valid=1;
        for(int i=0; i<strlen(email); i++){
            if(email[i] =='@'){
                etacount ++;
                etaindex =1;
                if(etacount >1){
                    valid=0;
                }
            }
            if(etaindex ==1)domenas[j++]=email[i];
            if(email[i] =='.' && email[i+1]=='.'){
                valid=0;
            }
            if(email[i] =='@' && email[i+1]=='.'){
                valid=0;
            }
            if(email[i] =='.' && email[i+1]=='@'){
                valid=0;
            }
            if(etaindex==1 && email[i] == '.')taskaspoeta=1;
            if(!isalnum(email[i]) && email[i] !='.' && email[i] !='@' && email[i] !='-' && email[i] !='_'){
                valid=0;
            }

        }
        if(taskaspoeta ==0){
            printf("po @ zenklo turi buti bent vienas taskas. Bandykite dar karta.\n");
            continue;
        }
        if(!valid){
            printf("Netinkamas formatas. Bandykite dar karta.\n");
            continue;
        }

        break;
    }


    printf("\n%s\n", domenas);
    fprintf(append, "%s\n", email);

    return 0;
}