#include <stdio.h>
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

int main() {
    
    double distance = getDistance(createPoint(2, -3),createPoint(-4, 5));
    //printf(".2%lf", distance);

    return 0;
}
