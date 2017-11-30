#include <stdio.h>
#include <math.h>

//Vorbereitungsaufgaben

//Aufgabe 2: Nach Struktogramm

int main2V() {

    int iTag;
    printf("Bitte geben Sie die Nummer eines Wochentags ein:");
    scanf("%d", &iTag);

    if (iTag == 1) {

        printf("Sonntag");

    } else {

        if (iTag == 2) {

            printf("Montag");

        } else {

            if (iTag == 3 || iTag == 4 || iTag == 5 || iTag == 6 || iTag == 7) {

                printf("Baustelle: muss noch implementiert");

            } else {

                printf("ungueltiger Tag");
            }
        }
    }
}

//Aufgabe 3: Eingabe einer Zahl und Zuordnung des Monats

int main3V() {

    int iMonat;

    for (;;) {

        printf("Bitte geben Sie die Nummer eines Monats ein:");
        scanf("%d", &iMonat);

        if (iMonat == 1) {

            printf("Januar\n");

        } else {

            if (iMonat == 2) {

                printf("Februar\n");

            } else {

                if (iMonat == 3) {

                    printf("März\n");

                } else {

                    if (iMonat == 4) {

                        printf("April\n");

                    } else {

                        if (iMonat == 5) {

                            printf("Mai\n");

                        } else {

                            if (iMonat == 6) {

                                printf("Juni\n");

                            } else {

                                if (iMonat == 7) {

                                    printf("Juli\n");

                                } else {

                                    if (iMonat == 8) {

                                        printf("August\n");

                                    } else {

                                        if (iMonat == 9) {

                                            printf("September\n");
                                        } else {

                                            if (iMonat == 10) {

                                                printf("Oktober\n");

                                            } else {

                                                if (iMonat == 11) {

                                                    printf("November\n");

                                                } else {

                                                    if (iMonat == 12) {

                                                        printf("Dezember\n");

                                                    } else {

                                                        printf("ungueltiger Monat\n");

                                                        return 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}



//Aufgabe 4: Rechteck Berechnungen

int main4V() {

    double dHoehe, dBreite;

    for (;;) {

        printf("Bitte geben Sie Höhe und Breite Ihres Rechtecks ein:");
        scanf("%lf %lf", &dHoehe, &dBreite);

        if (dHoehe < 0 || dBreite < 0) {

            printf("Negativer Wert - Programmende\n");
            return 0;

        } else {

            printf("Der Umfang des Rechtecks beträgt %.2f\n", 2 * (dHoehe + dBreite));

            printf("Die Länge der Diagonale beträgt %.2f\n", sqrt(pow(dHoehe, 2) + pow(dBreite, 2)));

            printf("Die Flaeche des Rechtecks beträgt %.2f\n", dHoehe * dBreite);

        }
    }
}


//Laboraufgaben

//Aufgabe 1:Nach PAP

int main1L() {

    int n, count, res1, res2;

    while (1) {

        printf("Bitte geben Sie eine ganze Zahl ein:");
        scanf("%d", &n);

        if (n <= 0) {

            printf("Falsche Eingabe!");
            return 0;

        } else {

            res1 = 0;
            count = 1;

            while (count <= n) {

                res1 = res1 + count;
                count++;
            }

            res2 = n * (n + 1) / 2;
            printf("res1 ist %d und res2 ist %d\n", res1, res2);
        }
    }
}


//Aufgabe 2: Jahreszeiten

int main2L()
{

    int iTag;
    int iMonat;

    while (1)
    {

        printf("Bitte geben Sie Tag und Monat getrennt durch einen Punkt ein:");
        scanf("%d.%d", &iTag, &iMonat);

        if (iMonat>=1 && iMonat<3 ||iMonat==3 && iTag<20 || iMonat==12 && iTag>21){

            printf("Winter\n");
        }
        else
        {
            if(iMonat>3 && iMonat<6 || iMonat==6 && iTag<21||iMonat==3 && iTag>19)
            {
                printf("Frühling\n");
            }
            else
            {
                if(iMonat>6 && iMonat<9 || iMonat==9 && iTag<23 || iMonat==6 && iTag>20)
                {
                    printf("Sommer\n");
                }
                else
                {
                    if(iMonat>9 && iMonat<13 || iMonat==12 && iTag<22 || iMonat==9 && iTag>22)
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

int main() {

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



