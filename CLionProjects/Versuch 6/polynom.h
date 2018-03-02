#ifndef ___POLYNOM_H__
#define ___POLYNOM_H__
#include <stddef.h>

/**
 * Datentyp zum Umgang mit Polynomen.
 * Vor Verwendung muss eine Variable des Typs polynom_t initialisiert werden.
 *
 * 	p(x) = coefficients[0] + coefficients[1] * x + coefficients[2] * x * x + ...
 */
typedef struct{
	double* coefficients;
	size_t  size;
} polynom_t;


/**
 * Initialierung der Variable an Adresse poly. size ist die Anzahl der
 * Koeffizienten. Die Funktion gibt die Adresse des dynamisch allokierten Speichers
 * zurueck -- hierdurch koennen Allokationsfehler erkannt werden.
 */
void* polynom_initialize (polynom_t *poly, size_t size);

/**
 * Freigeben dynamisch allokierten Speichers nach letzter Verwendung der Variablen
 * an der Adresse poly.
 */
void polynom_destroy(polynom_t *poly);

/**
 * Setzen der Koeffizienten der Variablen an der Adresse poly.
 * array ist ein Feld von poly->size Elementen.
 * Alle Koeffizienten werden von array kopiert.
 */
void polynom_set_coefficients_from_array (polynom_t *poly, double *array);

/**
 * Extrahieren der Koeffizienten der Variablen an der Adresse poly.
 * array ist ein Feld von poly->size Elementen.
 * Alle Koeffizienten werden nach array kopiert.
 */
void polynom_put_coefficients_to_array (polynom_t *poly, double *array);

/**
 * Berechnung des Funktionswertes eines Polynoms an der Stelle x.
 */
double polynom_evaluate(polynom_t *polynom, double x);

/**
 * Ausgabe eines Polynoms auf der Standardausgabe.
 * Koeffizienten, der Betrag kleiner als eps ist, werden nicht mit ausgegeben.
 * Die Zeichenkette arg_name (bsp "x" oder "t") ist Platzhalter fuer die Variable des Polynoms.
 */
void polynom_print(polynom_t *polynom, double eps, const char *arg_name);

/**
 * Bestimmung eines Ausgleichspolynoms durch die Methode der kleinsten Fehlerquadrate.
 * x und y sind Felder mit jeweils number_of_points Elementen.
 * Das Polynom an der Adresse sink muss bereits initialisiert sein,
 * sink->coefficents zeigt also bereits auf ein Feld von sink->size Elementen.
 * Es wird das Polynom
 * 		p(x) = a_0 + a_1*x + a_2*x*x + a_3*x*x*x + ...
 * vom Grad sink->coefficents - 1 gesucht, das am Besten zu den Punkten (x_i,y_i) passt.
 * Fuer jeden Punkt (x_i,y_i) gibt es den Fehler  E_i := y_i - p(x_i)
 * Das gefundene Polynom minimiert die Summe aller E_i*E_i.
 */
void polynom_least_sqares(polynom_t *sink, double *x, double *y, size_t number_of_points);

#endif/*___POLYNOM_H__*/
