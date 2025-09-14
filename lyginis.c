#include <stdio.h>

int main() {
    
    printf("Irasykite skaiciu: ");
    int sk;
    scanf("%d",&sk);

    printf("skaicius yra %s", sk%2 == 0 ? "lyginis" : "nelyginis");

    return 0;
}