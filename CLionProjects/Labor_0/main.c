#include <stdio.h>

//Vorbereitungsaufgaben

/* Aufgabe 1: Gib alle Zahlen von 1-100 aus */

int main1V() {
    int izaehler;
    izaehler = 0;
    while (izaehler < 100) {
        izaehler++;
        printf("%d\t", izaehler);
    }
    return 0;
}

//Aufgabe 2: Kleines Einmaleins mit while-Verschachtelung

int main2V() {
    int ivar1 = 1, ivar2, imult;
    while (ivar1 < 10) {
        ivar2 = 1;

        while (ivar2 < 10) {
            imult = ivar1 * ivar2;
            printf("%d*%d=%d\t", ivar1, ivar2, imult);
            ivar2++;
        }
        printf("\n");
        ivar1++;

    }
    return 0;
}

/* Aufgabe 2: Kleines Einmaleins mit while&if */

int main21V() {
    int ivar1, ivar2, imult;
    imult = 0;
    ivar1 = 1;
    ivar2 = 1;
    while (ivar1 < 9 || ivar2 < 10) {
        if (ivar1 < 10 && ivar2 > 9) {
            ivar1++;
            ivar2 = 1;
            printf("\n");
        } else {
            imult = ivar1 * ivar2;
            printf("%d*%d=%d\t", ivar1, ivar2, imult);
            ivar2++;
        }
    }
    return 0;
}


/*Aufgabe 2: Kleines Einmaleins mit for-Schleife*/

int main22V() {
    int imult;
    for (int ivar1 = 1; ivar1 < 10; ivar1++) {
        printf("\n");
        for (int ivar2 = 1; ivar2 < 10; ivar2++) {
            imult = ivar1 * ivar2;
            printf("%d*%d=%d\t", ivar1, ivar2, imult);
        }
    }
    return 0;
}

/* Aufgabe 3: Alle geraden Zahlen von 1-100 */

int main3V() {
    int izaehler;
    izaehler = 1;
    while (izaehler <= 100) {
        if ((izaehler / 2) * 2 == izaehler) {
            printf("%d\t", izaehler);
        }
        izaehler++;
    }
    return 0;
}

//Laboraufgaben

//Aufgabe 1: Alle ungeraden Zahlen zwischen 1-500

int main1L() {
    int izaehler;
    izaehler = 1;
    while (izaehler < 500) {
        if ((izaehler / 2) * 2 != izaehler) {
            printf("%d\t", izaehler);
        }
        izaehler++;
    }
    return 0;
}

//Aufgabe 2: siehe "Aufgabe 2: Kleines Einmalseins mit while-Verschachtelung
