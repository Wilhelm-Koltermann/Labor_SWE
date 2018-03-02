#ifndef ___SIMPLE_RGB_IMAGE_H___
#define ___SIMPLE_RGB_IMAGE_H___

#include <stdio.h>

/**
 * simple_rgb_image_t dient zur Speicherung einer Rastergraphik.
 * Eine Variable diesen Typs muss unbedingt vor der Verwendung mit
 * 		simple_rgb_image_init
 * initialisiert werden (dynamische Speicherallokation) und
 * nach der Verwendung mit
 *		simple_rgb_image_clear
 * wieder bereinigt werden (Freigabe des dynamischen Speichers).
 */
typedef struct {
	/**
	 * 	Breite des Bildes in Pixeln
	 */
	int width;

	/**
	 * Hoehe des Bildes in Pixeln
	 */
	int height;

	/**
	 * Zeiger auf die einzelnen Pixel,
	 * diese sind zusammenhaengend im Speicher abgelegt
	 */
	unsigned char *data;
} simple_rgb_image_t;

/**
 * Setzt die Attribute width und height von sink.
 * Allokiert den benoetigten Speicher fuer die Bilddaten.
 */
void simple_rgb_image_init(simple_rgb_image_t *sink, int width, int height);

/**
 * Gibt den fuer sink dynamisch allokierten Speicher wieder frei.
 */
void simple_rgb_image_clear(simple_rgb_image_t *sink);

/**
 * Speichert source im Windows-Bitmap-Format in stream.
 * stream muss im Modus "wb" (Write Binary) geoeffnet sein.
 */
void simple_rgb_image_to_bitmap_stream(simple_rgb_image_t *source, FILE *stream);

/**
 * Faerbt den Pixel (x,y) im Bild sink mit den Farbaussteuerungen (red,green,blue).
 * Pixel werden von 0 an gezaehlt.
 * 		(0,0)				-> erstes Pixel
 * 		(width-1,height-1)	-> letztes Pixel
 */
void simple_rgb_image_put_pixel(simple_rgb_image_t *sink, int x, int y, unsigned char red, unsigned char green, unsigned char blue);

/**
 * Abfrage der Farbaussteuerungen des Pixels (x,y) des Bildes source
 *
 * Rueckgabe:
 * 	0:	Fehler (Pixel ausserhalb des Bildes, Farbaussteuerungen bleiben unveraendert)
 * 	1:	ok (valider Pixel, Farbaussteuerungen wurden angepasst)
 */
int simple_rgb_image_get_pixel(unsigned char *red, unsigned char *green, unsigned char *blue, simple_rgb_image_t *source, int x, int y);

/**
 * Faerbt die Linie der Linienbreite width vom Pixel (x0,y0) zum Pixel (x1,y1) mit den Farbaussteuerungen (red,green,blue).
 */
void simple_rgb_image_draw_line(simple_rgb_image_t *sink, int x0, int y0, int x1, int y1, int width, unsigned char red, unsigned char green, unsigned char blue);

/**
 * Faerbt alle Pixel innerhalb des Kreises mit Mittelpunkt (x,y) und Radius radius mit den Farbaussteuerungen (red,green,blue).
 */
void simple_rgb_image_fill_circle(simple_rgb_image_t *sink, int x, int y, int radius, unsigned char red, unsigned char green, unsigned char blue);

/**
 * Faerbt alle Pixel des Umfangs des Kreises mit Mittelpunkt (x,y) und Radius radius mit den Farbaussteuerungen (red,green,blue).
 * Dabei betraegt die Linienbreite width.
 */
void simple_rgb_image_draw_circle(simple_rgb_image_t *sink, int x, int y, int radius, int width, unsigned char red, unsigned char green, unsigned char blue);

#endif/*___SIMPLE_RGB_IMAGE_H___*/
