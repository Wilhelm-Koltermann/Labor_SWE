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


int main2t() {

    printf("%d", fib(4));


}



//Aufgabe 2: Testprogramm für fib_v2

int fib_v2(int n);

int call_cnt, level, level_max;

int main2V() {

    int zahl;

    while (1) {

        printf("Welche Fibonacci-Zahl ist zu berechnen?");
        scanf("%d", &zahl);

        if (fib_v2(zahl) == -1) {

            printf("Programmende\n");

            break;

        } else {

            call_cnt = level_max = 0;

            printf("Die %d. Fibonnaci-Zahl ist %d\n", zahl, fib_v2(zahl));

            printf("Anzahl der Aufrufe %d\n", call_cnt);

            printf("Anzahl der Hierarchiebenen %d\n", level_max);
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

int main3V() {

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

//Laboraufgaben

//Aufgabe 1: Zahlenausgabe mit Rekursion

void print_dec_v2(unsigned int number);

void print_hex_v2(unsigned int number);

int main1L() {

    print_dec_v2(0xffffffff);
    putchar('\n');
    print_dec_v2(0);
    putchar('\n');
    print_dec_v2(12345678);
    putchar('\n');
    print_dec_v2(987654321);
    putchar('\n');
    putchar('\n');
    print_hex_v2(0xffffffff);
    putchar('\n');
    print_hex_v2(0);
    putchar('\n');
    print_hex_v2(12345678);
    putchar('\n');
    print_hex_v2(0xabcd);
    putchar('\n');
    putchar('\n');
    return 0;
}



//Aufgabe 2: Testprogramm für fib_v3

int fib_v3(int n);

int main3l() {

    int zahl;

    while (1) {

        printf("Welche Fibonacci-Zahl ist zu berechnen?");
        scanf("%d", &zahl);

        if (zahl >= 0) {

            printf("Die %d. Fibonnaci-Zahl ist %d\n", zahl, fib_v3(zahl));

            printf("Anzahl der Aufrufe %d\n", fib_v3(-2));

            printf("Anzahl der Hierarchiebenen %d\n", fib_v3(-3));

            fib_v3(-1);


        } else {

            printf("\nProgrammende");

            return 0;
        }
    }


}

//Augabe 3: Binomialkoeffizient durch Rekursion

unsigned int bin_koeff_v2(unsigned int n, unsigned int k);

int main() {

    unsigned int n, k;

    while (1) {

        if (n < 0 || k < 0) {

            printf("Error");

            return 0;

        } else {

            printf("Bitte Werte für n und k eingeben: ");
            scanf("%u %u", &n, &k);

            printf("Der Binomialkoeffizient n über k ist: %u\n", bin_koeff_v2(n, k));
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

//Funktion Vorbereitungsaufgabe 1: printf_hex_v1

void print_hex_v1(unsigned int number) {

    unsigned int div, digit;

    int first = 1;

    for (div = (unsigned int) pow(16, 7); div; div /= 16) {

        digit = number / div;

        if (digit == 0 && first && div != 1) continue;

        first = 0;

        if (digit == 10) putchar('A');

        if (digit == 11) putchar('B');

        if (digit == 12) putchar('C');

        if (digit == 13) putchar('D');

        if (digit == 14) putchar('E');

        if (digit == 15) putchar('F');

        if (digit < 10) putchar(digit + '0');

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

    if (n < 0) return -1;

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


        BinKoeff = BinKoeff * (n + 1 - i) / i;

        printf("%u\n", (n + 1 - i) / i);

    }

    return BinKoeff;


}

//Funktion Laboraufgabe 1: print_dez

void print_dec_v2(unsigned int number) {

    unsigned int digit, parameter;

    digit = number % 10;

    parameter = number / 10;

    if (parameter != 0) print_dec_v2(parameter);

    putchar(digit + '0');

}

//Funktion Laboraufgabe 1 : printf_hex

void print_hex_v2(unsigned int number) {

    unsigned int digit, parameter;

    digit = number % 16;

    parameter = number / 16;

    if (parameter != 0) print_hex_v2(parameter);

    if (digit < 10) putchar(digit + '0');

    if (digit == 10) putchar('a');

    if (digit == 11) putchar('b');

    if (digit == 12) putchar('c');

    if (digit == 13) putchar('d');

    if (digit == 14) putchar('e');

    if (digit == 15) putchar('f');

}

//Funktion Laboraufgabe 2: fib_v3

int fib_v3(int n) {

    int static call_cnt;
    int static level;
    int static level_max;

    if (n == -3) return level_max;

    if (n == -2) return call_cnt;

    if (n == -1) {
        call_cnt = level_max = 0;
        return 0;
    }

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

    val = fib_v3(n - 1);

    val += fib_v3(n - 2);

    level--;

    return val;
}


//Funktion Laboraufgabe 3:  bin_koeff_v2

unsigned int bin_koeff_v2(unsigned int n, unsigned int k) {

    int static call_cnt;
    int static level;
    int static level_max;

    call_cnt++;

    level++;

    if (level > level_max) { level_max = level;}

    printf("---> DEBUG: %d-ter Aufruf mit Parameter n= %u und k = %u "
                   "auf Ebene %d\n", call_cnt, n, k, level_max);

    unsigned int val;

    if (k == 0 || n == k) { level--; return 1;}


    if (k == 1 || n == k-1) { level--; return n;}

    val = bin_koeff_v2(n-1, k-1);

    val += bin_koeff_v2(n-1, k);

    level--;

    return val;
}

