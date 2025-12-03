#include <stdio.h>
#include <stdlib.h>
#include "funkcijos.h"

void trumpinti(elementas* dabartinis) {
    while (dabartinis != NULL && dabartinis->kitas != NULL) {
        if (dabartinis->verte == dabartinis->kitas->verte) {
            
            elementas* salintinas = dabartinis->kitas; // antro salinimas
            dabartinis->kitas = salintinas->kitas; 
            free(salintinas);
            
        } else {
            dabartinis = dabartinis->kitas;
        }
    }
}

void spausdinti(elementas *dabartinis){
    while (dabartinis != NULL) {
        printf("%d ", dabartinis->verte);
        dabartinis = dabartinis->kitas;
    }
    printf("\n");
}

void sunaikinti(elementas **dabartinis){
    while(*dabartinis != NULL){
        elementas *naikinimui = *dabartinis;
        *dabartinis = (*dabartinis) -> kitas;
        free(naikinimui);
    }
}

void prideti(int reiksme, elementas **pirmas){
    elementas *naujas = (elementas*)malloc(sizeof(elementas));
    naujas->verte = reiksme;
    naujas->kitas = *pirmas;
    *pirmas = naujas;
}