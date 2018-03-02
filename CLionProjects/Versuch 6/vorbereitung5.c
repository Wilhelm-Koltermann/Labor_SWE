#include <stdio.h>
#include "polynom.h"

int main(){
	
	int i,j=0;
	polynom_t poly;
	FILE *file;
	size_t n=3;
	
	file = fopen("vorbereitung.data", "rb");
	
	if(file == NULL) printf("error\n");
	
double f[14],x[7],koeff[]={1.,-2.,1.};
	
	for(i=0; i<14; i++){
		
		fscanf(file, "%lf", &f[i]);
		
	}
	
	if(polynom_initialize(&poly,n)==NULL) printf("error\n");

	 polynom_set_coefficients_from_array (&poly,koeff);
	
	for(i=0; i<14 ;i++){
		
		if(i%2 == 0){	
		
		printf("f(%lf) = %lf\n",f[i],polynom_evaluate(&poly,f[i]));
		
		}
		
	}
	
	polynom_destroy(&poly);
	fclose(file);
	
}