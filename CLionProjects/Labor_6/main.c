#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>
#include <math.h>

//Augabe 1: Bilddatei erstellen

double distance(double xm, double ym, double x, double y);

int main(void) {

    simple_rgb_image_t image; /* Bildspeicher */

    FILE *file;

    int image_width = 512;

    int image_height = 512;



/* Bilddatei zum binaeren Schreiben oeffnen */

    if ((file = fopen("mein_bild.bmp", "wb")) == NULL) {

        printf("open error\n");

        return -1;
    }

/* Initialisierung des Bildspeichers */

    simple_rgb_image_init(&image, image_width, image_height);

/* Hier werden Zeichenbefehle ausgefuehrt */

/* Ein roter Kreis in der Bildmitte */

    simple_rgb_image_fill_circle(&image, 256, 256, 128, 255, 0, 0);

/* Eine Diagonale gruen einzeichnen */

    simple_rgb_image_draw_line(&image, 0, 0, 511, 511, 4, 0, 255, 0);

/* Die andere Diagonale blau einzeichnen */

    simple_rgb_image_draw_line(&image, 0, 511, 511, 0, 4, 0, 0, 255);

/* Bild in Datei abspeichern */

    simple_rgb_image_to_bitmap_stream(&image, file);

/* Dynamisch allokierten Speicher des Bildes wieder freigeben */

    simple_rgb_image_clear(&image);

/* Bilddatei schließen */

    fclose(file);

    return 0;
}

//Funktionen

//Funktion Vorbereitungsaufgabe 1: Initialisierung des Bildes

void simple_rgb_image_init(simple_rgb_image_t *sink, int width, int height) {

    sink->width = width;

    sink->height = height;

    sink->data = malloc(3 * width * height);

    if (sink->data == NULL) { printf("Error-Allokation fehlgeschlagen\n"); }
}

//Funktion Vorbereitungsaufgabe 1: Freigabe des Speicherplatzes

void simple_rgb_image_clear(simple_rgb_image_t *sink) {

    free(sink->data);
}

//Funktion Vorbereitungsaufgabe 1: Erzeugung der Bilddatei

void simple_rgb_image_to_bitmap_stream(simple_rgb_image_t *source, FILE *stream) {

    int i;

    for (i = 0; i <= (3 * source->width * source->height) - 1; i++) {

        fputc(source->data[i], stream);
    }

}

//Funktion Vorbereitungsaufgabe 1: Pixel Färben

void simple_rgb_image_put_pixel(simple_rgb_image_t *sink, int x, int y,
                                unsigned char red, unsigned char green, unsigned char blue) {

    sink->data[(y * (sink->width) * 3) + (x * 3)] = red;

    sink->data[((y * (sink->width) * 3) + (x * 3)) + 1] = green;

    sink->data[((y * (sink->width) * 3) + (x * 3)) + 2] = blue;


}

//Funktion Vorbereitunsgaugabe 1: Linie einzeichnen

void simple_rgb_image_draw_line(simple_rgb_image_t *sink, int x0, int y0, int
x1, int y1, int width, unsigned char red, unsigned char green, unsigned char blue) {

    int i, j, k;

    if (y0 <= y1) {

        for (i = x0, j = y0; i <= x1, j <= y1; i++, j++) {

            for (k = 0; k <= width - 1; k++) {

                if ((j + width) <= sink->height - 1) {

                    simple_rgb_image_put_pixel(sink, i, (j + width), red, green, blue);
                }
            }
        }

    } else {

        for (i = x0, j = y0; i <= x1, j >= y1; i++, j--) {

            for (k = 0; k <= width - 1; k++) {

                if ((j + width) <= sink->height - 1) {

                    simple_rgb_image_put_pixel(sink, i, (j + width), red, green, blue);
                }
            }
        }
    }
}


//Funktion Vorbereitungsaufgabe 1: Kreis zeichnen und ausfüllen

void simple_rgb_image_fill_circle(simple_rgb_image_t *sink, int x, int y, int
radius, unsigned char red, unsigned char green, unsigned char blue) {

    int i, j;

    for (i = 0, j = 0; i <= sink->height - 1, j <= sink->width - 1; i++, j++)

        if (distance(x, y, i, j) <= radius) { simple_rgb_image_put_pixel(sink, i, j, red, green, blue); }
}




//Funktion Distance: Aufgabe 2 Vorbereitung und Labor, Abstand zweier Punkte
//Bib:math.h

double distance(double xm, double ym, double x, double y) {

    double Sub_x2_x1 = x - xm;   //Subtraktion der x-Koordinaten

    double Sub_y2_y1 = y - ym;   //"--" y-Koordinaten

    double vektorBetrag = sqrt(pow(Sub_x2_x1, 2) + pow(Sub_y2_y1, 2));

    return vektorBetrag;
}
