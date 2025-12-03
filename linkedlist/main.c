#include <stdio.h>
#include <stdlib.h>
#include "funkcijos.h"

int main() {
    
    elementas *pirmas = NULL;
    
    prideti(1, &pirmas);
    prideti(2, &pirmas);
    prideti(2, &pirmas);
    prideti(2, &pirmas);
    prideti(3, &pirmas);

    spausdinti(pirmas);
    trumpinti(pirmas);
    spausdinti(pirmas);
    sunaikinti(&pirmas);
    
    return 0;
}