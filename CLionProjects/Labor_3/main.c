#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Aufgabe1:Winkel und Seiten eines Dreickes nach Kosinus- und Sinussatz
//Bib: stdio,math

double rad(double grad);

double grad(double rad);

void triangle_1(double a, double b, double gamma, double *c, double *alpha, double *beta);

int main1V() {

    int i, anz;
    double a, b, c, alpha, beta, gamma;

    printf("Wie viele Dreiecke sollen berechnet werden?");
    scanf("%d", &anz);

    for (i = 1; i <= anz; i++) {

        printf("Dreieck %d: Bitte a, b und gamma eingeben:", i);
        scanf("%lf %lf %lf", &a, &b, &gamma);

        gamma = rad(gamma);


        triangle_1(a, b, gamma, &c, &alpha, &beta);

        printf("--> a,b,c: %.1lf %.1lf %.1lf; gegenueber liegende Winkel: %.1lf %.1lf %.1lf\n", a, b, c, grad(alpha),
               grad(beta), grad(gamma));


    }

}


//Aufgabe 2: Ausgabe von Zufallszahlen und Berechnung ihres Mittelwertes

double gp_zufall(double dmax);

double mittelwert(double dFeld[], int iAnz);

int main2V() {

    int iAnz;
    double dfeld[1000];

    srand(123);

    while (1) {


        printf("Bitte Anzahl eingeben:");
        scanf("%d", &iAnz);

        printf("Die %d Zufallswerte lauten:\n", iAnz);

        if (iAnz > 0) {

            if (iAnz < 1000) {

                mittelwert(dfeld, iAnz);

            } else {

                printf("maximal mögliche Anzahl ist 1000\n");
            }

        } else {

            printf("Programm-Ende: ungueltige Anzahl eingegeben\n");

            return 0;
        }


    }


}

//Test für Aufgabe 4: Zeichenkette vertauschen

void tausche_2(char *c1, char *c2);

void change_sequence_2(char f[]);

int main4V() {

    char f[] = {"Wilhelm"};

    change_sequence_2(f);

    printf("%s", f);


}


//Aufgabe 5: String einlesen und umdrehen

void change_sequence_1(char *F);

void tausche_2(char *c1, char *c2);


int main() {

    char f[100];

    int ilang;

    while (1) {


        fflush(stdin);

        printf("Bitte geben einen String ein:");

        fgets(f, 100, stdin);

        ilang = strlen(f);

        f[ilang - 1] = 0;

        if ((ilang - 1) == 0) {

            printf("Programmende");

            return 0;
        }

        printf("Eingegebener String: %s\n", f, ilang);

        change_sequence_1(f);

        printf("%s\n", f);
    }

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


    *c = sqrt((pow(a, 2) + pow(b, 2)) - (2 * a * b * cos(gamma)));

    *alpha = asin((sin(gamma) * a) / (*c));

    *beta = M_PI - (*alpha + gamma);
}

//Funktion Aufgabe 2 Vorbereitung: gp_zufall aus Vorbereitung 2

double gp_zufall(double dmax) {

    return dmax * ((double) rand() /
                   (double) RAND_MAX); //Normierung der ausgegebenen Zufallszahl und Anpassen an Intervall
}

//Funktion Aufgabe 2 Vorbereitung: errechnet Mittelwert

double mittelwert(double dFeld[], int iAnz) {

    int i;
    double sum = 0;

    for (i = 0; i <= iAnz - 1; i++) {

        dFeld[i] = gp_zufall(100.);

        sum = sum + dFeld[i];

        printf("%d: %lf\n", i + 1, dFeld[i]);
    }

    printf("Der Mittelwert beträgt: %lf\n", sum / iAnz);
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