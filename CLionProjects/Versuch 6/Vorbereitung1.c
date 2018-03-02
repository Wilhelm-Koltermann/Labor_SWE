#include <stdio.h>
#include "simple_rgb_image.h"
#include <math.h>

int main()
{
simple_rgb_image_t image;
FILE *file;
int image_width = 512;
int image_height = 512;
/* Bildspeicher */
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
