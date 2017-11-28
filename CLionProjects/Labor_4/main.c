#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Aufgabe 1 Vorbereitung: Entfernung zweier Punkte

struct point {

    double x;
    double y;
};


double distance_of_points(struct point p1, struct point p2);

int main() {


    struct point x = {1., 1.}, y = {2., 2.}, z = {-2., -1.};

    printf("Die Entfernung von x und y betraegt: %.2lf\n", distance_of_points(x, y));

    printf("Die Entfernung von x und z betraegt: %.2lf\n", distance_of_points(x, z));

    printf("Die Entfernung von x und y betraegt: %.2lf\n", distance_of_points(z, y));

    return 0;
}


//Funktionen

//Funktion Aufgabe 1 Vorbereitung: Entfernung zweier Punkte

double distance_of_points(struct point p1, struct point p2) {

    double xk, yk;

    xk = p1.x - p2.x;

    yk = p1.y - p2.y;

    return sqrt(pow(xk, 2) + pow(yk, 2));


}
