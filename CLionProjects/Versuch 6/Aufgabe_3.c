#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_number_from_char(char *zeile, double *x, double *y, int line);
void find_min_max(double *min, double *max, double *x, size_t size);
size_t get_number_of_lines_in_file(FILE *file);


int main()
{
	int i = 0, j = 0;
	char pfad[200];

	double x_min, x_max, y_min, y_max;
	char zeile[7];						//Zeileninhalt
	char number[2];
	
	fflush(stdin);
	printf("Pfad:\n");
	fgets(pfad, 200, stdin);
	pfad[strlen(pfad)-1] = 0;
	FILE *datei = fopen(pfad, "r");
	if(datei == NULL) printf("Error\n");
	int lines = (int)get_number_of_lines_in_file(datei);	//Anzahl der Zeilen

	double *x = (double*)malloc(lines * sizeof(double));		//x-Werte
	if(x == NULL) {printf("Speicher-Fehler\n"); return 0;}
	double *y = (double*)malloc(lines * sizeof(double));		//y-Werte
	if(y == NULL) {printf("Speicher-Fehler\n"); return 0;}

	for(i = 0; i < lines; i++)
	{
		if(fgets(zeile, 7, datei) == NULL) break;
		get_number_from_char(zeile, x, y, i);
	
	}
	find_min_max(&x_min, &x_max, x, (size_t)lines);
	find_min_max(&y_min, &y_max, y, (size_t)lines);

	printf("X:\nMin: %.0lf\tMax: %.0lf\nY:\nMin: %.0lf\tMax: %.0lf\n", x_min, x_max, y_min, y_max);


	fclose(datei);
	return 0;
}

void get_number_from_char(char *zeile, double *x, double *y, int line)
{
	int i = 0;

	if(zeile[i] == '-')
	{
		i++;
		x[line] = (zeile[i]-48) - ((zeile[i]-48) *2);
	}
	else
	{
		x[line] = (zeile[i]-48);
	}
	i += 2;

	if(zeile[i] == '-')
	{
		i++;
		y[line] = (zeile[i]-48) - ((zeile[i]-48) *2);
	}
	else
	{
		y[line] = (zeile[i]-48);
	}
}

void find_min_max(double *min, double *max, double *x, size_t size)
/*	Übergeben werden jeweils ein Zeiger auf eine Variable, in dem später der min und max wert aus dem Array stehen.
	Übergeben wird auch ein array (x) in das die Werte zur verfügung stellt und die größe des Arrays.	*/
{
	size_t i;						//Zählervariable für die for-Schleife
	*min = x[0];	
	*max = x[0];					//Das 1. Feld des Arrays wird in "min" und in "max" gespeichert
	for(i = 1; i < size; ++i)		//Durchläufe von der 2. Array Stelle bis zur letzten
	{
		if(x[i] < *min)
		{
			*min = x[i];			//Wenn die aktuelle Array Stelle kleiner als das bisherige min ist, wird diese in min gespeichert
		}
		if(x[i] > *max)
		{
			*max = x[i];			//Wenn die aktuelle Array Stelle größer als das bisherige max ist, wird diese in max gespeichert
		}
	}
}

size_t get_number_of_lines_in_file(FILE *file)	//Es wird ein Zeiger auf eine Datei übergeben
{
	size_t cnt=0;								//Zählervariable auf 0 setzen
	char line[1024];							//Array für die Inhalte der Zeilen
	while (fgets(line, sizeof(line), file) != NULL) cnt++; 	//Zähle cnt hoch, bis keine Zeile mehr eingelesen wird (Dateiende)
	rewind(file);								//Setzt den Zeiger wieder an den Anfang der Datei
	return cnt;									//Gibt die anzahl der Zeilen zurück
}

