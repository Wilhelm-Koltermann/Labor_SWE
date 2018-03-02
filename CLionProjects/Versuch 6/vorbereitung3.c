#include <stdio.h>
#include "screen_transform.h"
#include "polynom.h"
#include "simple_rgb_image.h"
#include <stdlib.h>
#include <math.h>

void find_min_max(double *min, double *max, double *x, size_t size);

size_t get_number_of_lines_in_file(FILE *file);

int main(){
	
	FILE *file;
	
	file = fopen("vorbereitung.data", "rb");
	
	int i,j=0,k=0;
	
	size_t sizearray = get_number_of_lines_in_file(file);
	
	double min,max;
	
	double f[sizearray*2],x[sizearray],y[sizearray];
	
	
	for (i = 0; i < (sizearray*2); i++){
		
        fscanf(file, "%lf", &f[i] );
    }
	

	for(i=0;i < (sizearray*2);i++){

		if(i%2==0){
		
		x[j]=f[i]; 
		
		j++;
		
		}else{
	
		y[k]=f[i];
		
		k++;
	}
	
}
	
	find_min_max(&min,&max,x,sizeof(x)/8);
	
	printf("min von x: %lf max von x: %lf\n", min,max);
	
	find_min_max(&min,&max,y,sizeof(y)/8);
	
	printf("min von y: %lf max von y: %lf\n", min,max);
	
	fclose(file);

}

//Funktionen

//Findet max und min einer Zahlenmenge

void find_min_max(double *min, double *max, double *x, size_t size){
	
	size_t i;
	
	*min = x[0];
	
	*max = x[0];
	
	for(i = 1; i < size; ++i){
	
		if(x[i] < *min){
		
		*min = x[i];
	
		}
		
		if(x[i] > *max){
			
		*max = x[i];
			
		}
	}
}

//Ermittelt Anzahl der Zeilen eines Files

size_t get_number_of_lines_in_file(FILE *file){
	
	size_t cnt = 0;
	
	char line[1024];
	
	while (fgets(line, sizeof(line), file) != NULL) cnt++;
	
	rewind(file);
	
	return cnt;
}

	