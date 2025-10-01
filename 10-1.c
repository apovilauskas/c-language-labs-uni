#include <stdio.h>

void maxx(int sk1, int sk2, int *ats){
    if(sk1>sk2) *ats = sk1;
    else *ats = sk2;
}

int main(){

    int sk1=5, sk2=8;
    int ats;

    maxx(sk1, sk2, &ats);
    printf("Didesnis skaicius yra %d", ats);

    return 0;
}