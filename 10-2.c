// Užduotis turi 3 sąlygas. 
// 1 – ji turi turėti vartotojo sąsają (nurodyti, ką įvesti, arba paaiškinti, 
// kas bus daroma su įvestais duomenimis). 
// 2 – patvirtinimas (neleisti programai sugriūti, jei faktiniai įvesti 
// duomenys neatitinka tikėtinų įvestų duomenų (int įvestis turėtų priimti 12, 
// bet ne 12abc). 
// 3 – įvesti duomenys turėtų būti patikrinti, 
// kad visada atitiktų masyvo rėžius. 

// užduotis:
// a) apibrėžia masyvą, galinti sutalpinti 10 elementų, tame pačiame sakinyje inicializuodama juos nulinėmis reikšmėmis
// b) atspausdina visą masyvą į ekraną
// c) pačiam pirmam, ketvirtam ir dešimtam masyvo elementams priskiria reikšmes atitinkamai 1, 2 ir 3
// d) ištrina iš masyvo trečią elementą
// e) įterpia į masyvą naują elementą su reikšme 4, taip, kad po įterpimo jis būtų septintas
// f) atspausdina visą masyvą į ekraną
// g) paprašo vartotojo įvesti du skaičius (x ir y), ir masyvo elementui su indeksu x nustato naują reikšmę, lygią y
// h) paprašo vartotojo įvesti vieną skaičių (x), ir ištrina iš masyvo elementą su indeksu x
// i) paprašo vartotoją įvesti du skaičius (x ir y), ir į masyvą įterpia naują elementą su reikšme y, taip, kad po įterpimo jo
// indeksas būtų x
// j) atspausdina visą masyvą į ekraną

#include <stdio.h>
#include <limits.h>

int main() {

    // a) apibrėžia masyvą, galinti sutalpinti 10 elementų, 
    // tame pačiame sakinyje inicializuodama juos nulinėmis reikšmėmis    
   
    int cmax = 10;
    int arr[50] = {0}; //extra vietos iterpimams
    
    for(int i=0; i<cmax; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // b) atspausdina visą masyvą į ekraną
        
    for(int i=0; i<cmax; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

    // c) pačiam pirmam, ketvirtam ir dešimtam masyvo elementams priskiria reikšmes atitinkamai 1, 2 ir 3
    
    arr[0] = 1;
    arr[3] = 2;
    arr[9] = 3;

    // d) ištrina iš masyvo trečią elementą

    int index = 2;
    cmax --;
    for(int i=index; i<cmax; i++){
        arr[i] = arr[i+1];
    }

        // for(int i=0; i<cmax; i++){
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");
    
   // e) įterpia į masyvą naują elementą su reikšme 4, taip, kad po įterpimo jis būtų septintas
  
   int index1 = 6;
   for(int i=cmax; i>index1; i--){
        arr[i+1] = arr[i];
   }
   cmax ++;
   arr[index1] = 4;
    
   // f) atspausdina visą masyvą į ekraną

    for(int i=0; i<cmax; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // g) paprašo vartotojo įvesti du skaičius (x ir y)
    // ir masyvo elementui su indeksu x nustato naują reikšmę, lygią y
  
    int x, y;
    printf("\nIveskite indeksa, esanti masyve (0 - %d): ", cmax-1);

    while(1){

        scanf("%d", &x);
        
        //validavimas
        int tinka =1;     
        while(getchar() != '\n') tinka=0;

        //jei yra raidziu tai buferi istrinam ir pasakom netinka
        if(tinka == 0){
            printf("irasykite tik sveikus skaicius\n");
        }
        
        else if(x< cmax && x>=0)break;
        else printf("toks indeksas masyve neegzistuoja\n");

    }

    printf("Iveskite norima reiksme: ");

    while(1){

        scanf("%d", &y);
        
        //validavimas
        int tinka =1;     
        while(getchar() != '\n') tinka=0;

        //jei yra raidziu tai buferi istrinam ir pasakom netinka
        if(tinka == 0){
            printf("irasykite tik sveikus skaicius\n");
        }
        
        else if(y> INT_MIN && y<INT_MAX)break;
        else printf("toks skaicius netinkamas\n");

    }
    
    arr[x] = y;

        // for(int i=0; i<cmax; i++){
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");

    // h) paprašo vartotojo įvesti vieną skaičių (x), 
    // ir ištrina iš masyvo elementą su indeksu x   

    printf("Iveskite skaiciu. Elementas tuo indeksu bus istrintas: ");

    while(1){

    scanf("%d", &x);
    
    //validavimas
    int tinka =1;     
    while(getchar() != '\n') tinka=0;

    //jei yra raidziu tai buferi istrinam ir pasakom netinka
    if(tinka == 0){
        printf("irasykite tik sveikus skaicius\n");
    }
    
    //main logic
    else if(x<=cmax && x>=0)break;
    else printf("toks indeksas masyve neegzistuoja\n");

}

    cmax --;
    int index2 = x;
    for(int i = index2;  i<cmax;i++){
        arr[i] = arr[i+1];
    }

        // for(int i=0; i<cmax; i++){
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");

    // į) paprašo vartotoją įvesti du skaičius (x ir y), 
    // ir į masyvą įterpia naują elementą su reikšme y, taip, kad po įterpimo jo
    // indeksas būtų x

    printf("Prasome ivesti pirma skaiciu - indeksa: ");

    while(1){

    scanf("%d", &x);
    
    //validavimas
    int tinka =1;     
    while(getchar() != '\n') tinka=0;

    //jei yra raidziu tai buferi istrinam ir pasakom netinka
    if(tinka == 0){
        printf("irasykite tik sveikus skaicius\n");
    }
    
    //main logic
    else if(x<=cmax && x>=0)break;
    else printf("toks indeksas masyve neegzistuoja\n");

}

    printf("Prasome ivesti antra skaiciu - reiksme: ");

    while(1){

        scanf("%d", &y);
        
        //validavimas
        int tinka =1;     
        while(getchar() != '\n') tinka=0;

        //jei yra raidziu tai buferi istrinam ir pasakom netinka
        if(tinka == 0){
            printf("irasykite tik sveikus skaicius\n");
        }
        
        else if(y> INT_MIN && y<INT_MAX)break;
        else printf("toks skaicius netinkamas\n");

    }

    cmax++;
    for(int i=cmax; i>x; i--){
        arr[i] = arr[i-1];
    }
    arr[x] =y;

    // j) atspausdina visą masyvą į ekraną

    for(int i=0; i<cmax; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}