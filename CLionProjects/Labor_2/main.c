#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Aufgabe 3: Abstand Mittelpunkt & beliebiger Punkt
//Bib: stdio

//Vorbereitungsaufgaben

double distance(double xm, double ym, double x, double y);

int main3V() {

    double x1, y1, x2, y2, rad;
    int anz, zaehl;

    printf("Bitte geben Sie die x-und y-Koordinate des Mittelpunkts sowie den Radius Ihres Kreises ein:");
    scanf("%lf %lf %lf", &x1, &y1, &rad);

    printf("Eingegebene Werte für die Koordinaten des Kreismittelpunkts und des Radius: x=%.2lf, y=%.2lf, r=%.2lf\n",
           x1, y1, rad);

    printf("Wie viele Punkte sollen eingegeben werden?");
    scanf("%d", &anz);

    for (zaehl = 1; zaehl <= anz; zaehl++) {

        printf("Bitte geben Sie die x-und y-Koordinate Ihres Punktes ein:");
        scanf("%lf %lf", &x2, &y2);

        printf("Der Abstand zwischen dem Kreismittelpunkt und Ihrem Punkt beträgt %.2lf\n", distance(x1, y1, x2, y2));
    }

    return 0;
}


//Aufgabe 5: 50 zufällige GP-Zahlen im Bereich von 0.0-10.0
//stdlib,time, stdio

double gp_zufall(double dmax);

int main5V() {

    int i;    //i=Anzahl der ausgegebenen Zahlen, d=Nummerierung der Zahlen
    srand(time(NULL));

    for (i = 1; i <= 50; i++) {

        printf("%d.Zufallszahl = %lf\t", i, gp_zufall(10.0));

        if (i % 5 == 0) {  //für eine übersichtlichere Ausgabe

            printf("\n");
        }

    }

    return 0;
}


//Laboraufgaben

//Aufgabe 1:Fakultät berechenen
//Bib:stdio

unsigned int fak(unsigned int n);

int main1L() {

    for (;;) {

        int n;

        printf("Bitte geben Sie eine ganze, nicht-negative Zahl ein:\n");

        scanf("%d", &n);

        if (n >= 0) {

            printf("Die Fakultät der eingegebenen Zahl beträgt %u\n", fak((unsigned int) n));

        } else {

            printf("Falsche Eingabe\n");

            return 0;
        }


    }
}

//Aufgabe2: Punkte innerhalb oder außerhalb des Kreises
//Bib: stdio

int circle_check(double xm, double ym, double r, double x, double y);

int main2L() {

    double xm, ym, x, y, r;
    int anz, zaehl;

    printf("Bitte geben Sie die x-und y-Koordinate des Mittelpunkts sowie den Radius Ihres Kreises ein:");
    scanf("%lf %lf %lf", &xm, &ym, &r);

    printf("Eingegebene Werte fuer die Koordinaten des Kreismittelpunkts und des Radius: x=%.2lf, y=%.2lf, r=%.2lf\n",
           xm, ym, r);

    printf("Wie viele Punkte sollen eingegeben werden?");
    scanf("%d", &anz);

    for (zaehl = 1; zaehl <= anz; zaehl++) {

        printf("Bitte geben Sie die x-und y-Koordinate Ihres Punktes ein:");
        scanf("%lf %lf", &x, &y);

        printf("%d\n", circle_check(xm, ym, r, x, y));
        printf("Ausgabe -1 oder 0: Der Punkt liegt in Ihrem Kreis bzw. auf dem Rand des Kreises\nAusgabe 1: Der Punkt liegt außerhalb Ihres Kreises");

    }

    return 0;
}


//Aufgabe 3 Labor: Annäherung der Zahl Pi
//Bib: stdlib, stdio,time

int main() {

    int anz, i, cnt1 = 0, cnt2 = 0;

    double x, y, pi, abw;

    const double xm = 1., ym = 1., r = 1.;

    srand(time(NULL));

    printf("Bitte geben Sie eine ganze Zahl ein:");
    scanf("%d", &anz);

    for (i = 0; i < anz; i++) {

        x = gp_zufall(2.0);
        y = gp_zufall(2.0);

        if (circle_check(xm, ym, r, x, y) == -1 || circle_check(xm, ym, r, x, y) == 0) {

            cnt1++;

        } else {

            cnt2++;
        }
    }

    pi = (4 * (double) cnt1) / (cnt1 + cnt2);

    abw = fabs(4 * atan(1.0) - pi);

    printf("pi angenähert=%.10lf\nAbweichung=%g\n", pi, abw);

    return 0;
}




//Funktionen

//Funktion Fak zu Aufgabe 1 Labor: Berechnung der Fakultät

unsigned int fak(unsigned int n) {

    unsigned f = 1, i;

    for (i = 1; i <= n; i++) {

        f = f * i;
    }

    return f;
}

//Funktion Distance: Aufgabe2 Vorbereitung und Labor, Abstand zweier Punkte
//Bib:math.h

double distance(double xm, double ym, double x, double y) {

    double Sub_x2_x1 = x - xm;   //Subtraktion der x-Koordinaten

    double Sub_y2_y1 = y - ym;   //"--" y-Koordinaten

    double vektorBetrag = sqrt(pow(Sub_x2_x1, 2) + pow(Sub_y2_y1, 2));

    return vektorBetrag;
}

//Funktion gp_zufall: Aufgabe 4 Vorbereitung; Gibt Zufallszahl aus
//Bib: stdlib

double gp_zufall(double dmax) {

    return dmax * ((double) rand() / (double) RAND_MAX); //Normierung der ausgegebenen Zufallszahl und Anpassen an Intervall
}


//Funktion Circle_Check zu Aufgabe 2 Labor

int circle_check(double xm, double ym, double r, double x, double y) {

    double m = distance(xm, ym, x, y);

    if (m < r) {


        return -1;
    }
    if (m > r) {


        return 1;
    }
    if (m == r) {


        return 0;
    }


}

