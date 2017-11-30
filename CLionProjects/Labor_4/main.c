#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Aufgabe 1 Vorbereitung: Entfernung zweier Punkte

struct POINT {

    double x;
    double y;
};


double distance_of_points(struct POINT p1, struct POINT p2);

int main1V() {


    struct POINT x = {1., 1.}, y = {2., 2.}, z = {-2., -1.};

    printf("Die Entfernung von x und y betraegt: %.2lf\n", distance_of_points(x, y));

    printf("Die Entfernung von x und z betraegt: %.2lf\n", distance_of_points(x, z));

    printf("Die Entfernung von x und y betraegt: %.2lf\n", distance_of_points(z, y));

    return 0;
}


//Aufgabe 2 Vorbereitung

struct SEGMENT calculate_segment_v1(struct SEGMENT s);

void print_segment(struct SEGMENT s);

struct SEGMENT read_segment_v1();

struct SEGMENT {

    struct POINT p1;
    struct POINT p2;
    double length;
    double angle;
};


int main2V() {

    struct SEGMENT S;

    char c;

    double l;

    while (1) {


        printf("Bitte # eingeben fuer Programmende: ");

        fflush(stdin);

        scanf("%c", &c);

        if (c == '#') break;

        S = read_segment_v1();

        S = calculate_segment_v1(S);

        print_segment(S);
    }

    printf("\nEnde des Programms\n");

    return 0;
}

//Aufgabe 3: Aufgabe 2 auf andere Weise

void read_segment_v2(struct SEGMENT *s);

void calculate_segment_v2(struct SEGMENT *s);

int main3V() {

    struct SEGMENT S;

    char c;

    double l;

    while (1) {


        printf("Bitte # eingeben fuer Programmende: ");

        fflush(stdin);

        scanf("%c", &c);

        if (c == '#') break;

        read_segment_v2(&S);

        calculate_segment_v2(&S);

        print_segment(S);
    }

    printf("\nEnde des Programms\n");

    return 0;
}

//Aufgabe 5:

void set_flag_v1(unsigned int flag_number, void *adr);

void clear_flag_v1(unsigned int flag_number, void *adr);

int test_flag_v1(unsigned int flag_number, void *adr);


int main(){

    char f[1000000];

    int NMAX= 8*sizeof(f);
}



//Funktionen

//Funktion grad aus Versuch 3

double grad(double rad) {
    return (rad * 45.) / atan(1.);
}

//Funktion Aufgabe 1 Vorbereitung: Entfernung zweier Punkte

double distance_of_points(struct POINT p1, struct POINT p2) {

    double xk, yk;

    xk = p1.x - p2.x;

    yk = p1.y - p2.y;

    return sqrt(pow(xk, 2) + pow(yk, 2));


}

//Funktion Aufgabe 2 Vorbereitung: print_segment

void print_segment(struct SEGMENT s) {

    printf("\n--> Die Strecke verbindet die Punkte"
                   " (%.2lf,%.2lf) und (%.2lf,%.2lf);\n"
                   "--> Sie hat eine Laenge von %.4lf;\n"
                   "--> Der Winkel betraegt: %.2lf Grad.\n\n",

           s.p1.x, s.p1.y, s.p2.x, s.p2.y, s.length, s.angle);
}


//Funktion Aufgabe 2 Vorbereitung: read_segment

struct SEGMENT read_segment_v1() {

    struct SEGMENT s;


    printf("\n>> Bitte Koordinaten x,y des ersten"
                   " Punktes der Strecke eingeben: ");


    scanf("%lf %lf", &s.p1.x, &s.p1.y);


    printf(">> Bitte Koordinaten x,y des zweiten"
                   " Punktes der Strecke eingeben: ");


    scanf("%lf %lf", &s.p2.x, &s.p2.y);


    return s;
}

//Funktion Aufgabe 2 Vorbereitung: calculate_segment_v1

struct SEGMENT calculate_segment_v1(struct SEGMENT s) {

    double x, y;

    x = s.p2.x - s.p1.x;

    y = s.p2.y - s.p1.y;

    s.length = distance_of_points(s.p1, s.p2);

    s.angle = grad(atan2(y, x));

    return s;

}

//Funktion Aufgabe 3: read_segment_v2

void read_segment_v2(struct SEGMENT *s) {

    printf(">> Bitte Koordinaten x,y des ersten"
                   " Punktes der Strecke eingeben: ");

    scanf("%lf %lf", &s->p1.x, &s->p1.y);

    printf(">> Bitte Koordinaten x,y des zweiten"
                   " Punktes der Strecke eingeben: ");

    scanf("%lf %lf", &s->p2.x, &s->p2.y);


}

//Funktion Aufgabe 3: calculate_segment_v2

void calculate_segment_v2(struct SEGMENT *s) {

    double x, y;

    x = (s->p2.x) - (s->p1.x);

    y = (s->p2.y) - (s->p1.y);

    s->length = distance_of_points(s->p1, s->p2);

    s->angle = grad(atan2(y, x));

}


//Funktion Aufgabe 5: set_flag

void set_flag_v1(unsigned int flag_number, void *adr) {
    char *pc = (char *) adr; // Zeiger-Konvertierung

    pc[flag_number - 1] = 1;
}

//Funktion 5: clear_flag

void clear_flag_v1(unsigned int flag_number, void *adr) {
    char *pc = (char *) adr; // Zeiger-Konvertierung

    pc[flag_number - 1] = 0;
}

//Funktion: test_flag

int test_flag_v1(unsigned int flag_number, void *adr) {

    char *pc = (char *) adr; // Zeiger-Konvertierung

    if (pc[flag_number - 1]) {


        return 1;

    } else {

        return 0;
    }
}