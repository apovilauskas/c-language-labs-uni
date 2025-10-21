#include <stdio.h>

#define cmax 50
typedef char string[cmax];

typedef struct{
    int metai;
    string vardas;
    string charakteris; //gera bloga
    string isvaizda; 

} mergyte;

int main() {
 
    string words[cmax] = {"good" , "girl"};
    
    for(int i=0; i<2; ++i){
        printf("%s ", words[i]);
    }
    printf("\n");

    string words3d[cmax][cmax] = {{"cute", "hot"},{"good", "girl"}, {"bad", "boy"}, };
    
    for(int i=0; i<3; i++){
        for(int j=0; j<2; ++j){
            printf("%s ", words3d[i][j]);
        }
    }


    return 0;
}
