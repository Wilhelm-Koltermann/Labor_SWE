#ifndef ___SCREEN_TRANSFORM_H___
#define ___SCREEN_TRANSFORM_H___

/**
 *	Datentyp zum vereinfachten Umgang mit Rastergraphiken.
 *	Zeichenbefehle aus einem Weltkoordinatensystem werden
 *	auf das Rastergraphikkoordinatensystem (auch Screen-,
 *  bzw. Bildschirmkoordinatensystem) uebersetzt.
 */
typedef struct{
	double world_min_x;
	double world_min_y;
	double world_max_x;
	double world_max_y;
	int screen_min_x;
	int screen_min_y;
	int screen_max_x;
	int screen_max_y;
} screen_transform_t;

/**
 * Einstellen des horizontalen Bildausschnittes fuer die Transformation an Adresse trans.
 * Der abgebildete Bereich geht von Spalte min bis Spalte max.
 */
void screen_transform_set_screen_range_x (screen_transform_t *trans, int min, int max);

/**
 * Einstellen des vertikalen Bildausschnittes fuer die Transformation an Adresse trans.
 * Der abgebildete Bereich geht von Zeile min bis Zeile max.
 */
void screen_transform_set_screen_range_y (screen_transform_t *trans, int min, int max);

/**
 * Einstellen des horizontalen Weltausschnittes fuer die Transformation an Adresse trans.
 * Der abgebildete Bereich geht von min bis max.
 */
void screen_transform_set_world_range_x (screen_transform_t *trans, double min, double max);

/**
 * Einstellen des vertikalen Weltausschnittes fuer die Transformation an Adresse trans.
 * Der abgebildete Bereich geht von min bis max.
 */
void screen_transform_set_world_range_y (screen_transform_t *trans, double min, double max);

/**
 * Der Abbildungsmassstab von sink wird mit scale multipliziert.
 * Das Zentrum des dargestellten Ausschnittes der Welt bleibt dabei unveraendert.
 * Beispiel:
 * 		scale = 2
 * 			==> dargestellter Bereich des Weltkoordinatensystems halbiert sich
 *					(Darstellung wird doppelt so gross)
 *		scale = 0.5
 * 			==> dargestellter Bereich des Weltkoordinatensystems verdoppelt sich
 *					(Darstellung wird halb so gross)
 */
void screen_transform_zoom(screen_transform_t *sink, double scale);

/**
 * Bestimmung von Screen- aus Weltkoordinaten (x-Achse).
 */
int screen_transform_get_screen_x(screen_transform_t *source, double x);

/**
 * Bestimmung von Screen- aus Weltkoordinaten (y-Achse).
 */
int screen_transform_get_screen_y(screen_transform_t *source, double y);

/**
 * Bestimmung von Welt- aus Screenkoordinaten (x-Achse).
 */
double screen_transform_get_world_x(screen_transform_t *source, int x);

/**
 * Bestimmung von Welt- aus Screenkoordinaten (y-Achse).
 */
double screen_transform_get_world_y(screen_transform_t *source, int y);


#endif/*___SCREEN_TRANSFORM_H___*/
