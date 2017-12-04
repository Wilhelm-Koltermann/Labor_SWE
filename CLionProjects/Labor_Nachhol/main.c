#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Versuch 1

//Aufgabe 2: Jahreszeiten

int mainV11()
{

    int iTag;
    int iMonat;

    while (1)
    {

        printf("Bitte geben Sie Tag und Monat getrennt durch einen Punkt ein:");
        scanf("%d.%d", &iTag, &iMonat);

        if ((iMonat>=1 && iMonat<3) ||(iMonat==3 && iTag<20) || (iMonat==12 && iTag>21)){

            printf("Winter\n");
        }
        else
        {
            if((iMonat>3 && iMonat<6) || (iMonat==6 && iTag<21)||(iMonat==3 && iTag>19))
            {
                printf("Frühling\n");
            }
            else
            {
                if((iMonat>6 && iMonat<9) || (iMonat==9 && iTag<23) || (iMonat==6 && iTag>20))
                {
                    printf("Sommer\n");
                }
                else
                {
                    if((iMonat>9 && iMonat<13) || (iMonat==12 && iTag<22) || (iMonat==9 && iTag>22))
                    {
                        printf("Herbst\n");
                    }
                    else
                    {
                        printf("ungueltiger Tag");
                        return 0;
                    }
                }
            }

        }
    }
}


//Aufgabe 3: Wurfhöhe und -weite berechnen

int mainV12() {

    const double g = 9.81;
    double v, alpha;

    while (1) {

        printf("Bitte geben Sie die Abwurfgeschwindigkeit in m/s sowie den Abwurfwinkel im Gradmaß ein:");
        scanf("%lf %lf", &v, &alpha);

        if (v > 0 && alpha > 0) {

            alpha = (2 * M_PI * alpha )/ 360;

            printf("Die Wurfweite beträgt %.2f\n", (pow(v, 2) * sin(2. * alpha)) / g);
            printf("Die Wurfhöhe beträgt %.2f\n", (pow(v, 2) * pow(sin(alpha), 2)) /( 2 * g));

        } else {
            printf("ungueltige Eingabe");
            return 0;
        }


    }
}


//Versuch 2:

//Aufgabe 3 : Annäherung der Zahl Pi

double gp_zufall(double dmax);

int circle_check(double xm, double ym, double r, double x, double y);

double distance(double xm, double ym, double x, double y);

int main23() {

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


//Versuch 3



//Aufgabe 2: Standardabweichung

double standard_abw(double dFeld[], int anz, double mwert);

double mittelwert(double dFeld[], int iAnz);

int main32() {

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

//Aufgabe 3:

//Aufgabe 3: Decoding

void decode_string(char str[]);

void change_sequence_2(char *f);

void tausche_2(char *c1, char *c2);

int main33() {

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

//Funktion Versuch 2 Aufgabe 3: gp_zufall

double gp_zufall(double dmax) {

    return dmax * ((double) rand() / (double) RAND_MAX); //Normierung der ausgegebenen Zufallszahl und Anpassen an Intervall
}


//Funktion Versuch 2 Aufgabe 3: circle_check

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


//Funktion Versuch 2 Aufgabe 3: distance

double distance(double xm, double ym, double x, double y) {

    double Sub_x2_x1 = x - xm;   //Subtraktion der x-Koordinaten

    double Sub_y2_y1 = y - ym;   //"--" y-Koordinaten

    double vektorBetrag = sqrt(pow(Sub_x2_x1, 2) + pow(Sub_y2_y1, 2));

    return vektorBetrag;
}


//Funktion Versuch 3 Aufgabe 2: mittelwert

double mittelwert(double dFeld[], int iAnz) {

    int i;

    double sum=0.;

    for (i = 0; i < iAnz; i++) {

        sum += dFeld[i];
    }

    return sum / iAnz;
}


//Funktion Versuch 3 Aufgabe 2: Standardabweichung

double standard_abw(double dFeld[], int anz, double mwert) {

    int i;

    double sum = 0.;

    for (i = 0; i < anz; i++) {

        sum += pow((dFeld[i] - mwert), 2);
    }

    return sqrt((sum / (double) (anz - 1)));

}


//Funktion Versuch 3 Aufgabe 3: decode_string

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

//Funktion Versuch 3 Aufgabe 3: change_sequence_3

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

//Funktion Versuch 3 Aufgabe 3: tausche 2

void tausche_2(char *c1, char *c2) {

    char temp;

    temp = *c1;

    *c1 = *c2;

    *c2 = temp;

}
