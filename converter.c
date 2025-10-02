#include <stdio.h>
#include <math.h>

int main() {
    
    //binary -> decimal
{
    char binary[] = "11001011010101";

    int sum=0;
    int size = sizeof(binary)-1;
    int power = size-1;
    for(int i=0; i<size; i++){
        int digit = binary[i]-'0';
        sum+= digit* (pow(2,power));
        power--;
        
    }

    printf("%d \n", sum);
}
    //decimal -> binary
{
    int decimal = 75;
    char res[100];
    int i=0;
    while(decimal != 0){
        
        res[i] = decimal%2 + '0';
        decimal /= 2;
        i++;
    }
    for(int k=i-1; k>=0; k--){
        printf("%d", res[k]);
    }
    printf("\n");
}

    //hex -> decimal
{
    char hexnum[] = "23E";
    char hex[] = {"0123456789ABCDEF"};
    int sum=0;
    int size = sizeof(hexnum)-1;
    int power = size-1;
    for(int i=0; i<size; i++){
        for(int j=0; j<16; j++){
            if(hexnum[i] == hex[j]){
                sum += j * (pow(16, power));
                power--;
            }
        }
    }
    printf("%d \n", sum);
}

    //decimal -> hex

    int  dec = 894;
        //printf("0x%X\n", dec);
    char hex[] = "0123456789ABCDEF";
    int maxsize=100;
    char res[maxsize];
    int i=maxsize-1;
    res[i]='\0';
    i--;
    while(dec != 0){
        res[i] = hex[dec%16];
        i--;
        dec/=16;
    }
    printf("%s\n", &res[i+1]);

    return 0;
}