#include <stdio.h>

#include <math.h>

//Vorberitungsaufgaben

//Aufgabe 1: Zahlensysteme

void print_hex_v1(unsigned int number);

void print_dec_v1(unsigned int number);

int main() {

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

