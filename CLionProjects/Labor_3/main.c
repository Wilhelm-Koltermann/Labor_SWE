#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Vorbereitung


//Aufgabe1:Winkel und Seiten eines Dreickes nach Kosinus- und Sinussatz
//Bib: stdio,math


void triangle_1(double a, double b, double gamma, double *c, double *alpha, double *beta);

int main1V() {

    int i, anz;
    double a, b, c, alpha, beta, gamma;

    printf("Wie viele Dreiecke sollen berechnet werden?");
    scanf("%d", &anz);

    for (i = 1; i <= anz; i++) {

        printf("Dreieck %d: Bitte a, b und gamma eingeben:", i);
        scanf("%lf %lf %lf", &a, &b, &gamma);

        triangle_1(a, b, gamma, &c, &alpha, &beta);

        printf("--> a,b,c: %.1lf %.1lf %.1lf; gegenueber liegende Winkel: %.1lf %.1lf %.1lf\n", a, b, c, alpha, beta,
               gamma);


    }

    printf("\nEnde des Programms keine - weiteren Eingaben erforderlich");

    return 0;
}


//Aufgabe 2: Ausgabe von Zufallszahlen und Berechnung ihres Mittelwertes
//Bib stdllib,stdio


double gp_zufall(double dmax);

double mittelwert(double dFeld[], int iAnz);

int main2V() {

    int iAnz, i;
    double dfeld[1000];

    srand(123);

    while (1) {


        printf("Bitte Anzahl eingeben:");
        scanf("%d", &iAnz);


        if (iAnz > 0) {

            if (iAnz < 10001) {

                printf("Die %d Zufallswerte lauten:\n", iAnz);

                for (i = 0; i < iAnz; i++) {

                    dfeld[i] = gp_zufall(100.);

                    printf("%d: %lf\n", i + 1, dfeld[i]);

                }

                printf("Mittelwert: %lf\n", mittelwert(dfeld, iAnz));


            } else {

                printf("maximal mögliche Anzahl ist 1000\n");
            }

        } else {

            printf("\nProgramm-Ende: ungueltige Anzahl eingegeben");

            return 0;
        }


    }


}

//Test für Aufgabe 4: Zeichenkette vertauschen

void tausche_2(char *c1, char *c2);

void change_sequence_2(char f[]);

int main4V() {

    char f[] = {"``0L#@30\"C\"@OICK0HAC0%1AK%1C@I#@#0#IA0I@4"};

    change_sequence_2(f);

    printf("%s", f);


}


//Aufgabe 5: String einlesen und umdrehen

void change_sequence_1(char *F);

void tausche_1(char cFeld[], int idx1, int idx2);


int main5V() {

    char f[100];

    int ilang;

    while (1) {


        fflush(stdin);

        printf("Bitte geben Sie einen String ein:");

        fgets(f, 100, stdin);

        ilang = strlen(f);


        f[ilang - 1] = 0;


        if (ilang > 1) {

            printf("Eingegebener String: %s\n", f);

            change_sequence_1(f);

            printf("Umgedrehter String: %s\n", f);

        } else {

            printf("\nProgrammende\n");

            return 0;

        }
    }

}

//Laboraufgaben:

//Aufgabe 1: Dreiecksberechnungen wenn alle Seiten gegeben

double rad(double grad);

double grad(double rad);

void triangle_2(double a, double b, double c, double *alpha, double *beta, double *gamma, double *A, double *R);

int main() {

    int i, anz;
    double a, b, c, alpha, beta, gamma, A, R;

    printf("Wie viele Dreiecke sollen berechnet werden?");
    scanf("%d", &anz);

    for (i = 1; i <= anz; i++) {

        printf("Dreieck %d: Bitte a, b,c eingeben:", i);
        scanf("%lf %lf %lf", &a, &b, &c);

        triangle_2(a, b, c, &alpha, &beta, &gamma, &A, &R);

        printf("--> a,b,c: %.1lf %.1lf %.1lf; gegenueber liegende Winkel: %.1lf %.1lf %.1lf\n", a, b, c, alpha, beta,
               gamma);

        printf("\n---> Flaeche: %lf; Radius d. Umkreises: %lf\n", A, R);


    }

    printf("\nEnde des Programms keine - weiteren Eingaben erforderlich");

    return 0;
}

//Aufgabe 2: Standardabweichung

double standard_abw(double dFeld[], int anz, double mwert);

int main2L() {

    int iAnz, i;

    double dfeld[1000], mwert;

    srand(123);

    while (1) {


        printf("Bitte Anzahl eingeben:");
        scanf("%d", &iAnz);


        if (iAnz > 1) {

            if (iAnz < 1001) {

                printf("Es wurden %d Zufallszahlen erzeugt:\n", iAnz);

                for (i = 0; i < iAnz; i++) {

                    dfeld[i] = gp_zufall(100.);

                    //printf("%d: %lf\n", i + 1, dfeld[i]);

                }

                mwert = mittelwert(dfeld, iAnz);

                printf("Der Mittelwert betraegt: %lf\n", mwert);

                printf("Die Standardabweichung betraegt: %lf\n", standard_abw(dfeld, iAnz, mwert));


            } else {

                printf("maximal mögliche Anzahl ist 1000\n");
            }

        } else {

            printf("\nProgramm-Ende: ungueltige Anzahl eingegeben");

            return 0;
        }


    }


}


//Aufgabe 3: Decoding

void decode_string(char str[]);

int main3L() {

    char f[100];

    int ilang;

    fflush(stdin);

    printf("Bitte geben Sie einen String ein:");

    fgets(f, 100, stdin);

    ilang = strlen(f);

    f[ilang - 1] = 0;

    printf("Eingegebener String: %s\n", f);

    decode_string(f);

    printf("Dekodierter String: %s", f);

}




//Funktionen

//Funktion Aufgabe 1 Vorbereitung: Gradmaß --> Bogenmaß

double rad(double grad) {

    return (grad / 45.) * atan(1.);
}
//Funktion Aufgabe 1 Vorbereitung: Bogenmaß --> Gradmaß

double grad(double rad) {

    return (rad * 45.) / atan(1.);
}

//Funktion Aufgabe 1 Vorbereitung: Berechnung von alpha,beta und c

void triangle_1(double a, double b, double gamma, double *c, double *alpha, double *beta) {

    double *p;

    p = &gamma;

    *p = rad(gamma);

    *alpha = rad(*alpha);

    *beta = rad(*beta);

    *c = sqrt((pow(a, 2) + pow(b, 2)) - (2 * a * b * cos(gamma)));

    *alpha = asin((sin(gamma) * a) / (*c));

    *beta = M_PI - (*alpha + gamma);

    *alpha = grad(*alpha);

    *beta = grad(*beta);

    *p = grad(gamma);
}

//Funktion Aufgabe 2 Vorbereitung: gp_zufall aus Vorbereitung 2

double gp_zufall(double dmax) {

    return dmax * ((double) rand() / (double) RAND_MAX); //Normierung der ausgegebenen Zufallszahl und Anpassen an Intervall
}

//Funktion Aufgabe 2 Vorbereitung: errechnet Mittelwert

double mittelwert(double dFeld[], int iAnz) {

    int i;

    double sum=0.;

    for (i = 0; i < iAnz; i++) {

        sum += dFeld[i];
    }

    return sum / iAnz;
}


//Funktion Augabe 4: change_sequence_2

void change_sequence_2(char *f) {

    int i, j;

    char *c1, *c2;

    j = strlen(f) - 1;

    for (i = 0; i < j; i++) {

        c1 = f + i;
        c2 = f + j;

        tausche_2(c1, c2);

        j--;
    }
}




//Funktion Aufgabe 4: tausche_2


void tausche_2(char *c1, char *c2) {

    char temp;

    temp = *c1;

    *c1 = *c2;

    *c2 = temp;

}


//Funktion Aufgabe 5: change_sequence_1

void change_sequence_1(char *F) {

    int i, j;

    i = 0;

    j = strlen(F) - 1;

    while (i < j) {

        tausche_1(F, i, j);

        i = i + 1;

        j = j - 1;
    }
}

//Funktion Aufgabe 5: tausche_1

void tausche_1(char cFeld[], int idx1, int idx2) {

    char temp;

    temp = cFeld[idx1];

    cFeld[idx1] = cFeld[idx2];

    cFeld[idx2] = temp;
}


//Funktion Aufgabe 1 Labor: triangle_2

void triangle_2(double a, double b, double c, double *alpha, double *beta, double *gamma, double *A, double *R) {


    *alpha = acos(((((pow(b, 2) + pow(c, 2))) - pow(a, 2)) / (2 * b * c)));

    *beta = asin(b * sin(*alpha) / a);

    *gamma = M_PI - (*alpha + *beta);

    *A = (a * b * sin(*gamma)) / 2;

    *R = (a * b * c) / (4 * (*A));

    *alpha = grad(*alpha);

    *beta = grad(*beta);

    *gamma = grad(*gamma);
}


//Funktion Aufgabe 2: Standardabweichung

double standard_abw(double dFeld[], int anz, double mwert) {

    int i;

    double sum = 0.;

    for (i = 0; i < anz; i++) {

        sum += pow((dFeld[i] - mwert), 2);
    }

    return sqrt((sum / (double) (anz - 1)));

}


//Funktion Aufgabe 3: decode string

void decode_string(char str[]) {

    int i, Index1, Index2, Decode[] = {62, 94, 82, 84, 55, 72, 22, 4, 59, 33, 14, 88, 42, 31, 74, 20, 0, 67, 7, 51, 36,
                                       61, 21, 89, 93, 63, 30, 92, 19, 29, 45, 70, 65, 73, 24, 69, 50, 85, 6, 54, 78,
                                       83, 44, 76, 90, 57, 56,
                                       66, 23, 77, 27, 3, 53, 40, 18, 48, 28, 32, 37, 15, 34, 25, 2, 10, 1, 91, 68, 64,
                                       16, 12, 60, 41, 79, 9,
                                       8, 52, 49, 13, 11, 81, 71, 5, 46, 38, 58, 26, 47, 80, 86, 43, 87, 39, 75, 17,
                                       35};

    change_sequence_2(str);

    for (i = 0; i < strlen(str); i++) {


        if ((str[i] < 0x20) || (str[i] > 0x7E)) {

            continue;

        } else {

            Index1 = (int) str[i] - 0x20;

            Index2 = Decode[Index1];

            str[i] = (char) (Index2 + 0x20);

        }


    }


}
