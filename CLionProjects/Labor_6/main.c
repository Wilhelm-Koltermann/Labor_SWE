#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>

//Augabe 1: Bilddatei erstellen

int main(void)
{
    simple_rgb_image_t image; /* Bildspeicher */

    FILE *file;

    int image_width = 512;

    int image_height = 512;



/* Bilddatei zum binaeren Schreiben oeffnen */

    if ( (file = fopen("mein_bild.bmp", "wb")) == NULL) {

        printf("open error\n"); return -1;}

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

//Funktion Vorbereitung 1:

void simple_rgb_image_init(simple_rgb_image_t *sink, int width, int height) {

    sink->width = width;

    sink->height = height;

    sink->data = malloc(3 * width * height);

}
