#include <stdio.h>

#include <math.h>

//Vorbereitungsaufgaben

//Aufgabe 1: Zahlensysteme

void print_hex_v1(unsigned int number);

void print_dec_v1(unsigned int number);

int main1V() {

    print_dec_v1(0xffffffff);
    putchar('\n');


    print_dec_v1(0);
    putchar('\n');

    print_dec_v1(12345678);
    putchar('\n');

    print_dec_v1(987654321);
    putchar('\n');
    putchar('\n');

    print_hex_v1(0xffffffff);
    putchar('\n');

    print_hex_v1(0);
    putchar('\n');

    print_hex_v1(12345678);
    putchar('\n');

    print_hex_v1(0xabcd);
    putchar('\n');
    putchar('\n');
    return 0;
}



//Aufgabe 2: Testprogramm für Fib

unsigned int fib(unsigned int n);


int main2V1() {

    printf("%d", fib(5));


}



//Aufgabe 2: Testprogramm für fib_v2

int fib_v2(int n);

int call_cnt, level, level_max;

int main2v() {

    int zahl;

    while (1) {

        printf("Welche Fibonacci-Zahl ist zu berechnen?");
        scanf("%d", &zahl);

        if (zahl >= 0) {

            call_cnt = level_max = 0;

            printf("Die %d. Fibinnaci-Zahl ist %d\n", zahl, fib_v2(zahl));

            printf("Anzahl der Aufrufe %d\n", call_cnt);

            printf("Anzahl der Hierarchiebenen %d\n", level_max);


        } else {

            printf("\nProgrammende");

            return 0;
        }
    }


}

//Aufgabe 3 Testprogramm für bin_koeff_v1

unsigned int bin_koeff_v1(unsigned int n, unsigned int k);

int main3t() {

    unsigned int n, k;

    printf("Bitte n und k eingeben:");
    scanf("%u %u", &n, &k);

    printf("\nDer Binomialkoeffizient beträgt: %u\n", bin_koeff_v1(n, k));


}

//Aufgabe 3 Testprogramm Pascalsches Dreieck

int main() {

    unsigned int n, k;

    for (n = 0; n < 13; n++) {

        for (k = 0; k <= n; k++) {

            printf("%u\t", bin_koeff_v1(n, k));

            if (n == k) {

                printf("\n");
            }

        }


    }
}



//Funktionen:

//Funktion Vorbereitungsaufgabe 1: printf_dec_v1

void print_dec_v1(unsigned int number) {

    unsigned int div, digit;

    int first = 1;

    for (div = (int) 1e9; div; div /= 10) {

        digit = number / div;

        if (digit == 0 && first && div != 1) {

            continue;
        }

        first = 0;

        putchar(digit + '0');

        number -= digit * div;
    }
}

//Funktion Vorbereitungsaufgabe 2: printf_hex_v1

void print_hex_v1(unsigned int number) {

    unsigned int div, digit;

    int first = 1;

    for (div = (unsigned int) pow(16, 7); div; div /= 16) {

        digit = number / div;

        if (digit == 10) putchar('A');

        if (digit == 11) putchar('B');

        if (digit == 12) putchar('C');

        if (digit == 13) putchar('D');

        if (digit == 14) putchar('E');

        if (digit == 15) putchar('F');

        if (digit == 0 && first && div != 1) continue;

        if (digit == 0 || digit == 1 || digit == 2 || digit == 3 || digit == 4 ||
            digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
            putchar(digit + '0');

        first = 0;

        number -= digit * div;


    }


}


//Funktion Vorbereitungsaugabe 2: fib

unsigned int fib(unsigned int n) {

    if (n == 0 || n == 1) {

        return n;
    }

    if (n > 1) {

        return fib(n - 1) + fib(n - 2);
    }

}

//Funktion Vorbereitungsaugabe 2: fib_v2


int fib_v2(int n) {

    call_cnt++;

    level++;

    if (level > level_max) {

        level_max = level;
    }

    int val;

    if (n == 0 || n == 1) {

        level--;

        return n;
    }

    val = fib_v2(n - 1);

    val += fib_v2(n - 2);

    level--;

    return val;
}

//Funktion Vorbereitungsaufgabe 3: bin_koeff_v1

unsigned int bin_koeff_v1(unsigned int n, unsigned int k) {

    unsigned int BinKoeff = 1, i;

    for (i = 1; i <= k; i++) {


        BinKoeff = (double) BinKoeff * (double) (n + 1 - i) / i;

    }

    return BinKoeff;


}