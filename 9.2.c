#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int *arr; 
}Stack;

void initStack(Stack *stack){
    stack->size = 0;
    stack->arr = NULL;
}

void printStack(Stack *stack){
    for(int i=0; i<stack->size; i++){
        printf("%d ", stack->arr[i]);
    }
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, int value){
    stack->arr = (int*)realloc(stack->arr, (stack->size +1) * sizeof(int));
    stack->arr[stack->size]=value;
    stack->size ++;
}

int top(Stack *stack){
    if(stack->size > 0)return stack->arr[stack->size -1];
    return 0; //tuscias
}

//normally pop doesnt return anything, this time its an exception
int pop(Stack *stack){
    if(stack->size == 0)return 0;

    int grazinti= top(stack);
    stack->size--;
    stack->arr = (int*)realloc(stack->arr, stack->size * sizeof(int));
    return grazinti;
}

void destroyStack(Stack *stack){
    free(stack->arr);
    stack->arr = NULL;
    stack->size=0;
}


int main() {
        
    
    return 0;
}