// Vartotojas įveda tris natūraliuosius skaičius (a, b, c). 
// Programa turi atspausdinti du skaičius - šių trijų skaičių
// didžiausią bendrąjį daliklį (DBD) 
// bei mažiausiąjį bendrą kartotinį (MBK)

#include <stdio.h>
#include <math.h>

int main(){

    int a, b, c;
    printf("Iveskite tris naturaliuosius skaicius\n");
    scanf("%d %d %d", &a, &b, &c);

    int dbd=-1;
    for(int i=a; i>0; i--){
        if(a%i == 0 && b%i==0 && c%i==0){
            dbd = i;
            break;
        }
    }

    int a1=a, b1=b, c1=c;
    int mbk=1;
    while(1){
        if(a == b && a ==c){
            mbk = a;
            break;
        }
        if(a<=b && a <=c) a+=a1;
        else if(a>=b && b <=c) b+=b1;
        else if(a>=c && c <=b) c+=c1;
    }

   printf("DBD = %d, MBK = %d\n", dbd, mbk);


    return 0;
}