// Apibrėžkite funkciją swap, kuri moka sukeisti dviejų 
// (tai funkcijai perduodamų) kintamųjų (sveikųjų skaičių) reikšmes
// vietomis, taip, kad apkeitimas vyktų funkcijoje, o efektas liktų 
// galioti ne tik funkcijoje, bet ir už jos ribų.

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}

int main() {
    
    int num1 = 5, num2 =7;
    swap(&num1, &num2);
    
    return 0;
}