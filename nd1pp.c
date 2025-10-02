#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  
int num;
int count =0;

printf("irasykite skaiciu aibe, baigti spauskit 0 \n");

while(1){

    scanf("%d", &num);
    
    //validavimas
    int tinka =1;     
    while(getchar() != '\n') tinka=0;

    //jei yra raidziu tai buferi istrinam ir pasakom netinka
    if(tinka == 0){
        printf("irasykite tik sveikus skaicius\n");
    }
    
    //main logic
    else if(num == 0)break;
    else if(num%2 != 0 && num<0)count ++;

}

printf("%d", count);

    return 0;
}