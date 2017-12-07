#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Vorbereitung

//Aufgabe 1: Entfernung zweier Punkte

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


//Aufgabe 2: Länge eines Vektors und Winkel zur x-Achse

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


        printf("Bitte # eingeben fuer Programmende:");

        //fflush(stdout);

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

//Aufgabe 5: Sieb des Erathosthenes


void set_flag_v1(unsigned int flag_number, void *adr);

void clear_flag_v1(unsigned int flag_number, void *adr);

int test_flag_v1(unsigned int flag_number, void *adr);


int main5V() {

    int f[250000];

    int NMAX = sizeof(f), t;


    unsigned int n, i, j;

    while (1) {

        printf("Bitte eine positive ganze Zahl eingeben:");
        scanf("%u", &n);

        if (n == 0) {

            printf("\nProgrammende!");

            return 0;

        } else {

            if (n <= NMAX) {

                i = 1;

                while (i <= n) {

                    set_flag_v1(i, f);

                    i++;
                }

                i = 2;

                while (i <= n) {

                    j = 2;

                    while (j <= (n / i)) {

                        clear_flag_v1(i * j, f);

                        j++;
                    }

                    i++;
                }

                i = 2;

                while (i <= n) {

                    t = test_flag_v1(i, f);

                    if (t == 1) {

                        printf("%d ist eine Primzahl\n", i);

                    }

                    i++;
                }
            }
        }

    }
}


//Aufgabe 6: LED-Display

void print_pixel(unsigned int pixel_number, void *adr);

void toggle_pixel_v2(unsigned int pixel_number, void *adr);


int main6V() {

    int i;

    int iFeld[] = {0, 536870912, 949880764, 1109556263, -1874190200,
                   -1138670526, 658023144, -2008938372, 1108609568,
                   129884292, 1172389022, 8, 0, 0};

    for (i = 1; i <= 420; i++) {

        print_pixel(i, iFeld);

        if (i % 60 == 0) printf("\n");
    }

    for (i = 1; i <= 420; i++) toggle_pixel_v2(i, iFeld);

    for (i = 1; i <= 420; i++) {

        print_pixel(i, iFeld);

        if (i % 60 == 0) printf("\n");
    }

    return 0;
}

//Labor

//Aufgabe 1: Dreiecksspezifikation

struct TRIANGLE {

    struct POINT p1;

    struct POINT p2;

    struct POINT p3;

    double seite_lang;

    double seite_mittel;

    double seite_kurz;

    int typ;
};

void print_triangle(struct TRIANGLE *t);

void read_triangle(struct TRIANGLE *t);

void calculate_triangle(struct TRIANGLE *t);

void triple_sort(double *l1l1, double *ll11, double *l11l);

void main1L() {

    struct TRIANGLE T;

    char c;

    while (1) {

        printf("Bitte # eingeben fuer Programmende: ");

        fflush(stdin);

        scanf("%c", &c);

        if (c == '#') {

            break;
        }

        fflush(stdin);

        read_triangle(&T);

        calculate_triangle(&T);

        print_triangle(&T);
    }

    printf("Ende des Programms\n");
}


//Aufgabe 2: Sieb des Erathostenes mit malloc


int main2L() {

    int t;

    char c;

    void *f;

    unsigned int n, i, j;

    while (1) {

        printf("\nBitte geben Sie eine positive ganze Zahl ein:");
        scanf("%u", &n);

        printf("Es werden %d Bytes vom Betriebssystem angefordert.\n",  n);

        f = malloc(n);

        if (f == NULL) {

            printf("Neuen Wert für Obergrenze eingeben\n");

            continue;

        } else {


            printf("Allokation erfolgreich\n");
        }


        if (n == 0) {

            printf("\nProgrammende!");

            return 0;

        } else {

            i = 1;

            while (i <= n) {

                set_flag_v1(i, f);

                i++;
            }

            i = 2;

            while (i <= n) {

                j = 2;

                while (j <= (n / i)) {

                    clear_flag_v1(i * j, f);

                    j++;
                }

                i++;
            }

            i = 2;

            printf("Bitte s für Ausgabe eingeben:");

            fflush(stdin);

            scanf("%c", &c);

            if (c == 's') {


                while (i <= n) {

                    t = test_flag_v1(i, f);

                    if (t == 1) {


                        printf(" %d ist eine Primzahl\t", i);
                    }

                    i++;
                }

                free(f);


            }
        }

    }
}



//Aufgabe 3: Sieb des Erathostenes mit Bit-Shift

    void set_flag_v2(unsigned int flag_number, void *adr);

    void clear_flag_v2(unsigned int flag_number, void *adr);

    int test_flag_v2(unsigned int flag_number, void *adr);

    int main() {

        int t;

        char c;

        void *f;

        unsigned int n, i, j;

        while (1) {

            printf("\nBitte geben Sie positive ganze Zahl ein:");
            scanf("%u", &n);

            printf("Es werden %d Bytes vom Betriebssystem angefordert.\n", ((n + 7) / 8));

            f = malloc(((n + 7) / 8));

            if (f == NULL) {

                printf("Neuen Wert für Obergrenze eingeben\n");

                continue;

            } else {


                printf("Allokation erfolgreich\n");
            }


            if (n == 0) {

                printf("\nProgrammende!");

                return 0;

            } else {


                    i = 1;

                    while (i <= n) {

                        set_flag_v2(i, f);

                        i++;
                    }

                    i = 2;

                    while (i <= n) {

                        j = 2;

                        while (j <= (n / i)) {

                            clear_flag_v2(i * j, f);

                            j++;
                        }

                        i++;
                    }

                    i = 2;

                    printf("Bitte return für Ausgabe eingeben:\n");

                    fflush(stdin);

                    scanf("%c", &c);

                    if (c == '\n') {


                        while (i <= n) {

                            t = test_flag_v2(i, f);

                            if (t == 1) {


                                printf(" %d ist eine Primzahl\t", i);

                                i++;


                            } else {

                                i++;
                            }
                        }

                        free(f);
                }

            }
        }

    }






//Funktionen

//Funktion grad aus Versuch 3

    double grad(double rad) {

        return (rad * 45.) / atan(1.);
    }

//Funktion: Vorbereitungsaufgabe 1: Entfernung zweier Punkte

    double distance_of_points(struct POINT p1, struct POINT p2) {

        double xk, yk;

        xk = p1.x - p2.x;

        yk = p1.y - p2.y;

        return sqrt(pow(xk, 2) + pow(yk, 2));


    }

//Funktion Vorbereitungsaufgabe 2: print_segment

    void print_segment(struct SEGMENT s) {

        printf("\n--> Die Strecke verbindet die Punkte"
                       " (%.2lf,%.2lf) und (%.2lf,%.2lf);\n"
                       "--> Sie hat eine Laenge von %.4lf;\n"
                       "--> Der Winkel betraegt: %.2lf Grad.\n\n",

               s.p1.x, s.p1.y, s.p2.x, s.p2.y, s.length, s.angle);
    }


//Funktion Vorbereitungsaufgabe 2 Vorbereitung: read_segment

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

//Funktion Vorbereitungsaufgabe 2: calculate_segment_v1

    struct SEGMENT calculate_segment_v1(struct SEGMENT s) {

        double x, y;

        x = s.p2.x - s.p1.x;

        y = s.p2.y - s.p1.y;

        s.length = distance_of_points(s.p1, s.p2);

        s.angle = grad(atan2(y, x));

        return s;

    }

//Funktion Vorbereitungsaufgabe 3: read_segment_v2

    void read_segment_v2(struct SEGMENT *s) {

        printf(">> Bitte Koordinaten x,y des ersten"
                       " Punktes der Strecke eingeben: ");

        scanf("%lf %lf", &s->p1.x, &s->p1.y);

        printf(">> Bitte Koordinaten x,y des zweiten"
                       " Punktes der Strecke eingeben: ");

        scanf("%lf %lf", &s->p2.x, &s->p2.y);


    }

//Funktion Vorbereitungsaufgabe 3: calculate_segment_v2

    void calculate_segment_v2(struct SEGMENT *s) {

        double x, y;

        x = (s->p2.x) - (s->p1.x);

        y = (s->p2.y) - (s->p1.y);

        s->length = distance_of_points(s->p1, s->p2);

        s->angle = grad(atan2(y, x));

    }


//Funktion Vorbereitaungsaufgabe 5: set_flag

    void set_flag_v1(unsigned int flag_number, void *adr) {
        char *pc = (char *) adr; // Zeiger-Konvertierung

        pc[flag_number - 1] = 1;
    }

//Funktion  Vorbereitungsaufgabe 5: clear_flag

    void clear_flag_v1(unsigned int flag_number, void *adr) {
        char *pc = (char *) adr; // Zeiger-Konvertierung

        pc[flag_number - 1] = 0;
    }

//Funktion Vorbereitungsaufgabe 5: test_flag

    int test_flag_v1(unsigned int flag_number, void *adr) {

        char *pc = (char *) adr; // Zeiger-Konvertierung

        if (pc[flag_number - 1]) {


            return 1;

        } else {

            return 0;
        }
    }


//Funktion Vorbereitungsaufgabe 6: printf_pixel

    void print_pixel(unsigned int pixel_number, void *adr) {

        char *pc = (char *) adr;

        int ioff = (pixel_number - 1) / 8;

        int ibit = (pixel_number - 1) % 8;

        if (pc[ioff] & (1 << ibit)) {


            printf("#");
        } else {

            printf(" ");

        }
    }

//Funktion Vorbereitungsaufgabe 6: toggle_pixel_v2

    void toggle_pixel_v2(unsigned int pixel_number, void *adr) {

        char *pc = (char *) adr;

        int ioff = (pixel_number - 1) / 8;

        int ibit = (pixel_number - 1) % 8;

        pc[ioff] ^= (1 << ibit);
    }


//Funktion Laboraugabe 1: print_triangle

    void print_triangle(struct TRIANGLE *t) {
        printf("--> Das Dreick hat die Eckpunkte: "
                       "(%.2f,%.2f) (%.2f,%.2f) (%.2f,%.2f)\n"
                       "--> Die Seitenlaengen (laengste zuerst) sind: "
                       "%.4f %.4f %.4f\n",
               t->p1.x, t->p1.y, t->p2.x, t->p2.y, t->p3.x, t->p3.y,
               t->seite_lang, t->seite_mittel, t->seite_kurz
        );
        if (t->typ == 1) printf("--> Das Dreieck ist spitzwinklig\n");
        else if (t->typ == 2) printf("--> Das Dreieck ist rechtwinklig\n");
        else if (t->typ == 3) printf("--> Das Dreieck ist stumpfwinklig\n");
        else printf("--> Dreieck noch nicht berechnet\n");
    }


//Funktion Laboraufgabe 1: read_triangle

    void read_triangle(struct TRIANGLE *t) {
        printf(">> Bitte Koordinaten x,y des ersten Punktes"
                       " des Dreiecks eingeben: ");
        scanf("%lf%lf", &t->p1.x, &t->p1.y);

        printf(">> Bitte Koordinaten x,y des zweiten Punktes"
                       " des Dreiecks eingeben: ");
        scanf("%lf%lf", &t->p2.x, &t->p2.y);

        printf(">> Bitte Koordinaten x,y des dritten Punktes"
                       " des Dreiecks eingeben: ");
        scanf("%lf%lf", &t->p3.x, &t->p3.y);
    }

//Funktion Laboraufgabe 1: triple_sort

    void triple_sort(double *l1l1, double *ll11, double *l11l)

/* Diese Funktion erhält als Parameter die Adressen von 3
double-Variablen. Die 3 double-Werte werden so umsortiert, dass am
Ende die erste Adresse auf den größten und die 3. Adresse auf den
kleinsten Wert zeigt */

    {
        double l111;
        if (*l1l1 < *l11l)
            if (*l1l1 < *ll11)
                if (*ll11 < *l11l) {
                    l111 = *l1l1;
                    *l1l1 = *l11l;
                    *l11l = l111;
                } else {
                    l111 = *l1l1;
                    *l1l1 = *ll11;
                    *ll11 = *l11l;
                    *l11l = l111;
                }
            else {
                l111 = *l11l;
                *l11l = *ll11;
                *ll11 = *l1l1;
                *l1l1 = l111;
            }
        else if (*l1l1 < *ll11) {
            l111 = *l1l1;
            *l1l1 = *ll11;
            *ll11 = l111;
        } else if (*ll11 < *l11l) {
            l111 = *ll11;
            *ll11 = *l11l;
            *l11l = l111;
        } else { ; }
    }

//Funktion Laboraufgabe 1: calculate_triangle

    void calculate_triangle(struct TRIANGLE *t) {

        double a, b, c;

        a = distance_of_points(t->p1, t->p2);

        b = distance_of_points(t->p1, t->p3);

        c = distance_of_points(t->p2, t->p3);

        triple_sort(&c, &b, &a);

        t->seite_lang = c;

        t->seite_mittel = b;

        t->seite_kurz = a;


        if (fabs(c - (sqrt(pow(a, 2) + pow(b, 2))) <= 1.0e-8)) {

            t->typ = 2;
        }

        if ((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b) < 0.) {

            t->typ = 3;

        } else {

            t->typ = 1;
        }

    }

//Funktion Laboraufgabe 3 : setf_lag_v2

    void set_flag_v2(unsigned int flag_number, void *adr) {

        char *pc = (char *) adr;

        int ioff = (flag_number - 1) / 8;

        int ibit = (flag_number - 1) % 8;

        pc[ioff] |= (1 << ibit);
    }


//Funktion Laboraufgabe 3: clear_flag_v2

    void clear_flag_v2(unsigned int flag_number, void *adr) {

        char *pc = (char *) adr;

        int ioff = (flag_number - 1) / 8;

        int ibit = (flag_number - 1) % 8;

        pc[ioff] &= ~(1 << ibit);


    }

//Funktion Laboraufgabe 3: test_flag_v2

    int test_flag_v2(unsigned int flag_number, void *adr) {

        char *pc = (char *) adr;

        int ioff = (flag_number - 1) / 8;

        int ibit = (flag_number - 1) % 8;

        if (pc[ioff] & (1 << ibit)) {


            return 1;


        } else {

            return 0;
        }


    }