#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

typedef struct elementas{
    int verte;
    struct elementas* kitas;

}elementas;

void trumpinti(elementas* dabartinis);

void spausdinti(elementas *dabartinis);

void sunaikinti(elementas **dabartinis);

void prideti(int reiksme, elementas **pirmas);


#endif