#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

void printPoint(Point p){
    printf("%.2lf, %.2lf", p.x, p.y);
}

Point createPoint(double x, double y){
    Point pt = {x,y};
    return pt;
}

double getDistance(Point a, Point b){
   return sqrt(pow(b.x - a.x, 2)+pow(b.y - a.y, 2));
}

typedef struct{
    int size;
    Point *arr; 
}Stack;

void initStack(Stack *stack){
    stack->size = 0;
    stack->arr = NULL;
}

void printStack(Stack *stack){
    for(int i=0; i<stack->size; i++){
        double length = sqrt(pow(stack->arr[i].x, 2)+pow(stack->arr[i].y, 2)); //length from 0;0 coordinate using pythagorean
        printf("%.1lf %.1lf %.1lf \n", stack->arr[i].x, stack->arr[i].y, length);
    }
}

int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, Point pt){
    stack->arr = (Point*)realloc(stack->arr, (stack->size +1) * sizeof(Point));
    stack->arr[stack->size].x=pt.x;
    stack->arr[stack->size].y=pt.y;
    stack->size++;
}

Point top(Stack *stack){
    if(stack->size > 0)return stack->arr[stack->size -1];
    Point p ={0, 0}; //EMPTY 
    return p;
}

//normally pop doesnt return anything, this time its an exception
Point pop(Stack *stack){
    if(stack->size == 0){
        Point p = {0, 0};
        return p;
    }

    Point ret= top(stack);
    stack->size--;
    stack->arr = (Point*)realloc(stack->arr, stack->size * sizeof(Point));
    return ret;
}

void destroyStack(Stack *stack){
    free(stack->arr);
    stack->arr = NULL;
    stack->size=0;
}


int main() {
    Stack *stack;
    initStack(stack);

    push(stack, createPoint(3.33, 4.2));
    push(stack, createPoint(-3.5, -4));
    push(stack, createPoint(1.3, 2.4));
    push(stack, createPoint(3.2, 4.3));
    push(stack, createPoint(31, 14));
    
    printStack(stack);
    destroyStack(stack);

    return 0;
}